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

rsip_ret_t r_rsip_p8f (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_WrappedKeyIndex[],
                       uint32_t       OutData_Text[],
                       uint32_t       KEY_INDEX_SIZE,
                       uint32_t       WRAPPED_KEY_SIZE)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B4H, 0x0000001dU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x008f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000001c7U, 0x80020100U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_WrappedKeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00003409U);

    r_rsip_func_sub006(0x3420a900U, 0x00000002U, 0x00A60000U);

    r_rsip_func_sub006(0x3420a800U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_p8f_func100_001[] =
    {
        BSWAP_32BIG_C(0x028a0cbbU), BSWAP_32BIG_C(0x40697bf1U), BSWAP_32BIG_C(0x1816f508U), BSWAP_32BIG_C(0x6c044d0eU),
    };
    r_rsip_func100(Param_p8f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p8f_func102_001[] =
        {
            BSWAP_32BIG_C(0x48e2ca3cU), BSWAP_32BIG_C(0xba015e40U), BSWAP_32BIG_C(0xeece954bU), BSWAP_32BIG_C(
                0x09e53f29U),
        };
        r_rsip_func102(Param_p8f_func102_001);
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x800103a0U, 0x00008f01U);

        static const uint32_t Param_p8f_func101_001[] =
        {
            BSWAP_32BIG_C(0xe2c5515dU), BSWAP_32BIG_C(0x629ac68bU), BSWAP_32BIG_C(0x9b8282ccU), BSWAP_32BIG_C(
                0x3fd2c138U),
        };
        r_rsip_func101(Param_p8f_func101_001);
        r_rsip_func043();

        r_rsip_func_sub017(0x38000d08U, 0x00260000U);

        static const uint32_t Param_p8f_func100_002[] =
        {
            BSWAP_32BIG_C(0x0e2189e0U), BSWAP_32BIG_C(0x1e75781cU), BSWAP_32BIG_C(0x6def5d24U), BSWAP_32BIG_C(
                0x87f14c42U),
        };
        r_rsip_func100(Param_p8f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub003(0x800103a0U, 0x00008f01U);

            static const uint32_t Param_p8f_func101_002[] =
            {
                BSWAP_32BIG_C(0x053bef49U), BSWAP_32BIG_C(0x8641d4b2U), BSWAP_32BIG_C(0xb6e32ec2U), BSWAP_32BIG_C(
                    0x58ef0673U),
            };
            r_rsip_func101(Param_p8f_func101_002);
            r_rsip_func044();

            static const uint32_t Param_p8f_func100_003[] =
            {
                BSWAP_32BIG_C(0x761b584cU), BSWAP_32BIG_C(0x0539381bU), BSWAP_32BIG_C(0x7adc43e3U), BSWAP_32BIG_C(
                    0x0b25fb8eU),
            };
            r_rsip_func100(Param_p8f_func100_003);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_182CH, 0x00000000U);

            static const uint32_t Param_p8f_func101_003[] =
            {
                BSWAP_32BIG_C(0x195a4dc1U), BSWAP_32BIG_C(0x7b015d19U), BSWAP_32BIG_C(0xa7b9599fU), BSWAP_32BIG_C(
                    0x683928c1U),
            };
            r_rsip_func101(Param_p8f_func101_003);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub003(0x800103a0U, 0x00008f02U);

            static const uint32_t Param_p8f_func101_004[] =
            {
                BSWAP_32BIG_C(0x47736210U), BSWAP_32BIG_C(0x3e1ae5bcU), BSWAP_32BIG_C(0xdc81757aU), BSWAP_32BIG_C(
                    0xfdd99ba4U),
            };
            r_rsip_func101(Param_p8f_func101_004);
            r_rsip_func044();

            static const uint32_t Param_p8f_func100_004[] =
            {
                BSWAP_32BIG_C(0xc2c71bf6U), BSWAP_32BIG_C(0x795d20c4U), BSWAP_32BIG_C(0x18121a7cU), BSWAP_32BIG_C(
                    0xec06ff95U),
            };
            r_rsip_func100(Param_p8f_func100_004);
            r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            static const uint32_t Param_p8f_func100_005[] =
            {
                BSWAP_32BIG_C(0x58e3d241U), BSWAP_32BIG_C(0x312e4e4eU), BSWAP_32BIG_C(0x40f10a05U), BSWAP_32BIG_C(
                    0xf21f15feU),
            };
            r_rsip_func100(Param_p8f_func100_005);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_182CH, 0x40000000U);

            static const uint32_t Param_p8f_func101_005[] =
            {
                BSWAP_32BIG_C(0x49aedde1U), BSWAP_32BIG_C(0x8b816fdaU), BSWAP_32BIG_C(0xcae25c76U), BSWAP_32BIG_C(
                    0x70a88ae5U),
            };
            r_rsip_func101(Param_p8f_func101_005);
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p8f_func100_006[] =
        {
            BSWAP_32BIG_C(0xfdb7088dU), BSWAP_32BIG_C(0x93fc06b3U), BSWAP_32BIG_C(0x07fc0f7eU), BSWAP_32BIG_C(
                0x5eb38b57U),
        };
        r_rsip_func100(Param_p8f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p8f_func102_002[] =
            {
                BSWAP_32BIG_C(0x8d4ff5f1U), BSWAP_32BIG_C(0xd2545684U), BSWAP_32BIG_C(0x6b56ebe0U), BSWAP_32BIG_C(
                    0x221d6b1aU),
            };
            r_rsip_func102(Param_p8f_func102_002);
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_1600H, 0x000035c7U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_WrappedKeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x00008f02U);

            static const uint32_t Param_p8f_func101_006[] =
            {
                BSWAP_32BIG_C(0xb62b748dU), BSWAP_32BIG_C(0x8fbd6610U), BSWAP_32BIG_C(0xa9c91c45U), BSWAP_32BIG_C(
                    0xc9240f9eU),
            };
            r_rsip_func101(Param_p8f_func101_006);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x000034e6U);

            r_rsip_func_sub003(0x800103a0U, 0x00008f03U);

            static const uint32_t Param_p8f_func101_007[] =
            {
                BSWAP_32BIG_C(0x395b3e5bU), BSWAP_32BIG_C(0x1d52f6f8U), BSWAP_32BIG_C(0x5f34bef1U), BSWAP_32BIG_C(
                    0x40236ddfU),
            };
            r_rsip_func101(Param_p8f_func101_007);
            r_rsip_func044();

            WR1_PROG(REG_1600H, 0x000034eeU);

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub004(0x08000054U, 0x00000000U);

            r_rsip_func_sub021(0x0000b7e0U, 0x00000008U, 0x0000b780U, 0x00000010U);

            r_rsip_func_sub021(0x00000bdeU, 0x0000b760U, 0x00000004U, 0x0000a8e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 1]);

                WR1_PROG(REG_1608H, 0x8084001fU);
                r_rsip_func_sub001(0x03420011U);

                WR1_PROG(REG_1600H, 0x000027fcU);

                WR1_PROG(REG_1600H, 0x000027dbU);

                static const uint32_t Param_p8f_func101_008[] =
                {
                    BSWAP_32BIG_C(0x7f5cec79U), BSWAP_32BIG_C(0x2be2151fU), BSWAP_32BIG_C(0xabf0c984U), BSWAP_32BIG_C(
                        0x7f58aef6U),
                };
                r_rsip_func101(Param_p8f_func101_008);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub011(0x38000bc7U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p8f_func100_007[] =
            {
                BSWAP_32BIG_C(0xc7a1ed92U), BSWAP_32BIG_C(0xcfddade1U), BSWAP_32BIG_C(0x3a9c19e4U), BSWAP_32BIG_C(
                    0x42d6de77U),
            };
            r_rsip_func100(Param_p8f_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p8f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x329b5189U), BSWAP_32BIG_C(0x9431dac3U), BSWAP_32BIG_C(0x6235cc44U), BSWAP_32BIG_C(
                        0x234f64deU),
                };
                r_rsip_func102(Param_p8f_func102_003);
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub021(0x0000b400U, 0xa6a6a6a6U, 0x00003420U, 0x0000b760U);
                r_rsip_func_sub021(0x00000008U, 0x0000b780U, 0x00000004U, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_1600H, 0x00000bdeU);

                for (jLoop = 0U; jLoop <= 5; jLoop++)
                {
                    WR1_PROG(REG_1600H, 0x000037fbU);

                    WR1_PROG(REG_1600H, 0x00000bbdU);

                    for (iLoop = 1; iLoop <= (WRAPPED_KEY_SIZE - 2) / 2; iLoop++)
                    {
                        WR1_PROG(REG_1824H, 0x0a008105U);
                        WR1_PROG(REG_1608H, 0x81020000U);
                        r_rsip_func_sub001(0x00490009U);
                        WR1_PROG(REG_1608H, 0x8182001fU);
                        r_rsip_func_sub001(0x00490009U);

                        WR1_PROG(REG_1608H, 0x80040000U);
                        r_rsip_func_sub001(0x03410011U);

                        r_rsip_func_sub021(0x00000824U, 0x00003c5fU, 0x000027fcU, 0x00003c7fU);
                        r_rsip_func_sub022(0x000027fcU, 0x00002c80U, 0x00002fa0U);

                        static const uint32_t Param_p8f_func101_009[] =
                        {
                            BSWAP_32BIG_C(0xfd5a860dU), BSWAP_32BIG_C(0x8c14061eU), BSWAP_32BIG_C(0xcfc1d543U),
                            BSWAP_32BIG_C(0x2ab0b6a3U),
                        };
                        r_rsip_func101(Param_p8f_func101_009);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub011(0x38000ba5U);

                    WR1_PROG(REG_1600H, 0x00002fc0U);

                    static const uint32_t Param_p8f_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x23d9c946U), BSWAP_32BIG_C(0x854c9920U), BSWAP_32BIG_C(0xfb74a4cfU),
                        BSWAP_32BIG_C(0x49bd84c7U),
                    };
                    r_rsip_func101(Param_p8f_func101_010);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub006(0x38008bc0U, 0x00000006U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub021(0x00000bffU, 0x00003c1fU, 0x000027fcU, 0x00003c3fU);

                r_rsip_func_sub021(0x00000bffU, 0x00000bdeU, 0x000037a5U, 0x00002fa0U);

                WR1_PROG(REG_1600H, 0x0000b780U);
                WR1_PROG(REG_1600H, 0x00000008U);

                for (iLoop = 0U; iLoop < WRAPPED_KEY_SIZE; )
                {
                    r_rsip_func_sub022(0x000008c6U, 0x34202bddU, 0x2000d0c0U);

                    r_rsip_func_sub014(0x00007c06U, 0x00602000U);

                    static const uint32_t Param_p8f_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xfb11b1c0U), BSWAP_32BIG_C(0xcc3434caU), BSWAP_32BIG_C(0xea166ad2U),
                        BSWAP_32BIG_C(0x88637393U),
                    };
                    r_rsip_func100(Param_p8f_func100_008);
                    r_rsip_func_sub016(0x8182001fU, 0x0000500aU);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);

                    WR1_PROG(REG_1600H, 0x000027fcU);

                    WR1_PROG(REG_1600H, 0x00002fc0U);

                    static const uint32_t Param_p8f_func101_011[] =
                    {
                        BSWAP_32BIG_C(0xf345f53dU), BSWAP_32BIG_C(0xf58ec480U), BSWAP_32BIG_C(0xea093b02U),
                        BSWAP_32BIG_C(0xf5387c5fU),
                    };
                    r_rsip_func101(Param_p8f_func101_011);
                    iLoop = iLoop + 2;
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000bddU);

                static const uint32_t Param_p8f_func102_004[] =
                {
                    BSWAP_32BIG_C(0xb7614d87U), BSWAP_32BIG_C(0x36498aadU), BSWAP_32BIG_C(0x66753f20U), BSWAP_32BIG_C(
                        0xf279371dU),
                };
                r_rsip_func102(Param_p8f_func102_004);
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
