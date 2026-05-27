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

rsip_ret_t r_rsip_p15 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00150001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001501U);

    static const uint32_t Param_p15_func101_001[] =
    {
        BSWAP_32BIG_C(0x8659d07eU), BSWAP_32BIG_C(0x92b87690U), BSWAP_32BIG_C(0xed77f7efU), BSWAP_32BIG_C(0xb3a1fe61U),
    };
    r_rsip_func101(Param_p15_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000015U);

    static const uint32_t Param_p15_func101_002[] =
    {
        BSWAP_32BIG_C(0x92c80c6cU), BSWAP_32BIG_C(0x0edc24d9U), BSWAP_32BIG_C(0xdb8b5e34U), BSWAP_32BIG_C(0x90d97832U),
    };
    r_rsip_func101(Param_p15_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000015U);

    static const uint32_t Param_p15_func101_003[] =
    {
        BSWAP_32BIG_C(0x7e207f82U), BSWAP_32BIG_C(0x45359812U), BSWAP_32BIG_C(0xf45bf106U), BSWAP_32BIG_C(0x6598f771U),
    };
    r_rsip_func101(Param_p15_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p15_func100_001[] =
    {
        BSWAP_32BIG_C(0x57eb27d5U), BSWAP_32BIG_C(0x50413466U), BSWAP_32BIG_C(0x7c06927aU), BSWAP_32BIG_C(0xd4e6c891U),
    };
    r_rsip_func100(Param_p15_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001502U);

    static const uint32_t Param_p15_func101_004[] =
    {
        BSWAP_32BIG_C(0xabe56aa8U), BSWAP_32BIG_C(0xaa66f03fU), BSWAP_32BIG_C(0xa16caba6U), BSWAP_32BIG_C(0x6d8b950cU),
    };
    r_rsip_func101(Param_p15_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001503U);

    static const uint32_t Param_p15_func101_005[] =
    {
        BSWAP_32BIG_C(0x1c52b274U), BSWAP_32BIG_C(0x5f247437U), BSWAP_32BIG_C(0x3ab9ef3fU), BSWAP_32BIG_C(0xf5242788U),
    };
    r_rsip_func101(Param_p15_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p15_func100_002[] =
    {
        BSWAP_32BIG_C(0x5ef994b2U), BSWAP_32BIG_C(0xf734a9f8U), BSWAP_32BIG_C(0x60ce0433U), BSWAP_32BIG_C(0xd670760dU),
    };
    r_rsip_func100(Param_p15_func100_002);
    r_rsip_func_sub029(0x40000100U, 0xe7009d47U, 0x81060000U);
    r_rsip_func_sub001(0x00890019U);
    r_rsip_func_sub001(0x00800009U);

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

    static const uint32_t Param_p15_func102_001[] =
    {
        BSWAP_32BIG_C(0x19e03380U), BSWAP_32BIG_C(0x6b5c6406U), BSWAP_32BIG_C(0x3b9b013aU), BSWAP_32BIG_C(0xcd3b6df7U),
    };
    r_rsip_func102(Param_p15_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
