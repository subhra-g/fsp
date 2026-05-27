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

rsip_ret_t r_rsip_p3c (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00003c01U);

    static const uint32_t Param_p3c_func101_001[] =
    {
        BSWAP_32BIG_C(0x6623dcbbU), BSWAP_32BIG_C(0x360a321dU), BSWAP_32BIG_C(0xbd4932c2U), BSWAP_32BIG_C(0x59d38244U),
    };
    r_rsip_func101(Param_p3c_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000003cU);

    static const uint32_t Param_p3c_func101_002[] =
    {
        BSWAP_32BIG_C(0x9e4ad544U), BSWAP_32BIG_C(0xba9f60aeU), BSWAP_32BIG_C(0xe3bd45ebU), BSWAP_32BIG_C(0xf9d1ab6bU),
    };
    r_rsip_func101(Param_p3c_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000028U);

    r_rsip_func_sub003(0x800103a0U, 0x0000003cU);

    static const uint32_t Param_p3c_func101_003[] =
    {
        BSWAP_32BIG_C(0x3005eeb3U), BSWAP_32BIG_C(0xc5c575ceU), BSWAP_32BIG_C(0x0b9279efU), BSWAP_32BIG_C(0xa4611eb6U),
    };
    r_rsip_func101(Param_p3c_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3c_func100_001[] =
    {
        BSWAP_32BIG_C(0x7b221004U), BSWAP_32BIG_C(0x0b91fa37U), BSWAP_32BIG_C(0xdc1bb9aaU), BSWAP_32BIG_C(0xd4288633U),
    };
    r_rsip_func100(Param_p3c_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x800103a0U, 0x00003c02U);

    static const uint32_t Param_p3c_func101_004[] =
    {
        BSWAP_32BIG_C(0x72585eefU), BSWAP_32BIG_C(0x48bda3b3U), BSWAP_32BIG_C(0x88935e97U), BSWAP_32BIG_C(0x81b51219U),
    };
    r_rsip_func101(Param_p3c_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003c03U);

    static const uint32_t Param_p3c_func101_005[] =
    {
        BSWAP_32BIG_C(0x5cd843eeU), BSWAP_32BIG_C(0xd80d9223U), BSWAP_32BIG_C(0x433ad1a8U), BSWAP_32BIG_C(0x6f73a940U),
    };
    r_rsip_func101(Param_p3c_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003c04U);

    static const uint32_t Param_p3c_func101_006[] =
    {
        BSWAP_32BIG_C(0xc5da015fU), BSWAP_32BIG_C(0xea0f73d4U), BSWAP_32BIG_C(0x64ed7786U), BSWAP_32BIG_C(0xc79cfec7U),
    };
    r_rsip_func101(Param_p3c_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3c_func100_002[] =
    {
        BSWAP_32BIG_C(0xb473dd6fU), BSWAP_32BIG_C(0x3267c347U), BSWAP_32BIG_C(0x390eecdbU), BSWAP_32BIG_C(0xc91011bcU),
    };
    r_rsip_func100(Param_p3c_func100_002);

    r_rsip_func_sub027(0x40000200U, 0xe7009d47U, 0x810c0000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    static const uint32_t Param_p3c_func100_003[] =
    {
        BSWAP_32BIG_C(0x74bde7cfU), BSWAP_32BIG_C(0xc89e185cU), BSWAP_32BIG_C(0xc37dfdf6U), BSWAP_32BIG_C(0x05d7f055U),
    };
    r_rsip_func100(Param_p3c_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000003U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

    static const uint32_t Param_p3c_func102_001[] =
    {
        BSWAP_32BIG_C(0x72347da7U), BSWAP_32BIG_C(0x4e3ce7cdU), BSWAP_32BIG_C(0x38082f42U), BSWAP_32BIG_C(0xaf58d31fU),
    };
    r_rsip_func102(Param_p3c_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
