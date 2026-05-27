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

rsip_ret_t r_rsip_pda (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_IVType[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_DataA[],
                       const uint32_t InData_DataALen[],
                       const uint32_t InData_EncAPDU[],
                       const uint32_t InData_EncAPDULen[],
                       const uint32_t InData_DataT[],
                       const uint32_t InData_DataTLen[],
                       uint32_t       OutData_Data1[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_Data2[],
                       uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00da0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x000000daU);

    static const uint32_t Param_pda_func101_001[] =
    {
        BSWAP_32BIG_C(0x80568a8cU), BSWAP_32BIG_C(0x34bd3df3U), BSWAP_32BIG_C(0x25239ccfU), BSWAP_32BIG_C(0x468dc38fU),
    };
    r_rsip_func101(Param_pda_func101_001);
    r_rsip_func431(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_pda_func100_001[] =
    {
        BSWAP_32BIG_C(0x29007ec7U), BSWAP_32BIG_C(0x2198ed14U), BSWAP_32BIG_C(0x5dcc556cU), BSWAP_32BIG_C(0x4426634aU),
    };
    r_rsip_func100(Param_pda_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pda_func102_001[] =
        {
            BSWAP_32BIG_C(0xdd6421a7U), BSWAP_32BIG_C(0x8f71060fU), BSWAP_32BIG_C(0x7ddd44eeU), BSWAP_32BIG_C(
                0xb7f1f9bcU),
        };
        r_rsip_func102(Param_pda_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_pda_func100_002[] =
        {
            BSWAP_32BIG_C(0xc99bb1c3U), BSWAP_32BIG_C(0x33c5f957U), BSWAP_32BIG_C(0x1a1f7456U), BSWAP_32BIG_C(
                0x61abf3fdU),
        };
        r_rsip_func100(Param_pda_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pda_func102_002[] =
            {
                BSWAP_32BIG_C(0x71f0121bU), BSWAP_32BIG_C(0xa4c0bb57U), BSWAP_32BIG_C(0x273c3cceU), BSWAP_32BIG_C(
                    0x7abea3ccU),
            };
            r_rsip_func102(Param_pda_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func430(InData_DataA, MAX_CNT);

            r_rsip_func432();

            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x80010060U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_EncAPDULen[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub007(0x3420a860U, 0x00000002U, 0x00260000U);

            WR1_PROG(REG_0094H, 0x0000b420U);
            r_rsip_func_sub007(0x00000048U, 0x34202823U, 0x00260000U);

            static const uint32_t Param_pda_func100_003[] =
            {
                BSWAP_32BIG_C(0xa165e769U), BSWAP_32BIG_C(0x1fbab735U), BSWAP_32BIG_C(0xd77b0ec3U), BSWAP_32BIG_C(
                    0xe2807513U),
            };
            r_rsip_func100(Param_pda_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pda_func102_003[] =
                {
                    BSWAP_32BIG_C(0xae142c1eU), BSWAP_32BIG_C(0xfb12969aU), BSWAP_32BIG_C(0xcdc41c3aU), BSWAP_32BIG_C(
                        0xe3b6127eU),
                };
                r_rsip_func102(Param_pda_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pda_func100_004[] =
                {
                    BSWAP_32BIG_C(0x2cec154aU), BSWAP_32BIG_C(0xd0bb474fU), BSWAP_32BIG_C(0xf31aad88U), BSWAP_32BIG_C(
                        0xb05325a5U),
                };
                r_rsip_func100(Param_pda_func100_004);

                WR1_PROG(REG_0094H, 0x000034a3U);
                WR1_PROG(REG_0094H, 0x000468a5U);

                r_rsip_func_sub015(0x00000884U, 0x810100a0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_00B0H, 0x00004409U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub008(0x000003c1U, 0x00008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);
                    r_rsip_func_sub009(0x00c10011U, 0x00002c80U);

                    static const uint32_t Param_pda_func101_002[] =
                    {
                        BSWAP_32BIG_C(0xd8c5419aU), BSWAP_32BIG_C(0x08365cc1U), BSWAP_32BIG_C(0x70da5551U),
                        BSWAP_32BIG_C(0x9fe722cfU),
                    };
                    r_rsip_func101(Param_pda_func101_002);
                }

                r_rsip_func_sub010(0x38000885U);

                WR1_PROG(REG_0094H, 0x00003403U);

                r_rsip_func_sub007(0x08008c00U, 0x0000000fU, 0x00A60000U);

                static const uint32_t Param_pda_func100_005[] =
                {
                    BSWAP_32BIG_C(0x3c3ea664U), BSWAP_32BIG_C(0x6b4cd262U), BSWAP_32BIG_C(0x8386bdf9U), BSWAP_32BIG_C(
                        0xe8c6d69dU),
                };
                r_rsip_func100(Param_pda_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub008(0x000003c1U, 0x00008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);

                    WR1_PROG(REG_0094H, 0x00000821U);
                    r_rsip_func_sub003(0x80840001U, 0x03410011U);

                    WR1_PROG(REG_0094H, 0x00000884U);
                    for (iLoop = 0U; iLoop < 16U; iLoop++)
                    {
                        r_rsip_func_sub016(0x3c002820U, 0x12003c81U, 0x00002c20U);
                    }

                    r_rsip_func_sub007(0x3420a860U, 0x00000040U, 0x00260000U);

                    static const uint32_t Param_pda_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x822ada52U), BSWAP_32BIG_C(0x0f07247fU), BSWAP_32BIG_C(0x1e66a9e5U),
                        BSWAP_32BIG_C(0x738fda79U),
                    };
                    r_rsip_func100(Param_pda_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0094H, 0x00000821U);
                        r_rsip_func_sub003(0x81840001U, 0x00c90011U);

                        static const uint32_t Param_pda_func101_003[] =
                        {
                            BSWAP_32BIG_C(0x2a4b24d4U), BSWAP_32BIG_C(0x9fd7f50cU), BSWAP_32BIG_C(0xcdf757a8U),
                            BSWAP_32BIG_C(0x824da217U),
                        };
                        r_rsip_func101(Param_pda_func101_003);
                    }
                    else
                    {
                        WR1_PROG(REG_0094H, 0x00000821U);
                        r_rsip_func_sub003(0x81820001U, 0x00c90009U);

                        static const uint32_t Param_pda_func101_004[] =
                        {
                            BSWAP_32BIG_C(0x7ea69cb7U), BSWAP_32BIG_C(0x70a61dfbU), BSWAP_32BIG_C(0x55537b62U),
                            BSWAP_32BIG_C(0x0a62cd87U),
                        };
                        r_rsip_func101(Param_pda_func101_004);
                    }

                    static const uint32_t Param_pda_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x5cc65c2fU), BSWAP_32BIG_C(0x19f6b053U), BSWAP_32BIG_C(0xe1f48bbdU),
                        BSWAP_32BIG_C(0xa3fe46b4U),
                    };
                    r_rsip_func101(Param_pda_func101_005);
                }

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub007(0x00000040U, 0x3c002823U, 0x00260000U);

                static const uint32_t Param_pda_func100_007[] =
                {
                    BSWAP_32BIG_C(0x884d6c98U), BSWAP_32BIG_C(0x36db0f26U), BSWAP_32BIG_C(0x4c2d0e47U), BSWAP_32BIG_C(
                        0x532924f5U),
                };
                r_rsip_func100(Param_pda_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pda_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x1c8493d5U), BSWAP_32BIG_C(0xc6d625b8U), BSWAP_32BIG_C(0xf7f13d4fU),
                        BSWAP_32BIG_C(0x64d12347U),
                    };
                    r_rsip_func100(Param_pda_func100_008);

                    r_rsip_func_sub016(0x00000884U, 0x000034a3U, 0x00000821U);
                    r_rsip_func_sub016(0x0c00a4a0U, 0x0000000fU, 0x00802481U);

                    r_rsip_func_sub016(0x018268a4U, 0x00008ca0U, 0xfffffffcU);

                    WR1_PROG(REG_0094H, 0x0000b480U);
                    WR1_PROG(REG_0094H, 0x00000012U);

                    r_rsip_func_sub015(0x00002885U, 0x81010080U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);

                    WR1_PROG(REG_0094H, 0x000008a5U);

                    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                    {
                        r_rsip_func_sub009(0x00c00005U, 0x00002ca0U);

                        static const uint32_t Param_pda_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xbaf2b265U), BSWAP_32BIG_C(0x135b8856U), BSWAP_32BIG_C(0xd5cd189eU),
                            BSWAP_32BIG_C(0x2c7482e2U),
                        };
                        r_rsip_func101(Param_pda_func101_006);
                    }

                    r_rsip_func_sub010(0x380008a4U);

                    static const uint32_t Param_pda_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x6bca002dU), BSWAP_32BIG_C(0x6cf7a29fU), BSWAP_32BIG_C(0x8bbcf699U),
                        BSWAP_32BIG_C(0x7f578f5dU),
                    };
                    r_rsip_func101(Param_pda_func101_007);
                }

                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x800100a0U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_DataTLen[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub007(0x380088a0U, 0x00000000U, 0x00260000U);

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub007(0x00000010U, 0x34202825U, 0x00260000U);

                static const uint32_t Param_pda_func100_009[] =
                {
                    BSWAP_32BIG_C(0xc5c59fd4U), BSWAP_32BIG_C(0x690984b4U), BSWAP_32BIG_C(0x5053b10dU), BSWAP_32BIG_C(
                        0xe6a2bbafU),
                };
                r_rsip_func100(Param_pda_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pda_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x6ad52961U), BSWAP_32BIG_C(0x0aada3c1U), BSWAP_32BIG_C(0x3f4dad49U),
                        BSWAP_32BIG_C(0xc7296e61U),
                    };
                    r_rsip_func102(Param_pda_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func_sub016(0x00000842U, 0x00003403U, 0x00036c63U);

                    r_rsip_func433(InData_DataALen, InData_DataT);

                    static const uint32_t Param_pda_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xa5382e64U), BSWAP_32BIG_C(0x0a9a6accU), BSWAP_32BIG_C(0xc9b4f2eeU),
                        BSWAP_32BIG_C(0xb2b2b05fU),
                    };
                    r_rsip_func100(Param_pda_func100_010);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pda_func102_005[] =
                        {
                            BSWAP_32BIG_C(0xd974fd88U), BSWAP_32BIG_C(0x2953009cU), BSWAP_32BIG_C(0x2e267ad9U),
                            BSWAP_32BIG_C(0xad013c20U),
                        };
                        r_rsip_func102(Param_pda_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_AUTH_FAIL;
                    }
                    else
                    {
                        r_rsip_func_sub002(0x800100e0U, 0x000000daU);

                        static const uint32_t Param_pda_func101_008[] =
                        {
                            BSWAP_32BIG_C(0x4926a67cU), BSWAP_32BIG_C(0x10eb88fcU), BSWAP_32BIG_C(0xc38e38d0U),
                            BSWAP_32BIG_C(0x93c5c008U),
                        };
                        r_rsip_func101(Param_pda_func101_008);
                        r_rsip_func434(OutData_Data1, OutData_KeyIndex, OutData_Data2);

                        WR1_PROG(REG_0094H, 0x38000c21U);
                        WR1_PROG(REG_009CH, 0x00000080U);
                        WR1_PROG(REG_0040H, 0x00260000U);

                        static const uint32_t Param_pda_func100_011[] =
                        {
                            BSWAP_32BIG_C(0x9ab4aa83U), BSWAP_32BIG_C(0x0df61b66U), BSWAP_32BIG_C(0x541bb126U),
                            BSWAP_32BIG_C(0xb3c8ffb4U),
                        };
                        r_rsip_func100(Param_pda_func100_011);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            static const uint32_t Param_pda_func102_006[] =
                            {
                                BSWAP_32BIG_C(0xb65325a2U), BSWAP_32BIG_C(0x4e6e07f8U), BSWAP_32BIG_C(0xcab61e9bU),
                                BSWAP_32BIG_C(0x49b361b8U),
                            };
                            r_rsip_func102(Param_pda_func102_006);
                            WR1_PROG(REG_006CH, 0x00000040U);
                            WAIT_STS(REG_0020H, 12, 0);

                            return RSIP_RET_PASS;
                        }
                        else
                        {
                            static const uint32_t Param_pda_func102_007[] =
                            {
                                BSWAP_32BIG_C(0xc38f907cU), BSWAP_32BIG_C(0xbd82d22eU), BSWAP_32BIG_C(0x74fc1c57U),
                                BSWAP_32BIG_C(0x2309efc0U),
                            };
                            r_rsip_func102(Param_pda_func102_007);
                            WR1_PROG(REG_006CH, 0x00000040U);
                            WAIT_STS(REG_0020H, 12, 0);

                            return RSIP_RET_VERIFICATION_FAIL;
                        }
                    }
                }
            }
        }
    }
}
