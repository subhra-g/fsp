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

rsip_ret_t r_rsip_p44i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00440001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000007U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000044U, 0x00000000U);

    static const uint32_t Param_p44i_func101_001[] =
    {
        BSWAP_32BIG_C(0xdb636ea2U), BSWAP_32BIG_C(0xe9e16b67U), BSWAP_32BIG_C(0x4670a6f2U), BSWAP_32BIG_C(0x47e2e937U),
    };
    r_rsip_func101(Param_p44i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_p44i_func100_001[] =
    {
        BSWAP_32BIG_C(0xa45c3d50U), BSWAP_32BIG_C(0x6f197183U), BSWAP_32BIG_C(0xb0a25cbbU), BSWAP_32BIG_C(0x492b3cf1U),
    };
    r_rsip_func100(Param_p44i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p44i_func102_001[] =
        {
            BSWAP_32BIG_C(0x2841530aU), BSWAP_32BIG_C(0x185c7c22U), BSWAP_32BIG_C(0x1d1f43fdU), BSWAP_32BIG_C(
                0x06a429eaU),
        };
        r_rsip_func102(Param_p44i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p44i_func100_002[] =
        {
            BSWAP_32BIG_C(0x298d0955U), BSWAP_32BIG_C(0xc344a988U), BSWAP_32BIG_C(0x9bf53dcaU), BSWAP_32BIG_C(
                0xd52b1cd3U),
        };
        r_rsip_func100(Param_p44i_func100_002);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

        static const uint32_t Param_p44i_func100_003[] =
        {
            BSWAP_32BIG_C(0xb035c67dU), BSWAP_32BIG_C(0xac45080dU), BSWAP_32BIG_C(0x9c18f0f4U), BSWAP_32BIG_C(
                0x739792feU),
        };
        r_rsip_func100(Param_p44i_func100_003);
        r_rsip_func_sub013(0x08000095U, 0x00430011U);

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        return RSIP_RET_PASS;
    }
}
