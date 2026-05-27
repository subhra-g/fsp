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

rsip_ret_t r_rsip_pb9i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b90001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b9U);

    static const uint32_t Param_pb9i_func101_001[] =
    {
        BSWAP_32BIG_C(0x3c6a7b24U), BSWAP_32BIG_C(0xfafd0275U), BSWAP_32BIG_C(0x5685dc46U), BSWAP_32BIG_C(0xa2e1d631U),
    };
    r_rsip_func101(Param_pb9i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b9U);

    static const uint32_t Param_pb9i_func101_002[] =
    {
        BSWAP_32BIG_C(0x4cdf0856U), BSWAP_32BIG_C(0x39200853U), BSWAP_32BIG_C(0x72b50e1fU), BSWAP_32BIG_C(0xcf019744U),
    };
    r_rsip_func101(Param_pb9i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub023(0x00000fc2U, 0x40000300U, 0xf7009d07U);

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8090001fU);
    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pb9i_func100_001[] =
    {
        BSWAP_32BIG_C(0x649edaf1U), BSWAP_32BIG_C(0x7ab8c172U), BSWAP_32BIG_C(0x4e912b68U), BSWAP_32BIG_C(0x14d63d2aU),
    };
    r_rsip_func100(Param_pb9i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb9i_func102_001[] =
        {
            BSWAP_32BIG_C(0x2fc4b034U), BSWAP_32BIG_C(0x5b5080a2U), BSWAP_32BIG_C(0x7b64e572U), BSWAP_32BIG_C(
                0xf98e413dU),
        };
        r_rsip_func102(Param_pb9i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub025(0x00000800U, 0x0000b420U, 0x00000020U);

        r_rsip_func424();

        r_rsip_func_sub024(0x000037dfU, 0x0000b400U, 0x00000010U, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000030U);
        r_rsip_func424();

        WR1_PROG(REG_1600H, 0x000013feU);

        r_rsip_func_sub006(0x38008be0U, 0x1ae211e9U, 0x00A60000U);

        static const uint32_t Param_pb9i_func100_002[] =
        {
            BSWAP_32BIG_C(0x731f185fU), BSWAP_32BIG_C(0x8fb554f0U), BSWAP_32BIG_C(0x0da2437cU), BSWAP_32BIG_C(
                0xe0ac1fbeU),
        };
        r_rsip_func100(Param_pb9i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb9i_func102_002[] =
            {
                BSWAP_32BIG_C(0xcf7335edU), BSWAP_32BIG_C(0x237ae70fU), BSWAP_32BIG_C(0x8ff314edU), BSWAP_32BIG_C(
                    0x179fe33aU),
            };
            r_rsip_func102(Param_pb9i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb9i_func100_003[] =
            {
                BSWAP_32BIG_C(0xe4aa5c6eU), BSWAP_32BIG_C(0x785cf1a6U), BSWAP_32BIG_C(0x9728dd8eU), BSWAP_32BIG_C(
                    0xcfbbe768U),
            };
            r_rsip_func100(Param_pb9i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_004[] =
            {
                BSWAP_32BIG_C(0x462c4ccdU), BSWAP_32BIG_C(0xdec74a9aU), BSWAP_32BIG_C(0x8f930f5bU), BSWAP_32BIG_C(
                    0x269549efU),
            };
            r_rsip_func100(Param_pb9i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_005[] =
            {
                BSWAP_32BIG_C(0x1f3fe180U), BSWAP_32BIG_C(0x11eaa27eU), BSWAP_32BIG_C(0x70143472U), BSWAP_32BIG_C(
                    0xc99edb1bU),
            };
            r_rsip_func100(Param_pb9i_func100_005);
            WR1_PROG(REG_1824H, 0x080000a5U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb9i_func100_006[] =
            {
                BSWAP_32BIG_C(0x5ae1daa4U), BSWAP_32BIG_C(0x541117d7U), BSWAP_32BIG_C(0x704bf8f1U), BSWAP_32BIG_C(
                    0xc945e7feU),
            };
            r_rsip_func100(Param_pb9i_func100_006);
            WR1_PROG(REG_1824H, 0x080000b5U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0a028045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
