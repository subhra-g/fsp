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

rsip_ret_t r_rsip_pe5s (uint32_t OutData_State[])
{
    WR1_PROG(REG_00F4H, 0x00000100U);

    static const uint32_t Param_pe5s_func100_001[] =
    {
        BSWAP_32BIG_C(0x14a2147eU), BSWAP_32BIG_C(0x13600ca5U), BSWAP_32BIG_C(0x61e9f225U), BSWAP_32BIG_C(0xbdea0b27U),
    };
    r_rsip_func100(Param_pe5s_func100_001);
    WR1_PROG(REG_00F4H, 0x00000020U);

    WR1_PROG(REG_0008H, 0x00004022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD8_ADDR(REG_002CH, &OutData_State[0]);

    static const uint32_t Param_pe5s_func102_001[] =
    {
        BSWAP_32BIG_C(0x0bb48185U), BSWAP_32BIG_C(0x3c0fd44bU), BSWAP_32BIG_C(0xebb719bcU), BSWAP_32BIG_C(0x944f39a1U),
    };
    r_rsip_func102(Param_pe5s_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
