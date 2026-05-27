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

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x80010060U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_MACLength[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub007(0x38008860U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    r_rsip_func_sub007(0x00000010U, 0x342028a3U, 0x00260000U);

    static const uint32_t Param_pa4f_func100_001[] =
    {
        BSWAP_32BIG_C(0x65adc143U), BSWAP_32BIG_C(0x0fbfeab9U), BSWAP_32BIG_C(0x281826d2U), BSWAP_32BIG_C(0x0bd7f13aU),
    };
    r_rsip_func100(Param_pa4f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pa4f_func102_001[] =
        {
            BSWAP_32BIG_C(0x1e9a06ddU), BSWAP_32BIG_C(0xf3947fb6U), BSWAP_32BIG_C(0x8e5aac58U), BSWAP_32BIG_C(
                0x3bb6c9d0U),
        };
        r_rsip_func102(Param_pa4f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010000U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_TextLen[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        WR1_PROG(REG_0094H, 0x00008c00U);
        WR1_PROG(REG_0094H, 0x0000000fU);

        r_rsip_func_sub007(0x38008800U, 0x00000000U, 0x00A60000U);

        static const uint32_t Param_pa4f_func100_002[] =
        {
            BSWAP_32BIG_C(0x181b769cU), BSWAP_32BIG_C(0x1eb41883U), BSWAP_32BIG_C(0x94718677U), BSWAP_32BIG_C(
                0xe2a5a6a7U),
        };
        r_rsip_func100(Param_pa4f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x80840001U, 0x03410011U);

            WR1_PROG(REG_0094H, 0x00000821U);

            WR1_PROG(REG_0094H, 0x000008a5U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub016(0x3c0028a0U, 0x12003c25U, 0x00002ca0U);
            }

            static const uint32_t Param_pa4f_func100_003[] =
            {
                BSWAP_32BIG_C(0x5c1c76dcU), BSWAP_32BIG_C(0x73dbbb94U), BSWAP_32BIG_C(0x2f7fa56cU), BSWAP_32BIG_C(
                    0xaa2d6d07U),
            };
            r_rsip_func100(Param_pa4f_func100_003);
            r_rsip_func_sub015(0x00000821U, 0x81840001U, 0x00005012U);
            RD1_ADDR(REG_002CH, &OutData_Text[0]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[1]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[2]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[3]);

            WR1_PROG(REG_00D4H, 0x40000000U);
            WR1_PROG(REG_00D0H, 0x0e108405U);
            r_rsip_func_sub003(0x81840001U, 0x00490011U);

            static const uint32_t Param_pa4f_func101_001[] =
            {
                BSWAP_32BIG_C(0x64068ab7U), BSWAP_32BIG_C(0x52031ee7U), BSWAP_32BIG_C(0x8a7eac51U), BSWAP_32BIG_C(
                    0x186d422eU),
            };
            r_rsip_func101(Param_pa4f_func101_001);
        }
        else
        {
            static const uint32_t Param_pa4f_func101_002[] =
            {
                BSWAP_32BIG_C(0x0d9516c1U), BSWAP_32BIG_C(0x3677ea26U), BSWAP_32BIG_C(0xdb23a010U), BSWAP_32BIG_C(
                    0x5766879aU),
            };
            r_rsip_func101(Param_pa4f_func101_002);
        }

        r_rsip_func_sub005(0x000000a1U, 0x0c100104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0x07208d05U, 0x00410011U);

        WR1_PROG(REG_0094H, 0x00000821U);
        r_rsip_func_sub003(0x80840001U, 0x03410011U);

        WR1_PROG(REG_0094H, 0x000008a5U);

        WR1_PROG(REG_0094H, 0x00000821U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub016(0x3c0028a3U, 0x12003c25U, 0x00002ca0U);
        }

        WR1_PROG(REG_0014H, 0x000003c1U);
        WR1_PROG(REG_00D0H, 0x08000055U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &InData_MAC[0]);

        WR1_PROG(REG_00D0H, 0x9c100005U);
        WR1_PROG(REG_0094H, 0x00000821U);
        r_rsip_func_sub003(0x81840001U, 0x00490011U);
        WR1_PROG(REG_00D0H, 0x00000000U);

        static const uint32_t Param_pa4f_func100_004[] =
        {
            BSWAP_32BIG_C(0x7db0d3aaU), BSWAP_32BIG_C(0x3838e6e8U), BSWAP_32BIG_C(0xf0e0f08eU), BSWAP_32BIG_C(
                0x455b5e70U),
        };
        r_rsip_func100(Param_pa4f_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pa4f_func102_002[] =
            {
                BSWAP_32BIG_C(0x334a361eU), BSWAP_32BIG_C(0x5d071300U), BSWAP_32BIG_C(0x415d9f57U), BSWAP_32BIG_C(
                    0x58ba50b0U),
            };
            r_rsip_func102(Param_pa4f_func102_002);

            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_pa4f_func102_003[] =
            {
                BSWAP_32BIG_C(0x7777d002U), BSWAP_32BIG_C(0x5fae10c8U), BSWAP_32BIG_C(0x1050edd7U), BSWAP_32BIG_C(
                    0x578921e4U),
            };
            r_rsip_func102(Param_pa4f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
