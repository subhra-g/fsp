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

rsip_ret_t r_rsip_p34i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00340001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003401U);

    static const uint32_t Param_p34i_func101_001[] =
    {
        BSWAP_32BIG_C(0xa1a89503U), BSWAP_32BIG_C(0x98dfdbf1U), BSWAP_32BIG_C(0xd71361c0U), BSWAP_32BIG_C(0xaebce691U),
    };
    r_rsip_func101(Param_p34i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003401U);

    static const uint32_t Param_p34i_func101_002[] =
    {
        BSWAP_32BIG_C(0x94fbe1e1U), BSWAP_32BIG_C(0xca324aa5U), BSWAP_32BIG_C(0x39de5889U), BSWAP_32BIG_C(0x16b0301eU),
    };
    r_rsip_func101(Param_p34i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p34i_func100_001[] =
    {
        BSWAP_32BIG_C(0x7ace34eaU), BSWAP_32BIG_C(0xa39c2112U), BSWAP_32BIG_C(0xe3ea362cU), BSWAP_32BIG_C(0xe0596bccU),
    };
    r_rsip_func100(Param_p34i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p34i_func100_002[] =
    {
        BSWAP_32BIG_C(0xce1d2959U), BSWAP_32BIG_C(0x55e309beU), BSWAP_32BIG_C(0x43ab1748U), BSWAP_32BIG_C(0x92a2ae85U),
    };
    r_rsip_func100(Param_p34i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p34i_func100_003[] =
    {
        BSWAP_32BIG_C(0x13694d05U), BSWAP_32BIG_C(0x98ce3f05U), BSWAP_32BIG_C(0x267eaa94U), BSWAP_32BIG_C(0x7ff85210U),
    };
    r_rsip_func100(Param_p34i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p34i_func102_001[] =
        {
            BSWAP_32BIG_C(0xdc58ab87U), BSWAP_32BIG_C(0x471eadfaU), BSWAP_32BIG_C(0x67aa937fU), BSWAP_32BIG_C(
                0xfb369f3dU),
        };
        r_rsip_func102(Param_p34i_func102_001);
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

        static const uint32_t Param_p34i_func100_004[] =
        {
            BSWAP_32BIG_C(0x0128c57dU), BSWAP_32BIG_C(0xb87a8064U), BSWAP_32BIG_C(0xebe67e81U), BSWAP_32BIG_C(
                0x8a621a01U),
        };
        r_rsip_func100(Param_p34i_func100_004);
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

            static const uint32_t Param_p34i_func101_003[] =
            {
                BSWAP_32BIG_C(0x9290d273U), BSWAP_32BIG_C(0x7deced29U), BSWAP_32BIG_C(0x541e1cdcU), BSWAP_32BIG_C(
                    0x7779ac75U),
            };
            r_rsip_func101(Param_p34i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003402U);

            static const uint32_t Param_p34i_func101_004[] =
            {
                BSWAP_32BIG_C(0x6e5cbcacU), BSWAP_32BIG_C(0xf02ca8e0U), BSWAP_32BIG_C(0x95158d15U), BSWAP_32BIG_C(
                    0x8668f112U),
            };
            r_rsip_func101(Param_p34i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003402U);

            static const uint32_t Param_p34i_func101_005[] =
            {
                BSWAP_32BIG_C(0xa41063f0U), BSWAP_32BIG_C(0x6b151900U), BSWAP_32BIG_C(0x4adf5d73U), BSWAP_32BIG_C(
                    0x0aebc649U),
            };
            r_rsip_func101(Param_p34i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p34i_func100_005[] =
            {
                BSWAP_32BIG_C(0xc2885833U), BSWAP_32BIG_C(0x0bb2499bU), BSWAP_32BIG_C(0x7a2f07e3U), BSWAP_32BIG_C(
                    0xc6fdb699U),
            };
            r_rsip_func100(Param_p34i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p34i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xd572aed5U), BSWAP_32BIG_C(0xfcce968fU), BSWAP_32BIG_C(0xd5b39a14U), BSWAP_32BIG_C(
                        0x9a65dbb5U),
                };
                r_rsip_func102(Param_p34i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p34i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x724e4e1cU), BSWAP_32BIG_C(0xbbee6407U), BSWAP_32BIG_C(0xb4819a97U), BSWAP_32BIG_C(
                        0xf479b8abU),
                };
                r_rsip_func101(Param_p34i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p34i_func101_007[] =
        {
            BSWAP_32BIG_C(0xe21815faU), BSWAP_32BIG_C(0xf2a388efU), BSWAP_32BIG_C(0x2d448464U), BSWAP_32BIG_C(
                0xaa05ef6fU),
        };
        r_rsip_func101(Param_p34i_func101_007);

        return RSIP_RET_PASS;
    }
}
