/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <math.h>
#include <stdio.h>
#include "rm_motor_sensor_hall.h"
#include "rm_motor_mc_lib.h"
#include "rm_motor_sensor_hall_cfg.h"
#include "rm_motor_sensor_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define     MOTOR_SENSOR_HALL_OPEN    (0X4D414553ULL)

#ifndef MOTOR_SENSOR_HALL_ERROR_RETURN

 #define MOTOR_SENSOR_HALL_ERROR_RETURN(a, err)    FSP_ERROR_RETURN((a), (err))
#endif

#define     MOTOR_SENSOR_HALL_30DEGREE              (MOTOR_FUNDLIB_TWOPI / 12.0F)
#define     MOTOR_SENSOR_HALL_U_SHIFT               (2)
#define     MOTOR_SENSOR_HALL_V_SHIFT               (1)
#define     MOTOR_SENSOR_HALL_CALCULATE_KHZ         (1000.0F)
#define     MOTOR_SENSOR_HALL_CALCULATE_MSEC        (1000.0F)
#define     MOTOR_SENSOR_HALL_FLAG_SET              (1)
#define     MOTOR_SENSOR_HALL_FLAG_CLEAR            (0)

#define     MOTOR_SENSOR_HALL_AVOID_ZERO_DIV        (0.01F)
#define     MOTOR_SENSOR_HALL_HALL_SIGNAL_NUMBER    (6.0F)

/* Id/Iq state */
#define     MOTOR_SENSOR_HALL_ID_STATE_DEFAULT      (3)
#define     MOTOR_SENSOR_HALL_IQ_STATE_DEFAULT      (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static float rm_motor_sensor_hall_clamp01(float f4_input);
static float rm_motor_sensor_hall_speed_mixed_calc(motor_sensor_ctrl_t * const p_ctrl,
                                                   float                       f4_speed_fast,
                                                   float                       f4_speed_precision);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
const motor_sensor_api_t g_motor_sensor_on_motor_sensor_hall =
{
    .open             = RM_MOTOR_SENSOR_HALL_Open,
    .close            = RM_MOTOR_SENSOR_HALL_Close,
    .reset            = RM_MOTOR_SENSOR_HALL_Reset,
    .parameterUpdate  = RM_MOTOR_SENSOR_HALL_ParameterUpdate,
    .angleSpeedInit   = RM_MOTOR_SENSOR_HALL_AngleSpeedInit,
    .angleSpeedCalc   = RM_MOTOR_SENSOR_HALL_AngleSpeedCalc,
    .positionSpeedGet = RM_MOTOR_SENSOR_HALL_PositionSpeedGet,
};

/*******************************************************************************************************************//**
 * @addtogroup MOTOR_SENSOR_HALL
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Opens and configures the Angle Estimation module. Implements
 * @ref motor_sensor_api_t::open.
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_Open
 *
 * @retval FSP_SUCCESS              MTR_ANGL_EST successfully configured.
 * @retval FSP_ERR_ASSERTION        Null pointer, or one or more configuration options is invalid.
 * @retval FSP_ERR_ALREADY_OPEN     Module is already open.  This module can only be opened once.
 * @retval FSP_ERR_INVALID_ARGUMENT Configuration parameter error.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_Open (motor_sensor_ctrl_t * const p_ctrl, motor_sensor_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
#endif

    FSP_ERROR_RETURN(MOTOR_SENSOR_HALL_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    p_instance_ctrl->p_cfg = p_cfg;

    /* Mark driver as open */
    p_instance_ctrl->signals.angle_el = 0.0F;
    p_instance_ctrl->open             = MOTOR_SENSOR_HALL_OPEN;

    p_instance_ctrl->to_inner.mode_sensor = MOTOR_CTRLMODE_DEFAULT;
    p_instance_ctrl->signals.state_id_ref = MOTOR_SENSOR_HALL_ID_STATE_DEFAULT;
    p_instance_ctrl->signals.state_iq_ref = MOTOR_SENSOR_HALL_IQ_STATE_DEFAULT;

    return err;
}

/*******************************************************************************************************************//**
 * @brief Disables specified Angle Estimation module. Implements @ref motor_sensor_api_t::close.
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_Close
 *
 * @retval FSP_SUCCESS              Successfully closed.
 * @retval FSP_ERR_ASSERTION        Null pointer.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_Close (motor_sensor_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl != NULL);
#endif

    p_instance_ctrl->open = 0U;

    return err;
}

/*******************************************************************************************************************//**
 * @brief Reset variables of Angle Estimation module. Implements @ref motor_sensor_api_t::reset
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_Reset
 *
 * @retval FSP_SUCCESS              Successfully reset.
 * @retval FSP_ERR_ASSERTION        Null pointer.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_Reset (motor_sensor_ctrl_t * const p_ctrl)
{
    uint8_t   i;
    fsp_err_t err = FSP_SUCCESS;
    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl != NULL);
#endif

    p_instance_ctrl->signals.speed_el = 0.0F;
    p_instance_ctrl->signals.angle_el = 0.0F;

    /* Reset valid period tracking for correct first-revolution speed calculation */
    p_instance_ctrl->signals.hall_signal_count              = 0U;
    p_instance_ctrl->signals.period_counter                 = 0U;
    p_instance_ctrl->signals.carrier_count                  = 0U;
    p_instance_ctrl->signals.last_hall_signal               = 0U;
    p_instance_ctrl->signals.hall_signal                    = 0U;
    p_instance_ctrl->signals.calculated_speed_el            = 0.0F;
    p_instance_ctrl->signals.calculated_speed_el_last_pulse = 0.0F;
    p_instance_ctrl->signals.calculated_speed_el_mvavg      = 0.0F;
    p_instance_ctrl->signals.calculated_angle_el            = 0.0F;
    p_instance_ctrl->signals.calculated_angle_el_per_count  = 0.0F;

    /* Clear period history */
    for (i = 0U; i < MOTOR_SENSOR_HALL_SPEED_COUNTS; i++)
    {
        p_instance_ctrl->signals.hall_period[i] = 0U;
    }

    return err;
}

/********************************************************************************************************************
 * @brief Update the parameters of Angle&Speed Estimation. Implements @ref motor_sensor_api_t::parameterUpdate
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_ParameterUpdate
 *
 * @retval FSP_SUCCESS              Successfully data is update.
 * @retval FSP_ERR_ASSERTION        Null pointer.
 * @retval FSP_ERR_NOT_OPEN         Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_ParameterUpdate (motor_sensor_ctrl_t * const      p_ctrl,
                                                motor_sensor_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_cfg != NULL);
#endif

    if (FSP_SUCCESS == err)
    {
        p_instance_ctrl->p_cfg = p_cfg;
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief Sets output pointers for speed, angle, and extra data for the inner loop estimation.
 *
 * This function assigns the addresses of the internal speed and angle variables to the provided pointers,
 * and sets up the pointer to extra output data for the inner loop. Also copies control period values from
 * the inner loop input data to the internal signal structure and stores a reference to the inner data.
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_AngleSpeedInit
 *
 * @param[in]   p_ctrl             Pointer to the motor sensor control structure.
 * @param[out]  pp_speed           Address of pointer to store the speed variable address.
 * @param[out]  pp_angle           Address of pointer to store the angle variable address.
 * @param[out]  p_out_extra_data  Address of pointer to store extra output data address.
 *
 * @retval FSP_SUCCESS             Pointers set successfully.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_AngleSpeedInit (motor_sensor_ctrl_t * const          p_ctrl,
                                               float                             ** pp_speed,
                                               float                             ** pp_angle,
                                               motor_sensor_data_exchange_t * const p_out_extra_data)
{
    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl != NULL);
    FSP_ASSERT(pp_speed != NULL);
    FSP_ASSERT(pp_angle != NULL);
    FSP_ASSERT(p_out_extra_data != NULL);
#endif
    const motor_shared_sensor_data_exchange_t * p_extra_data =
        (motor_shared_sensor_data_exchange_t *) p_out_extra_data;
    const motor_shared_inner_to_position_speed_t * p_from_inner =
        (const motor_shared_inner_to_position_speed_t *) p_extra_data->p_in_extra_data;

    /* Set the pointers */
    *pp_speed = &(p_instance_ctrl->signals.speed_el);
    *pp_angle = &(p_instance_ctrl->signals.angle_el);

    /* Set the pointers to the extra data to inner loop */
    *(p_extra_data->pp_out_extra_data) = &(p_instance_ctrl->to_inner);

    /* Initial configuration from inner */
    p_instance_ctrl->signals.inner_control_period = p_from_inner->inner_control_period;
    p_instance_ctrl->signals.outer_control_period = p_from_inner->outer_control_period;
    p_instance_ctrl->p_from_inner                 = p_from_inner;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief Calculates angle and speed based on Hall sensor inputs.
 *
 * This function reads Hall sensor signals, determines rotation direction,
 * calculates speed and angle, and updates the relevant output pointers.
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_AngleSpeedCalc
 *
 * @param[in]  p_ctrl   Pointer to motor angle control structure.
 * @param[in]  p_inner  Pointer to inner loop input data.
 * @param[in]  p_outer  Pointer to outer loop input data.
 *
 * @retval FSP_SUCCESS         Calculation performed successfully.
 * @retval FSP_ERR_ASSERTION   Null pointer or invalid state detected.
 * @retval FSP_ERR_NOT_OPEN    Module is not open.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_AngleSpeedCalc (motor_sensor_ctrl_t * const        p_ctrl,
                                               motor_sensor_input_inner_t * const p_inner,
                                               motor_sensor_input_outer_t * const p_outer)
{
    float temp_angle = 0.0F;

    fsp_err_t err = FSP_SUCCESS;
    motor_sensor_hall_instance_ctrl_t      * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;
    motor_sensor_input_inner_t             * p_inner_data    = p_inner;
    motor_shared_outer_to_position_speed_t * p_outer_data    = (motor_shared_outer_to_position_speed_t *) p_outer;

    (void) p_inner_data;
    (void) p_outer_data;
#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_inner != NULL);
    FSP_ASSERT(p_outer != NULL);
    FSP_ERROR_RETURN(MOTOR_SENSOR_HALL_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    if (FSP_SUCCESS == err)
    {
        motor_sensor_hall_extended_cfg_t * p_extended_cfg =
            (motor_sensor_hall_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

        uint32_t uvw_sum    = 0U;
        uint32_t temp_level = 0U;

        uint8_t i                     = 0U;
        float   est_speed_el_max      = 0.0F;
        float   speed_reversal_factor = 1.0F;
        uint8_t valid_pulse_count     = 0U;
        uint8_t idx;

        /* Position acquisition (hall sensor) */
        p_instance_ctrl->signals.last_hall_signal = p_instance_ctrl->signals.hall_signal;

        temp_level = R_BSP_PinRead(p_extended_cfg->port_hall_sensor_u);
        p_instance_ctrl->signals.hall_signal = (uint8_t) (temp_level << MOTOR_SENSOR_HALL_U_SHIFT);
        temp_level = R_BSP_PinRead(p_extended_cfg->port_hall_sensor_v);
        p_instance_ctrl->signals.hall_signal |= (uint8_t) (temp_level << MOTOR_SENSOR_HALL_V_SHIFT);
        temp_level = R_BSP_PinRead(p_extended_cfg->port_hall_sensor_w);
        p_instance_ctrl->signals.hall_signal |= (uint8_t) (temp_level);

        if (0U == p_instance_ctrl->signals.last_hall_signal)
        {
            return FSP_SUCCESS;
        }

        /* Count time with limitation */
        p_instance_ctrl->signals.carrier_count++;
        if (p_instance_ctrl->signals.carrier_count > p_extended_cfg->maximum_period)
        {
            p_instance_ctrl->signals.carrier_count = p_extended_cfg->maximum_period;
        }

        /* Speed & angle estimation */
        /* At the boundary of hall signal change */
        if (p_instance_ctrl->signals.hall_signal != p_instance_ctrl->signals.last_hall_signal)
        {
            /* Rotation direction judge */
            p_instance_ctrl->signals.last_direction = p_instance_ctrl->signals.direction;

            for (i = 1; i < MOTOR_SENSOR_HALL_SPEED_COUNTS + 1; i++)
            {
                if (p_instance_ctrl->signals.hall_signal == p_extended_cfg->hall_pattern[i])
                {
                    if (p_instance_ctrl->signals.last_hall_signal == p_extended_cfg->hall_pattern[i - 1])
                    {
                        p_instance_ctrl->signals.direction = MOTOR_SENSOR_HALL_DIRECTION_CW;
                    }
                }
            }

            for (i = 0; i < MOTOR_SENSOR_HALL_SPEED_COUNTS; i++)
            {
                if (p_instance_ctrl->signals.hall_signal == p_extended_cfg->hall_pattern[i])
                {
                    if (p_instance_ctrl->signals.last_hall_signal == p_extended_cfg->hall_pattern[i + 1])
                    {
                        p_instance_ctrl->signals.direction = MOTOR_SENSOR_HALL_DIRECTION_CCW;
                    }
                }
            }

            /* Store current period into ring buffer */
            p_instance_ctrl->signals.hall_period[p_instance_ctrl->signals.period_counter] =
                p_instance_ctrl->signals.carrier_count;

            p_instance_ctrl->signals.period_counter++;

            if (p_instance_ctrl->signals.period_counter >= MOTOR_SENSOR_HALL_SPEED_COUNTS)
            {
                p_instance_ctrl->signals.period_counter = 0;
            }

            /* When the change of rotational direction happens */
            if (p_instance_ctrl->signals.last_direction != p_instance_ctrl->signals.direction)
            {
                /* Reset all period buffers to current period */
                p_instance_ctrl->signals.hall_period[0] = p_instance_ctrl->signals.carrier_count;
                p_instance_ctrl->signals.hall_period[1] = 0U;
                p_instance_ctrl->signals.hall_period[2] = 0U;
                p_instance_ctrl->signals.hall_period[3] = 0U;
                p_instance_ctrl->signals.hall_period[4] = 0U;
                p_instance_ctrl->signals.hall_period[5] = 0U;

                /* Reset period counter: next write goes to index 1 */
                p_instance_ctrl->signals.period_counter = 1U;

                /* Reset accumulated valid pulse count to 1 (current pulse only) */
                p_instance_ctrl->signals.hall_signal_count = 1U;

                speed_reversal_factor = 0.0F;
            }
            else
            {
                /* ====== Accumulation of effective pulse count (up to 6) ====== */
                if (p_instance_ctrl->signals.hall_signal_count < MOTOR_SENSOR_HALL_SPEED_COUNTS)
                {
                    p_instance_ctrl->signals.hall_signal_count++;
                }

                speed_reversal_factor = 1.0F;
            }

            /* Obtain the number of active pulses (minimum 1, maximum 6) */
            valid_pulse_count = p_instance_ctrl->signals.hall_signal_count;
            if (valid_pulse_count == 0U)
            {
                valid_pulse_count = 1U;
            }

            /* Calculate the total time of only the active pulses. */
            uvw_sum = 0U;

            /* Sum the most recent valid_pulse_count from the ring buffer. */
            idx = p_instance_ctrl->signals.period_counter;
            for (i = 0U; i < valid_pulse_count; i++)
            {
                if (idx == 0U)
                {
                    idx = MOTOR_SENSOR_HALL_SPEED_COUNTS;
                }

                idx--;
                uvw_sum += (uint32_t) p_instance_ctrl->signals.hall_period[idx];
            }

            /* Avoid zero division */
            if (uvw_sum == 0U)
            {
                uvw_sum = 1U;
            }

            /* Increase direction */
            if (MOTOR_SENSOR_HALL_DIRECTION_CW == p_instance_ctrl->signals.direction)
            {
                p_instance_ctrl->signals.calculated_angle_el = -(MOTOR_SENSOR_HALL_30DEGREE);

                /* Angle increment per count = Angle increment per pulse (number of active pulses) / Total time */
                p_instance_ctrl->signals.calculated_angle_el_per_count =
                    ((MOTOR_FUNDLIB_TWOPI / MOTOR_SENSOR_HALL_HALL_SIGNAL_NUMBER) *
                     (float) valid_pulse_count) / (float) uvw_sum;
            }
            /* Decrease direction */
            else
            {
                p_instance_ctrl->signals.calculated_angle_el           = MOTOR_SENSOR_HALL_30DEGREE;
                p_instance_ctrl->signals.calculated_angle_el_per_count =
                    -((MOTOR_FUNDLIB_TWOPI / MOTOR_SENSOR_HALL_HALL_SIGNAL_NUMBER) *
                      (float) valid_pulse_count) / (float) uvw_sum;
            }

            /* switched denominator and numerator from original */
            p_instance_ctrl->signals.calculated_speed_el_last_pulse =
                (MOTOR_FUNDLIB_TWOPI / MOTOR_SENSOR_HALL_HALL_SIGNAL_NUMBER) *
                speed_reversal_factor /
                (p_instance_ctrl->signals.inner_control_period) /
                (p_instance_ctrl->signals.carrier_count);

            if (MOTOR_SENSOR_HALL_DIRECTION_CCW == p_instance_ctrl->signals.direction)
            {
                p_instance_ctrl->signals.calculated_speed_el_last_pulse =
                    -p_instance_ctrl->signals.calculated_speed_el_last_pulse;
            }

            p_instance_ctrl->signals.calculated_speed_el_mvavg =
                p_instance_ctrl->signals.calculated_angle_el_per_count /
                (p_instance_ctrl->signals.inner_control_period);

            /* Select the speed output */
            switch (p_extended_cfg->speed_select)
            {
                case MOTOR_SENSOR_HALL_SPEED_SELECT_MOVAVG:
                {
                    p_instance_ctrl->signals.calculated_speed_el = p_instance_ctrl->signals.calculated_speed_el_mvavg;
                    break;
                }

                case MOTOR_SENSOR_HALL_SPEED_SELECT_LAST_PULSE:
                {
                    p_instance_ctrl->signals.calculated_speed_el =
                        p_instance_ctrl->signals.calculated_speed_el_last_pulse;
                    break;
                }

                case MOTOR_SENSOR_HALL_SPEED_SELECT_AUTO:
                default:
                {
                    p_instance_ctrl->signals.calculated_speed_el =
                        rm_motor_sensor_hall_speed_mixed_calc((motor_sensor_hall_instance_ctrl_t *) p_ctrl,
                                                              p_instance_ctrl->signals.calculated_speed_el_last_pulse,
                                                              p_instance_ctrl->signals.calculated_speed_el_mvavg);
                    break;
                }
            }

            p_instance_ctrl->signals.carrier_count = 0U;
        }
        /* During the same hall signal is detected */
        else
        {
            p_instance_ctrl->signals.calculated_angle_el = p_instance_ctrl->signals.calculated_angle_el +
                                                           p_instance_ctrl->signals.calculated_angle_el_per_count;
            if (p_instance_ctrl->signals.calculated_angle_el > MOTOR_SENSOR_HALL_30DEGREE)
            {
                p_instance_ctrl->signals.calculated_angle_el = MOTOR_SENSOR_HALL_30DEGREE;
            }
            else if (p_instance_ctrl->signals.calculated_angle_el < -(MOTOR_SENSOR_HALL_30DEGREE))
            {
                p_instance_ctrl->signals.calculated_angle_el = -(MOTOR_SENSOR_HALL_30DEGREE);
            }
            else
            {
                /* Do nothing */
            }
        }

        /* Calculate estimated maximum speed by time elapse after last edge */
        est_speed_el_max = (1.0F + p_extended_cfg->speed_mix_deviation_threshold) *
                           (MOTOR_FUNDLIB_TWOPI / MOTOR_SENSOR_HALL_HALL_SIGNAL_NUMBER) /
                           p_instance_ctrl->signals.carrier_count /
                           (p_instance_ctrl->signals.inner_control_period);

        if (est_speed_el_max >= 1.0F)
        {
            if (p_instance_ctrl->signals.calculated_speed_el > est_speed_el_max)
            {
                p_instance_ctrl->signals.calculated_speed_el = est_speed_el_max;
            }
            else if (p_instance_ctrl->signals.calculated_speed_el < -est_speed_el_max)
            {
                p_instance_ctrl->signals.calculated_speed_el = -est_speed_el_max;
            }
            else
            {
                /*do nothing*/
            }
        }

        /* If the time elapsed reach the maximum, the speed should be assumed as 0 */
        if (p_instance_ctrl->signals.carrier_count == p_extended_cfg->maximum_period)
        {
            p_instance_ctrl->signals.calculated_speed_el = 0.0F;
        }

        /* Set the angle according to hall signal */
        temp_angle = p_extended_cfg->angle_correct + p_instance_ctrl->signals.calculated_angle_el;
        for (i = 0; i < MOTOR_SENSOR_HALL_SPEED_COUNTS; i++)
        {
            if (p_instance_ctrl->signals.hall_signal == p_extended_cfg->hall_pattern[i])
            {
                temp_angle += (MOTOR_FUNDLIB_TWOPI / MOTOR_SENSOR_HALL_SPEED_COUNTS) * i;
            }
        }

        /* Converted angle within 0..2PI */
        if (temp_angle > MOTOR_FUNDLIB_TWOPI)
        {
            temp_angle = temp_angle - MOTOR_FUNDLIB_TWOPI;
        }
        else if (temp_angle < 0.0F)
        {
            temp_angle = temp_angle + MOTOR_FUNDLIB_TWOPI;
        }
        else
        {
            /* Do nothing */
        }

        /* Position acquisition (hall sensor) */
        p_instance_ctrl->signals.last_hall_signal = p_instance_ctrl->signals.hall_signal;
        p_instance_ctrl->signals.speed_el         = p_instance_ctrl->signals.calculated_speed_el;
        p_instance_ctrl->signals.angle_el         = temp_angle;
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief Get mechanical position and speed from Hall sensor measurements.
 *
 * This function retrieves the current mechanical rotational position and speed from the Hall sensor controller.
 * The speed output is normalized to mechanical units [rad/s mech] by dividing the electrical speed by the
 * number of pole pairs. The position output is currently set to zero and must be implemented.
 *
 * Example:
 * @snippet rm_motor_sensor_hall_example.c RM_MOTOR_SENSOR_HALL_PositionSpeedGet
 *
 * @param[in]  p_ctrl   Pointer to the Hall sensor instance control structure.
 * @param[out] p_pos    Pointer to store the resulting mechanical position [rad mech].
 * @param[out] p_speed  Pointer to store the resulting mechanical speed [rad/s mech].
 *
 * @retval  FSP_SUCCESS Always returns success.
 **********************************************************************************************************************/
fsp_err_t RM_MOTOR_SENSOR_HALL_PositionSpeedGet (motor_sensor_ctrl_t * const p_ctrl,
                                                 float * const               p_pos,
                                                 float * const               p_speed)
{
    fsp_err_t err = FSP_SUCCESS;

    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;

#if (RM_MOTOR_SENSOR_HALL_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl != NULL);
    FSP_ASSERT(p_pos != NULL);
    FSP_ASSERT(p_speed != NULL);
#endif

    motor_parameter_ramp_t * p_motor_params = p_instance_ctrl->p_from_inner->p_motor_params;

    *p_speed = p_instance_ctrl->signals.speed_el / p_motor_params->u2_mtr_pp; // [rad/s mech]

    *p_pos = 0.0F;                                                            // Mechanical angle  [rad mech]

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup MOTOR_SENSOR_HALL)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Clamp the input value to the range [0.0, 1.0].
 *
 * @param[in]  f4_input        Input value to clamp.
 *
 * @retval     Clamped value within [0.0, 1.0].
 **********************************************************************************************************************/
static float rm_motor_sensor_hall_clamp01 (float f4_input)
{
    if (f4_input < 0.0F)
    {
        return 0.0F;
    }

    if (f4_input > 1.0F)
    {
        return 1.0F;
    }

    return f4_input;
}

/*******************************************************************************************************************//**
 * @brief Calculates a weighted speed value based on fast and precision speed estimates.
 *
 * This function mixes a fast speed estimate with a precision speed estimate using a dynamically
 * calculated weight. The weight is determined by the absolute speed and the deviation between
 * the precision and fast speed estimates, with thresholds and clamping applied for stability.
 *
 * @param[in]  p_ctrl             Pointer to the motor angle control structure.
 * @param[in]  f4_speed_fast      Fast speed estimate [rad/s el].
 * @param[in]  f4_speed_precision Precision speed estimate [rad/s el].
 *
 * @retval Weighted speed value (rad/s).
 **********************************************************************************************************************/
static float rm_motor_sensor_hall_speed_mixed_calc (motor_sensor_ctrl_t * const p_ctrl,
                                                    float                       f4_speed_fast,
                                                    float                       f4_speed_precision)
{
    float f4_speed_ret = 0.0F;
    float f4_1_over_speed_fast;
    float f4_speed_ratio;
    float f4_speed_dev_ratio;
    float f4_weight_fast;

    motor_sensor_hall_instance_ctrl_t * p_instance_ctrl = (motor_sensor_hall_instance_ctrl_t *) p_ctrl;
    motor_sensor_hall_extended_cfg_t  * p_extended_cfg  =
        (motor_sensor_hall_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Add 0.01 to the denominator, to avoid division by zero */
    f4_1_over_speed_fast = 1.0F / (fabsf(f4_speed_fast) + MOTOR_SENSOR_HALL_AVOID_ZERO_DIV);

    f4_speed_ratio     = p_extended_cfg->speed_mix_switch_threshold * f4_1_over_speed_fast;
    f4_speed_dev_ratio = fabsf(f4_speed_precision - f4_speed_fast) * f4_1_over_speed_fast;

    /* Calculate the weight of fast speed
     * weight_fast(absolute speed term)  = speed_ratio^4
     * weight_fast(speed deviation term) = speed_dev_ratio - threshold, clamped to range 0 ~ 1 */
    f4_weight_fast = f4_speed_ratio * f4_speed_ratio;
    f4_weight_fast = f4_weight_fast * f4_weight_fast;

    f4_weight_fast +=
        rm_motor_sensor_hall_clamp01((f4_speed_dev_ratio - p_extended_cfg->speed_mix_deviation_threshold));

    /* Clamp the weight of low latency estimation to range 0 ~ 1 */
    f4_weight_fast = rm_motor_sensor_hall_clamp01(f4_weight_fast);

    /* Return the weighted speed, and save the weight for monitoring */
    f4_speed_ret = f4_speed_fast * f4_weight_fast + f4_speed_precision * (1.0F - f4_weight_fast);
    p_instance_ctrl->signals.weight = f4_weight_fast;

    return f4_speed_ret;
}
