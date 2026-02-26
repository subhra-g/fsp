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

void r_rsip_func431 (const uint32_t ARG1[], const uint32_t ARG2[], const uint32_t ARG3[])
{
    r_rsip_func_sub022(0x00003427U, 0x0000b4a0U, 0x00000005U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004310U, 0x00000000U);

    static const uint32_t Param_func431_func101_001[] =
    {
        BSWAP_32BIG_C(0x04e2a3eeU), BSWAP_32BIG_C(0xfc2ebee6U), BSWAP_32BIG_C(0x2cfd4f0fU), BSWAP_32BIG_C(0xfaf6eb3dU),
    };
    r_rsip_func101(Param_func431_func101_001);
    r_rsip_func440(ARG1);

    static const uint32_t Param_func431_func100_001[] =
    {
        BSWAP_32BIG_C(0x9a4bb0b4U), BSWAP_32BIG_C(0xa4c18a6eU), BSWAP_32BIG_C(0x159a004bU), BSWAP_32BIG_C(0x2bd89c97U),
    };
    r_rsip_func100(Param_func431_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func431_func101_002[] =
        {
            BSWAP_32BIG_C(0x8008ce55U), BSWAP_32BIG_C(0x026cb91dU), BSWAP_32BIG_C(0x5451715bU), BSWAP_32BIG_C(
                0xa18e37acU),
        };
        r_rsip_func101(Param_func431_func101_002);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_009CH, 0x80840000U);
        r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
        WR1_PROG(REG_002CH, ARG2[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_func431_func100_002[] =
        {
            BSWAP_32BIG_C(0xe63ea73cU), BSWAP_32BIG_C(0x68f486e1U), BSWAP_32BIG_C(0x5b99d6bdU), BSWAP_32BIG_C(
                0xbe55600dU),
        };
        r_rsip_func100(Param_func431_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000105U);
            WR4_ADDR(REG_002CH, &ARG3[0]);

            r_rsip_func_sub009(0x00000401U, 0x00c10009U, 0x00001800U);

            r_rsip_func_sub009(0x00000402U, 0x00c10009U, 0x00001800U);

            static const uint32_t Param_func431_func101_003[] =
            {
                BSWAP_32BIG_C(0xfd6db979U), BSWAP_32BIG_C(0x79d0c303U), BSWAP_32BIG_C(0xb71baa7dU), BSWAP_32BIG_C(
                    0x06c7884eU),
            };
            r_rsip_func101(Param_func431_func101_003);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004311U, 0x00000000U);

            static const uint32_t Param_func431_func101_004[] =
            {
                BSWAP_32BIG_C(0x117af9f7U), BSWAP_32BIG_C(0x1d03ea82U), BSWAP_32BIG_C(0xad435ad0U), BSWAP_32BIG_C(
                    0xbf5d5148U),
            };
            r_rsip_func101(Param_func431_func101_004);
            r_rsip_func440(ARG3);

            static const uint32_t Param_func431_func101_005[] =
            {
                BSWAP_32BIG_C(0x46752a9eU), BSWAP_32BIG_C(0xe963a40cU), BSWAP_32BIG_C(0x8b5e2187U), BSWAP_32BIG_C(
                    0xef20c26aU),
            };
            r_rsip_func101(Param_func431_func101_005);
        }

        static const uint32_t Param_func431_func100_003[] =
        {
            BSWAP_32BIG_C(0x8c2eae75U), BSWAP_32BIG_C(0xb12e5c88U), BSWAP_32BIG_C(0x4146bc7dU), BSWAP_32BIG_C(
                0x4befc102U),
        };
        r_rsip_func100(Param_func431_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000002U);

            static const uint32_t Param_func431_func101_006[] =
            {
                BSWAP_32BIG_C(0x3eae2657U), BSWAP_32BIG_C(0x4fb09f43U), BSWAP_32BIG_C(0x286c1727U), BSWAP_32BIG_C(
                    0xa1875309U),
            };
            r_rsip_func101(Param_func431_func101_006);
        }
        else
        {
            static const uint32_t Param_func431_func100_004[] =
            {
                BSWAP_32BIG_C(0x9e389589U), BSWAP_32BIG_C(0xbd1679c8U), BSWAP_32BIG_C(0xc683a4c7U), BSWAP_32BIG_C(
                    0x54269e66U),
            };
            r_rsip_func100(Param_func431_func100_004);
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000010U);

            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub012(0x81840000U, 0x00490011U);

            WR1_PROG(REG_009CH, 0x80840000U);
            r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

            r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

            static const uint32_t Param_func431_func100_005[] =
            {
                BSWAP_32BIG_C(0xf3c67016U), BSWAP_32BIG_C(0x5ec6c218U), BSWAP_32BIG_C(0x1e5ac33aU), BSWAP_32BIG_C(
                    0x11d0888aU),
            };
            r_rsip_func100(Param_func431_func100_005);
            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x0a0000a4U, 0x00000000U);

            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func431_func101_007[] =
            {
                BSWAP_32BIG_C(0xb190b60dU), BSWAP_32BIG_C(0xa3574165U), BSWAP_32BIG_C(0x25a4959aU), BSWAP_32BIG_C(
                    0x02dbb4d3U),
            };
            r_rsip_func101(Param_func431_func101_007);
        }

        static const uint32_t Param_func431_func101_008[] =
        {
            BSWAP_32BIG_C(0x5f9953d2U), BSWAP_32BIG_C(0x7ae91a51U), BSWAP_32BIG_C(0x894f1940U), BSWAP_32BIG_C(
                0x28b77f56U),
        };
        r_rsip_func101(Param_func431_func101_008);
    }

    WR1_PROG(REG_0094H, 0x000034e1U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
