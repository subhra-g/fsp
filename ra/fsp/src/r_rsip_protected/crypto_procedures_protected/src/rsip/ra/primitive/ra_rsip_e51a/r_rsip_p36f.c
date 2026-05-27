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

rsip_ret_t r_rsip_p36f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000001c7U, 0x80020100U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_TextLen[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x0000b580U, 0x0000007FU, 0x0000b5a0U, 0xFFFFFF00U);
    r_rsip_func_sub006(0x0c0029a9U, 0x04a02988U, 0x00260000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010140U);
    WR1_PROG(REG_1420H, InData_DataTLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008940U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_1600H, 0x0000b7e0U);
    r_rsip_func_sub006(0x00000010U, 0x34202beaU, 0x00260000U);

    static const uint32_t Param_p36f_func100_001[] =
    {
        BSWAP_32BIG_C(0x38644529U), BSWAP_32BIG_C(0x7cb3ad21U), BSWAP_32BIG_C(0xef228c44U), BSWAP_32BIG_C(0xec61df57U),
    };
    r_rsip_func100(Param_p36f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p36f_func102_001[] =
        {
            BSWAP_32BIG_C(0x0d2837b9U), BSWAP_32BIG_C(0x3b0b7349U), BSWAP_32BIG_C(0x1d2ba0cdU), BSWAP_32BIG_C(
                0x62c5958aU),
        };
        r_rsip_func102(Param_p36f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00003409U);
        WR1_PROG(REG_1600H, 0x00036800U);

        r_rsip_func_sub006(0x08008c00U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_p36f_func100_002[] =
        {
            BSWAP_32BIG_C(0xbcc461b2U), BSWAP_32BIG_C(0x19b725bbU), BSWAP_32BIG_C(0x37dbffe7U), BSWAP_32BIG_C(
                0xb038451aU),
        };
        r_rsip_func100(Param_p36f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p36f_func100_003[] =
            {
                BSWAP_32BIG_C(0x3e19b863U), BSWAP_32BIG_C(0xacf5d5d0U), BSWAP_32BIG_C(0x53f2cea6U), BSWAP_32BIG_C(
                    0x953ba9c4U),
            };
            r_rsip_func100(Param_p36f_func100_003);

            r_rsip_func_sub019(0x000003c1U, 0x40018020U, 0x07008d05U);
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

            WR1_PROG(REG_1600H, 0x00000821U);
            r_rsip_func_sub016(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);

            static const uint32_t Param_p36f_func101_001[] =
            {
                BSWAP_32BIG_C(0x7fd3f4f6U), BSWAP_32BIG_C(0x84bceb66U), BSWAP_32BIG_C(0x955f048dU), BSWAP_32BIG_C(
                    0xc45ad97bU),
            };
            r_rsip_func101(Param_p36f_func101_001);
        }
        else
        {
        }

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

        WR1_PROG(REG_182CH, 0x40000020U);
        WR1_PROG(REG_1824H, 0x07008d05U);
        r_rsip_func_sub001(0x00410011U);

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x80840001U);
        r_rsip_func_sub001(0x03410011U);

        WR1_PROG(REG_1600H, 0x00000bffU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub025(0x3c002beaU, 0x12003c3fU, 0x00002fe0U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub020(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1824H, 0x9c100005U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1608H, 0x81840001U);
        r_rsip_func_sub001(0x00490011U);
        WR1_PROG(REG_1824H, 0x00000000U);

        static const uint32_t Param_p36f_func100_004[] =
        {
            BSWAP_32BIG_C(0xdd7b6d7bU), BSWAP_32BIG_C(0xf463fa83U), BSWAP_32BIG_C(0x3aef73b0U), BSWAP_32BIG_C(
                0x0dd15a67U),
        };
        r_rsip_func100(Param_p36f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p36f_func102_002[] =
            {
                BSWAP_32BIG_C(0x91fe3861U), BSWAP_32BIG_C(0xada191d1U), BSWAP_32BIG_C(0xfd5d3d81U), BSWAP_32BIG_C(
                    0x939a04e4U),
            };
            r_rsip_func102(Param_p36f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p36f_func102_003[] =
            {
                BSWAP_32BIG_C(0x05ac305bU), BSWAP_32BIG_C(0xe13a1aaeU), BSWAP_32BIG_C(0x5611f1eaU), BSWAP_32BIG_C(
                    0x00b7bafdU),
            };
            r_rsip_func102(Param_p36f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
