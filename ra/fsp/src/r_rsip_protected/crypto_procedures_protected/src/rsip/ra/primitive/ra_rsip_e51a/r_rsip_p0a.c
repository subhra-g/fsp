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

rsip_ret_t r_rsip_p0a (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000a0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000a01U);

    static const uint32_t Param_p0a_func101_001[] =
    {
        BSWAP_32BIG_C(0xa8f23ddcU), BSWAP_32BIG_C(0x03d3f5b3U), BSWAP_32BIG_C(0x6cfe5115U), BSWAP_32BIG_C(0xce886a44U),
    };
    r_rsip_func101(Param_p0a_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000aU);

    static const uint32_t Param_p0a_func101_002[] =
    {
        BSWAP_32BIG_C(0xfe6103c2U), BSWAP_32BIG_C(0xaff19ce7U), BSWAP_32BIG_C(0x8afd270eU), BSWAP_32BIG_C(0x000e36d0U),
    };
    r_rsip_func101(Param_p0a_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000001aU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000aU);

    static const uint32_t Param_p0a_func101_003[] =
    {
        BSWAP_32BIG_C(0x1efeae3cU), BSWAP_32BIG_C(0x01f0f7dcU), BSWAP_32BIG_C(0x215f8d58U), BSWAP_32BIG_C(0x807b3d17U),
    };
    r_rsip_func101(Param_p0a_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p0a_func100_001[] =
    {
        BSWAP_32BIG_C(0x57ee6a4bU), BSWAP_32BIG_C(0xf23b2c01U), BSWAP_32BIG_C(0xb6225974U), BSWAP_32BIG_C(0x78482520U),
    };
    r_rsip_func100(Param_p0a_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000a02U);

    static const uint32_t Param_p0a_func101_004[] =
    {
        BSWAP_32BIG_C(0xedc15dbcU), BSWAP_32BIG_C(0x663d6080U), BSWAP_32BIG_C(0xacefa043U), BSWAP_32BIG_C(0xcd90f8b1U),
    };
    r_rsip_func101(Param_p0a_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000a03U);

    static const uint32_t Param_p0a_func101_005[] =
    {
        BSWAP_32BIG_C(0x8971c83aU), BSWAP_32BIG_C(0x8632248fU), BSWAP_32BIG_C(0xb94afa61U), BSWAP_32BIG_C(0xb961ee63U),
    };
    r_rsip_func101(Param_p0a_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p0a_func100_002[] =
    {
        BSWAP_32BIG_C(0x90f50d97U), BSWAP_32BIG_C(0x8952ecb2U), BSWAP_32BIG_C(0x0e27f81dU), BSWAP_32BIG_C(0xef979cdcU),
    };
    r_rsip_func100(Param_p0a_func100_002);
    r_rsip_func_sub029(0x40000100U, 0xe7009d47U, 0x81070000U);
    r_rsip_func_sub001(0x0089001dU);
    r_rsip_func_sub001(0x00800005U);

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

    static const uint32_t Param_p0a_func102_001[] =
    {
        BSWAP_32BIG_C(0x96e46d58U), BSWAP_32BIG_C(0x8d4cb3fcU), BSWAP_32BIG_C(0x98f78456U), BSWAP_32BIG_C(0x844c6b6bU),
    };
    r_rsip_func102(Param_p0a_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
