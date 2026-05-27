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

rsip_ret_t r_rsip_pa4i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00a40001U, 0x00000007U);

    r_rsip_func_sub002(0x800100e0U, 0x000000a4U);

    static const uint32_t Param_pa4i_func101_001[] =
    {
        BSWAP_32BIG_C(0xae234251U), BSWAP_32BIG_C(0x577bb95cU), BSWAP_32BIG_C(0xc48c311fU), BSWAP_32BIG_C(0x453d1f11U),
    };
    r_rsip_func101(Param_pa4i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_pa4i_func100_001[] =
    {
        BSWAP_32BIG_C(0x7543619dU), BSWAP_32BIG_C(0x6e07611fU), BSWAP_32BIG_C(0x32a8d831U), BSWAP_32BIG_C(0xd9b8b4e0U),
    };
    r_rsip_func100(Param_pa4i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pa4i_func102_001[] =
        {
            BSWAP_32BIG_C(0xa4814e21U), BSWAP_32BIG_C(0xfaed354eU), BSWAP_32BIG_C(0x6255699aU), BSWAP_32BIG_C(
                0xe88ef58fU),
        };
        r_rsip_func102(Param_pa4i_func102_001);
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

        static const uint32_t Param_pa4i_func100_002[] =
        {
            BSWAP_32BIG_C(0x77ea2d05U), BSWAP_32BIG_C(0xb7f9e8faU), BSWAP_32BIG_C(0xb8c17713U), BSWAP_32BIG_C(
                0xac19d9b5U),
        };
        r_rsip_func100(Param_pa4i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x08000045U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_pa4i_func101_002[] =
            {
                BSWAP_32BIG_C(0x0a8b37ceU), BSWAP_32BIG_C(0x22cff5ffU), BSWAP_32BIG_C(0xa756a04dU), BSWAP_32BIG_C(
                    0x9df88536U),
            };
            r_rsip_func101(Param_pa4i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x800100e0U, 0x000000a4U);

            static const uint32_t Param_pa4i_func101_003[] =
            {
                BSWAP_32BIG_C(0x14dd1faaU), BSWAP_32BIG_C(0x9a24f2cfU), BSWAP_32BIG_C(0x7f481dbcU), BSWAP_32BIG_C(
                    0xb8021569U),
            };
            r_rsip_func101(Param_pa4i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_pa4i_func100_003[] =
            {
                BSWAP_32BIG_C(0x67e525e2U), BSWAP_32BIG_C(0x20ba7973U), BSWAP_32BIG_C(0xfdc7924eU), BSWAP_32BIG_C(
                    0x30c76aa6U),
            };
            r_rsip_func100(Param_pa4i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pa4i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x809c0f9dU), BSWAP_32BIG_C(0x1f2e46f3U), BSWAP_32BIG_C(0x8718296bU), BSWAP_32BIG_C(
                        0xcea74c7dU),
                };
                r_rsip_func102(Param_pa4i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub004(0x00000801U, 0x00430009U);

                r_rsip_func_sub004(0x00000802U, 0x00430009U);

                static const uint32_t Param_pa4i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x3f1b8e43U), BSWAP_32BIG_C(0x10ae81ecU), BSWAP_32BIG_C(0xe78c8dfeU), BSWAP_32BIG_C(
                        0x5aa342d2U),
                };
                r_rsip_func101(Param_pa4i_func101_004);
            }
        }

        static const uint32_t Param_pa4i_func100_004[] =
        {
            BSWAP_32BIG_C(0x756f20c2U), BSWAP_32BIG_C(0xebed14b4U), BSWAP_32BIG_C(0x364da16bU), BSWAP_32BIG_C(
                0x7e5a5735U),
        };
        r_rsip_func100(Param_pa4i_func100_004);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub004(0x0000181eU, 0x00430011U);

        static const uint32_t Param_pa4i_func100_005[] =
        {
            BSWAP_32BIG_C(0x8eb3c75cU), BSWAP_32BIG_C(0x8a74af99U), BSWAP_32BIG_C(0xbe1cf2e8U), BSWAP_32BIG_C(
                0x94d74eb0U),
        };
        r_rsip_func100(Param_pa4i_func100_005);
        r_rsip_func_sub006(0x08000095U, 0x00430011U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa4i_func101_005[] =
        {
            BSWAP_32BIG_C(0xef328880U), BSWAP_32BIG_C(0x5fa88accU), BSWAP_32BIG_C(0xb3196322U), BSWAP_32BIG_C(
                0xe07c4a37U),
        };
        r_rsip_func101(Param_pa4i_func101_005);

        return RSIP_RET_PASS;
    }
}
