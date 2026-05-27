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
    r_rsip_func_sub016(0x00003427U, 0x0000b4a0U, 0x00000005U);

    r_rsip_func_sub002(0x800100e0U, 0x00004310U);

    static const uint32_t Param_func431_func101_001[] =
    {
        BSWAP_32BIG_C(0xc049ba8dU), BSWAP_32BIG_C(0xc8b85f30U), BSWAP_32BIG_C(0x9d795e8eU), BSWAP_32BIG_C(0x3aae8d9dU),
    };
    r_rsip_func101(Param_func431_func101_001);
    r_rsip_func440(ARG1);

    static const uint32_t Param_func431_func100_001[] =
    {
        BSWAP_32BIG_C(0x08befa93U), BSWAP_32BIG_C(0x55bb3553U), BSWAP_32BIG_C(0xb849047dU), BSWAP_32BIG_C(0x5318be5bU),
    };
    r_rsip_func100(Param_func431_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000001U);

        static const uint32_t Param_func431_func101_002[] =
        {
            BSWAP_32BIG_C(0x09bc9692U), BSWAP_32BIG_C(0xcebb9908U), BSWAP_32BIG_C(0xd5aeac5dU), BSWAP_32BIG_C(
                0xf07519e6U),
        };
        r_rsip_func101(Param_func431_func101_002);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_009CH, 0x80840000U);
        r_rsip_func_sub004(0x00000801U, 0x03430009U);

        r_rsip_func_sub004(0x00000802U, 0x03430009U);

        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x800100a0U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, ARG2[0]);
        r_rsip_func_sub012(0x38000ca5U, 0x00260000U);

        static const uint32_t Param_func431_func100_002[] =
        {
            BSWAP_32BIG_C(0x5fef9e36U), BSWAP_32BIG_C(0x5a2b350bU), BSWAP_32BIG_C(0x1daed944U), BSWAP_32BIG_C(
                0x84cd191fU),
        };
        r_rsip_func100(Param_func431_func100_002);
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

            static const uint32_t Param_func431_func101_003[] =
            {
                BSWAP_32BIG_C(0xb3712f01U), BSWAP_32BIG_C(0x778ede5eU), BSWAP_32BIG_C(0x9bc50b93U), BSWAP_32BIG_C(
                    0x07aa6419U),
            };
            r_rsip_func101(Param_func431_func101_003);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x00004311U);

            static const uint32_t Param_func431_func101_004[] =
            {
                BSWAP_32BIG_C(0x8839e0edU), BSWAP_32BIG_C(0xff8df881U), BSWAP_32BIG_C(0x24ec517cU), BSWAP_32BIG_C(
                    0x0b7cd6fdU),
            };
            r_rsip_func101(Param_func431_func101_004);
            r_rsip_func440(ARG3);

            static const uint32_t Param_func431_func101_005[] =
            {
                BSWAP_32BIG_C(0x75c1f3e5U), BSWAP_32BIG_C(0x160a42b6U), BSWAP_32BIG_C(0x91cfb05aU), BSWAP_32BIG_C(
                    0x2ef0ee1fU),
            };
            r_rsip_func101(Param_func431_func101_005);
        }

        static const uint32_t Param_func431_func100_003[] =
        {
            BSWAP_32BIG_C(0xcc0a0bacU), BSWAP_32BIG_C(0xea86285fU), BSWAP_32BIG_C(0x973eee1aU), BSWAP_32BIG_C(
                0x1bec20f7U),
        };
        r_rsip_func100(Param_func431_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000002U);

            static const uint32_t Param_func431_func101_006[] =
            {
                BSWAP_32BIG_C(0x53079513U), BSWAP_32BIG_C(0x3c40acf8U), BSWAP_32BIG_C(0x64fc58c4U), BSWAP_32BIG_C(
                    0x2ad0348eU),
            };
            r_rsip_func101(Param_func431_func101_006);
        }
        else
        {
            static const uint32_t Param_func431_func100_004[] =
            {
                BSWAP_32BIG_C(0x05dc4fc4U), BSWAP_32BIG_C(0x558a951bU), BSWAP_32BIG_C(0x1c28d305U), BSWAP_32BIG_C(
                    0x5c8cb3deU),
            };
            r_rsip_func100(Param_func431_func100_004);
            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000010U);

            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub003(0x81840000U, 0x00490011U);

            WR1_PROG(REG_009CH, 0x80840000U);
            r_rsip_func_sub004(0x00000801U, 0x03430009U);

            r_rsip_func_sub004(0x00000802U, 0x03430009U);

            static const uint32_t Param_func431_func100_005[] =
            {
                BSWAP_32BIG_C(0x87f206efU), BSWAP_32BIG_C(0x6a486b64U), BSWAP_32BIG_C(0xe2a8bcf4U), BSWAP_32BIG_C(
                    0x35c95095U),
            };
            r_rsip_func100(Param_func431_func100_005);
            r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub005(0x000000a1U, 0x0a0000a4U, 0x00000000U);

            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func431_func101_007[] =
            {
                BSWAP_32BIG_C(0x1405f52bU), BSWAP_32BIG_C(0xebcf36f8U), BSWAP_32BIG_C(0x2587557fU), BSWAP_32BIG_C(
                    0x67fa6316U),
            };
            r_rsip_func101(Param_func431_func101_007);
        }

        static const uint32_t Param_func431_func101_008[] =
        {
            BSWAP_32BIG_C(0x4868032dU), BSWAP_32BIG_C(0x02518491U), BSWAP_32BIG_C(0xff35ab10U), BSWAP_32BIG_C(
                0xd269cb0fU),
        };
        r_rsip_func101(Param_func431_func101_008);
    }

    WR1_PROG(REG_0094H, 0x000034e1U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
