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

void r_rsip_func302 (void)
{
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1f480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x1111000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func302_func100_001[] =
    {
        BSWAP_32BIG_C(0xebc3fc05U), BSWAP_32BIG_C(0xefb97619U), BSWAP_32BIG_C(0xda871071U), BSWAP_32BIG_C(0x8eb49b2cU),
    };
    r_rsip_func100(Param_func302_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func302_func100_002[] =
        {
            BSWAP_32BIG_C(0x0ab13913U), BSWAP_32BIG_C(0x05882ea2U), BSWAP_32BIG_C(0xab583e8dU), BSWAP_32BIG_C(
                0x1d4aa3a6U),
        };
        r_rsip_func100(Param_func302_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func302_func101_001[] =
            {
                BSWAP_32BIG_C(0x4b8b270dU), BSWAP_32BIG_C(0xe9d63591U), BSWAP_32BIG_C(0x07745a36U), BSWAP_32BIG_C(
                    0x019222b7U),
            };
            r_rsip_func101(Param_func302_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func302_func101_002[] =
            {
                BSWAP_32BIG_C(0x1ec17fc5U), BSWAP_32BIG_C(0xb1ecda41U), BSWAP_32BIG_C(0xaa2a1fa2U), BSWAP_32BIG_C(
                    0x18fa8b15U),
            };
            r_rsip_func101(Param_func302_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func302_func100_003[] =
        {
            BSWAP_32BIG_C(0xc74ebd23U), BSWAP_32BIG_C(0xfb81e80cU), BSWAP_32BIG_C(0x562336d5U), BSWAP_32BIG_C(
                0x9af6e6e8U),
        };
        r_rsip_func100(Param_func302_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func302_func101_003[] =
            {
                BSWAP_32BIG_C(0x8028c0c0U), BSWAP_32BIG_C(0xa5e74618U), BSWAP_32BIG_C(0xd75bec94U), BSWAP_32BIG_C(
                    0x142e61dbU),
            };
            r_rsip_func101(Param_func302_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1111000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func302_func101_004[] =
            {
                BSWAP_32BIG_C(0xe3a4de3dU), BSWAP_32BIG_C(0x43aa5b5aU), BSWAP_32BIG_C(0x99f59db7U), BSWAP_32BIG_C(
                    0x90eae4a5U),
            };
            r_rsip_func101(Param_func302_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
