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
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x004e0001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_p4e_func100_001[] =
    {
        BSWAP_32BIG_C(0x92296edbU), BSWAP_32BIG_C(0x82fe4ec3U), BSWAP_32BIG_C(0x7f25e598U), BSWAP_32BIG_C(0xd1a8505cU),
    };
    r_rsip_func100(Param_p4e_func100_001);
    r_rsip_func027(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e01U);

    static const uint32_t Param_p4e_func101_001[] =
    {
        BSWAP_32BIG_C(0x59fec05dU), BSWAP_32BIG_C(0xc4fde013U), BSWAP_32BIG_C(0xbb760ba8U), BSWAP_32BIG_C(0x60226a6eU),
    };
    r_rsip_func101(Param_p4e_func101_001);
    r_rsip_func043();

    r_rsip_func076();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e01U);

    static const uint32_t Param_p4e_func101_002[] =
    {
        BSWAP_32BIG_C(0x918051e2U), BSWAP_32BIG_C(0x334979ebU), BSWAP_32BIG_C(0xc0472a49U), BSWAP_32BIG_C(0x0861b75dU),
    };
    r_rsip_func101(Param_p4e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub023(0x00000bc2U, 0x40000200U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 12U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x13100000U);
    r_rsip_func_sub001(0x00c20031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p4e_func100_002[] =
    {
        BSWAP_32BIG_C(0x0be593a8U), BSWAP_32BIG_C(0x500b6a6dU), BSWAP_32BIG_C(0xff1f84c2U), BSWAP_32BIG_C(0x8baf91efU),
    };
    r_rsip_func100(Param_p4e_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p4e_func102_001[] =
        {
            BSWAP_32BIG_C(0x0b62cc05U), BSWAP_32BIG_C(0x1c2b1961U), BSWAP_32BIG_C(0x54aff6d7U), BSWAP_32BIG_C(
                0xc5184907U),
        };
        r_rsip_func102(Param_p4e_func102_001);
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

        static const uint32_t Param_p4e_func100_003[] =
        {
            BSWAP_32BIG_C(0xbb0132e6U), BSWAP_32BIG_C(0x1216121fU), BSWAP_32BIG_C(0x89234a08U), BSWAP_32BIG_C(
                0x0d4acd26U),
        };
        r_rsip_func100(Param_p4e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x00000bd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 48U; )
            {
                WR1_ADDR((&(REG_00E0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1444H, 0x00000bd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 48U; )
            {
                WR1_ADDR((&(REG_0130H))[iLoop / 4], &InData_PubKey[12 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            static const uint32_t Param_p4e_func101_003[] =
            {
                BSWAP_32BIG_C(0x76f7defaU), BSWAP_32BIG_C(0x5e75b5bcU), BSWAP_32BIG_C(0x015b79fdU), BSWAP_32BIG_C(
                    0x44e0c7b1U),
            };
            r_rsip_func101(Param_p4e_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e02U);

            static const uint32_t Param_p4e_func101_004[] =
            {
                BSWAP_32BIG_C(0xc918e5beU), BSWAP_32BIG_C(0xe21eb167U), BSWAP_32BIG_C(0x6ba23afbU), BSWAP_32BIG_C(
                    0x1fcd0500U),
            };
            r_rsip_func101(Param_p4e_func101_004);
            r_rsip_func043();

            r_rsip_func077();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e02U);

            static const uint32_t Param_p4e_func101_005[] =
            {
                BSWAP_32BIG_C(0xddc80570U), BSWAP_32BIG_C(0xb19fffb2U), BSWAP_32BIG_C(0x97d1fb16U), BSWAP_32BIG_C(
                    0xbe483218U),
            };
            r_rsip_func101(Param_p4e_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000017c2U, 0x40000500U, 0xe8009107U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);

            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub001(0x00c20031U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[21]);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c20031U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[25]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p4e_func100_004[] =
            {
                BSWAP_32BIG_C(0x7e52aadeU), BSWAP_32BIG_C(0x6912e633U), BSWAP_32BIG_C(0xf66e0c03U), BSWAP_32BIG_C(
                    0xc7a6848bU),
            };
            r_rsip_func100(Param_p4e_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4e_func102_002[] =
                {
                    BSWAP_32BIG_C(0xfb5859a3U), BSWAP_32BIG_C(0xeba553e0U), BSWAP_32BIG_C(0xd3d2ec06U), BSWAP_32BIG_C(
                        0xc0d42f02U),
                };
                r_rsip_func102(Param_p4e_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p4e_func101_006[] =
                {
                    BSWAP_32BIG_C(0x2036775cU), BSWAP_32BIG_C(0x5d9dbc00U), BSWAP_32BIG_C(0xb856a4baU), BSWAP_32BIG_C(
                        0x7285db5dU),
                };
                r_rsip_func101(Param_p4e_func101_006);
            }
        }

        r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
        r_rsip_func_sub041(0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x06060005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x06060005U, 0x00010001U);
        r_rsip_func_sub041(0x00000200U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x06060001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p4e_func100_005[] =
        {
            BSWAP_32BIG_C(0x7f5e80ebU), BSWAP_32BIG_C(0x43844727U), BSWAP_32BIG_C(0x671124a3U), BSWAP_32BIG_C(
                0xd235a938U),
        };
        r_rsip_func100(Param_p4e_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p4e_func102_003[] =
            {
                BSWAP_32BIG_C(0x50aa0ecbU), BSWAP_32BIG_C(0x5e0e722eU), BSWAP_32BIG_C(0x19cf7584U), BSWAP_32BIG_C(
                    0xf290aac4U),
            };
            r_rsip_func102(Param_p4e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_func_sub001(0x00c00031U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000218U, 0x06060009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001e0U, 0x06060009U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000004eU);

            static const uint32_t Param_p4e_func101_007[] =
            {
                BSWAP_32BIG_C(0x3920b5d9U), BSWAP_32BIG_C(0xfc89f8e0U), BSWAP_32BIG_C(0x368a44c1U), BSWAP_32BIG_C(
                    0xe7ebe725U),
            };
            r_rsip_func101(Param_p4e_func101_007);
            r_rsip_func089();

            static const uint32_t Param_p4e_func100_006[] =
            {
                BSWAP_32BIG_C(0x24e802e4U), BSWAP_32BIG_C(0x46c59e47U), BSWAP_32BIG_C(0xec6f0f3dU), BSWAP_32BIG_C(
                    0xce7ec315U),
            };
            r_rsip_func100(Param_p4e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4e_func102_004[] =
                {
                    BSWAP_32BIG_C(0x059283b7U), BSWAP_32BIG_C(0x7257859dU), BSWAP_32BIG_C(0x4d1ec816U), BSWAP_32BIG_C(
                        0x1e1a9ff1U),
                };
                r_rsip_func102(Param_p4e_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000004eU);

                static const uint32_t Param_p4e_func101_008[] =
                {
                    BSWAP_32BIG_C(0x356d0231U), BSWAP_32BIG_C(0x2eaf5637U), BSWAP_32BIG_C(0xe84305baU), BSWAP_32BIG_C(
                        0xaab18240U),
                };
                r_rsip_func101(Param_p4e_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e03U);

                static const uint32_t Param_p4e_func101_009[] =
                {
                    BSWAP_32BIG_C(0x61c9609bU), BSWAP_32BIG_C(0xeb6dca41U), BSWAP_32BIG_C(0x3cd54576U), BSWAP_32BIG_C(
                        0xe0611bedU),
                };
                r_rsip_func101(Param_p4e_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0165e3d8U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004e03U);

                static const uint32_t Param_p4e_func101_010[] =
                {
                    BSWAP_32BIG_C(0x52e64e8fU), BSWAP_32BIG_C(0xe0dce3b3U), BSWAP_32BIG_C(0x6cf3cc6cU), BSWAP_32BIG_C(
                        0x17f0b426U),
                };
                r_rsip_func101(Param_p4e_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p4e_func100_007[] =
                {
                    BSWAP_32BIG_C(0x22165956U), BSWAP_32BIG_C(0xfbe944d3U), BSWAP_32BIG_C(0xcb145b27U), BSWAP_32BIG_C(
                        0x27cd3048U),
                };
                r_rsip_func100(Param_p4e_func100_007);
                r_rsip_func_sub040(0x40000200U, 0xe7009d07U, 0x12700000U);
                r_rsip_func_sub001(0x00830031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[9]);

                static const uint32_t Param_p4e_func100_008[] =
                {
                    BSWAP_32BIG_C(0x0d69d9c3U), BSWAP_32BIG_C(0xb4e23fe0U), BSWAP_32BIG_C(0x008934f2U), BSWAP_32BIG_C(
                        0x2c7c0947U),
                };
                r_rsip_func100(Param_p4e_func100_008);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[13]);

                static const uint32_t Param_p4e_func100_009[] =
                {
                    BSWAP_32BIG_C(0xdbd8131cU), BSWAP_32BIG_C(0xa957f1dbU), BSWAP_32BIG_C(0x3141af23U), BSWAP_32BIG_C(
                        0xc1bcb082U),
                };
                r_rsip_func100(Param_p4e_func100_009);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p4e_func102_005[] =
                {
                    BSWAP_32BIG_C(0x192f519eU), BSWAP_32BIG_C(0x650ab23aU), BSWAP_32BIG_C(0x0a036f4dU), BSWAP_32BIG_C(
                        0x50c3595fU),
                };
                r_rsip_func102(Param_p4e_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
