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

rsip_ret_t r_rsip_p76i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00760001U, 0x0000001bU);

    static const uint32_t Param_p76i_sub100_001[] =
    {
        BSWAP_32BIG_C(0x00000076U), BSWAP_32BIG_C(0x7fcbf233U), BSWAP_32BIG_C(0xe5611c1bU),
        BSWAP_32BIG_C(0x161ce25dU),
        BSWAP_32BIG_C(0xf2aff49aU), BSWAP_32BIG_C(0x00000076U), BSWAP_32BIG_C(0x28e239f0U),
        BSWAP_32BIG_C(0x57dcc571U),
        BSWAP_32BIG_C(0xb617820eU),
        BSWAP_32BIG_C(0x6508c66eU), 0x00001404U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_p76i_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_p76i_func100_001[] =
    {
        BSWAP_32BIG_C(0xae7681d1U), BSWAP_32BIG_C(0x6ab0e43aU), BSWAP_32BIG_C(0x493183cfU), BSWAP_32BIG_C(0x39378d37U),
    };
    r_rsip_func100(Param_p76i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p76i_func102_001[] =
        {
            BSWAP_32BIG_C(0xbfe89678U), BSWAP_32BIG_C(0xfe583687U), BSWAP_32BIG_C(0xf7a8a8c6U), BSWAP_32BIG_C(
                0x9ffd0c01U),
        };
        r_rsip_func102(Param_p76i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func004();

        WR1_PROG(REG_00F4H, 0x00000011U);

        r_rsip_func001();

        static const uint32_t Param_p76i_func101_001[] =
        {
            BSWAP_32BIG_C(0x9afb12a6U), BSWAP_32BIG_C(0xc892b828U), BSWAP_32BIG_C(0xed5aca13U), BSWAP_32BIG_C(
                0x7df5aa47U),
        };
        r_rsip_func101(Param_p76i_func101_001);

        return RSIP_RET_PASS;
    }
}
