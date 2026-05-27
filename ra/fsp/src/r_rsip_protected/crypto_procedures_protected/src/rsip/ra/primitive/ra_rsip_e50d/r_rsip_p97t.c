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

void r_rsip_p97t (void)
{
    static const uint32_t Param_p97t_func100_001[] =
    {
        BSWAP_32BIG_C(0x85ab01ceU), BSWAP_32BIG_C(0xf5845f81U), BSWAP_32BIG_C(0x0574070bU), BSWAP_32BIG_C(0x07d1c4f3U),
    };
    r_rsip_func100(Param_p97t_func100_001);
    WR1_PROG(REG_1600H, 0x0000b440U);
    WR1_PROG(REG_1600H, 0x00000002U);

    r_rsip_func_sub016(0x81010040U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    static const uint32_t Param_p97t_func101_001[] =
    {
        BSWAP_32BIG_C(0x2c26ad81U), BSWAP_32BIG_C(0x82c64639U), BSWAP_32BIG_C(0xf6ecc569U), BSWAP_32BIG_C(0x26e94211U),
    };
    r_rsip_func101(Param_p97t_func101_001);
}
