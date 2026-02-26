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
    r_rsip_func_sub022(0x00003427U, 0x0000b4a0U, 0x00000007U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004350U, 0x00000000U);

    static const uint32_t Param_func435_func101_001[] =
    {
        BSWAP_32BIG_C(0x9747dbf8U), BSWAP_32BIG_C(0x469ba9caU), BSWAP_32BIG_C(0x0586fda3U), BSWAP_32BIG_C(0xdba4bf48U),
    };
    r_rsip_func101(Param_func435_func101_001);
    r_rsip_func441(ARG1);

    static const uint32_t Param_func435_func100_001[] =
    {
        BSWAP_32BIG_C(0x30725a83U), BSWAP_32BIG_C(0xe218468dU), BSWAP_32BIG_C(0xe0fe388dU), BSWAP_32BIG_C(0x4391bd9dU),
    };
    r_rsip_func100(Param_func435_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func435_func101_002[] =
        {
            BSWAP_32BIG_C(0x1de2106fU), BSWAP_32BIG_C(0x587b96c2U), BSWAP_32BIG_C(0x802b7c4aU), BSWAP_32BIG_C(
                0xb5103718U),
        };
        r_rsip_func101(Param_func435_func101_002);
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
        WR1_PROG(REG_002CH, ARG2[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_func435_func100_002[] =
        {
            BSWAP_32BIG_C(0xc562a457U), BSWAP_32BIG_C(0x4cc62f7fU), BSWAP_32BIG_C(0x042ee1f5U), BSWAP_32BIG_C(
                0x979a58b5U),
        };
        r_rsip_func100(Param_func435_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000105U);
            WR4_ADDR(REG_002CH, &ARG3[0]);

            r_rsip_func_sub009(0x00000401U, 0x00c10009U, 0x00001800U);

            r_rsip_func_sub009(0x00000402U, 0x00c10009U, 0x00001800U);

            static const uint32_t Param_func435_func101_003[] =
            {
                BSWAP_32BIG_C(0xdfc2d4a5U), BSWAP_32BIG_C(0x1d9f0881U), BSWAP_32BIG_C(0x0ccdea29U), BSWAP_32BIG_C(
                    0xee33f5a9U),
            };
            r_rsip_func101(Param_func435_func101_003);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004351U, 0x00000000U);

            static const uint32_t Param_func435_func101_004[] =
            {
                BSWAP_32BIG_C(0x331d5292U), BSWAP_32BIG_C(0x57c199c9U), BSWAP_32BIG_C(0xd5de2579U), BSWAP_32BIG_C(
                    0xb9255b3eU),
            };
            r_rsip_func101(Param_func435_func101_004);
            r_rsip_func440(ARG3);

            static const uint32_t Param_func435_func101_005[] =
            {
                BSWAP_32BIG_C(0x9257c629U), BSWAP_32BIG_C(0x9282a745U), BSWAP_32BIG_C(0xde81764bU), BSWAP_32BIG_C(
                    0xb00b32c8U),
            };
            r_rsip_func101(Param_func435_func101_005);
        }

        static const uint32_t Param_func435_func100_003[] =
        {
            BSWAP_32BIG_C(0x0a775b5bU), BSWAP_32BIG_C(0xe124ab68U), BSWAP_32BIG_C(0xa76d5eccU), BSWAP_32BIG_C(
                0x7059ffe2U),
        };
        r_rsip_func100(Param_func435_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000002U);

            static const uint32_t Param_func435_func101_006[] =
            {
                BSWAP_32BIG_C(0x15f625dcU), BSWAP_32BIG_C(0xafd1a28fU), BSWAP_32BIG_C(0x545e3fb4U), BSWAP_32BIG_C(
                    0x3be74c16U),
            };
            r_rsip_func101(Param_func435_func101_006);
        }
        else
        {
            static const uint32_t Param_func435_func100_004[] =
            {
                BSWAP_32BIG_C(0x13a6226fU), BSWAP_32BIG_C(0xb9db1617U), BSWAP_32BIG_C(0x8698bed1U), BSWAP_32BIG_C(
                    0x92d3058eU),
            };
            r_rsip_func100(Param_func435_func100_004);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

            static const uint32_t Param_func435_func100_005[] =
            {
                BSWAP_32BIG_C(0x0e8a1682U), BSWAP_32BIG_C(0x7cc2339cU), BSWAP_32BIG_C(0x5490e049U), BSWAP_32BIG_C(
                    0x2c140802U),
            };
            r_rsip_func100(Param_func435_func100_005);
            r_rsip_func_sub013(0x08000095U, 0x00430011U);

            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000010U);

            WR1_PROG(REG_009CH, 0x80840000U);
            r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

            r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

            static const uint32_t Param_func435_func100_006[] =
            {
                BSWAP_32BIG_C(0x00db2df1U), BSWAP_32BIG_C(0xba12028aU), BSWAP_32BIG_C(0x34047592U), BSWAP_32BIG_C(
                    0x4e1944d1U),
            };
            r_rsip_func100(Param_func435_func100_006);
            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub011(0x000000a1U, 0x40000000U, 0x0a0080a4U);
            WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func435_func101_007[] =
            {
                BSWAP_32BIG_C(0x8d639aecU), BSWAP_32BIG_C(0x7bd7159eU), BSWAP_32BIG_C(0x9fcd63aaU), BSWAP_32BIG_C(
                    0x169b657dU),
            };
            r_rsip_func101(Param_func435_func101_007);
        }

        static const uint32_t Param_func435_func101_008[] =
        {
            BSWAP_32BIG_C(0xe63049ceU), BSWAP_32BIG_C(0x4fbd40b8U), BSWAP_32BIG_C(0x125b4092U), BSWAP_32BIG_C(
                0x676dacb7U),
        };
        r_rsip_func101(Param_func435_func101_008);
    }

    WR1_PROG(REG_0094H, 0x000034e1U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
