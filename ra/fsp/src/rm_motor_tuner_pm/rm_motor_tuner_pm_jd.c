/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include <math.h>
#include "rm_motor_tuner_pm_jd.h"
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE          (106)
#endif

/**
 * @brief Defines RLS order, higher order means more calculation effort, but may get better result when noise exists
 */
#define JD_PRV_RLS_MODE                  (2)       ///< RLS mode selection, 1: order 1, 2: order 2, 3: order 3
#define JD_PRV_KI_MULT                   (0.2F)    ///< Multiplier for speed PI ki gain calculation during JD process
#define JD_PRV_SLOW_DOWN_SPEED_DIFF      (-1.0F)   ///< Speed difference threshold [rad/s] that allows decrease speed command
#define JD_PRV_MEASURE_SEQ_STOP          (0)       ///< JD measure sequence stop state
#define JD_PRV_MEASURE_SEQ_KE            (1)       ///< JD measure sequence KE measurement state
#define JD_PRV_MEASURE_SEQ_SETUP         (2)       ///< JD measure sequence setup state
#define JD_PRV_MEASURE_SEQ_RLS           (3)       ///< JD measure sequence RLS measurement state
#define JD_PRV_MEASURE_SEQ_DFT           (4)       ///< JD measure sequence DFT measurement state
#define JD_PRV_MEASURE_SEQ_COMP          (5)       ///< JD measure sequence result compensation state
#define JD_PRV_SPEED_CHANGE_UNLIMITED    (300.0F)  ///< A large value to represent unlimited speed change rate
#define JD_PRV_DEFAULT_INERTIA_MIN       (0.1E-6F) ///< Default minimum inertia value, value below this is considered as error
#define JD_PRV_DEFAULT_INERTIA_MAX       (5.0E-3F) ///< Default maximum inertia value, value exceed this is considered as error
#define JD_PRV_PI_ADJUST_MULT_MAX        (2.0F)    ///< Maximum multiplier for speed PI gains adjustment per attempt during JD process
#define JD_PRV_PI_ADJUST_MULT_MIN        (1.0F)    ///< Minimum multiplier for speed PI gains adjustment per attempt during JD process
#define JD_PRV_SPEED_AMP_RATIO_MAX       (0.95F)   ///< Maximum ratio of speed amplitude to reference speed for JD process
#define JD_PRV_RLS_INIT_PA               (4.0F)    ///< Initial value of RLS parameter p_a
#define JD_PRV_RLS_INIT_A                (0.999F)  ///< Initial value of RLS parameter A

/**
 * @brief Number of speed periods to sample for DFT estimation
 */
#define JD_PRV_SAMPLE_PERIOD_NUM         (50)      ///< Number of periods to sample

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void jd_design_speed_pi(motor_tuner_pm_jd_t       * p_jd,
                               motor_tuner_pm_core_foc_t * p_foc,
                               float                       inertia,
                               float                       speed_omega_hz);
static void jd_adjust_speed_pi(motor_tuner_pm_jd_t       * p_jd,
                               motor_tuner_pm_core_foc_t * p_foc,
                               float                       iq_amp,
                               float                       speed_amp);
static void jd_estimate_jd_rls(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_estimate_jd_dft(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_update_dft_result(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_seq_init(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_seq_ready(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_seq_measure(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_seq_check(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);
static void jd_seq_reset(motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief Main JD action function, to be called periodically in the control loop
 * @param p_jd       Pointer to JD instance structure
 * @param p_foc      Pointer to FOC core instance structure
 * @return           Whether the process is done (1) or not (0)
 */
uint16_t tuner_pm_jd_act (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    uint16_t ret = 0;
    switch (p_jd->e_status)
    {
        case TUNER_PM_SEQ_J_INIT:
        {
            jd_seq_init(p_jd, p_foc);
            break;
        }

        case TUNER_PM_SEQ_J_READY:
        {
            jd_seq_ready(p_jd, p_foc);
            break;
        }

        case TUNER_PM_SEQ_J_MEASURE:
        {
            jd_seq_measure(p_jd, p_foc);
            break;
        }

        case TUNER_PM_SEQ_J_CHECK:
        {
            jd_seq_check(p_jd, p_foc);
            break;
        }

        case TUNER_PM_SEQ_J_RESET:
        {
            jd_seq_reset(p_jd, p_foc);
            break;
        }

        case TUNER_PM_SEQ_J_COMPLETED:
        {
            ret = 1;
            break;
        }

        default:
        {
            TUNER_PM_ASSERT_FAIL();
            break;
        }
    }

    return ret;
}

/*******************************************************************************************************************//**
 * @brief       Resets JD module internal states
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
void tuner_pm_jd_reset (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_jd->j_rls            = 0.0F;
    p_jd->j_dft            = 0.0F;
    p_jd->d_rls            = 0.0F;
    p_jd->d_rls            = 0.0F;
    p_jd->e_status         = TUNER_PM_SEQ_J_INIT;
    p_jd->j_seq            = JD_PRV_MEASURE_SEQ_STOP;
    p_jd->iq_sum           = 0.0F;
    p_jd->iq_amp           = 0.0F;
    p_jd->iq               = 0.0F;
    p_jd->iq_lpf           = 0.0F;
    p_jd->refspeed_freq_hz = 0.0F;
    p_jd->refspeed_amp_max = 0.0F;
    p_jd->refspeed_amp     = 0.0F;
    p_jd->refspeed_offset  = 0.0F;
    p_jd->rls_respns_pre   = 0.0F;
    p_jd->speed_rad        = 0.0F;
    p_jd->speed_amp        = 0.0F;
    p_jd->ol2cl_speed      = 0.0F;
    p_jd->cl2ol_speed      = 0.0F;
    p_jd->dft_cycle_cnt    = 0.0F;
    p_jd->rls_coefa        = 0.0F;
    p_jd->rls_coefb        = 0.0F;
    p_jd->iq_offset        = 0.0F;
    p_jd->time_elapsed_ms  = 0.0F;
}

/*******************************************************************************************************************//**
 * @brief       Configure the inertia range for JD tuning process
 * The inertia range is from 0.0 to 1.0, where 0.0 means the minimum inertia, and 1.0 means the maximum inertia
 * This setting affects the amplitude of speed oscillation during the tuning process, large value means small speed
 * oscillation amplitude, vice versa.
 * @param[in]   p_jd            Pointer to JD instance structure
 * @param[in]   p_foc           Pointer to FOC core instance structure
 * @param[in]   inertia_range   Inertia range from 0.0 to 1.0
 **********************************************************************************************************************/
void tuner_pm_jd_config_inertia_range (motor_tuner_pm_jd_t       * p_jd,
                                       motor_tuner_pm_core_foc_t * p_foc,
                                       float                       inertia_range)
{
    FSP_PARAMETER_NOT_USED(p_jd);
    FSP_PARAMETER_NOT_USED(p_foc);

    TUNER_PM_ASSERT(inertia_range >= 0.0F);
    TUNER_PM_ASSERT(inertia_range <= 1.0F);

    p_jd->user_inertia_range = inertia_range;
}

/*******************************************************************************************************************//**
 * @brief       Design speed PI controller gains based on the given inertia and speed bandwidth
 * @param[in]   p_jd           Pointer to JD instance structure
 * @param[in]   p_foc          Pointer to FOC core instance structure
 * @param[in]   inertia       The inertia moment to be used to design speed PI controller
 * @param[in]   speed_omega_hz The desired speed control bandwidth in Hz
 **********************************************************************************************************************/
static void jd_design_speed_pi (motor_tuner_pm_jd_t       * p_jd,
                                motor_tuner_pm_core_foc_t * p_foc,
                                float                       inertia,
                                float                       speed_omega_hz)
{
    float gain_p;
    float gain_i_mult_dt;
    float speed_over_iq;
    float temp;

    FSP_PARAMETER_NOT_USED(p_jd);

    /* Calculate speed PI gains
     *  Kp = (2 * omega * J) / (Ke * P^2)
     *  Ki = (omega^2 * J) / (Ke * P^2) * T
     */
    speed_over_iq  = p_foc->ke * p_foc->pole_pairs * p_foc->pole_pairs;
    temp           = inertia / speed_over_iq;
    gain_p         = (speed_omega_hz * TUNER_PM_TWOPI * 2.0F) * temp; // NOLINT(readability-magic-numbers)
    gain_i_mult_dt = (TUNER_PM_TWOPI * speed_omega_hz * TUNER_PM_TWOPI * speed_omega_hz) *
                     JD_PRV_KI_MULT * temp * p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND;

    /* Set PI gains through the common core interface */
    tuner_pm_core_set_speed_pi(p_foc, gain_p, gain_i_mult_dt);
}

/*******************************************************************************************************************//**
 * @brief       Adjust speed PI controller gains during JD measurement process
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 * @param[in]   iq_amp     The current Iq amplitude measured during JD process
 * @param[in]   speed_amp  The current speed amplitude measured during JD process
 **********************************************************************************************************************/
static void jd_adjust_speed_pi (motor_tuner_pm_jd_t       * p_jd,
                                motor_tuner_pm_core_foc_t * p_foc,
                                float                       iq_amp,
                                float                       speed_amp)
{
    static const float JD_PRV_MIN_IQ_AMP_LSB = 20.0F; /* Minimum Iq amplitude in LSB to consider valid measurement */
    float              mult;
    float              speed_ratio;
    float              iq_ratio;
    float              iq_amp_min = p_foc->current_lsb * JD_PRV_MIN_IQ_AMP_LSB;

    /*
     * If the speed amplitude is lower than the target amplitude, and Iq amplitude is too small,
     * increase the speed PI gain to boost the speed response for better signal noise ratio.
     *
     * The speed PI gain will be recalculated using the new estimated inertia.
     * Expected minimum Iq amplitude is 0.025A
     */
    if ((speed_amp < (p_jd->refspeed_amp * p_jd->p_cfg->measure_start_amp_rate)) && (iq_amp < iq_amp_min))
    {
        speed_ratio = p_jd->refspeed_amp / speed_amp;
        iq_ratio    = iq_amp_min / iq_amp;
        mult        = (speed_ratio < iq_ratio) ? speed_ratio : iq_ratio;
        if (mult > JD_PRV_PI_ADJUST_MULT_MAX)
        {
            mult = JD_PRV_PI_ADJUST_MULT_MAX;
        }
        else if (mult < JD_PRV_PI_ADJUST_MULT_MIN)
        {
            mult = JD_PRV_PI_ADJUST_MULT_MIN;
        }
        else
        {
            /* Do nothing */
        }

        p_jd->j_pi_ctrl *= mult;
        jd_design_speed_pi(p_jd, p_foc, p_jd->j_pi_ctrl, p_jd->p_cfg->speedpi_omega);
    }
}

/*******************************************************************************************************************//**
 * @brief       Estimate inertia and friction coefficient by RLS method
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_estimate_jd_rls (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    float respns;
    float linearized_iq;
    float elespeed_over_iq;

    /* RLS filter , offset must be remove from both response and input terms before estimation */
    respns           = p_jd->speed_rad - p_jd->refspeed_offset;
    linearized_iq    = p_jd->iq - p_jd->iq_offset;
    elespeed_over_iq = (p_foc->ke * p_foc->pole_pairs * p_foc->pole_pairs);

#if (JD_PRV_RLS_MODE == 2)
    rm_motor_tuner_rls2_exec(&p_foc->rls,
                             p_jd->rls_respns_pre,
                             linearized_iq,
                             respns,
                             &p_jd->rls_coefa,
                             &p_jd->rls_coefb);
    p_jd->rls_respns_pre = respns;
    p_jd->d_rls          = ((1.0F - p_jd->rls_coefa) * elespeed_over_iq) / p_jd->rls_coefb;
    p_jd->j_rls          = (p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_jd->rls_coefa * elespeed_over_iq) /
                           p_jd->rls_coefb;
#elif (JD_PRV_RLS_MODE == 3)
    {
        float in[3];
        float coef[3];
        respns = p_jd->speed_rad;
        in[0]  = p_jd->rls_respns_pre;
        in[1]  = p_jd->iq;
        in[2]  = 1.0F;
        rm_motor_tuner_rls3_exec(&p_jd->rls3, in, respns, coef);
        p_jd->rls_respns_pre = respns;
        p_jd->rls_coefa      = coef[0];
        p_jd->rls_coefb      = coef[1];
        p_jd->d_rls          = (1.0F - p_jd->rls_coefa) * elespeed_over_iq / p_jd->rls_coefb;
        p_jd->j_rls          =
            (p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_jd->rls_coefa * elespeed_over_iq) /
            p_jd->rls_coefb;
    }
#else
    rm_motor_tuner_rls_exec(&p_foc->rls, linearized_iq, respns, &p_jd->rls_coefa, &p_jd->rls_coefb);
    p_jd->d_rls = ((1 + p_jd->rls_coefa) * elespeed_over_iq) / p_jd->rls_coefb;
    p_jd->j_rls = (-(p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_jd->rls_coefa * elespeed_over_iq)) /
                  p_jd->rls_coefb;
#endif
}

/*******************************************************************************************************************//**
 * @brief       Update DFT result for inertia and friction calculation
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_update_dft_result (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    float real;
    float imag;

    /* Factor that converts  Iq/We => Torque/Wm : C = (Torque/Iq) / (Wm / We) = Ke * Pn / (1 / Pn) = Ke * Pn^2  */
    float factor = p_foc->ke * p_foc->pole_pairs * p_foc->pole_pairs;

    /* Result of this function is Iq/We = (J*W*j + B)/C
     * => J = C * real / W, B = C * imag */
    rm_motor_tuner_dftdiff_result_div(&p_foc->dftdiff, &real, &imag);
    p_jd->j_dft = (imag * factor) / (TUNER_PM_TWOPI * p_jd->refspeed_freq_hz);
    p_jd->d_dft = real * factor;
}

/*******************************************************************************************************************//**
 * @brief       Estimate inertia and friction coefficient by DFT method
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_estimate_jd_dft (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    p_jd->dft_cycle_cnt++;
    rm_motor_tuner_dftdiff_sum(&p_foc->dftdiff,
                               rm_motor_tuner_sinref_get_angle(&p_foc->sinref),
                               p_jd->iq,
                               p_jd->speed_rad);

    if (p_jd->dft_cycle_cnt > (p_foc->spd_ctrl_freq_hz / p_jd->refspeed_freq_hz))
    {
        p_jd->dft_cycle_cnt -= (p_foc->spd_ctrl_freq_hz / p_jd->refspeed_freq_hz);
        jd_update_dft_result(p_jd, p_foc);
    }
}

/*******************************************************************************************************************//**
 * @brief       JD init sequence function, to be called periodically in the control loop
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_seq_init (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    float base_speed;
    float amp_coef;
    float flux_q_on_base_speed = p_foc->lq * p_foc->imag_max;

    /* This is duplicated with ones in KE, but is required if KE ID is skipped */
    tuner_pm_core_config_current_pi_gains(p_foc, p_foc->p_cfg->current_omega_hz, p_foc->p_cfg->current_zeta);
    tuner_pm_core_config_bemf_obsv(p_foc, p_foc->p_cfg->e_obs_omega_hz, p_foc->p_cfg->e_obs_zeta);

    base_speed = p_foc->vmag_max / sqrtf((p_foc->ke * p_foc->ke) + (flux_q_on_base_speed * flux_q_on_base_speed));

    /* Speed Kp */
    jd_design_speed_pi(p_jd, p_foc, p_foc->p_cfg->assumed_inertia, p_jd->p_cfg->speedpi_omega);

    /* Change parameter of sensor-less start-up sequence */
    p_jd->ol2cl_speed = p_foc->p_cfg->ol2cl_speed_th_coef * base_speed;
    p_jd->cl2ol_speed = p_foc->p_cfg->cl2ol_speed_th_coef * base_speed;
    tuner_pm_core_set_startup_params(p_foc,
                                     p_foc->rated_current * p_foc->p_cfg->id_ref_coef,
                                     p_jd->ol2cl_speed,
                                     p_jd->cl2ol_speed);

    /* Set parameter of speed reference signal for identification
     * Offset = base_speed * 0.5 (default)
     * Amplitude = base_speed * 0.15(default)
     */
    p_jd->refspeed_freq_hz = p_jd->p_cfg->speed_osc_freq_hz;
    amp_coef               = p_jd->p_cfg->speed_osc_amp_coef_min +
                             ((p_jd->p_cfg->speed_osc_amp_coef - p_jd->p_cfg->speed_osc_amp_coef_min) *
                              (1.0F - p_jd->user_inertia_range));
    p_jd->refspeed_amp     = base_speed * amp_coef;
    p_jd->refspeed_offset  = base_speed * p_foc->p_cfg->speed_offset_coef;
    p_jd->refspeed_amp_max = (p_jd->refspeed_offset - p_jd->cl2ol_speed) * JD_PRV_SPEED_AMP_RATIO_MAX;

    /* Initialize sine signal generator, DFT */
    rm_motor_tuner_sinref_init(&p_foc->sinref,
                               p_jd->refspeed_freq_hz,
                               p_jd->refspeed_amp,
                               p_jd->refspeed_offset,
                               p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_tuner_dftdiff_init(&p_foc->dftdiff);
    p_jd->setup_wait_cnt = 0.0F;

    /* Initialization of RLS filter */
#if (JD_PRV_RLS_MODE == 2)
    {
        float temp;

        temp = p_foc->ke * (p_foc->pole_pairs * p_foc->pole_pairs);

        /* Assumed the variance of 'a' is less than 0.04 (20%^2), initial value should be 100 times of it */
        rm_motor_tuner_rls2_init(&p_foc->rls,
                                 JD_PRV_RLS_INIT_PA,
                                 p_jd->p_cfg->rls_init,
                                 p_jd->p_cfg->rls_forget_k,
                                 JD_PRV_RLS_INIT_A,
                                                                 /* Initial weight for last output term */
                                 (temp * p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND) /
                                 p_foc->p_cfg->assumed_inertia); /* Initial weight for Iq */
    }
#elif (JD_PRV_RLS_MODE == 3)
    rm_motor_tuner_rls3_init(&p_jd->rls3,
                             p_jd->p_cfg->rls_init,
                             p_jd->p_cfg->rls_init,
                             p_jd->p_cfg->rls_init,
                             p_jd->p_cfg->rls_forget_k,
                             1.0F,
                             0.0F,
                             0.0F);
#else
    rm_motor_tuner_rls_init(&p_foc->rls, p_jd->p_cfg->rls_init, p_jd->p_cfg->rls_forget_k);
#endif

    p_jd->j_min     = JD_PRV_DEFAULT_INERTIA_MIN;
    p_jd->j_max     = JD_PRV_DEFAULT_INERTIA_MAX;
    p_jd->j_pi_ctrl = p_foc->p_cfg->assumed_inertia;

    p_jd->j_seq    = JD_PRV_MEASURE_SEQ_KE;
    p_jd->e_status = TUNER_PM_SEQ_J_READY;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_4);
    p_foc->limit_speed_change = p_foc->p_cfg->speed_change_rate_limit;

    /* If motor is in closed-loop drive mode, do not reset the start-up sequence, go ahead */
    if (MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP == p_foc->rotor_angle_mode)
    {
        tuner_pm_core_reset_startup_seq(p_foc);
    }
}

/*******************************************************************************************************************//**
 * @brief       JD ready sequence function, to be called periodically in the control loop
 * Waits for the speed reaching the offset speed
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_seq_ready (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->ref_speed_rad = p_jd->refspeed_offset;

    /* If the startup sequence failed, throw startup error */
    if ((p_foc->speed_lpf_rad < 0.0F) && (MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_CLOSEDLOOP == p_foc->rotor_angle_mode))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_J_STARTUP);
        p_jd->e_status = TUNER_PM_SEQ_J_RESET;
    }

    if (p_foc->ref_speed_rad_ctrl >= p_jd->refspeed_offset)
    {
        rm_motor_tuner_dftdiff_init(&p_foc->dftdiff);
        p_jd->dft_cycle_cnt = 0;
        p_jd->iq_lpf        = p_foc->iq_ad;
        p_jd->e_status      = TUNER_PM_SEQ_J_MEASURE;
    }
}

/*******************************************************************************************************************//**
 * @brief       JD measurement sequence function, to be called periodically in the control loop
 *
 * @param[in]   p_jd       Pointer to JD instance structure
 * @param[in]   p_foc      Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_seq_measure (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->one_ms_cnt++;
    p_jd->iq_sum += p_foc->iq_ad;

    /* TUNER_PM_CTRL_FREQ/TUNER_PM_1MS_FREQ is float, convert to uint16_t */
    if (((uint16_t) (p_foc->ctrl_freq_hz / p_foc->spd_ctrl_freq_hz)) == p_foc->one_ms_cnt)
    {
        /* Use PLL estimation as speed */
        p_jd->speed_rad = p_foc->speed_rad;

        p_jd->iq     = p_jd->iq_sum / p_foc->one_ms_cnt;
        p_jd->iq_sum = 0;

        p_foc->one_ms_cnt      = 0;
        p_jd->time_elapsed_ms += p_foc->spd_ctrl_period_ms;

        if (p_jd->j_seq >= JD_PRV_MEASURE_SEQ_SETUP)
        {
            /* Generate sinusoidal speed command signal,
             * frequency of the signal should be low enough than the specified bandwidth of speed PI */
            p_foc->ref_speed_rad = rm_motor_tuner_sinref_generate(&p_foc->sinref);

            jd_estimate_jd_rls(p_jd, p_foc);
            jd_estimate_jd_dft(p_jd, p_foc);
        }

        switch (p_jd->j_seq)
        {
            case JD_PRV_MEASURE_SEQ_KE:
            {
                if (p_jd->time_elapsed_ms > p_jd->p_cfg->stab_wait)
                {
                    p_jd->j_seq           = JD_PRV_MEASURE_SEQ_SETUP;
                    p_jd->time_elapsed_ms = 0.0F;
                    p_jd->iq_offset       = p_jd->iq_lpf;
                    p_jd->rls_respns_pre  = 0.0F;

                    /* Unlimit speed change rate, prevent the speed command signal distorted by change rate limiter */
                    p_foc->limit_speed_change = JD_PRV_SPEED_CHANGE_UNLIMITED;
                }
                else
                {
                    /* Wait until the speed became stable (500msec)
                     * NOTE: Fixed waiting time may be insufficient
                     * when the actual inertia is far larger than the assumed inertia
                     *  */
                }

                break;
            }

            case JD_PRV_MEASURE_SEQ_SETUP:
            {
                /* Measure the iq amplitude by DFT every 3 periods, adjust speed PI base on the result */
                p_jd->setup_wait_cnt++;
                if (p_jd->setup_wait_cnt >= ((p_foc->spd_ctrl_freq_hz / p_jd->refspeed_freq_hz) * 3))
                {
                    p_jd->setup_wait_cnt = 0;
                    rm_motor_tuner_dftdiff_get_result_amp(&p_foc->dftdiff, &p_jd->iq_amp, &p_jd->speed_amp);
                    jd_adjust_speed_pi(p_jd, p_foc, p_jd->iq_amp, p_jd->speed_amp);
                    rm_motor_tuner_dftdiff_init(&p_foc->dftdiff); /* Clear DFT */
                }

                if (p_jd->time_elapsed_ms >= ((TUNER_PM_SECOND_TO_MS / p_jd->refspeed_freq_hz) * p_jd->p_cfg->dft_num))
                {
                    p_jd->time_elapsed_ms = 0;
                    p_foc->sample_cnt     = 0;
                    rm_motor_tuner_dftdiff_init(&p_foc->dftdiff);
                    p_jd->j_seq = JD_PRV_MEASURE_SEQ_DFT;
                }

                break;
            }

            case JD_PRV_MEASURE_SEQ_RLS:
            {
                p_foc->sample_cnt++;
                if (((p_foc->spd_ctrl_freq_hz / p_jd->refspeed_freq_hz) * (float) JD_PRV_SAMPLE_PERIOD_NUM) <=
                    (float) p_foc->sample_cnt)
                {
                    p_jd->d_rls =
                        ((1 + p_jd->rls_coefa) * (p_foc->ke * p_foc->pole_pairs * p_foc->pole_pairs)) /
                        p_jd->rls_coefb;
                    p_jd->j_rls =
                        (-(p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_jd->rls_coefa *
                           (p_foc->ke * p_foc->pole_pairs * p_foc->pole_pairs))) / p_jd->rls_coefb;
                    p_foc->sample_cnt = 0;
                    p_jd->j_seq       = JD_PRV_MEASURE_SEQ_DFT;
                    rm_motor_tuner_dftdiff_init(&p_foc->dftdiff);
                }

                break;
            }

            case JD_PRV_MEASURE_SEQ_DFT:
            {
                p_foc->sample_cnt++;

                if (((p_foc->spd_ctrl_freq_hz * (float) JD_PRV_SAMPLE_PERIOD_NUM) / p_jd->refspeed_freq_hz) <=
                    (float) p_foc->sample_cnt)
                {
                    jd_update_dft_result(p_jd, p_foc);
                    p_foc->sample_cnt = 0;
                    p_jd->j_seq       = JD_PRV_MEASURE_SEQ_COMP;
                    p_jd->e_status    = TUNER_PM_SEQ_J_CHECK;
                }

                break;
            }

            default:
            {
                TUNER_PM_ASSERT_FAIL();
                break;
            }
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Check the estimated inertia and friction coefficient
 * @param[in] p_jd      Pointer to JD instance structure
 * @param[in] p_foc     Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_seq_check (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    float inertia;

    inertia = p_jd->j_dft;
    if ((inertia > p_jd->j_max) || (inertia <= p_jd->j_min))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_J);
    }

    /* Viscous friction check is skipped, since precise viscous friction is not ensured */

    p_jd->e_status = TUNER_PM_SEQ_J_RESET;
}

/*******************************************************************************************************************//**
 * @brief Reset sequence, slow down the motor to stop
 * @param[in] p_jd      Pointer to JD instance structure
 * @param[in] p_foc     Pointer to FOC core instance structure
 **********************************************************************************************************************/
static void jd_seq_reset (motor_tuner_pm_jd_t * p_jd, motor_tuner_pm_core_foc_t * p_foc)
{
    /* Restore the speed change rate limiter */
    p_foc->limit_speed_change = p_foc->p_cfg->speed_change_rate_limit;

    /*  In the case of the actual inertia is far more larger than the assumed inertia,
     *  the actual speed may be still high when transition starts.
     *  Slow down motor according to actual speed, to reduce switching shock of OL to CL transition */
    if ((p_foc->ref_speed_rad - p_foc->speed_lpf_rad) > JD_PRV_SLOW_DOWN_SPEED_DIFF)
    {
        p_foc->ref_speed_rad -= (p_jd->refspeed_offset * p_foc->ctrl_period_ms / p_jd->p_cfg->stop_time);
    }

    if (p_foc->ref_speed_rad < 0)
    {
        p_foc->ref_speed_rad = 0.0F;
        p_jd->e_status       = TUNER_PM_SEQ_J_COMPLETED;
    }
}
