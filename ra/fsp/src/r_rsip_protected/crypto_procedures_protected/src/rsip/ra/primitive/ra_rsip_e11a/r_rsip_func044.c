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

void r_rsip_func044 (void)
{
    r_rsip_func_sub016(0x00008cc0U, 0x00ffffffU, 0x000090c0U);
    WR1_PROG(REG_0094H, 0x01000000U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009104U);
    r_rsip_func_sub003(0x810100c0U, 0x00490005U);

    r_rsip_func_sub016(0x00008cc0U, 0x00ffffffU, 0x000090c0U);
    WR1_PROG(REG_0094H, 0x02000000U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009044U);
    r_rsip_func_sub003(0x810100c0U, 0x00490005U);

    static const uint32_t Param_func044_func100_001[] =
    {
        BSWAP_32BIG_C(0x42d35f05U), BSWAP_32BIG_C(0x2e2f4f28U), BSWAP_32BIG_C(0x7e241f51U), BSWAP_32BIG_C(0x93b47cdeU),
    };
    r_rsip_func100(Param_func044_func100_001);
    r_rsip_func_sub006(0x08000085U, 0x00410011U);

    static const uint32_t Param_func044_func100_002[] =
    {
        BSWAP_32BIG_C(0xdb1bb873U), BSWAP_32BIG_C(0xae363a34U), BSWAP_32BIG_C(0xe5ae30d6U), BSWAP_32BIG_C(0x970ee6caU),
    };
    r_rsip_func100(Param_func044_func100_002);
    r_rsip_func_sub005(0x000000a1U, 0x0c000094U, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
