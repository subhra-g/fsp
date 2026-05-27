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

void r_rsip_func092 (void)
{
    static const uint32_t Param_func092_func100_001[] =
    {
        BSWAP_32BIG_C(0xd4026ab7U), BSWAP_32BIG_C(0x4cb770aaU), BSWAP_32BIG_C(0x13d66d1dU), BSWAP_32BIG_C(0x475c04ffU),
    };
    r_rsip_func100(Param_func092_func100_001);
    r_rsip_func_sub021(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x01000000U);

    r_rsip_func_sub004(0x4a060044U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0e060084U);
    WR1_PROG(REG_1608H, 0x81010140U);
    r_rsip_func_sub001(0x00890005U);

    static const uint32_t Param_func092_func100_002[] =
    {
        BSWAP_32BIG_C(0xda78a32dU), BSWAP_32BIG_C(0x8e38a4c3U), BSWAP_32BIG_C(0x0a6c4ff5U), BSWAP_32BIG_C(0x1be859eaU),
    };
    r_rsip_func100(Param_func092_func100_002);
    r_rsip_func_sub021(0x00008d40U, 0x00ffffffU, 0x00009140U, 0x02000000U);

    WR1_PROG(REG_1A24H, 0x0e060094U);
    WR1_PROG(REG_1608H, 0x81010140U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub021(0x300032a0U, 0x00070020U, 0x0000b6e0U, 0x1204c99cU);
    r_rsip_func_sub021(0x00030040U, 0x0000b6e0U, 0xa9ed4879U, 0x00050040U);
    r_rsip_func_sub021(0x0000b6e0U, 0x7c182e99U, 0x00000080U, 0x00008ee0U);
    r_rsip_func_sub022(0x00ffffffU, 0x000092e0U, 0x01000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009104U, 0x810102e0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub021(0x00008ee0U, 0x00ffffffU, 0x000092e0U, 0x02000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009044U, 0x810102e0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    static const uint32_t Param_func092_func100_003[] =
    {
        BSWAP_32BIG_C(0x6aca5809U), BSWAP_32BIG_C(0x331407fbU), BSWAP_32BIG_C(0x0de35e2cU), BSWAP_32BIG_C(0x40b6223eU),
    };
    r_rsip_func100(Param_func092_func100_003);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_func092_func100_004[] =
    {
        BSWAP_32BIG_C(0x34a533c2U), BSWAP_32BIG_C(0x58750b30U), BSWAP_32BIG_C(0x1133044cU), BSWAP_32BIG_C(0x6f64466fU),
    };
    r_rsip_func100(Param_func092_func100_004);
    r_rsip_func_sub004(0x0c000094U, 0x00000000U);

    r_rsip_func_sub021(0x00008ec0U, 0x00ffffffU, 0x000092c0U, 0x01000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009104U, 0x810102c0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    r_rsip_func_sub021(0x00008ec0U, 0x00ffffffU, 0x000092c0U, 0x02000000U);

    r_rsip_func_sub027(0x40000000U, 0x30009044U, 0x810102c0U);
    r_rsip_func_sub001(0x00890005U);

    r_rsip_func_sub004(0x08000004U, 0x00000000U);

    static const uint32_t Param_func092_func100_005[] =
    {
        BSWAP_32BIG_C(0xd151f813U), BSWAP_32BIG_C(0x3dd3ca1cU), BSWAP_32BIG_C(0xf9386f7bU), BSWAP_32BIG_C(0xfd4765d4U),
    };
    r_rsip_func100(Param_func092_func100_005);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_func092_func100_006[] =
    {
        BSWAP_32BIG_C(0x87ae7eedU), BSWAP_32BIG_C(0x9dc63c83U), BSWAP_32BIG_C(0x34600170U), BSWAP_32BIG_C(0x7a232d88U),
    };
    r_rsip_func100(Param_func092_func100_006);
    r_rsip_func_sub004(0x0c000094U, 0x00000000U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
