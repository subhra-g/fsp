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

rsip_ret_t r_rsip_p83f (const uint32_t InData_Text[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000001c7U, 0x80020100U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x0000b580U, 0x0000007FU, 0x0000b5a0U, 0xFFFFFF00U);
    r_rsip_func_sub006(0x0c0029a9U, 0x04a02988U, 0x00260000U);

    static const uint32_t Param_p83f_func100_001[] =
    {
        BSWAP_32BIG_C(0x83cccf84U), BSWAP_32BIG_C(0x2cb52154U), BSWAP_32BIG_C(0xfb871811U), BSWAP_32BIG_C(0x8d713e02U),
    };
    r_rsip_func100(Param_p83f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p83f_func102_001[] =
        {
            BSWAP_32BIG_C(0x11007451U), BSWAP_32BIG_C(0x8f74262cU), BSWAP_32BIG_C(0xb9870bc3U), BSWAP_32BIG_C(
                0x14e6900bU),
        };
        r_rsip_func102(Param_p83f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00003409U);
        WR1_PROG(REG_1600H, 0x00036800U);

        r_rsip_func_sub006(0x08008c00U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_p83f_func100_002[] =
        {
            BSWAP_32BIG_C(0x34f4c116U), BSWAP_32BIG_C(0x56bafdc7U), BSWAP_32BIG_C(0x1338e325U), BSWAP_32BIG_C(
                0x31fd0246U),
        };
        r_rsip_func100(Param_p83f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000030U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            WR1_PROG(REG_1600H, 0x00000bffU);
            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub025(0x3c002be0U, 0x12003c3fU, 0x00002fe0U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p83f_func100_003[] =
            {
                BSWAP_32BIG_C(0xc9fea7b8U), BSWAP_32BIG_C(0x2d22d20fU), BSWAP_32BIG_C(0xc0292c40U), BSWAP_32BIG_C(
                    0x3ddc5227U),
            };
            r_rsip_func100(Param_p83f_func100_003);
            WR1_PROG(REG_182CH, 0x00018000U);
            WR1_PROG(REG_1824H, 0x0a008005U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub016(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);

            static const uint32_t Param_p83f_func101_001[] =
            {
                BSWAP_32BIG_C(0x71ab7c92U), BSWAP_32BIG_C(0xc68db878U), BSWAP_32BIG_C(0xb60ddf6cU), BSWAP_32BIG_C(
                    0x0f18ccf0U),
            };
            r_rsip_func101(Param_p83f_func101_001);
        }

        static const uint32_t Param_p83f_func100_004[] =
        {
            BSWAP_32BIG_C(0x368be93eU), BSWAP_32BIG_C(0x691d5361U), BSWAP_32BIG_C(0x39485ac7U), BSWAP_32BIG_C(
                0x712c2a54U),
        };
        r_rsip_func100(Param_p83f_func100_004);
        r_rsip_func_sub019(0x000001c1U, 0x00018000U, 0x0a008005U);
        WR2_ADDR(REG_1420H, &InData_DataALen[0]);

        WR1_PROG(REG_1608H, 0x81020100U);
        r_rsip_func_sub001(0x00490009U);

        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81040080U);
        r_rsip_func_sub001(0x00490011U);

        WR1_PROG(REG_182CH, 0x00400000U);
        r_rsip_func_sub020(0x000000a1U, 0x0c008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_182CH, 0x40000030U);
        WR1_PROG(REG_1824H, 0x07008d05U);
        r_rsip_func_sub001(0x00410011U);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        static const uint32_t Param_p83f_func102_002[] =
        {
            BSWAP_32BIG_C(0x229bf9c1U), BSWAP_32BIG_C(0x2f0ce0e9U), BSWAP_32BIG_C(0xcefd76f6U), BSWAP_32BIG_C(
                0x258cffe8U),
        };
        r_rsip_func102(Param_p83f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
