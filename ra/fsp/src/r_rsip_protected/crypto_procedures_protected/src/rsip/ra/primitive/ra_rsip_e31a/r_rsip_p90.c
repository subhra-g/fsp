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

rsip_ret_t r_rsip_p90 (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       WRAPPED_KEY_SIZE,
                       uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;
    int32_t  jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00900001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000001c7U, 0x800200c0U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_WrappedKeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00003407U);

    r_rsip_func_sub010(0x3420a8c0U, 0x00000002U, 0x00A70000U);

    r_rsip_func_sub010(0x3420a800U, 0x00000003U, 0x00A70000U);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_p90_func100_001[] =
    {
        BSWAP_32BIG_C(0x9c80c788U), BSWAP_32BIG_C(0x2a95778fU), BSWAP_32BIG_C(0x8998d340U), BSWAP_32BIG_C(0x021df710U),
    };
    r_rsip_func100(Param_p90_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p90_func102_001[] =
        {
            BSWAP_32BIG_C(0x4f273077U), BSWAP_32BIG_C(0x289fef1bU), BSWAP_32BIG_C(0x9fbb8fe5U), BSWAP_32BIG_C(
                0x9370bf29U),
        };
        r_rsip_func102(Param_p90_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x00003486U, 0x38000c84U, 0x00270000U);

        static const uint32_t Param_p90_func100_002[] =
        {
            BSWAP_32BIG_C(0xdaac6d26U), BSWAP_32BIG_C(0x93584a11U), BSWAP_32BIG_C(0xbfc6f33fU), BSWAP_32BIG_C(
                0x2e523f79U),
        };
        r_rsip_func100(Param_p90_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000090U, 0x00000000U);

            static const uint32_t Param_p90_func101_001[] =
            {
                BSWAP_32BIG_C(0xedba8c40U), BSWAP_32BIG_C(0xb389c5caU), BSWAP_32BIG_C(0x838c761cU), BSWAP_32BIG_C(
                    0x0a54468fU),
            };
            r_rsip_func101(Param_p90_func101_001);
            r_rsip_func440(InData_KeyIndex);

            static const uint32_t Param_p90_func100_003[] =
            {
                BSWAP_32BIG_C(0x099d380cU), BSWAP_32BIG_C(0x9d147c05U), BSWAP_32BIG_C(0x10fd1f50U), BSWAP_32BIG_C(
                    0xd066e7beU),
            };
            r_rsip_func100(Param_p90_func100_003);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

            r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

            WR1_PROG(REG_00D4H, 0x00000000U);

            static const uint32_t Param_p90_func101_002[] =
            {
                BSWAP_32BIG_C(0xf8894e3bU), BSWAP_32BIG_C(0x9fce4b5dU), BSWAP_32BIG_C(0xedc510dcU), BSWAP_32BIG_C(
                    0xa9ac08f5U),
            };
            r_rsip_func101(Param_p90_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000007U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000090U, 0x00000000U);

            static const uint32_t Param_p90_func101_003[] =
            {
                BSWAP_32BIG_C(0x69990113U), BSWAP_32BIG_C(0x19ffe889U), BSWAP_32BIG_C(0xf3e38e5fU), BSWAP_32BIG_C(
                    0xff59d66cU),
            };
            r_rsip_func101(Param_p90_func101_003);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_p90_func100_004[] =
            {
                BSWAP_32BIG_C(0xd6206f64U), BSWAP_32BIG_C(0x25dec164U), BSWAP_32BIG_C(0x3849470aU), BSWAP_32BIG_C(
                    0xffa6fadbU),
            };
            r_rsip_func100(Param_p90_func100_004);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

            static const uint32_t Param_p90_func100_005[] =
            {
                BSWAP_32BIG_C(0x39e3ba83U), BSWAP_32BIG_C(0x6b70413aU), BSWAP_32BIG_C(0x2ac310bbU), BSWAP_32BIG_C(
                    0xdf71d321U),
            };
            r_rsip_func100(Param_p90_func100_005);
            r_rsip_func_sub013(0x08000095U, 0x00430011U);

            WR1_PROG(REG_00D4H, 0x40000000U);

            static const uint32_t Param_p90_func101_004[] =
            {
                BSWAP_32BIG_C(0xe544a19aU), BSWAP_32BIG_C(0xc90c215fU), BSWAP_32BIG_C(0xf7a3f475U), BSWAP_32BIG_C(
                    0xe0486889U),
            };
            r_rsip_func101(Param_p90_func101_004);
        }

        static const uint32_t Param_p90_func100_006[] =
        {
            BSWAP_32BIG_C(0x15666930U), BSWAP_32BIG_C(0xa2d82daeU), BSWAP_32BIG_C(0xa69bc796U), BSWAP_32BIG_C(
                0x2e80ace0U),
        };
        r_rsip_func100(Param_p90_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p90_func102_002[] =
            {
                BSWAP_32BIG_C(0x7f295659U), BSWAP_32BIG_C(0xa5c7790fU), BSWAP_32BIG_C(0x4cb0b56fU), BSWAP_32BIG_C(
                    0x54996f9bU),
            };
            r_rsip_func102(Param_p90_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_0094H, 0x00002ca0U);

            WR1_PROG(REG_00D0H, 0x08000044U);
            r_rsip_func_sub012(0x810100c0U, 0x00490005U);

            WR1_PROG(REG_00D0H, 0x08000054U);
            r_rsip_func_sub012(0x810100e0U, 0x00490005U);

            r_rsip_func_sub014(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_002CH, InData_Text[0]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_Text[1]);
            r_rsip_func_sub018(0x00000000U, 0x00000884U, 0x00000863U);
            WR1_PROG(REG_0094H, 0x00002c60U);

            for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; )
            {
                r_rsip_func_sub014(0x000001c7U, 0x80820004U);
                WR1_PROG(REG_002CH, InData_Text[iLoop]);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Text[iLoop + 1]);
                r_rsip_func_sub018(0x00000000U, 0x0000a480U, 0x00000008U);

                WR1_PROG(REG_0094H, 0x00002c60U);

                static const uint32_t Param_p90_func101_005[] =
                {
                    BSWAP_32BIG_C(0x4f61659eU), BSWAP_32BIG_C(0x6fdc4263U), BSWAP_32BIG_C(0xc8fe1c9eU), BSWAP_32BIG_C(
                        0xfae3e9daU),
                };
                r_rsip_func101(Param_p90_func101_005);
                iLoop = iLoop + 2;
            }

            r_rsip_func_sub016(0x38000865U, 0x00000080U, 0x00270000U);

            WR1_PROG(REG_0040H, 0x00402000U);

            WR1_PROG(REG_0094H, 0x0000a880U);
            WR1_PROG(REG_0094H, 0x00000008U);

            WR1_PROG(REG_00D0H, 0x08000065U);
            r_rsip_func_sub005(0x81020080U, 0x00490009U, 0x00400009U);

            r_rsip_func_sub022(0x000034c5U, 0x000030c0U, 0x00003486U);
            r_rsip_func_sub022(0x00026c84U, 0x00016cc6U, 0x00002486U);

            WR1_PROG(REG_0094H, 0x000008a5U);

            for (jLoop = 5; jLoop >= 0; )
            {
                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub012(0x800100e0U, 0x03410005U);

                r_rsip_func_sub005(0x800100c0U, 0x03410005U, 0x00010009U);
                WR1_PROG(REG_0094H, 0x000030c0U);

                for (iLoop = (WRAPPED_KEY_SIZE / 2) - 1; iLoop >= 1; )
                {
                    WR1_PROG(REG_0094H, 0x00000824U);

                    WR1_PROG(REG_00D0H, 0x0a00810dU);
                    r_rsip_func_sub012(0x81020000U, 0x00490009U);
                    r_rsip_func_sub012(0x81820007U, 0x00490009U);

                    r_rsip_func_sub006(0x80040000U, 0x03410011U, 0x00003c47U, 0x0000a4e0U);
                    r_rsip_func_sub022(0x00000004U, 0x00003c67U, 0x0000a8e0U);
                    r_rsip_func_sub022(0x0000000cU, 0x00003080U, 0x000030c0U);

                    static const uint32_t Param_p90_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xb426fe27U), BSWAP_32BIG_C(0x610d6daaU), BSWAP_32BIG_C(0x104dd64dU),
                        BSWAP_32BIG_C(0xecb1c94eU),
                    };
                    r_rsip_func101(Param_p90_func101_006);
                    iLoop = iLoop - 1;
                }

                r_rsip_func_sub016(0x38000cc6U, 0x00000080U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00002ca0U);

                static const uint32_t Param_p90_func101_007[] =
                {
                    BSWAP_32BIG_C(0x027857d4U), BSWAP_32BIG_C(0x70773527U), BSWAP_32BIG_C(0x3d72540dU), BSWAP_32BIG_C(
                        0xdbb1b2b2U),
                };
                r_rsip_func101(Param_p90_func101_007);
                jLoop = jLoop - 1;
            }

            r_rsip_func_sub010(0x380088a0U, 0x00000006U, 0x00270000U);

            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub010(0x38008800U, 0xa6a6a6a6U, 0x00A70000U);

            r_rsip_func_sub010(0x38008820U, 0xa6a6a6a6U, 0x00A70000U);

            static const uint32_t Param_p90_func100_007[] =
            {
                BSWAP_32BIG_C(0x92005d33U), BSWAP_32BIG_C(0x6619a033U), BSWAP_32BIG_C(0xcb6e9ee2U), BSWAP_32BIG_C(
                    0xa9b1866cU),
            };
            r_rsip_func100(Param_p90_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p90_func102_003[] =
                {
                    BSWAP_32BIG_C(0x1f040664U), BSWAP_32BIG_C(0x00de8b7aU), BSWAP_32BIG_C(0x3250f3b3U), BSWAP_32BIG_C(
                        0xb69b4f69U),
                };
                r_rsip_func102(Param_p90_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p90_func100_008[] =
                {
                    BSWAP_32BIG_C(0x205fa2a6U), BSWAP_32BIG_C(0xb45d6feeU), BSWAP_32BIG_C(0x25b8ca41U), BSWAP_32BIG_C(
                        0xdbec6aeeU),
                };
                r_rsip_func100(Param_p90_func100_008);

                WR1_PROG(REG_0094H, 0x00000842U);
                WR1_PROG(REG_009CH, 0x81880002U);
                r_rsip_func_sub009(0x00001404U, 0x00c90021U, 0x00001800U);

                r_rsip_func_sub008(0x000000a1U, 0x0c100104U, 0x00000000U);

                r_rsip_func_sub005(0x80010020U, 0x03410005U, 0x0001000dU);
                WR1_PROG(REG_0094H, 0x0000a820U);
                WR1_PROG(REG_0094H, 0x00000005U);

                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub005(0x80010080U, 0x03410005U, 0x0001000dU);

                r_rsip_func103();
                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000090U, 0x00000000U);

                static const uint32_t Param_p90_func101_008[] =
                {
                    BSWAP_32BIG_C(0x71d5f869U), BSWAP_32BIG_C(0x924f3623U), BSWAP_32BIG_C(0x4c7b3cc0U), BSWAP_32BIG_C(
                        0x968396a2U),
                };
                r_rsip_func101(Param_p90_func101_008);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x000034c4U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000090U, 0x00000000U);

                static const uint32_t Param_p90_func101_009[] =
                {
                    BSWAP_32BIG_C(0x511d8d89U), BSWAP_32BIG_C(0x413d203dU), BSWAP_32BIG_C(0x80006abfU), BSWAP_32BIG_C(
                        0x71020738U),
                };
                r_rsip_func101(Param_p90_func101_009);
                r_rsip_func044();

                WR1_PROG(REG_0094H, 0x00000842U);
                WR1_PROG(REG_00B0H, 0x00001804U);
                r_rsip_func_sub012(0x80880002U, 0x03430021U);

                WR1_PROG(REG_0094H, 0x000008e7U);

                r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

                r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

                WR1_PROG(REG_0094H, 0x00000884U);

                for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
                {
                    r_rsip_func_sub022(0x000008c6U, 0x34202881U, 0x2000d0c0U);

                    WR1_PROG(REG_0094H, 0x00007c06U);
                    WR1_PROG(REG_0040H, 0x00602000U);

                    static const uint32_t Param_p90_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x39c0a0e2U), BSWAP_32BIG_C(0x0119de6fU), BSWAP_32BIG_C(0xf33f7afeU),
                        BSWAP_32BIG_C(0x4f6b8387U),
                    };
                    r_rsip_func100(Param_p90_func100_009);
                    WR1_PROG(REG_00D4H, 0x40000000U);
                    WR1_PROG(REG_00D0H, 0xe7008d05U);
                    r_rsip_func_sub012(0x81840007U, 0x00490011U);

                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[iLoop + 1]);

                    r_rsip_func_sub022(0x0000a4e0U, 0x00000010U, 0x0000a480U);
                    WR1_PROG(REG_0094H, 0x00000004U);

                    static const uint32_t Param_p90_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x9adf5b90U), BSWAP_32BIG_C(0xbe2fe00eU), BSWAP_32BIG_C(0x2e9ad64cU),
                        BSWAP_32BIG_C(0xb3c46649U),
                    };
                    r_rsip_func101(Param_p90_func101_010);
                    iLoop = iLoop + 4U;
                }

                r_rsip_func_sub016(0x38000881U, 0x00000080U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                static const uint32_t Param_p90_func100_010[] =
                {
                    BSWAP_32BIG_C(0x1b99e6cfU), BSWAP_32BIG_C(0x5ea5970dU), BSWAP_32BIG_C(0x0faf07b5U), BSWAP_32BIG_C(
                        0x73ca92baU),
                };
                r_rsip_func100(Param_p90_func100_010);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[iLoop + 1]);

                static const uint32_t Param_p90_func100_011[] =
                {
                    BSWAP_32BIG_C(0xcdc6b124U), BSWAP_32BIG_C(0x7e4f0bc8U), BSWAP_32BIG_C(0x9b4a0922U), BSWAP_32BIG_C(
                        0xc3f1136bU),
                };
                r_rsip_func100(Param_p90_func100_011);
                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                static const uint32_t Param_p90_func102_004[] =
                {
                    BSWAP_32BIG_C(0xf101e0ddU), BSWAP_32BIG_C(0xe0faf36cU), BSWAP_32BIG_C(0x08028894U), BSWAP_32BIG_C(
                        0x8eb5d771U),
                };
                r_rsip_func102(Param_p90_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
