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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00e70001U, 0x000001c7U, 0x800200a0U);
    WR1_PROG(REG_002CH, InData_KDFInfo_Count[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_OutDataType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3000a8c0U, 0x00000007U, 0x00010020U);
    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x00000006U);
    r_rsip_func_sub007(0x00000080U, 0x38000ca5U, 0x00260000U);

    WR1_PROG(REG_0094H, 0x0000b400U);
    r_rsip_func_sub007(0x08000000U, 0x34202805U, 0x00260000U);

    r_rsip_func_sub007(0x380088c0U, 0x00000003U, 0x00260000U);

    r_rsip_func_sub007(0x380088c0U, 0x00000004U, 0x00260000U);

    r_rsip_func_sub007(0x380088c0U, 0x00000005U, 0x00260000U);

    static const uint32_t Param_pe7_func100_001[] =
    {
        BSWAP_32BIG_C(0x23444ccdU), BSWAP_32BIG_C(0x1cd09463U), BSWAP_32BIG_C(0xb77bdad9U), BSWAP_32BIG_C(0x983cc684U),
    };
    r_rsip_func100(Param_pe7_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe7_func102_001[] =
        {
            BSWAP_32BIG_C(0xddfd5b8dU), BSWAP_32BIG_C(0x35e0dbdaU), BSWAP_32BIG_C(0x27d6bc7eU), BSWAP_32BIG_C(
                0x5f0b986bU),
        };
        r_rsip_func102(Param_pe7_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe7_func100_002[] =
        {
            BSWAP_32BIG_C(0x86f86687U), BSWAP_32BIG_C(0xff12997fU), BSWAP_32BIG_C(0xa1367908U), BSWAP_32BIG_C(
                0x559d2aa0U),
        };
        r_rsip_func100(Param_pe7_func100_002);
        WR1_PROG(REG_0094H, 0x00007c06U);
        WR1_PROG(REG_0040H, 0x00600000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub002(0x80010080U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_001[] =
            {
                BSWAP_32BIG_C(0xb538c615U), BSWAP_32BIG_C(0x3ee41483U), BSWAP_32BIG_C(0x03237020U), BSWAP_32BIG_C(
                    0xe20726d7U),
            };
            r_rsip_func101(Param_pe7_func101_001);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub002(0x80010080U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_002[] =
            {
                BSWAP_32BIG_C(0xf7ca43bfU), BSWAP_32BIG_C(0xe1b1880cU), BSWAP_32BIG_C(0x4f28d81cU), BSWAP_32BIG_C(
                    0x66d165a6U),
            };
            r_rsip_func101(Param_pe7_func101_002);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub002(0x80010080U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_003[] =
            {
                BSWAP_32BIG_C(0x5ec3d184U), BSWAP_32BIG_C(0xac868236U), BSWAP_32BIG_C(0xb245df37U), BSWAP_32BIG_C(
                    0x2093fd3bU),
            };
            r_rsip_func101(Param_pe7_func101_003);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            r_rsip_func_sub002(0x80010080U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_004[] =
            {
                BSWAP_32BIG_C(0xe4a0dbffU), BSWAP_32BIG_C(0x2cb9ce63U), BSWAP_32BIG_C(0x3b067e2eU), BSWAP_32BIG_C(
                    0xcb488f39U),
            };
            r_rsip_func101(Param_pe7_func101_004);
        }

        WR1_PROG(REG_0094H, 0x0000b4e0U);
        WR1_PROG(REG_0094H, 0x00000010U);
        r_rsip_func_sub013(0x00003cc7U, 0x80010020U);
        WR1_PROG(REG_002CH, InData_OutDataLocation[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x00003405U, 0x00056c00U, 0x00003000U);

        r_rsip_func_sub007(0x00002481U, 0x34202804U, 0x00260000U);

        WR1_PROG(REG_0094H, 0x34202824U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00A60000U);

        static const uint32_t Param_pe7_func100_003[] =
        {
            BSWAP_32BIG_C(0x818762c0U), BSWAP_32BIG_C(0x2899c407U), BSWAP_32BIG_C(0x8cbdb209U), BSWAP_32BIG_C(
                0x4923b5b3U),
        };
        r_rsip_func100(Param_pe7_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe7_func102_002[] =
            {
                BSWAP_32BIG_C(0x99cebf8bU), BSWAP_32BIG_C(0xc73e0e3bU), BSWAP_32BIG_C(0x11f2effaU), BSWAP_32BIG_C(
                    0xba191fc4U),
            };
            r_rsip_func102(Param_pe7_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub016(0x000008c6U, 0x00000800U, 0x00000842U);

            WR1_PROG(REG_0094H, 0x00000863U);

            static const uint32_t Param_pe7_func100_004[] =
            {
                BSWAP_32BIG_C(0xf0290472U), BSWAP_32BIG_C(0x9ff95744U), BSWAP_32BIG_C(0x12bf3972U), BSWAP_32BIG_C(
                    0xaeda341fU),
            };
            r_rsip_func100(Param_pe7_func100_004);
            WR1_PROG(REG_009CH, 0x810100a0U);
            WR1_PROG(REG_0008H, 0x00005006U);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub016(0x0000b4e0U, 0x00000014U, 0x00003ca7U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_0094H, 0x34202880U);
                WR1_PROG(REG_009CH, 0x00000080U);
                WR1_PROG(REG_0040H, 0x00260000U);

                WR1_PROG(REG_0094H, 0x0000a400U);
                r_rsip_func_sub007(0x0000001fU, 0x34202801U, 0x00260000U);

                static const uint32_t Param_pe7_func100_005[] =
                {
                    BSWAP_32BIG_C(0x53394a86U), BSWAP_32BIG_C(0x64f23fc7U), BSWAP_32BIG_C(0xd426ae85U), BSWAP_32BIG_C(
                        0xa96a3de1U),
                };
                r_rsip_func100(Param_pe7_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pe7_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x7103159aU), BSWAP_32BIG_C(0x569f6e78U), BSWAP_32BIG_C(0x1715601dU),
                        BSWAP_32BIG_C(0x59512b03U),
                    };
                    r_rsip_func101(Param_pe7_func101_005);
                }
                else
                {
                    r_rsip_func_sub016(0x0000b4e0U, 0x00000018U, 0x00003c47U);

                    WR1_PROG(REG_0094H, 0x0000b4e0U);
                    WR1_PROG(REG_0094H, 0x0000001cU);
                    r_rsip_func_sub013(0x00003cc7U, 0x800100c0U);
                    WR1_PROG(REG_002CH, InData_KDFInfo[iLoop * 13]);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    r_rsip_func_sub002(0x800100e0U, 0x0000e701U);

                    static const uint32_t Param_pe7_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x83b2f70cU), BSWAP_32BIG_C(0x627201afU), BSWAP_32BIG_C(0x8ceab0a4U),
                        BSWAP_32BIG_C(0x1a4ba328U),
                    };
                    r_rsip_func101(Param_pe7_func101_006);
                    r_rsip_func143();

                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x01799093U);

                    r_rsip_func_sub002(0x800100e0U, 0x0000e701U);

                    static const uint32_t Param_pe7_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xce406ce6U), BSWAP_32BIG_C(0x09f47874U), BSWAP_32BIG_C(0x99ee286eU),
                        BSWAP_32BIG_C(0x0b6c739fU),
                    };
                    r_rsip_func101(Param_pe7_func101_007);
                    r_rsip_func044();

                    WR1_PROG(REG_0094H, 0x38000c63U);
                    WR1_PROG(REG_009CH, 0x00000080U);
                    WR1_PROG(REG_0040H, 0x00260000U);

                    static const uint32_t Param_pe7_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x760f25b8U), BSWAP_32BIG_C(0x2d1e4780U), BSWAP_32BIG_C(0xc2f55ca6U),
                        BSWAP_32BIG_C(0x44ae6a4eU),
                    };
                    r_rsip_func100(Param_pe7_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_00B0H, 0x00001404U);

                        static const uint32_t Param_pe7_func101_008[] =
                        {
                            BSWAP_32BIG_C(0xc2c1d9b9U), BSWAP_32BIG_C(0x387a7e59U), BSWAP_32BIG_C(0x2bf55b95U),
                            BSWAP_32BIG_C(0x19d56ec8U),
                        };
                        r_rsip_func101(Param_pe7_func101_008);
                    }
                    else
                    {
                        WR1_PROG(REG_00B0H, 0x00001408U);

                        static const uint32_t Param_pe7_func101_009[] =
                        {
                            BSWAP_32BIG_C(0x68ce6d75U), BSWAP_32BIG_C(0x3bbdd06fU), BSWAP_32BIG_C(0x9a333aa0U),
                            BSWAP_32BIG_C(0x97bda50dU),
                        };
                        r_rsip_func101(Param_pe7_func101_009);
                    }

                    r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

                    r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

                    r_rsip_func_sub008(0x000007c1U, 0x40000100U, 0xf7008d07U);
                    WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 1]);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 5]);

                    r_rsip_func_sub009(0x00c10021U, 0x00002c60U);

                    r_rsip_func_sub016(0x0000b4e0U, 0x00000018U, 0x00003847U);

                    r_rsip_func_sub016(0x0000b4e0U, 0x0000001cU, 0x000038c7U);

                    r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
                    WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 9]);

                    r_rsip_func_sub006(0x9c100005U, 0x00410011U);

                    static const uint32_t Param_pe7_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x0df102a4U), BSWAP_32BIG_C(0xe26020ceU), BSWAP_32BIG_C(0x4c02d3a9U),
                        BSWAP_32BIG_C(0xdcce7c9aU),
                    };
                    r_rsip_func100(Param_pe7_func100_007);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0094H, 0x0000d040U);
                        static const uint32_t Param_pe7_func101_010[] =
                        {
                            BSWAP_32BIG_C(0x5f124310U), BSWAP_32BIG_C(0x15de0e46U), BSWAP_32BIG_C(0xf828f69cU),
                            BSWAP_32BIG_C(0x98e30fd9U),
                        };
                        r_rsip_func101(Param_pe7_func101_010);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func101_011[] =
                        {
                            BSWAP_32BIG_C(0x8f26ae97U), BSWAP_32BIG_C(0xd952a7abU), BSWAP_32BIG_C(0x60d8465eU),
                            BSWAP_32BIG_C(0x828732f6U),
                        };
                        r_rsip_func101(Param_pe7_func101_011);
                    }
                }

                WR1_PROG(REG_0094H, 0x00002c00U);

                WR1_PROG(REG_0094H, 0x00002cc0U);

                static const uint32_t Param_pe7_func101_012[] =
                {
                    BSWAP_32BIG_C(0x1e3eb30dU), BSWAP_32BIG_C(0xe33f2eaeU), BSWAP_32BIG_C(0xc51827a1U), BSWAP_32BIG_C(
                        0xaef949cdU),
                };
                r_rsip_func101(Param_pe7_func101_012);
            }

            WR1_PROG(REG_0094H, 0x0000b4e0U);
            WR1_PROG(REG_0094H, 0x00000014U);
            r_rsip_func_sub007(0x00003807U, 0x380008c0U, 0x00260000U);
            WR1_PROG(REG_0040H, 0x00402000U);
            r_rsip_func_sub012(0x38000c42U, 0x00A60000U);
            static const uint32_t Param_pe7_func100_008[] =
            {
                BSWAP_32BIG_C(0x05d9184dU), BSWAP_32BIG_C(0x5a5d455eU), BSWAP_32BIG_C(0xf473ef91U), BSWAP_32BIG_C(
                    0x6a60a711U),
            };
            r_rsip_func100(Param_pe7_func100_008);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe7_func102_003[] =
                {
                    BSWAP_32BIG_C(0xa7623a25U), BSWAP_32BIG_C(0x8b353fd5U), BSWAP_32BIG_C(0x3626c7f8U), BSWAP_32BIG_C(
                        0xebe92818U),
                };
                r_rsip_func102(Param_pe7_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe7_func100_009[] =
                {
                    BSWAP_32BIG_C(0x6e3390c6U), BSWAP_32BIG_C(0x16b03663U), BSWAP_32BIG_C(0x8a964c98U), BSWAP_32BIG_C(
                        0xc9c03e28U),
                };
                r_rsip_func100(Param_pe7_func100_009);
                r_rsip_func103();

                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e702U);

                static const uint32_t Param_pe7_func101_013[] =
                {
                    BSWAP_32BIG_C(0xa26a80f0U), BSWAP_32BIG_C(0x41d39635U), BSWAP_32BIG_C(0xef1d688eU), BSWAP_32BIG_C(
                        0x8fc07632U),
                };
                r_rsip_func101(Param_pe7_func101_013);
                r_rsip_func143();

                r_rsip_func_sub016(0x0000b4e0U, 0x00000010U, 0x00003847U);

                static const uint32_t Param_pe7_func100_010[] =
                {
                    BSWAP_32BIG_C(0x0e5b3b63U), BSWAP_32BIG_C(0x7c825af4U), BSWAP_32BIG_C(0x7431cdb6U), BSWAP_32BIG_C(
                        0x4c3033d8U),
                };
                r_rsip_func100(Param_pe7_func100_010);
                WR1_PROG(REG_0094H, 0x00007c02U);
                WR1_PROG(REG_0040H, 0x00600000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x00000005U);

                    static const uint32_t Param_pe7_func101_014[] =
                    {
                        BSWAP_32BIG_C(0x8ea22a0bU), BSWAP_32BIG_C(0x188481b0U), BSWAP_32BIG_C(0x068358b5U),
                        BSWAP_32BIG_C(0x0609b96aU),
                    };
                    r_rsip_func101(Param_pe7_func101_014);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x00000007U);

                    static const uint32_t Param_pe7_func101_015[] =
                    {
                        BSWAP_32BIG_C(0x8f507f14U), BSWAP_32BIG_C(0x2f6f28cfU), BSWAP_32BIG_C(0x54dc319eU),
                        BSWAP_32BIG_C(0x11cdfa89U),
                    };
                    r_rsip_func101(Param_pe7_func101_015);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x0199e556U);

                    static const uint32_t Param_pe7_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x40faba00U), BSWAP_32BIG_C(0x16b5eab8U), BSWAP_32BIG_C(0x5df2f576U),
                        BSWAP_32BIG_C(0xc5ba8585U),
                    };
                    r_rsip_func101(Param_pe7_func101_016);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x0000001bU);

                    static const uint32_t Param_pe7_func101_017[] =
                    {
                        BSWAP_32BIG_C(0x370ed2e7U), BSWAP_32BIG_C(0x0de1980bU), BSWAP_32BIG_C(0xb2cc6a1fU),
                        BSWAP_32BIG_C(0xdcdefb6aU),
                    };
                    r_rsip_func101(Param_pe7_func101_017);
                }

                r_rsip_func_sub002(0x800100e0U, 0x0000e702U);

                static const uint32_t Param_pe7_func101_018[] =
                {
                    BSWAP_32BIG_C(0xb2838e5fU), BSWAP_32BIG_C(0x7ddef38eU), BSWAP_32BIG_C(0x32f21c1aU), BSWAP_32BIG_C(
                        0xc0d33dcdU),
                };
                r_rsip_func101(Param_pe7_func101_018);
                r_rsip_func044();

                r_rsip_func_sub016(0x00008c20U, 0x0000001fU, 0x000008e7U);

                WR1_PROG(REG_0094H, 0x000008a5U);

                r_rsip_func_sub007(0x38008860U, 0x00000001U, 0x00260000U);

                static const uint32_t Param_pe7_func100_011[] =
                {
                    BSWAP_32BIG_C(0x51b794c7U), BSWAP_32BIG_C(0x9c85fe03U), BSWAP_32BIG_C(0x66eb37a1U), BSWAP_32BIG_C(
                        0xd60a4d3bU),
                };
                r_rsip_func100(Param_pe7_func100_011);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x0000b480U);
                    WR1_PROG(REG_0094H, 0x00000020U);
                    WR1_PROG(REG_00B0H, 0x00001804U);

                    static const uint32_t Param_pe7_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x8a0741e6U), BSWAP_32BIG_C(0x83843246U), BSWAP_32BIG_C(0x36041072U),
                        BSWAP_32BIG_C(0x17bcd42cU),
                    };
                    r_rsip_func101(Param_pe7_func101_019);
                }
                else
                {
                    WR1_PROG(REG_0094H, 0x0000b480U);
                    WR1_PROG(REG_0094H, 0x00000040U);
                    WR1_PROG(REG_00B0H, 0x00003808U);

                    static const uint32_t Param_pe7_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x86fc0914U), BSWAP_32BIG_C(0x8c19584bU), BSWAP_32BIG_C(0xa76de44bU),
                        BSWAP_32BIG_C(0xaa52932aU),
                    };
                    r_rsip_func101(Param_pe7_func101_020);
                }

                static const uint32_t Param_pe7_func100_012[] =
                {
                    BSWAP_32BIG_C(0xd2e3eddcU), BSWAP_32BIG_C(0xd1491349U), BSWAP_32BIG_C(0xb8834944U), BSWAP_32BIG_C(
                        0xd146fcc7U),
                };
                r_rsip_func100(Param_pe7_func100_012);
                WR1_PROG(REG_009CH, 0x81010080U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    WR1_PROG(REG_0094H, 0x342028a1U);
                    WR1_PROG(REG_009CH, 0x00000080U);
                    WR1_PROG(REG_0040H, 0x00260000U);

                    r_rsip_func_sub007(0x3420a8e0U, 0x00000020U, 0x00A60000U);

                    static const uint32_t Param_pe7_func100_013[] =
                    {
                        BSWAP_32BIG_C(0xd616a99cU), BSWAP_32BIG_C(0xee776c24U), BSWAP_32BIG_C(0x19791fe6U),
                        BSWAP_32BIG_C(0xeaf143eeU),
                    };
                    r_rsip_func100(Param_pe7_func100_013);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0000H, 0x1000000dU);
                        WAIT_STS(REG_0004H, 30, 0);
                        WR1_PROG(REG_0040H, 0x00001800U);
                        WR1_PROG(REG_0000H, 0x10030005U);
                        WAIT_STS(REG_0004H, 30, 0);
                        WR1_PROG(REG_0040H, 0x00001800U);

                        static const uint32_t Param_pe7_func101_021[] =
                        {
                            BSWAP_32BIG_C(0xee4eb7abU), BSWAP_32BIG_C(0xa029b9d6U), BSWAP_32BIG_C(0x51d34a7bU),
                            BSWAP_32BIG_C(0xb235c07fU),
                        };
                        r_rsip_func101(Param_pe7_func101_021);
                    }
                    else
                    {
                        r_rsip_func_sub003(0x800100c0U, 0x1340000dU);
                        r_rsip_func_sub009(0x13430005U, 0x02003cc7U);

                        WR1_PROG(REG_0094H, 0x00002ce0U);

                        static const uint32_t Param_pe7_func101_022[] =
                        {
                            BSWAP_32BIG_C(0x8b083f32U), BSWAP_32BIG_C(0xbe550ebaU), BSWAP_32BIG_C(0x21f31c86U),
                            BSWAP_32BIG_C(0x98fffd3cU),
                        };
                        r_rsip_func101(Param_pe7_func101_022);
                    }

                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_pe7_func101_023[] =
                    {
                        BSWAP_32BIG_C(0xbb203d3fU), BSWAP_32BIG_C(0x168b8066U), BSWAP_32BIG_C(0x0fd3877eU),
                        BSWAP_32BIG_C(0x4750a2d2U),
                    };
                    r_rsip_func101(Param_pe7_func101_023);
                }

                r_rsip_func_sub010(0x380008a4U);

                WR1_PROG(REG_0094H, 0x0000b4e0U);
                WR1_PROG(REG_0094H, 0x00000000U);

                r_rsip_func_sub007(0x3420a840U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_pe7_func100_014[] =
                {
                    BSWAP_32BIG_C(0x09ea0d90U), BSWAP_32BIG_C(0xc2759f7cU), BSWAP_32BIG_C(0x1e737daeU), BSWAP_32BIG_C(
                        0xc66675f8U),
                };
                r_rsip_func100(Param_pe7_func100_014);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x38000c42U);
                    WR1_PROG(REG_009CH, 0x00000080U);
                    WR1_PROG(REG_0040H, 0x00260000U);

                    static const uint32_t Param_pe7_func100_015[] =
                    {
                        BSWAP_32BIG_C(0xd7d82226U), BSWAP_32BIG_C(0x35716785U), BSWAP_32BIG_C(0xe16e59b9U),
                        BSWAP_32BIG_C(0xfdbe682aU),
                    };
                    r_rsip_func100(Param_pe7_func100_015);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_016[] =
                        {
                            BSWAP_32BIG_C(0x8069ac5aU), BSWAP_32BIG_C(0x5af201e6U), BSWAP_32BIG_C(0xbf393810U),
                            BSWAP_32BIG_C(0x67a8b293U),
                        };
                        r_rsip_func100(Param_pe7_func100_016);
                        WR1_PROG(REG_00D4H, 0x40000000U);
                        WR1_PROG(REG_00D0H, 0xe7009d05U);

                        r_rsip_func_sub003(0x81840007U, 0x00490011U);
                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);

                        static const uint32_t Param_pe7_func100_017[] =
                        {
                            BSWAP_32BIG_C(0x83be8878U), BSWAP_32BIG_C(0xe91559c6U), BSWAP_32BIG_C(0x280dafe4U),
                            BSWAP_32BIG_C(0x278d93c0U),
                        };
                        r_rsip_func100(Param_pe7_func100_017);
                        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_00D4H, 0x40000000U);
                        r_rsip_func_sub006(0x09108105U, 0x00410011U);

                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x13a25e80U), BSWAP_32BIG_C(0x16caa0e6U), BSWAP_32BIG_C(0x4a9a81aaU),
                            BSWAP_32BIG_C(0xbfc37d6eU),
                        };
                        r_rsip_func101(Param_pe7_func101_024);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_018[] =
                        {
                            BSWAP_32BIG_C(0x0be92dc2U), BSWAP_32BIG_C(0x6184d31fU), BSWAP_32BIG_C(0x4afecabfU),
                            BSWAP_32BIG_C(0xdca9fd83U),
                        };
                        r_rsip_func100(Param_pe7_func100_018);
                        WR1_PROG(REG_00D4H, 0x40000100U);
                        WR1_PROG(REG_00D0H, 0xe7009d07U);

                        r_rsip_func_sub003(0x81880007U, 0x00490021U);
                        WR1_PROG(REG_0008H, 0x00001022U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func100_019[] =
                        {
                            BSWAP_32BIG_C(0x44ccc008U), BSWAP_32BIG_C(0x682fb7abU), BSWAP_32BIG_C(0xd6862dd9U),
                            BSWAP_32BIG_C(0x2cb7c7a1U),
                        };
                        r_rsip_func100(Param_pe7_func100_019);
                        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_00D4H, 0x40000000U);
                        r_rsip_func_sub006(0x09108105U, 0x00410011U);

                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[9]);

                        static const uint32_t Param_pe7_func101_025[] =
                        {
                            BSWAP_32BIG_C(0x76c83d11U), BSWAP_32BIG_C(0x65beced1U), BSWAP_32BIG_C(0x26eac509U),
                            BSWAP_32BIG_C(0xe214e2c1U),
                        };
                        r_rsip_func101(Param_pe7_func101_025);
                    }

                    static const uint32_t Param_pe7_func100_020[] =
                    {
                        BSWAP_32BIG_C(0x20f39bcbU), BSWAP_32BIG_C(0xbbf1ffe7U), BSWAP_32BIG_C(0x636ac79eU),
                        BSWAP_32BIG_C(0xe0b48692U),
                    };
                    r_rsip_func100(Param_pe7_func100_020);
                    WR1_PROG(REG_009CH, 0x81010000U);
                    WR1_PROG(REG_0008H, 0x00005006U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe7_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x3efb1c6bU), BSWAP_32BIG_C(0x90307becU), BSWAP_32BIG_C(0x424f984fU),
                        BSWAP_32BIG_C(0xe1e2d288U),
                    };
                    r_rsip_func102(Param_pe7_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
                else
                {
                    r_rsip_func_sub007(0x3420a840U, 0x00000006U, 0x00A60000U);

                    static const uint32_t Param_pe7_func100_021[] =
                    {
                        BSWAP_32BIG_C(0x54dc6648U), BSWAP_32BIG_C(0xf6674d58U), BSWAP_32BIG_C(0xec193d6eU),
                        BSWAP_32BIG_C(0x7afa0270U),
                    };
                    r_rsip_func100(Param_pe7_func100_021);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_022[] =
                        {
                            BSWAP_32BIG_C(0x4bb49e14U), BSWAP_32BIG_C(0x897e9aa3U), BSWAP_32BIG_C(0x87997f5fU),
                            BSWAP_32BIG_C(0x85cc3c46U),
                        };
                        r_rsip_func100(Param_pe7_func100_022);
                        WR1_PROG(REG_00D4H, 0x40000100U);
                        WR1_PROG(REG_00D0H, 0xe7009d07U);

                        r_rsip_func_sub003(0x81880007U, 0x00490021U);
                        WR1_PROG(REG_0008H, 0x00001022U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[1]);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[5]);

                        static const uint32_t Param_pe7_func100_023[] =
                        {
                            BSWAP_32BIG_C(0x24135ccfU), BSWAP_32BIG_C(0xf5dbaa30U), BSWAP_32BIG_C(0xfaa6067aU),
                            BSWAP_32BIG_C(0x53dad97bU),
                        };
                        r_rsip_func100(Param_pe7_func100_023);
                        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_00D4H, 0x40000000U);
                        r_rsip_func_sub006(0x09108105U, 0x00410011U);

                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[9]);

                        static const uint32_t Param_pe7_func100_024[] =
                        {
                            BSWAP_32BIG_C(0xbc184f28U), BSWAP_32BIG_C(0xc2030cbaU), BSWAP_32BIG_C(0x261c2225U),
                            BSWAP_32BIG_C(0x0ccc61eeU),
                        };
                        r_rsip_func100(Param_pe7_func100_024);
                        WR1_PROG(REG_009CH, 0x81010000U);
                        WR1_PROG(REG_0008H, 0x00005006U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD1_ADDR(REG_002CH, &OutData_HMACKeyIndex[0]);

                        static const uint32_t Param_pe7_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x9746947bU), BSWAP_32BIG_C(0x1505a3e7U), BSWAP_32BIG_C(0xc487f28fU),
                            BSWAP_32BIG_C(0x09835b77U),
                        };
                        r_rsip_func102(Param_pe7_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_025[] =
                        {
                            BSWAP_32BIG_C(0xee3d3854U), BSWAP_32BIG_C(0xe7aa18eeU), BSWAP_32BIG_C(0x2a27f125U),
                            BSWAP_32BIG_C(0xe8fa696fU),
                        };
                        r_rsip_func100(Param_pe7_func100_025);
                        WR1_PROG(REG_00D4H, 0x40000000U);
                        WR1_PROG(REG_00D0H, 0xe7009d05U);

                        r_rsip_func_sub003(0x81840007U, 0x00490011U);
                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_EncIV[1]);

                        static const uint32_t Param_pe7_func100_026[] =
                        {
                            BSWAP_32BIG_C(0x15471752U), BSWAP_32BIG_C(0xd761a449U), BSWAP_32BIG_C(0x32733ee0U),
                            BSWAP_32BIG_C(0x2e3a128fU),
                        };
                        r_rsip_func100(Param_pe7_func100_026);
                        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_00D4H, 0x40000000U);
                        r_rsip_func_sub006(0x09108105U, 0x00410011U);

                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_EncIV[5]);

                        static const uint32_t Param_pe7_func100_027[] =
                        {
                            BSWAP_32BIG_C(0x64711f3cU), BSWAP_32BIG_C(0x0747c734U), BSWAP_32BIG_C(0x473fc529U),
                            BSWAP_32BIG_C(0x4ee0b68dU),
                        };
                        r_rsip_func100(Param_pe7_func100_027);
                        WR1_PROG(REG_009CH, 0x81010000U);
                        WR1_PROG(REG_0008H, 0x00005006U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD1_ADDR(REG_002CH, &OutData_EncIV[0]);

                        static const uint32_t Param_pe7_func102_006[] =
                        {
                            BSWAP_32BIG_C(0x69f2a2f0U), BSWAP_32BIG_C(0x6b9b7794U), BSWAP_32BIG_C(0xc8ad6f57U),
                            BSWAP_32BIG_C(0xa4b5ed3eU),
                        };
                        r_rsip_func102(Param_pe7_func102_006);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
