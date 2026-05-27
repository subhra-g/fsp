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

void r_rsip_func073 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    static const uint32_t Param_func073_func100_001[] =
    {
        BSWAP_32BIG_C(0x1a17116dU), BSWAP_32BIG_C(0x1534088dU), BSWAP_32BIG_C(0x822d9d3aU), BSWAP_32BIG_C(0x86cf5164U),
    };
    r_rsip_func100(Param_func073_func100_001);
    r_rsip_func070(ARG1);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

    WR1_PROG(REG_1404H, 0x11e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0404000aU);

    r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0404000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func073_func100_002[] =
    {
        BSWAP_32BIG_C(0x4bcdf189U), BSWAP_32BIG_C(0xaf66475bU), BSWAP_32BIG_C(0xb52b2d2dU), BSWAP_32BIG_C(0x3e0f065cU),
    };
    r_rsip_func100(Param_func073_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func073_func101_001[] =
        {
            BSWAP_32BIG_C(0x95486067U), BSWAP_32BIG_C(0xf45456e8U), BSWAP_32BIG_C(0xa5b526f0U), BSWAP_32BIG_C(
                0x798882b6U),
        };
        r_rsip_func101(Param_func073_func101_001);
    }
    else
    {
        static const uint32_t Param_func073_func100_003[] =
        {
            BSWAP_32BIG_C(0xdaaf0924U), BSWAP_32BIG_C(0xf21f9d17U), BSWAP_32BIG_C(0x95199256U), BSWAP_32BIG_C(
                0xb2dd032bU),
        };
        r_rsip_func100(Param_func073_func100_003);

        r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0404000aU);

        r_rsip_func_sub022(0x00000980U, 0x000001b0U, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1010H, 0x00000020U);

        r_rsip_func_sub037(0x0404000fU, 0x00010001U);
        WR1_PROG(REG_143CH, 0x00000d00U);

        r_rsip_func_sub022(0x00000110U, 0x00000840U, 0x000000c0U);
        r_rsip_func_sub005(0x00000160U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub033(0x10f00000U, 0x00000bffU, 0x8188001fU);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub022(0x00000110U, 0x00000160U, 0x000000c0U);
        r_rsip_func_sub005(0x00000480U, 0x04040002U, 0x00010001U);
        r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
        r_rsip_func_sub005(0x00000340U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1010H, 0x00000018U);

        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_func_sub001(0x00c00021U);

        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub001(0x00c002d1U);

        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000a70U, 0x04040004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002c8U, 0x04040009U);

        r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x04040009U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1608H, 0x81880001U);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000a20U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub012(0x10f00000U, 0x000037e1U, 0x0000a7e0U);
        WR1_PROG(REG_1600H, 0x00000020U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        r_rsip_func_sub001(0x00c90021U);

        r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000a48U, 0x04040002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        static const uint32_t Param_func073_func100_004[] =
        {
            BSWAP_32BIG_C(0x95ce33b6U), BSWAP_32BIG_C(0x0caec020U), BSWAP_32BIG_C(0x3d68910fU), BSWAP_32BIG_C(
                0x726ba7bdU),
        };
        r_rsip_func100(Param_func073_func100_004);
        r_rsip_func071(ARG1);

        r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000b10U, 0x04040009U);

        r_rsip_func_sub002(0x00000228U, 0x00000160U, 0x00000b38U, 0x04040009U);

        r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x04040009U);

        r_rsip_func_sub002(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000b38U, 0x00000a48U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000a48U, 0x00000b38U, 0x00000110U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func073_func100_005[] =
        {
            BSWAP_32BIG_C(0xf2c73929U), BSWAP_32BIG_C(0x543811e5U), BSWAP_32BIG_C(0x274e655eU), BSWAP_32BIG_C(
                0xcb1a2177U),
        };
        r_rsip_func100(Param_func073_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub022(0x00000b60U, 0x00000a70U, 0x00000070U);
            r_rsip_func_sub005(0x00000c50U, 0x04040013U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            static const uint32_t Param_func073_func101_002[] =
            {
                BSWAP_32BIG_C(0x7bc13891U), BSWAP_32BIG_C(0x2d588ab0U), BSWAP_32BIG_C(0xaba1ee5aU), BSWAP_32BIG_C(
                    0x1f0e61fcU),
            };
            r_rsip_func101(Param_func073_func101_002);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_101CH, 0x000002f0U);
            r_rsip_func_sub005(0x00000c50U, 0x04040014U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            static const uint32_t Param_func073_func101_003[] =
            {
                BSWAP_32BIG_C(0xa796a82aU), BSWAP_32BIG_C(0x0b15b4d8U), BSWAP_32BIG_C(0x144272e1U), BSWAP_32BIG_C(
                    0xc1f8f6ecU),
            };
            r_rsip_func101(Param_func073_func101_003);
        }

        r_rsip_func_sub044(0x00000821U, 0x14600000U, 0x80880001U);
        r_rsip_func_sub001(0x03430021U);

        r_rsip_func_sub034(0x0000a420U, 0x00000050U, 0x13200000U);
        WR1_PROG(REG_1608H, 0x80880001U);
        r_rsip_func_sub001(0x03430021U);

        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x00c000f1U);

        WR1_PROG(REG_1600H, 0x00000821U);

        for (iLoop = 0U; iLoop < 8U; iLoop++)
        {
            r_rsip_func_sub024(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
            r_rsip_func_sub025(0x00000050U, 0x00003885U, 0x00000842U);

            for (jLoop = 0U; jLoop < 32U; jLoop++)
            {
                r_rsip_func_sub024(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                WR1_PROG(REG_1600H, 0x00016c84U);

                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00a10000U);

                r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00a10000U);

                static const uint32_t Param_func073_func100_006[] =
                {
                    BSWAP_32BIG_C(0x191767f0U), BSWAP_32BIG_C(0xabc6db42U), BSWAP_32BIG_C(0x9992ee17U), BSWAP_32BIG_C(
                        0x44d567baU),
                };
                r_rsip_func100(Param_func073_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x000002f0U);
                    r_rsip_func_sub005(0x00000250U, 0x04040014U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    static const uint32_t Param_func073_func101_004[] =
                    {
                        BSWAP_32BIG_C(0x0bf72d59U), BSWAP_32BIG_C(0x410c46e2U), BSWAP_32BIG_C(0xf26de175U),
                        BSWAP_32BIG_C(0x5aa05d25U),
                    };
                    r_rsip_func101(Param_func073_func101_004);
                }
                else
                {
                    static const uint32_t Param_func073_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x8cec993eU), BSWAP_32BIG_C(0xa3e7c7c2U), BSWAP_32BIG_C(0x39305501U),
                        BSWAP_32BIG_C(0xbed293bfU),
                    };
                    r_rsip_func101(Param_func073_func101_005);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                static const uint32_t Param_func073_func100_007[] =
                {
                    BSWAP_32BIG_C(0xbdc2f467U), BSWAP_32BIG_C(0x6e7526a0U), BSWAP_32BIG_C(0x242438bfU), BSWAP_32BIG_C(
                        0x5047ecc5U),
                };
                r_rsip_func100(Param_func073_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_func073_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x3b8dc878U), BSWAP_32BIG_C(0x344a8884U), BSWAP_32BIG_C(0x9a078a77U),
                        BSWAP_32BIG_C(0xefdd58cfU),
                    };
                    r_rsip_func100(Param_func073_func100_008);

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub001(0x00c00021U);

                    r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                    {
                        r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000a48U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x30231137U), BSWAP_32BIG_C(0xfd6f9e09U), BSWAP_32BIG_C(0xdfe25bfdU),
                            BSWAP_32BIG_C(0x6df51643U),
                        };
                        r_rsip_func101(Param_func073_func101_006);
                    }
                    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                    {
                        r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000b38U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xa8fe4a11U), BSWAP_32BIG_C(0x10661ad1U), BSWAP_32BIG_C(0xc7063800U),
                            BSWAP_32BIG_C(0xd95f9173U),
                        };
                        r_rsip_func101(Param_func073_func101_007);
                    }
                    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                    {
                        r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x04040009U);

                        r_rsip_func_sub002(0x00000c28U, 0x00000160U, 0x00000458U, 0x04040009U);

                        r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);

                        static const uint32_t Param_func073_func101_008[] =
                        {
                            BSWAP_32BIG_C(0xd4201b8dU), BSWAP_32BIG_C(0xb71b39cdU), BSWAP_32BIG_C(0x6aaa4ad1U),
                            BSWAP_32BIG_C(0x9684b655U),
                        };
                        r_rsip_func101(Param_func073_func101_008);
                    }

                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_func073_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x815d4972U), BSWAP_32BIG_C(0x35424cf3U), BSWAP_32BIG_C(0x32df663cU),
                        BSWAP_32BIG_C(0xf3b8ee50U),
                    };
                    r_rsip_func100(Param_func073_func100_009);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000110U, 0x0404000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_func073_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x4ba41fffU), BSWAP_32BIG_C(0xf81310a6U), BSWAP_32BIG_C(0xf8796bdfU),
                            BSWAP_32BIG_C(0xaab20d7fU),
                        };
                        r_rsip_func100(Param_func073_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000200U, 0x00000430U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000430U, 0x00000200U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000228U, 0x00000458U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000458U, 0x00000228U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0404000aU);

                            WR1_PROG(REG_143CH, 0x00210000U);

                            static const uint32_t Param_func073_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x2635d046U), BSWAP_32BIG_C(0x20b329a4U), BSWAP_32BIG_C(0xde498607U),
                                BSWAP_32BIG_C(0x5f44fecaU),
                            };
                            r_rsip_func100(Param_func073_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub022(0x00000250U, 0x00000480U, 0x00000070U);
                                r_rsip_func_sub005(0x00000250U, 0x04040013U, 0x00010001U);
                                WAIT_STS(REG_1000H, 0, 0);
                                WR1_PROG(REG_143CH, 0x00000d00U);

                                static const uint32_t Param_func073_func101_009[] =
                                {
                                    BSWAP_32BIG_C(0xcbfc8dfbU), BSWAP_32BIG_C(0x5c1f6da9U), BSWAP_32BIG_C(0x5eb382a7U),
                                    BSWAP_32BIG_C(0xcb77f9e4U),
                                };
                                r_rsip_func101(Param_func073_func101_009);
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_101CH, 0x000002f0U);
                                r_rsip_func_sub005(0x00000250U, 0x04040014U, 0x00010001U);
                                WAIT_STS(REG_1000H, 0, 0);
                                WR1_PROG(REG_143CH, 0x00000d00U);

                                static const uint32_t Param_func073_func101_010[] =
                                {
                                    BSWAP_32BIG_C(0x121ad6a0U), BSWAP_32BIG_C(0x4abdaa1dU), BSWAP_32BIG_C(0x87efc800U),
                                    BSWAP_32BIG_C(0xc9b59ee2U),
                                };
                                r_rsip_func101(Param_func073_func101_010);
                            }
                        }
                        else
                        {
                            static const uint32_t Param_func073_func101_011[] =
                            {
                                BSWAP_32BIG_C(0x4437f798U), BSWAP_32BIG_C(0xc2603db6U), BSWAP_32BIG_C(0xdb097d26U),
                                BSWAP_32BIG_C(0x6e736af2U),
                            };
                            r_rsip_func101(Param_func073_func101_011);
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_func_sub001(0x00c00021U);

                        r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x04040009U);

                        r_rsip_func_sub002(0x00000458U, 0x00000160U, 0x00000228U, 0x04040009U);

                        r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);

                        static const uint32_t Param_func073_func101_012[] =
                        {
                            BSWAP_32BIG_C(0x3de3f17dU), BSWAP_32BIG_C(0x87271290U), BSWAP_32BIG_C(0x9c1a9c8fU),
                            BSWAP_32BIG_C(0x9e585bafU),
                        };
                        r_rsip_func101(Param_func073_func101_012);
                    }
                }
                else
                {
                    static const uint32_t Param_func073_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x8b0ae415U), BSWAP_32BIG_C(0x7b46fb70U), BSWAP_32BIG_C(0xeb25ac6eU),
                        BSWAP_32BIG_C(0xd4382c1dU),
                    };
                    r_rsip_func101(Param_func073_func101_013);
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                static const uint32_t Param_func073_func101_014[] =
                {
                    BSWAP_32BIG_C(0xf4655730U), BSWAP_32BIG_C(0xf928fbbeU), BSWAP_32BIG_C(0x4abbd73fU), BSWAP_32BIG_C(
                        0xf874d7deU),
                };
                r_rsip_func101(Param_func073_func101_014);
            }

            r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00002c20U);

            static const uint32_t Param_func073_func101_015[] =
            {
                BSWAP_32BIG_C(0xa2384d69U), BSWAP_32BIG_C(0xf9a4974cU), BSWAP_32BIG_C(0x779a3b1cU), BSWAP_32BIG_C(
                    0xda9e0812U),
            };
            r_rsip_func101(Param_func073_func101_015);
        }

        r_rsip_func_sub006(0x38008820U, 0x00000008U, 0x00260000U);

        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x12800000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0404000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func073_func100_012[] =
        {
            BSWAP_32BIG_C(0x96e6a243U), BSWAP_32BIG_C(0xc9efea35U), BSWAP_32BIG_C(0xea881343U), BSWAP_32BIG_C(
                0x77955462U),
        };
        r_rsip_func100(Param_func073_func100_012);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func073_func101_016[] =
            {
                BSWAP_32BIG_C(0xfa7deb28U), BSWAP_32BIG_C(0x7d91d2abU), BSWAP_32BIG_C(0x884549b3U), BSWAP_32BIG_C(
                    0x87d6ca43U),
            };
            r_rsip_func101(Param_func073_func101_016);
        }
        else
        {
            static const uint32_t Param_func073_func100_013[] =
            {
                BSWAP_32BIG_C(0xcc82ccacU), BSWAP_32BIG_C(0xd1cdc457U), BSWAP_32BIG_C(0x32e6b3e2U), BSWAP_32BIG_C(
                    0xa5d19c08U),
            };
            r_rsip_func100(Param_func073_func100_013);

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
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func073_func100_014[] =
            {
                BSWAP_32BIG_C(0x785aa023U), BSWAP_32BIG_C(0x28d92742U), BSWAP_32BIG_C(0x352febc3U), BSWAP_32BIG_C(
                    0xced84b2eU),
            };
            r_rsip_func100(Param_func073_func100_014);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func073_func101_017[] =
                {
                    BSWAP_32BIG_C(0x14c1a0a2U), BSWAP_32BIG_C(0x99dcd412U), BSWAP_32BIG_C(0x0f5bf522U), BSWAP_32BIG_C(
                        0xb0da0764U),
                };
                r_rsip_func101(Param_func073_func101_017);
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1600H, 0x797935bbU);

                static const uint32_t Param_func073_func101_018[] =
                {
                    BSWAP_32BIG_C(0x925a047dU), BSWAP_32BIG_C(0x795335c8U), BSWAP_32BIG_C(0x389791f7U), BSWAP_32BIG_C(
                        0x58dee35dU),
                };
                r_rsip_func101(Param_func073_func101_018);
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
