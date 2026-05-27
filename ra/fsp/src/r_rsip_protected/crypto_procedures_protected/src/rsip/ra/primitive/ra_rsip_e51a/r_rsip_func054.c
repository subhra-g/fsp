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

void r_rsip_func054 (void)
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

        static const uint32_t Param_func054_func100_001[] =
        {
            BSWAP_32BIG_C(0x0114d52cU), BSWAP_32BIG_C(0x386b9764U), BSWAP_32BIG_C(0x73ca42daU), BSWAP_32BIG_C(
                0xa7c4294bU),
        };
        r_rsip_func100(Param_func054_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1600H, 0x00002fc0U);

            static const uint32_t Param_func054_func101_001[] =
            {
                BSWAP_32BIG_C(0xa9471521U), BSWAP_32BIG_C(0x774cdc21U), BSWAP_32BIG_C(0x387f848dU), BSWAP_32BIG_C(
                    0xccb62111U),
            };
            r_rsip_func101(Param_func054_func101_001);
        }
        else
        {
            static const uint32_t Param_func054_func101_002[] =
            {
                BSWAP_32BIG_C(0xdde6385cU), BSWAP_32BIG_C(0xdcb41b2dU), BSWAP_32BIG_C(0x328ee887U), BSWAP_32BIG_C(
                    0x76f88bdeU),
            };
            r_rsip_func101(Param_func054_func101_002);

            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_func_sub001(0x00c00111U);

    r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

    OFS_ADR = 72;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000541U);

    static const uint32_t Param_func054_func101_003[] =
    {
        BSWAP_32BIG_C(0xfea630f6U), BSWAP_32BIG_C(0x45c2ae0bU), BSWAP_32BIG_C(0xb385cb86U), BSWAP_32BIG_C(0x2057b232U),
    };
    r_rsip_func101(Param_func054_func101_003);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x94174653U);

    OFS_ADR = 144;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000542U);

    static const uint32_t Param_func054_func101_004[] =
    {
        BSWAP_32BIG_C(0x7d561fc3U), BSWAP_32BIG_C(0xa4c40e9cU), BSWAP_32BIG_C(0xa1356e42U), BSWAP_32BIG_C(0xf5ec4fa8U),
    };
    r_rsip_func101(Param_func054_func101_004);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

    OFS_ADR = 0;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000543U);

    static const uint32_t Param_func054_func101_005[] =
    {
        BSWAP_32BIG_C(0x51ff7c06U), BSWAP_32BIG_C(0x558bed30U), BSWAP_32BIG_C(0x3216d2d2U), BSWAP_32BIG_C(0x0fb78763U),
    };
    r_rsip_func101(Param_func054_func101_005);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

    OFS_ADR = 216;

    r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000544U);

    static const uint32_t Param_func054_func101_006[] =
    {
        BSWAP_32BIG_C(0x23599527U), BSWAP_32BIG_C(0xc8d76b11U), BSWAP_32BIG_C(0x82635f52U), BSWAP_32BIG_C(0xb3c2a4c2U),
    };
    r_rsip_func101(Param_func054_func101_006);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

    OFS_ADR = 288;

    r_rsip_func_sub012(0x11200000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000545U);

    static const uint32_t Param_func054_func101_007[] =
    {
        BSWAP_32BIG_C(0x53bb93fdU), BSWAP_32BIG_C(0xec245d90U), BSWAP_32BIG_C(0x5d7c9b28U), BSWAP_32BIG_C(0x3d0918c3U),
    };
    r_rsip_func101(Param_func054_func101_007);
    r_rsip_func016(OFS_ADR);

    r_rsip_func_sub033(0x15300000U, 0x00000b7bU, 0x80c0001bU);
    r_rsip_func_sub001(0x03430101U);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func054_func100_002[] =
        {
            BSWAP_32BIG_C(0xcf4cf38eU), BSWAP_32BIG_C(0x020afd29U), BSWAP_32BIG_C(0x00af941cU), BSWAP_32BIG_C(
                0x39507714U),
        };
        r_rsip_func100(Param_func054_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_func054_func101_008[] =
            {
                BSWAP_32BIG_C(0x02527f2eU), BSWAP_32BIG_C(0x403184f7U), BSWAP_32BIG_C(0x14fb28d3U), BSWAP_32BIG_C(
                    0xe40e6853U),
            };
            r_rsip_func101(Param_func054_func101_008);

            break;
        }
        else
        {
            r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000541U);

            static const uint32_t Param_func054_func101_009[] =
            {
                BSWAP_32BIG_C(0x00b488f5U), BSWAP_32BIG_C(0xe2077677U), BSWAP_32BIG_C(0x366e26d8U), BSWAP_32BIG_C(
                    0x7b4a6c90U),
            };
            r_rsip_func101(Param_func054_func101_009);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

            OFS_ADR = 72;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000542U);

            static const uint32_t Param_func054_func101_010[] =
            {
                BSWAP_32BIG_C(0xf4ea50e3U), BSWAP_32BIG_C(0x930aa438U), BSWAP_32BIG_C(0x7584d8edU), BSWAP_32BIG_C(
                    0x73f29ed5U),
            };
            r_rsip_func101(Param_func054_func101_010);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000541U);

            static const uint32_t Param_func054_func101_011[] =
            {
                BSWAP_32BIG_C(0x56648348U), BSWAP_32BIG_C(0xc321bc63U), BSWAP_32BIG_C(0x613cda0dU), BSWAP_32BIG_C(
                    0x424f0251U),
            };
            r_rsip_func101(Param_func054_func101_011);
            r_rsip_func055();

            r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

            OFS_ADR = 0;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000546U);

            static const uint32_t Param_func054_func101_012[] =
            {
                BSWAP_32BIG_C(0x53481bb8U), BSWAP_32BIG_C(0xf096fde8U), BSWAP_32BIG_C(0xfdd55b91U), BSWAP_32BIG_C(
                    0x1aeb10f0U),
            };
            r_rsip_func101(Param_func054_func101_012);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

            OFS_ADR = 72;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000547U);

            static const uint32_t Param_func054_func101_013[] =
            {
                BSWAP_32BIG_C(0xb7ec2b76U), BSWAP_32BIG_C(0x48622633U), BSWAP_32BIG_C(0xca5d036bU), BSWAP_32BIG_C(
                    0xfe7befefU),
            };
            r_rsip_func101(Param_func054_func101_013);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0x94174653U);

            OFS_ADR = 144;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000543U);

            static const uint32_t Param_func054_func101_014[] =
            {
                BSWAP_32BIG_C(0xe0d9cb00U), BSWAP_32BIG_C(0x2f5ad688U), BSWAP_32BIG_C(0xb8e47143U), BSWAP_32BIG_C(
                    0xe3a1e7c1U),
            };
            r_rsip_func101(Param_func054_func101_014);
            r_rsip_func017(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

            OFS_ADR = 216;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000544U);

            static const uint32_t Param_func054_func101_015[] =
            {
                BSWAP_32BIG_C(0x4331cb5bU), BSWAP_32BIG_C(0xe7fb1f5bU), BSWAP_32BIG_C(0xefa89eb3U), BSWAP_32BIG_C(
                    0x87271464U),
            };
            r_rsip_func101(Param_func054_func101_015);
            r_rsip_func017(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_func_sub001(0x00c00101U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000542U);

            static const uint32_t Param_func054_func101_016[] =
            {
                BSWAP_32BIG_C(0x3e28f773U), BSWAP_32BIG_C(0x8a9fecfeU), BSWAP_32BIG_C(0xaa4ee8dcU), BSWAP_32BIG_C(
                    0xae7a96cdU),
            };
            r_rsip_func101(Param_func054_func101_016);
            r_rsip_func055();

            r_rsip_func_sub004(0x0b040184U, 0x94174653U);

            OFS_ADR = 144;

            r_rsip_func_sub012(0x13180000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000548U);

            static const uint32_t Param_func054_func101_017[] =
            {
                BSWAP_32BIG_C(0xe61ff5a3U), BSWAP_32BIG_C(0x2cb247f8U), BSWAP_32BIG_C(0xdd9b76abU), BSWAP_32BIG_C(
                    0x939cc005U),
            };
            r_rsip_func101(Param_func054_func101_017);
            r_rsip_func016(OFS_ADR);

            r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

            OFS_ADR = 216;

            r_rsip_func_sub012(0x19300000U, 0x0000b400U, 0x00000044U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000549U);

            static const uint32_t Param_func054_func101_018[] =
            {
                BSWAP_32BIG_C(0x5da03a5cU), BSWAP_32BIG_C(0x24313715U), BSWAP_32BIG_C(0x614cee89U), BSWAP_32BIG_C(
                    0xf88315f2U),
            };
            r_rsip_func101(Param_func054_func101_018);
            r_rsip_func016(OFS_ADR);

            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_func_sub001(0x00c00101U);

            r_rsip_func_sub002(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);

            r_rsip_func_sub002(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);

            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);

            r_rsip_func_sub002(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_func054_func100_003[] =
            {
                BSWAP_32BIG_C(0x14c820feU), BSWAP_32BIG_C(0x0cdfecd2U), BSWAP_32BIG_C(0xc71b247aU), BSWAP_32BIG_C(
                    0x425b56e8U),
            };
            r_rsip_func100(Param_func054_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000545U);

                static const uint32_t Param_func054_func101_019[] =
                {
                    BSWAP_32BIG_C(0xebde67d8U), BSWAP_32BIG_C(0x03ea280fU), BSWAP_32BIG_C(0x3c1b26b6U), BSWAP_32BIG_C(
                        0xf8a7875dU),
                };
                r_rsip_func101(Param_func054_func101_019);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000546U);

                static const uint32_t Param_func054_func101_020[] =
                {
                    BSWAP_32BIG_C(0xac0aa1b4U), BSWAP_32BIG_C(0x366aec0bU), BSWAP_32BIG_C(0x8dba3c05U), BSWAP_32BIG_C(
                        0x2b922f80U),
                };
                r_rsip_func101(Param_func054_func101_020);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000541U);

                static const uint32_t Param_func054_func101_021[] =
                {
                    BSWAP_32BIG_C(0x31357296U), BSWAP_32BIG_C(0x94317cc8U), BSWAP_32BIG_C(0x252ad271U), BSWAP_32BIG_C(
                        0xe2b365e0U),
                };
                r_rsip_func101(Param_func054_func101_021);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054aU);

                static const uint32_t Param_func054_func101_022[] =
                {
                    BSWAP_32BIG_C(0x920740a0U), BSWAP_32BIG_C(0xf3e5109fU), BSWAP_32BIG_C(0x7761f4e8U), BSWAP_32BIG_C(
                        0x07e7ff7bU),
                };
                r_rsip_func101(Param_func054_func101_022);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000547U);

                static const uint32_t Param_func054_func101_023[] =
                {
                    BSWAP_32BIG_C(0x59046d9eU), BSWAP_32BIG_C(0xf7e4fe60U), BSWAP_32BIG_C(0xd76cd256U), BSWAP_32BIG_C(
                        0xb4e19c85U),
                };
                r_rsip_func101(Param_func054_func101_023);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000548U);

                static const uint32_t Param_func054_func101_024[] =
                {
                    BSWAP_32BIG_C(0x6600b9bcU), BSWAP_32BIG_C(0xb7cecfaaU), BSWAP_32BIG_C(0x98d343e6U), BSWAP_32BIG_C(
                        0xb4f76ad9U),
                };
                r_rsip_func101(Param_func054_func101_024);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000542U);

                static const uint32_t Param_func054_func101_025[] =
                {
                    BSWAP_32BIG_C(0xd2b499c6U), BSWAP_32BIG_C(0xead45d6eU), BSWAP_32BIG_C(0x2334d23fU), BSWAP_32BIG_C(
                        0x1621bc29U),
                };
                r_rsip_func101(Param_func054_func101_025);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054bU);

                static const uint32_t Param_func054_func101_026[] =
                {
                    BSWAP_32BIG_C(0x9464d078U), BSWAP_32BIG_C(0xfc4e2801U), BSWAP_32BIG_C(0xe52614d7U), BSWAP_32BIG_C(
                        0x7462fbadU),
                };
                r_rsip_func101(Param_func054_func101_026);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func054_func101_027[] =
                {
                    BSWAP_32BIG_C(0x2f398a84U), BSWAP_32BIG_C(0x63398ec9U), BSWAP_32BIG_C(0xfc51de95U), BSWAP_32BIG_C(
                        0x0ccf339bU),
                };
                r_rsip_func101(Param_func054_func101_027);
            }
            else
            {
                r_rsip_func_sub002(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054aU);

                static const uint32_t Param_func054_func101_028[] =
                {
                    BSWAP_32BIG_C(0x0971b9b3U), BSWAP_32BIG_C(0x3f9b66a3U), BSWAP_32BIG_C(0x62640cafU), BSWAP_32BIG_C(
                        0x76a3dee8U),
                };
                r_rsip_func101(Param_func054_func101_028);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0x933f58e2U);

                OFS_ADR = 0;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054bU);

                static const uint32_t Param_func054_func101_029[] =
                {
                    BSWAP_32BIG_C(0x951f6a87U), BSWAP_32BIG_C(0x8aa15a51U), BSWAP_32BIG_C(0x306075b4U), BSWAP_32BIG_C(
                        0xd866f2c1U),
                };
                r_rsip_func101(Param_func054_func101_029);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000543U);

                static const uint32_t Param_func054_func101_030[] =
                {
                    BSWAP_32BIG_C(0x8005f1c6U), BSWAP_32BIG_C(0xfb1a9aa8U), BSWAP_32BIG_C(0x558990c3U), BSWAP_32BIG_C(
                        0x3b40bdceU),
                };
                r_rsip_func101(Param_func054_func101_030);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0x94174653U);

                OFS_ADR = 144;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054cU);

                static const uint32_t Param_func054_func101_031[] =
                {
                    BSWAP_32BIG_C(0xd803fb33U), BSWAP_32BIG_C(0xebb58422U), BSWAP_32BIG_C(0xabec795bU), BSWAP_32BIG_C(
                        0x30cb057dU),
                };
                r_rsip_func101(Param_func054_func101_031);
                r_rsip_func016(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054cU);

                static const uint32_t Param_func054_func101_032[] =
                {
                    BSWAP_32BIG_C(0x060f9514U), BSWAP_32BIG_C(0x83b7ef9cU), BSWAP_32BIG_C(0x241c8b07U), BSWAP_32BIG_C(
                        0x6a605418U),
                };
                r_rsip_func101(Param_func054_func101_032);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub004(0x0b040184U, 0xd9634da2U);

                OFS_ADR = 72;

                r_rsip_func_sub012(0x1ec80000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054dU);

                static const uint32_t Param_func054_func101_033[] =
                {
                    BSWAP_32BIG_C(0x6f0d7e7cU), BSWAP_32BIG_C(0x0f1e7902U), BSWAP_32BIG_C(0x319ec8e5U), BSWAP_32BIG_C(
                        0x711ad429U),
                };
                r_rsip_func101(Param_func054_func101_033);
                r_rsip_func017(OFS_ADR);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000544U);

                static const uint32_t Param_func054_func101_034[] =
                {
                    BSWAP_32BIG_C(0x6a021b57U), BSWAP_32BIG_C(0x57df69b1U), BSWAP_32BIG_C(0x8e97125fU), BSWAP_32BIG_C(
                        0xc62627eeU),
                };
                r_rsip_func101(Param_func054_func101_034);
                r_rsip_func305();

                r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

                OFS_ADR = 216;

                r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054dU);

                static const uint32_t Param_func054_func101_035[] =
                {
                    BSWAP_32BIG_C(0xbb449c76U), BSWAP_32BIG_C(0x713a34d1U), BSWAP_32BIG_C(0xa400470bU), BSWAP_32BIG_C(
                        0xf3996329U),
                };
                r_rsip_func101(Param_func054_func101_035);
                r_rsip_func016(OFS_ADR);

                static const uint32_t Param_func054_func101_036[] =
                {
                    BSWAP_32BIG_C(0xcb6b16efU), BSWAP_32BIG_C(0xace48422U), BSWAP_32BIG_C(0x3452d5faU), BSWAP_32BIG_C(
                        0x179cd397U),
                };
                r_rsip_func101(Param_func054_func101_036);
            }
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

    OFS_ADR = 288;

    r_rsip_func_sub012(0x11200000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054eU);

    static const uint32_t Param_func054_func101_037[] =
    {
        BSWAP_32BIG_C(0x420d5ea7U), BSWAP_32BIG_C(0x1a3099dbU), BSWAP_32BIG_C(0x2e8c381dU), BSWAP_32BIG_C(0xe72732c0U),
    };
    r_rsip_func101(Param_func054_func101_037);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);

        static const uint32_t Param_func054_func100_004[] =
        {
            BSWAP_32BIG_C(0x151fbae3U), BSWAP_32BIG_C(0xfb8adb0fU), BSWAP_32BIG_C(0x3b042ad5U), BSWAP_32BIG_C(
                0x979221a5U),
        };
        r_rsip_func100(Param_func054_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);

            r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);

            WR1_PROG(REG_1600H, 0x000033c0U);

            static const uint32_t Param_func054_func101_038[] =
            {
                BSWAP_32BIG_C(0x253ade5eU), BSWAP_32BIG_C(0x190e4edfU), BSWAP_32BIG_C(0x2c010649U), BSWAP_32BIG_C(
                    0x92300968U),
            };
            r_rsip_func101(Param_func054_func101_038);
        }
        else
        {
            static const uint32_t Param_func054_func101_039[] =
            {
                BSWAP_32BIG_C(0xd87ee3f0U), BSWAP_32BIG_C(0x49cf04a7U), BSWAP_32BIG_C(0xb2fad346U), BSWAP_32BIG_C(
                    0xbc9540dfU),
            };
            r_rsip_func101(Param_func054_func101_039);

            break;
        }
    }

    r_rsip_func_sub004(0x0b040184U, 0xe14d5c93U);

    OFS_ADR = 216;

    r_rsip_func_sub012(0x17280000U, 0x0000b400U, 0x00000044U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000054fU);

    static const uint32_t Param_func054_func101_040[] =
    {
        BSWAP_32BIG_C(0x2e3a9051U), BSWAP_32BIG_C(0x740ee11aU), BSWAP_32BIG_C(0xbe37186dU), BSWAP_32BIG_C(0xb125ae82U),
    };
    r_rsip_func101(Param_func054_func101_040);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    while (1)
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000a40U, 0x2121000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func054_func100_005[] =
        {
            BSWAP_32BIG_C(0x7ab81e38U), BSWAP_32BIG_C(0xd06568e8U), BSWAP_32BIG_C(0x36bb363aU), BSWAP_32BIG_C(
                0xb5757ff9U),
        };
        r_rsip_func100(Param_func054_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func054_func101_041[] =
            {
                BSWAP_32BIG_C(0x90380ef4U), BSWAP_32BIG_C(0xae544b11U), BSWAP_32BIG_C(0x3f15c1c9U), BSWAP_32BIG_C(
                    0x798cd3c9U),
            };
            r_rsip_func101(Param_func054_func101_041);
        }
        else
        {
            static const uint32_t Param_func054_func101_042[] =
            {
                BSWAP_32BIG_C(0x6d3852e3U), BSWAP_32BIG_C(0x8fdf0541U), BSWAP_32BIG_C(0x65cf6941U), BSWAP_32BIG_C(
                    0xa6b3936aU),
            };
            r_rsip_func101(Param_func054_func101_042);

            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);

    static const uint32_t Param_func054_func100_006[] =
    {
        BSWAP_32BIG_C(0xeb6141e3U), BSWAP_32BIG_C(0xe9eb3966U), BSWAP_32BIG_C(0x2bd55db2U), BSWAP_32BIG_C(0x226fe2f1U),
    };
    r_rsip_func100(Param_func054_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);

        static const uint32_t Param_func054_func101_043[] =
        {
            BSWAP_32BIG_C(0x88397779U), BSWAP_32BIG_C(0xe6268741U), BSWAP_32BIG_C(0x0e32048aU), BSWAP_32BIG_C(
                0x9601bf37U),
        };
        r_rsip_func101(Param_func054_func101_043);
    }
    else
    {
        static const uint32_t Param_func054_func101_044[] =
        {
            BSWAP_32BIG_C(0x8c20d2c2U), BSWAP_32BIG_C(0x589cc6e2U), BSWAP_32BIG_C(0x87e2f6fdU), BSWAP_32BIG_C(
                0x6f5aca9cU),
        };
        r_rsip_func101(Param_func054_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
