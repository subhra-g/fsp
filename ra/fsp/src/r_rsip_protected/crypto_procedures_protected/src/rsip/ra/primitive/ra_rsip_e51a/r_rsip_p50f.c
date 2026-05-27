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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p50f (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p50f_func101_001[] =
        {
            BSWAP_32BIG_C(0x51918b25U), BSWAP_32BIG_C(0x21cb2e29U), BSWAP_32BIG_C(0x5e8bb2eaU), BSWAP_32BIG_C(
                0xa9e46fccU),
        };
        r_rsip_func101(Param_p50f_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p50f_func101_002[] =
        {
            BSWAP_32BIG_C(0x514cac3bU), BSWAP_32BIG_C(0x8d94dd1fU), BSWAP_32BIG_C(0x0fe693a1U), BSWAP_32BIG_C(
                0xce7152ceU),
        };
        r_rsip_func101(Param_p50f_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p50f_func101_003[] =
        {
            BSWAP_32BIG_C(0xa25522a4U), BSWAP_32BIG_C(0x803beb1fU), BSWAP_32BIG_C(0xbf2c1e3bU), BSWAP_32BIG_C(
                0xe7efe428U),
        };
        r_rsip_func101(Param_p50f_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        static const uint32_t Param_p50f_func101_004[] =
        {
            BSWAP_32BIG_C(0xaef7b372U), BSWAP_32BIG_C(0x944d935bU), BSWAP_32BIG_C(0xed52892bU), BSWAP_32BIG_C(
                0xe0d2eb96U),
        };
        r_rsip_func101(Param_p50f_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        static const uint32_t Param_p50f_func101_005[] =
        {
            BSWAP_32BIG_C(0xa8e06244U), BSWAP_32BIG_C(0x868e7c5fU), BSWAP_32BIG_C(0x9888fdedU), BSWAP_32BIG_C(
                0x25ab8c6eU),
        };
        r_rsip_func101(Param_p50f_func101_005);
    }

    static const uint32_t Param_p50f_func102_001[] =
    {
        BSWAP_32BIG_C(0x4380f41aU), BSWAP_32BIG_C(0x6029e898U), BSWAP_32BIG_C(0x61ae0705U), BSWAP_32BIG_C(0xe7be0026U),
    };
    r_rsip_func102(Param_p50f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
