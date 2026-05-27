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

rsip_ret_t r_rsip_p0b (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000b0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000b01U);

    static const uint32_t Param_p0b_func101_001[] =
    {
        BSWAP_32BIG_C(0x4842f6a2U), BSWAP_32BIG_C(0xa209ce9bU), BSWAP_32BIG_C(0x303c5d3cU), BSWAP_32BIG_C(0x9523ece0U),
    };
    r_rsip_func101(Param_p0b_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000bU);

    static const uint32_t Param_p0b_func101_002[] =
    {
        BSWAP_32BIG_C(0x4c2a99e5U), BSWAP_32BIG_C(0x8aee295dU), BSWAP_32BIG_C(0xd11e90afU), BSWAP_32BIG_C(0x1ba3160dU),
    };
    r_rsip_func101(Param_p0b_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000001bU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000bU);

    static const uint32_t Param_p0b_func101_003[] =
    {
        BSWAP_32BIG_C(0x62c1f37bU), BSWAP_32BIG_C(0x1d97b516U), BSWAP_32BIG_C(0x27192504U), BSWAP_32BIG_C(0xbdad33bfU),
    };
    r_rsip_func101(Param_p0b_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p0b_func100_001[] =
    {
        BSWAP_32BIG_C(0x451fcb42U), BSWAP_32BIG_C(0x93430809U), BSWAP_32BIG_C(0xb2d13a62U), BSWAP_32BIG_C(0x5f6a085fU),
    };
    r_rsip_func100(Param_p0b_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000b02U);

    static const uint32_t Param_p0b_func101_004[] =
    {
        BSWAP_32BIG_C(0x12bbca56U), BSWAP_32BIG_C(0xf21d3cadU), BSWAP_32BIG_C(0x4c17f2cbU), BSWAP_32BIG_C(0xc3ad1732U),
    };
    r_rsip_func101(Param_p0b_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000b03U);

    static const uint32_t Param_p0b_func101_005[] =
    {
        BSWAP_32BIG_C(0x653c699eU), BSWAP_32BIG_C(0xca77f89cU), BSWAP_32BIG_C(0xc3c67a93U), BSWAP_32BIG_C(0xb605724aU),
    };
    r_rsip_func101(Param_p0b_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);
    static const uint32_t Param_p0b_func100_002[] =
    {
        BSWAP_32BIG_C(0xdba1f209U), BSWAP_32BIG_C(0xac9e20a4U), BSWAP_32BIG_C(0x563dbe64U), BSWAP_32BIG_C(0xb9efa32eU),
    };
    r_rsip_func100(Param_p0b_func100_002);

    r_rsip_func_sub029(0x40000100U, 0xe7009d47U, 0x81080000U);
    r_rsip_func_sub001(0x00890021U);

    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000002U));

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    static const uint32_t Param_p0b_func102_001[] =
    {
        BSWAP_32BIG_C(0xc8ef061fU), BSWAP_32BIG_C(0x50a96df1U), BSWAP_32BIG_C(0xf06cd8fbU), BSWAP_32BIG_C(0x260bd72cU),
    };
    r_rsip_func102(Param_p0b_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
