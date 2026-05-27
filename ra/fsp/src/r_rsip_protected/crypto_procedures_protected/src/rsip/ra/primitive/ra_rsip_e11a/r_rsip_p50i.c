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

    r_rsip_func_sub011(0x00500001U, 0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000007U);

    r_rsip_func_sub002(0x800100e0U, 0x00000050U);

    static const uint32_t Param_p50i_func101_001[] =
    {
        BSWAP_32BIG_C(0x9e616931U), BSWAP_32BIG_C(0x117d9f2aU), BSWAP_32BIG_C(0x52326398U), BSWAP_32BIG_C(0xe19e7d14U),
    };
    r_rsip_func101(Param_p50i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_p50i_func100_001[] =
    {
        BSWAP_32BIG_C(0x22e1f7c9U), BSWAP_32BIG_C(0x9742f5daU), BSWAP_32BIG_C(0x30aa6b8bU), BSWAP_32BIG_C(0xbd0a9a6fU),
    };
    r_rsip_func100(Param_p50i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p50i_func102_001[] =
        {
            BSWAP_32BIG_C(0xda443dbbU), BSWAP_32BIG_C(0xbb7746a1U), BSWAP_32BIG_C(0xc499713eU), BSWAP_32BIG_C(
                0x9bbd994aU),
        };
        r_rsip_func102(Param_p50i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x3c00a880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_p50i_func100_002[] =
        {
            BSWAP_32BIG_C(0x40e26c00U), BSWAP_32BIG_C(0x656987fcU), BSWAP_32BIG_C(0x837c5dd6U), BSWAP_32BIG_C(
                0xdc7245caU),
        };
        r_rsip_func100(Param_p50i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x000008a5U);

            r_rsip_func_sub007(0x3c00a880U, 0x00000004U, 0x00A60000U);

            static const uint32_t Param_p50i_func100_003[] =
            {
                BSWAP_32BIG_C(0x6f4e874bU), BSWAP_32BIG_C(0xc9e9ec99U), BSWAP_32BIG_C(0xabdc4670U), BSWAP_32BIG_C(
                    0x967abd56U),
            };
            r_rsip_func100(Param_p50i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x800100a0U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_IVType[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                static const uint32_t Param_p50i_func101_002[] =
                {
                    BSWAP_32BIG_C(0x56d495deU), BSWAP_32BIG_C(0x3c8dffa0U), BSWAP_32BIG_C(0x228b25b9U), BSWAP_32BIG_C(
                        0x93330919U),
                };
                r_rsip_func101(Param_p50i_func101_002);
            }

            WR1_PROG(REG_0094H, 0x38000ca5U);
            WR1_PROG(REG_009CH, 0x00000080U);
            WR1_PROG(REG_0040H, 0x00260000U);

            static const uint32_t Param_p50i_func100_004[] =
            {
                BSWAP_32BIG_C(0x4b035432U), BSWAP_32BIG_C(0x14321d60U), BSWAP_32BIG_C(0x1afd6c04U), BSWAP_32BIG_C(
                    0x0b2312e2U),
            };
            r_rsip_func100(Param_p50i_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000003c1U);
                WR1_PROG(REG_00D0H, 0x08000045U);
                WAIT_STS(REG_0014H, 31, 1);
                WR4_ADDR(REG_002CH, &InData_IV[0]);

                static const uint32_t Param_p50i_func101_003[] =
                {
                    BSWAP_32BIG_C(0xcaea9a17U), BSWAP_32BIG_C(0x39e17aebU), BSWAP_32BIG_C(0x642f6f3dU), BSWAP_32BIG_C(
                        0xad51bf15U),
                };
                r_rsip_func101(Param_p50i_func101_003);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x0199e556U);

                r_rsip_func_sub002(0x800100e0U, 0x00000050U);

                static const uint32_t Param_p50i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x42c9700aU), BSWAP_32BIG_C(0xa34a3251U), BSWAP_32BIG_C(0x6eb2d535U), BSWAP_32BIG_C(
                        0xcea1e710U),
                };
                r_rsip_func101(Param_p50i_func101_004);
                r_rsip_func440(InData_IV);

                static const uint32_t Param_p50i_func100_005[] =
                {
                    BSWAP_32BIG_C(0xd4d91e11U), BSWAP_32BIG_C(0x4283bd97U), BSWAP_32BIG_C(0xaa342ec4U), BSWAP_32BIG_C(
                        0x41e873dfU),
                };
                r_rsip_func100(Param_p50i_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p50i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0x51726a2eU), BSWAP_32BIG_C(0x5dd9723dU), BSWAP_32BIG_C(0xa95881a6U),
                        BSWAP_32BIG_C(0x7617b555U),
                    };
                    r_rsip_func102(Param_p50i_func102_002);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_00D0H, 0x08000045U);
                    r_rsip_func_sub004(0x00000801U, 0x00430009U);

                    r_rsip_func_sub004(0x00000802U, 0x00430009U);

                    static const uint32_t Param_p50i_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x57443361U), BSWAP_32BIG_C(0x3641ec08U), BSWAP_32BIG_C(0x473b82d8U),
                        BSWAP_32BIG_C(0xeafd7211U),
                    };
                    r_rsip_func101(Param_p50i_func101_005);
                }
            }
        }

        static const uint32_t Param_p50i_func100_006[] =
        {
            BSWAP_32BIG_C(0x9ced1399U), BSWAP_32BIG_C(0x35965713U), BSWAP_32BIG_C(0x3246013cU), BSWAP_32BIG_C(
                0x13e1cf15U),
        };
        r_rsip_func100(Param_p50i_func100_006);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub004(0x0000181eU, 0x00430011U);

        static const uint32_t Param_p50i_func100_007[] =
        {
            BSWAP_32BIG_C(0xf799af27U), BSWAP_32BIG_C(0xc1942962U), BSWAP_32BIG_C(0x7abc7786U), BSWAP_32BIG_C(
                0x899c24f2U),
        };
        r_rsip_func100(Param_p50i_func100_007);
        r_rsip_func_sub006(0x08000095U, 0x00430011U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0a000100U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0a000108U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x0e000500U);

        r_rsip_func_sub016(0x0c003080U, 0x2000b4e0U, 0x09000908U);

        r_rsip_func_sub016(0x0c00a880U, 0xfffffffcU, 0x2000b4e0U);
        WR1_PROG(REG_0094H, 0x07000d00U);

        static const uint32_t Param_p50i_func101_006[] =
        {
            BSWAP_32BIG_C(0xf24b94f5U), BSWAP_32BIG_C(0x47500955U), BSWAP_32BIG_C(0xa247a088U), BSWAP_32BIG_C(
                0xc8e39b2fU),
        };
        r_rsip_func101(Param_p50i_func101_006);

        return RSIP_RET_PASS;
    }
}
