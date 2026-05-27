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

rsip_ret_t r_rsip_p2c (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002cU);

    static const uint32_t Param_p2c_func101_001[] =
    {
        BSWAP_32BIG_C(0xe4550b41U), BSWAP_32BIG_C(0x816b27d7U), BSWAP_32BIG_C(0xa6f03cf4U), BSWAP_32BIG_C(0x1b2b8f33U),
    };
    r_rsip_func101(Param_p2c_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000002cU);

    static const uint32_t Param_p2c_func101_002[] =
    {
        BSWAP_32BIG_C(0x739f6269U), BSWAP_32BIG_C(0xed55ff32U), BSWAP_32BIG_C(0xe94789c6U), BSWAP_32BIG_C(0x0b4d7a23U),
    };
    r_rsip_func101(Param_p2c_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x80840001U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p2c_func100_001[] =
    {
        BSWAP_32BIG_C(0xf3c4df08U), BSWAP_32BIG_C(0xde01e9caU), BSWAP_32BIG_C(0x5029ab3eU), BSWAP_32BIG_C(0xeb6fb089U),
    };
    r_rsip_func100(Param_p2c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2c_func102_001[] =
        {
            BSWAP_32BIG_C(0xd050af91U), BSWAP_32BIG_C(0x30204a38U), BSWAP_32BIG_C(0xfc8aff57U), BSWAP_32BIG_C(
                0x74abc66fU),
        };
        r_rsip_func102(Param_p2c_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p2c_func100_002[] =
        {
            BSWAP_32BIG_C(0xca38b20eU), BSWAP_32BIG_C(0x620da7e5U), BSWAP_32BIG_C(0x11048e7fU), BSWAP_32BIG_C(
                0x60a81deaU),
        };
        r_rsip_func100(Param_p2c_func100_002);
        WR1_PROG(REG_1438H, 0x40000100U);

        r_rsip_func_sub026(0x0000b400U, 0x00000000U, 0x81010000U);
        r_rsip_func_sub001(0x02090005U);

        static const uint32_t Param_p2c_func100_003[] =
        {
            BSWAP_32BIG_C(0xd6446ed6U), BSWAP_32BIG_C(0x844d807dU), BSWAP_32BIG_C(0x4701e6a3U), BSWAP_32BIG_C(
                0xd90b30deU),
        };
        r_rsip_func100(Param_p2c_func100_003);
        WR1_PROG(REG_1438H, 0x40000110U);

        r_rsip_func_sub001(0x02000011U);

        static const uint32_t Param_p2c_func100_004[] =
        {
            BSWAP_32BIG_C(0xea310309U), BSWAP_32BIG_C(0xcdea15b9U), BSWAP_32BIG_C(0x4b530004U), BSWAP_32BIG_C(
                0xacca6c86U),
        };
        r_rsip_func100(Param_p2c_func100_004);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81840001U);
        r_rsip_func_sub001(0x02090011U);

        r_rsip_func_sub010(0x000001c7U, 0x80020000U);
        WR1_PROG(REG_1420H, InData_DOTFSEED[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_DOTFSEED[1]);
        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p2c_func100_005[] =
        {
            BSWAP_32BIG_C(0x4b09bad8U), BSWAP_32BIG_C(0x7cf5ec6fU), BSWAP_32BIG_C(0xd91a3e0aU), BSWAP_32BIG_C(
                0xab56dd86U),
        };
        r_rsip_func100(Param_p2c_func100_005);
        WR1_PROG(REG_1438H, 0x40000140U);

        WR1_PROG(REG_1608H, 0x81020000U);
        r_rsip_func_sub001(0x02090009U);

        static const uint32_t Param_p2c_func102_002[] =
        {
            BSWAP_32BIG_C(0xe53bf0f4U), BSWAP_32BIG_C(0x1d2adf54U), BSWAP_32BIG_C(0x1556405bU), BSWAP_32BIG_C(
                0x7ce73748U),
        };
        r_rsip_func102(Param_p2c_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
