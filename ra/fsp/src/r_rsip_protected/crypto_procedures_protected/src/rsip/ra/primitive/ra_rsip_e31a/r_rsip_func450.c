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
        BSWAP_32BIG_C(0x39c966b9U), BSWAP_32BIG_C(0xd661347dU), BSWAP_32BIG_C(0x83f824b7U), BSWAP_32BIG_C(0x80fe3307U),
    };
    r_rsip_func100(Param_func450_func100_001);
    r_rsip_func_sub017(0x810100a0U, 0x00005006U);
    RD1_ADDR(REG_002CH, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        static const uint32_t Param_func450_func100_002[] =
        {
            BSWAP_32BIG_C(0x568bed21U), BSWAP_32BIG_C(0x6c1e9f93U), BSWAP_32BIG_C(0xd10a1ed7U), BSWAP_32BIG_C(
                0x5756b38bU),
        };
        r_rsip_func100(Param_func450_func100_002);
        r_rsip_func_sub004(0x40000000U, 0xe7008d05U, 0x00430011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

        WR1_PROG(REG_0094H, 0x0000a4e0U);
        WR1_PROG(REG_0094H, 0x00000004U);

        static const uint32_t Param_func450_func101_001[] =
        {
            BSWAP_32BIG_C(0xbc29d000U), BSWAP_32BIG_C(0x3462836aU), BSWAP_32BIG_C(0x10ffed90U), BSWAP_32BIG_C(
                0x3bad559aU),
        };
        r_rsip_func101(Param_func450_func101_001);
        iLoop = iLoop + 4U;
    }

    r_rsip_func_sub016(0x380008a7U, 0x00000080U, 0x00270000U);
    WR1_PROG(REG_0040H, 0x00402000U);

    r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00A70000U);

    static const uint32_t Param_func450_func100_003[] =
    {
        BSWAP_32BIG_C(0xea5d61d5U), BSWAP_32BIG_C(0xd4ef8b44U), BSWAP_32BIG_C(0x8be2dcbeU), BSWAP_32BIG_C(0x086423e4U),
    };
    r_rsip_func100(Param_func450_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_func450_func100_004[] =
        {
            BSWAP_32BIG_C(0xdf3e1f39U), BSWAP_32BIG_C(0xa0125d9fU), BSWAP_32BIG_C(0x6b78c1faU), BSWAP_32BIG_C(
                0x9fd3c553U),
        };
        r_rsip_func100(Param_func450_func100_004);
        r_rsip_func_sub017(0x81010040U, 0x00005006U);
        RD1_ADDR(REG_002CH, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        iTemp = iLoop;
        for (iLoop = iTemp; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_func450_func100_005[] =
            {
                BSWAP_32BIG_C(0x84e0a22eU), BSWAP_32BIG_C(0x05b44189U), BSWAP_32BIG_C(0x12773a0dU), BSWAP_32BIG_C(
                    0x753b7983U),
            };
            r_rsip_func100(Param_func450_func100_005);
            r_rsip_func_sub004(0x40000000U, 0xe7008d05U, 0x00400011U, 0x00001012U);
            RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

            WR1_PROG(REG_0094H, 0x0000a4e0U);
            WR1_PROG(REG_0094H, 0x00000004U);

            static const uint32_t Param_func450_func101_002[] =
            {
                BSWAP_32BIG_C(0xd35aefc7U), BSWAP_32BIG_C(0xf7f0563fU), BSWAP_32BIG_C(0x59891268U), BSWAP_32BIG_C(
                    0xbb0dceccU),
            };
            r_rsip_func101(Param_func450_func101_002);
            iLoop = iLoop + 4U;
        }

        r_rsip_func_sub016(0x38000847U, 0x00000080U, 0x00270000U);
        WR1_PROG(REG_0040H, 0x00402000U);

        static const uint32_t Param_func450_func101_003[] =
        {
            BSWAP_32BIG_C(0x4e1c2932U), BSWAP_32BIG_C(0x4526a61fU), BSWAP_32BIG_C(0x04e0533cU), BSWAP_32BIG_C(
                0xad070dd3U),
        };
        r_rsip_func101(Param_func450_func101_003);
    }

    static const uint32_t Param_func450_func100_006[] =
    {
        BSWAP_32BIG_C(0x238895f7U), BSWAP_32BIG_C(0x72f5f4d5U), BSWAP_32BIG_C(0x095eaf26U), BSWAP_32BIG_C(0x939c4fb2U),
    };
    r_rsip_func100(Param_func450_func100_006);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &ARG1[1 + iLoop]);

    static const uint32_t Param_func450_func100_007[] =
    {
        BSWAP_32BIG_C(0xc51f3180U), BSWAP_32BIG_C(0xd93e6e83U), BSWAP_32BIG_C(0xa185e50aU), BSWAP_32BIG_C(0x4949127aU),
    };
    r_rsip_func100(Param_func450_func100_007);
    r_rsip_func_sub017(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_002CH, &ARG1[0]);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
