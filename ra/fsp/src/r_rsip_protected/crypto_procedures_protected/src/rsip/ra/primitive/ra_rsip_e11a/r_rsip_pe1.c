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

rsip_ret_t r_rsip_pe1 (const uint32_t InData_Sel_KeyType[],
                       const uint32_t InData_Certificate[],
                       const uint32_t InData_CertificateLength[],
                       const uint32_t InData_CertificatePubKey[],
                       const uint32_t InData_EncCertificateInfo[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t iTemp = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00e10001U, 0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_Sel_KeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub007(0x3420a800U, 0x00000003U, 0x00260000U);

    r_rsip_func_sub007(0x38008800U, 0x00000004U, 0x00260000U);

    r_rsip_func_sub007(0x38008800U, 0x00000005U, 0x00260000U);

    static const uint32_t Param_pe1_func100_001[] =
    {
        BSWAP_32BIG_C(0xe5f121e0U), BSWAP_32BIG_C(0x65e237e3U), BSWAP_32BIG_C(0x0c7bc9c8U), BSWAP_32BIG_C(0x928b56ccU),
    };
    r_rsip_func100(Param_pe1_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe1_func102_001[] =
        {
            BSWAP_32BIG_C(0x25ae2478U), BSWAP_32BIG_C(0x91146df6U), BSWAP_32BIG_C(0x8991984dU), BSWAP_32BIG_C(
                0xe77d770dU),
        };
        r_rsip_func102(Param_pe1_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub016(0x3000a800U, 0x00000006U, 0x00010020U);
        r_rsip_func_sub016(0x0000b400U, 0x00000006U, 0x00000080U);

        r_rsip_func_sub016(0x0000b420U, 0x00000014U, 0x00003c01U);

        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x010f6caaU);

        static const uint32_t Param_pe1_sub100_001[] =
        {
            BSWAP_32BIG_C(0x0000e101U), BSWAP_32BIG_C(0xcd3d1509U), BSWAP_32BIG_C(0xb4859818U),
            BSWAP_32BIG_C(0xb2abcf16U),
            BSWAP_32BIG_C(0x18d8cb92U), BSWAP_32BIG_C(0x0000e101U), BSWAP_32BIG_C(0xccfe9c52U),
            BSWAP_32BIG_C(0x4b68d4f1U),
            BSWAP_32BIG_C(0x208c08fcU),
            BSWAP_32BIG_C(0xa568c4bcU), 0x00001404U,
        };
        r_rsip_func_sub100(InData_EncCertificateInfo, Param_pe1_sub100_001, RSIP_SEL_BIT_LENGTH_256);

        static const uint32_t Param_pe1_func100_002[] =
        {
            BSWAP_32BIG_C(0xbcc3e720U), BSWAP_32BIG_C(0xa337f7abU), BSWAP_32BIG_C(0x92e842feU), BSWAP_32BIG_C(
                0x1b6469edU),
        };
        r_rsip_func100(Param_pe1_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe1_func102_002[] =
            {
                BSWAP_32BIG_C(0x028f9647U), BSWAP_32BIG_C(0x4fc9280cU), BSWAP_32BIG_C(0x2cce16c6U), BSWAP_32BIG_C(
                    0x1fb06394U),
            };
            r_rsip_func102(Param_pe1_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x80010040U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificateLength[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            WR1_PROG(REG_0014H, 0x000003c7U);
            WR1_PROG(REG_009CH, 0x80040060U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[0]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[1]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[2]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[3]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func004();

            WR1_PROG(REG_00F4H, 0x00000011U);

            r_rsip_func_sub016(0x000008e7U, 0x0000b400U, 0x0000001fU);

            r_rsip_func_sub016(0x0000b420U, 0x0000001fU, 0x3c0028a6U);
            r_rsip_func_sub016(0x1000d0e0U, 0x00002425U, 0x08002826U);
            r_rsip_func_sub016(0x2000d0e0U, 0x3c002864U, 0x1000d0e0U);

            r_rsip_func_sub016(0x3c002885U, 0x1000d0e0U, 0x00002403U);
            r_rsip_func_sub016(0x08002804U, 0x2000d0e0U, 0x3c0028c2U);
            r_rsip_func_sub007(0x1000d0e0U, 0x38000ce7U, 0x00A60000U);

            static const uint32_t Param_pe1_func100_003[] =
            {
                BSWAP_32BIG_C(0x1328827aU), BSWAP_32BIG_C(0x329679f6U), BSWAP_32BIG_C(0xcc3eff9cU), BSWAP_32BIG_C(
                    0x50dd2d60U),
            };
            r_rsip_func100(Param_pe1_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe1_func102_003[] =
                {
                    BSWAP_32BIG_C(0x1bf07fbaU), BSWAP_32BIG_C(0xa5b1994cU), BSWAP_32BIG_C(0x5b1488a6U), BSWAP_32BIG_C(
                        0x78756be3U),
                };
                r_rsip_func102(Param_pe1_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe1_func100_004[] =
                {
                    BSWAP_32BIG_C(0x83f703f4U), BSWAP_32BIG_C(0xa82db290U), BSWAP_32BIG_C(0x5e70bc6bU), BSWAP_32BIG_C(
                        0xf8b7a50eU),
                };
                r_rsip_func100(Param_pe1_func100_004);
                WR1_PROG(REG_0094H, 0x00003403U);
                WR1_PROG(REG_0094H, 0x00046800U);
                r_rsip_func_sub015(0x00026c00U, 0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x00000821U);

                for (iLoop = 0U; iLoop < S_RAM[0]; )
                {
                    WR1_PROG(REG_0014H, 0x000003c4U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR4_ADDR(REG_002CH, &InData_Certificate[iLoop]);

                    WR1_PROG(REG_0094H, 0x0000a420U);
                    WR1_PROG(REG_0094H, 0x00000004U);

                    static const uint32_t Param_pe1_func101_001[] =
                    {
                        BSWAP_32BIG_C(0xf75ac6b5U), BSWAP_32BIG_C(0x286e420eU), BSWAP_32BIG_C(0x0c39df1cU),
                        BSWAP_32BIG_C(0x78c218eaU),
                    };
                    r_rsip_func101(Param_pe1_func101_001);
                    iLoop = iLoop + 4U;
                }

                static const uint32_t Param_pe1_func100_005[] =
                {
                    BSWAP_32BIG_C(0x0922ba4cU), BSWAP_32BIG_C(0xa11bab47U), BSWAP_32BIG_C(0x7d10fd5aU), BSWAP_32BIG_C(
                        0x844f9a5fU),
                };
                r_rsip_func100(Param_pe1_func100_005);

                r_rsip_func_sub010(0x38000801U);

                WR1_PROG(REG_00B0H, 0x0000340cU);

                r_rsip_func_sub016(0x00003402U, 0x0000a400U, 0x00000003U);
                r_rsip_func_sub015(0x00026800U, 0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub016(0x000034e1U, 0x00026ce7U, 0x00003040U);

                WR1_PROG(REG_0094H, 0x00000884U);
                WR1_PROG(REG_0094H, 0x00003c04U);

                iTemp = iLoop;
                for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                {
                    WR1_PROG(REG_0014H, 0x000000c7U);
                    WR1_PROG(REG_009CH, 0x800100c0U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR1_PROG(REG_002CH, InData_Certificate[iLoop]);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    r_rsip_func_sub016(0x0000b480U, 0x00000004U, 0x00003c24U);

                    WR1_PROG(REG_0094H, 0x00000821U);

                    for (jLoop = 0U; jLoop < 4; jLoop++)
                    {
                        r_rsip_func_sub016(0x00002c20U, 0x01886c06U, 0x00086cc6U);

                        WR1_PROG(REG_0094H, 0x00003485U);
                        WR1_PROG(REG_0094H, 0x0000a480U);
                        r_rsip_func_sub007(0x0000001fU, 0x3c0028e5U, 0x00260000U);

                        static const uint32_t Param_pe1_func100_006[] =
                        {
                            BSWAP_32BIG_C(0x2987208bU), BSWAP_32BIG_C(0xadd9ab59U), BSWAP_32BIG_C(0xab120c79U),
                            BSWAP_32BIG_C(0x1883f843U),
                        };
                        r_rsip_func100(Param_pe1_func100_006);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_0094H, 0x3c002887U);
                            WR1_PROG(REG_009CH, 0x00000080U);
                            WR1_PROG(REG_0040H, 0x00260000U);

                            static const uint32_t Param_pe1_func100_007[] =
                            {
                                BSWAP_32BIG_C(0x603aa01bU), BSWAP_32BIG_C(0x99da0e79U), BSWAP_32BIG_C(0x17aa7b3eU),
                                BSWAP_32BIG_C(0x3730dbefU),
                            };
                            r_rsip_func100(Param_pe1_func100_007);
                            WR1_PROG(REG_0040H, 0x00400000U);
                            WR1_PROG(REG_0024H, 0x00000000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                                WR1_PROG(REG_0000H, 0x10c90005U);
                                WAIT_STS(REG_0004H, 30, 0);
                                WR1_PROG(REG_0040H, 0x00001800U);

                                static const uint32_t Param_pe1_func101_002[] =
                                {
                                    BSWAP_32BIG_C(0xab2bfd28U), BSWAP_32BIG_C(0xc8601e9dU), BSWAP_32BIG_C(0x9a11cbd3U),
                                    BSWAP_32BIG_C(0x58706426U),
                                };
                                r_rsip_func101(Param_pe1_func101_002);
                            }

                            static const uint32_t Param_pe1_func101_003[] =
                            {
                                BSWAP_32BIG_C(0x814699bbU), BSWAP_32BIG_C(0x2475659dU), BSWAP_32BIG_C(0x9a76d792U),
                                BSWAP_32BIG_C(0x1e04e42bU),
                            };
                            r_rsip_func101(Param_pe1_func101_003);
                        }

                        WR1_PROG(REG_0094H, 0x00003483U);
                        WR1_PROG(REG_0094H, 0x0000a480U);
                        r_rsip_func_sub007(0x0000001fU, 0x3c0028e3U, 0x00260000U);

                        static const uint32_t Param_pe1_func100_008[] =
                        {
                            BSWAP_32BIG_C(0xfc0b07e3U), BSWAP_32BIG_C(0x4bef6665U), BSWAP_32BIG_C(0x1d9db218U),
                            BSWAP_32BIG_C(0xf3d11aacU),
                        };
                        r_rsip_func100(Param_pe1_func100_008);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            WR1_PROG(REG_0094H, 0x3c002887U);
                            WR1_PROG(REG_009CH, 0x00000080U);
                            WR1_PROG(REG_0040H, 0x00260000U);

                            static const uint32_t Param_pe1_func100_009[] =
                            {
                                BSWAP_32BIG_C(0x938c16cbU), BSWAP_32BIG_C(0x248f3a12U), BSWAP_32BIG_C(0xfeef9f7aU),
                                BSWAP_32BIG_C(0x2b476dedU),
                            };
                            r_rsip_func100(Param_pe1_func100_009);
                            WR1_PROG(REG_0040H, 0x00400000U);
                            WR1_PROG(REG_0024H, 0x00000000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                                WR1_PROG(REG_0000H, 0x10c90005U);
                                WAIT_STS(REG_0004H, 30, 0);
                                WR1_PROG(REG_0040H, 0x00001800U);

                                static const uint32_t Param_pe1_func101_004[] =
                                {
                                    BSWAP_32BIG_C(0x76c81461U), BSWAP_32BIG_C(0x386f1eb2U), BSWAP_32BIG_C(0xb79c0f64U),
                                    BSWAP_32BIG_C(0x4e862579U),
                                };
                                r_rsip_func101(Param_pe1_func101_004);
                            }

                            static const uint32_t Param_pe1_func101_005[] =
                            {
                                BSWAP_32BIG_C(0xde4c11c5U), BSWAP_32BIG_C(0xc43ee273U), BSWAP_32BIG_C(0xd96c3ef1U),
                                BSWAP_32BIG_C(0xf47d63a8U),
                            };
                            r_rsip_func101(Param_pe1_func101_005);
                        }

                        WR1_PROG(REG_0094H, 0x3c002847U);
                        WR1_PROG(REG_009CH, 0x00000080U);
                        WR1_PROG(REG_0040H, 0x00260000U);

                        static const uint32_t Param_pe1_func100_010[] =
                        {
                            BSWAP_32BIG_C(0xccd785c4U), BSWAP_32BIG_C(0x1a5968bcU), BSWAP_32BIG_C(0x2d47b810U),
                            BSWAP_32BIG_C(0x1a7d6ea2U),
                        };
                        r_rsip_func100(Param_pe1_func100_010);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                            WR1_PROG(REG_0000H, 0x11490005U);
                            WAIT_STS(REG_0004H, 30, 0);
                            WR1_PROG(REG_0040H, 0x00001800U);

                            static const uint32_t Param_pe1_func101_006[] =
                            {
                                BSWAP_32BIG_C(0x710b5ab0U), BSWAP_32BIG_C(0xf9b5586fU), BSWAP_32BIG_C(0xea77bec5U),
                                BSWAP_32BIG_C(0x07e5942eU),
                            };
                            r_rsip_func101(Param_pe1_func101_006);
                        }

                        WR1_PROG(REG_0094H, 0x00002ce0U);

                        static const uint32_t Param_pe1_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xbfde6369U), BSWAP_32BIG_C(0xf6d547f1U), BSWAP_32BIG_C(0xfb5bfdafU),
                            BSWAP_32BIG_C(0x5849dd6fU),
                        };
                        r_rsip_func101(Param_pe1_func101_007);
                    }

                    r_rsip_func_sub007(0x38008820U, 0x00000004U, 0x00260000U);
                    WR1_PROG(REG_0040H, 0x00402000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    r_rsip_func_sub016(0x0000b480U, 0x00000004U, 0x00003824U);

                    WR1_PROG(REG_0094H, 0x00002c20U);

                    static const uint32_t Param_pe1_func101_008[] =
                    {
                        BSWAP_32BIG_C(0xede7ab1cU), BSWAP_32BIG_C(0xafbab4b4U), BSWAP_32BIG_C(0xbda5e765U),
                        BSWAP_32BIG_C(0x063b4ad7U),
                    };
                    r_rsip_func101(Param_pe1_func101_008);
                }

                WR1_PROG(REG_0094H, 0x00000884U);
                r_rsip_func_sub007(0x00003804U, 0x38000801U, 0x00260000U);
                WR1_PROG(REG_0040H, 0x00402000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub016(0x00002c40U, 0x0000b400U, 0x00000080U);
                r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                r_rsip_func_sub009(0x11490005U, 0x00003402U);
                r_rsip_func_sub016(0x00002c00U, 0x00008c00U, 0x0000003fU);

                WR1_PROG(REG_0094H, 0x0000b420U);
                r_rsip_func_sub007(0x00000038U, 0x3c002820U, 0x00260000U);

                static const uint32_t Param_pe1_func100_011[] =
                {
                    BSWAP_32BIG_C(0xf2e94975U), BSWAP_32BIG_C(0x29ae8986U), BSWAP_32BIG_C(0xa45541baU), BSWAP_32BIG_C(
                        0x22aeba71U),
                };
                r_rsip_func100(Param_pe1_func100_011);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x00202820U);

                    static const uint32_t Param_pe1_func101_009[] =
                    {
                        BSWAP_32BIG_C(0xb41d2540U), BSWAP_32BIG_C(0xee2f1a2cU), BSWAP_32BIG_C(0x5aed749aU),
                        BSWAP_32BIG_C(0x36ae81d6U),
                    };
                    r_rsip_func101(Param_pe1_func101_009);
                }
                else
                {
                    r_rsip_func_sub016(0x0000a420U, 0x00000040U, 0x00202820U);

                    static const uint32_t Param_pe1_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x761e6a23U), BSWAP_32BIG_C(0x7d3ea277U), BSWAP_32BIG_C(0x3810233aU),
                        BSWAP_32BIG_C(0xdd14c661U),
                    };
                    r_rsip_func101(Param_pe1_func101_010);
                }

                static const uint32_t Param_pe1_func100_012[] =
                {
                    BSWAP_32BIG_C(0x65eb4f3aU), BSWAP_32BIG_C(0x2b297a30U), BSWAP_32BIG_C(0xff99ab44U), BSWAP_32BIG_C(
                        0xb0d8216dU),
                };
                r_rsip_func100(Param_pe1_func100_012);
                WR1_PROG(REG_009CH, 0x81010020U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x000008a5U);

                WR1_PROG(REG_0094H, 0x00000800U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub003(0x81010000U, 0x11490005U);
                    r_rsip_func_sub009(0x1009000dU, 0x00002ca0U);

                    static const uint32_t Param_pe1_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x8a87c4b0U), BSWAP_32BIG_C(0xf8bcf046U), BSWAP_32BIG_C(0x4444cda6U),
                        BSWAP_32BIG_C(0x09d050dfU),
                    };
                    r_rsip_func101(Param_pe1_func101_011);
                }

                r_rsip_func_sub010(0x38000825U);

                r_rsip_func_sub016(0x00000821U, 0x01836c22U, 0x00036c42U);

                r_rsip_func_sub003(0x81020020U, 0x01490009U);

                WAIT_STS(REG_00F8H, 2, 0);

                WR1_PROG(REG_00F4H, 0x00000100U);

                WR1_PROG(REG_0040H, 0x00001600U);

                WR1_PROG(REG_00F4H, 0x00000020U);

                WR1_PROG(REG_0094H, 0x000008a5U);

                WR1_PROG(REG_0094H, 0x00000800U);

                WR1_PROG(REG_00B0H, 0x00001804U);

                for (iLoop = 0U; iLoop < 8U; iLoop++)
                {
                    r_rsip_func_sub003(0x80010020U, 0x03450005U);

                    r_rsip_func_sub003(0x80010040U, 0x03430005U);

                    r_rsip_func_sub016(0x08002822U, 0x2000d000U, 0x00002ca0U);

                    static const uint32_t Param_pe1_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x6a08b8abU), BSWAP_32BIG_C(0x6a4daf43U), BSWAP_32BIG_C(0x39316551U),
                        BSWAP_32BIG_C(0x48b425d6U),
                    };
                    r_rsip_func101(Param_pe1_func101_012);
                }

                r_rsip_func_sub007(0x380088a0U, 0x00000008U, 0x00260000U);
                WR1_PROG(REG_0040H, 0x00402000U);
                r_rsip_func_sub012(0x38000c00U, 0x00A60000U);

                static const uint32_t Param_pe1_func100_013[] =
                {
                    BSWAP_32BIG_C(0xde099eecU), BSWAP_32BIG_C(0x57064854U), BSWAP_32BIG_C(0xf0665017U), BSWAP_32BIG_C(
                        0x31bedd1bU),
                };
                r_rsip_func100(Param_pe1_func100_013);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pe1_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x7b1b8e14U), BSWAP_32BIG_C(0x842f3439U), BSWAP_32BIG_C(0x85e828c6U),
                        BSWAP_32BIG_C(0x6e790ec4U),
                    };
                    r_rsip_func102(Param_pe1_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pe1_func100_014[] =
                    {
                        BSWAP_32BIG_C(0xae6cb94dU), BSWAP_32BIG_C(0x6acfde91U), BSWAP_32BIG_C(0x6ffc68c0U),
                        BSWAP_32BIG_C(0x0e3f2206U),
                    };
                    r_rsip_func100(Param_pe1_func100_014);
                    r_rsip_func103();

                    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                    r_rsip_func_sub003(0x80010000U, 0x03410005U);
                    r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                    r_rsip_func_sub002(0x800100e0U, 0x0000e102U);

                    static const uint32_t Param_pe1_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x9e3fc928U), BSWAP_32BIG_C(0x7093442dU), BSWAP_32BIG_C(0xac97fad1U),
                        BSWAP_32BIG_C(0x5e214651U),
                    };
                    r_rsip_func101(Param_pe1_func101_013);
                    r_rsip_func143();

                    r_rsip_func_sub016(0x0000b420U, 0x00000014U, 0x00003881U);

                    static const uint32_t Param_pe1_func100_015[] =
                    {
                        BSWAP_32BIG_C(0x6fb3857bU), BSWAP_32BIG_C(0xf4f0bfc9U), BSWAP_32BIG_C(0xa1555e15U),
                        BSWAP_32BIG_C(0x78c05a97U),
                    };
                    r_rsip_func100(Param_pe1_func100_015);
                    WR1_PROG(REG_0094H, 0x00007c04U);
                    WR1_PROG(REG_0040H, 0x00600000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
                    {
                        WR1_PROG(REG_0094H, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x00000016U);

                        static const uint32_t Param_pe1_func101_014[] =
                        {
                            BSWAP_32BIG_C(0x72005e96U), BSWAP_32BIG_C(0x7686808bU), BSWAP_32BIG_C(0xc55a80b4U),
                            BSWAP_32BIG_C(0xbf17511cU),
                        };
                        r_rsip_func101(Param_pe1_func101_014);
                    }
                    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
                    {
                        WR1_PROG(REG_0094H, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x0000001cU);

                        static const uint32_t Param_pe1_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x58a425fbU), BSWAP_32BIG_C(0x8fccdf2aU), BSWAP_32BIG_C(0x7b381489U),
                            BSWAP_32BIG_C(0xf7dbfbc3U),
                        };
                        r_rsip_func101(Param_pe1_func101_015);
                    }

                    r_rsip_func_sub002(0x800100e0U, 0x0000e102U);

                    static const uint32_t Param_pe1_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x45cb7810U), BSWAP_32BIG_C(0x518be860U), BSWAP_32BIG_C(0x65b7989bU),
                        BSWAP_32BIG_C(0xce21edeeU),
                    };
                    r_rsip_func101(Param_pe1_func101_016);
                    r_rsip_func044();

                    static const uint32_t Param_pe1_func100_016[] =
                    {
                        BSWAP_32BIG_C(0x1b074282U), BSWAP_32BIG_C(0xde072271U), BSWAP_32BIG_C(0xb67e284dU),
                        BSWAP_32BIG_C(0x847f1c1fU),
                    };
                    r_rsip_func100(Param_pe1_func100_016);
                    r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

                    r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

                    WR1_PROG(REG_00D4H, 0x40000100U);
                    WR1_PROG(REG_00D0H, 0xe8008107U);
                    r_rsip_func_sub004(0x00001808U, 0x00430021U);

                    WR1_PROG(REG_0008H, 0x00001022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                    static const uint32_t Param_pe1_func100_017[] =
                    {
                        BSWAP_32BIG_C(0x43435a2fU), BSWAP_32BIG_C(0xdebdd7deU), BSWAP_32BIG_C(0x8797a247U),
                        BSWAP_32BIG_C(0x5169eecdU),
                    };
                    r_rsip_func100(Param_pe1_func100_017);
                    WR1_PROG(REG_00D4H, 0x40000100U);
                    WR1_PROG(REG_00D0H, 0xe8008107U);
                    r_rsip_func_sub004(0x0000180cU, 0x00430021U);

                    WR1_PROG(REG_0008H, 0x00001022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[9]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[13]);

                    static const uint32_t Param_pe1_func100_018[] =
                    {
                        BSWAP_32BIG_C(0x390c85e3U), BSWAP_32BIG_C(0x735c7338U), BSWAP_32BIG_C(0x9e704ba8U),
                        BSWAP_32BIG_C(0x08bb6397U),
                    };
                    r_rsip_func100(Param_pe1_func100_018);
                    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                    WR1_PROG(REG_00D4H, 0x40000000U);
                    r_rsip_func_sub006(0x09108105U, 0x00410011U);

                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[17]);

                    static const uint32_t Param_pe1_func100_019[] =
                    {
                        BSWAP_32BIG_C(0x58603459U), BSWAP_32BIG_C(0x8a2fd396U), BSWAP_32BIG_C(0x6dcb2857U),
                        BSWAP_32BIG_C(0x81ebb71fU),
                    };
                    r_rsip_func100(Param_pe1_func100_019);
                    WR1_PROG(REG_009CH, 0x81010000U);
                    WR1_PROG(REG_0008H, 0x00005006U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe1_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x7a122badU), BSWAP_32BIG_C(0xbcf1ec7eU), BSWAP_32BIG_C(0xcf408e42U),
                        BSWAP_32BIG_C(0xa53289a5U),
                    };
                    r_rsip_func102(Param_pe1_func102_005);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
