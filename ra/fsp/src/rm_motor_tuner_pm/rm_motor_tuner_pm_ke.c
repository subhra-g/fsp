/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include <math.h>
#include "rm_motor_tuner_pm_ke.h"
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE         (105)
#endif
#define KE_PRV_KI_MULT                  (0.2F)
#define KE_PRV_TARGET_STEADY_TIME_MS    (1000.0F)
#define KE_PRV_STAB_WAIT_TIMEOUT        (10000.0F)
#define KE_PRV_SPEED_ERR_TH             (0.02F)
#define KE_PRV_RESULT_MIN_TOL_COEF      (0.8F)

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void ke_seq_init(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);
static void ke_seq_ready(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);
static void ke_seq_measure(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);
static void ke_seq_check(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);
static void ke_seq_reset(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);
static void ke_prepare_closed_loop(motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Execute KE identification state machine
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 * @retval 0   Identification not completed
 * @retval 1   Identification completed
 **********************************************************************************************************************/
uint16_t tuner_pm_ke_act (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    uint16_t ret = 0;

    switch (p_ke->ke_status)
    {
        case TUNER_PM_SEQ_KE_INIT:
        {
            ke_seq_init(p_ke, p_foc);
            break;
        }

        case TUNER_PM_SEQ_KE_READY:
        {
            ke_seq_ready(p_ke, p_foc);
            break;
        }

        case TUNER_PM_SEQ_KE_MEASURE:
        {
            ke_seq_measure(p_ke, p_foc);
            break;
        }

        case TUNER_PM_SEQ_KE_CHECK:
        {
            ke_seq_check(p_ke, p_foc);
            break;
        }

        case TUNER_PM_SEQ_KE_RESET:
        {
            ke_seq_reset(p_ke, p_foc);
            break;
        }

        case TUNER_PM_SEQ_KE_COMPLETED:
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
 * @brief Reset KE identification module
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 ************************************************************************************************************************/
void tuner_pm_ke_reset (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    int32_t index;

    FSP_PARAMETER_NOT_USED(p_foc);

    /* Ke */
    p_ke->ke_status           = TUNER_PM_SEQ_KE_INIT;
    p_ke->sample_cnt          = 0;
    p_ke->time_elapsed_ms     = 0.0F;
    p_ke->time_steady_ms      = 0.0F;
    p_ke->ol_freq_ref_hz      = 0.0F;  /* Will be determined in seq_init */
    p_ke->id_ref_step         = 0.0F;  /* Will be determined in seq_init */
    p_ke->ol_freq_ref_step_hz = 0.0F;  /* Will be determined in seq_init */
    p_ke->e_sum               = 0.0F;
    p_ke->ed_sum              = 0.0F;
    p_ke->eq_sum              = 0.0F;
    p_ke->speed_rad_sum       = 0.0F;
    p_ke->vd_ref_sum          = 0.0F;
    p_ke->vq_ref_sum          = 0.0F;
    p_ke->speed_rad_ave       = 0.0F;
    p_ke->vd_ref_ave          = 0.0F;
    p_ke->vq_ref_ave          = 0.0F;
    p_ke->ed_ave              = 0.0F;
    p_ke->eq_ave              = 0.0F;
    p_ke->id_ave              = 0.0F;
    p_ke->ke_max              = 0.0F;
    p_ke->ke_min              = 0.0F;
    p_ke->no_stop             = false;
    for (index = 0; index < MOTOR_TUNER_PM_KE_LINEREG_NUM; index++)
    {
        p_ke->ke_over_id[index] = 0.0F;
        p_ke->id[index]         = 0.0F;
    }

    p_ke->index = 0;
}

/*******************************************************************************************************************//**
 * @brief Configure no stop flag for KE identification
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 * @param[in] no_stop   true(1): Do not stop, false(0): Stop on identification completed
 ***********************************************************************************************************************/
void tuner_pm_ke_config_no_stop_flag (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc, uint8_t no_stop)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_ke->no_stop = no_stop;
}

/*******************************************************************************************************************//**
 * @brief Initialize sequence for KE identification
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 ************************************************************************************************************************/
static void ke_seq_init (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    motor_tuner_pm_core_foc_cfg_t const * p_foc_cfg = p_foc->p_cfg;

    /* PI gains will be designed with motor parameters stored in CORE module */
    tuner_pm_core_config_current_pi_gains(p_foc, p_foc_cfg->current_omega_hz, p_foc_cfg->current_zeta);
    tuner_pm_core_config_bemf_obsv(p_foc, p_foc_cfg->e_obs_omega_hz, p_foc_cfg->e_obs_zeta);

    /* Update derived parameters */
    p_ke->id_ref_step = (p_foc->imag_max * p_foc_cfg->id_ref_coef) / p_foc_cfg->id_up_time *
                        p_foc->ctrl_period_ms;
    p_ke->ol_freq_ref_step_hz = p_ke->p_cfg->ol_ramp_up_rate_hzps * p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND; /* Hz/s to Hz/tick */

    /* Reset states */
    p_ke->ol_freq_ref_hz = 0.0F;
    p_ke->e_sum          = 0.0F;
    p_ke->speed_rad_sum  = 0.0F;
    p_ke->vd_ref_sum     = 0.0F;
    p_ke->vq_ref_sum     = 0.0F;

    p_ke->time_elapsed_ms = 0.0F;
    p_ke->ke_status       = TUNER_PM_SEQ_KE_READY;
    p_ke->ke_sub_seq      = KE_OL_ID_RAMPUP;

    p_foc->id_ref = 0.0F;

    /* Upgrade control level to enable BEMF observer and current PI controller */
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_3);
}

/*******************************************************************************************************************//**
 * @brief Ready sequence before starting KE measurement, ramp-up Id and speed in open-loop
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 ***********************************************************************************************************************/
static void ke_seq_ready (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ke->time_elapsed_ms += p_foc->ctrl_period_ms;
    switch (p_ke->ke_sub_seq)
    {
        case KE_OL_ID_RAMPUP:
        {
            /* Ramp-up id to prepare starting acceleration */
            p_foc->id_ref += p_ke->id_ref_step;
            p_foc->iq_ref  = 0.0F;
            if (p_ke->time_elapsed_ms > p_foc->p_cfg->id_up_time)
            {
                p_ke->ke_sub_seq      = KE_OL_SPEED_RAMPUP;
                p_ke->time_elapsed_ms = 0.0F;
            }

            break;
        }

        case KE_OL_SPEED_RAMPUP:
        {
            /* Accelerate motor to apparent speed to achieve enough BEMF,
             * acceleration will be stopped at specified target frequency (ol_target_freq_hz)
             * or when estimated back-EMF exceeds a threshold related to maximum voltage,
             * which indicates SNR is enough for KE measurement.
             *  */
            if ((fabsf(p_foc->e_lpf) > (p_foc->vmag_max * p_ke->p_cfg->bemf_threshold_coef)) ||
                (p_ke->ol_freq_ref_hz > p_ke->p_cfg->ol_target_freq_hz))
            {
                p_ke->ke_sub_seq      = KE_OL_MEASURE_WAIT_STAB;
                p_ke->ke_status       = TUNER_PM_SEQ_KE_MEASURE;
                p_ke->time_elapsed_ms = 0.0F;
                p_ke->sample_cnt      = 0;
            }
            else
            {
                p_ke->ol_freq_ref_hz     += p_ke->ol_freq_ref_step_hz;
                p_foc->ref_speed_rad_ctrl = p_ke->ol_freq_ref_hz * TUNER_PM_TWOPI;
                p_foc->speed_rad          = p_foc->ref_speed_rad_ctrl;
            }

            break;
        }

        default:
            TUNER_PM_ASSERT_FAIL();
    }
}

/*******************************************************************************************************************//**
 * @brief Measure Ke in open-loop and closed-loop, main measurement process
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 ************************************************************************************************************************/
static void ke_seq_measure (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ke->time_elapsed_ms += p_foc->ctrl_period_ms;
    switch (p_ke->ke_sub_seq)
    {
        case KE_OL_MEASURE_WAIT_STAB:
        {
            if (p_ke->time_elapsed_ms >= (p_ke->p_cfg->ol_stab_wait_ms))
            {
                p_ke->time_elapsed_ms = 0.0F;
                p_ke->sample_cnt      = 0;
                p_ke->ke_sub_seq      = KE_OL_MEASURE_SAMPLING;
            }

            break;
        }

        case KE_OL_MEASURE_SAMPLING:
        {
            /* Maintain the speed and acquire data for flux estimation */
            p_foc->ref_speed_rad_ctrl = p_ke->ol_freq_ref_hz * TUNER_PM_TWOPI;

            p_ke->e_sum         += p_foc->e;
            p_ke->speed_rad_sum += (p_ke->ol_freq_ref_hz * TUNER_PM_TWOPI);
            p_ke->vd_ref_sum    += p_foc->vd_ref;
            p_ke->vq_ref_sum    += p_foc->vq_ref;
            p_ke->ed_sum        += p_foc->ed;
            p_ke->eq_sum        += p_foc->eq;
            p_ke->sample_cnt++;

            if (p_ke->time_elapsed_ms >= (p_ke->p_cfg->measure_time_ms))
            {
                if (p_ke->index < MOTOR_TUNER_PM_KE_LINEREG_NUM)
                {
                    float one_div_sample_cnt;

                    p_ke->ke_open = p_ke->e_sum / p_ke->speed_rad_sum;

                    /* Cache the 1/(number of sample) to improve performance */
                    one_div_sample_cnt  = 1.0F / (float) p_ke->sample_cnt;
                    p_ke->vd_ref_ave    = p_ke->vd_ref_sum * one_div_sample_cnt;
                    p_ke->vq_ref_ave    = p_ke->vq_ref_sum * one_div_sample_cnt;
                    p_ke->speed_rad_ave = p_ke->speed_rad_sum * one_div_sample_cnt;
                    p_ke->ed_ave        = p_ke->ed_sum * one_div_sample_cnt;
                    p_ke->eq_ave        = p_ke->eq_sum * one_div_sample_cnt;
                    p_ke->id_ave        = p_foc->id_ref;

                    /* Reset accumulated values and start measurement with lower id */
                    p_foc->iq_ref                 = 0.0F;
                    p_ke->e_sum                   = 0.0F;
                    p_ke->ed_sum                  = 0.0F;
                    p_ke->eq_sum                  = 0.0F;
                    p_ke->speed_rad_sum           = 0.0F;
                    p_ke->vd_ref_sum              = 0.0F;
                    p_ke->vq_ref_sum              = 0.0F;
                    p_ke->id[p_ke->index]         = p_ke->id_ave;
                    p_ke->ke_over_id[p_ke->index] = p_ke->ke_open;
                    p_ke->index++;

                    if (MOTOR_TUNER_PM_KE_LINEREG_NUM == p_ke->index)
                    {
#if (MOTOR_TUNER_PM_KE_LINEREG_NUM > 1)
                        float slope;
                        float intercept;

                        rm_motor_tuner_linear_regression(p_ke->id,
                                                         p_ke->ke_over_id,
                                                         MOTOR_TUNER_PM_KE_LINEREG_NUM,
                                                         &slope,
                                                         &intercept);
                        p_ke->ke_open = intercept;
#elif (MOTOR_TUNER_PM_KE_LINEREG_NUM == 1)
                        p_ke->ke_open = p_ke->ke_over_id[0];
#else
 #error "Invalid number of samples of Ke linear regression"
#endif
                        p_ke->time_elapsed_ms = 0;

                        ke_prepare_closed_loop(p_ke, p_foc);
                        p_ke->ke_sub_seq = KE_CL_SPEED_RAMPUP;
                    }
                    else
                    {
                        /* Reset timer and acquire more sample on different Id conditions */
                        p_foc->id_ref         = p_foc->id_ref * p_foc->p_cfg->id_ref_coef;
                        p_ke->time_elapsed_ms = 0;
                        p_ke->ke_sub_seq      = KE_OL_MEASURE_WAIT_STAB;
                    }
                }
            }

            break;
        }

        case KE_OL_SPEED_SLOPE_DOWN:
        {
            /* Slow-down the speed after acquired enough samples */
            p_foc->ref_speed_rad_ctrl -= (p_ke->ol_freq_ref_step_hz * TUNER_PM_TWOPI);
            p_foc->ref_speed_rad       = p_foc->ref_speed_rad_ctrl;
            if (p_foc->ref_speed_rad_ctrl <= 0.0F)
            {
                ke_prepare_closed_loop(p_ke, p_foc);
                p_ke->ke_sub_seq = KE_CL_SPEED_RAMPUP;
            }

            break;
        }

        case KE_CL_SPEED_RAMPUP:
        {
            if (p_foc->ref_speed_rad_ctrl >= p_foc->ref_speed_rad)
            {
                p_ke->ke_sub_seq      = KE_CL_WAIT_STAB;
                p_ke->time_elapsed_ms = 0;
            }

            break;
        }

        case KE_CL_WAIT_STAB:
        {
            float speed_err_ratio;

            p_ke->time_steady_ms += p_foc->ctrl_period_ms;
            speed_err_ratio       = p_foc->speed_lpf_rad / p_foc->ref_speed_rad - 1.0F;
            if (fabsf(speed_err_ratio) > KE_PRV_SPEED_ERR_TH)
            {
                p_ke->time_steady_ms = 0.0F;
            }

            if ((p_ke->time_steady_ms > KE_PRV_TARGET_STEADY_TIME_MS) ||
                (p_ke->time_elapsed_ms > KE_PRV_STAB_WAIT_TIMEOUT))
            {
                p_ke->time_elapsed_ms = 0;
                p_ke->e_sum           = 0.0F;
                p_ke->speed_rad_sum   = 0.0F;
                p_ke->ke_sub_seq      = KE_CL_MEASURE;
            }

            break;
        }

        case KE_CL_MEASURE:
        {
            p_ke->e_sum         += p_foc->e;
            p_ke->speed_rad_sum += p_foc->speed_rad;
            p_ke->sample_cnt++;
            if (p_ke->time_elapsed_ms > p_ke->p_cfg->measure_time_ms)
            {
                p_ke->ke_closed_loop = p_ke->e_sum / p_ke->speed_rad_sum;
                if (true == p_ke->no_stop)
                {
                    p_ke->ke_status = TUNER_PM_SEQ_KE_CHECK;
                }
                else
                {
                    p_ke->ke_sub_seq = KE_CL_SPEED_SLOPE_DOWN;
                }
            }

            break;
        }

        case KE_CL_SPEED_SLOPE_DOWN:
        {
            /* Slow-down the speed after acquired enough samples */
            p_foc->ref_speed_rad_ctrl -= (p_ke->ol_freq_ref_step_hz * TUNER_PM_TWOPI);
            if (p_foc->ref_speed_rad_ctrl <= 0.0F)
            {
                p_ke->ke_status = TUNER_PM_SEQ_KE_CHECK;
            }

            p_foc->ref_speed_rad = p_foc->ref_speed_rad_ctrl;
            break;
        }

        default:
            TUNER_PM_ASSERT_FAIL();
    }
}

/*******************************************************************************************************************//**
 * @brief Check validity of identified Ke value
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 **********************************************************************************************************************/
static void ke_seq_check (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    float temp0;
    float temp1;

    temp0        = p_ke->vd_ref_ave * p_ke->vd_ref_ave;
    temp1        = p_ke->vq_ref_ave * p_ke->vq_ref_ave;
    temp0        = sqrtf(temp0 + temp1);
    p_ke->ke_max = temp0 / p_ke->speed_rad_ave;

    temp0        = p_ke->vq_ref_ave - (p_ke->speed_rad_ave * p_foc->ld * p_ke->id_ave);
    temp0        = fabsf(temp0);
    p_ke->ke_min = (temp0 / p_ke->speed_rad_ave) * KE_PRV_RESULT_MIN_TOL_COEF;

    if ((p_ke->ke_open > p_ke->ke_max) || (p_ke->ke_open <= p_ke->ke_min))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_KE);
    }

    p_ke->ke_status       = TUNER_PM_SEQ_KE_RESET;
    p_ke->time_elapsed_ms = 0.0F;
}

/*******************************************************************************************************************//**
 * @brief Reset sequence after KE identification is done
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 **********************************************************************************************************************/
static void ke_seq_reset (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ke->time_elapsed_ms += p_foc->ctrl_period_ms;

    if (p_ke->no_stop == false)
    {
        p_foc->vd_ref             = 0.0F;
        p_foc->vq_ref             = 0.0F;
        p_foc->id_ref             = 0.0F;
        p_foc->iq_ref             = 0.0F;
        p_foc->angle_rad          = 0.0F;
        p_foc->ref_speed_rad_ctrl = 0.0F;
        p_foc->speed_rad          = 0.0F;
    }

    p_ke->ol_freq_ref_hz = 0.0F;

    if (p_ke->time_elapsed_ms > p_ke->p_cfg->reset_time_ms)
    {
        p_ke->time_elapsed_ms = 0;
        p_ke->ke_status       = TUNER_PM_SEQ_KE_COMPLETED;
        p_ke->ke_sub_seq      = KE_IDLE;
    }
}

/*******************************************************************************************************************//**
 * @brief Configure start-up parameter, gains of speed controller and other necessary parameters for starting
 *        KE identification with closed-loop FOC
 * @param[in] p_ke   Pointer to motor tuner KE instance
 * @param[in] p_foc  Pointer to motor tuner CORE FOC instance
 **********************************************************************************************************************/
static void ke_prepare_closed_loop (motor_tuner_pm_ke_t * p_ke, motor_tuner_pm_core_foc_t * p_foc)
{
    motor_tuner_pm_core_foc_cfg_t const * p_foc_cfg = p_foc->p_cfg;
    float base_speed;
    float kp;
    float kidt;
    float speed_el_over_iq;
    float inertia_over_iq;
    float flux_q_on_base_speed = p_foc->lq * p_foc->imag_max;

    base_speed = p_foc->vmag_max /
                 sqrtf((p_ke->ke_open * p_ke->ke_open) + (flux_q_on_base_speed * flux_q_on_base_speed));
    tuner_pm_core_set_startup_params(p_foc,
                                     p_foc->imag_max * p_foc_cfg->id_ref_coef,
                                     p_foc_cfg->ol2cl_speed_th_coef * base_speed,
                                     p_foc_cfg->cl2ol_speed_th_coef * base_speed);

    /* Since inertia is unknown in this stage, calculate the speed PI gains using assumed inertia */
    speed_el_over_iq = p_ke->ke_open * p_foc->pole_pairs * p_foc->pole_pairs;
    inertia_over_iq  = p_foc_cfg->assumed_inertia / speed_el_over_iq;

    /*
     * Speed Kp, Ki calculation
     * Kp = (speed_omega * 2π * 2) * (J / (Ke * P^2))
     * Ki = (2π * speed_omega)^2 * 0.2 * (J / (Ke * P^2)) * Tctrl
     * Ignore magic number lint for better readability
     */
    kp   = (p_foc_cfg->speed_omega * TUNER_PM_TWOPI * 2.0F) * inertia_over_iq; // NOLINT(readability-magic-numbers)
    kidt = (TUNER_PM_TWOPI * p_foc_cfg->speed_omega * TUNER_PM_TWOPI * p_foc_cfg->speed_omega) *
           KE_PRV_KI_MULT * inertia_over_iq * p_foc->spd_ctrl_period_ms * TUNER_PM_MS_TO_SECOND;

    /* Set PI gains through the common AID core interface */
    tuner_pm_core_set_speed_pi(p_foc, kp, kidt);
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_4);

    p_foc->ref_speed_rad      = base_speed * p_foc_cfg->speed_offset_coef;
    p_foc->limit_speed_change = p_foc_cfg->speed_change_rate_limit;
}
