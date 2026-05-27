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

rsip_ret_t r_rsip_p95f (const uint32_t InData_Text[],
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

    static const uint32_t Param_p95f_func100_001[] =
    {
        BSWAP_32BIG_C(0xb9a27ff0U), BSWAP_32BIG_C(0x853bb8e7U), BSWAP_32BIG_C(0xfc884222U), BSWAP_32BIG_C(0x2032a4b2U),
    };
    r_rsip_func100(Param_p95f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0014H, 0x000003c1U);
        WR1_PROG(REG_00D0H, 0xe7000d05U);
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

        static const uint32_t Param_p95f_func100_002[] =
        {
            BSWAP_32BIG_C(0x809e1a95U), BSWAP_32BIG_C(0xec144a92U), BSWAP_32BIG_C(0x0daf90dcU), BSWAP_32BIG_C(
                0x46d7e386U),
        };
        r_rsip_func100(Param_p95f_func100_002);
        r_rsip_func_sub015(0x00000821U, 0x81840001U, 0x00005012U);
        RD1_ADDR(REG_002CH, &OutData_Text[0]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[2]);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_Text[3]);

        static const uint32_t Param_p95f_func101_001[] =
        {
            BSWAP_32BIG_C(0x68a372b7U), BSWAP_32BIG_C(0x828cfedfU), BSWAP_32BIG_C(0xae0a728bU), BSWAP_32BIG_C(
                0x186c51b5U),
        };
        r_rsip_func101(Param_p95f_func101_001);
    }
    else
    {
        static const uint32_t Param_p95f_func101_002[] =
        {
            BSWAP_32BIG_C(0xee0a14d0U), BSWAP_32BIG_C(0x59a5e822U), BSWAP_32BIG_C(0xeecece5cU), BSWAP_32BIG_C(
                0xf6b69b2cU),
        };
        r_rsip_func101(Param_p95f_func101_002);
    }

    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

    static const uint32_t Param_p95f_func100_003[] =
    {
        BSWAP_32BIG_C(0x8363bbbfU), BSWAP_32BIG_C(0x96f760c2U), BSWAP_32BIG_C(0x272d57b4U), BSWAP_32BIG_C(0x5b4f8cfeU),
    };
    r_rsip_func100(Param_p95f_func100_003);
    r_rsip_func_sub006(0x09100105U, 0x00410011U);

    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_MAC[0]);

    static const uint32_t Param_p95f_func102_001[] =
    {
        BSWAP_32BIG_C(0x90a81bb2U), BSWAP_32BIG_C(0xe27d2368U), BSWAP_32BIG_C(0x0de73bfdU), BSWAP_32BIG_C(0xfaaf820bU),
    };
    r_rsip_func102(Param_p95f_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
