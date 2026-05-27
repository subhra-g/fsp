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

rsip_ret_t r_rsip_peef (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub003(0x800103a0U, 0x00000eefU);

    static const uint32_t Param_peef_func101_001[] =
    {
        BSWAP_32BIG_C(0x1cd37b16U), BSWAP_32BIG_C(0x79b1beb3U), BSWAP_32BIG_C(0x387388f7U), BSWAP_32BIG_C(0x52ed2c47U),
    };
    r_rsip_func101(Param_peef_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000ee02U);

    static const uint32_t Param_peef_func101_002[] =
    {
        BSWAP_32BIG_C(0x4c3dd6ccU), BSWAP_32BIG_C(0xa86d749dU), BSWAP_32BIG_C(0xf233ee19U), BSWAP_32BIG_C(0xbc017d62U),
    };
    r_rsip_func101(Param_peef_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x010f6caaU);

    r_rsip_func_sub003(0x800103a0U, 0x0000ee02U);

    static const uint32_t Param_peef_func101_003[] =
    {
        BSWAP_32BIG_C(0x102e4f3eU), BSWAP_32BIG_C(0x3252d21bU), BSWAP_32BIG_C(0xc487f5b4U), BSWAP_32BIG_C(0xced32d82U),
    };
    r_rsip_func101(Param_peef_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_peef_func100_001[] =
    {
        BSWAP_32BIG_C(0xe7428a00U), BSWAP_32BIG_C(0x1e756033U), BSWAP_32BIG_C(0x3b4f4374U), BSWAP_32BIG_C(0xe6c30d65U),
    };
    r_rsip_func100(Param_peef_func100_001);
    r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81880004U);
    r_rsip_func_sub001(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);

    static const uint32_t Param_peef_func100_002[] =
    {
        BSWAP_32BIG_C(0x58bf62c0U), BSWAP_32BIG_C(0x7ba1c02eU), BSWAP_32BIG_C(0x54b31bfcU), BSWAP_32BIG_C(0xe4949015U),
    };
    r_rsip_func100(Param_peef_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_peef_func100_003[] =
    {
        BSWAP_32BIG_C(0x73a3ea16U), BSWAP_32BIG_C(0xa7350895U), BSWAP_32BIG_C(0x28302064U), BSWAP_32BIG_C(0x0e271a19U),
    };
    r_rsip_func100(Param_peef_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_peef_func102_001[] =
    {
        BSWAP_32BIG_C(0x32eca69fU), BSWAP_32BIG_C(0x65a6901fU), BSWAP_32BIG_C(0x995a9fdaU), BSWAP_32BIG_C(0x57867118U),
    };
    r_rsip_func102(Param_peef_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
