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

rsip_ret_t r_rsip_p47f (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p47f_func101_001[] =
        {
            BSWAP_32BIG_C(0x7c1839bbU), BSWAP_32BIG_C(0xdb1964afU), BSWAP_32BIG_C(0x3b18725cU), BSWAP_32BIG_C(
                0x0c30bfc8U),
        };
        r_rsip_func101(Param_p47f_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p47f_func101_002[] =
        {
            BSWAP_32BIG_C(0x15622c79U), BSWAP_32BIG_C(0xad7a4026U), BSWAP_32BIG_C(0x6da71cb7U), BSWAP_32BIG_C(
                0xdbfc6783U),
        };
        r_rsip_func101(Param_p47f_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p47f_func101_003[] =
        {
            BSWAP_32BIG_C(0xa2326a27U), BSWAP_32BIG_C(0x0864d1d2U), BSWAP_32BIG_C(0x700d8ad2U), BSWAP_32BIG_C(
                0xcef8c280U),
        };
        r_rsip_func101(Param_p47f_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        static const uint32_t Param_p47f_func101_004[] =
        {
            BSWAP_32BIG_C(0x386d4cfeU), BSWAP_32BIG_C(0xac6fd53aU), BSWAP_32BIG_C(0xd3eaf72fU), BSWAP_32BIG_C(
                0xacbbbb20U),
        };
        r_rsip_func101(Param_p47f_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        static const uint32_t Param_p47f_func101_005[] =
        {
            BSWAP_32BIG_C(0xc1cfad39U), BSWAP_32BIG_C(0x54191ceeU), BSWAP_32BIG_C(0xb8d68cc6U), BSWAP_32BIG_C(
                0x77a0a3ceU),
        };
        r_rsip_func101(Param_p47f_func101_005);
    }
    else
    {
        ;
    }

    static const uint32_t Param_p47f_func102_001[] =
    {
        BSWAP_32BIG_C(0xf9c7aeceU), BSWAP_32BIG_C(0xf05b2fb2U), BSWAP_32BIG_C(0x46ea5307U), BSWAP_32BIG_C(0x72377664U),
    };
    r_rsip_func102(Param_p47f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
