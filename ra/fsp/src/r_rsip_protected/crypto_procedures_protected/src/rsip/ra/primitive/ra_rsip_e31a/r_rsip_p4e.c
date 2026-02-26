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

rsip_ret_t r_rsip_p4e (const uint32_t InData_CurveType[],
                       const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x004e0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00A0H, 0x00010000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3420a800U, 0x00000002U);
    WR1_PROG(REG_0094H, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000001U);

    r_rsip_func027(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    WR1_PROG(REG_00B8H, 0x00000007U);

    WR1_PROG(REG_00A4H, 0x06060010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func076();

    WR1_PROG(REG_0094H, 0x000034a6U);

    static const uint32_t Param_p4e_sub100_001[] =
    {
        BSWAP_32BIG_C(0x00004e01U), BSWAP_32BIG_C(0x35e8df95U), BSWAP_32BIG_C(0x3c875dbeU),
        BSWAP_32BIG_C(0xf1cfa543U),
        BSWAP_32BIG_C(0xb2bdf37dU), BSWAP_32BIG_C(0x00004e01U), BSWAP_32BIG_C(0xca8a8c6bU),
        BSWAP_32BIG_C(0x4789afd0U),
        BSWAP_32BIG_C(0x5e7cef08U),
        BSWAP_32BIG_C(0xb19522eaU), 0x00009446U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_p4e_sub100_001, RSIP_SEL_BIT_LENGTH_384);

    static const uint32_t Param_p4e_func100_001[] =
    {
        BSWAP_32BIG_C(0xe7dc83e7U), BSWAP_32BIG_C(0xba25cb52U), BSWAP_32BIG_C(0xd5c4e858U), BSWAP_32BIG_C(0x9decf68cU),
    };
    r_rsip_func100(Param_p4e_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p4e_func102_001[] =
        {
            BSWAP_32BIG_C(0x1f3f595dU), BSWAP_32BIG_C(0xb39a9ca5U), BSWAP_32BIG_C(0x00ba165eU), BSWAP_32BIG_C(
                0xb1d415f4U),
        };
        r_rsip_func102(Param_p4e_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x80010060U);
        WR1_PROG(REG_002CH, InData_PubKeyType[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000c63U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_p4e_func100_002[] =
        {
            BSWAP_32BIG_C(0xc12e89e6U), BSWAP_32BIG_C(0x7c5ed210U), BSWAP_32BIG_C(0x16df0fe9U), BSWAP_32BIG_C(
                0xd98f00acU),
        };
        r_rsip_func100(Param_p4e_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000017c5U);
            WR1_PROG(REG_00B0H, 0x00009415U);
            WAIT_STS(REG_0014H, 31, 1);
            WR12_ADDR(REG_002CH, &InData_PubKey[0]);

            WR1_PROG(REG_00B0H, 0x0000941cU);
            WAIT_STS(REG_0014H, 31, 1);
            WR12_ADDR(REG_002CH, &InData_PubKey[12]);

            static const uint32_t Param_p4e_func101_001[] =
            {
                BSWAP_32BIG_C(0x56205f3fU), BSWAP_32BIG_C(0x01948b7bU), BSWAP_32BIG_C(0x7d016639U), BSWAP_32BIG_C(
                    0xd4112d67U),
            };
            r_rsip_func101(Param_p4e_func101_001);
        }
        else
        {
            r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_PubKey[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004e02U, 0x00000000U);

            static const uint32_t Param_p4e_func101_002[] =
            {
                BSWAP_32BIG_C(0x395a475cU), BSWAP_32BIG_C(0x54367fc0U), BSWAP_32BIG_C(0xe89b0628U), BSWAP_32BIG_C(
                    0x6619d78fU),
            };
            r_rsip_func101(Param_p4e_func101_002);
            r_rsip_func143();

            r_rsip_func077();

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004e02U, 0x00000000U);

            static const uint32_t Param_p4e_func101_003[] =
            {
                BSWAP_32BIG_C(0x5c7abfecU), BSWAP_32BIG_C(0xea50616cU), BSWAP_32BIG_C(0xacb51685U), BSWAP_32BIG_C(
                    0x8b5ead6eU),
            };
            r_rsip_func101(Param_p4e_func101_003);
            r_rsip_func044();

            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub011(0x000017c1U, 0x40000500U, 0xe8009107U);
            WR4_ADDR(REG_002CH, &InData_PubKey[1]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[5]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[9]);

            r_rsip_func_sub009(0x00009415U, 0x00c10031U, 0x00001800U);

            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[13]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[17]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[21]);

            r_rsip_func_sub009(0x0000941cU, 0x00c10031U, 0x00001800U);

            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_PubKey[25]);

            r_rsip_func_sub013(0x9c100005U, 0x00410011U);

            static const uint32_t Param_p4e_func100_003[] =
            {
                BSWAP_32BIG_C(0x27ccc9d9U), BSWAP_32BIG_C(0x1abb3c76U), BSWAP_32BIG_C(0xfd2ce282U), BSWAP_32BIG_C(
                    0xe61d2177U),
            };
            r_rsip_func100(Param_p4e_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p4e_func102_002[] =
                {
                    BSWAP_32BIG_C(0x0adbeb65U), BSWAP_32BIG_C(0x1e2b70a2U), BSWAP_32BIG_C(0xecd237ddU), BSWAP_32BIG_C(
                        0xfc32159bU),
                };
                r_rsip_func102(Param_p4e_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p4e_func101_004[] =
                {
                    BSWAP_32BIG_C(0xa75442b5U), BSWAP_32BIG_C(0x571c1a7bU), BSWAP_32BIG_C(0xcb241593U), BSWAP_32BIG_C(
                        0x9e7d4c63U),
                };
                r_rsip_func101(Param_p4e_func101_004);
            }
        }

        r_rsip_func_sub001(0x004d0015U, 0x00230007U, 0x06060002U);

        r_rsip_func_sub001(0x004d001cU, 0x002a0007U, 0x06060002U);

        r_rsip_func_sub001(0x00230023U, 0x00150007U, 0x06060002U);

        r_rsip_func_sub001(0x00850015U, 0x001c0007U, 0x06060005U);

        r_rsip_func_sub001(0x0023001cU, 0x00150007U, 0x06060002U);

        r_rsip_func_sub001(0x008c0015U, 0x001c0007U, 0x06060005U);

        r_rsip_func_sub001(0x002a002aU, 0x00150007U, 0x06060002U);

        r_rsip_func_sub001(0x001c0015U, 0x00310000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x0015001cU, 0x00310000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_p4e_func100_004[] =
        {
            BSWAP_32BIG_C(0x06a7db75U), BSWAP_32BIG_C(0x7abd15c6U), BSWAP_32BIG_C(0xe87c164aU), BSWAP_32BIG_C(
                0x7b4138d7U),
        };
        r_rsip_func100(Param_p4e_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p4e_func102_003[] =
            {
                BSWAP_32BIG_C(0x396972fcU), BSWAP_32BIG_C(0xaa342138U), BSWAP_32BIG_C(0xaa9b724dU), BSWAP_32BIG_C(
                    0xc001ffdfU),
            };
            r_rsip_func102(Param_p4e_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000004eU, 0x00000000U);

            static const uint32_t Param_p4e_func101_005[] =
            {
                BSWAP_32BIG_C(0x4f92ea70U), BSWAP_32BIG_C(0xfc56d0ccU), BSWAP_32BIG_C(0x3a67a75eU), BSWAP_32BIG_C(
                    0x4e5ba7a2U),
            };
            r_rsip_func101(Param_p4e_func101_005);
            r_rsip_func089();

            static const uint32_t Param_p4e_func100_005[] =
            {
                BSWAP_32BIG_C(0xad2cb81cU), BSWAP_32BIG_C(0x67c7b1d6U), BSWAP_32BIG_C(0x41cf3d39U), BSWAP_32BIG_C(
                    0xd20b045eU),
            };
            r_rsip_func100(Param_p4e_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p4e_func102_004[] =
                {
                    BSWAP_32BIG_C(0xa4531e35U), BSWAP_32BIG_C(0xcc3855b1U), BSWAP_32BIG_C(0xc2c81c61U), BSWAP_32BIG_C(
                        0x7bf2d44eU),
                };
                r_rsip_func102(Param_p4e_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p4e_func100_006[] =
                {
                    BSWAP_32BIG_C(0xe0d3120aU), BSWAP_32BIG_C(0xf9bf0e64U), BSWAP_32BIG_C(0x1015145cU), BSWAP_32BIG_C(
                        0x69b1c7edU),
                };
                r_rsip_func100(Param_p4e_func100_006);
                r_rsip_func103();

                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004e03U, 0x00000000U);

                static const uint32_t Param_p4e_func101_006[] =
                {
                    BSWAP_32BIG_C(0x7e3c1366U), BSWAP_32BIG_C(0x00edd744U), BSWAP_32BIG_C(0x09d9ce4aU), BSWAP_32BIG_C(
                        0xb82affdfU),
                };
                r_rsip_func101(Param_p4e_func101_006);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x0165e3d8U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004e03U, 0x00000000U);

                static const uint32_t Param_p4e_func101_007[] =
                {
                    BSWAP_32BIG_C(0x6ccd1a82U), BSWAP_32BIG_C(0x9eb897b2U), BSWAP_32BIG_C(0x1d2db16eU), BSWAP_32BIG_C(
                        0x857f8008U),
                };
                r_rsip_func101(Param_p4e_func101_007);
                r_rsip_func044();

                static const uint32_t Param_p4e_func100_007[] =
                {
                    BSWAP_32BIG_C(0x04cac0e6U), BSWAP_32BIG_C(0x08d035f7U), BSWAP_32BIG_C(0xd5b4c498U), BSWAP_32BIG_C(
                        0x0e8fa1beU),
                };
                r_rsip_func100(Param_p4e_func100_007);
                WR1_PROG(REG_00B0H, 0x00009838U);

                r_rsip_func_sub004(0x40000200U, 0xe7009d07U, 0x00430031U, 0x00001032U);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[5]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[9]);

                static const uint32_t Param_p4e_func100_008[] =
                {
                    BSWAP_32BIG_C(0x152ec865U), BSWAP_32BIG_C(0x56a56499U), BSWAP_32BIG_C(0x4092aeffU), BSWAP_32BIG_C(
                        0xfbca4362U),
                };
                r_rsip_func100(Param_p4e_func100_008);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[13]);

                static const uint32_t Param_p4e_func100_009[] =
                {
                    BSWAP_32BIG_C(0xce730911U), BSWAP_32BIG_C(0xd387c461U), BSWAP_32BIG_C(0x7d5eb719U), BSWAP_32BIG_C(
                        0xded8e8c4U),
                };
                r_rsip_func100(Param_p4e_func100_009);
                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &OutData_EncSecret[0]);

                static const uint32_t Param_p4e_func102_005[] =
                {
                    BSWAP_32BIG_C(0xb0cad132U), BSWAP_32BIG_C(0xef580084U), BSWAP_32BIG_C(0xdfb1542bU), BSWAP_32BIG_C(
                        0x66298457U),
                };
                r_rsip_func102(Param_p4e_func102_005);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
