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

void r_rsip_func052 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

        static const uint32_t Param_func052_func100_001[] =
        {
            BSWAP_32BIG_C(0x7c6ac214U), BSWAP_32BIG_C(0xf6d38923U), BSWAP_32BIG_C(0x6edc917dU), BSWAP_32BIG_C(
                0x74e45fe0U),
        };
        r_rsip_func100(Param_func052_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1010000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x1010000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func052_func101_001[] =
            {
                BSWAP_32BIG_C(0xf2100eb9U), BSWAP_32BIG_C(0x1644cec2U), BSWAP_32BIG_C(0x570218c9U), BSWAP_32BIG_C(
                    0x11ddbd6bU),
            };
            r_rsip_func101(Param_func052_func101_001);
        }
        else
        {
            static const uint32_t Param_func052_func101_002[] =
            {
                BSWAP_32BIG_C(0x9d6a3a32U), BSWAP_32BIG_C(0x8c74a943U), BSWAP_32BIG_C(0xbb46c6b9U), BSWAP_32BIG_C(
                    0xb2bd77ccU),
            };
            r_rsip_func101(Param_func052_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_func_sub001(0x00c00091U);

    r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

    OFS_ADR = 40;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000521U);

    static const uint32_t Param_func052_func101_003[] =
    {
        BSWAP_32BIG_C(0x63fc75a1U), BSWAP_32BIG_C(0x06db7dffU), BSWAP_32BIG_C(0x6d74b834U), BSWAP_32BIG_C(0xfc307f0dU),
    };
    r_rsip_func101(Param_func052_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

    OFS_ADR = 80;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000522U);

    static const uint32_t Param_func052_func101_004[] =
    {
        BSWAP_32BIG_C(0xc6f978b9U), BSWAP_32BIG_C(0x45118571U), BSWAP_32BIG_C(0x7dcef9beU), BSWAP_32BIG_C(0xe733a32fU),
    };
    r_rsip_func101(Param_func052_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000523U);

    static const uint32_t Param_func052_func101_005[] =
    {
        BSWAP_32BIG_C(0xea1e641eU), BSWAP_32BIG_C(0xbe352ddeU), BSWAP_32BIG_C(0x74455cbeU), BSWAP_32BIG_C(0x23449c19U),
    };
    r_rsip_func101(Param_func052_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

    OFS_ADR = 120;

    r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000524U);

    static const uint32_t Param_func052_func101_006[] =
    {
        BSWAP_32BIG_C(0x38228f9eU), BSWAP_32BIG_C(0xa1a5aeddU), BSWAP_32BIG_C(0x68dcc687U), BSWAP_32BIG_C(0x093f17e7U),
    };
    r_rsip_func101(Param_func052_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x093b7d04U);

    OFS_ADR = 160;

    r_rsip_func_sub012(0x11a00000U, 0x0000b400U, 0x00000020U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000525U);

    static const uint32_t Param_func052_func101_007[] =
    {
        BSWAP_32BIG_C(0xf85ae6afU), BSWAP_32BIG_C(0x50c047b8U), BSWAP_32BIG_C(0x89dc3e3eU), BSWAP_32BIG_C(0x9fc541d7U),
    };
    r_rsip_func101(Param_func052_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub033(0x15b00000U, 0x00000b7bU, 0x80a0001bU);
    r_rsip_func_sub001(0x03430081U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func052_func100_002[] =
        {
            BSWAP_32BIG_C(0xaa04c482U), BSWAP_32BIG_C(0x55e286acU), BSWAP_32BIG_C(0xb54fbc75U), BSWAP_32BIG_C(
                0x4229209fU),
        };
        r_rsip_func100(Param_func052_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func052_func101_008[] =
            {
                BSWAP_32BIG_C(0xbd2f4512U), BSWAP_32BIG_C(0x1cdcd45aU), BSWAP_32BIG_C(0xdb0a530dU), BSWAP_32BIG_C(
                    0x48eff268U),
            };
            r_rsip_func101(Param_func052_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000521U);

            static const uint32_t Param_func052_func101_009[] =
            {
                BSWAP_32BIG_C(0x5973b3f4U), BSWAP_32BIG_C(0x7debd89eU), BSWAP_32BIG_C(0x9766ef56U), BSWAP_32BIG_C(
                    0x3934cdd6U),
            };
            r_rsip_func101(Param_func052_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

            OFS_ADR = 40;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000522U);

            static const uint32_t Param_func052_func101_010[] =
            {
                BSWAP_32BIG_C(0x0d381f08U), BSWAP_32BIG_C(0xab42f3fbU), BSWAP_32BIG_C(0x0a5f0f5aU), BSWAP_32BIG_C(
                    0xcd3cffd5U),
            };
            r_rsip_func101(Param_func052_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000521U);

            static const uint32_t Param_func052_func101_011[] =
            {
                BSWAP_32BIG_C(0xc01d0439U), BSWAP_32BIG_C(0xdf87e860U), BSWAP_32BIG_C(0x000c1558U), BSWAP_32BIG_C(
                    0x30368515U),
            };
            r_rsip_func101(Param_func052_func101_011);
            r_rsip_func053();

            r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000526U);

            static const uint32_t Param_func052_func101_012[] =
            {
                BSWAP_32BIG_C(0xa19eeb87U), BSWAP_32BIG_C(0x1a1bb519U), BSWAP_32BIG_C(0x02210472U), BSWAP_32BIG_C(
                    0xf5271bbcU),
            };
            r_rsip_func101(Param_func052_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

            OFS_ADR = 40;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000527U);

            static const uint32_t Param_func052_func101_013[] =
            {
                BSWAP_32BIG_C(0xe0adcff3U), BSWAP_32BIG_C(0x1e6dbcb2U), BSWAP_32BIG_C(0xa6cb099fU), BSWAP_32BIG_C(
                    0xaa6c3cabU),
            };
            r_rsip_func101(Param_func052_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

            OFS_ADR = 80;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000523U);

            static const uint32_t Param_func052_func101_014[] =
            {
                BSWAP_32BIG_C(0x51e31ad8U), BSWAP_32BIG_C(0x91d3d0e1U), BSWAP_32BIG_C(0xf72c4cccU), BSWAP_32BIG_C(
                    0x349f7125U),
            };
            r_rsip_func101(Param_func052_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

            OFS_ADR = 120;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000524U);

            static const uint32_t Param_func052_func101_015[] =
            {
                BSWAP_32BIG_C(0x498c84d1U), BSWAP_32BIG_C(0x5c07b8e5U), BSWAP_32BIG_C(0x4320ac62U), BSWAP_32BIG_C(
                    0xeb4e90e0U),
            };
            r_rsip_func101(Param_func052_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_func_sub001(0x00c00081U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000522U);

            static const uint32_t Param_func052_func101_016[] =
            {
                BSWAP_32BIG_C(0x64088ec8U), BSWAP_32BIG_C(0xa1137ecfU), BSWAP_32BIG_C(0x8f6f5227U), BSWAP_32BIG_C(
                    0x876abcd4U),
            };
            r_rsip_func101(Param_func052_func101_016);
            r_rsip_func053();

            r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

            OFS_ADR = 80;

            r_rsip_func_sub012(0x13980000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000528U);

            static const uint32_t Param_func052_func101_017[] =
            {
                BSWAP_32BIG_C(0x44666c98U), BSWAP_32BIG_C(0x19a3f9d4U), BSWAP_32BIG_C(0x71ae2cfeU), BSWAP_32BIG_C(
                    0x9674e24fU),
            };
            r_rsip_func101(Param_func052_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

            OFS_ADR = 120;

            r_rsip_func_sub012(0x19b00000U, 0x0000b400U, 0x00000024U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000529U);

            static const uint32_t Param_func052_func101_018[] =
            {
                BSWAP_32BIG_C(0x60b25cb8U), BSWAP_32BIG_C(0x09849cd5U), BSWAP_32BIG_C(0x72e20d92U), BSWAP_32BIG_C(
                    0x88459d59U),
            };
            r_rsip_func101(Param_func052_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_func_sub001(0x00c00081U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func052_func100_003[] =
            {
                BSWAP_32BIG_C(0x858a157fU), BSWAP_32BIG_C(0xaadc81d1U), BSWAP_32BIG_C(0xc1e4a9f2U), BSWAP_32BIG_C(
                    0x59616e49U),
            };
            r_rsip_func100(Param_func052_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000525U);

                static const uint32_t Param_func052_func101_019[] =
                {
                    BSWAP_32BIG_C(0xc2c0f3d9U), BSWAP_32BIG_C(0x1c868867U), BSWAP_32BIG_C(0x76f4064aU), BSWAP_32BIG_C(
                        0xc35092daU),
                };
                r_rsip_func101(Param_func052_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000526U);

                static const uint32_t Param_func052_func101_020[] =
                {
                    BSWAP_32BIG_C(0xcf049895U), BSWAP_32BIG_C(0x4391b176U), BSWAP_32BIG_C(0xbe70aa70U), BSWAP_32BIG_C(
                        0xe15033d1U),
                };
                r_rsip_func101(Param_func052_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000521U);

                static const uint32_t Param_func052_func101_021[] =
                {
                    BSWAP_32BIG_C(0xbd5601a5U), BSWAP_32BIG_C(0x559a2ac9U), BSWAP_32BIG_C(0x1520a56eU), BSWAP_32BIG_C(
                        0x8f7fd2b9U),
                };
                r_rsip_func101(Param_func052_func101_021);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052aU);

                static const uint32_t Param_func052_func101_022[] =
                {
                    BSWAP_32BIG_C(0xcee7a7b1U), BSWAP_32BIG_C(0xff7ce462U), BSWAP_32BIG_C(0x8efd19d1U), BSWAP_32BIG_C(
                        0x3a4a2ee9U),
                };
                r_rsip_func101(Param_func052_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000527U);

                static const uint32_t Param_func052_func101_023[] =
                {
                    BSWAP_32BIG_C(0xf0f362e9U), BSWAP_32BIG_C(0x375ab0bcU), BSWAP_32BIG_C(0xd7124398U), BSWAP_32BIG_C(
                        0x36391239U),
                };
                r_rsip_func101(Param_func052_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000528U);

                static const uint32_t Param_func052_func101_024[] =
                {
                    BSWAP_32BIG_C(0x3f4c1c10U), BSWAP_32BIG_C(0x976d4db7U), BSWAP_32BIG_C(0x56e10896U), BSWAP_32BIG_C(
                        0xe57c1968U),
                };
                r_rsip_func101(Param_func052_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000522U);

                static const uint32_t Param_func052_func101_025[] =
                {
                    BSWAP_32BIG_C(0x123d43e9U), BSWAP_32BIG_C(0x19223b04U), BSWAP_32BIG_C(0x8ddc8b02U), BSWAP_32BIG_C(
                        0xf4a282f6U),
                };
                r_rsip_func101(Param_func052_func101_025);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052bU);

                static const uint32_t Param_func052_func101_026[] =
                {
                    BSWAP_32BIG_C(0xc50acd4eU), BSWAP_32BIG_C(0x34c71d00U), BSWAP_32BIG_C(0xb6835d2eU), BSWAP_32BIG_C(
                        0x8412ad76U),
                };
                r_rsip_func101(Param_func052_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func052_func101_027[] =
                {
                    BSWAP_32BIG_C(0x077d5b77U), BSWAP_32BIG_C(0x97a81921U), BSWAP_32BIG_C(0x755c34a2U), BSWAP_32BIG_C(
                        0xc5a2dbd4U),
                };
                r_rsip_func101(Param_func052_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052aU);

                static const uint32_t Param_func052_func101_028[] =
                {
                    BSWAP_32BIG_C(0xa92bb347U), BSWAP_32BIG_C(0x296c1816U), BSWAP_32BIG_C(0x46dc743cU), BSWAP_32BIG_C(
                        0x76f69540U),
                };
                r_rsip_func101(Param_func052_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x68d2ac6fU);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052bU);

                static const uint32_t Param_func052_func101_029[] =
                {
                    BSWAP_32BIG_C(0x34b30840U), BSWAP_32BIG_C(0xeab7f3e9U), BSWAP_32BIG_C(0x374e6fb3U), BSWAP_32BIG_C(
                        0x50ae3b0fU),
                };
                r_rsip_func101(Param_func052_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000523U);

                static const uint32_t Param_func052_func101_030[] =
                {
                    BSWAP_32BIG_C(0xc4c524a3U), BSWAP_32BIG_C(0x41cdb506U), BSWAP_32BIG_C(0xa8963a09U), BSWAP_32BIG_C(
                        0x84c8adfdU),
                };
                r_rsip_func101(Param_func052_func101_030);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x725c8882U);

                OFS_ADR = 80;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052cU);

                static const uint32_t Param_func052_func101_031[] =
                {
                    BSWAP_32BIG_C(0x7af55f9eU), BSWAP_32BIG_C(0xc2ba9459U), BSWAP_32BIG_C(0x8844a4aeU), BSWAP_32BIG_C(
                        0xd98ca9f6U),
                };
                r_rsip_func101(Param_func052_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052cU);

                static const uint32_t Param_func052_func101_032[] =
                {
                    BSWAP_32BIG_C(0xe26f2c4eU), BSWAP_32BIG_C(0x9aa932d9U), BSWAP_32BIG_C(0x7f937af4U), BSWAP_32BIG_C(
                        0x544c70b1U),
                };
                r_rsip_func101(Param_func052_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xf22994b8U);

                OFS_ADR = 40;

                r_rsip_func_sub012(0x1f480000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052dU);

                static const uint32_t Param_func052_func101_033[] =
                {
                    BSWAP_32BIG_C(0x3755ac8eU), BSWAP_32BIG_C(0x2e702383U), BSWAP_32BIG_C(0x6d8cd9dfU), BSWAP_32BIG_C(
                        0x3307a73eU),
                };
                r_rsip_func101(Param_func052_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000524U);

                static const uint32_t Param_func052_func101_034[] =
                {
                    BSWAP_32BIG_C(0x3f4279feU), BSWAP_32BIG_C(0x302d87e8U), BSWAP_32BIG_C(0xc375784cU), BSWAP_32BIG_C(
                        0x78d50328U),
                };
                r_rsip_func101(Param_func052_func101_034);
                r_rsip_func303();

                r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

                OFS_ADR = 120;

                r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052dU);

                static const uint32_t Param_func052_func101_035[] =
                {
                    BSWAP_32BIG_C(0x58aa89a5U), BSWAP_32BIG_C(0xe1b53846U), BSWAP_32BIG_C(0x3147e93cU), BSWAP_32BIG_C(
                        0xe67d7176U),
                };
                r_rsip_func101(Param_func052_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func052_func101_036[] =
                {
                    BSWAP_32BIG_C(0xd9ac97bcU), BSWAP_32BIG_C(0x96100312U), BSWAP_32BIG_C(0x00cf8024U), BSWAP_32BIG_C(
                        0xea34fff2U),
                };
                r_rsip_func101(Param_func052_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x093b7d04U);

    OFS_ADR = 160;

    r_rsip_func_sub012(0x11a00000U, 0x0000b400U, 0x00000020U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052eU);

    static const uint32_t Param_func052_func101_037[] =
    {
        BSWAP_32BIG_C(0xd65d8e4bU), BSWAP_32BIG_C(0xf1c6fe15U), BSWAP_32BIG_C(0x57a651e4U), BSWAP_32BIG_C(0x4593a27dU),
    };
    r_rsip_func101(Param_func052_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func052_func100_004[] =
        {
            BSWAP_32BIG_C(0x0ba2029bU), BSWAP_32BIG_C(0xa858a58dU), BSWAP_32BIG_C(0x3fa4efa3U), BSWAP_32BIG_C(
                0xfe4f1928U),
        };
        r_rsip_func100(Param_func052_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func052_func101_038[] =
            {
                BSWAP_32BIG_C(0xb5bee57fU), BSWAP_32BIG_C(0x9813f1c8U), BSWAP_32BIG_C(0x38a6508bU), BSWAP_32BIG_C(
                    0x7e2aafebU),
            };
            r_rsip_func101(Param_func052_func101_038);
        }
        else
        {
            static const uint32_t Param_func052_func101_039[] =
            {
                BSWAP_32BIG_C(0x6416321fU), BSWAP_32BIG_C(0xd47d43d3U), BSWAP_32BIG_C(0xe8c186daU), BSWAP_32BIG_C(
                    0xb5082f64U),
            };
            r_rsip_func101(Param_func052_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x6afa85bfU);

    OFS_ADR = 120;

    r_rsip_func_sub012(0x17a80000U, 0x0000b400U, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000052fU);

    static const uint32_t Param_func052_func101_040[] =
    {
        BSWAP_32BIG_C(0x200159efU), BSWAP_32BIG_C(0xf4bb8116U), BSWAP_32BIG_C(0x83bde300U), BSWAP_32BIG_C(0xf9e96ca4U),
    };
    r_rsip_func101(Param_func052_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x1111000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func052_func100_005[] =
        {
            BSWAP_32BIG_C(0x6ee67558U), BSWAP_32BIG_C(0x9cfb72dbU), BSWAP_32BIG_C(0x0d380054U), BSWAP_32BIG_C(
                0x6f274a77U),
        };
        r_rsip_func100(Param_func052_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);

            static const uint32_t Param_func052_func101_041[] =
            {
                BSWAP_32BIG_C(0x70d389b5U), BSWAP_32BIG_C(0x7b31e8e3U), BSWAP_32BIG_C(0x8236f7e4U), BSWAP_32BIG_C(
                    0x3b05898aU),
            };
            r_rsip_func101(Param_func052_func101_041);
        }
        else
        {
            static const uint32_t Param_func052_func101_042[] =
            {
                BSWAP_32BIG_C(0x81ffdc83U), BSWAP_32BIG_C(0xeaaddd29U), BSWAP_32BIG_C(0xe5b82c09U), BSWAP_32BIG_C(
                    0x6ee4df22U),
            };
            r_rsip_func101(Param_func052_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func052_func100_006[] =
    {
        BSWAP_32BIG_C(0x1f3cb9b7U), BSWAP_32BIG_C(0x568953fcU), BSWAP_32BIG_C(0xf895cad8U), BSWAP_32BIG_C(0x96fa5640U),
    };
    r_rsip_func100(Param_func052_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);

        static const uint32_t Param_func052_func101_043[] =
        {
            BSWAP_32BIG_C(0x3c2344c0U), BSWAP_32BIG_C(0xa2c19d38U), BSWAP_32BIG_C(0xb05c4bd0U), BSWAP_32BIG_C(
                0x1ecc5658U),
        };
        r_rsip_func101(Param_func052_func101_043);
    }
    else
    {
        static const uint32_t Param_func052_func101_044[] =
        {
            BSWAP_32BIG_C(0x04923d9eU), BSWAP_32BIG_C(0xba90c94cU), BSWAP_32BIG_C(0xe0d69265U), BSWAP_32BIG_C(
                0xbfbe2be2U),
        };
        r_rsip_func101(Param_func052_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
