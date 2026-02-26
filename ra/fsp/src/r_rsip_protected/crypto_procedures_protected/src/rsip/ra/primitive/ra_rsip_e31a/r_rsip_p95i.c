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

    WR1_PROG(REG_0070H, 0x00950001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000005U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00009501U, 0x00000000U);

    static const uint32_t Param_p95i_func101_001[] =
    {
        BSWAP_32BIG_C(0x5745250bU), BSWAP_32BIG_C(0x5eb9f25eU), BSWAP_32BIG_C(0x4d950297U), BSWAP_32BIG_C(0x0dee4558U),
    };
    r_rsip_func101(Param_p95i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p95i_func100_001[] =
    {
        BSWAP_32BIG_C(0x7e8222f6U), BSWAP_32BIG_C(0xa27e2b48U), BSWAP_32BIG_C(0xb923b689U), BSWAP_32BIG_C(0x52e5652cU),
    };
    r_rsip_func100(Param_p95i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p95i_func102_001[] =
        {
            BSWAP_32BIG_C(0xf559769cU), BSWAP_32BIG_C(0xa349051eU), BSWAP_32BIG_C(0x8969e08cU), BSWAP_32BIG_C(
                0x6af4cc44U),
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
        r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub014(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_p95i_func100_002[] =
        {
            BSWAP_32BIG_C(0xd710f4e5U), BSWAP_32BIG_C(0xf3c05638U), BSWAP_32BIG_C(0x75353d42U), BSWAP_32BIG_C(
                0x2b1c802fU),
        };
        r_rsip_func100(Param_p95i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_p95i_func101_002[] =
            {
                BSWAP_32BIG_C(0x039e86a2U), BSWAP_32BIG_C(0x2e1e724aU), BSWAP_32BIG_C(0x38ba6f83U), BSWAP_32BIG_C(
                    0x876ffdceU),
            };
            r_rsip_func101(Param_p95i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00009502U, 0x00000000U);

            static const uint32_t Param_p95i_func101_003[] =
            {
                BSWAP_32BIG_C(0xa3f9549cU), BSWAP_32BIG_C(0x2a7853e8U), BSWAP_32BIG_C(0x9bd71b59U), BSWAP_32BIG_C(
                    0xd6765b3cU),
            };
            r_rsip_func101(Param_p95i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_p95i_func100_003[] =
            {
                BSWAP_32BIG_C(0xbd41c2deU), BSWAP_32BIG_C(0xc17957ddU), BSWAP_32BIG_C(0xe43df482U), BSWAP_32BIG_C(
                    0xa07882aaU),
            };
            r_rsip_func100(Param_p95i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p95i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x62a0e588U), BSWAP_32BIG_C(0x6dee039dU), BSWAP_32BIG_C(0xadf00230U), BSWAP_32BIG_C(
                        0xc8f49fa3U),
                };
                r_rsip_func102(Param_p95i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                static const uint32_t Param_p95i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xdacae135U), BSWAP_32BIG_C(0x545e6da1U), BSWAP_32BIG_C(0xe5b59e4fU), BSWAP_32BIG_C(
                        0x76c03154U),
                };
                r_rsip_func101(Param_p95i_func101_004);
            }
        }

        static const uint32_t Param_p95i_func100_004[] =
        {
            BSWAP_32BIG_C(0x94b2d747U), BSWAP_32BIG_C(0x03624578U), BSWAP_32BIG_C(0x6e9f3dc5U), BSWAP_32BIG_C(
                0x74ea0487U),
        };
        r_rsip_func100(Param_p95i_func100_004);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub012(0x81840000U, 0x00490011U);

        WR1_PROG(REG_00D4H, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p95i_func101_005[] =
        {
            BSWAP_32BIG_C(0x881c6116U), BSWAP_32BIG_C(0xf45ca629U), BSWAP_32BIG_C(0x4b819b47U), BSWAP_32BIG_C(
                0xd2da7d6eU),
        };
        r_rsip_func101(Param_p95i_func101_005);

        return RSIP_RET_PASS;
    }
}
