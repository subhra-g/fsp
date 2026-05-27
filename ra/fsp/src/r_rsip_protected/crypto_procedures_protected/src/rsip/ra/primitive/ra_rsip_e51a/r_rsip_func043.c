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

void r_rsip_func043 (void)
{
    static const uint32_t Param_func043_func100_001[] =
    {
        BSWAP_32BIG_C(0x6ab71710U), BSWAP_32BIG_C(0xb914c763U), BSWAP_32BIG_C(0x60a8d359U), BSWAP_32BIG_C(0xb76d5418U),
    };
    r_rsip_func100(Param_func043_func100_001);
    r_rsip_func_sub026(0x0000b540U, 0x000001d0U, 0x8188000aU);

    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func043_func100_002[] =
    {
        BSWAP_32BIG_C(0x6a1baa91U), BSWAP_32BIG_C(0x0f3acd3dU), BSWAP_32BIG_C(0x401977b6U), BSWAP_32BIG_C(0xb1b408a5U),
    };
    r_rsip_func100(Param_func043_func100_002);
    WR1_PROG(REG_1A24H, 0x08000095U);
    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_func043_func100_003[] =
    {
        BSWAP_32BIG_C(0xcbbf314bU), BSWAP_32BIG_C(0x8579611fU), BSWAP_32BIG_C(0x5e2a7cf5U), BSWAP_32BIG_C(0x3cff2581U),
    };
    r_rsip_func100(Param_func043_func100_003);

    r_rsip_func_sub026(0x0000b540U, 0x000001c0U, 0x8184000aU);

    WR1_PROG(REG_1A24H, 0x080000c5U);
    r_rsip_func_sub001(0x00890011U);

    WR1_PROG(REG_1A24H, 0x0b040104U);
    WR1_PROG(REG_1608H, 0x810100e0U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1608H, 0x80040140U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x01000000U);

    r_rsip_func_sub029(0x40000000U, 0x30009105U, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub024(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x02000000U);

    r_rsip_func_sub029(0x40000000U, 0x30009045U, 0x81040140U);
    r_rsip_func_sub001(0x00890011U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    static const uint32_t Param_func043_func100_004[] =
    {
        BSWAP_32BIG_C(0xb63c4bacU), BSWAP_32BIG_C(0x458abb86U), BSWAP_32BIG_C(0xb9a13e61U), BSWAP_32BIG_C(0xb132cd47U),
    };
    r_rsip_func100(Param_func043_func100_004);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_func043_func100_005[] =
    {
        BSWAP_32BIG_C(0x915d9137U), BSWAP_32BIG_C(0x7df2d248U), BSWAP_32BIG_C(0xcc59b369U), BSWAP_32BIG_C(0x184be643U),
    };
    r_rsip_func100(Param_func043_func100_005);
    r_rsip_func_sub004(0x0c000094U, 0x00000000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
