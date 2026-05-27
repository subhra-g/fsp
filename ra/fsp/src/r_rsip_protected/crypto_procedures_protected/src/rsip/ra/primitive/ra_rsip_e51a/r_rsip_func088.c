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

void r_rsip_func088 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000430U, 0x0404000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000430U, 0x04040010U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f08801U);

    static const uint32_t Param_func088_func101_001[] =
    {
        BSWAP_32BIG_C(0x6ea23088U), BSWAP_32BIG_C(0xfa6e2d6eU), BSWAP_32BIG_C(0xcfe32205U), BSWAP_32BIG_C(0x0337730bU),
    };
    r_rsip_func101(Param_func088_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10f00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f08802U);

    static const uint32_t Param_func088_func101_002[] =
    {
        BSWAP_32BIG_C(0x9771bb05U), BSWAP_32BIG_C(0x8694b075U), BSWAP_32BIG_C(0x21f1dcd5U), BSWAP_32BIG_C(0x6b27adc1U),
    };
    r_rsip_func101(Param_func088_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub021(0x00000430U, 0x00000480U, 0x00000020U, 0x04040004U);
    WR1_PROG(REG_1404H, 0x14380000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000458U, 0x00000160U, 0x04040009U);

    r_rsip_func_sub038(0x00000020U, 0x000000c0U, 0x04040010U);
    r_rsip_func_sub007(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x04040005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000458U, 0x00000480U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func088_func100_001[] =
    {
        BSWAP_32BIG_C(0x93d63f27U), BSWAP_32BIG_C(0x90d501adU), BSWAP_32BIG_C(0xbf374952U), BSWAP_32BIG_C(0x268844abU),
    };
    r_rsip_func100(Param_func088_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func088_func101_003[] =
        {
            BSWAP_32BIG_C(0x45c2a524U), BSWAP_32BIG_C(0x4558eb0cU), BSWAP_32BIG_C(0x635216f0U), BSWAP_32BIG_C(
                0x89d6656cU),
        };
        r_rsip_func101(Param_func088_func101_003);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub021(0x00000070U, 0x00000250U, 0x00000018U, 0x04040004U);

        WR1_PROG(REG_1404H, 0x14100000U);
        r_rsip_func_sub001(0x00c00021U);

        r_rsip_func_sub002(0x00000890U, 0x00000430U, 0x000002c8U, 0x04040009U);

        r_rsip_func_sub002(0x00000070U, 0x00000430U, 0x000002f0U, 0x04040009U);

        static const uint32_t Param_func088_func100_002[] =
        {
            BSWAP_32BIG_C(0x9f5015daU), BSWAP_32BIG_C(0xc9c28d47U), BSWAP_32BIG_C(0x483086fbU), BSWAP_32BIG_C(
                0x05835c4fU),
        };
        r_rsip_func100(Param_func088_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x04040015U, 0x00010001U);
        r_rsip_func_sub042(0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x00000520U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func088_func100_003[] =
        {
            BSWAP_32BIG_C(0xd52827ccU), BSWAP_32BIG_C(0xeebd3a80U), BSWAP_32BIG_C(0x52d2ce51U), BSWAP_32BIG_C(
                0xf9880cfaU),
        };
        r_rsip_func100(Param_func088_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func088_func101_004[] =
            {
                BSWAP_32BIG_C(0xd64913e3U), BSWAP_32BIG_C(0xffd323e0U), BSWAP_32BIG_C(0x03064f94U), BSWAP_32BIG_C(
                    0xb6005c6fU),
            };
            r_rsip_func101(Param_func088_func101_004);
        }
        else
        {
            static const uint32_t Param_func088_func100_004[] =
            {
                BSWAP_32BIG_C(0xd8c562b6U), BSWAP_32BIG_C(0xd6a0f25aU), BSWAP_32BIG_C(0x3675fe30U), BSWAP_32BIG_C(
                    0x42c6059dU),
            };
            r_rsip_func100(Param_func088_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x04040015U, 0x00010001U);
            r_rsip_func_sub042(0x10f00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func088_func100_005[] =
            {
                BSWAP_32BIG_C(0x4d765037U), BSWAP_32BIG_C(0x54f029f0U), BSWAP_32BIG_C(0x0f041113U), BSWAP_32BIG_C(
                    0xd92038f8U),
            };
            r_rsip_func100(Param_func088_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func088_func101_005[] =
                {
                    BSWAP_32BIG_C(0xf8c0f17dU), BSWAP_32BIG_C(0xc73c1358U), BSWAP_32BIG_C(0xaa3c8c76U), BSWAP_32BIG_C(
                        0x8cae2191U),
                };
                r_rsip_func101(Param_func088_func101_005);
            }
            else
            {
                static const uint32_t Param_func088_func100_006[] =
                {
                    BSWAP_32BIG_C(0x1b1aed91U), BSWAP_32BIG_C(0xf1a3373aU), BSWAP_32BIG_C(0x55dd78ffU), BSWAP_32BIG_C(
                        0xf8b1c848U),
                };
                r_rsip_func100(Param_func088_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x00000520U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x00000548U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000548U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub001(0x00c00021U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000520U, 0x04040009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040013U, 0x00010001U);
                r_rsip_func_sub042(0x12d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func088_func100_007[] =
                {
                    BSWAP_32BIG_C(0x78c59514U), BSWAP_32BIG_C(0xcdfbbaecU), BSWAP_32BIG_C(0x2e5f93fdU), BSWAP_32BIG_C(
                        0x8c9c33efU),
                };
                r_rsip_func100(Param_func088_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func088_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xe26e6ebdU), BSWAP_32BIG_C(0xc9e4ad34U), BSWAP_32BIG_C(0x8fbcdaddU),
                        BSWAP_32BIG_C(0x825b0dc8U),
                    };
                    r_rsip_func101(Param_func088_func101_006);
                }
                else
                {
                    static const uint32_t Param_func088_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x475a1149U), BSWAP_32BIG_C(0xc6e70b17U), BSWAP_32BIG_C(0xbe287bacU),
                        BSWAP_32BIG_C(0x1354735aU),
                    };
                    r_rsip_func100(Param_func088_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x04040004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub022(0x00000200U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000228U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x04040002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x618c5618U);

                    static const uint32_t Param_func088_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x4e32590dU), BSWAP_32BIG_C(0x770fd1cfU), BSWAP_32BIG_C(0xb2366702U),
                        BSWAP_32BIG_C(0xfa9976d7U),
                    };
                    r_rsip_func101(Param_func088_func101_007);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x618c5618U, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
