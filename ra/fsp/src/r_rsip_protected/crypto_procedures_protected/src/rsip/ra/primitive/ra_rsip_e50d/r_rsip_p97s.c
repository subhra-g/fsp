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

rsip_ret_t r_rsip_p97s (uint32_t OutData_State[])
{
    uint32_t iLoop = 0U;

    if (S_RAM[0] == 1)
    {
        static const uint32_t Param_p97s_func101_001[] =
        {
            BSWAP_32BIG_C(0x709ca98aU), BSWAP_32BIG_C(0x3857904fU), BSWAP_32BIG_C(0x4029cf76U), BSWAP_32BIG_C(
                0x7d81fdfdU),
        };
        r_rsip_func101(Param_p97s_func101_001);
    }
    else
    {
        static const uint32_t Param_p97s_func101_002[] =
        {
            BSWAP_32BIG_C(0x429bac95U), BSWAP_32BIG_C(0x359d8724U), BSWAP_32BIG_C(0x09e2bd40U), BSWAP_32BIG_C(
                0x6b2fe609U),
        };
        r_rsip_func101(Param_p97s_func101_002);
    }

    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    RD1_ADDR(REG_1C08H, &OutData_State[0]);
    RD1_ADDR(REG_1C10H, &OutData_State[1]);
    RD1_ADDR(REG_1C14H, &OutData_State[2]);

    for (iLoop = 3; iLoop < 10U; iLoop++)
    {
        RD1_ADDR(REG_1C2CH, &OutData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000034e3U);

    r_rsip_func_sub003(0x800103a0U, 0x00009704U);

    static const uint32_t Param_p97s_func101_003[] =
    {
        BSWAP_32BIG_C(0xb94bc733U), BSWAP_32BIG_C(0x1af28709U), BSWAP_32BIG_C(0x8250881fU), BSWAP_32BIG_C(0x18af0e05U),
    };
    r_rsip_func101(Param_p97s_func101_003);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0121608eU);

    r_rsip_func_sub003(0x800103a0U, 0x00009704U);

    static const uint32_t Param_p97s_func101_004[] =
    {
        BSWAP_32BIG_C(0x2b6148bbU), BSWAP_32BIG_C(0x400812dcU), BSWAP_32BIG_C(0xadb5141aU), BSWAP_32BIG_C(0xc1ccc1c5U),
    };
    r_rsip_func101(Param_p97s_func101_004);
    r_rsip_func044();

    static const uint32_t Param_p97s_func100_001[] =
    {
        BSWAP_32BIG_C(0xccd3e966U), BSWAP_32BIG_C(0xae3e4138U), BSWAP_32BIG_C(0x7ecf29b7U), BSWAP_32BIG_C(0xedef180fU),
    };
    r_rsip_func100(Param_p97s_func100_001);
    r_rsip_func_sub027(0x40000000U, 0xe8009104U, 0x81010040U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30, 1);
    RD1_ADDR(REG_1420H, &OutData_State[11]);
    r_rsip_func_sub001(0x0002000dU);

    static const uint32_t Param_p97s_func100_002[] =
    {
        BSWAP_32BIG_C(0x1844c0bdU), BSWAP_32BIG_C(0x590636aeU), BSWAP_32BIG_C(0x7663bd1fU), BSWAP_32BIG_C(0x27236122U),
    };
    r_rsip_func100(Param_p97s_func100_002);
    r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_State[12]);

    static const uint32_t Param_p97s_func100_003[] =
    {
        BSWAP_32BIG_C(0x61dfe978U), BSWAP_32BIG_C(0xeaba36dcU), BSWAP_32BIG_C(0x4ba03829U), BSWAP_32BIG_C(0x266b9a13U),
    };
    r_rsip_func100(Param_p97s_func100_003);
    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_State[10]);

    static const uint32_t Param_p97s_func102_001[] =
    {
        BSWAP_32BIG_C(0xa242dde8U), BSWAP_32BIG_C(0x7a91647dU), BSWAP_32BIG_C(0x2ad4f900U), BSWAP_32BIG_C(0x4c728e65U),
    };
    r_rsip_func102(Param_p97s_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
