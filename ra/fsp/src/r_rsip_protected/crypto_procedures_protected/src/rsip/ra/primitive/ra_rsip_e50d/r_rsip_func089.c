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

void r_rsip_func089 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11300000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000410U, 0x06060010U);

    r_rsip_func_sub003(0x800103a0U, 0x00f08901U);

    static const uint32_t Param_func089_func101_001[] =
    {
        BSWAP_32BIG_C(0x05afaf4bU), BSWAP_32BIG_C(0xc3bc3dfdU), BSWAP_32BIG_C(0x378d79e6U), BSWAP_32BIG_C(0xddde4921U),
    };
    r_rsip_func101(Param_func089_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x800103a0U, 0x00f08902U);

    static const uint32_t Param_func089_func101_002[] =
    {
        BSWAP_32BIG_C(0xa82abe92U), BSWAP_32BIG_C(0x3f1650e8U), BSWAP_32BIG_C(0x9ab4a03eU), BSWAP_32BIG_C(0x6d11d681U),
    };
    r_rsip_func101(Param_func089_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x800103a0U, 0x00f08903U);

    static const uint32_t Param_func089_func101_003[] =
    {
        BSWAP_32BIG_C(0x04e4a640U), BSWAP_32BIG_C(0x7bd374e5U), BSWAP_32BIG_C(0x94394412U), BSWAP_32BIG_C(0x97c5ea8bU),
    };
    r_rsip_func101(Param_func089_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x00000410U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);

    WR1_PROG(REG_1004H, 0x06060004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x14180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000448U, 0x00000160U, 0x06060009U);

    r_rsip_func_sub036(0x00000020U, 0x000000c0U, 0x06060010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    r_rsip_func_sub007(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x06060005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000448U, 0x00000480U, 0x0606000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func089_func100_001[] =
    {
        BSWAP_32BIG_C(0xa76beb69U), BSWAP_32BIG_C(0x9fe28779U), BSWAP_32BIG_C(0x3e63d088U), BSWAP_32BIG_C(0xcd78798eU),
    };
    r_rsip_func100(Param_func089_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func089_func101_004[] =
        {
            BSWAP_32BIG_C(0x29664332U), BSWAP_32BIG_C(0x8657bc14U), BSWAP_32BIG_C(0x7f3293fdU), BSWAP_32BIG_C(
                0x2ebe2411U),
        };
        r_rsip_func101(Param_func089_func101_004);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);

        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x13e00000U);
        r_rsip_func_sub001(0x00c00031U);

        r_rsip_func_sub002(0x00000890U, 0x00000410U, 0x000002b8U, 0x06060009U);

        r_rsip_func_sub002(0x00000070U, 0x00000410U, 0x000002f0U, 0x06060009U);

        static const uint32_t Param_func089_func100_002[] =
        {
            BSWAP_32BIG_C(0x9fb33d55U), BSWAP_32BIG_C(0xc23d707aU), BSWAP_32BIG_C(0x57dc6480U), BSWAP_32BIG_C(
                0xd95a6cdaU),
        };
        r_rsip_func100(Param_func089_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x06060015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10e00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x00000500U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func089_func100_003[] =
        {
            BSWAP_32BIG_C(0xfb7a7279U), BSWAP_32BIG_C(0x9624a144U), BSWAP_32BIG_C(0x317f0d97U), BSWAP_32BIG_C(
                0x241129a5U),
        };
        r_rsip_func100(Param_func089_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func089_func101_005[] =
            {
                BSWAP_32BIG_C(0x930559e7U), BSWAP_32BIG_C(0x13f5f143U), BSWAP_32BIG_C(0x7679ca93U), BSWAP_32BIG_C(
                    0xd4e80e74U),
            };
            r_rsip_func101(Param_func089_func101_005);
        }
        else
        {
            static const uint32_t Param_func089_func100_004[] =
            {
                BSWAP_32BIG_C(0xe698df73U), BSWAP_32BIG_C(0xdcf7e59eU), BSWAP_32BIG_C(0xbb782fedU), BSWAP_32BIG_C(
                    0x0e29313dU),
            };
            r_rsip_func100(Param_func089_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x06060015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func089_func100_005[] =
            {
                BSWAP_32BIG_C(0x189e6a5aU), BSWAP_32BIG_C(0x94ba0e4cU), BSWAP_32BIG_C(0xf67fffceU), BSWAP_32BIG_C(
                    0x6c0fd67fU),
            };
            r_rsip_func100(Param_func089_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func089_func101_006[] =
                {
                    BSWAP_32BIG_C(0x1aa895a0U), BSWAP_32BIG_C(0x0544f462U), BSWAP_32BIG_C(0xa6be4254U), BSWAP_32BIG_C(
                        0xcbfbbbc7U),
                };
                r_rsip_func101(Param_func089_func101_006);
            }
            else
            {
                static const uint32_t Param_func089_func100_006[] =
                {
                    BSWAP_32BIG_C(0x580e8169U), BSWAP_32BIG_C(0x50fc721dU), BSWAP_32BIG_C(0x860df3c6U), BSWAP_32BIG_C(
                        0x11440969U),
                };
                r_rsip_func100(Param_func089_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x06060004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1014H, 0x00000500U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x00000538U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0606000aU);

                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000538U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub001(0x00c00031U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000500U, 0x06060009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x06060004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func089_func100_007[] =
                {
                    BSWAP_32BIG_C(0xd9ca762bU), BSWAP_32BIG_C(0x8f48a563U), BSWAP_32BIG_C(0xad4403bdU), BSWAP_32BIG_C(
                        0xc03cb2f7U),
                };
                r_rsip_func100(Param_func089_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func089_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xae5114fdU), BSWAP_32BIG_C(0xbdadc080U), BSWAP_32BIG_C(0x8f7cc9a8U),
                        BSWAP_32BIG_C(0xf26a5a07U),
                    };
                    r_rsip_func101(Param_func089_func101_007);
                }
                else
                {
                    static const uint32_t Param_func089_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x9ce9521bU), BSWAP_32BIG_C(0xdf15202eU), BSWAP_32BIG_C(0xa1ca1753U),
                        BSWAP_32BIG_C(0x4f9c27b5U),
                    };
                    r_rsip_func100(Param_func089_func100_008);
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

                    WR1_PROG(REG_1014H, 0x000001e0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x06060002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000218U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x06060002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x1714dcbaU);

                    static const uint32_t Param_func089_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x96fac04fU), BSWAP_32BIG_C(0xb489a640U), BSWAP_32BIG_C(0x06b3a826U),
                        BSWAP_32BIG_C(0x58a07fd3U),
                    };
                    r_rsip_func101(Param_func089_func101_008);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x1714dcbaU, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
