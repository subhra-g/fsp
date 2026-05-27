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

rsip_ret_t r_rsip_p89f (void)
{
    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p89f_func101_001[] =
        {
            BSWAP_32BIG_C(0xf351fd8fU), BSWAP_32BIG_C(0x5df42a44U), BSWAP_32BIG_C(0x2093f6bdU), BSWAP_32BIG_C(
                0xd54e3977U),
        };
        r_rsip_func101(Param_p89f_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p89f_func101_002[] =
        {
            BSWAP_32BIG_C(0x23d0f905U), BSWAP_32BIG_C(0xec060a28U), BSWAP_32BIG_C(0xba8e4acfU), BSWAP_32BIG_C(
                0xe5aad16cU),
        };
        r_rsip_func101(Param_p89f_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p89f_func101_003[] =
        {
            BSWAP_32BIG_C(0xc0dddca4U), BSWAP_32BIG_C(0xd8384309U), BSWAP_32BIG_C(0x0718c944U), BSWAP_32BIG_C(
                0x53e5c656U),
        };
        r_rsip_func101(Param_p89f_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        static const uint32_t Param_p89f_func101_004[] =
        {
            BSWAP_32BIG_C(0x7410d6eeU), BSWAP_32BIG_C(0xb7e6a471U), BSWAP_32BIG_C(0x6a718631U), BSWAP_32BIG_C(
                0xb48c248dU),
        };
        r_rsip_func101(Param_p89f_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        static const uint32_t Param_p89f_func101_005[] =
        {
            BSWAP_32BIG_C(0x8290ca26U), BSWAP_32BIG_C(0x1dbdd9aaU), BSWAP_32BIG_C(0x9388548dU), BSWAP_32BIG_C(
                0x3532f2a8U),
        };
        r_rsip_func101(Param_p89f_func101_005);
    }
    else
    {
        ;
    }

    static const uint32_t Param_p89f_func102_001[] =
    {
        BSWAP_32BIG_C(0xd97f89a3U), BSWAP_32BIG_C(0xaa23577eU), BSWAP_32BIG_C(0xd6bf1091U), BSWAP_32BIG_C(0xbee3efcaU),
    };
    r_rsip_func102(Param_p89f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
