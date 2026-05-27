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

rsip_ret_t r_rsip_p29i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00290001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x00000029U);

    static const uint32_t Param_p29i_func101_001[] =
    {
        BSWAP_32BIG_C(0x1c598dd1U), BSWAP_32BIG_C(0x4f10c0d9U), BSWAP_32BIG_C(0x3a9929a6U), BSWAP_32BIG_C(0x5b1c091aU),
    };
    r_rsip_func101(Param_p29i_func101_001);
    r_rsip_func431(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p29i_func100_001[] =
    {
        BSWAP_32BIG_C(0xe19dd5acU), BSWAP_32BIG_C(0x02a7b6aaU), BSWAP_32BIG_C(0xc3298be7U), BSWAP_32BIG_C(0x0cba7e6fU),
    };
    r_rsip_func100(Param_p29i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p29i_func102_001[] =
        {
            BSWAP_32BIG_C(0xf3a2ef8fU), BSWAP_32BIG_C(0xe0b2cb89U), BSWAP_32BIG_C(0x7b27c987U), BSWAP_32BIG_C(
                0x17a2f704U),
        };
        r_rsip_func102(Param_p29i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p29i_func100_002[] =
        {
            BSWAP_32BIG_C(0x4c609779U), BSWAP_32BIG_C(0x93a8eaa8U), BSWAP_32BIG_C(0x69a67792U), BSWAP_32BIG_C(
                0x4cba4d45U),
        };
        r_rsip_func100(Param_p29i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p29i_func102_002[] =
            {
                BSWAP_32BIG_C(0xec51485aU), BSWAP_32BIG_C(0x291bd586U), BSWAP_32BIG_C(0xe010216bU), BSWAP_32BIG_C(
                    0xfeaeac30U),
            };
            r_rsip_func102(Param_p29i_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p29i_func101_002[] =
            {
                BSWAP_32BIG_C(0xa33039bfU), BSWAP_32BIG_C(0x76e03d13U), BSWAP_32BIG_C(0xd468ba3aU), BSWAP_32BIG_C(
                    0x25d8e0c6U),
            };
            r_rsip_func101(Param_p29i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
