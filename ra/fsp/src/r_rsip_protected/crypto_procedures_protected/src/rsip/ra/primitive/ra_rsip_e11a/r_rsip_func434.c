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

void r_rsip_func434 (uint32_t ARG1[], uint32_t ARG2[], uint32_t ARG3[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_0094H, 0x00003467U);

    WR1_PROG(REG_00B0H, 0x00000801U);
    r_rsip_func_sub003(0x80010040U, 0x03430005U);
    r_rsip_func_sub009(0x00030005U, 0x00000821U);
    WR1_PROG(REG_0094H, 0x01886c22U);
    WR1_PROG(REG_0094H, 0x00086c42U);

    r_rsip_func_sub007(0x38008820U, 0x00000001U, 0x00A60000U);

    static const uint32_t Param_func434_func100_001[] =
    {
        BSWAP_32BIG_C(0x0971252aU), BSWAP_32BIG_C(0xc03e1f25U), BSWAP_32BIG_C(0x75ecf669U), BSWAP_32BIG_C(0x4922688fU),
    };
    r_rsip_func100(Param_func434_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_func434_func100_002[] =
        {
            BSWAP_32BIG_C(0xc3835f65U), BSWAP_32BIG_C(0xc51373b5U), BSWAP_32BIG_C(0x8da2d5f5U), BSWAP_32BIG_C(
                0xf47aa7eaU),
        };
        r_rsip_func100(Param_func434_func100_002);
        WR1_PROG(REG_0094H, 0x01886c22U);
        r_rsip_func_sub015(0x00106c21U, 0x81010020U, 0x00005006U);
        RD1_ADDR(REG_002CH, &ARG1[0]);

        WR1_PROG(REG_0094H, 0x0000b420U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func434_func101_001[] =
        {
            BSWAP_32BIG_C(0x1f69b862U), BSWAP_32BIG_C(0x64082bacU), BSWAP_32BIG_C(0x7ed95995U), BSWAP_32BIG_C(
                0x0940f802U),
        };
        r_rsip_func101(Param_func434_func101_001);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x01886c22U);
        WR1_PROG(REG_0094H, 0x00086c42U);

        r_rsip_func_sub007(0x38008820U, 0x00000100U, 0x00260000U);

        static const uint32_t Param_func434_func100_003[] =
        {
            BSWAP_32BIG_C(0x11fcbe6bU), BSWAP_32BIG_C(0xa1bcb437U), BSWAP_32BIG_C(0xc9afe714U), BSWAP_32BIG_C(
                0xd87d544fU),
        };
        r_rsip_func100(Param_func434_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_func434_func100_004[] =
            {
                BSWAP_32BIG_C(0x5a8e291aU), BSWAP_32BIG_C(0xe3a57bdfU), BSWAP_32BIG_C(0x8fdc5e81U), BSWAP_32BIG_C(
                    0xa53c95e6U),
            };
            r_rsip_func100(Param_func434_func100_004);
            r_rsip_func_sub015(0x00106c21U, 0x81010020U, 0x00005006U);
            RD1_ADDR(REG_002CH, &ARG1[0]);

            WR1_PROG(REG_0094H, 0x00002c00U);
            WR1_PROG(REG_0094H, 0x00026800U);

            WR1_PROG(REG_00B0H, 0x00004809U);
            r_rsip_func_sub003(0x800100c0U, 0x03430005U);

            WR1_PROG(REG_0094H, 0x000008a5U);

            for (iLoop = 0U; iLoop < 17; iLoop++)
            {
                WR1_PROG(REG_0094H, 0x342028a0U);
                WR1_PROG(REG_009CH, 0x00000080U);
                WR1_PROG(REG_0040H, 0x00260000U);

                static const uint32_t Param_func434_func100_005[] =
                {
                    BSWAP_32BIG_C(0x92428c8eU), BSWAP_32BIG_C(0x7688faedU), BSWAP_32BIG_C(0x285de17eU), BSWAP_32BIG_C(
                        0x1c4733ffU),
                };
                r_rsip_func100(Param_func434_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x5b1e44f0U), BSWAP_32BIG_C(0x38b9a18fU), BSWAP_32BIG_C(0x6dd5011bU),
                        BSWAP_32BIG_C(0xa918561fU),
                    };
                    r_rsip_func100(Param_func434_func100_006);

                    r_rsip_func_sub003(0x800100e0U, 0x03430005U);

                    WR1_PROG(REG_0094H, 0x01906cc7U);
                    r_rsip_func_sub015(0x00106ce7U, 0x810100c0U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                    WR1_PROG(REG_0094H, 0x01906cc7U);
                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_func434_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x7f6e9394U), BSWAP_32BIG_C(0xfa70fc80U), BSWAP_32BIG_C(0x665596ffU),
                        BSWAP_32BIG_C(0x2d9f6c3dU),
                    };
                    r_rsip_func101(Param_func434_func101_002);
                }
                else
                {
                    WR1_PROG(REG_0000H, 0x00030005U);
                    WAIT_STS(REG_0004H, 30, 0);
                    WR1_PROG(REG_0040H, 0x00001800U);

                    static const uint32_t Param_func434_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x90430d52U), BSWAP_32BIG_C(0x26ee3c47U), BSWAP_32BIG_C(0x397fcff4U),
                        BSWAP_32BIG_C(0xae68c387U),
                    };
                    r_rsip_func101(Param_func434_func101_003);
                }

                static const uint32_t Param_func434_func101_004[] =
                {
                    BSWAP_32BIG_C(0x0003ab80U), BSWAP_32BIG_C(0x88eca1a3U), BSWAP_32BIG_C(0x19f1fc30U), BSWAP_32BIG_C(
                        0xd1fc1c1eU),
                };
                r_rsip_func101(Param_func434_func101_004);
            }

            WR1_PROG(REG_0094H, 0x342028a0U);
            WR1_PROG(REG_009CH, 0x00000080U);
            WR1_PROG(REG_0040H, 0x00260000U);

            static const uint32_t Param_func434_func100_007[] =
            {
                BSWAP_32BIG_C(0x92428c8eU), BSWAP_32BIG_C(0x7688faedU), BSWAP_32BIG_C(0x285de17eU), BSWAP_32BIG_C(
                    0x1c4733ffU),
            };
            r_rsip_func100(Param_func434_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_func434_func100_008[] =
                {
                    BSWAP_32BIG_C(0xb4511bfaU), BSWAP_32BIG_C(0x5eb6e00cU), BSWAP_32BIG_C(0xf9b9457eU), BSWAP_32BIG_C(
                        0x6ba366c2U),
                };
                r_rsip_func100(Param_func434_func100_008);

                r_rsip_func_sub015(0x00106cc6U, 0x810100c0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                static const uint32_t Param_func434_func101_005[] =
                {
                    BSWAP_32BIG_C(0x4b58697eU), BSWAP_32BIG_C(0x45f8bc7bU), BSWAP_32BIG_C(0xfdf51609U), BSWAP_32BIG_C(
                        0xf46d8a81U),
                };
                r_rsip_func101(Param_func434_func101_005);
            }

            WR1_PROG(REG_0094H, 0x00000821U);

            static const uint32_t Param_func434_func101_006[] =
            {
                BSWAP_32BIG_C(0xc6219bdaU), BSWAP_32BIG_C(0x2588d854U), BSWAP_32BIG_C(0x9cecd5afU), BSWAP_32BIG_C(
                    0x8dc51c20U),
            };
            r_rsip_func101(Param_func434_func101_006);
        }
        else
        {
            static const uint32_t Param_func434_func100_009[] =
            {
                BSWAP_32BIG_C(0x51a00f62U), BSWAP_32BIG_C(0x590a699dU), BSWAP_32BIG_C(0x83fbc607U), BSWAP_32BIG_C(
                    0x4b0bafd9U),
            };
            r_rsip_func100(Param_func434_func100_009);
            r_rsip_func_sub016(0x01886c22U, 0x000034e1U, 0x00008ce0U);
            r_rsip_func_sub016(0x000000ffU, 0x00003487U, 0x0000a480U);
            WR1_PROG(REG_0094H, 0x00000003U);

            r_rsip_func_sub015(0x00086c21U, 0x81010020U, 0x00005006U);
            RD1_ADDR(REG_002CH, &ARG1[0]);

            r_rsip_func_sub016(0x000008c6U, 0x380088e0U, 0x00000010U);
            r_rsip_func_sub016(0x1000d0c0U, 0x380088e0U, 0x00000020U);
            r_rsip_func_sub016(0x1000d0c0U, 0x34202804U, 0x2000d0c1U);

            r_rsip_func_sub007(0x380088c0U, 0x00000003U, 0x00A60000U);

            static const uint32_t Param_func434_func100_010[] =
            {
                BSWAP_32BIG_C(0xa2ff2336U), BSWAP_32BIG_C(0x769d57c7U), BSWAP_32BIG_C(0xfc727478U), BSWAP_32BIG_C(
                    0xf91739e5U),
            };
            r_rsip_func100(Param_func434_func100_010);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x00000001U);

                static const uint32_t Param_func434_func101_007[] =
                {
                    BSWAP_32BIG_C(0x0dcc20d1U), BSWAP_32BIG_C(0xb67a4ddeU), BSWAP_32BIG_C(0xf585c3ddU), BSWAP_32BIG_C(
                        0x86653eedU),
                };
                r_rsip_func101(Param_func434_func101_007);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x000034a0U);

                r_rsip_func_sub007(0x380088e0U, 0x00000010U, 0x00260000U);

                static const uint32_t Param_func434_func100_011[] =
                {
                    BSWAP_32BIG_C(0x98ef4b5fU), BSWAP_32BIG_C(0xfb653527U), BSWAP_32BIG_C(0xa075466aU), BSWAP_32BIG_C(
                        0xe4558912U),
                };
                r_rsip_func100(Param_func434_func100_011);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub016(0x0000b480U, 0x00000004U, 0x0000b420U);
                    r_rsip_func_sub016(0x00000005U, 0x0000a8a0U, 0x00000010U);

                    static const uint32_t Param_func434_func101_008[] =
                    {
                        BSWAP_32BIG_C(0xdf2b7426U), BSWAP_32BIG_C(0xcf96bb5aU), BSWAP_32BIG_C(0xb4201b0cU),
                        BSWAP_32BIG_C(0x769d5b42U),
                    };
                    r_rsip_func101(Param_func434_func101_008);
                }
                else
                {
                    r_rsip_func_sub016(0x0000b480U, 0x00000008U, 0x0000b420U);
                    r_rsip_func_sub016(0x00000007U, 0x0000a8a0U, 0x00000020U);

                    static const uint32_t Param_func434_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x13306d44U), BSWAP_32BIG_C(0xc424d755U), BSWAP_32BIG_C(0xdd898898U),
                        BSWAP_32BIG_C(0x142e60ebU),
                    };
                    r_rsip_func101(Param_func434_func101_009);
                }

                WR1_PROG(REG_0094H, 0x000268a5U);

                static const uint32_t Param_func434_func100_012[] =
                {
                    BSWAP_32BIG_C(0xcaf0b411U), BSWAP_32BIG_C(0xe47a92c8U), BSWAP_32BIG_C(0xe589eae4U), BSWAP_32BIG_C(
                        0x4aec26edU),
                };
                r_rsip_func100(Param_func434_func100_012);
                r_rsip_func103();

                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x0000f434U);

                static const uint32_t Param_func434_func101_010[] =
                {
                    BSWAP_32BIG_C(0x6d109074U), BSWAP_32BIG_C(0x9f25a5d1U), BSWAP_32BIG_C(0x28d4445dU), BSWAP_32BIG_C(
                        0xbbaabd9cU),
                };
                r_rsip_func101(Param_func434_func101_010);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x000034c1U);

                r_rsip_func_sub002(0x800100e0U, 0x0000f434U);

                static const uint32_t Param_func434_func101_011[] =
                {
                    BSWAP_32BIG_C(0x3f8dd723U), BSWAP_32BIG_C(0xeec3273eU), BSWAP_32BIG_C(0x11ec5556U), BSWAP_32BIG_C(
                        0xbcc0ca9fU),
                };
                r_rsip_func101(Param_func434_func101_011);
                r_rsip_func044();

                static const uint32_t Param_func434_func100_013[] =
                {
                    BSWAP_32BIG_C(0x7c4d2d68U), BSWAP_32BIG_C(0x5ced5a6aU), BSWAP_32BIG_C(0xe5b148e8U), BSWAP_32BIG_C(
                        0x8faa6bf2U),
                };
                r_rsip_func100(Param_func434_func100_013);
                WR1_PROG(REG_00B0H, 0x00004809U);
                r_rsip_func_sub003(0x800100c0U, 0x03430005U);

                WR1_PROG(REG_0094H, 0x00000842U);

                r_rsip_func_sub015(0x00000821U, 0x81010080U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub003(0x800100e0U, 0x03430005U);

                    r_rsip_func_sub016(0x01986cc7U, 0x00186ce7U, 0x00003cc1U);

                    r_rsip_func_sub016(0x01886cc7U, 0x0000a420U, 0x00000004U);
                    WR1_PROG(REG_0094H, 0x00002c40U);

                    static const uint32_t Param_func434_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x4ff51349U), BSWAP_32BIG_C(0x0a1eafd1U), BSWAP_32BIG_C(0x5ca45081U),
                        BSWAP_32BIG_C(0xdd339d6fU),
                    };
                    r_rsip_func101(Param_func434_func101_012);
                }

                static const uint32_t Param_func434_func100_014[] =
                {
                    BSWAP_32BIG_C(0x1b09bdcfU), BSWAP_32BIG_C(0xf2b146c1U), BSWAP_32BIG_C(0xa6cc7eb4U), BSWAP_32BIG_C(
                        0xe881e1a2U),
                };
                r_rsip_func100(Param_func434_func100_014);
                r_rsip_func_sub010(0x38000844U);

                r_rsip_func_sub016(0x0000b420U, 0x00000011U, 0x00002824U);

                r_rsip_func_sub015(0x00000884U, 0x81010020U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x00000842U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    WR1_PROG(REG_0094H, 0x34202845U);
                    WR1_PROG(REG_009CH, 0x00000080U);
                    WR1_PROG(REG_0040H, 0x00260000U);

                    static const uint32_t Param_func434_func100_015[] =
                    {
                        BSWAP_32BIG_C(0x0e8c17e4U), BSWAP_32BIG_C(0x9611a65dU), BSWAP_32BIG_C(0x7c747c03U),
                        BSWAP_32BIG_C(0xed599c04U),
                    };
                    r_rsip_func100(Param_func434_func100_015);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_func434_func100_016[] =
                        {
                            BSWAP_32BIG_C(0x597a57cbU), BSWAP_32BIG_C(0x33083993U), BSWAP_32BIG_C(0xf1651f9cU),
                            BSWAP_32BIG_C(0x5a5943d9U),
                        };
                        r_rsip_func100(Param_func434_func100_016);

                        r_rsip_func_sub003(0x800100e0U, 0x03430005U);

                        WR1_PROG(REG_0094H, 0x01986cc7U);
                        r_rsip_func_sub015(0x00186ce7U, 0x810100c0U, 0x00005006U);
                        RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                        WR1_PROG(REG_0094H, 0x01886cc7U);
                        WR1_PROG(REG_0094H, 0x00002c40U);

                        static const uint32_t Param_func434_func101_013[] =
                        {
                            BSWAP_32BIG_C(0x150d294eU), BSWAP_32BIG_C(0x7a306c92U), BSWAP_32BIG_C(0xc88e2474U),
                            BSWAP_32BIG_C(0xdc6cdcf8U),
                        };
                        r_rsip_func101(Param_func434_func101_013);
                    }
                    else
                    {
                        WR1_PROG(REG_0000H, 0x00030005U);
                        WAIT_STS(REG_0004H, 30, 0);
                        WR1_PROG(REG_0040H, 0x00001800U);

                        static const uint32_t Param_func434_func101_014[] =
                        {
                            BSWAP_32BIG_C(0x259804bcU), BSWAP_32BIG_C(0x51bd15b1U), BSWAP_32BIG_C(0xc2fb6207U),
                            BSWAP_32BIG_C(0x2b0302c9U),
                        };
                        r_rsip_func101(Param_func434_func101_014);
                    }

                    WR1_PROG(REG_0094H, 0x00002c80U);

                    static const uint32_t Param_func434_func101_015[] =
                    {
                        BSWAP_32BIG_C(0x792f1f31U), BSWAP_32BIG_C(0x19686268U), BSWAP_32BIG_C(0xe2f7a5c4U),
                        BSWAP_32BIG_C(0x464550c6U),
                    };
                    r_rsip_func101(Param_func434_func101_015);
                }

                r_rsip_func_sub010(0x38000881U);

                WR1_PROG(REG_0094H, 0x34202845U);
                WR1_PROG(REG_009CH, 0x00000080U);
                WR1_PROG(REG_0040H, 0x00260000U);

                static const uint32_t Param_func434_func100_017[] =
                {
                    BSWAP_32BIG_C(0x07480b3bU), BSWAP_32BIG_C(0xeaabe19aU), BSWAP_32BIG_C(0x121fc186U), BSWAP_32BIG_C(
                        0xa3a69148U),
                };
                r_rsip_func100(Param_func434_func100_017);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_018[] =
                    {
                        BSWAP_32BIG_C(0xad260a46U), BSWAP_32BIG_C(0x4b09d58fU), BSWAP_32BIG_C(0x32ed167aU),
                        BSWAP_32BIG_C(0x2b55e820U),
                    };
                    r_rsip_func100(Param_func434_func100_018);

                    r_rsip_func_sub015(0x00186cc6U, 0x810100c0U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                    static const uint32_t Param_func434_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x40b846d8U), BSWAP_32BIG_C(0x5c71eb8dU), BSWAP_32BIG_C(0x790efe61U),
                        BSWAP_32BIG_C(0x2ec20ee0U),
                    };
                    r_rsip_func101(Param_func434_func101_016);
                }

                WR1_PROG(REG_0094H, 0x00000884U);

                r_rsip_func_sub007(0x38008820U, 0x0000000dU, 0x00260000U);

                static const uint32_t Param_func434_func100_019[] =
                {
                    BSWAP_32BIG_C(0x34b458a2U), BSWAP_32BIG_C(0x2accb71aU), BSWAP_32BIG_C(0x3c911aa8U), BSWAP_32BIG_C(
                        0x5e7d5689U),
                };
                r_rsip_func100(Param_func434_func100_019);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_020[] =
                    {
                        BSWAP_32BIG_C(0x5a1ba9feU), BSWAP_32BIG_C(0xd1b69120U), BSWAP_32BIG_C(0xadd37979U),
                        BSWAP_32BIG_C(0xb0e264dbU),
                    };
                    r_rsip_func100(Param_func434_func100_020);
                    WR1_PROG(REG_00D4H, 0x40000000U);
                    WR1_PROG(REG_00D0H, 0xe7009d05U);

                    r_rsip_func_sub003(0x81840004U, 0x00490011U);
                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[1]);

                    static const uint32_t Param_func434_func100_021[] =
                    {
                        BSWAP_32BIG_C(0x49949e29U), BSWAP_32BIG_C(0xc161f9dfU), BSWAP_32BIG_C(0x600e5b27U),
                        BSWAP_32BIG_C(0x1aa61a5fU),
                    };
                    r_rsip_func100(Param_func434_func100_021);
                    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                    WR1_PROG(REG_00D4H, 0x40000000U);
                    r_rsip_func_sub006(0x09108105U, 0x00410011U);

                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[5]);

                    static const uint32_t Param_func434_func101_017[] =
                    {
                        BSWAP_32BIG_C(0x5ccc2bf2U), BSWAP_32BIG_C(0x50747695U), BSWAP_32BIG_C(0xd3dec29dU),
                        BSWAP_32BIG_C(0xe846b942U),
                    };
                    r_rsip_func101(Param_func434_func101_017);
                }
                else
                {
                    static const uint32_t Param_func434_func100_022[] =
                    {
                        BSWAP_32BIG_C(0x0371c32eU), BSWAP_32BIG_C(0x011a93daU), BSWAP_32BIG_C(0x3843d750U),
                        BSWAP_32BIG_C(0x37c4215cU),
                    };
                    r_rsip_func100(Param_func434_func100_022);
                    WR1_PROG(REG_00D4H, 0x40000100U);
                    WR1_PROG(REG_00D0H, 0xe7009d07U);

                    r_rsip_func_sub003(0x81880004U, 0x00490021U);
                    WR1_PROG(REG_0008H, 0x00001022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[1]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[5]);

                    static const uint32_t Param_func434_func100_023[] =
                    {
                        BSWAP_32BIG_C(0x3df3c21eU), BSWAP_32BIG_C(0xacf74fe0U), BSWAP_32BIG_C(0x2dab943aU),
                        BSWAP_32BIG_C(0x4ce09927U),
                    };
                    r_rsip_func100(Param_func434_func100_023);
                    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                    WR1_PROG(REG_00D4H, 0x40000000U);
                    r_rsip_func_sub006(0x09108105U, 0x00410011U);

                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[9]);

                    static const uint32_t Param_func434_func101_018[] =
                    {
                        BSWAP_32BIG_C(0x53c91666U), BSWAP_32BIG_C(0x8d8b2e49U), BSWAP_32BIG_C(0x3a179b97U),
                        BSWAP_32BIG_C(0x869f53a2U),
                    };
                    r_rsip_func101(Param_func434_func101_018);
                }

                static const uint32_t Param_func434_func100_024[] =
                {
                    BSWAP_32BIG_C(0xfb49b3c9U), BSWAP_32BIG_C(0xc9b24344U), BSWAP_32BIG_C(0x513f03d8U), BSWAP_32BIG_C(
                        0xf5920b69U),
                };
                r_rsip_func100(Param_func434_func100_024);
                WR1_PROG(REG_009CH, 0x81010000U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &ARG2[0]);

                WR1_PROG(REG_0094H, 0x00000821U);

                static const uint32_t Param_func434_func101_019[] =
                {
                    BSWAP_32BIG_C(0x5a67f65cU), BSWAP_32BIG_C(0x4babc900U), BSWAP_32BIG_C(0xdc8a3b02U), BSWAP_32BIG_C(
                        0x76bfbfd4U),
                };
                r_rsip_func101(Param_func434_func101_019);
            }

            static const uint32_t Param_func434_func101_020[] =
            {
                BSWAP_32BIG_C(0x516293b1U), BSWAP_32BIG_C(0x6a889686U), BSWAP_32BIG_C(0xc490d06aU), BSWAP_32BIG_C(
                    0xd0bd4915U),
            };
            r_rsip_func101(Param_func434_func101_020);
        }

        static const uint32_t Param_func434_func101_021[] =
        {
            BSWAP_32BIG_C(0xc2f3441dU), BSWAP_32BIG_C(0x9ce3fbf7U), BSWAP_32BIG_C(0x849c3ba1U), BSWAP_32BIG_C(
                0x81c03e58U),
        };
        r_rsip_func101(Param_func434_func101_021);
    }

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
