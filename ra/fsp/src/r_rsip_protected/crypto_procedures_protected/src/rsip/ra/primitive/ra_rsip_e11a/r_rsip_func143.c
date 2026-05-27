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

void r_rsip_func143 (void)
{
    WR1_PROG(REG_00A0H, 0x00010000U);

    static const uint32_t Param_func143_func100_001[] =
    {
        BSWAP_32BIG_C(0xe70b0311U), BSWAP_32BIG_C(0xf2a7329bU), BSWAP_32BIG_C(0x5a167e53U), BSWAP_32BIG_C(0x6f4fecedU),
    };
    r_rsip_func100(Param_func143_func100_001);
    WR1_PROG(REG_00B0H, 0x00001898U);
    r_rsip_func_sub006(0x08000085U, 0x00430011U);

    static const uint32_t Param_func143_func100_002[] =
    {
        BSWAP_32BIG_C(0xd4aad776U), BSWAP_32BIG_C(0xcd33f88dU), BSWAP_32BIG_C(0x61166039U), BSWAP_32BIG_C(0xb0743597U),
    };
    r_rsip_func100(Param_func143_func100_002);
    r_rsip_func_sub006(0x08000095U, 0x00430011U);

    static const uint32_t Param_func143_func100_003[] =
    {
        BSWAP_32BIG_C(0x07143c6fU), BSWAP_32BIG_C(0xc52e2a1bU), BSWAP_32BIG_C(0xa851536bU), BSWAP_32BIG_C(0x2b75f0fbU),
    };
    r_rsip_func100(Param_func143_func100_003);

    WR1_PROG(REG_00D0H, 0x080000c5U);
    r_rsip_func_sub004(0x00000893U, 0x00430009U);
    r_rsip_func_sub004(0x00000894U, 0x00430009U);

    WR1_PROG(REG_00D0H, 0x0b040104U);
    r_rsip_func_sub003(0x810100c0U, 0x00490005U);

    WR1_PROG(REG_0094H, 0x000008c6U);

    r_rsip_func_sub003(0x80840006U, 0x03410011U);

    r_rsip_func_sub016(0x00003846U, 0x00008c40U, 0x00ffffffU);
    r_rsip_func_sub016(0x00009040U, 0x01000000U, 0x00003c46U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009105U);
    r_rsip_func_sub003(0x81840006U, 0x00490011U);

    r_rsip_func_sub016(0x00008c40U, 0x00ffffffU, 0x00009040U);
    WR1_PROG(REG_0094H, 0x02000000U);
    WR1_PROG(REG_0094H, 0x00003c46U);

    static const uint32_t Param_func143_func100_004[] =
    {
        BSWAP_32BIG_C(0x4ebcf62eU), BSWAP_32BIG_C(0x79ae282fU), BSWAP_32BIG_C(0x759f2c12U), BSWAP_32BIG_C(0xdd1bd903U),
    };
    r_rsip_func100(Param_func143_func100_004);
    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009095U);
    r_rsip_func_sub003(0x81840006U, 0x00490011U);

    static const uint32_t Param_func143_func100_005[] =
    {
        BSWAP_32BIG_C(0x23f11179U), BSWAP_32BIG_C(0x6635ab8dU), BSWAP_32BIG_C(0xcfcc652eU), BSWAP_32BIG_C(0x5301513fU),
    };
    r_rsip_func100(Param_func143_func100_005);
    r_rsip_func_sub006(0x08000085U, 0x00410011U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
