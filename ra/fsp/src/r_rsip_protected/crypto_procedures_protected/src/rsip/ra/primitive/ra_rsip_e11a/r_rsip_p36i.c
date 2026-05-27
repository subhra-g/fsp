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

rsip_ret_t r_rsip_p36i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00360001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x00000036U);

    static const uint32_t Param_p36i_func101_001[] =
    {
        BSWAP_32BIG_C(0x4ed4d87aU), BSWAP_32BIG_C(0xe7be7fddU), BSWAP_32BIG_C(0x9ac5bf7dU), BSWAP_32BIG_C(0xe99fcb90U),
    };
    r_rsip_func101(Param_p36i_func101_001);
    r_rsip_func435(InData_KeyIndex, InData_IVType, InData_IV);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p36i_func100_001[] =
    {
        BSWAP_32BIG_C(0xf973ab57U), BSWAP_32BIG_C(0xd2692108U), BSWAP_32BIG_C(0x735be674U), BSWAP_32BIG_C(0x5f954263U),
    };
    r_rsip_func100(Param_p36i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p36i_func102_001[] =
        {
            BSWAP_32BIG_C(0xe7a84bb5U), BSWAP_32BIG_C(0x772fd39cU), BSWAP_32BIG_C(0x5f2953a4U), BSWAP_32BIG_C(
                0x2c4820daU),
        };
        r_rsip_func102(Param_p36i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p36i_func100_002[] =
        {
            BSWAP_32BIG_C(0x9e76554aU), BSWAP_32BIG_C(0x939f948fU), BSWAP_32BIG_C(0x2a0ea4d3U), BSWAP_32BIG_C(
                0x8ac3a2ffU),
        };
        r_rsip_func100(Param_p36i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p36i_func102_002[] =
            {
                BSWAP_32BIG_C(0x16ab968eU), BSWAP_32BIG_C(0x5a94796fU), BSWAP_32BIG_C(0xe266272fU), BSWAP_32BIG_C(
                    0xa2bcc543U),
            };
            r_rsip_func102(Param_p36i_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p36i_func101_002[] =
            {
                BSWAP_32BIG_C(0xa5b875b2U), BSWAP_32BIG_C(0xdead7e0fU), BSWAP_32BIG_C(0x055ababbU), BSWAP_32BIG_C(
                    0xacbe279fU),
            };
            r_rsip_func101(Param_p36i_func101_002);

            return RSIP_RET_PASS;
        }
    }
}
