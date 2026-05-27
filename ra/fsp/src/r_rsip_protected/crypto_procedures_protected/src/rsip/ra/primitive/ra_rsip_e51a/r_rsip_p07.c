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

rsip_ret_t r_rsip_p07 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00070001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000701U);

    static const uint32_t Param_p07_func101_001[] =
    {
        BSWAP_32BIG_C(0x2b8cfa4fU), BSWAP_32BIG_C(0xe4bb921bU), BSWAP_32BIG_C(0xd62d0dfbU), BSWAP_32BIG_C(0xfb3cc0ebU),
    };
    r_rsip_func101(Param_p07_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000007U);

    static const uint32_t Param_p07_func101_002[] =
    {
        BSWAP_32BIG_C(0x14c74b78U), BSWAP_32BIG_C(0xae7a894eU), BSWAP_32BIG_C(0xc29ad69dU), BSWAP_32BIG_C(0x44ee96c9U),
    };
    r_rsip_func101(Param_p07_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000007U);

    static const uint32_t Param_p07_func101_003[] =
    {
        BSWAP_32BIG_C(0xd630f09aU), BSWAP_32BIG_C(0x6b56d023U), BSWAP_32BIG_C(0x5f2a04b0U), BSWAP_32BIG_C(0xd40d019eU),
    };
    r_rsip_func101(Param_p07_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p07_func100_001[] =
    {
        BSWAP_32BIG_C(0xac328280U), BSWAP_32BIG_C(0x7295a54fU), BSWAP_32BIG_C(0x8639b49fU), BSWAP_32BIG_C(0xecaccbdcU),
    };
    r_rsip_func100(Param_p07_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000702U);

    static const uint32_t Param_p07_func101_004[] =
    {
        BSWAP_32BIG_C(0xaa75e6fdU), BSWAP_32BIG_C(0xd192de85U), BSWAP_32BIG_C(0x4fee36ffU), BSWAP_32BIG_C(0x3fd63c90U),
    };
    r_rsip_func101(Param_p07_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub029(0x40000000U, 0xe7009d45U, 0x81040000U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p07_func100_002[] =
    {
        BSWAP_32BIG_C(0xfa424195U), BSWAP_32BIG_C(0xa02ad773U), BSWAP_32BIG_C(0x24948af7U), BSWAP_32BIG_C(0x7fc9654cU),
    };
    r_rsip_func100(Param_p07_func100_002);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000001U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

    static const uint32_t Param_p07_func102_001[] =
    {
        BSWAP_32BIG_C(0xa34d52c8U), BSWAP_32BIG_C(0x2b63eb59U), BSWAP_32BIG_C(0xd03daa87U), BSWAP_32BIG_C(0x871e8f7cU),
    };
    r_rsip_func102(Param_p07_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
