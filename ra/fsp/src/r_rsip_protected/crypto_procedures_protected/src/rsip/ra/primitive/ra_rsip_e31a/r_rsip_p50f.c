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

rsip_ret_t r_rsip_p50f (void)
{
    static const uint32_t Param_p50f_func102_001[] =
    {
        BSWAP_32BIG_C(0x3ce1994bU), BSWAP_32BIG_C(0x9b9aaf9aU), BSWAP_32BIG_C(0x237db6a6U), BSWAP_32BIG_C(0x348a9a8bU),
    };
    r_rsip_func102(Param_p50f_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
