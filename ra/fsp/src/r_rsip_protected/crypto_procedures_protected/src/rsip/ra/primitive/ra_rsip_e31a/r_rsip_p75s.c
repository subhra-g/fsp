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

rsip_ret_t r_rsip_p75s (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    for (iLoop = 0U; iLoop < 18U; iLoop++)
    {
        RD1_ADDR(REG_0114H, &OutData_State[iLoop]);
    }

    RD1_ADDR(REG_0104H, &OutData_State[18]);
    RD1_ADDR(REG_0100H, &OutData_State[19]);

    static const uint32_t Param_p75s_func102_001[] =
    {
        BSWAP_32BIG_C(0x093035c5U), BSWAP_32BIG_C(0x64b4f7acU), BSWAP_32BIG_C(0x9262835bU), BSWAP_32BIG_C(0x56004a03U),
    };
    r_rsip_func102(Param_p75s_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
