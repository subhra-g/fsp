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

rsip_ret_t r_rsip_pe3 (const uint32_t InData_HashType[],
                       const uint32_t InData_EncSecret[],
                       const uint32_t InData_OutDataType[],
                       uint32_t       OutData_EncMsg[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00e30001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010020U);
    WR1_PROG(REG_002CH, InData_OutDataType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3000a820U, 0x00000002U);
    r_rsip_func_sub022(0x00010020U, 0x0000b420U, 0x00000001U);
    r_rsip_func_sub022(0x00000080U, 0x3000a880U, 0x00000002U);
    r_rsip_func_sub022(0x00010020U, 0x0000b480U, 0x00000001U);
    WR1_PROG(REG_0094H, 0x00000080U);

    static const uint32_t Param_pe3_func100_001[] =
    {
        BSWAP_32BIG_C(0x5f28f8ebU), BSWAP_32BIG_C(0x152bd9afU), BSWAP_32BIG_C(0x6ac4599bU), BSWAP_32BIG_C(0xa682dee1U),
    };
    r_rsip_func100(Param_pe3_func100_001);
    WR1_PROG(REG_0094H, 0x00007c04U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x015c5d71U);

        static const uint32_t Param_pe3_sub100_001[] =
        {
            BSWAP_32BIG_C(0x0000e301U), BSWAP_32BIG_C(0xc1807adbU), BSWAP_32BIG_C(0xaf030ca8U),
            BSWAP_32BIG_C(0x7b0b9d10U),
            BSWAP_32BIG_C(0x6fd7dc49U), BSWAP_32BIG_C(0x0000e301U), BSWAP_32BIG_C(0x74cf1723U),
            BSWAP_32BIG_C(0x8dba3fc6U),
            BSWAP_32BIG_C(0x9cfe364aU),
            BSWAP_32BIG_C(0x223b5de5U), 0x00001404U,
        };
        r_rsip_func_sub100(InData_EncSecret, Param_pe3_sub100_001, RSIP_SEL_BIT_LENGTH_256);

        static const uint32_t Param_pe3_func101_001[] =
        {
            BSWAP_32BIG_C(0x24edc459U), BSWAP_32BIG_C(0x11e95aa8U), BSWAP_32BIG_C(0x3dfefbeaU), BSWAP_32BIG_C(
                0x4eadd7e3U),
        };
        r_rsip_func101(Param_pe3_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x0165e3d8U);

        static const uint32_t Param_pe3_sub100_002[] =
        {
            BSWAP_32BIG_C(0x0000e302U), BSWAP_32BIG_C(0xedfa2f12U), BSWAP_32BIG_C(0x88b74871U),
            BSWAP_32BIG_C(0x3b7d63c5U),
            BSWAP_32BIG_C(0x867ee2f7U), BSWAP_32BIG_C(0x0000e302U), BSWAP_32BIG_C(0x4b59e46fU),
            BSWAP_32BIG_C(0x401a5ccdU),
            BSWAP_32BIG_C(0x536d8f8bU),
            BSWAP_32BIG_C(0x28b3b7c6U), 0x00009406U,
        };
        r_rsip_func_sub100(InData_EncSecret, Param_pe3_sub100_002, RSIP_SEL_BIT_LENGTH_384);

        static const uint32_t Param_pe3_func101_002[] =
        {
            BSWAP_32BIG_C(0xff7b2cedU), BSWAP_32BIG_C(0xde999fb7U), BSWAP_32BIG_C(0x824484ddU), BSWAP_32BIG_C(
                0xb2075f50U),
        };
        r_rsip_func101(Param_pe3_func101_002);
    }

    static const uint32_t Param_pe3_func100_002[] =
    {
        BSWAP_32BIG_C(0xb7dfa5c4U), BSWAP_32BIG_C(0xe5cd1f82U), BSWAP_32BIG_C(0x8ed38a2eU), BSWAP_32BIG_C(0x30814f6eU),
    };
    r_rsip_func100(Param_pe3_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe3_func102_001[] =
        {
            BSWAP_32BIG_C(0x10f86227U), BSWAP_32BIG_C(0xa4faabcfU), BSWAP_32BIG_C(0xb561e8e8U), BSWAP_32BIG_C(
                0xd62753d9U),
        };
        r_rsip_func102(Param_pe3_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe3_func100_003[] =
        {
            BSWAP_32BIG_C(0x6f50672cU), BSWAP_32BIG_C(0x130de3ceU), BSWAP_32BIG_C(0xa44634b1U), BSWAP_32BIG_C(
                0x007243e7U),
        };
        r_rsip_func100(Param_pe3_func100_003);
        r_rsip_func103();

        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e303U, 0x00000000U);

        static const uint32_t Param_pe3_func101_003[] =
        {
            BSWAP_32BIG_C(0xb1ed8323U), BSWAP_32BIG_C(0x5e2d2e59U), BSWAP_32BIG_C(0x326a2b1eU), BSWAP_32BIG_C(
                0xe116af16U),
        };
        r_rsip_func101(Param_pe3_func101_003);
        r_rsip_func143();

        static const uint32_t Param_pe3_func100_004[] =
        {
            BSWAP_32BIG_C(0x92c708e4U), BSWAP_32BIG_C(0xce4baa7bU), BSWAP_32BIG_C(0x773e4e4fU), BSWAP_32BIG_C(
                0x7caab5f1U),
        };
        r_rsip_func100(Param_pe3_func100_004);
        WR1_PROG(REG_0094H, 0x00007c01U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_0094H, 0x0000b4c0U);
            r_rsip_func_sub010(0x01799093U, 0x38000c84U, 0x00270000U);

            static const uint32_t Param_pe3_func100_005[] =
            {
                BSWAP_32BIG_C(0x04e470deU), BSWAP_32BIG_C(0x795c7c87U), BSWAP_32BIG_C(0x3b77ffdcU), BSWAP_32BIG_C(
                    0x3b488588U),
            };
            r_rsip_func100(Param_pe3_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00001804U);

                static const uint32_t Param_pe3_func101_004[] =
                {
                    BSWAP_32BIG_C(0x693ad791U), BSWAP_32BIG_C(0x4eb25251U), BSWAP_32BIG_C(0xb9e640f0U), BSWAP_32BIG_C(
                        0x93f7d1f2U),
                };
                r_rsip_func101(Param_pe3_func101_004);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x0000000cU);

                WR1_PROG(REG_00B0H, 0x00009806U);

                static const uint32_t Param_pe3_func101_005[] =
                {
                    BSWAP_32BIG_C(0x91d6d388U), BSWAP_32BIG_C(0x506e223dU), BSWAP_32BIG_C(0xa6e1d84eU), BSWAP_32BIG_C(
                        0x0fd9a490U),
                };
                r_rsip_func101(Param_pe3_func101_005);
            }

            static const uint32_t Param_pe3_func101_006[] =
            {
                BSWAP_32BIG_C(0xea3c5c5fU), BSWAP_32BIG_C(0x56b048c1U), BSWAP_32BIG_C(0x287c0f2bU), BSWAP_32BIG_C(
                    0x46a3a027U),
            };
            r_rsip_func101(Param_pe3_func101_006);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_0094H, 0x0000b440U);
            r_rsip_func_sub010(0x00000010U, 0x38000c84U, 0x00270000U);

            static const uint32_t Param_pe3_func100_006[] =
            {
                BSWAP_32BIG_C(0x0a11f0e8U), BSWAP_32BIG_C(0x426a8139U), BSWAP_32BIG_C(0x9ddf65e9U), BSWAP_32BIG_C(
                    0xda86b874U),
            };
            r_rsip_func100(Param_pe3_func100_006);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub022(0x0000b4a0U, 0x00000008U, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x01b41ce9U);

                WR1_PROG(REG_00B0H, 0x00001804U);

                static const uint32_t Param_pe3_func101_007[] =
                {
                    BSWAP_32BIG_C(0x2634bc0eU), BSWAP_32BIG_C(0xdc4153bbU), BSWAP_32BIG_C(0x18025c31U), BSWAP_32BIG_C(
                        0x845813b6U),
                };
                r_rsip_func101(Param_pe3_func101_007);
            }
            else
            {
                r_rsip_func_sub022(0x0000b4a0U, 0x0000000cU, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x0199f119U);

                WR1_PROG(REG_00B0H, 0x00009806U);

                static const uint32_t Param_pe3_func101_008[] =
                {
                    BSWAP_32BIG_C(0xc7cfc9c2U), BSWAP_32BIG_C(0x9e2fdd5bU), BSWAP_32BIG_C(0x7175efa0U), BSWAP_32BIG_C(
                        0xe377478aU),
                };
                r_rsip_func101(Param_pe3_func101_008);
            }

            static const uint32_t Param_pe3_func101_009[] =
            {
                BSWAP_32BIG_C(0x94f1029cU), BSWAP_32BIG_C(0x51c28025U), BSWAP_32BIG_C(0x38ad21d2U), BSWAP_32BIG_C(
                    0xefcc6c47U),
            };
            r_rsip_func101(Param_pe3_func101_009);
        }

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e303U, 0x00000000U);

        static const uint32_t Param_pe3_func101_010[] =
        {
            BSWAP_32BIG_C(0x6dc61a8dU), BSWAP_32BIG_C(0x5c6cce81U), BSWAP_32BIG_C(0x6425b422U), BSWAP_32BIG_C(
                0x44e4ae76U),
        };
        r_rsip_func101(Param_pe3_func101_010);
        r_rsip_func044();

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pe3_func100_007[] =
        {
            BSWAP_32BIG_C(0x13f9a85fU), BSWAP_32BIG_C(0x87f2d198U), BSWAP_32BIG_C(0x3cad03caU), BSWAP_32BIG_C(
                0x045a9b1fU),
        };
        r_rsip_func100(Param_pe3_func100_007);
        WR1_PROG(REG_0094H, 0x00007c01U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e301U, 0x00000000U);
            static const uint32_t Param_pe3_func101_011[] =
            {
                BSWAP_32BIG_C(0x77a4ae12U), BSWAP_32BIG_C(0x23887516U), BSWAP_32BIG_C(0x10a37bd0U), BSWAP_32BIG_C(
                    0xa0ab5bedU),
            };
            r_rsip_func101(Param_pe3_func101_011);
            r_rsip_func450(OutData_EncMsg);

            static const uint32_t Param_pe3_func101_012[] =
            {
                BSWAP_32BIG_C(0x0a6bd8b4U), BSWAP_32BIG_C(0xab068637U), BSWAP_32BIG_C(0x742e8febU), BSWAP_32BIG_C(
                    0xbb32cbbdU),
            };
            r_rsip_func101(Param_pe3_func101_012);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e302U, 0x00000000U);
            static const uint32_t Param_pe3_func101_013[] =
            {
                BSWAP_32BIG_C(0x9b99cbf3U), BSWAP_32BIG_C(0x263eed7dU), BSWAP_32BIG_C(0x38a41889U), BSWAP_32BIG_C(
                    0x3c416078U),
            };
            r_rsip_func101(Param_pe3_func101_013);
            r_rsip_func450(OutData_KeyIndex);

            static const uint32_t Param_pe3_func101_014[] =
            {
                BSWAP_32BIG_C(0xfa6c7c9bU), BSWAP_32BIG_C(0xfedc6961U), BSWAP_32BIG_C(0x5d9e9e8cU), BSWAP_32BIG_C(
                    0xe174f553U),
            };
            r_rsip_func101(Param_pe3_func101_014);
        }

        static const uint32_t Param_pe3_func102_002[] =
        {
            BSWAP_32BIG_C(0xa4f76870U), BSWAP_32BIG_C(0x5c3f732fU), BSWAP_32BIG_C(0x6b3ee82bU), BSWAP_32BIG_C(
                0x90be2ffeU),
        };
        r_rsip_func102(Param_pe3_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
