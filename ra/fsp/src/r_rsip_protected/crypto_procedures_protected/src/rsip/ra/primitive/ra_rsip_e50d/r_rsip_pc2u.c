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

void r_rsip_pc2u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    static const uint32_t Param_pc2u_func100_001[] =
    {
        BSWAP_32BIG_C(0xf47101f4U), BSWAP_32BIG_C(0x0ff7ba4fU), BSWAP_32BIG_C(0xefcd3648U), BSWAP_32BIG_C(0x83117d31U),
    };
    r_rsip_func100(Param_pc2u_func100_001);

    r_rsip_func_sub025(0x00020061U, 0x40000020U, 0x0d00890eU);
    WR1_PROG(REG_1408H, 0x000c1000U);

    r_rsip_func220(InData_Text, MAX_CNT, OutData_Text);

    static const uint32_t Param_pc2u_func101_001[] =
    {
        BSWAP_32BIG_C(0x9e894a56U), BSWAP_32BIG_C(0x31fcbe81U), BSWAP_32BIG_C(0xab8a8887U), BSWAP_32BIG_C(0x40634befU),
    };
    r_rsip_func101(Param_pc2u_func101_001);
}
