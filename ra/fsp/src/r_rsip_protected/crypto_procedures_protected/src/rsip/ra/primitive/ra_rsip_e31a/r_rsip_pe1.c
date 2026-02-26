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

    WR1_PROG(REG_0070H, 0x00e10001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_Sel_KeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub010(0x3420a800U, 0x00000003U, 0x00270000U);

    r_rsip_func_sub010(0x38008800U, 0x00000005U, 0x00270000U);

    static const uint32_t Param_pe1_func100_001[] =
    {
        BSWAP_32BIG_C(0x592b494aU), BSWAP_32BIG_C(0x0d57b2a1U), BSWAP_32BIG_C(0x419ee291U), BSWAP_32BIG_C(0xf8a977daU),
    };
    r_rsip_func100(Param_pe1_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe1_func102_001[] =
        {
            BSWAP_32BIG_C(0x4817d770U), BSWAP_32BIG_C(0x397cbb90U), BSWAP_32BIG_C(0x8f1cb092U), BSWAP_32BIG_C(
                0x91b03a98U),
        };
        r_rsip_func102(Param_pe1_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub022(0x3000a800U, 0x00000007U, 0x00010020U);
        r_rsip_func_sub022(0x0000b400U, 0x00000007U, 0x00000080U);

        r_rsip_func_sub010(0x38008800U, 0x00000003U, 0x00270000U);

        r_rsip_func_sub010(0x38008800U, 0x00000006U, 0x00270000U);

        static const uint32_t Param_pe1_func100_002[] =
        {
            BSWAP_32BIG_C(0xf19cf6e4U), BSWAP_32BIG_C(0xf6ebc056U), BSWAP_32BIG_C(0x754ccd62U), BSWAP_32BIG_C(
                0x8019ccbeU),
        };
        r_rsip_func100(Param_pe1_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub022(0x0000b460U, 0x00000008U, 0x0000b440U);
            r_rsip_func_sub022(0x00000010U, 0x00003c62U, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x010f6caaU);

            static const uint32_t Param_pe1_sub100_001[] =
            {
                BSWAP_32BIG_C(0x0000e101U), BSWAP_32BIG_C(0x1f986baaU), BSWAP_32BIG_C(0x9da66afcU),
                BSWAP_32BIG_C(0x336f0bb2U),
                BSWAP_32BIG_C(0x15b904cbU), BSWAP_32BIG_C(0x0000e101U), BSWAP_32BIG_C(0x8910c6c9U),
                BSWAP_32BIG_C(0x6083b466U),
                BSWAP_32BIG_C(0x5330e36bU),
                BSWAP_32BIG_C(0xccc472e0U), 0x00001404U,
            };
            r_rsip_func_sub100(InData_EncCertificateInfo, Param_pe1_sub100_001, RSIP_SEL_BIT_LENGTH_256);

            static const uint32_t Param_pe1_func101_001[] =
            {
                BSWAP_32BIG_C(0x4706ba3cU), BSWAP_32BIG_C(0xbb9709f9U), BSWAP_32BIG_C(0xda8bce51U), BSWAP_32BIG_C(
                    0xfc554089U),
            };
            r_rsip_func101(Param_pe1_func101_001);
        }
        else
        {
            r_rsip_func_sub022(0x0000b460U, 0x0000000cU, 0x0000b440U);
            r_rsip_func_sub022(0x00000010U, 0x00003c62U, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x01f6c222U);

            static const uint32_t Param_pe1_sub100_002[] =
            {
                BSWAP_32BIG_C(0x0000e102U), BSWAP_32BIG_C(0xe59df274U), BSWAP_32BIG_C(0xb8a5a52dU),
                BSWAP_32BIG_C(0x0c2aab44U),
                BSWAP_32BIG_C(0xd509c6b9U), BSWAP_32BIG_C(0x0000e102U), BSWAP_32BIG_C(0x6527c427U),
                BSWAP_32BIG_C(0x02dc6f19U),
                BSWAP_32BIG_C(0x50601c53U),
                BSWAP_32BIG_C(0xaff1a2baU), 0x00009406U,
            };
            r_rsip_func_sub100(InData_EncCertificateInfo, Param_pe1_sub100_002, RSIP_SEL_BIT_LENGTH_384);

            static const uint32_t Param_pe1_func101_002[] =
            {
                BSWAP_32BIG_C(0x599485bfU), BSWAP_32BIG_C(0x3c93a5e8U), BSWAP_32BIG_C(0xe5b8d288U), BSWAP_32BIG_C(
                    0x123dc990U),
            };
            r_rsip_func101(Param_pe1_func101_002);
        }

        static const uint32_t Param_pe1_func100_003[] =
        {
            BSWAP_32BIG_C(0x1bd0ede6U), BSWAP_32BIG_C(0xf427454dU), BSWAP_32BIG_C(0x361fbaebU), BSWAP_32BIG_C(
                0x21b89fefU),
        };
        r_rsip_func100(Param_pe1_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe1_func102_002[] =
            {
                BSWAP_32BIG_C(0xa44579ccU), BSWAP_32BIG_C(0xa0184398U), BSWAP_32BIG_C(0xf01625cfU), BSWAP_32BIG_C(
                    0x4366b0aeU),
            };
            r_rsip_func102(Param_pe1_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub014(0x000000c7U, 0x80010040U);
            WR1_PROG(REG_002CH, InData_CertificateLength[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub014(0x000003c7U, 0x80040060U);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[0]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[1]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[2]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_CertificatePubKey[3]);
            r_rsip_func_sub018(0x00000000U, 0x0000b420U, 0x00000014U);
            WR1_PROG(REG_0094H, 0x00003c01U);

            WR1_PROG(REG_00F0H, 0x00000001U);

            WR1_PROG(REG_0094H, 0x000008e7U);

            r_rsip_func_sub010(0x38008800U, 0x00000003U, 0x00270000U);

            r_rsip_func_sub010(0x38008800U, 0x00000006U, 0x00270000U);

            static const uint32_t Param_pe1_func100_004[] =
            {
                BSWAP_32BIG_C(0x2d243bb9U), BSWAP_32BIG_C(0x93974f4bU), BSWAP_32BIG_C(0x08b2008aU), BSWAP_32BIG_C(
                    0x036ab821U),
            };
            r_rsip_func100(Param_pe1_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_00F4H, 0x00000050U);

                r_rsip_func_sub022(0x0000b400U, 0x0000001fU, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x0000001fU);

                static const uint32_t Param_pe1_func101_003[] =
                {
                    BSWAP_32BIG_C(0xd00eb85fU), BSWAP_32BIG_C(0x79df3fb6U), BSWAP_32BIG_C(0x11db440dU), BSWAP_32BIG_C(
                        0x28f2bbb7U),
                };
                r_rsip_func101(Param_pe1_func101_003);
            }
            else
            {
                WR1_PROG(REG_00F4H, 0x000000a0U);

                r_rsip_func_sub022(0x0000b400U, 0x0000002fU, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x0000002fU);

                static const uint32_t Param_pe1_func101_004[] =
                {
                    BSWAP_32BIG_C(0x5e0c3dcdU), BSWAP_32BIG_C(0x2038103fU), BSWAP_32BIG_C(0x7cb87311U), BSWAP_32BIG_C(
                        0x2ea022f7U),
                };
                r_rsip_func101(Param_pe1_func101_004);
            }

            r_rsip_func_sub022(0x3c0028a6U, 0x1000d0e0U, 0x00002425U);
            r_rsip_func_sub022(0x08002826U, 0x2000d0e0U, 0x3c002864U);
            r_rsip_func_sub022(0x1000d0e0U, 0x3c002885U, 0x1000d0e0U);

            r_rsip_func_sub022(0x00002403U, 0x08002804U, 0x2000d0e0U);

            WR1_PROG(REG_0094H, 0x3c0028c2U);
            r_rsip_func_sub010(0x1000d0e0U, 0x38000ce7U, 0x00A70000U);

            static const uint32_t Param_pe1_func100_005[] =
            {
                BSWAP_32BIG_C(0xbd0bf7e5U), BSWAP_32BIG_C(0x69429de8U), BSWAP_32BIG_C(0x8a66fdb1U), BSWAP_32BIG_C(
                    0x40c826bfU),
            };
            r_rsip_func100(Param_pe1_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe1_func102_003[] =
                {
                    BSWAP_32BIG_C(0xd1a7cde6U), BSWAP_32BIG_C(0x4b255cf4U), BSWAP_32BIG_C(0x3e8f2fc1U), BSWAP_32BIG_C(
                        0x2566d934U),
                };
                r_rsip_func102(Param_pe1_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe1_func100_006[] =
                {
                    BSWAP_32BIG_C(0xd567b677U), BSWAP_32BIG_C(0xec7a82a7U), BSWAP_32BIG_C(0x66424550U), BSWAP_32BIG_C(
                        0x2e5e0a4cU),
                };
                r_rsip_func100(Param_pe1_func100_006);
                r_rsip_func_sub022(0x00000800U, 0x00003422U, 0x01836c01U);
                WR1_PROG(REG_0094H, 0x00036c21U);

                r_rsip_func_sub017(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &S_RAM[0 + 1]);
                S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                static const uint32_t Param_pe1_func100_007[] =
                {
                    BSWAP_32BIG_C(0x269f07e5U), BSWAP_32BIG_C(0xe5a8dc64U), BSWAP_32BIG_C(0xad6298a7U), BSWAP_32BIG_C(
                        0x9e578302U),
                };
                r_rsip_func100(Param_pe1_func100_007);
                WR1_PROG(REG_0014H, 0x00000040U);
                WR1_PROG(REG_0104H, S_RAM[0]);
                WR1_PROG(REG_0014H, 0x00000040U);
                WR1_PROG(REG_0100H, S_RAM[0 + 1]);

                r_rsip_func_sub022(0x00003403U, 0x00046800U, 0x00026c00U);

                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x00000821U);

                WAIT_STS(REG_0118H, 0, 1);

                for (iLoop = 0U; iLoop < S_RAM[0]; )
                {
                    WR1_PROG(REG_0014H, 0x000003c4U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR4_ADDR(REG_002CH, &InData_Certificate[iLoop]);

                    WR1_PROG(REG_0094H, 0x0000a420U);
                    WR1_PROG(REG_0094H, 0x00000004U);

                    static const uint32_t Param_pe1_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xdccf2eb3U), BSWAP_32BIG_C(0x8db6c900U), BSWAP_32BIG_C(0x44fc33d1U),
                        BSWAP_32BIG_C(0x88707a74U),
                    };
                    r_rsip_func101(Param_pe1_func101_005);
                    iLoop = iLoop + 4U;
                }

                static const uint32_t Param_pe1_func100_008[] =
                {
                    BSWAP_32BIG_C(0x8ba39084U), BSWAP_32BIG_C(0x175e5f49U), BSWAP_32BIG_C(0x2f70a9f3U), BSWAP_32BIG_C(
                        0xfc0ea338U),
                };
                r_rsip_func100(Param_pe1_func100_008);

                r_rsip_func_sub016(0x38000801U, 0x00000080U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub022(0x00003402U, 0x0000a400U, 0x00000003U);
                WR1_PROG(REG_0094H, 0x00026800U);

                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub022(0x000034e1U, 0x00026ce7U, 0x00003040U);

                r_rsip_func_sub022(0x00000884U, 0x00003c04U, 0x0000b480U);
                WR1_PROG(REG_0094H, 0x00000014U);
                WR1_PROG(REG_0094H, 0x00003804U);

                r_rsip_func_sub010(0x38008800U, 0x00000003U, 0x00270000U);

                r_rsip_func_sub010(0x38008800U, 0x00000006U, 0x00270000U);

                static const uint32_t Param_pe1_func100_009[] =
                {
                    BSWAP_32BIG_C(0xc7f5aeaaU), BSWAP_32BIG_C(0x04b49ec5U), BSWAP_32BIG_C(0x97e786e0U), BSWAP_32BIG_C(
                        0x33d6998aU),
                };
                r_rsip_func100(Param_pe1_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_00B0H, 0x0000340eU);

                    iTemp = iLoop;
                    for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                    {
                        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
                        WR1_PROG(REG_002CH, InData_Certificate[iLoop]);
                        r_rsip_func_sub018(0x00000000U, 0x0000b480U, 0x00000004U);
                        WR1_PROG(REG_0094H, 0x00003c24U);

                        WR1_PROG(REG_0094H, 0x00000821U);

                        for (jLoop = 0U; jLoop < 4; jLoop++)
                        {
                            r_rsip_func_sub022(0x00002c20U, 0x01886c06U, 0x00086cc6U);

                            WR1_PROG(REG_0094H, 0x00003485U);
                            WR1_PROG(REG_0094H, 0x0000a480U);
                            r_rsip_func_sub010(0x0000001fU, 0x3c0028e5U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_010[] =
                            {
                                BSWAP_32BIG_C(0x2c6c42a8U), BSWAP_32BIG_C(0x973a5491U), BSWAP_32BIG_C(0xdbab73a7U),
                                BSWAP_32BIG_C(0x7282a763U),
                            };
                            r_rsip_func100(Param_pe1_func100_010);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub016(0x3c002887U, 0x00000080U, 0x00270000U);

                                static const uint32_t Param_pe1_func100_011[] =
                                {
                                    BSWAP_32BIG_C(0xf05ad2a6U), BSWAP_32BIG_C(0x4fa4a9a4U), BSWAP_32BIG_C(0x1208e45eU),
                                    BSWAP_32BIG_C(0x624ac98aU),
                                };
                                r_rsip_func100(Param_pe1_func100_011);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x10c90005U);

                                    static const uint32_t Param_pe1_func101_006[] =
                                    {
                                        BSWAP_32BIG_C(0x83e612a8U), BSWAP_32BIG_C(0x735c141fU), BSWAP_32BIG_C(
                                            0xddd2066fU),           BSWAP_32BIG_C(0x085023dbU),
                                    };
                                    r_rsip_func101(Param_pe1_func101_006);
                                }

                                static const uint32_t Param_pe1_func101_007[] =
                                {
                                    BSWAP_32BIG_C(0xcfb8357bU), BSWAP_32BIG_C(0x5b029d39U), BSWAP_32BIG_C(0x36eacbb3U),
                                    BSWAP_32BIG_C(0x566dcb8dU),
                                };
                                r_rsip_func101(Param_pe1_func101_007);
                            }

                            WR1_PROG(REG_0094H, 0x00003483U);
                            WR1_PROG(REG_0094H, 0x0000a480U);
                            r_rsip_func_sub010(0x0000001fU, 0x3c0028e3U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_012[] =
                            {
                                BSWAP_32BIG_C(0xd5b380adU), BSWAP_32BIG_C(0x7e910973U), BSWAP_32BIG_C(0x2dbfe3fdU),
                                BSWAP_32BIG_C(0xc9fddc1dU),
                            };
                            r_rsip_func100(Param_pe1_func100_012);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub016(0x3c002887U, 0x00000080U, 0x00270000U);

                                static const uint32_t Param_pe1_func100_013[] =
                                {
                                    BSWAP_32BIG_C(0x103746a6U), BSWAP_32BIG_C(0x0e7ea98dU), BSWAP_32BIG_C(0x6c7ac374U),
                                    BSWAP_32BIG_C(0x57739a33U),
                                };
                                r_rsip_func100(Param_pe1_func100_013);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x10c90005U);

                                    static const uint32_t Param_pe1_func101_008[] =
                                    {
                                        BSWAP_32BIG_C(0x1df858adU), BSWAP_32BIG_C(0x7787ad0cU), BSWAP_32BIG_C(
                                            0xddf3a0afU),           BSWAP_32BIG_C(0x5cb69bceU),
                                    };
                                    r_rsip_func101(Param_pe1_func101_008);
                                }

                                static const uint32_t Param_pe1_func101_009[] =
                                {
                                    BSWAP_32BIG_C(0x6bc1308bU), BSWAP_32BIG_C(0xf78eb84eU), BSWAP_32BIG_C(0x5f381b1fU),
                                    BSWAP_32BIG_C(0x24906095U),
                                };
                                r_rsip_func101(Param_pe1_func101_009);
                            }

                            r_rsip_func_sub016(0x3c002847U, 0x00000080U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_014[] =
                            {
                                BSWAP_32BIG_C(0x0dd43b75U), BSWAP_32BIG_C(0x29bcedeeU), BSWAP_32BIG_C(0x68641598U),
                                BSWAP_32BIG_C(0x7759b498U),
                            };
                            r_rsip_func100(Param_pe1_func100_014);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x11490005U);

                                static const uint32_t Param_pe1_func101_010[] =
                                {
                                    BSWAP_32BIG_C(0x1c8392b5U), BSWAP_32BIG_C(0x7ec909bdU), BSWAP_32BIG_C(0x96e4c82cU),
                                    BSWAP_32BIG_C(0xf8f126b8U),
                                };
                                r_rsip_func101(Param_pe1_func101_010);
                            }

                            WR1_PROG(REG_0094H, 0x00002ce0U);

                            static const uint32_t Param_pe1_func101_011[] =
                            {
                                BSWAP_32BIG_C(0x8a50b8abU), BSWAP_32BIG_C(0xf5218864U), BSWAP_32BIG_C(0x531a5c81U),
                                BSWAP_32BIG_C(0x6b1640b6U),
                            };
                            r_rsip_func101(Param_pe1_func101_011);
                        }

                        r_rsip_func_sub010(0x38008820U, 0x00000004U, 0x00270000U);
                        WR1_PROG(REG_0040H, 0x00402000U);

                        r_rsip_func_sub022(0x0000b480U, 0x00000004U, 0x00003824U);

                        WR1_PROG(REG_0094H, 0x00002c20U);

                        static const uint32_t Param_pe1_func101_012[] =
                        {
                            BSWAP_32BIG_C(0x8685e0fbU), BSWAP_32BIG_C(0xddcdf3afU), BSWAP_32BIG_C(0x138e9c11U),
                            BSWAP_32BIG_C(0xe2df3354U),
                        };
                        r_rsip_func101(Param_pe1_func101_012);
                    }

                    static const uint32_t Param_pe1_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x43dfa63dU), BSWAP_32BIG_C(0x5e23536dU), BSWAP_32BIG_C(0xc22b18d3U),
                        BSWAP_32BIG_C(0x94103c8bU),
                    };
                    r_rsip_func101(Param_pe1_func101_013);
                }
                else
                {
                    WR1_PROG(REG_00B0H, 0x0000b412U);

                    iTemp = iLoop;
                    for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                    {
                        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
                        WR1_PROG(REG_002CH, InData_Certificate[iLoop]);
                        r_rsip_func_sub018(0x00000000U, 0x0000b480U, 0x00000004U);
                        WR1_PROG(REG_0094H, 0x00003c24U);

                        WR1_PROG(REG_0094H, 0x00000821U);

                        for (jLoop = 0U; jLoop < 4; jLoop++)
                        {
                            r_rsip_func_sub022(0x00002c20U, 0x01886c06U, 0x00086cc6U);

                            WR1_PROG(REG_0094H, 0x00003485U);
                            WR1_PROG(REG_0094H, 0x0000a480U);
                            r_rsip_func_sub010(0x0000002fU, 0x3c0028e5U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_015[] =
                            {
                                BSWAP_32BIG_C(0x0d3d71a5U), BSWAP_32BIG_C(0xac4f972aU), BSWAP_32BIG_C(0xaa89f2e5U),
                                BSWAP_32BIG_C(0x8e7bfcf9U),
                            };
                            r_rsip_func100(Param_pe1_func100_015);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub016(0x3c002887U, 0x00000080U, 0x00270000U);

                                static const uint32_t Param_pe1_func100_016[] =
                                {
                                    BSWAP_32BIG_C(0x4c3292bcU), BSWAP_32BIG_C(0xa5c4b018U), BSWAP_32BIG_C(0x3460f8adU),
                                    BSWAP_32BIG_C(0xda19ce77U),
                                };
                                r_rsip_func100(Param_pe1_func100_016);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x10c90005U);

                                    static const uint32_t Param_pe1_func101_014[] =
                                    {
                                        BSWAP_32BIG_C(0xec57dbb8U), BSWAP_32BIG_C(0x6cecb80cU), BSWAP_32BIG_C(
                                            0x4de7f34aU),           BSWAP_32BIG_C(0xe50bd1caU),
                                    };
                                    r_rsip_func101(Param_pe1_func101_014);
                                }

                                static const uint32_t Param_pe1_func101_015[] =
                                {
                                    BSWAP_32BIG_C(0x7cc124d7U), BSWAP_32BIG_C(0xad6fe4b6U), BSWAP_32BIG_C(0xb68db92bU),
                                    BSWAP_32BIG_C(0x3c4c5a99U),
                                };
                                r_rsip_func101(Param_pe1_func101_015);
                            }

                            WR1_PROG(REG_0094H, 0x00003483U);
                            WR1_PROG(REG_0094H, 0x0000a480U);
                            r_rsip_func_sub010(0x0000002fU, 0x3c0028e3U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_017[] =
                            {
                                BSWAP_32BIG_C(0x92d99914U), BSWAP_32BIG_C(0xcfa00c23U), BSWAP_32BIG_C(0x75d1e01aU),
                                BSWAP_32BIG_C(0xa6e35cb8U),
                            };
                            r_rsip_func100(Param_pe1_func100_017);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub016(0x3c002887U, 0x00000080U, 0x00270000U);

                                static const uint32_t Param_pe1_func100_018[] =
                                {
                                    BSWAP_32BIG_C(0x893cd8ddU), BSWAP_32BIG_C(0x4bd0b087U), BSWAP_32BIG_C(0x3d04917eU),
                                    BSWAP_32BIG_C(0xaeee68e4U),
                                };
                                r_rsip_func100(Param_pe1_func100_018);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x10c90005U);

                                    static const uint32_t Param_pe1_func101_016[] =
                                    {
                                        BSWAP_32BIG_C(0xa50484eaU), BSWAP_32BIG_C(0xef5eeae8U), BSWAP_32BIG_C(
                                            0xfb12e840U),           BSWAP_32BIG_C(0xba2fd16bU),
                                    };
                                    r_rsip_func101(Param_pe1_func101_016);
                                }

                                static const uint32_t Param_pe1_func101_017[] =
                                {
                                    BSWAP_32BIG_C(0x57751df3U), BSWAP_32BIG_C(0xe32dc4a8U), BSWAP_32BIG_C(0xd58ed526U),
                                    BSWAP_32BIG_C(0xa0fca902U),
                                };
                                r_rsip_func101(Param_pe1_func101_017);
                            }

                            r_rsip_func_sub016(0x3c002847U, 0x00000080U, 0x00270000U);

                            static const uint32_t Param_pe1_func100_019[] =
                            {
                                BSWAP_32BIG_C(0xe5459920U), BSWAP_32BIG_C(0xe8e3c21aU), BSWAP_32BIG_C(0x21c07a9bU),
                                BSWAP_32BIG_C(0x99668b66U),
                            };
                            r_rsip_func100(Param_pe1_func100_019);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub005(0x81010000U, 0x1009000dU, 0x11490005U);

                                static const uint32_t Param_pe1_func101_018[] =
                                {
                                    BSWAP_32BIG_C(0xc6391ec9U), BSWAP_32BIG_C(0xe11f9b0dU), BSWAP_32BIG_C(0xb7baec9eU),
                                    BSWAP_32BIG_C(0xc6e69d88U),
                                };
                                r_rsip_func101(Param_pe1_func101_018);
                            }

                            WR1_PROG(REG_0094H, 0x00002ce0U);

                            static const uint32_t Param_pe1_func101_019[] =
                            {
                                BSWAP_32BIG_C(0x3249f6e0U), BSWAP_32BIG_C(0x90f32da5U), BSWAP_32BIG_C(0x0f60d329U),
                                BSWAP_32BIG_C(0xc65a44c4U),
                            };
                            r_rsip_func101(Param_pe1_func101_019);
                        }

                        r_rsip_func_sub010(0x38008820U, 0x00000004U, 0x00270000U);
                        WR1_PROG(REG_0040H, 0x00402000U);

                        r_rsip_func_sub022(0x0000b480U, 0x00000004U, 0x00003824U);

                        WR1_PROG(REG_0094H, 0x00002c20U);

                        static const uint32_t Param_pe1_func101_020[] =
                        {
                            BSWAP_32BIG_C(0x6147ebc8U), BSWAP_32BIG_C(0x1b41b7a7U), BSWAP_32BIG_C(0x6d524e48U),
                            BSWAP_32BIG_C(0x2de0fc9aU),
                        };
                        r_rsip_func101(Param_pe1_func101_020);
                    }

                    static const uint32_t Param_pe1_func101_021[] =
                    {
                        BSWAP_32BIG_C(0x9f0a5a34U), BSWAP_32BIG_C(0x8f9ce52cU), BSWAP_32BIG_C(0x363f1443U),
                        BSWAP_32BIG_C(0xc97a98ecU),
                    };
                    r_rsip_func101(Param_pe1_func101_021);
                }

                WR1_PROG(REG_0094H, 0x00000884U);
                r_rsip_func_sub010(0x00003804U, 0x38000801U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00002c40U);

                static const uint32_t Param_pe1_func100_020[] =
                {
                    BSWAP_32BIG_C(0x4341096cU), BSWAP_32BIG_C(0x4a9f6947U), BSWAP_32BIG_C(0xd8e368b3U), BSWAP_32BIG_C(
                        0x4200d728U),
                };
                r_rsip_func100(Param_pe1_func100_020);
                r_rsip_func_sub022(0x00003402U, 0x00008c00U, 0x00000003U);

                r_rsip_func_sub022(0x0000b440U, 0x00000004U, 0x00002840U);
                WR1_PROG(REG_0094H, 0x00008c40U);
                WR1_PROG(REG_0094H, 0x00000003U);

                r_rsip_func_sub017(0x81010040U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x000008a5U);

                WR1_PROG(REG_0094H, 0x00000863U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub005(0x81010060U, 0x11490005U, 0x1009000dU);

                    WR1_PROG(REG_0094H, 0x00086c63U);

                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_pe1_func101_022[] =
                    {
                        BSWAP_32BIG_C(0xbed25e06U), BSWAP_32BIG_C(0x47e60b16U), BSWAP_32BIG_C(0x912900a2U),
                        BSWAP_32BIG_C(0x71b3db40U),
                    };
                    r_rsip_func101(Param_pe1_func101_022);
                }

                r_rsip_func_sub016(0x38000845U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub022(0x000008a5U, 0x00000800U, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x00000014U);
                WR1_PROG(REG_0094H, 0x00003881U);

                r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

                r_rsip_func_sub010(0x38008880U, 0x00000006U, 0x00270000U);

                static const uint32_t Param_pe1_func100_021[] =
                {
                    BSWAP_32BIG_C(0xe84c22dfU), BSWAP_32BIG_C(0x73acf52dU), BSWAP_32BIG_C(0x73155f5fU), BSWAP_32BIG_C(
                        0xbecb750cU),
                };
                r_rsip_func100(Param_pe1_func100_021);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_00B0H, 0x00001804U);

                    static const uint32_t Param_pe1_func101_023[] =
                    {
                        BSWAP_32BIG_C(0x33147617U), BSWAP_32BIG_C(0x0eb3ae73U), BSWAP_32BIG_C(0x82ec591cU),
                        BSWAP_32BIG_C(0xcc46c6d2U),
                    };
                    r_rsip_func101(Param_pe1_func101_023);
                }
                else
                {
                    WR1_PROG(REG_00B0H, 0x00009806U);

                    static const uint32_t Param_pe1_func101_024[] =
                    {
                        BSWAP_32BIG_C(0x6c295c06U), BSWAP_32BIG_C(0x7839a15bU), BSWAP_32BIG_C(0x2dcc98e3U),
                        BSWAP_32BIG_C(0x6e3aa7a0U),
                    };
                    r_rsip_func101(Param_pe1_func101_024);
                }

                static const uint32_t Param_pe1_func100_022[] =
                {
                    BSWAP_32BIG_C(0xa2d2b2fbU), BSWAP_32BIG_C(0xa3b1e0b4U), BSWAP_32BIG_C(0xe2b988fcU), BSWAP_32BIG_C(
                        0xe13a23abU),
                };
                r_rsip_func100(Param_pe1_func100_022);
                WR1_PROG(REG_0094H, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x00000010U);
                r_rsip_func_sub017(0x81810001U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub012(0x80010020U, 0x03450005U);

                    r_rsip_func_sub006(0x80010040U, 0x03430005U, 0x08002822U, 0x2000d000U);

                    WR1_PROG(REG_0094H, 0x00002ca0U);

                    static const uint32_t Param_pe1_func101_025[] =
                    {
                        BSWAP_32BIG_C(0x02ce80a1U), BSWAP_32BIG_C(0x88b2f6d5U), BSWAP_32BIG_C(0x1033c381U),
                        BSWAP_32BIG_C(0x344ed354U),
                    };
                    r_rsip_func101(Param_pe1_func101_025);
                }

                WR1_PROG(REG_0094H, 0x0000b420U);
                WR1_PROG(REG_0094H, 0x00000010U);
                r_rsip_func_sub010(0x00003841U, 0x380008a2U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00A70000U);

                static const uint32_t Param_pe1_func100_023[] =
                {
                    BSWAP_32BIG_C(0xe137d784U), BSWAP_32BIG_C(0x0f13add4U), BSWAP_32BIG_C(0x5a399015U), BSWAP_32BIG_C(
                        0xc8c38c26U),
                };
                r_rsip_func100(Param_pe1_func100_023);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pe1_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xba5a056dU), BSWAP_32BIG_C(0x9914c60fU), BSWAP_32BIG_C(0x5f63ff9fU),
                        BSWAP_32BIG_C(0x1bb446b3U),
                    };
                    r_rsip_func102(Param_pe1_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pe1_func100_024[] =
                    {
                        BSWAP_32BIG_C(0x5d104e7fU), BSWAP_32BIG_C(0x80745c10U), BSWAP_32BIG_C(0xa5799c02U),
                        BSWAP_32BIG_C(0x5eab9e4cU),
                    };
                    r_rsip_func100(Param_pe1_func100_024);
                    r_rsip_func103();

                    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                    r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                    WR1_PROG(REG_0094H, 0x000034c0U);

                    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e103U, 0x00000000U);

                    static const uint32_t Param_pe1_func101_026[] =
                    {
                        BSWAP_32BIG_C(0x037e9f04U), BSWAP_32BIG_C(0x306392abU), BSWAP_32BIG_C(0x147a32e3U),
                        BSWAP_32BIG_C(0x0ee805c6U),
                    };
                    r_rsip_func101(Param_pe1_func101_026);
                    r_rsip_func143();

                    r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

                    r_rsip_func_sub010(0x38008880U, 0x00000006U, 0x00270000U);

                    static const uint32_t Param_pe1_func100_025[] =
                    {
                        BSWAP_32BIG_C(0x105ed78aU), BSWAP_32BIG_C(0x76a0de2eU), BSWAP_32BIG_C(0x7bbad9d5U),
                        BSWAP_32BIG_C(0xa142829bU),
                    };
                    r_rsip_func100(Param_pe1_func100_025);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_00B0H, 0x0000380eU);

                        r_rsip_func_sub022(0x0000b460U, 0x00000010U, 0x38008880U);
                        r_rsip_func_sub022(0x00000003U, 0x00030020U, 0x0000b4c0U);
                        r_rsip_func_sub022(0x00000016U, 0x00000060U, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x0000001cU);
                        WR1_PROG(REG_0094H, 0x00000080U);

                        static const uint32_t Param_pe1_func101_027[] =
                        {
                            BSWAP_32BIG_C(0x80354cfbU), BSWAP_32BIG_C(0xbe2e187bU), BSWAP_32BIG_C(0x287fb77fU),
                            BSWAP_32BIG_C(0x0d126fbdU),
                        };
                        r_rsip_func101(Param_pe1_func101_027);
                    }
                    else
                    {
                        WR1_PROG(REG_00B0H, 0x0000b812U);

                        r_rsip_func_sub022(0x0000b460U, 0x00000018U, 0x38008880U);
                        r_rsip_func_sub022(0x00000004U, 0x00030020U, 0x0000b4c0U);
                        r_rsip_func_sub022(0x00000018U, 0x00000060U, 0x0000b4c0U);
                        WR1_PROG(REG_0094H, 0x0000001eU);
                        WR1_PROG(REG_0094H, 0x00000080U);

                        static const uint32_t Param_pe1_func101_028[] =
                        {
                            BSWAP_32BIG_C(0x2609e222U), BSWAP_32BIG_C(0x15f67d92U), BSWAP_32BIG_C(0xb9a83bc5U),
                            BSWAP_32BIG_C(0xf9a01db2U),
                        };
                        r_rsip_func101(Param_pe1_func101_028);
                    }

                    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e103U, 0x00000000U);

                    static const uint32_t Param_pe1_func101_029[] =
                    {
                        BSWAP_32BIG_C(0xa3ae72aaU), BSWAP_32BIG_C(0x8578a28dU), BSWAP_32BIG_C(0x67b4e16aU),
                        BSWAP_32BIG_C(0x694934fcU),
                    };
                    r_rsip_func101(Param_pe1_func101_029);
                    r_rsip_func044();

                    static const uint32_t Param_pe1_func100_026[] =
                    {
                        BSWAP_32BIG_C(0x9dd89496U), BSWAP_32BIG_C(0x80d692f6U), BSWAP_32BIG_C(0xfce21c2fU),
                        BSWAP_32BIG_C(0xc62e4201U),
                    };
                    r_rsip_func100(Param_pe1_func100_026);
                    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

                    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

                    r_rsip_func_sub017(0x81010060U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &S_RAM[0]);
                    S_RAM[0] = bswap_32big(S_RAM[0]);

                    WR1_PROG(REG_0094H, 0x00000884U);
                    WR1_PROG(REG_0094H, 0x000008a5U);

                    for (iLoop = 0U; iLoop < S_RAM[0]; )
                    {
                        r_rsip_func_sub022(0x342028a3U, 0x2000d080U, 0x00007c04U);
                        WR1_PROG(REG_0040H, 0x00602000U);

                        static const uint32_t Param_pe1_func100_027[] =
                        {
                            BSWAP_32BIG_C(0xf849b20eU), BSWAP_32BIG_C(0xe5226a07U), BSWAP_32BIG_C(0x40e3f8e2U),
                            BSWAP_32BIG_C(0x7636c737U),
                        };
                        r_rsip_func100(Param_pe1_func100_027);
                        r_rsip_func_sub004(0x40000000U, 0xe8008105U, 0x00430011U, 0x00001012U);
                        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

                        WR1_PROG(REG_0094H, 0x0000a4a0U);
                        WR1_PROG(REG_0094H, 0x00000004U);

                        static const uint32_t Param_pe1_func101_030[] =
                        {
                            BSWAP_32BIG_C(0xdb055863U), BSWAP_32BIG_C(0xcf0c436aU), BSWAP_32BIG_C(0x04747d2aU),
                            BSWAP_32BIG_C(0xf8bbbf4dU),
                        };
                        r_rsip_func101(Param_pe1_func101_030);
                        iLoop = iLoop + 4U;
                    }

                    r_rsip_func_sub016(0x380008a3U, 0x00000080U, 0x00270000U);
                    WR1_PROG(REG_0040H, 0x00402000U);

                    static const uint32_t Param_pe1_func100_028[] =
                    {
                        BSWAP_32BIG_C(0x8e4a1cb5U), BSWAP_32BIG_C(0x11f36713U), BSWAP_32BIG_C(0xa816c288U),
                        BSWAP_32BIG_C(0xa08aeb9bU),
                    };
                    r_rsip_func100(Param_pe1_func100_028);
                    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

                    static const uint32_t Param_pe1_func100_029[] =
                    {
                        BSWAP_32BIG_C(0xb2b6afc1U), BSWAP_32BIG_C(0x5995c3d3U), BSWAP_32BIG_C(0x7a22cf88U),
                        BSWAP_32BIG_C(0x638845aeU),
                    };
                    r_rsip_func100(Param_pe1_func100_029);
                    r_rsip_func_sub017(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe1_func102_005[] =
                    {
                        BSWAP_32BIG_C(0xc1bce075U), BSWAP_32BIG_C(0xfdc13536U), BSWAP_32BIG_C(0x1e7b3a07U),
                        BSWAP_32BIG_C(0x1b07ec4cU),
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
