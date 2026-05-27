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

rsip_ret_t r_rsip_pefr (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ef0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x3000a800U, 0x00000003U, 0x00010020U, 0x0000b400U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1600H, 0x00000080U);

    static const uint32_t Param_pefr_func100_001[] =
    {
        BSWAP_32BIG_C(0x8e6ca25bU), BSWAP_32BIG_C(0x3c27e3c7U), BSWAP_32BIG_C(0x4e64c67bU), BSWAP_32BIG_C(0x2f1c8ad3U),
    };
    r_rsip_func100(Param_pefr_func100_001);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00001050U);

        static const uint32_t Param_pefr_func101_001[] =
        {
            BSWAP_32BIG_C(0x37efd5ddU), BSWAP_32BIG_C(0x37788243U), BSWAP_32BIG_C(0x0037f01eU), BSWAP_32BIG_C(
                0x050e767fU),
        };
        r_rsip_func101(Param_pefr_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x000010a0U);

        static const uint32_t Param_pefr_func101_002[] =
        {
            BSWAP_32BIG_C(0x079d5e22U), BSWAP_32BIG_C(0xb63ec1b4U), BSWAP_32BIG_C(0x102acff8U), BSWAP_32BIG_C(
                0x0509a0bcU),
        };
        r_rsip_func101(Param_pefr_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x000010b0U);

        static const uint32_t Param_pefr_func101_003[] =
        {
            BSWAP_32BIG_C(0x39926437U), BSWAP_32BIG_C(0x0d874dc5U), BSWAP_32BIG_C(0x33a9bf3aU), BSWAP_32BIG_C(
                0xbf225884U),
        };
        r_rsip_func101(Param_pefr_func101_003);
    }

    r_rsip_func_sub025(0x0000b420U, 0x00000010U, 0x00003c01U);

    r_rsip_func_sub036(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

    for (iLoop = 0U; iLoop < 18U; iLoop++)
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2028H, InData_State[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pefr_func101_004[] =
    {
        BSWAP_32BIG_C(0x681ce34dU), BSWAP_32BIG_C(0xb18679bfU), BSWAP_32BIG_C(0x550b1484U), BSWAP_32BIG_C(0x557c0af6U),
    };
    r_rsip_func101(Param_pefr_func101_004);

    return RSIP_RET_PASS;
}
