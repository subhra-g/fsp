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

rsip_ret_t r_rsip_p34i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00340001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x00000034U);

    static const uint32_t Param_p34i_func101_001[] =
    {
        BSWAP_32BIG_C(0xbbb649a7U), BSWAP_32BIG_C(0xfb3f6fb9U), BSWAP_32BIG_C(0x88ab1157U), BSWAP_32BIG_C(0xe7852b2aU),
    };
    r_rsip_func101(Param_p34i_func101_001);
    r_rsip_func435(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p34i_func100_001[] =
    {
        BSWAP_32BIG_C(0x77b0b1b5U), BSWAP_32BIG_C(0x6573a799U), BSWAP_32BIG_C(0x00a50127U), BSWAP_32BIG_C(0x424782cdU),
    };
    r_rsip_func100(Param_p34i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p34i_func102_001[] =
        {
            BSWAP_32BIG_C(0x3201b3a9U), BSWAP_32BIG_C(0x18fd7f07U), BSWAP_32BIG_C(0x658a5a39U), BSWAP_32BIG_C(
                0x225437b0U),
        };
        r_rsip_func102(Param_p34i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p34i_func100_002[] =
        {
            BSWAP_32BIG_C(0x3f791ab4U), BSWAP_32BIG_C(0x0190babfU), BSWAP_32BIG_C(0x624c480cU), BSWAP_32BIG_C(
                0x91a22d18U),
        };
        r_rsip_func100(Param_p34i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p34i_func102_002[] =
            {
                BSWAP_32BIG_C(0x903c89ecU), BSWAP_32BIG_C(0x1636da9dU), BSWAP_32BIG_C(0x361a6c7bU), BSWAP_32BIG_C(
                    0x9ca525ecU),
            };
            r_rsip_func102(Param_p34i_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p34i_func101_002[] =
            {
                BSWAP_32BIG_C(0xee14580aU), BSWAP_32BIG_C(0x3580867eU), BSWAP_32BIG_C(0xcb47fa31U), BSWAP_32BIG_C(
                    0xbd77c31cU),
            };
            r_rsip_func101(Param_p34i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
