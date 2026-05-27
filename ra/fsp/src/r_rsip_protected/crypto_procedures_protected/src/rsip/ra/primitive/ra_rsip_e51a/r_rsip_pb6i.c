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

rsip_ret_t r_rsip_pb6i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b60001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b6U);

    static const uint32_t Param_pb6i_func101_001[] =
    {
        BSWAP_32BIG_C(0x3758f0d5U), BSWAP_32BIG_C(0x7624b886U), BSWAP_32BIG_C(0x4acd213cU), BSWAP_32BIG_C(0x02441220U),
    };
    r_rsip_func101(Param_pb6i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000008U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b6U);

    static const uint32_t Param_pb6i_func101_002[] =
    {
        BSWAP_32BIG_C(0xe61b375eU), BSWAP_32BIG_C(0x44edba96U), BSWAP_32BIG_C(0xcf8a3bc3U), BSWAP_32BIG_C(0xafac43beU),
    };
    r_rsip_func101(Param_pb6i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8088001fU);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pb6i_func100_001[] =
    {
        BSWAP_32BIG_C(0xccd28d8eU), BSWAP_32BIG_C(0x480361f7U), BSWAP_32BIG_C(0x0d692003U), BSWAP_32BIG_C(0xb57c6a67U),
    };
    r_rsip_func100(Param_pb6i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb6i_func102_001[] =
        {
            BSWAP_32BIG_C(0x0990e9feU), BSWAP_32BIG_C(0xfe7517e1U), BSWAP_32BIG_C(0xc0bf2176U), BSWAP_32BIG_C(
                0xb477bcebU),
        };
        r_rsip_func102(Param_pb6i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub025(0x00000800U, 0x0000b420U, 0x00000010U);

        r_rsip_func424();

        r_rsip_func_sub006(0x38008be0U, 0x1ae211e9U, 0x00A60000U);

        static const uint32_t Param_pb6i_func100_002[] =
        {
            BSWAP_32BIG_C(0x01363f60U), BSWAP_32BIG_C(0xbb72682cU), BSWAP_32BIG_C(0x88037031U), BSWAP_32BIG_C(
                0x09861a08U),
        };
        r_rsip_func100(Param_pb6i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb6i_func102_002[] =
            {
                BSWAP_32BIG_C(0xf6da9b1eU), BSWAP_32BIG_C(0x6582bf3bU), BSWAP_32BIG_C(0x7fe6fcbdU), BSWAP_32BIG_C(
                    0x0bf177e9U),
            };
            r_rsip_func102(Param_pb6i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb6i_func100_003[] =
            {
                BSWAP_32BIG_C(0x94f77138U), BSWAP_32BIG_C(0x7e50db79U), BSWAP_32BIG_C(0x8f101b2cU), BSWAP_32BIG_C(
                    0xcc75592cU),
            };
            r_rsip_func100(Param_pb6i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8188001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb6i_func100_004[] =
            {
                BSWAP_32BIG_C(0x2465c08bU), BSWAP_32BIG_C(0xe0f88521U), BSWAP_32BIG_C(0x330448a8U), BSWAP_32BIG_C(
                    0x143f1511U),
            };
            r_rsip_func100(Param_pb6i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x0a010045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
