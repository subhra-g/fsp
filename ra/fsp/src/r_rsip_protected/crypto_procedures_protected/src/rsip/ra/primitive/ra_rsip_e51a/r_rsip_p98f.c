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

rsip_ret_t r_rsip_p98f (const uint32_t InData_Text[], const uint32_t InData_MAC[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub006(0x38008940U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    r_rsip_func_sub006(0x00000010U, 0x34202beaU, 0x00260000U);

    static const uint32_t Param_p98f_func100_001[] =
    {
        BSWAP_32BIG_C(0x5a7ec03cU), BSWAP_32BIG_C(0xa68a74c7U), BSWAP_32BIG_C(0xca681fc6U), BSWAP_32BIG_C(0x7f414f09U),
    };
    r_rsip_func100(Param_p98f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p98f_func102_001[] =
        {
            BSWAP_32BIG_C(0x54dfa407U), BSWAP_32BIG_C(0x3a426fbfU), BSWAP_32BIG_C(0x36c7d35fU), BSWAP_32BIG_C(
                0xac86215eU),
        };
        r_rsip_func102(Param_p98f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub025(0x00003409U, 0x00008c00U, 0x0000000fU);

        r_rsip_func_sub006(0x38008800U, 0x00000000U, 0x00A60000U);

        static const uint32_t Param_p98f_func100_002[] =
        {
            BSWAP_32BIG_C(0x27a12520U), BSWAP_32BIG_C(0x1906db13U), BSWAP_32BIG_C(0xe4b3dd48U), BSWAP_32BIG_C(
                0x3f254163U),
        };
        r_rsip_func100(Param_p98f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000003c1U, 0x07000d05U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            r_rsip_func_sub026(0x0000b420U, 0x00000080U, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub024(0x00000821U, 0x0000a400U, 0x00000080U, 0x0000b7e0U);
            WR1_PROG(REG_1600H, 0x00000080U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub025(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p98f_func100_003[] =
            {
                BSWAP_32BIG_C(0x52fc845cU), BSWAP_32BIG_C(0xd6c324efU), BSWAP_32BIG_C(0x0796c6e2U), BSWAP_32BIG_C(
                    0x0e235bffU),
            };
            r_rsip_func100(Param_p98f_func100_003);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1600H, 0x00000080U);
            r_rsip_func_sub016(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);

            WR1_PROG(REG_1824H, 0x0e100405U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_p98f_func101_001[] =
            {
                BSWAP_32BIG_C(0xa66ccc5cU), BSWAP_32BIG_C(0x0b2f7bf8U), BSWAP_32BIG_C(0xe25f41ebU), BSWAP_32BIG_C(
                    0xda2e36fdU),
            };
            r_rsip_func101(Param_p98f_func101_001);
        }
        else
        {
            static const uint32_t Param_p98f_func101_002[] =
            {
                BSWAP_32BIG_C(0xf67e7fcaU), BSWAP_32BIG_C(0x518271e5U), BSWAP_32BIG_C(0x23438b3dU), BSWAP_32BIG_C(
                    0x18214108U),
            };
            r_rsip_func101(Param_p98f_func101_002);
        }

        r_rsip_func_sub020(0x000000a1U, 0x0c100104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1824H, 0x07200d05U);
        r_rsip_func_sub001(0x00410011U);

        r_rsip_func_sub026(0x0000b420U, 0x00000080U, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        r_rsip_func_sub024(0x0000a540U, 0x00000080U, 0x0000b7e0U, 0x00000080U);

        WR1_PROG(REG_1600H, 0x00000821U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub025(0x3c002beaU, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_1420H, &InData_MAC[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        r_rsip_func_sub026(0x0000b420U, 0x00000080U, 0x81840001U);
        r_rsip_func_sub001(0x00490011U);
        WR1_PROG(REG_1824H, 0x00000000U);

        static const uint32_t Param_p98f_func100_004[] =
        {
            BSWAP_32BIG_C(0xe766706dU), BSWAP_32BIG_C(0x37ee4d54U), BSWAP_32BIG_C(0xfef96882U), BSWAP_32BIG_C(
                0x486534f4U),
        };
        r_rsip_func100(Param_p98f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p98f_func102_002[] =
            {
                BSWAP_32BIG_C(0x7220e070U), BSWAP_32BIG_C(0x61f2d5d5U), BSWAP_32BIG_C(0x3b9c3699U), BSWAP_32BIG_C(
                    0x2de01c9dU),
            };
            r_rsip_func102(Param_p98f_func102_002);

            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p98f_func102_003[] =
            {
                BSWAP_32BIG_C(0xe508df83U), BSWAP_32BIG_C(0x3f703852U), BSWAP_32BIG_C(0xbf858488U), BSWAP_32BIG_C(
                    0x030d79bdU),
            };
            r_rsip_func102(Param_p98f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
