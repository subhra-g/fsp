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

rsip_ret_t r_rsip_p36i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00360001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00003601U);

    static const uint32_t Param_p36i_func101_001[] =
    {
        BSWAP_32BIG_C(0x5e46e6a2U), BSWAP_32BIG_C(0xb573fa8dU), BSWAP_32BIG_C(0xddbf8d7aU), BSWAP_32BIG_C(0xe29b97afU),
    };
    r_rsip_func101(Param_p36i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x800103a0U, 0x00003601U);

    static const uint32_t Param_p36i_func101_002[] =
    {
        BSWAP_32BIG_C(0x7fb9bf71U), BSWAP_32BIG_C(0x7c9ec2a4U), BSWAP_32BIG_C(0x232dabf5U), BSWAP_32BIG_C(0x507c260dU),
    };
    r_rsip_func101(Param_p36i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p36i_func100_001[] =
    {
        BSWAP_32BIG_C(0x98a261a1U), BSWAP_32BIG_C(0x569860e7U), BSWAP_32BIG_C(0xbdad963bU), BSWAP_32BIG_C(0x79207655U),
    };
    r_rsip_func100(Param_p36i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p36i_func100_002[] =
    {
        BSWAP_32BIG_C(0xd7a02c4aU), BSWAP_32BIG_C(0x8c0a14f9U), BSWAP_32BIG_C(0xa6a78147U), BSWAP_32BIG_C(0xc007bd64U),
    };
    r_rsip_func100(Param_p36i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p36i_func100_003[] =
    {
        BSWAP_32BIG_C(0x7ba98e87U), BSWAP_32BIG_C(0xd790c6feU), BSWAP_32BIG_C(0x99d9f082U), BSWAP_32BIG_C(0x3d2c3f81U),
    };
    r_rsip_func100(Param_p36i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p36i_func102_001[] =
        {
            BSWAP_32BIG_C(0x17126d8eU), BSWAP_32BIG_C(0x8b4621d0U), BSWAP_32BIG_C(0x138216e8U), BSWAP_32BIG_C(
                0xfe8f9660U),
        };
        r_rsip_func102(Param_p36i_func102_001);
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

        static const uint32_t Param_p36i_func100_004[] =
        {
            BSWAP_32BIG_C(0x5cf1e457U), BSWAP_32BIG_C(0x8d33b519U), BSWAP_32BIG_C(0x7de4522fU), BSWAP_32BIG_C(
                0x45353d7eU),
        };
        r_rsip_func100(Param_p36i_func100_004);
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

            static const uint32_t Param_p36i_func101_003[] =
            {
                BSWAP_32BIG_C(0x9d1ad23aU), BSWAP_32BIG_C(0x5bd45281U), BSWAP_32BIG_C(0xe2e79f42U), BSWAP_32BIG_C(
                    0x1d0193aeU),
            };
            r_rsip_func101(Param_p36i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x00003602U);

            static const uint32_t Param_p36i_func101_004[] =
            {
                BSWAP_32BIG_C(0xd2ba1284U), BSWAP_32BIG_C(0x3e478d59U), BSWAP_32BIG_C(0x9f18a2c6U), BSWAP_32BIG_C(
                    0x9604b21aU),
            };
            r_rsip_func101(Param_p36i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x800103a0U, 0x00003602U);

            static const uint32_t Param_p36i_func101_005[] =
            {
                BSWAP_32BIG_C(0xbd0a818cU), BSWAP_32BIG_C(0xb5b178d4U), BSWAP_32BIG_C(0x932f66f8U), BSWAP_32BIG_C(
                    0x73554ae6U),
            };
            r_rsip_func101(Param_p36i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p36i_func100_005[] =
            {
                BSWAP_32BIG_C(0x3d56954cU), BSWAP_32BIG_C(0xa627e3cfU), BSWAP_32BIG_C(0x9795015aU), BSWAP_32BIG_C(
                    0x5d8be3a3U),
            };
            r_rsip_func100(Param_p36i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p36i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x8b674233U), BSWAP_32BIG_C(0xd828c49cU), BSWAP_32BIG_C(0x98607ee5U), BSWAP_32BIG_C(
                        0x9865f9cfU),
                };
                r_rsip_func102(Param_p36i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p36i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x288b9083U), BSWAP_32BIG_C(0x04cc2ab1U), BSWAP_32BIG_C(0x3d6f4019U), BSWAP_32BIG_C(
                        0xa5730b65U),
                };
                r_rsip_func101(Param_p36i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x40070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p36i_func101_007[] =
        {
            BSWAP_32BIG_C(0x980d814cU), BSWAP_32BIG_C(0xfbc29d85U), BSWAP_32BIG_C(0x67765da3U), BSWAP_32BIG_C(
                0xe414d83eU),
        };
        r_rsip_func101(Param_p36i_func101_007);

        return RSIP_RET_PASS;
    }
}
