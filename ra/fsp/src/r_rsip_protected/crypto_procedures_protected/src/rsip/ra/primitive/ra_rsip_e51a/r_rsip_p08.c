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

rsip_ret_t r_rsip_p08 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00080001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000801U);

    static const uint32_t Param_p08_func101_001[] =
    {
        BSWAP_32BIG_C(0x5f589dfbU), BSWAP_32BIG_C(0x150a25beU), BSWAP_32BIG_C(0x6d98128fU), BSWAP_32BIG_C(0xa71a463fU),
    };
    r_rsip_func101(Param_p08_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000008U);

    static const uint32_t Param_p08_func101_002[] =
    {
        BSWAP_32BIG_C(0x45693b6bU), BSWAP_32BIG_C(0x68cbd215U), BSWAP_32BIG_C(0xcd24384aU), BSWAP_32BIG_C(0x31dc4e9cU),
    };
    r_rsip_func101(Param_p08_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000008U);

    static const uint32_t Param_p08_func101_003[] =
    {
        BSWAP_32BIG_C(0x5be22900U), BSWAP_32BIG_C(0xf07394d9U), BSWAP_32BIG_C(0x8dbad761U), BSWAP_32BIG_C(0x00246267U),
    };
    r_rsip_func101(Param_p08_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p08_func100_001[] =
    {
        BSWAP_32BIG_C(0xda537d01U), BSWAP_32BIG_C(0xf707e590U), BSWAP_32BIG_C(0x50229f5dU), BSWAP_32BIG_C(0x7738a7b5U),
    };
    r_rsip_func100(Param_p08_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000802U);

    static const uint32_t Param_p08_func101_004[] =
    {
        BSWAP_32BIG_C(0xd9b62a99U), BSWAP_32BIG_C(0x3a3600a7U), BSWAP_32BIG_C(0x4a6881b3U), BSWAP_32BIG_C(0x2eb0bfeeU),
    };
    r_rsip_func101(Param_p08_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000803U);

    static const uint32_t Param_p08_func101_005[] =
    {
        BSWAP_32BIG_C(0x10881f30U), BSWAP_32BIG_C(0x3829e559U), BSWAP_32BIG_C(0x5f41533aU), BSWAP_32BIG_C(0xe5ba4884U),
    };
    r_rsip_func101(Param_p08_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);
    static const uint32_t Param_p08_func100_002[] =
    {
        BSWAP_32BIG_C(0x346078a8U), BSWAP_32BIG_C(0x76f267b6U), BSWAP_32BIG_C(0x3385d467U), BSWAP_32BIG_C(0x60836a5aU),
    };
    r_rsip_func100(Param_p08_func100_002);

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

    static const uint32_t Param_p08_func102_001[] =
    {
        BSWAP_32BIG_C(0x8412a131U), BSWAP_32BIG_C(0xd88c9644U), BSWAP_32BIG_C(0x39eba840U), BSWAP_32BIG_C(0x8bc5ab71U),
    };
    r_rsip_func102(Param_p08_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
