/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef RM_PM_TUNER_CORE_H
#define RM_PM_TUNER_CORE_H
#include <stdint.h>
#include "rm_motor_tuner_api.h"
#include "rm_motor_tuner_pm.h"
#include "rm_motor_mc_lib.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
#ifndef NULL
 #define NULL    (0)
#endif

#ifndef RELEASE
 #define TUNER_PM_ASSERT(expr)     if (!(expr)) {tuner_pm_core_assert_fail(p_foc, __LINE__, TUNER_PM_PRV_FILE_CODE);}
 #define TUNER_PM_ASSERT_FAIL()    tuner_pm_core_assert_fail(p_foc, __LINE__, TUNER_PM_PRV_FILE_CODE)
#else
 #define TUNER_PM_ASSERT(expr)
 #define TUNER_PM_ASSERT_FAIL()    nop()
#endif

#define TUNER_PM_VOLTERR_TABLE_SIZE     (5)       ///< Size of voltage error compensation table
#define TUNER_PM_MS_TO_SECOND           (0.001F)  ///< Milliseconds to seconds conversion factor
#define TUNER_PM_SECOND_TO_MS           (1000.0F) ///< Seconds to milliseconds conversion factor
#define TUNER_PM_SIGNAL_CONF_DEFAULT    (0)
#define TUNER_PM_ID_UP                  (0)
#define TUNER_PM_ID_CONST               (1)
#define TUNER_PM_ID_DOWN                (2)
#define TUNER_PM_ID_ZERO_CONST          (3)

#define TUNER_PM_IQ_ZERO_CONST          (0)
#define TUNER_PM_IQ_SPEED_PI_OUTPUT     (1)
#define TUNER_PM_IQ_DOWN                (2)

#define TUNER_PM_SPEED_HOLD             (0)
#define TUNER_PM_SPEED_CHANGE           (1)

/* control configuration */
#define TUNER_PM_CONTROL_CURRENT        (0x01)
#define TUNER_PM_CONTROL_SPEED          (0x02)

#define TUNER_PM_CTRL_LEVEL_0           (0) ///< Initial state, identification has not started yet */
#define TUNER_PM_CTRL_LEVEL_1           (1) ///< Only voltage output and current measurement */
#define TUNER_PM_CTRL_LEVEL_2           (2) ///< Current control loop and BEMF observer is enabled above this level */
#define TUNER_PM_CTRL_LEVEL_3           (3) ///< Angle and speed is estimated by PLL if possible */
#define TUNER_PM_CTRL_LEVEL_4           (4) ///< Enables speed controller and startup sequence controller */

/* flag state*/
#define TUNER_PM_FLG_CLR                (0) /* for flag clear */
#define TUNER_PM_FLG_SET                (1) /* for flag set */

#define TUNER_PM_RUNMODE_INIT           (0)
#define TUNER_PM_RUNMODE_BOOT           (1)
#define TUNER_PM_RUNMODE_READY          (2)

#define     TUNER_PM_TWOPI              (2.0F * 3.1415926535F)   ///< 2 * pi */
#define     TUNER_PM_SQRT_3             (1.7320508F)             ///< Sqrt(3) */
#define     TUNER_PM_SQRT_2             (1.41421356F)            ///< Sqrt(2) */
#define     TUNER_PM_MECH_RAD_TO_RPM    (60.0F / TUNER_PM_TWOPI) ///< Mechanical RPM to rad/s conversion factor */

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
void tuner_pm_core_init(motor_tuner_pm_core_foc_t           * p_foc,
                        motor_tuner_pm_core_foc_cfg_t const * p_cfg,
                        void                                * p_context,
                        uint8_t                               pwm_tick_per_irq,
                        float                                 speed_ctrl_period);
void tuner_pm_core_crnt_ctrl_handler(motor_tuner_pm_core_foc_t * p_foc,
                                     motor_tuner_in_t          * p_in,
                                     motor_tuner_out_t         * p_out);
void tuner_pm_core_spd_ctrl_handler(motor_tuner_pm_core_foc_t * p_foc);
void tuner_pm_core_assert_fail(motor_tuner_pm_core_foc_t * p_foc, uint32_t line, uint32_t file);
void tuner_pm_core_throw_error(motor_tuner_pm_core_foc_t * p_foc, uint16_t error_code);
void tuner_pm_core_config_bemf_obsv(motor_tuner_pm_core_foc_t * p_foc, float omega, float zeta);
void tuner_pm_core_config_current_pi_gains(motor_tuner_pm_core_foc_t * p_foc, float omega, float zeta);
void tuner_pm_core_set_startup_params(motor_tuner_pm_core_foc_t * p_foc,
                                      float                       open_loop_id,
                                      float                       ol2cl_speed_rad,
                                      float                       cl2ol_speed_rad);
void tuner_pm_core_set_speed_pi(motor_tuner_pm_core_foc_t * p_foc, float kp, float kidt);
void tuner_pm_core_set_rated_current(motor_tuner_pm_core_foc_t * p_foc, float rated_current);
void tuner_pm_core_set_volterr_table(motor_tuner_pm_core_foc_t * p_foc,
                                     const float               * current_tab,
                                     const float               * voltage_tab,
                                     float                       vdc_ref);
void tuner_pm_core_set_ctrl_level(motor_tuner_pm_core_foc_t * p_foc, uint16_t ctrl_level);
void tuner_pm_core_clear_error(motor_tuner_pm_core_foc_t * p_foc);
void tuner_pm_core_reset(motor_tuner_pm_core_foc_t * p_foc);
void tuner_pm_core_stop(motor_tuner_pm_core_foc_t * p_foc);
void tuner_pm_core_reset_startup_seq(motor_tuner_pm_core_foc_t * p_foc);
void tuner_pm_core_warning(motor_tuner_pm_core_foc_t * p_foc, uint32_t warn_code, float related_val);
void tuner_pm_core_hook_on_error(motor_tuner_pm_core_foc_t * p_foc, uint16_t error_code);
void tuner_pm_core_hook_before_current_ctrl(void * p_context);
void tuner_pm_core_hook_after_pwmoutput(void * p_context);

#endif                                 /* RM_PM_TUNER_CORE_H */
