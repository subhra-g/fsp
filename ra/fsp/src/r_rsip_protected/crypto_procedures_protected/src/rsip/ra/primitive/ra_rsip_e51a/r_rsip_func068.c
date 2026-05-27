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

void r_rsip_func068 (void)
{
    static const uint32_t Param_func068_func100_001[] =
    {
        BSWAP_32BIG_C(0x89a4702aU), BSWAP_32BIG_C(0x860ade94U), BSWAP_32BIG_C(0xcfb8875fU), BSWAP_32BIG_C(0x57ea3022U),
    };
    r_rsip_func100(Param_func068_func100_001);
    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x01000000U);

    r_rsip_func_sub004(0x4a060044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e060084U);
    WR1_PROG(REG_1608H, 0x81010140U);
    r_rsip_func_sub001(0x00890005U);

    static const uint32_t Param_func068_func100_002[] =
    {
        BSWAP_32BIG_C(0x3cabdf26U), BSWAP_32BIG_C(0xb8c6a487U), BSWAP_32BIG_C(0x7c30475fU), BSWAP_32BIG_C(0x1864f5d9U),
    };
    r_rsip_func100(Param_func068_func100_002);
    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x02000000U);

    WR1_PROG(REG_1A24H, 0x0e060094U);
    WR1_PROG(REG_1608H, 0x81010140U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
