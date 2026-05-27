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

rsip_ret_t r_rsip_p44i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00440001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00000044U);

    static const uint32_t Param_p44i_func101_001[] =
    {
        BSWAP_32BIG_C(0x0016cdbbU), BSWAP_32BIG_C(0xfadbbf30U), BSWAP_32BIG_C(0x68feffbcU), BSWAP_32BIG_C(0xdc3d84acU),
    };
    r_rsip_func101(Param_p44i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x800103a0U, 0x00000044U);

    static const uint32_t Param_p44i_func101_002[] =
    {
        BSWAP_32BIG_C(0x1f80c1b8U), BSWAP_32BIG_C(0x00d55f14U), BSWAP_32BIG_C(0xf7b6feffU), BSWAP_32BIG_C(0x82d89836U),
    };
    r_rsip_func101(Param_p44i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p44i_func100_001[] =
    {
        BSWAP_32BIG_C(0x9665d5f6U), BSWAP_32BIG_C(0xf62fd705U), BSWAP_32BIG_C(0x346e74b8U), BSWAP_32BIG_C(0x4e2ed0d9U),
    };
    r_rsip_func100(Param_p44i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p44i_func100_002[] =
    {
        BSWAP_32BIG_C(0xb9837ad1U), BSWAP_32BIG_C(0x4ff8f69aU), BSWAP_32BIG_C(0x088aec37U), BSWAP_32BIG_C(0x21123929U),
    };
    r_rsip_func100(Param_p44i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p44i_func100_003[] =
    {
        BSWAP_32BIG_C(0x965f901eU), BSWAP_32BIG_C(0x198bd30fU), BSWAP_32BIG_C(0x79d4c13cU), BSWAP_32BIG_C(0x5496bae5U),
    };
    r_rsip_func100(Param_p44i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p44i_func102_001[] =
        {
            BSWAP_32BIG_C(0xeb453b85U), BSWAP_32BIG_C(0x519547acU), BSWAP_32BIG_C(0x440af007U), BSWAP_32BIG_C(
                0x1aae4ba9U),
        };
        r_rsip_func102(Param_p44i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub020(0x000000a1U, 0x08000044U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        return RSIP_RET_PASS;
    }
}
