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

void r_rsip_pa1u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_pa1u_func100_001[] =
    {
        BSWAP_32BIG_C(0x5b1a1a8bU), BSWAP_32BIG_C(0xdf5348c7U), BSWAP_32BIG_C(0x0ae143a8U), BSWAP_32BIG_C(0x8b4b45f9U),
    };
    r_rsip_func100(Param_pa1u_func100_001);
    WR1_PROG(REG_0014H, 0x00020061U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0xe7008d06U);
    WR1_PROG(REG_0008H, 0x000c1000U);

    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Text[0]);
    for (iLoop = 4; iLoop < MAX_CNT; )
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &InData_Text[iLoop]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_Text[iLoop - 4]);
        iLoop = iLoop + 4U;
    }

    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_Text[MAX_CNT - 4]);

    r_rsip_func206();

    static const uint32_t Param_pa1u_func101_001[] =
    {
        BSWAP_32BIG_C(0xc280c64cU), BSWAP_32BIG_C(0x299d8bd0U), BSWAP_32BIG_C(0x9b805d75U), BSWAP_32BIG_C(0x9c08d316U),
    };
    r_rsip_func101(Param_pa1u_func101_001);
}
