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

rsip_ret_t r_rsip_pa1f (const uint32_t InData_Text[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x80010000U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_TextLen[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00008c00U);
    WR1_PROG(REG_0094H, 0x0000000fU);

    r_rsip_func_sub007(0x38008800U, 0x00000000U, 0x00A60000U);

    static const uint32_t Param_pa1f_func100_001[] =
    {
        BSWAP_32BIG_C(0x0a6032a4U), BSWAP_32BIG_C(0x33da8786U), BSWAP_32BIG_C(0x73aa16e0U), BSWAP_32BIG_C(0x44436769U),
    };
    r_rsip_func100(Param_pa1f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0xe7008d05U);
        WR4_ADDR(REG_002CH, &InData_Text[0]);

        WR1_PROG(REG_0094H, 0x00000821U);
        r_rsip_func_sub003(0x80840001U, 0x03410011U);

        WR1_PROG(REG_0094H, 0x00000821U);

        WR1_PROG(REG_0094H, 0x000008a5U);

        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            r_rsip_func_sub016(0x3c0028a0U, 0x12003c25U, 0x00002ca0U);
        }

        static const uint32_t Param_pa1f_func100_002[] =
        {
            BSWAP_32BIG_C(0xd18b3490U), BSWAP_32BIG_C(0x6f6a6ee2U), BSWAP_32BIG_C(0x0534576cU), BSWAP_32BIG_C(
                0xe015b7d2U),
        };
        r_rsip_func100(Param_pa1f_func100_002);
        r_rsip_func_sub015(0x00000821U, 0x81840001U, 0x00005012U);
        RD1_ADDR(REG_002CH, &OutData_Text[0]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[2]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[3]);

        static const uint32_t Param_pa1f_func101_001[] =
        {
            BSWAP_32BIG_C(0x8e752d87U), BSWAP_32BIG_C(0x54e4c42dU), BSWAP_32BIG_C(0x8258eae8U), BSWAP_32BIG_C(
                0xeace9d5cU),
        };
        r_rsip_func101(Param_pa1f_func101_001);
    }
    else
    {
        static const uint32_t Param_pa1f_func101_002[] =
        {
            BSWAP_32BIG_C(0xee8929fdU), BSWAP_32BIG_C(0xbb62601cU), BSWAP_32BIG_C(0xc49290edU), BSWAP_32BIG_C(
                0x554a0abaU),
        };
        r_rsip_func101(Param_pa1f_func101_002);
    }

    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

    static const uint32_t Param_pa1f_func100_003[] =
    {
        BSWAP_32BIG_C(0x23779b99U), BSWAP_32BIG_C(0x23b05fa5U), BSWAP_32BIG_C(0x453c84c9U), BSWAP_32BIG_C(0x924ecce0U),
    };
    r_rsip_func100(Param_pa1f_func100_003);
    WR1_PROG(REG_00D4H, 0x40000000U);
    r_rsip_func_sub006(0x09108105U, 0x00410011U);

    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_MAC[0]);

    static const uint32_t Param_pa1f_func102_001[] =
    {
        BSWAP_32BIG_C(0xfb65f077U), BSWAP_32BIG_C(0x41a090d9U), BSWAP_32BIG_C(0xba456db1U), BSWAP_32BIG_C(0xc6fbb442U),
    };
    r_rsip_func102(Param_pa1f_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
