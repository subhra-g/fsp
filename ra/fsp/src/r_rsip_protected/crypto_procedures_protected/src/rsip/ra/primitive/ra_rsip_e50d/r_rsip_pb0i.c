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

rsip_ret_t r_rsip_pb0i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00b00001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x000000b0U);

    static const uint32_t Param_pb0i_func101_001[] =
    {
        BSWAP_32BIG_C(0x76ca7abdU), BSWAP_32BIG_C(0xfbd732abU), BSWAP_32BIG_C(0x025ad2a8U), BSWAP_32BIG_C(0x8523dd4aU),
    };
    r_rsip_func101(Param_pb0i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x800103a0U, 0x000000b0U);

    static const uint32_t Param_pb0i_func101_002[] =
    {
        BSWAP_32BIG_C(0xbf594a4cU), BSWAP_32BIG_C(0x70a5177eU), BSWAP_32BIG_C(0xcad7ddffU), BSWAP_32BIG_C(0x28104d46U),
    };
    r_rsip_func101(Param_pb0i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_pb0i_func100_001[] =
    {
        BSWAP_32BIG_C(0x38b1a9e2U), BSWAP_32BIG_C(0xdfaa2cb5U), BSWAP_32BIG_C(0xf599039dU), BSWAP_32BIG_C(0x2eb9cd41U),
    };
    r_rsip_func100(Param_pb0i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_pb0i_func100_002[] =
    {
        BSWAP_32BIG_C(0x01b95625U), BSWAP_32BIG_C(0x3fd7dc15U), BSWAP_32BIG_C(0xd0bab388U), BSWAP_32BIG_C(0xf8409483U),
    };
    r_rsip_func100(Param_pb0i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pb0i_func100_003[] =
    {
        BSWAP_32BIG_C(0x1f6186e8U), BSWAP_32BIG_C(0xa10e77acU), BSWAP_32BIG_C(0x43dd6396U), BSWAP_32BIG_C(0x4e55e96fU),
    };
    r_rsip_func100(Param_pb0i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb0i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc819606bU), BSWAP_32BIG_C(0x9a23f3faU), BSWAP_32BIG_C(0x20a6098aU), BSWAP_32BIG_C(
                0x18815050U),
        };
        r_rsip_func102(Param_pb0i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub020(0x000003c1U, 0x08000145U);
        WR4_ADDR(REG_1420H, &InData_IV[0]);

        WR1_PROG(REG_1824H, 0x08000065U);
        r_rsip_func_sub001(0x00410011U);

        r_rsip_func_sub020(0x000000a1U, 0x07000c04U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub020(0x000000a1U, 0x08000054U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub025(0x00020061U, 0x40000010U, 0x0e108406U);

        for (iLoop = 0U; iLoop < Header_Len; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Header[iLoop]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func216();

        return RSIP_RET_PASS;
    }
}
