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

void r_rsip_p34u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p34u_func100_001[] =
    {
        BSWAP_32BIG_C(0x7529c871U), BSWAP_32BIG_C(0xb7c2c061U), BSWAP_32BIG_C(0xd239a94fU), BSWAP_32BIG_C(0xfc868f57U),
    };
    r_rsip_func100(Param_p34u_func100_001);

    WR1_PROG(REG_0014H, 0x00020061U);
    WR1_PROG(REG_00D4H, 0x40000020U);
    WR1_PROG(REG_00D0H, 0x20008d06U);
    WR1_PROG(REG_0008H, 0x000c1000U);

    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Text[0]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4U)
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &InData_Text[iLoop]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_Text[iLoop - 4]);
    }

    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_Text[iLoop - 4]);

    r_rsip_func206();

    static const uint32_t Param_p34u_func101_001[] =
    {
        BSWAP_32BIG_C(0xd354d9f9U), BSWAP_32BIG_C(0xa3c95c5bU), BSWAP_32BIG_C(0xda98c1d3U), BSWAP_32BIG_C(0x1fa3c3b6U),
    };
    r_rsip_func101(Param_p34u_func101_001);
}
