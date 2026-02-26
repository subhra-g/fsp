/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <math.h>
#include "rm_motor_tuner_pm_ldq.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE                       (104)
#endif
#define TUNER_PM_PRV_LDQ_CTRL_LEVEL                   (TUNER_PM_CTRL_LEVEL_0)
#define TUNER_PM_PRV_OFFSET_ADJUST_START_TIME_COEF    (0.5F)   ///< Start time for offset adjustment is half of stabilization wait time
#define TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF       (2.0F)   ///< Waiting for both DC and AC for one cycle of stabilization wait time
#define TUNER_PM_PRV_CURRENT_STEP_COEF                (0.005F) ///< Coefficient for current step calculation during Rld DFT
#define TUNER_PM_PRV_ID_MIN_MARGIN_COEF               (0.9F)   ///< Margin coefficient for minimum Id during Lq identification
#define TUNER_PM_PRV_INITIAL_CURRENT_TARGET_COEF      (0.5F)   ///< Initial current target coefficient during identification

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_init(motor_tuner_pm_ldq_t         * p_ldq,
                                 motor_tuner_pm_core_foc_t    * p_foc,
                                 motor_tuner_pm_signal_conf_t * st_signal_conf);
static void ldq_seq_rld_rls_ready(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_rls_measure(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_rls_check(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_rls_reset(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_dft_init(motor_tuner_pm_ldq_t         * p_ldq,
                                 motor_tuner_pm_core_foc_t    * p_foc,
                                 motor_tuner_pm_signal_conf_t * st_signal_conf);
static void ldq_seq_rld_dft_ready(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_dft_measure(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_dft_check(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_rld_dft_reset(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_rls_init(motor_tuner_pm_ldq_t         * p_ldq,
                                motor_tuner_pm_core_foc_t    * p_foc,
                                motor_tuner_pm_signal_conf_t * st_signal_conf);
static void ldq_seq_lq_rls_ready(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_rls_measure(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_rls_check(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_rls_reset(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_dft_init(motor_tuner_pm_ldq_t         * p_ldq,
                                motor_tuner_pm_core_foc_t    * p_foc,
                                motor_tuner_pm_signal_conf_t * st_signal_conf);
static void ldq_seq_lq_dft_ready(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_dft_measure(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_dft_check(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);
static void ldq_seq_lq_dft_reset(motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc);

/***********************************************************************************************************************
 * Function Name : tuner_pm_rld_dft_act
 * Description   :
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 **********************************************************************************************************************/
uint16_t tuner_pm_rld_dft_act (motor_tuner_pm_ldq_t         * p_ldq,
                               motor_tuner_pm_core_foc_t    * p_foc,
                               motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    uint16_t ret = 0;

    switch (p_ldq->lddft_status)
    {
        case TUNER_PM_SEQ_RLD_DFT_INIT:
        {
            ldq_seq_rld_dft_init(p_ldq, p_foc, st_signal_conf);
            break;
        }

        case TUNER_PM_SEQ_RLD_DFT_READY:
        {
            ldq_seq_rld_dft_ready(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_DFT_MEASURE:
        {
            ldq_seq_rld_dft_measure(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_DFT_CHECK:
        {
            ldq_seq_rld_dft_check(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_DFT_RESET:
        {
            ldq_seq_rld_dft_reset(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_DFT_COMPLETED:
        {
            ret = 1;                   /* Inform that the identification is completed */
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
 * Function Name : tuner_pm_rld_rls_act
 * Description   :
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 **********************************************************************************************************************/
uint16_t tuner_pm_rld_rls_act (motor_tuner_pm_ldq_t         * p_ldq,
                               motor_tuner_pm_core_foc_t    * p_foc,
                               motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    uint16_t ret = 0;

    switch (p_ldq->ldrls_status)
    {
        case TUNER_PM_SEQ_RLD_RLS_INIT:
        {
            ldq_seq_rld_rls_init(p_ldq, p_foc, st_signal_conf);
            break;
        }

        case TUNER_PM_SEQ_RLD_RLS_READY:
        {
            ldq_seq_rld_rls_ready(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_RLS_MEASURE:
        {
            ldq_seq_rld_rls_measure(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_RLS_CHECK:
        {
            ldq_seq_rld_rls_check(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_RLS_RESET:
        {
            ldq_seq_rld_rls_reset(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLD_RLS_COMPLETED:
        {
            ret = 1;                   /* Inform that the identification is completed */
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
 * Function Name : tuner_pm_lq_dft_act
 * Description   :
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 **********************************************************************************************************************/
uint16_t tuner_pm_lq_dft_act (motor_tuner_pm_ldq_t         * p_ldq,
                              motor_tuner_pm_core_foc_t    * p_foc,
                              motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    uint16_t ret = 0;

    switch (p_ldq->lqdft_status)
    {
        case TUNER_PM_SEQ_RLQ_DFT_INIT:
        {
            ldq_seq_lq_dft_init(p_ldq, p_foc, st_signal_conf);
            break;
        }

        case TUNER_PM_SEQ_RLQ_DFT_READY:
        {
            ldq_seq_lq_dft_ready(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_DFT_MEASURE:
        {
            ldq_seq_lq_dft_measure(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_DFT_CHECK:
        {
            ldq_seq_lq_dft_check(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_DFT_RESET:
        {
            ldq_seq_lq_dft_reset(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_DFT_COMPLETED:
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
 * Function Name : tuner_pm_lq_rls_act
 * Description   :
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 **********************************************************************************************************************/
uint16_t tuner_pm_lq_rls_act (motor_tuner_pm_ldq_t         * p_ldq,
                              motor_tuner_pm_core_foc_t    * p_foc,
                              motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    uint16_t ret = 0;

    switch (p_ldq->lqrls_status)
    {
        case TUNER_PM_SEQ_RLQ_RLS_INIT:
        {
            ldq_seq_lq_rls_init(p_ldq, p_foc, st_signal_conf);
            break;
        }

        case TUNER_PM_SEQ_RLQ_RLS_READY:
        {
            ldq_seq_lq_rls_ready(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_RLS_MEASURE:
        {
            ldq_seq_lq_rls_measure(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_RLS_CHECK:
        {
            ldq_seq_lq_rls_check(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_RLS_RESET:
        {
            ldq_seq_lq_rls_reset(p_ldq, p_foc);
            break;
        }

        case TUNER_PM_SEQ_RLQ_RLS_COMPLETED:
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
 * Function Name: tuner_pm_ldq_reset
 * Description  : Initialize inductance identification
 * Arguments    : None
 * Return Value : None
 **********************************************************************************************************************/
void tuner_pm_ldq_reset (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_ldq->ldrls_status = TUNER_PM_SEQ_RLD_RLS_INIT;
    p_ldq->lddft_status = TUNER_PM_SEQ_RLD_DFT_INIT;
    p_ldq->lqrls_status = TUNER_PM_SEQ_RLQ_RLS_INIT;
    p_ldq->lqdft_status = TUNER_PM_SEQ_RLQ_DFT_INIT;

    p_ldq->vd_ref_amp      = 0.0F;
    p_ldq->vq_ref_amp      = 0.0F;
    p_ldq->vd_ref_offset   = 0.0F;
    p_ldq->dft_real        = 0.0F;
    p_ldq->dft_imag        = 0.0F;
    p_ldq->dft_amp         = 0.0F;
    p_ldq->dft_amp2        = 0.0F;
    p_ldq->current_pre     = 0.0F;
    p_ldq->voltage_pre     = 0.0F;
    p_ldq->id_offset       = 0.0F;
    p_ldq->id_sum          = 0.0F;
    p_ldq->id_sum_cnt      = 0.0F;
    p_ldq->a_est           = 0.0F;
    p_ldq->b_est           = 0.0F;
    p_ldq->angle_pre       = 0.0F;
    p_ldq->stab_wait_ms    = 0;
    p_ldq->time_elapsed_ms = 0.0F;

    p_ldq->lddft_v      = 0.0F;
    p_ldq->lddft_i_mag  = 0.0F;
    p_ldq->lddft_i_img  = 0.0F;
    p_ldq->lddft_i_real = 0.0F;
    p_ldq->lqdft_v      = 0.0F;
    p_ldq->lqdft_i_mag  = 0.0F;
    p_ldq->lqdft_i_img  = 0.0F;
    p_ldq->lqdft_i_real = 0.0F;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_rls_init
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_init (motor_tuner_pm_ldq_t         * p_ldq,
                                  motor_tuner_pm_core_foc_t    * p_foc,
                                  motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    if (TUNER_PM_SIGNAL_CONF_DEFAULT == st_signal_conf)
    {
        p_ldq->ldq_freq_ref_hz = p_ldq->p_cfg->rld_freq;

        p_ldq->vd_ref_offset = (p_foc->r * (p_foc->rated_current * p_ldq->p_cfg->rld_vd_offset_coef)) + p_foc->v_err;
        p_ldq->vd_ref_amp    = p_foc->r * p_foc->rated_current * p_ldq->p_cfg->rld_vd_amp_coef;
    }
    else
    {
        p_ldq->ldq_freq_ref_hz = st_signal_conf->signal_freg_hz;
        p_ldq->vd_ref_offset   = st_signal_conf->signal_offset;
        p_ldq->vd_ref_amp      = st_signal_conf->signal_amp;
    }

    rm_motor_tuner_sinref_init(&p_foc->sinref,
                               p_ldq->ldq_freq_ref_hz,
                               p_ldq->vd_ref_amp,
                               p_ldq->vd_ref_offset,
                               p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_tuner_rls_init(&p_foc->rls, p_foc->p_cfg->default_rls_init, p_foc->p_cfg->default_rls_forget_k);

    p_ldq->stab_wait_ms =
        (uint16_t) ((p_ldq->p_cfg->stab_time_coef * (p_ldq->p_cfg->ldq_init_assumption / p_foc->r)) *
                    TUNER_PM_SECOND_TO_MS);
    p_ldq->ldrls_status = TUNER_PM_SEQ_RLD_RLS_READY;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_PRV_LDQ_CTRL_LEVEL);
    p_ldq->time_elapsed_ms = 0.0F;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_rls_ready
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_ready (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    p_foc->vd_ref = p_ldq->vd_ref_offset;

    if ((p_ldq->time_elapsed_ms > p_ldq->stab_wait_ms) &&
        (p_ldq->time_elapsed_ms <= (p_ldq->stab_wait_ms + p_ldq->p_cfg->rld_rls_measure_offset_time)))
    {
        if (p_foc->id_ad >=
            (TUNER_PM_PRV_ID_MIN_MARGIN_COEF * (p_foc->rated_current * p_ldq->p_cfg->rld_vd_offset_coef)))
        {
            p_ldq->id_sum     += p_foc->id_ad;
            p_ldq->id_sum_cnt += 1.0F;
        }
        else
        {
            p_foc->v_err         = p_foc->vd_ref - (p_foc->id_ad * p_foc->r);
            p_ldq->vd_ref_offset = (p_foc->r * (p_foc->rated_current * p_ldq->p_cfg->rld_vd_offset_coef)) +
                                   p_foc->v_err;

            rm_motor_tuner_sinref_init(&p_foc->sinref,
                                       p_ldq->ldq_freq_ref_hz,
                                       p_ldq->vd_ref_amp,
                                       p_ldq->vd_ref_offset,
                                       p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);

            p_foc->vd_ref          = p_ldq->vd_ref_offset;
            p_ldq->time_elapsed_ms = 0.0F;
            p_ldq->id_sum          = 0.0F;
            p_ldq->id_sum_cnt      = 0.0F;
        }
    }
    else if ((p_ldq->time_elapsed_ms > (p_ldq->stab_wait_ms + p_ldq->p_cfg->rld_rls_measure_offset_time)) &&
             (p_ldq->time_elapsed_ms <=
              ((TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF * p_ldq->stab_wait_ms) +
               p_ldq->p_cfg->rld_rls_measure_offset_time)))
    {
        p_foc->vd_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);
    }
    else if (p_ldq->time_elapsed_ms >
             ((TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF * p_ldq->stab_wait_ms) +
              p_ldq->p_cfg->rld_rls_measure_offset_time))
    {
        p_ldq->id_offset       = p_ldq->id_sum / p_ldq->id_sum_cnt;
        p_ldq->id_sum          = 0.0F;
        p_ldq->id_sum_cnt      = 0.0F;
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->ldrls_status    = TUNER_PM_SEQ_RLD_RLS_MEASURE;
    }
    else
    {
        /* Do nothing */
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_rls_measure
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_measure (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    float input;
    float measured_output;

    p_foc->sum_cnt++;

    input           = p_foc->vd_ref - p_ldq->vd_ref_offset;
    measured_output = p_foc->id_ad - p_ldq->id_offset;

    rm_motor_tuner_rls_exec(&p_foc->rls, input, measured_output, &p_ldq->a_est, &p_ldq->b_est);

    p_foc->vd_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);

    if (p_foc->sum_cnt >= ((p_foc->ctrl_freq_hz / p_ldq->ldq_freq_ref_hz) * p_ldq->p_cfg->rld_rls_measure_num))
    {
        p_ldq->r_rls  = (1 + p_ldq->a_est) / p_ldq->b_est;
        p_ldq->ld_rls = (-(p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_ldq->a_est)) / p_ldq->b_est;

        p_foc->sum_cnt      = 0;
        p_ldq->ldrls_status = TUNER_PM_SEQ_RLD_RLS_CHECK;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_rls_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_check (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    /* Only check inductance, do not check R for RLS, since the result are not actually referenced */
    if (p_ldq->ld_rls <= p_foc->ld_min)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_LD_RLS);
    }

    p_ldq->ldrls_status = TUNER_PM_SEQ_RLD_RLS_RESET;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_rls_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_rls_reset (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    if (p_ldq->time_elapsed_ms > p_ldq->p_cfg->reset_time_ms)
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->ldrls_status    = TUNER_PM_SEQ_RLD_RLS_COMPLETED;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_dft_init
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_dft_init (motor_tuner_pm_ldq_t         * p_ldq,
                                  motor_tuner_pm_core_foc_t    * p_foc,
                                  motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    if (TUNER_PM_SIGNAL_CONF_DEFAULT == st_signal_conf)
    {
        p_ldq->ldq_freq_ref_hz = p_ldq->p_cfg->rld_freq;

        p_ldq->vd_ref_offset = (p_foc->r * p_foc->rated_current * p_ldq->p_cfg->rld_vd_offset_coef) + p_foc->v_err;
        p_ldq->vd_ref_amp    = p_foc->r * p_foc->rated_current * p_ldq->p_cfg->rld_vd_amp_coef;
    }
    else
    {
        p_ldq->ldq_freq_ref_hz = st_signal_conf->signal_freg_hz;
        p_ldq->vd_ref_offset   = st_signal_conf->signal_offset;
        p_ldq->vd_ref_amp      = st_signal_conf->signal_amp;
    }

    rm_motor_tuner_sinref_init(&p_foc->sinref,
                               p_ldq->ldq_freq_ref_hz,
                               p_ldq->vd_ref_amp,
                               p_ldq->vd_ref_offset,
                               p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_tuner_dft_init(&p_foc->dft);

    p_ldq->stab_wait_ms    = (uint16_t) ((p_foc->ld * TUNER_PM_SECOND_TO_MS * p_ldq->p_cfg->stab_time_coef) / p_foc->r);
    p_ldq->time_elapsed_ms = 0.0F;
    p_ldq->lddft_status    = TUNER_PM_SEQ_RLD_DFT_READY;

    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_PRV_LDQ_CTRL_LEVEL);
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_dft_ready
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_dft_ready (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_ldq);

    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    p_foc->vd_ref = p_foc->rated_current * TUNER_PM_PRV_INITIAL_CURRENT_TARGET_COEF * p_foc->r_dc;

    if ((p_ldq->time_elapsed_ms > (p_ldq->stab_wait_ms * TUNER_PM_PRV_OFFSET_ADJUST_START_TIME_COEF)) &&
        (p_ldq->time_elapsed_ms <= p_ldq->stab_wait_ms))
    {
        p_foc->vd_ref -= (p_foc->rated_current * TUNER_PM_PRV_CURRENT_STEP_COEF * p_foc->r_dc);
        if (p_foc->vd_ref < 0.0F)
        {
            p_foc->vd_ref = 0.0F;
        }
    }
    else if ((p_ldq->time_elapsed_ms > p_ldq->stab_wait_ms) &&
             (p_ldq->time_elapsed_ms <= (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF)))
    {
        p_foc->vd_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);
    }
    else if (p_ldq->time_elapsed_ms > (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF))
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lddft_status    = TUNER_PM_SEQ_RLD_DFT_MEASURE;
    }
    else
    {
        /* Do nothing */
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_dft_measure
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_dft_measure (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->sum_cnt++;

    p_ldq->angle_pre = rm_motor_tuner_sinref_get_angle(&p_foc->sinref);
    p_foc->vd_ref    = rm_motor_tuner_sinref_generate(&p_foc->sinref);

    rm_motor_tuner_dft_sum(&p_foc->dft, p_ldq->angle_pre, p_foc->id_ad);

    if (p_foc->sum_cnt >= ((p_foc->ctrl_freq_hz / p_ldq->ldq_freq_ref_hz) * p_ldq->p_cfg->rld_dft_measure_num))
    {
        rm_motor_tuner_dft_result(&p_foc->dft, &p_ldq->dft_real, &p_ldq->dft_imag);

        p_ldq->dft_amp2 = (p_ldq->dft_real * p_ldq->dft_real) + (p_ldq->dft_imag * p_ldq->dft_imag);

        p_ldq->ld_dft = ((p_ldq->vd_ref_amp * p_ldq->dft_imag) / p_ldq->dft_amp2) /
                        (p_ldq->ldq_freq_ref_hz * TUNER_PM_TWOPI);
        p_ldq->r_dft = (p_ldq->vd_ref_amp * p_ldq->dft_real) / p_ldq->dft_amp2;

        p_foc->sum_cnt      = 0;
        p_ldq->lddft_status = TUNER_PM_SEQ_RLD_DFT_CHECK;

        p_ldq->lddft_v      = p_ldq->vd_ref_amp;
        p_ldq->lddft_i_mag  = sqrtf(p_ldq->dft_amp2);
        p_ldq->lddft_i_img  = p_ldq->dft_imag;
        p_ldq->lddft_i_real = p_ldq->dft_real;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_dft_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_dft_check (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    if (p_ldq->ld_dft <= p_foc->ld_min)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_LD_DFT);
    }

    p_ldq->lddft_status = TUNER_PM_SEQ_RLD_DFT_RESET;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_rld_dft_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_rld_dft_reset (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    if (p_ldq->time_elapsed_ms > p_ldq->p_cfg->reset_time_ms)
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lddft_status    = TUNER_PM_SEQ_RLD_DFT_COMPLETED;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_rls_init
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_rls_init (motor_tuner_pm_ldq_t         * p_ldq,
                                 motor_tuner_pm_core_foc_t    * p_foc,
                                 motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    float temp;
    float inpedence;

    if (TUNER_PM_SIGNAL_CONF_DEFAULT == st_signal_conf)
    {
        p_ldq->ldq_freq_ref_hz = p_ldq->p_cfg->lq_freq;

        p_ldq->vd_ref_offset = (p_foc->r * p_foc->rated_current * p_ldq->p_cfg->lq_vd_offset_coef) + p_foc->v_err;

        temp              = p_ldq->ldq_freq_ref_hz * p_foc->ld * TUNER_PM_TWOPI;
        inpedence         = sqrtf((p_foc->r * p_foc->r) + (temp * temp));
        p_ldq->vq_ref_amp = inpedence * p_foc->rated_current * p_ldq->p_cfg->lq_vq_amp_coef;
    }
    else
    {
        p_ldq->ldq_freq_ref_hz = st_signal_conf->signal_freg_hz;
        p_ldq->vd_ref_offset   = st_signal_conf->signal_offset;
        p_ldq->vd_ref_amp      = st_signal_conf->signal_amp;
    }

    p_ldq->stab_wait_ms = (uint16_t) ((p_foc->ld * TUNER_PM_SECOND_TO_MS * p_ldq->p_cfg->stab_time_coef) / p_foc->r);
    rm_motor_tuner_sinref_init(&p_foc->sinref,
                               p_ldq->ldq_freq_ref_hz,
                               p_ldq->vq_ref_amp,
                               0,
                               p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_tuner_rls_init(&p_foc->rls, p_foc->p_cfg->default_rls_init, p_foc->p_cfg->default_rls_forget_k);

    p_ldq->time_elapsed_ms = 0.0F;
    p_ldq->lqrls_status    = TUNER_PM_SEQ_RLQ_RLS_READY;
    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_PRV_LDQ_CTRL_LEVEL);
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_rls_ready
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_rls_ready (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    p_foc->vd_ref = p_ldq->vd_ref_offset;

    if ((p_ldq->time_elapsed_ms > p_ldq->stab_wait_ms) &&
        (p_ldq->time_elapsed_ms <= (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF)))
    {
        p_foc->vq_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);
    }
    else if (p_ldq->time_elapsed_ms > (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF))
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lqrls_status    = TUNER_PM_SEQ_RLQ_RLS_MEASURE;
    }
    else
    {
        /* Do nothing */
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_rls_measure
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_rls_measure (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    float input;
    float measured_output;

    p_foc->sum_cnt++;

    input           = p_foc->vq_ref;
    measured_output = p_foc->iq_ad;

    rm_motor_tuner_rls_exec(&p_foc->rls, input, measured_output, &p_ldq->a_est, &p_ldq->b_est);

    p_foc->vq_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);

    if (p_foc->sum_cnt >= ((p_foc->ctrl_freq_hz * p_ldq->p_cfg->lq_rls_measure_num) / p_ldq->ldq_freq_ref_hz))
    {
        p_ldq->lq_rls = (-(p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND * p_ldq->a_est)) / p_ldq->b_est;

        p_foc->sum_cnt      = 0;
        p_foc->vq_ref       = 0.0F;
        p_ldq->lqrls_status = TUNER_PM_SEQ_RLQ_RLS_CHECK;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_rls_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_rls_check (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    if (p_ldq->lq_rls <= p_foc->lq_min)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_LQ_RLS);
    }

    if (p_foc->ld > p_ldq->lq_rls)
    {
        p_foc->lq = p_foc->ld;
    }
    else
    {
        p_foc->lq = p_ldq->lq_rls;
    }

    p_ldq->lqrls_status = TUNER_PM_SEQ_RLQ_RLS_RESET;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_rls_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_rls_reset (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    if (p_ldq->time_elapsed_ms > p_ldq->p_cfg->reset_time_ms)
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lqrls_status    = TUNER_PM_SEQ_RLQ_RLS_COMPLETED;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_dft_init
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_dft_init (motor_tuner_pm_ldq_t         * p_ldq,
                                 motor_tuner_pm_core_foc_t    * p_foc,
                                 motor_tuner_pm_signal_conf_t * st_signal_conf)
{
    float temp;
    float inpedence;

    if (TUNER_PM_SIGNAL_CONF_DEFAULT == st_signal_conf)
    {
        p_ldq->ldq_freq_ref_hz = p_ldq->p_cfg->lq_freq;

        p_ldq->vd_ref_offset = (p_foc->r * p_foc->rated_current * p_ldq->p_cfg->lq_vd_offset_coef) + p_foc->v_err;

        temp              = p_ldq->ldq_freq_ref_hz * p_foc->ld * TUNER_PM_TWOPI;
        inpedence         = sqrtf((p_foc->r * p_foc->r) + (temp * temp));
        p_ldq->vq_ref_amp = inpedence * p_foc->rated_current * p_ldq->p_cfg->lq_vq_amp_coef;
    }
    else
    {
        p_ldq->ldq_freq_ref_hz = st_signal_conf->signal_freg_hz;
        p_ldq->vd_ref_offset   = st_signal_conf->signal_offset;
        p_ldq->vq_ref_amp      = st_signal_conf->signal_amp;
    }

    rm_motor_tuner_sinref_init(&p_foc->sinref,
                               p_ldq->ldq_freq_ref_hz,
                               p_ldq->vq_ref_amp,
                               0,
                               p_foc->ctrl_period_ms * TUNER_PM_MS_TO_SECOND);
    rm_motor_tuner_dft_init(&p_foc->dft);

    p_ldq->stab_wait_ms    = (uint16_t) ((p_foc->lq * TUNER_PM_SECOND_TO_MS * p_ldq->p_cfg->stab_time_coef) / p_foc->r);
    p_ldq->time_elapsed_ms = 0.0F;
    p_ldq->lqdft_status    = TUNER_PM_SEQ_RLQ_DFT_READY;

    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_PRV_LDQ_CTRL_LEVEL);
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_dft_ready
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_dft_ready (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_ldq);

    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    p_foc->vd_ref = p_ldq->vd_ref_offset;

    if ((p_ldq->time_elapsed_ms > p_ldq->stab_wait_ms) &&
        (p_ldq->time_elapsed_ms <= (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF)))
    {
        p_foc->vq_ref = rm_motor_tuner_sinref_generate(&p_foc->sinref);
    }
    else if (p_ldq->time_elapsed_ms > (p_ldq->stab_wait_ms * TUNER_PM_PRV_AC_STAB_WAIT_END_TIME_COEF))
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lqdft_status    = TUNER_PM_SEQ_RLQ_DFT_MEASURE;
    }
    else
    {
        /* Do nothing */
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_dft_measure
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_dft_measure (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_foc->sum_cnt++;

    p_ldq->angle_pre = rm_motor_tuner_sinref_get_angle(&p_foc->sinref);
    p_foc->vq_ref    = rm_motor_tuner_sinref_generate(&p_foc->sinref);

    rm_motor_tuner_dft_sum(&p_foc->dft, p_ldq->angle_pre, p_foc->iq_ad);

    if (p_foc->sum_cnt >= ((p_foc->ctrl_freq_hz / p_ldq->ldq_freq_ref_hz) * p_ldq->p_cfg->lq_dft_measure_num))
    {
        rm_motor_tuner_dft_result(&p_foc->dft, &p_ldq->dft_real, &p_ldq->dft_imag);

        p_ldq->dft_amp2 = (p_ldq->dft_real * p_ldq->dft_real) + (p_ldq->dft_imag * p_ldq->dft_imag);
        p_ldq->dft_amp  = sqrtf(p_ldq->dft_amp2);

        p_ldq->lq_dft = ((p_ldq->vq_ref_amp * p_ldq->dft_imag) / p_ldq->dft_amp2) /
                        (p_ldq->ldq_freq_ref_hz * TUNER_PM_TWOPI);

        p_foc->sum_cnt      = 0;
        p_ldq->lqdft_status = TUNER_PM_SEQ_RLQ_DFT_CHECK;

        p_ldq->lqdft_v      = p_ldq->vq_ref_amp;
        p_ldq->lqdft_i_mag  = p_ldq->dft_amp;
        p_ldq->lqdft_i_img  = p_ldq->dft_imag;
        p_ldq->lqdft_i_real = p_ldq->dft_real;
    }
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_dft_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_dft_check (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    if (p_ldq->lq_dft <= p_foc->lq_min)
    {
        tuner_pm_core_throw_error(p_foc, MOTOR_TUNER_PM_ERROR_LQ_DFT);
    }

    p_ldq->lqdft_status = TUNER_PM_SEQ_RLQ_DFT_RESET;
}

/***********************************************************************************************************************
 * Function Name : ldq_seq_lq_dft_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 **********************************************************************************************************************/
static void ldq_seq_lq_dft_reset (motor_tuner_pm_ldq_t * p_ldq, motor_tuner_pm_core_foc_t * p_foc)
{
    p_ldq->time_elapsed_ms += p_foc->ctrl_period_ms;

    p_foc->vd_ref    = 0.0F;
    p_foc->vq_ref    = 0.0F;
    p_ldq->angle_pre = 0.0F;

    if (p_ldq->time_elapsed_ms > p_ldq->p_cfg->reset_time_ms)
    {
        p_ldq->time_elapsed_ms = 0.0F;
        p_ldq->lqdft_status    = TUNER_PM_SEQ_RLQ_DFT_COMPLETED;
    }
    else
    {
        /* Do nothing */
    }
}
