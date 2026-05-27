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

rsip_ret_t r_rsip_p89i (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00890001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000089U);

    static const uint32_t Param_p89i_func101_001[] =
    {
        BSWAP_32BIG_C(0xf8b3ad50U), BSWAP_32BIG_C(0xaae92652U), BSWAP_32BIG_C(0x92a4d7bfU), BSWAP_32BIG_C(0x4738924cU),
    };
    r_rsip_func101(Param_p89i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000006U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000089U);

    static const uint32_t Param_p89i_func101_002[] =
    {
        BSWAP_32BIG_C(0x7797b6acU), BSWAP_32BIG_C(0xeb7d5ae5U), BSWAP_32BIG_C(0x877c27f5U), BSWAP_32BIG_C(0x6a4ddb2eU),
    };
    r_rsip_func101(Param_p89i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p89i_func100_001[] =
    {
        BSWAP_32BIG_C(0x33d0ca40U), BSWAP_32BIG_C(0xf22a1ef8U), BSWAP_32BIG_C(0xe2bd9e9bU), BSWAP_32BIG_C(0xb2b7f41dU),
    };
    r_rsip_func100(Param_p89i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p89i_func100_002[] =
    {
        BSWAP_32BIG_C(0x65791523U), BSWAP_32BIG_C(0x68594a89U), BSWAP_32BIG_C(0x25b88bbeU), BSWAP_32BIG_C(0xdc9e028cU),
    };
    r_rsip_func100(Param_p89i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p89i_func100_003[] =
    {
        BSWAP_32BIG_C(0x407cc6fdU), BSWAP_32BIG_C(0xf424a300U), BSWAP_32BIG_C(0x2604c437U), BSWAP_32BIG_C(0xc6e20074U),
    };
    r_rsip_func100(Param_p89i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p89i_func102_001[] =
        {
            BSWAP_32BIG_C(0x851d8212U), BSWAP_32BIG_C(0xb502ddb3U), BSWAP_32BIG_C(0x8e1696f6U), BSWAP_32BIG_C(
                0x9a2bccddU),
        };
        r_rsip_func102(Param_p89i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1608H, 0x80010000U);
        WR1_PROG(REG_1444H, 0x000000c7U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub024(0x3000a800U, 0x00000004U, 0x00010020U, 0x0000b400U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1600H, 0x00000080U);

        static const uint32_t Param_p89i_func100_004[] =
        {
            BSWAP_32BIG_C(0xad284ee0U), BSWAP_32BIG_C(0x72780197U), BSWAP_32BIG_C(0x90692935U), BSWAP_32BIG_C(
                0xdc6473ceU),
        };
        r_rsip_func100(Param_p89i_func100_004);
        r_rsip_func_sub014(0x00007c00U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            static const uint32_t Param_p89i_func101_003[] =
            {
                BSWAP_32BIG_C(0x82815d8eU), BSWAP_32BIG_C(0x61338f74U), BSWAP_32BIG_C(0x5d1b531aU), BSWAP_32BIG_C(
                    0x94408b0fU),
            };
            r_rsip_func101(Param_p89i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p89i_func101_004[] =
            {
                BSWAP_32BIG_C(0xb1c69c16U), BSWAP_32BIG_C(0x9517a426U), BSWAP_32BIG_C(0x2211c437U), BSWAP_32BIG_C(
                    0x187a2584U),
            };
            r_rsip_func101(Param_p89i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p89i_func101_005[] =
            {
                BSWAP_32BIG_C(0xb1127db0U), BSWAP_32BIG_C(0xb0c739f0U), BSWAP_32BIG_C(0x6939a0d4U), BSWAP_32BIG_C(
                    0x8ee7d7edU),
            };
            r_rsip_func101(Param_p89i_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p89i_func101_006[] =
            {
                BSWAP_32BIG_C(0x972cfb65U), BSWAP_32BIG_C(0x40f1dff4U), BSWAP_32BIG_C(0x1ce6c7dfU), BSWAP_32BIG_C(
                    0xee17ecddU),
            };
            r_rsip_func101(Param_p89i_func101_006);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p89i_func101_007[] =
            {
                BSWAP_32BIG_C(0x5e044856U), BSWAP_32BIG_C(0x7c62990fU), BSWAP_32BIG_C(0x2425c353U), BSWAP_32BIG_C(
                    0x0121188dU),
            };
            r_rsip_func101(Param_p89i_func101_007);
        }
        else
        {
            ;
        }

        return RSIP_RET_PASS;
    }
}
