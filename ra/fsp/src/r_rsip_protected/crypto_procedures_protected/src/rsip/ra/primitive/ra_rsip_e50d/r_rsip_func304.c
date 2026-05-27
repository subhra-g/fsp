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

void r_rsip_func304 (void)
{
    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1ec80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x2121000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func304_func100_001[] =
    {
        BSWAP_32BIG_C(0x0482f1deU), BSWAP_32BIG_C(0x0425cc0bU), BSWAP_32BIG_C(0x93b904a2U), BSWAP_32BIG_C(0xcfaa5e61U),
    };
    r_rsip_func100(Param_func304_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func304_func100_002[] =
        {
            BSWAP_32BIG_C(0x55f43070U), BSWAP_32BIG_C(0xec726d02U), BSWAP_32BIG_C(0xafb82f2dU), BSWAP_32BIG_C(
                0x8f73c757U),
        };
        r_rsip_func100(Param_func304_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func304_func101_001[] =
            {
                BSWAP_32BIG_C(0xae16cbb2U), BSWAP_32BIG_C(0xad07c43bU), BSWAP_32BIG_C(0x088441dcU), BSWAP_32BIG_C(
                    0xdbe4ed5eU),
            };
            r_rsip_func101(Param_func304_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func304_func101_002[] =
            {
                BSWAP_32BIG_C(0x31c18744U), BSWAP_32BIG_C(0x68a5083dU), BSWAP_32BIG_C(0x8eb1d357U), BSWAP_32BIG_C(
                    0x51111556U),
            };
            r_rsip_func101(Param_func304_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func304_func100_003[] =
        {
            BSWAP_32BIG_C(0xd83e5f80U), BSWAP_32BIG_C(0xbb23c5a8U), BSWAP_32BIG_C(0x4d2c4620U), BSWAP_32BIG_C(
                0x9b1d9097U),
        };
        r_rsip_func100(Param_func304_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func304_func101_003[] =
            {
                BSWAP_32BIG_C(0x80987b8dU), BSWAP_32BIG_C(0x940c8e41U), BSWAP_32BIG_C(0xceb045d6U), BSWAP_32BIG_C(
                    0x853d9255U),
            };
            r_rsip_func101(Param_func304_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x2121000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func304_func101_004[] =
            {
                BSWAP_32BIG_C(0x14a4003eU), BSWAP_32BIG_C(0x5e5c72d8U), BSWAP_32BIG_C(0x99d46613U), BSWAP_32BIG_C(
                    0x3b5b4673U),
            };
            r_rsip_func101(Param_func304_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
