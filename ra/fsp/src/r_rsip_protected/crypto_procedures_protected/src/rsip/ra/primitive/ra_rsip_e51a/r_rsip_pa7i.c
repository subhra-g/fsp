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

rsip_ret_t r_rsip_pa7i (const uint32_t InData_KeyIndex[],
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

    WR1_PROG(REG_1B00H, 0x00a70001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a7U);

    static const uint32_t Param_pa7i_func101_001[] =
    {
        BSWAP_32BIG_C(0x88dfa970U), BSWAP_32BIG_C(0xa8943563U), BSWAP_32BIG_C(0x24571bdbU), BSWAP_32BIG_C(0xc482f366U),
    };
    r_rsip_func101(Param_pa7i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a7U);

    static const uint32_t Param_pa7i_func101_002[] =
    {
        BSWAP_32BIG_C(0x893beed3U), BSWAP_32BIG_C(0xea49cd50U), BSWAP_32BIG_C(0x26ed1a30U), BSWAP_32BIG_C(0x8de57d47U),
    };
    r_rsip_func101(Param_pa7i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_pa7i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb4fd0ed9U), BSWAP_32BIG_C(0xca24cf2dU), BSWAP_32BIG_C(0x6284d46cU), BSWAP_32BIG_C(0x1d7f394eU),
    };
    r_rsip_func100(Param_pa7i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_pa7i_func100_002[] =
    {
        BSWAP_32BIG_C(0x38f1d1d5U), BSWAP_32BIG_C(0x6d1e76a3U), BSWAP_32BIG_C(0x09fe240cU), BSWAP_32BIG_C(0x27098b75U),
    };
    r_rsip_func100(Param_pa7i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pa7i_func100_003[] =
    {
        BSWAP_32BIG_C(0x6512547dU), BSWAP_32BIG_C(0x1641a52eU), BSWAP_32BIG_C(0x71f6a284U), BSWAP_32BIG_C(0x18a020adU),
    };
    r_rsip_func100(Param_pa7i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa7i_func102_001[] =
        {
            BSWAP_32BIG_C(0x0ee340daU), BSWAP_32BIG_C(0x6aa1f5deU), BSWAP_32BIG_C(0x02559e76U), BSWAP_32BIG_C(
                0xd48807b8U),
        };
        r_rsip_func102(Param_pa7i_func102_001);
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

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x0e108456U);

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
