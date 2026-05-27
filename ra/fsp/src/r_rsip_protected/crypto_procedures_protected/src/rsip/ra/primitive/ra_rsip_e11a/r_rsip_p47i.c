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

rsip_ret_t r_rsip_p47i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00470001U, 0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000005U);

    r_rsip_func_sub002(0x800100e0U, 0x00004701U);

    static const uint32_t Param_p47i_func101_001[] =
    {
        BSWAP_32BIG_C(0x89beb64eU), BSWAP_32BIG_C(0x3ffeaa00U), BSWAP_32BIG_C(0xff853c24U), BSWAP_32BIG_C(0x36f22cf5U),
    };
    r_rsip_func101(Param_p47i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p47i_func100_001[] =
    {
        BSWAP_32BIG_C(0x9d18ff63U), BSWAP_32BIG_C(0x1a5a2b27U), BSWAP_32BIG_C(0x6a3d35daU), BSWAP_32BIG_C(0x1b27fe61U),
    };
    r_rsip_func100(Param_p47i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p47i_func102_001[] =
        {
            BSWAP_32BIG_C(0xeeb47652U), BSWAP_32BIG_C(0xbb5940a2U), BSWAP_32BIG_C(0xf35f73e4U), BSWAP_32BIG_C(
                0x4bef9c17U),
        };
        r_rsip_func102(Param_p47i_func102_001);
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

        r_rsip_func_sub007(0x3c00a880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p47i_func100_002[] =
        {
            BSWAP_32BIG_C(0x400be8c1U), BSWAP_32BIG_C(0x6e618a49U), BSWAP_32BIG_C(0x4241298bU), BSWAP_32BIG_C(
                0x9023cfbcU),
        };
        r_rsip_func100(Param_p47i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x000008a5U);

            r_rsip_func_sub007(0x3c00a880U, 0x00000004U, 0x00A60000U);

            static const uint32_t Param_p47i_func100_003[] =
            {
                BSWAP_32BIG_C(0x56753d83U), BSWAP_32BIG_C(0x5240cea3U), BSWAP_32BIG_C(0xef200f5fU), BSWAP_32BIG_C(
                    0x51ac6be1U),
            };
            r_rsip_func100(Param_p47i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x800100a0U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_IVType[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                static const uint32_t Param_p47i_func101_002[] =
                {
                    BSWAP_32BIG_C(0x5d9fcdf1U), BSWAP_32BIG_C(0x9dd4726bU), BSWAP_32BIG_C(0x233b31a6U), BSWAP_32BIG_C(
                        0xb0de3b90U),
                };
                r_rsip_func101(Param_p47i_func101_002);
            }

            WR1_PROG(REG_0094H, 0x38000ca5U);
            WR1_PROG(REG_009CH, 0x00000080U);
            WR1_PROG(REG_0040H, 0x00260000U);

            static const uint32_t Param_p47i_func100_004[] =
            {
                BSWAP_32BIG_C(0x1dd74c0bU), BSWAP_32BIG_C(0xf32a31c3U), BSWAP_32BIG_C(0x3a12388cU), BSWAP_32BIG_C(
                    0xc29890e7U),
            };
            r_rsip_func100(Param_p47i_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000003c1U);
                WR1_PROG(REG_00D0H, 0x08000045U);
                WAIT_STS(REG_0014H, 31, 1);
                WR4_ADDR(REG_002CH, &InData_IV[0]);

                static const uint32_t Param_p47i_func101_003[] =
                {
                    BSWAP_32BIG_C(0xa81bbbfbU), BSWAP_32BIG_C(0x03018856U), BSWAP_32BIG_C(0xf59bf5d1U), BSWAP_32BIG_C(
                        0x11bc7193U),
                };
                r_rsip_func101(Param_p47i_func101_003);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x0199e556U);

                r_rsip_func_sub002(0x800100e0U, 0x00004702U);

                static const uint32_t Param_p47i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xa62acae2U), BSWAP_32BIG_C(0x974c50b8U), BSWAP_32BIG_C(0xeb00ed12U), BSWAP_32BIG_C(
                        0x7d082c62U),
                };
                r_rsip_func101(Param_p47i_func101_004);
                r_rsip_func440(InData_IV);

                static const uint32_t Param_p47i_func100_005[] =
                {
                    BSWAP_32BIG_C(0x5893b71eU), BSWAP_32BIG_C(0xac524a26U), BSWAP_32BIG_C(0x740ab7ecU), BSWAP_32BIG_C(
                        0x719f0918U),
                };
                r_rsip_func100(Param_p47i_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p47i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0xef05461dU), BSWAP_32BIG_C(0xa519fee3U), BSWAP_32BIG_C(0x9be7e360U),
                        BSWAP_32BIG_C(0x59bdbf9bU),
                    };
                    r_rsip_func102(Param_p47i_func102_002);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_00D0H, 0x08000045U);
                    r_rsip_func_sub004(0x00000801U, 0x00430009U);

                    r_rsip_func_sub004(0x00000802U, 0x00430009U);

                    static const uint32_t Param_p47i_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x86ca016eU), BSWAP_32BIG_C(0xe34b26a2U), BSWAP_32BIG_C(0x952fb08bU),
                        BSWAP_32BIG_C(0x78806a9eU),
                    };
                    r_rsip_func101(Param_p47i_func101_005);
                }
            }
        }

        static const uint32_t Param_p47i_func100_006[] =
        {
            BSWAP_32BIG_C(0x094b147eU), BSWAP_32BIG_C(0x71fafd08U), BSWAP_32BIG_C(0x9ff19d62U), BSWAP_32BIG_C(
                0x1688ba74U),
        };
        r_rsip_func100(Param_p47i_func100_006);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub003(0x81840000U, 0x00490011U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0a000100U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0a000108U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0e000500U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x09000908U);

        r_rsip_func_sub016(0x0c00a880U, 0xfffffffcU, 0x2000b4e0U);
        WR1_PROG(REG_0094H, 0x07000d00U);

        static const uint32_t Param_p47i_func101_006[] =
        {
            BSWAP_32BIG_C(0x1392f00aU), BSWAP_32BIG_C(0xe0f57f43U), BSWAP_32BIG_C(0xac6a07daU), BSWAP_32BIG_C(
                0x6837ad20U),
        };
        r_rsip_func101(Param_p47i_func101_006);

        return RSIP_RET_PASS;
    }
}
