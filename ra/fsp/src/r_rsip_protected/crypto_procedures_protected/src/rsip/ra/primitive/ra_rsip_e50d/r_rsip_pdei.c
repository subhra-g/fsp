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

rsip_ret_t r_rsip_pdei (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00de0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x000000deU);

    static const uint32_t Param_pdei_func101_001[] =
    {
        BSWAP_32BIG_C(0xa72b0ebeU), BSWAP_32BIG_C(0xb85e7ba8U), BSWAP_32BIG_C(0xd9d8bf72U), BSWAP_32BIG_C(0x13dd289fU),
    };
    r_rsip_func101(Param_pdei_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000eU);

    r_rsip_func_sub003(0x800103a0U, 0x000000deU);

    static const uint32_t Param_pdei_func101_002[] =
    {
        BSWAP_32BIG_C(0xe15be2c9U), BSWAP_32BIG_C(0x3373c131U), BSWAP_32BIG_C(0x8e1f4ab8U), BSWAP_32BIG_C(0x8d1f3b8bU),
    };
    r_rsip_func101(Param_pdei_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000063c2U, 0x40001800U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pdei_func100_001[] =
    {
        BSWAP_32BIG_C(0x43800998U), BSWAP_32BIG_C(0x69e08b0cU), BSWAP_32BIG_C(0x40beec77U), BSWAP_32BIG_C(0xc1494116U),
    };
    r_rsip_func100(Param_pdei_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdei_func102_001[] =
        {
            BSWAP_32BIG_C(0x3332b328U), BSWAP_32BIG_C(0x80c3c4b2U), BSWAP_32BIG_C(0xe5756d36U), BSWAP_32BIG_C(
                0x960fbf1aU),
        };
        r_rsip_func102(Param_pdei_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x30300010U);

        r_rsip_func_sub024(0x00005fc2U, 0x40001700U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10a00000U);
        for (iLoop = 0U; iLoop < 96U; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
            iLoop = iLoop + 8U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x3030000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x3030000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x3030000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pdei_func100_002[] =
        {
            BSWAP_32BIG_C(0xb44b0ea7U), BSWAP_32BIG_C(0xcbbfcec1U), BSWAP_32BIG_C(0x112dd7adU), BSWAP_32BIG_C(
                0xfb543b6aU),
        };
        r_rsip_func100(Param_pdei_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdei_func102_002[] =
            {
                BSWAP_32BIG_C(0x0e53e8ebU), BSWAP_32BIG_C(0x27a178ecU), BSWAP_32BIG_C(0xcb0dbf93U), BSWAP_32BIG_C(
                    0x8304037cU),
            };
            r_rsip_func102(Param_pdei_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdei_func100_003[] =
            {
                BSWAP_32BIG_C(0xc65b5129U), BSWAP_32BIG_C(0x784ab9efU), BSWAP_32BIG_C(0x20296f08U), BSWAP_32BIG_C(
                    0x233e0afdU),
            };
            r_rsip_func100(Param_pdei_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0130000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000bffU, 0x0000b400U, 0x00000060U);

            WR1_PROG(REG_1404H, 0x16b80000U);

            for (iLoop = 0U; iLoop < 96U; )
            {
                r_rsip_func_sub022(0x00000bdeU, 0x34202be0U, 0x2000d3c0U);

                r_rsip_func_sub014(0x00007c1eU, 0x00602000U);

                static const uint32_t Param_pdei_func100_004[] =
                {
                    BSWAP_32BIG_C(0xfb7cc304U), BSWAP_32BIG_C(0x97098f0eU), BSWAP_32BIG_C(0x1f9b6eddU), BSWAP_32BIG_C(
                        0xe0cf1720U),
                };
                r_rsip_func100(Param_pdei_func100_004);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                static const uint32_t Param_pdei_func101_003[] =
                {
                    BSWAP_32BIG_C(0xda1fb4bcU), BSWAP_32BIG_C(0xba7fa846U), BSWAP_32BIG_C(0x9165305fU), BSWAP_32BIG_C(
                        0xe77d00a3U),
                };
                r_rsip_func101(Param_pdei_func101_003);
                iLoop = iLoop + 8U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_pdei_func100_005[] =
            {
                BSWAP_32BIG_C(0xef5dfa62U), BSWAP_32BIG_C(0x47301741U), BSWAP_32BIG_C(0xb5b8485bU), BSWAP_32BIG_C(
                    0x668e895fU),
            };
            r_rsip_func100(Param_pdei_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pdei_func101_004[] =
            {
                BSWAP_32BIG_C(0x5d119513U), BSWAP_32BIG_C(0xa3bf7607U), BSWAP_32BIG_C(0x7d9e6c6eU), BSWAP_32BIG_C(
                    0x28dde1cfU),
            };
            r_rsip_func101(Param_pdei_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
