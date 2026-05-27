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

rsip_ret_t r_rsip_p12 (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub030(0x00120001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000012U);

    static const uint32_t Param_p12_func101_001[] =
    {
        BSWAP_32BIG_C(0xe4e6f231U), BSWAP_32BIG_C(0x94c64e63U), BSWAP_32BIG_C(0x7c2c5fcfU), BSWAP_32BIG_C(0x7d4f0af8U),
    };
    r_rsip_func101(Param_p12_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000012U);

    static const uint32_t Param_p12_func101_002[] =
    {
        BSWAP_32BIG_C(0xd0b6038fU), BSWAP_32BIG_C(0xb27eeb53U), BSWAP_32BIG_C(0x2077b27eU), BSWAP_32BIG_C(0x361d9115U),
    };
    r_rsip_func101(Param_p12_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x000027c2U, 0x40000900U, 0xe8009107U);

    r_rsip_func_sub026(0x0000b420U, 0x00000060U, 0x80a80001U);
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
    r_rsip_func_sub001(0x03420021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[29]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[37]);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[41]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p12_func100_001[] =
    {
        BSWAP_32BIG_C(0x1abeb8e6U), BSWAP_32BIG_C(0xfd779813U), BSWAP_32BIG_C(0x97c75e33U), BSWAP_32BIG_C(0x4a4f39c8U),
    };
    r_rsip_func100(Param_p12_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p12_func102_001[] =
        {
            BSWAP_32BIG_C(0x5171e3e2U), BSWAP_32BIG_C(0xa5776a6bU), BSWAP_32BIG_C(0x72687beeU), BSWAP_32BIG_C(
                0xbb81f80bU),
        };
        r_rsip_func102(Param_p12_func102_001);
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

        r_rsip_func_sub003(0x000000a7U, 0x80010360U, 0x00000012U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p12_func100_002[] =
        {
            BSWAP_32BIG_C(0x7d7553e9U), BSWAP_32BIG_C(0x3bfdbf71U), BSWAP_32BIG_C(0x4b17eeb1U), BSWAP_32BIG_C(
                0x1cf147f6U),
        };
        r_rsip_func100(Param_p12_func100_002);
        r_rsip_func086(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

        WR1_PROG(REG_1404H, 0x18e00000U);
        r_rsip_func_sub008(0x000027c2U, 0x00000900U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x19300000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[24]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[28]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[32]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[36]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x11b80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0909000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p12_func100_003[] =
        {
            BSWAP_32BIG_C(0x59cc1cccU), BSWAP_32BIG_C(0xee735e5bU), BSWAP_32BIG_C(0x5b29c997U), BSWAP_32BIG_C(
                0x95f91d04U),
        };
        r_rsip_func100(Param_p12_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p12_func101_003[] =
            {
                BSWAP_32BIG_C(0x84ddcda9U), BSWAP_32BIG_C(0x0cd1d327U), BSWAP_32BIG_C(0x70f044eeU), BSWAP_32BIG_C(
                    0x8f8b0aecU),
            };
            r_rsip_func101(Param_p12_func101_003);
        }
        else
        {
            static const uint32_t Param_p12_func100_004[] =
            {
                BSWAP_32BIG_C(0x4ebcf058U), BSWAP_32BIG_C(0x0cd163e8U), BSWAP_32BIG_C(0x56fe6533U), BSWAP_32BIG_C(
                    0x801c7524U),
            };
            r_rsip_func100(Param_p12_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0909000aU);

            r_rsip_func_sub022(0x00000980U, 0x000001b0U, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);

            r_rsip_func_sub037(0x0909000fU, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x10c00000U);
            r_rsip_func_sub001(0x00c00011U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub022(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x09090002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_func_sub001(0x00c00049U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x09090004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002a0U, 0x09090009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x09090009U);

            WR1_PROG(REG_1404H, 0x10c00000U);
            WR1_PROG(REG_1608H, 0x81940001U);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x000009d0U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10c00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1608H, 0x8194001fU);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a20U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p12_func100_005[] =
            {
                BSWAP_32BIG_C(0x7b3ee435U), BSWAP_32BIG_C(0x55c880dfU), BSWAP_32BIG_C(0x0f1dc185U), BSWAP_32BIG_C(
                    0x1405fd8aU),
            };
            r_rsip_func100(Param_p12_func100_005);
            r_rsip_func087(InData_DomainParam);

            r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000ac0U, 0x09090009U);

            r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000b10U, 0x09090009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x09090009U);

            r_rsip_func_sub002(0x00000ac0U, 0x000009d0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x000009d0U, 0x00000ac0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p12_func100_006[] =
            {
                BSWAP_32BIG_C(0x3ceaf008U), BSWAP_32BIG_C(0xa9e8b676U), BSWAP_32BIG_C(0x0ba171c1U), BSWAP_32BIG_C(
                    0x0942acfdU),
            };
            r_rsip_func100(Param_p12_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x09090013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p12_func101_004[] =
                {
                    BSWAP_32BIG_C(0xab6fc217U), BSWAP_32BIG_C(0x3b5bbeebU), BSWAP_32BIG_C(0x0f8f2cc4U), BSWAP_32BIG_C(
                        0xc0e8e2acU),
                };
                r_rsip_func101(Param_p12_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x09090014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p12_func101_005[] =
                {
                    BSWAP_32BIG_C(0x322ab825U), BSWAP_32BIG_C(0xa7480ae3U), BSWAP_32BIG_C(0x0e2e0c65U), BSWAP_32BIG_C(
                        0x4e51f04eU),
                };
                r_rsip_func101(Param_p12_func101_005);
            }

            r_rsip_func_sub044(0x00000821U, 0x14380000U, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            r_rsip_func_sub034(0x0000a420U, 0x00000050U, 0x12f80000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 18U; iLoop++)
            {
                r_rsip_func_sub024(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub025(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub024(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c00045U);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p12_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x05c86752U), BSWAP_32BIG_C(0xf3b94837U), BSWAP_32BIG_C(0x20890582U),
                        BSWAP_32BIG_C(0x452d3f20U),
                    };
                    r_rsip_func100(Param_p12_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p12_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xe4e6a977U), BSWAP_32BIG_C(0x35784319U), BSWAP_32BIG_C(0xbd76059fU),
                            BSWAP_32BIG_C(0x0320b22fU),
                        };
                        r_rsip_func101(Param_p12_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p12_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xb620a53aU), BSWAP_32BIG_C(0xb2b89a42U), BSWAP_32BIG_C(0xf93cc3c5U),
                            BSWAP_32BIG_C(0x29489552U),
                        };
                        r_rsip_func101(Param_p12_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p12_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xc1678e6dU), BSWAP_32BIG_C(0x260e24e3U), BSWAP_32BIG_C(0xd8aef2dfU),
                        BSWAP_32BIG_C(0xdf404a02U),
                    };
                    r_rsip_func100(Param_p12_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p12_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x08ff7922U), BSWAP_32BIG_C(0x39b9d7e2U), BSWAP_32BIG_C(0x8d291d06U),
                            BSWAP_32BIG_C(0x8bb98510U),
                        };
                        r_rsip_func100(Param_p12_func100_009);

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub001(0x00c00049U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009d0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x220bbd69U), BSWAP_32BIG_C(0xe1061fbbU), BSWAP_32BIG_C(0x78272fa5U),
                                BSWAP_32BIG_C(0x8acafd4aU),
                            };
                            r_rsip_func101(Param_p12_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x94e021a6U), BSWAP_32BIG_C(0x3f69a9eaU), BSWAP_32BIG_C(0x98458254U),
                                BSWAP_32BIG_C(0x9d5500e9U),
                            };
                            r_rsip_func101(Param_p12_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p12_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x5388c928U), BSWAP_32BIG_C(0x470d4f32U), BSWAP_32BIG_C(0x455a67c5U),
                                BSWAP_32BIG_C(0xd873818fU),
                            };
                            r_rsip_func101(Param_p12_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c00045U);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p12_func100_010[] =
                        {
                            BSWAP_32BIG_C(0xe6e64432U), BSWAP_32BIG_C(0xaeb5b8b6U), BSWAP_32BIG_C(0x0ce3b61eU),
                            BSWAP_32BIG_C(0x3f6b7f24U),
                        };
                        r_rsip_func100(Param_p12_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p12_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x9e90facdU), BSWAP_32BIG_C(0xe7c503d6U), BSWAP_32BIG_C(0x9dd18390U),
                                BSWAP_32BIG_C(0x70d19cadU),
                            };
                            r_rsip_func100(Param_p12_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001b0U, 0x000003e0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x000003e0U, 0x000001b0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000200U, 0x00000430U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000430U, 0x00000200U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p12_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xf0289b69U), BSWAP_32BIG_C(0x57318414U), BSWAP_32BIG_C(0xb170ae0bU),
                                    BSWAP_32BIG_C(0xdf2ef331U),
                                };
                                r_rsip_func100(Param_p12_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub022(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p12_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x3411a5e4U), BSWAP_32BIG_C(0x4a6d4f01U), BSWAP_32BIG_C(
                                            0x0b14a29cU),           BSWAP_32BIG_C(0x080456e1U),
                                    };
                                    r_rsip_func101(Param_p12_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p12_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0xdde60c76U), BSWAP_32BIG_C(0xf2017836U), BSWAP_32BIG_C(
                                            0x011a6ed8U),           BSWAP_32BIG_C(0x7447746eU),
                                    };
                                    r_rsip_func101(Param_p12_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_p12_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x1c003eb7U), BSWAP_32BIG_C(0x21ff4999U), BSWAP_32BIG_C(0xbbe3f19aU),
                                    BSWAP_32BIG_C(0x56a52d85U),
                                };
                                r_rsip_func101(Param_p12_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_func_sub001(0x00c00049U);

                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);

                            static const uint32_t Param_p12_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x5974953dU), BSWAP_32BIG_C(0x0451234dU), BSWAP_32BIG_C(0x8c13ab0fU),
                                BSWAP_32BIG_C(0x2e39e063U),
                            };
                            r_rsip_func101(Param_p12_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p12_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x4f712ed6U), BSWAP_32BIG_C(0x2e299e13U), BSWAP_32BIG_C(0xfecaf5b9U),
                            BSWAP_32BIG_C(0x831785c2U),
                        };
                        r_rsip_func101(Param_p12_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p12_func101_016[] =
                    {
                        BSWAP_32BIG_C(0xb7673bffU), BSWAP_32BIG_C(0xf57300acU), BSWAP_32BIG_C(0xcd18562aU),
                        BSWAP_32BIG_C(0x9d6455d2U),
                    };
                    r_rsip_func101(Param_p12_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p12_func101_017[] =
                {
                    BSWAP_32BIG_C(0x14b0be08U), BSWAP_32BIG_C(0xe1a8a3feU), BSWAP_32BIG_C(0xbcfb5bf2U), BSWAP_32BIG_C(
                        0x94a19ef2U),
                };
                r_rsip_func101(Param_p12_func101_017);
            }

            r_rsip_func_sub006(0x38008820U, 0x00000012U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x12580000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p12_func100_013[] =
            {
                BSWAP_32BIG_C(0x433743e9U), BSWAP_32BIG_C(0x86be0732U), BSWAP_32BIG_C(0x02ccdc65U), BSWAP_32BIG_C(
                    0x0a3986a4U),
            };
            r_rsip_func100(Param_p12_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p12_func101_018[] =
                {
                    BSWAP_32BIG_C(0x75ad8378U), BSWAP_32BIG_C(0x788f0be7U), BSWAP_32BIG_C(0x596a5c5fU), BSWAP_32BIG_C(
                        0xd6ef8398U),
                };
                r_rsip_func101(Param_p12_func101_018);
            }
            else
            {
                static const uint32_t Param_p12_func100_014[] =
                {
                    BSWAP_32BIG_C(0x1e956984U), BSWAP_32BIG_C(0x0f59ae25U), BSWAP_32BIG_C(0xabe5ea18U), BSWAP_32BIG_C(
                        0xb823b68dU),
                };
                r_rsip_func100(Param_p12_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x000001b0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p12_func100_015[] =
                {
                    BSWAP_32BIG_C(0x2ae41089U), BSWAP_32BIG_C(0x97da58c1U), BSWAP_32BIG_C(0x457b097aU), BSWAP_32BIG_C(
                        0xef2b8cb5U),
                };
                r_rsip_func100(Param_p12_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p12_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xdc972363U), BSWAP_32BIG_C(0xc30a36d0U), BSWAP_32BIG_C(0xa11998b0U),
                        BSWAP_32BIG_C(0x3656289aU),
                    };
                    r_rsip_func101(Param_p12_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_p12_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xfd99d8f4U), BSWAP_32BIG_C(0x82ec05c6U), BSWAP_32BIG_C(0xf5c27e69U),
                        BSWAP_32BIG_C(0x797c3cfdU),
                    };
                    r_rsip_func101(Param_p12_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p12_func100_016[] =
        {
            BSWAP_32BIG_C(0xf1ebfcbdU), BSWAP_32BIG_C(0x6290c228U), BSWAP_32BIG_C(0xe1c40b54U), BSWAP_32BIG_C(
                0x2085c6cdU),
        };
        r_rsip_func100(Param_p12_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p12_func102_002[] =
            {
                BSWAP_32BIG_C(0x5c5ef3b1U), BSWAP_32BIG_C(0x6d324abeU), BSWAP_32BIG_C(0xbf1df9f2U), BSWAP_32BIG_C(
                    0x8ac0b838U),
            };
            r_rsip_func102(Param_p12_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p12_func102_003[] =
            {
                BSWAP_32BIG_C(0x9dd89bb0U), BSWAP_32BIG_C(0x49925296U), BSWAP_32BIG_C(0x9f276718U), BSWAP_32BIG_C(
                    0x35eabe42U),
            };
            r_rsip_func102(Param_p12_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
