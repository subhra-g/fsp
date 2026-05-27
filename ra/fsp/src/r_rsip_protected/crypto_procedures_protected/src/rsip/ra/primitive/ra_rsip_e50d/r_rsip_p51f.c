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

rsip_ret_t r_rsip_p51f (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub003(0x800103a0U, 0x00000051U);

    static const uint32_t Param_p51f_func101_001[] =
    {
        BSWAP_32BIG_C(0xafa76023U), BSWAP_32BIG_C(0xcfdf6e31U), BSWAP_32BIG_C(0x876c7ed3U), BSWAP_32BIG_C(0xbfa852b2U),
    };
    r_rsip_func101(Param_p51f_func101_001);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x00005102U);

    static const uint32_t Param_p51f_func101_002[] =
    {
        BSWAP_32BIG_C(0xa611414cU), BSWAP_32BIG_C(0x212a3d6eU), BSWAP_32BIG_C(0x545cefcdU), BSWAP_32BIG_C(0xefeeaf16U),
    };
    r_rsip_func101(Param_p51f_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01f6c222U);

    r_rsip_func_sub003(0x800103a0U, 0x00005102U);

    static const uint32_t Param_p51f_func101_003[] =
    {
        BSWAP_32BIG_C(0x85bd883bU), BSWAP_32BIG_C(0x1c3401a1U), BSWAP_32BIG_C(0x8fdef9e4U), BSWAP_32BIG_C(0x598bd571U),
    };
    r_rsip_func101(Param_p51f_func101_003);
    r_rsip_func044();

    WR1_PROG(REG_1600H, 0x00000884U);

    static const uint32_t Param_p51f_func100_001[] =
    {
        BSWAP_32BIG_C(0xab50bbd0U), BSWAP_32BIG_C(0xa12e668bU), BSWAP_32BIG_C(0x0420f303U), BSWAP_32BIG_C(0x164e0e02U),
    };
    r_rsip_func100(Param_p51f_func100_001);
    r_rsip_func_sub027(0x40000200U, 0xe7009d07U, 0x818c0004U);
    r_rsip_func_sub001(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p51f_func100_002[] =
    {
        BSWAP_32BIG_C(0x1f0dc008U), BSWAP_32BIG_C(0xa2fe4924U), BSWAP_32BIG_C(0x1a91cc83U), BSWAP_32BIG_C(0x54fefb0fU),
    };
    r_rsip_func100(Param_p51f_func100_002);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p51f_func100_003[] =
    {
        BSWAP_32BIG_C(0xed0db4e4U), BSWAP_32BIG_C(0x9050c163U), BSWAP_32BIG_C(0xe2842e16U), BSWAP_32BIG_C(0x725e127dU),
    };
    r_rsip_func100(Param_p51f_func100_003);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p51f_func102_001[] =
    {
        BSWAP_32BIG_C(0x52b0d8eaU), BSWAP_32BIG_C(0x6b6cad27U), BSWAP_32BIG_C(0x63cba73aU), BSWAP_32BIG_C(0xad25ccddU),
    };
    r_rsip_func102(Param_p51f_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
