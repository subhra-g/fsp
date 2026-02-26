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

void r_rsip_p98u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p98u_func100_001[] =
    {
        BSWAP_32BIG_C(0x1fab4081U), BSWAP_32BIG_C(0x1cc8891aU), BSWAP_32BIG_C(0xbe39fd50U), BSWAP_32BIG_C(0x8c950e43U),
    };
    r_rsip_func100(Param_p98u_func100_001);
    WR1_PROG(REG_0014H, 0x00020061U);

    WR1_PROG(REG_00D0H, 0xf7000d06U);
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

    static const uint32_t Param_p98u_func101_001[] =
    {
        BSWAP_32BIG_C(0x2ad77ff8U), BSWAP_32BIG_C(0xb956aec0U), BSWAP_32BIG_C(0xe40627a0U), BSWAP_32BIG_C(0xf71ef429U),
    };
    r_rsip_func101(Param_p98u_func101_001);
}
