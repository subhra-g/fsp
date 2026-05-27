/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"
#include "r_rsip_sub_func.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func433 (const uint32_t ARG1[], const uint32_t ARG2[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub008(0x000001c1U, 0x00008000U, 0x0e128455U);
    WR2_ADDR(REG_002CH, &ARG1[0]);

    r_rsip_func_sub003(0x81020040U, 0x00490009U);

    WR1_PROG(REG_00D0H, 0x08000045U);
    WR1_PROG(REG_0094H, 0x0000b420U);
    WR1_PROG(REG_0094H, 0x00000010U);
    r_rsip_func_sub003(0x81840001U, 0x00490011U);

    r_rsip_func_sub005(0x000000a1U, 0x0c100104U, 0x00000000U);

    WR1_PROG(REG_00D4H, 0x00000020U);
    r_rsip_func_sub006(0x07008d05U, 0x00410011U);

    WR1_PROG(REG_0094H, 0x00000821U);
    r_rsip_func_sub003(0x80840001U, 0x03410011U);

    WR1_PROG(REG_0094H, 0x00000884U);
    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub016(0x3c002825U, 0x12003c81U, 0x00002c20U);
    }

    WR1_PROG(REG_0014H, 0x000003c1U);
    WR1_PROG(REG_00D0H, 0x08000055U);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &ARG2[0]);

    WR1_PROG(REG_00D0H, 0x9c100005U);
    WR1_PROG(REG_0094H, 0x00000821U);
    r_rsip_func_sub003(0x81840001U, 0x00490011U);
}
