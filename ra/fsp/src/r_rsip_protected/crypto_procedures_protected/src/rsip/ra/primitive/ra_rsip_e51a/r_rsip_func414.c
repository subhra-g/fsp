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

void r_rsip_func414 (uint32_t ARG1[])
{
    WR1_PROG(REG_1600H, 0x0000379dU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f414U);

    static const uint32_t Param_func414_func101_001[] =
    {
        BSWAP_32BIG_C(0xf6219afaU), BSWAP_32BIG_C(0x70cece3eU), BSWAP_32BIG_C(0xc1635e92U), BSWAP_32BIG_C(0xe0c9d16bU),
    };
    r_rsip_func101(Param_func414_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f414U);

    static const uint32_t Param_func414_func101_002[] =
    {
        BSWAP_32BIG_C(0x80ab7718U), BSWAP_32BIG_C(0x967cd68cU), BSWAP_32BIG_C(0xde25544fU), BSWAP_32BIG_C(0xc7153b3aU),
    };
    r_rsip_func101(Param_func414_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x010f6caaU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f414U);

    static const uint32_t Param_func414_func101_003[] =
    {
        BSWAP_32BIG_C(0x31d44933U), BSWAP_32BIG_C(0xb12bb6e1U), BSWAP_32BIG_C(0x7767b4ccU), BSWAP_32BIG_C(0x78b69ff4U),
    };
    r_rsip_func101(Param_func414_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_func414_func100_001[] =
    {
        BSWAP_32BIG_C(0x4e2c09abU), BSWAP_32BIG_C(0xb09e3a2aU), BSWAP_32BIG_C(0x04dff962U), BSWAP_32BIG_C(0xbe5381c6U),
    };
    r_rsip_func100(Param_func414_func100_001);
    r_rsip_func_sub029(0x40000100U, 0xe7009d07U, 0x81880004U);
    r_rsip_func_sub001(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[5]);

    static const uint32_t Param_func414_func100_002[] =
    {
        BSWAP_32BIG_C(0xb6310e63U), BSWAP_32BIG_C(0x3d515da6U), BSWAP_32BIG_C(0xb65f2e9aU), BSWAP_32BIG_C(0xa5a2e87eU),
    };
    r_rsip_func100(Param_func414_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &ARG1[9]);

    static const uint32_t Param_func414_func100_003[] =
    {
        BSWAP_32BIG_C(0xe4b75707U), BSWAP_32BIG_C(0x1ba73c28U), BSWAP_32BIG_C(0xcb9bf17eU), BSWAP_32BIG_C(0x8e765d45U),
    };
    r_rsip_func100(Param_func414_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &ARG1[0]);

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
