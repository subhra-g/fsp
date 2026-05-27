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

void r_rsip_func016 (uint32_t ARG1)
{
    uint32_t oLoop = 0U;

    static const uint32_t Param_func016_func100_001[] =
    {
        BSWAP_32BIG_C(0x6f1ac5a9U), BSWAP_32BIG_C(0xa623b33bU), BSWAP_32BIG_C(0xbe75b461U), BSWAP_32BIG_C(0x5cd3d5ccU),
    };
    r_rsip_func100(Param_func016_func100_001);
    r_rsip_func_sub024(0x00000821U, 0x0000b440U, 0x00000004U, 0x00000863U);

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0 + 2]);
    S_RAM[0 + 2] = bswap_32big(S_RAM[0 + 2]);

    for (oLoop = 0U; oLoop < S_RAM[0 + 2]; )
    {
        WR1_PROG(REG_1600H, 0x34202820U);
        WR1_PROG(REG_1600H, 0x2000d060U);
        r_rsip_func_sub014(0x00007c03U, 0x00602000U);

        static const uint32_t Param_func016_func100_002[] =
        {
            BSWAP_32BIG_C(0x9c2e3e2aU), BSWAP_32BIG_C(0x7ee70e3bU), BSWAP_32BIG_C(0x22c4ad1fU), BSWAP_32BIG_C(
                0xe2233620U),
        };
        r_rsip_func100(Param_func016_func100_002);
        WR1_PROG(REG_1A24H, 0xe70c0d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &S_HEAP[ARG1 + oLoop]);

        WR1_PROG(REG_1600H, 0x00002422U);

        static const uint32_t Param_func016_func101_001[] =
        {
            BSWAP_32BIG_C(0x33a34c03U), BSWAP_32BIG_C(0x2465cc63U), BSWAP_32BIG_C(0x760883d2U), BSWAP_32BIG_C(
                0x69a0de7dU),
        };
        r_rsip_func101(Param_func016_func101_001);
        oLoop = oLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000801U);

    static const uint32_t Param_func016_func100_003[] =
    {
        BSWAP_32BIG_C(0x0199b139U), BSWAP_32BIG_C(0x136515d9U), BSWAP_32BIG_C(0xef3162ccU), BSWAP_32BIG_C(0xe347a6faU),
    };
    r_rsip_func100(Param_func016_func100_003);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x091c0105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &S_HEAP[ARG1 + oLoop]);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
