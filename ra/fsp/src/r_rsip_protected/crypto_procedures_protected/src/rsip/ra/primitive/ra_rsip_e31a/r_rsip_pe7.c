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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00e70001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010040U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub014(0x000001c7U, 0x800200a0U);
    WR1_PROG(REG_002CH, InData_KDFInfo_Count[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_OutDataType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3000a840U, 0x00000002U);
    r_rsip_func_sub022(0x00010020U, 0x0000b440U, 0x00000001U);
    r_rsip_func_sub022(0x00000080U, 0x3000a8c0U, 0x00000008U);
    r_rsip_func_sub022(0x00010020U, 0x0000b4c0U, 0x00000007U);
    WR1_PROG(REG_0094H, 0x00000080U);

    static const uint32_t Param_pe7_func100_001[] =
    {
        BSWAP_32BIG_C(0x0474295aU), BSWAP_32BIG_C(0xec4d427aU), BSWAP_32BIG_C(0x5950db3cU), BSWAP_32BIG_C(0x5f3a191cU),
    };
    r_rsip_func100(Param_pe7_func100_001);
    WR1_PROG(REG_0094H, 0x00007c02U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        r_rsip_func_sub010(0x08000000U, 0x34202805U, 0x00270000U);

        static const uint32_t Param_pe7_func101_001[] =
        {
            BSWAP_32BIG_C(0xaac385eaU), BSWAP_32BIG_C(0x2b7c8dedU), BSWAP_32BIG_C(0xdd6350d3U), BSWAP_32BIG_C(
                0x81045fe8U),
        };
        r_rsip_func101(Param_pe7_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        r_rsip_func_sub010(0x05555555U, 0x34202805U, 0x00270000U);

        static const uint32_t Param_pe7_func101_002[] =
        {
            BSWAP_32BIG_C(0xdf2f823cU), BSWAP_32BIG_C(0x332f7eb8U), BSWAP_32BIG_C(0x66a14b64U), BSWAP_32BIG_C(
                0x420ed312U),
        };
        r_rsip_func101(Param_pe7_func101_002);
    }

    r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

    r_rsip_func_sub010(0x380088c0U, 0x00000003U, 0x00270000U);

    r_rsip_func_sub010(0x380088c0U, 0x00000004U, 0x00270000U);

    r_rsip_func_sub010(0x380088c0U, 0x00000005U, 0x00270000U);

    static const uint32_t Param_pe7_func100_002[] =
    {
        BSWAP_32BIG_C(0xa8059c1bU), BSWAP_32BIG_C(0x22cc9149U), BSWAP_32BIG_C(0x40f7c5fbU), BSWAP_32BIG_C(0x5f4741ffU),
    };
    r_rsip_func100(Param_pe7_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe7_func102_001[] =
        {
            BSWAP_32BIG_C(0x48aceb5dU), BSWAP_32BIG_C(0x5949d84dU), BSWAP_32BIG_C(0x0bc1256aU), BSWAP_32BIG_C(
                0xc81595f7U),
        };
        r_rsip_func102(Param_pe7_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe7_func100_003[] =
        {
            BSWAP_32BIG_C(0x9bae2425U), BSWAP_32BIG_C(0x66688472U), BSWAP_32BIG_C(0xd5ddff05U), BSWAP_32BIG_C(
                0x1ebd9cf7U),
        };
        r_rsip_func100(Param_pe7_func100_003);
        WR1_PROG(REG_0094H, 0x00007c06U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x80010080U, 0x0000000fU, 0x00000000U);

            static const uint32_t Param_pe7_func101_003[] =
            {
                BSWAP_32BIG_C(0xe60467cbU), BSWAP_32BIG_C(0x019f6760U), BSWAP_32BIG_C(0x733e3920U), BSWAP_32BIG_C(
                    0x5c08c02eU),
            };
            r_rsip_func101(Param_pe7_func101_003);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x80010080U, 0x0000001fU, 0x00000000U);

            static const uint32_t Param_pe7_func101_004[] =
            {
                BSWAP_32BIG_C(0x3e3197b4U), BSWAP_32BIG_C(0xc55b9efeU), BSWAP_32BIG_C(0xe040870dU), BSWAP_32BIG_C(
                    0x8d4fabd9U),
            };
            r_rsip_func101(Param_pe7_func101_004);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x80010080U, 0x0000000fU, 0x00000000U);

            static const uint32_t Param_pe7_func101_005[] =
            {
                BSWAP_32BIG_C(0x23296402U), BSWAP_32BIG_C(0xe7f679beU), BSWAP_32BIG_C(0xdc1d3ff9U), BSWAP_32BIG_C(
                    0x4754960dU),
            };
            r_rsip_func101(Param_pe7_func101_005);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x80010080U, 0x0000001fU, 0x00000000U);

            static const uint32_t Param_pe7_func101_006[] =
            {
                BSWAP_32BIG_C(0x622f80aeU), BSWAP_32BIG_C(0xc61e8c81U), BSWAP_32BIG_C(0x9f3a5683U), BSWAP_32BIG_C(
                    0xae676121U),
            };
            r_rsip_func101(Param_pe7_func101_006);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000007U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x80010080U, 0x0000002fU, 0x00000000U);

            static const uint32_t Param_pe7_func101_007[] =
            {
                BSWAP_32BIG_C(0xafcc7751U), BSWAP_32BIG_C(0x89960253U), BSWAP_32BIG_C(0x1d9ad6feU), BSWAP_32BIG_C(
                    0x624568dbU),
            };
            r_rsip_func101(Param_pe7_func101_007);
        }

        r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x00003cc7U);

        r_rsip_func_sub014(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_002CH, InData_OutDataLocation[0]);
        r_rsip_func_sub018(0x00000000U, 0x30003040U, 0x00070020U);

        r_rsip_func_sub022(0x00003405U, 0x00056c00U, 0x00003000U);

        r_rsip_func_sub022(0x00000060U, 0x00003405U, 0x00046c00U);
        r_rsip_func_sub022(0x00003465U, 0x00056c63U, 0x00002403U);
        WR1_PROG(REG_0094H, 0x00003000U);

        WR1_PROG(REG_0094H, 0x00000080U);

        r_rsip_func_sub010(0x00002481U, 0x34202804U, 0x00270000U);

        r_rsip_func_sub016(0x34202824U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_pe7_func100_004[] =
        {
            BSWAP_32BIG_C(0x0edf7dcaU), BSWAP_32BIG_C(0xc2d6ff49U), BSWAP_32BIG_C(0x201ff6e0U), BSWAP_32BIG_C(
                0xca76f0adU),
        };
        r_rsip_func100(Param_pe7_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe7_func102_002[] =
            {
                BSWAP_32BIG_C(0x000addc1U), BSWAP_32BIG_C(0x6d07e28dU), BSWAP_32BIG_C(0x0f767f12U), BSWAP_32BIG_C(
                    0x10fd5f45U),
            };
            r_rsip_func102(Param_pe7_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub022(0x000008c6U, 0x00000800U, 0x00000863U);

            static const uint32_t Param_pe7_func100_005[] =
            {
                BSWAP_32BIG_C(0xda30d11bU), BSWAP_32BIG_C(0xde0741deU), BSWAP_32BIG_C(0x7532ead9U), BSWAP_32BIG_C(
                    0xade36a9fU),
            };
            r_rsip_func100(Param_pe7_func100_005);
            r_rsip_func_sub017(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub022(0x0000b4e0U, 0x00000014U, 0x00003ca7U);

            static const uint32_t Param_pe7_func100_006[] =
            {
                BSWAP_32BIG_C(0x42cab37aU), BSWAP_32BIG_C(0xf9ddcc22U), BSWAP_32BIG_C(0xa1967acbU), BSWAP_32BIG_C(
                    0xd9249c8eU),
            };
            r_rsip_func100(Param_pe7_func100_006);
            WR1_PROG(REG_0094H, 0x00007c02U);
            WR1_PROG(REG_0040H, 0x00600000U);

            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
            {
                WR1_PROG(REG_0094H, 0x00000842U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub016(0x34202880U, 0x00000080U, 0x00270000U);

                    WR1_PROG(REG_0094H, 0x0000a400U);
                    r_rsip_func_sub010(0x0000001fU, 0x34202801U, 0x00270000U);

                    static const uint32_t Param_pe7_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x7901613bU), BSWAP_32BIG_C(0x46f6671fU), BSWAP_32BIG_C(0x2c20e358U),
                        BSWAP_32BIG_C(0xdeb516eeU),
                    };
                    r_rsip_func100(Param_pe7_func100_007);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func101_008[] =
                        {
                            BSWAP_32BIG_C(0xdc033de3U), BSWAP_32BIG_C(0x77720302U), BSWAP_32BIG_C(0xb6ffa942U),
                            BSWAP_32BIG_C(0x6bff7da8U),
                        };
                        r_rsip_func101(Param_pe7_func101_008);
                    }
                    else
                    {
                        r_rsip_func_sub022(0x0000b4e0U, 0x00000018U, 0x00003c47U);

                        r_rsip_func_sub022(0x0000b4e0U, 0x0000001cU, 0x00003cc7U);

                        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
                        WR1_PROG(REG_002CH, InData_KDFInfo[iLoop * 13]);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e701U, 0x00000000U);

                        static const uint32_t Param_pe7_func101_009[] =
                        {
                            BSWAP_32BIG_C(0xf1074980U), BSWAP_32BIG_C(0xfd3e9ce7U), BSWAP_32BIG_C(0x27061455U),
                            BSWAP_32BIG_C(0x8f0f1961U),
                        };
                        r_rsip_func101(Param_pe7_func101_009);
                        r_rsip_func143();

                        WR1_PROG(REG_0094H, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x01799093U);

                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e701U, 0x00000000U);

                        static const uint32_t Param_pe7_func101_010[] =
                        {
                            BSWAP_32BIG_C(0x2395018bU), BSWAP_32BIG_C(0xc262b4d7U), BSWAP_32BIG_C(0xe7144052U),
                            BSWAP_32BIG_C(0x9be4a068U),
                        };
                        r_rsip_func101(Param_pe7_func101_010);
                        r_rsip_func044();

                        r_rsip_func_sub016(0x38000c63U, 0x00000080U, 0x00270000U);

                        static const uint32_t Param_pe7_func100_008[] =
                        {
                            BSWAP_32BIG_C(0x05c0dabfU), BSWAP_32BIG_C(0x9765ab43U), BSWAP_32BIG_C(0xe0b88d3fU),
                            BSWAP_32BIG_C(0xa5feef7eU),
                        };
                        r_rsip_func100(Param_pe7_func100_008);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_00B0H, 0x00001404U);

                            static const uint32_t Param_pe7_func101_011[] =
                            {
                                BSWAP_32BIG_C(0x512736e4U), BSWAP_32BIG_C(0x0791524eU), BSWAP_32BIG_C(0x65b319c8U),
                                BSWAP_32BIG_C(0xf1452f5eU),
                            };
                            r_rsip_func101(Param_pe7_func101_011);
                        }
                        else
                        {
                            r_rsip_func_sub010(0x38008860U, 0x00000001U, 0x00270000U);

                            static const uint32_t Param_pe7_func100_009[] =
                            {
                                BSWAP_32BIG_C(0x5b1f387aU), BSWAP_32BIG_C(0xa71f4192U), BSWAP_32BIG_C(0xb0acbc18U),
                                BSWAP_32BIG_C(0x094035a8U),
                            };
                            r_rsip_func100(Param_pe7_func100_009);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                WR1_PROG(REG_00B0H, 0x00001408U);

                                static const uint32_t Param_pe7_func101_012[] =
                                {
                                    BSWAP_32BIG_C(0xb6f56a9aU), BSWAP_32BIG_C(0x25ecc003U), BSWAP_32BIG_C(0xd21f8118U),
                                    BSWAP_32BIG_C(0x8aa87da7U),
                                };
                                r_rsip_func101(Param_pe7_func101_012);
                            }
                            else
                            {
                                WR1_PROG(REG_00B0H, 0x0000140cU);

                                static const uint32_t Param_pe7_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xba6d0b90U), BSWAP_32BIG_C(0x872baf77U), BSWAP_32BIG_C(0xdf8c90b6U),
                                    BSWAP_32BIG_C(0xcf9abff7U),
                                };
                                r_rsip_func101(Param_pe7_func101_013);
                            }

                            static const uint32_t Param_pe7_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x944859d7U), BSWAP_32BIG_C(0x75d8848eU), BSWAP_32BIG_C(0xc410d1b1U),
                                BSWAP_32BIG_C(0x957a7b61U),
                            };
                            r_rsip_func101(Param_pe7_func101_014);
                        }

                        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

                        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

                        r_rsip_func_sub011(0x000007c1U, 0x40000100U, 0xf7008d07U);
                        WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 1]);
                        WAIT_STS(REG_0014H, 31, 1);
                        WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 5]);

                        r_rsip_func_sub015(0x00c10021U, 0x00001800U);

                        r_rsip_func_sub022(0x00002c60U, 0x0000b4e0U, 0x00000018U);
                        r_rsip_func_sub022(0x00003847U, 0x0000b4e0U, 0x0000001cU);
                        WR1_PROG(REG_0094H, 0x000038c7U);

                        r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
                        WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 9]);

                        r_rsip_func_sub013(0x9c100005U, 0x00410011U);

                        static const uint32_t Param_pe7_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x302b6072U), BSWAP_32BIG_C(0x59b126d2U), BSWAP_32BIG_C(0x5f4eec0cU),
                            BSWAP_32BIG_C(0x6485adb0U),
                        };
                        r_rsip_func100(Param_pe7_func100_010);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_0094H, 0x0000d040U);
                            static const uint32_t Param_pe7_func101_015[] =
                            {
                                BSWAP_32BIG_C(0xa0e0df44U), BSWAP_32BIG_C(0xd46006f6U), BSWAP_32BIG_C(0x7220482fU),
                                BSWAP_32BIG_C(0xbb250b3fU),
                            };
                            r_rsip_func101(Param_pe7_func101_015);
                        }
                        else
                        {
                            static const uint32_t Param_pe7_func101_016[] =
                            {
                                BSWAP_32BIG_C(0x4bd2ae50U), BSWAP_32BIG_C(0x0e32c0ccU), BSWAP_32BIG_C(0x9425544cU),
                                BSWAP_32BIG_C(0xda0a9d40U),
                            };
                            r_rsip_func101(Param_pe7_func101_016);
                        }
                    }

                    WR1_PROG(REG_0094H, 0x00002c00U);

                    WR1_PROG(REG_0094H, 0x00002cc0U);

                    static const uint32_t Param_pe7_func101_017[] =
                    {
                        BSWAP_32BIG_C(0xf0fca2fbU), BSWAP_32BIG_C(0xb1ffbbddU), BSWAP_32BIG_C(0x72e36b6bU),
                        BSWAP_32BIG_C(0xefbca5d3U),
                    };
                    r_rsip_func101(Param_pe7_func101_017);
                }

                WR1_PROG(REG_0094H, 0x00000884U);

                static const uint32_t Param_pe7_func101_018[] =
                {
                    BSWAP_32BIG_C(0x14fe01e9U), BSWAP_32BIG_C(0x87739025U), BSWAP_32BIG_C(0xfd59349aU), BSWAP_32BIG_C(
                        0x36a959b9U),
                };
                r_rsip_func101(Param_pe7_func101_018);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
            {
                WR1_PROG(REG_0094H, 0x00000842U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub016(0x34202880U, 0x00000080U, 0x00270000U);

                    WR1_PROG(REG_0094H, 0x0000a400U);
                    r_rsip_func_sub010(0x0000002fU, 0x34202801U, 0x00270000U);

                    static const uint32_t Param_pe7_func100_011[] =
                    {
                        BSWAP_32BIG_C(0x85b10afeU), BSWAP_32BIG_C(0x5b785d28U), BSWAP_32BIG_C(0x8d84ad77U),
                        BSWAP_32BIG_C(0x1b1224beU),
                    };
                    r_rsip_func100(Param_pe7_func100_011);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func101_019[] =
                        {
                            BSWAP_32BIG_C(0xb1075054U), BSWAP_32BIG_C(0xb97152a1U), BSWAP_32BIG_C(0xd86735acU),
                            BSWAP_32BIG_C(0xb949d90aU),
                        };
                        r_rsip_func101(Param_pe7_func101_019);
                    }
                    else
                    {
                        r_rsip_func_sub022(0x0000b4e0U, 0x00000018U, 0x00003c47U);

                        r_rsip_func_sub022(0x0000b4e0U, 0x0000001cU, 0x00003cc7U);

                        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
                        WR1_PROG(REG_002CH, InData_KDFInfo[iLoop * 17]);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e702U, 0x00000000U);

                        static const uint32_t Param_pe7_func101_020[] =
                        {
                            BSWAP_32BIG_C(0x8d6678d4U), BSWAP_32BIG_C(0xb8bc0d6dU), BSWAP_32BIG_C(0x588beb10U),
                            BSWAP_32BIG_C(0xca8ef939U),
                        };
                        r_rsip_func101(Param_pe7_func101_020);
                        r_rsip_func143();

                        WR1_PROG(REG_0094H, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x01799093U);

                        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e702U, 0x00000000U);

                        static const uint32_t Param_pe7_func101_021[] =
                        {
                            BSWAP_32BIG_C(0xcdaad173U), BSWAP_32BIG_C(0x759ee735U), BSWAP_32BIG_C(0xc0a90cdfU),
                            BSWAP_32BIG_C(0x790cb926U),
                        };
                        r_rsip_func101(Param_pe7_func101_021);
                        r_rsip_func044();

                        r_rsip_func_sub016(0x38000c63U, 0x00000080U, 0x00270000U);

                        static const uint32_t Param_pe7_func100_012[] =
                        {
                            BSWAP_32BIG_C(0xbc640838U), BSWAP_32BIG_C(0x6003df74U), BSWAP_32BIG_C(0x1ae109d5U),
                            BSWAP_32BIG_C(0xf3807d59U),
                        };
                        r_rsip_func100(Param_pe7_func100_012);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_00B0H, 0x00009406U);

                            r_rsip_func_sub022(0x0000b4e0U, 0x0000001cU, 0x000038a7U);

                            static const uint32_t Param_pe7_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x21bab97bU), BSWAP_32BIG_C(0xaf7e7237U), BSWAP_32BIG_C(0xc61352c6U),
                                BSWAP_32BIG_C(0x8ab68484U),
                            };
                            r_rsip_func101(Param_pe7_func101_022);
                        }
                        else
                        {
                            WR1_PROG(REG_00B0H, 0x0000940cU);

                            static const uint32_t Param_pe7_func101_023[] =
                            {
                                BSWAP_32BIG_C(0x944f1f5aU), BSWAP_32BIG_C(0x598af3d0U), BSWAP_32BIG_C(0xd0669889U),
                                BSWAP_32BIG_C(0xec48763fU),
                            };
                            r_rsip_func101(Param_pe7_func101_023);
                        }

                        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

                        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

                        WR1_PROG(REG_0014H, 0x00000bc1U);
                        WR1_PROG(REG_00D4H, 0x40000200U);
                        WR1_PROG(REG_00D0H, 0xf7008d07U);

                        for (jLoop = 0U; jLoop < 12U; )
                        {
                            WAIT_STS(REG_0014H, 31, 1);
                            WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 17 + jLoop + 1]);
                            jLoop = jLoop + 4U;
                        }

                        r_rsip_func_sub015(0x00c10031U, 0x00001800U);

                        r_rsip_func_sub022(0x00002c60U, 0x0000b4e0U, 0x00000018U);
                        r_rsip_func_sub022(0x00003847U, 0x0000b4e0U, 0x0000001cU);
                        WR1_PROG(REG_0094H, 0x000038c7U);

                        r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
                        WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 17 + jLoop + 1]);

                        r_rsip_func_sub013(0x9c100005U, 0x00410011U);

                        static const uint32_t Param_pe7_func100_013[] =
                        {
                            BSWAP_32BIG_C(0x7cb97cd2U), BSWAP_32BIG_C(0x06ee27fbU), BSWAP_32BIG_C(0x5da744ebU),
                            BSWAP_32BIG_C(0x963d44a9U),
                        };
                        r_rsip_func100(Param_pe7_func100_013);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_0094H, 0x0000d040U);
                            static const uint32_t Param_pe7_func101_024[] =
                            {
                                BSWAP_32BIG_C(0xa1936fe5U), BSWAP_32BIG_C(0x41e0d8a4U), BSWAP_32BIG_C(0x4964b82fU),
                                BSWAP_32BIG_C(0x5d5f12fcU),
                            };
                            r_rsip_func101(Param_pe7_func101_024);
                        }
                        else
                        {
                            static const uint32_t Param_pe7_func101_025[] =
                            {
                                BSWAP_32BIG_C(0x9279573aU), BSWAP_32BIG_C(0x8a11b32aU), BSWAP_32BIG_C(0x8b2fea91U),
                                BSWAP_32BIG_C(0x4c15ec2bU),
                            };
                            r_rsip_func101(Param_pe7_func101_025);
                        }
                    }

                    WR1_PROG(REG_0094H, 0x00002c00U);

                    WR1_PROG(REG_0094H, 0x00002cc0U);

                    static const uint32_t Param_pe7_func101_026[] =
                    {
                        BSWAP_32BIG_C(0x1f8f892aU), BSWAP_32BIG_C(0x1dbe34fdU), BSWAP_32BIG_C(0x73b741aaU),
                        BSWAP_32BIG_C(0x4ac9503dU),
                    };
                    r_rsip_func101(Param_pe7_func101_026);
                }

                WR1_PROG(REG_0094H, 0x0000b480U);
                WR1_PROG(REG_0094H, 0x00000001U);

                static const uint32_t Param_pe7_func101_027[] =
                {
                    BSWAP_32BIG_C(0x901a631eU), BSWAP_32BIG_C(0x24be041aU), BSWAP_32BIG_C(0x9559b0d6U), BSWAP_32BIG_C(
                        0x15ed2d29U),
                };
                r_rsip_func101(Param_pe7_func101_027);
            }

            WR1_PROG(REG_0094H, 0x0000b4e0U);
            WR1_PROG(REG_0094H, 0x00000014U);
            r_rsip_func_sub010(0x00003807U, 0x380008c0U, 0x00270000U);
            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub016(0x38000c42U, 0x00000080U, 0x00A70000U);
            static const uint32_t Param_pe7_func100_014[] =
            {
                BSWAP_32BIG_C(0x23b50f0cU), BSWAP_32BIG_C(0x7c6dc4fbU), BSWAP_32BIG_C(0xfe79682aU), BSWAP_32BIG_C(
                    0x49751e65U),
            };
            r_rsip_func100(Param_pe7_func100_014);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe7_func102_003[] =
                {
                    BSWAP_32BIG_C(0x621e433dU), BSWAP_32BIG_C(0x1b7cc490U), BSWAP_32BIG_C(0x65108f8dU), BSWAP_32BIG_C(
                        0xb03da3d6U),
                };
                r_rsip_func102(Param_pe7_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe7_func100_015[] =
                {
                    BSWAP_32BIG_C(0xda839fa2U), BSWAP_32BIG_C(0x167bd543U), BSWAP_32BIG_C(0xa4255670U), BSWAP_32BIG_C(
                        0xf0e5ba8eU),
                };
                r_rsip_func100(Param_pe7_func100_015);
                r_rsip_func103();

                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e703U, 0x00000000U);

                static const uint32_t Param_pe7_func101_028[] =
                {
                    BSWAP_32BIG_C(0x651802c3U), BSWAP_32BIG_C(0xc4bccd6fU), BSWAP_32BIG_C(0xe0aac8faU), BSWAP_32BIG_C(
                        0xe28da32aU),
                };
                r_rsip_func101(Param_pe7_func101_028);
                r_rsip_func143();

                r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x00003847U);

                static const uint32_t Param_pe7_func100_016[] =
                {
                    BSWAP_32BIG_C(0x40269ffbU), BSWAP_32BIG_C(0xf75e4a92U), BSWAP_32BIG_C(0x0021b47aU), BSWAP_32BIG_C(
                        0x668c740cU),
                };
                r_rsip_func100(Param_pe7_func100_016);
                WR1_PROG(REG_0094H, 0x00007c02U);
                WR1_PROG(REG_0040H, 0x00600000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x00000005U);

                    static const uint32_t Param_pe7_func101_029[] =
                    {
                        BSWAP_32BIG_C(0x8d475e89U), BSWAP_32BIG_C(0xb6c2344eU), BSWAP_32BIG_C(0x6177a8aeU),
                        BSWAP_32BIG_C(0x8117368aU),
                    };
                    r_rsip_func101(Param_pe7_func101_029);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x00000007U);

                    static const uint32_t Param_pe7_func101_030[] =
                    {
                        BSWAP_32BIG_C(0x79f3162eU), BSWAP_32BIG_C(0xd97d6857U), BSWAP_32BIG_C(0xa3819e72U),
                        BSWAP_32BIG_C(0xdbf985e3U),
                    };
                    r_rsip_func101(Param_pe7_func101_030);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x0199e556U);

                    static const uint32_t Param_pe7_func101_031[] =
                    {
                        BSWAP_32BIG_C(0xbde86ce6U), BSWAP_32BIG_C(0x60dfcd3cU), BSWAP_32BIG_C(0x7de476f3U),
                        BSWAP_32BIG_C(0x150aafabU),
                    };
                    r_rsip_func101(Param_pe7_func101_031);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x0000001bU);

                    static const uint32_t Param_pe7_func101_032[] =
                    {
                        BSWAP_32BIG_C(0x474d1a94U), BSWAP_32BIG_C(0x2f42092aU), BSWAP_32BIG_C(0xe1e8d4c0U),
                        BSWAP_32BIG_C(0x063e20fdU),
                    };
                    r_rsip_func101(Param_pe7_func101_032);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000007U)
                {
                    WR1_PROG(REG_0094H, 0x0000b4c0U);
                    WR1_PROG(REG_0094H, 0x00000028U);

                    static const uint32_t Param_pe7_func101_033[] =
                    {
                        BSWAP_32BIG_C(0x3c25b32aU), BSWAP_32BIG_C(0x034cf0faU), BSWAP_32BIG_C(0x4d0f9541U),
                        BSWAP_32BIG_C(0x01454607U),
                    };
                    r_rsip_func101(Param_pe7_func101_033);
                }

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e703U, 0x00000000U);

                static const uint32_t Param_pe7_func101_034[] =
                {
                    BSWAP_32BIG_C(0x69fe8c7dU), BSWAP_32BIG_C(0x71d991edU), BSWAP_32BIG_C(0x06a6fd9eU), BSWAP_32BIG_C(
                        0x203c754dU),
                };
                r_rsip_func101(Param_pe7_func101_034);
                r_rsip_func044();

                static const uint32_t Param_pe7_func100_017[] =
                {
                    BSWAP_32BIG_C(0xdfd76ffcU), BSWAP_32BIG_C(0xecfa3251U), BSWAP_32BIG_C(0x533f7c5cU), BSWAP_32BIG_C(
                        0xe8b686d7U),
                };
                r_rsip_func100(Param_pe7_func100_017);
                WR1_PROG(REG_0094H, 0x00007c04U);
                WR1_PROG(REG_0040H, 0x00600000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_0094H, 0x00008c20U);
                    WR1_PROG(REG_0094H, 0x0000001fU);

                    r_rsip_func_sub010(0x38008860U, 0x00000001U, 0x00270000U);

                    static const uint32_t Param_pe7_func100_018[] =
                    {
                        BSWAP_32BIG_C(0xdf52b556U), BSWAP_32BIG_C(0xa1f1537eU), BSWAP_32BIG_C(0xdd3855dcU),
                        BSWAP_32BIG_C(0xadce6f47U),
                    };
                    r_rsip_func100(Param_pe7_func100_018);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0094H, 0x0000b460U);
                        WR1_PROG(REG_0094H, 0x00000020U);
                        WR1_PROG(REG_00B0H, 0x00001804U);

                        static const uint32_t Param_pe7_func101_035[] =
                        {
                            BSWAP_32BIG_C(0xd25974b8U), BSWAP_32BIG_C(0x4ebdbf5dU), BSWAP_32BIG_C(0x3ab94f92U),
                            BSWAP_32BIG_C(0x8d8caa43U),
                        };
                        r_rsip_func101(Param_pe7_func101_035);
                    }
                    else
                    {
                        r_rsip_func_sub010(0x38008860U, 0x00000002U, 0x00270000U);

                        static const uint32_t Param_pe7_func100_019[] =
                        {
                            BSWAP_32BIG_C(0x9d151ddeU), BSWAP_32BIG_C(0x664ced06U), BSWAP_32BIG_C(0xe949ef5aU),
                            BSWAP_32BIG_C(0xb64f70b2U),
                        };
                        r_rsip_func100(Param_pe7_func100_019);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_0094H, 0x0000b460U);
                            WR1_PROG(REG_0094H, 0x00000040U);
                            WR1_PROG(REG_00B0H, 0x00003808U);

                            static const uint32_t Param_pe7_func101_036[] =
                            {
                                BSWAP_32BIG_C(0xa00800bbU), BSWAP_32BIG_C(0x99de371dU), BSWAP_32BIG_C(0x80bdb603U),
                                BSWAP_32BIG_C(0xfdcec22aU),
                            };
                            r_rsip_func101(Param_pe7_func101_036);
                        }
                        else
                        {
                            WR1_PROG(REG_0094H, 0x0000b460U);
                            WR1_PROG(REG_0094H, 0x00000060U);
                            WR1_PROG(REG_00B0H, 0x0000b80cU);

                            static const uint32_t Param_pe7_func101_037[] =
                            {
                                BSWAP_32BIG_C(0xdac6fbfeU), BSWAP_32BIG_C(0x68cf71afU), BSWAP_32BIG_C(0x6b3a359dU),
                                BSWAP_32BIG_C(0xc522e366U),
                            };
                            r_rsip_func101(Param_pe7_func101_037);
                        }

                        static const uint32_t Param_pe7_func101_038[] =
                        {
                            BSWAP_32BIG_C(0x5d76770dU), BSWAP_32BIG_C(0x839298afU), BSWAP_32BIG_C(0x10563c79U),
                            BSWAP_32BIG_C(0xa92d3efaU),
                        };
                        r_rsip_func101(Param_pe7_func101_038);
                    }

                    static const uint32_t Param_pe7_func101_039[] =
                    {
                        BSWAP_32BIG_C(0x55c06984U), BSWAP_32BIG_C(0x6a256bedU), BSWAP_32BIG_C(0x8ab9fc87U),
                        BSWAP_32BIG_C(0x2962e0fbU),
                    };
                    r_rsip_func101(Param_pe7_func101_039);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                {
                    r_rsip_func_sub022(0x000034e5U, 0x00046ce7U, 0x00056ca5U);
                    WR1_PROG(REG_0094H, 0x000024a7U);
                    WR1_PROG(REG_0094H, 0x00002825U);

                    r_rsip_func_sub010(0x38008860U, 0x00000001U, 0x00270000U);

                    static const uint32_t Param_pe7_func100_020[] =
                    {
                        BSWAP_32BIG_C(0x0015edd2U), BSWAP_32BIG_C(0xf1c50f53U), BSWAP_32BIG_C(0xe1f950daU),
                        BSWAP_32BIG_C(0x0eef29b8U),
                    };
                    r_rsip_func100(Param_pe7_func100_020);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_0094H, 0x0000b460U);
                        WR1_PROG(REG_0094H, 0x00000030U);
                        WR1_PROG(REG_00B0H, 0x00009806U);

                        static const uint32_t Param_pe7_func101_040[] =
                        {
                            BSWAP_32BIG_C(0xbed38b05U), BSWAP_32BIG_C(0x772e5023U), BSWAP_32BIG_C(0xa0f98ad1U),
                            BSWAP_32BIG_C(0xb6439250U),
                        };
                        r_rsip_func101(Param_pe7_func101_040);
                    }
                    else
                    {
                        WR1_PROG(REG_0094H, 0x0000b460U);
                        WR1_PROG(REG_0094H, 0x00000060U);
                        WR1_PROG(REG_00B0H, 0x0000b80cU);

                        static const uint32_t Param_pe7_func101_041[] =
                        {
                            BSWAP_32BIG_C(0xf10f29adU), BSWAP_32BIG_C(0xbedd15e2U), BSWAP_32BIG_C(0x496e07cfU),
                            BSWAP_32BIG_C(0x4bc57070U),
                        };
                        r_rsip_func101(Param_pe7_func101_041);
                    }

                    static const uint32_t Param_pe7_func101_042[] =
                    {
                        BSWAP_32BIG_C(0x629dbffcU), BSWAP_32BIG_C(0xc2d1c66bU), BSWAP_32BIG_C(0x34354ba8U),
                        BSWAP_32BIG_C(0x5a7b9934U),
                    };
                    r_rsip_func101(Param_pe7_func101_042);
                }

                WR1_PROG(REG_0094H, 0x000008e7U);

                WR1_PROG(REG_0094H, 0x000008a5U);

                static const uint32_t Param_pe7_func100_021[] =
                {
                    BSWAP_32BIG_C(0x96985e1dU), BSWAP_32BIG_C(0xb6c1d963U), BSWAP_32BIG_C(0xee4fd143U), BSWAP_32BIG_C(
                        0x6fd83130U),
                };
                r_rsip_func100(Param_pe7_func100_021);
                r_rsip_func_sub017(0x81010060U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub016(0x342028a1U, 0x00000080U, 0x00270000U);

                    r_rsip_func_sub010(0x3420a8e0U, 0x00000020U, 0x00A70000U);

                    static const uint32_t Param_pe7_func100_022[] =
                    {
                        BSWAP_32BIG_C(0x4eece013U), BSWAP_32BIG_C(0x221c0d95U), BSWAP_32BIG_C(0xd4b5ac17U),
                        BSWAP_32BIG_C(0x71d9ed6eU),
                    };
                    r_rsip_func100(Param_pe7_func100_022);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub015(0x1000000dU, 0x00001800U);
                        r_rsip_func_sub015(0x10030005U, 0x00001800U);

                        static const uint32_t Param_pe7_func101_043[] =
                        {
                            BSWAP_32BIG_C(0x5c28ea65U), BSWAP_32BIG_C(0x6803d506U), BSWAP_32BIG_C(0x7d69c5ecU),
                            BSWAP_32BIG_C(0x24d5fd49U),
                        };
                        r_rsip_func101(Param_pe7_func101_043);
                    }
                    else
                    {
                        r_rsip_func_sub005(0x800100c0U, 0x1340000dU, 0x13430005U);

                        r_rsip_func_sub022(0x02003cc7U, 0x00002ce0U, 0x380088e0U);
                        r_rsip_func_sub022(0x00000020U, 0x00030020U, 0x000034c5U);
                        WR1_PROG(REG_0094H, 0x00002cc0U);
                        WR1_PROG(REG_0094H, 0x00000080U);

                        static const uint32_t Param_pe7_func101_044[] =
                        {
                            BSWAP_32BIG_C(0x602073d1U), BSWAP_32BIG_C(0x4c7a4cf1U), BSWAP_32BIG_C(0xfe91955cU),
                            BSWAP_32BIG_C(0x75054e8eU),
                        };
                        r_rsip_func101(Param_pe7_func101_044);
                    }

                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_pe7_func101_045[] =
                    {
                        BSWAP_32BIG_C(0x932229d8U), BSWAP_32BIG_C(0x0546a79dU), BSWAP_32BIG_C(0xf0b3b09dU),
                        BSWAP_32BIG_C(0xb1232575U),
                    };
                    r_rsip_func101(Param_pe7_func101_045);
                }

                r_rsip_func_sub016(0x380008a3U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x000008e7U);

                r_rsip_func_sub010(0x3420a840U, 0x00000002U, 0x00270000U);

                static const uint32_t Param_pe7_func100_023[] =
                {
                    BSWAP_32BIG_C(0x7029a978U), BSWAP_32BIG_C(0xc5cc4e3fU), BSWAP_32BIG_C(0xd069b1a6U), BSWAP_32BIG_C(
                        0x8463eabdU),
                };
                r_rsip_func100(Param_pe7_func100_023);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub016(0x38000c42U, 0x00000080U, 0x00270000U);

                    static const uint32_t Param_pe7_func100_024[] =
                    {
                        BSWAP_32BIG_C(0xc00b2098U), BSWAP_32BIG_C(0xdab5fc4aU), BSWAP_32BIG_C(0xed23ed18U),
                        BSWAP_32BIG_C(0x02667a4bU),
                    };
                    r_rsip_func100(Param_pe7_func100_024);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_025[] =
                        {
                            BSWAP_32BIG_C(0x88940bcaU), BSWAP_32BIG_C(0x29ba7f32U), BSWAP_32BIG_C(0xcf4b0fdeU),
                            BSWAP_32BIG_C(0x70897136U),
                        };
                        r_rsip_func100(Param_pe7_func100_025);
                        WR1_PROG(REG_00D4H, 0x40000000U);
                        WR1_PROG(REG_00D0H, 0xe7009d05U);

                        r_rsip_func_sub012(0x81840007U, 0x00490011U);
                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);

                        static const uint32_t Param_pe7_func100_026[] =
                        {
                            BSWAP_32BIG_C(0x7f3d54a8U), BSWAP_32BIG_C(0xbb9102dcU), BSWAP_32BIG_C(0x8afdb787U),
                            BSWAP_32BIG_C(0xee8c689bU),
                        };
                        r_rsip_func100(Param_pe7_func100_026);
                        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func101_046[] =
                        {
                            BSWAP_32BIG_C(0xe7e379aaU), BSWAP_32BIG_C(0xf8371c27U), BSWAP_32BIG_C(0x3d10e0c4U),
                            BSWAP_32BIG_C(0x3c7bba0fU),
                        };
                        r_rsip_func101(Param_pe7_func101_046);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_027[] =
                        {
                            BSWAP_32BIG_C(0x7eecefc1U), BSWAP_32BIG_C(0xf39c06fcU), BSWAP_32BIG_C(0x20c0ab88U),
                            BSWAP_32BIG_C(0x68fa179fU),
                        };
                        r_rsip_func100(Param_pe7_func100_027);
                        WR1_PROG(REG_00D4H, 0x40000100U);
                        WR1_PROG(REG_00D0H, 0xe7009d07U);

                        r_rsip_func_sub012(0x81880007U, 0x00490021U);
                        WR1_PROG(REG_0008H, 0x00001022U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func100_028[] =
                        {
                            BSWAP_32BIG_C(0x9194d8d5U), BSWAP_32BIG_C(0x064d23d7U), BSWAP_32BIG_C(0x53a89920U),
                            BSWAP_32BIG_C(0x83244cd9U),
                        };
                        r_rsip_func100(Param_pe7_func100_028);
                        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[9]);

                        static const uint32_t Param_pe7_func101_047[] =
                        {
                            BSWAP_32BIG_C(0xea8afebcU), BSWAP_32BIG_C(0xc18b70ebU), BSWAP_32BIG_C(0x95fc4bfeU),
                            BSWAP_32BIG_C(0x0ab32077U),
                        };
                        r_rsip_func101(Param_pe7_func101_047);
                    }

                    static const uint32_t Param_pe7_func100_029[] =
                    {
                        BSWAP_32BIG_C(0x65a86bd8U), BSWAP_32BIG_C(0xb6201e6cU), BSWAP_32BIG_C(0x4710403cU),
                        BSWAP_32BIG_C(0x78fe3362U),
                    };
                    r_rsip_func100(Param_pe7_func100_029);
                    r_rsip_func_sub017(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe7_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x9ed7c3ddU), BSWAP_32BIG_C(0xdac883ddU), BSWAP_32BIG_C(0xbca9a5a5U),
                        BSWAP_32BIG_C(0xac52adeeU),
                    };
                    r_rsip_func102(Param_pe7_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
                else
                {
                    r_rsip_func_sub010(0x3420a840U, 0x00000006U, 0x00A70000U);

                    static const uint32_t Param_pe7_func100_030[] =
                    {
                        BSWAP_32BIG_C(0x2043b9f2U), BSWAP_32BIG_C(0xf5460363U), BSWAP_32BIG_C(0xf5f84729U),
                        BSWAP_32BIG_C(0xc4b65b59U),
                    };
                    r_rsip_func100(Param_pe7_func100_030);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_031[] =
                        {
                            BSWAP_32BIG_C(0x5bb79af0U), BSWAP_32BIG_C(0xfba92fa6U), BSWAP_32BIG_C(0xf3dfa057U),
                            BSWAP_32BIG_C(0x9580b098U),
                        };
                        r_rsip_func100(Param_pe7_func100_031);
                        WR1_PROG(REG_00D4H, 0x40000100U);
                        WR1_PROG(REG_00D0H, 0xe7009d07U);

                        r_rsip_func_sub012(0x81880007U, 0x00490021U);
                        WR1_PROG(REG_0008H, 0x00001022U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[1]);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[5]);

                        r_rsip_func_sub010(0x38008840U, 0x00000006U, 0x00270000U);

                        static const uint32_t Param_pe7_func100_032[] =
                        {
                            BSWAP_32BIG_C(0x942cbbb8U), BSWAP_32BIG_C(0x07079968U), BSWAP_32BIG_C(0xcf6a3628U),
                            BSWAP_32BIG_C(0xddeda1deU),
                        };
                        r_rsip_func100(Param_pe7_func100_032);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            static const uint32_t Param_pe7_func100_033[] =
                            {
                                BSWAP_32BIG_C(0x658f2046U), BSWAP_32BIG_C(0x07fa69a8U), BSWAP_32BIG_C(0x124e0f84U),
                                BSWAP_32BIG_C(0x51a1522bU),
                            };
                            r_rsip_func100(Param_pe7_func100_033);
                            r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                            r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                            RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[9]);

                            static const uint32_t Param_pe7_func101_048[] =
                            {
                                BSWAP_32BIG_C(0xce2eb1baU), BSWAP_32BIG_C(0x4a3d151aU), BSWAP_32BIG_C(0xffea5083U),
                                BSWAP_32BIG_C(0x9367eb7cU),
                            };
                            r_rsip_func101(Param_pe7_func101_048);
                        }
                        else
                        {
                            static const uint32_t Param_pe7_func100_034[] =
                            {
                                BSWAP_32BIG_C(0x8e911f12U), BSWAP_32BIG_C(0x5f73c9d6U), BSWAP_32BIG_C(0x29d4200cU),
                                BSWAP_32BIG_C(0x59b053b9U),
                            };
                            r_rsip_func100(Param_pe7_func100_034);
                            WR1_PROG(REG_0094H, 0x00007c04U);
                            WR1_PROG(REG_0040H, 0x00600000U);

                            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                            {
                                WR1_PROG(REG_0094H, 0x00003426U);

                                r_rsip_func_sub010(0x38008860U, 0x00000020U, 0x00270000U);

                                static const uint32_t Param_pe7_func100_035[] =
                                {
                                    BSWAP_32BIG_C(0x93597a1dU), BSWAP_32BIG_C(0x1dd3c05bU), BSWAP_32BIG_C(0x46c513c1U),
                                    BSWAP_32BIG_C(0xe4086a65U),
                                };
                                r_rsip_func100(Param_pe7_func100_035);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    WR1_PROG(REG_00B0H, 0x00001804U);

                                    static const uint32_t Param_pe7_func101_049[] =
                                    {
                                        BSWAP_32BIG_C(0x9612281fU), BSWAP_32BIG_C(0x270736d2U), BSWAP_32BIG_C(
                                            0x0be7ab39U),           BSWAP_32BIG_C(0x6270294cU),
                                    };
                                    r_rsip_func101(Param_pe7_func101_049);
                                }
                                else
                                {
                                    r_rsip_func_sub010(0x38008860U, 0x00000040U, 0x00270000U);

                                    static const uint32_t Param_pe7_func100_036[] =
                                    {
                                        BSWAP_32BIG_C(0x8a481fcfU), BSWAP_32BIG_C(0x3bb40884U), BSWAP_32BIG_C(
                                            0x92d24ff4U),           BSWAP_32BIG_C(0xadc0726eU),
                                    };
                                    r_rsip_func100(Param_pe7_func100_036);
                                    WR1_PROG(REG_0040H, 0x00400000U);

                                    if (CHCK_STS(REG_0040H, 22, 1))
                                    {
                                        WR1_PROG(REG_00B0H, 0x00003808U);

                                        static const uint32_t Param_pe7_func101_050[] =
                                        {
                                            BSWAP_32BIG_C(0xcdf40887U), BSWAP_32BIG_C(0x50b3789eU), BSWAP_32BIG_C(
                                                0x2364c4b7U),           BSWAP_32BIG_C(0x3b9e17f3U),
                                        };
                                        r_rsip_func101(Param_pe7_func101_050);
                                    }
                                    else
                                    {
                                        WR1_PROG(REG_00B0H, 0x0000b80cU);

                                        static const uint32_t Param_pe7_func101_051[] =
                                        {
                                            BSWAP_32BIG_C(0x641dacf0U), BSWAP_32BIG_C(0x6bf1fef3U), BSWAP_32BIG_C(
                                                0x6fa947caU),           BSWAP_32BIG_C(0x0d46d5ddU),
                                        };
                                        r_rsip_func101(Param_pe7_func101_051);
                                    }

                                    static const uint32_t Param_pe7_func101_052[] =
                                    {
                                        BSWAP_32BIG_C(0x93d6407fU), BSWAP_32BIG_C(0xf7495c30U), BSWAP_32BIG_C(
                                            0x3c0cc76dU),           BSWAP_32BIG_C(0xa53577d1U),
                                    };
                                    r_rsip_func101(Param_pe7_func101_052);
                                }

                                static const uint32_t Param_pe7_func101_053[] =
                                {
                                    BSWAP_32BIG_C(0x3f932ad8U), BSWAP_32BIG_C(0x395a9e71U), BSWAP_32BIG_C(0x9535e686U),
                                    BSWAP_32BIG_C(0x2994d2afU),
                                };
                                r_rsip_func101(Param_pe7_func101_053);
                            }
                            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                            {
                                WR1_PROG(REG_0094H, 0x00003426U);

                                r_rsip_func_sub010(0x38008860U, 0x00000030U, 0x00270000U);

                                static const uint32_t Param_pe7_func100_037[] =
                                {
                                    BSWAP_32BIG_C(0xb007c3a2U), BSWAP_32BIG_C(0x2ae949c2U), BSWAP_32BIG_C(0x0e4783f5U),
                                    BSWAP_32BIG_C(0x8b577cd5U),
                                };
                                r_rsip_func100(Param_pe7_func100_037);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    WR1_PROG(REG_00B0H, 0x00009806U);

                                    static const uint32_t Param_pe7_func101_054[] =
                                    {
                                        BSWAP_32BIG_C(0xc46f1a06U), BSWAP_32BIG_C(0x81b9d431U), BSWAP_32BIG_C(
                                            0x97387ebfU),           BSWAP_32BIG_C(0x890ec869U),
                                    };
                                    r_rsip_func101(Param_pe7_func101_054);
                                }
                                else
                                {
                                    WR1_PROG(REG_00B0H, 0x0000b80cU);

                                    static const uint32_t Param_pe7_func101_055[] =
                                    {
                                        BSWAP_32BIG_C(0xe7679254U), BSWAP_32BIG_C(0x438bd26fU), BSWAP_32BIG_C(
                                            0xe7e3e92bU),           BSWAP_32BIG_C(0xacc755c2U),
                                    };
                                    r_rsip_func101(Param_pe7_func101_055);
                                }

                                static const uint32_t Param_pe7_func101_056[] =
                                {
                                    BSWAP_32BIG_C(0x362f5818U), BSWAP_32BIG_C(0x537087deU), BSWAP_32BIG_C(0xda3a555aU),
                                    BSWAP_32BIG_C(0x49f17071U),
                                };
                                r_rsip_func101(Param_pe7_func101_056);
                            }

                            WR1_PROG(REG_0094H, 0x000008a5U);

                            static const uint32_t Param_pe7_func100_038[] =
                            {
                                BSWAP_32BIG_C(0xb3b715fcU), BSWAP_32BIG_C(0x77aaf802U), BSWAP_32BIG_C(0x10315dc0U),
                                BSWAP_32BIG_C(0xe3829811U),
                            };
                            r_rsip_func100(Param_pe7_func100_038);
                            r_rsip_func_sub017(0x81010060U, 0x00005006U);
                            RD1_ADDR(REG_002CH, &S_RAM[0]);
                            S_RAM[0] = bswap_32big(S_RAM[0]);

                            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                            {
                                r_rsip_func_sub016(0x342028a1U, 0x00000080U, 0x00270000U);

                                r_rsip_func_sub010(0x3420a8e0U, 0x00000010U, 0x00A70000U);

                                static const uint32_t Param_pe7_func100_039[] =
                                {
                                    BSWAP_32BIG_C(0x14b4c4bbU), BSWAP_32BIG_C(0x28ac32e3U), BSWAP_32BIG_C(0x82106fb9U),
                                    BSWAP_32BIG_C(0x4d856ceaU),
                                };
                                r_rsip_func100(Param_pe7_func100_039);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub015(0x1000000dU, 0x00001800U);
                                    r_rsip_func_sub015(0x10030005U, 0x00001800U);

                                    static const uint32_t Param_pe7_func101_057[] =
                                    {
                                        BSWAP_32BIG_C(0xdc2f657bU), BSWAP_32BIG_C(0x969e41e5U), BSWAP_32BIG_C(
                                            0x9d21d2cdU),           BSWAP_32BIG_C(0x60c0dca6U),
                                    };
                                    r_rsip_func101(Param_pe7_func101_057);
                                }
                                else
                                {
                                    r_rsip_func_sub005(0x800100c0U, 0x1340000dU, 0x13430005U);

                                    WR1_PROG(REG_0094H, 0x02003cc7U);

                                    WR1_PROG(REG_0094H, 0x00002ce0U);

                                    static const uint32_t Param_pe7_func101_058[] =
                                    {
                                        BSWAP_32BIG_C(0x009ccbb6U), BSWAP_32BIG_C(0xe33ae4d6U), BSWAP_32BIG_C(
                                            0x47504141U),           BSWAP_32BIG_C(0xefc71cb8U),
                                    };
                                    r_rsip_func101(Param_pe7_func101_058);
                                }

                                WR1_PROG(REG_0094H, 0x00002ca0U);

                                static const uint32_t Param_pe7_func101_059[] =
                                {
                                    BSWAP_32BIG_C(0x96123615U), BSWAP_32BIG_C(0x89bf3aa3U), BSWAP_32BIG_C(0x1c07ecc6U),
                                    BSWAP_32BIG_C(0x8bd19b3aU),
                                };
                                r_rsip_func101(Param_pe7_func101_059);
                            }

                            r_rsip_func_sub016(0x380008a3U, 0x00000080U, 0x00270000U);
                            WR1_PROG(REG_0040H, 0x00402000U);

                            WR1_PROG(REG_0094H, 0x000008e7U);

                            static const uint32_t Param_pe7_func100_040[] =
                            {
                                BSWAP_32BIG_C(0xe7136344U), BSWAP_32BIG_C(0x416972ebU), BSWAP_32BIG_C(0x6ab1ac80U),
                                BSWAP_32BIG_C(0x292fe3b0U),
                            };
                            r_rsip_func100(Param_pe7_func100_040);
                            WR1_PROG(REG_00D4H, 0x40000000U);
                            WR1_PROG(REG_00D0H, 0xe7008d05U);

                            r_rsip_func_sub012(0x81840007U, 0x00490011U);
                            WR1_PROG(REG_0008H, 0x00001012U);
                            WAIT_STS(REG_0008H, 30, 1);
                            RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[9]);

                            static const uint32_t Param_pe7_func100_041[] =
                            {
                                BSWAP_32BIG_C(0x04df8c75U), BSWAP_32BIG_C(0x94641ddfU), BSWAP_32BIG_C(0x989f2569U),
                                BSWAP_32BIG_C(0x475c6e29U),
                            };
                            r_rsip_func100(Param_pe7_func100_041);
                            r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                            r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                            RD4_ADDR(REG_002CH, &OutData_HMACKeyIndex[13]);

                            static const uint32_t Param_pe7_func101_060[] =
                            {
                                BSWAP_32BIG_C(0x333c14cbU), BSWAP_32BIG_C(0xb9501fd2U), BSWAP_32BIG_C(0x8777c968U),
                                BSWAP_32BIG_C(0xb9640223U),
                            };
                            r_rsip_func101(Param_pe7_func101_060);
                        }

                        static const uint32_t Param_pe7_func100_042[] =
                        {
                            BSWAP_32BIG_C(0x95b1eb14U), BSWAP_32BIG_C(0x4234e1baU), BSWAP_32BIG_C(0x150c58cdU),
                            BSWAP_32BIG_C(0xaac7bd00U),
                        };
                        r_rsip_func100(Param_pe7_func100_042);
                        r_rsip_func_sub017(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_002CH, &OutData_HMACKeyIndex[0]);

                        static const uint32_t Param_pe7_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x7d6b79c7U), BSWAP_32BIG_C(0x5fa01c3eU), BSWAP_32BIG_C(0xadb77805U),
                            BSWAP_32BIG_C(0xf22ea65eU),
                        };
                        r_rsip_func102(Param_pe7_func102_005);
                        WR1_PROG(REG_006CH, 0x00000040U);
                        WAIT_STS(REG_0020H, 12, 0);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_043[] =
                        {
                            BSWAP_32BIG_C(0x7fcbdd01U), BSWAP_32BIG_C(0x59e5016cU), BSWAP_32BIG_C(0x43ad7445U),
                            BSWAP_32BIG_C(0x77dfdb04U),
                        };
                        r_rsip_func100(Param_pe7_func100_043);
                        WR1_PROG(REG_00D4H, 0x40000000U);
                        WR1_PROG(REG_00D0H, 0xe7009d05U);

                        r_rsip_func_sub012(0x81840007U, 0x00490011U);
                        WR1_PROG(REG_0008H, 0x00001012U);
                        WAIT_STS(REG_0008H, 30, 1);
                        RD4_ADDR(REG_002CH, &OutData_EncIV[1]);

                        static const uint32_t Param_pe7_func100_044[] =
                        {
                            BSWAP_32BIG_C(0x5a6c7a79U), BSWAP_32BIG_C(0x8376be5aU), BSWAP_32BIG_C(0xd2512f7aU),
                            BSWAP_32BIG_C(0xa76c01c8U),
                        };
                        r_rsip_func100(Param_pe7_func100_044);
                        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                        RD4_ADDR(REG_002CH, &OutData_EncIV[5]);

                        static const uint32_t Param_pe7_func100_045[] =
                        {
                            BSWAP_32BIG_C(0x14f5adf1U), BSWAP_32BIG_C(0xb07fd031U), BSWAP_32BIG_C(0x94dd42aeU),
                            BSWAP_32BIG_C(0xb4ffc86aU),
                        };
                        r_rsip_func100(Param_pe7_func100_045);
                        r_rsip_func_sub017(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_002CH, &OutData_EncIV[0]);

                        static const uint32_t Param_pe7_func102_006[] =
                        {
                            BSWAP_32BIG_C(0x0212979fU), BSWAP_32BIG_C(0x3a7c8125U), BSWAP_32BIG_C(0xed9fa888U),
                            BSWAP_32BIG_C(0xffb29142U),
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
