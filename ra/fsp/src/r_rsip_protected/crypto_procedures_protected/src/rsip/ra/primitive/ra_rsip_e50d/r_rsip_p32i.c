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

rsip_ret_t r_rsip_p32i (const uint32_t InData_KeyIndex[], const uint32_t InData_IVType[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00320001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00003201U);

    static const uint32_t Param_p32i_func101_001[] =
    {
        BSWAP_32BIG_C(0x0dfc12a4U), BSWAP_32BIG_C(0xfa8880ccU), BSWAP_32BIG_C(0x5bd5afcfU), BSWAP_32BIG_C(0x3c95f918U),
    };
    r_rsip_func101(Param_p32i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub003(0x800103a0U, 0x00003201U);

    static const uint32_t Param_p32i_func101_002[] =
    {
        BSWAP_32BIG_C(0xfe886365U), BSWAP_32BIG_C(0xf6aeb45aU), BSWAP_32BIG_C(0x95d59963U), BSWAP_32BIG_C(0x41bc194cU),
    };
    r_rsip_func101(Param_p32i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p32i_func100_001[] =
    {
        BSWAP_32BIG_C(0x338ff82bU), BSWAP_32BIG_C(0x84c1bf79U), BSWAP_32BIG_C(0x3d6e030dU), BSWAP_32BIG_C(0xf99ba861U),
    };
    r_rsip_func100(Param_p32i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p32i_func100_002[] =
    {
        BSWAP_32BIG_C(0x5278f9adU), BSWAP_32BIG_C(0x5a5a03c0U), BSWAP_32BIG_C(0x22c9ab0aU), BSWAP_32BIG_C(0xd417ae7bU),
    };
    r_rsip_func100(Param_p32i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p32i_func102_001[] =
        {
            BSWAP_32BIG_C(0x06d299d8U), BSWAP_32BIG_C(0xbfe159b0U), BSWAP_32BIG_C(0xbababe5aU), BSWAP_32BIG_C(
                0xaf8cd8f8U),
        };
        r_rsip_func102(Param_p32i_func102_001);
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

        static const uint32_t Param_p32i_func100_003[] =
        {
            BSWAP_32BIG_C(0x3499228bU), BSWAP_32BIG_C(0x05527b55U), BSWAP_32BIG_C(0x32646751U), BSWAP_32BIG_C(
                0xd9ad9186U),
        };
        r_rsip_func100(Param_p32i_func100_003);
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

            static const uint32_t Param_p32i_func101_003[] =
            {
                BSWAP_32BIG_C(0xf72820acU), BSWAP_32BIG_C(0xa3354f78U), BSWAP_32BIG_C(0x0f25691fU), BSWAP_32BIG_C(
                    0x5c8e9215U),
            };
            r_rsip_func101(Param_p32i_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_IV[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x00003202U);

            static const uint32_t Param_p32i_func101_004[] =
            {
                BSWAP_32BIG_C(0xf054384fU), BSWAP_32BIG_C(0xd1c7cde3U), BSWAP_32BIG_C(0xb04510c2U), BSWAP_32BIG_C(
                    0x046e95dcU),
            };
            r_rsip_func101(Param_p32i_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x800103a0U, 0x00003202U);

            static const uint32_t Param_p32i_func101_005[] =
            {
                BSWAP_32BIG_C(0x3e7472c8U), BSWAP_32BIG_C(0x018d19d2U), BSWAP_32BIG_C(0x989946edU), BSWAP_32BIG_C(
                    0xb7bbe33fU),
            };
            r_rsip_func101(Param_p32i_func101_005);
            r_rsip_func044();

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_IV[1]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_IV[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p32i_func100_004[] =
            {
                BSWAP_32BIG_C(0xed02afb6U), BSWAP_32BIG_C(0x6145cbc0U), BSWAP_32BIG_C(0x47a21e84U), BSWAP_32BIG_C(
                    0x4919a996U),
            };
            r_rsip_func100(Param_p32i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p32i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xa3fbd9a2U), BSWAP_32BIG_C(0x6092c04dU), BSWAP_32BIG_C(0x1062edf4U), BSWAP_32BIG_C(
                        0x1cf9acc4U),
                };
                r_rsip_func102(Param_p32i_func102_002);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p32i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x545b605aU), BSWAP_32BIG_C(0x558e1182U), BSWAP_32BIG_C(0xeb72a294U), BSWAP_32BIG_C(
                        0xd12eabf6U),
                };
                r_rsip_func101(Param_p32i_func101_006);
            }
        }

        r_rsip_func_sub020(0x000000a1U, 0x08000024U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub019(0x000000a1U, 0x00070000U, 0x0a008004U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p32i_func101_007[] =
        {
            BSWAP_32BIG_C(0x0b0cc55bU), BSWAP_32BIG_C(0x1e6a90e5U), BSWAP_32BIG_C(0x4dbfb921U), BSWAP_32BIG_C(
                0xaa982470U),
        };
        r_rsip_func101(Param_p32i_func101_007);

        return RSIP_RET_PASS;
    }
}
