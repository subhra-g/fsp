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

void r_rsip_pa4u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_pa4u_func100_001[] =
    {
        BSWAP_32BIG_C(0x9eb16f83U), BSWAP_32BIG_C(0x07489ad8U), BSWAP_32BIG_C(0x2567e07fU), BSWAP_32BIG_C(0xf6f72cbcU),
    };
    r_rsip_func100(Param_pa4u_func100_001);
    r_rsip_func_sub028(0x00020061U, 0x40000000U, 0xf7008d06U);
    WR1_PROG(REG_1408H, 0x000c1000U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    for (iLoop = 4U; iLoop < MAX_CNT; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);

    r_rsip_func215();

    static const uint32_t Param_pa4u_func101_001[] =
    {
        BSWAP_32BIG_C(0x63dd8ff7U), BSWAP_32BIG_C(0xa4b35995U), BSWAP_32BIG_C(0x23f6f556U), BSWAP_32BIG_C(0xce59c450U),
    };
    r_rsip_func101(Param_pa4u_func101_001);
}
