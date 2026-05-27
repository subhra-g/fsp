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

rsip_ret_t r_rsip_p5fi (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub029(0x005f0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00005f01U);

    static const uint32_t Param_p5fi_func101_001[] =
    {
        BSWAP_32BIG_C(0x14f5ff4aU), BSWAP_32BIG_C(0xd670bef1U), BSWAP_32BIG_C(0xf2d71c66U), BSWAP_32BIG_C(0xa02338c3U),
    };
    r_rsip_func101(Param_p5fi_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000020U);

    r_rsip_func_sub003(0x800103a0U, 0x00005f01U);

    static const uint32_t Param_p5fi_func101_002[] =
    {
        BSWAP_32BIG_C(0x852a94f6U), BSWAP_32BIG_C(0x0df68518U), BSWAP_32BIG_C(0x3ba54f3dU), BSWAP_32BIG_C(0x2dba871bU),
    };
    r_rsip_func101(Param_p5fi_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a00001U);
    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[17 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p5fi_func100_001[] =
    {
        BSWAP_32BIG_C(0x86cc11c5U), BSWAP_32BIG_C(0x4c37c1cfU), BSWAP_32BIG_C(0x239e84a6U), BSWAP_32BIG_C(0x960edb12U),
    };
    r_rsip_func100(Param_p5fi_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p5fi_func102_001[] =
        {
            BSWAP_32BIG_C(0xd42abd63U), BSWAP_32BIG_C(0x281b47d9U), BSWAP_32BIG_C(0xb8e26af4U), BSWAP_32BIG_C(
                0x8763ce98U),
        };
        r_rsip_func102(Param_p5fi_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000fc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x8090001fU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub022(0x00000bdeU, 0x0000b7e0U, 0x00000100U);

        WR1_PROG(REG_1A2CH, 0x00000300U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        for (iLoop = 0U; iLoop < 16U; )
        {
            WR1_PROG(REG_1608H, 0x8184001eU);
            r_rsip_func_sub001(0x00890011U);
            WR1_PROG(REG_1608H, 0x8084001fU);
            r_rsip_func_sub001(0x03420011U);

            r_rsip_func_sub021(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x80010360U, 0x0000005fU);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p5fi_func100_002[] =
        {
            BSWAP_32BIG_C(0xe8131870U), BSWAP_32BIG_C(0xff52cbcdU), BSWAP_32BIG_C(0xcb537efbU), BSWAP_32BIG_C(
                0xdaf09b0aU),
        };
        r_rsip_func100(Param_p5fi_func100_002);
        r_rsip_func078(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

        WR1_PROG(REG_1404H, 0x18f00000U);
        r_rsip_func_sub008(0x00001fc2U, 0x00000700U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x19400000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[24]);
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[28]);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x11c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0808000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p5fi_func100_003[] =
        {
            BSWAP_32BIG_C(0xd1fbc162U), BSWAP_32BIG_C(0xe20f739fU), BSWAP_32BIG_C(0xc0602066U), BSWAP_32BIG_C(
                0x215f30eaU),
        };
        r_rsip_func100(Param_p5fi_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p5fi_func101_003[] =
            {
                BSWAP_32BIG_C(0xd5838959U), BSWAP_32BIG_C(0x19bb59c6U), BSWAP_32BIG_C(0x59985b7aU), BSWAP_32BIG_C(
                    0x203e0838U),
            };
            r_rsip_func101(Param_p5fi_func101_003);
        }
        else
        {
            static const uint32_t Param_p5fi_func100_004[] =
            {
                BSWAP_32BIG_C(0xb3995d73U), BSWAP_32BIG_C(0x8d9031e9U), BSWAP_32BIG_C(0x9e6491c6U), BSWAP_32BIG_C(
                    0xa5e779b0U),
            };
            r_rsip_func100(Param_p5fi_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0808000aU);

            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);

            WR1_PROG(REG_1004H, 0x0808000fU);
            r_rsip_func_sub035(0x00010001U);

            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000840U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub030(0x10d00000U, 0x00000bffU, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000160U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x08080002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub001(0x00c00041U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x08080004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002a8U, 0x08080009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x08080009U);

            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1608H, 0x81900001U);
            r_rsip_func_sub001(0x00c90041U);

            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x000009e0U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10d00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a28U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p5fi_func100_005[] =
            {
                BSWAP_32BIG_C(0xe09be6d1U), BSWAP_32BIG_C(0x2242d919U), BSWAP_32BIG_C(0xe7b16682U), BSWAP_32BIG_C(
                    0x8fc18a8eU),
            };
            r_rsip_func100(Param_p5fi_func100_005);
            r_rsip_func079(InData_DomainParam);

            r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000ad0U, 0x08080009U);

            r_rsip_func_sub002(0x00000208U, 0x00000160U, 0x00000b18U, 0x08080009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x08080009U);

            r_rsip_func_sub002(0x00000ad0U, 0x000009e0U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x000009e0U, 0x00000ad0U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b18U, 0x00000a28U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a28U, 0x00000b18U, 0x00000110U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p5fi_func100_006[] =
            {
                BSWAP_32BIG_C(0x9711a114U), BSWAP_32BIG_C(0x442e5613U), BSWAP_32BIG_C(0xd2104118U), BSWAP_32BIG_C(
                    0x802c1395U),
            };
            r_rsip_func100(Param_p5fi_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p5fi_func101_004[] =
                {
                    BSWAP_32BIG_C(0x11b79db5U), BSWAP_32BIG_C(0x1aba9207U), BSWAP_32BIG_C(0x0efe17bfU), BSWAP_32BIG_C(
                        0x369da93eU),
                };
                r_rsip_func101(Param_p5fi_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x08080014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p5fi_func101_005[] =
                {
                    BSWAP_32BIG_C(0x8b485f09U), BSWAP_32BIG_C(0xce2bcdacU), BSWAP_32BIG_C(0xd1480dbeU), BSWAP_32BIG_C(
                        0x69c108a1U),
                };
                r_rsip_func101(Param_p5fi_func101_005);
            }

            WR1_PROG(REG_1600H, 0x00000821U);

            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            r_rsip_func_sub001(0x03430041U);

            r_rsip_func_sub031(0x0000a420U, 0x00000050U, 0x13000000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            r_rsip_func_sub001(0x03430041U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub021(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub022(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0003dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p5fi_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x4304b1c3U), BSWAP_32BIG_C(0x8043e874U), BSWAP_32BIG_C(0x766162beU),
                        BSWAP_32BIG_C(0x9579dacbU),
                    };
                    r_rsip_func100(Param_p5fi_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p5fi_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x79341e0eU), BSWAP_32BIG_C(0x4fc54342U), BSWAP_32BIG_C(0x83f41afdU),
                            BSWAP_32BIG_C(0x9b47de33U),
                        };
                        r_rsip_func101(Param_p5fi_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p5fi_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x14a478c2U), BSWAP_32BIG_C(0xf427bcb2U), BSWAP_32BIG_C(0x92afb93aU),
                            BSWAP_32BIG_C(0xb0971002U),
                        };
                        r_rsip_func101(Param_p5fi_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p5fi_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x30885ff3U), BSWAP_32BIG_C(0x26d5a0adU), BSWAP_32BIG_C(0xe40b1f32U),
                        BSWAP_32BIG_C(0x33a46184U),
                    };
                    r_rsip_func100(Param_p5fi_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p5fi_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x97c381c6U), BSWAP_32BIG_C(0x72d6f91eU), BSWAP_32BIG_C(0xb191e2edU),
                            BSWAP_32BIG_C(0x9b79b148U),
                        };
                        r_rsip_func100(Param_p5fi_func100_009);

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub001(0x00c00041U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009e0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a28U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x37c03066U), BSWAP_32BIG_C(0xc58756deU), BSWAP_32BIG_C(0x6ef8bee4U),
                                BSWAP_32BIG_C(0xeb9d65aaU),
                            };
                            r_rsip_func101(Param_p5fi_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ad0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b18U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xe60eb951U), BSWAP_32BIG_C(0xeaa1cddaU), BSWAP_32BIG_C(0x5abcda3eU),
                                BSWAP_32BIG_C(0x3a8315adU),
                            };
                            r_rsip_func101(Param_p5fi_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bc0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c08U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_010[] =
                            {
                                BSWAP_32BIG_C(0xc1f6e268U), BSWAP_32BIG_C(0x81135f76U), BSWAP_32BIG_C(0x7e8c2439U),
                                BSWAP_32BIG_C(0xd53a4128U),
                            };
                            r_rsip_func101(Param_p5fi_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0003dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p5fi_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x42e0b694U), BSWAP_32BIG_C(0xb92dbe55U), BSWAP_32BIG_C(0x85958a49U),
                            BSWAP_32BIG_C(0xd84a8177U),
                        };
                        r_rsip_func100(Param_p5fi_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p5fi_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x284ed7baU), BSWAP_32BIG_C(0x84998a8fU), BSWAP_32BIG_C(0xb41ad3d5U),
                                BSWAP_32BIG_C(0x9dfcbbf1U),
                            };
                            r_rsip_func100(Param_p5fi_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001c0U, 0x000003f0U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x000003f0U, 0x000001c0U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000208U, 0x00000438U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000438U, 0x00000208U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0808000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p5fi_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xfd2a4a4dU), BSWAP_32BIG_C(0xdbd7f245U), BSWAP_32BIG_C(0xb221a381U),
                                    BSWAP_32BIG_C(0x3e3239eaU),
                                };
                                r_rsip_func100(Param_p5fi_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    WR1_PROG(REG_101CH, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p5fi_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0xb302f2c4U), BSWAP_32BIG_C(0x27371218U), BSWAP_32BIG_C(
                                            0x6aad2245U),           BSWAP_32BIG_C(0xd0ab66dfU),
                                    };
                                    r_rsip_func101(Param_p5fi_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p5fi_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x9bf656f8U), BSWAP_32BIG_C(0x5bb23bd5U), BSWAP_32BIG_C(
                                            0x45135387U),           BSWAP_32BIG_C(0xb6d43e03U),
                                    };
                                    r_rsip_func101(Param_p5fi_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_p5fi_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xe7ccefeaU), BSWAP_32BIG_C(0xc19ee188U), BSWAP_32BIG_C(0x98b43ed0U),
                                    BSWAP_32BIG_C(0x8fa5ac12U),
                                };
                                r_rsip_func101(Param_p5fi_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_func_sub001(0x00c00041U);

                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);

                            static const uint32_t Param_p5fi_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x82d351a8U), BSWAP_32BIG_C(0x71068ad1U), BSWAP_32BIG_C(0x5d88792fU),
                                BSWAP_32BIG_C(0xe21262fcU),
                            };
                            r_rsip_func101(Param_p5fi_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p5fi_func101_015[] =
                        {
                            BSWAP_32BIG_C(0xd899b2e0U), BSWAP_32BIG_C(0x2f4a67ebU), BSWAP_32BIG_C(0x92de9931U),
                            BSWAP_32BIG_C(0x9658b8e4U),
                        };
                        r_rsip_func101(Param_p5fi_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p5fi_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xe3f9fb58U), BSWAP_32BIG_C(0x992b70fcU), BSWAP_32BIG_C(0x2ae296b7U),
                        BSWAP_32BIG_C(0x6704c5e6U),
                    };
                    r_rsip_func101(Param_p5fi_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p5fi_func101_017[] =
                {
                    BSWAP_32BIG_C(0x2074f063U), BSWAP_32BIG_C(0x1a6ec197U), BSWAP_32BIG_C(0x3d14eedcU), BSWAP_32BIG_C(
                        0x2a71438bU),
                };
                r_rsip_func101(Param_p5fi_func101_017);
            }

            r_rsip_func_sub006(0x38008820U, 0x00000010U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x12600000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p5fi_func100_013[] =
            {
                BSWAP_32BIG_C(0xcc7d3a82U), BSWAP_32BIG_C(0xfa8f1b52U), BSWAP_32BIG_C(0xc4377cfaU), BSWAP_32BIG_C(
                    0x4bbc4600U),
            };
            r_rsip_func100(Param_p5fi_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p5fi_func101_018[] =
                {
                    BSWAP_32BIG_C(0x63e9b9feU), BSWAP_32BIG_C(0xfcf0f282U), BSWAP_32BIG_C(0xc7c86e4eU), BSWAP_32BIG_C(
                        0x235cf277U),
                };
                r_rsip_func101(Param_p5fi_func101_018);
            }
            else
            {
                static const uint32_t Param_p5fi_func100_014[] =
                {
                    BSWAP_32BIG_C(0xe24de367U), BSWAP_32BIG_C(0x198b18f1U), BSWAP_32BIG_C(0x394368d8U), BSWAP_32BIG_C(
                        0x96bce89aU),
                };
                r_rsip_func100(Param_p5fi_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x08080004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1014H, 0x000001c0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p5fi_func100_015[] =
                {
                    BSWAP_32BIG_C(0x282a5db5U), BSWAP_32BIG_C(0xaa96282dU), BSWAP_32BIG_C(0xd9c6bb6dU), BSWAP_32BIG_C(
                        0x142f971bU),
                };
                r_rsip_func100(Param_p5fi_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p5fi_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x850ee47cU), BSWAP_32BIG_C(0xc5203495U), BSWAP_32BIG_C(0xdf3995c0U),
                        BSWAP_32BIG_C(0xbdaef5c9U),
                    };
                    r_rsip_func101(Param_p5fi_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_p5fi_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xd4c8e979U), BSWAP_32BIG_C(0x97f1c61aU), BSWAP_32BIG_C(0x9b73d8cbU),
                        BSWAP_32BIG_C(0x5143ff61U),
                    };
                    r_rsip_func101(Param_p5fi_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p5fi_func100_016[] =
        {
            BSWAP_32BIG_C(0x4b66efe5U), BSWAP_32BIG_C(0xb3cffb0bU), BSWAP_32BIG_C(0xd277b0eaU), BSWAP_32BIG_C(
                0xd1a18e8dU),
        };
        r_rsip_func100(Param_p5fi_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p5fi_func102_002[] =
            {
                BSWAP_32BIG_C(0xfa34f86bU), BSWAP_32BIG_C(0x78d78ecbU), BSWAP_32BIG_C(0x0b94a562U), BSWAP_32BIG_C(
                    0xaae0540eU),
            };
            r_rsip_func102(Param_p5fi_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub022(0x0000b7c0U, 0x00000100U, 0x00000bffU);

            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            for (iLoop = 0U; iLoop < 16U; )
            {
                WR1_PROG(REG_1608H, 0x8184001eU);
                r_rsip_func_sub001(0x00890011U);
                WR1_PROG(REG_1608H, 0x8084001fU);
                r_rsip_func_sub001(0x03420011U);

                r_rsip_func_sub021(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            return RSIP_RET_PASS;
        }
    }
}
