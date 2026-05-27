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

    r_rsip_func_sub002(0x800100e0U, 0x00000032U);

    static const uint32_t Param_p32i_func101_001[] =
    {
        BSWAP_32BIG_C(0xa6c5a01dU), BSWAP_32BIG_C(0xf7812d3fU), BSWAP_32BIG_C(0x62bc8a4dU), BSWAP_32BIG_C(0x37f44a79U),
    };
    r_rsip_func101(Param_p32i_func101_001);
    r_rsip_func431(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p32i_func100_001[] =
    {
        BSWAP_32BIG_C(0xa19a0862U), BSWAP_32BIG_C(0x88d1fc89U), BSWAP_32BIG_C(0x7b0cf154U), BSWAP_32BIG_C(0x041e0f57U),
    };
    r_rsip_func100(Param_p32i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p32i_func102_001[] =
        {
            BSWAP_32BIG_C(0xb67cfacaU), BSWAP_32BIG_C(0xa67aee62U), BSWAP_32BIG_C(0x5ff65388U), BSWAP_32BIG_C(
                0x0d048d40U),
        };
        r_rsip_func102(Param_p32i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p32i_func100_002[] =
        {
            BSWAP_32BIG_C(0xb4a6e22aU), BSWAP_32BIG_C(0xdaea6d0bU), BSWAP_32BIG_C(0x12d430a5U), BSWAP_32BIG_C(
                0x70694548U),
        };
        r_rsip_func100(Param_p32i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p32i_func102_002[] =
            {
                BSWAP_32BIG_C(0x6932226dU), BSWAP_32BIG_C(0x9da81a42U), BSWAP_32BIG_C(0xa43514edU), BSWAP_32BIG_C(
                    0xd7d0b23aU),
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
                BSWAP_32BIG_C(0x072ab489U), BSWAP_32BIG_C(0x9667b1c4U), BSWAP_32BIG_C(0xa2aa407fU), BSWAP_32BIG_C(
                    0xfc9aae44U),
            };
            r_rsip_func101(Param_p32i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
