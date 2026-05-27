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
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e20001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_pe2_func100_001[] =
    {
        BSWAP_32BIG_C(0xa841da9cU), BSWAP_32BIG_C(0xb38412f4U), BSWAP_32BIG_C(0x45131c51U), BSWAP_32BIG_C(0x1cf94ccaU),
    };
    r_rsip_func100(Param_pe2_func100_001);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x3420ab40U, 0x00000002U, 0x2000b740U, 0x00000001U);

    WR1_PROG(REG_1600H, 0x00000b9cU);

    r_rsip_func070(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e201U);

    static const uint32_t Param_pe2_func101_001[] =
    {
        BSWAP_32BIG_C(0xda96c451U), BSWAP_32BIG_C(0xf08821f6U), BSWAP_32BIG_C(0x7dfd9980U), BSWAP_32BIG_C(0x6ba79275U),
    };
    r_rsip_func101(Param_pe2_func101_001);
    r_rsip_func043();

    r_rsip_func074();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e201U);

    static const uint32_t Param_pe2_func101_002[] =
    {
        BSWAP_32BIG_C(0xde554be3U), BSWAP_32BIG_C(0x835b52e4U), BSWAP_32BIG_C(0xa5c19a65U), BSWAP_32BIG_C(0x0ff5e70eU),
    };
    r_rsip_func101(Param_pe2_func101_002);
    r_rsip_func044();

    r_rsip_func_sub023(0x000007c2U, 0x40000100U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 8U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x13200000U);
    r_rsip_func_sub001(0x00c20021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe2_func100_002[] =
    {
        BSWAP_32BIG_C(0x63938360U), BSWAP_32BIG_C(0xdf7b7f55U), BSWAP_32BIG_C(0x3b1a44a4U), BSWAP_32BIG_C(0x8e6efdbcU),
    };
    r_rsip_func100(Param_pe2_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe2_func102_001[] =
        {
            BSWAP_32BIG_C(0x2f393c7cU), BSWAP_32BIG_C(0x8c5e46b7U), BSWAP_32BIG_C(0xffe3e7e5U), BSWAP_32BIG_C(
                0x50c0fe61U),
        };
        r_rsip_func102(Param_pe2_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010360U);
        WR1_PROG(REG_1420H, InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000f7bU, 0x00260000U);

        static const uint32_t Param_pe2_func100_003[] =
        {
            BSWAP_32BIG_C(0x28acf91aU), BSWAP_32BIG_C(0x3d0b2c86U), BSWAP_32BIG_C(0x3d8d9d07U), BSWAP_32BIG_C(
                0xe170dc69U),
        };
        r_rsip_func100(Param_pe2_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x000007d0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 32U; )
            {
                WR1_ADDR((&(REG_00F0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1444H, 0x000007d0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 32U; )
            {
                WR1_ADDR((&(REG_0140H))[iLoop / 4], &InData_PubKey[8 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            static const uint32_t Param_pe2_func101_003[] =
            {
                BSWAP_32BIG_C(0x0760abfbU), BSWAP_32BIG_C(0x6d259365U), BSWAP_32BIG_C(0x92002191U), BSWAP_32BIG_C(
                    0x19fa1835U),
            };
            r_rsip_func101(Param_pe2_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e202U);

            static const uint32_t Param_pe2_func101_004[] =
            {
                BSWAP_32BIG_C(0xf8451663U), BSWAP_32BIG_C(0x0d90a12dU), BSWAP_32BIG_C(0xabf0cbe6U), BSWAP_32BIG_C(
                    0xe645e16bU),
            };
            r_rsip_func101(Param_pe2_func101_004);
            r_rsip_func043();

            r_rsip_func075();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e202U);

            static const uint32_t Param_pe2_func101_005[] =
            {
                BSWAP_32BIG_C(0x8e4c4dfbU), BSWAP_32BIG_C(0x01025140U), BSWAP_32BIG_C(0x55937e47U), BSWAP_32BIG_C(
                    0x1dc2433aU),
            };
            r_rsip_func101(Param_pe2_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x00000fc2U, 0x40000300U, 0xe8009107U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub001(0x00c20021U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);

            WR1_PROG(REG_1404H, 0x11400000U);
            r_rsip_func_sub001(0x00c20021U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pe2_func100_004[] =
            {
                BSWAP_32BIG_C(0x74c3157dU), BSWAP_32BIG_C(0x2dcea5d2U), BSWAP_32BIG_C(0x459809c9U), BSWAP_32BIG_C(
                    0xe0c6936dU),
            };
            r_rsip_func100(Param_pe2_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe2_func102_002[] =
                {
                    BSWAP_32BIG_C(0x26949b41U), BSWAP_32BIG_C(0x8f92608cU), BSWAP_32BIG_C(0x762fbd89U), BSWAP_32BIG_C(
                        0xe14f434aU),
                };
                r_rsip_func102(Param_pe2_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_pe2_func101_006[] =
                {
                    BSWAP_32BIG_C(0xb65fc77cU), BSWAP_32BIG_C(0x1d9908beU), BSWAP_32BIG_C(0xaf7473a5U), BSWAP_32BIG_C(
                        0xb78d6075U),
                };
                r_rsip_func101(Param_pe2_func101_006);
            }
        }

        r_rsip_func008();

        static const uint32_t Param_pe2_func100_005[] =
        {
            BSWAP_32BIG_C(0x5e180cffU), BSWAP_32BIG_C(0x7c600a29U), BSWAP_32BIG_C(0xa2e7e0d9U), BSWAP_32BIG_C(
                0xc5bf4914U),
        };
        r_rsip_func100(Param_pe2_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe2_func102_003[] =
            {
                BSWAP_32BIG_C(0xfd64a6a4U), BSWAP_32BIG_C(0x549a39d2U), BSWAP_32BIG_C(0xd6d1554aU), BSWAP_32BIG_C(
                    0xce100a75U),
            };
            r_rsip_func102(Param_pe2_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub001(0x00c00021U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000228U, 0x04040009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000200U, 0x04040009U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000e2U);

            static const uint32_t Param_pe2_func101_007[] =
            {
                BSWAP_32BIG_C(0x1120aea2U), BSWAP_32BIG_C(0x5bcb3616U), BSWAP_32BIG_C(0x7f221ad0U), BSWAP_32BIG_C(
                    0x2df5afbcU),
            };
            r_rsip_func101(Param_pe2_func101_007);
            r_rsip_func088();

            static const uint32_t Param_pe2_func100_006[] =
            {
                BSWAP_32BIG_C(0x271e41a4U), BSWAP_32BIG_C(0xca9878b3U), BSWAP_32BIG_C(0x989433c5U), BSWAP_32BIG_C(
                    0x26bc7f8cU),
            };
            r_rsip_func100(Param_pe2_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe2_func102_004[] =
                {
                    BSWAP_32BIG_C(0xa2087fa5U), BSWAP_32BIG_C(0xd41c5b4aU), BSWAP_32BIG_C(0x5febcdadU), BSWAP_32BIG_C(
                        0x7bf70f4fU),
                };
                r_rsip_func102(Param_pe2_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000e2U);

                static const uint32_t Param_pe2_func101_008[] =
                {
                    BSWAP_32BIG_C(0x22e02587U), BSWAP_32BIG_C(0xecce12b9U), BSWAP_32BIG_C(0x7e546bc9U), BSWAP_32BIG_C(
                        0x94873ae2U),
                };
                r_rsip_func101(Param_pe2_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e203U);

                static const uint32_t Param_pe2_func101_009[] =
                {
                    BSWAP_32BIG_C(0x88fcce3dU), BSWAP_32BIG_C(0x54172488U), BSWAP_32BIG_C(0x29beac92U), BSWAP_32BIG_C(
                        0xe32e0968U),
                };
                r_rsip_func101(Param_pe2_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x015c5d71U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e203U);

                static const uint32_t Param_pe2_func101_010[] =
                {
                    BSWAP_32BIG_C(0x79d167f3U), BSWAP_32BIG_C(0x8a1752e6U), BSWAP_32BIG_C(0x847c11d8U), BSWAP_32BIG_C(
                        0x1c158e46U),
                };
                r_rsip_func101(Param_pe2_func101_010);
                r_rsip_func044();

                static const uint32_t Param_pe2_func100_007[] =
                {
                    BSWAP_32BIG_C(0x9f24ee28U), BSWAP_32BIG_C(0xd0e30f82U), BSWAP_32BIG_C(0xad3713b7U), BSWAP_32BIG_C(
                        0xf389361aU),
                };
                r_rsip_func100(Param_pe2_func100_007);
                r_rsip_func_sub040(0x40000100U, 0xe7009d07U, 0x12800000U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5]);

                static const uint32_t Param_pe2_func100_008[] =
                {
                    BSWAP_32BIG_C(0x339850beU), BSWAP_32BIG_C(0x2cae0b73U), BSWAP_32BIG_C(0x1f03dbfdU), BSWAP_32BIG_C(
                        0x9916c85cU),
                };
                r_rsip_func100(Param_pe2_func100_008);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[9]);

                static const uint32_t Param_pe2_func100_009[] =
                {
                    BSWAP_32BIG_C(0x593f37c3U), BSWAP_32BIG_C(0x3c220bd5U), BSWAP_32BIG_C(0x140748abU), BSWAP_32BIG_C(
                        0xf426bf49U),
                };
                r_rsip_func100(Param_pe2_func100_009);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_pe2_func102_005[] =
                {
                    BSWAP_32BIG_C(0xb566a837U), BSWAP_32BIG_C(0x07ccbe98U), BSWAP_32BIG_C(0x23fd0bfaU), BSWAP_32BIG_C(
                        0x8cdd7025U),
                };
                r_rsip_func102(Param_pe2_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
