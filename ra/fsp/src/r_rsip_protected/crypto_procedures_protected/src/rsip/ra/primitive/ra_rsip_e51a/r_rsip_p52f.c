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

rsip_ret_t r_rsip_p52f (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000052U);

    static const uint32_t Param_p52f_func101_001[] =
    {
        BSWAP_32BIG_C(0x7837c402U), BSWAP_32BIG_C(0x7f93686aU), BSWAP_32BIG_C(0x1794922aU), BSWAP_32BIG_C(0x646f50fdU),
    };
    r_rsip_func101(Param_p52f_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005202U);

    static const uint32_t Param_p52f_func101_002[] =
    {
        BSWAP_32BIG_C(0x4d06f5eaU), BSWAP_32BIG_C(0xb0564afdU), BSWAP_32BIG_C(0xb6e2f911U), BSWAP_32BIG_C(0x69d8d027U),
    };
    r_rsip_func101(Param_p52f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x013a8e02U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005202U);

    static const uint32_t Param_p52f_func101_003[] =
    {
        BSWAP_32BIG_C(0x556c74cdU), BSWAP_32BIG_C(0x8f7abcefU), BSWAP_32BIG_C(0x27a3d91aU), BSWAP_32BIG_C(0xe12e0bc5U),
    };
    r_rsip_func101(Param_p52f_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p52f_func100_001[] =
    {
        BSWAP_32BIG_C(0xbef22b11U), BSWAP_32BIG_C(0xbecfa02cU), BSWAP_32BIG_C(0x030631f7U), BSWAP_32BIG_C(0x83206983U),
    };
    r_rsip_func100(Param_p52f_func100_001);
    r_rsip_func_sub029(0x40000200U, 0xe7009d07U, 0x81900004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p52f_func100_002[] =
    {
        BSWAP_32BIG_C(0xe81f6f37U), BSWAP_32BIG_C(0xc62167beU), BSWAP_32BIG_C(0xe9f99abaU), BSWAP_32BIG_C(0x03f64998U),
    };
    r_rsip_func100(Param_p52f_func100_002);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_func_sub001(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p52f_func100_003[] =
    {
        BSWAP_32BIG_C(0x7902fa73U), BSWAP_32BIG_C(0x4b70644dU), BSWAP_32BIG_C(0xa5d8617bU), BSWAP_32BIG_C(0x9faa2747U),
    };
    r_rsip_func100(Param_p52f_func100_003);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);

    static const uint32_t Param_p52f_func100_004[] =
    {
        BSWAP_32BIG_C(0x544f39f7U), BSWAP_32BIG_C(0x9d970e29U), BSWAP_32BIG_C(0xbe204d09U), BSWAP_32BIG_C(0x563157b0U),
    };
    r_rsip_func100(Param_p52f_func100_004);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p52f_func102_001[] =
    {
        BSWAP_32BIG_C(0x94263f9aU), BSWAP_32BIG_C(0x6d606824U), BSWAP_32BIG_C(0x4d748050U), BSWAP_32BIG_C(0x37f46c6cU),
    };
    r_rsip_func102(Param_p52f_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
