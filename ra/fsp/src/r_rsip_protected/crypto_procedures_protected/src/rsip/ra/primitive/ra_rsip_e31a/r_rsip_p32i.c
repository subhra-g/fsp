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

rsip_ret_t r_rsip_p32i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00320001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000032U, 0x00000000U);

    static const uint32_t Param_p32i_func101_001[] =
    {
        BSWAP_32BIG_C(0xbe1a061cU), BSWAP_32BIG_C(0x6879f341U), BSWAP_32BIG_C(0x710470ccU), BSWAP_32BIG_C(0xdbc46aa4U),
    };
    r_rsip_func101(Param_p32i_func101_001);
    r_rsip_func431(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_p32i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb016d559U), BSWAP_32BIG_C(0xe5381e18U), BSWAP_32BIG_C(0x08884d07U), BSWAP_32BIG_C(0x265d77cdU),
    };
    r_rsip_func100(Param_p32i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p32i_func102_001[] =
        {
            BSWAP_32BIG_C(0x2ff6616fU), BSWAP_32BIG_C(0xa16cff81U), BSWAP_32BIG_C(0xcfb1d788U), BSWAP_32BIG_C(
                0xff93faa5U),
        };
        r_rsip_func102(Param_p32i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x38008800U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_p32i_func100_002[] =
        {
            BSWAP_32BIG_C(0x0886eb9dU), BSWAP_32BIG_C(0xa258e19aU), BSWAP_32BIG_C(0x26f2c085U), BSWAP_32BIG_C(
                0x3b379bd6U),
        };
        r_rsip_func100(Param_p32i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p32i_func102_002[] =
            {
                BSWAP_32BIG_C(0xccdd0eb5U), BSWAP_32BIG_C(0xbf12c126U), BSWAP_32BIG_C(0x978f003fU), BSWAP_32BIG_C(
                    0x93ca3fdbU),
            };
            r_rsip_func102(Param_p32i_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p32i_func101_002[] =
            {
                BSWAP_32BIG_C(0x2095a093U), BSWAP_32BIG_C(0x65533592U), BSWAP_32BIG_C(0x8b8705d1U), BSWAP_32BIG_C(
                    0x3535fc5cU),
            };
            r_rsip_func101(Param_p32i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
