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

void r_rsip_func003 (void)
{
    WR1_PROG(REG_00F4H, 0x00000010U);

    WR1_PROG(REG_0014H, 0x000007a4U);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_PROG(REG_002CH, bswap_32big(0xc1059ed8U), bswap_32big(0x367cd507U), bswap_32big(0x3070dd17U),
             bswap_32big(0xf70e5939U), bswap_32big(0xffc00b31U), bswap_32big(0x68581511U), bswap_32big(0x64f98fa7U),
             bswap_32big(0xbefa4fa4U));
}
