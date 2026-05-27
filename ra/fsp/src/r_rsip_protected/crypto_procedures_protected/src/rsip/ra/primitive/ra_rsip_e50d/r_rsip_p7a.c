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

rsip_ret_t r_rsip_p7a (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    r_rsip_func_sub029(0x007a0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000007aU);

    static const uint32_t Param_p7a_func101_001[] =
    {
        BSWAP_32BIG_C(0x1041a559U), BSWAP_32BIG_C(0x001550c2U), BSWAP_32BIG_C(0x561de6a0U), BSWAP_32BIG_C(0xd3f0da52U),
    };
    r_rsip_func101(Param_p7a_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    r_rsip_func_sub003(0x800103a0U, 0x0000007aU);

    static const uint32_t Param_p7a_func101_002[] =
    {
        BSWAP_32BIG_C(0x8b2e6dd2U), BSWAP_32BIG_C(0x65094f88U), BSWAP_32BIG_C(0x7a17a94dU), BSWAP_32BIG_C(0xb0dc0a02U),
    };
    r_rsip_func101(Param_p7a_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x0000bfc2U, 0x40001700U, 0xf7009d07U);

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

    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);

    WR1_PROG(REG_1404H, 0x12a80000U);
    for (iLoop = 96U; iLoop < 192U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p7a_func100_001[] =
    {
        BSWAP_32BIG_C(0x6531aedaU), BSWAP_32BIG_C(0x18385a06U), BSWAP_32BIG_C(0x1be81a92U), BSWAP_32BIG_C(0x75b087f3U),
    };
    r_rsip_func100(Param_p7a_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7a_func102_001[] =
        {
            BSWAP_32BIG_C(0x11a972caU), BSWAP_32BIG_C(0x69b98d84U), BSWAP_32BIG_C(0x87f03242U), BSWAP_32BIG_C(
                0xaaa3befeU),
        };
        r_rsip_func102(Param_p7a_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
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

        static const uint32_t Param_p7a_func100_002[] =
        {
            BSWAP_32BIG_C(0x6bc74da0U), BSWAP_32BIG_C(0xd569db2fU), BSWAP_32BIG_C(0xe399af50U), BSWAP_32BIG_C(
                0x480e4427U),
        };
        r_rsip_func100(Param_p7a_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7a_func102_002[] =
            {
                BSWAP_32BIG_C(0x0c497a63U), BSWAP_32BIG_C(0xad71243cU), BSWAP_32BIG_C(0x07d99793U), BSWAP_32BIG_C(
                    0x2b77c7c2U),
            };
            r_rsip_func102(Param_p7a_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7a_func100_003[] =
            {
                BSWAP_32BIG_C(0xbb8a9004U), BSWAP_32BIG_C(0x90145d93U), BSWAP_32BIG_C(0x7b85bd65U), BSWAP_32BIG_C(
                    0x46994f37U),
            };
            r_rsip_func100(Param_p7a_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x30300000U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000bffU, 0x0000b400U, 0x00000060U);

            WR1_PROG(REG_1404H, 0x16b80000U);

            for (iLoop = 0U; iLoop < 96U; )
            {
                r_rsip_func_sub022(0x00000bdeU, 0x34202be0U, 0x2000d3c0U);

                r_rsip_func_sub014(0x00007c1eU, 0x00602000U);

                static const uint32_t Param_p7a_func100_004[] =
                {
                    BSWAP_32BIG_C(0x337a3220U), BSWAP_32BIG_C(0xdeeed72aU), BSWAP_32BIG_C(0xe100271cU), BSWAP_32BIG_C(
                        0xe9a9a698U),
                };
                r_rsip_func100(Param_p7a_func100_004);
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

                static const uint32_t Param_p7a_func101_003[] =
                {
                    BSWAP_32BIG_C(0xb49e12c7U), BSWAP_32BIG_C(0x5d3ba4aaU), BSWAP_32BIG_C(0x563d32d1U), BSWAP_32BIG_C(
                        0xc838de88U),
                };
                r_rsip_func101(Param_p7a_func101_003);
                iLoop = iLoop + 8U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p7a_func100_005[] =
            {
                BSWAP_32BIG_C(0xfeee56e5U), BSWAP_32BIG_C(0xa84dd085U), BSWAP_32BIG_C(0x1a7573f9U), BSWAP_32BIG_C(
                    0xbfd26526U),
            };
            r_rsip_func100(Param_p7a_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p7a_func102_003[] =
            {
                BSWAP_32BIG_C(0x4f8a2893U), BSWAP_32BIG_C(0x59f837d4U), BSWAP_32BIG_C(0xa451f922U), BSWAP_32BIG_C(
                    0xb6162953U),
            };
            r_rsip_func102(Param_p7a_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
