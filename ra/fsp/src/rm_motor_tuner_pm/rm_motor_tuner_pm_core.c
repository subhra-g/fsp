/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RM_MOTOR_TUNER_PM
 * @defgroup RM_MOTOR_TUNER_PM_CORE The tuner core FOC module
 * @brief RM_MOTOR_TUNER_PM_CORE module handles calibrations, current/speed control and signals. Also launch events for upper layer
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <math.h>
#include <stdint.h>
#include <float.h>
#include <stdbool.h>
#include <bsp_api.h>
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_mc_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE                (107)
#endif
#define TUNER_PM_CORE_PRV_INV_CURRENT_LIMIT    (5.0F)
#define TUNER_PM_CORE_PRV_SPEED_LPF_BAND_HZ    (125.0F)

/**
 * Multiplier for duty margin calculation, include non-linear deadtime region and margin for compensation
 */
#define TUNER_PM_CORE_DUTY_MARGIN_MULT         (2.0F)

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static float core_generate_iq_ref(motor_tuner_pm_core_foc_t * p_foc);
static float core_generate_id_ref(motor_tuner_pm_core_foc_t * p_foc);
static float core_generate_speed_ref(motor_tuner_pm_core_foc_t * p_foc);
static void  core_check_over_current_error(motor_tuner_pm_core_foc_t * p_foc,
                                           float                       iu,
                                           float                       iv,
                                           float                       iw,
                                           float                       overcurrent_limit);
static void core_check_over_voltage_error(motor_tuner_pm_core_foc_t * p_foc,
                                          float                       vdc,
                                          float                       overvoltage_limit);
static void core_check_under_voltage_error(motor_tuner_pm_core_foc_t * p_foc,
                                           float                       vdc,
                                           float                       undervoltage_limit);
static void                  core_check_abort(motor_tuner_pm_core_foc_t * p_foc);
static void                  core_angle_speed_est(motor_tuner_pm_core_foc_t * p_foc);
static void                  core_bemf_observer(motor_tuner_pm_core_foc_t * p_foc);
static uint32_t              core_offset_measure(motor_tuner_pm_core_foc_t * p_foc);
static void                  core_set_voltage_limit(motor_tuner_pm_core_foc_t * p_foc, float voltage_limit);
static motor_tuner_request_t core_restart_drive(motor_tuner_pm_core_foc_t * p_foc);
static void                  core_estimator_filter(motor_tuner_pm_core_foc_t * p_foc,
                                                   float                       phase_error_rad,
                                                   float                       est_bemf);

/*******************************************************************************************************************//**
 * @brief Record debug data when assert failure happened
 *
 * @param[in] p_foc  Pointer to motor tuner core FOC structure
 * @param[in] line  The line where the assertion failure happened
 * @param[in] file  The file code where the assertion failure happened
 **********************************************************************************************************************/
void tuner_pm_core_assert_fail (motor_tuner_pm_core_foc_t * p_foc, uint32_t line, uint32_t file)
{
    tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_ASSERT_FAIL);
    p_foc->assert_failed_lineno = line;
    p_foc->assert_failed_file   = file;
}

/*******************************************************************************************************************//**
 * @brief     Throw an error with the given error code and stop PWM output
 * @param[in] p_foc       Pointer to motor tuner core FOC structure
 * @param[in] error_code  The error code of the error
 **********************************************************************************************************************/
void tuner_pm_core_throw_error (motor_tuner_pm_core_foc_t * p_foc, uint16_t error_code)
{
    p_foc->error_status = error_code;
    tuner_pm_core_hook_on_error(p_foc, error_code);
}

/*******************************************************************************************************************//**
 * Configure start-up sequence
 *
 * @param[in] p_foc               Pointer to motor tuner core FOC structure
 * @param[in] open_loop_id        The Id[A] injected in open-loop mode
 * @param[in] ol2cl_speed_rad     The open-loop to closed-loop switching threshold speed in [rad/s]
 * @param[in] cl2ol_speed_rad     The closed-loop to open-loop switching threshold speed in [rad/s]
 **********************************************************************************************************************/
void tuner_pm_core_set_startup_params (motor_tuner_pm_core_foc_t * p_foc,
                                       float                       open_loop_id,
                                       float                       ol2cl_speed_rad,
                                       float                       cl2ol_speed_rad)
{
    TUNER_PM_ASSERT(open_loop_id >= 0.0F);
    TUNER_PM_ASSERT(cl2ol_speed_rad >= 0.0F);
    TUNER_PM_ASSERT(ol2cl_speed_rad >= cl2ol_speed_rad);

    p_foc->open_loop_id      = open_loop_id;
    p_foc->id_down_speed_rad = ol2cl_speed_rad;
    p_foc->id_up_speed_rad   = cl2ol_speed_rad;
    p_foc->id_up_step        = p_foc->open_loop_id / p_foc->p_cfg->id_up_time * p_foc->spd_ctrl_period_ms;
    p_foc->id_down_step      = p_foc->open_loop_id / p_foc->p_cfg->id_down_time * p_foc->spd_ctrl_period_ms;
}

/*******************************************************************************************************************//**
 * Configure speed pi with given gains
 *
 * @param[in]  p_foc       Pointer to motor tuner core FOC structure
 * @param[in]  kp         The proportional gain
 * @param[in]  kidt       The integral gain
 **********************************************************************************************************************/
void tuner_pm_core_set_speed_pi (motor_tuner_pm_core_foc_t * p_foc, float kp, float kidt)
{
    TUNER_PM_ASSERT(kp >= 0.0F);
    TUNER_PM_ASSERT(kidt >= 0.0F);

    p_foc->kp_speed       = kp;
    p_foc->ki_speed       = kidt;
    p_foc->pi_speed.f4_kp = kp;
    p_foc->pi_speed.f4_ki = kidt;
}

/*******************************************************************************************************************//**
 * @brief     Configure rated current, this will also change the current limits and the over-current threshold
 * @param[in] p_foc           Pointer to motor tuner core FOC structure
 * @param[in] rated_current  The value [A] to be set as the rated current
 **********************************************************************************************************************/
void tuner_pm_core_set_rated_current (motor_tuner_pm_core_foc_t * p_foc, float rated_current)
{
    TUNER_PM_ASSERT(rated_current > 0.0F);

    p_foc->imag_max           = rated_current * TUNER_PM_SQRT_3;
    p_foc->lim_iq             = p_foc->imag_max;
    p_foc->pi_speed.f4_ilimit = p_foc->lim_iq;

    /* The same phase current, just convert [Arms] to [A] by multiply sqrt(2), p_foc->p_cfg->overcurrent_limit_mult is for
     * adding some margin, so it should be larger than 1.0 */
    p_foc->overcurrent_limit = rated_current * TUNER_PM_SQRT_2 * p_foc->p_cfg->overcurrent_limit_mult;

    if (p_foc->overcurrent_limit > p_foc->overcurrent_limit_hw)
    {
        p_foc->overcurrent_limit = p_foc->overcurrent_limit_hw;
    }
}

/*******************************************************************************************************************//**
 * @brief     Configures the voltage error compensation module with the given lookup table
 * @param[in] p_foc         Pointer to motor tuner FOC core structure
 * @param[in] current_tab  The pointer to the current column array of the lookup table
 * @param[in] voltage_tab  The pointer to the voltage column array of the lookup table
 * @param[in] vdc_ref      The reference DC bus voltage which is the measurement condition of the given table
 **********************************************************************************************************************/
void tuner_pm_core_set_volterr_table (motor_tuner_pm_core_foc_t * p_foc,
                                      const float               * current_tab,
                                      const float               * voltage_tab,
                                      float                       vdc_ref)
{
    TUNER_PM_ASSERT(NULL != current_tab);
    TUNER_PM_ASSERT(NULL != voltage_tab);
    TUNER_PM_ASSERT(vdc_ref > 0.0F);

    rm_motor_volt_error_comp_set_table(&p_foc->volt_comp, current_tab, voltage_tab, vdc_ref);
}

/*******************************************************************************************************************//**
 * @brief     Clear the error status of the FOC core
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 **********************************************************************************************************************/
void tuner_pm_core_clear_error (motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->error_status = MOTOR_TUNER_PM_ERROR_NONE;
}

/*******************************************************************************************************************//**
 * Configure current pi with given gains
 *
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 * @param[in] omega  The natural frequency in [Hz]
 * @param[in] zeta   The damping factor
 **********************************************************************************************************************/
void tuner_pm_core_config_current_pi_gains (motor_tuner_pm_core_foc_t * p_foc, float omega, float zeta)
{
    float omega_sqr;
    float omega_rad;

    TUNER_PM_ASSERT(omega > 0.0F);
    TUNER_PM_ASSERT((zeta > 0.0F) && (zeta <= 1.0F));

    omega_rad            = omega * TUNER_PM_TWOPI;
    omega_sqr            = omega_rad * omega_rad;
    p_foc->omega_current = omega * TUNER_PM_TWOPI;
    p_foc->zeta_current  = zeta;

    /*
     *  Kp = (2 * omega * zeta * L) - R
     *  Ki = omega^2 * L * T
     */
    p_foc->kp_id       = (2.0F * omega_rad * zeta * p_foc->ld) - p_foc->r; // NOLINT(readability-magic-numbers)
    p_foc->pi_vd.f4_kp = p_foc->kp_id;
    p_foc->ki_id       = omega_sqr * p_foc->ld * p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND;
    p_foc->pi_vd.f4_ki = p_foc->ki_id;
    p_foc->kp_iq       = (2.0F * omega_rad * zeta * p_foc->lq) - p_foc->r; // NOLINT(readability-magic-numbers)
    p_foc->pi_vq.f4_kp = p_foc->kp_iq;
    p_foc->ki_iq       = omega_sqr * p_foc->lq * p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND;
    p_foc->pi_vq.f4_ki = p_foc->ki_iq;
}

/*******************************************************************************************************************//**
 * @brief Configure speed pi with given gains
 *
 * @param[in] p_foc  Pointer to motor tuner core FOC structure
 * @param[in] omega  The natural frequency in [Hz]
 * @param[in] zeta   The damping factor
 **********************************************************************************************************************/
void tuner_pm_core_config_bemf_obsv (motor_tuner_pm_core_foc_t * p_foc, float omega, float zeta)
{
    TUNER_PM_ASSERT(omega > 0.0F);
    TUNER_PM_ASSERT((zeta > 0.0F) && (zeta <= 1.0F));

    /* Design of BEMF observer, the flux and mechanical parameters are not required */
    p_foc->motor_params.f4_mtr_r               = p_foc->r;
    p_foc->motor_params.f4_mtr_ld              = p_foc->ld;
    p_foc->motor_params.f4_mtr_lq              = p_foc->lq;
    p_foc->motor_params.u2_mtr_pp              = (uint16_t) p_foc->pole_pairs;
    p_foc->motor_params.f4_mtr_nominal_current = p_foc->rated_current;
    p_foc->motor_params.f4_mtr_m               = 0.0F;
    p_foc->motor_params.f4_mtr_j               = 0.0F;

    rm_motor_bemf_obs_gain_calc(&p_foc->motor_params,
                                &p_foc->bemf_observer,
                                omega,
                                zeta,
                                p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_bemf_obs_pll_gain_calc(&p_foc->pll_est,
                                    p_foc->p_cfg->pll_est_omega_hz,
                                    p_foc->p_cfg->pll_est_zeta,
                                    p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
}

/*******************************************************************************************************************//**
 * @brief Carrier interrupt handler of CORE module
 * This function defines the process should be executed every PWM cycle
 * @param[in]  p_foc   Pointer to motor tuner FOC core structure
 * @param[in]  p_in    Pointer to motor tuner input structure
 * @param[out] p_out   Pointer to motor tuner output structure
 * @pre AD conversion of current and DC bus voltage must be done before calling this function
 **********************************************************************************************************************/
void tuner_pm_core_crnt_ctrl_handler (motor_tuner_pm_core_foc_t * p_foc,
                                      motor_tuner_in_t          * p_in,
                                      motor_tuner_out_t         * p_out)
{
    uint32_t              ret;
    float                 temp_abc[3];
    float                 temp_abc_2[3];
    float                 temp_dq[2];
    motor_tuner_request_t request;

    if (TUNER_PM_RUNMODE_INIT == p_foc->run_mode)
    {
        request         = core_restart_drive(p_foc);
        p_foc->run_mode = TUNER_PM_RUNMODE_BOOT;

        p_out->vu      = 0.0F;
        p_out->vv      = 0.0F;
        p_out->vw      = 0.0F;
        p_out->request = request;
        p_out->status  = MOTOR_TUNER_STATUS_RUNNING;

        return;
    }

    p_foc->ia_ad  = p_in->iu;
    p_foc->ib_ad  = p_in->iv;
    p_foc->ic_ad  = p_in->iw;
    p_foc->vdc_ad = p_in->vdc;

    /* Voltage Limit Calculation */
    core_set_voltage_limit(p_foc, p_foc->duty_available * p_in->va_max);

    if (TUNER_PM_RUNMODE_BOOT == p_foc->run_mode)
    {
        ret = core_offset_measure(p_foc);
        if (1 == ret)
        {
            p_foc->run_mode = TUNER_PM_RUNMODE_READY;
        }
    }

    /* Current offset adjustment */
    p_foc->ia_ad = p_foc->ia_ad - p_foc->offset_ia;
    p_foc->ib_ad = p_foc->ib_ad - p_foc->offset_ib;
    p_foc->ic_ad = p_foc->ic_ad - p_foc->offset_ic;

    /* Error check */
    core_check_over_current_error(p_foc, p_foc->ia_ad, p_foc->ib_ad, p_foc->ic_ad, p_foc->overcurrent_limit);
    core_check_over_voltage_error(p_foc, p_foc->vdc_ad, p_foc->overvoltage_limit);
    core_check_under_voltage_error(p_foc, p_foc->vdc_ad, p_foc->undervoltage_limit);
    core_check_abort(p_foc);

    if ((TUNER_PM_RUNMODE_READY == p_foc->run_mode) && (MOTOR_TUNER_PM_ERROR_NONE == p_foc->error_status))
    {
        temp_abc[0] = p_foc->ia_ad;
        temp_abc[1] = p_foc->ib_ad;
        temp_abc[2] = p_foc->ic_ad;
        rm_motor_transform_uvw_dq_abs(p_foc->angle_rad, temp_abc, temp_dq);
        p_foc->id_ad = temp_dq[0];
        p_foc->iq_ad = temp_dq[1];

        /* BEMF Observer */
        if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_2)
        {
            core_bemf_observer(p_foc);
            core_estimator_filter(p_foc, p_foc->phase_error, p_foc->e);
        }

        /* Angle and speed estimation/command generation (in open-loop operation)  */
        if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_3)
        {
            core_angle_speed_est(p_foc);
        }

        /* Motor parameter identification sequences */
        tuner_pm_core_hook_before_current_ctrl(p_foc->p_context); /* =>tuner_pm_motorid_sequence() */

        if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_2)
        {
            /* Current PI */
            p_foc->pi_vd.f4_err = p_foc->id_ref - p_foc->id_ad;
            p_foc->pi_vq.f4_err = p_foc->iq_ref - p_foc->iq_ad;
            p_foc->vd_ref       = rm_motor_pi_ctrl(&p_foc->pi_vd);
            p_foc->vq_ref       = rm_motor_pi_ctrl(&p_foc->pi_vq);
        }

        temp_dq[0] = p_foc->vd_ref;
        temp_dq[1] = p_foc->vq_ref;
        rm_motor_transform_dq_uvw_abs(p_foc->angle_rad, temp_dq, temp_abc);
        p_foc->va_ref = temp_abc[0];
        p_foc->vb_ref = temp_abc[1];
        p_foc->vc_ref = temp_abc[2];

        /*     voltage error compensation     */
        if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_3)
        {
            temp_dq[0] = p_foc->id_ref;
            temp_dq[1] = p_foc->iq_ref;
            rm_motor_transform_dq_uvw_abs(p_foc->angle_rad, temp_dq, temp_abc);
            p_foc->ia_ref = temp_abc[0];
            p_foc->ib_ref = temp_abc[1];
            p_foc->ic_ref = temp_abc[2];

            temp_abc[0]   = p_foc->va_ref;
            temp_abc[1]   = p_foc->vb_ref;
            temp_abc[2]   = p_foc->vc_ref;
            temp_abc_2[0] = p_foc->ia_ref;
            temp_abc_2[1] = p_foc->ib_ref;
            temp_abc_2[2] = p_foc->ic_ref;
            rm_motor_volt_error_comp_main(&p_foc->volt_comp, temp_abc, temp_abc_2, p_foc->vdc_ad);
            p_foc->va_ref_comp = temp_abc[0];
            p_foc->vb_ref_comp = temp_abc[1];
            p_foc->vc_ref_comp = temp_abc[2];
        }
        else if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_1)
        {
            temp_abc[0]   = p_foc->va_ref;
            temp_abc[1]   = p_foc->vb_ref;
            temp_abc[2]   = p_foc->vc_ref;
            temp_abc_2[0] = p_foc->ia_ref;
            temp_abc_2[1] = p_foc->ib_ref;
            temp_abc_2[2] = p_foc->ic_ref;
            rm_motor_volt_error_comp_main(&p_foc->volt_comp, temp_abc, temp_abc_2, p_foc->vdc_ad);
            p_foc->va_ref_comp = temp_abc[0];
            p_foc->vb_ref_comp = temp_abc[1];
            p_foc->vc_ref_comp = temp_abc[2];
        }
        else
        {
            p_foc->va_ref_comp = p_foc->va_ref;
            p_foc->vb_ref_comp = p_foc->vb_ref;
            p_foc->vc_ref_comp = p_foc->vc_ref;
        }

        /*     limit (Voltage)     */
        p_foc->va_ref_comp = rm_motor_filter_limitf_abs(p_foc->va_ref_comp, p_foc->vphase_limit);
        p_foc->vb_ref_comp = rm_motor_filter_limitf_abs(p_foc->vb_ref_comp, p_foc->vphase_limit);
        p_foc->vc_ref_comp = rm_motor_filter_limitf_abs(p_foc->vc_ref_comp, p_foc->vphase_limit);

        p_out->vu = p_foc->va_ref_comp;
        p_out->vv = p_foc->vb_ref_comp;
        p_out->vw = p_foc->vc_ref_comp;

        tuner_pm_core_hook_after_pwmoutput(p_foc->p_context);
    }
}

/*******************************************************************************************************************//**
 * @brief Stops driving motor, this also stops the PWM output
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 **********************************************************************************************************************/
void tuner_pm_core_stop (motor_tuner_pm_core_foc_t * p_foc)
{
    /* Stop inverter */
    p_foc->enable_pwm_output = false;

    p_foc->vd_ref        = 0.0F;
    p_foc->vq_ref        = 0.0F;
    p_foc->id_ref        = 0.0F;
    p_foc->iq_ref        = 0.0F;
    p_foc->speed_rad     = 0.0F;
    p_foc->ref_speed_rad = 0.0F;

    p_foc->run_mode = TUNER_PM_RUNMODE_INIT;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_0);
}

/*******************************************************************************************************************//**
 * @brief     Core module initialization
 * @param[in] p_foc        Pointer to motor tuner FOC core structure
 * @param[in] p_cfg        Pointer to motor tuner FOC core configuration structure
 * @param[in] p_context    Pointer to the upper layer context
 * @param[in] pwm_tick_per_irq     The PWM tick per interrupt
 * @param[in] speed_ctrl_period    The speed control period
 **********************************************************************************************************************/
void tuner_pm_core_init (motor_tuner_pm_core_foc_t           * p_foc,
                         motor_tuner_pm_core_foc_cfg_t const * p_cfg,
                         void                                * p_context,
                         uint8_t                               pwm_tick_per_irq,
                         float                                 speed_ctrl_period)
{
    float pwm_tick_cycle_ms;

    /* Check prerequisites */
    TUNER_PM_ASSERT(pwm_tick_per_irq >= 1);

    p_foc->p_context     = p_context;
    p_foc->abort_request = false;

    /* Calculate cycles */
    TUNER_PM_ASSERT(p_cfg->inv_info_pwm_cycle_s > 0.0F);
    pwm_tick_cycle_ms     = p_cfg->inv_info_pwm_cycle_s * TUNER_PM_SECOND_TO_MS;
    p_foc->pwm_period_ms  = pwm_tick_cycle_ms;
    p_foc->ctrl_period_ms = pwm_tick_cycle_ms * pwm_tick_per_irq;
    p_foc->ctrl_freq_hz   = 1.0F / p_cfg->inv_info_pwm_cycle_s / pwm_tick_per_irq;

    p_foc->spd_ctrl_period_ms = speed_ctrl_period * TUNER_PM_SECOND_TO_MS;
    TUNER_PM_ASSERT(p_foc->spd_ctrl_period_ms > p_foc->pwm_period_ms);
    p_foc->spd_ctrl_freq_hz = 1.0F / speed_ctrl_period;

    /* Calculate voltage limiter coefficient, STM should be difference from BLDC,
     * actual maximum voltage magnitude will be calculated before offset calibration */
    TUNER_PM_ASSERT(p_cfg->inv_info_pwm_duty_min >= 0.0F);
    TUNER_PM_ASSERT(p_cfg->inv_info_pwm_duty_max > p_cfg->inv_info_pwm_duty_min);
    if (p_cfg->inv_info_pwm_duty_min > (1.0F - p_cfg->inv_info_pwm_duty_max))
    {
        p_foc->duty_available = 1.0F - (TUNER_PM_CORE_DUTY_MARGIN_MULT * p_cfg->inv_info_pwm_duty_min);
    }
    else
    {
        p_foc->duty_available = (p_cfg->inv_info_pwm_duty_max * TUNER_PM_CORE_DUTY_MARGIN_MULT) - 1.0F;
    }

    /* Set up protection thresholds */
    TUNER_PM_ASSERT(p_cfg->inv_info_current_limit > 0.0F);
    p_foc->overcurrent_limit_hw = p_cfg->inv_info_current_limit;
    p_foc->overcurrent_limit    = p_foc->overcurrent_limit_hw;

    TUNER_PM_ASSERT(p_cfg->inv_info_overvoltage_th > 0.0F);
    p_foc->overvoltage_limit = p_cfg->inv_info_overvoltage_th;

    TUNER_PM_ASSERT(p_cfg->inv_info_undervoltage_th > 0.0F &&
                    (p_cfg->inv_info_undervoltage_th < p_cfg->inv_info_overvoltage_th));
    p_foc->undervoltage_limit = p_cfg->inv_info_undervoltage_th;

    TUNER_PM_ASSERT(p_cfg->mcu_adc_resolution > 0)
    p_foc->current_lsb = p_cfg->inv_info_current_full_range / (float) p_cfg->mcu_adc_resolution;

    TUNER_PM_ASSERT(p_cfg->mcu_pwm_resolution > 0)
    p_foc->pwm_duty_lsb = 1.0F / (float) p_cfg->mcu_pwm_resolution;

    /* Enabled by default */
    rm_motor_volt_error_comp_init(&p_foc->volt_comp);
    p_foc->volt_comp.u1_volt_err_comp_enable = MOTOR_CURRENT_VOLTAGE_COMPENSATION_SELECT_ENABLE;

    p_foc->rated_current = 0.0F;
    p_foc->rated_power   = 0.0F;
    p_foc->pole_pairs    = 0;

    p_foc->p_cfg = p_cfg;
}

/*******************************************************************************************************************//**
 * @brief     Sets the control level of CORE module
 * @param[in] p_foc        Pointer to motor tuner FOC core structure
 * @param[in] ctrl_level  The control level
 **********************************************************************************************************************/
void tuner_pm_core_set_ctrl_level (motor_tuner_pm_core_foc_t * p_foc, uint16_t ctrl_level)
{
    TUNER_PM_ASSERT(ctrl_level <= TUNER_PM_CTRL_LEVEL_4);
    p_foc->ctrl_level = ctrl_level;
}

/*******************************************************************************************************************//**
 * @brief   Resets CORE modules includes gain and motor parameters
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 * @warning This function will resets all parameters in the module, and should be used only when new identification
 *          starts
 **********************************************************************************************************************/
void tuner_pm_core_reset (motor_tuner_pm_core_foc_t * p_foc)
{
    /* HW Commands*/
    p_foc->enable_pwm_output = false;

    /* Common */
    p_foc->sample_cnt = 0;
    p_foc->one_ms_cnt = 0;
    p_foc->sum_cnt    = 0;

    /* Reset modes */
    p_foc->rotor_angle_mode = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_0);
    p_foc->error_status    = MOTOR_TUNER_PM_ERROR_NONE;
    p_foc->run_mode        = TUNER_PM_RUNMODE_INIT;
    p_foc->flag_id_ref     = TUNER_PM_ID_UP;
    p_foc->flag_iq_ref     = TUNER_PM_IQ_ZERO_CONST;
    p_foc->flag_speed_ref  = TUNER_PM_SPEED_HOLD;
    p_foc->flag_down_to_ol = 0;
    p_foc->ctrl_conf       = 0;

    /* Reset motor parameters */
    p_foc->r_dc  = 0.0F;
    p_foc->v_err = 0.0F;
    p_foc->r     = 0.0F;
    p_foc->ld    = 0.0F;
    p_foc->lq    = 0.0F;
    p_foc->ke    = 0.0F;
    p_foc->j     = 0.0F;

    /* Motor driver */
    p_foc->ia_ad  = 0.0F;
    p_foc->ib_ad  = 0.0F;
    p_foc->ic_ad  = 0.0F;
    p_foc->vd_ref = 0.0F;
    p_foc->vq_ref = 0.0F;
    p_foc->ia_ref = 0.0F;
    p_foc->ib_ref = 0.0F;
    p_foc->id_ref = 0.0F;
    p_foc->iq_ref = 0.0F;
    p_foc->id_ad  = 0.0F;
    p_foc->iq_ad  = 0.0F;
    p_foc->vdc_ad = 0.0F;

    p_foc->imag_max = 1.0F;            /* This value will be overrided when setting rated current */

    /* Reset offset calibration */
    p_foc->offset_ia        = 0.0F;
    p_foc->offset_ib        = 0.0F;
    p_foc->offset_ic        = 0.0F;
    p_foc->pre_offset_ia    = 0.0F;
    p_foc->pre_offset_ib    = 0.0F;
    p_foc->pre_offset_ic    = 0.0F;
    p_foc->offset_lpf_k     = p_foc->p_cfg->offset_lpf_k;
    p_foc->offset_calc_time = p_foc->p_cfg->offset_calc_time;
    p_foc->cnt_adjust       = 0;

    /* Reset PLL */
    p_foc->phase_error  = 0.0F;
    p_foc->speed_rad    = 0.0F;
    p_foc->angle_rad    = 0.0F;
    p_foc->kp_est_speed = 2 * TUNER_PM_TWOPI * p_foc->p_cfg->pll_est_omega_hz * p_foc->p_cfg->pll_est_zeta;
    p_foc->ki_est_speed = (TUNER_PM_TWOPI * p_foc->p_cfg->pll_est_omega_hz) *
                          (TUNER_PM_TWOPI * p_foc->p_cfg->pll_est_omega_hz) *
                          (p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    p_foc->temp_cos = 0.0F;
    p_foc->temp_sin = 0.0F;

    /* Reset current control */
    p_foc->omega_current   = TUNER_PM_TWOPI * p_foc->p_cfg->current_omega_hz;
    p_foc->zeta_current    = p_foc->p_cfg->current_zeta;
    p_foc->kp_id           = 0.0F;
    p_foc->ki_id           = 0.0F;
    p_foc->kp_iq           = 0.0F;
    p_foc->ki_iq           = 0.0F;
    p_foc->pi_vd.f4_kp     = 0.0F;
    p_foc->pi_vd.f4_ki     = 0.0F;
    p_foc->pi_vd.f4_refi   = 0.0F;
    p_foc->pi_vd.f4_ilimit = p_foc->overvoltage_limit;
    p_foc->pi_vq.f4_kp     = 0.0F;
    p_foc->pi_vq.f4_ki     = 0.0F;
    p_foc->pi_vq.f4_refi   = 0.0F;
    p_foc->pi_vq.f4_ilimit = p_foc->overvoltage_limit;

    /* Reset BEMF observer */
    p_foc->omega_e_obs = TUNER_PM_TWOPI * p_foc->p_cfg->e_obs_omega_hz;
    p_foc->zeta_e_obs  = p_foc->p_cfg->e_obs_zeta;
    p_foc->ed          = 0.0F;
    p_foc->eq          = 0.0F;
    p_foc->e           = 0.0F;
    p_foc->e_lpf       = 0.0F;
    rm_motor_bemf_obs_reset(&p_foc->bemf_observer);
    rm_motor_bemf_obs_pll_reset(&p_foc->pll_est);

    /* Reset speed control, speed change rate limiter */
    p_foc->kp_speed           = 0.0F;
    p_foc->ki_speed           = 0.0F;
    p_foc->lim_iq             = 0.0F;
    p_foc->ref_speed_rad_ctrl = 0.0F;
    p_foc->ref_speed_rad      = 0.0F;
    p_foc->limit_speed_change = p_foc->p_cfg->speed_change_rate_limit;
    p_foc->pi_speed.f4_kp     = 0.0F;
    p_foc->pi_speed.f4_ki     = 0.0F;
    p_foc->pi_speed.f4_refi   = 0.0F;
    p_foc->pi_speed.f4_ilimit = 0.0F;

    /* Reset start-up sequence parameters */
    p_foc->id_down_speed_rad = 0.0F;
    p_foc->id_up_speed_rad   = 0.0F;
    p_foc->id_up_step        = 0.0F;
    p_foc->id_down_step      = 0.0F;
    p_foc->open_loop_id      = 0.0F;
    p_foc->iq_down_step      = 0.0F;
    p_foc->ol_iq_down_step   = 1.0F / p_foc->p_cfg->iq_down_time;

    /* Resets modulation */
    p_foc->va_ref       = 0.0F;
    p_foc->vb_ref       = 0.0F;
    p_foc->vc_ref       = 0.0F;
    p_foc->va_ref_comp  = 0.0F;
    p_foc->vb_ref_comp  = 0.0F;
    p_foc->vc_ref_comp  = 0.0F;
    p_foc->vphase_limit = 0.0F;
    p_foc->moda         = 0.0F;
    p_foc->modb         = 0.0F;
    p_foc->modc         = 0.0F;

    /* Reset voltage error compensation */
    p_foc->vcomp_array[0]   = 0.0F;
    p_foc->vcomp_array[1]   = 0.0F;
    p_foc->vcomp_array[2]   = 0.0F;
    p_foc->vcomp_i_array[0] = 0.0F;
    p_foc->vcomp_i_array[1] = 0.0F;
    p_foc->vcomp_i_array[2] = 0.0F;
    p_foc->volt_comp.u1_volt_err_comp_enable = MOTOR_CURRENT_VOLTAGE_COMPENSATION_SELECT_ENABLE;

    /* Reset speed LPF */
    p_foc->speed_lpf_rad      = 0.0F;
    p_foc->speed_1ms_rad      = 0.0F;
    p_foc->speed_lpf_omega_hz = TUNER_PM_CORE_PRV_SPEED_LPF_BAND_HZ;
    rm_motor_filter_first_order_lpff_init(&p_foc->speed_lpf);
    rm_motor_filter_first_order_lpff_gain_calc(&p_foc->speed_lpf,
                                               p_foc->speed_lpf_omega_hz,
                                               p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
}

/*******************************************************************************************************************//**
 * @brief   Resets start-up sequence and related variables
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 **********************************************************************************************************************/
void tuner_pm_core_reset_startup_seq (motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->id_ref             = 0.0F;
    p_foc->iq_ref             = 0.0F;
    p_foc->ref_speed_rad_ctrl = 0.0F;
    p_foc->flag_speed_ref     = TUNER_PM_SPEED_HOLD;
    p_foc->flag_id_ref        = TUNER_PM_ID_UP;
    p_foc->flag_iq_ref        = TUNER_PM_IQ_ZERO_CONST;
    p_foc->torque_current     = 0.0F;
}

/*******************************************************************************************************************//**
 * @brief Long period interrupt handler, for outer loop and start-up sequence control
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 * @note  Wrapper of current control interrupt handler
 **********************************************************************************************************************/
void tuner_pm_core_spd_ctrl_handler (motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;

    p_foc->speed_1ms_rad = p_foc->speed_lpf_rad; /* speed */

    if (p_foc->ctrl_level >= TUNER_PM_CTRL_LEVEL_4)
    {
        /***** sensorless to openloop *****/
        temp0 = fabsf(p_foc->ref_speed_rad_ctrl);
        if (MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_CLOSEDLOOP == p_foc->rotor_angle_mode)
        {
            if (temp0 < p_foc->id_up_speed_rad)
            {
                p_foc->flag_down_to_ol = TUNER_PM_FLG_SET;
            }
        }

        /***** Id, Iq, speed reference setting *****/
        p_foc->ref_speed_rad_ctrl = core_generate_speed_ref(p_foc);
        p_foc->iq_ref             = core_generate_iq_ref(p_foc);
        p_foc->id_ref             = core_generate_id_ref(p_foc);

        p_foc->flag_down_to_ol = TUNER_PM_FLG_CLR;

        if (TUNER_PM_IQ_SPEED_PI_OUTPUT == p_foc->flag_iq_ref)
        {
            p_foc->ctrl_conf |= TUNER_PM_CONTROL_SPEED;
        }
        else
        {
            p_foc->ctrl_conf = TUNER_PM_CONTROL_CURRENT;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Generate Iq reference
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 * @return Iq reference [A]
 **********************************************************************************************************************/
static float core_generate_iq_ref (motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;
    float iq_ref_buff = 0.0F;

    if (TUNER_PM_FLG_SET == p_foc->flag_down_to_ol)
    {
        p_foc->flag_iq_ref      = TUNER_PM_IQ_DOWN;
        p_foc->rotor_angle_mode = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP;
        p_foc->iq_down_step     = p_foc->ol_iq_down_step * p_foc->iq_ref;
    }

    switch (p_foc->flag_iq_ref)
    {
        case TUNER_PM_IQ_ZERO_CONST:
        {
            p_foc->rotor_angle_mode = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP;
            iq_ref_buff             = 0.0F;
            temp0 = fabsf(p_foc->speed_1ms_rad);

            if (temp0 >= p_foc->id_down_speed_rad)
            {
                p_foc->flag_iq_ref            = TUNER_PM_IQ_SPEED_PI_OUTPUT;
                p_foc->rotor_angle_mode       = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_CLOSEDLOOP;
                p_foc->pll_est.f4_i_est_speed = p_foc->ref_speed_rad_ctrl;
            }

            break;
        }

        case TUNER_PM_IQ_SPEED_PI_OUTPUT:
        {
            /*** speed PI control ***/
            p_foc->pi_speed.f4_err = p_foc->ref_speed_rad_ctrl - p_foc->speed_1ms_rad;
            iq_ref_buff            = rm_motor_pi_ctrl(&p_foc->pi_speed);

            /*** iq reference limit ***/
            iq_ref_buff = rm_motor_filter_limitf_abs(iq_ref_buff, p_foc->lim_iq);
            break;
        }

        case TUNER_PM_IQ_DOWN:
        {
            iq_ref_buff = p_foc->iq_ref - p_foc->iq_down_step;
            temp0       = p_foc->iq_down_step * iq_ref_buff; /* check sign */
            if (temp0 <= 0)
            {
                iq_ref_buff        = 0.0F;
                p_foc->flag_iq_ref = TUNER_PM_IQ_ZERO_CONST;
            }

            break;
        }

        default:
        {
            /* Do Nothing */
            break;
        }
    }

    /* return iq reference */
    return iq_ref_buff;
}

/*******************************************************************************************************************//**
 * @brief  Generate Id reference
 * @param[in] p_foc   Pointer to motor tuner FOC core structure
 * @return Id reference [A]
 **********************************************************************************************************************/
static float core_generate_id_ref (motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;
    float id_ref_buff = 0.0F;

    if (TUNER_PM_FLG_SET == p_foc->flag_down_to_ol)
    {
        p_foc->flag_id_ref = TUNER_PM_ID_UP;
    }

    switch (p_foc->flag_id_ref)
    {
        case TUNER_PM_ID_UP:
        {
            id_ref_buff = p_foc->id_ref + p_foc->id_up_step;
            if (id_ref_buff >= p_foc->open_loop_id)
            {
                id_ref_buff        = p_foc->open_loop_id;
                p_foc->flag_id_ref = TUNER_PM_ID_CONST;
            }

            break;
        }

        case TUNER_PM_ID_CONST:
        {
            id_ref_buff = p_foc->id_ref;
            if (!rm_motor_tuner_is_equalf(p_foc->open_loop_id, id_ref_buff))
            {
                id_ref_buff = p_foc->open_loop_id;
            }

            temp0 = fabsf(p_foc->ref_speed_rad_ctrl);
            if (temp0 >= p_foc->id_down_speed_rad)
            {
                p_foc->flag_id_ref = TUNER_PM_ID_DOWN;
            }

            break;
        }

        case TUNER_PM_ID_DOWN:
        {
            id_ref_buff = p_foc->id_ref - p_foc->id_down_step;
            if (id_ref_buff < 0.0F)
            {
                id_ref_buff        = 0.0F;
                p_foc->flag_id_ref = TUNER_PM_ID_ZERO_CONST;
            }

            break;
        }

        case TUNER_PM_ID_ZERO_CONST:
        {
            id_ref_buff = 0.0F;
            break;
        }

        default:
        {
            TUNER_PM_ASSERT_FAIL();
            break;
        }
    }

    /* return id reference */
    return id_ref_buff;
}

/*******************************************************************************************************************//**
 * @brief  Generates speed command
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 * @return Speed command value [rad/s]
 **********************************************************************************************************************/
static float core_generate_speed_ref (motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;
    float temp1;
    float speed_rad_ref_buff = 0.0F;

    switch (p_foc->flag_speed_ref)
    {
        case TUNER_PM_SPEED_HOLD:
        {
            /* The final speed command is hold, not reset to zero,
             * preventing unintentional speed command reset */
            speed_rad_ref_buff = p_foc->ref_speed_rad_ctrl;
            if (TUNER_PM_ID_CONST == p_foc->flag_id_ref)
            {
                p_foc->flag_speed_ref = TUNER_PM_SPEED_CHANGE;
            }

            break;
        }

        case TUNER_PM_SPEED_CHANGE:
        {
            temp0              = p_foc->ref_speed_rad - p_foc->ref_speed_rad_ctrl;
            temp1              = fminf(p_foc->limit_speed_change * p_foc->spd_ctrl_period_ms, fabsf(temp0));
            speed_rad_ref_buff = p_foc->ref_speed_rad_ctrl + copysignf(temp1, temp0);
            break;
        }

        default:
        {
            TUNER_PM_ASSERT_FAIL();
            break;
        }
    }

    /* return speed reference */
    return speed_rad_ref_buff;
}

/*******************************************************************************************************************//**
 * @brief  Over current error check
 * @param[in] p_foc               Pointer to motor tuner core FOC structure
 * @param[in] iu                  Phase U current [A]
 * @param[in] iv                  Phase V current [A]
 * @param[in] iw                  Phase W current [A]
 * @param[in] overcurrent_limit   Over current limit [A]
 **********************************************************************************************************************/
static void core_check_over_current_error (motor_tuner_pm_core_foc_t * p_foc,
                                           float                       iu,
                                           float                       iv,
                                           float                       iw,
                                           float                       overcurrent_limit)
{
    float temp0;

    temp0 = fabsf(iu);
    if (temp0 > overcurrent_limit)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_OVER_CURRENT_SW);
    }

    temp0 = fabsf(iv);
    if (temp0 > overcurrent_limit)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_OVER_CURRENT_SW);
    }

    temp0 = fabsf(iw);
    if (temp0 > overcurrent_limit)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_OVER_CURRENT_SW);
    }
}

/*******************************************************************************************************************//**
 * @brief Over voltage error check
 * @param[in] p_foc               Pointer to motor tuner core FOC structure
 * @param[in] vdc                 DC bus voltage [V]
 * @param[in] overvoltage_limit   Over voltage limit [V]
 **********************************************************************************************************************/
static void core_check_over_voltage_error (motor_tuner_pm_core_foc_t * p_foc, float vdc, float overvoltage_limit)
{
    if (vdc > overvoltage_limit)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_OVER_VOLTAGE); /* over voltage error */
    }
}

/*******************************************************************************************************************//**
 * @brief Under voltage error check
 * @param[in] p_foc                 Pointer to motor tuner core FOC structure
 * @param[in] vdc                   DC bus voltage [V]
 * @param[in] undervoltage_limit     Under voltage limit [V]
 **********************************************************************************************************************/
static void core_check_under_voltage_error (motor_tuner_pm_core_foc_t * p_foc, float vdc, float undervoltage_limit)
{
    if (vdc < undervoltage_limit)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_UNDER_VOLTAGE); /* under voltage error */
    }
}

/*******************************************************************************************************************//**
 * @brief  Abort request check
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 **********************************************************************************************************************/
static void core_check_abort (motor_tuner_pm_core_foc_t * p_foc)
{
    if (p_foc->abort_request)
    {
        tuner_pm_core_throw_error(p_foc, p_foc->error_status);
        p_foc->abort_request = false;
    }
}

/*******************************************************************************************************************//**
 * @brief  Estimates rotor angle and speed using PLL
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 **********************************************************************************************************************/
static void core_angle_speed_est (motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;

    if ((MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_CLOSEDLOOP) == p_foc->rotor_angle_mode)
    {
        /* Estimate angle and speed with PLL */
        rm_motor_bemf_obs_pll(&p_foc->pll_est, p_foc->phase_error, &p_foc->speed_rad);
    }
    else if ((MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP) == p_foc->rotor_angle_mode)
    {
        /* speed setting */
        p_foc->speed_rad = p_foc->ref_speed_rad_ctrl;
    }
    else
    {
        /* Do nothing */
    }

    p_foc->speed_lpf_rad = rm_motor_filter_first_order_lpff(&p_foc->speed_lpf, p_foc->speed_rad);
    p_foc->angle_rad    += (p_foc->speed_rad * p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);

    temp0 = fabsf(p_foc->angle_rad);
    if (temp0 > TUNER_PM_TWOPI)
    {
        temp0            = temp0 - TUNER_PM_TWOPI;
        p_foc->angle_rad = copysignf(temp0, p_foc->angle_rad);
    }
}

/*******************************************************************************************************************//**
 * @brief  BEMF observer
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 **********************************************************************************************************************/
static void core_bemf_observer (motor_tuner_pm_core_foc_t * p_foc)
{
    rm_motor_bemf_obs_observer(&p_foc->bemf_observer,
                               &(p_foc->motor_params),
                               p_foc->vd_ref,
                               p_foc->vq_ref,
                               p_foc->id_ad,
                               p_foc->iq_ad);
    p_foc->ed = rm_motor_bemf_obs_calc_d(&p_foc->bemf_observer, &(p_foc->motor_params), p_foc->speed_rad, p_foc->iq_ad);
    p_foc->eq = rm_motor_bemf_obs_calc_q(&p_foc->bemf_observer, &(p_foc->motor_params), p_foc->speed_rad, p_foc->id_ad);

    /* BEMF estimate */
    p_foc->e = sqrtf((p_foc->ed * p_foc->ed) + (p_foc->eq * p_foc->eq));
    if (p_foc->eq < 0)
    {
        p_foc->e = -p_foc->e;
    }

    /* delta angle estimate */
    p_foc->phase_error = atan2f(p_foc->ed / p_foc->eq, 1.0F);
}

/*******************************************************************************************************************//**
 * @brief  Measures current offset
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 * @retval 0 Not completed yet
 * @retval 1 Completed
 **********************************************************************************************************************/
static uint32_t core_offset_measure (motor_tuner_pm_core_foc_t * p_foc)
{
    /* current offset detection */
    p_foc->offset_ia     = rm_motor_filter_lpff(p_foc->ia_ad, p_foc->pre_offset_ia, p_foc->offset_lpf_k);
    p_foc->pre_offset_ia = p_foc->offset_ia;
    p_foc->offset_ib     = rm_motor_filter_lpff(p_foc->ib_ad, p_foc->pre_offset_ib, p_foc->offset_lpf_k);
    p_foc->pre_offset_ib = p_foc->offset_ib;
    p_foc->offset_ic     = rm_motor_filter_lpff(p_foc->ic_ad, p_foc->pre_offset_ic, p_foc->offset_lpf_k);
    p_foc->pre_offset_ic = p_foc->offset_ic;
    p_foc->cnt_adjust++;

    return p_foc->cnt_adjust >= p_foc->offset_calc_time;
}

/*******************************************************************************************************************//**
 * @brief     Set-up voltage limiters with given phase voltage limit
 * @param[in] p_foc          Pointer to motor tuner core FOC structure
 * @param[in] voltage_limit  The phase voltage limit
 **********************************************************************************************************************/
static void core_set_voltage_limit (motor_tuner_pm_core_foc_t * p_foc, float voltage_limit)
{
    p_foc->vmag_max = voltage_limit * (TUNER_PM_SQRT_3 / TUNER_PM_SQRT_2);

    p_foc->vphase_limit = voltage_limit;

    /* Set integral limit for current regulators */
    p_foc->pi_vd.f4_ilimit = voltage_limit;
    p_foc->pi_vq.f4_ilimit = voltage_limit;
}

/*******************************************************************************************************************//**
 * @brief Restart motor drive without change configurations and controller gains
 * @param[in] p_foc   Pointer to motor tuner core FOC structure
 * @pre   p_foc->run_mode is under TUNER_PM_RUNMODE_INIT condition
 **********************************************************************************************************************/
static motor_tuner_request_t core_restart_drive (motor_tuner_pm_core_foc_t * p_foc)
{
    TUNER_PM_ASSERT(p_foc->run_mode == TUNER_PM_RUNMODE_INIT);

    /* Common */
    p_foc->sample_cnt = 0;
    p_foc->one_ms_cnt = 0;
    p_foc->sum_cnt    = 0;

    /* Reset modes */
    p_foc->rotor_angle_mode = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_0);
    p_foc->error_status    = MOTOR_TUNER_PM_ERROR_NONE;
    p_foc->flag_id_ref     = TUNER_PM_ID_UP;
    p_foc->flag_iq_ref     = TUNER_PM_IQ_ZERO_CONST;
    p_foc->flag_speed_ref  = TUNER_PM_SPEED_HOLD;
    p_foc->flag_down_to_ol = 0;
    p_foc->ctrl_conf       = 0;

    /* Motor driver */
    p_foc->ia_ad  = 0.0F;
    p_foc->ib_ad  = 0.0F;
    p_foc->vd_ref = 0.0F;
    p_foc->vq_ref = 0.0F;
    p_foc->ia_ref = 0.0F;
    p_foc->ib_ref = 0.0F;
    p_foc->id_ref = 0.0F;
    p_foc->iq_ref = 0.0F;
    p_foc->id_ad  = 0.0F;
    p_foc->iq_ad  = 0.0F;
    p_foc->vdc_ad = 0.0F;

    p_foc->imag_max = 1.0F;            /* This value will be overrided when setting rated current */

    /* Reset offset calibration */
    p_foc->offset_ia     = 0.0F;
    p_foc->offset_ib     = 0.0F;
    p_foc->pre_offset_ia = 0.0F;
    p_foc->pre_offset_ib = 0.0F;
    p_foc->cnt_adjust    = 0;

    /* Reset PLL */
    p_foc->phase_error = 0.0F;
    p_foc->speed_rad   = 0.0F;
    p_foc->angle_rad   = 0.0F;
    p_foc->temp_cos    = 1.0F;         /* Cos(0) */
    p_foc->temp_sin    = 0.0F;

    /* Reset current control */
    p_foc->kp_id         = 0.0F;
    p_foc->ki_id         = 0.0F;
    p_foc->kp_iq         = 0.0F;
    p_foc->ki_iq         = 0.0F;
    p_foc->pi_vd.f4_refi = 0.0F;
    p_foc->pi_vq.f4_refi = 0.0F;

    p_foc->ed    = 0.0F;
    p_foc->eq    = 0.0F;
    p_foc->e     = 0.0F;
    p_foc->e_lpf = 0.0F;

    /* Reset speed control, speed change rate limiter */
    p_foc->ref_speed_rad_ctrl = 0.0F;
    p_foc->ref_speed_rad      = 0.0F;
    p_foc->pi_speed.f4_refi   = 0.0F;

    /* Reset start-up sequence parameters */
    p_foc->id_down_speed_rad = 0.0F;
    p_foc->id_up_speed_rad   = 0.0F;
    p_foc->id_up_step        = 0.0F;
    p_foc->id_down_step      = 0.0F;
    p_foc->open_loop_id      = 0.0F;
    p_foc->iq_down_step      = 0.0F;

    /* Resets modulation */
    p_foc->va_ref       = 0.0F;
    p_foc->vb_ref       = 0.0F;
    p_foc->vc_ref       = 0.0F;
    p_foc->va_ref_comp  = 0.0F;
    p_foc->vb_ref_comp  = 0.0F;
    p_foc->vc_ref_comp  = 0.0F;
    p_foc->vphase_limit = 0.0F;
    p_foc->moda         = 0.0F;
    p_foc->modb         = 0.0F;
    p_foc->modc         = 0.0F;

    /* Reset voltage error compensation */
    p_foc->vcomp_array[0]   = 0.0F;
    p_foc->vcomp_array[1]   = 0.0F;
    p_foc->vcomp_array[2]   = 0.0F;
    p_foc->vcomp_i_array[0] = 0.0F;
    p_foc->vcomp_i_array[1] = 0.0F;
    p_foc->vcomp_i_array[2] = 0.0F;

    /* Reset speed LPF */
    p_foc->speed_lpf_rad      = 0.0F;
    p_foc->speed_1ms_rad      = 0.0F;
    p_foc->speed_lpf_omega_hz = TUNER_PM_CORE_PRV_SPEED_LPF_BAND_HZ;
    rm_motor_filter_first_order_lpff_reset(&p_foc->speed_lpf);

    return MOTOR_TUNER_REQUEST_START;
}

/*******************************************************************************************************************//**
 * @brief     Performs multiple filter process on estimated signals
 *
 * @param[in] p_foc           Pointer to motor tuner core FOC structure
 * @param[in] phase_error_rad  The phase error in [rad]
 * @param[in] est_bemf         The estimated magnitude of BEMF [V]
 **********************************************************************************************************************/
static void core_estimator_filter (motor_tuner_pm_core_foc_t * p_foc, float phase_error_rad, float est_bemf)
{
    float phase_error_lpf_pre;
    float lpf_num =
        ((TUNER_PM_TWOPI * p_foc->p_cfg->phaseerr_lpf_band_hz) * (p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND));
    float lpf_den = 1.0F -
                    ((TUNER_PM_TWOPI * p_foc->p_cfg->phaseerr_lpf_band_hz) *
                     (p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND));

    phase_error_lpf_pre    = p_foc->phase_error_lpf;
    p_foc->phase_error_lpf = (p_foc->phase_error_lpf * lpf_den) + (phase_error_rad * lpf_num);
    p_foc->phase_error_hpf = (p_foc->phase_error_hpf * lpf_den) +
                             ((p_foc->phase_error_lpf - phase_error_lpf_pre) * (p_foc->ctrl_freq_hz * lpf_num));

    p_foc->e_lpf = p_foc->e_lpf * lpf_den + est_bemf * lpf_num;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_MOTOR_TUNER_PM_CORE)
 **********************************************************************************************************************/
