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
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00200002U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000020U);

    static const uint32_t Param_p20_func101_001[] =
    {
        BSWAP_32BIG_C(0x7b4e80d3U), BSWAP_32BIG_C(0x50ed03c3U), BSWAP_32BIG_C(0x157cda39U), BSWAP_32BIG_C(0x7532ea8aU),
    };
    r_rsip_func101(Param_p20_func101_001);
    r_rsip_func103();
    static const uint32_t Param_p20_func100_001[] =
    {
        BSWAP_32BIG_C(0x18dcbb76U), BSWAP_32BIG_C(0x1bd8115cU), BSWAP_32BIG_C(0x841c0ee2U), BSWAP_32BIG_C(0x56401949U),
    };
    r_rsip_func100(Param_p20_func100_001);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[0]);

    static const uint32_t Param_p20_func102_001[] =
    {
        BSWAP_32BIG_C(0xca23625aU), BSWAP_32BIG_C(0xd1fb2144U), BSWAP_32BIG_C(0x617496c6U), BSWAP_32BIG_C(0xb60241acU),
    };
    r_rsip_func102(Param_p20_func102_001);

    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
