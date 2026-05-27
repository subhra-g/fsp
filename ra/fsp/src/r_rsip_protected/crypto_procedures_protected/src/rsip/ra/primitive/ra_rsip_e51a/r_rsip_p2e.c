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

rsip_ret_t r_rsip_p2e (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x002e0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002eU);

    static const uint32_t Param_p2e_func101_001[] =
    {
        BSWAP_32BIG_C(0x064b8eacU), BSWAP_32BIG_C(0x46aa6347U), BSWAP_32BIG_C(0x0e7c5c90U), BSWAP_32BIG_C(0xa2b91c93U),
    };
    r_rsip_func101(Param_p2e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002eU);

    static const uint32_t Param_p2e_func101_002[] =
    {
        BSWAP_32BIG_C(0x530d294cU), BSWAP_32BIG_C(0xf64cf311U), BSWAP_32BIG_C(0x50d60570U), BSWAP_32BIG_C(0xff20f891U),
    };
    r_rsip_func101(Param_p2e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80880001U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p2e_func100_001[] =
    {
        BSWAP_32BIG_C(0xa93f975bU), BSWAP_32BIG_C(0x158d0472U), BSWAP_32BIG_C(0x90f5ec2fU), BSWAP_32BIG_C(0xc28a9489U),
    };
    r_rsip_func100(Param_p2e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2e_func102_001[] =
        {
            BSWAP_32BIG_C(0x800f3032U), BSWAP_32BIG_C(0x17c60138U), BSWAP_32BIG_C(0xdd5f4ad9U), BSWAP_32BIG_C(
                0x950eef2bU),
        };
        r_rsip_func102(Param_p2e_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p2e_func100_002[] =
        {
            BSWAP_32BIG_C(0x87697706U), BSWAP_32BIG_C(0x53972684U), BSWAP_32BIG_C(0x85dd8526U), BSWAP_32BIG_C(
                0xf67f8015U),
        };
        r_rsip_func100(Param_p2e_func100_002);
        WR1_PROG(REG_1438H, 0x40000100U);

        r_rsip_func_sub026(0x0000b400U, 0x00000002U, 0x81010000U);
        r_rsip_func_sub001(0x02090005U);

        static const uint32_t Param_p2e_func100_003[] =
        {
            BSWAP_32BIG_C(0x40c39521U), BSWAP_32BIG_C(0xd8d9e045U), BSWAP_32BIG_C(0x99fa81a1U), BSWAP_32BIG_C(
                0xe705c507U),
        };
        r_rsip_func100(Param_p2e_func100_003);
        WR1_PROG(REG_1438H, 0x40000110U);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81880001U);
        r_rsip_func_sub001(0x02090021U);

        r_rsip_func_sub010(0x000001c7U, 0x80020000U);
        WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p2e_func100_004[] =
        {
            BSWAP_32BIG_C(0x4ec71b94U), BSWAP_32BIG_C(0x826f31d2U), BSWAP_32BIG_C(0x8693bce3U), BSWAP_32BIG_C(
                0x11f4d7d9U),
        };
        r_rsip_func100(Param_p2e_func100_004);
        WR1_PROG(REG_1438H, 0x40000140U);

        WR1_PROG(REG_1608H, 0x81020000U);
        r_rsip_func_sub001(0x02090009U);

        static const uint32_t Param_p2e_func102_002[] =
        {
            BSWAP_32BIG_C(0xc8dc4820U), BSWAP_32BIG_C(0xfaa9262fU), BSWAP_32BIG_C(0xb74c44eeU), BSWAP_32BIG_C(
                0x7e7b4261U),
        };
        r_rsip_func102(Param_p2e_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
