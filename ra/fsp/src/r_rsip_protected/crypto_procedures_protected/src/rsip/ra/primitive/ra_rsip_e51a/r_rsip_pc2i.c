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

rsip_ret_t r_rsip_pc2i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00c20001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000c2U);

    static const uint32_t Param_pc2i_func101_001[] =
    {
        BSWAP_32BIG_C(0xdbf87770U), BSWAP_32BIG_C(0x23969f27U), BSWAP_32BIG_C(0x07f4766bU), BSWAP_32BIG_C(0x900237c4U),
    };
    r_rsip_func101(Param_pc2i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000c2U);

    static const uint32_t Param_pc2i_func101_002[] =
    {
        BSWAP_32BIG_C(0x9899acd7U), BSWAP_32BIG_C(0x879509e6U), BSWAP_32BIG_C(0x1de0802aU), BSWAP_32BIG_C(0xc970f17aU),
    };
    r_rsip_func101(Param_pc2i_func101_002);
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

    static const uint32_t Param_pc2i_func100_001[] =
    {
        BSWAP_32BIG_C(0xd0d1b508U), BSWAP_32BIG_C(0xc32db85bU), BSWAP_32BIG_C(0x67e557bbU), BSWAP_32BIG_C(0x5b56c3d1U),
    };
    r_rsip_func100(Param_pc2i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pc2i_func102_001[] =
        {
            BSWAP_32BIG_C(0xd67830ffU), BSWAP_32BIG_C(0x0685ca1aU), BSWAP_32BIG_C(0x8a07f9b6U), BSWAP_32BIG_C(
                0xcfcf54e5U),
        };
        r_rsip_func102(Param_pc2i_func102_001);
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

        static const uint32_t Param_pc2i_func100_002[] =
        {
            BSWAP_32BIG_C(0xb06bcb48U), BSWAP_32BIG_C(0x6f20a511U), BSWAP_32BIG_C(0xd0e7d8d6U), BSWAP_32BIG_C(
                0x38400df5U),
        };
        r_rsip_func100(Param_pc2i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pc2i_func102_002[] =
            {
                BSWAP_32BIG_C(0x88bf30e0U), BSWAP_32BIG_C(0xc671274eU), BSWAP_32BIG_C(0x065d7fd0U), BSWAP_32BIG_C(
                    0x93801418U),
            };
            r_rsip_func102(Param_pc2i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pc2i_func100_003[] =
            {
                BSWAP_32BIG_C(0xae374bddU), BSWAP_32BIG_C(0x858abf78U), BSWAP_32BIG_C(0x34d80af8U), BSWAP_32BIG_C(
                    0x383372a7U),
            };
            r_rsip_func100(Param_pc2i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_004[] =
            {
                BSWAP_32BIG_C(0xa84e762aU), BSWAP_32BIG_C(0x4789ec01U), BSWAP_32BIG_C(0xe3db4667U), BSWAP_32BIG_C(
                    0x26ee98fdU),
            };
            r_rsip_func100(Param_pc2i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_005[] =
            {
                BSWAP_32BIG_C(0x3dc48dddU), BSWAP_32BIG_C(0xfaeb3ef8U), BSWAP_32BIG_C(0x62010ca8U), BSWAP_32BIG_C(
                    0xce824b86U),
            };
            r_rsip_func100(Param_pc2i_func100_005);
            WR1_PROG(REG_1824H, 0x080000a5U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pc2i_func100_006[] =
            {
                BSWAP_32BIG_C(0x8c5aa4a4U), BSWAP_32BIG_C(0xca881903U), BSWAP_32BIG_C(0x97250029U), BSWAP_32BIG_C(
                    0xe1c9453eU),
            };
            r_rsip_func100(Param_pc2i_func100_006);
            WR1_PROG(REG_1824H, 0x080000b5U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0a028045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
