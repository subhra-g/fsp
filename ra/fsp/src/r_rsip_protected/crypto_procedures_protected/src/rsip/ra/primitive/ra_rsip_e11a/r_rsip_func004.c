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

void r_rsip_func004 (void)
{
    WR1_PROG(REG_00F4H, 0x00000010U);

    WR1_PROG(REG_0014H, 0x000007a4U);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_PROG(REG_002CH, bswap_32big(0x6a09e667U), bswap_32big(0xbb67ae85U), bswap_32big(0x3c6ef372U),
             bswap_32big(0xa54ff53aU), bswap_32big(0x510e527fU), bswap_32big(0x9b05688cU), bswap_32big(0x1f83d9abU),
             bswap_32big(0x5be0cd19U));
}
