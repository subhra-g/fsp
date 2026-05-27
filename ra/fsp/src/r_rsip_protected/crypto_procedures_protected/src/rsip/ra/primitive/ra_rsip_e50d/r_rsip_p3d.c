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

rsip_ret_t r_rsip_p3d (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x003d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00003d01U);

    static const uint32_t Param_p3d_func101_001[] =
    {
        BSWAP_32BIG_C(0x066ff0b6U), BSWAP_32BIG_C(0x3b14888eU), BSWAP_32BIG_C(0x9c244157U), BSWAP_32BIG_C(0x3b3ba104U),
    };
    r_rsip_func101(Param_p3d_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000003dU);

    static const uint32_t Param_p3d_func101_002[] =
    {
        BSWAP_32BIG_C(0x2575e602U), BSWAP_32BIG_C(0x65f2a6dcU), BSWAP_32BIG_C(0xae416820U), BSWAP_32BIG_C(0x4635e180U),
    };
    r_rsip_func101(Param_p3d_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000029U);

    r_rsip_func_sub003(0x800103a0U, 0x0000003dU);

    static const uint32_t Param_p3d_func101_003[] =
    {
        BSWAP_32BIG_C(0x5c8c5894U), BSWAP_32BIG_C(0x8eddff6fU), BSWAP_32BIG_C(0x5c9a9cdeU), BSWAP_32BIG_C(0x81c99ba5U),
    };
    r_rsip_func101(Param_p3d_func101_003);
    r_rsip_func044();

    static const uint32_t Param_p3d_func100_001[] =
    {
        BSWAP_32BIG_C(0xdfb6d899U), BSWAP_32BIG_C(0x22212bb7U), BSWAP_32BIG_C(0x1e6ea182U), BSWAP_32BIG_C(0x9e6d4806U),
    };
    r_rsip_func100(Param_p3d_func100_001);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

    r_rsip_func_sub003(0x800103a0U, 0x00003d02U);

    static const uint32_t Param_p3d_func101_004[] =
    {
        BSWAP_32BIG_C(0x0dc20bedU), BSWAP_32BIG_C(0x7e9851beU), BSWAP_32BIG_C(0x3c802831U), BSWAP_32BIG_C(0xda07ecc8U),
    };
    r_rsip_func101(Param_p3d_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003d03U);

    static const uint32_t Param_p3d_func101_005[] =
    {
        BSWAP_32BIG_C(0xe89c2f71U), BSWAP_32BIG_C(0x0b4a55eeU), BSWAP_32BIG_C(0x516028b9U), BSWAP_32BIG_C(0x5be0c39cU),
    };
    r_rsip_func101(Param_p3d_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040080U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003d04U);

    static const uint32_t Param_p3d_func101_006[] =
    {
        BSWAP_32BIG_C(0x522d3d4dU), BSWAP_32BIG_C(0x8c1d7115U), BSWAP_32BIG_C(0x951b94c2U), BSWAP_32BIG_C(0x20899e6fU),
    };
    r_rsip_func101(Param_p3d_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040100U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00003d05U);

    static const uint32_t Param_p3d_func101_007[] =
    {
        BSWAP_32BIG_C(0xbc2e6c16U), BSWAP_32BIG_C(0xf92d940aU), BSWAP_32BIG_C(0xf9a9c7faU), BSWAP_32BIG_C(0x4ed9e745U),
    };
    r_rsip_func101(Param_p3d_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80040180U);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p3d_func100_002[] =
    {
        BSWAP_32BIG_C(0x5cecdcbaU), BSWAP_32BIG_C(0x9d0d8db6U), BSWAP_32BIG_C(0x76678695U), BSWAP_32BIG_C(0x25e81edcU),
    };
    r_rsip_func100(Param_p3d_func100_002);

    r_rsip_func_sub027(0x40000300U, 0xe7009d47U, 0x81100000U);
    r_rsip_func_sub001(0x00890031U);

    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

    r_rsip_func_sub001(0x00890011U);

    static const uint32_t Param_p3d_func100_003[] =
    {
        BSWAP_32BIG_C(0x2ba3a988U), BSWAP_32BIG_C(0x1d9a5f9aU), BSWAP_32BIG_C(0xe3875b36U), BSWAP_32BIG_C(0x9d179dffU),
    };
    r_rsip_func100(Param_p3d_func100_003);
    r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
    WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
             bswap_32big(0x00000004U));

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

    static const uint32_t Param_p3d_func102_001[] =
    {
        BSWAP_32BIG_C(0x65e3a887U), BSWAP_32BIG_C(0x888bccbcU), BSWAP_32BIG_C(0x6c1ae7e9U), BSWAP_32BIG_C(0x65405585U),
    };
    r_rsip_func102(Param_p3d_func102_001);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
