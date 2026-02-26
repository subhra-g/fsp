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

void r_rsip_func040 (void)
{
    static const uint32_t Param_func040_func100_001[] =
    {
        BSWAP_32BIG_C(0xde1b6cb4U), BSWAP_32BIG_C(0xdd98add5U), BSWAP_32BIG_C(0x7f36fb9dU), BSWAP_32BIG_C(0x7cc785dbU),
    };
    r_rsip_func100(Param_func040_func100_001);
    WR1_PROG(REG_00D0H, 0x4a470044U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

    WR1_PROG(REG_00D0H, 0x0e470484U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x01a5da45U));

    static const uint32_t Param_func040_func100_002[] =
    {
        BSWAP_32BIG_C(0x94c2b463U), BSWAP_32BIG_C(0xb981928aU), BSWAP_32BIG_C(0x1f24086bU), BSWAP_32BIG_C(0xe0328ef8U),
    };
    r_rsip_func100(Param_func040_func100_002);
    WR1_PROG(REG_00D0H, 0x4a470044U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

    WR1_PROG(REG_00D0H, 0x0e470494U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x02a5da45U));

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
