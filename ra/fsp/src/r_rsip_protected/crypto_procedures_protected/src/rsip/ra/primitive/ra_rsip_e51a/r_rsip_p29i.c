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

rsip_ret_t r_rsip_p29i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00290001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00002901U);

    static const uint32_t Param_p29i_func101_001[] =
    {
        BSWAP_32BIG_C(0x2b6a4acdU), BSWAP_32BIG_C(0x02cba8e3U), BSWAP_32BIG_C(0x2eb4f871U), BSWAP_32BIG_C(0x2bc2784cU),
    };
    r_rsip_func101(Param_p29i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00002901U);

    static const uint32_t Param_p29i_func101_002[] =
    {
        BSWAP_32BIG_C(0xa9ee3ff9U), BSWAP_32BIG_C(0x52f26700U), BSWAP_32BIG_C(0x57449ca3U), BSWAP_32BIG_C(0xb68f9428U),
    };
    r_rsip_func101(Param_p29i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p29i_func100_001[] =
    {
        BSWAP_32BIG_C(0xd00240e7U), BSWAP_32BIG_C(0x19a18630U), BSWAP_32BIG_C(0xa72fdc5fU), BSWAP_32BIG_C(0x9a132d2aU),
    };
    r_rsip_func100(Param_p29i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p29i_func100_002[] =
    {
        BSWAP_32BIG_C(0x34c3c143U), BSWAP_32BIG_C(0xcb7c04ceU), BSWAP_32BIG_C(0x7866458aU), BSWAP_32BIG_C(0xf5945c1bU),
    };
    r_rsip_func100(Param_p29i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p29i_func102_001[] =
        {
            BSWAP_32BIG_C(0x24fe20f9U), BSWAP_32BIG_C(0x9b321bdaU), BSWAP_32BIG_C(0xb46544ffU), BSWAP_32BIG_C(
                0xe8f863b7U),
        };
        r_rsip_func102(Param_p29i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_1420H, InData_IVType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000c84U, 0x00260000U);

        static const uint32_t Param_p29i_func100_003[] =
        {
            BSWAP_32BIG_C(0x1f490ff0U), BSWAP_32BIG_C(0xa9f1737dU), BSWAP_32BIG_C(0xf58841f8U), BSWAP_32BIG_C(
                0x0559489fU),
        };
        r_rsip_func100(Param_p29i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000003c7U, 0x80040080U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_IV[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_IV[2]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_IV[3]);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p29i_func101_003[] =
            {
                BSWAP_32BIG_C(0xcce45f9fU), BSWAP_32BIG_C(0x36169ddeU), BSWAP_32BIG_C(0x2f35bb2eU), BSWAP_32BIG_C(
                    0x5508eea2U),
            };
            r_rsip_func101(Param_p29i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00002902U);

            static const uint32_t Param_p29i_func101_004[] =
            {
                BSWAP_32BIG_C(0x36b5a34cU), BSWAP_32BIG_C(0x70d34ebcU), BSWAP_32BIG_C(0xee7c05d5U), BSWAP_32BIG_C(
                    0x3338caf1U),
            };
            r_rsip_func101(Param_p29i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00002902U);

            static const uint32_t Param_p29i_func101_005[] =
            {
                BSWAP_32BIG_C(0xfa9ffe2eU), BSWAP_32BIG_C(0xaf89c27aU), BSWAP_32BIG_C(0x4467d6a9U), BSWAP_32BIG_C(
                    0x145063a7U),
            };
            r_rsip_func101(Param_p29i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p29i_func100_004[] =
            {
                BSWAP_32BIG_C(0xf3ff431cU), BSWAP_32BIG_C(0x6740ebecU), BSWAP_32BIG_C(0xaefe585aU), BSWAP_32BIG_C(
                    0xaa178c3bU),
            };
            r_rsip_func100(Param_p29i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p29i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x9418c0daU), BSWAP_32BIG_C(0x1a4574ccU), BSWAP_32BIG_C(0x93a8543cU), BSWAP_32BIG_C(
                        0x872d515aU),
                };
                r_rsip_func102(Param_p29i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p29i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x8f482b1dU), BSWAP_32BIG_C(0xcdfd805eU), BSWAP_32BIG_C(0x9e0366b3U), BSWAP_32BIG_C(
                        0xaad810d0U),
                };
                r_rsip_func101(Param_p29i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x00070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p29i_func101_007[] =
        {
            BSWAP_32BIG_C(0x3fe58398U), BSWAP_32BIG_C(0x0211fff5U), BSWAP_32BIG_C(0xefe96923U), BSWAP_32BIG_C(
                0xda2e6edbU),
        };
        r_rsip_func101(Param_p29i_func101_007);

        return RSIP_RET_PASS;
    }
}
