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

rsip_ret_t r_rsip_p50i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00500001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    r_rsip_func_sub018(0x00000000U, 0x0000b4a0U, 0x00000007U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000050U, 0x00000000U);

    static const uint32_t Param_p50i_func101_001[] =
    {
        BSWAP_32BIG_C(0x1e50768aU), BSWAP_32BIG_C(0x5930933bU), BSWAP_32BIG_C(0x311f1280U), BSWAP_32BIG_C(0xece84cb3U),
    };
    r_rsip_func101(Param_p50i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_p50i_func100_001[] =
    {
        BSWAP_32BIG_C(0x6327f387U), BSWAP_32BIG_C(0x2baf972dU), BSWAP_32BIG_C(0x89127376U), BSWAP_32BIG_C(0x72e99f32U),
    };
    r_rsip_func100(Param_p50i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p50i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc5e00c86U), BSWAP_32BIG_C(0x69d970a5U), BSWAP_32BIG_C(0x8961cdc1U), BSWAP_32BIG_C(
                0x32aa4fa1U),
        };
        r_rsip_func102(Param_p50i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x3c00a880U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_p50i_func100_002[] =
        {
            BSWAP_32BIG_C(0xe7b5ccf0U), BSWAP_32BIG_C(0x34c50a1aU), BSWAP_32BIG_C(0x22e5823aU), BSWAP_32BIG_C(
                0xc1795e76U),
        };
        r_rsip_func100(Param_p50i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x000008a5U);

            r_rsip_func_sub010(0x3c00a880U, 0x00000004U, 0x00A70000U);

            static const uint32_t Param_p50i_func100_003[] =
            {
                BSWAP_32BIG_C(0x69c8e350U), BSWAP_32BIG_C(0xf1556ea8U), BSWAP_32BIG_C(0x8471565bU), BSWAP_32BIG_C(
                    0x36da8bf9U),
            };
            r_rsip_func100(Param_p50i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_002CH, InData_IVType[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                static const uint32_t Param_p50i_func101_002[] =
                {
                    BSWAP_32BIG_C(0x1d5a7194U), BSWAP_32BIG_C(0x2c64bdadU), BSWAP_32BIG_C(0x48d01062U), BSWAP_32BIG_C(
                        0x8f9350d7U),
                };
                r_rsip_func101(Param_p50i_func101_002);
            }

            r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

            static const uint32_t Param_p50i_func100_004[] =
            {
                BSWAP_32BIG_C(0xff3bb46dU), BSWAP_32BIG_C(0x0ca2b8ceU), BSWAP_32BIG_C(0xea68c347U), BSWAP_32BIG_C(
                    0x9fbcd8bbU),
            };
            r_rsip_func100(Param_p50i_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub019(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_002CH, &InData_IV[0]);

                static const uint32_t Param_p50i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x0d309780U), BSWAP_32BIG_C(0x2270e931U), BSWAP_32BIG_C(0x15b26d30U), BSWAP_32BIG_C(
                        0x9a9b2d28U),
                };
                r_rsip_func101(Param_p50i_func101_003);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x0199e556U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000050U, 0x00000000U);

                static const uint32_t Param_p50i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x6efc8c9bU), BSWAP_32BIG_C(0x6e1459c7U), BSWAP_32BIG_C(0x05243ec9U), BSWAP_32BIG_C(
                        0x0b3c7c48U),
                };
                r_rsip_func101(Param_p50i_func101_004);
                r_rsip_func440(InData_IV);

                static const uint32_t Param_p50i_func100_005[] =
                {
                    BSWAP_32BIG_C(0x70c0955aU), BSWAP_32BIG_C(0xf547cdacU), BSWAP_32BIG_C(0x022675c6U), BSWAP_32BIG_C(
                        0x4984584eU),
                };
                r_rsip_func100(Param_p50i_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p50i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0x3f30bc75U), BSWAP_32BIG_C(0x58ac2203U), BSWAP_32BIG_C(0x3667f034U),
                        BSWAP_32BIG_C(0x480ccf6cU),
                    };
                    r_rsip_func102(Param_p50i_func102_002);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_00D0H, 0x08000045U);
                    r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                    r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                    static const uint32_t Param_p50i_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xab38d16aU), BSWAP_32BIG_C(0xc0a3dee7U), BSWAP_32BIG_C(0xf0fe7fe7U),
                        BSWAP_32BIG_C(0x0b740c3fU),
                    };
                    r_rsip_func101(Param_p50i_func101_005);
                }
            }
        }

        static const uint32_t Param_p50i_func100_006[] =
        {
            BSWAP_32BIG_C(0x3e9191e3U), BSWAP_32BIG_C(0x83289b6bU), BSWAP_32BIG_C(0x8260e39fU), BSWAP_32BIG_C(
                0x58cabaebU),
        };
        r_rsip_func100(Param_p50i_func100_006);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

        static const uint32_t Param_p50i_func100_007[] =
        {
            BSWAP_32BIG_C(0xf142c420U), BSWAP_32BIG_C(0x6f0f79a3U), BSWAP_32BIG_C(0xbc3eeddbU), BSWAP_32BIG_C(
                0xd9cbc04bU),
        };
        r_rsip_func100(Param_p50i_func100_007);
        r_rsip_func_sub013(0x08000095U, 0x00430011U);

        r_rsip_func_sub022(0x0c003080U, 0x2000b4e0U, 0x0a000100U);

        r_rsip_func_sub022(0x0c003080U, 0x2000b4e0U, 0x0a000108U);

        r_rsip_func_sub022(0x0c003080U, 0x2000b4e0U, 0x0e000500U);

        r_rsip_func_sub022(0x0c003080U, 0x2000b4e0U, 0x09000908U);

        r_rsip_func_sub022(0x0c00a880U, 0xfffffffcU, 0x2000b4e0U);
        WR1_PROG(REG_0094H, 0x07000d00U);

        static const uint32_t Param_p50i_func101_006[] =
        {
            BSWAP_32BIG_C(0xfda76a5cU), BSWAP_32BIG_C(0x2c028b81U), BSWAP_32BIG_C(0xb22309f1U), BSWAP_32BIG_C(
                0x86f50e37U),
        };
        r_rsip_func101(Param_p50i_func101_006);

        return RSIP_RET_PASS;
    }
}
