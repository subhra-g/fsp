/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <math.h>

#include <stdint.h>
#include "rm_motor_tuner_pm_rdiff.h"
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE    (103)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void rdiff_seq_init(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_ready1(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_ready12(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_measure1(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_ready2(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_ready22(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_measure2(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_check(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);
static void rdiff_seq_reset(motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/******************************************************************************
 * Function Name : tuner_pm_rdiff_act
 * Description   :
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 ******************************************************************************/
uint16_t tuner_pm_rdiff_act (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    uint16_t ret = 0;
    switch (p_rdiff->rdiff_status)
    {
        case TUNER_PM_SEQ_R_DIFF_INIT:
        {
            rdiff_seq_init(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_READY1:
        {
            rdiff_seq_ready1(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_READY12:
        {
            rdiff_seq_ready12(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_MEASURE1:
        {
            rdiff_seq_measure1(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_READY2:
        {
            rdiff_seq_ready2(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_READY22:
        {
            rdiff_seq_ready22(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_MEASURE2:
        {
            rdiff_seq_measure2(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_CHECK:
        {
            rdiff_seq_check(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_RESET:
        {
            rdiff_seq_reset(p_rdiff, p_foc);
            break;
        }

        case TUNER_PM_SEQ_R_DIFF_COMPLETED:
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

/***********************************************************************************************************************
 * Function Name: tuner_pm_rdiff_reset
 * Description  : Throw an error with the given error code and stop PWM output
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
void tuner_pm_rdiff_reset (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_INIT;

    /* RL measurement */
    p_rdiff->target_current_a_min = 0.0F;
    p_rdiff->target_current_a_max = 0.0F;
    p_rdiff->target_current_b_min = 0.0F;
    p_rdiff->target_current_b_max = 0.0F;
    p_rdiff->vd_sample1           = 0.0F;
    p_rdiff->vd_sample2           = 0.0F;
    p_rdiff->id_sample1           = 0.0F;
    p_rdiff->id_sample2           = 0.0F;
    p_rdiff->sum_vu               = 0.0F;
    p_rdiff->sum_iu               = 0.0F;
    p_rdiff->cnt_stab             = 0;
    p_rdiff->timeout_cnt          = 0;
    p_rdiff->r_diff               = 0.0F;
    p_rdiff->volterr_est          = 0.0F;
}

/******************************************************************************
 * Function Name : rdiff_seq_init
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_init (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    float target_current_margin = p_rdiff->p_cfg->target_current_margin * p_foc->rated_current;
    p_rdiff->target_current_a_min = p_foc->rated_current * p_rdiff->p_cfg->target_current_a;
    p_rdiff->target_current_b_min = p_foc->rated_current * p_rdiff->p_cfg->target_current_b;
    p_rdiff->target_current_a_max = p_rdiff->target_current_a_min + target_current_margin;
    p_rdiff->target_current_b_max = p_rdiff->target_current_b_min + target_current_margin;

    /* Make sure that the angle do not change during the measurement */
    p_foc->angle_rad     = 0.0F;
    p_foc->ref_speed_rad = 0.0F;

    p_rdiff->v_step         = p_rdiff->p_cfg->vd_step_lsb * p_foc->vmag_max * p_foc->pwm_duty_lsb;
    p_foc->vd_ref           = 0.0F;
    p_foc->vq_ref           = 0.0F;
    p_rdiff->sample_cnt     = 0;
    p_rdiff->rdiff_status   = TUNER_PM_SEQ_R_DIFF_READY1;
    p_foc->rotor_angle_mode = MOTOR_TUNER_PM_ROTOR_ANGLE_MODE_OPENLOOP;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_0);
}

/******************************************************************************
 * Function Name : rdiff_seq_ready1
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_ready1 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;

    /* Note: Code in these blocks are executed only once per vd_step_wait_ms cycle */
    if (1 == p_rdiff->sample_cnt)
    {
        /* Adjust voltage to fix target current every p_rdiff->p_cfg->vd_step_wait_ms sample cycles */
        if ((p_foc->id_ad < p_rdiff->target_current_a_min) &&
            (p_rdiff->timeout_cnt <= p_rdiff->p_cfg->vd_adjust_timeout))
        {
            p_foc->vd_ref    += p_rdiff->v_step;
            p_rdiff->cnt_stab = 0;
        }
        else if (p_foc->id_ad > p_rdiff->target_current_a_max)
        {
            p_foc->vd_ref    -= p_rdiff->v_step;
            p_rdiff->cnt_stab = 0;
            p_rdiff->timeout_cnt++;
        }
        else
        {
            p_rdiff->cnt_stab++;
        }
    }

    /* Wait for p_rdiff->p_cfg->vd_step_wait_ms [ms] */
    else if (p_rdiff->sample_cnt >
             (uint32_t) (p_rdiff->p_cfg->vd_step_wait_ms * TUNER_PM_MS_TO_SECOND * p_foc->ctrl_freq_hz))
    {
        p_rdiff->sample_cnt = 0;

        /* Wait for p_rdiff->p_cfg->stab_wait */
        if (p_rdiff->cnt_stab > (uint32_t) (p_rdiff->p_cfg->stab_wait))
        {
            p_rdiff->cnt_stab     = 0;
            p_rdiff->timeout_cnt  = 0;
            p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_READY12;
        }
    }
    else
    {
        /* Do nothing */
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_ready12
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_ready12 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;

    /* Wait for p_rdiff->p_cfg->measure_wait_ms [ms] */
    if (p_rdiff->sample_cnt >
        (uint32_t) (p_rdiff->p_cfg->measure_wait_ms * p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND))
    {
        p_rdiff->sample_cnt   = 0;
        p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_MEASURE1;
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_measure1
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_measure1 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;
    p_rdiff->vd_sample1 += p_foc->vd_ref;
    p_rdiff->id_sample1 += p_foc->id_ad;

    /* Wait for p_rdiff->p_cfg->measure_time_ms [ms] */
    if (p_rdiff->sample_cnt >=
        (uint32_t) (p_rdiff->p_cfg->measure_time_ms * p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND))
    {
        p_rdiff->vd_sample1   = p_rdiff->vd_sample1 / (float) p_rdiff->sample_cnt;
        p_rdiff->id_sample1   = p_rdiff->id_sample1 / (float) p_rdiff->sample_cnt;
        p_rdiff->sample_cnt   = 0;
        p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_READY2;
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_ready2
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_ready2 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;
    if (1 == p_rdiff->sample_cnt)
    {
        if ((p_foc->id_ad < p_rdiff->target_current_b_min) &&
            (p_rdiff->timeout_cnt <= p_rdiff->p_cfg->vd_adjust_timeout))
        {
            p_foc->vd_ref    += p_rdiff->v_step;
            p_rdiff->cnt_stab = 0;
        }
        else if (p_foc->id_ad > p_rdiff->target_current_b_max)
        {
            p_foc->vd_ref    -= p_rdiff->v_step;
            p_rdiff->cnt_stab = 0;
            p_rdiff->timeout_cnt++;
        }
        else
        {
            p_rdiff->cnt_stab++;
        }
    }

    /* Wait for p_rdiff->p_cfg->vd_step_wait_ms [ms] */
    else if (p_rdiff->sample_cnt >
             (uint32_t) (p_rdiff->p_cfg->vd_step_wait_ms * TUNER_PM_MS_TO_SECOND * p_foc->ctrl_freq_hz))
    {
        p_rdiff->sample_cnt = 0;

        /* Wait for p_rdiff->p_cfg->stab_wait */
        if (p_rdiff->cnt_stab > (uint32_t) (p_rdiff->p_cfg->stab_wait))
        {
            p_rdiff->cnt_stab     = 0;
            p_rdiff->timeout_cnt  = 0;
            p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_READY22;
        }
    }
    else
    {
        /* Do nothing */
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_ready22
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_ready22 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;

    /* Wait for p_rdiff->p_cfg->measure_wait_ms [ms] */
    if (p_rdiff->sample_cnt >
        (uint32_t) (p_rdiff->p_cfg->measure_wait_ms * p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND))
    {
        p_rdiff->sample_cnt   = 0;
        p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_MEASURE2;
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_measure2
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_measure2 (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_rdiff->sample_cnt++;
    p_rdiff->vd_sample2 += p_foc->vd_ref;
    p_rdiff->id_sample2 += p_foc->id_ad;

    /* Wait for p_rdiff->p_cfg->measure_time_ms [ms] */
    if (p_rdiff->sample_cnt >=
        (uint32_t) (p_rdiff->p_cfg->measure_time_ms * p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND))
    {
        p_rdiff->vd_sample2 = p_rdiff->vd_sample2 / (float) p_rdiff->sample_cnt;
        p_rdiff->id_sample2 = p_rdiff->id_sample2 / (float) p_rdiff->sample_cnt;
        p_rdiff->r_diff     = (p_rdiff->vd_sample2 - p_rdiff->vd_sample1) /
                              (p_rdiff->id_sample2 - p_rdiff->id_sample1);
        p_rdiff->volterr_est  = p_rdiff->vd_sample2 - (p_rdiff->r_diff * p_rdiff->id_sample2);
        p_rdiff->sample_cnt   = 0;
        p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_CHECK;
    }
}

/******************************************************************************
 * Function Name : rdiff_seq_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_check (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    if (p_rdiff->r_diff > p_foc->r_max)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_R_DIFF);
    }

    if (p_rdiff->r_diff <= p_foc->r_min)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_R_DIFF);
    }

    p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_RESET;
}

/******************************************************************************
 * Function Name : rdiff_seq_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void rdiff_seq_reset (motor_tuner_pm_rdiff_t * p_rdiff, motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->vd_ref = 0.0F;
    p_rdiff->sample_cnt++;

    /* Wait for p_rdiff->p_cfg->reset_time_ms [ms] */
    if (p_rdiff->sample_cnt > (uint32_t) (p_rdiff->p_cfg->reset_time_ms * p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND))
    {
        p_rdiff->sample_cnt   = 0;
        p_rdiff->rdiff_status = TUNER_PM_SEQ_R_DIFF_COMPLETED;
    }
}
