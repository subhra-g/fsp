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

rsip_ret_t r_rsip_p4f (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x004f0001U, 0x000007f0U);

    static const uint32_t Param_p4f_func100_001[] =
    {
        BSWAP_32BIG_C(0x2fbe0dd5U), BSWAP_32BIG_C(0xda443bd5U), BSWAP_32BIG_C(0x795891d9U), BSWAP_32BIG_C(0xc94c2b9bU),
    };
    r_rsip_func100(Param_p4f_func100_001);
    r_rsip_func086(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00004f01U);

    static const uint32_t Param_p4f_func101_001[] =
    {
        BSWAP_32BIG_C(0xf28e80d5U), BSWAP_32BIG_C(0x315cc5ebU), BSWAP_32BIG_C(0xcd897c8cU), BSWAP_32BIG_C(0xd19ed2b7U),
    };
    r_rsip_func101(Param_p4f_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000025U);

    r_rsip_func_sub003(0x800103a0U, 0x00004f01U);

    static const uint32_t Param_p4f_func101_002[] =
    {
        BSWAP_32BIG_C(0x6dbf0933U), BSWAP_32BIG_C(0x32549d85U), BSWAP_32BIG_C(0x6b34aa8fU), BSWAP_32BIG_C(0xbea09385U),
    };
    r_rsip_func101(Param_p4f_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x000013c2U, 0x40000400U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x12f00000U);

    for (iLoop = 0U; iLoop < 20; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        r_rsip_func_sub001(0x00c20011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p4f_func100_002[] =
    {
        BSWAP_32BIG_C(0xd1f859c7U), BSWAP_32BIG_C(0x86170122U), BSWAP_32BIG_C(0x89e49f17U), BSWAP_32BIG_C(0x2813c39aU),
    };
    r_rsip_func100(Param_p4f_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p4f_func102_001[] =
        {
            BSWAP_32BIG_C(0x50e46e85U), BSWAP_32BIG_C(0x0f5300e9U), BSWAP_32BIG_C(0x62d21955U), BSWAP_32BIG_C(
                0x94b83cc8U),
        };
        r_rsip_func102(Param_p4f_func102_001);
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

        static const uint32_t Param_p4f_func100_003[] =
        {
            BSWAP_32BIG_C(0xbfe67ddeU), BSWAP_32BIG_C(0x20521f01U), BSWAP_32BIG_C(0x90b66147U), BSWAP_32BIG_C(
                0x47237516U),
        };
        r_rsip_func100(Param_p4f_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000bdeU);

            WR1_PROG(REG_1444H, 0x000027c7U);
            WR1_PROG(REG_1608H, 0x80a8001eU);
            for (iLoop = 0U; iLoop < 40U; iLoop++)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_PubKey[iLoop]);
            }

            r_rsip_func_sub034(0x00000bffU, 0x00000bbdU);

            for (iLoop = 0U; iLoop < 2U; iLoop++)
            {
                for (jLoop = 0U; jLoop < 3U; jLoop++)
                {
                    r_rsip_func_sub021(0x0000381eU, 0x38000c00U, 0x100053fdU, 0x00002fa0U);
                    WR1_PROG(REG_1600H, 0x0000a7c0U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub021(0x0000381eU, 0x38008c00U, 0xfffffe00U, 0x100053fdU);

                r_rsip_func_sub022(0x00002fa0U, 0x0000b7c0U, 0x00000050U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub006(0x38008be0U, 0x000000ffU, 0x00A60000U);

            static const uint32_t Param_p4f_func100_004[] =
            {
                BSWAP_32BIG_C(0xecb11aacU), BSWAP_32BIG_C(0xda2ad50aU), BSWAP_32BIG_C(0xd627203cU), BSWAP_32BIG_C(
                    0xf389f55fU),
            };
            r_rsip_func100(Param_p4f_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_002[] =
                {
                    BSWAP_32BIG_C(0x78a6982eU), BSWAP_32BIG_C(0xa6e21406U), BSWAP_32BIG_C(0x377d293dU), BSWAP_32BIG_C(
                        0xe64d5881U),
                };
                r_rsip_func102(Param_p4f_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p4f_func101_003[] =
                {
                    BSWAP_32BIG_C(0x756ddd9cU), BSWAP_32BIG_C(0xd4c58ca1U), BSWAP_32BIG_C(0xfaab4ce0U), BSWAP_32BIG_C(
                        0x959e4bd7U),
                };
                r_rsip_func101(Param_p4f_func101_003);
            }
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x00004f02U);

            static const uint32_t Param_p4f_func101_004[] =
            {
                BSWAP_32BIG_C(0x3f9fca82U), BSWAP_32BIG_C(0x69efa2fdU), BSWAP_32BIG_C(0x138a963eU), BSWAP_32BIG_C(
                    0x6052d13eU),
            };
            r_rsip_func101(Param_p4f_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000024U);

            r_rsip_func_sub003(0x800103a0U, 0x00004f02U);

            static const uint32_t Param_p4f_func101_005[] =
            {
                BSWAP_32BIG_C(0xa5eb2c5fU), BSWAP_32BIG_C(0x97ef0327U), BSWAP_32BIG_C(0xf309ccf8U), BSWAP_32BIG_C(
                    0xfddb84e6U),
            };
            r_rsip_func101(Param_p4f_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub024(0x000027c2U, 0x40000900U, 0xe8009107U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x80a8001eU);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[5]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[9]);
            r_rsip_func_sub001(0x03420031U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[13]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[17]);
            r_rsip_func_sub001(0x03420021U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[21]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[25]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[29]);
            r_rsip_func_sub001(0x03420031U);

            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[33]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKey[37]);
            r_rsip_func_sub001(0x03420021U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[41]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p4f_func100_005[] =
            {
                BSWAP_32BIG_C(0xea4e2544U), BSWAP_32BIG_C(0x112ab0daU), BSWAP_32BIG_C(0xc55034b6U), BSWAP_32BIG_C(
                    0x58e8bc20U),
            };
            r_rsip_func100(Param_p4f_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x9508cee5U), BSWAP_32BIG_C(0x64357f83U), BSWAP_32BIG_C(0x2564cf34U), BSWAP_32BIG_C(
                        0x84adc095U),
                };
                r_rsip_func102(Param_p4f_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p4f_func101_006[] =
                {
                    BSWAP_32BIG_C(0x35e076bbU), BSWAP_32BIG_C(0xae3ecdedU), BSWAP_32BIG_C(0xa32be00fU), BSWAP_32BIG_C(
                        0xb4bd9a5bU),
                };
                r_rsip_func101(Param_p4f_func101_006);
            }
        }

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x81a8001eU);
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_func_sub001(0x00c90051U);

        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_func_sub001(0x00c90051U);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x09090005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x09090005U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x09090001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p4f_func100_006[] =
        {
            BSWAP_32BIG_C(0x6ca0d89cU), BSWAP_32BIG_C(0x0721cd88U), BSWAP_32BIG_C(0xa199c26fU), BSWAP_32BIG_C(
                0x682d5e28U),
        };
        r_rsip_func100(Param_p4f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p4f_func102_004[] =
            {
                BSWAP_32BIG_C(0x2c44d0caU), BSWAP_32BIG_C(0x6a189af6U), BSWAP_32BIG_C(0x6fc45e3aU), BSWAP_32BIG_C(
                    0x9ed4e39eU),
            };
            r_rsip_func102(Param_p4f_func102_004);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10c80000U);
            r_rsip_func_sub001(0x00c00049U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000200U, 0x09090009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001b0U, 0x09090009U);

            r_rsip_func_sub003(0x800103a0U, 0x0000004fU);

            static const uint32_t Param_p4f_func101_007[] =
            {
                BSWAP_32BIG_C(0xf166da1fU), BSWAP_32BIG_C(0x19b64510U), BSWAP_32BIG_C(0xcabe011bU), BSWAP_32BIG_C(
                    0x671a73fcU),
            };
            r_rsip_func101(Param_p4f_func101_007);
            r_rsip_func091();

            static const uint32_t Param_p4f_func100_007[] =
            {
                BSWAP_32BIG_C(0x0da6054fU), BSWAP_32BIG_C(0x457456b9U), BSWAP_32BIG_C(0x29c3775eU), BSWAP_32BIG_C(
                    0xd6bde236U),
            };
            r_rsip_func100(Param_p4f_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p4f_func102_005[] =
                {
                    BSWAP_32BIG_C(0x2c76bdd7U), BSWAP_32BIG_C(0x037f2397U), BSWAP_32BIG_C(0x6750b1e3U), BSWAP_32BIG_C(
                        0xde740239U),
                };
                r_rsip_func102(Param_p4f_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x800103a0U, 0x0000004fU);

                static const uint32_t Param_p4f_func101_008[] =
                {
                    BSWAP_32BIG_C(0xb3777504U), BSWAP_32BIG_C(0x05c822b0U), BSWAP_32BIG_C(0xd14d3841U), BSWAP_32BIG_C(
                        0x48286b73U),
                };
                r_rsip_func101(Param_p4f_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x800103a0U, 0x00004f03U);

                static const uint32_t Param_p4f_func101_009[] =
                {
                    BSWAP_32BIG_C(0x6cb39292U), BSWAP_32BIG_C(0x26590065U), BSWAP_32BIG_C(0x66cdd0ceU), BSWAP_32BIG_C(
                        0x585463abU),
                };
                r_rsip_func101(Param_p4f_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01ea2366U);

                r_rsip_func_sub003(0x800103a0U, 0x00004f03U);

                static const uint32_t Param_p4f_func101_010[] =
                {
                    BSWAP_32BIG_C(0x2c37a5d9U), BSWAP_32BIG_C(0x6cf3c189U), BSWAP_32BIG_C(0x5dc7ad3cU), BSWAP_32BIG_C(
                        0xfb7d033bU),
                };
                r_rsip_func101(Param_p4f_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p4f_func100_008[] =
                {
                    BSWAP_32BIG_C(0x72da56e2U), BSWAP_32BIG_C(0x771acd6bU), BSWAP_32BIG_C(0x15f67c9aU), BSWAP_32BIG_C(
                        0x7d9ba59fU),
                };
                r_rsip_func100(Param_p4f_func100_008);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12580000U);
                r_rsip_func_sub001(0x00800009U);
                r_rsip_func_sub001(0x00830029U);

                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0U; iLoop < 12U; )
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 1]);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p4f_func100_009[] =
                {
                    BSWAP_32BIG_C(0xb9eddd84U), BSWAP_32BIG_C(0x163dabacU), BSWAP_32BIG_C(0xe4de49ffU), BSWAP_32BIG_C(
                        0xcdcb02b1U),
                };
                r_rsip_func100(Param_p4f_func100_009);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7008d07U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                static const uint32_t Param_p4f_func100_010[] =
                {
                    BSWAP_32BIG_C(0x222b2b9cU), BSWAP_32BIG_C(0x35a66401U), BSWAP_32BIG_C(0xb47dcac4U), BSWAP_32BIG_C(
                        0xd618e601U),
                };
                r_rsip_func100(Param_p4f_func100_010);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 9]);

                static const uint32_t Param_p4f_func100_011[] =
                {
                    BSWAP_32BIG_C(0x82f304ceU), BSWAP_32BIG_C(0x47e842c8U), BSWAP_32BIG_C(0xaf286571U), BSWAP_32BIG_C(
                        0x0e5c267cU),
                };
                r_rsip_func100(Param_p4f_func100_011);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p4f_func102_006[] =
                {
                    BSWAP_32BIG_C(0xa77dc41fU), BSWAP_32BIG_C(0x04cfb7fdU), BSWAP_32BIG_C(0xd4496b51U), BSWAP_32BIG_C(
                        0x2254abc1U),
                };
                r_rsip_func102(Param_p4f_func102_006);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
