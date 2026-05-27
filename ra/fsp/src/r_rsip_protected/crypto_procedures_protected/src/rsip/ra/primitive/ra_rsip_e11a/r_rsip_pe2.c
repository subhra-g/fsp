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

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x80010000U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3420a800U, 0x00000002U, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000001U);

    r_rsip_func070(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    WR1_PROG(REG_00B8H, 0x00000005U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    WR1_PROG(REG_00A0H, 0x20010001U);
    WAIT_STS(REG_00A8H, 0, 1);
    WR1_PROG(REG_00ACH, 0x00000001U);

    r_rsip_func074();

    WR1_PROG(REG_0094H, 0x000034a6U);

    static const uint32_t Param_pe2_sub100_001[] =
    {
        BSWAP_32BIG_C(0x0000e201U), BSWAP_32BIG_C(0xba0cee2cU), BSWAP_32BIG_C(0x269f404cU),
        BSWAP_32BIG_C(0x6e5ad263U),
        BSWAP_32BIG_C(0xd6645663U), BSWAP_32BIG_C(0x0000e201U), BSWAP_32BIG_C(0x3bfb8b03U),
        BSWAP_32BIG_C(0xd2c41a7dU),
        BSWAP_32BIG_C(0x91022ed6U),
        BSWAP_32BIG_C(0x9ab26ba7U), 0x00001432U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_pe2_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_pe2_func100_001[] =
    {
        BSWAP_32BIG_C(0xac4e4994U), BSWAP_32BIG_C(0x0a5376a3U), BSWAP_32BIG_C(0x60d6729cU), BSWAP_32BIG_C(0xbf3e7c8aU),
    };
    r_rsip_func100(Param_pe2_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe2_func102_001[] =
        {
            BSWAP_32BIG_C(0x86d49a48U), BSWAP_32BIG_C(0x6dbd8fd7U), BSWAP_32BIG_C(0x9ce26314U), BSWAP_32BIG_C(
                0x00385660U),
        };
        r_rsip_func102(Param_pe2_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010060U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_PubKeyType[0]);
        r_rsip_func_sub012(0x38000c63U, 0x00260000U);

        static const uint32_t Param_pe2_func100_002[] =
        {
            BSWAP_32BIG_C(0x9d395341U), BSWAP_32BIG_C(0x8af5c5b8U), BSWAP_32BIG_C(0xe7e6435cU), BSWAP_32BIG_C(
                0xfeb6c487U),
        };
        r_rsip_func100(Param_pe2_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

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
                BSWAP_32BIG_C(0xf9ed2becU), BSWAP_32BIG_C(0xc2b5d994U), BSWAP_32BIG_C(0x883a9bddU), BSWAP_32BIG_C(
                    0x04ea3fadU),
            };
            r_rsip_func101(Param_pe2_func101_001);
        }
        else
        {
            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x800100c0U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_PubKey[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x800100e0U, 0x0000e202U);

            static const uint32_t Param_pe2_func101_002[] =
            {
                BSWAP_32BIG_C(0x504c6b12U), BSWAP_32BIG_C(0xe688f065U), BSWAP_32BIG_C(0xe1a0bd6cU), BSWAP_32BIG_C(
                    0xcbcf40aaU),
            };
            r_rsip_func101(Param_pe2_func101_002);
            r_rsip_func143();

            r_rsip_func075();

            r_rsip_func_sub002(0x800100e0U, 0x0000e202U);

            static const uint32_t Param_pe2_func101_003[] =
            {
                BSWAP_32BIG_C(0xb7f81698U), BSWAP_32BIG_C(0x47cf658dU), BSWAP_32BIG_C(0x27903d01U), BSWAP_32BIG_C(
                    0xec2a1305U),
            };
            r_rsip_func101(Param_pe2_func101_003);
            r_rsip_func044();

            r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x00000fc1U, 0x40000300U, 0xe8009107U);
            WR4_ADDR(REG_002CH, &InData_PubKey[1]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[5]);

            r_rsip_func_sub004(0x0000140fU, 0x00c10021U);

            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[9]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_PubKey[13]);

            r_rsip_func_sub004(0x00001414U, 0x00c10021U);

            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_PubKey[17]);

            r_rsip_func_sub006(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe2_func100_003[] =
            {
                BSWAP_32BIG_C(0x4586396aU), BSWAP_32BIG_C(0xa572af97U), BSWAP_32BIG_C(0x36ee9174U), BSWAP_32BIG_C(
                    0x21d3640fU),
            };
            r_rsip_func100(Param_pe2_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe2_func102_002[] =
                {
                    BSWAP_32BIG_C(0x68296eceU), BSWAP_32BIG_C(0xed51638aU), BSWAP_32BIG_C(0x78c79c7aU), BSWAP_32BIG_C(
                        0x7003da46U),
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
                    BSWAP_32BIG_C(0x653e751bU), BSWAP_32BIG_C(0x6beef504U), BSWAP_32BIG_C(0x37e430b1U), BSWAP_32BIG_C(
                        0x92a6b106U),
                };
                r_rsip_func101(Param_pe2_func101_004);
            }
        }

        r_rsip_func008();

        static const uint32_t Param_pe2_func100_004[] =
        {
            BSWAP_32BIG_C(0x678da258U), BSWAP_32BIG_C(0xc5ac0b4aU), BSWAP_32BIG_C(0x72697280U), BSWAP_32BIG_C(
                0x03a4d00dU),
        };
        r_rsip_func100(Param_pe2_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe2_func102_003[] =
            {
                BSWAP_32BIG_C(0x32776746U), BSWAP_32BIG_C(0xbbbdd99dU), BSWAP_32BIG_C(0x5120f9b5U), BSWAP_32BIG_C(
                    0x2a2ab1b3U),
            };
            r_rsip_func102(Param_pe2_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub002(0x800100e0U, 0x000000e2U);

            static const uint32_t Param_pe2_func101_005[] =
            {
                BSWAP_32BIG_C(0x03d97f21U), BSWAP_32BIG_C(0x170dae2cU), BSWAP_32BIG_C(0xaabdd916U), BSWAP_32BIG_C(
                    0xcf0b4106U),
            };
            r_rsip_func101(Param_pe2_func101_005);
            r_rsip_func088();

            static const uint32_t Param_pe2_func100_005[] =
            {
                BSWAP_32BIG_C(0xea572d81U), BSWAP_32BIG_C(0x26b963ddU), BSWAP_32BIG_C(0xbca69d01U), BSWAP_32BIG_C(
                    0x44b58eecU),
            };
            r_rsip_func100(Param_pe2_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe2_func102_004[] =
                {
                    BSWAP_32BIG_C(0xf7e36273U), BSWAP_32BIG_C(0xff75c753U), BSWAP_32BIG_C(0x422c0cccU), BSWAP_32BIG_C(
                        0x6741ca2aU),
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
                    BSWAP_32BIG_C(0x139686b6U), BSWAP_32BIG_C(0x160425a8U), BSWAP_32BIG_C(0x93642c65U), BSWAP_32BIG_C(
                        0x0f94cdd3U),
                };
                r_rsip_func100(Param_pe2_func100_006);
                r_rsip_func103();

                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e203U);

                static const uint32_t Param_pe2_func101_006[] =
                {
                    BSWAP_32BIG_C(0x93f31adeU), BSWAP_32BIG_C(0x88ee952aU), BSWAP_32BIG_C(0x7de15226U), BSWAP_32BIG_C(
                        0xf144963bU),
                };
                r_rsip_func101(Param_pe2_func101_006);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x015c5d71U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e203U);

                static const uint32_t Param_pe2_func101_007[] =
                {
                    BSWAP_32BIG_C(0xbfbd7b30U), BSWAP_32BIG_C(0x3f928cb4U), BSWAP_32BIG_C(0xce35843fU), BSWAP_32BIG_C(
                        0xc92ab8f8U),
                };
                r_rsip_func101(Param_pe2_func101_007);
                r_rsip_func044();

                static const uint32_t Param_pe2_func100_007[] =
                {
                    BSWAP_32BIG_C(0x3bf18a65U), BSWAP_32BIG_C(0x5524019bU), BSWAP_32BIG_C(0xd9722e3eU), BSWAP_32BIG_C(
                        0x1ca4b836U),
                };
                r_rsip_func100(Param_pe2_func100_007);
                WR1_PROG(REG_00B0H, 0x00001828U);

                WR1_PROG(REG_00D4H, 0x40000100U);
                r_rsip_func_sub006(0xe7009d07U, 0x00430021U);

                WR1_PROG(REG_0008H, 0x00001022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[5]);

                static const uint32_t Param_pe2_func100_008[] =
                {
                    BSWAP_32BIG_C(0x0d3ec125U), BSWAP_32BIG_C(0x5715eb10U), BSWAP_32BIG_C(0x667e6836U), BSWAP_32BIG_C(
                        0xb476cfc4U),
                };
                r_rsip_func100(Param_pe2_func100_008);
                r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                WR1_PROG(REG_00D4H, 0x40000000U);
                r_rsip_func_sub006(0x09108105U, 0x00410011U);

                WR1_PROG(REG_0008H, 0x00001012U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_EncSecret[9]);

                static const uint32_t Param_pe2_func100_009[] =
                {
                    BSWAP_32BIG_C(0x9e719bb6U), BSWAP_32BIG_C(0x918ea4c1U), BSWAP_32BIG_C(0x15783e96U), BSWAP_32BIG_C(
                        0x22e71df6U),
                };
                r_rsip_func100(Param_pe2_func100_009);
                WR1_PROG(REG_009CH, 0x81010000U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_EncSecret[0]);

                static const uint32_t Param_pe2_func102_005[] =
                {
                    BSWAP_32BIG_C(0x0df6d43cU), BSWAP_32BIG_C(0x14cc0962U), BSWAP_32BIG_C(0xf5c2e9b8U), BSWAP_32BIG_C(
                        0x97091165U),
                };
                r_rsip_func102(Param_pe2_func102_005);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
