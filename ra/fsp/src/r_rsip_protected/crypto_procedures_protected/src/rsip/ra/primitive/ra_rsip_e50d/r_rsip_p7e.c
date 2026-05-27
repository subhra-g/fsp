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

rsip_ret_t r_rsip_p7e (const uint32_t InData_KeyIndex[],
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

    r_rsip_func_sub029(0x007e0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000007eU);

    static const uint32_t Param_p7e_func101_001[] =
    {
        BSWAP_32BIG_C(0x331e84e0U), BSWAP_32BIG_C(0x1c477d9dU), BSWAP_32BIG_C(0x82b9edf0U), BSWAP_32BIG_C(0xa085474dU),
    };
    r_rsip_func101(Param_p7e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000020U);

    r_rsip_func_sub003(0x800103a0U, 0x0000007eU);

    static const uint32_t Param_p7e_func101_002[] =
    {
        BSWAP_32BIG_C(0xc46018cdU), BSWAP_32BIG_C(0x0ee89f0fU), BSWAP_32BIG_C(0x23b0b717U), BSWAP_32BIG_C(0x7265f191U),
    };
    r_rsip_func101(Param_p7e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80a00001U);
    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 17]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[33]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p7e_func100_001[] =
    {
        BSWAP_32BIG_C(0xbcdf1297U), BSWAP_32BIG_C(0x4567f627U), BSWAP_32BIG_C(0xb9c56121U), BSWAP_32BIG_C(0x664d75a1U),
    };
    r_rsip_func100(Param_p7e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7e_func102_001[] =
        {
            BSWAP_32BIG_C(0x9929fc88U), BSWAP_32BIG_C(0xc7c941c3U), BSWAP_32BIG_C(0x91ac1fd1U), BSWAP_32BIG_C(
                0xc969ab27U),
        };
        r_rsip_func102(Param_p7e_func102_001);
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

        r_rsip_func_sub003(0x80010360U, 0x0000007eU);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p7e_func100_002[] =
        {
            BSWAP_32BIG_C(0xcd01c7f7U), BSWAP_32BIG_C(0x4c737b82U), BSWAP_32BIG_C(0x44ef9d55U), BSWAP_32BIG_C(
                0xf41b0bb2U),
        };
        r_rsip_func100(Param_p7e_func100_002);
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

        static const uint32_t Param_p7e_func100_003[] =
        {
            BSWAP_32BIG_C(0x306c7cd5U), BSWAP_32BIG_C(0x4aaa36cdU), BSWAP_32BIG_C(0x3289d560U), BSWAP_32BIG_C(
                0xb95da083U),
        };
        r_rsip_func100(Param_p7e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p7e_func101_003[] =
            {
                BSWAP_32BIG_C(0x0c1053fcU), BSWAP_32BIG_C(0xf8f0d08aU), BSWAP_32BIG_C(0x12645fc6U), BSWAP_32BIG_C(
                    0xf82ba89aU),
            };
            r_rsip_func101(Param_p7e_func101_003);
        }
        else
        {
            static const uint32_t Param_p7e_func100_004[] =
            {
                BSWAP_32BIG_C(0xc9efe878U), BSWAP_32BIG_C(0x3dd98d4eU), BSWAP_32BIG_C(0x61cc304aU), BSWAP_32BIG_C(
                    0x61717222U),
            };
            r_rsip_func100(Param_p7e_func100_004);

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

            static const uint32_t Param_p7e_func100_005[] =
            {
                BSWAP_32BIG_C(0x1d8d6d5bU), BSWAP_32BIG_C(0xeca4b656U), BSWAP_32BIG_C(0x8a4c8630U), BSWAP_32BIG_C(
                    0x13afe170U),
            };
            r_rsip_func100(Param_p7e_func100_005);
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

            static const uint32_t Param_p7e_func100_006[] =
            {
                BSWAP_32BIG_C(0xbad88468U), BSWAP_32BIG_C(0x73fa70f6U), BSWAP_32BIG_C(0xd82f664aU), BSWAP_32BIG_C(
                    0x031fffcdU),
            };
            r_rsip_func100(Param_p7e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p7e_func101_004[] =
                {
                    BSWAP_32BIG_C(0x954d3910U), BSWAP_32BIG_C(0xda1b4896U), BSWAP_32BIG_C(0xee693040U), BSWAP_32BIG_C(
                        0xe2fe7ae8U),
                };
                r_rsip_func101(Param_p7e_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x08080014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p7e_func101_005[] =
                {
                    BSWAP_32BIG_C(0xfeae9548U), BSWAP_32BIG_C(0xf2a06da1U), BSWAP_32BIG_C(0x4fc0b425U), BSWAP_32BIG_C(
                        0x26a58024U),
                };
                r_rsip_func101(Param_p7e_func101_005);
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

                    static const uint32_t Param_p7e_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x249e5836U), BSWAP_32BIG_C(0xabc66244U), BSWAP_32BIG_C(0x606c531bU),
                        BSWAP_32BIG_C(0x6f42e26bU),
                    };
                    r_rsip_func100(Param_p7e_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p7e_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x6d92a778U), BSWAP_32BIG_C(0x4ecf7844U), BSWAP_32BIG_C(0xdd9eac9bU),
                            BSWAP_32BIG_C(0x0b94263dU),
                        };
                        r_rsip_func101(Param_p7e_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p7e_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xc3729894U), BSWAP_32BIG_C(0xd7341b7aU), BSWAP_32BIG_C(0x2f1dad42U),
                            BSWAP_32BIG_C(0x5747a9f8U),
                        };
                        r_rsip_func101(Param_p7e_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p7e_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xe0e5fe6aU), BSWAP_32BIG_C(0x7620493dU), BSWAP_32BIG_C(0x6c406e36U),
                        BSWAP_32BIG_C(0x48da7dc0U),
                    };
                    r_rsip_func100(Param_p7e_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p7e_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x678b676bU), BSWAP_32BIG_C(0x2cc7db67U), BSWAP_32BIG_C(0x28119041U),
                            BSWAP_32BIG_C(0x94720d30U),
                        };
                        r_rsip_func100(Param_p7e_func100_009);

                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_func_sub001(0x00c00041U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009e0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a28U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xad9b81c4U), BSWAP_32BIG_C(0xd43a7e36U), BSWAP_32BIG_C(0xe706826bU),
                                BSWAP_32BIG_C(0xfe24ed6bU),
                            };
                            r_rsip_func101(Param_p7e_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ad0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b18U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xbf5e7a10U), BSWAP_32BIG_C(0x0a76436dU), BSWAP_32BIG_C(0xc9222b4dU),
                                BSWAP_32BIG_C(0x518ba3d2U),
                            };
                            r_rsip_func101(Param_p7e_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bc0U, 0x00000160U, 0x000003f0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c08U, 0x00000160U, 0x00000438U, 0x08080009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x232ff655U), BSWAP_32BIG_C(0x0a4322c0U), BSWAP_32BIG_C(0xa1100469U),
                                BSWAP_32BIG_C(0xfba69e68U),
                            };
                            r_rsip_func101(Param_p7e_func101_010);
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

                        static const uint32_t Param_p7e_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x5a4e7440U), BSWAP_32BIG_C(0x1927f2daU), BSWAP_32BIG_C(0x0017b154U),
                            BSWAP_32BIG_C(0xe4fc2e98U),
                        };
                        r_rsip_func100(Param_p7e_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p7e_func100_011[] =
                            {
                                BSWAP_32BIG_C(0xcac34c3cU), BSWAP_32BIG_C(0xce416f3cU), BSWAP_32BIG_C(0xb5c842f7U),
                                BSWAP_32BIG_C(0x51b7f912U),
                            };
                            r_rsip_func100(Param_p7e_func100_011);
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

                                static const uint32_t Param_p7e_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x6a098fd1U), BSWAP_32BIG_C(0xd427204eU), BSWAP_32BIG_C(0x3478b127U),
                                    BSWAP_32BIG_C(0xc1b858e2U),
                                };
                                r_rsip_func100(Param_p7e_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    WR1_PROG(REG_101CH, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p7e_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0xbf3994ddU), BSWAP_32BIG_C(0xc56d6cfdU), BSWAP_32BIG_C(
                                            0x6f60de55U),           BSWAP_32BIG_C(0x6f86e857U),
                                    };
                                    r_rsip_func101(Param_p7e_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x08080014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p7e_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0xb9352a35U), BSWAP_32BIG_C(0xb62d53edU), BSWAP_32BIG_C(
                                            0xda436f56U),           BSWAP_32BIG_C(0xbb8e52bbU),
                                    };
                                    r_rsip_func101(Param_p7e_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_p7e_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x33a8cb47U), BSWAP_32BIG_C(0x7b4b128cU), BSWAP_32BIG_C(0xe2b6754eU),
                                    BSWAP_32BIG_C(0x59b74136U),
                                };
                                r_rsip_func101(Param_p7e_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_func_sub001(0x00c00041U);

                            r_rsip_func_sub002(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);

                            r_rsip_func_sub002(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);

                            static const uint32_t Param_p7e_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x51c8bd08U), BSWAP_32BIG_C(0xb72c9019U), BSWAP_32BIG_C(0x0900f0e4U),
                                BSWAP_32BIG_C(0x8e8e6167U),
                            };
                            r_rsip_func101(Param_p7e_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p7e_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x0812f1b1U), BSWAP_32BIG_C(0x9bdfdbe5U), BSWAP_32BIG_C(0x78583637U),
                            BSWAP_32BIG_C(0x871aad66U),
                        };
                        r_rsip_func101(Param_p7e_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p7e_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x20fc2467U), BSWAP_32BIG_C(0x30515322U), BSWAP_32BIG_C(0x7095c208U),
                        BSWAP_32BIG_C(0x3e19c9c8U),
                    };
                    r_rsip_func101(Param_p7e_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p7e_func101_017[] =
                {
                    BSWAP_32BIG_C(0x5d175a92U), BSWAP_32BIG_C(0x831a1017U), BSWAP_32BIG_C(0x4c26afb9U), BSWAP_32BIG_C(
                        0x7d9b3e5bU),
                };
                r_rsip_func101(Param_p7e_func101_017);
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

            static const uint32_t Param_p7e_func100_013[] =
            {
                BSWAP_32BIG_C(0xe46c269aU), BSWAP_32BIG_C(0x87f26ee9U), BSWAP_32BIG_C(0x1b358840U), BSWAP_32BIG_C(
                    0x408e8353U),
            };
            r_rsip_func100(Param_p7e_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p7e_func101_018[] =
                {
                    BSWAP_32BIG_C(0xbf9819a4U), BSWAP_32BIG_C(0x676eda8fU), BSWAP_32BIG_C(0xcaf21897U), BSWAP_32BIG_C(
                        0xd750ef71U),
                };
                r_rsip_func101(Param_p7e_func101_018);
            }
            else
            {
                static const uint32_t Param_p7e_func100_014[] =
                {
                    BSWAP_32BIG_C(0x00be8870U), BSWAP_32BIG_C(0x4202d626U), BSWAP_32BIG_C(0xcabd94ebU), BSWAP_32BIG_C(
                        0xb340c0cfU),
                };
                r_rsip_func100(Param_p7e_func100_014);

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

                static const uint32_t Param_p7e_func100_015[] =
                {
                    BSWAP_32BIG_C(0xa3b6a580U), BSWAP_32BIG_C(0x991cc0b4U), BSWAP_32BIG_C(0xd5c121dcU), BSWAP_32BIG_C(
                        0xa3324b95U),
                };
                r_rsip_func100(Param_p7e_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p7e_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xcca0c364U), BSWAP_32BIG_C(0x2eddf876U), BSWAP_32BIG_C(0x7d738bd8U),
                        BSWAP_32BIG_C(0xfbbc069eU),
                    };
                    r_rsip_func101(Param_p7e_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_p7e_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x3edf04c6U), BSWAP_32BIG_C(0x8f9bd110U), BSWAP_32BIG_C(0x765237d2U),
                        BSWAP_32BIG_C(0xe27a29e3U),
                    };
                    r_rsip_func101(Param_p7e_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p7e_func100_016[] =
        {
            BSWAP_32BIG_C(0x00f9ba66U), BSWAP_32BIG_C(0xf8179214U), BSWAP_32BIG_C(0x9f758430U), BSWAP_32BIG_C(
                0x5c5e453fU),
        };
        r_rsip_func100(Param_p7e_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7e_func102_002[] =
            {
                BSWAP_32BIG_C(0x56870795U), BSWAP_32BIG_C(0xbf6a8b0dU), BSWAP_32BIG_C(0xdff875d5U), BSWAP_32BIG_C(
                    0x0a9df613U),
            };
            r_rsip_func102(Param_p7e_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7e_func102_003[] =
            {
                BSWAP_32BIG_C(0xcd2ca957U), BSWAP_32BIG_C(0x7d0c2da1U), BSWAP_32BIG_C(0x996cbe10U), BSWAP_32BIG_C(
                    0x25014c80U),
            };
            r_rsip_func102(Param_p7e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
