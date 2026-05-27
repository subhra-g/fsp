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

rsip_ret_t r_rsip_pb0f (const uint32_t InData_Text[],
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

    static const uint32_t Param_pb0f_func100_001[] =
    {
        BSWAP_32BIG_C(0x3c982798U), BSWAP_32BIG_C(0xab01bcbbU), BSWAP_32BIG_C(0xc5affd93U), BSWAP_32BIG_C(0xa8a63719U),
    };
    r_rsip_func100(Param_pb0f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb0f_func102_001[] =
        {
            BSWAP_32BIG_C(0xa7d47fdaU), BSWAP_32BIG_C(0xd2924d8dU), BSWAP_32BIG_C(0x31fa2a26U), BSWAP_32BIG_C(
                0x016be777U),
        };
        r_rsip_func102(Param_pb0f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_1420H, InData_TextLen[0]);
        r_rsip_func_sub034(0x00008c00U, 0x0000000fU);

        r_rsip_func_sub006(0x38008800U, 0x00000000U, 0x00A60000U);

        static const uint32_t Param_pb0f_func100_002[] =
        {
            BSWAP_32BIG_C(0x202211d0U), BSWAP_32BIG_C(0xe32b68b9U), BSWAP_32BIG_C(0xb9949c55U), BSWAP_32BIG_C(
                0x95c9213dU),
        };
        r_rsip_func100(Param_pb0f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub021(0x00000821U, 0x0000a400U, 0x00000080U, 0x0000b7e0U);
            WR1_PROG(REG_1600H, 0x00000080U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub022(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_pb0f_func100_003[] =
            {
                BSWAP_32BIG_C(0xf508b21aU), BSWAP_32BIG_C(0x86c4541bU), BSWAP_32BIG_C(0x10b4dddfU), BSWAP_32BIG_C(
                    0x07ab6870U),
            };
            r_rsip_func100(Param_pb0f_func100_003);
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

            WR1_PROG(REG_182CH, 0x40000010U);
            WR1_PROG(REG_1824H, 0x0e108405U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            static const uint32_t Param_pb0f_func101_001[] =
            {
                BSWAP_32BIG_C(0xd775f6efU), BSWAP_32BIG_C(0xb3c23273U), BSWAP_32BIG_C(0xbf1f8414U), BSWAP_32BIG_C(
                    0x725f2999U),
            };
            r_rsip_func101(Param_pb0f_func101_001);
        }
        else
        {
            static const uint32_t Param_pb0f_func101_002[] =
            {
                BSWAP_32BIG_C(0xe4620497U), BSWAP_32BIG_C(0xc5b8543dU), BSWAP_32BIG_C(0x6e3e5170U), BSWAP_32BIG_C(
                    0x7d18de2cU),
            };
            r_rsip_func101(Param_pb0f_func101_002);
        }

        r_rsip_func_sub020(0x000000a1U, 0x0c100104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000010U);
        WR1_PROG(REG_1824H, 0x07208d05U);
        r_rsip_func_sub001(0x00410011U);

        r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        r_rsip_func_sub021(0x0000a540U, 0x00000080U, 0x0000b7e0U, 0x00000080U);

        WR1_PROG(REG_1600H, 0x00000821U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub022(0x3c002beaU, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_1420H, &InData_MAC[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        r_rsip_func_sub023(0x0000b420U, 0x00000080U, 0x81840001U);
        r_rsip_func_sub001(0x00490011U);
        WR1_PROG(REG_1824H, 0x00000000U);

        static const uint32_t Param_pb0f_func100_004[] =
        {
            BSWAP_32BIG_C(0x84389ea9U), BSWAP_32BIG_C(0x4fe08abdU), BSWAP_32BIG_C(0x24f4f524U), BSWAP_32BIG_C(
                0xc224dc91U),
        };
        r_rsip_func100(Param_pb0f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pb0f_func102_002[] =
            {
                BSWAP_32BIG_C(0x392d9b21U), BSWAP_32BIG_C(0xaf8cd266U), BSWAP_32BIG_C(0xca162ec9U), BSWAP_32BIG_C(
                    0x95e952bdU),
            };
            r_rsip_func102(Param_pb0f_func102_002);

            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_pb0f_func102_003[] =
            {
                BSWAP_32BIG_C(0xe528a1d6U), BSWAP_32BIG_C(0x352b028fU), BSWAP_32BIG_C(0x8e1828c4U), BSWAP_32BIG_C(
                    0xdf2bddc8U),
            };
            r_rsip_func102(Param_pb0f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
