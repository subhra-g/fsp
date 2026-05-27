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

rsip_ret_t r_rsip_pedi (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00ed0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x000000edU);

    static const uint32_t Param_pedi_func101_001[] =
    {
        BSWAP_32BIG_C(0x9f23fd4eU), BSWAP_32BIG_C(0x6f03cee7U), BSWAP_32BIG_C(0x917de89aU), BSWAP_32BIG_C(0x4aea1f6eU),
    };
    r_rsip_func101(Param_pedi_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000cU);

    r_rsip_func_sub003(0x800103a0U, 0x000000edU);

    static const uint32_t Param_pedi_func101_002[] =
    {
        BSWAP_32BIG_C(0x03d9d309U), BSWAP_32BIG_C(0x0d16f3d8U), BSWAP_32BIG_C(0xb14aba02U), BSWAP_32BIG_C(0x69050e5eU),
    };
    r_rsip_func101(Param_pedi_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000043c2U, 0x40000f00U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[65]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[69]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pedi_func100_001[] =
    {
        BSWAP_32BIG_C(0xafab33c2U), BSWAP_32BIG_C(0x1ce58968U), BSWAP_32BIG_C(0x94e67c06U), BSWAP_32BIG_C(0xf2c7cd84U),
    };
    r_rsip_func100(Param_pedi_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pedi_func102_001[] =
        {
            BSWAP_32BIG_C(0x767436b4U), BSWAP_32BIG_C(0x0cff882bU), BSWAP_32BIG_C(0xbe86aae9U), BSWAP_32BIG_C(
                0x8b778211U),
        };
        r_rsip_func102(Param_pedi_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x20200010U);

        r_rsip_func_sub024(0x00003fc2U, 0x40000f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x11200000U);
        for (iLoop = 0U; iLoop < 64U; )
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

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pedi_func100_002[] =
        {
            BSWAP_32BIG_C(0x6508fdd6U), BSWAP_32BIG_C(0xc154b0c2U), BSWAP_32BIG_C(0x4cb956fcU), BSWAP_32BIG_C(
                0x5a02a3b9U),
        };
        r_rsip_func100(Param_pedi_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pedi_func102_002[] =
            {
                BSWAP_32BIG_C(0xb2deca3bU), BSWAP_32BIG_C(0x8ff98efdU), BSWAP_32BIG_C(0x82ecc779U), BSWAP_32BIG_C(
                    0xbe0d05c8U),
            };
            r_rsip_func102(Param_pedi_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pedi_func100_003[] =
            {
                BSWAP_32BIG_C(0x4657e487U), BSWAP_32BIG_C(0xbb07750cU), BSWAP_32BIG_C(0x19dd8440U), BSWAP_32BIG_C(
                    0xa2816561U),
            };
            r_rsip_func100(Param_pedi_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0120000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000bffU, 0x0000b400U, 0x00000040U);

            WR1_PROG(REG_1404H, 0x17380000U);

            for (iLoop = 0U; iLoop < 64U; )
            {
                r_rsip_func_sub022(0x00000bdeU, 0x34202be0U, 0x2000d3c0U);

                r_rsip_func_sub014(0x00007c1eU, 0x00602000U);

                static const uint32_t Param_pedi_func100_004[] =
                {
                    BSWAP_32BIG_C(0x8d72c612U), BSWAP_32BIG_C(0x3518f82aU), BSWAP_32BIG_C(0xc2a6199aU), BSWAP_32BIG_C(
                        0xf9b1526bU),
                };
                r_rsip_func100(Param_pedi_func100_004);
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

                static const uint32_t Param_pedi_func101_003[] =
                {
                    BSWAP_32BIG_C(0x7a21c317U), BSWAP_32BIG_C(0x4afd494bU), BSWAP_32BIG_C(0x908e728aU), BSWAP_32BIG_C(
                        0xe0c73435U),
                };
                r_rsip_func101(Param_pedi_func101_003);
                iLoop = iLoop + 8U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_pedi_func100_005[] =
            {
                BSWAP_32BIG_C(0x631e2cdaU), BSWAP_32BIG_C(0x301bae2fU), BSWAP_32BIG_C(0x953739a6U), BSWAP_32BIG_C(
                    0xec51202bU),
            };
            r_rsip_func100(Param_pedi_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pedi_func101_004[] =
            {
                BSWAP_32BIG_C(0x09318df3U), BSWAP_32BIG_C(0x918fec60U), BSWAP_32BIG_C(0x743f1540U), BSWAP_32BIG_C(
                    0xb3a92f8bU),
            };
            r_rsip_func101(Param_pedi_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
