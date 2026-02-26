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

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000dbU, 0x00000000U);

    static const uint32_t Param_pdb_func101_001[] =
    {
        BSWAP_32BIG_C(0x1260cb8aU), BSWAP_32BIG_C(0x7d41cef9U), BSWAP_32BIG_C(0x3c75804aU), BSWAP_32BIG_C(0x41011558U),
    };
    r_rsip_func101(Param_pdb_func101_001);
    r_rsip_func435(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_pdb_func100_001[] =
    {
        BSWAP_32BIG_C(0x18cf9a9eU), BSWAP_32BIG_C(0x2b43ea6fU), BSWAP_32BIG_C(0x3ab15354U), BSWAP_32BIG_C(0x9134ec5bU),
    };
    r_rsip_func100(Param_pdb_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pdb_func102_001[] =
        {
            BSWAP_32BIG_C(0xafe9826eU), BSWAP_32BIG_C(0x6a7f1e7cU), BSWAP_32BIG_C(0x1f10b942U), BSWAP_32BIG_C(
                0x96222214U),
        };
        r_rsip_func102(Param_pdb_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x38008800U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_pdb_func100_002[] =
        {
            BSWAP_32BIG_C(0xf07ad9b2U), BSWAP_32BIG_C(0x89e7b1f8U), BSWAP_32BIG_C(0x8db2d07eU), BSWAP_32BIG_C(
                0xf7a9e5f9U),
        };
        r_rsip_func100(Param_pdb_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pdb_func102_002[] =
            {
                BSWAP_32BIG_C(0x99704bb2U), BSWAP_32BIG_C(0x6b1b4638U), BSWAP_32BIG_C(0x38b36c97U), BSWAP_32BIG_C(
                    0xc0498c7dU),
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

            r_rsip_func_sub014(0x000000c7U, 0x80010060U);
            WR1_PROG(REG_002CH, InData_EncAPDULen[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub010(0x3420a860U, 0x00000002U, 0x00270000U);

            WR1_PROG(REG_0094H, 0x0000b420U);
            r_rsip_func_sub010(0x00000048U, 0x34202823U, 0x00270000U);

            static const uint32_t Param_pdb_func100_003[] =
            {
                BSWAP_32BIG_C(0x684eb4a4U), BSWAP_32BIG_C(0xe5611720U), BSWAP_32BIG_C(0x7ad80ae6U), BSWAP_32BIG_C(
                    0x2e3966e8U),
            };
            r_rsip_func100(Param_pdb_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pdb_func102_003[] =
                {
                    BSWAP_32BIG_C(0x5e841d2aU), BSWAP_32BIG_C(0x03cede6eU), BSWAP_32BIG_C(0x8e3f9242U), BSWAP_32BIG_C(
                        0x91ff9b1fU),
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
                    BSWAP_32BIG_C(0xdfbb5791U), BSWAP_32BIG_C(0x520dbec0U), BSWAP_32BIG_C(0x3eb850c1U), BSWAP_32BIG_C(
                        0xa550066bU),
                };
                r_rsip_func100(Param_pdb_func100_004);

                r_rsip_func_sub022(0x000034a3U, 0x000468a5U, 0x00000884U);

                r_rsip_func_sub017(0x810100a0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_00B0H, 0x00004409U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub011(0x000003c1U, 0x40008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);
                    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

                    WR1_PROG(REG_0094H, 0x00002c80U);

                    static const uint32_t Param_pdb_func101_002[] =
                    {
                        BSWAP_32BIG_C(0xe903e9b1U), BSWAP_32BIG_C(0x4fa9bfddU), BSWAP_32BIG_C(0x1989e382U),
                        BSWAP_32BIG_C(0x2b666457U),
                    };
                    r_rsip_func101(Param_pdb_func101_002);
                }

                r_rsip_func_sub016(0x38000885U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00003403U);

                r_rsip_func_sub010(0x08008c00U, 0x0000000fU, 0x00A70000U);

                static const uint32_t Param_pdb_func100_005[] =
                {
                    BSWAP_32BIG_C(0x5ba98a81U), BSWAP_32BIG_C(0x7b4b1e9bU), BSWAP_32BIG_C(0xc8c5bcaeU), BSWAP_32BIG_C(
                        0x6d55ce61U),
                };
                r_rsip_func100(Param_pdb_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub011(0x000003c1U, 0x40008020U, 0x20008d05U);
                    WR4_ADDR(REG_002CH, &InData_EncAPDU[iLoop * 4]);

                    r_rsip_func_sub007(0x00000821U, 0x80840001U, 0x03410011U);

                    WR1_PROG(REG_0094H, 0x00000884U);
                    for (iLoop = 0U; iLoop < 16U; iLoop++)
                    {
                        r_rsip_func_sub022(0x3c002820U, 0x12003c81U, 0x00002c20U);
                    }

                    r_rsip_func_sub010(0x3420a860U, 0x00000040U, 0x00270000U);

                    static const uint32_t Param_pdb_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x288ddbaaU), BSWAP_32BIG_C(0x6cb1f5e4U), BSWAP_32BIG_C(0xb445ceecU),
                        BSWAP_32BIG_C(0xf570fc33U),
                    };
                    r_rsip_func100(Param_pdb_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub007(0x00000821U, 0x81840001U, 0x00c90011U);

                        static const uint32_t Param_pdb_func101_003[] =
                        {
                            BSWAP_32BIG_C(0x60ee595dU), BSWAP_32BIG_C(0x1e4a97e9U), BSWAP_32BIG_C(0xd9de27bcU),
                            BSWAP_32BIG_C(0x7c2ca371U),
                        };
                        r_rsip_func101(Param_pdb_func101_003);
                    }
                    else
                    {
                        r_rsip_func_sub007(0x00000821U, 0x81820001U, 0x00c90009U);

                        static const uint32_t Param_pdb_func101_004[] =
                        {
                            BSWAP_32BIG_C(0xa286240aU), BSWAP_32BIG_C(0xd952361cU), BSWAP_32BIG_C(0x3c8f9893U),
                            BSWAP_32BIG_C(0xefe1c9e6U),
                        };
                        r_rsip_func101(Param_pdb_func101_004);
                    }

                    static const uint32_t Param_pdb_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x5e9f70b2U), BSWAP_32BIG_C(0x4c1cb7d6U), BSWAP_32BIG_C(0xec040434U),
                        BSWAP_32BIG_C(0xa224a0a8U),
                    };
                    r_rsip_func101(Param_pdb_func101_005);
                }

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub010(0x00000040U, 0x3c002823U, 0x00270000U);

                static const uint32_t Param_pdb_func100_007[] =
                {
                    BSWAP_32BIG_C(0xe2a7a0fdU), BSWAP_32BIG_C(0x23d554faU), BSWAP_32BIG_C(0x95ed540eU), BSWAP_32BIG_C(
                        0x6fa093e5U),
                };
                r_rsip_func100(Param_pdb_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pdb_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xdc59400eU), BSWAP_32BIG_C(0xc2b2421dU), BSWAP_32BIG_C(0x694f9b39U),
                        BSWAP_32BIG_C(0xcbd6d7c7U),
                    };
                    r_rsip_func100(Param_pdb_func100_008);

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

                        static const uint32_t Param_pdb_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x8c3872dcU), BSWAP_32BIG_C(0xa5f66d90U), BSWAP_32BIG_C(0x8d01f69dU),
                            BSWAP_32BIG_C(0xd2928a03U),
                        };
                        r_rsip_func101(Param_pdb_func101_006);
                    }

                    r_rsip_func_sub016(0x380008a4U, 0x00000080U, 0x00270000U);
                    WR1_PROG(REG_0040H, 0x00402000U);

                    static const uint32_t Param_pdb_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xef856234U), BSWAP_32BIG_C(0xb9421e78U), BSWAP_32BIG_C(0x038993e7U),
                        BSWAP_32BIG_C(0xdde39ba0U),
                    };
                    r_rsip_func101(Param_pdb_func101_007);
                }

                r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_002CH, InData_DataTLen[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub010(0x380088a0U, 0x00000000U, 0x00270000U);

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub010(0x00000010U, 0x34202825U, 0x00270000U);

                static const uint32_t Param_pdb_func100_009[] =
                {
                    BSWAP_32BIG_C(0xd99ac0bdU), BSWAP_32BIG_C(0x5e0ed192U), BSWAP_32BIG_C(0x682629e1U), BSWAP_32BIG_C(
                        0x1ecd57b6U),
                };
                r_rsip_func100(Param_pdb_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pdb_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xd1c85cecU), BSWAP_32BIG_C(0x92e42af5U), BSWAP_32BIG_C(0xb94cb580U),
                        BSWAP_32BIG_C(0xf4e10092U),
                    };
                    r_rsip_func102(Param_pdb_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func_sub022(0x00000842U, 0x00003403U, 0x00036c63U);

                    r_rsip_func437(InData_DataALen, InData_DataT);

                    static const uint32_t Param_pdb_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x41a7a636U), BSWAP_32BIG_C(0x3b51c313U), BSWAP_32BIG_C(0xe5e059e7U),
                        BSWAP_32BIG_C(0x3576079aU),
                    };
                    r_rsip_func100(Param_pdb_func100_010);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pdb_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x054faee3U), BSWAP_32BIG_C(0xaf997d0cU), BSWAP_32BIG_C(0x3ef82696U),
                            BSWAP_32BIG_C(0xafd1f119U),
                        };
                        r_rsip_func102(Param_pdb_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_AUTH_FAIL;
                    }
                    else
                    {
                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000dbU, 0x00000000U);

                        static const uint32_t Param_pdb_func101_008[] =
                        {
                            BSWAP_32BIG_C(0x9cf19b14U), BSWAP_32BIG_C(0x96c70715U), BSWAP_32BIG_C(0x90ba315cU),
                            BSWAP_32BIG_C(0xbc27386dU),
                        };
                        r_rsip_func101(Param_pdb_func101_008);
                        r_rsip_func434(OutData_Data1, OutData_KeyIndex, OutData_Data2);

                        r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00270000U);

                        static const uint32_t Param_pdb_func100_011[] =
                        {
                            BSWAP_32BIG_C(0xaa88c26cU), BSWAP_32BIG_C(0xcf91e242U), BSWAP_32BIG_C(0x2151ccc0U),
                            BSWAP_32BIG_C(0xe067bf9aU),
                        };
                        r_rsip_func100(Param_pdb_func100_011);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            static const uint32_t Param_pdb_func102_006[] =
                            {
                                BSWAP_32BIG_C(0x238845edU), BSWAP_32BIG_C(0xa400cba8U), BSWAP_32BIG_C(0xca6cc5ceU),
                                BSWAP_32BIG_C(0x9c4300f5U),
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
                                BSWAP_32BIG_C(0x51cb8696U), BSWAP_32BIG_C(0xfc78082eU), BSWAP_32BIG_C(0x3e72857bU),
                                BSWAP_32BIG_C(0x5e1d2cb7U),
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
