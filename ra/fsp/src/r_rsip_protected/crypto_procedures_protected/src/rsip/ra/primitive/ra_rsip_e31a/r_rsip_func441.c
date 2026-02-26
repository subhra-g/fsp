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
        BSWAP_32BIG_C(0x00000441U), BSWAP_32BIG_C(0xdd165f6bU), BSWAP_32BIG_C(0x55769a38U),
        BSWAP_32BIG_C(0x20156a64U),
        BSWAP_32BIG_C(0xe455b52eU), BSWAP_32BIG_C(0x00000441U), BSWAP_32BIG_C(0x41d33946U),
        BSWAP_32BIG_C(0xb0bdb099U),
        BSWAP_32BIG_C(0xb7a8aeeeU),
        BSWAP_32BIG_C(0x48ab9a08U), 0x0000141eU,
    };
    r_rsip_func_sub100(ARG1, Param_func441_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
