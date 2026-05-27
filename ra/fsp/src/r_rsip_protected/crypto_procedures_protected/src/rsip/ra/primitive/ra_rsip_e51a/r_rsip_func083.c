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

void r_rsip_func083 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func083_func100_001[] =
    {
        BSWAP_32BIG_C(0x0568b4e1U), BSWAP_32BIG_C(0xbf0433caU), BSWAP_32BIG_C(0x66adef04U), BSWAP_32BIG_C(0xde527ecdU),
    };
    r_rsip_func100(Param_func083_func100_001);
    r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
    WR1_PROG(REG_1420H, ARG1[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00002840U);

    r_rsip_func_sub016(0x81010040U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x000008a5U);

    WR1_PROG(REG_1600H, 0x00003466U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        WR1_PROG(REG_1608H, 0x81010060U);
        r_rsip_func_sub001(0x12490005U);
        r_rsip_func_sub001(0x1009000dU);

        WR1_PROG(REG_1600H, 0x00086c63U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_001[] =
        {
            BSWAP_32BIG_C(0x821546c5U), BSWAP_32BIG_C(0xe5cbedc8U), BSWAP_32BIG_C(0x3782e44eU), BSWAP_32BIG_C(
                0x6a9ecf45U),
        };
        r_rsip_func101(Param_func083_func101_001);
    }

    r_rsip_func_sub011(0x38000845U);

    static const uint32_t Param_func083_func100_002[] =
    {
        BSWAP_32BIG_C(0x5a1e4294U), BSWAP_32BIG_C(0xb7b2d990U), BSWAP_32BIG_C(0x6074e52eU), BSWAP_32BIG_C(0x73069a3cU),
    };
    r_rsip_func100(Param_func083_func100_002);

    r_rsip_func_sub025(0x000034e6U, 0x00036c00U, 0x00004400U);

    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1600H, 0x00000001U);

    for (iLoop = 1; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_1420H, ARG1[iLoop]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub026(0x00003506U, 0x01807507U, 0x81010100U);
        r_rsip_func_sub001(0x02490005U);

        WR1_PROG(REG_1600H, 0x000034e6U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_002[] =
        {
            BSWAP_32BIG_C(0x20482510U), BSWAP_32BIG_C(0x05a4e180U), BSWAP_32BIG_C(0xa3667c53U), BSWAP_32BIG_C(
                0xe8d7b0fbU),
        };
        r_rsip_func101(Param_func083_func101_002);
    }

    r_rsip_func_sub011(0x38000965U);
    r_rsip_func_sub006(0x38008ec0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_func083_func100_003[] =
    {
        BSWAP_32BIG_C(0x84d3852eU), BSWAP_32BIG_C(0xe3377619U), BSWAP_32BIG_C(0x415df6ebU), BSWAP_32BIG_C(0x364c220bU),
    };
    r_rsip_func100(Param_func083_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub026(0x00000908U, 0x01807507U, 0x81010100U);
        r_rsip_func_sub001(0x02490005U);

        static const uint32_t Param_func083_func101_003[] =
        {
            BSWAP_32BIG_C(0x645141fcU), BSWAP_32BIG_C(0x6939e82aU), BSWAP_32BIG_C(0xe9f488bbU), BSWAP_32BIG_C(
                0x4a7740b8U),
        };
        r_rsip_func101(Param_func083_func101_003);
    }

    static const uint32_t Param_func083_func100_004[] =
    {
        BSWAP_32BIG_C(0xf5fcea36U), BSWAP_32BIG_C(0xd41ed011U), BSWAP_32BIG_C(0x386435cbU), BSWAP_32BIG_C(0x3a0dbf36U),
    };
    r_rsip_func100(Param_func083_func100_004);
    r_rsip_func_sub024(0x00003416U, 0x0000a400U, 0x00000003U, 0x00026800U);
    r_rsip_func_sub024(0x0000240bU, 0x00008c00U, 0x00000003U, 0x0000b440U);
    r_rsip_func_sub024(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

    r_rsip_func_sub016(0x81010040U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x000008a5U);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub001(0x00400005U);

        WR1_PROG(REG_1600H, 0x00002ca0U);

        static const uint32_t Param_func083_func101_004[] =
        {
            BSWAP_32BIG_C(0x007ba068U), BSWAP_32BIG_C(0xf1369610U), BSWAP_32BIG_C(0x1b6cbcc6U), BSWAP_32BIG_C(
                0xa9a88bbeU),
        };
        r_rsip_func101(Param_func083_func101_004);
    }

    r_rsip_func_sub011(0x38000845U);

    WAIT_STS(REG_2030H, 4, 1);

    WAIT_STS(REG_1828H, 6, 0);
    WR1_PROG(REG_143CH, 0x00000400U);
    WR1_PROG(REG_1824H, 0x00000000U);
    r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1608H, 0x8084001eU);
    r_rsip_func_sub001(0x03410011U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
