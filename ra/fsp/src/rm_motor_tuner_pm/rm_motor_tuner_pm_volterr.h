/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "rm_motor_tuner_pm.h"
#include "rm_motor_tuner_pm_core.h"
#ifndef RM_MOTOR_TUNER_PM_VOLTERR_H
 #define RM_MOTOR_TUNER_PM_VOLTERR_H

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void     tuner_pm_volterr_init(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
uint16_t tuner_pm_volterr_act(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
void     tuner_pm_volterr_config(motor_tuner_pm_volterr_t    * p_volterr_id,
                                 motor_tuner_pm_core_foc_t   * p_foc,
                                 float                         r_initval,
                                 float                         i_lsb,
                                 motor_tuner_volterr_cfg_rid_t e_rid_cfg);
void tuner_pm_volterr_config_current_step(motor_tuner_pm_volterr_t  * p_volterr_id,
                                          motor_tuner_pm_core_foc_t * p_foc,
                                          uint16_t                    ilsb);
void tuner_pm_volterr_reset(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);

#endif                                 /* RM_MOTOR_TUNER_PM_VOLTERR_H */
