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

void r_rsip_func411 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func411_func100_001[] =
    {
        BSWAP_32BIG_C(0x3d914b24U), BSWAP_32BIG_C(0xae6f621cU), BSWAP_32BIG_C(0x791a6637U), BSWAP_32BIG_C(0x427e17fdU),
    };
    r_rsip_func100(Param_func411_func100_001);

    r_rsip_func_sub024(0x3420a8a0U, 0x00000006U, 0x2000b4a0U, 0x00000005U);

    r_rsip_func_sub024(0x000034c5U, 0x380088c0U, 0x00000002U, 0x100008c6U);

    r_rsip_func_sub024(0x380088c0U, 0x00000003U, 0x1000b4c0U, 0x00000001U);

    r_rsip_func_sub025(0x00000800U, 0x0000b420U, 0x00000080U);

    WR1_PROG(REG_1608H, 0x80b10000U);
    r_rsip_func_sub001(0x034000c5U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub024(0x0000b560U, 0x00000007U, 0x0000b580U, 0x000000a4U);

        static const uint32_t Param_func411_func101_001[] =
        {
            BSWAP_32BIG_C(0x7460c75bU), BSWAP_32BIG_C(0x1258518dU), BSWAP_32BIG_C(0x324d7cf4U), BSWAP_32BIG_C(
                0x1e5b74aeU),
        };
        r_rsip_func101(Param_func411_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub024(0x0000b560U, 0x00000008U, 0x0000b580U, 0x000000a0U);

        static const uint32_t Param_func411_func101_002[] =
        {
            BSWAP_32BIG_C(0x6317df35U), BSWAP_32BIG_C(0xcff9f1f8U), BSWAP_32BIG_C(0x2c54476cU), BSWAP_32BIG_C(
                0x584205cfU),
        };
        r_rsip_func101(Param_func411_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        r_rsip_func_sub024(0x0000b560U, 0x0000000cU, 0x0000b580U, 0x00000090U);

        static const uint32_t Param_func411_func101_003[] =
        {
            BSWAP_32BIG_C(0x1281f3fbU), BSWAP_32BIG_C(0xb37e1668U), BSWAP_32BIG_C(0x8547a55fU), BSWAP_32BIG_C(
                0x4f7f175eU),
        };
        r_rsip_func101(Param_func411_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        r_rsip_func_sub024(0x0000b560U, 0x00000010U, 0x0000b580U, 0x00000080U);

        static const uint32_t Param_func411_func101_004[] =
        {
            BSWAP_32BIG_C(0x4fb97af4U), BSWAP_32BIG_C(0x704ed688U), BSWAP_32BIG_C(0x4ddab710U), BSWAP_32BIG_C(
                0xb1f9bce5U),
        };
        r_rsip_func101(Param_func411_func101_004);
    }

    WR1_PROG(REG_1600H, 0x0000094aU);

    static const uint32_t Param_func411_func100_002[] =
    {
        BSWAP_32BIG_C(0xb5f98613U), BSWAP_32BIG_C(0xcd0b6ee0U), BSWAP_32BIG_C(0x69a5d2acU), BSWAP_32BIG_C(0xefeee76fU),
    };
    r_rsip_func100(Param_func411_func100_002);
    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub010(0x000000c7U, 0x80810000U);
        WR1_PROG(REG_1420H, ARG1[iLoop]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub025(0x0000a400U, 0x00000004U, 0x00002d40U);
        static const uint32_t Param_func411_func101_005[] =
        {
            BSWAP_32BIG_C(0x5de7b4e7U), BSWAP_32BIG_C(0x9f9cfc36U), BSWAP_32BIG_C(0xe8e9dc27U), BSWAP_32BIG_C(
                0x543f4245U),
        };
        r_rsip_func101(Param_func411_func101_005);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x3800094bU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
