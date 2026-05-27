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

rsip_ret_t r_rsip_p8f (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_WrappedKeyIndex[],
                       uint32_t       OutData_Text[],
                       uint32_t       KEY_INDEX_SIZE,
                       uint32_t       WRAPPED_KEY_SIZE)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x008f0001U, 0x000001c7U, 0x800200c0U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_WrappedKeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00003407U);

    r_rsip_func_sub007(0x3420a8c0U, 0x00000002U, 0x00A60000U);

    r_rsip_func_sub007(0x3420a800U, 0x00000003U, 0x00A60000U);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p8f_func100_001[] =
    {
        BSWAP_32BIG_C(0xdda14420U), BSWAP_32BIG_C(0x2227fc6aU), BSWAP_32BIG_C(0x9a655522U), BSWAP_32BIG_C(0x47736c8bU),
    };
    r_rsip_func100(Param_p8f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p8f_func102_001[] =
        {
            BSWAP_32BIG_C(0x4ddbe11fU), BSWAP_32BIG_C(0xc16afa06U), BSWAP_32BIG_C(0xa4cd14d7U), BSWAP_32BIG_C(
                0xdb528deaU),
        };
        r_rsip_func102(Param_p8f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x00003486U, 0x38000c84U, 0x00260000U);

        static const uint32_t Param_p8f_func100_002[] =
        {
            BSWAP_32BIG_C(0x73ff1dd4U), BSWAP_32BIG_C(0xc2a520ceU), BSWAP_32BIG_C(0x50a597b8U), BSWAP_32BIG_C(
                0x1741d749U),
        };
        r_rsip_func100(Param_p8f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            r_rsip_func_sub002(0x800100e0U, 0x0000008fU);

            static const uint32_t Param_p8f_func101_001[] =
            {
                BSWAP_32BIG_C(0x38de9a4fU), BSWAP_32BIG_C(0xff95e4d3U), BSWAP_32BIG_C(0x5db3baf7U), BSWAP_32BIG_C(
                    0xfcd78599U),
            };
            r_rsip_func101(Param_p8f_func101_001);
            r_rsip_func440(InData_KeyIndex);

            static const uint32_t Param_p8f_func101_002[] =
            {
                BSWAP_32BIG_C(0x45645f83U), BSWAP_32BIG_C(0xb49dd400U), BSWAP_32BIG_C(0x88bc04dbU), BSWAP_32BIG_C(
                    0x763a4c55U),
            };
            r_rsip_func101(Param_p8f_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000007U);

            r_rsip_func_sub002(0x800100e0U, 0x0000008fU);

            static const uint32_t Param_p8f_func101_003[] =
            {
                BSWAP_32BIG_C(0xaa39fe94U), BSWAP_32BIG_C(0x7ad24a36U), BSWAP_32BIG_C(0x8db266e8U), BSWAP_32BIG_C(
                    0x96f9d061U),
            };
            r_rsip_func101(Param_p8f_func101_003);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_p8f_func101_004[] =
            {
                BSWAP_32BIG_C(0xe40cd53cU), BSWAP_32BIG_C(0x4ccb795eU), BSWAP_32BIG_C(0x20072b87U), BSWAP_32BIG_C(
                    0x55859127U),
            };
            r_rsip_func101(Param_p8f_func101_004);
        }

        static const uint32_t Param_p8f_func100_003[] =
        {
            BSWAP_32BIG_C(0x9d8b5be9U), BSWAP_32BIG_C(0xd5ba5113U), BSWAP_32BIG_C(0x0e3bcb0eU), BSWAP_32BIG_C(
                0xb9775840U),
        };
        r_rsip_func100(Param_p8f_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p8f_func102_002[] =
            {
                BSWAP_32BIG_C(0xefe79a61U), BSWAP_32BIG_C(0x1950383fU), BSWAP_32BIG_C(0x2c61c051U), BSWAP_32BIG_C(
                    0xf498b710U),
            };
            r_rsip_func102(Param_p8f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            r_rsip_func_sub016(0x00003427U, 0x0000b460U, 0x00000010U);

            WR1_PROG(REG_0094H, 0x00003ca3U);

            r_rsip_func_sub013(0x00003466U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_WrappedKeyIndex[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x800100e0U, 0x0000008fU);

            static const uint32_t Param_p8f_func101_005[] =
            {
                BSWAP_32BIG_C(0xd53fd197U), BSWAP_32BIG_C(0x4414ec9dU), BSWAP_32BIG_C(0x5c3d1bf2U), BSWAP_32BIG_C(
                    0xc3f36a51U),
            };
            r_rsip_func101(Param_p8f_func101_005);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x000034c3U);

            r_rsip_func_sub002(0x800100e0U, 0x0000008fU);

            static const uint32_t Param_p8f_func101_006[] =
            {
                BSWAP_32BIG_C(0x427925f6U), BSWAP_32BIG_C(0x6065089aU), BSWAP_32BIG_C(0x46c3004bU), BSWAP_32BIG_C(
                    0x938f2995U),
            };
            r_rsip_func101(Param_p8f_func101_006);
            r_rsip_func044();

            r_rsip_func_sub016(0x000034e1U, 0x0000b460U, 0x00000010U);

            WR1_PROG(REG_0094H, 0x000038a3U);

            r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub016(0x00000863U, 0x0000b420U, 0x00000010U);

            r_rsip_func_sub016(0x00000842U, 0x0000b400U, 0x00000004U);

            WR1_PROG(REG_0094H, 0x0000a8e0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
            {
                r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_002CH, &InData_WrappedKeyIndex[iLoop + 1]);

                r_rsip_func_sub003(0x80840003U, 0x03410011U);

                WR1_PROG(REG_0094H, 0x00002461U);

                WR1_PROG(REG_0094H, 0x00002440U);

                static const uint32_t Param_p8f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x7f96478eU), BSWAP_32BIG_C(0x17049be0U), BSWAP_32BIG_C(0x6b60818bU), BSWAP_32BIG_C(
                        0xa2ef23afU),
                };
                r_rsip_func101(Param_p8f_func101_007);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub010(0x38000847U);

            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_WrappedKeyIndex[iLoop + 1]);

            r_rsip_func_sub006(0x9c100005U, 0x00410011U);

            static const uint32_t Param_p8f_func100_004[] =
            {
                BSWAP_32BIG_C(0x0cf981edU), BSWAP_32BIG_C(0x2ac8fcd8U), BSWAP_32BIG_C(0x1316039dU), BSWAP_32BIG_C(
                    0x00381aecU),
            };
            r_rsip_func100(Param_p8f_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p8f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x55406589U), BSWAP_32BIG_C(0xa2738c23U), BSWAP_32BIG_C(0xed6abc13U), BSWAP_32BIG_C(
                        0xb9d74656U),
                };
                r_rsip_func102(Param_p8f_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                WR1_PROG(REG_0094H, 0x38000c84U);
                WR1_PROG(REG_009CH, 0x00000080U);
                WR1_PROG(REG_0040H, 0x00260000U);

                static const uint32_t Param_p8f_func100_005[] =
                {
                    BSWAP_32BIG_C(0x579010c3U), BSWAP_32BIG_C(0x3f5c83afU), BSWAP_32BIG_C(0x9a4dec4fU), BSWAP_32BIG_C(
                        0x277d23daU),
                };
                r_rsip_func100(Param_p8f_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p8f_func100_006[] =
                    {
                        BSWAP_32BIG_C(0xae436800U), BSWAP_32BIG_C(0x6da0c32cU), BSWAP_32BIG_C(0x468d21abU),
                        BSWAP_32BIG_C(0x0036fc26U),
                    };
                    r_rsip_func100(Param_p8f_func100_006);

                    WR1_PROG(REG_00D0H, 0x08000085U);
                    r_rsip_func_sub004(0x00000801U, 0x00430009U);

                    r_rsip_func_sub004(0x00000802U, 0x00430009U);

                    WR1_PROG(REG_00D4H, 0x00000000U);

                    static const uint32_t Param_p8f_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x0c0d7cf4U), BSWAP_32BIG_C(0xedc64722U), BSWAP_32BIG_C(0x789686f9U),
                        BSWAP_32BIG_C(0x9ca97a7bU),
                    };
                    r_rsip_func101(Param_p8f_func101_008);
                }
                else
                {
                    static const uint32_t Param_p8f_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x993bb6c4U), BSWAP_32BIG_C(0x0a30311cU), BSWAP_32BIG_C(0xe1d63451U),
                        BSWAP_32BIG_C(0xfef07df8U),
                    };
                    r_rsip_func100(Param_p8f_func100_007);

                    WR1_PROG(REG_00D0H, 0x08000085U);
                    r_rsip_func_sub004(0x0000181eU, 0x00430011U);

                    static const uint32_t Param_p8f_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x08ddd33fU), BSWAP_32BIG_C(0x165c7354U), BSWAP_32BIG_C(0x40640d59U),
                        BSWAP_32BIG_C(0xcec16594U),
                    };
                    r_rsip_func100(Param_p8f_func100_008);
                    r_rsip_func_sub006(0x08000095U, 0x00430011U);

                    WR1_PROG(REG_00D4H, 0x40000000U);

                    static const uint32_t Param_p8f_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x6e1abfb9U), BSWAP_32BIG_C(0x348ecd1bU), BSWAP_32BIG_C(0xd12676f2U),
                        BSWAP_32BIG_C(0x29fb259cU),
                    };
                    r_rsip_func101(Param_p8f_func101_009);
                }

                r_rsip_func_sub016(0x0000b400U, 0xa6a6a6a6U, 0x00003420U);

                r_rsip_func_sub016(0x0000b480U, 0x00000001U, 0x000008c6U);

                WR1_PROG(REG_0094H, 0x00036ca5U);

                for (jLoop = 0U; jLoop <= 5; jLoop++)
                {
                    WR1_PROG(REG_0094H, 0x000008e7U);

                    for (iLoop = 1; iLoop <= (WRAPPED_KEY_SIZE - 2) / 2; iLoop++)
                    {
                        WR1_PROG(REG_00D0H, 0x0a008105U);
                        r_rsip_func_sub003(0x81020000U, 0x00490009U);
                        r_rsip_func_sub003(0x81820007U, 0x00490009U);

                        r_rsip_func_sub003(0x80040000U, 0x03410011U);

                        r_rsip_func_sub016(0x00000824U, 0x00003c47U, 0x0000a4e0U);
                        r_rsip_func_sub016(0x00000004U, 0x00003c67U, 0x0000a4e0U);
                        WR1_PROG(REG_0094H, 0x00000004U);

                        WR1_PROG(REG_0094H, 0x00002c80U);

                        static const uint32_t Param_p8f_func101_010[] =
                        {
                            BSWAP_32BIG_C(0xd6875739U), BSWAP_32BIG_C(0x8451d02eU), BSWAP_32BIG_C(0xaeb042d8U),
                            BSWAP_32BIG_C(0x9e26a9f5U),
                        };
                        r_rsip_func101(Param_p8f_func101_010);
                    }

                    r_rsip_func_sub010(0x380008e5U);

                    WR1_PROG(REG_0094H, 0x00002cc0U);

                    static const uint32_t Param_p8f_func101_011[] =
                    {
                        BSWAP_32BIG_C(0xfa3d3181U), BSWAP_32BIG_C(0x9eade361U), BSWAP_32BIG_C(0xecf69bfeU),
                        BSWAP_32BIG_C(0x056df28fU),
                    };
                    r_rsip_func101(Param_p8f_func101_011);
                }

                r_rsip_func_sub007(0x380088c0U, 0x00000006U, 0x00260000U);

                WR1_PROG(REG_0040H, 0x00402000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                static const uint32_t Param_p8f_func100_009[] =
                {
                    BSWAP_32BIG_C(0x37dd4ab5U), BSWAP_32BIG_C(0x1785c39eU), BSWAP_32BIG_C(0xc4a7b7acU), BSWAP_32BIG_C(
                        0x2a383cabU),
                };
                r_rsip_func100(Param_p8f_func100_009);
                WR1_PROG(REG_009CH, 0x81020000U);
                WR1_PROG(REG_0008H, 0x0000500aU);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_Text[0]);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_Text[1]);

                r_rsip_func_sub016(0x000008e7U, 0x00000863U, 0x000368a5U);

                for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; )
                {
                    r_rsip_func_sub016(0x000008c6U, 0x34202865U, 0x2000d0c0U);

                    WR1_PROG(REG_0094H, 0x00007c06U);
                    WR1_PROG(REG_0040H, 0x00602000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    static const uint32_t Param_p8f_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xa887bc1bU), BSWAP_32BIG_C(0x47ad9e65U), BSWAP_32BIG_C(0xde99ba43U),
                        BSWAP_32BIG_C(0x98ba2ddbU),
                    };
                    r_rsip_func100(Param_p8f_func100_010);
                    WR1_PROG(REG_009CH, 0x81820007U);
                    WR1_PROG(REG_0008H, 0x0000500aU);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD1_ADDR(REG_002CH, &OutData_Text[iLoop]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD1_ADDR(REG_002CH, &OutData_Text[iLoop + 1]);

                    r_rsip_func_sub016(0x0000a4e0U, 0x00000008U, 0x00002c60U);

                    static const uint32_t Param_p8f_func101_012[] =
                    {
                        BSWAP_32BIG_C(0xdef46c17U), BSWAP_32BIG_C(0x1553b742U), BSWAP_32BIG_C(0x303f9199U),
                        BSWAP_32BIG_C(0xb233c79cU),
                    };
                    r_rsip_func101(Param_p8f_func101_012);
                    iLoop = iLoop + 2;
                }

                r_rsip_func_sub010(0x38000865U);

                static const uint32_t Param_p8f_func102_004[] =
                {
                    BSWAP_32BIG_C(0x6f2f4dbaU), BSWAP_32BIG_C(0x68da6a1eU), BSWAP_32BIG_C(0xc5b12857U), BSWAP_32BIG_C(
                        0x0d709620U),
                };
                r_rsip_func102(Param_p8f_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
