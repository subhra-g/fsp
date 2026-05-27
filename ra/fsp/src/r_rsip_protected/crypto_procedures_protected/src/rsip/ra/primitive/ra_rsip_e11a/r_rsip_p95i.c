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

rsip_ret_t r_rsip_p95i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00950001U, 0x00000005U);

    r_rsip_func_sub002(0x800100e0U, 0x00009501U);

    static const uint32_t Param_p95i_func101_001[] =
    {
        BSWAP_32BIG_C(0x0c0018c3U), BSWAP_32BIG_C(0x20958bdaU), BSWAP_32BIG_C(0x4b28f863U), BSWAP_32BIG_C(0xeef0fabaU),
    };
    r_rsip_func101(Param_p95i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p95i_func100_001[] =
    {
        BSWAP_32BIG_C(0x98ecec4dU), BSWAP_32BIG_C(0x404021ccU), BSWAP_32BIG_C(0xe6f2f501U), BSWAP_32BIG_C(0xb144740fU),
    };
    r_rsip_func100(Param_p95i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p95i_func102_001[] =
        {
            BSWAP_32BIG_C(0xcf36a407U), BSWAP_32BIG_C(0x518b72dbU), BSWAP_32BIG_C(0x2e0143a8U), BSWAP_32BIG_C(
                0x4d374773U),
        };
        r_rsip_func102(Param_p95i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_009CH, 0x80840000U);
        r_rsip_func_sub004(0x00000801U, 0x03430009U);

        r_rsip_func_sub004(0x00000802U, 0x03430009U);

        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010080U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        r_rsip_func_sub012(0x38000c84U, 0x00260000U);

        static const uint32_t Param_p95i_func100_002[] =
        {
            BSWAP_32BIG_C(0xfe78b3e8U), BSWAP_32BIG_C(0x9c3711efU), BSWAP_32BIG_C(0x0311946dU), BSWAP_32BIG_C(
                0xe3240b94U),
        };
        r_rsip_func100(Param_p95i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x08000045U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_p95i_func101_002[] =
            {
                BSWAP_32BIG_C(0x1a15466dU), BSWAP_32BIG_C(0xdcdcc075U), BSWAP_32BIG_C(0x7951c9d5U), BSWAP_32BIG_C(
                    0x67331294U),
            };
            r_rsip_func101(Param_p95i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x00009502U);

            static const uint32_t Param_p95i_func101_003[] =
            {
                BSWAP_32BIG_C(0xb578499bU), BSWAP_32BIG_C(0x82882949U), BSWAP_32BIG_C(0x87fc7de2U), BSWAP_32BIG_C(
                    0xd0d297f3U),
            };
            r_rsip_func101(Param_p95i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_p95i_func100_003[] =
            {
                BSWAP_32BIG_C(0x10cb73caU), BSWAP_32BIG_C(0x80bc1252U), BSWAP_32BIG_C(0xd1500eceU), BSWAP_32BIG_C(
                    0x1ccac826U),
            };
            r_rsip_func100(Param_p95i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p95i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x28b48edfU), BSWAP_32BIG_C(0xa584e2d0U), BSWAP_32BIG_C(0x1134273bU), BSWAP_32BIG_C(
                        0xf57fe680U),
                };
                r_rsip_func102(Param_p95i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub004(0x00000801U, 0x00430009U);

                r_rsip_func_sub004(0x00000802U, 0x00430009U);

                static const uint32_t Param_p95i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x5584cdb3U), BSWAP_32BIG_C(0x390dc7d6U), BSWAP_32BIG_C(0xdb63c81fU), BSWAP_32BIG_C(
                        0xd796655bU),
                };
                r_rsip_func101(Param_p95i_func101_004);
            }
        }

        static const uint32_t Param_p95i_func100_004[] =
        {
            BSWAP_32BIG_C(0x78b98525U), BSWAP_32BIG_C(0x88e32fc5U), BSWAP_32BIG_C(0xc922548aU), BSWAP_32BIG_C(
                0x860b69b8U),
        };
        r_rsip_func100(Param_p95i_func100_004);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub003(0x81840000U, 0x00490011U);

        WR1_PROG(REG_00D4H, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p95i_func101_005[] =
        {
            BSWAP_32BIG_C(0x47457a11U), BSWAP_32BIG_C(0x7e435741U), BSWAP_32BIG_C(0xbda8e140U), BSWAP_32BIG_C(
                0xcce9ff15U),
        };
        r_rsip_func101(Param_p95i_func101_005);

        return RSIP_RET_PASS;
    }
}
