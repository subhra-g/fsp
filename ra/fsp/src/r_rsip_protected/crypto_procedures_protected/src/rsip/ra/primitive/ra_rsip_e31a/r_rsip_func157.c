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

    WR1_PROG(REG_0094H, 0x00003467U);

    r_rsip_func_sub019(0x000003c1U, 0x08000065U);
    WR4_ADDR(REG_002CH, &ARG1[0]);

    r_rsip_func_sub008(0x000000a1U, 0x08000074U, 0x00000000U);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f157U, 0x00000000U);

    static const uint32_t Param_func157_func101_001[] =
    {
        BSWAP_32BIG_C(0xb048bbd4U), BSWAP_32BIG_C(0xf20eee6dU), BSWAP_32BIG_C(0xb4cf1f5aU), BSWAP_32BIG_C(0x48d4d078U),
    };
    r_rsip_func101(Param_func157_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x000034c4U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f157U, 0x00000000U);

    static const uint32_t Param_func157_func101_002[] =
    {
        BSWAP_32BIG_C(0xfa2e33a9U), BSWAP_32BIG_C(0x4949c9deU), BSWAP_32BIG_C(0x0b4501bcU), BSWAP_32BIG_C(0x2754d1afU),
    };
    r_rsip_func101(Param_func157_func101_002);
    r_rsip_func044();

    static const uint32_t Param_func157_func100_001[] =
    {
        BSWAP_32BIG_C(0x667102c9U), BSWAP_32BIG_C(0x5ce91f4fU), BSWAP_32BIG_C(0xe04364daU), BSWAP_32BIG_C(0xf692d317U),
    };
    r_rsip_func100(Param_func157_func100_001);

    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

    r_rsip_func081();

    WR1_PROG(REG_0094H, 0x00007c01U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func157_func100_002[] =
            {
                BSWAP_32BIG_C(0xb4aab5dcU), BSWAP_32BIG_C(0x77652d00U), BSWAP_32BIG_C(0x85ed7cb6U), BSWAP_32BIG_C(
                    0xf66fcdd2U),
            };
            r_rsip_func100(Param_func157_func100_002);
            r_rsip_func_sub019(0x000003c1U, 0xd922090dU);
            WR4_ADDR(REG_002CH, &ARG2[iLoop]);

            r_rsip_func_sub004(0x40000000U, 0xe7008d05U, 0x00410011U, 0x00001012U);
            RD4_ADDR(REG_002CH, &ARG3[1 + iLoop]);

            static const uint32_t Param_func157_func101_003[] =
            {
                BSWAP_32BIG_C(0xd45f82dbU), BSWAP_32BIG_C(0xeb7245c5U), BSWAP_32BIG_C(0x714c575dU), BSWAP_32BIG_C(
                    0x9bed87d9U),
            };
            r_rsip_func101(Param_func157_func101_003);
            iLoop = iLoop + 4U;
        }

        static const uint32_t Param_func157_func101_004[] =
        {
            BSWAP_32BIG_C(0x2b8bebfdU), BSWAP_32BIG_C(0x82949a31U), BSWAP_32BIG_C(0x2ced197dU), BSWAP_32BIG_C(
                0xc78ef450U),
        };
        r_rsip_func101(Param_func157_func101_004);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000016U)
    {
        for (iLoop = 0U; iLoop < (INST_DATA_SIZE - 4); )
        {
            static const uint32_t Param_func157_func100_003[] =
            {
                BSWAP_32BIG_C(0xd70fa5fbU), BSWAP_32BIG_C(0x97e2e477U), BSWAP_32BIG_C(0x8e10bd9fU), BSWAP_32BIG_C(
                    0x0f4fe421U),
            };
            r_rsip_func100(Param_func157_func100_003);
            r_rsip_func_sub019(0x000003c1U, 0xd922090dU);
            WR4_ADDR(REG_002CH, &ARG2[iLoop]);

            r_rsip_func_sub004(0x40000000U, 0xe8008105U, 0x00410011U, 0x00001012U);
            RD4_ADDR(REG_002CH, &ARG3[1 + iLoop]);

            static const uint32_t Param_func157_func101_005[] =
            {
                BSWAP_32BIG_C(0xea9c0a88U), BSWAP_32BIG_C(0x588f599aU), BSWAP_32BIG_C(0x7b9d8071U), BSWAP_32BIG_C(
                    0x7e180d1dU),
            };
            r_rsip_func101(Param_func157_func101_005);
            iLoop = iLoop + 4U;
        }

        static const uint32_t Param_func157_func101_006[] =
        {
            BSWAP_32BIG_C(0xa5cfedb7U), BSWAP_32BIG_C(0x3be78840U), BSWAP_32BIG_C(0x9c0c6ecdU), BSWAP_32BIG_C(
                0x2e91cb8aU),
        };
        r_rsip_func101(Param_func157_func101_006);
    }

    static const uint32_t Param_func157_func100_004[] =
    {
        BSWAP_32BIG_C(0x63085c72U), BSWAP_32BIG_C(0x61065e27U), BSWAP_32BIG_C(0xe487b4eaU), BSWAP_32BIG_C(0xa2b0bde8U),
    };
    r_rsip_func100(Param_func157_func100_004);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &ARG3[1 + iLoop]);

    r_rsip_func_sub019(0x000003c1U, 0x0922090dU);
    WR4_ADDR(REG_002CH, &ARG2[iLoop]);

    r_rsip_func_sub013(0x9c300005U, 0x00410011U);

    WR1_PROG(REG_0094H, 0x000034e3U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
