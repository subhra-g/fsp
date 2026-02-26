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
        BSWAP_32BIG_C(0xec4bb937U), BSWAP_32BIG_C(0xe8062b64U), BSWAP_32BIG_C(0xeb4b98a8U), BSWAP_32BIG_C(0x6dd96185U),
    };
    r_rsip_func100(Param_peef_func100_001);
    r_rsip_func103();

    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

    r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ee02U, 0x00000000U);

    static const uint32_t Param_peef_func101_001[] =
    {
        BSWAP_32BIG_C(0xd4a337d7U), BSWAP_32BIG_C(0xa3b7d462U), BSWAP_32BIG_C(0x10569334U), BSWAP_32BIG_C(0xc1ca9236U),
    };
    r_rsip_func101(Param_peef_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x010f6caaU);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ee02U, 0x00000000U);

    static const uint32_t Param_peef_func101_002[] =
    {
        BSWAP_32BIG_C(0x525c9965U), BSWAP_32BIG_C(0x6405e43cU), BSWAP_32BIG_C(0x902dc3dfU), BSWAP_32BIG_C(0xfac38e15U),
    };
    r_rsip_func101(Param_peef_func101_002);
    r_rsip_func044();

    static const uint32_t Param_peef_func100_002[] =
    {
        BSWAP_32BIG_C(0x85af574cU), BSWAP_32BIG_C(0x0414bc7eU), BSWAP_32BIG_C(0xf8913c32U), BSWAP_32BIG_C(0x56c08b48U),
    };
    r_rsip_func100(Param_peef_func100_002);
    WR1_PROG(REG_00B0H, 0x0000187eU);

    r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00430021U, 0x00001022U);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[5]);

    static const uint32_t Param_peef_func100_003[] =
    {
        BSWAP_32BIG_C(0x41a862a8U), BSWAP_32BIG_C(0xf2aa4d10U), BSWAP_32BIG_C(0xa852b29bU), BSWAP_32BIG_C(0x6a79304cU),
    };
    r_rsip_func100(Param_peef_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_peef_func100_004[] =
    {
        BSWAP_32BIG_C(0x2ff7d652U), BSWAP_32BIG_C(0xe62ae6c2U), BSWAP_32BIG_C(0xa61a75b3U), BSWAP_32BIG_C(0xb1863f3eU),
    };
    r_rsip_func100(Param_peef_func100_004);
    r_rsip_func_sub017(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_002CH, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_peef_func102_001[] =
    {
        BSWAP_32BIG_C(0x62e501aeU), BSWAP_32BIG_C(0xa1f30a66U), BSWAP_32BIG_C(0xacd55e6dU), BSWAP_32BIG_C(0x6f022925U),
    };
    r_rsip_func102(Param_peef_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
