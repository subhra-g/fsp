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

    WR1_PROG(REG_0070H, 0x00980001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000005U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00009801U, 0x00000000U);

    static const uint32_t Param_p98i_func101_001[] =
    {
        BSWAP_32BIG_C(0xcefadc0dU), BSWAP_32BIG_C(0x7e227b55U), BSWAP_32BIG_C(0x134e5d4dU), BSWAP_32BIG_C(0x3f4d14a5U),
    };
    r_rsip_func101(Param_p98i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p98i_func100_001[] =
    {
        BSWAP_32BIG_C(0xd3297866U), BSWAP_32BIG_C(0xb716216cU), BSWAP_32BIG_C(0xf3894df9U), BSWAP_32BIG_C(0xaa0c20f2U),
    };
    r_rsip_func100(Param_p98i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p98i_func102_001[] =
        {
            BSWAP_32BIG_C(0x44012978U), BSWAP_32BIG_C(0xff9336beU), BSWAP_32BIG_C(0xd212569fU), BSWAP_32BIG_C(
                0xa7beeef4U),
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
        r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub014(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_p98i_func100_002[] =
        {
            BSWAP_32BIG_C(0xa322109aU), BSWAP_32BIG_C(0x1faa11eeU), BSWAP_32BIG_C(0x2dc33995U), BSWAP_32BIG_C(
                0xd09db658U),
        };
        r_rsip_func100(Param_p98i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_p98i_func101_002[] =
            {
                BSWAP_32BIG_C(0x10138dd3U), BSWAP_32BIG_C(0x05e8d0c4U), BSWAP_32BIG_C(0x0f2d0175U), BSWAP_32BIG_C(
                    0xce2c82f6U),
            };
            r_rsip_func101(Param_p98i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00009802U, 0x00000000U);

            static const uint32_t Param_p98i_func101_003[] =
            {
                BSWAP_32BIG_C(0x0c372af1U), BSWAP_32BIG_C(0x290e2fa5U), BSWAP_32BIG_C(0x952dfe8eU), BSWAP_32BIG_C(
                    0x5379c356U),
            };
            r_rsip_func101(Param_p98i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_p98i_func100_003[] =
            {
                BSWAP_32BIG_C(0x297fd27aU), BSWAP_32BIG_C(0xd9320480U), BSWAP_32BIG_C(0xbf53489cU), BSWAP_32BIG_C(
                    0x7084038eU),
            };
            r_rsip_func100(Param_p98i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p98i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x4d85d570U), BSWAP_32BIG_C(0x1b3d8f93U), BSWAP_32BIG_C(0x0cfa9d7eU), BSWAP_32BIG_C(
                        0x0208c732U),
                };
                r_rsip_func102(Param_p98i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                static const uint32_t Param_p98i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xcee20e2cU), BSWAP_32BIG_C(0x2981867eU), BSWAP_32BIG_C(0x134a837aU), BSWAP_32BIG_C(
                        0xaf30329bU),
                };
                r_rsip_func101(Param_p98i_func101_004);
            }
        }

        static const uint32_t Param_p98i_func100_004[] =
        {
            BSWAP_32BIG_C(0x99aa84deU), BSWAP_32BIG_C(0xfd5d08b9U), BSWAP_32BIG_C(0x019c318aU), BSWAP_32BIG_C(
                0xa6e9f8a2U),
        };
        r_rsip_func100(Param_p98i_func100_004);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub012(0x81840000U, 0x00490011U);

        WR1_PROG(REG_00D4H, 0x00000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_p98i_func101_005[] =
        {
            BSWAP_32BIG_C(0xf721213eU), BSWAP_32BIG_C(0x90184440U), BSWAP_32BIG_C(0xc151f26fU), BSWAP_32BIG_C(
                0x219a163aU),
        };
        r_rsip_func101(Param_p98i_func101_005);

        return RSIP_RET_PASS;
    }
}
