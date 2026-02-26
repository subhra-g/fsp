/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup RM_MOTOR_TUNER_PM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/

/* Standard library headers */
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* Main associated headers */
#include "rm_motor_tuner_pm.h"
#include "rm_motor_tuner_api.h"
#include "rm_motor_tuner_pm_internal.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE         (100) ///< File code for error tracking
#endif

#define TUNER_PM_PRV_EVENT_COMPLETED    (5U)  ///< The internal COMPLETED event */
#define TUNER_PM_PRV_EVENT_ERROR        (6U)  ///< The internal ERROR event */

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* Function prototypes of static functions */
static void     tuner_pm_reset(motor_tuner_pm_instance_ctrl_t * p_instance);
static void     tuner_pm_revert_to_last_tune_stage(motor_tuner_pm_instance_ctrl_t * p_instance, uint16_t * p_paramode);
static void     tuner_pm_motorid_sequence(motor_tuner_pm_instance_ctrl_t * p_instance);
static void     tuner_pm_motorid_sequence_post(motor_tuner_pm_instance_ctrl_t * p_instance);
static void     tuner_pm_act_tune_init(motor_tuner_pm_instance_ctrl_t * p_instance_ctrl);
static void     tuner_pm_act_tune_end(motor_tuner_pm_instance_ctrl_t * p_instance_ctrl);
static uint16_t tuner_pm_get_next_tune_stage(motor_tuner_pm_instance_ctrl_t * p_instance_ctrl);
static float    tuner_pm_design_base_speed(float flux_wb, float r, float lq, float va_max, float ia_max);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief     State machine function event handler
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 * @param[in] event  The event code TUNER_PM_COMMAND_<CMD> group is available, in addition,
 *                   TUNER_PM_PRV_EVENT_COMPLETED is also available for completed event
 **********************************************************************************************************************/
void tuner_pm_state_machine_event (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl, uint16_t event)
{
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    switch (p_instance_ctrl->tune_status)
    {
        /* These case are intentionally combined */
        case MOTOR_TUNER_STATUS_READY:
        case MOTOR_TUNER_STATUS_COMPLETED:
        {
            if (TUNER_PM_COMMAND_START == event)
            {
                tuner_pm_reset(p_instance_ctrl);
                p_instance_ctrl->total_time_elapsed = 0.0F;
                p_instance_ctrl->tune_status        = MOTOR_TUNER_STATUS_RUNNING;
                p_instance_ctrl->last_request       = MOTOR_TUNER_REQUEST_START;
            }
            /* The RESUME command is available only when the last identification is not completed */
            else if ((TUNER_PM_COMMAND_RESUME == event) && (MOTOR_TUNER_PM_STAGE_INIT != p_instance_ctrl->tune_stage))
            {
                tuner_pm_revert_to_last_tune_stage(p_instance_ctrl, &p_instance_ctrl->tune_stage);
                p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_RUNNING;
                p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_START;
            }
            else if (TUNER_PM_PRV_EVENT_ERROR == event)
            {
                p_instance_ctrl->tune_status = MOTOR_TUNER_STATUS_ERROR;
            }
            else
            {
                /* Do nothing */
            }

            break;
        }

        case MOTOR_TUNER_STATUS_RUNNING:
        {
            if (TUNER_PM_COMMAND_STOP == event)
            {
                p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_RESET;
                p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_STOP;
            }
            else if (TUNER_PM_PRV_EVENT_COMPLETED == event)
            {
                p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_COMPLETED;
                p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_STOP;
            }
            else if (TUNER_PM_PRV_EVENT_ERROR == event)
            {
                p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_ERROR;
                p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_STOP;
            }
            else
            {
                /* Do nothing */
            }

            break;
        }

        case MOTOR_TUNER_STATUS_ERROR:
        {
            if (TUNER_PM_COMMAND_RESET == event)
            {
                p_instance_ctrl->tune_status = MOTOR_TUNER_STATUS_RESET;
            }
            else if (TUNER_PM_COMMAND_RESUME == event)
            {
                tuner_pm_core_clear_error(p_foc);
                tuner_pm_revert_to_last_tune_stage(p_instance_ctrl, &p_instance_ctrl->tune_stage);
                p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_RUNNING;
                p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_START;
            }
            else
            {
                /* Do nothing */
            }

            break;
        }

        case MOTOR_TUNER_STATUS_RESET:
        {
            tuner_pm_core_stop(p_foc);
            tuner_pm_core_clear_error(p_foc);
            p_instance_ctrl->tune_status = MOTOR_TUNER_STATUS_READY;
            break;
        }

        default:
        {
            TUNER_PM_ASSERT_FAIL();
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Implementation of on error event in CORE module
 * @param[in] p_foc        Pointer to motor tuner core FOC structure
 * @param[in] error_code  The error code
 **********************************************************************************************************************/
void tuner_pm_core_hook_on_error (motor_tuner_pm_core_foc_t * p_foc, uint16_t error_code)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_foc->p_context;

    (void) p_foc;                      /* Unused */
    (void) error_code;                 /* Unused */

    p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_STOP;
    p_instance_ctrl->tune_status  = MOTOR_TUNER_STATUS_ERROR;
}

/*******************************************************************************************************************//**
 * @brief Hook function implementation called before current control in each inner loop cyclic execution
 * @param[in] p_context  The pointer to the context of motor tuner instance control
 **********************************************************************************************************************/
void tuner_pm_core_hook_before_current_ctrl (void * p_context)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_context;
    tuner_pm_motorid_sequence(p_instance_ctrl);
}

/**
 * @brief Hook function implementation called after PWM output in each inner loop cyclic execution
 * @param[in] p_context  The pointer to the context of motor tuner instance control
 */
void tuner_pm_core_hook_after_pwmoutput (void * p_context)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_context;
    tuner_pm_motorid_sequence_post(p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * @brief Reset tuner for next identification
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 * @details All submodule will be reset, derived parameter such as rated speed/torque will be cleared
 * @warning CORE module will also be reset so the identified parameter will be lost.
 **********************************************************************************************************************/
static void tuner_pm_reset (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    /* Sequence */
    p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_INIT;
    tuner_pm_core_reset(p_foc);        /* This will also resets motor parameters */

    /* Input */
    p_foc->rated_current = 0.0F;
    p_foc->rated_power   = 0.0F;
    p_foc->pole_pairs    = 0.0F;

    tuner_pm_volterr_reset(&p_instance_ctrl->tuner_volterr, p_foc);
    tuner_pm_rdiff_reset(&p_instance_ctrl->tuner_rdiff, p_foc);
    tuner_pm_ldq_reset(&p_instance_ctrl->tuner_ldq, p_foc);
    tuner_pm_ke_reset(&p_instance_ctrl->tuner_ke, p_foc);
    tuner_pm_jd_reset(&p_instance_ctrl->tuner_jd, p_foc);

    /* Derived parameters */
    p_instance_ctrl->rated_speed_mech_rpm = 0.0F;
    p_instance_ctrl->rated_speed_elec_rad = 0.0F;
    p_instance_ctrl->rated_torque_nm      = 0.0F;
}

/*******************************************************************************************************************//**
 * @brief Revert identification to latest state that is able to restart
 * @param[in] p_instance  Pointer to motor tuner instance control structure
 * @param[in,out] p_paramode  Pointer to tuning stage variable
 **********************************************************************************************************************/
static void tuner_pm_revert_to_last_tune_stage (motor_tuner_pm_instance_ctrl_t * p_instance, uint16_t * p_paramode)
{
    motor_tuner_pm_core_foc_t * p_foc = &p_instance->base_foc;

    switch (*p_paramode)
    {
        case MOTOR_TUNER_PM_STAGE_VOLTERR:
        {
            tuner_pm_volterr_reset(&p_instance->tuner_volterr, p_foc);
            break;
        }

        case MOTOR_TUNER_PM_STAGE_R_DIFF:
        {
            tuner_pm_rdiff_reset(&p_instance->tuner_rdiff, p_foc);
            p_foc->r = 0.0F;
            break;
        }

        case MOTOR_TUNER_PM_STAGE_RLD_RLS:
        case MOTOR_TUNER_PM_STAGE_RLD_DFT:
        {
            tuner_pm_ldq_reset(&p_instance->tuner_ldq, p_foc);
            p_foc->ld   = 0.0F;
            *p_paramode = MOTOR_TUNER_PM_STAGE_RLD_RLS;
            break;
        }

        case MOTOR_TUNER_PM_STAGE_LQ_RLS:
        case MOTOR_TUNER_PM_STAGE_LQ_DFT:
        {
            tuner_pm_ldq_reset(&p_instance->tuner_ldq, p_foc);
            p_foc->lq   = 0.0F;
            *p_paramode = MOTOR_TUNER_PM_STAGE_LQ_RLS;
            break;
        }

        case MOTOR_TUNER_PM_STAGE_KE:
        {
            tuner_pm_ke_reset(&p_instance->tuner_ke, p_foc);
            p_foc->ke = 0.0F;
            break;
        }

        case MOTOR_TUNER_PM_STAGE_JD:
        {
            tuner_pm_jd_reset(&p_instance->tuner_jd, p_foc);
            p_foc->j = 0.0F;
            p_foc->d = 0.0F;
            break;
        }

        default:
        {
            /* Do nothing */
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Execute motor identification sequence, this sequence function should be execute before setting the current
 *        reference
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 * @note  MOTOR_TUNER_PM_STAGE_JD state is excluded because it is time consuming that will delay the PWM output update the
 *        process is put into tuner_pm_motorid_sequence_post function
 **********************************************************************************************************************/
static void tuner_pm_motorid_sequence (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    uint16_t is_completed             = false;
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    switch (p_instance_ctrl->tune_stage)
    {
        case MOTOR_TUNER_PM_STAGE_INIT:
        {
            /* Wait until the CORE module is ready to receive voltage/current command */
            if (TUNER_PM_RUNMODE_READY == p_foc->run_mode)
            {
                tuner_pm_act_tune_init(p_instance_ctrl); /* This function is only executed once */
                if (true == p_instance_ctrl->user_inputs.volterr_is_enabled)
                {
                    p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_VOLTERR;
                }
                else
                {
                    p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_R_DIFF */
                }
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_VOLTERR:
        {
            if (p_instance_ctrl->user_inputs.volterr_is_enabled == 1)
            {
                is_completed = tuner_pm_volterr_act(&p_instance_ctrl->tuner_volterr, p_foc);
                if (true == is_completed)
                {
                    tuner_pm_core_set_volterr_table(p_foc,
                                                    (p_instance_ctrl->tuner_volterr.output_current_tab),
                                                    (p_instance_ctrl->tuner_volterr.output_voltage_tab),
                                                    p_instance_ctrl->tuner_volterr.output_vdc_ref);
                    p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_R_DIFF */
                }
            }
            else
            {
                TUNER_PM_ASSERT_FAIL();
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_R_DIFF:
        {
            is_completed = tuner_pm_rdiff_act(&p_instance_ctrl->tuner_rdiff, p_foc);
            if (true == is_completed)
            {
                if (p_foc->r <= 0.0F)
                {
                    p_foc->r    = p_instance_ctrl->tuner_rdiff.r_diff;
                    p_foc->r_dc = p_instance_ctrl->tuner_rdiff.r_diff;
                }

                p_foc->v_err                = p_instance_ctrl->tuner_rdiff.volterr_est;
                p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_RLD_RLS */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_RLD_RLS:
        {
            is_completed = tuner_pm_rld_rls_act(&p_instance_ctrl->tuner_ldq, p_foc, TUNER_PM_SIGNAL_CONF_DEFAULT);
            if (true == is_completed)
            {
                p_foc->ld = p_instance_ctrl->tuner_ldq.ld_rls;
                p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_RLD_DFT; /* Always perform DFT method identification after RLS */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_RLD_DFT:
        {
            is_completed = tuner_pm_rld_dft_act(&p_instance_ctrl->tuner_ldq, p_foc, TUNER_PM_SIGNAL_CONF_DEFAULT);
            if (true == is_completed)
            {
                p_foc->ld = p_instance_ctrl->tuner_ldq.ld_dft;
                p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_LQ_RLS */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_LQ_RLS:
        {
            is_completed = tuner_pm_lq_rls_act(&p_instance_ctrl->tuner_ldq, p_foc, TUNER_PM_SIGNAL_CONF_DEFAULT);
            if (true == is_completed)
            {
                p_foc->lq =
                    (p_instance_ctrl->tuner_ldq.lq_rls >= p_foc->ld) ? p_instance_ctrl->tuner_ldq.lq_rls : p_foc->ld;
                p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_LQ_DFT; /* Always perform DFT method identification after RLS */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_LQ_DFT:
        {
            is_completed = tuner_pm_lq_dft_act(&p_instance_ctrl->tuner_ldq, p_foc, TUNER_PM_SIGNAL_CONF_DEFAULT);
            if (true == is_completed)
            {
                p_foc->lq =
                    (p_instance_ctrl->tuner_ldq.lq_dft >= p_foc->ld) ? p_instance_ctrl->tuner_ldq.lq_dft : p_foc->ld;
                p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_KE */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_KE:
        {
            is_completed = tuner_pm_ke_act(&p_instance_ctrl->tuner_ke, p_foc);
            if (true == is_completed)
            {
                /* Closed-loop result is more accurate, because the error caused by
                 * Ld, Lq error is mostly eliminated by small drive current in small friction condition, which is very likely */
                p_foc->ke = p_instance_ctrl->tuner_ke.ke_closed_loop;
                p_instance_ctrl->tune_stage = tuner_pm_get_next_tune_stage(p_instance_ctrl); /* MOTOR_TUNER_PM_STAGE_JD */
            }

            break;
        }

        case MOTOR_TUNER_PM_STAGE_JD:
        {
            /* The action function is invoked after PWM setting, see tuner_pm_motorid_seuence_post */

            break;
        }

        case MOTOR_TUNER_PM_STAGE_END:
        {
            tuner_pm_act_tune_end(p_instance_ctrl);
            tuner_pm_state_machine_event(p_instance_ctrl, TUNER_PM_PRV_EVENT_COMPLETED);
            p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_INIT;
            break;
        }

        default:
        {
            TUNER_PM_ASSERT_FAIL();
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief Process executed after update PWM duty cycles
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 **********************************************************************************************************************/
static void tuner_pm_motorid_sequence_post (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    uint16_t is_completed             = false;
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    if (MOTOR_TUNER_PM_STAGE_JD == p_instance_ctrl->tune_stage)
    {
        is_completed = tuner_pm_jd_act(&p_instance_ctrl->tuner_jd, p_foc);
        if (true == is_completed)
        {
            p_instance_ctrl->tune_stage = MOTOR_TUNER_PM_STAGE_END;
            p_foc->j = p_instance_ctrl->tuner_jd.j_dft;
            p_foc->d = p_instance_ctrl->tuner_jd.d_dft;
        }
    }
}

/*******************************************************************************************************************//**
 * Load parameters from user inputs
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 * @note This function will be called when transitioning from MOTOR_TUNER_PM_STAGE_INIT to next mode, since the DC voltage
 * knowledge is required
 **********************************************************************************************************************/
static void tuner_pm_act_tune_init (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    motor_tuner_pm_core_foc_t         * p_foc        = &p_instance_ctrl->base_foc;
    motor_tuner_pm_extend_cfg_t const * p_extend_cfg =
        (motor_tuner_pm_extend_cfg_t const *) p_instance_ctrl->p_cfg->p_extend;

    /* Input from GUI */
    p_foc->rated_current = p_instance_ctrl->user_inputs.current_setting;
    p_foc->pole_pairs    = p_instance_ctrl->user_inputs.polepairs_setting;

    /* Check input parameters */
    if ((p_foc->rated_current > p_instance_ctrl->rated_current_max) || (p_foc->rated_current <= 0.0F))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_INPUT_CURRENT);

        return;
    }

    /* Number of pole pairs should not be less than 1, too many pole pairs (more than 100) is also not make sense */
    if ((p_foc->pole_pairs <= 0) || (p_foc->pole_pairs > p_foc->p_cfg->num_pole_pair_limit))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_INPUT_POLEPAIR);

        return;
    }

    if ((p_instance_ctrl->user_inputs.inertia_setting < 0.0F) || (p_instance_ctrl->user_inputs.inertia_setting > 1.0F))
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_INPUT_INERTIA_RANGE);

        return;
    }

    tuner_pm_core_set_rated_current(p_foc, p_foc->rated_current);

    if (p_instance_ctrl->user_inputs.volterr_is_enabled == 1)
    {
        if (p_instance_ctrl->user_inputs.volterr_setting < 1)
        {
            tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_INPUT_VOLTERR_STEP);

            return;
        }

        tuner_pm_volterr_config(&p_instance_ctrl->tuner_volterr,
                                p_foc,
                                p_extend_cfg->tuner_volterr_cfg.init_r,
                                p_foc->current_lsb,
                                TUNER_PM_VOLTERR_RID_RLS);
        tuner_pm_volterr_config_current_step(&p_instance_ctrl->tuner_volterr,
                                             p_foc,
                                             p_instance_ctrl->user_inputs.volterr_setting);
    }

    /* Assume that maximum copper loss (proportional to R) should not exceed a certain limit */
    p_foc->r_max  = p_foc->vdc_ad / p_foc->rated_current;
    p_foc->r_min  = p_extend_cfg->base_foc_cfg.r_min;
    p_foc->ld_min = 0.0F;
    p_foc->lq_min = 0.0F;

    /* Initialization of tuning identification results. If this value is non-zero, the measurement is skipped. */
    p_foc->r    = p_instance_ctrl->user_inputs.init_r;
    p_foc->r_dc = p_instance_ctrl->user_inputs.init_r;
    p_foc->ld   = p_instance_ctrl->user_inputs.init_ld;
    p_foc->lq   = p_instance_ctrl->user_inputs.init_lq;
    p_foc->ke   = p_instance_ctrl->user_inputs.init_ke;
    p_foc->j    = p_instance_ctrl->user_inputs.init_j;

    tuner_pm_jd_config_inertia_range(&p_instance_ctrl->tuner_jd, p_foc, p_instance_ctrl->user_inputs.inertia_setting);
}

/*******************************************************************************************************************//**
 * @brief Finalize the tuning process, calculate rated speed and torque
 * @param[in] p_instance_ctrl  Pointer to motor tuner instance control structure
 **********************************************************************************************************************/
static void tuner_pm_act_tune_end (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    /* Rated speed (electrical,[rad/s] */
    p_instance_ctrl->rated_speed_elec_rad = tuner_pm_design_base_speed(p_instance_ctrl->tuner_ke.ke_open,
                                                                       p_foc->r,
                                                                       p_foc->lq,
                                                                       p_foc->vmag_max,
                                                                       p_foc->imag_max);

    /* Rated speed [rpm] */
    p_instance_ctrl->rated_speed_mech_rpm = (p_instance_ctrl->rated_speed_elec_rad / p_foc->pole_pairs) *
                                            TUNER_PM_MECH_RAD_TO_RPM;

    /* Rated torque */
    p_instance_ctrl->rated_torque_nm = p_foc->ke * p_foc->rated_current * p_foc->pole_pairs;
    tuner_pm_core_stop(&p_instance_ctrl->base_foc);
}

/*******************************************************************************************************************//**
 * @brief  Determine the next tuning stage. Skip the identification of known parameter.
 * @note   Implicit input:
 *              - p_foc->r
 *              - p_foc->ld
 *              - p_foc->lq
 *              - p_foc->ke
 *              - p_foc->jd
 * @warning This function only handles electrical tuning stages, voltage error measurement mode is
 *          excluded if enabled
 * @return The next tuning stage.
 **********************************************************************************************************************/
static uint16_t tuner_pm_get_next_tune_stage (motor_tuner_pm_instance_ctrl_t * p_instance_ctrl)
{
    uint16_t ret = MOTOR_TUNER_PM_STAGE_END;
    motor_tuner_pm_core_foc_t * p_foc = &p_instance_ctrl->base_foc;

    if ((rm_motor_tuner_is_equalf(p_foc->r, 0.0F)) || (rm_motor_tuner_is_equalf(p_foc->r_dc, 0.0F)))
    {
        ret = MOTOR_TUNER_PM_STAGE_R_DIFF;
    }
    else if (rm_motor_tuner_is_equalf(p_foc->ld, 0.0F))
    {
        ret = MOTOR_TUNER_PM_STAGE_RLD_RLS;
    }
    else if (rm_motor_tuner_is_equalf(p_foc->lq, 0.0F))
    {
        ret = MOTOR_TUNER_PM_STAGE_LQ_RLS;
    }
    else if (rm_motor_tuner_is_equalf(p_foc->ke, 0.0F))
    {
        if (rm_motor_tuner_is_equalf(p_foc->j, 0.0F))
        {
            tuner_pm_ke_config_no_stop_flag(&p_instance_ctrl->tuner_ke, &p_instance_ctrl->base_foc, true);
        }

        ret = MOTOR_TUNER_PM_STAGE_KE;
    }
    else if (rm_motor_tuner_is_equalf(p_foc->j, 0.0F))
    {
        ret = MOTOR_TUNER_PM_STAGE_JD;
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/*******************************************************************************************************************//**
 * @brief     Calculate the base speed with given motor parameters, voltage and current limitations
 *
 * @param[in] flux_wb  The flux, BEMF coefficient [Wb]
 * @param[in] r        The resistance[ohm]
 * @param[in] lq       The q-axis inductance[h]
 * @param[in] va_max   The maximum magnitude of voltage vector [V]
 * @param[in] ia_max   The maximum magnitude of current vector [A]
 *
 * @return    The base speed [rad/s], which is the maximum speed that can deliver maximum torque
 **********************************************************************************************************************/
static float tuner_pm_design_base_speed (float flux_wb, float r, float lq, float va_max, float ia_max)
{
    float totalflux_max;
    float vflux_max;
    float flux_q_wb;
    float base_speed_rad;

    /* NOTE: this is a simplified method that can only be used on non-salient motor */
    /* Flux on q-axis is generated by q-axis current, assumes that all current is used on q-axis */
    flux_q_wb = lq * ia_max;

    /* Calculate maximum total flux */
    totalflux_max = sqrtf((flux_wb * flux_wb) + (flux_q_wb * flux_q_wb));

    /* Calculate maximum voltage can be generated by flux */
    vflux_max = va_max - (r * ia_max);

    /* Return the base speed */
    base_speed_rad = vflux_max / totalflux_max;

    return base_speed_rad;
}

/** @} */
