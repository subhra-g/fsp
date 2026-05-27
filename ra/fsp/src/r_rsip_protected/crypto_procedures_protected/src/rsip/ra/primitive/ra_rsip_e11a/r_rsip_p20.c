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

rsip_ret_t r_rsip_p20 (uint32_t OutData_Text[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00200002U);
    WR1_PROG(REG_004CH, 0x00000000U);

    static const uint32_t Param_p20_func100_001[] =
    {
        BSWAP_32BIG_C(0x466e169dU), BSWAP_32BIG_C(0x6ba86c1cU), BSWAP_32BIG_C(0x1116394cU), BSWAP_32BIG_C(0xe151d83fU),
    };
    r_rsip_func100(Param_p20_func100_001);
    r_rsip_func103();
    static const uint32_t Param_p20_func100_002[] =
    {
        BSWAP_32BIG_C(0x39771fcfU), BSWAP_32BIG_C(0xf5bbe206U), BSWAP_32BIG_C(0x94229b14U), BSWAP_32BIG_C(0xc57e8e42U),
    };
    r_rsip_func100(Param_p20_func100_002);
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_Text[0]);

    static const uint32_t Param_p20_func102_001[] =
    {
        BSWAP_32BIG_C(0x033f3f05U), BSWAP_32BIG_C(0xea4f993bU), BSWAP_32BIG_C(0x4c346526U), BSWAP_32BIG_C(0x9be4e224U),
    };
    r_rsip_func102(Param_p20_func102_001);

    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
