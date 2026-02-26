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

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000daU, 0x00000000U);

    static const uint32_t Param_pda_func101_001[] =
    {
        BSWAP_32BIG_C(0x79bfaa1dU), BSWAP_32BIG_C(0x542eb075U), BSWAP_32BIG_C(0x73ca10d7U), BSWAP_32BIG_C(0xa70bbd9dU),
    };
    r_rsip_func101(Param_pda_func101_001);
    r_rsip_func431(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_pda_func100_001[] =
    {
        BSWAP_32BIG_C(0x82997ba1U), BSWAP_32BIG_C(0x83f5ae6eU), BSWAP_32BIG_C(0xc787c724U), BSWAP_32BIG_C(0x87d83530U),
    };
    r_rsip_func100(Param_pda_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pda_func102_001[] =
        {
            BSWAP_32BIG_C(0x30dc299aU), BSWAP_32BIG_C(0xb941a44fU), BSWAP_32BIG_C(0x68938b72U), BSWAP_32BIG_C(
                0xedeebcbeU),
        };
        r_rsip_func102(Param_pda_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x38008800U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_pda_func100_002[] =
        {
            BSWAP_32BIG_C(0x21742446U), BSWAP_32BIG_C(0x156d26f3U), BSWAP_32BIG_C(0x89e2f883U), BSWAP_32BIG_C(
                0x7a0f6638U),
        };
        r_rsip_func100(Param_pda_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pda_func102_002[] =
            {
                BSWAP_32BIG_C(0x9366a7e9U), BSWAP_32BIG_C(0x372591d6U), BSWAP_32BIG_C(0x33c5a236U), BSWAP_32BIG_C(
                    0xc41cea90U),
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

            r_rsip_func_sub014(0x000000c7U, 0x80010060U);
            WR1_PROG(REG_002CH, InData_EncAPDULen[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub010(0x3420a860U, 0x00000002U, 0x00270000U);

            WR1_PROG(REG_0094H, 0x0000b420U);
            r_rsip_func_sub010(0x00000048U, 0x34202823U, 0x00270000U);

            static const uint32_t Param_pda_func100_003[] =
            {
                BSWAP_32BIG_C(0x2756361aU), BSWAP_32BIG_C(0x7da6aa7fU), BSWAP_32BIG_C(0x91d4fe78U), BSWAP_32BIG_C(
                    0xf829c487U),
            };
            r_rsip_func100(Param_pda_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pda_func102_003[] =
                {
                    BSWAP_32BIG_C(0x4ba86ab3U), BSWAP_32BIG_C(0xe0a87080U), BSWAP_32BIG_C(0x715b74bcU), BSWAP_32BIG_C(
                        0xa26e9087U),
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
                    BSWAP_32BIG_C(0x80477871U), BSWAP_32BIG_C(0x45b86219U), BSWAP_32BIG_C(0x06abc05eU), BSWAP_32BIG_C(
                        0x1078e495U),
                };
                r_rsip_func100(Param_pda_func100_004);

                r_rsip_func_sub022(0x000034a3U, 0x000468a5U, 0x00000884U);

                r_rsip_func_sub017(0x810100a0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_00B0H, 0x00004409U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub011(0x000003c1U, 0x00008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);
                    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

                    WR1_PROG(REG_0094H, 0x00002c80U);

                    static const uint32_t Param_pda_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x3e538c4aU), BSWAP_32BIG_C(0x003c3314U), BSWAP_32BIG_C(0x68214d9cU),
                        BSWAP_32BIG_C(0x70f30acaU),
                    };
                    r_rsip_func101(Param_pda_func101_002);
                }

                r_rsip_func_sub016(0x38000885U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00003403U);

                r_rsip_func_sub010(0x08008c00U, 0x0000000fU, 0x00A70000U);

                static const uint32_t Param_pda_func100_005[] =
                {
                    BSWAP_32BIG_C(0xb7c1ac19U), BSWAP_32BIG_C(0x9f8aba2fU), BSWAP_32BIG_C(0x3a0e17c4U), BSWAP_32BIG_C(
                        0xbc405926U),
                };
                r_rsip_func100(Param_pda_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub011(0x000003c1U, 0x00008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);

                    r_rsip_func_sub007(0x00000821U, 0x80840001U, 0x03410011U);

                    WR1_PROG(REG_0094H, 0x00000884U);
                    for (iLoop = 0U; iLoop < 16U; iLoop++)
                    {
                        r_rsip_func_sub022(0x3c002820U, 0x12003c81U, 0x00002c20U);
                    }

                    r_rsip_func_sub010(0x3420a860U, 0x00000040U, 0x00270000U);

                    static const uint32_t Param_pda_func100_006[] =
                    {
                        BSWAP_32BIG_C(0xcc496526U), BSWAP_32BIG_C(0x5ef777c9U), BSWAP_32BIG_C(0x0a95abaeU),
                        BSWAP_32BIG_C(0xa6c1fac1U),
                    };
                    r_rsip_func100(Param_pda_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub007(0x00000821U, 0x81840001U, 0x00c90011U);

                        static const uint32_t Param_pda_func101_003[] =
                        {
                            BSWAP_32BIG_C(0x212013a8U), BSWAP_32BIG_C(0x1f629edaU), BSWAP_32BIG_C(0x6716fdcaU),
                            BSWAP_32BIG_C(0xf92c6b91U),
                        };
                        r_rsip_func101(Param_pda_func101_003);
                    }
                    else
                    {
                        r_rsip_func_sub007(0x00000821U, 0x81820001U, 0x00c90009U);

                        static const uint32_t Param_pda_func101_004[] =
                        {
                            BSWAP_32BIG_C(0x57c903fcU), BSWAP_32BIG_C(0x1718aab4U), BSWAP_32BIG_C(0xff6e8956U),
                            BSWAP_32BIG_C(0xa57937e1U),
                        };
                        r_rsip_func101(Param_pda_func101_004);
                    }

                    static const uint32_t Param_pda_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xa49320b8U), BSWAP_32BIG_C(0x27484e97U), BSWAP_32BIG_C(0x41ad3310U),
                        BSWAP_32BIG_C(0x152c3d83U),
                    };
                    r_rsip_func101(Param_pda_func101_005);
                }

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub010(0x00000040U, 0x3c002823U, 0x00270000U);

                static const uint32_t Param_pda_func100_007[] =
                {
                    BSWAP_32BIG_C(0xad07eabfU), BSWAP_32BIG_C(0x15a2e4beU), BSWAP_32BIG_C(0x2de7c2c6U), BSWAP_32BIG_C(
                        0x0e95f28dU),
                };
                r_rsip_func100(Param_pda_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pda_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xe4d32689U), BSWAP_32BIG_C(0xf7389e1fU), BSWAP_32BIG_C(0xa9709c1eU),
                        BSWAP_32BIG_C(0x548a98deU),
                    };
                    r_rsip_func100(Param_pda_func100_008);

                    r_rsip_func_sub022(0x00000884U, 0x000034a3U, 0x00000821U);
                    r_rsip_func_sub022(0x0c00a4a0U, 0x0000000fU, 0x00802481U);

                    r_rsip_func_sub022(0x018268a4U, 0x00008ca0U, 0xfffffffcU);

                    r_rsip_func_sub022(0x0000b480U, 0x00000012U, 0x00002885U);

                    r_rsip_func_sub017(0x81010080U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);

                    WR1_PROG(REG_0094H, 0x000008a5U);

                    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                    {
                        r_rsip_func_sub015(0x00c00005U, 0x00001800U);
                        WR1_PROG(REG_0094H, 0x00002ca0U);

                        static const uint32_t Param_pda_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x4b7b808bU), BSWAP_32BIG_C(0xd85329dcU), BSWAP_32BIG_C(0xc1b3d085U),
                            BSWAP_32BIG_C(0x10d5bf02U),
                        };
                        r_rsip_func101(Param_pda_func101_006);
                    }

                    r_rsip_func_sub016(0x380008a4U, 0x00000080U, 0x00270000U);
                    WR1_PROG(REG_0040H, 0x00402000U);

                    static const uint32_t Param_pda_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xbde04aa7U), BSWAP_32BIG_C(0x4f4c7777U), BSWAP_32BIG_C(0xd814d14bU),
                        BSWAP_32BIG_C(0x4820283fU),
                    };
                    r_rsip_func101(Param_pda_func101_007);
                }

                r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_002CH, InData_DataTLen[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub010(0x380088a0U, 0x00000000U, 0x00270000U);

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub010(0x00000010U, 0x34202825U, 0x00270000U);

                static const uint32_t Param_pda_func100_009[] =
                {
                    BSWAP_32BIG_C(0x0d1c944cU), BSWAP_32BIG_C(0xd391407eU), BSWAP_32BIG_C(0x5013cc44U), BSWAP_32BIG_C(
                        0x45c5e716U),
                };
                r_rsip_func100(Param_pda_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pda_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x07b13599U), BSWAP_32BIG_C(0x1ca1f718U), BSWAP_32BIG_C(0xc9d10011U),
                        BSWAP_32BIG_C(0x3e8fb68cU),
                    };
                    r_rsip_func102(Param_pda_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func_sub022(0x00000842U, 0x00003403U, 0x00036c63U);

                    r_rsip_func433(InData_DataALen, InData_DataT);

                    static const uint32_t Param_pda_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x211eb185U), BSWAP_32BIG_C(0x1e1ef6e5U), BSWAP_32BIG_C(0xd074f26bU),
                        BSWAP_32BIG_C(0xeb2e871fU),
                    };
                    r_rsip_func100(Param_pda_func100_010);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pda_func102_005[] =
                        {
                            BSWAP_32BIG_C(0xc9c180baU), BSWAP_32BIG_C(0xade6f518U), BSWAP_32BIG_C(0xc68dc808U),
                            BSWAP_32BIG_C(0x9f06660fU),
                        };
                        r_rsip_func102(Param_pda_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_AUTH_FAIL;
                    }
                    else
                    {
                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000daU, 0x00000000U);

                        static const uint32_t Param_pda_func101_008[] =
                        {
                            BSWAP_32BIG_C(0xc83548a6U), BSWAP_32BIG_C(0x8d6438e4U), BSWAP_32BIG_C(0x0674fb9bU),
                            BSWAP_32BIG_C(0x60bca00fU),
                        };
                        r_rsip_func101(Param_pda_func101_008);
                        r_rsip_func434(OutData_Data1, OutData_KeyIndex, OutData_Data2);

                        r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00270000U);

                        static const uint32_t Param_pda_func100_011[] =
                        {
                            BSWAP_32BIG_C(0x0881b809U), BSWAP_32BIG_C(0xcc617b74U), BSWAP_32BIG_C(0xbcee143bU),
                            BSWAP_32BIG_C(0x1299400fU),
                        };
                        r_rsip_func100(Param_pda_func100_011);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            static const uint32_t Param_pda_func102_006[] =
                            {
                                BSWAP_32BIG_C(0xaf604cf7U), BSWAP_32BIG_C(0x3ed9fba0U), BSWAP_32BIG_C(0xc93b72bbU),
                                BSWAP_32BIG_C(0xacfdbe10U),
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
                                BSWAP_32BIG_C(0xbb5387abU), BSWAP_32BIG_C(0x1a7bb814U), BSWAP_32BIG_C(0x4a1b22f0U),
                                BSWAP_32BIG_C(0x0b73ea7dU),
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
