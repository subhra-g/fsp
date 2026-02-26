/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup MOTOR_SENSOR_HALL
 * @{
 **********************************************************************************************************************/

#ifndef RM_MOTOR_HALL_SENSOR_H
#define RM_MOTOR_HALL_SENSOR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_motor_sensor_api.h"
#include "rm_motor_shared_pos_speed_data.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define MOTOR_SENSOR_HALL_SPEED_COUNTS    (6)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Motor rotation direction */
typedef enum e_motor_sensor_hall_direction
{
    MOTOR_SENSOR_HALL_DIRECTION_CW  = 1, ///< Clockwise rotation direction
    MOTOR_SENSOR_HALL_DIRECTION_CCW = 0, ///< Counter-clockwise rotation direction
} motor_sensor_hall_direction_t;

/** Speed estimation post-process method definitions */
typedef enum e_sensor_hall_speed_select
{
    MOTOR_SENSOR_HALL_SPEED_SELECT_AUTO       = 0, ///< Use weighted average (weights depend on speed and difference)
    MOTOR_SENSOR_HALL_SPEED_SELECT_MOVAVG     = 1, ///< Use moving averaged speed as output
    MOTOR_SENSOR_HALL_SPEED_SELECT_LAST_PULSE = 2, ///< Use the latest speed as output
} motor_sensor_hall_speed_select_t;

/** Status for hall signal capture */
typedef enum e_motor_sensor_hall_signal_status
{
    MOTOR_SENSOR_HALL_SIGNAL_STATUS_INITIAL  = 1, ///< Hall signal is not captured (Initial state)
    MOTOR_SENSOR_HALL_SIGNAL_STATUS_CAPTURED = 0, ///< Hall signal is captured
} motor_sensor_hall_signal_status_t;

/** Extended configuration for hall sensor module */
typedef struct st_motor_sensor_hall_extended_cfg
{
    bsp_io_port_pin_t port_hall_sensor_u;                     ///< Hall U-signal input port
    bsp_io_port_pin_t port_hall_sensor_v;                     ///< Hall V-signal input port
    bsp_io_port_pin_t port_hall_sensor_w;                     ///< Hall W-signal input port

    uint8_t hall_pattern[MOTOR_SENSOR_HALL_SPEED_COUNTS + 1]; ///< The order of hall signal pattern

    float angle_correct;                                      ///< Coefficient to correct angle

    uint16_t default_counts;                                  ///< Default counts for period of hall signal to reset
    uint16_t maximum_period;                                  ///< Maximum counts of hall signal period

    float speed_mix_deviation_threshold;                      ///< Speed mixing deviation threshold

    float   speed_mix_switch_threshold;                       ///< Speed mixing switching threshold in [rad/s], the weight of more precise speed estimation will increase very fast above this value
    uint8_t speed_select;                                     ///< Speed output selection @ref motor_sensor_hall_speed_select_t
} motor_sensor_hall_extended_cfg_t;

/** Signals for hall FOC */
typedef struct st_motor_sensor_hall_instance_signals_ctrl
{
    float speed_el;                                       ///< Estimated electrical speed [rad/s]
    float angle_el;                                       ///< Estimated electrical angle [rad]
    float inner_control_period;                           ///< Inner control cycle period [sec]
    float outer_control_period;                           ///< Outer control cycle period [sec]

    uint8_t state_id_ref;                                 ///< State of Id reference control
    uint8_t state_iq_ref;                                 ///< State of Iq reference control

    float speed_ref_el_ctrl;                              ///< Command electrical speed value [rad/s]

    uint8_t hall_signal;                                  ///< Current hall signal pattern
    uint8_t last_hall_signal;                             ///< Previous hall signal pattern
    motor_sensor_hall_direction_t direction;              ///< Current rotation direction
    motor_sensor_hall_direction_t last_direction;         ///< Previous rotation direction
    uint16_t carrier_count;                               ///< Carrier interrupt count
    uint16_t hall_period[MOTOR_SENSOR_HALL_SPEED_COUNTS]; ///< Array of carrier counts for 2PI calculation
    uint8_t  period_counter;                              ///< Counter index for hall_period array
    float    calculated_angle_el;                         ///< Calculated rotor electrical angle [rad]
    float    calculated_angle_el_per_count;               ///< Angle increment per carrier count [rad]
    float    calculated_speed_el;                         ///< Calculated electrical speed [rad/s]
    float    calculated_speed_el_last_pulse;              ///< Electrical speed from last pulse [rad/s]
    float    calculated_speed_el_mvavg;                   ///< Moving average electrical speed [rad/s]
    float    weight;                                      ///< Weight of speed estimated by last pulse

    uint8_t hall_signal_memory;                           ///< Memorized hall signal at startup
    motor_sensor_hall_signal_status_t hall_signal_status; ///< Hall signal capture status
    uint8_t  hall_signal_count;                           ///< Rotation counter
    float    pseudo_speed_rad;                            ///< Pseudo speed for startup [rad/s]
    float    add_pseudo_speed_rad;                        ///< Step of pseudo speed to update [rad/s]
    uint16_t startup_carrier_count;                       ///< Counter of carrier interrupt for startup
    uint8_t  startup_flag;                                ///< Flag for startup sequence
} motor_sensor_hall_instance_signals_ctrl_t;

/** Hall sensor instane control block */
typedef struct st_motor_sensor_hall_instance_ctrl
{
    uint32_t open;                                               ///< module open flag
    motor_sensor_hall_instance_signals_ctrl_t signals;           ///< Signals and controls structure

    motor_shared_pos_speed_to_inner_t              to_inner;     ///< Structure of data to be sent to inner loop
    const motor_shared_inner_to_position_speed_t * p_from_inner; ///< pointer to data from inner loop
    motor_sensor_cfg_t const * p_cfg;                            ///< Angle related configuration structure
} motor_sensor_hall_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const motor_sensor_api_t g_motor_sensor_on_motor_sensor_hall;

/** @endcond */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_Open(motor_sensor_ctrl_t * const p_ctrl, motor_sensor_cfg_t const * const p_cfg);

fsp_err_t RM_MOTOR_SENSOR_HALL_Close(motor_sensor_ctrl_t * const p_ctrl);

fsp_err_t RM_MOTOR_SENSOR_HALL_Reset(motor_sensor_ctrl_t * const p_ctrl);

fsp_err_t RM_MOTOR_SENSOR_HALL_ParameterUpdate(motor_sensor_ctrl_t * const p_ctrl, motor_sensor_cfg_t const * p_cfg);

fsp_err_t RM_MOTOR_SENSOR_HALL_AngleSpeedInit(motor_sensor_ctrl_t * const          p_ctrl,
                                              float                             ** pp_speed,
                                              float                             ** pp_angle,
                                              motor_sensor_data_exchange_t * const p_out_extra_data);

fsp_err_t RM_MOTOR_SENSOR_HALL_AngleSpeedCalc(motor_sensor_ctrl_t * const        p_ctrl,
                                              motor_sensor_input_inner_t * const p_inner,
                                              motor_sensor_input_outer_t * const p_outer);

fsp_err_t RM_MOTOR_SENSOR_HALL_PositionSpeedGet(motor_sensor_ctrl_t * const p_ctrl,
                                                float * const               p_pos,
                                                float * const               p_speed);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // RM_MOTOR_HALL_SENSOR_H

/*******************************************************************************************************************//**
 * @} (end addtogroup MOTOR_SENSOR_HALL)
 **********************************************************************************************************************/
