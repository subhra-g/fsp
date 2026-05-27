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

rsip_ret_t r_rsip_p96r (const uint32_t InData_KeyIndex[], const uint32_t InData_Nonce[], const uint32_t InData_State[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00960001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    static const uint32_t Param_p96r_func100_001[] =
    {
        BSWAP_32BIG_C(0xb6d51d17U), BSWAP_32BIG_C(0x6c9791f9U), BSWAP_32BIG_C(0xee32699bU), BSWAP_32BIG_C(0x20f69d81U),
    };
    r_rsip_func100(Param_p96r_func100_001);
    WR1_PROG(REG_1C00H, 0x00000001U);

    WR1_PROG(REG_1C04H, 0x00001001U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00009602U);

    static const uint32_t Param_p96r_func101_001[] =
    {
        BSWAP_32BIG_C(0x3e38d406U), BSWAP_32BIG_C(0x82f508fdU), BSWAP_32BIG_C(0x28235048U), BSWAP_32BIG_C(0x8e3818edU),
    };
    r_rsip_func101(Param_p96r_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000030U);

    r_rsip_func_sub003(0x800103a0U, 0x00009602U);

    static const uint32_t Param_p96r_func101_002[] =
    {
        BSWAP_32BIG_C(0xf1e7c7c8U), BSWAP_32BIG_C(0xb7c0bce6U), BSWAP_32BIG_C(0x265b4402U), BSWAP_32BIG_C(0x93c5dc36U),
    };
    r_rsip_func101(Param_p96r_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    r_rsip_func_sub001(0x01c20021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p96r_func100_002[] =
    {
        BSWAP_32BIG_C(0xc8d375fbU), BSWAP_32BIG_C(0x03c6107aU), BSWAP_32BIG_C(0x03f0f178U), BSWAP_32BIG_C(0x8a9ccb26U),
    };
    r_rsip_func100(Param_p96r_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p96r_func102_001[] =
        {
            BSWAP_32BIG_C(0x5c0a1da3U), BSWAP_32BIG_C(0x7a7ade8eU), BSWAP_32BIG_C(0x3403fa36U), BSWAP_32BIG_C(
                0x493be09dU),
        };
        r_rsip_func102(Param_p96r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C10H, InData_State[1]);

        WR1_PROG(REG_1C04H, 0x00000000U);

        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C08H, InData_State[0]);

        WR1_PROG(REG_1C04H, 0x00000001U);

        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[1]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_1C0CH, InData_Nonce[2]);

        static const uint32_t Param_p96r_func101_003[] =
        {
            BSWAP_32BIG_C(0x3e151f92U), BSWAP_32BIG_C(0x97749da3U), BSWAP_32BIG_C(0x904c4f00U), BSWAP_32BIG_C(
                0xf8adde68U),
        };
        r_rsip_func101(Param_p96r_func101_003);

        return RSIP_RET_PASS;
    }
}
