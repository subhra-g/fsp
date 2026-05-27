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

rsip_ret_t r_rsip_pdcr (const uint32_t InData_KeyIndex[], const uint32_t InData_State[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00dc0001U, 0x0000001aU);

    static const uint32_t Param_pdcr_sub100_001[] =
    {
        BSWAP_32BIG_C(0x0000dc02U), BSWAP_32BIG_C(0x5fbb3a1cU), BSWAP_32BIG_C(0xf572f95cU),
        BSWAP_32BIG_C(0xc3bbdebcU),
        BSWAP_32BIG_C(0xcf33c4e1U), BSWAP_32BIG_C(0x0000dc02U), BSWAP_32BIG_C(0xf27c1c13U),
        BSWAP_32BIG_C(0x2ada3b6aU),
        BSWAP_32BIG_C(0xca5f2d09U),
        BSWAP_32BIG_C(0x28ab82c1U), 0x00001404U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_pdcr_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_pdcr_func100_001[] =
    {
        BSWAP_32BIG_C(0x8eb1f041U), BSWAP_32BIG_C(0x297d5121U), BSWAP_32BIG_C(0xfd41ba37U), BSWAP_32BIG_C(0x1b79a79dU),
    };
    r_rsip_func100(Param_pdcr_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pdcr_func102_001[] =
        {
            BSWAP_32BIG_C(0x5aeed8fbU), BSWAP_32BIG_C(0x5bcb5c5fU), BSWAP_32BIG_C(0xa29f1393U), BSWAP_32BIG_C(
                0x5d2a9855U),
        };
        r_rsip_func102(Param_pdcr_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_00F4H, 0x00000010U);

        WR1_PROG(REG_0014H, 0x000007c4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR8_ADDR(REG_002CH, &InData_State[0]);

        WR1_PROG(REG_00F4H, 0x00000011U);

        WR1_PROG(REG_00D0H, 0x08000045U);
        r_rsip_func_sub004(0x00001804U, 0x00430011U);

        r_rsip_func_sub006(0x08000055U, 0x00430011U);

        static const uint32_t Param_pdcr_func101_001[] =
        {
            BSWAP_32BIG_C(0x38120222U), BSWAP_32BIG_C(0x6e5b17d8U), BSWAP_32BIG_C(0x61e7f43cU), BSWAP_32BIG_C(
                0xb43f4307U),
        };
        r_rsip_func101(Param_pdcr_func101_001);

        return RSIP_RET_PASS;
    }
}
