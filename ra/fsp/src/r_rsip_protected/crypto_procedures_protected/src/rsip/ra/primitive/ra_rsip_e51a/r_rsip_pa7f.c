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

rsip_ret_t r_rsip_pa7f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    r_rsip_func_sub039(0x00008c00U, 0x0000000fU);

    r_rsip_func_sub006(0x38008800U, 0x00000000U, 0x00A60000U);

    static const uint32_t Param_pa7f_func100_001[] =
    {
        BSWAP_32BIG_C(0x906b641fU), BSWAP_32BIG_C(0x6aa6d3caU), BSWAP_32BIG_C(0x58a04858U), BSWAP_32BIG_C(0x1687648dU),
    };
    r_rsip_func100(Param_pa7f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0xe7008d05U);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        r_rsip_func_sub026(0x0000b420U, 0x00000080U, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        r_rsip_func_sub024(0x00000821U, 0x0000a400U, 0x00000080U, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x00000080U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub025(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_pa7f_func100_002[] =
        {
            BSWAP_32BIG_C(0x86664c46U), BSWAP_32BIG_C(0x0513b405U), BSWAP_32BIG_C(0x96d7d4acU), BSWAP_32BIG_C(
                0x869c421cU),
        };
        r_rsip_func100(Param_pa7f_func100_002);
        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000080U);
        r_rsip_func_sub016(0x81840001U, 0x00005012U);
        RD1_ADDR(REG_1420H, &OutData_Text[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[2]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[3]);

        static const uint32_t Param_pa7f_func101_001[] =
        {
            BSWAP_32BIG_C(0x7e7610d9U), BSWAP_32BIG_C(0xa263c2b8U), BSWAP_32BIG_C(0x6a5b6fd8U), BSWAP_32BIG_C(
                0x90a218f4U),
        };
        r_rsip_func101(Param_pa7f_func101_001);
    }
    else
    {
        static const uint32_t Param_pa7f_func101_002[] =
        {
            BSWAP_32BIG_C(0x3bc47236U), BSWAP_32BIG_C(0x12c54170U), BSWAP_32BIG_C(0xddb1e9e3U), BSWAP_32BIG_C(
                0xdd4de3ceU),
        };
        r_rsip_func101(Param_pa7f_func101_002);
    }

    r_rsip_func_sub020(0x000000a1U, 0x0c200104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    static const uint32_t Param_pa7f_func100_003[] =
    {
        BSWAP_32BIG_C(0x20407f2fU), BSWAP_32BIG_C(0x03dd53adU), BSWAP_32BIG_C(0x166677feU), BSWAP_32BIG_C(0x1390c519U),
    };
    r_rsip_func100(Param_pa7f_func100_003);
    WR1_PROG(REG_182CH, 0x40000010U);
    WR1_PROG(REG_1824H, 0x09108105U);
    r_rsip_func_sub001(0x00410011U);

    WR1_PROG(REG_1408H, 0x00001012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_MAC[0]);

    static const uint32_t Param_pa7f_func102_001[] =
    {
        BSWAP_32BIG_C(0x48e196aeU), BSWAP_32BIG_C(0x684415a6U), BSWAP_32BIG_C(0x67fd5d48U), BSWAP_32BIG_C(0x2eb89ab9U),
    };
    r_rsip_func102(Param_pa7f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
