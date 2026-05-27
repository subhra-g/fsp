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

rsip_ret_t r_rsip_p76s (uint32_t OutData_State[])
{
    WR1_PROG(REG_00F4H, 0x00000100U);

    static const uint32_t Param_p76s_func100_001[] =
    {
        BSWAP_32BIG_C(0x4fd152c1U), BSWAP_32BIG_C(0x94c11b9fU), BSWAP_32BIG_C(0xe1c36a7cU), BSWAP_32BIG_C(0x62432e48U),
    };
    r_rsip_func100(Param_p76s_func100_001);
    WR1_PROG(REG_00F4H, 0x00000020U);

    WR1_PROG(REG_0008H, 0x00004022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD8_ADDR(REG_002CH, &OutData_State[0]);

    static const uint32_t Param_p76s_func102_001[] =
    {
        BSWAP_32BIG_C(0xa22f2beaU), BSWAP_32BIG_C(0xe2010f54U), BSWAP_32BIG_C(0x470fadb4U), BSWAP_32BIG_C(0xef673c85U),
    };
    r_rsip_func102(Param_p76s_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
