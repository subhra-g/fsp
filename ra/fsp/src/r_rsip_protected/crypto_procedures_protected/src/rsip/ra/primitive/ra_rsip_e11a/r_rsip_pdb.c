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

rsip_ret_t r_rsip_pdb (const uint32_t InData_KeyIndex[],
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

    WR1_PROG(REG_0070H, 0x00db0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x000000dbU);

    static const uint32_t Param_pdb_func101_001[] =
    {
        BSWAP_32BIG_C(0x1600e55cU), BSWAP_32BIG_C(0xc673a26fU), BSWAP_32BIG_C(0x29a8dfbbU), BSWAP_32BIG_C(0x656ba6aaU),
    };
    r_rsip_func101(Param_pdb_func101_001);
    r_rsip_func435(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_pdb_func100_001[] =
    {
        BSWAP_32BIG_C(0x1eb43041U), BSWAP_32BIG_C(0x09212ed8U), BSWAP_32BIG_C(0x418451cfU), BSWAP_32BIG_C(0x878ffc13U),
    };
    r_rsip_func100(Param_pdb_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pdb_func102_001[] =
        {
            BSWAP_32BIG_C(0xb35089d0U), BSWAP_32BIG_C(0x1b30ed19U), BSWAP_32BIG_C(0xb48fe9a6U), BSWAP_32BIG_C(
                0x208c8716U),
        };
        r_rsip_func102(Param_pdb_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_pdb_func100_002[] =
        {
            BSWAP_32BIG_C(0x250f61ecU), BSWAP_32BIG_C(0xdc9f2f8cU), BSWAP_32BIG_C(0xb028faa5U), BSWAP_32BIG_C(
                0x883c2d7aU),
        };
        r_rsip_func100(Param_pdb_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pdb_func102_002[] =
            {
                BSWAP_32BIG_C(0x8310f83eU), BSWAP_32BIG_C(0xe66a160fU), BSWAP_32BIG_C(0x9621b0f8U), BSWAP_32BIG_C(
                    0x31cada8fU),
            };
            r_rsip_func102(Param_pdb_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func430(InData_DataA, MAX_CNT);

            r_rsip_func436();

            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x80010060U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_EncAPDULen[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub007(0x3420a860U, 0x00000002U, 0x00260000U);

            WR1_PROG(REG_0094H, 0x0000b420U);
            r_rsip_func_sub007(0x00000048U, 0x34202823U, 0x00260000U);

            static const uint32_t Param_pdb_func100_003[] =
            {
                BSWAP_32BIG_C(0x9420aacaU), BSWAP_32BIG_C(0xb9d632b4U), BSWAP_32BIG_C(0x2688b5b6U), BSWAP_32BIG_C(
                    0x37e6ad06U),
            };
            r_rsip_func100(Param_pdb_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pdb_func102_003[] =
                {
                    BSWAP_32BIG_C(0x1a6cbcc4U), BSWAP_32BIG_C(0xc883346eU), BSWAP_32BIG_C(0x895feeccU), BSWAP_32BIG_C(
                        0x051747b6U),
                };
                r_rsip_func102(Param_pdb_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pdb_func100_004[] =
                {
                    BSWAP_32BIG_C(0x0afc7004U), BSWAP_32BIG_C(0x4497e28fU), BSWAP_32BIG_C(0xbf33fed6U), BSWAP_32BIG_C(
                        0x6119f9d4U),
                };
                r_rsip_func100(Param_pdb_func100_004);

                WR1_PROG(REG_0094H, 0x000034a3U);
                WR1_PROG(REG_0094H, 0x000468a5U);

                r_rsip_func_sub015(0x00000884U, 0x810100a0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_00B0H, 0x00004409U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub008(0x000003c1U, 0x40008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);
                    r_rsip_func_sub009(0x00c10011U, 0x00002c80U);

                    static const uint32_t Param_pdb_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x72a57876U), BSWAP_32BIG_C(0x01e98868U), BSWAP_32BIG_C(0xedf056c9U),
                        BSWAP_32BIG_C(0x55cc954cU),
                    };
                    r_rsip_func101(Param_pdb_func101_002);
                }

                r_rsip_func_sub010(0x38000885U);

                WR1_PROG(REG_0094H, 0x00003403U);

                r_rsip_func_sub007(0x08008c00U, 0x0000000fU, 0x00A60000U);

                static const uint32_t Param_pdb_func100_005[] =
                {
                    BSWAP_32BIG_C(0x14814a1bU), BSWAP_32BIG_C(0x1c1b1247U), BSWAP_32BIG_C(0xb5f8cbeaU), BSWAP_32BIG_C(
                        0xcec4a917U),
                };
                r_rsip_func100(Param_pdb_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub008(0x000003c1U, 0x40008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);

                    WR1_PROG(REG_0094H, 0x00000821U);
                    r_rsip_func_sub003(0x80840001U, 0x03410011U);

                    WR1_PROG(REG_0094H, 0x00000884U);
                    for (iLoop = 0U; iLoop < 16U; iLoop++)
                    {
                        r_rsip_func_sub016(0x3c002820U, 0x12003c81U, 0x00002c20U);
                    }

                    r_rsip_func_sub007(0x3420a860U, 0x00000040U, 0x00260000U);

                    static const uint32_t Param_pdb_func100_006[] =
                    {
                        BSWAP_32BIG_C(0xa85e6a5fU), BSWAP_32BIG_C(0x2d7af04aU), BSWAP_32BIG_C(0xa9ee5034U),
                        BSWAP_32BIG_C(0x71815676U),
                    };
                    r_rsip_func100(Param_pdb_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0094H, 0x00000821U);
                        r_rsip_func_sub003(0x81840001U, 0x00c90011U);

                        static const uint32_t Param_pdb_func101_003[] =
                        {
                            BSWAP_32BIG_C(0xd7ab1aefU), BSWAP_32BIG_C(0xd80f17b1U), BSWAP_32BIG_C(0xa5e1d76eU),
                            BSWAP_32BIG_C(0x6d6aa226U),
                        };
                        r_rsip_func101(Param_pdb_func101_003);
                    }
                    else
                    {
                        WR1_PROG(REG_0094H, 0x00000821U);
                        r_rsip_func_sub003(0x81820001U, 0x00c90009U);

                        static const uint32_t Param_pdb_func101_004[] =
                        {
                            BSWAP_32BIG_C(0x361ed6f8U), BSWAP_32BIG_C(0xd0508a20U), BSWAP_32BIG_C(0x37dbba3dU),
                            BSWAP_32BIG_C(0xf5db33aeU),
                        };
                        r_rsip_func101(Param_pdb_func101_004);
                    }

                    static const uint32_t Param_pdb_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x44707efdU), BSWAP_32BIG_C(0xa1d62784U), BSWAP_32BIG_C(0xa576f578U),
                        BSWAP_32BIG_C(0x2ee5b815U),
                    };
                    r_rsip_func101(Param_pdb_func101_005);
                }

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub007(0x00000040U, 0x3c002823U, 0x00260000U);

                static const uint32_t Param_pdb_func100_007[] =
                {
                    BSWAP_32BIG_C(0x7b7d3c0dU), BSWAP_32BIG_C(0xe963bc92U), BSWAP_32BIG_C(0xa344c2c3U), BSWAP_32BIG_C(
                        0xbb64a017U),
                };
                r_rsip_func100(Param_pdb_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pdb_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x8227ca85U), BSWAP_32BIG_C(0x2ec6beb1U), BSWAP_32BIG_C(0x2786a221U),
                        BSWAP_32BIG_C(0x9d63ff64U),
                    };
                    r_rsip_func100(Param_pdb_func100_008);

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

                        static const uint32_t Param_pdb_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x55dea591U), BSWAP_32BIG_C(0x651b0500U), BSWAP_32BIG_C(0x57c93160U),
                            BSWAP_32BIG_C(0x08df808bU),
                        };
                        r_rsip_func101(Param_pdb_func101_006);
                    }

                    r_rsip_func_sub010(0x380008a4U);

                    static const uint32_t Param_pdb_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xe2df960fU), BSWAP_32BIG_C(0xe647f61fU), BSWAP_32BIG_C(0x00b96585U),
                        BSWAP_32BIG_C(0x18aac3a9U),
                    };
                    r_rsip_func101(Param_pdb_func101_007);
                }

                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x800100a0U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_DataTLen[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub007(0x380088a0U, 0x00000000U, 0x00260000U);

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub007(0x00000010U, 0x34202825U, 0x00260000U);

                static const uint32_t Param_pdb_func100_009[] =
                {
                    BSWAP_32BIG_C(0xd0ec2152U), BSWAP_32BIG_C(0xfa8db4d6U), BSWAP_32BIG_C(0x5f4e9615U), BSWAP_32BIG_C(
                        0xbc6d3580U),
                };
                r_rsip_func100(Param_pdb_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pdb_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xceaa2b57U), BSWAP_32BIG_C(0x2521943aU), BSWAP_32BIG_C(0x6242b6e9U),
                        BSWAP_32BIG_C(0x220e2e61U),
                    };
                    r_rsip_func102(Param_pdb_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func_sub016(0x00000842U, 0x00003403U, 0x00036c63U);

                    r_rsip_func437(InData_DataALen, InData_DataT);

                    static const uint32_t Param_pdb_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x494ad4a5U), BSWAP_32BIG_C(0x0fd9e5ecU), BSWAP_32BIG_C(0xc5656ca4U),
                        BSWAP_32BIG_C(0x7bd92fc2U),
                    };
                    r_rsip_func100(Param_pdb_func100_010);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pdb_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x36766daaU), BSWAP_32BIG_C(0x7eeb4479U), BSWAP_32BIG_C(0xd7806f5eU),
                            BSWAP_32BIG_C(0xfdcd50a5U),
                        };
                        r_rsip_func102(Param_pdb_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_AUTH_FAIL;
                    }
                    else
                    {
                        r_rsip_func_sub002(0x800100e0U, 0x000000dbU);

                        static const uint32_t Param_pdb_func101_008[] =
                        {
                            BSWAP_32BIG_C(0xa2d6702fU), BSWAP_32BIG_C(0xc6225aa7U), BSWAP_32BIG_C(0xfa25638dU),
                            BSWAP_32BIG_C(0x40a710bbU),
                        };
                        r_rsip_func101(Param_pdb_func101_008);
                        r_rsip_func434(OutData_Data1, OutData_KeyIndex, OutData_Data2);

                        WR1_PROG(REG_0094H, 0x38000c21U);
                        WR1_PROG(REG_009CH, 0x00000080U);
                        WR1_PROG(REG_0040H, 0x00260000U);

                        static const uint32_t Param_pdb_func100_011[] =
                        {
                            BSWAP_32BIG_C(0xe4db76aaU), BSWAP_32BIG_C(0x160c178aU), BSWAP_32BIG_C(0xd0aabc6bU),
                            BSWAP_32BIG_C(0x6bfa262cU),
                        };
                        r_rsip_func100(Param_pdb_func100_011);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            static const uint32_t Param_pdb_func102_006[] =
                            {
                                BSWAP_32BIG_C(0xc20242bdU), BSWAP_32BIG_C(0x2c528396U), BSWAP_32BIG_C(0x075f6a6bU),
                                BSWAP_32BIG_C(0x2afff978U),
                            };
                            r_rsip_func102(Param_pdb_func102_006);
                            WR1_PROG(REG_006CH, 0x00000040U);
                            WAIT_STS(REG_0020H, 12, 0);

                            return RSIP_RET_PASS;
                        }
                        else
                        {
                            static const uint32_t Param_pdb_func102_007[] =
                            {
                                BSWAP_32BIG_C(0x3b45512eU), BSWAP_32BIG_C(0xa02bae9bU), BSWAP_32BIG_C(0xa5e1f8a0U),
                                BSWAP_32BIG_C(0xbf6848bfU),
                            };
                            r_rsip_func102(Param_pdb_func102_007);
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
