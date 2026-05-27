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

    r_rsip_func_sub003(0x800103a0U, 0x0000f057U);

    static const uint32_t Param_func057_func101_001[] =
    {
        BSWAP_32BIG_C(0x05928519U), BSWAP_32BIG_C(0x20094bedU), BSWAP_32BIG_C(0x9dd3a61dU), BSWAP_32BIG_C(0x5a94f15eU),
    };
    r_rsip_func101(Param_func057_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000f057U);

    static const uint32_t Param_func057_func101_002[] =
    {
        BSWAP_32BIG_C(0x047b8036U), BSWAP_32BIG_C(0x7c5e5c6bU), BSWAP_32BIG_C(0x832415beU), BSWAP_32BIG_C(0xed194874U),
    };
    r_rsip_func101(Param_func057_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub003(0x800103a0U, 0x0000f057U);

    static const uint32_t Param_func057_func101_003[] =
    {
        BSWAP_32BIG_C(0xa01f135eU), BSWAP_32BIG_C(0x12c1c002U), BSWAP_32BIG_C(0x0b85c594U), BSWAP_32BIG_C(0xb65d0f93U),
    };
    r_rsip_func101(Param_func057_func101_003);
    r_rsip_func044();

    static const uint32_t Param_func057_func100_001[] =
    {
        BSWAP_32BIG_C(0xd2608f9eU), BSWAP_32BIG_C(0x4886fa97U), BSWAP_32BIG_C(0x55af3a4fU), BSWAP_32BIG_C(0xd9491aa7U),
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
                BSWAP_32BIG_C(0xbf80b81dU), BSWAP_32BIG_C(0xb49dc26bU), BSWAP_32BIG_C(0x1c9ffc1dU), BSWAP_32BIG_C(
                    0x75b6f2c3U),
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
                BSWAP_32BIG_C(0xda21911eU), BSWAP_32BIG_C(0xf50d2c16U), BSWAP_32BIG_C(0xb00b6635U), BSWAP_32BIG_C(
                    0x79d708b3U),
            };
            r_rsip_func101(Param_func057_func101_004);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_005[] =
        {
            BSWAP_32BIG_C(0x9cfede43U), BSWAP_32BIG_C(0x8ac80985U), BSWAP_32BIG_C(0xeef73c0fU), BSWAP_32BIG_C(
                0x3901dda8U),
        };
        r_rsip_func101(Param_func057_func101_005);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000aU)
    {
        static const uint32_t Param_func057_func100_003[] =
        {
            BSWAP_32BIG_C(0x150572b9U), BSWAP_32BIG_C(0x48f45375U), BSWAP_32BIG_C(0xc194bd6bU), BSWAP_32BIG_C(
                0xe6db849dU),
        };
        r_rsip_func100(Param_func057_func100_003);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func065(0, ARG3);
        static const uint32_t Param_func057_func100_004[] =
        {
            BSWAP_32BIG_C(0x398ab511U), BSWAP_32BIG_C(0x602d4166U), BSWAP_32BIG_C(0x68ead4bbU), BSWAP_32BIG_C(
                0x0fc4a985U),
        };
        r_rsip_func100(Param_func057_func100_004);
        r_rsip_func065(8, ARG3);
        static const uint32_t Param_func057_func100_005[] =
        {
            BSWAP_32BIG_C(0x6e591599U), BSWAP_32BIG_C(0x0d2dd6b9U), BSWAP_32BIG_C(0x9276a780U), BSWAP_32BIG_C(
                0xbcaf7878U),
        };
        r_rsip_func100(Param_func057_func100_005);
        r_rsip_func065(16, ARG3);
        static const uint32_t Param_func057_func100_006[] =
        {
            BSWAP_32BIG_C(0x46346c99U), BSWAP_32BIG_C(0xc60cb693U), BSWAP_32BIG_C(0x1ff45009U), BSWAP_32BIG_C(
                0xae407f66U),
        };
        r_rsip_func100(Param_func057_func100_006);
        r_rsip_func065(24, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func100_007[] =
        {
            BSWAP_32BIG_C(0xed57b357U), BSWAP_32BIG_C(0xd33820b2U), BSWAP_32BIG_C(0x5bf191e9U), BSWAP_32BIG_C(
                0x315b7b7cU),
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
            BSWAP_32BIG_C(0xa1fe1c1fU), BSWAP_32BIG_C(0x2100b6adU), BSWAP_32BIG_C(0xc87ff293U), BSWAP_32BIG_C(
                0x061b72c1U),
        };
        r_rsip_func101(Param_func057_func101_006);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000bU)
    {
        static const uint32_t Param_func057_func100_008[] =
        {
            BSWAP_32BIG_C(0x8c70ed9eU), BSWAP_32BIG_C(0xf42dddfbU), BSWAP_32BIG_C(0xe495fbe3U), BSWAP_32BIG_C(
                0xc971da9fU),
        };
        r_rsip_func100(Param_func057_func100_008);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func061(0, ARG2);
        iLoop = 0 + 32;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func062(0, ARG3);
        static const uint32_t Param_func057_func100_009[] =
        {
            BSWAP_32BIG_C(0xc9641802U), BSWAP_32BIG_C(0x00ac89a1U), BSWAP_32BIG_C(0xb9a8ec70U), BSWAP_32BIG_C(
                0xda145a34U),
        };
        r_rsip_func100(Param_func057_func100_009);
        r_rsip_func062(8, ARG3);
        static const uint32_t Param_func057_func100_010[] =
        {
            BSWAP_32BIG_C(0x9aba046dU), BSWAP_32BIG_C(0x9d2a8436U), BSWAP_32BIG_C(0x0bf507eaU), BSWAP_32BIG_C(
                0xb3e81cbaU),
        };
        r_rsip_func100(Param_func057_func100_010);
        r_rsip_func062(16, ARG3);
        static const uint32_t Param_func057_func100_011[] =
        {
            BSWAP_32BIG_C(0x61fdb98fU), BSWAP_32BIG_C(0x506eef14U), BSWAP_32BIG_C(0x184c21e9U), BSWAP_32BIG_C(
                0xb75e2015U),
        };
        r_rsip_func100(Param_func057_func100_011);
        r_rsip_func062(24, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func100_012[] =
        {
            BSWAP_32BIG_C(0xc801a945U), BSWAP_32BIG_C(0x3cc840f6U), BSWAP_32BIG_C(0xd48af6baU), BSWAP_32BIG_C(
                0x33a62bd9U),
        };
        r_rsip_func100(Param_func057_func100_012);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func061(32, ARG2);
        iLoop = 32 + 32;

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func062(32, ARG3);
        static const uint32_t Param_func057_func100_013[] =
        {
            BSWAP_32BIG_C(0xe05c8e3aU), BSWAP_32BIG_C(0x6a68d6d8U), BSWAP_32BIG_C(0x64ca9c9eU), BSWAP_32BIG_C(
                0x70a6e4b4U),
        };
        r_rsip_func100(Param_func057_func100_013);
        r_rsip_func062(40, ARG3);
        static const uint32_t Param_func057_func100_014[] =
        {
            BSWAP_32BIG_C(0x9bdc7900U), BSWAP_32BIG_C(0xb9deedf1U), BSWAP_32BIG_C(0xcc0b3be2U), BSWAP_32BIG_C(
                0xeffe3cedU),
        };
        r_rsip_func100(Param_func057_func100_014);
        r_rsip_func062(48, ARG3);
        static const uint32_t Param_func057_func100_015[] =
        {
            BSWAP_32BIG_C(0xf6b7af28U), BSWAP_32BIG_C(0x70655a28U), BSWAP_32BIG_C(0x9128575eU), BSWAP_32BIG_C(
                0x0922e1d1U),
        };
        r_rsip_func100(Param_func057_func100_015);
        r_rsip_func062(56, ARG3);
        oLoop = oLoop + 32;

        static const uint32_t Param_func057_func101_007[] =
        {
            BSWAP_32BIG_C(0xd7efec02U), BSWAP_32BIG_C(0x841e87dbU), BSWAP_32BIG_C(0x06202a19U), BSWAP_32BIG_C(
                0x37b43f49U),
        };
        r_rsip_func101(Param_func057_func101_007);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000cU)
    {
        static const uint32_t Param_func057_func100_016[] =
        {
            BSWAP_32BIG_C(0x47de726cU), BSWAP_32BIG_C(0xa6dee9b2U), BSWAP_32BIG_C(0x72b063a1U), BSWAP_32BIG_C(
                0x95a259eeU),
        };
        r_rsip_func100(Param_func057_func100_016);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func065(0, ARG3);
        static const uint32_t Param_func057_func100_017[] =
        {
            BSWAP_32BIG_C(0xba068bdbU), BSWAP_32BIG_C(0x66a84f79U), BSWAP_32BIG_C(0xf8b0e95eU), BSWAP_32BIG_C(
                0xcedfd98aU),
        };
        r_rsip_func100(Param_func057_func100_017);
        r_rsip_func065(8, ARG3);
        static const uint32_t Param_func057_func100_018[] =
        {
            BSWAP_32BIG_C(0x15e48f0eU), BSWAP_32BIG_C(0x42c76939U), BSWAP_32BIG_C(0x10c79334U), BSWAP_32BIG_C(
                0x3b815ba2U),
        };
        r_rsip_func100(Param_func057_func100_018);
        r_rsip_func065(16, ARG3);
        static const uint32_t Param_func057_func100_019[] =
        {
            BSWAP_32BIG_C(0xda54e7e5U), BSWAP_32BIG_C(0x2849139fU), BSWAP_32BIG_C(0x78b77f18U), BSWAP_32BIG_C(
                0xc00cc35dU),
        };
        r_rsip_func100(Param_func057_func100_019);
        r_rsip_func065(24, ARG3);
        static const uint32_t Param_func057_func100_020[] =
        {
            BSWAP_32BIG_C(0xfe669854U), BSWAP_32BIG_C(0x71a50a49U), BSWAP_32BIG_C(0x98344956U), BSWAP_32BIG_C(
                0xd67ad222U),
        };
        r_rsip_func100(Param_func057_func100_020);
        r_rsip_func065(32, ARG3);
        static const uint32_t Param_func057_func100_021[] =
        {
            BSWAP_32BIG_C(0x4935e3c9U), BSWAP_32BIG_C(0xb0f822eaU), BSWAP_32BIG_C(0x74035f4bU), BSWAP_32BIG_C(
                0xb3d43a33U),
        };
        r_rsip_func100(Param_func057_func100_021);
        r_rsip_func065(40, ARG3);
        static const uint32_t Param_func057_func100_022[] =
        {
            BSWAP_32BIG_C(0x6455554aU), BSWAP_32BIG_C(0x47190422U), BSWAP_32BIG_C(0x26321c11U), BSWAP_32BIG_C(
                0x79fcabdfU),
        };
        r_rsip_func100(Param_func057_func100_022);
        r_rsip_func065(48, ARG3);
        static const uint32_t Param_func057_func100_023[] =
        {
            BSWAP_32BIG_C(0xa7a96803U), BSWAP_32BIG_C(0x4aefbbabU), BSWAP_32BIG_C(0xbd210542U), BSWAP_32BIG_C(
                0x471f1e80U),
        };
        r_rsip_func100(Param_func057_func100_023);
        r_rsip_func065(56, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func100_024[] =
        {
            BSWAP_32BIG_C(0x1e4c69cbU), BSWAP_32BIG_C(0xc3e7a4afU), BSWAP_32BIG_C(0x929cbd10U), BSWAP_32BIG_C(
                0xb26d656eU),
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
            BSWAP_32BIG_C(0x671e2dceU), BSWAP_32BIG_C(0xac551ddbU), BSWAP_32BIG_C(0xd9896b23U), BSWAP_32BIG_C(
                0x818b22a6U),
        };
        r_rsip_func101(Param_func057_func101_008);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x0000000dU)
    {
        static const uint32_t Param_func057_func100_025[] =
        {
            BSWAP_32BIG_C(0xed7f8e1eU), BSWAP_32BIG_C(0x24435c5fU), BSWAP_32BIG_C(0x59b7f50aU), BSWAP_32BIG_C(
                0x39af12e5U),
        };
        r_rsip_func100(Param_func057_func100_025);
        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func063(0, ARG2);
        iLoop = 0 + 64;

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func062(0, ARG3);
        static const uint32_t Param_func057_func100_026[] =
        {
            BSWAP_32BIG_C(0x6dd8b3bcU), BSWAP_32BIG_C(0x3372df63U), BSWAP_32BIG_C(0xc8973630U), BSWAP_32BIG_C(
                0x0b17f7a0U),
        };
        r_rsip_func100(Param_func057_func100_026);
        r_rsip_func062(8, ARG3);
        static const uint32_t Param_func057_func100_027[] =
        {
            BSWAP_32BIG_C(0x81a93426U), BSWAP_32BIG_C(0xd39e0dacU), BSWAP_32BIG_C(0x5bd00fa6U), BSWAP_32BIG_C(
                0x3123e53fU),
        };
        r_rsip_func100(Param_func057_func100_027);
        r_rsip_func062(16, ARG3);
        static const uint32_t Param_func057_func100_028[] =
        {
            BSWAP_32BIG_C(0xb8559b20U), BSWAP_32BIG_C(0x20f50a96U), BSWAP_32BIG_C(0x7992234aU), BSWAP_32BIG_C(
                0x79a04fa6U),
        };
        r_rsip_func100(Param_func057_func100_028);
        r_rsip_func062(24, ARG3);
        static const uint32_t Param_func057_func100_029[] =
        {
            BSWAP_32BIG_C(0x14e7cd11U), BSWAP_32BIG_C(0x2e9ac7d2U), BSWAP_32BIG_C(0x323a8b34U), BSWAP_32BIG_C(
                0x74e36f3fU),
        };
        r_rsip_func100(Param_func057_func100_029);
        r_rsip_func062(32, ARG3);
        static const uint32_t Param_func057_func100_030[] =
        {
            BSWAP_32BIG_C(0x7d025c31U), BSWAP_32BIG_C(0x2cc01853U), BSWAP_32BIG_C(0x86654d27U), BSWAP_32BIG_C(
                0x84cd49e2U),
        };
        r_rsip_func100(Param_func057_func100_030);
        r_rsip_func062(40, ARG3);
        static const uint32_t Param_func057_func100_031[] =
        {
            BSWAP_32BIG_C(0xcd040c39U), BSWAP_32BIG_C(0x8d5def42U), BSWAP_32BIG_C(0x3c48b5deU), BSWAP_32BIG_C(
                0x9ad1f2c7U),
        };
        r_rsip_func100(Param_func057_func100_031);
        r_rsip_func062(48, ARG3);
        static const uint32_t Param_func057_func100_032[] =
        {
            BSWAP_32BIG_C(0x6e293d03U), BSWAP_32BIG_C(0xc9e5f72dU), BSWAP_32BIG_C(0x9d5c526eU), BSWAP_32BIG_C(
                0x9ce44f62U),
        };
        r_rsip_func100(Param_func057_func100_032);
        r_rsip_func062(56, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func100_033[] =
        {
            BSWAP_32BIG_C(0x2befc839U), BSWAP_32BIG_C(0x1a798025U), BSWAP_32BIG_C(0x13f9e14bU), BSWAP_32BIG_C(
                0x6527a540U),
        };
        r_rsip_func100(Param_func057_func100_033);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func063(64, ARG2);
        iLoop = 64 + 64;

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func062(64, ARG3);
        static const uint32_t Param_func057_func100_034[] =
        {
            BSWAP_32BIG_C(0x50cd8871U), BSWAP_32BIG_C(0x3e593c23U), BSWAP_32BIG_C(0x8757cb46U), BSWAP_32BIG_C(
                0x10f26ffcU),
        };
        r_rsip_func100(Param_func057_func100_034);
        r_rsip_func062(72, ARG3);
        static const uint32_t Param_func057_func100_035[] =
        {
            BSWAP_32BIG_C(0x6db0f5c7U), BSWAP_32BIG_C(0x4a247f08U), BSWAP_32BIG_C(0x0a8ebedfU), BSWAP_32BIG_C(
                0x6ce6f427U),
        };
        r_rsip_func100(Param_func057_func100_035);
        r_rsip_func062(80, ARG3);
        static const uint32_t Param_func057_func100_036[] =
        {
            BSWAP_32BIG_C(0xb06632edU), BSWAP_32BIG_C(0x4a2cf9d7U), BSWAP_32BIG_C(0x143a529aU), BSWAP_32BIG_C(
                0x883f3c9aU),
        };
        r_rsip_func100(Param_func057_func100_036);
        r_rsip_func062(88, ARG3);
        static const uint32_t Param_func057_func100_037[] =
        {
            BSWAP_32BIG_C(0x34bca1f3U), BSWAP_32BIG_C(0x77f3d10eU), BSWAP_32BIG_C(0x06274830U), BSWAP_32BIG_C(
                0x727c36f2U),
        };
        r_rsip_func100(Param_func057_func100_037);
        r_rsip_func062(96, ARG3);
        static const uint32_t Param_func057_func100_038[] =
        {
            BSWAP_32BIG_C(0xde18381dU), BSWAP_32BIG_C(0xf43f501aU), BSWAP_32BIG_C(0x96fa69aaU), BSWAP_32BIG_C(
                0xa30bf1d2U),
        };
        r_rsip_func100(Param_func057_func100_038);
        r_rsip_func062(104, ARG3);
        static const uint32_t Param_func057_func100_039[] =
        {
            BSWAP_32BIG_C(0x67f08f76U), BSWAP_32BIG_C(0xb0287bc7U), BSWAP_32BIG_C(0x7eb6f3d5U), BSWAP_32BIG_C(
                0x6fb4767eU),
        };
        r_rsip_func100(Param_func057_func100_039);
        r_rsip_func062(112, ARG3);
        static const uint32_t Param_func057_func100_040[] =
        {
            BSWAP_32BIG_C(0x5ff06c0dU), BSWAP_32BIG_C(0x563e6f81U), BSWAP_32BIG_C(0x24d5b9eeU), BSWAP_32BIG_C(
                0x5a074decU),
        };
        r_rsip_func100(Param_func057_func100_040);
        r_rsip_func062(120, ARG3);
        oLoop = oLoop + 64;

        static const uint32_t Param_func057_func101_009[] =
        {
            BSWAP_32BIG_C(0x46ab8325U), BSWAP_32BIG_C(0x9c01dad2U), BSWAP_32BIG_C(0x2532aa6bU), BSWAP_32BIG_C(
                0x103d03c1U),
        };
        r_rsip_func101(Param_func057_func101_009);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000012U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func057_func100_041[] =
            {
                BSWAP_32BIG_C(0xc06a8edcU), BSWAP_32BIG_C(0x81a935f4U), BSWAP_32BIG_C(0x884cf091U), BSWAP_32BIG_C(
                    0xd567a945U),
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
                BSWAP_32BIG_C(0x1b5d88f7U), BSWAP_32BIG_C(0x5828431fU), BSWAP_32BIG_C(0xfbebfa48U), BSWAP_32BIG_C(
                    0xfb980a41U),
            };
            r_rsip_func101(Param_func057_func101_010);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        oLoop = iLoop;

        static const uint32_t Param_func057_func101_011[] =
        {
            BSWAP_32BIG_C(0x1120c04fU), BSWAP_32BIG_C(0xd488e3feU), BSWAP_32BIG_C(0x07be0ab5U), BSWAP_32BIG_C(
                0xd3f7d314U),
        };
        r_rsip_func101(Param_func057_func101_011);
    }

    static const uint32_t Param_func057_func100_042[] =
    {
        BSWAP_32BIG_C(0xf0352fcbU), BSWAP_32BIG_C(0xe5efed4fU), BSWAP_32BIG_C(0x35a3d684U), BSWAP_32BIG_C(0x51b209baU),
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
