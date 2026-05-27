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

void r_rsip_func057 (const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3[])
{
    uint32_t iLoop = 0U;
    uint32_t oLoop = 0U;

    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
    WR4_ADDR(REG_1420H, &ARG1[0]);

    r_rsip_func_sub020(0x000000a1U, 0x08000054U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f057U);

    static const uint32_t Param_func057_func101_001[] =
    {
        BSWAP_32BIG_C(0x1d9c643fU), BSWAP_32BIG_C(0x51f05ae0U), BSWAP_32BIG_C(0x1a2fbd89U), BSWAP_32BIG_C(0x4a9f277eU),
    };
    r_rsip_func101(Param_func057_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000ffU);

    static const uint32_t Param_func057_func101_002[] =
    {
        BSWAP_32BIG_C(0x91115787U), BSWAP_32BIG_C(0x3dc4b55cU), BSWAP_32BIG_C(0xcce4258fU), BSWAP_32BIG_C(0x98a1bd5aU),
    };
    r_rsip_func101(Param_func057_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000feU);

    static const uint32_t Param_func057_func101_003[] =
    {
        BSWAP_32BIG_C(0x7a34a588U), BSWAP_32BIG_C(0x9f19faddU), BSWAP_32BIG_C(0x105d4e65U), BSWAP_32BIG_C(0x2c6b9c61U),
    };
    r_rsip_func101(Param_func057_func101_003);
    r_rsip_func044();

    static const uint32_t Param_func057_func100_001[] =
    {
        BSWAP_32BIG_C(0xb45d6191U), BSWAP_32BIG_C(0x69f02425U), BSWAP_32BIG_C(0xcdcf3ff3U), BSWAP_32BIG_C(0xfcd2661cU),
    };
    r_rsip_func100(Param_func057_func100_001);

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1000H, 0x00010000U);

    r_rsip_func081();

    r_rsip_func_sub014(0x00007c01U, 0x00600000U);

    oLoop = 0U;
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func057_func100_002[] =
            {
                BSWAP_32BIG_C(0xf78b7c3bU), BSWAP_32BIG_C(0x5bf2abb1U), BSWAP_32BIG_C(0x2dd45823U), BSWAP_32BIG_C(
                    0x8b9bebacU),
            };
            r_rsip_func100(Param_func057_func100_002);
            r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            r_rsip_func_sub001(0x00810011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            static const uint32_t Param_func057_func101_004[] =
            {
                BSWAP_32BIG_C(0x8c67d4baU), BSWAP_32BIG_C(0x5dbb6346U), BSWAP_32BIG_C(0x36314530U), BSWAP_32BIG_C(
                    0xe22570ceU),
            };
            r_rsip_func101(Param_func057_func101_004);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_005[] =
        {
            BSWAP_32BIG_C(0x3c8e1e9eU), BSWAP_32BIG_C(0x8b587a19U), BSWAP_32BIG_C(0x22480e81U), BSWAP_32BIG_C(
                0x604ecefeU),
        };
        r_rsip_func101(Param_func057_func101_005);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000aU)
    {
        static const uint32_t Param_func057_func100_003[] =
        {
            BSWAP_32BIG_C(0xd9e45ba4U), BSWAP_32BIG_C(0x3ee3425fU), BSWAP_32BIG_C(0xda42dcd5U), BSWAP_32BIG_C(
                0xaa35d3a6U),
        };
        r_rsip_func100(Param_func057_func100_003);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func065(0, ARG3);
        static const uint32_t Param_func057_func100_004[] =
        {
            BSWAP_32BIG_C(0xb747c814U), BSWAP_32BIG_C(0x21e78d2aU), BSWAP_32BIG_C(0x570dc412U), BSWAP_32BIG_C(
                0x5b2ccc31U),
        };
        r_rsip_func100(Param_func057_func100_004);
        r_rsip_func065(8, ARG3);
        static const uint32_t Param_func057_func100_005[] =
        {
            BSWAP_32BIG_C(0xfff15fe9U), BSWAP_32BIG_C(0x4730eb1cU), BSWAP_32BIG_C(0xac182b22U), BSWAP_32BIG_C(
                0xf6f9539bU),
        };
        r_rsip_func100(Param_func057_func100_005);
        r_rsip_func065(16, ARG3);
        static const uint32_t Param_func057_func100_006[] =
        {
            BSWAP_32BIG_C(0x63681694U), BSWAP_32BIG_C(0x2cd6435cU), BSWAP_32BIG_C(0x26d97b23U), BSWAP_32BIG_C(
                0x73d8a97aU),
        };
        r_rsip_func100(Param_func057_func100_006);
        r_rsip_func065(24, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func100_007[] =
        {
            BSWAP_32BIG_C(0x405e106eU), BSWAP_32BIG_C(0x287e9cefU), BSWAP_32BIG_C(0x1189f507U), BSWAP_32BIG_C(
                0x9e9ff40aU),
        };
        r_rsip_func100(Param_func057_func100_007);
        r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
        WR4_ADDR(REG_1420H, &ARG2[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        static const uint32_t Param_func057_func101_006[] =
        {
            BSWAP_32BIG_C(0x36b59a3bU), BSWAP_32BIG_C(0x55dcbb6eU), BSWAP_32BIG_C(0x39143f0dU), BSWAP_32BIG_C(
                0x171df73cU),
        };
        r_rsip_func101(Param_func057_func101_006);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000bU)
    {
        static const uint32_t Param_func057_func100_008[] =
        {
            BSWAP_32BIG_C(0x9690cf2cU), BSWAP_32BIG_C(0x7bce5c8fU), BSWAP_32BIG_C(0xccb52088U), BSWAP_32BIG_C(
                0x835c8d5eU),
        };
        r_rsip_func100(Param_func057_func100_008);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func062(0, ARG3);
        static const uint32_t Param_func057_func100_009[] =
        {
            BSWAP_32BIG_C(0xf83aee04U), BSWAP_32BIG_C(0x2b223e4dU), BSWAP_32BIG_C(0x5848680cU), BSWAP_32BIG_C(
                0x1b78422cU),
        };
        r_rsip_func100(Param_func057_func100_009);
        r_rsip_func062(8, ARG3);
        static const uint32_t Param_func057_func100_010[] =
        {
            BSWAP_32BIG_C(0x124534cfU), BSWAP_32BIG_C(0xe443f2aeU), BSWAP_32BIG_C(0xc81ffa4cU), BSWAP_32BIG_C(
                0xfcf24872U),
        };
        r_rsip_func100(Param_func057_func100_010);
        r_rsip_func062(16, ARG3);
        static const uint32_t Param_func057_func100_011[] =
        {
            BSWAP_32BIG_C(0xa2ef1772U), BSWAP_32BIG_C(0xe524a4eaU), BSWAP_32BIG_C(0x7d43abf8U), BSWAP_32BIG_C(
                0x92f2280fU),
        };
        r_rsip_func100(Param_func057_func100_011);
        r_rsip_func062(24, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func100_012[] =
        {
            BSWAP_32BIG_C(0xc44d7458U), BSWAP_32BIG_C(0xc3c8b89eU), BSWAP_32BIG_C(0xf6edcc85U), BSWAP_32BIG_C(
                0x87a1a2ffU),
        };
        r_rsip_func100(Param_func057_func100_012);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func061(32, ARG2);
        iLoop = 32 + 32;

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func062(32, ARG3);
        static const uint32_t Param_func057_func100_013[] =
        {
            BSWAP_32BIG_C(0xb03f6da5U), BSWAP_32BIG_C(0x2f58fba3U), BSWAP_32BIG_C(0x9422647eU), BSWAP_32BIG_C(
                0x1efb85c2U),
        };
        r_rsip_func100(Param_func057_func100_013);
        r_rsip_func062(40, ARG3);
        static const uint32_t Param_func057_func100_014[] =
        {
            BSWAP_32BIG_C(0x2acb4987U), BSWAP_32BIG_C(0xf5fbd999U), BSWAP_32BIG_C(0x54b43cdeU), BSWAP_32BIG_C(
                0x495aef0aU),
        };
        r_rsip_func100(Param_func057_func100_014);
        r_rsip_func062(48, ARG3);
        static const uint32_t Param_func057_func100_015[] =
        {
            BSWAP_32BIG_C(0xcd3086c4U), BSWAP_32BIG_C(0x82afd5cdU), BSWAP_32BIG_C(0xd99519e1U), BSWAP_32BIG_C(
                0x4afbc043U),
        };
        r_rsip_func100(Param_func057_func100_015);
        r_rsip_func062(56, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func101_007[] =
        {
            BSWAP_32BIG_C(0xf0420fadU), BSWAP_32BIG_C(0xd2e744eaU), BSWAP_32BIG_C(0xf7e14ea2U), BSWAP_32BIG_C(
                0xd5f37807U),
        };
        r_rsip_func101(Param_func057_func101_007);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000cU)
    {
        static const uint32_t Param_func057_func100_016[] =
        {
            BSWAP_32BIG_C(0x28e8224fU), BSWAP_32BIG_C(0x63d20dfdU), BSWAP_32BIG_C(0x5bdef589U), BSWAP_32BIG_C(
                0xf86b2b83U),
        };
        r_rsip_func100(Param_func057_func100_016);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func065(0, ARG3);
        static const uint32_t Param_func057_func100_017[] =
        {
            BSWAP_32BIG_C(0x97c2b947U), BSWAP_32BIG_C(0x484f0b12U), BSWAP_32BIG_C(0x97a74178U), BSWAP_32BIG_C(
                0x22faac60U),
        };
        r_rsip_func100(Param_func057_func100_017);
        r_rsip_func065(8, ARG3);
        static const uint32_t Param_func057_func100_018[] =
        {
            BSWAP_32BIG_C(0x5a8bcdd1U), BSWAP_32BIG_C(0x8a0e585dU), BSWAP_32BIG_C(0xaf0c9d37U), BSWAP_32BIG_C(
                0x6365655cU),
        };
        r_rsip_func100(Param_func057_func100_018);
        r_rsip_func065(16, ARG3);
        static const uint32_t Param_func057_func100_019[] =
        {
            BSWAP_32BIG_C(0x186833fbU), BSWAP_32BIG_C(0xa8bf2705U), BSWAP_32BIG_C(0x813b7c1aU), BSWAP_32BIG_C(
                0x60a1ee73U),
        };
        r_rsip_func100(Param_func057_func100_019);
        r_rsip_func065(24, ARG3);
        static const uint32_t Param_func057_func100_020[] =
        {
            BSWAP_32BIG_C(0xf315072aU), BSWAP_32BIG_C(0x8300d795U), BSWAP_32BIG_C(0xe9258088U), BSWAP_32BIG_C(
                0x05c8fb87U),
        };
        r_rsip_func100(Param_func057_func100_020);
        r_rsip_func065(32, ARG3);
        static const uint32_t Param_func057_func100_021[] =
        {
            BSWAP_32BIG_C(0x6c359d20U), BSWAP_32BIG_C(0x92180d08U), BSWAP_32BIG_C(0x560dc733U), BSWAP_32BIG_C(
                0x793a44f6U),
        };
        r_rsip_func100(Param_func057_func100_021);
        r_rsip_func065(40, ARG3);
        static const uint32_t Param_func057_func100_022[] =
        {
            BSWAP_32BIG_C(0xd5fcd702U), BSWAP_32BIG_C(0x79e33f9aU), BSWAP_32BIG_C(0xbc282de2U), BSWAP_32BIG_C(
                0x90183566U),
        };
        r_rsip_func100(Param_func057_func100_022);
        r_rsip_func065(48, ARG3);
        static const uint32_t Param_func057_func100_023[] =
        {
            BSWAP_32BIG_C(0x7a92f74aU), BSWAP_32BIG_C(0x52470de2U), BSWAP_32BIG_C(0x50d493bbU), BSWAP_32BIG_C(
                0x03e04151U),
        };
        r_rsip_func100(Param_func057_func100_023);
        r_rsip_func065(56, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func100_024[] =
        {
            BSWAP_32BIG_C(0xd11d182bU), BSWAP_32BIG_C(0xb071b621U), BSWAP_32BIG_C(0xa8f29e62U), BSWAP_32BIG_C(
                0x7ab7d5e2U),
        };
        r_rsip_func100(Param_func057_func100_024);
        r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
        WR4_ADDR(REG_1420H, &ARG2[iLoop]);
        iLoop = iLoop + 4;

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);
        oLoop = oLoop + 4;

        WAIT_STS(REG_1A28H, 6, 0);

        static const uint32_t Param_func057_func101_008[] =
        {
            BSWAP_32BIG_C(0xac19009bU), BSWAP_32BIG_C(0xf87b8294U), BSWAP_32BIG_C(0x50d45fe1U), BSWAP_32BIG_C(
                0xec9f2329U),
        };
        r_rsip_func101(Param_func057_func101_008);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000dU)
    {
        static const uint32_t Param_func057_func100_025[] =
        {
            BSWAP_32BIG_C(0xad6e80b8U), BSWAP_32BIG_C(0x0fa2d1bfU), BSWAP_32BIG_C(0xe445bb5aU), BSWAP_32BIG_C(
                0xb1c7d229U),
        };
        r_rsip_func100(Param_func057_func100_025);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func062(0, ARG3);
        static const uint32_t Param_func057_func100_026[] =
        {
            BSWAP_32BIG_C(0xdab49857U), BSWAP_32BIG_C(0x7718798fU), BSWAP_32BIG_C(0xe14af5e9U), BSWAP_32BIG_C(
                0x8a3d02e9U),
        };
        r_rsip_func100(Param_func057_func100_026);
        r_rsip_func062(8, ARG3);
        static const uint32_t Param_func057_func100_027[] =
        {
            BSWAP_32BIG_C(0x027d9eb3U), BSWAP_32BIG_C(0xb4bfad26U), BSWAP_32BIG_C(0xa58cff45U), BSWAP_32BIG_C(
                0x939ac84cU),
        };
        r_rsip_func100(Param_func057_func100_027);
        r_rsip_func062(16, ARG3);
        static const uint32_t Param_func057_func100_028[] =
        {
            BSWAP_32BIG_C(0xbbfaf311U), BSWAP_32BIG_C(0x92ee6a2fU), BSWAP_32BIG_C(0xe3d82256U), BSWAP_32BIG_C(
                0x8ecfbaa9U),
        };
        r_rsip_func100(Param_func057_func100_028);
        r_rsip_func062(24, ARG3);
        static const uint32_t Param_func057_func100_029[] =
        {
            BSWAP_32BIG_C(0x2021b03cU), BSWAP_32BIG_C(0x195766e1U), BSWAP_32BIG_C(0x88c6535dU), BSWAP_32BIG_C(
                0x5ec43fd9U),
        };
        r_rsip_func100(Param_func057_func100_029);
        r_rsip_func062(32, ARG3);
        static const uint32_t Param_func057_func100_030[] =
        {
            BSWAP_32BIG_C(0x4788bc1aU), BSWAP_32BIG_C(0x580f048dU), BSWAP_32BIG_C(0x7f3d5b5fU), BSWAP_32BIG_C(
                0xaebe64c4U),
        };
        r_rsip_func100(Param_func057_func100_030);
        r_rsip_func062(40, ARG3);
        static const uint32_t Param_func057_func100_031[] =
        {
            BSWAP_32BIG_C(0x97959b92U), BSWAP_32BIG_C(0x2f308f5aU), BSWAP_32BIG_C(0x4b48d814U), BSWAP_32BIG_C(
                0xda49080aU),
        };
        r_rsip_func100(Param_func057_func100_031);
        r_rsip_func062(48, ARG3);
        static const uint32_t Param_func057_func100_032[] =
        {
            BSWAP_32BIG_C(0x790137f4U), BSWAP_32BIG_C(0xdf8fdb4aU), BSWAP_32BIG_C(0x72d57a72U), BSWAP_32BIG_C(
                0x6f3a69c8U),
        };
        r_rsip_func100(Param_func057_func100_032);
        r_rsip_func062(56, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func100_033[] =
        {
            BSWAP_32BIG_C(0x01dc96e0U), BSWAP_32BIG_C(0x063094d5U), BSWAP_32BIG_C(0x28d2a8a9U), BSWAP_32BIG_C(
                0xf82bf24aU),
        };
        r_rsip_func100(Param_func057_func100_033);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func063(64, ARG2);
        iLoop = 64 + 64;

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func062(64, ARG3);
        static const uint32_t Param_func057_func100_034[] =
        {
            BSWAP_32BIG_C(0x8ea0e088U), BSWAP_32BIG_C(0x90b980c7U), BSWAP_32BIG_C(0x1a00697fU), BSWAP_32BIG_C(
                0x04d70a97U),
        };
        r_rsip_func100(Param_func057_func100_034);
        r_rsip_func062(72, ARG3);
        static const uint32_t Param_func057_func100_035[] =
        {
            BSWAP_32BIG_C(0x0b7474afU), BSWAP_32BIG_C(0x6bd14713U), BSWAP_32BIG_C(0x1bc8ba7eU), BSWAP_32BIG_C(
                0xb140ac37U),
        };
        r_rsip_func100(Param_func057_func100_035);
        r_rsip_func062(80, ARG3);
        static const uint32_t Param_func057_func100_036[] =
        {
            BSWAP_32BIG_C(0xb5482b2cU), BSWAP_32BIG_C(0x684ae3bdU), BSWAP_32BIG_C(0xb09e4fdcU), BSWAP_32BIG_C(
                0xb24eb9ebU),
        };
        r_rsip_func100(Param_func057_func100_036);
        r_rsip_func062(88, ARG3);
        static const uint32_t Param_func057_func100_037[] =
        {
            BSWAP_32BIG_C(0x78d066eaU), BSWAP_32BIG_C(0xe71d7d67U), BSWAP_32BIG_C(0xd8af340eU), BSWAP_32BIG_C(
                0xf32bb617U),
        };
        r_rsip_func100(Param_func057_func100_037);
        r_rsip_func062(96, ARG3);
        static const uint32_t Param_func057_func100_038[] =
        {
            BSWAP_32BIG_C(0xa8de069cU), BSWAP_32BIG_C(0x4e9fc512U), BSWAP_32BIG_C(0x541b99fbU), BSWAP_32BIG_C(
                0x38eb7b59U),
        };
        r_rsip_func100(Param_func057_func100_038);
        r_rsip_func062(104, ARG3);
        static const uint32_t Param_func057_func100_039[] =
        {
            BSWAP_32BIG_C(0x27dc1b25U), BSWAP_32BIG_C(0xb4705dd3U), BSWAP_32BIG_C(0x29f7e483U), BSWAP_32BIG_C(
                0x144a2fb5U),
        };
        r_rsip_func100(Param_func057_func100_039);
        r_rsip_func062(112, ARG3);
        static const uint32_t Param_func057_func100_040[] =
        {
            BSWAP_32BIG_C(0x2496bcafU), BSWAP_32BIG_C(0xab036e21U), BSWAP_32BIG_C(0xd3b37848U), BSWAP_32BIG_C(
                0x05d61913U),
        };
        r_rsip_func100(Param_func057_func100_040);
        r_rsip_func062(120, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func101_009[] =
        {
            BSWAP_32BIG_C(0x8ecd93f9U), BSWAP_32BIG_C(0x41535173U), BSWAP_32BIG_C(0xc416675cU), BSWAP_32BIG_C(
                0xa0b1103fU),
        };
        r_rsip_func101(Param_func057_func101_009);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000012U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func057_func100_041[] =
            {
                BSWAP_32BIG_C(0x23f19a7dU), BSWAP_32BIG_C(0x9609f129U), BSWAP_32BIG_C(0x6313ecacU), BSWAP_32BIG_C(
                    0xc36ca68eU),
            };
            r_rsip_func100(Param_func057_func100_041);
            r_rsip_func_sub020(0x000003c1U, 0xd900090dU);
            WR4_ADDR(REG_1420H, &ARG2[iLoop]);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_func_sub001(0x00810011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &ARG3[1 + iLoop]);

            static const uint32_t Param_func057_func101_010[] =
            {
                BSWAP_32BIG_C(0x2fbfac41U), BSWAP_32BIG_C(0xb085fcd4U), BSWAP_32BIG_C(0xdac79525U), BSWAP_32BIG_C(
                    0x3ef0d443U),
            };
            r_rsip_func101(Param_func057_func101_010);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_011[] =
        {
            BSWAP_32BIG_C(0xf9029aadU), BSWAP_32BIG_C(0xdb469de3U), BSWAP_32BIG_C(0x5ade0f46U), BSWAP_32BIG_C(
                0x6ba8e912U),
        };
        r_rsip_func101(Param_func057_func101_011);
    }

    static const uint32_t Param_func057_func100_042[] =
    {
        BSWAP_32BIG_C(0x1f9e302aU), BSWAP_32BIG_C(0x1d48214dU), BSWAP_32BIG_C(0xb463381dU), BSWAP_32BIG_C(0x32afbb34U),
    };
    r_rsip_func100(Param_func057_func100_042);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG3[1 + oLoop]);

    r_rsip_func_sub020(0x000003c1U, 0x0900090dU);
    WR4_ADDR(REG_1420H, &ARG2[iLoop]);

    WR1_PROG(REG_1824H, 0x9c100005U);
    r_rsip_func_sub001(0x00410011U);

    r_rsip_func_sub014(0x00007c1cU, 0x00602000U);
}
