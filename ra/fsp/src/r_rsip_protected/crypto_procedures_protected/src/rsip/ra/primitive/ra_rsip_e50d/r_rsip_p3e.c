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

rsip_ret_t r_rsip_p3e (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00003e01U);

    static const uint32_t Param_p3e_func101_001[] =
    {
        BSWAP_32BIG_C(0x06005ab1U), BSWAP_32BIG_C(0xa36f5dd6U), BSWAP_32BIG_C(0x1a1407b3U), BSWAP_32BIG_C(0x65ffcb7dU),
    };
    r_rsip_func101(Param_p3e_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000003eU);

    static const uint32_t Param_p3e_func101_002[] =
    {
        BSWAP_32BIG_C(0x46012c3cU), BSWAP_32BIG_C(0xeef99d2bU), BSWAP_32BIG_C(0x9f6e4701U), BSWAP_32BIG_C(0x306da1d2U),
    };
    r_rsip_func101(Param_p3e_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000002aU);

    r_rsip_func_sub003(0x800103a0U, 0x0000003eU);

    static const uint32_t Param_p3e_func101_003[] =
    {
        BSWAP_32BIG_C(0xb4c24b93U), BSWAP_32BIG_C(0xd29e9802U), BSWAP_32BIG_C(0x61686ffeU), BSWAP_32BIG_C(0x675d0b73U),
    };
    r_rsip_func101(Param_p3e_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3e_func100_001[] =
    {
        BSWAP_32BIG_C(0x1ee61a43U), BSWAP_32BIG_C(0x4939033bU), BSWAP_32BIG_C(0x5a826d99U), BSWAP_32BIG_C(0xc2330fabU),
    };
    r_rsip_func100(Param_p3e_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x800103a0U, 0x00003e02U);

    static const uint32_t Param_p3e_func101_004[] =
    {
        BSWAP_32BIG_C(0xf8dc6d84U), BSWAP_32BIG_C(0x067c4344U), BSWAP_32BIG_C(0x3c8944fdU), BSWAP_32BIG_C(0x1a11d635U),
    };
    r_rsip_func101(Param_p3e_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003e03U);

    static const uint32_t Param_p3e_func101_005[] =
    {
        BSWAP_32BIG_C(0x9d92b024U), BSWAP_32BIG_C(0xde638b7dU), BSWAP_32BIG_C(0xbe7d87dfU), BSWAP_32BIG_C(0xbea0fa4dU),
    };
    r_rsip_func101(Param_p3e_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003e04U);

    static const uint32_t Param_p3e_func101_006[] =
    {
        BSWAP_32BIG_C(0x32828eb2U), BSWAP_32BIG_C(0xa80426eaU), BSWAP_32BIG_C(0xe4590065U), BSWAP_32BIG_C(0xb7cacfdbU),
    };
    r_rsip_func101(Param_p3e_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003e05U);

    static const uint32_t Param_p3e_func101_007[] =
    {
        BSWAP_32BIG_C(0xfa32de6eU), BSWAP_32BIG_C(0x3ae4c743U), BSWAP_32BIG_C(0xcf19ed49U), BSWAP_32BIG_C(0xb25f3c4fU),
    };
    r_rsip_func101(Param_p3e_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3e_func100_002[] =
    {
        BSWAP_32BIG_C(0x0cc6291bU), BSWAP_32BIG_C(0xc96aba36U), BSWAP_32BIG_C(0x637b929fU), BSWAP_32BIG_C(0xa15ed7f4U),
    };
    r_rsip_func100(Param_p3e_func100_002);

    r_rsip_func_sub027(0x40000300U, 0xe7009d47U, 0x81100000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p3e_func100_003[] =
    {
        BSWAP_32BIG_C(0x078583dbU), BSWAP_32BIG_C(0xa339896aU), BSWAP_32BIG_C(0x76412dd8U), BSWAP_32BIG_C(0x257ee941U),
    };
    r_rsip_func100(Param_p3e_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3e_func102_001[] =
    {
        BSWAP_32BIG_C(0xe5afa511U), BSWAP_32BIG_C(0xe1852370U), BSWAP_32BIG_C(0xb8d9e32dU), BSWAP_32BIG_C(0x61c0e8d6U),
    };
    r_rsip_func102(Param_p3e_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
