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

rsip_ret_t r_rsip_pf0 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00f00001U, 0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3420a800U, 0x00000003U, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000002U);

    r_rsip_func070(InData_DomainParam);

    static const uint32_t Param_pf0_func100_001[] =
    {
        BSWAP_32BIG_C(0x686deac7U), BSWAP_32BIG_C(0x709b2a28U), BSWAP_32BIG_C(0xbcc50a35U), BSWAP_32BIG_C(0xdd4c2688U),
    };
    r_rsip_func100(Param_pf0_func100_001);

    WR1_PROG(REG_00B0H, 0x0000140fU);
    r_rsip_func103();
    static const uint32_t Param_pf0_func100_002[] =
    {
        BSWAP_32BIG_C(0x2867ed39U), BSWAP_32BIG_C(0x3356f188U), BSWAP_32BIG_C(0x8e378447U), BSWAP_32BIG_C(0x9aaf3b9eU),
    };
    r_rsip_func100(Param_pf0_func100_002);
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func_sub004(0x00001428U, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

    r_rsip_func_sub004(0x00001419U, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

    r_rsip_func_sub001(0x0019000aU, 0x00140000U, 0x0404000aU);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B8H, 0x00000014U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    WR1_PROG(REG_00A0H, 0x20010001U);
    WAIT_STS(REG_00A8H, 0, 1);
    WR1_PROG(REG_00ACH, 0x00000001U);

    r_rsip_func_sub001(0x0028000fU, 0x002d0014U, 0x04040002U);

    r_rsip_func_sub001(0x0028002dU, 0x00320000U, 0x04040009U);

    r_rsip_func071(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x800100e0U, 0x000000f0U);

    static const uint32_t Param_pf0_func101_001[] =
    {
        BSWAP_32BIG_C(0xbba9725fU), BSWAP_32BIG_C(0x37f58e4fU), BSWAP_32BIG_C(0x806ac6acU), BSWAP_32BIG_C(0x3bcfd5faU),
    };
    r_rsip_func101(Param_pf0_func101_001);
    r_rsip_func088();

    static const uint32_t Param_pf0_func100_003[] =
    {
        BSWAP_32BIG_C(0x428c2e0dU), BSWAP_32BIG_C(0x5da1d275U), BSWAP_32BIG_C(0x1f07e4f7U), BSWAP_32BIG_C(0x5ce8df37U),
    };
    r_rsip_func100(Param_pf0_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf0_func102_001[] =
        {
            BSWAP_32BIG_C(0xc3fd2c34U), BSWAP_32BIG_C(0xd266d3fbU), BSWAP_32BIG_C(0xd69f85eaU), BSWAP_32BIG_C(
                0x412328d3U),
        };
        r_rsip_func102(Param_pf0_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00B8H, 0x0000000aU);

        WR1_PROG(REG_00A4H, 0x04040010U);

        WR1_PROG(REG_00A0H, 0x20010001U);
        WAIT_STS(REG_00A8H, 0, 1);
        WR1_PROG(REG_00ACH, 0x00000001U);

        r_rsip_func_sub001(0x005a0028U, 0x002d000aU, 0x04040002U);

        WR1_PROG(REG_0014H, 0x000000a5U);
        r_rsip_func_sub004(0x0000140fU, 0x00c0001dU);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x000f002dU, 0x0028000aU, 0x04040002U);

        r_rsip_func_sub001(0x000f0028U, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_pf0_func100_004[] =
        {
            BSWAP_32BIG_C(0x0d166d6cU), BSWAP_32BIG_C(0xab40d024U), BSWAP_32BIG_C(0x621f1f6dU), BSWAP_32BIG_C(
                0x7babc156U),
        };
        r_rsip_func100(Param_pf0_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pf0_func102_002[] =
            {
                BSWAP_32BIG_C(0xc525800fU), BSWAP_32BIG_C(0x06fe9510U), BSWAP_32BIG_C(0x67968cd5U), BSWAP_32BIG_C(
                    0x025a0febU),
            };
            r_rsip_func102(Param_pf0_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf0_func100_005[] =
            {
                BSWAP_32BIG_C(0xe88d6cd4U), BSWAP_32BIG_C(0xa60c2b1cU), BSWAP_32BIG_C(0x9ba0284cU), BSWAP_32BIG_C(
                    0x88d159c4U),
            };
            r_rsip_func100(Param_pf0_func100_005);
            r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
            WR1_PROG(REG_0014H, 0x000000a5U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

            r_rsip_func_sub001(0x0014000aU, 0x000f0000U, 0x0404000aU);

            WR1_PROG(REG_00B4H, 0x000f0032U);
            WR1_PROG(REG_00B8H, 0x0014000aU);

            WR1_PROG(REG_00A4H, 0x04040000U);
            WR1_PROG(REG_0008H, 0x00020000U);
            WR1_PROG(REG_00A0H, 0x20010001U);
            WAIT_STS(REG_00A8H, 0, 1);
            WR1_PROG(REG_00ACH, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x005a0014U, 0x000f000aU, 0x04040002U);

            WR1_PROG(REG_0014H, 0x000007c5U);
            WR1_PROG(REG_00B0H, 0x00001414U);
            WAIT_STS(REG_0014H, 31, 1);
            WR8_ADDR(REG_002CH, &InData_MsgDgst[0]);

            r_rsip_func074();

            WR1_PROG(REG_0094H, 0x000034a6U);

            r_rsip_func_sub002(0x800100e0U, 0x000000f0U);

            static const uint32_t Param_pf0_func101_002[] =
            {
                BSWAP_32BIG_C(0x968a2af4U), BSWAP_32BIG_C(0x11e1ea7eU), BSWAP_32BIG_C(0x54f3bd76U), BSWAP_32BIG_C(
                    0x61fe4e80U),
            };
            r_rsip_func101(Param_pf0_func101_002);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_pf0_func100_006[] =
            {
                BSWAP_32BIG_C(0xcdea3308U), BSWAP_32BIG_C(0xf90be7aaU), BSWAP_32BIG_C(0x77c57928U), BSWAP_32BIG_C(
                    0x099bc521U),
            };
            r_rsip_func100(Param_pf0_func100_006);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pf0_func102_003[] =
                {
                    BSWAP_32BIG_C(0x26ac7cf4U), BSWAP_32BIG_C(0x79218899U), BSWAP_32BIG_C(0x5d9583c5U), BSWAP_32BIG_C(
                        0xadddf769U),
                };
                r_rsip_func102(Param_pf0_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub001(0x005a001eU, 0x0019000aU, 0x04040002U);

                r_rsip_func_sub001(0x00280019U, 0x001e000aU, 0x04040002U);

                r_rsip_func_sub001(0x001e0014U, 0x0019000aU, 0x04040005U);

                r_rsip_func_sub001(0x0019000fU, 0x001e000aU, 0x04040002U);

                r_rsip_func_sub004(0x0000140fU, 0x00c0001dU);
                WR1_PROG(REG_0014H, 0x000000a5U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

                r_rsip_func_sub001(0x000f001eU, 0x00140000U, 0x0404000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_pf0_func100_007[] =
                {
                    BSWAP_32BIG_C(0xbf4144b5U), BSWAP_32BIG_C(0xf0b719bdU), BSWAP_32BIG_C(0x07b52060U), BSWAP_32BIG_C(
                        0x2ab7223eU),
                };
                r_rsip_func100(Param_pf0_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pf0_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xcbb1f85dU), BSWAP_32BIG_C(0xaa9af461U), BSWAP_32BIG_C(0x9ea5d93fU),
                        BSWAP_32BIG_C(0xbf9b1a69U),
                    };
                    r_rsip_func102(Param_pf0_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pf0_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x7cbe7fdbU), BSWAP_32BIG_C(0x6a832482U), BSWAP_32BIG_C(0x09790231U),
                        BSWAP_32BIG_C(0xf39756cbU),
                    };
                    r_rsip_func100(Param_pf0_func100_008);
                    WR1_PROG(REG_00B0H, 0x00001828U);
                    WR1_PROG(REG_0008H, 0x00006022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD8_ADDR(REG_002CH, &OutData_Signature[0]);

                    static const uint32_t Param_pf0_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x43ccfd6aU), BSWAP_32BIG_C(0x30eb3a51U), BSWAP_32BIG_C(0x876144d3U),
                        BSWAP_32BIG_C(0x67c1f2c7U),
                    };
                    r_rsip_func100(Param_pf0_func100_009);
                    WR1_PROG(REG_00B0H, 0x0000181eU);
                    WR1_PROG(REG_0008H, 0x00006022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD8_ADDR(REG_002CH, &OutData_Signature[8]);

                    static const uint32_t Param_pf0_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x86b10571U), BSWAP_32BIG_C(0xfe1d2263U), BSWAP_32BIG_C(0xbcd73d6eU),
                        BSWAP_32BIG_C(0x2ec269a4U),
                    };
                    r_rsip_func102(Param_pf0_func102_005);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
