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
    static const uint32_t Param_peef_func100_001[] =
    {
        BSWAP_32BIG_C(0xa0ad0f3aU), BSWAP_32BIG_C(0x4fb03125U), BSWAP_32BIG_C(0x27640e0cU), BSWAP_32BIG_C(0x1e8ebcfbU),
    };
    r_rsip_func100(Param_peef_func100_001);
    r_rsip_func103();

    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

    r_rsip_func_sub003(0x80010000U, 0x03410005U);
    r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

    r_rsip_func_sub002(0x800100e0U, 0x0000ee02U);

    static const uint32_t Param_peef_func101_001[] =
    {
        BSWAP_32BIG_C(0x2a37a8d6U), BSWAP_32BIG_C(0x6f0b043aU), BSWAP_32BIG_C(0xbcea8475U), BSWAP_32BIG_C(0x6bef5bd9U),
    };
    r_rsip_func101(Param_peef_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x010f6caaU);

    r_rsip_func_sub002(0x800100e0U, 0x0000ee02U);

    static const uint32_t Param_peef_func101_002[] =
    {
        BSWAP_32BIG_C(0x45cf7860U), BSWAP_32BIG_C(0x2a3f037dU), BSWAP_32BIG_C(0x96eb6b18U), BSWAP_32BIG_C(0xf767f714U),
    };
    r_rsip_func101(Param_peef_func101_002);
    r_rsip_func044();

    static const uint32_t Param_peef_func100_002[] =
    {
        BSWAP_32BIG_C(0xfb2e9defU), BSWAP_32BIG_C(0xe16db998U), BSWAP_32BIG_C(0x00e0d5b4U), BSWAP_32BIG_C(0x46f3d96dU),
    };
    r_rsip_func100(Param_peef_func100_002);
    WR1_PROG(REG_00B0H, 0x0000187eU);

    WR1_PROG(REG_00D4H, 0x40000100U);
    r_rsip_func_sub006(0xe7009d07U, 0x00430021U);

    WR1_PROG(REG_0008H, 0x00001022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[5]);

    static const uint32_t Param_peef_func100_003[] =
    {
        BSWAP_32BIG_C(0x31d90cd8U), BSWAP_32BIG_C(0x361b034cU), BSWAP_32BIG_C(0x536592cbU), BSWAP_32BIG_C(0xbb49c143U),
    };
    r_rsip_func100(Param_peef_func100_003);
    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    r_rsip_func_sub006(0x09108105U, 0x00410011U);

    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_peef_func100_004[] =
    {
        BSWAP_32BIG_C(0x56e900edU), BSWAP_32BIG_C(0x8e52006dU), BSWAP_32BIG_C(0x6f9b4756U), BSWAP_32BIG_C(0x1743b4afU),
    };
    r_rsip_func100(Param_peef_func100_004);
    WR1_PROG(REG_009CH, 0x81010000U);
    WR1_PROG(REG_0008H, 0x00005006U);
    WAIT_STS(REG_0008H, 30, 1);
    RD1_ADDR(REG_002CH, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_peef_func102_001[] =
    {
        BSWAP_32BIG_C(0x83d47976U), BSWAP_32BIG_C(0xd1f38d36U), BSWAP_32BIG_C(0xc67716beU), BSWAP_32BIG_C(0xfc8131e0U),
    };
    r_rsip_func102(Param_peef_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
