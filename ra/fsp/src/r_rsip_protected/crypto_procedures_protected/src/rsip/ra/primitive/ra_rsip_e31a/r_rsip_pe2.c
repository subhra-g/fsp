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

rsip_ret_t r_rsip_pe2 (const uint32_t InData_CurveType[],
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

    WR1_PROG(REG_0070H, 0x00e20001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00A0H, 0x00010000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3420a800U, 0x00000002U);
    WR1_PROG(REG_0094H, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000001U);

    r_rsip_func070(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    WR1_PROG(REG_00B8H, 0x00000005U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func074();

    WR1_PROG(REG_0094H, 0x000034a6U);

    static const uint32_t Param_pe2_sub100_001[] =
    {
        BSWAP_32BIG_C(0x0000e201U), BSWAP_32BIG_C(0x0b9326bfU), BSWAP_32BIG_C(0xe66c5fc5U),
        BSWAP_32BIG_C(0xff51b8acU),
        BSWAP_32BIG_C(0x5f256e0bU), BSWAP_32BIG_C(0x0000e201U), BSWAP_32BIG_C(0x3ad18b94U),
        BSWAP_32BIG_C(0xbdeac556U),
        BSWAP_32BIG_C(0x21260613U),
        BSWAP_32BIG_C(0xbafef59fU), 0x00001432U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_pe2_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_pe2_func100_001[] =
    {
        BSWAP_32BIG_C(0x9e5c7cbdU), BSWAP_32BIG_C(0xf53fae8fU), BSWAP_32BIG_C(0x3396ff5eU), BSWAP_32BIG_C(0xfebf5a76U),
    };
    r_rsip_func100(Param_pe2_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe2_func102_001[] =
        {
            BSWAP_32BIG_C(0x2fd04f93U), BSWAP_32BIG_C(0x583ac9caU), BSWAP_32BIG_C(0xfd47875dU), BSWAP_32BIG_C(
                0x13d67dcdU),
        };
        r_rsip_func102(Param_pe2_func102_001);
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

        static const uint32_t Param_pe2_func100_002[] =
        {
            BSWAP_32BIG_C(0xc8424aceU), BSWAP_32BIG_C(0x269a5d9bU), BSWAP_32BIG_C(0x7a885cb3U), BSWAP_32BIG_C(
                0x36a3817bU),
        };
        r_rsip_func100(Param_pe2_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x00000fc5U);
            WR1_PROG(REG_00B0H, 0x0000140fU);
            WAIT_STS(REG_0014H, 31, 1);
            WR8_ADDR(REG_002CH, &InData_PubKey[0]);

            WR1_PROG(REG_00B0H, 0x00001414U);
            WAIT_STS(REG_0014H, 31, 1);
            WR8_ADDR(REG_002CH, &InData_PubKey[8]);

            static const uint32_t Param_pe2_func101_001[] =
            {
                BSWAP_32BIG_C(0x5c5f5981U), BSWAP_32BIG_C(0x4a142153U), BSWAP_32BIG_C(0x4decd683U), BSWAP_32BIG_C(
                    0x9f37e783U),
            };
            r_rsip_func101(Param_pe2_func101_001);
        }
        else
        {
            r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_PubKey[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e202U, 0x00000000U);

            static const uint32_t Param_pe2_func101_002[] =
            {
                BSWAP_32BIG_C(0x9580b5d1U), BSWAP_32BIG_C(0x7ac5b6a9U), BSWAP_32BIG_C(0x387ea163U), BSWAP_32BIG_C(
                    0x8054e050U),
            };
            r_rsip_func101(Param_pe2_func101_002);
            r_rsip_func143();

            r_rsip_func075();

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e202U, 0x00000000U);

            static const uint32_t Param_pe2_func101_003[] =
            {
                BSWAP_32BIG_C(0x8a94aba7U), BSWAP_32BIG_C(0x6a2c20ffU), BSWAP_32BIG_C(0x82a0c105U), BSWAP_32BIG_C(
                    0x3e9d43e9U),
            };
            r_rsip_func101(Param_pe2_func101_003);
            r_rsip_func044();

            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub011(0x00000fc1U, 0x40000300U, 0xe8009107U);
            WR4_ADDR(REG_002CH, &InData_PubKey[1]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[5]);

            r_rsip_func_sub009(0x0000140fU, 0x00c10021U, 0x00001800U);

            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[9]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[13]);

            r_rsip_func_sub009(0x00001414U, 0x00c10021U, 0x00001800U);

            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_PubKey[17]);

            r_rsip_func_sub013(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe2_func100_003[] =
            {
                BSWAP_32BIG_C(0xe5a01ae5U), BSWAP_32BIG_C(0x5c89bb66U), BSWAP_32BIG_C(0x06bdc215U), BSWAP_32BIG_C(
                    0x995cda27U),
            };
            r_rsip_func100(Param_pe2_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe2_func102_002[] =
                {
                    BSWAP_32BIG_C(0xd5a16328U), BSWAP_32BIG_C(0x2f158a32U), BSWAP_32BIG_C(0xe251cb13U), BSWAP_32BIG_C(
                        0x85037851U),
                };
                r_rsip_func102(Param_pe2_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_pe2_func101_004[] =
                {
                    BSWAP_32BIG_C(0xfb82ec0cU), BSWAP_32BIG_C(0x423e0a16U), BSWAP_32BIG_C(0x82504df7U), BSWAP_32BIG_C(
                        0xa9e9922cU),
                };
                r_rsip_func101(Param_pe2_func101_004);
            }
        }

        r_rsip_func008();

        static const uint32_t Param_pe2_func100_004[] =
        {
            BSWAP_32BIG_C(0x908df434U), BSWAP_32BIG_C(0xd0d7d6a2U), BSWAP_32BIG_C(0x5d12500eU), BSWAP_32BIG_C(
                0xbd08c02aU),
        };
        r_rsip_func100(Param_pe2_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe2_func102_003[] =
            {
                BSWAP_32BIG_C(0x5925df6eU), BSWAP_32BIG_C(0x097d7b89U), BSWAP_32BIG_C(0xf566e677U), BSWAP_32BIG_C(
                    0xaf90188bU),
            };
            r_rsip_func102(Param_pe2_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000e2U, 0x00000000U);

            static const uint32_t Param_pe2_func101_005[] =
            {
                BSWAP_32BIG_C(0x4e5b8995U), BSWAP_32BIG_C(0x9125f7b2U), BSWAP_32BIG_C(0x492ff671U), BSWAP_32BIG_C(
                    0x3dacb2d2U),
            };
            r_rsip_func101(Param_pe2_func101_005);
            r_rsip_func088();

            static const uint32_t Param_pe2_func100_005[] =
            {
                BSWAP_32BIG_C(0x422686d9U), BSWAP_32BIG_C(0xae95433bU), BSWAP_32BIG_C(0x8b726562U), BSWAP_32BIG_C(
                    0xbf4401f6U),
            };
            r_rsip_func100(Param_pe2_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe2_func102_004[] =
                {
                    BSWAP_32BIG_C(0xe9624b2eU), BSWAP_32BIG_C(0xe24cbd49U), BSWAP_32BIG_C(0x606b3a3eU), BSWAP_32BIG_C(
                        0xa0cc72f3U),
                };
                r_rsip_func102(Param_pe2_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe2_func100_006[] =
                {
                    BSWAP_32BIG_C(0xbb869832U), BSWAP_32BIG_C(0xaa061383U), BSWAP_32BIG_C(0xddecf058U), BSWAP_32BIG_C(
                        0xfcf7bbd3U),
                };
                r_rsip_func100(Param_pe2_func100_006);
                r_rsip_func103();

                r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

                WR1_PROG(REG_0094H, 0x000034c0U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e203U, 0x00000000U);

                static const uint32_t Param_pe2_func101_006[] =
                {
                    BSWAP_32BIG_C(0xcd481beeU), BSWAP_32BIG_C(0xe37751e1U), BSWAP_32BIG_C(0xcea94c74U), BSWAP_32BIG_C(
                        0x482ef26bU),
                };
                r_rsip_func101(Param_pe2_func101_006);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x015c5d71U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e203U, 0x00000000U);

                static const uint32_t Param_pe2_func101_007[] =
                {
                    BSWAP_32BIG_C(0xa6c19a58U), BSWAP_32BIG_C(0x32026bd9U), BSWAP_32BIG_C(0xf33ee201U), BSWAP_32BIG_C(
                        0x3904c406U),
                };
                r_rsip_func101(Param_pe2_func101_007);
                r_rsip_func044();

                static const uint32_t Param_pe2_func100_007[] =
                {
                    BSWAP_32BIG_C(0x08969528U), BSWAP_32BIG_C(0x5be7c99fU), BSWAP_32BIG_C(0x3b22ae41U), BSWAP_32BIG_C(
                        0xb1933a99U),
                };
                r_rsip_func100(Param_pe2_func100_007);
                WR1_PROG(REG_00B0H, 0x00001828U);

                r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00430021U, 0x00001022U);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[5]);

                static const uint32_t Param_pe2_func100_008[] =
                {
                    BSWAP_32BIG_C(0x7993c8b0U), BSWAP_32BIG_C(0x1b8d45d2U), BSWAP_32BIG_C(0x703280abU), BSWAP_32BIG_C(
                        0xead63f15U),
                };
                r_rsip_func100(Param_pe2_func100_008);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[9]);

                static const uint32_t Param_pe2_func100_009[] =
                {
                    BSWAP_32BIG_C(0x3c66653fU), BSWAP_32BIG_C(0x6d4de3ccU), BSWAP_32BIG_C(0xfb79a827U), BSWAP_32BIG_C(
                        0x6d17f45eU),
                };
                r_rsip_func100(Param_pe2_func100_009);
                r_rsip_func_sub017(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_002CH, &OutData_EncSecret[0]);

                static const uint32_t Param_pe2_func102_005[] =
                {
                    BSWAP_32BIG_C(0xba5794a1U), BSWAP_32BIG_C(0xe9b47f1aU), BSWAP_32BIG_C(0x79090a19U), BSWAP_32BIG_C(
                        0xc2a51b35U),
                };
                r_rsip_func102(Param_pe2_func102_005);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
