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

rsip_ret_t r_rsip_pe3 (const uint32_t InData_EncSecret[],
                       const uint32_t InData_OutDataType[],
                       uint32_t       OutData_EncMsg[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00e30001U, 0x000000c7U, 0x80010020U);
    WR1_PROG(REG_002CH, InData_OutDataType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3000a820U, 0x00000002U, 0x00010020U);
    r_rsip_func_sub016(0x0000b420U, 0x00000001U, 0x00000080U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x015c5d71U);

    static const uint32_t Param_pe3_sub100_001[] =
    {
        BSWAP_32BIG_C(0x0000e301U), BSWAP_32BIG_C(0x31833552U), BSWAP_32BIG_C(0xd5ad4a3bU),
        BSWAP_32BIG_C(0xeeb7ab12U),
        BSWAP_32BIG_C(0x49e24c15U), BSWAP_32BIG_C(0x0000e301U), BSWAP_32BIG_C(0xb5ea674cU),
        BSWAP_32BIG_C(0xa21611bdU),
        BSWAP_32BIG_C(0xbbcd1ef3U),
        BSWAP_32BIG_C(0xeda099c5U), 0x00001404U,
    };
    r_rsip_func_sub100(InData_EncSecret, Param_pe3_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_pe3_func100_001[] =
    {
        BSWAP_32BIG_C(0x66487e8eU), BSWAP_32BIG_C(0x16804061U), BSWAP_32BIG_C(0x4faf1d56U), BSWAP_32BIG_C(0x31c86a1aU),
    };
    r_rsip_func100(Param_pe3_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe3_func102_001[] =
        {
            BSWAP_32BIG_C(0x0daa3a1eU), BSWAP_32BIG_C(0x773103d3U), BSWAP_32BIG_C(0x435b6f91U), BSWAP_32BIG_C(
                0xfe9ff2baU),
        };
        r_rsip_func102(Param_pe3_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe3_func100_002[] =
        {
            BSWAP_32BIG_C(0x8770efd4U), BSWAP_32BIG_C(0xebf3ee1aU), BSWAP_32BIG_C(0x213d80faU), BSWAP_32BIG_C(
                0x6c2f8f61U),
        };
        r_rsip_func100(Param_pe3_func100_002);
        r_rsip_func103();

        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

        r_rsip_func_sub002(0x800100e0U, 0x0000e302U);

        static const uint32_t Param_pe3_func101_001[] =
        {
            BSWAP_32BIG_C(0x9af0fe14U), BSWAP_32BIG_C(0xb8904251U), BSWAP_32BIG_C(0x30c751c7U), BSWAP_32BIG_C(
                0x1fc2f74cU),
        };
        r_rsip_func101(Param_pe3_func101_001);
        r_rsip_func143();

        r_rsip_func_sub016(0x0000b4a0U, 0x00000008U, 0x00000842U);

        WR1_PROG(REG_00B0H, 0x00001804U);

        r_rsip_func_sub016(0x30003020U, 0x00070020U, 0x0000b4c0U);
        r_rsip_func_sub016(0x01799093U, 0x00000060U, 0x0000b440U);
        r_rsip_func_sub016(0x00000010U, 0x0000b4c0U, 0x01b41ce9U);
        WR1_PROG(REG_0094H, 0x00000080U);

        r_rsip_func_sub002(0x800100e0U, 0x0000e302U);

        static const uint32_t Param_pe3_func101_002[] =
        {
            BSWAP_32BIG_C(0x601aea79U), BSWAP_32BIG_C(0x21d47468U), BSWAP_32BIG_C(0x11637c12U), BSWAP_32BIG_C(
                0x05249158U),
        };
        r_rsip_func101(Param_pe3_func101_002);
        r_rsip_func044();

        r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pe3_func100_003[] =
        {
            BSWAP_32BIG_C(0x4887cfe9U), BSWAP_32BIG_C(0xfddb5301U), BSWAP_32BIG_C(0xd0de524fU), BSWAP_32BIG_C(
                0xafb63db2U),
        };
        r_rsip_func100(Param_pe3_func100_003);
        WR1_PROG(REG_0094H, 0x00007c01U);
        WR1_PROG(REG_0040H, 0x00600000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub002(0x800100e0U, 0x0000e301U);
            static const uint32_t Param_pe3_func101_003[] =
            {
                BSWAP_32BIG_C(0xe47f2c7aU), BSWAP_32BIG_C(0x7f7cb441U), BSWAP_32BIG_C(0x3ffd6961U), BSWAP_32BIG_C(
                    0xdc0279e6U),
            };
            r_rsip_func101(Param_pe3_func101_003);
            r_rsip_func450(OutData_EncMsg);

            static const uint32_t Param_pe3_func101_004[] =
            {
                BSWAP_32BIG_C(0x624f3336U), BSWAP_32BIG_C(0x6911b07bU), BSWAP_32BIG_C(0x7b07feabU), BSWAP_32BIG_C(
                    0x76c30e5aU),
            };
            r_rsip_func101(Param_pe3_func101_004);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub002(0x800100e0U, 0x0000e302U);
            static const uint32_t Param_pe3_func101_005[] =
            {
                BSWAP_32BIG_C(0x71b6bb2cU), BSWAP_32BIG_C(0xbcd0f205U), BSWAP_32BIG_C(0xb15608d4U), BSWAP_32BIG_C(
                    0xb0b89c94U),
            };
            r_rsip_func101(Param_pe3_func101_005);
            r_rsip_func450(OutData_KeyIndex);

            static const uint32_t Param_pe3_func101_006[] =
            {
                BSWAP_32BIG_C(0x7ead3bd8U), BSWAP_32BIG_C(0xd1d9be15U), BSWAP_32BIG_C(0x57fc2f32U), BSWAP_32BIG_C(
                    0xd426d9d1U),
            };
            r_rsip_func101(Param_pe3_func101_006);
        }

        static const uint32_t Param_pe3_func102_002[] =
        {
            BSWAP_32BIG_C(0x0570e997U), BSWAP_32BIG_C(0x8bd7f359U), BSWAP_32BIG_C(0xc0a3ccb3U), BSWAP_32BIG_C(
                0xa70af380U),
        };
        r_rsip_func102(Param_pe3_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
