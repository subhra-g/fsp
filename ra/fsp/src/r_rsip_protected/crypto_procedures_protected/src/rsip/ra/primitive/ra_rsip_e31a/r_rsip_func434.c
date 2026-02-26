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
    r_rsip_func_sub005(0x80010040U, 0x03430005U, 0x00030005U);

    r_rsip_func_sub022(0x00000821U, 0x01886c22U, 0x00086c42U);

    r_rsip_func_sub010(0x38008820U, 0x00000001U, 0x00A70000U);

    static const uint32_t Param_func434_func100_001[] =
    {
        BSWAP_32BIG_C(0x625e92d1U), BSWAP_32BIG_C(0xa5bfa7a9U), BSWAP_32BIG_C(0xdef3f9baU), BSWAP_32BIG_C(0x3a604308U),
    };
    r_rsip_func100(Param_func434_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_func434_func100_002[] =
        {
            BSWAP_32BIG_C(0x2eadb16cU), BSWAP_32BIG_C(0xda92a448U), BSWAP_32BIG_C(0xa9a1437dU), BSWAP_32BIG_C(
                0xf564b09fU),
        };
        r_rsip_func100(Param_func434_func100_002);
        WR1_PROG(REG_0094H, 0x01886c22U);
        WR1_PROG(REG_0094H, 0x00106c21U);

        r_rsip_func_sub017(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_002CH, &ARG1[0]);

        WR1_PROG(REG_0094H, 0x0000b420U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func434_func101_001[] =
        {
            BSWAP_32BIG_C(0x74780f84U), BSWAP_32BIG_C(0xae2c6ae4U), BSWAP_32BIG_C(0xb468703eU), BSWAP_32BIG_C(
                0x382e8a3eU),
        };
        r_rsip_func101(Param_func434_func101_001);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x01886c22U);
        WR1_PROG(REG_0094H, 0x00086c42U);

        r_rsip_func_sub010(0x38008820U, 0x00000100U, 0x00270000U);

        static const uint32_t Param_func434_func100_003[] =
        {
            BSWAP_32BIG_C(0xf0151905U), BSWAP_32BIG_C(0x977c28d5U), BSWAP_32BIG_C(0xcea6fcc5U), BSWAP_32BIG_C(
                0xa218578aU),
        };
        r_rsip_func100(Param_func434_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_func434_func100_004[] =
            {
                BSWAP_32BIG_C(0xfd756b6eU), BSWAP_32BIG_C(0x154b04fcU), BSWAP_32BIG_C(0xc7c5c005U), BSWAP_32BIG_C(
                    0xd37c19b2U),
            };
            r_rsip_func100(Param_func434_func100_004);
            WR1_PROG(REG_0094H, 0x00106c21U);

            r_rsip_func_sub017(0x81010020U, 0x00005006U);
            RD1_ADDR(REG_002CH, &ARG1[0]);

            WR1_PROG(REG_0094H, 0x00002c00U);
            WR1_PROG(REG_0094H, 0x00026800U);

            WR1_PROG(REG_00B0H, 0x00004809U);
            r_rsip_func_sub012(0x800100c0U, 0x03430005U);

            WR1_PROG(REG_0094H, 0x000008a5U);

            for (iLoop = 0U; iLoop < 17; iLoop++)
            {
                r_rsip_func_sub016(0x342028a0U, 0x00000080U, 0x00270000U);

                static const uint32_t Param_func434_func100_005[] =
                {
                    BSWAP_32BIG_C(0xcf2511baU), BSWAP_32BIG_C(0x2b1d6fd1U), BSWAP_32BIG_C(0x2eff1b8eU), BSWAP_32BIG_C(
                        0x26852e31U),
                };
                r_rsip_func100(Param_func434_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x860e767dU), BSWAP_32BIG_C(0xb25161caU), BSWAP_32BIG_C(0x25787281U),
                        BSWAP_32BIG_C(0x48d52549U),
                    };
                    r_rsip_func100(Param_func434_func100_006);

                    r_rsip_func_sub006(0x800100e0U, 0x03430005U, 0x01906cc7U, 0x00106ce7U);

                    r_rsip_func_sub017(0x810100c0U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                    WR1_PROG(REG_0094H, 0x01906cc7U);
                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_func434_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x7902075dU), BSWAP_32BIG_C(0xca411bdfU), BSWAP_32BIG_C(0x5922651cU),
                        BSWAP_32BIG_C(0x1d9cdbbeU),
                    };
                    r_rsip_func101(Param_func434_func101_002);
                }
                else
                {
                    r_rsip_func_sub015(0x00030005U, 0x00001800U);

                    static const uint32_t Param_func434_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x8c970f39U), BSWAP_32BIG_C(0xef681350U), BSWAP_32BIG_C(0x10650e6dU),
                        BSWAP_32BIG_C(0x0d75f994U),
                    };
                    r_rsip_func101(Param_func434_func101_003);
                }

                static const uint32_t Param_func434_func101_004[] =
                {
                    BSWAP_32BIG_C(0xb3f5eeb1U), BSWAP_32BIG_C(0x45a45f8cU), BSWAP_32BIG_C(0xd6a9de92U), BSWAP_32BIG_C(
                        0xe5ecbc4bU),
                };
                r_rsip_func101(Param_func434_func101_004);
            }

            r_rsip_func_sub016(0x342028a0U, 0x00000080U, 0x00270000U);

            static const uint32_t Param_func434_func100_007[] =
            {
                BSWAP_32BIG_C(0xcf2511baU), BSWAP_32BIG_C(0x2b1d6fd1U), BSWAP_32BIG_C(0x2eff1b8eU), BSWAP_32BIG_C(
                    0x26852e31U),
            };
            r_rsip_func100(Param_func434_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_func434_func100_008[] =
                {
                    BSWAP_32BIG_C(0x210cd929U), BSWAP_32BIG_C(0x03cb69e6U), BSWAP_32BIG_C(0xe22693beU), BSWAP_32BIG_C(
                        0x6d3abed4U),
                };
                r_rsip_func100(Param_func434_func100_008);

                WR1_PROG(REG_0094H, 0x00106cc6U);

                r_rsip_func_sub017(0x810100c0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                static const uint32_t Param_func434_func101_005[] =
                {
                    BSWAP_32BIG_C(0x6cacda1dU), BSWAP_32BIG_C(0xb60079dbU), BSWAP_32BIG_C(0x59f6617dU), BSWAP_32BIG_C(
                        0xb04e20a5U),
                };
                r_rsip_func101(Param_func434_func101_005);
            }

            WR1_PROG(REG_0094H, 0x00000821U);

            static const uint32_t Param_func434_func101_006[] =
            {
                BSWAP_32BIG_C(0xe2f8e577U), BSWAP_32BIG_C(0x355f5b14U), BSWAP_32BIG_C(0x12362b04U), BSWAP_32BIG_C(
                    0x32e0d2e4U),
            };
            r_rsip_func101(Param_func434_func101_006);
        }
        else
        {
            static const uint32_t Param_func434_func100_009[] =
            {
                BSWAP_32BIG_C(0xb7b0810fU), BSWAP_32BIG_C(0xe38d8aebU), BSWAP_32BIG_C(0xce57d420U), BSWAP_32BIG_C(
                    0x18a5b609U),
            };
            r_rsip_func100(Param_func434_func100_009);
            r_rsip_func_sub022(0x01886c22U, 0x000034e1U, 0x00008ce0U);
            r_rsip_func_sub022(0x000000ffU, 0x00003487U, 0x0000a480U);
            WR1_PROG(REG_0094H, 0x00000003U);

            WR1_PROG(REG_0094H, 0x00086c21U);

            r_rsip_func_sub017(0x81010020U, 0x00005006U);
            RD1_ADDR(REG_002CH, &ARG1[0]);

            r_rsip_func_sub022(0x000008c6U, 0x380088e0U, 0x00000010U);
            r_rsip_func_sub022(0x1000d0c0U, 0x380088e0U, 0x00000020U);
            r_rsip_func_sub022(0x1000d0c0U, 0x34202804U, 0x2000d0c1U);

            r_rsip_func_sub010(0x380088c0U, 0x00000003U, 0x00A70000U);

            static const uint32_t Param_func434_func100_010[] =
            {
                BSWAP_32BIG_C(0x0daaad4bU), BSWAP_32BIG_C(0x7651c20dU), BSWAP_32BIG_C(0x08bc0f30U), BSWAP_32BIG_C(
                    0x888b55e4U),
            };
            r_rsip_func100(Param_func434_func100_010);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x00000001U);

                static const uint32_t Param_func434_func101_007[] =
                {
                    BSWAP_32BIG_C(0x96bd84a0U), BSWAP_32BIG_C(0x80f74f43U), BSWAP_32BIG_C(0x42a19137U), BSWAP_32BIG_C(
                        0xef4a52ceU),
                };
                r_rsip_func101(Param_func434_func101_007);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x000034a0U);

                r_rsip_func_sub010(0x380088e0U, 0x00000010U, 0x00270000U);

                static const uint32_t Param_func434_func100_011[] =
                {
                    BSWAP_32BIG_C(0xbcb0698bU), BSWAP_32BIG_C(0x6521c918U), BSWAP_32BIG_C(0x48b671f9U), BSWAP_32BIG_C(
                        0x5e44384fU),
                };
                r_rsip_func100(Param_func434_func100_011);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub022(0x0000b480U, 0x00000004U, 0x0000b420U);
                    r_rsip_func_sub022(0x00000005U, 0x0000a8a0U, 0x00000010U);

                    static const uint32_t Param_func434_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x68661fa1U), BSWAP_32BIG_C(0x9909b550U), BSWAP_32BIG_C(0x2f3f7c4dU),
                        BSWAP_32BIG_C(0x3412e97eU),
                    };
                    r_rsip_func101(Param_func434_func101_008);
                }
                else
                {
                    r_rsip_func_sub022(0x0000b480U, 0x00000008U, 0x0000b420U);
                    r_rsip_func_sub022(0x00000007U, 0x0000a8a0U, 0x00000020U);

                    static const uint32_t Param_func434_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x973853b5U), BSWAP_32BIG_C(0xdc11e525U), BSWAP_32BIG_C(0xb83abb23U),
                        BSWAP_32BIG_C(0x9c635c29U),
                    };
                    r_rsip_func101(Param_func434_func101_009);
                }

                WR1_PROG(REG_0094H, 0x000268a5U);

                static const uint32_t Param_func434_func100_012[] =
                {
                    BSWAP_32BIG_C(0x66285284U), BSWAP_32BIG_C(0xfdd7e936U), BSWAP_32BIG_C(0x9f94a5b0U), BSWAP_32BIG_C(
                        0xce9f230aU),
                };
                r_rsip_func100(Param_func434_func100_012);
                r_rsip_func103();

                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f434U, 0x00000000U);

                static const uint32_t Param_func434_func101_010[] =
                {
                    BSWAP_32BIG_C(0xeebb3b7fU), BSWAP_32BIG_C(0xa522415aU), BSWAP_32BIG_C(0xae503098U), BSWAP_32BIG_C(
                        0xf8126d7bU),
                };
                r_rsip_func101(Param_func434_func101_010);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x000034c1U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f434U, 0x00000000U);

                static const uint32_t Param_func434_func101_011[] =
                {
                    BSWAP_32BIG_C(0x09ed8bc7U), BSWAP_32BIG_C(0x0eece57eU), BSWAP_32BIG_C(0x93e9b27cU), BSWAP_32BIG_C(
                        0x245cada8U),
                };
                r_rsip_func101(Param_func434_func101_011);
                r_rsip_func044();

                static const uint32_t Param_func434_func100_013[] =
                {
                    BSWAP_32BIG_C(0xc5215e6eU), BSWAP_32BIG_C(0xff6499fdU), BSWAP_32BIG_C(0xd38e0cc7U), BSWAP_32BIG_C(
                        0x55d83e46U),
                };
                r_rsip_func100(Param_func434_func100_013);
                WR1_PROG(REG_00B0H, 0x00004809U);
                r_rsip_func_sub006(0x800100c0U, 0x03430005U, 0x00000842U, 0x00000821U);

                r_rsip_func_sub017(0x81010080U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub006(0x800100e0U, 0x03430005U, 0x01986cc7U, 0x00186ce7U);

                    r_rsip_func_sub022(0x00003cc1U, 0x01886cc7U, 0x0000a420U);
                    WR1_PROG(REG_0094H, 0x00000004U);
                    WR1_PROG(REG_0094H, 0x00002c40U);

                    static const uint32_t Param_func434_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x3f226259U), BSWAP_32BIG_C(0xffc61177U), BSWAP_32BIG_C(0x523339bcU),
                        BSWAP_32BIG_C(0x2761926eU),
                    };
                    r_rsip_func101(Param_func434_func101_012);
                }

                static const uint32_t Param_func434_func100_014[] =
                {
                    BSWAP_32BIG_C(0x7c2a6655U), BSWAP_32BIG_C(0x537f4006U), BSWAP_32BIG_C(0x1a5e538fU), BSWAP_32BIG_C(
                        0xeea8dfdeU),
                };
                r_rsip_func100(Param_func434_func100_014);
                r_rsip_func_sub016(0x38000844U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub022(0x0000b420U, 0x00000011U, 0x00002824U);

                WR1_PROG(REG_0094H, 0x00000884U);

                r_rsip_func_sub017(0x81010020U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x00000842U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub016(0x34202845U, 0x00000080U, 0x00270000U);

                    static const uint32_t Param_func434_func100_015[] =
                    {
                        BSWAP_32BIG_C(0xa590517fU), BSWAP_32BIG_C(0x22704166U), BSWAP_32BIG_C(0xeb8f5a4fU),
                        BSWAP_32BIG_C(0xb7fe7477U),
                    };
                    r_rsip_func100(Param_func434_func100_015);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_func434_func100_016[] =
                        {
                            BSWAP_32BIG_C(0x7677af36U), BSWAP_32BIG_C(0x1eb1bfe5U), BSWAP_32BIG_C(0x3692b81dU),
                            BSWAP_32BIG_C(0x8f71014fU),
                        };
                        r_rsip_func100(Param_func434_func100_016);

                        r_rsip_func_sub006(0x800100e0U, 0x03430005U, 0x01986cc7U, 0x00186ce7U);

                        r_rsip_func_sub017(0x810100c0U, 0x00005006U);
                        RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                        WR1_PROG(REG_0094H, 0x01886cc7U);
                        WR1_PROG(REG_0094H, 0x00002c40U);

                        static const uint32_t Param_func434_func101_013[] =
                        {
                            BSWAP_32BIG_C(0x53457ccdU), BSWAP_32BIG_C(0x32dc79e5U), BSWAP_32BIG_C(0xda44f9b3U),
                            BSWAP_32BIG_C(0x92332a98U),
                        };
                        r_rsip_func101(Param_func434_func101_013);
                    }
                    else
                    {
                        r_rsip_func_sub015(0x00030005U, 0x00001800U);

                        static const uint32_t Param_func434_func101_014[] =
                        {
                            BSWAP_32BIG_C(0x50fedae4U), BSWAP_32BIG_C(0x705e2303U), BSWAP_32BIG_C(0xbb1110b4U),
                            BSWAP_32BIG_C(0x4aa6a3a0U),
                        };
                        r_rsip_func101(Param_func434_func101_014);
                    }

                    WR1_PROG(REG_0094H, 0x00002c80U);

                    static const uint32_t Param_func434_func101_015[] =
                    {
                        BSWAP_32BIG_C(0x9ec3b392U), BSWAP_32BIG_C(0x48db1047U), BSWAP_32BIG_C(0xc4ba4e33U),
                        BSWAP_32BIG_C(0xe8e6fad6U),
                    };
                    r_rsip_func101(Param_func434_func101_015);
                }

                r_rsip_func_sub016(0x38000881U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub016(0x34202845U, 0x00000080U, 0x00270000U);

                static const uint32_t Param_func434_func100_017[] =
                {
                    BSWAP_32BIG_C(0xa1d13c30U), BSWAP_32BIG_C(0xbacc9e54U), BSWAP_32BIG_C(0x0cddecb7U), BSWAP_32BIG_C(
                        0xdd9d9016U),
                };
                r_rsip_func100(Param_func434_func100_017);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_018[] =
                    {
                        BSWAP_32BIG_C(0x897a6a0eU), BSWAP_32BIG_C(0x2386714eU), BSWAP_32BIG_C(0x492094bcU),
                        BSWAP_32BIG_C(0x81e1cdbbU),
                    };
                    r_rsip_func100(Param_func434_func100_018);

                    WR1_PROG(REG_0094H, 0x00186cc6U);

                    r_rsip_func_sub017(0x810100c0U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &ARG3[iLoop]);

                    static const uint32_t Param_func434_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x358d84c8U), BSWAP_32BIG_C(0x29602c75U), BSWAP_32BIG_C(0x11704b29U),
                        BSWAP_32BIG_C(0x418cb58fU),
                    };
                    r_rsip_func101(Param_func434_func101_016);
                }

                WR1_PROG(REG_0094H, 0x00000884U);

                r_rsip_func_sub010(0x38008820U, 0x0000000dU, 0x00270000U);

                static const uint32_t Param_func434_func100_019[] =
                {
                    BSWAP_32BIG_C(0xef8c2c8aU), BSWAP_32BIG_C(0x3fc40960U), BSWAP_32BIG_C(0x8290b5bbU), BSWAP_32BIG_C(
                        0xa205ef1bU),
                };
                r_rsip_func100(Param_func434_func100_019);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_func434_func100_020[] =
                    {
                        BSWAP_32BIG_C(0x5b11503aU), BSWAP_32BIG_C(0x6f21aed3U), BSWAP_32BIG_C(0x57e08d11U),
                        BSWAP_32BIG_C(0x2008b992U),
                    };
                    r_rsip_func100(Param_func434_func100_020);
                    WR1_PROG(REG_00D4H, 0x40000000U);
                    WR1_PROG(REG_00D0H, 0xe7009d05U);

                    r_rsip_func_sub012(0x81840004U, 0x00490011U);
                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[1]);

                    static const uint32_t Param_func434_func100_021[] =
                    {
                        BSWAP_32BIG_C(0x6e1d6142U), BSWAP_32BIG_C(0x25ed925bU), BSWAP_32BIG_C(0xbbf3da98U),
                        BSWAP_32BIG_C(0x7eb44714U),
                    };
                    r_rsip_func100(Param_func434_func100_021);
                    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                    RD4_ADDR(REG_002CH, &ARG2[5]);

                    static const uint32_t Param_func434_func101_017[] =
                    {
                        BSWAP_32BIG_C(0xcfb1c93cU), BSWAP_32BIG_C(0x9da2bcd5U), BSWAP_32BIG_C(0x4955c602U),
                        BSWAP_32BIG_C(0x266c56b7U),
                    };
                    r_rsip_func101(Param_func434_func101_017);
                }
                else
                {
                    static const uint32_t Param_func434_func100_022[] =
                    {
                        BSWAP_32BIG_C(0x0c82d0cfU), BSWAP_32BIG_C(0x6cb4360eU), BSWAP_32BIG_C(0x570a9496U),
                        BSWAP_32BIG_C(0x2f7a4f2aU),
                    };
                    r_rsip_func100(Param_func434_func100_022);
                    WR1_PROG(REG_00D4H, 0x40000100U);
                    WR1_PROG(REG_00D0H, 0xe7009d07U);

                    r_rsip_func_sub012(0x81880004U, 0x00490021U);
                    WR1_PROG(REG_0008H, 0x00001022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[1]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &ARG2[5]);

                    static const uint32_t Param_func434_func100_023[] =
                    {
                        BSWAP_32BIG_C(0xadb0e3b3U), BSWAP_32BIG_C(0x9fd3f454U), BSWAP_32BIG_C(0x096a45a2U),
                        BSWAP_32BIG_C(0xefc092e4U),
                    };
                    r_rsip_func100(Param_func434_func100_023);
                    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                    RD4_ADDR(REG_002CH, &ARG2[9]);

                    static const uint32_t Param_func434_func101_018[] =
                    {
                        BSWAP_32BIG_C(0x4a1d21d7U), BSWAP_32BIG_C(0x975bb219U), BSWAP_32BIG_C(0x4f6ef7f9U),
                        BSWAP_32BIG_C(0xf7df9869U),
                    };
                    r_rsip_func101(Param_func434_func101_018);
                }

                static const uint32_t Param_func434_func100_024[] =
                {
                    BSWAP_32BIG_C(0xd2bdcbcbU), BSWAP_32BIG_C(0xe0d6c594U), BSWAP_32BIG_C(0x5d0a85bcU), BSWAP_32BIG_C(
                        0x0656c93dU),
                };
                r_rsip_func100(Param_func434_func100_024);
                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &ARG2[0]);

                WR1_PROG(REG_0094H, 0x00000821U);

                static const uint32_t Param_func434_func101_019[] =
                {
                    BSWAP_32BIG_C(0xe4a86691U), BSWAP_32BIG_C(0xe072d141U), BSWAP_32BIG_C(0x90a0eeb3U), BSWAP_32BIG_C(
                        0x39290947U),
                };
                r_rsip_func101(Param_func434_func101_019);
            }

            static const uint32_t Param_func434_func101_020[] =
            {
                BSWAP_32BIG_C(0x28a961bdU), BSWAP_32BIG_C(0x5d96953bU), BSWAP_32BIG_C(0x327f0e13U), BSWAP_32BIG_C(
                    0x556eda86U),
            };
            r_rsip_func101(Param_func434_func101_020);
        }

        static const uint32_t Param_func434_func101_021[] =
        {
            BSWAP_32BIG_C(0xb8376146U), BSWAP_32BIG_C(0x3653c4b0U), BSWAP_32BIG_C(0x5f3e3754U), BSWAP_32BIG_C(
                0xe8508fcdU),
        };
        r_rsip_func101(Param_func434_func101_021);
    }

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
