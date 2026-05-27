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

rsip_ret_t r_rsip_pa1i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00a10001U, 0x00000007U);

    r_rsip_func_sub002(0x800100e0U, 0x000000a1U);

    static const uint32_t Param_pa1i_func101_001[] =
    {
        BSWAP_32BIG_C(0xaa11abf2U), BSWAP_32BIG_C(0xbb3caf1cU), BSWAP_32BIG_C(0x8d729836U), BSWAP_32BIG_C(0xf73e2b4aU),
    };
    r_rsip_func101(Param_pa1i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_pa1i_func100_001[] =
    {
        BSWAP_32BIG_C(0x38757c92U), BSWAP_32BIG_C(0x96318703U), BSWAP_32BIG_C(0xa5edf4a0U), BSWAP_32BIG_C(0x7ba3ce71U),
    };
    r_rsip_func100(Param_pa1i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pa1i_func102_001[] =
        {
            BSWAP_32BIG_C(0x05060c29U), BSWAP_32BIG_C(0xa6042d38U), BSWAP_32BIG_C(0x544f762aU), BSWAP_32BIG_C(
                0xe8a31f3fU),
        };
        r_rsip_func102(Param_pa1i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010080U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        r_rsip_func_sub012(0x38000c84U, 0x00260000U);

        static const uint32_t Param_pa1i_func100_002[] =
        {
            BSWAP_32BIG_C(0x0f795149U), BSWAP_32BIG_C(0xec917a2bU), BSWAP_32BIG_C(0x69636c10U), BSWAP_32BIG_C(
                0x1e3c108aU),
        };
        r_rsip_func100(Param_pa1i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x08000045U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_pa1i_func101_002[] =
            {
                BSWAP_32BIG_C(0x4d4a47b9U), BSWAP_32BIG_C(0xe27060b7U), BSWAP_32BIG_C(0x934605f3U), BSWAP_32BIG_C(
                    0x3b88a196U),
            };
            r_rsip_func101(Param_pa1i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x000000a1U);

            static const uint32_t Param_pa1i_func101_003[] =
            {
                BSWAP_32BIG_C(0xa7017194U), BSWAP_32BIG_C(0x9c95e9b9U), BSWAP_32BIG_C(0x78859c43U), BSWAP_32BIG_C(
                    0x1129ff2eU),
            };
            r_rsip_func101(Param_pa1i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_pa1i_func100_003[] =
            {
                BSWAP_32BIG_C(0xfe3e4a9aU), BSWAP_32BIG_C(0x2427bb82U), BSWAP_32BIG_C(0xce02c8b3U), BSWAP_32BIG_C(
                    0x4d398315U),
            };
            r_rsip_func100(Param_pa1i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pa1i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xe988275dU), BSWAP_32BIG_C(0xdbf6e2faU), BSWAP_32BIG_C(0x8bdf6ce7U), BSWAP_32BIG_C(
                        0x694ed6c4U),
                };
                r_rsip_func102(Param_pa1i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub004(0x00000801U, 0x00430009U);

                r_rsip_func_sub004(0x00000802U, 0x00430009U);

                static const uint32_t Param_pa1i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xae352b37U), BSWAP_32BIG_C(0xdf9c189cU), BSWAP_32BIG_C(0x086c5d17U), BSWAP_32BIG_C(
                        0xc269b119U),
                };
                r_rsip_func101(Param_pa1i_func101_004);
            }
        }

        static const uint32_t Param_pa1i_func100_004[] =
        {
            BSWAP_32BIG_C(0x04fa419cU), BSWAP_32BIG_C(0xaad3d715U), BSWAP_32BIG_C(0x574e3f10U), BSWAP_32BIG_C(
                0x115ba07cU),
        };
        r_rsip_func100(Param_pa1i_func100_004);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub004(0x0000181eU, 0x00430011U);

        static const uint32_t Param_pa1i_func100_005[] =
        {
            BSWAP_32BIG_C(0xc8398579U), BSWAP_32BIG_C(0x3d4e740bU), BSWAP_32BIG_C(0xfe153857U), BSWAP_32BIG_C(
                0xdae4119fU),
        };
        r_rsip_func100(Param_pa1i_func100_005);
        r_rsip_func_sub006(0x08000095U, 0x00430011U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa1i_func101_005[] =
        {
            BSWAP_32BIG_C(0x249d8118U), BSWAP_32BIG_C(0x1d680b40U), BSWAP_32BIG_C(0x337d2619U), BSWAP_32BIG_C(
                0x291d88afU),
        };
        r_rsip_func101(Param_pa1i_func101_005);

        return RSIP_RET_PASS;
    }
}
