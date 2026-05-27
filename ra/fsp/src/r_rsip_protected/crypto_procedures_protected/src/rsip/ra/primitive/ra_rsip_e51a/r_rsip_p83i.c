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

rsip_ret_t r_rsip_p83i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00830001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000083U);

    static const uint32_t Param_p83i_func101_001[] =
    {
        BSWAP_32BIG_C(0x17250ef1U), BSWAP_32BIG_C(0xfc7a10e9U), BSWAP_32BIG_C(0x6fcab1baU), BSWAP_32BIG_C(0xbf6cb56bU),
    };
    r_rsip_func101(Param_p83i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000083U);

    static const uint32_t Param_p83i_func101_002[] =
    {
        BSWAP_32BIG_C(0x6324fd46U), BSWAP_32BIG_C(0xe08fdf8eU), BSWAP_32BIG_C(0x54425e42U), BSWAP_32BIG_C(0xeb7112caU),
    };
    r_rsip_func101(Param_p83i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p83i_func100_001[] =
    {
        BSWAP_32BIG_C(0xcc6939e1U), BSWAP_32BIG_C(0xd2eaa3a4U), BSWAP_32BIG_C(0x8267fdbdU), BSWAP_32BIG_C(0xc9b40791U),
    };
    r_rsip_func100(Param_p83i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p83i_func100_002[] =
    {
        BSWAP_32BIG_C(0xb00d66d0U), BSWAP_32BIG_C(0x3da1b337U), BSWAP_32BIG_C(0x8856edafU), BSWAP_32BIG_C(0x946e2812U),
    };
    r_rsip_func100(Param_p83i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p83i_func100_003[] =
    {
        BSWAP_32BIG_C(0xb953ebc0U), BSWAP_32BIG_C(0x2b41cea0U), BSWAP_32BIG_C(0x7eb929b5U), BSWAP_32BIG_C(0xff3e8522U),
    };
    r_rsip_func100(Param_p83i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p83i_func102_001[] =
        {
            BSWAP_32BIG_C(0x99f57749U), BSWAP_32BIG_C(0x86c0f335U), BSWAP_32BIG_C(0xd95a44d8U), BSWAP_32BIG_C(
                0x3ea4daa0U),
        };
        r_rsip_func102(Param_p83i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000003c7U, 0x80040080U);
        WR1_PROG(REG_1420H, InData_IV[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[2]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_IV[3]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070010U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        return RSIP_RET_PASS;
    }
}
