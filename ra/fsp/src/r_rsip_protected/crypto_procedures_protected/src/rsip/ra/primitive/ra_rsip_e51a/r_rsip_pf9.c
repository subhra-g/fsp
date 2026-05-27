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

rsip_ret_t r_rsip_pf9 (const uint32_t InData_CurveType[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00f90001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pf9_func100_001[] =
    {
        BSWAP_32BIG_C(0xff1cb4a9U), BSWAP_32BIG_C(0x3a72a3d1U), BSWAP_32BIG_C(0x148e98fdU), BSWAP_32BIG_C(0x258420dbU),
    };
    r_rsip_func100(Param_pf9_func100_001);
    r_rsip_func027(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    WR1_PROG(REG_1404H, 0x12b80000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f901U);

    static const uint32_t Param_pf9_func101_001[] =
    {
        BSWAP_32BIG_C(0xd5fe9314U), BSWAP_32BIG_C(0x94a047e3U), BSWAP_32BIG_C(0xe641d3fdU), BSWAP_32BIG_C(0x116f2551U),
    };
    r_rsip_func101(Param_pf9_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f902U);

    static const uint32_t Param_pf9_func101_002[] =
    {
        BSWAP_32BIG_C(0xdd32083dU), BSWAP_32BIG_C(0x62c88b01U), BSWAP_32BIG_C(0xcb6dae93U), BSWAP_32BIG_C(0x06a15576U),
    };
    r_rsip_func101(Param_pf9_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f903U);

    static const uint32_t Param_pf9_func101_003[] =
    {
        BSWAP_32BIG_C(0xd1316202U), BSWAP_32BIG_C(0x78be438fU), BSWAP_32BIG_C(0x93752d0fU), BSWAP_32BIG_C(0xbc026a68U),
    };
    r_rsip_func101(Param_pf9_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f904U);

    static const uint32_t Param_pf9_func101_004[] =
    {
        BSWAP_32BIG_C(0xd3d50aa5U), BSWAP_32BIG_C(0x45154693U), BSWAP_32BIG_C(0x2bb870ebU), BSWAP_32BIG_C(0x81ec6964U),
    };
    r_rsip_func101(Param_pf9_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0606000aU);

    WR1_PROG(REG_1404H, 0x11280000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x06060007U);

    static const uint32_t Param_pf9_func100_002[] =
    {
        BSWAP_32BIG_C(0x26a38baaU), BSWAP_32BIG_C(0x6ab83ec9U), BSWAP_32BIG_C(0x4dd0ad12U), BSWAP_32BIG_C(0xdd25c61eU),
    };
    r_rsip_func100(Param_pf9_func100_002);
    r_rsip_func_sub025(0x00000800U, 0x00000821U, 0x00000863U);

    WR1_PROG(REG_1404H, 0x12180000U);
    WR1_PROG(REG_1608H, 0x808e0001U);
    r_rsip_func_sub001(0x03430039U);

    for (iLoop = 0U; iLoop < 14U; iLoop++)
    {
        r_rsip_func_sub024(0x38000c63U, 0x20000842U, 0x10003841U, 0x0000b7c0U);
        WR1_PROG(REG_1600H, 0x0000001fU);

        for (jLoop = 0U; jLoop < 32U; jLoop++)
        {
            r_rsip_func_sub024(0x3800585eU, 0x20003460U, 0x20002c60U, 0x10002c00U);
            WR1_PROG(REG_1600H, 0x100033c0U);
        }

        r_rsip_func_sub039(0x0000a420U, 0x00000004U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x14480000U);
    r_rsip_func_sub001(0x00c00039U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);

    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00035U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x07070007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_pf9_func101_005[] =
        {
            BSWAP_32BIG_C(0x727d92d1U), BSWAP_32BIG_C(0x6341c753U), BSWAP_32BIG_C(0x4ba8731aU), BSWAP_32BIG_C(
                0xdcbf778fU),
        };
        r_rsip_func101(Param_pf9_func101_005);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_func_sub001(0x00c00039U);

    static const uint32_t Param_pf9_func100_003[] =
    {
        BSWAP_32BIG_C(0x5e729a0dU), BSWAP_32BIG_C(0x95a9dcfeU), BSWAP_32BIG_C(0x96edb86aU), BSWAP_32BIG_C(0x72bb9e88U),
    };
    r_rsip_func100(Param_pf9_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0707000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_pf9_func100_004[] =
        {
            BSWAP_32BIG_C(0x7012ccb7U), BSWAP_32BIG_C(0x8d630a74U), BSWAP_32BIG_C(0xba68cc1aU), BSWAP_32BIG_C(
                0x7996aec5U),
        };
        r_rsip_func100(Param_pf9_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x07070009U);

            static const uint32_t Param_pf9_func101_006[] =
            {
                BSWAP_32BIG_C(0xbe91ece6U), BSWAP_32BIG_C(0x75567f84U), BSWAP_32BIG_C(0x64c49cfeU), BSWAP_32BIG_C(
                    0x33a91e00U),
            };
            r_rsip_func101(Param_pf9_func101_006);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0707000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_pf9_func101_007[] =
        {
            BSWAP_32BIG_C(0x1909bd64U), BSWAP_32BIG_C(0x70126e51U), BSWAP_32BIG_C(0xa4c004f8U), BSWAP_32BIG_C(
                0x7520a026U),
        };
        r_rsip_func101(Param_pf9_func101_007);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x06060009U);

    static const uint32_t Param_pf9_func100_005[] =
    {
        BSWAP_32BIG_C(0x958e6bc4U), BSWAP_32BIG_C(0xdb6e4126U), BSWAP_32BIG_C(0xc295359bU), BSWAP_32BIG_C(0xfb5b92b1U),
    };
    r_rsip_func100(Param_pf9_func100_005);
    r_rsip_func028(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f9U);

    static const uint32_t Param_pf9_func101_008[] =
    {
        BSWAP_32BIG_C(0x9ec5d94bU), BSWAP_32BIG_C(0x522d9a32U), BSWAP_32BIG_C(0x40b9e2a7U), BSWAP_32BIG_C(0xb7336aebU),
    };
    r_rsip_func101(Param_pf9_func101_008);
    r_rsip_func089();

    static const uint32_t Param_pf9_func100_006[] =
    {
        BSWAP_32BIG_C(0xa3c3b359U), BSWAP_32BIG_C(0x41849722U), BSWAP_32BIG_C(0x917fe07eU), BSWAP_32BIG_C(0x363f374dU),
    };
    r_rsip_func100(Param_pf9_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf9_func102_001[] =
        {
            BSWAP_32BIG_C(0xe303feeaU), BSWAP_32BIG_C(0x0421fe89U), BSWAP_32BIG_C(0x0d312d05U), BSWAP_32BIG_C(
                0x99ddada3U),
        };
        r_rsip_func102(Param_pf9_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f905U);

        static const uint32_t Param_pf9_func101_009[] =
        {
            BSWAP_32BIG_C(0xcc169e7aU), BSWAP_32BIG_C(0x2d4e2a97U), BSWAP_32BIG_C(0x6e040cffU), BSWAP_32BIG_C(
                0x180361b4U),
        };
        r_rsip_func101(Param_pf9_func101_009);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f9U);

        static const uint32_t Param_pf9_func101_010[] =
        {
            BSWAP_32BIG_C(0xdd749240U), BSWAP_32BIG_C(0xb67e2bcfU), BSWAP_32BIG_C(0x8bd14cccU), BSWAP_32BIG_C(
                0xb30c1609U),
        };
        r_rsip_func101(Param_pf9_func101_010);
        r_rsip_func043();

        r_rsip_func076();

        WR1_PROG(REG_1600H, 0x000034feU);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f9U);

        static const uint32_t Param_pf9_func101_011[] =
        {
            BSWAP_32BIG_C(0x412524d2U), BSWAP_32BIG_C(0xaef55453U), BSWAP_32BIG_C(0x352c5a90U), BSWAP_32BIG_C(
                0x0b86b1f8U),
        };
        r_rsip_func101(Param_pf9_func101_011);
        r_rsip_func044();

        static const uint32_t Param_pf9_func100_007[] =
        {
            BSWAP_32BIG_C(0xe55c29cfU), BSWAP_32BIG_C(0xaebb0977U), BSWAP_32BIG_C(0x356fa0a9U), BSWAP_32BIG_C(
                0x87571be2U),
        };
        r_rsip_func100(Param_pf9_func100_007);
        r_rsip_func_sub040(0x40000200U, 0xe7009d07U, 0x13100000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

        static const uint32_t Param_pf9_func100_008[] =
        {
            BSWAP_32BIG_C(0xac63472eU), BSWAP_32BIG_C(0xd50ed40cU), BSWAP_32BIG_C(0xad0e6b30U), BSWAP_32BIG_C(
                0x99a34fb8U),
        };
        r_rsip_func100(Param_pf9_func100_008);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);

        static const uint32_t Param_pf9_func100_009[] =
        {
            BSWAP_32BIG_C(0x63338a5fU), BSWAP_32BIG_C(0xf9251a31U), BSWAP_32BIG_C(0x5e98a340U), BSWAP_32BIG_C(
                0xe7192e73U),
        };
        r_rsip_func100(Param_pf9_func100_009);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f906U);

        static const uint32_t Param_pf9_func101_012[] =
        {
            BSWAP_32BIG_C(0xc221b2a4U), BSWAP_32BIG_C(0x092a763dU), BSWAP_32BIG_C(0xe85a297dU), BSWAP_32BIG_C(
                0xce9f4440U),
        };
        r_rsip_func101(Param_pf9_func101_012);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000027U);

        static const uint32_t Param_pf9_func101_013[] =
        {
            BSWAP_32BIG_C(0x4bf8303eU), BSWAP_32BIG_C(0x186fec56U), BSWAP_32BIG_C(0x328066f9U), BSWAP_32BIG_C(
                0xb7d73264U),
        };
        r_rsip_func101(Param_pf9_func101_013);
        r_rsip_func043();

        r_rsip_func077();

        WR1_PROG(REG_1600H, 0x000034feU);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000028U);

        static const uint32_t Param_pf9_func101_014[] =
        {
            BSWAP_32BIG_C(0xda80c124U), BSWAP_32BIG_C(0xcf1c9722U), BSWAP_32BIG_C(0x63acc1c0U), BSWAP_32BIG_C(
                0xe2a50a9bU),
        };
        r_rsip_func101(Param_pf9_func101_014);
        r_rsip_func044();

        static const uint32_t Param_pf9_func100_010[] =
        {
            BSWAP_32BIG_C(0x6b19d285U), BSWAP_32BIG_C(0x7c95c1a6U), BSWAP_32BIG_C(0x127178c2U), BSWAP_32BIG_C(
                0x96c67df2U),
        };
        r_rsip_func100(Param_pf9_func100_010);
        r_rsip_func_sub040(0x40000200U, 0xe8009107U, 0x12700000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

        static const uint32_t Param_pf9_func100_011[] =
        {
            BSWAP_32BIG_C(0xa3935396U), BSWAP_32BIG_C(0x6b46fe89U), BSWAP_32BIG_C(0x9c0cdf7cU), BSWAP_32BIG_C(
                0xf49096f8U),
        };
        r_rsip_func100(Param_pf9_func100_011);
        r_rsip_func_sub040(0x40000200U, 0xe8008107U, 0x12c00000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[21]);

        static const uint32_t Param_pf9_func100_012[] =
        {
            BSWAP_32BIG_C(0x06ad8123U), BSWAP_32BIG_C(0x5cf6f22dU), BSWAP_32BIG_C(0x05ad5747U), BSWAP_32BIG_C(
                0x77c01826U),
        };
        r_rsip_func100(Param_pf9_func100_012);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[25]);

        static const uint32_t Param_pf9_func100_013[] =
        {
            BSWAP_32BIG_C(0x0acae8ceU), BSWAP_32BIG_C(0x72937d21U), BSWAP_32BIG_C(0x0baf6b18U), BSWAP_32BIG_C(
                0xb37ef9fdU),
        };
        r_rsip_func100(Param_pf9_func100_013);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_pf9_func102_002[] =
        {
            BSWAP_32BIG_C(0xc6255c83U), BSWAP_32BIG_C(0xdfb7c330U), BSWAP_32BIG_C(0x459ec868U), BSWAP_32BIG_C(
                0x878913dbU),
        };
        r_rsip_func102(Param_pf9_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
