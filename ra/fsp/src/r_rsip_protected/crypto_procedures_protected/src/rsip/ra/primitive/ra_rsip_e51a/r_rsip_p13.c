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

rsip_ret_t r_rsip_p13 (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00130001U, 0x000007f0U);

    static const uint32_t Param_p13_func100_001[] =
    {
        BSWAP_32BIG_C(0xb6ac2fc2U), BSWAP_32BIG_C(0x821a6020U), BSWAP_32BIG_C(0x62c94bcaU), BSWAP_32BIG_C(0x94794e29U),
    };
    r_rsip_func100(Param_p13_func100_001);
    r_rsip_func086(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    WR1_PROG(REG_1404H, 0x12a00000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001301U);

    static const uint32_t Param_p13_func101_001[] =
    {
        BSWAP_32BIG_C(0x35838fe1U), BSWAP_32BIG_C(0x103cef5eU), BSWAP_32BIG_C(0x7375246bU), BSWAP_32BIG_C(0x60ece265U),
    };
    r_rsip_func101(Param_p13_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80020000U);
    r_rsip_func_sub001(0x03420009U);
    r_rsip_func_sub025(0x00000800U, 0x00008c20U, 0x000001ffU);
    WR1_PROG(REG_1608H, 0x81020000U);
    r_rsip_func_sub001(0x00c90009U);
    r_rsip_func_sub001(0x00c20009U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001302U);

    static const uint32_t Param_p13_func101_002[] =
    {
        BSWAP_32BIG_C(0x41fe8407U), BSWAP_32BIG_C(0xa459806eU), BSWAP_32BIG_C(0x48dbc8e8U), BSWAP_32BIG_C(0xb91bc9daU),
    };
    r_rsip_func101(Param_p13_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001303U);

    static const uint32_t Param_p13_func101_003[] =
    {
        BSWAP_32BIG_C(0x995b2ec8U), BSWAP_32BIG_C(0x118783e6U), BSWAP_32BIG_C(0xb05c8347U), BSWAP_32BIG_C(0xb29aee6fU),
    };
    r_rsip_func101(Param_p13_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001304U);

    static const uint32_t Param_p13_func101_004[] =
    {
        BSWAP_32BIG_C(0x841181daU), BSWAP_32BIG_C(0x2c2a5c53U), BSWAP_32BIG_C(0x14653399U), BSWAP_32BIG_C(0xfeca4ad2U),
    };
    r_rsip_func101(Param_p13_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001305U);

    static const uint32_t Param_p13_func101_005[] =
    {
        BSWAP_32BIG_C(0x14baa3d6U), BSWAP_32BIG_C(0x38dcf89eU), BSWAP_32BIG_C(0x938d41b4U), BSWAP_32BIG_C(0x66ac5ae6U),
    };
    r_rsip_func101(Param_p13_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0909000aU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x09090007U);

    static const uint32_t Param_p13_func100_002[] =
    {
        BSWAP_32BIG_C(0xabf54acfU), BSWAP_32BIG_C(0x46abdd67U), BSWAP_32BIG_C(0x0f372209U), BSWAP_32BIG_C(0x07ab1c62U),
    };
    r_rsip_func100(Param_p13_func100_002);
    r_rsip_func_sub025(0x00000800U, 0x00000821U, 0x00000863U);

    WR1_PROG(REG_1404H, 0x12000000U);
    WR1_PROG(REG_1608H, 0x80940001U);
    r_rsip_func_sub001(0x03430051U);

    for (iLoop = 0U; iLoop < 20; iLoop++)
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

    WR1_PROG(REG_1404H, 0x14300000U);
    r_rsip_func_sub001(0x00c00051U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);

    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0004dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x0a0a0007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_p13_func101_006[] =
        {
            BSWAP_32BIG_C(0xd635d65cU), BSWAP_32BIG_C(0x67532c5eU), BSWAP_32BIG_C(0x3b7bd1b9U), BSWAP_32BIG_C(
                0xdaf75c54U),
        };
        r_rsip_func101(Param_p13_func101_006);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_func_sub001(0x00c00051U);

    static const uint32_t Param_p13_func100_003[] =
    {
        BSWAP_32BIG_C(0x3eea1a57U), BSWAP_32BIG_C(0xfe2ed5e6U), BSWAP_32BIG_C(0x03ef4f3aU), BSWAP_32BIG_C(0x765e56f6U),
    };
    r_rsip_func100(Param_p13_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0a0a000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_p13_func100_004[] =
        {
            BSWAP_32BIG_C(0xfe09dc90U), BSWAP_32BIG_C(0x0d330977U), BSWAP_32BIG_C(0x9a652222U), BSWAP_32BIG_C(
                0x5bd1dacfU),
        };
        r_rsip_func100(Param_p13_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x0a0a0009U);

            static const uint32_t Param_p13_func101_007[] =
            {
                BSWAP_32BIG_C(0x2651107fU), BSWAP_32BIG_C(0x9538ee48U), BSWAP_32BIG_C(0xb8d0f034U), BSWAP_32BIG_C(
                    0xa86f7909U),
            };
            r_rsip_func101(Param_p13_func101_007);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0a0a000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x0a0a0009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_p13_func101_008[] =
        {
            BSWAP_32BIG_C(0x29a50128U), BSWAP_32BIG_C(0xf92aa3daU), BSWAP_32BIG_C(0xaca38e16U), BSWAP_32BIG_C(
                0x0370bef8U),
        };
        r_rsip_func101(Param_p13_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x09090009U);

    static const uint32_t Param_p13_func100_005[] =
    {
        BSWAP_32BIG_C(0x54979f37U), BSWAP_32BIG_C(0x59294fc2U), BSWAP_32BIG_C(0x17426697U), BSWAP_32BIG_C(0xefff9c9bU),
    };
    r_rsip_func100(Param_p13_func100_005);

    r_rsip_func087(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000013U);

    static const uint32_t Param_p13_func101_009[] =
    {
        BSWAP_32BIG_C(0x08482350U), BSWAP_32BIG_C(0x8d75130aU), BSWAP_32BIG_C(0xebca15b4U), BSWAP_32BIG_C(0xd0977999U),
    };
    r_rsip_func101(Param_p13_func101_009);
    r_rsip_func091();

    static const uint32_t Param_p13_func100_006[] =
    {
        BSWAP_32BIG_C(0x3efec19eU), BSWAP_32BIG_C(0x738bd53cU), BSWAP_32BIG_C(0xb6a78e5eU), BSWAP_32BIG_C(0xeadd4494U),
    };
    r_rsip_func100(Param_p13_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p13_func102_001[] =
        {
            BSWAP_32BIG_C(0x8d8dfec1U), BSWAP_32BIG_C(0x1a915238U), BSWAP_32BIG_C(0x5d452ea3U), BSWAP_32BIG_C(
                0xfbcacb5cU),
        };
        r_rsip_func102(Param_p13_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001306U);

        static const uint32_t Param_p13_func101_010[] =
        {
            BSWAP_32BIG_C(0xcc7c27bbU), BSWAP_32BIG_C(0xb67aaef3U), BSWAP_32BIG_C(0xcc9ea67aU), BSWAP_32BIG_C(
                0x1b725192U),
        };
        r_rsip_func101(Param_p13_func101_010);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000013U);

        static const uint32_t Param_p13_func101_011[] =
        {
            BSWAP_32BIG_C(0xdaa8deeeU), BSWAP_32BIG_C(0xead064cfU), BSWAP_32BIG_C(0x376e15d4U), BSWAP_32BIG_C(
                0x1844d095U),
        };
        r_rsip_func101(Param_p13_func101_011);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000025U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000013U);

        static const uint32_t Param_p13_func101_012[] =
        {
            BSWAP_32BIG_C(0x9873b624U), BSWAP_32BIG_C(0x24e56d0aU), BSWAP_32BIG_C(0x1b00b720U), BSWAP_32BIG_C(
                0x87ad72adU),
        };
        r_rsip_func101(Param_p13_func101_012);
        r_rsip_func044();

        static const uint32_t Param_p13_func100_007[] =
        {
            BSWAP_32BIG_C(0x1820a720U), BSWAP_32BIG_C(0x7d084caeU), BSWAP_32BIG_C(0x4d2bf6b9U), BSWAP_32BIG_C(
                0x4e126983U),
        };
        r_rsip_func100(Param_p13_func100_007);
        r_rsip_func_sub040(0x40000200U, 0xe7009d07U, 0x12f80000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830029U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_008[] =
        {
            BSWAP_32BIG_C(0x6152a981U), BSWAP_32BIG_C(0x95a8146bU), BSWAP_32BIG_C(0xecfa4a95U), BSWAP_32BIG_C(
                0x4d14cbcfU),
        };
        r_rsip_func100(Param_p13_func100_008);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);

        static const uint32_t Param_p13_func100_009[] =
        {
            BSWAP_32BIG_C(0x52a7bd0aU), BSWAP_32BIG_C(0x2be5b62bU), BSWAP_32BIG_C(0x7f821862U), BSWAP_32BIG_C(
                0x4e23fd78U),
        };
        r_rsip_func100(Param_p13_func100_009);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 9]);

        static const uint32_t Param_p13_func100_010[] =
        {
            BSWAP_32BIG_C(0x03e61202U), BSWAP_32BIG_C(0x0e47778fU), BSWAP_32BIG_C(0xc76af654U), BSWAP_32BIG_C(
                0xf4e0d488U),
        };
        r_rsip_func100(Param_p13_func100_010);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001307U);

        static const uint32_t Param_p13_func101_013[] =
        {
            BSWAP_32BIG_C(0xc265a524U), BSWAP_32BIG_C(0xdceed181U), BSWAP_32BIG_C(0xf1fca866U), BSWAP_32BIG_C(
                0x92a0ab4eU),
        };
        r_rsip_func101(Param_p13_func101_013);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000113U);

        static const uint32_t Param_p13_func101_014[] =
        {
            BSWAP_32BIG_C(0xa8515017U), BSWAP_32BIG_C(0x594e2992U), BSWAP_32BIG_C(0xd0b04b99U), BSWAP_32BIG_C(
                0x3489de20U),
        };
        r_rsip_func101(Param_p13_func101_014);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000024U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000113U);

        static const uint32_t Param_p13_func101_015[] =
        {
            BSWAP_32BIG_C(0xcb172c2fU), BSWAP_32BIG_C(0x21e50dddU), BSWAP_32BIG_C(0xc9948a94U), BSWAP_32BIG_C(
                0xc3dfba9aU),
        };
        r_rsip_func101(Param_p13_func101_015);
        r_rsip_func044();

        static const uint32_t Param_p13_func100_011[] =
        {
            BSWAP_32BIG_C(0xc68a5edfU), BSWAP_32BIG_C(0x759be082U), BSWAP_32BIG_C(0x26cd6a97U), BSWAP_32BIG_C(
                0x047cf198U),
        };
        r_rsip_func100(Param_p13_func100_011);
        r_rsip_func_sub040(0x40000200U, 0xe8009107U, 0x12580000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830029U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_012[] =
        {
            BSWAP_32BIG_C(0x0a82ed80U), BSWAP_32BIG_C(0x88455583U), BSWAP_32BIG_C(0x2d3d92a0U), BSWAP_32BIG_C(
                0x3642aa28U),
        };
        r_rsip_func100(Param_p13_func100_012);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830021U);
        WR1_PROG(REG_1404H, 0x12a80000U);
        r_rsip_func_sub001(0x00800009U);
        r_rsip_func_sub001(0x00830009U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_013[] =
        {
            BSWAP_32BIG_C(0x9aaf09beU), BSWAP_32BIG_C(0x6238ebbeU), BSWAP_32BIG_C(0x0d008d72U), BSWAP_32BIG_C(
                0x34bed910U),
        };
        r_rsip_func100(Param_p13_func100_013);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 24; iLoop < 36; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p13_func100_014[] =
        {
            BSWAP_32BIG_C(0x39ee005fU), BSWAP_32BIG_C(0x627a4c10U), BSWAP_32BIG_C(0x51524826U), BSWAP_32BIG_C(
                0xffdedcc6U),
        };
        r_rsip_func100(Param_p13_func100_014);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);

        static const uint32_t Param_p13_func100_015[] =
        {
            BSWAP_32BIG_C(0xc9564f47U), BSWAP_32BIG_C(0xdc24f36fU), BSWAP_32BIG_C(0x90007a7fU), BSWAP_32BIG_C(
                0xff0e895fU),
        };
        r_rsip_func100(Param_p13_func100_015);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);

        static const uint32_t Param_p13_func100_016[] =
        {
            BSWAP_32BIG_C(0x824d504aU), BSWAP_32BIG_C(0x092c0620U), BSWAP_32BIG_C(0xbd3afb05U), BSWAP_32BIG_C(
                0x9645ca6dU),
        };
        r_rsip_func100(Param_p13_func100_016);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_p13_func102_002[] =
        {
            BSWAP_32BIG_C(0x8f74ea7dU), BSWAP_32BIG_C(0xbf758be2U), BSWAP_32BIG_C(0x3829a63cU), BSWAP_32BIG_C(
                0x3eea288dU),
        };
        r_rsip_func102(Param_p13_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
