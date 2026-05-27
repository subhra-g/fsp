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

rsip_ret_t r_rsip_pe5u (const uint32_t InData_Msg[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_00F8H, 0, 1);

    WR1_PROG(REG_0014H, 0x00020064U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_Msg[iLoop]);
    }

    WAIT_STS(REG_00F8H, 2, 0);

    WR1_PROG(REG_0014H, 0x00000000U);

    WR1_PROG(REG_0040H, 0x00001600U);

    static const uint32_t Param_pe5u_func101_001[] =
    {
        BSWAP_32BIG_C(0x2f258725U), BSWAP_32BIG_C(0x9602b550U), BSWAP_32BIG_C(0xd185a194U), BSWAP_32BIG_C(0x34dac589U),
    };
    r_rsip_func101(Param_pe5u_func101_001);

    return RSIP_RET_PASS;
}
