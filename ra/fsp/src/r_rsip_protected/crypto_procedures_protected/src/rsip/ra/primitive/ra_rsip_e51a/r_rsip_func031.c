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

void r_rsip_func031 (const uint32_t ARG1[])
{
    r_rsip_func_sub024(0x0000356aU, 0x0420a960U, 0x00000002U, 0x0001696bU);
    r_rsip_func_sub024(0x00036d6bU, 0x00009160U, 0x00000042U, 0x00186d6bU);

    r_rsip_func_sub024(0x00008c60U, 0x00ffffffU, 0x0000106bU, 0x000010c9U);

    WR1_PROG(REG_1824H, 0x08000105U);
    WR1_PROG(REG_1608H, 0x81040060U);
    r_rsip_func_sub001(0x00490011U);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80840001U);
    r_rsip_func_sub001(0x03410011U);

    r_rsip_func_sub020(0x000003c1U, 0x08000105U);
    WR4_ADDR(REG_1420H, &ARG1[0]);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03410011U);

    r_rsip_func_sub024(0x0000b560U, 0x00000005U, 0x01906d6cU, 0x01906d8dU);
    WR1_PROG(REG_1600H, 0x000009adU);
    WR1_PROG(REG_1600H, 0x000009ceU);

    WR1_PROG(REG_1824H, 0x08000105U);
    WR1_PROG(REG_1608H, 0x81040160U);
    r_rsip_func_sub001(0x00490011U);

    r_rsip_func_sub026(0x0000a420U, 0x00000010U, 0x80840001U);
    r_rsip_func_sub001(0x03410011U);

    WR1_PROG(REG_182CH, 0x00000100U);
    WR1_PROG(REG_1824H, 0xf8008007U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x81880001U);
    r_rsip_func_sub001(0x00490021U);
}
