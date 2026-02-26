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

rsip_ret_t r_rsip_p41i (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00410001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000005U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000041U, 0x00000000U);

    static const uint32_t Param_p41i_func101_001[] =
    {
        BSWAP_32BIG_C(0x1142c72bU), BSWAP_32BIG_C(0x5a0d3e95U), BSWAP_32BIG_C(0x0ba49b89U), BSWAP_32BIG_C(0x5cb7c012U),
    };
    r_rsip_func101(Param_p41i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p41i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6238acb3U), BSWAP_32BIG_C(0x4b626921U), BSWAP_32BIG_C(0xee36318dU), BSWAP_32BIG_C(0xdd07d18aU),
    };
    r_rsip_func100(Param_p41i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p41i_func102_001[] =
        {
            BSWAP_32BIG_C(0x46f4f2dbU), BSWAP_32BIG_C(0xafd766e0U), BSWAP_32BIG_C(0x0c3fe143U), BSWAP_32BIG_C(
                0x514dda5eU),
        };
        r_rsip_func102(Param_p41i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p41i_func100_002[] =
        {
            BSWAP_32BIG_C(0x36d8a8ddU), BSWAP_32BIG_C(0x483ba6bdU), BSWAP_32BIG_C(0x1cba0811U), BSWAP_32BIG_C(
                0xf0b3c4e5U),
        };
        r_rsip_func100(Param_p41i_func100_002);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

        r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        return RSIP_RET_PASS;
    }
}
