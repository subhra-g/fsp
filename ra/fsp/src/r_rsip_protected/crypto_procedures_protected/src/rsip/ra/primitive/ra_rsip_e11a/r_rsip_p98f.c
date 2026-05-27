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

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x80010060U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_MACLength[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub007(0x38008860U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    r_rsip_func_sub007(0x00000010U, 0x342028a3U, 0x00260000U);

    static const uint32_t Param_p98f_func100_001[] =
    {
        BSWAP_32BIG_C(0xa665331eU), BSWAP_32BIG_C(0x25ae30daU), BSWAP_32BIG_C(0x79ccc05dU), BSWAP_32BIG_C(0x4a778539U),
    };
    r_rsip_func100(Param_p98f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p98f_func102_001[] =
        {
            BSWAP_32BIG_C(0x3fb7b863U), BSWAP_32BIG_C(0xb488fccaU), BSWAP_32BIG_C(0xa1fe13daU), BSWAP_32BIG_C(
                0xd4125252U),
        };
        r_rsip_func102(Param_p98f_func102_001);
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

        static const uint32_t Param_p98f_func100_002[] =
        {
            BSWAP_32BIG_C(0x53b63e53U), BSWAP_32BIG_C(0x2879571bU), BSWAP_32BIG_C(0xbb84f7e1U), BSWAP_32BIG_C(
                0x84ab406fU),
        };
        r_rsip_func100(Param_p98f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x07000d05U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x80840001U, 0x03410011U);

            WR1_PROG(REG_0094H, 0x00000821U);

            WR1_PROG(REG_0094H, 0x000008a5U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub016(0x3c0028a0U, 0x12003c25U, 0x00002ca0U);
            }

            static const uint32_t Param_p98f_func100_003[] =
            {
                BSWAP_32BIG_C(0xae8921c9U), BSWAP_32BIG_C(0xe3a53c17U), BSWAP_32BIG_C(0x4be0ea2bU), BSWAP_32BIG_C(
                    0x204f59bfU),
            };
            r_rsip_func100(Param_p98f_func100_003);
            r_rsip_func_sub015(0x00000821U, 0x81840001U, 0x00005012U);
            RD1_ADDR(REG_002CH, &OutData_Text[0]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[1]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[2]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[3]);

            WR1_PROG(REG_00D0H, 0x0e100405U);
            r_rsip_func_sub003(0x81840001U, 0x00490011U);

            static const uint32_t Param_p98f_func101_001[] =
            {
                BSWAP_32BIG_C(0x059cb716U), BSWAP_32BIG_C(0xe8eaf101U), BSWAP_32BIG_C(0x114648a9U), BSWAP_32BIG_C(
                    0x99a95fa2U),
            };
            r_rsip_func101(Param_p98f_func101_001);
        }
        else
        {
            static const uint32_t Param_p98f_func101_002[] =
            {
                BSWAP_32BIG_C(0xf90658d5U), BSWAP_32BIG_C(0x95ee8351U), BSWAP_32BIG_C(0x363eb488U), BSWAP_32BIG_C(
                    0x78c9bf87U),
            };
            r_rsip_func101(Param_p98f_func101_002);
        }

        r_rsip_func_sub005(0x000000a1U, 0x0c100104U, 0x00000000U);

        r_rsip_func_sub006(0x07200d05U, 0x00410011U);

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

        static const uint32_t Param_p98f_func100_004[] =
        {
            BSWAP_32BIG_C(0x58c85975U), BSWAP_32BIG_C(0xca006fe0U), BSWAP_32BIG_C(0x5cdea5fcU), BSWAP_32BIG_C(
                0x16dd2b10U),
        };
        r_rsip_func100(Param_p98f_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p98f_func102_002[] =
            {
                BSWAP_32BIG_C(0x705daacbU), BSWAP_32BIG_C(0x3520300aU), BSWAP_32BIG_C(0x4c47a1feU), BSWAP_32BIG_C(
                    0x1b120bffU),
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
                BSWAP_32BIG_C(0x1ef6e4b6U), BSWAP_32BIG_C(0xfadb209eU), BSWAP_32BIG_C(0x0a0e1b92U), BSWAP_32BIG_C(
                    0xfb69d6a2U),
            };
            r_rsip_func102(Param_p98f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
