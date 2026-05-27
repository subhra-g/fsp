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

rsip_ret_t r_rsip_p3f (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003f01U);

    static const uint32_t Param_p3f_func101_001[] =
    {
        BSWAP_32BIG_C(0xe5cc8770U), BSWAP_32BIG_C(0x21210170U), BSWAP_32BIG_C(0xccbf9c84U), BSWAP_32BIG_C(0x496e916dU),
    };
    r_rsip_func101(Param_p3f_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000003fU);

    static const uint32_t Param_p3f_func101_002[] =
    {
        BSWAP_32BIG_C(0x7c2987a4U), BSWAP_32BIG_C(0x9f00c16fU), BSWAP_32BIG_C(0xe9ff9eb8U), BSWAP_32BIG_C(0x9a15de96U),
    };
    r_rsip_func101(Param_p3f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000002bU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000003fU);

    static const uint32_t Param_p3f_func101_003[] =
    {
        BSWAP_32BIG_C(0xb1687ba5U), BSWAP_32BIG_C(0xf2a3f9a3U), BSWAP_32BIG_C(0xdd4d8b50U), BSWAP_32BIG_C(0x4214c5d6U),
    };
    r_rsip_func101(Param_p3f_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3f_func100_001[] =
    {
        BSWAP_32BIG_C(0xcd0e607dU), BSWAP_32BIG_C(0xecf00df6U), BSWAP_32BIG_C(0x2b2deb84U), BSWAP_32BIG_C(0xa08e4ed0U),
    };
    r_rsip_func100(Param_p3f_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003f02U);

    static const uint32_t Param_p3f_func101_004[] =
    {
        BSWAP_32BIG_C(0x63fe714aU), BSWAP_32BIG_C(0x5fc32757U), BSWAP_32BIG_C(0xb43d4275U), BSWAP_32BIG_C(0x36e6823dU),
    };
    r_rsip_func101(Param_p3f_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003f03U);

    static const uint32_t Param_p3f_func101_005[] =
    {
        BSWAP_32BIG_C(0x4b0d7a04U), BSWAP_32BIG_C(0x17159db3U), BSWAP_32BIG_C(0x23c00ee8U), BSWAP_32BIG_C(0xd3780adbU),
    };
    r_rsip_func101(Param_p3f_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003f04U);

    static const uint32_t Param_p3f_func101_006[] =
    {
        BSWAP_32BIG_C(0xc676fb8dU), BSWAP_32BIG_C(0xba8c37c3U), BSWAP_32BIG_C(0x3b357521U), BSWAP_32BIG_C(0x87cf6e19U),
    };
    r_rsip_func101(Param_p3f_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003f05U);

    static const uint32_t Param_p3f_func101_007[] =
    {
        BSWAP_32BIG_C(0xb5f740e3U), BSWAP_32BIG_C(0xb9ce332cU), BSWAP_32BIG_C(0xb5fa3856U), BSWAP_32BIG_C(0xff6a9f74U),
    };
    r_rsip_func101(Param_p3f_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3f_func100_002[] =
    {
        BSWAP_32BIG_C(0xe634a46cU), BSWAP_32BIG_C(0x7a387a14U), BSWAP_32BIG_C(0xebd962e2U), BSWAP_32BIG_C(0x59490732U),
    };
    r_rsip_func100(Param_p3f_func100_002);

    r_rsip_func_sub029(0x40000300U, 0xe7009d47U, 0x81100000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p3f_func100_003[] =
    {
        BSWAP_32BIG_C(0xdde29597U), BSWAP_32BIG_C(0xdb98060aU), BSWAP_32BIG_C(0xb4c8220bU), BSWAP_32BIG_C(0x83e8ec4eU),
    };
    r_rsip_func100(Param_p3f_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3f_func102_001[] =
    {
        BSWAP_32BIG_C(0xc033813fU), BSWAP_32BIG_C(0xa72fd4eaU), BSWAP_32BIG_C(0xd4e2e703U), BSWAP_32BIG_C(0x7c992189U),
    };
    r_rsip_func102(Param_p3f_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
