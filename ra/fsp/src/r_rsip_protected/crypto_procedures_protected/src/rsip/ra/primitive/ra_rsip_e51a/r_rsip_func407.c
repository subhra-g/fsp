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

void r_rsip_func407 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    static const uint32_t Param_func407_func100_001[] =
    {
        BSWAP_32BIG_C(0x697fdaaeU), BSWAP_32BIG_C(0xce07b0a7U), BSWAP_32BIG_C(0x2a561da2U), BSWAP_32BIG_C(0x3540d86fU),
    };
    r_rsip_func100(Param_func407_func100_001);
    r_rsip_func_sub016(0x810100c0U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, ARG1[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f407U);

    static const uint32_t Param_func407_func101_001[] =
    {
        BSWAP_32BIG_C(0xdddf44b0U), BSWAP_32BIG_C(0x196546c3U), BSWAP_32BIG_C(0xb36e0473U), BSWAP_32BIG_C(0x17543918U),
    };
    r_rsip_func101(Param_func407_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f407U);

    static const uint32_t Param_func407_func101_002[] =
    {
        BSWAP_32BIG_C(0x1481edd1U), BSWAP_32BIG_C(0x7c777a33U), BSWAP_32BIG_C(0x6c537039U), BSWAP_32BIG_C(0xa8853563U),
    };
    r_rsip_func101(Param_func407_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    WR1_PROG(REG_1600H, 0x000008a5U);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &ARG1[1 + iLoop]);

        WR1_PROG(REG_1608H, 0x80840005U);
        r_rsip_func_sub001(0x03420011U);

        r_rsip_func_sub024(0x0000a4a0U, 0x00000010U, 0x0000a4e0U, 0x00000004U);

        static const uint32_t Param_func407_func101_003[] =
        {
            BSWAP_32BIG_C(0x638e4599U), BSWAP_32BIG_C(0xcaff2167U), BSWAP_32BIG_C(0xe247c414U), BSWAP_32BIG_C(
                0x16dfb792U),
        };
        r_rsip_func101(Param_func407_func101_003);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x380008c7U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &ARG1[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
