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

rsip_ret_t r_rsip_p76r (const uint32_t InData_KeyIndex[], const uint32_t InData_State[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00760001U, 0x0000001bU);

    static const uint32_t Param_p76r_sub100_001[] =
    {
        BSWAP_32BIG_C(0x00007602U), BSWAP_32BIG_C(0x6fbef920U), BSWAP_32BIG_C(0x3f5ade1eU),
        BSWAP_32BIG_C(0x5606dc30U),
        BSWAP_32BIG_C(0x2a757953U), BSWAP_32BIG_C(0x00007602U), BSWAP_32BIG_C(0x72032da2U),
        BSWAP_32BIG_C(0xbf3e0201U),
        BSWAP_32BIG_C(0xde4ddad3U),
        BSWAP_32BIG_C(0x98f43d33U), 0x00001404U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_p76r_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_p76r_func100_001[] =
    {
        BSWAP_32BIG_C(0x43c51bc2U), BSWAP_32BIG_C(0x205ecb98U), BSWAP_32BIG_C(0x60e17ac2U), BSWAP_32BIG_C(0x1e078cf2U),
    };
    r_rsip_func100(Param_p76r_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p76r_func102_001[] =
        {
            BSWAP_32BIG_C(0xcd0dd564U), BSWAP_32BIG_C(0x27eae833U), BSWAP_32BIG_C(0xab6fd1dfU), BSWAP_32BIG_C(
                0x47ffe4c5U),
        };
        r_rsip_func102(Param_p76r_func102_001);
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

        static const uint32_t Param_p76r_func101_001[] =
        {
            BSWAP_32BIG_C(0x0b1fa522U), BSWAP_32BIG_C(0x3c76590bU), BSWAP_32BIG_C(0x78cf6a43U), BSWAP_32BIG_C(
                0xaf7620f6U),
        };
        r_rsip_func101(Param_p76r_func101_001);

        return RSIP_RET_PASS;
    }
}
