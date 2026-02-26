/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup RM_MOTOR_TUNER_PM
 * @{
 **********************************************************************************************************************/

#ifndef RM_MOTOR_TUNER_PM_H
#define RM_MOTOR_TUNER_PM_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "bsp_api.h"
#include "rm_motor_tuner_pm_cfg.h"
#include "rm_motor_tuner_api.h"
#include "rm_motor_mc_lib.h"
#include "rm_motor_tuner_lib.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** TUNER_PM_STAGE Parameter Identification Stage. Indicates which stage is the identification process in */
#define MOTOR_TUNER_PM_STAGE_INIT                   (0)                            ///< Defines initial identification stage code
#define MOTOR_TUNER_PM_STAGE_R_DIFF                 (1)                            ///< Defines RDIFF identification stage code
#define MOTOR_TUNER_PM_STAGE_RLD_RLS                (2)                            ///< Defines RLS method Ld identification stage code
#define MOTOR_TUNER_PM_STAGE_RLD_DFT                (3)                            ///< Defines DFT method Ld identification stage code
#define MOTOR_TUNER_PM_STAGE_LQ_RLS                 (4)                            ///< Defines RLS method Lq identification stage code
#define MOTOR_TUNER_PM_STAGE_LQ_DFT                 (5)                            ///< Defines DFT method Lq identification stage code
#define MOTOR_TUNER_PM_STAGE_KE                     (6)                            ///< Defines rated flux identification stage code
#define MOTOR_TUNER_PM_STAGE_JD                     (7)                            ///< Defines inertia identification stage code
#define MOTOR_TUNER_PM_STAGE_END                    (8)                            ///< Defines end identification stage code
#define MOTOR_TUNER_PM_STAGE_VOLTERR                (9)                            ///< Defines voltage error measurement stage code

#define MOTOR_TUNER_PM_ERROR_NONE                   (0x0000)                       ///< Defines non-error code
#define MOTOR_TUNER_PM_ERROR_OVER_CURRENT_HW        (0x0001)                       ///< Defines error code, value 1
#define MOTOR_TUNER_PM_ERROR_OVER_CURRENT_SW        (0x0002)                       ///< Defines error code, value 2
#define MOTOR_TUNER_PM_ERROR_OVER_VOLTAGE           (0x0003)                       ///< Defines error code, value 3
#define MOTOR_TUNER_PM_ERROR_UNDER_VOLTAGE          (0x0004)                       ///< Defines error code, value 4
#define MOTOR_TUNER_PM_ERROR_INPUT                  (0x0011)                       ///< Defines error code, value 17
#define MOTOR_TUNER_PM_ERROR_R_DIFF                 (0x0012)                       ///< Defines error code, value 18
#define MOTOR_TUNER_PM_ERROR_R_DFT                  (0x0013)                       ///< Defines error code, value 19
#define MOTOR_TUNER_PM_ERROR_R_RLS                  (0x0014)                       ///< Defines error code, value 20
#define MOTOR_TUNER_PM_ERROR_LD_DFT                 (0x0015)                       ///< Defines error code, value 21
#define MOTOR_TUNER_PM_ERROR_LD_RLS                 (0x0016)                       ///< Defines error code, value 22
#define MOTOR_TUNER_PM_ERROR_LQ_DFT                 (0x0017)                       ///< Defines error code, value 23
#define MOTOR_TUNER_PM_ERROR_LQ_RLS                 (0x0018)                       ///< Defines error code, value 24
#define MOTOR_TUNER_PM_ERROR_KE                     (0x0019)                       ///< Defines error code, value 25
#define MOTOR_TUNER_PM_ERROR_J                      (0x001A)                       ///< Defines error code, value 26
#define MOTOR_TUNER_PM_ERROR_D                      (0x001B)                       ///< Defines error code, value 27
#define MOTOR_TUNER_PM_ERROR_J_STARTUP              (0x001C)                       ///< Defines error code, value 28
#define MOTOR_TUNER_PM_ERROR_ASSERT_FAIL            (0xFFFF)                       ///< Defines error code, value 65535
#define MOTOR_TUNER_PM_ERROR_INPUT_CURRENT          (0x1001)                       ///< (4097) The rated current input value is invalid */
#define MOTOR_TUNER_PM_ERROR_INPUT_POLEPAIR         (0x1002)                       ///< (4098) The number of pole pairs input value is invalid */
#define MOTOR_TUNER_PM_ERROR_INPUT_VOLTERR_STEP     (0x1003)                       ///< (4099) The voltage error current step input value is invalid */
#define MOTOR_TUNER_PM_ERROR_INPUT_INERTIA_RANGE    (0x1004)                       ///< (4100) The inertia range input value is invalid */

/**
 * @brief Number of points for Ke calculation in open-loop, if > 1 linear regression is used for reduce offset error,
 * but the time for Ke identification will be longer
 */
#define MOTOR_TUNER_PM_KE_LINEREG_NUM               (1)                            ///< Number of points for Ke calculation in open-loop

#define MOTOR_TUNER_PM_VOLTERR_OUTPUT_TAB_SIZE      (TUNER_VOLTAGE_ERROR_LUT_SIZE) ///< Size of output table for voltage error compensation
#define MOTOR_TUNER_PM_VOLTERR_POINT_NUM            (64)                           ///< Number of points for voltage error identification

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @brief Rotor angle mode
 */
typedef enum e_motor_tuner_pm_rotor_angle_mode
{
    MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP   = 0, ///< Open-loop mode, angle are advanced by specified speed in each tick
    MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_CLOSEDLOOP = 1, ///< Closed-loop mode (PLL), angle and speed is estimated by PLL
} motor_tuner_pm_rotor_angle_mode_t;

/**
 * @brief Signal configuration
 */
typedef struct st_motor_tuner_pm_signal_conf
{
    float signal_amp;                  ///< Signal amplitude
    float signal_offset;               ///< Signal offset
    float signal_freg_hz;              ///< Signal frequency in Hz
} motor_tuner_pm_signal_conf_t;

/**
 * @brief Motor tuner core FOC configuration
 */
typedef struct st_motor_tuner_pm_core_foc_cfg
{
    float current_omega_hz;               ///< Current controller natural frequency[Hz]
    float current_zeta;                   ///< Current controller damping factor
    float e_obs_omega_hz;                 ///< Back-EMF observer natural frequency[Hz]
    float e_obs_zeta;                     ///< Back-EMF observer damping factor
    float pll_est_omega_hz;               ///< PLL estimator natural frequency[Hz]
    float pll_est_zeta;                   ///< PLL estimator damping factor
    float offset_lpf_k;                   ///< Low-pass filter constant for offset calibration
    float offset_calc_time;               ///< Offset calibration time in ticks
    float overcurrent_limit_mult;         ///< Over-current limit multiplier, related to rated current
    float ol2cl_speed_th_coef;            ///< Open-loop to closed-loop speed threshold coefficient, related to base speed
    float cl2ol_speed_th_coef;            ///< Closed-loop to open-loop speed threshold coefficient, related to base speed
    float speed_change_rate_limit;        ///< Speed change rate limit in [rad/s^2]
    float iq_down_time;                   ///< Time in ticks for IQ to ramp down to zero current
    float id_up_time;                     ///< Time in ticks for ID to ramp up to the specified value
    float id_down_time;                   ///< Time in ticks for ID to ramp down to zero current
    float phaseerr_lpf_band_hz;           ///< Phase error low-pass filter bandwidth in Hz
    float r_min;                          ///< Minimum stator resistance limit
    float num_pole_pair_limit;            ///< Maximum number of pole pairs allowed

    float id_ref_coef;                    ///< Coefficient to calculate the ID reference current during speed control
    float speed_omega;                    ///< Default speed omega used in various calculations
    float speed_offset_coef;              ///< Speed offset coefficient used to calculate speed offset during startup
    float assumed_inertia;                ///< Inertia value used in speed PI gain calculation when inertia is unknown
    float default_rls_init;               ///< Default initial value for RLS method identification
    float default_rls_forget_k;           ///< Default forgetting factor for RLS method identification

    uint32_t mcu_adc_resolution;          ///< ADC resolution in digits, e.g. 12-bit ADC = 4096
    uint32_t mcu_pwm_resolution;          ///< PWM resolution in digits, depends on timer period and mode
    float    inv_info_current_full_range; ///< Full range current that can be measured by the inverter current sensing
    float    inv_info_current_limit;      ///< Current limitation of the inverter
    float    inv_info_overvoltage_th;     ///< Over-voltage threshold of the inverter
    float    inv_info_undervoltage_th;    ///< Under-voltage threshold of the inverter
    float    inv_info_pwm_duty_min;       ///< Minimum PWM duty cycle of the inverter
    float    inv_info_pwm_duty_max;       ///< Maximum PWM duty cycle of the inverter
    float    inv_info_pwm_cycle_s;        ///< PWM period of the inverter
    float    inv_info_pwm_deadtime_s;     ///< PWM dead-time of the inverter
} motor_tuner_pm_core_foc_cfg_t;

/* Basic motor drive signals */
typedef struct st_motor_tuner_pm_core_foc
{
    void * p_context;                                   ///< Pointer to the instance control structure */
    motor_tuner_pm_core_foc_cfg_t const * p_cfg;        ///< Pointer to the runtime configuration

    uint16_t ctrl_level;                                ///< Determine control process is enabled or disabled, RW */

    /* Motor drive control mode selection */
    uint16_t run_mode;                                  ///< Tuner error code, RO */
    uint16_t error_status;                              ///< Tuner error code, RO */
    motor_tuner_pm_rotor_angle_mode_t rotor_angle_mode; ///< Determine rotor angle by PLL or specified value, RO */

    /* Inverter properties */
    float current_lsb;                                  ///< Current LSB value in [A/digit]
    float pwm_duty_lsb;                                 ///< PWM duty LSB value in [duty/digit]

    float vdc_ad;                                       ///< Measured DC bus voltage after AD conversion
    float angle_rad;                                    ///< Rotor angle in radians
    float speed_rad;                                    ///< Rotor speed in rad/s
    float speed_lpf_rad;                                ///< Rotor speed after low-pass filter in rad/s
    float ia_ref;                                       ///< Reference phase A/U current
    float ib_ref;                                       ///< Reference phase B/V current
    float ic_ref;                                       ///< Reference phase C/W current
    float ia_ad;                                        ///< Measured phase A/U current after AD conversion
    float ib_ad;                                        ///< Measured phase B/V current after AD conversion
    float ic_ad;                                        ///< Measured phase C/W current after AD conversion
    float id_ref;                                       ///< Reference d-axis current
    float iq_ref;                                       ///< Reference q-axis current
    float id_ad;                                        ///< Measured d-axis current after AD conversion
    float iq_ad;                                        ///< Measured q-axis current after AD conversion
    float vd_ref;                                       ///< Reference d-axis voltage
    float vq_ref;                                       ///< Reference q-axis voltage
    float va_ref_pwm;                                   ///< Reference phase A/U voltage for PWM
    float vb_ref_pwm;                                   ///< Reference phase B/V voltage for PWM
    float vc_ref_pwm;                                   ///< Reference phase C/W voltage for PWM
    float ref_speed_rad;                                ///< Reference speed in rad/s
    float ref_speed_rad_ctrl;                           ///< Reference speed for control in rad/s
    float limit_speed_change;                           ///< Limit for speed change
    float e;                                            ///< Back-EMF magnitude
    float ed;                                           ///< Back-EMF d-axis component
    float eq;                                           ///< Back-EMF q-axis component
    float e_lpf;                                        ///< Back-EMF magnitude after low-pass filter
    float vmag_max;                                     ///< Maximum voltage magnitude
    float imag_max;                                     ///< Maximum current magnitude

    float    duty_available;                            ///< Available duty cycle for PWM
    float    offset_ia;                                 ///< Current offset for phase A/U
    float    offset_ib;                                 ///< Current offset for phase B/V
    float    offset_ic;                                 ///< Current offset for phase C/W
    float    pre_offset_ia;                             ///< Previous current offset for phase A/U
    float    pre_offset_ib;                             ///< Previous current offset for phase B/V
    float    pre_offset_ic;                             ///< Previous current offset for phase C/W
    float    offset_lpf_k;                              ///< Low-pass filter coefficient for current offset
    uint16_t cnt_adjust;                                ///< Counter for offset calibration
    float    offset_calc_time;                          ///< Offset calibration time in ticks
    float    lim_iq;                                    ///< IQ current limit
    float    overcurrent_limit_hw;                      ///< Hardware over-current limit
    float    overcurrent_limit;                         ///< Software over-current limit
    float    overvoltage_limit;                         ///< Over-voltage limit
    float    undervoltage_limit;                        ///< Under-voltage limit
    float    ol2cl_speed_th;                            ///< Open-loop to closed-loop speed threshold

    float                   open_loop_id;               ///< D-axis current during open-loop
    float                   speed_lpf_omega_hz;         ///< Speed low-pass filter bandwidth in Hz
    float                   omega_current;              ///< Current controller natural frequency[rad/s]
    float                   zeta_current;               ///< Current controller damping factor
    float                   kp_id;                      ///< Proportional gain for d-axis current controller
    float                   ki_id;                      ///< Integral gain for d-axis current controller
    float                   kp_iq;                      ///< Proportional gain for q-axis current controller
    float                   ki_iq;                      ///< Integral gain for q-axis current controller
    float                   omega_e_obs;                ///< Back-EMF observer natural frequency[rad/s]
    float                   zeta_e_obs;                 ///< Back-EMF observer damping factor
    float                   kp_speed;                   ///< Proportional gain for speed controller
    float                   ki_speed;                   ///< Integral gain for speed controller
    float                   id_down_speed_rad;          ///< Speed at which ID starts to ramp down to zero current
    float                   id_up_speed_rad;            ///< Speed at which ID starts to ramp up from zero current
    float                   id_up_step;                 ///< Step value for ID ramp up
    float                   id_down_step;               ///< Step value for ID ramp down
    float                   phase_error;                ///< Phase error between estimated angle and voltage vector angle
    float                   va_ref;                     ///< Reference phase A/U voltage
    float                   vb_ref;                     ///< Reference phase B/V voltage
    float                   vc_ref;                     ///< Reference phase C/W voltage
    float                   va_ref_comp;                ///< Compensated reference phase A/U voltage
    float                   vb_ref_comp;                ///< Compensated reference phase B/V voltage
    float                   vc_ref_comp;                ///< Compensated reference phase C/W voltage
    float                   vphase_limit;               ///< Maximum phase voltage limit for voltage compensation
    float                   moda;                       ///< Modulation index for phase A/U
    float                   modb;                       ///< Modulation index for phase B/V
    float                   modc;                       ///< Modulation index for phase C/W
    float                   speed_1ms_rad;              ///< Speed in rad/s calculated every 1 ms
    uint16_t                ctrl_conf;                  ///< Control configuration
    uint8_t                 flag_down_to_ol;            ///< Flag to indicate down-switching to open-loop
    uint8_t                 flag_iq_ref;                ///< Flag to indicate IQ reference source
    uint8_t                 flag_id_ref;                ///< Flag to indicate ID reference source
    uint8_t                 flag_speed_ref;             ///< Flag to indicate speed reference source
    float                   iq_down_step;               ///< Step value for IQ ramp down
    float                   ol_iq_down_step;            ///< Step value for IQ ramp down during open-loop
    float                   kp_est_speed;               ///< Proportional gain for speed estimator
    float                   ki_est_speed;               ///< Integral gain for speed estimator
    float                   vcomp_array[3];             ///< Voltage error compensation voltage array for three phases
    float                   vcomp_i_array[3];           ///< Voltage error compensation current array for three phases
    float                   temp_cos;                   ///< Temporary variable to store cosine value
    float                   temp_sin;                   ///< Temporary variable to store sine value
    pi_ctrl_t               pi_vd;                      ///< PI controller for d-axis current
    pi_ctrl_t               pi_vq;                      ///< PI controller for q-axis current
    pi_ctrl_t               pi_speed;                   ///< PI controller for speed
    motor_bemf_observer_t   bemf_observer;              ///< Back-EMF observer
    motor_pll_est_t         pll_est;                    ///< PLL estimator
    motor_parameter_ramp_t  motor_params;               ///< Motor parameters
    motor_volt_error_comp_t volt_comp;                  ///< Voltage error compensation
    motor_common_lpf_t      speed_lpf;                  ///< Speed low-pass filter
    float                   phase_error_lpf;            ///< Phase error low-pass filter
    float                   phase_error_hpf;            ///< Phase error high-pass filter
    float                   torque_current;             ///< Torque-producing current

    motor_tuner_rls_t     rls;                          ///< RLS identification module
    motor_tuner_dft_t     dft;                          ///< DFT identification module
    motor_tuner_dftdiff_t dftdiff;                      ///< DFT difference identification module
    motor_tuner_sinref_t  sinref;                       ///< Sine wave reference generator

    /* Control points */
    uint8_t enable_pwm_output;                          ///< Enable PWM output if not zero
    uint8_t abort_request;                              ///< Abort request flag

    /* Shared counter, to save RAM */
    uint32_t sample_cnt;                                ///< General purpose sample counter
    uint16_t one_ms_cnt;                                ///< 1ms counter
    uint16_t sum_cnt;                                   ///< General purpose sum counter

    /* Shared variables */
    float r_max;                                        ///< The upper limit of a acceptable resistance identification result [ohm] */
    float r_min;                                        ///< The lower limit of a acceptable resistance identification result [ohm] */
    float ld_min;                                       ///< The lower limit of a acceptable Ld identification result [H] */
    float lq_min;                                       ///< The lower limit of a acceptable Lq identification result [H] */

    /* Timing variables */
    float pwm_period_ms;                                ///< PWM period in milliseconds
    float ctrl_period_ms;                               ///< Control period in milliseconds
    float spd_ctrl_period_ms;                           ///< Speed control period in milliseconds
    float ctrl_freq_hz;                                 ///< Control frequency in Hz
    float spd_ctrl_freq_hz;                             ///< Speed control frequency in Hz

    /* Identification parameters */
    float rated_current;                                ///< Rated current
    float rated_power;                                  ///< Rated power
    float pole_pairs;                                   ///< Number of pole pairs

    /* Shared identified parameters */
    float r_dc;                                         ///< Stator resistance
    float v_err;                                        ///< Voltage error
    float r;                                            ///< Stator resistance
    float ld;                                           ///< D-axis inductance
    float lq;                                           ///< Q-axis inductance
    float ke;                                           ///< Back-EMF constant
    float j;                                            ///< Rotor inertia
    float d;                                            ///< Viscous friction coefficient

    uint32_t assert_failed_lineno;                      ///< Line number where assert failed
    uint32_t assert_failed_file;                        ///< File code where assert failed
} motor_tuner_pm_core_foc_t;

typedef enum e_motor_tuner_pm_volterr_status
{
    TUNER_PM_VOLTERR_SEQ_INIT,         ///< The INITIALIZATION stage, to determine parameters for measurement */
    TUNER_PM_VOLTERR_SEQ_ID_R,         ///< The READY stage equivalent, to retrieve resistance by RLS method */
    TUNER_PM_VOLTERR_SEQ_ID_V_OVER_I,  ///< The MEASURE stage equivalent, to acquire the IV characteristics */
    TUNER_PM_VOLTERR_SEQ_CALC,         ///< The CALCULATION stage, process bulk data */
    TUNER_PM_VOLTERR_SEQ_CHECK,        ///< The CHECK stage, performs sanity check on the results */
    TUNER_PM_VOLTERR_SEQ_RESET,        ///< The RESET ramp down the system */
    TUNER_PM_VOLTERR_SEQ_COMPLETED     ///< The completed stage, sequence function returns 1, sequence will remain on this stage until being reset
} motor_tuner_pm_volterr_status_t;

/**
 * @brief Voltage error measurement configuration
 */
typedef struct st_motor_tuner_pm_volterr_cfg
{
    uint8_t  enable;                   ///< Enable voltage error measurement
    float    rls_fgt_factor;           ///< Forgetting factor for RLS resistance identification
    float    avg_sample;               ///< Number of samples to average for each voltage error point
    float    avg_sample_fast;          ///< Number of samples to average for each voltage error point during fast identification
    float    avg_wait_time;            ///< Waiting time [ms] after reaching each current target before starting to sample
    uint32_t point_num;                ///< Number of voltage error points to be identified
    float    min_current_step_lsb;     ///< Minimum current step in LSB for voltage error measurement
    uint32_t iteration_num;            ///< Number of iterations for resistance identification
    float    rls_upper_current;        ///< Upper current limit for RLS resistance identification
    float    rls_lower_current;        ///< Lower current limit for RLS resistance identification
    float    init_r;                   ///< Initial resistance value for RLS resistance identification
} motor_tuner_pm_volterr_cfg_t;

/**
 * @brief Voltage error measurement R identification method
 */
typedef enum e_motor_tuner_volterr_cfg_rid
{
    TUNER_PM_VOLTERR_RID_RLS,          ///< Identify R before VI measurement
    TUNER_PM_VOLTERR_RID_IGNORE        ///< Use initial R
} motor_tuner_volterr_cfg_rid_t;

/**
 * @brief Voltage error measurement structure
 */
typedef struct st_motor_tuner_pm_volterr
{
    motor_tuner_pm_volterr_status_t e_status;                         ///< The main status for voltage error measurement sequence
    float current_table[MOTOR_TUNER_PM_VOLTERR_POINT_NUM];            ///< Current column identified voltage error lookup table
    float voltage_table[MOTOR_TUNER_PM_VOLTERR_POINT_NUM];            ///< Voltage column identified voltage error lookup table
    float slope_table[MOTOR_TUNER_PM_VOLTERR_POINT_NUM];              ///< The slope of linear regression of the nearest 5 samples
    float intercept_table[MOTOR_TUNER_PM_VOLTERR_POINT_NUM];          ///< The intercept of linear regression of the nearest 5 samples
    float sat_current;                                                ///< Identified current that the voltage error dose not increase,
    ///< the current table will refer to this value
    float    sat_voltage;                                             ///< Identified maximum voltage error
    float    r_dc;                                                    ///< The R in DC condition used to calculate current step and store final result
    float    meas_volt_sum;                                           ///< The sum of sampled voltage in order to calculate mean voltage
    float    meas_current_sum;                                        ///< The sum of sampled current in order to calculate mean voltage
    float    current_target;                                          ///< The target current [A] that should be achieved by last voltage command
    float    voltage_step;                                            ///< The voltage step should be increased to achieve the next target current
    uint32_t iteration_cnt;                                           ///< The counter of resistance measurement iteration
    uint32_t count;                                                   ///< The general counter
    uint32_t meas_index;                                              ///< The index of voltage error point that is under measurement

    float output_current_tab[MOTOR_TUNER_PM_VOLTERR_OUTPUT_TAB_SIZE]; ///< Output current table for voltage error compensation
    float output_voltage_tab[MOTOR_TUNER_PM_VOLTERR_OUTPUT_TAB_SIZE]; ///< Output voltage table for voltage error compensation
    float output_vdc_ref;                                             ///< Reference DC bus voltage for output table
    float output_rdc;                                                 ///< Stator resistance for output table

    motor_tuner_volterr_cfg_rid_t rid_method;                         ///< R identification method before VI measurement
    float   r_init;                                                   ///< Initial resistance value for RLS resistance identification
    float   i_lsb;                                                    ///< Current LSB value in [A/digit] during voltage error measurement
    float   current_step_ilsb;                                        ///< Current step in LSB for voltage error measurement
    int32_t start_current_lsb;                                        ///< Starting current in LSB for voltage error measurement

    motor_tuner_pm_volterr_cfg_t * p_cfg;                             /* Pointer to configuration structure */
} motor_tuner_pm_volterr_t;

/**
 * @brief Motor tuner PM Rdiff sequence enumeration
 */
typedef enum e_tuner_pm_seq_r_diff
{
    TUNER_PM_SEQ_R_DIFF_INIT,          ///< Initialization stage
    TUNER_PM_SEQ_R_DIFF_READY1,        ///< Ready stage for first measurement
    TUNER_PM_SEQ_R_DIFF_READY12,       ///< Waiting stage after first measurement
    TUNER_PM_SEQ_R_DIFF_MEASURE1,      ///< Measurement stage for first measurement
    TUNER_PM_SEQ_R_DIFF_READY2,        ///< Ready stage for second measurement
    TUNER_PM_SEQ_R_DIFF_READY22,       ///< Waiting stage after second measurement
    TUNER_PM_SEQ_R_DIFF_MEASURE2,      ///< Measurement stage for second measurement
    TUNER_PM_SEQ_R_DIFF_CALC,          ///< Calculation stage
    TUNER_PM_SEQ_R_DIFF_CHECK,         ///< Check stage
    TUNER_PM_SEQ_R_DIFF_RESET,         ///< Reset stage
    TUNER_PM_SEQ_R_DIFF_COMPLETED      ///< Completed stage
} e_tuner_pm_seq_r_diff_t;

/**
 * @brief Motor tuner PM Rdiff configuration structure
 */
typedef struct st_motor_tuner_pm_rdiff_cfg
{
    float    vd_step_lsb;              ///< Step voltage vd applied during Rdiff measurement
    float    target_current_a;         ///< Target current A coefficient (0.0 to 1.0), multiplied by rated current
    float    target_current_b;         ///< Target current B coefficient (0.0 to 1.0), multiplied by rated current
    float    target_current_margin;    ///< Tolerance upper margin for target current during Rdiff measurement
    float    vd_step_wait_ms;          ///< Waiting time after stepping [ms]
    float    stab_wait;                ///< Stabilization wait time before sampling, unit is vd_step_wait_ms cycle counts
    float    measure_wait_ms;          ///< Waiting time before starting measurement [ms]
    float    measure_time_ms;          ///< Measurement time duration [ms]
    float    reset_time_ms;            ///< Reset time duration [ms]
    uint32_t vd_adjust_timeout;        ///< Timeout count, if the current do not stabilize within this vd_step_wait_ms cycles, the vd step adjustment is stopped
} motor_tuner_pm_rdiff_cfg_t;

/**
 * @brief Motor tuner PM Rdiff measurement structure
 */
typedef struct st_motor_tuner_pm_rdiff
{
    e_tuner_pm_seq_r_diff_t rdiff_status; ///< The main status for Rdiff measurement sequence
    float    target_current_a_min;        ///< Minimum target current A
    float    target_current_a_max;        ///< Maximum target current A
    float    target_current_b_min;        ///< Minimum target current B
    float    target_current_b_max;        ///< Maximum target current B
    float    vd_sample1;                  ///< Sampled vd for first measurement
    float    vd_sample2;                  ///< Sampled vd for second measurement
    float    id_sample1;                  ///< Sampled id for first measurement
    float    id_sample2;                  ///< Sampled id for second measurement
    float    sum_vu;                      ///< Sum of phase U voltage samples
    float    sum_iu;                      ///< Sum of phase U current samples
    uint32_t cnt_stab;                    ///< Stabilization counter
    uint32_t sample_cnt;                  ///< Sample counter
    uint32_t timeout_cnt;                 ///< Timeout counter for vd step adjustment
    float    r_diff;                      ///< Identified resistance difference
    float    volterr_est;                 ///< Estimated voltage error from Rdiff measurement
    float    v_step;                      ///< Actual applied vd step during Rdiff measurement

    motor_tuner_pm_rdiff_cfg_t * p_cfg;   ///< Pointer to configuration structure
} motor_tuner_pm_rdiff_t;

/**
 * @brief Motor tuner PM R and Ld identification sequences (DFT method)
 */
typedef enum e_motor_tuner_pm_rld_dft
{
    TUNER_PM_SEQ_RLD_DFT_INIT,         ///< Initialization stage
    TUNER_PM_SEQ_RLD_DFT_READY,        ///< Ready stage
    TUNER_PM_SEQ_RLD_DFT_MEASURE,      ///< Measurement stage
    TUNER_PM_SEQ_RLD_DFT_CALC,         ///< Calculation stage
    TUNER_PM_SEQ_RLD_DFT_CHECK,        ///< Check stage
    TUNER_PM_SEQ_RLD_DFT_RESET,        ///< Reset stage
    TUNER_PM_SEQ_RLD_DFT_COMPLETED,    ///< Completed stage
} motor_tuner_pm_seq_rld_dft_t;

/**
 * @brief Motor tuner PM R and Lq identification sequences (RLS method)
 */
typedef enum e_motor_tuner_pm_rld_rls
{
    TUNER_PM_SEQ_RLD_RLS_INIT,         ///< Initialization stage
    TUNER_PM_SEQ_RLD_RLS_READY,        ///< Ready stage
    TUNER_PM_SEQ_RLD_RLS_MEASURE,      ///< Measurement stage
    TUNER_PM_SEQ_RLD_RLS_CALC,         ///< Calculation stage
    TUNER_PM_SEQ_RLD_RLS_CHECK,        ///< Check stage
    TUNER_PM_SEQ_RLD_RLS_RESET,        ///< Reset stage
    TUNER_PM_SEQ_RLD_RLS_COMPLETED,    ///< Completed stage
} motor_tuner_pm_seq_rld_rls_t;

/**
 * @brief Motor tuner PM Lq identification sequences (DFT method)
 */
typedef enum e_motor_tuner_pm_rlq_dft
{
    TUNER_PM_SEQ_RLQ_DFT_INIT,         ///< Initialization stage
    TUNER_PM_SEQ_RLQ_DFT_READY,        ///< Ready stage
    TUNER_PM_SEQ_RLQ_DFT_MEASURE,      ///< Measurement stage
    TUNER_PM_SEQ_RLQ_DFT_CALC,         ///< Calculation stage
    TUNER_PM_SEQ_RLQ_DFT_CHECK,        ///< Check stage
    TUNER_PM_SEQ_RLQ_DFT_RESET,        ///< Reset stage
    TUNER_PM_SEQ_RLQ_DFT_COMPLETED     ///< Completed stage
} motor_tuner_pm_seq_rlq_dft_t;

/**
 * @brief Motor tuner PM Lq identification sequences (RLS method)
 */
typedef enum e_motor_tuner_pm_rlq_rls
{
    TUNER_PM_SEQ_RLQ_RLS_INIT,         ///< Initialization stage
    TUNER_PM_SEQ_RLQ_RLS_READY,        ///< Ready stage
    TUNER_PM_SEQ_RLQ_RLS_MEASURE,      ///< Measurement stage
    TUNER_PM_SEQ_RLQ_RLS_CALC,         ///< Calculation stage
    TUNER_PM_SEQ_RLQ_RLS_CHECK,        ///< Check stage
    TUNER_PM_SEQ_RLQ_RLS_RESET,        ///< Reset stage
    TUNER_PM_SEQ_RLQ_RLS_COMPLETED     ///< Completed stage
} motor_tuner_pm_seq_rlq_rls_t;

/**
 * @brief Motor tuner PM Ld and Lq identification configuration structure
 */
typedef struct st_motor_tuner_pm_ldq_cfg
{
    float reset_time_ms;               ///< Reset time duration [ms]
    float stab_time_coef;              ///< Stabilization wait time coefficient, final value is multiplied by motor time constant (L/R)
    float ldq_init_assumption;         ///< Initial assumption value of inductance for calculating wait time [H]
    float rld_freq;                    ///< Frequency for R & Ld measurement
    float rld_vd_amp_coef;             ///< Vd amplitude coefficient for R & Ld measurement, multiplied by (R*rated_current)
    float rld_vd_offset_coef;          ///< Vd offset coefficient for R & Ld measurement, multiplied by (R*rated_current) and added by v_err
    float rld_rls_measure_offset_time; ///< Measurement offset time for R & Ld RLS measurement [ms]
    float rld_rls_measure_num;         ///< Number of periods for R & Ld RLS measurement
    float rld_dft_measure_num;         ///< Number of periods for R & Ld DFT measurement
    float lq_freq;                     ///< Frequency for Lq measurement [Hz]
    float lq_vq_amp_coef;              ///< Vq amplitude coefficient for Lq measurement, multiplied by inpedence*rated_current
    float lq_vd_offset_coef;           ///< Vd offset coefficient for Lq measurement, multiplied by (R*rated_current) and added by v_err
    float lq_rls_measure_num;          ///< Number of periods for Lq RLS measurement
    float lq_dft_measure_num;          ///< Number of periods for Lq DFT measurement
} motor_tuner_pm_ldq_cfg_t;

/**
 * @brief Motor tuner PM Ld and Lq identification structure
 */
typedef struct st_motor_tuner_pm_ldq
{
    float r_dft;                               ///< Identified resistance from DFT method
    float r_rls;                               ///< Identified resistance from RLS method
    float ld_dft;                              ///< Identified d-axis inductance from DFT method
    float ld_rls;                              ///< Identified d-axis inductance from RLS method
    float lq_dft;                              ///< Identified q-axis inductance from DFT method
    float lq_rls;                              ///< Identified q-axis inductance from RLS method
    motor_tuner_pm_ldq_cfg_t * p_cfg;          ///< Pointer to configuration structure

    float ldq_freq_ref_hz;                     ///< Reference frequency for Ld & Lq measurement
    float time_elapsed_ms;                     ///< Elapsed time [ms]
    motor_tuner_pm_seq_rld_rls_t ldrls_status; ///< Ld RLS measurement sequence status
    motor_tuner_pm_seq_rld_dft_t lddft_status; ///< Ld DFT measurement sequence status
    motor_tuner_pm_seq_rlq_rls_t lqrls_status; ///< Lq RLS measurement sequence status
    motor_tuner_pm_seq_rlq_dft_t lqdft_status; ///< Lq DFT measurement sequence status
    float    vd_ref_amp;                       ///< Vd reference amplitude during Ld measurement
    float    vq_ref_amp;                       ///< Vq reference amplitude during Lq measurement
    float    vd_ref_offset;                    ///< Vd reference offset during Ld and Lq measurement
    float    dft_real;                         ///< DFT real part accumulator
    float    dft_imag;                         ///< DFT imaginary part accumulator
    float    dft_amp;                          ///< DFT amplitude
    float    dft_amp2;                         ///< DFT amplitude squared
    float    current_pre;                      ///< Previous current sample
    float    voltage_pre;                      ///< Previous voltage sample
    float    id_offset;                        ///< Id offset
    float    id_sum;                           ///< Id sum for calculating average current
    float    id_sum_cnt;                       ///< Id sum counter
    float    a_est;                            ///< RLS estimated parameter a
    float    b_est;                            ///< RLS estimated parameter b
    uint16_t stab_wait_ms;                     ///< Stabilization wait time in ms
    float    angle_pre;                        ///< Previous angle sample

    /* Monitoring states */
    float lddft_v;                             ///< Ld DFT voltage magnitude
    float lddft_i_mag;                         ///< Ld DFT current magnitude
    float lddft_i_img;                         ///< Ld DFT current imaginary part
    float lddft_i_real;                        ///< Ld DFT current real part
    float lqdft_v;                             ///< Lq DFT voltage magnitude
    float lqdft_i_mag;                         ///< Lq DFT current magnitude
    float lqdft_i_img;                         ///< Lq DFT current imaginary part
    float lqdft_i_real;                        ///< Lq DFT current real part
} motor_tuner_pm_ldq_t;

/**
 * @brief Motor tuner PM JD identification sequences
 */
typedef enum e_tuner_pm_seq_j
{
    TUNER_PM_SEQ_J_INIT,               ///< Initialization stage
    TUNER_PM_SEQ_J_READY,              ///< Ready stage
    TUNER_PM_SEQ_J_MEASURE,            ///< Measurement stage
    TUNER_PM_SEQ_J_CALC,               ///< Calculation stage
    TUNER_PM_SEQ_J_CHECK,              ///< Check stage
    TUNER_PM_SEQ_J_RESET,              ///< Reset stage
    TUNER_PM_SEQ_J_COMPLETED           ///< Completed stage
} motor_tuner_pm_seq_j_t;

/**
 * @brief JD measurement configuration structure
 */
typedef struct st_motor_tuner_pm_jd_cfg
{
    float speedpi_omega;               ///< Speed PI natural frequency [Hz] used in inertia identification, should be larger than speed_osc_freq_hz * 2
    float speed_osc_freq_hz;           ///< Speed sine wave frequency [Hz]
    float speed_osc_amp_coef;          ///< Speed sine wave amplitude coefficient, related to base speed
    float speed_osc_amp_coef_min;      ///< Minimum speed sine wave amplitude coefficient, related to base speed
    float rls_init;                    ///< RLS initial value
    float rls_forget_k;                ///< RLS forgetting factor
    float dft_num;                     ///< Number of cycles to be sampled by DFT method
    float measure_start_amp_rate;      ///< When speed sine wave amplitude reaches this rate of the final amplitude, start to measure
    float stab_wait;                   ///< Wait time [ms] for the system to be stable before starting measurement
    float stop_time;                   ///< Stop time [ms] for slowing down the motor at the end of JD identification
} motor_tuner_pm_jd_cfg_t;

/**
 * @brief Motor tuner PM JD identification structure
 */
typedef struct st_motor_tuner_pm_jd
{
    motor_tuner_pm_seq_j_t e_status;   ///< JD main sequence status see definition of type motor_tuner_pm_seq_j_t
    uint8_t                j_seq;      ///< JD measure sequence status see macro with prefix JD_PRV_MEASURE_SEQ
    float iq_sum;                      ///< Iq sum from last measure function execution
    float iq_amp;                      ///< Amplitude of Iq
    float iq;                          ///< Iq used in JD measurement
    float iq_lpf;                      ///< Iq filtered by 1st order LPF
    float refspeed_freq_hz;            ///< Frequency of the sine signal used as speed command
    float refspeed_amp_max;            ///< Maximum amplitude of the sine signal in [rad/s]
    float refspeed_amp;                ///< Current amplitude of the sine signal in [rad/s]
    float refspeed_offset;             ///< Offset of the sine signal in [rad/s]
    float rls_respns_pre;              ///< The last response (the speed) from the mechanical system for RLS method
    float speed_rad;                   ///< Speed used in the JD measurement
    float speed_amp;                   ///< Speed vibration amplitude, measured by DFT method
    float ol2cl_speed;                 ///< The threshold that transient from open-loop drive mode to the closed-loop mode
    float cl2ol_speed;                 ///< The threshold that transient from closed-loop drive mode to the open-loop mode
    float dft_cycle_cnt;               ///< The counter to count how many cycles has been sampled by DFT method */
    float rls_coefa;                   ///< The weight a estimated by RLS
    float rls_coefb;                   ///< The weight b estimated by RLS
    float iq_offset;                   ///< The iq offset measured with fixed speed command, to remove offset for RLS
    float j_max;                       ///< The maximum tolerable estimated inertia
    float j_min;                       ///< The minimum tolerable estimated inertia
    float j_pi_ctrl;                   ///< The inertia that is currently used to design speed PI controller
    float time_elapsed_ms;             ///< Elapsed Time [ms]
    float setup_wait_cnt;              ///< Counter for waiting
#if (TUNER_PM_JD_PRV_RLS_MODE == 3)
    motor_tuner_rls3_t rls3;           ///< RLS3 structure for inertia identification
#endif

    float j_rls;                       ///< The inertia estimated by RLS method
    float d_rls;                       ///< The viscous friction coefficient estimated by RLS method
    float j_dft;                       ///< The inertia estimated by DFT method
    float d_dft;                       ///< The viscous friction coefficient estimated by DFT method
    float user_inertia_range;          ///< The inertia range set by user for tuning process, 0.0 ~ 1.0

    motor_tuner_pm_jd_cfg_t * p_cfg;   ///< Pointer to configuration structure
} motor_tuner_pm_jd_t;

/**
 * @brief Ke measurement sequences enumeration
 */
typedef enum e_motor_tuner_pm_ke_seq
{
    TUNER_PM_SEQ_KE_INIT,              ///< Initialization stage
    TUNER_PM_SEQ_KE_READY,             ///< Ready stage
    TUNER_PM_SEQ_KE_MEASURE,           ///< Measurement stage
    TUNER_PM_SEQ_KE_CALC,              ///< Calculation stage
    TUNER_PM_SEQ_KE_CHECK,             ///< Check stage
    TUNER_PM_SEQ_KE_RESET,             ///< Reset stage
    TUNER_PM_SEQ_KE_COMPLETED          ///< Completed stage
} e_tuner_pm_seq_ke_t;

/**
 * @brief Sub-sequences for KE measurement
 */
typedef enum tuner_pm_ke_sub_seq
{
    KE_IDLE = 0,                       ///< Idle state
    KE_OL_ID_RAMPUP,                   ///< Open-loop Id ramp-up
    KE_OL_SPEED_RAMPUP,                ///< Open-loop speed ramp-up
    KE_OL_MEASURE_WAIT_STAB,           ///< Open-loop waiting for Id to stabilize before measuring KE
    KE_OL_MEASURE_SAMPLING,            ///< Open-loop KE measurement sampling
    KE_OL_SPEED_SLOPE_DOWN,            ///< Open-loop speed slope down
    KE_CL_SPEED_RAMPUP,                ///< Closed-loop speed ramp-up
    KE_CL_WAIT_STAB,                   ///< Closed-loop waiting for Id to stabilize before measuring KE
    KE_CL_MEASURE,                     ///< Closed-loop KE measurement sampling
    KE_CL_SPEED_SLOPE_DOWN             ///< Closed-loop speed slope down
} motor_tuner_pm_ke_sub_seq_t;

/**
 * @brief KE measurement configuration structure
 */
typedef struct st_motor_tuner_pm_ke_cfg
{
    /**
     *  @brief Drive frequency [Hz] in open-loop drive for KE measurement
     *  The actual freq of open-loop drive may be lower if BEMF threshold is reached earlier
     *
     *  @note For most motors, BEMF threshould should be reached before the this target frequency.
     *        Please adjust this value if you do not want to stress the motor too much during KE measurement.
     */
    float ol_target_freq_hz;

    /**
     * @brief Ramp-up rate in [Hz/s] for open-loop speed during KE measurement
     * This value should be tuned according to the motor inertia and frictional load.
     *
     * @note High ramp-up rate may cause instability or even failure in the open-loop start-up.
     *       if the start-up fails (current injected but rotor not rotating), reduce this value.
     */
    float ol_ramp_up_rate_hzps;

    /**
     * @brief Relative value to maximum voltage on dp frame for stopping open-loop acceleration
     * If abs(bemf) > (voltage_max_on_dq * bemf_threshold_coef), the open-loop acceleration will be stopped since SNR is enough for KE measurement.
     */
    float bemf_threshold_coef;

    float ol_stab_wait_ms;             ///< Waiting time for Id to stabilize before measuring KE [ms]
    float measure_time_ms;             ///< Time duration to measure KE at steady state [ms]
    float reset_time_ms;               ///< Time duration to wait after reset before starting next process [ms]
} motor_tuner_pm_ke_cfg_t;

/**
 * @brief KE measurement structure
 */
typedef struct st_motor_tuner_pm_ke
{
    float                       ol_freq_ref_step_hz;    ///< Open-loop frequency reference step in [Hz] for each control cycle
    e_tuner_pm_seq_ke_t         ke_status;              ///< KE main sequence status see definition of type e_tuner_pm_seq_ke_t
    motor_tuner_pm_ke_sub_seq_t ke_sub_seq;             ///< KE sub-sequence status see definition of type motor_tuner_pm_ke_sub_seq_t

    uint32_t sample_cnt;                                ///< Sample counter during KE measurement
    float    time_elapsed_ms;                           ///< Elapsed Time [ms]
    float    time_steady_ms;                            ///< Time duration that speed is steady during KE measurement [ms]
    float    ol_freq_ref_hz;                            ///< Open-loop frequency reference in [Hz]
    float    id_ref_step;                               ///< D-axis current reference step for each control cycle during open-loop ramp-up
    float    e_sum;                                     ///< Back-EMF sum during KE measurement
    float    ed_sum;                                    ///< D-axis Back-EMF sum during KE measurement
    float    eq_sum;                                    ///< Q-axis Back-EMF sum during KE measurement
    float    speed_rad_sum;                             ///< Speed sum during KE measurement
    float    vd_ref_sum;                                ///< D-axis voltage reference sum during KE measurement
    float    vq_ref_sum;                                ///< Q-axis voltage reference sum during KE measurement
    float    speed_rad_ave;                             ///< Average speed during KE measurement
    float    vd_ref_ave;                                ///< Average d-axis voltage reference during KE measurement
    float    vq_ref_ave;                                ///< Average q-axis voltage reference during KE measurement
    float    ed_ave;                                    ///< Average d-axis Back-EMF during KE measurement
    float    eq_ave;                                    ///< Average q-axis Back-EMF during KE measurement
    float    id_ave;                                    ///< Average d-axis current during KE measurement
    float    ke_max;                                    ///< Maximum Ke value during KE measurement
    float    ke_min;                                    ///< Minimum Ke value during KE measurement
    float    ke_over_id[MOTOR_TUNER_PM_KE_LINEREG_NUM]; ///< Ke over Id data points for linear regression
    float    id[MOTOR_TUNER_PM_KE_LINEREG_NUM];         ///< Id data points for linear regression
    float    ke_open;                                   ///< Ke identified in open-loop stage
    float    ke_closed_loop;                            ///< Ke identified in closed-loop stage
    uint32_t index;                                     ///< Index for ke_over_id and id data points
    uint8_t  no_stop;                                   ///< Do not stop on finish if true, for skipping the start-up sequence in next stage to save time

    motor_tuner_pm_ke_cfg_t * p_cfg;                    ///< Pointer to configuration structure
} motor_tuner_pm_ke_t;

/** PMSM Tuner extended configuration */
typedef struct st_motor_tuner_pm_extend_cfg
{
    motor_tuner_pm_volterr_cfg_t  tuner_volterr_cfg; ///< Voltage error identification configuration
    motor_tuner_pm_rdiff_cfg_t    tuner_rdiff_cfg;   ///< Resistance identification configuration
    motor_tuner_pm_ldq_cfg_t      tuner_ldq_cfg;     ///< Inductance identification configuration
    motor_tuner_pm_ke_cfg_t       tuner_ke_cfg;      ///< Back-EMF constant identification configuration
    motor_tuner_pm_jd_cfg_t       tuner_jd_cfg;      ///< Inertia and friction identification configuration
    motor_tuner_pm_core_foc_cfg_t base_foc_cfg;      ///< Base FOC configuration
    uint8_t pwm_tick_per_irq;                        ///< PWM ticks per control interrupt
    float   speed_ctrl_period;                       ///< Speed control period in seconds
} motor_tuner_pm_extend_cfg_t;

/** Tuner control structure */
typedef struct st_motor_tuner_pm_ctrl
{
    uint32_t open;                            ///< Open flag
    motor_tuner_pm_core_foc_t base_foc;       ///< Base FOC control structure
    motor_tuner_pm_volterr_t  tuner_volterr;  ///< Voltage error identification structure
    motor_tuner_pm_rdiff_t    tuner_rdiff;    ///< Resistance identification structure
    motor_tuner_pm_ldq_t      tuner_ldq;      ///< Inductance identification structure
    motor_tuner_pm_ke_t       tuner_ke;       ///< Back-EMF constant  identification structure
    motor_tuner_pm_jd_t       tuner_jd;       ///< Inertia and friction identification structure

    motor_tuner_request_t last_request;       ///< Last request
    motor_tuner_status_t  tune_status;        ///< Overal tuning status
    uint16_t              tune_stage;         ///< Current tuning stage, @see motor_tuner_pm_stage_t
    float                 total_time_elapsed; ///< Indicates how long time elapsed from starting identification */

    struct st_motor_tuner_pm_user_inputs
    {
        float    current_setting;             ///< The current reference used during the identification
        float    inertia_setting;             ///< The load inertia used during the identification
        uint16_t polepairs_setting;           ///< The number of pole pairs of the motor
        uint16_t volterr_setting;             ///< The voltage error identification setting
        uint8_t  volterr_is_enabled;          ///< Whether conduct voltage error identification or not
        float    init_r;                      ///< The initial R, if not 0 the respective identification will be skipped
        float    init_ld;                     ///< The initial Ld, if not 0 the respective identification will be skipped
        float    init_lq;                     ///< The initial Lq, if not 0 the respective identification will be skipped
        float    init_ke;                     ///< The initial Ke, if not 0 the respective identification will be skipped
        float    init_j;                      ///< The initial j, if not 0 the respective identification will be skipped
    } user_inputs;

    /* Derived parameters */
    float rated_speed_elec_rad;               ///< The rated speed (electrical) in [rad/s]
    float rated_speed_mech_rpm;               ///< The rated speed (mechanical) in [rpm]
    float rated_torque_nm;                    ///< The rated torque [Nm]
    float rated_current_max;                  ///< The maximum rated current [Arms] calculated from inverter parameter

    motor_tuner_cfg_t const * p_cfg;          ///< Pointer to the runtime configuration
    void * p_context;                         ///< Placeholder for user data
} motor_tuner_pm_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in interface API structure for this instance. */
extern const motor_tuner_api_t g_motor_tuner_on_motor_tuner_pm;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_TUNER_PM_Open(motor_tuner_ctrl_t * const p_ctrl, motor_tuner_cfg_t const * const p_cfg);
fsp_err_t RM_MOTOR_TUNER_PM_InnerLoopProcess(motor_tuner_ctrl_t * const p_ctrl,
                                             motor_tuner_in_t         * p_in,
                                             motor_tuner_out_t        * p_out);
fsp_err_t RM_MOTOR_TUNER_PM_OuterLoopProcess(motor_tuner_ctrl_t * p_ctrl);
fsp_err_t RM_MOTOR_TUNER_PM_IsActive(motor_tuner_ctrl_t * const p_ctrl, bool * p_is_active);
fsp_err_t RM_MOTOR_TUNER_PM_Start(motor_tuner_ctrl_t * const p_ctrl);
fsp_err_t RM_MOTOR_TUNER_PM_Stop(motor_tuner_ctrl_t * const p_ctrl);
fsp_err_t RM_MOTOR_TUNER_PM_Reset(motor_tuner_ctrl_t * const p_ctrl);
fsp_err_t RM_MOTOR_TUNER_PM_Abort(motor_tuner_ctrl_t * const p_ctrl, uint8_t error_code);

fsp_err_t RM_MOTOR_TUNER_PM_StatusGet(motor_tuner_ctrl_t * const p_ctrl, motor_tuner_status_t * p_status);
fsp_err_t RM_MOTOR_TUNER_PM_ErrorGet(motor_tuner_ctrl_t * const p_ctrl, uint16_t * p_error);
fsp_err_t RM_MOTOR_TUNER_PM_ProgressGet(motor_tuner_ctrl_t * const p_ctrl, float * p_progress);

fsp_err_t RM_MOTOR_TUNER_PM_IdentifiedParamGet(motor_tuner_ctrl_t * const p_ctrl,
                                               motor_tuner_param_type_t   param_type,
                                               float                    * p_value);
fsp_err_t RM_MOTOR_TUNER_PM_IdentifiedVoltageErrorGet(motor_tuner_ctrl_t * const  p_ctrl,
                                                      motor_tuner_volterr_lut_t * p_lut,
                                                      float                     * p_rdc);
fsp_err_t RM_MOTOR_TUNER_PM_VoltageErrorSet(motor_tuner_ctrl_t * const p_ctrl, motor_tuner_volterr_lut_t * p_lut);
fsp_err_t RM_MOTOR_TUNER_PM_KnownParamSet(motor_tuner_ctrl_t * const p_ctrl,
                                          motor_tuner_param_type_t   param_type,
                                          float                      value);

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_MOTOR_TUNER_PM)
 **********************************************************************************************************************/

FSP_FOOTER

#endif                                 /* RM_MOTOR_TUNER_PM_H */
