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

void r_rsip_func143 (void)
{
    WR1_PROG(REG_00A0H, 0x00010000U);

    static const uint32_t Param_func143_func100_001[] =
    {
        BSWAP_32BIG_C(0xf848b1e8U), BSWAP_32BIG_C(0xeee62ceeU), BSWAP_32BIG_C(0x8c1ebe2bU), BSWAP_32BIG_C(0xfbcbb1c0U),
    };
    r_rsip_func100(Param_func143_func100_001);
    WR1_PROG(REG_00B0H, 0x000018b8U);
    r_rsip_func_sub013(0x08000085U, 0x00430011U);

    static const uint32_t Param_func143_func100_002[] =
    {
        BSWAP_32BIG_C(0x7898f29fU), BSWAP_32BIG_C(0x89ef16f9U), BSWAP_32BIG_C(0xa55c32aaU), BSWAP_32BIG_C(0xd3fb3e0bU),
    };
    r_rsip_func100(Param_func143_func100_002);
    r_rsip_func_sub013(0x08000095U, 0x00430011U);

    static const uint32_t Param_func143_func100_003[] =
    {
        BSWAP_32BIG_C(0x2e758ab2U), BSWAP_32BIG_C(0x0160a534U), BSWAP_32BIG_C(0x7d37ea8fU), BSWAP_32BIG_C(0x3b8d7b09U),
    };
    r_rsip_func100(Param_func143_func100_003);

    WR1_PROG(REG_00D0H, 0x080000c5U);
    r_rsip_func_sub009(0x000008b3U, 0x00430009U, 0x00001800U);
    r_rsip_func_sub009(0x000008b4U, 0x00430009U, 0x00001800U);

    WR1_PROG(REG_00D0H, 0x0b040104U);
    r_rsip_func_sub012(0x810100c0U, 0x00490005U);

    WR1_PROG(REG_0094H, 0x000008c6U);

    r_rsip_func_sub006(0x80840006U, 0x03410011U, 0x00003846U, 0x00008c40U);
    r_rsip_func_sub022(0x00ffffffU, 0x00009040U, 0x01000000U);
    WR1_PROG(REG_0094H, 0x00003c46U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009105U);
    r_rsip_func_sub006(0x81840006U, 0x00490011U, 0x00008c40U, 0x00ffffffU);
    r_rsip_func_sub022(0x00009040U, 0x02000000U, 0x00003c46U);

    static const uint32_t Param_func143_func100_004[] =
    {
        BSWAP_32BIG_C(0x9e269ca6U), BSWAP_32BIG_C(0x7841e28fU), BSWAP_32BIG_C(0xa2a2e5a9U), BSWAP_32BIG_C(0x34d5760bU),
    };
    r_rsip_func100(Param_func143_func100_004);
    WR1_PROG(REG_00D4H, 0x40000000U);
    WR1_PROG(REG_00D0H, 0x30009095U);
    r_rsip_func_sub012(0x81840006U, 0x00490011U);

    static const uint32_t Param_func143_func100_005[] =
    {
        BSWAP_32BIG_C(0xae3b5fedU), BSWAP_32BIG_C(0x1abfa8f1U), BSWAP_32BIG_C(0xd3d8f263U), BSWAP_32BIG_C(0x3d79b1abU),
    };
    r_rsip_func100(Param_func143_func100_005);
    r_rsip_func_sub013(0x08000085U, 0x00410011U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
