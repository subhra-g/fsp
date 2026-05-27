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

void r_rsip_func435 (const uint32_t ARG1[], const uint32_t ARG2[], const uint32_t ARG3[])
{
    r_rsip_func_sub016(0x00003427U, 0x0000b4a0U, 0x00000007U);

    r_rsip_func_sub002(0x800100e0U, 0x00004350U);

    static const uint32_t Param_func435_func101_001[] =
    {
        BSWAP_32BIG_C(0x706124f0U), BSWAP_32BIG_C(0x4ee23e5eU), BSWAP_32BIG_C(0x979b363cU), BSWAP_32BIG_C(0x8b840219U),
    };
    r_rsip_func101(Param_func435_func101_001);
    r_rsip_func441(ARG1);

    static const uint32_t Param_func435_func100_001[] =
    {
        BSWAP_32BIG_C(0x29dfa0c4U), BSWAP_32BIG_C(0xd8356628U), BSWAP_32BIG_C(0x984f8feeU), BSWAP_32BIG_C(0xafd22014U),
    };
    r_rsip_func100(Param_func435_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func435_func101_002[] =
        {
            BSWAP_32BIG_C(0x95aaa3a8U), BSWAP_32BIG_C(0x5883bc48U), BSWAP_32BIG_C(0x3b9d5fa0U), BSWAP_32BIG_C(
                0x0e405048U),
        };
        r_rsip_func101(Param_func435_func101_002);
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x800100a0U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, ARG2[0]);
        r_rsip_func_sub012(0x38000ca5U, 0x00260000U);

        static const uint32_t Param_func435_func100_002[] =
        {
            BSWAP_32BIG_C(0x2568c34eU), BSWAP_32BIG_C(0xd1f43e20U), BSWAP_32BIG_C(0x6fb1198cU), BSWAP_32BIG_C(
                0x3b5f4cccU),
        };
        r_rsip_func100(Param_func435_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x08000105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &ARG3[0]);

            r_rsip_func_sub004(0x00000401U, 0x00c10009U);

            r_rsip_func_sub004(0x00000402U, 0x00c10009U);

            static const uint32_t Param_func435_func101_003[] =
            {
                BSWAP_32BIG_C(0xaf01154bU), BSWAP_32BIG_C(0xc96b8ef9U), BSWAP_32BIG_C(0x290b60fdU), BSWAP_32BIG_C(
                    0xdd36f081U),
            };
            r_rsip_func101(Param_func435_func101_003);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x00004351U);

            static const uint32_t Param_func435_func101_004[] =
            {
                BSWAP_32BIG_C(0xc9f580d4U), BSWAP_32BIG_C(0x1c77fc8bU), BSWAP_32BIG_C(0xd10c46dcU), BSWAP_32BIG_C(
                    0x73b3775eU),
            };
            r_rsip_func101(Param_func435_func101_004);
            r_rsip_func440(ARG3);

            static const uint32_t Param_func435_func101_005[] =
            {
                BSWAP_32BIG_C(0x4c75f945U), BSWAP_32BIG_C(0x9a2d64b3U), BSWAP_32BIG_C(0x6c1d37e9U), BSWAP_32BIG_C(
                    0xbccb9cf1U),
            };
            r_rsip_func101(Param_func435_func101_005);
        }

        static const uint32_t Param_func435_func100_003[] =
        {
            BSWAP_32BIG_C(0x1546dafcU), BSWAP_32BIG_C(0x38ae5968U), BSWAP_32BIG_C(0xbe0d5aa7U), BSWAP_32BIG_C(
                0x2e2b198bU),
        };
        r_rsip_func100(Param_func435_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000002U);

            static const uint32_t Param_func435_func101_006[] =
            {
                BSWAP_32BIG_C(0x1fb087f2U), BSWAP_32BIG_C(0x31113bbeU), BSWAP_32BIG_C(0x3db8ba78U), BSWAP_32BIG_C(
                    0x55d58874U),
            };
            r_rsip_func101(Param_func435_func101_006);
        }
        else
        {
            static const uint32_t Param_func435_func100_004[] =
            {
                BSWAP_32BIG_C(0x7770fc6cU), BSWAP_32BIG_C(0x9ddc6d91U), BSWAP_32BIG_C(0x7140eb47U), BSWAP_32BIG_C(
                    0xae40a264U),
            };
            r_rsip_func100(Param_func435_func100_004);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub004(0x0000181eU, 0x00430011U);

            static const uint32_t Param_func435_func100_005[] =
            {
                BSWAP_32BIG_C(0x0365b263U), BSWAP_32BIG_C(0x3a553601U), BSWAP_32BIG_C(0xe035deefU), BSWAP_32BIG_C(
                    0xe13b7653U),
            };
            r_rsip_func100(Param_func435_func100_005);
            r_rsip_func_sub006(0x08000095U, 0x00430011U);

            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000010U);

            WR1_PROG(REG_009CH, 0x80840000U);
            r_rsip_func_sub004(0x00000801U, 0x03430009U);

            r_rsip_func_sub004(0x00000802U, 0x03430009U);

            static const uint32_t Param_func435_func100_006[] =
            {
                BSWAP_32BIG_C(0x1b606ee9U), BSWAP_32BIG_C(0x79ad7e85U), BSWAP_32BIG_C(0xa526749fU), BSWAP_32BIG_C(
                    0x970bb169U),
            };
            r_rsip_func100(Param_func435_func100_006);
            r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x40000000U, 0x0a0080a4U);
            WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func435_func101_007[] =
            {
                BSWAP_32BIG_C(0x236e74a3U), BSWAP_32BIG_C(0x98d24e5cU), BSWAP_32BIG_C(0x879d23d5U), BSWAP_32BIG_C(
                    0x09209a15U),
            };
            r_rsip_func101(Param_func435_func101_007);
        }

        static const uint32_t Param_func435_func101_008[] =
        {
            BSWAP_32BIG_C(0xb3a369b5U), BSWAP_32BIG_C(0x25f7e7b6U), BSWAP_32BIG_C(0xebac3808U), BSWAP_32BIG_C(
                0x3b9652f1U),
        };
        r_rsip_func101(Param_func435_func101_008);
    }

    WR1_PROG(REG_0094H, 0x000034e1U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
