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

rsip_ret_t r_rsip_p51i (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00510001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005101U);

    static const uint32_t Param_p51i_func101_001[] =
    {
        BSWAP_32BIG_C(0xcf827ef0U), BSWAP_32BIG_C(0x46dcbf26U), BSWAP_32BIG_C(0xaf886714U), BSWAP_32BIG_C(0xb3927569U),
    };
    r_rsip_func101(Param_p51i_func101_001);
    r_rsip_func043();

    r_rsip_func077();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005101U);

    static const uint32_t Param_p51i_func101_002[] =
    {
        BSWAP_32BIG_C(0x9f904d75U), BSWAP_32BIG_C(0x39e120e8U), BSWAP_32BIG_C(0x1257ce9aU), BSWAP_32BIG_C(0xa8e5867bU),
    };
    r_rsip_func101(Param_p51i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x000017c2U, 0x40000500U, 0xe8009107U);

    r_rsip_func_sub026(0x0000b420U, 0x00000060U, 0x80980001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    r_rsip_func_sub001(0x03420031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p51i_func100_001[] =
    {
        BSWAP_32BIG_C(0x81ce3c2fU), BSWAP_32BIG_C(0x00d63520U), BSWAP_32BIG_C(0x4bc21c04U), BSWAP_32BIG_C(0x14e139f0U),
    };
    r_rsip_func100(Param_p51i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p51i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc7808741U), BSWAP_32BIG_C(0x231cfb41U), BSWAP_32BIG_C(0x1738c005U), BSWAP_32BIG_C(
                0x15018108U),
        };
        r_rsip_func102(Param_p51i_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x808c001fU);
        for (iLoop = 0U; iLoop < 12U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x00000200U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x818c001eU);
        r_rsip_func_sub001(0x00890031U);

        r_rsip_func_sub026(0x0000b7c0U, 0x00000100U, 0x808c001eU);
        r_rsip_func_sub001(0x03420031U);

        r_rsip_func_sub003(0x000000a7U, 0x80010360U, 0x00000051U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p51i_func100_002[] =
        {
            BSWAP_32BIG_C(0xd54e8d33U), BSWAP_32BIG_C(0xb7d72cceU), BSWAP_32BIG_C(0x032bdae4U), BSWAP_32BIG_C(
                0x7c7953d1U),
        };
        r_rsip_func100(Param_p51i_func100_002);
        r_rsip_func027(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

        WR1_PROG(REG_1404H, 0x19000000U);
        r_rsip_func_sub008(0x000017c2U, 0x00000500U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x19500000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x11d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0606000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p51i_func100_003[] =
        {
            BSWAP_32BIG_C(0xf0351567U), BSWAP_32BIG_C(0x84420d00U), BSWAP_32BIG_C(0xa3fbe4efU), BSWAP_32BIG_C(
                0xe10ce2a3U),
        };
        r_rsip_func100(Param_p51i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p51i_func101_003[] =
            {
                BSWAP_32BIG_C(0x6e784953U), BSWAP_32BIG_C(0x76d334f5U), BSWAP_32BIG_C(0x00a92279U), BSWAP_32BIG_C(
                    0x64f24229U),
            };
            r_rsip_func101(Param_p51i_func101_003);
        }
        else
        {
            static const uint32_t Param_p51i_func100_004[] =
            {
                BSWAP_32BIG_C(0x52eb7ad5U), BSWAP_32BIG_C(0x9dd2115fU), BSWAP_32BIG_C(0xb9d376bcU), BSWAP_32BIG_C(
                    0xe34ccd2dU),
            };
            r_rsip_func100(Param_p51i_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0606000aU);

            r_rsip_func_sub022(0x00000980U, 0x000001b0U, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);

            r_rsip_func_sub037(0x0606000fU, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub033(0x10e00000U, 0x00000bffU, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x06060002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c00031U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x06060004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002b8U, 0x06060009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x06060009U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1608H, 0x818c0001U);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a00U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10e00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a38U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p51i_func100_005[] =
            {
                BSWAP_32BIG_C(0xa2ca9bceU), BSWAP_32BIG_C(0x1987f549U), BSWAP_32BIG_C(0xbd6efaeaU), BSWAP_32BIG_C(
                    0xedddf264U),
            };
            r_rsip_func100(Param_p51i_func100_005);
            r_rsip_func028(InData_DomainParam);

            r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000af0U, 0x06060009U);

            r_rsip_func_sub002(0x00000218U, 0x00000160U, 0x00000b28U, 0x06060009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x06060009U);

            r_rsip_func_sub002(0x00000af0U, 0x00000a00U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a00U, 0x00000af0U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b28U, 0x00000a38U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a38U, 0x00000b28U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p51i_func100_006[] =
            {
                BSWAP_32BIG_C(0xa0b17a17U), BSWAP_32BIG_C(0xc65d53a0U), BSWAP_32BIG_C(0xef22760fU), BSWAP_32BIG_C(
                    0x859e8c99U),
            };
            r_rsip_func100(Param_p51i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p51i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xb88dd5a4U), BSWAP_32BIG_C(0x4aea1022U), BSWAP_32BIG_C(0x18eb4832U), BSWAP_32BIG_C(
                        0xde5a957fU),
                };
                r_rsip_func101(Param_p51i_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x06060014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p51i_func101_005[] =
                {
                    BSWAP_32BIG_C(0x06d81f9dU), BSWAP_32BIG_C(0x3320787dU), BSWAP_32BIG_C(0x456ba820U), BSWAP_32BIG_C(
                        0xa91bf37dU),
                };
                r_rsip_func101(Param_p51i_func101_005);
            }

            r_rsip_func_sub044(0x00000821U, 0x14500000U, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            r_rsip_func_sub034(0x0000a420U, 0x00000050U, 0x13100000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 12U; iLoop++)
            {
                r_rsip_func_sub024(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub025(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub024(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0002dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p51i_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x67744cbeU), BSWAP_32BIG_C(0x2480d621U), BSWAP_32BIG_C(0x50803b7aU),
                        BSWAP_32BIG_C(0xfb8deaffU),
                    };
                    r_rsip_func100(Param_p51i_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p51i_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xca659dccU), BSWAP_32BIG_C(0xf0b5f902U), BSWAP_32BIG_C(0x570c61dfU),
                            BSWAP_32BIG_C(0x530022fdU),
                        };
                        r_rsip_func101(Param_p51i_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p51i_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xe40b84d4U), BSWAP_32BIG_C(0xf78d7831U), BSWAP_32BIG_C(0x1f32312bU),
                            BSWAP_32BIG_C(0xf2882d86U),
                        };
                        r_rsip_func101(Param_p51i_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p51i_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xcbe3662dU), BSWAP_32BIG_C(0xaf1273ebU), BSWAP_32BIG_C(0xa9318fbaU),
                        BSWAP_32BIG_C(0x4546aafcU),
                    };
                    r_rsip_func100(Param_p51i_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p51i_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x821a8dd5U), BSWAP_32BIG_C(0x417994dbU), BSWAP_32BIG_C(0x3f18f054U),
                            BSWAP_32BIG_C(0x0b397a78U),
                        };
                        r_rsip_func100(Param_p51i_func100_009);

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub001(0x00c00031U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x00000a00U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a38U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xb0b12ad4U), BSWAP_32BIG_C(0x36b007a3U), BSWAP_32BIG_C(0x6942a78aU),
                                BSWAP_32BIG_C(0x77f1f042U),
                            };
                            r_rsip_func101(Param_p51i_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000af0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b28U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x7c03f7f5U), BSWAP_32BIG_C(0x59b6ad56U), BSWAP_32BIG_C(0x4b55cb17U),
                                BSWAP_32BIG_C(0xc6b6ec8cU),
                            };
                            r_rsip_func101(Param_p51i_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000be0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c18U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_010[] =
                            {
                                BSWAP_32BIG_C(0xc473bf2aU), BSWAP_32BIG_C(0x46a42e51U), BSWAP_32BIG_C(0xa4d217daU),
                                BSWAP_32BIG_C(0xbfb671d1U),
                            };
                            r_rsip_func101(Param_p51i_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0002dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p51i_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x0355abfbU), BSWAP_32BIG_C(0x18e483aaU), BSWAP_32BIG_C(0x161a8e9fU),
                            BSWAP_32BIG_C(0xf5967a10U),
                        };
                        r_rsip_func100(Param_p51i_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p51i_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x23376590U), BSWAP_32BIG_C(0xcd87c03dU), BSWAP_32BIG_C(0x1a528762U),
                                BSWAP_32BIG_C(0x4acd41e8U),
                            };
                            r_rsip_func100(Param_p51i_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001e0U, 0x00000410U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000410U, 0x000001e0U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000218U, 0x00000448U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000448U, 0x00000218U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p51i_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xff680518U), BSWAP_32BIG_C(0x150684b3U), BSWAP_32BIG_C(0x66b68592U),
                                    BSWAP_32BIG_C(0x11e68d29U),
                                };
                                r_rsip_func100(Param_p51i_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub022(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p51i_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x1ab4a112U), BSWAP_32BIG_C(0xac4ff13aU), BSWAP_32BIG_C(
                                            0x73d9c968U),           BSWAP_32BIG_C(0xbccf389eU),
                                    };
                                    r_rsip_func101(Param_p51i_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p51i_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x08207576U), BSWAP_32BIG_C(0xb0876031U), BSWAP_32BIG_C(
                                            0xbe02366aU),           BSWAP_32BIG_C(0x98d40b69U),
                                    };
                                    r_rsip_func101(Param_p51i_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_p51i_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x494d6ab3U), BSWAP_32BIG_C(0x2b0419b8U), BSWAP_32BIG_C(0xb6413d30U),
                                    BSWAP_32BIG_C(0x85fb4c3dU),
                                };
                                r_rsip_func101(Param_p51i_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11300000U);
                            r_rsip_func_sub001(0x00c00031U);

                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x000001e0U, 0x06060009U);

                            r_rsip_func_sub002(0x00000448U, 0x00000160U, 0x00000218U, 0x06060009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);

                            static const uint32_t Param_p51i_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x43db0358U), BSWAP_32BIG_C(0x2421207aU), BSWAP_32BIG_C(0x538c2a41U),
                                BSWAP_32BIG_C(0xd23b7161U),
                            };
                            r_rsip_func101(Param_p51i_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p51i_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x85a97f2cU), BSWAP_32BIG_C(0x98542558U), BSWAP_32BIG_C(0x87dc8542U),
                            BSWAP_32BIG_C(0xadfdcfe9U),
                        };
                        r_rsip_func101(Param_p51i_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p51i_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xda515a95U), BSWAP_32BIG_C(0x0ae54391U), BSWAP_32BIG_C(0xf971d725U),
                        BSWAP_32BIG_C(0x12effeadU),
                    };
                    r_rsip_func101(Param_p51i_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p51i_func101_017[] =
                {
                    BSWAP_32BIG_C(0xcf82e310U), BSWAP_32BIG_C(0x80400a11U), BSWAP_32BIG_C(0xf626f417U), BSWAP_32BIG_C(
                        0x41ddf4b9U),
                };
                r_rsip_func101(Param_p51i_func101_017);
            }

            r_rsip_func_sub006(0x38008820U, 0x0000000cU, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x12700000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p51i_func100_013[] =
            {
                BSWAP_32BIG_C(0xa9c2f93bU), BSWAP_32BIG_C(0xa56e6923U), BSWAP_32BIG_C(0xf246bba2U), BSWAP_32BIG_C(
                    0x901afc75U),
            };
            r_rsip_func100(Param_p51i_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p51i_func101_018[] =
                {
                    BSWAP_32BIG_C(0xef29384aU), BSWAP_32BIG_C(0x0700f5eaU), BSWAP_32BIG_C(0xd0de216aU), BSWAP_32BIG_C(
                        0x9d78b6ddU),
                };
                r_rsip_func101(Param_p51i_func101_018);
            }
            else
            {
                static const uint32_t Param_p51i_func100_014[] =
                {
                    BSWAP_32BIG_C(0x6d519652U), BSWAP_32BIG_C(0x80fee761U), BSWAP_32BIG_C(0xc5185804U), BSWAP_32BIG_C(
                        0x22eb277fU),
                };
                r_rsip_func100(Param_p51i_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x000001e0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p51i_func100_015[] =
                {
                    BSWAP_32BIG_C(0x7c89e1c7U), BSWAP_32BIG_C(0x3d2e5e0bU), BSWAP_32BIG_C(0x379e89ddU), BSWAP_32BIG_C(
                        0xabea5a9dU),
                };
                r_rsip_func100(Param_p51i_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p51i_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x6d627810U), BSWAP_32BIG_C(0x35e43526U), BSWAP_32BIG_C(0x40c4f31aU),
                        BSWAP_32BIG_C(0xa2d2783dU),
                    };
                    r_rsip_func101(Param_p51i_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_p51i_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x7e0febccU), BSWAP_32BIG_C(0x8ecc0d2cU), BSWAP_32BIG_C(0x0866f419U),
                        BSWAP_32BIG_C(0x5cc06743U),
                    };
                    r_rsip_func101(Param_p51i_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p51i_func100_016[] =
        {
            BSWAP_32BIG_C(0xb3399aa0U), BSWAP_32BIG_C(0x0acd36d6U), BSWAP_32BIG_C(0x91809d58U), BSWAP_32BIG_C(
                0x950b891bU),
        };
        r_rsip_func100(Param_p51i_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p51i_func102_002[] =
            {
                BSWAP_32BIG_C(0xf8895b73U), BSWAP_32BIG_C(0x9bbefb9aU), BSWAP_32BIG_C(0x3d118738U), BSWAP_32BIG_C(
                    0xae1b1a1aU),
            };
            r_rsip_func102(Param_p51i_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            r_rsip_func_sub026(0x0000b7c0U, 0x00000100U, 0x818c001eU);
            r_rsip_func_sub001(0x00890031U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x808c001eU);
            r_rsip_func_sub001(0x03420031U);

            static const uint32_t Param_p51i_func101_021[] =
            {
                BSWAP_32BIG_C(0x89d8d21fU), BSWAP_32BIG_C(0x25ab1dccU), BSWAP_32BIG_C(0x818dc7ceU), BSWAP_32BIG_C(
                    0x44dea2f9U),
            };
            r_rsip_func101(Param_p51i_func101_021);

            return RSIP_RET_PASS;
        }
    }
}
