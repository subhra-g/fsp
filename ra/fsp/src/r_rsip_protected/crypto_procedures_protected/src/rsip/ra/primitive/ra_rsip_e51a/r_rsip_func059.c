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

void r_rsip_func059 (void)
{
    static const uint32_t Param_func059_func100_001[] =
    {
        BSWAP_32BIG_C(0xadc0c725U), BSWAP_32BIG_C(0xc7568f8dU), BSWAP_32BIG_C(0x63cda326U), BSWAP_32BIG_C(0x25d47cfaU),
    };
    r_rsip_func100(Param_func059_func100_001);
    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x01000000U);

    r_rsip_func_sub004(0x4a060044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e060085U);
    WR1_PROG(REG_1608H, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func059_func100_002[] =
    {
        BSWAP_32BIG_C(0x78e24cbaU), BSWAP_32BIG_C(0x50bf9103U), BSWAP_32BIG_C(0x4eb6c97eU), BSWAP_32BIG_C(0x65a4b108U),
    };
    r_rsip_func100(Param_func059_func100_002);
    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x02000000U);

    WR1_PROG(REG_1A24H, 0x0e060095U);
    WR1_PROG(REG_1608H, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
