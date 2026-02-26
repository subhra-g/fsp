/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef RM_MOTOR_TUNER_PM_INTERNAL_H
#define RM_MOTOR_TUNER_PM_INTERNAL_H
#include <stdint.h>
#include "rm_motor_tuner_api.h"
#include "rm_motor_tuner_pm.h"
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_tuner_pm_rdiff.h"
#include "rm_motor_tuner_pm_ldq.h"
#include "rm_motor_tuner_pm_ke.h"
#include "rm_motor_tuner_pm_jd.h"
#include "rm_motor_tuner_pm_volterr.h"

/*******************************************************************************************************************//**
 * @addtogroup RM_MOTOR_TUNER_PM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/**
 * @defgroup Command Command Code
 * @brief Command code
 * @{*/
#define TUNER_PM_COMMAND_NONE      (0U) ///< Defines status that no command is issued */
#define TUNER_PM_COMMAND_START     (1U) ///< Defines command code that starts tuning */
#define TUNER_PM_COMMAND_STOP      (2U) ///< Defines command code that stops tuning */
#define TUNER_PM_COMMAND_RESET     (3U) ///< Defines reset command code */
#define TUNER_PM_COMMAND_RESUME    (4U) ///< Defines resume command code */

/** @}*/

/**
 * @defgroup FaultRet Fault return code
 * @brief Fault codes that returned by some API functions, integer
 */
#define TUNER_PM_FAULT_PARAM_R     (-1) ///< Defines fault code that parameter R is invalid */
#define TUNER_PM_FAULT_PARAM_LD    (-2) ///< Defines fault code that parameter Ld is invalid  */
#define TUNER_PM_FAULT_PARAM_LQ    (-3) ///< Defines fault code that parameter Lq is invalid  */
#define TUNER_PM_FAULT_PARAM_KE    (-4) ///< Defines fault code that parameter Ke is invalid  */
#define TUNER_PM_FAULT_PARAM_J     (-5) ///< Defines fault code that parameter j is invalid  */

/** @}*/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Voltage error lookup table structure, this data structure is used for setting and getting the lookup table
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Identification setting structure, this data structure is used for obtaining current identification setting
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
void tuner_pm_state_machine_event(motor_tuner_pm_instance_ctrl_t * p_instance_ctrl, uint16_t event);

/** @} */
#endif                                 /* RM_MOTOR_TUNER_PM_INTERNAL_H */
