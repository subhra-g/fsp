/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include <stdint.h>

#include "rm_motor_tuner_pm_volterr.h"
#include "rm_motor_tuner_pm_core.h"
#include "rm_motor_tuner_lib.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB     (2)
#define TUNER_PM_VOLTERR_PRV_LINEREG_TAB_NUM      ((TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB * 2) + 1)
#define TUNER_PM_VOLTERR_PRV_START_CURRENT_LSB    (-16)
#ifndef TUNER_PM_PRV_FILE_CODE
 #define TUNER_PM_PRV_FILE_CODE                   (102)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static const float s_normalized_verr_breakpoints[5] =
{
    0.409F,
    0.696F,
    0.878F,
    0.970F,
    1.0F
};

static void volterr_seq_init(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
static void volterr_seq_id_r(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
static void volterr_seq_id_verr_over_i(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
static void volterr_seq_calc(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
static void volterr_seq_check(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);
static void volterr_seq_reset(motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name : tuner_pm_volterr_init
 * Description   : Init
 * Arguments     : None
 * Return Value  : None
 ***********************************************************************************************************************/
void tuner_pm_volterr_init (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    static const float s_r_init_default = 0.5F;
    static const float s_i_lsb_default  = 0.01F;

    FSP_PARAMETER_NOT_USED(p_foc);

    p_volterr_id->rid_method        = TUNER_PM_VOLTERR_RID_RLS;
    p_volterr_id->r_init            = s_r_init_default;
    p_volterr_id->i_lsb             = s_i_lsb_default;
    p_volterr_id->current_step_ilsb = p_volterr_id->p_cfg->min_current_step_lsb;
    p_volterr_id->start_current_lsb = TUNER_PM_VOLTERR_PRV_START_CURRENT_LSB;
}

/******************************************************************************
 * Function Name : tuner_pm_volterr_act
 * Description   : Voltage error identification top layer sequence
 * Arguments     : None
 * Return Value  : Whether the process is done (1) or not (0)
 ******************************************************************************/
uint16_t tuner_pm_volterr_act (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    uint16_t ret = 0;
    switch (p_volterr_id->e_status)
    {
        case TUNER_PM_VOLTERR_SEQ_INIT:
        {
            volterr_seq_init(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_ID_R:
        {
            volterr_seq_id_r(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_ID_V_OVER_I:
        {
            volterr_seq_id_verr_over_i(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_CALC:
        {
            volterr_seq_calc(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_CHECK:
        {
            volterr_seq_check(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_RESET:
        {
            volterr_seq_reset(p_volterr_id, p_foc);
            break;
        }

        case TUNER_PM_VOLTERR_SEQ_COMPLETED:
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
 * Function Name : tuner_pm_volterr_reset
 * Description   : Reset voltage error identification
 * Arguments     : None
 * Return Value  : None
 ***********************************************************************************************************************/
void tuner_pm_volterr_reset (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_INIT;
}

/***********************************************************************************************************************
 * Function Name : tuner_pm_volterr_config
 * Description   : Configure basic settings
 * Arguments     :
 * Return Value  : None
 ***********************************************************************************************************************/
void tuner_pm_volterr_config (motor_tuner_pm_volterr_t    * p_volterr_id,
                              motor_tuner_pm_core_foc_t   * p_foc,
                              float                         r_initval,
                              float                         i_lsb,
                              motor_tuner_volterr_cfg_rid_t e_rid_cfg)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_volterr_id->r_init = r_initval;

    /* Considering scaling from phase current to dq current */
    p_volterr_id->i_lsb      = i_lsb * TUNER_PM_SQRT_3;
    p_volterr_id->rid_method = e_rid_cfg;
}

/***********************************************************************************************************************
 * Function Name : tuner_pm_volterr_config_current_step
 * Description   : Set current step multiplier (integer, at least p_volterr_id->p_cfg->min_current_step_lsb)
 * Arguments     :
 * Return Value  : None
 ***********************************************************************************************************************/
void tuner_pm_volterr_config_current_step (motor_tuner_pm_volterr_t  * p_volterr_id,
                                           motor_tuner_pm_core_foc_t * p_foc,
                                           uint16_t                    ilsb)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    if (ilsb < p_volterr_id->p_cfg->min_current_step_lsb)
    {
        p_volterr_id->current_step_ilsb = p_volterr_id->p_cfg->min_current_step_lsb;
    }
    else
    {
        /* Integer to float */
        p_volterr_id->current_step_ilsb = (float) ilsb;
    }
}

/******************************************************************************
 * Function Name : volterr_seq_init
 * Description   : Initializes parameters
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_init (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    static const float s_inject_angle_rad = (TUNER_PM_TWOPI * (-0.3333333F * 0.25F));

    memset(p_volterr_id->current_table, 0, sizeof(p_volterr_id->current_table));
    memset(p_volterr_id->voltage_table, 0, sizeof(p_volterr_id->voltage_table));
    memset(p_volterr_id->slope_table, 0, sizeof(p_volterr_id->slope_table));
    memset(p_volterr_id->intercept_table, 0, sizeof(p_volterr_id->intercept_table));
    p_volterr_id->count            = 0;
    p_volterr_id->meas_index       = 0;
    p_volterr_id->meas_volt_sum    = 0.0F;
    p_volterr_id->meas_current_sum = 0.0F;
    p_volterr_id->sat_current      = 0.0F;
    p_volterr_id->sat_voltage      = 0.0F;
    p_volterr_id->current_target   = 0.0F;
    p_volterr_id->r_dc             = p_volterr_id->r_init;
    p_volterr_id->voltage_step     = (p_volterr_id->r_dc * p_volterr_id->i_lsb * p_volterr_id->current_step_ilsb);
    rm_motor_tuner_rls2_init(&p_foc->rls,
                             p_foc->p_cfg->default_rls_init,
                             p_foc->p_cfg->default_rls_init,
                             p_volterr_id->p_cfg->rls_fgt_factor,
                             p_volterr_id->r_dc,
                             0.0F);

    if (TUNER_PM_VOLTERR_RID_IGNORE == p_volterr_id->rid_method)
    {
        p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_ID_V_OVER_I;
    }
    else
    {
        p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_ID_R;
    }

    tuner_pm_core_set_ctrl_level(p_foc, TUNER_PM_CTRL_LEVEL_0);
    p_foc->vd_ref = p_volterr_id->voltage_step;

    /* Inject current with 30 degree will eliminate current through phase W (presented by ic_ad) */
    p_foc->angle_rad = s_inject_angle_rad;
}

/******************************************************************************
 * Function Name : volterr_seq_id_r
 * Description   : Estimate maximum voltage error and precisive resistance by RLS algorithm
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_id_r (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    static const float id_coef = 2.0F;
    float              v_mean;
    float              i_mean;
    float              vd_ref;
    float              id;
    float              verr_est;
    uint32_t           avg_sample_fast = (uint32_t) p_volterr_id->p_cfg->avg_sample_fast;
    uint32_t           sample_to_wait  =
        (uint32_t) (p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND * p_volterr_id->p_cfg->avg_wait_time);

    /* Input signals */
    vd_ref = p_foc->vd_ref;
    id     = p_foc->ia_ad * id_coef;

    p_volterr_id->count++;

    if (p_volterr_id->count >= (avg_sample_fast + sample_to_wait))
    {
        i_mean                         = p_volterr_id->meas_current_sum / p_volterr_id->p_cfg->avg_sample_fast;
        v_mean                         = p_volterr_id->meas_volt_sum / p_volterr_id->p_cfg->avg_sample_fast;
        p_volterr_id->count            = 0;
        p_volterr_id->meas_current_sum = 0.0F;
        p_volterr_id->meas_volt_sum    = 0.0F;

        rm_motor_tuner_rls2_exec(&p_foc->rls, i_mean, 1.0F, v_mean, &p_volterr_id->r_dc, &verr_est);

        /* When current reaches the specified boundary */
        if (((p_volterr_id->voltage_step > 0.0F) &&
             (i_mean > (p_foc->rated_current * p_volterr_id->p_cfg->rls_upper_current))) ||
            ((p_volterr_id->voltage_step < 0.0F) &&
             (i_mean < (p_foc->rated_current * p_volterr_id->p_cfg->rls_lower_current))))
        {
            p_volterr_id->iteration_cnt++;

            /* Update magnitude of voltage step with latest R */
            p_volterr_id->voltage_step = (p_volterr_id->r_dc * p_volterr_id->i_lsb * p_volterr_id->current_step_ilsb);

            /* Reverse direction of voltage step */
            if (p_volterr_id->iteration_cnt & 0x01)
            {
                p_volterr_id->voltage_step = -p_volterr_id->voltage_step;
            }

            /* If all test is ended */
            if (p_volterr_id->iteration_cnt > p_volterr_id->p_cfg->iteration_num)
            {
                p_volterr_id->e_status     = TUNER_PM_VOLTERR_SEQ_ID_V_OVER_I;
                p_volterr_id->voltage_step =
                    (p_volterr_id->r_dc * p_volterr_id->i_lsb * p_volterr_id->current_step_ilsb);
                p_volterr_id->current_target = p_volterr_id->i_lsb *
                                               (p_volterr_id->current_step_ilsb *
                                                (float) p_volterr_id->start_current_lsb);
                vd_ref = p_volterr_id->r_dc * p_volterr_id->current_target;
                p_volterr_id->iteration_cnt = 0;
            }
        }
        else
        {
            vd_ref += p_volterr_id->voltage_step;
        }
    }
    else if (p_volterr_id->count >=
             (uint32_t) (p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND * p_volterr_id->p_cfg->avg_wait_time))
    {
        p_volterr_id->meas_current_sum += id;
        p_volterr_id->meas_volt_sum    += p_foc->va_ref_pwm;
    }
    else
    {
        /* Do nothing */
    }

    /* Output signals */
    p_foc->vd_ref = vd_ref;
}

/******************************************************************************
 * Function Name : volterr_seq_id_verr_over_i
 * Description   : Measure the voltage error at each current measurement point
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_id_verr_over_i (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    float v_mean;
    float i_mean;
    float vd_ref;
    float id;

    /* Input signals */
    vd_ref = p_foc->vd_ref;
    id     = p_foc->id_ad;

    p_volterr_id->count++;
    if (p_volterr_id->count >=
        (uint32_t) (p_volterr_id->p_cfg->avg_sample +
                    (p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND * p_volterr_id->p_cfg->avg_wait_time)))
    {
        i_mean = p_volterr_id->meas_current_sum / p_volterr_id->p_cfg->avg_sample;
        v_mean = p_volterr_id->meas_volt_sum / p_volterr_id->p_cfg->avg_sample;

        if ((p_volterr_id->current_target - i_mean) > (p_volterr_id->i_lsb))
        {
            vd_ref += (p_volterr_id->i_lsb * p_volterr_id->r_dc);
        }
        else
        {
            p_volterr_id->current_table[p_volterr_id->meas_index] = i_mean;
            p_volterr_id->voltage_table[p_volterr_id->meas_index] = v_mean;
            p_volterr_id->meas_index++;
            if ((p_volterr_id->meas_index >= p_volterr_id->p_cfg->point_num) || (i_mean > p_foc->rated_current))
            {
                vd_ref                 = 0.0F;
                p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_CALC;
            }
            else
            {
                p_volterr_id->current_target = i_mean + (p_volterr_id->i_lsb * p_volterr_id->current_step_ilsb);
                vd_ref += p_volterr_id->voltage_step;
            }
        }

        p_volterr_id->count            = 0;
        p_volterr_id->meas_current_sum = 0.0F;
        p_volterr_id->meas_volt_sum    = 0.0F;
    }
    else if (p_volterr_id->count >=
             (uint32_t) (p_foc->ctrl_freq_hz * TUNER_PM_MS_TO_SECOND * p_volterr_id->p_cfg->avg_wait_time))
    {
        p_volterr_id->meas_current_sum += id;
        p_volterr_id->meas_volt_sum    += p_foc->va_ref_pwm;
    }
    else
    {
        /* Do nothing */
    }

    /* Output signals */
    p_foc->vd_ref = vd_ref;
}

/******************************************************************************
 * Function Name : volterr_seq_calc
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_calc (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    static const float s_volt_err_coef = 0.5F; // the measured error includes error of two phases
    uint32_t           tab_n;
    uint32_t           i;
    uint32_t           j;
    float              max_verr  = 0.0F;
    uint32_t           sat_index = 0;
    float              cursor;
    float              volt_err;

    FSP_PARAMETER_NOT_USED(p_foc);

    tab_n = p_volterr_id->meas_index;
    for (i = TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB; i < (tab_n - TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB); i++)
    {
        rm_motor_tuner_linear_regression(&p_volterr_id->current_table[i - TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB],
                                         &p_volterr_id->voltage_table[i - TUNER_PM_VOLTERR_PRV_LINEREG_SIZE_TAB],
                                         TUNER_PM_VOLTERR_PRV_LINEREG_TAB_NUM,
                                         &p_volterr_id->slope_table[i],
                                         &p_volterr_id->intercept_table[i]);

        if (max_verr < p_volterr_id->intercept_table[i])
        {
            max_verr  = p_volterr_id->intercept_table[i];
            sat_index = i;
        }
    }

    /* Determine the resistance to calculate voltage error, store saturated voltage error and current at that point*/
    p_volterr_id->r_dc        = p_volterr_id->slope_table[sat_index];
    p_volterr_id->sat_current = p_volterr_id->current_table[sat_index];
    p_volterr_id->sat_voltage = p_volterr_id->voltage_table[sat_index] -
                                (p_volterr_id->sat_current * p_volterr_id->r_dc);

    /* Construct the interpolation table */
    j = 0;
    for (i = 0; i < MOTOR_TUNER_PM_VOLTERR_OUTPUT_TAB_SIZE; i++)
    {
        cursor = s_normalized_verr_breakpoints[i] * p_volterr_id->sat_voltage;

        do
        {
            j++;
            volt_err = p_volterr_id->voltage_table[j] -
                       (p_volterr_id->current_table[j] * p_volterr_id->r_dc);
        } while ((volt_err < cursor) && (j < (tab_n - 1)));

        p_volterr_id->output_current_tab[i] = p_volterr_id->current_table[j];
        p_volterr_id->output_voltage_tab[i] = volt_err * s_volt_err_coef;
    }

    p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_CHECK;
}

/******************************************************************************
 * Function Name : volterr_seq_check
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_check (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    p_volterr_id->output_vdc_ref = p_foc->vdc_ad;
    p_volterr_id->output_rdc     = p_volterr_id->r_dc;
    p_volterr_id->e_status       = TUNER_PM_VOLTERR_SEQ_RESET;
}

/******************************************************************************
 * Function Name : volterr_seq_reset
 * Description   :
 * Arguments     : None
 * Return Value  : none
 ******************************************************************************/
static void volterr_seq_reset (motor_tuner_pm_volterr_t * p_volterr_id, motor_tuner_pm_core_foc_t * p_foc)
{
    FSP_PARAMETER_NOT_USED(p_foc);

    p_volterr_id->e_status = TUNER_PM_VOLTERR_SEQ_COMPLETED;
}
