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

rsip_ret_t r_rsip_p2d (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
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

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002dU);

    static const uint32_t Param_p2d_func101_001[] =
    {
        BSWAP_32BIG_C(0x4e8a0d28U), BSWAP_32BIG_C(0x7df86047U), BSWAP_32BIG_C(0x39378e07U), BSWAP_32BIG_C(0x0f668eceU),
    };
    r_rsip_func101(Param_p2d_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002dU);

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
        static const uint32_t Param_p2d_func100_002[] =
        {
            BSWAP_32BIG_C(0x82bd954dU), BSWAP_32BIG_C(0xbc85b76fU), BSWAP_32BIG_C(0xbccc8fd9U), BSWAP_32BIG_C(
                0x54f187edU),
        };
        r_rsip_func100(Param_p2d_func100_002);
        WR1_PROG(REG_1438H, 0x40000100U);

        r_rsip_func_sub026(0x0000b400U, 0x00000001U, 0x81010000U);
        r_rsip_func_sub001(0x02090005U);

        static const uint32_t Param_p2d_func100_003[] =
        {
            BSWAP_32BIG_C(0xc75c0d1dU), BSWAP_32BIG_C(0x44eb94ddU), BSWAP_32BIG_C(0x376cee07U), BSWAP_32BIG_C(
                0x30ef5860U),
        };
        r_rsip_func100(Param_p2d_func100_003);
        WR1_PROG(REG_1438H, 0x40000110U);

        r_rsip_func_sub001(0x02000009U);

        static const uint32_t Param_p2d_func100_004[] =
        {
            BSWAP_32BIG_C(0x107f17fdU), BSWAP_32BIG_C(0x71037facU), BSWAP_32BIG_C(0x2f457a30U), BSWAP_32BIG_C(
                0x1534de24U),
        };
        r_rsip_func100(Param_p2d_func100_004);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81860001U);
        r_rsip_func_sub001(0x02090019U);

        r_rsip_func_sub010(0x000001c7U, 0x80020000U);
        WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p2d_func100_005[] =
        {
            BSWAP_32BIG_C(0xd47ef471U), BSWAP_32BIG_C(0x8b4a5e6eU), BSWAP_32BIG_C(0xe21d68e5U), BSWAP_32BIG_C(
                0x4dbd369aU),
        };
        r_rsip_func100(Param_p2d_func100_005);
        WR1_PROG(REG_1438H, 0x40000140U);

        WR1_PROG(REG_1608H, 0x81020000U);
        r_rsip_func_sub001(0x02090009U);

        static const uint32_t Param_p2d_func102_002[] =
        {
            BSWAP_32BIG_C(0xc7398015U), BSWAP_32BIG_C(0xd0763bc5U), BSWAP_32BIG_C(0xa42bcf4fU), BSWAP_32BIG_C(
                0xc68025deU),
        };
        r_rsip_func102(Param_p2d_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
