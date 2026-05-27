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

rsip_ret_t r_rsip_pf6 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00f60001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f6U);

    static const uint32_t Param_pf6_func101_001[] =
    {
        BSWAP_32BIG_C(0xbbc2583fU), BSWAP_32BIG_C(0x0b77e50aU), BSWAP_32BIG_C(0x47376bcbU), BSWAP_32BIG_C(0xe796333bU),
    };
    r_rsip_func101(Param_pf6_func101_001);
    r_rsip_func043();

    r_rsip_func077();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f6U);

    static const uint32_t Param_pf6_func101_002[] =
    {
        BSWAP_32BIG_C(0xe0fcd2bdU), BSWAP_32BIG_C(0x5dff2296U), BSWAP_32BIG_C(0xc7b73718U), BSWAP_32BIG_C(0x9c0d7097U),
    };
    r_rsip_func101(Param_pf6_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x000017c2U, 0x40000500U, 0xe8009107U);

    r_rsip_func_sub026(0x0000b420U, 0x00000060U, 0x80980001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    r_rsip_func_sub001(0x03420031U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[21]);
    r_rsip_func_sub001(0x03420031U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[25]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pf6_func100_001[] =
    {
        BSWAP_32BIG_C(0xdd4d4326U), BSWAP_32BIG_C(0xecc32e1bU), BSWAP_32BIG_C(0x678374c8U), BSWAP_32BIG_C(0xbeb6c400U),
    };
    r_rsip_func100(Param_pf6_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf6_func102_001[] =
        {
            BSWAP_32BIG_C(0x004ac751U), BSWAP_32BIG_C(0x1eb6ba0aU), BSWAP_32BIG_C(0xfd56ee83U), BSWAP_32BIG_C(
                0x84dcb049U),
        };
        r_rsip_func102(Param_pf6_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x808c001fU);
        for (iLoop = 0U; iLoop < 12U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x80010360U, 0x000000f6U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_pf6_func100_002[] =
        {
            BSWAP_32BIG_C(0x7b32a97eU), BSWAP_32BIG_C(0xe8f46b19U), BSWAP_32BIG_C(0x61547683U), BSWAP_32BIG_C(
                0x3e1a957bU),
        };
        r_rsip_func100(Param_pf6_func100_002);
        r_rsip_func027(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

        WR1_PROG(REG_1404H, 0x19000000U);
        r_rsip_func_sub008(0x000017c2U, 0x00000500U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x19500000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        r_rsip_func_sub001(0x00c20031U);

        WR1_PROG(REG_1404H, 0x11d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0606000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pf6_func100_003[] =
        {
            BSWAP_32BIG_C(0xd0702932U), BSWAP_32BIG_C(0x67ebeff0U), BSWAP_32BIG_C(0xd9a33228U), BSWAP_32BIG_C(
                0xf8cfc189U),
        };
        r_rsip_func100(Param_pf6_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_pf6_func101_003[] =
            {
                BSWAP_32BIG_C(0xaae76fecU), BSWAP_32BIG_C(0xddbd1d83U), BSWAP_32BIG_C(0x58986dacU), BSWAP_32BIG_C(
                    0x3724e93bU),
            };
            r_rsip_func101(Param_pf6_func101_003);
        }
        else
        {
            static const uint32_t Param_pf6_func100_004[] =
            {
                BSWAP_32BIG_C(0x302f4ccfU), BSWAP_32BIG_C(0x369a3af5U), BSWAP_32BIG_C(0x959cb153U), BSWAP_32BIG_C(
                    0x4632d664U),
            };
            r_rsip_func100(Param_pf6_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0606000aU);

            r_rsip_func_sub022(0x00000980U, 0x000001b0U, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);

            r_rsip_func_sub037(0x0606000fU, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub033(0x10e00000U, 0x00000bffU, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x06060002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub001(0x00c00031U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x06060004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002b8U, 0x06060009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x06060009U);

            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1608H, 0x818c0001U);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a00U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10e00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            r_rsip_func_sub001(0x00c90031U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a38U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_pf6_func100_005[] =
            {
                BSWAP_32BIG_C(0xc0401041U), BSWAP_32BIG_C(0x8a4ba88bU), BSWAP_32BIG_C(0x6d3c7918U), BSWAP_32BIG_C(
                    0x4fb8407fU),
            };
            r_rsip_func100(Param_pf6_func100_005);
            r_rsip_func028(InData_DomainParam);

            r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000af0U, 0x06060009U);

            r_rsip_func_sub002(0x00000218U, 0x00000160U, 0x00000b28U, 0x06060009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x06060009U);

            r_rsip_func_sub002(0x00000af0U, 0x00000a00U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a00U, 0x00000af0U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b28U, 0x00000a38U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a38U, 0x00000b28U, 0x00000110U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf6_func100_006[] =
            {
                BSWAP_32BIG_C(0xdc151ea5U), BSWAP_32BIG_C(0x190d8560U), BSWAP_32BIG_C(0x936bb66fU), BSWAP_32BIG_C(
                    0x3766db0aU),
            };
            r_rsip_func100(Param_pf6_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x06060013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_pf6_func101_004[] =
                {
                    BSWAP_32BIG_C(0xf1fe4625U), BSWAP_32BIG_C(0xbc007e74U), BSWAP_32BIG_C(0x19fd1bfdU), BSWAP_32BIG_C(
                        0xdd83e8c3U),
                };
                r_rsip_func101(Param_pf6_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x06060014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_pf6_func101_005[] =
                {
                    BSWAP_32BIG_C(0x245a8d17U), BSWAP_32BIG_C(0x8ae1d93fU), BSWAP_32BIG_C(0x55ff9c00U), BSWAP_32BIG_C(
                        0x2dde1392U),
                };
                r_rsip_func101(Param_pf6_func101_005);
            }

            r_rsip_func_sub044(0x00000821U, 0x14500000U, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            r_rsip_func_sub034(0x0000a420U, 0x00000050U, 0x13100000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            r_rsip_func_sub001(0x03430031U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 12U; iLoop++)
            {
                r_rsip_func_sub024(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub025(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub024(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0002dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_pf6_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x78488daeU), BSWAP_32BIG_C(0xa33ce35aU), BSWAP_32BIG_C(0x9c7e3896U),
                        BSWAP_32BIG_C(0xcf165b32U),
                    };
                    r_rsip_func100(Param_pf6_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_pf6_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x5904743eU), BSWAP_32BIG_C(0xc53b5d4aU), BSWAP_32BIG_C(0x28eeaf58U),
                            BSWAP_32BIG_C(0x11663c56U),
                        };
                        r_rsip_func101(Param_pf6_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_pf6_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x1eb9f769U), BSWAP_32BIG_C(0xb418bd5dU), BSWAP_32BIG_C(0x5dd5ea57U),
                            BSWAP_32BIG_C(0x3b5b332cU),
                        };
                        r_rsip_func101(Param_pf6_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_pf6_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x2d76c0acU), BSWAP_32BIG_C(0x7618c9fcU), BSWAP_32BIG_C(0x2d91762eU),
                        BSWAP_32BIG_C(0x85d4f3c9U),
                    };
                    r_rsip_func100(Param_pf6_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pf6_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x458705ccU), BSWAP_32BIG_C(0xe267b315U), BSWAP_32BIG_C(0xb4015c58U),
                            BSWAP_32BIG_C(0x958400bcU),
                        };
                        r_rsip_func100(Param_pf6_func100_009);

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub001(0x00c00031U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x00000a00U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a38U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x17b5d499U), BSWAP_32BIG_C(0xfac09d37U), BSWAP_32BIG_C(0x19e9bfdeU),
                                BSWAP_32BIG_C(0x5952342aU),
                            };
                            r_rsip_func101(Param_pf6_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000af0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b28U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xc0042aa1U), BSWAP_32BIG_C(0xdd9fb291U), BSWAP_32BIG_C(0xa275e87dU),
                                BSWAP_32BIG_C(0xebec268dU),
                            };
                            r_rsip_func101(Param_pf6_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000be0U, 0x00000160U, 0x00000410U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c18U, 0x00000160U, 0x00000448U, 0x06060009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x307ebf99U), BSWAP_32BIG_C(0xcd78573eU), BSWAP_32BIG_C(0x698afb3eU),
                                BSWAP_32BIG_C(0x0ed028cfU),
                            };
                            r_rsip_func101(Param_pf6_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c0002dU);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_pf6_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x6a073adaU), BSWAP_32BIG_C(0x43a0cfadU), BSWAP_32BIG_C(0x32c49c78U),
                            BSWAP_32BIG_C(0xf38d2e41U),
                        };
                        r_rsip_func100(Param_pf6_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_pf6_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x17fc605aU), BSWAP_32BIG_C(0x28a89aabU), BSWAP_32BIG_C(0x1425ac1fU),
                                BSWAP_32BIG_C(0x1fd898a5U),
                            };
                            r_rsip_func100(Param_pf6_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001e0U, 0x00000410U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000410U, 0x000001e0U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000218U, 0x00000448U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000448U, 0x00000218U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0606000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_pf6_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0xe822ea65U), BSWAP_32BIG_C(0x254610d6U), BSWAP_32BIG_C(0x93efde2eU),
                                    BSWAP_32BIG_C(0xf7f525bfU),
                                };
                                r_rsip_func100(Param_pf6_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub022(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_pf6_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x17bbf529U), BSWAP_32BIG_C(0x0c73b7caU), BSWAP_32BIG_C(
                                            0x68fceefcU),           BSWAP_32BIG_C(0xa0e4585dU),
                                    };
                                    r_rsip_func101(Param_pf6_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x06060014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_pf6_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x5c601e67U), BSWAP_32BIG_C(0xab91835bU), BSWAP_32BIG_C(
                                            0xf7500dd1U),           BSWAP_32BIG_C(0x4c0721ccU),
                                    };
                                    r_rsip_func101(Param_pf6_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_pf6_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xaea03807U), BSWAP_32BIG_C(0x49514dadU), BSWAP_32BIG_C(0xe1045737U),
                                    BSWAP_32BIG_C(0xe97504a5U),
                                };
                                r_rsip_func101(Param_pf6_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11300000U);
                            r_rsip_func_sub001(0x00c00031U);

                            r_rsip_func_sub002(0x00000410U, 0x00000160U, 0x000001e0U, 0x06060009U);

                            r_rsip_func_sub002(0x00000448U, 0x00000160U, 0x00000218U, 0x06060009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);

                            static const uint32_t Param_pf6_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xa9feff43U), BSWAP_32BIG_C(0x77d772dfU), BSWAP_32BIG_C(0xd5697b9cU),
                                BSWAP_32BIG_C(0x3dd5bec1U),
                            };
                            r_rsip_func101(Param_pf6_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_pf6_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x74f4c842U), BSWAP_32BIG_C(0x6b55e0d5U), BSWAP_32BIG_C(0x3ab7e5e0U),
                            BSWAP_32BIG_C(0x2e581b0fU),
                        };
                        r_rsip_func101(Param_pf6_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_pf6_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x58661d5cU), BSWAP_32BIG_C(0x307b56d8U), BSWAP_32BIG_C(0x3840358bU),
                        BSWAP_32BIG_C(0x951d0d3aU),
                    };
                    r_rsip_func101(Param_pf6_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_pf6_func101_017[] =
                {
                    BSWAP_32BIG_C(0x054d23b7U), BSWAP_32BIG_C(0x1a639893U), BSWAP_32BIG_C(0x52a47e89U), BSWAP_32BIG_C(
                        0x17199521U),
                };
                r_rsip_func101(Param_pf6_func101_017);
            }

            r_rsip_func_sub006(0x38008820U, 0x0000000cU, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x12700000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0606000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf6_func100_013[] =
            {
                BSWAP_32BIG_C(0xd9b9f22cU), BSWAP_32BIG_C(0xb2a5026cU), BSWAP_32BIG_C(0xffba9197U), BSWAP_32BIG_C(
                    0x02c27a15U),
            };
            r_rsip_func100(Param_pf6_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_pf6_func101_018[] =
                {
                    BSWAP_32BIG_C(0xa26c9c9cU), BSWAP_32BIG_C(0x579ded4aU), BSWAP_32BIG_C(0x13041f6eU), BSWAP_32BIG_C(
                        0xae04a268U),
                };
                r_rsip_func101(Param_pf6_func101_018);
            }
            else
            {
                static const uint32_t Param_pf6_func100_014[] =
                {
                    BSWAP_32BIG_C(0x68d243dbU), BSWAP_32BIG_C(0x81864761U), BSWAP_32BIG_C(0xd34296afU), BSWAP_32BIG_C(
                        0xca5ba0fdU),
                };
                r_rsip_func100(Param_pf6_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x000001e0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_pf6_func100_015[] =
                {
                    BSWAP_32BIG_C(0x396ab264U), BSWAP_32BIG_C(0xa4b4bcdaU), BSWAP_32BIG_C(0x33643a68U), BSWAP_32BIG_C(
                        0x549ea493U),
                };
                r_rsip_func100(Param_pf6_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_pf6_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x8b2bb26dU), BSWAP_32BIG_C(0x5de6c6ceU), BSWAP_32BIG_C(0x0fbe8043U),
                        BSWAP_32BIG_C(0x28650794U),
                    };
                    r_rsip_func101(Param_pf6_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_pf6_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x8d92baa8U), BSWAP_32BIG_C(0xfbd58e93U), BSWAP_32BIG_C(0xa600c8caU),
                        BSWAP_32BIG_C(0x22c2e085U),
                    };
                    r_rsip_func101(Param_pf6_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_pf6_func100_016[] =
        {
            BSWAP_32BIG_C(0x2dcf05ffU), BSWAP_32BIG_C(0x91e573c9U), BSWAP_32BIG_C(0xc4577fc3U), BSWAP_32BIG_C(
                0x817852c4U),
        };
        r_rsip_func100(Param_pf6_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf6_func102_002[] =
            {
                BSWAP_32BIG_C(0xdbe846a4U), BSWAP_32BIG_C(0xd29e2f19U), BSWAP_32BIG_C(0x2f3393b8U), BSWAP_32BIG_C(
                    0x0fd59554U),
            };
            r_rsip_func102(Param_pf6_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf6_func102_003[] =
            {
                BSWAP_32BIG_C(0x0c055d02U), BSWAP_32BIG_C(0x353d4708U), BSWAP_32BIG_C(0x17c65129U), BSWAP_32BIG_C(
                    0x873ebf7fU),
            };
            r_rsip_func102(Param_pf6_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
