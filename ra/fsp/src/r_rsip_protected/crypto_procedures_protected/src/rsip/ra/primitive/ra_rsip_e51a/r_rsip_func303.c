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

void r_rsip_func303 (void)
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

    static const uint32_t Param_func303_func100_001[] =
    {
        BSWAP_32BIG_C(0x06368669U), BSWAP_32BIG_C(0xe7ed91a1U), BSWAP_32BIG_C(0x590b36c5U), BSWAP_32BIG_C(0xa0c5c203U),
    };
    r_rsip_func100(Param_func303_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func303_func100_002[] =
        {
            BSWAP_32BIG_C(0x9da54cb3U), BSWAP_32BIG_C(0xdeedb109U), BSWAP_32BIG_C(0x22753694U), BSWAP_32BIG_C(
                0x6b6ad934U),
        };
        r_rsip_func100(Param_func303_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func303_func101_001[] =
            {
                BSWAP_32BIG_C(0x04a37645U), BSWAP_32BIG_C(0x7d2edf7eU), BSWAP_32BIG_C(0x4487b211U), BSWAP_32BIG_C(
                    0x7b39e3a1U),
            };
            r_rsip_func101(Param_func303_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func303_func101_002[] =
            {
                BSWAP_32BIG_C(0x99405635U), BSWAP_32BIG_C(0x768baf33U), BSWAP_32BIG_C(0xa4446829U), BSWAP_32BIG_C(
                    0x6cbd7a02U),
            };
            r_rsip_func101(Param_func303_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func303_func100_003[] =
        {
            BSWAP_32BIG_C(0xafd07230U), BSWAP_32BIG_C(0x73b5db2aU), BSWAP_32BIG_C(0xe2d32420U), BSWAP_32BIG_C(
                0x3a76baf9U),
        };
        r_rsip_func100(Param_func303_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1111000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func303_func101_003[] =
            {
                BSWAP_32BIG_C(0xd6eae33cU), BSWAP_32BIG_C(0x4a5c8723U), BSWAP_32BIG_C(0x951ebb62U), BSWAP_32BIG_C(
                    0x5b62ac2cU),
            };
            r_rsip_func101(Param_func303_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);

            static const uint32_t Param_func303_func101_004[] =
            {
                BSWAP_32BIG_C(0x828ea0e5U), BSWAP_32BIG_C(0xa318b3ddU), BSWAP_32BIG_C(0xd7565856U), BSWAP_32BIG_C(
                    0x34b30d6dU),
            };
            r_rsip_func101(Param_func303_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
