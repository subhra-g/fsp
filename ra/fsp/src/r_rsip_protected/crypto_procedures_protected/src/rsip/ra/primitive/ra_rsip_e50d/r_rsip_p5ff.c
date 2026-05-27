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

rsip_ret_t r_rsip_p5ff (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub003(0x800103a0U, 0x0000005fU);

    static const uint32_t Param_p5ff_func101_001[] =
    {
        BSWAP_32BIG_C(0xc580920dU), BSWAP_32BIG_C(0x4062ba0fU), BSWAP_32BIG_C(0xf609c187U), BSWAP_32BIG_C(0xd3278b49U),
    };
    r_rsip_func101(Param_p5ff_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x00005f02U);

    static const uint32_t Param_p5ff_func101_002[] =
    {
        BSWAP_32BIG_C(0x4b0c1dbbU), BSWAP_32BIG_C(0xf1e969feU), BSWAP_32BIG_C(0x19f48baaU), BSWAP_32BIG_C(0xb48034aaU),
    };
    r_rsip_func101(Param_p5ff_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x013a8e02U);

    r_rsip_func_sub003(0x800103a0U, 0x00005f02U);

    static const uint32_t Param_p5ff_func101_003[] =
    {
        BSWAP_32BIG_C(0x18d94c6cU), BSWAP_32BIG_C(0xa15d68edU), BSWAP_32BIG_C(0x6d03a83fU), BSWAP_32BIG_C(0x94c4a260U),
    };
    r_rsip_func101(Param_p5ff_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p5ff_func100_001[] =
    {
        BSWAP_32BIG_C(0x944ef033U), BSWAP_32BIG_C(0x78b9cf50U), BSWAP_32BIG_C(0x8a33f2e8U), BSWAP_32BIG_C(0x6469c773U),
    };
    r_rsip_func100(Param_p5ff_func100_001);
    r_rsip_func_sub027(0x40000200U, 0xe7009d07U, 0x81900004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p5ff_func100_002[] =
    {
        BSWAP_32BIG_C(0x626704dbU), BSWAP_32BIG_C(0x76badd87U), BSWAP_32BIG_C(0xab4d1df8U), BSWAP_32BIG_C(0x8dd6627bU),
    };
    r_rsip_func100(Param_p5ff_func100_002);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_func_sub001(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p5ff_func100_003[] =
    {
        BSWAP_32BIG_C(0xb04f5418U), BSWAP_32BIG_C(0x5bc09678U), BSWAP_32BIG_C(0x9e776ebeU), BSWAP_32BIG_C(0xdede2f15U),
    };
    r_rsip_func100(Param_p5ff_func100_003);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);

    static const uint32_t Param_p5ff_func100_004[] =
    {
        BSWAP_32BIG_C(0xf4ca1fffU), BSWAP_32BIG_C(0xc38def93U), BSWAP_32BIG_C(0xa1cb42a0U), BSWAP_32BIG_C(0xdb5d4967U),
    };
    r_rsip_func100(Param_p5ff_func100_004);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p5ff_func102_001[] =
    {
        BSWAP_32BIG_C(0xc4647677U), BSWAP_32BIG_C(0xff9b81a5U), BSWAP_32BIG_C(0x84436d5bU), BSWAP_32BIG_C(0xeea12833U),
    };
    r_rsip_func102(Param_p5ff_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
