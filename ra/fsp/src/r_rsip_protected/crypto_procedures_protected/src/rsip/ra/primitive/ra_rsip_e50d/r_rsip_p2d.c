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

rsip_ret_t r_rsip_p2d (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000002dU);

    static const uint32_t Param_p2d_func101_001[] =
    {
        BSWAP_32BIG_C(0x4e8a0d28U), BSWAP_32BIG_C(0x7df86047U), BSWAP_32BIG_C(0x39378e07U), BSWAP_32BIG_C(0x0f668eceU),
    };
    r_rsip_func101(Param_p2d_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x800103a0U, 0x0000002dU);

    static const uint32_t Param_p2d_func101_002[] =
    {
        BSWAP_32BIG_C(0xea2a7360U), BSWAP_32BIG_C(0xb832644aU), BSWAP_32BIG_C(0x8bd3e735U), BSWAP_32BIG_C(0x71bd1c17U),
    };
    r_rsip_func101(Param_p2d_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80880001U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p2d_func100_001[] =
    {
        BSWAP_32BIG_C(0x5c371d6bU), BSWAP_32BIG_C(0x598f7b65U), BSWAP_32BIG_C(0x954f2c91U), BSWAP_32BIG_C(0xcf76d7e1U),
    };
    r_rsip_func100(Param_p2d_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2d_func102_001[] =
        {
            BSWAP_32BIG_C(0x27a9c796U), BSWAP_32BIG_C(0xdd07dc91U), BSWAP_32BIG_C(0x146091d3U), BSWAP_32BIG_C(
                0xe0189051U),
        };
        r_rsip_func102(Param_p2d_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x08000c00U, 0x00260000U);

        static const uint32_t Param_p2d_func100_002[] =
        {
            BSWAP_32BIG_C(0x249b1e18U), BSWAP_32BIG_C(0xc23aee99U), BSWAP_32BIG_C(0x55492480U), BSWAP_32BIG_C(
                0x7ccf4245U),
        };
        r_rsip_func100(Param_p2d_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2d_func100_003[] =
            {
                BSWAP_32BIG_C(0xd02508b0U), BSWAP_32BIG_C(0x95436045U), BSWAP_32BIG_C(0xfef873f0U), BSWAP_32BIG_C(
                    0x00c1624aU),
            };
            r_rsip_func100(Param_p2d_func100_003);
            WR1_PROG(REG_1438H, 0x40000100U);

            r_rsip_func_sub023(0x0000b400U, 0x00000001U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2d_func100_004[] =
            {
                BSWAP_32BIG_C(0x16370a0fU), BSWAP_32BIG_C(0xc80c718eU), BSWAP_32BIG_C(0xb82e7ef6U), BSWAP_32BIG_C(
                    0x87ed85afU),
            };
            r_rsip_func100(Param_p2d_func100_004);
            WR1_PROG(REG_1438H, 0x40000110U);

            r_rsip_func_sub001(0x02000009U);

            static const uint32_t Param_p2d_func100_005[] =
            {
                BSWAP_32BIG_C(0x7ff27054U), BSWAP_32BIG_C(0x9be02113U), BSWAP_32BIG_C(0xf4b538c7U), BSWAP_32BIG_C(
                    0x79c7bfdeU),
            };
            r_rsip_func100(Param_p2d_func100_005);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81860001U);
            r_rsip_func_sub001(0x02090019U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2d_func100_006[] =
            {
                BSWAP_32BIG_C(0x19377bd2U), BSWAP_32BIG_C(0x79154159U), BSWAP_32BIG_C(0x8ab341e1U), BSWAP_32BIG_C(
                    0x130d01a7U),
            };
            r_rsip_func100(Param_p2d_func100_006);
            WR1_PROG(REG_1438H, 0x40000140U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2d_func102_002[] =
            {
                BSWAP_32BIG_C(0x88003a27U), BSWAP_32BIG_C(0xa601d7eaU), BSWAP_32BIG_C(0xe5a04a51U), BSWAP_32BIG_C(
                    0xfaf3e5a3U),
            };
            r_rsip_func102(Param_p2d_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
        else
        {
            static const uint32_t Param_p2d_func100_007[] =
            {
                BSWAP_32BIG_C(0x580dfa17U), BSWAP_32BIG_C(0xa91a9d91U), BSWAP_32BIG_C(0x896a419bU), BSWAP_32BIG_C(
                    0x702ce2eeU),
            };
            r_rsip_func100(Param_p2d_func100_007);
            WR1_PROG(REG_1438H, 0x40000180U);

            r_rsip_func_sub023(0x0000b400U, 0x00000001U, 0x81010000U);
            r_rsip_func_sub001(0x02090005U);

            static const uint32_t Param_p2d_func100_008[] =
            {
                BSWAP_32BIG_C(0xab24f488U), BSWAP_32BIG_C(0xd11b1a4eU), BSWAP_32BIG_C(0x7273609aU), BSWAP_32BIG_C(
                    0x5413f429U),
            };
            r_rsip_func100(Param_p2d_func100_008);
            WR1_PROG(REG_1438H, 0x40000190U);

            r_rsip_func_sub001(0x02000009U);

            static const uint32_t Param_p2d_func100_009[] =
            {
                BSWAP_32BIG_C(0xc59891a3U), BSWAP_32BIG_C(0x66af12f8U), BSWAP_32BIG_C(0x990df3e3U), BSWAP_32BIG_C(
                    0x16f4d23eU),
            };
            r_rsip_func100(Param_p2d_func100_009);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81860001U);
            r_rsip_func_sub001(0x02090019U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p2d_func100_010[] =
            {
                BSWAP_32BIG_C(0xf79f9c0fU), BSWAP_32BIG_C(0x8812ea3cU), BSWAP_32BIG_C(0x96840c7eU), BSWAP_32BIG_C(
                    0x3510e8d5U),
            };
            r_rsip_func100(Param_p2d_func100_010);
            WR1_PROG(REG_1438H, 0x400001C0U);

            WR1_PROG(REG_1608H, 0x81020000U);
            r_rsip_func_sub001(0x02090009U);

            static const uint32_t Param_p2d_func102_003[] =
            {
                BSWAP_32BIG_C(0x21acee55U), BSWAP_32BIG_C(0xa4e07934U), BSWAP_32BIG_C(0x4047476dU), BSWAP_32BIG_C(
                    0x2ffb1211U),
            };
            r_rsip_func102(Param_p2d_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
