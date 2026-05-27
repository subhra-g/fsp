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

rsip_ret_t r_rsip_p98i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00980001U, 0x00000005U);

    r_rsip_func_sub002(0x800100e0U, 0x00009801U);

    static const uint32_t Param_p98i_func101_001[] =
    {
        BSWAP_32BIG_C(0x7a41ee26U), BSWAP_32BIG_C(0x592d34a5U), BSWAP_32BIG_C(0xec851f8fU), BSWAP_32BIG_C(0xa8a4d4c5U),
    };
    r_rsip_func101(Param_p98i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p98i_func100_001[] =
    {
        BSWAP_32BIG_C(0x43134419U), BSWAP_32BIG_C(0xd1b94409U), BSWAP_32BIG_C(0xf630a657U), BSWAP_32BIG_C(0xbf6c7580U),
    };
    r_rsip_func100(Param_p98i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p98i_func102_001[] =
        {
            BSWAP_32BIG_C(0x08480999U), BSWAP_32BIG_C(0xda7755caU), BSWAP_32BIG_C(0xf9d171b8U), BSWAP_32BIG_C(
                0x0b640d7bU),
        };
        r_rsip_func102(Param_p98i_func102_001);
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

        static const uint32_t Param_p98i_func100_002[] =
        {
            BSWAP_32BIG_C(0x42db3362U), BSWAP_32BIG_C(0x337f2c4bU), BSWAP_32BIG_C(0xcbbdcd08U), BSWAP_32BIG_C(
                0x238072c8U),
        };
        r_rsip_func100(Param_p98i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x08000045U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_p98i_func101_002[] =
            {
                BSWAP_32BIG_C(0xe8d9c668U), BSWAP_32BIG_C(0x63967497U), BSWAP_32BIG_C(0x3ea72d50U), BSWAP_32BIG_C(
                    0xb1429127U),
            };
            r_rsip_func101(Param_p98i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x00009802U);

            static const uint32_t Param_p98i_func101_003[] =
            {
                BSWAP_32BIG_C(0xb92d153bU), BSWAP_32BIG_C(0x006718e2U), BSWAP_32BIG_C(0x986a8cd2U), BSWAP_32BIG_C(
                    0x9ebfaad9U),
            };
            r_rsip_func101(Param_p98i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_p98i_func100_003[] =
            {
                BSWAP_32BIG_C(0xff8fe263U), BSWAP_32BIG_C(0xbd011d63U), BSWAP_32BIG_C(0x4f5bedaaU), BSWAP_32BIG_C(
                    0x18aeebd7U),
            };
            r_rsip_func100(Param_p98i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p98i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xf667807bU), BSWAP_32BIG_C(0x95553116U), BSWAP_32BIG_C(0x7abd5529U), BSWAP_32BIG_C(
                        0x3ac25e1aU),
                };
                r_rsip_func102(Param_p98i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub004(0x00000801U, 0x00430009U);

                r_rsip_func_sub004(0x00000802U, 0x00430009U);

                static const uint32_t Param_p98i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x242555e3U), BSWAP_32BIG_C(0xc21cab02U), BSWAP_32BIG_C(0xd45ba34aU), BSWAP_32BIG_C(
                        0xae10c4d3U),
                };
                r_rsip_func101(Param_p98i_func101_004);
            }
        }

        static const uint32_t Param_p98i_func100_004[] =
        {
            BSWAP_32BIG_C(0x632fbe46U), BSWAP_32BIG_C(0xc1715091U), BSWAP_32BIG_C(0x8913a3afU), BSWAP_32BIG_C(
                0x473fdb14U),
        };
        r_rsip_func100(Param_p98i_func100_004);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub003(0x81840000U, 0x00490011U);

        WR1_PROG(REG_00D4H, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p98i_func101_005[] =
        {
            BSWAP_32BIG_C(0x2f27aa1bU), BSWAP_32BIG_C(0xc5e6fe73U), BSWAP_32BIG_C(0xd7f41b1eU), BSWAP_32BIG_C(
                0x65338922U),
        };
        r_rsip_func101(Param_p98i_func101_005);

        return RSIP_RET_PASS;
    }
}
