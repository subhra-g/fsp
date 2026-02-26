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

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000034U, 0x00000000U);

    static const uint32_t Param_p34i_func101_001[] =
    {
        BSWAP_32BIG_C(0x8c0573eeU), BSWAP_32BIG_C(0x4b623f03U), BSWAP_32BIG_C(0x294c9e8cU), BSWAP_32BIG_C(0xf99967efU),
    };
    r_rsip_func101(Param_p34i_func101_001);
    r_rsip_func435(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_p34i_func100_001[] =
    {
        BSWAP_32BIG_C(0xe57b430aU), BSWAP_32BIG_C(0x524f37edU), BSWAP_32BIG_C(0x636e0603U), BSWAP_32BIG_C(0x2c5a06c3U),
    };
    r_rsip_func100(Param_p34i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p34i_func102_001[] =
        {
            BSWAP_32BIG_C(0x4fe8389dU), BSWAP_32BIG_C(0x0313641dU), BSWAP_32BIG_C(0x7bb836faU), BSWAP_32BIG_C(
                0xff0d45d0U),
        };
        r_rsip_func102(Param_p34i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x38008800U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_p34i_func100_002[] =
        {
            BSWAP_32BIG_C(0xe2b670d7U), BSWAP_32BIG_C(0x87898775U), BSWAP_32BIG_C(0xb0ed8f9fU), BSWAP_32BIG_C(
                0x9a1a6e63U),
        };
        r_rsip_func100(Param_p34i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p34i_func102_002[] =
            {
                BSWAP_32BIG_C(0x312d0b7bU), BSWAP_32BIG_C(0xe6b9a7bbU), BSWAP_32BIG_C(0x142abb0bU), BSWAP_32BIG_C(
                    0x883d0eedU),
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
                BSWAP_32BIG_C(0xb05f1b1bU), BSWAP_32BIG_C(0xd1998a93U), BSWAP_32BIG_C(0x886b7bf4U), BSWAP_32BIG_C(
                    0xf68aaef6U),
            };
            r_rsip_func101(Param_p34i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
