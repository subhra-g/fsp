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

rsip_ret_t r_rsip_pb3i (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00b30001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x000000b3U);

    static const uint32_t Param_pb3i_func101_001[] =
    {
        BSWAP_32BIG_C(0x6c24788cU), BSWAP_32BIG_C(0x948505f9U), BSWAP_32BIG_C(0xc127e67dU), BSWAP_32BIG_C(0x1cb2c1f5U),
    };
    r_rsip_func101(Param_pb3i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000008U);

    r_rsip_func_sub003(0x800103a0U, 0x000000b3U);

    static const uint32_t Param_pb3i_func101_002[] =
    {
        BSWAP_32BIG_C(0x96059cfcU), BSWAP_32BIG_C(0x23f8d351U), BSWAP_32BIG_C(0xef861811U), BSWAP_32BIG_C(0x8d923b27U),
    };
    r_rsip_func101(Param_pb3i_func101_002);
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

    static const uint32_t Param_pb3i_func100_001[] =
    {
        BSWAP_32BIG_C(0x14ce11ebU), BSWAP_32BIG_C(0x6eff92c0U), BSWAP_32BIG_C(0x5a68f1a7U), BSWAP_32BIG_C(0x33109b2cU),
    };
    r_rsip_func100(Param_pb3i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb3i_func102_001[] =
        {
            BSWAP_32BIG_C(0x80f3ec65U), BSWAP_32BIG_C(0xc0674d52U), BSWAP_32BIG_C(0xd381deb4U), BSWAP_32BIG_C(
                0xbd498eddU),
        };
        r_rsip_func102(Param_pb3i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000010U);

        r_rsip_func424();

        r_rsip_func_sub006(0x38008be0U, 0x1ae211e9U, 0x00A60000U);

        static const uint32_t Param_pb3i_func100_002[] =
        {
            BSWAP_32BIG_C(0x6b034cb1U), BSWAP_32BIG_C(0x7194c79cU), BSWAP_32BIG_C(0xe3017edeU), BSWAP_32BIG_C(
                0x51c0a62dU),
        };
        r_rsip_func100(Param_pb3i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb3i_func102_002[] =
            {
                BSWAP_32BIG_C(0x267a3b43U), BSWAP_32BIG_C(0x15137165U), BSWAP_32BIG_C(0x348fd9e2U), BSWAP_32BIG_C(
                    0xd511d2ddU),
            };
            r_rsip_func102(Param_pb3i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pb3i_func100_003[] =
            {
                BSWAP_32BIG_C(0x80a5f771U), BSWAP_32BIG_C(0xcca0ebedU), BSWAP_32BIG_C(0x6f482d6fU), BSWAP_32BIG_C(
                    0xc57f373aU),
            };
            r_rsip_func100(Param_pb3i_func100_003);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8188001fU);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb3i_func100_004[] =
            {
                BSWAP_32BIG_C(0xcc7efcf6U), BSWAP_32BIG_C(0xd7fe8deeU), BSWAP_32BIG_C(0xf9676a2cU), BSWAP_32BIG_C(
                    0x7e07738fU),
            };
            r_rsip_func100(Param_pb3i_func100_004);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x0a010045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            return RSIP_RET_PASS;
        }
    }
}
