/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdbool.h>
#include "bsp_api.h"
#include "rm_motor_tuner_api.h"
#include "rm_motor_tuner_pm.h"
#include "rm_motor_tuner_pm_internal.h"
#include "rm_motor_tuner_pm_core.h"
#include "fsp_common_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define MOTOR_TUNER_OPEN                       (0x54554E52UL) /* "TUNR" */
#define MOTOR_TUNER_PM_PRV_PROGRESS_RDIFF      (0.5F)         ///< Progress weight for Rdiff identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_RLD_RLS    (0.60F)        ///< Progress weight for Rld identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_RLD_DFT    (0.625F)       ///< Progress weight for Rld identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_LQ_RLS     (0.65F)        ///< Progress weight for Lq identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_LQ_DFT     (0.675F)       ///< Progress weight for Lq identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_KE         (0.7F)         ///< Progress weight for Ke identification
#define MOTOR_TUNER_PM_PRV_PROGRESS_JD         (0.8F)         ///< Progress weight for J and D identification

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/* API structure */
const motor_tuner_api_t g_motor_tuner_on_motor_tuner_pm =
{
    .open                      = RM_MOTOR_TUNER_PM_Open,
    .innerLoopProcess          = RM_MOTOR_TUNER_PM_InnerLoopProcess,
    .outerLoopProcess          = RM_MOTOR_TUNER_PM_OuterLoopProcess,
    .start                     = RM_MOTOR_TUNER_PM_Start,
    .stop                      = RM_MOTOR_TUNER_PM_Stop,
    .reset                     = RM_MOTOR_TUNER_PM_Reset,
    .abort                     = RM_MOTOR_TUNER_PM_Abort,
    .statusGet                 = RM_MOTOR_TUNER_PM_StatusGet,
    .errorGet                  = RM_MOTOR_TUNER_PM_ErrorGet,
    .knownParamSet             = RM_MOTOR_TUNER_PM_KnownParamSet,
    .progressGet               = RM_MOTOR_TUNER_PM_ProgressGet,
    .identifiedParamGet        = RM_MOTOR_TUNER_PM_IdentifiedParamGet,
    .identifiedVoltageErrorGet = RM_MOTOR_TUNER_PM_IdentifiedVoltageErrorGet,
    .isActive                  = RM_MOTOR_TUNER_PM_IsActive,
    .voltageErrorLutSet        = RM_MOTOR_TUNER_PM_VoltageErrorSet,
};

/*******************************************************************************************************************//**
 * @addtogroup RM_MOTOR_TUNER_PM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Open the Motor Tuner instance. Implements @ref motor_tuner_api_t::open.
 *
 * Initializes the motor tuner system including GUI initialization
 * and parameter setup for motor parameter estimation.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_Open
 *
 * @retval FSP_SUCCESS              Motor Tuner successfully configured.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Open (motor_tuner_ctrl_t * const p_ctrl, motor_tuner_cfg_t const * const p_cfg)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cfg);
#endif
    motor_tuner_pm_extend_cfg_t * p_extend_cfg = (motor_tuner_pm_extend_cfg_t *) p_cfg->p_extend;
    motor_tuner_pm_core_foc_t   * p_foc        = &p_instance_ctrl->base_foc;
    uint8_t pwm_tick_per_irq  = p_extend_cfg->pwm_tick_per_irq;
    float   speed_ctrl_period = p_extend_cfg->speed_ctrl_period;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_extend_cfg);
    FSP_ERROR_RETURN((p_instance_ctrl->open != MOTOR_TUNER_OPEN), FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN((p_extend_cfg->pwm_tick_per_irq != 0), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_extend_cfg->speed_ctrl_period > 0.0F), FSP_ERR_INVALID_ARGUMENT);
#endif

    p_instance_ctrl->tune_status = MOTOR_TUNER_STATUS_READY;
    p_instance_ctrl->open        = MOTOR_TUNER_OPEN;
    tuner_pm_core_init(p_foc, &p_extend_cfg->base_foc_cfg, (void *) p_instance_ctrl, pwm_tick_per_irq,
                       speed_ctrl_period);

    p_instance_ctrl->rated_current_max = p_foc->overcurrent_limit_hw /
                                         (TUNER_PM_SQRT_2 * p_foc->p_cfg->overcurrent_limit_mult);
    p_instance_ctrl->tuner_volterr.p_cfg = &p_extend_cfg->tuner_volterr_cfg;
    p_instance_ctrl->tuner_rdiff.p_cfg   = &p_extend_cfg->tuner_rdiff_cfg;
    p_instance_ctrl->tuner_ldq.p_cfg     = &p_extend_cfg->tuner_ldq_cfg;
    p_instance_ctrl->tuner_ke.p_cfg      = &p_extend_cfg->tuner_ke_cfg;
    p_instance_ctrl->tuner_jd.p_cfg      = &p_extend_cfg->tuner_jd_cfg;

    tuner_pm_volterr_init(&p_instance_ctrl->tuner_volterr, p_foc);

    p_instance_ctrl->p_cfg = p_cfg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Start motor tuner. Implements @ref motor_tuner_api_t::start.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_Start
 *
 * @retval FSP_SUCCESS      Successfully started the tuner.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Start (motor_tuner_ctrl_t * const p_ctrl)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    tuner_pm_state_machine_event(p_instance_ctrl, TUNER_PM_COMMAND_START);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Stop motor tuner. Implements @ref motor_tuner_api_t::stop.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_Stop
 *
 * @retval FSP_SUCCESS      Successfully stopped the tuner.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Stop (motor_tuner_ctrl_t * const p_ctrl)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif
    p_instance_ctrl->base_foc.abort_request = true;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Reset motor tuner. Implements @ref motor_tuner_api_t::reset.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_Reset
 *
 * @retval FSP_SUCCESS      Successfully reset the tuner.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Reset (motor_tuner_ctrl_t * const p_ctrl)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    tuner_pm_state_machine_event(p_instance_ctrl, TUNER_PM_COMMAND_RESET);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Get motor tuner status. Implements @ref motor_tuner_api_t::statusGet.
 *
 * Retrieves the current status of the tuner. See @ref motor_tuner_status_t for details.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_StatusGet
 *
 * @retval FSP_SUCCESS      Successfully retrieved the status.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_StatusGet (motor_tuner_ctrl_t * const p_ctrl, motor_tuner_status_t * p_status)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_status), FSP_ERR_INVALID_ARGUMENT);
#endif

    *p_status = p_instance_ctrl->tune_status;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Get motor tuner error code. Implements @ref motor_tuner_api_t::errorGet.
 *
 * Retrieves the current error code of the tuner.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_ErrorGet
 *
 * @retval FSP_SUCCESS      Successfully retrieved the error code.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_ErrorGet (motor_tuner_ctrl_t * const p_ctrl, uint16_t * p_error)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    motor_tuner_pm_core_foc_t      * p_foc           = &p_instance_ctrl->base_foc;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_error), FSP_ERR_INVALID_ARGUMENT);
#endif

    *p_error = p_foc->error_status;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Get motor tuner progress. Implements @ref motor_tuner_api_t::progressGet.
 *
 * Retrieves the current progress of the tuner operation as a float between 0.0 and 1.0.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_ProgressGet
 *
 * @retval FSP_SUCCESS      Successfully retrieved the progress.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_ProgressGet (motor_tuner_ctrl_t * const p_ctrl, float * p_progress)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    float progress = 0.0F;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_progress), FSP_ERR_INVALID_ARGUMENT);
#endif

    if (MOTOR_TUNER_STATUS_COMPLETED == p_instance_ctrl->tune_status)
    {
        progress = 1.0F;
    }
    else
    {
        switch (p_instance_ctrl->tune_stage)
        {
            case MOTOR_TUNER_PM_STAGE_INIT:
            {
                progress = 0.0F;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_VOLTERR:
            {
                progress = 0.0F;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_R_DIFF:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_RDIFF;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_RLD_RLS:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_RLD_RLS;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_RLD_DFT:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_RLD_DFT;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_LQ_RLS:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_LQ_RLS;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_LQ_DFT:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_LQ_DFT;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_KE:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_KE;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_JD:
            {
                progress = MOTOR_TUNER_PM_PRV_PROGRESS_JD;
                break;
            }

            case MOTOR_TUNER_PM_STAGE_END:
            {
                progress = 1.0F;
                break;
            }

            default:
            {

                /* Do nothing */
                return FSP_ERR_ASSERTION;
                break;
            }
        }
    }

    *p_progress = progress;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Abort motor tuner. Implements @ref motor_tuner_api_t::abort.
 *
 * Aborts the tuner operation with an optional error code. If the error code is zero, it is equivalent to a normal stop.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_Abort
 *
 * @retval FSP_SUCCESS      Successfully aborted the tuner.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Abort (motor_tuner_ctrl_t * const p_ctrl, uint8_t error_code)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->base_foc.error_status  = error_code;
    p_instance_ctrl->base_foc.abort_request = true;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Get identified motor parameter. Implements @ref motor_tuner_api_t::identifiedParamGet.
 *
 * Retrieves the identified motor parameter based on the specified type.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_IdentifiedParamGet
 *
 * @retval FSP_SUCCESS              Successfully retrieved the identified parameter.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_IdentifiedParamGet (motor_tuner_ctrl_t * const p_ctrl,
                                                motor_tuner_param_type_t   param_type,
                                                float                    * p_value)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    motor_tuner_pm_core_foc_t      * p_foc           = &p_instance_ctrl->base_foc;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_value), FSP_ERR_INVALID_ARGUMENT);
#endif

    switch (param_type)
    {
        case MOTOR_TUNER_PARAM_TYPE_POLE_PAIRS:
        {
            *p_value = p_foc->pole_pairs;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_INERTIA:
        {
            *p_value = p_foc->j;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_VISCOUS_FRICTION:
        {
            *p_value = p_foc->d;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_R:
        {
            *p_value = p_foc->r;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_LD:
        {
            *p_value = p_foc->ld;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_LQ:
        {
            *p_value = p_foc->lq;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_KE:
        {
            *p_value = p_foc->ke;
            break;
        }

        default:

            return FSP_ERR_INVALID_ARGUMENT;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Process inner loop for motor tuner. Implements @ref motor_tuner_api_t::innerLoopProcess.
 *
 * Executes the inner loop(current control, rotor angle estimation, etc.) processing for motor parameter estimation
 * when the tuner is initialized, running, and active.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_InnerLoopProcess
 *
 * @param[in]  p_ctrl       Pointer to control structure.
 * @param[in]  p_in         Pointer to input structure.
 * @param[out] p_out        Pointer to output structure.
 *
 * @retval FSP_SUCCESS      Successfully processed inner loop.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_InnerLoopProcess (motor_tuner_ctrl_t * const p_ctrl,
                                              motor_tuner_in_t         * p_in,
                                              motor_tuner_out_t        * p_out)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    motor_tuner_pm_core_foc_t      * p_foc           = &p_instance_ctrl->base_foc;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_in), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_out), FSP_ERR_INVALID_ARGUMENT);
#endif

    if (MOTOR_TUNER_STATUS_RUNNING == p_instance_ctrl->tune_status)
    {
        tuner_pm_core_crnt_ctrl_handler(&p_instance_ctrl->base_foc, p_in, p_out);
        p_instance_ctrl->total_time_elapsed += (p_foc->ctrl_period_ms);
        p_out->request                = p_instance_ctrl->last_request;
        p_instance_ctrl->last_request = MOTOR_TUNER_REQUEST_NONE;
    }

    /* Run the state machine without event to trigger the delayed transition (such as RESET=>READY) */
    tuner_pm_state_machine_event(p_instance_ctrl, TUNER_PM_COMMAND_NONE);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Process outer loop for motor tuner. Implements @ref motor_tuner_api_t::outerLoopProcess.
 *
 * Executes the outer loop processing and main loop for motor parameter
 * estimation. It also handles initialization if not yet completed.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_OuterLoopProcess
 *
 * @param[in]  p_ctrl       Pointer to control structure.
 *
 * @retval FSP_SUCCESS      Successfully processed outer loop.
 * @retval FSP_ERR_NOT_OPEN Module is not open.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_OuterLoopProcess (motor_tuner_ctrl_t * const p_ctrl)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    tuner_pm_core_spd_ctrl_handler(&p_instance_ctrl->base_foc);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Check if motor tuner is active. Implements @ref motor_tuner_api_t::isActive.
 *
 * Checks whether the motor tuner is currently active and running.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_IsActive
 *
 * @param[in]  p_ctrl       Pointer to control structure.
 * @param[out] p_is_active  Pointer to active status flag.
 *
 * @retval FSP_SUCCESS              Successfully checked active status.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_IsActive (motor_tuner_ctrl_t * const p_ctrl, bool * p_is_active)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_is_active), FSP_ERR_INVALID_ARGUMENT);
#endif

    *p_is_active = (p_instance_ctrl->tune_status == MOTOR_TUNER_STATUS_RUNNING) ? true : false;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Get identified voltage error data. Implements @ref motor_tuner_api_t::identifiedVoltageErrorGet.
 *
 * Retrieves the identified voltage error data including current breakpoints, voltage error values,
 * DC bus reference voltage, and DC resistance.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_IdentifiedVoltageErrorGet
 *
 * @retval FSP_SUCCESS              Successfully retrieved the voltage error data.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_IdentifiedVoltageErrorGet (motor_tuner_ctrl_t * const  p_ctrl,
                                                       motor_tuner_volterr_lut_t * p_lut,
                                                       float                     * p_rdc)
{
#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(p_lut, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Allow p_vdc_ref and p_rdc to be NULL */
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    motor_tuner_pm_volterr_t       * p_volterr_id    = &p_instance_ctrl->tuner_volterr;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    for (size_t i = 0; i < MOTOR_TUNER_PM_VOLTERR_OUTPUT_TAB_SIZE; i++)
    {
        p_lut->current_breakpoints[i] = p_volterr_id->output_current_tab[i];
        p_lut->volterr_table[i]       = p_volterr_id->output_voltage_tab[i];
    }

    p_lut->ref_voltage = p_volterr_id->output_vdc_ref;

    if (p_rdc)
    {
        *p_rdc = p_volterr_id->output_rdc;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Set voltage error lookup table. Implements @ref motor_tuner_api_t::voltageErrorLutSet.
 *
 * Sets the voltage error lookup table for the motor tuner.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_VoltageErrorSet
 *
 * @retval FSP_SUCCESS              Successfully set the voltage error lookup table.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_VoltageErrorSet (motor_tuner_ctrl_t * const p_ctrl, motor_tuner_volterr_lut_t * p_lut)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;
    motor_tuner_pm_core_foc_t      * p_foc           = &p_instance_ctrl->base_foc;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((p_lut), FSP_ERR_INVALID_ARGUMENT);
#endif

    tuner_pm_core_set_volterr_table(p_foc, p_lut->current_breakpoints, p_lut->volterr_table, p_lut->ref_voltage);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Set known motor parameter. Implements @ref motor_tuner_api_t::knownParamSet.
 *
 * Sets a known motor parameter based on the specified type and value.
 *
 * Example:
 * @snippet rm_motor_tuner_pm_example.c RM_MOTOR_TUNER_PM_KnownParamSet
 *
 * @retval FSP_SUCCESS              Successfully set the known parameter.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument.
 *
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_KnownParamSet (motor_tuner_ctrl_t * const p_ctrl,
                                           motor_tuner_param_type_t   param_type,
                                           float                      value)
{
    motor_tuner_pm_instance_ctrl_t * p_instance_ctrl = (motor_tuner_pm_instance_ctrl_t *) p_ctrl;

#if RM_MOTOR_TUNER_PM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN((p_instance_ctrl->open == MOTOR_TUNER_OPEN), FSP_ERR_NOT_OPEN);
#endif

    switch (param_type)
    {
        case MOTOR_TUNER_PARAM_TYPE_INERTIA:
        {
            p_instance_ctrl->user_inputs.init_j = value;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_R:
        {
            p_instance_ctrl->user_inputs.init_r = value;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_LD:
        {
            p_instance_ctrl->user_inputs.init_ld = value;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_LQ:
        {
            p_instance_ctrl->user_inputs.init_lq = value;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_PMSM_KE:
        {
            p_instance_ctrl->user_inputs.init_ke = value;
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_POLE_PAIRS:
        {
            p_instance_ctrl->user_inputs.polepairs_setting = (uint8_t) (value);
            break;
        }

        case MOTOR_TUNER_PARAM_TYPE_RATED_CURRENT:
        {
            p_instance_ctrl->user_inputs.current_setting = value;
            break;
        }

        default:

            return FSP_ERR_INVALID_ARGUMENT;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_MOTOR_TUNER_PM)
 **********************************************************************************************************************/
