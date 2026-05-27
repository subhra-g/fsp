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

rsip_ret_t r_rsip_pdcs (uint32_t OutData_State[])
{
    WR1_PROG(REG_00F4H, 0x00000100U);

    static const uint32_t Param_pdcs_func100_001[] =
    {
        BSWAP_32BIG_C(0x7425e7c6U), BSWAP_32BIG_C(0x3ee9926fU), BSWAP_32BIG_C(0xbe8eb266U), BSWAP_32BIG_C(0x559eacc5U),
    };
    r_rsip_func100(Param_pdcs_func100_001);
    WR1_PROG(REG_00F4H, 0x00000020U);

    WR1_PROG(REG_0008H, 0x00004022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD8_ADDR(REG_002CH, &OutData_State[0]);

    static const uint32_t Param_pdcs_func102_001[] =
    {
        BSWAP_32BIG_C(0x9fcdcbb2U), BSWAP_32BIG_C(0xe4dff52cU), BSWAP_32BIG_C(0x8e11ee54U), BSWAP_32BIG_C(0xb98abea4U),
    };
    r_rsip_func102(Param_pdcs_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
