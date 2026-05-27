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

void r_rsip_func423 (uint32_t ARG1[], uint32_t ARG2)
{
    uint32_t jLoop = 0U;

    r_rsip_func_sub024(0x000008c6U, 0x000024c8U, 0x00003826U, 0x00000c24U);

    WR1_PROG(REG_1600H, 0x00003c26U);

    WR1_PROG(REG_1600H, 0x00000bffU);

    for (jLoop = 0U; jLoop < S_RAM[0]; jLoop++)
    {
        r_rsip_func_sub025(0x000024c5U, 0x00003fe6U, 0x00003120U);
        static const uint32_t Param_func423_func101_001[] =
        {
            BSWAP_32BIG_C(0x3cd11efeU), BSWAP_32BIG_C(0x247c55d2U), BSWAP_32BIG_C(0x73a3eb4cU), BSWAP_32BIG_C(
                0xf970f89dU),
        };
        r_rsip_func101(Param_func423_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_func423_func100_001[] =
    {
        BSWAP_32BIG_C(0x552f951bU), BSWAP_32BIG_C(0x58204dc9U), BSWAP_32BIG_C(0xfe1ab997U), BSWAP_32BIG_C(0x8e59d6bdU),
    };
    r_rsip_func100(Param_func423_func100_001);
    r_rsip_func_sub011(0x38000d29U);

    WR1_PROG(REG_1600H, 0x000008c6U);
    r_rsip_func_sub016(0x81840006U, 0x00005012U);
    RD1_ADDR(REG_1420H, &ARG1[ARG2 + 4]);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &ARG1[ARG2 + 5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &ARG1[ARG2 + 6]);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &ARG1[ARG2 + 7]);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
