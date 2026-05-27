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

rsip_ret_t r_rsip_p29f (const uint32_t InData_Text[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_0014H, 0x000001c7U);
    WR1_PROG(REG_009CH, 0x80020040U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_TextLen[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_TextLen[1]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x0000b400U, 0x0000007FU, 0x0000b420U);
    WR1_PROG(REG_0094H, 0xFFFFFF00U);
    r_rsip_func_sub007(0x0c002823U, 0x04a02802U, 0x00260000U);

    static const uint32_t Param_p29f_func100_001[] =
    {
        BSWAP_32BIG_C(0x768b0feeU), BSWAP_32BIG_C(0x01d34923U), BSWAP_32BIG_C(0x5ac54f68U), BSWAP_32BIG_C(0x4ecd8b13U),
    };
    r_rsip_func100(Param_p29f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p29f_func102_001[] =
        {
            BSWAP_32BIG_C(0x3f97d3e3U), BSWAP_32BIG_C(0x19562042U), BSWAP_32BIG_C(0x27c829b7U), BSWAP_32BIG_C(
                0xa976a69fU),
        };
        r_rsip_func102(Param_p29f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00003403U);
        WR1_PROG(REG_0094H, 0x00036800U);

        r_rsip_func_sub007(0x08008c00U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_p29f_func100_002[] =
        {
            BSWAP_32BIG_C(0x345e6ca5U), BSWAP_32BIG_C(0x227f4e0eU), BSWAP_32BIG_C(0x0800cf04U), BSWAP_32BIG_C(
                0xf0a96851U),
        };
        r_rsip_func100(Param_p29f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p29f_func100_003[] =
            {
                BSWAP_32BIG_C(0xaea4d1b3U), BSWAP_32BIG_C(0x49b0e2beU), BSWAP_32BIG_C(0x7194e2e6U), BSWAP_32BIG_C(
                    0xbe572a8eU),
            };
            r_rsip_func100(Param_p29f_func100_003);
            r_rsip_func_sub008(0x000003c1U, 0x00000020U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x80840001U, 0x03410011U);

            WR1_PROG(REG_0094H, 0x00000884U);
            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub016(0x3c002820U, 0x12003c81U, 0x00002c20U);
            }

            WR1_PROG(REG_00D4H, 0x00008000U);
            WR1_PROG(REG_00D0H, 0x0e128455U);
            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x81840001U, 0x00490011U);

            WAIT_STS(REG_00C8H, 6, 0);
            WR1_PROG(REG_0040H, 0x00000400U);
            WR1_PROG(REG_0040H, 0x00000500U);

            WR1_PROG(REG_009CH, 0x81840001U);
            WR1_PROG(REG_0008H, 0x00005012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[0]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[1]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[2]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[3]);

            static const uint32_t Param_p29f_func101_001[] =
            {
                BSWAP_32BIG_C(0xe2546cc3U), BSWAP_32BIG_C(0xc7ae8548U), BSWAP_32BIG_C(0xe3a2adcbU), BSWAP_32BIG_C(
                    0xc9df52aeU),
            };
            r_rsip_func101(Param_p29f_func101_001);
        }

        static const uint32_t Param_p29f_func100_004[] =
        {
            BSWAP_32BIG_C(0x452a2fa8U), BSWAP_32BIG_C(0xdf1cbe15U), BSWAP_32BIG_C(0x16fc0224U), BSWAP_32BIG_C(
                0x61488ee3U),
        };
        r_rsip_func100(Param_p29f_func100_004);
        r_rsip_func_sub008(0x000001c1U, 0x00008000U, 0x0e128455U);
        WR2_ADDR(REG_002CH, &InData_DataALen[0]);

        r_rsip_func_sub003(0x81020040U, 0x00490009U);

        WR1_PROG(REG_00D0H, 0x08000045U);
        WR1_PROG(REG_0094H, 0x0000b420U);
        WR1_PROG(REG_0094H, 0x00000010U);
        r_rsip_func_sub003(0x81840001U, 0x00490011U);

        r_rsip_func_sub005(0x000000a1U, 0x0c100104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x00000020U);
        r_rsip_func_sub006(0x07008d05U, 0x00410011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_DataT[0]);

        static const uint32_t Param_p29f_func102_002[] =
        {
            BSWAP_32BIG_C(0xa5965b93U), BSWAP_32BIG_C(0xa072c0a7U), BSWAP_32BIG_C(0xb8586588U), BSWAP_32BIG_C(
                0xc0fdc9b3U),
        };
        r_rsip_func102(Param_p29f_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
