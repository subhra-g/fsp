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

void r_rsip_func157 (const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3[])
{
    uint32_t iLoop = 0U;
    uint32_t oLoop = 0U;

    WR1_PROG(REG_0094H, 0x00003467U);

    WR1_PROG(REG_0014H, 0x000003c1U);
    WR1_PROG(REG_00D0H, 0x08000065U);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &ARG1[0]);

    r_rsip_func_sub005(0x000000a1U, 0x08000074U, 0x00000000U);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x800100e0U, 0x000000ffU);

    static const uint32_t Param_func157_func101_001[] =
    {
        BSWAP_32BIG_C(0xb1fb3a8cU), BSWAP_32BIG_C(0xda46003dU), BSWAP_32BIG_C(0x486e7767U), BSWAP_32BIG_C(0x727814ccU),
    };
    r_rsip_func101(Param_func157_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x000034c4U);

    r_rsip_func_sub002(0x800100e0U, 0x000000feU);

    static const uint32_t Param_func157_func101_002[] =
    {
        BSWAP_32BIG_C(0xd8e1ce85U), BSWAP_32BIG_C(0x4934b0a4U), BSWAP_32BIG_C(0xfd0c9ca1U), BSWAP_32BIG_C(0x6b4a23e1U),
    };
    r_rsip_func101(Param_func157_func101_002);
    r_rsip_func044();

    static const uint32_t Param_func157_func100_001[] =
    {
        BSWAP_32BIG_C(0x9d755203U), BSWAP_32BIG_C(0xcd4c6313U), BSWAP_32BIG_C(0x3bc31b32U), BSWAP_32BIG_C(0xb7ca2e83U),
    };
    r_rsip_func100(Param_func157_func100_001);

    r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

    r_rsip_func081();

    WR1_PROG(REG_0094H, 0x00007c01U);
    WR1_PROG(REG_0040H, 0x00600000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    oLoop = 0U;
    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func157_func100_002[] =
            {
                BSWAP_32BIG_C(0x33d6092bU), BSWAP_32BIG_C(0x82f4b241U), BSWAP_32BIG_C(0xdad07a92U), BSWAP_32BIG_C(
                    0xc660daa9U),
            };
            r_rsip_func100(Param_func157_func100_002);
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0xd922090dU);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &ARG2[iLoop]);

            WR1_PROG(REG_00D4H, 0x40000000U);
            r_rsip_func_sub006(0xe7008d05U, 0x00410011U);

            WR1_PROG(REG_0008H, 0x00001012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD4_ADDR(REG_002CH, &ARG3[1 + iLoop]);

            static const uint32_t Param_func157_func101_003[] =
            {
                BSWAP_32BIG_C(0xada8180aU), BSWAP_32BIG_C(0x279b92d7U), BSWAP_32BIG_C(0xb4ad3bccU), BSWAP_32BIG_C(
                    0x7e67de85U),
            };
            r_rsip_func101(Param_func157_func101_003);
            iLoop = iLoop + 4U;
        }

        oLoop = iLoop;

        static const uint32_t Param_func157_func101_004[] =
        {
            BSWAP_32BIG_C(0xbe6ae8bfU), BSWAP_32BIG_C(0xdf2021a2U), BSWAP_32BIG_C(0x89b0c369U), BSWAP_32BIG_C(
                0xf604d556U),
        };
        r_rsip_func101(Param_func157_func101_004);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000016U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func157_func100_003[] =
            {
                BSWAP_32BIG_C(0x95e38f3eU), BSWAP_32BIG_C(0xab2f89dfU), BSWAP_32BIG_C(0x3e49f63cU), BSWAP_32BIG_C(
                    0x7d4f9186U),
            };
            r_rsip_func100(Param_func157_func100_003);
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0xd922090dU);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &ARG2[iLoop]);

            WR1_PROG(REG_00D4H, 0x40000000U);
            r_rsip_func_sub006(0xe8008105U, 0x00410011U);

            WR1_PROG(REG_0008H, 0x00001012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD4_ADDR(REG_002CH, &ARG3[1 + iLoop]);

            static const uint32_t Param_func157_func101_005[] =
            {
                BSWAP_32BIG_C(0xdc7887cbU), BSWAP_32BIG_C(0x0c39edeaU), BSWAP_32BIG_C(0xb63e4fa0U), BSWAP_32BIG_C(
                    0xb29a7997U),
            };
            r_rsip_func101(Param_func157_func101_005);
            iLoop = iLoop + 4U;
        }

        oLoop = iLoop;

        static const uint32_t Param_func157_func101_006[] =
        {
            BSWAP_32BIG_C(0x14ab75f8U), BSWAP_32BIG_C(0xe2a1a6b4U), BSWAP_32BIG_C(0x795bffefU), BSWAP_32BIG_C(
                0xc8013792U),
        };
        r_rsip_func101(Param_func157_func101_006);
    }

    static const uint32_t Param_func157_func100_004[] =
    {
        BSWAP_32BIG_C(0xcb76b4ceU), BSWAP_32BIG_C(0x4355f6f9U), BSWAP_32BIG_C(0x94aa6b09U), BSWAP_32BIG_C(0x43495277U),
    };
    r_rsip_func100(Param_func157_func100_004);
    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    r_rsip_func_sub006(0x09108105U, 0x00410011U);
    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &ARG3[1 + oLoop]);

    WR1_PROG(REG_0014H, 0x000003c1U);
    WR1_PROG(REG_00D0H, 0x0922090dU);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &ARG2[iLoop]);

    r_rsip_func_sub006(0x9c300005U, 0x00410011U);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
