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

    r_rsip_func_sub014(0x00410001U, 0x00000005U);

    r_rsip_func_sub002(0x800100e0U, 0x00000041U);

    static const uint32_t Param_p41i_func101_001[] =
    {
        BSWAP_32BIG_C(0xb83d4444U), BSWAP_32BIG_C(0x1bec0d18U), BSWAP_32BIG_C(0xc7d0663cU), BSWAP_32BIG_C(0x64615b9aU),
    };
    r_rsip_func101(Param_p41i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p41i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6c87f2f5U), BSWAP_32BIG_C(0x02bd8c65U), BSWAP_32BIG_C(0x74204177U), BSWAP_32BIG_C(0xb2c4ce5fU),
    };
    r_rsip_func100(Param_p41i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p41i_func102_001[] =
        {
            BSWAP_32BIG_C(0xd7a6e26cU), BSWAP_32BIG_C(0x562e71ccU), BSWAP_32BIG_C(0x66d6198cU), BSWAP_32BIG_C(
                0x7d47a577U),
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
            BSWAP_32BIG_C(0x5c3058f9U), BSWAP_32BIG_C(0xf95c9beeU), BSWAP_32BIG_C(0x4b935d8aU), BSWAP_32BIG_C(
                0xa8a3df91U),
        };
        r_rsip_func100(Param_p41i_func100_002);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub004(0x00000801U, 0x00430009U);

        r_rsip_func_sub004(0x00000802U, 0x00430009U);

        r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

        return RSIP_RET_PASS;
    }
}
