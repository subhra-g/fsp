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

void r_rsip_func450 (uint32_t ARG1[])
{
    uint32_t iLoop = 0U;
    uint32_t iTemp = 0U;

    WR1_PROG(REG_0094H, 0x00003467U);

    WR1_PROG(REG_0094H, 0x000008e7U);

    static const uint32_t Param_func450_func100_001[] =
    {
        BSWAP_32BIG_C(0xc5dcf631U), BSWAP_32BIG_C(0x5e55c5c3U), BSWAP_32BIG_C(0x6d1f467cU), BSWAP_32BIG_C(0xb8c4a54bU),
    };
    r_rsip_func100(Param_func450_func100_001);
    WR1_PROG(REG_009CH, 0x810100a0U);
    WR1_PROG(REG_0008H, 0x00005006U);
    WAIT_STS(REG_0008H, 30, 1);
    RD1_ADDR(REG_002CH, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        static const uint32_t Param_func450_func100_002[] =
        {
            BSWAP_32BIG_C(0x288477d7U), BSWAP_32BIG_C(0x8400aa8cU), BSWAP_32BIG_C(0xf0a79771U), BSWAP_32BIG_C(
                0xc3027043U),
        };
        r_rsip_func100(Param_func450_func100_002);
        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0xe7008d05U, 0x00430011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

        WR1_PROG(REG_0094H, 0x0000a4e0U);
        WR1_PROG(REG_0094H, 0x00000004U);

        static const uint32_t Param_func450_func101_001[] =
        {
            BSWAP_32BIG_C(0x17ffb219U), BSWAP_32BIG_C(0xd4952a0bU), BSWAP_32BIG_C(0xda7074a9U), BSWAP_32BIG_C(
                0x5199fee3U),
        };
        r_rsip_func101(Param_func450_func101_001);
        iLoop = iLoop + 4U;
    }

    r_rsip_func_sub010(0x380008a7U);

    WR1_PROG(REG_0094H, 0x38000c21U);
    WR1_PROG(REG_009CH, 0x00000080U);
    WR1_PROG(REG_0040H, 0x00A60000U);

    static const uint32_t Param_func450_func100_003[] =
    {
        BSWAP_32BIG_C(0xa141bef3U), BSWAP_32BIG_C(0xdff8b589U), BSWAP_32BIG_C(0x656c4b56U), BSWAP_32BIG_C(0x4ed63597U),
    };
    r_rsip_func100(Param_func450_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_func450_func100_004[] =
        {
            BSWAP_32BIG_C(0x3eed7111U), BSWAP_32BIG_C(0xcaf71cc3U), BSWAP_32BIG_C(0xc4c3be30U), BSWAP_32BIG_C(
                0xd35ae7a3U),
        };
        r_rsip_func100(Param_func450_func100_004);
        WR1_PROG(REG_009CH, 0x81010040U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        iTemp = iLoop;
        for (iLoop = iTemp; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_func450_func100_005[] =
            {
                BSWAP_32BIG_C(0xd02a6a5eU), BSWAP_32BIG_C(0x01530f26U), BSWAP_32BIG_C(0x640ad303U), BSWAP_32BIG_C(
                    0xa908d701U),
            };
            r_rsip_func100(Param_func450_func100_005);
            WR1_PROG(REG_00D4H, 0x40000000U);
            r_rsip_func_sub006(0xe7008d05U, 0x00400011U);

            WR1_PROG(REG_0008H, 0x00001012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

            WR1_PROG(REG_0094H, 0x0000a4e0U);
            WR1_PROG(REG_0094H, 0x00000004U);

            static const uint32_t Param_func450_func101_002[] =
            {
                BSWAP_32BIG_C(0xe0b1cd95U), BSWAP_32BIG_C(0x4cd28629U), BSWAP_32BIG_C(0x8a2c1175U), BSWAP_32BIG_C(
                    0x44ae0a39U),
            };
            r_rsip_func101(Param_func450_func101_002);
            iLoop = iLoop + 4U;
        }

        r_rsip_func_sub010(0x38000847U);

        static const uint32_t Param_func450_func101_003[] =
        {
            BSWAP_32BIG_C(0x7b7dfd4bU), BSWAP_32BIG_C(0x5d956721U), BSWAP_32BIG_C(0xabafb78cU), BSWAP_32BIG_C(
                0xed293bcaU),
        };
        r_rsip_func101(Param_func450_func101_003);
    }

    static const uint32_t Param_func450_func100_006[] =
    {
        BSWAP_32BIG_C(0xf13bad4dU), BSWAP_32BIG_C(0xb13da076U), BSWAP_32BIG_C(0xb3ce398bU), BSWAP_32BIG_C(0x4b8c2ae0U),
    };
    r_rsip_func100(Param_func450_func100_006);
    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

    WR1_PROG(REG_00D4H, 0x40000000U);
    r_rsip_func_sub006(0x09108105U, 0x00410011U);

    WR1_PROG(REG_0008H, 0x00001012U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

    static const uint32_t Param_func450_func100_007[] =
    {
        BSWAP_32BIG_C(0xc4d561e6U), BSWAP_32BIG_C(0x3da94ce0U), BSWAP_32BIG_C(0x6b544229U), BSWAP_32BIG_C(0xfd6a59aeU),
    };
    r_rsip_func100(Param_func450_func100_007);
    WR1_PROG(REG_009CH, 0x81010000U);
    WR1_PROG(REG_0008H, 0x00005006U);
    WAIT_STS(REG_0008H, 30, 1);
    RD1_ADDR(REG_002CH, &ARG1[0]);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
