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

void r_rsip_func441 (const uint32_t ARG1[])
{
    WR1_PROG(REG_0094H, 0x00003467U);

    static const uint32_t Param_func441_sub100_001[] =
    {
        BSWAP_32BIG_C(0x00000441U), BSWAP_32BIG_C(0xfbab3793U), BSWAP_32BIG_C(0x7baa8fceU),
        BSWAP_32BIG_C(0xd6238c71U),
        BSWAP_32BIG_C(0x8ccbf2c0U), BSWAP_32BIG_C(0x00000441U), BSWAP_32BIG_C(0xe2126eafU),
        BSWAP_32BIG_C(0xf3f802c4U),
        BSWAP_32BIG_C(0xe4e20346U),
        BSWAP_32BIG_C(0xc7b048faU), 0x0000141eU,
    };
    r_rsip_func_sub100(ARG1, Param_func441_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
