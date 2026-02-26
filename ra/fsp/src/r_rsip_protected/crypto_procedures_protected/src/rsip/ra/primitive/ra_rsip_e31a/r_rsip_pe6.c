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

rsip_ret_t r_rsip_pe6 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataLength[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00e60001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3000a880U, 0x00000002U);
    r_rsip_func_sub022(0x00010020U, 0x0000b480U, 0x00000001U);
    r_rsip_func_sub022(0x00000080U, 0x30003080U, 0x00070020U);
    r_rsip_func_sub022(0x0000b4c0U, 0x00000002U, 0x0000b4e0U);
    r_rsip_func_sub022(0x00000020U, 0x0000b460U, 0x0000000dU);

    r_rsip_func_sub022(0x00030040U, 0x0000b4c0U, 0x00000002U);

    r_rsip_func_sub022(0x0000b4e0U, 0x00000030U, 0x0000b460U);
    WR1_PROG(REG_0094H, 0x00000011U);

    WR1_PROG(REG_0094H, 0x00000080U);

    r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
    WR1_PROG(REG_002CH, InData_KDFInfo_Count[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

    r_rsip_func_sub016(0x342028c5U, 0x00000080U, 0x00270000U);

    static const uint32_t Param_pe6_func100_001[] =
    {
        BSWAP_32BIG_C(0xe5ec0dcaU), BSWAP_32BIG_C(0x2780ff22U), BSWAP_32BIG_C(0xd00635dfU), BSWAP_32BIG_C(0x362ef099U),
    };
    r_rsip_func100(Param_pe6_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe6_func102_001[] =
        {
            BSWAP_32BIG_C(0x6bb5f127U), BSWAP_32BIG_C(0xa296ae1aU), BSWAP_32BIG_C(0x15a6bac7U), BSWAP_32BIG_C(
                0x3a707823U),
        };
        r_rsip_func102(Param_pe6_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_002CH, InData_OutDataLength[0]);
        r_rsip_func_sub018(0x00000000U, 0x300030a0U, 0x00030020U);
        r_rsip_func_sub022(0x00003407U, 0x00000060U, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000040U);

        r_rsip_func_sub010(0x00000080U, 0x342028c7U, 0x00270000U);

        r_rsip_func_sub016(0x34202806U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_pe6_func100_002[] =
        {
            BSWAP_32BIG_C(0xc012fbedU), BSWAP_32BIG_C(0x9b018959U), BSWAP_32BIG_C(0x81d2566aU), BSWAP_32BIG_C(
                0xef1d34c5U),
        };
        r_rsip_func100(Param_pe6_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe6_func102_002[] =
            {
                BSWAP_32BIG_C(0xb32945d7U), BSWAP_32BIG_C(0xfd166179U), BSWAP_32BIG_C(0x14b7ec57U), BSWAP_32BIG_C(
                    0x626b774cU),
            };
            r_rsip_func102(Param_pe6_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe6_func100_003[] =
            {
                BSWAP_32BIG_C(0xd4363110U), BSWAP_32BIG_C(0x4e77a98fU), BSWAP_32BIG_C(0xf430223cU), BSWAP_32BIG_C(
                    0x94876894U),
            };
            r_rsip_func100(Param_pe6_func100_003);
            r_rsip_func_sub017(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            static const uint32_t Param_pe6_func100_004[] =
            {
                BSWAP_32BIG_C(0xdacf15eeU), BSWAP_32BIG_C(0x6ff4f7ccU), BSWAP_32BIG_C(0x9788dbacU), BSWAP_32BIG_C(
                    0x1927b51fU),
            };
            r_rsip_func100(Param_pe6_func100_004);
            r_rsip_func_sub017(0x81010060U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
            OFS_ADR      = S_RAM[0 + 1];

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003cc1U);

            WR1_PROG(REG_0094H, 0x00000800U);

            WR1_PROG(REG_0094H, 0x00000821U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
                WR1_PROG(REG_002CH, InData_KDFInfo[iLoop * OFS_ADR]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e601U, 0x00000000U);

                static const uint32_t Param_pe6_func101_001[] =
                {
                    BSWAP_32BIG_C(0x6b7cfc01U), BSWAP_32BIG_C(0x3750d0b5U), BSWAP_32BIG_C(0x6282f63fU), BSWAP_32BIG_C(
                        0x318b8e33U),
                };
                r_rsip_func101(Param_pe6_func101_001);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x01799093U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e601U, 0x00000000U);

                static const uint32_t Param_pe6_func101_002[] =
                {
                    BSWAP_32BIG_C(0x7b253539U), BSWAP_32BIG_C(0x8dc7f369U), BSWAP_32BIG_C(0xa8766b9dU), BSWAP_32BIG_C(
                        0x095069aeU),
                };
                r_rsip_func101(Param_pe6_func101_002);
                r_rsip_func044();

                r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00270000U);

                static const uint32_t Param_pe6_func100_005[] =
                {
                    BSWAP_32BIG_C(0xe91b3608U), BSWAP_32BIG_C(0xb4ceba4aU), BSWAP_32BIG_C(0x6dcab603U), BSWAP_32BIG_C(
                        0x32206278U),
                };
                r_rsip_func100(Param_pe6_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

                    static const uint32_t Param_pe6_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x920b9ae2U), BSWAP_32BIG_C(0x000c4c1aU), BSWAP_32BIG_C(0x5b8a7dbeU),
                        BSWAP_32BIG_C(0xda5cf7fbU),
                    };
                    r_rsip_func100(Param_pe6_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_00B0H, 0x00001404U);

                        static const uint32_t Param_pe6_func101_003[] =
                        {
                            BSWAP_32BIG_C(0x65f94618U), BSWAP_32BIG_C(0xbdf3f95cU), BSWAP_32BIG_C(0x5ffb0201U),
                            BSWAP_32BIG_C(0x1a9975a0U),
                        };
                        r_rsip_func101(Param_pe6_func101_003);
                    }
                    else
                    {
                        WR1_PROG(REG_00B0H, 0x00009406U);

                        static const uint32_t Param_pe6_func101_004[] =
                        {
                            BSWAP_32BIG_C(0x7000c6f0U), BSWAP_32BIG_C(0x2e2c4109U), BSWAP_32BIG_C(0x03705da5U),
                            BSWAP_32BIG_C(0x1acd3808U),
                        };
                        r_rsip_func101(Param_pe6_func101_004);
                    }

                    static const uint32_t Param_pe6_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x0cf54ac8U), BSWAP_32BIG_C(0x1fc434daU), BSWAP_32BIG_C(0x29c0226eU),
                        BSWAP_32BIG_C(0xbeb06bf6U),
                    };
                    r_rsip_func101(Param_pe6_func101_005);
                }
                else
                {
                    r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

                    static const uint32_t Param_pe6_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x6960ac90U), BSWAP_32BIG_C(0xc044445dU), BSWAP_32BIG_C(0xde1f8d8cU),
                        BSWAP_32BIG_C(0xbd6d2a43U),
                    };
                    r_rsip_func100(Param_pe6_func100_007);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        WR1_PROG(REG_00B0H, 0x00001408U);

                        static const uint32_t Param_pe6_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xc9f3a486U), BSWAP_32BIG_C(0x1dccf58bU), BSWAP_32BIG_C(0xcfc00ebbU),
                            BSWAP_32BIG_C(0x10b17844U),
                        };
                        r_rsip_func101(Param_pe6_func101_006);
                    }
                    else
                    {
                        WR1_PROG(REG_00B0H, 0x0000940cU);

                        static const uint32_t Param_pe6_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xf9ceb581U), BSWAP_32BIG_C(0xda5c064aU), BSWAP_32BIG_C(0x47d5a108U),
                            BSWAP_32BIG_C(0xc9428710U),
                        };
                        r_rsip_func101(Param_pe6_func101_007);
                    }

                    static const uint32_t Param_pe6_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x0e5b3fa4U), BSWAP_32BIG_C(0xac73c438U), BSWAP_32BIG_C(0xcb1d143eU),
                        BSWAP_32BIG_C(0xd449e5e1U),
                    };
                    r_rsip_func101(Param_pe6_func101_008);
                }

                r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

                r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

                WR1_PROG(REG_0094H, 0x00000842U);

                for (jLoop = 0U; jLoop < OFS_ADR - 5; )
                {
                    r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0xf7008d05U);
                    WR4_ADDR(REG_002CH, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

                    WR1_PROG(REG_0094H, 0x0000a440U);
                    WR1_PROG(REG_0094H, 0x00000004U);

                    static const uint32_t Param_pe6_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x04f02334U), BSWAP_32BIG_C(0xf3eeb659U), BSWAP_32BIG_C(0x7f6a5a94U),
                        BSWAP_32BIG_C(0x0ddd5d22U),
                    };
                    r_rsip_func101(Param_pe6_func101_009);
                    jLoop = jLoop + 4U;
                }

                WR1_PROG(REG_0094H, 0x000034e3U);
                WR1_PROG(REG_0094H, 0x0000a8e0U);
                r_rsip_func_sub010(0x00000005U, 0x380008e2U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_002CH, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                r_rsip_func_sub013(0x9c100005U, 0x00410011U);

                WR1_PROG(REG_0094H, 0x00002c00U);

                static const uint32_t Param_pe6_func100_008[] =
                {
                    BSWAP_32BIG_C(0xbd74762fU), BSWAP_32BIG_C(0x3bbc01dcU), BSWAP_32BIG_C(0xa312c77eU), BSWAP_32BIG_C(
                        0x54200f04U),
                };
                r_rsip_func100(Param_pe6_func100_008);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x0000d020U);
                    static const uint32_t Param_pe6_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x421a232bU), BSWAP_32BIG_C(0x2fd6f40aU), BSWAP_32BIG_C(0x6c3e30ecU),
                        BSWAP_32BIG_C(0x37476abdU),
                    };
                    r_rsip_func101(Param_pe6_func101_010);
                }
                else
                {
                    static const uint32_t Param_pe6_func101_011[] =
                    {
                        BSWAP_32BIG_C(0xf0b33e76U), BSWAP_32BIG_C(0x40555238U), BSWAP_32BIG_C(0x35a32b5bU),
                        BSWAP_32BIG_C(0xfa6f4184U),
                    };
                    r_rsip_func101(Param_pe6_func101_011);
                }
            }

            r_rsip_func_sub016(0x38000805U, 0x00000080U, 0x00270000U);
            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00A70000U);
            static const uint32_t Param_pe6_func100_009[] =
            {
                BSWAP_32BIG_C(0xa3e563c0U), BSWAP_32BIG_C(0xea6f48d4U), BSWAP_32BIG_C(0xc519a9eaU), BSWAP_32BIG_C(
                    0xd791c018U),
            };
            r_rsip_func100(Param_pe6_func100_009);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe6_func102_003[] =
                {
                    BSWAP_32BIG_C(0x10318d2fU), BSWAP_32BIG_C(0xdd92a44bU), BSWAP_32BIG_C(0x6d0fd1e5U), BSWAP_32BIG_C(
                        0xc2726e9aU),
                };
                r_rsip_func102(Param_pe6_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x000038a1U);

                static const uint32_t Param_pe6_func100_010[] =
                {
                    BSWAP_32BIG_C(0x92ffc950U), BSWAP_32BIG_C(0x37be238dU), BSWAP_32BIG_C(0x18542c72U), BSWAP_32BIG_C(
                        0x9bc75d04U),
                };
                r_rsip_func100(Param_pe6_func100_010);
                r_rsip_func_sub017(0x810100a0U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                static const uint32_t Param_pe6_func100_011[] =
                {
                    BSWAP_32BIG_C(0xbb8c5a6eU), BSWAP_32BIG_C(0x1167fa79U), BSWAP_32BIG_C(0xccbf1a5eU), BSWAP_32BIG_C(
                        0x909b8ad7U),
                };
                r_rsip_func100(Param_pe6_func100_011);
                r_rsip_func103();

                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e602U, 0x00000000U);

                static const uint32_t Param_pe6_func101_012[] =
                {
                    BSWAP_32BIG_C(0xc329dd9eU), BSWAP_32BIG_C(0xc13788a8U), BSWAP_32BIG_C(0x37443eecU), BSWAP_32BIG_C(
                        0xf7bf8cdcU),
                };
                r_rsip_func101(Param_pe6_func101_012);
                r_rsip_func143();

                r_rsip_func_sub022(0x30003080U, 0x00070020U, 0x0000b4c0U);
                r_rsip_func_sub022(0x01b41ce9U, 0x00000060U, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x0199f119U);
                WR1_PROG(REG_0094H, 0x00000080U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e602U, 0x00000000U);

                static const uint32_t Param_pe6_func101_013[] =
                {
                    BSWAP_32BIG_C(0xe64842b8U), BSWAP_32BIG_C(0x7e530998U), BSWAP_32BIG_C(0x10c8f23cU), BSWAP_32BIG_C(
                        0xffded45aU),
                };
                r_rsip_func101(Param_pe6_func101_013);
                r_rsip_func044();

                static const uint32_t Param_pe6_func100_012[] =
                {
                    BSWAP_32BIG_C(0x5639f7d4U), BSWAP_32BIG_C(0x810bbe8fU), BSWAP_32BIG_C(0x4583cf06U), BSWAP_32BIG_C(
                        0x47d5f355U),
                };
                r_rsip_func100(Param_pe6_func100_012);
                WR1_PROG(REG_00B0H, 0x00001804U);
                r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00430021U, 0x00001022U);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                WR1_PROG(REG_0094H, 0x000008e7U);

                r_rsip_func_sub010(0x3420a8a0U, 0x00000021U, 0x00A70000U);

                static const uint32_t Param_pe6_func100_013[] =
                {
                    BSWAP_32BIG_C(0xf8a2a8a8U), BSWAP_32BIG_C(0xc6448393U), BSWAP_32BIG_C(0xa924f5abU), BSWAP_32BIG_C(
                        0xfd8c5095U),
                };
                r_rsip_func100(Param_pe6_func100_013);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_00B0H, 0x00001808U);
                    r_rsip_func_sub012(0x80880007U, 0x03430021U);

                    static const uint32_t Param_pe6_func101_014[] =
                    {
                        BSWAP_32BIG_C(0x2f66ecc2U), BSWAP_32BIG_C(0x639efe51U), BSWAP_32BIG_C(0x77ea4eaeU),
                        BSWAP_32BIG_C(0x44aef080U),
                    };
                    r_rsip_func101(Param_pe6_func101_014);
                }

                r_rsip_func_sub022(0x00000842U, 0x0000b460U, 0x00000040U);
                r_rsip_func_sub022(0x00002865U, 0x00000884U, 0x00003425U);
                WR1_PROG(REG_0094H, 0x0000a820U);
                WR1_PROG(REG_0094H, 0x00000020U);

                for (iLoop = S_RAM[0]; iLoop < 64U; iLoop++)
                {
                    r_rsip_func_sub022(0x02003c41U, 0x00002c80U, 0x00002c20U);
                    static const uint32_t Param_pe6_func101_015[] =
                    {
                        BSWAP_32BIG_C(0x04f984eeU), BSWAP_32BIG_C(0x831a97beU), BSWAP_32BIG_C(0x5fe82ca6U),
                        BSWAP_32BIG_C(0x4b468e65U),
                    };
                    r_rsip_func101(Param_pe6_func101_015);
                }

                r_rsip_func_sub016(0x38000883U, 0x00000080U, 0x00270000U);
                WR1_PROG(REG_0040H, 0x00402000U);

                static const uint32_t Param_pe6_func100_014[] =
                {
                    BSWAP_32BIG_C(0x9bcfecd4U), BSWAP_32BIG_C(0xd7823c5eU), BSWAP_32BIG_C(0x47c32057U), BSWAP_32BIG_C(
                        0x595756d0U),
                };
                r_rsip_func100(Param_pe6_func100_014);
                WR1_PROG(REG_0094H, 0x000008e7U);
                WR1_PROG(REG_00D4H, 0x40000100U);
                WR1_PROG(REG_00D0H, 0xe7008d07U);

                r_rsip_func_sub012(0x81880007U, 0x00490021U);
                WR1_PROG(REG_0008H, 0x00001022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[9]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[13]);

                static const uint32_t Param_pe6_func100_015[] =
                {
                    BSWAP_32BIG_C(0x2d80dfe5U), BSWAP_32BIG_C(0x4bc52bd5U), BSWAP_32BIG_C(0x35f98944U), BSWAP_32BIG_C(
                        0x475644a0U),
                };
                r_rsip_func100(Param_pe6_func100_015);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[17]);

                static const uint32_t Param_pe6_func100_016[] =
                {
                    BSWAP_32BIG_C(0x58635cf9U), BSWAP_32BIG_C(0xdee4c7e3U), BSWAP_32BIG_C(0x85d79befU), BSWAP_32BIG_C(
                        0x51ac3f10U),
                };
                r_rsip_func100(Param_pe6_func100_016);
                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe6_func102_004[] =
                {
                    BSWAP_32BIG_C(0xfbbf594bU), BSWAP_32BIG_C(0xf6796c01U), BSWAP_32BIG_C(0x543777e0U), BSWAP_32BIG_C(
                        0x39355c57U),
                };
                r_rsip_func102(Param_pe6_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
