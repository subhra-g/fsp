/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_MOTOR_TUNER_PM_LDQ_H
#define RM_MOTOR_TUNER_PM_LDQ_H

/***********************************************************************************************************************
 * Includes <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdint.h>
#include "rm_motor_tuner_pm.h"
#include "rm_motor_tuner_pm_core.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
uint16_t tuner_pm_rld_dft_act(motor_tuner_pm_ldq_t         * p_ldq,
                              motor_tuner_pm_core_foc_t    * p_foc,
                              motor_tuner_pm_signal_conf_t * st_signal_conf);
uint16_t tuner_pm_rld_rls_act(motor_tuner_pm_ldq_t         * p_ldq,
                              motor_tuner_pm_core_foc_t    * p_foc,
                              motor_tuner_pm_signal_conf_t * st_signal_conf);
uint16_t tuner_pm_lq_dft_act(motor_tuner_pm_ldq_t         * p_ldq,
                             motor_tuner_pm_core_foc_t    * p_foc,
                             motor_tuner_pm_signal_conf_t * st_signal_conf);
uint16_t tuner_pm_lq_rls_act(motor_tuner_pm_ldq_t         * p_ldq,
                             motor_tuner_pm_core_foc_t    * p_foc,
                             motor_tuner_pm_signal_conf_t * st_signal_conf);
void tuner_pm_ldq_reset(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);

#endif                                 /* RM_MOTOR_TUNER_PM_LDQ_H_ */
