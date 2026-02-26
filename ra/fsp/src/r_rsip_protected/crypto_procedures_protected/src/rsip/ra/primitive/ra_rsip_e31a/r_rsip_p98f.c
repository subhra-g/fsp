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

rsip_ret_t r_rsip_p98f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_MACLength[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub014(0x000000c7U, 0x80010060U);
    WR1_PROG(REG_002CH, InData_MACLength[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub010(0x38008860U, 0x00000000U, 0x00270000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    r_rsip_func_sub010(0x00000010U, 0x342028a3U, 0x00270000U);

    static const uint32_t Param_p98f_func100_001[] =
    {
        BSWAP_32BIG_C(0x67bc5bc5U), BSWAP_32BIG_C(0xa296fcc7U), BSWAP_32BIG_C(0x9cf7c8c4U), BSWAP_32BIG_C(0xc9477a57U),
    };
    r_rsip_func100(Param_p98f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p98f_func102_001[] =
        {
            BSWAP_32BIG_C(0x4cd300bfU), BSWAP_32BIG_C(0x3cb88ae6U), BSWAP_32BIG_C(0xef05c901U), BSWAP_32BIG_C(
                0xd52a81e7U),
        };
        r_rsip_func102(Param_p98f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x80010000U);
        WR1_PROG(REG_002CH, InData_TextLen[0]);
        r_rsip_func_sub018(0x00000000U, 0x00008c00U, 0x0000000fU);

        r_rsip_func_sub010(0x38008800U, 0x00000000U, 0x00A70000U);

        static const uint32_t Param_p98f_func100_002[] =
        {
            BSWAP_32BIG_C(0x6dc14605U), BSWAP_32BIG_C(0x4ba98597U), BSWAP_32BIG_C(0x7ded49c6U), BSWAP_32BIG_C(
                0x67b2a6e0U),
        };
        r_rsip_func100(Param_p98f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x07000d05U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub006(0x80840001U, 0x03410011U, 0x00000821U, 0x000008a5U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub022(0x3c0028a0U, 0x12003c25U, 0x00002ca0U);
            }

            static const uint32_t Param_p98f_func100_003[] =
            {
                BSWAP_32BIG_C(0xd36f9432U), BSWAP_32BIG_C(0xf227f701U), BSWAP_32BIG_C(0x3ed044fcU), BSWAP_32BIG_C(
                    0x49299c65U),
            };
            r_rsip_func100(Param_p98f_func100_003);
            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub017(0x81840001U, 0x00005012U);
            RD1_ADDR(REG_002CH, &OutData_Text[0]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[1]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[2]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[3]);

            WR1_PROG(REG_00D0H, 0x0e100405U);
            r_rsip_func_sub012(0x81840001U, 0x00490011U);

            static const uint32_t Param_p98f_func101_001[] =
            {
                BSWAP_32BIG_C(0xa5d4bcedU), BSWAP_32BIG_C(0x1ea848a3U), BSWAP_32BIG_C(0x386f506bU), BSWAP_32BIG_C(
                    0xb8e7bf75U),
            };
            r_rsip_func101(Param_p98f_func101_001);
        }
        else
        {
            static const uint32_t Param_p98f_func101_002[] =
            {
                BSWAP_32BIG_C(0x6db87862U), BSWAP_32BIG_C(0x5c80bde8U), BSWAP_32BIG_C(0xf12ddb9aU), BSWAP_32BIG_C(
                    0x8cf1642aU),
            };
            r_rsip_func101(Param_p98f_func101_002);
        }

        r_rsip_func_sub008(0x000000a1U, 0x0c100104U, 0x00000000U);

        r_rsip_func_sub013(0x07200d05U, 0x00410011U);

        WR1_PROG(REG_0094H, 0x00000821U);
        r_rsip_func_sub006(0x80840001U, 0x03410011U, 0x000008a5U, 0x00000821U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub022(0x3c0028a3U, 0x12003c25U, 0x00002ca0U);
        }

        r_rsip_func_sub019(0x000003c1U, 0x08000055U);
        WR4_ADDR(REG_002CH, &InData_MAC[0]);

        WR1_PROG(REG_00D0H, 0x9c100005U);
        r_rsip_func_sub007(0x00000821U, 0x81840001U, 0x00490011U);
        WR1_PROG(REG_00D0H, 0x00000000U);

        static const uint32_t Param_p98f_func100_004[] =
        {
            BSWAP_32BIG_C(0x341f60d3U), BSWAP_32BIG_C(0x1c4b6893U), BSWAP_32BIG_C(0xcd0a0812U), BSWAP_32BIG_C(
                0xd037555bU),
        };
        r_rsip_func100(Param_p98f_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p98f_func102_002[] =
            {
                BSWAP_32BIG_C(0x45301f61U), BSWAP_32BIG_C(0xe07078eaU), BSWAP_32BIG_C(0xbbb72c60U), BSWAP_32BIG_C(
                    0x3f77669bU),
            };
            r_rsip_func102(Param_p98f_func102_002);

            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p98f_func102_003[] =
            {
                BSWAP_32BIG_C(0x449de32cU), BSWAP_32BIG_C(0xcb6fdda5U), BSWAP_32BIG_C(0xcfbdf05cU), BSWAP_32BIG_C(
                    0x05f5bf75U),
            };
            r_rsip_func102(Param_p98f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
