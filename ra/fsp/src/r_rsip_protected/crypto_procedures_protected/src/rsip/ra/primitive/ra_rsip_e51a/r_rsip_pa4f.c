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

rsip_ret_t r_rsip_pa4f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_MACLength[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010140U);
    WR1_PROG(REG_1420H, InData_MACLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008940U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    r_rsip_func_sub006(0x00000010U, 0x34202beaU, 0x00260000U);

    static const uint32_t Param_pa4f_func100_001[] =
    {
        BSWAP_32BIG_C(0xf2a7c1bcU), BSWAP_32BIG_C(0xe0d14548U), BSWAP_32BIG_C(0xd6cf6b5bU), BSWAP_32BIG_C(0xc434af82U),
    };
    r_rsip_func100(Param_pa4f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa4f_func102_001[] =
        {
            BSWAP_32BIG_C(0x33906ca7U), BSWAP_32BIG_C(0xf17e621eU), BSWAP_32BIG_C(0x138b58b5U), BSWAP_32BIG_C(
                0x0380b926U),
        };
        r_rsip_func102(Param_pa4f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_TextLen[0]);
        r_rsip_func_sub039(0x00008c00U, 0x0000000fU);

        r_rsip_func_sub006(0x38008800U, 0x00000000U, 0x00A60000U);

        static const uint32_t Param_pa4f_func100_002[] =
        {
            BSWAP_32BIG_C(0x5090e5d6U), BSWAP_32BIG_C(0x41b5819eU), BSWAP_32BIG_C(0x88cb7391U), BSWAP_32BIG_C(
                0xefe03502U),
        };
        r_rsip_func100(Param_pa4f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x07008d05U);
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

            static const uint32_t Param_pa4f_func100_003[] =
            {
                BSWAP_32BIG_C(0xafb6e12fU), BSWAP_32BIG_C(0xc3d15fd1U), BSWAP_32BIG_C(0xb6962350U), BSWAP_32BIG_C(
                    0x8f7ce851U),
            };
            r_rsip_func100(Param_pa4f_func100_003);
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

            WR1_PROG(REG_182CH, 0x40000000U);
            WR1_PROG(REG_1824H, 0x0e108405U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pa4f_func101_001[] =
            {
                BSWAP_32BIG_C(0x6189f45eU), BSWAP_32BIG_C(0xed4656f7U), BSWAP_32BIG_C(0x7cfacebaU), BSWAP_32BIG_C(
                    0xbe8927acU),
            };
            r_rsip_func101(Param_pa4f_func101_001);
        }
        else
        {
            static const uint32_t Param_pa4f_func101_002[] =
            {
                BSWAP_32BIG_C(0x6872d4baU), BSWAP_32BIG_C(0xcc4ef1a3U), BSWAP_32BIG_C(0xd8ea0851U), BSWAP_32BIG_C(
                    0xfe2fdad3U),
            };
            r_rsip_func101(Param_pa4f_func101_002);
        }

        r_rsip_func_sub020(0x000000a1U, 0x0c100104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000000U);
        WR1_PROG(REG_1824H, 0x07208d05U);
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

        static const uint32_t Param_pa4f_func100_004[] =
        {
            BSWAP_32BIG_C(0xddabf2dbU), BSWAP_32BIG_C(0x5ab8904bU), BSWAP_32BIG_C(0xcb540cb9U), BSWAP_32BIG_C(
                0x1bb97480U),
        };
        r_rsip_func100(Param_pa4f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pa4f_func102_002[] =
            {
                BSWAP_32BIG_C(0x7a3cbe9dU), BSWAP_32BIG_C(0x17f6c9c0U), BSWAP_32BIG_C(0x193c1265U), BSWAP_32BIG_C(
                    0x0ae91024U),
            };
            r_rsip_func102(Param_pa4f_func102_002);

            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_pa4f_func102_003[] =
            {
                BSWAP_32BIG_C(0x44457413U), BSWAP_32BIG_C(0x5f9f11a3U), BSWAP_32BIG_C(0x0d141b1cU), BSWAP_32BIG_C(
                    0xcf9cefa3U),
            };
            r_rsip_func102(Param_pa4f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
