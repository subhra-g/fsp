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

rsip_ret_t r_rsip_p7f (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x007f0001U, 0x000007f0U);

    static const uint32_t Param_p7f_func100_001[] =
    {
        BSWAP_32BIG_C(0xfe66784eU), BSWAP_32BIG_C(0x63730ef1U), BSWAP_32BIG_C(0x032320bbU), BSWAP_32BIG_C(0xd8a433dfU),
    };
    r_rsip_func100(Param_p7f_func100_001);
    r_rsip_func078(InData_DomainParam);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    WR1_PROG(REG_1404H, 0x12a80000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f01U);

    static const uint32_t Param_p7f_func101_001[] =
    {
        BSWAP_32BIG_C(0x1e449e63U), BSWAP_32BIG_C(0x76572aa1U), BSWAP_32BIG_C(0xef022fd7U), BSWAP_32BIG_C(0x28ea8f5dU),
    };
    r_rsip_func101(Param_p7f_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f02U);

    static const uint32_t Param_p7f_func101_002[] =
    {
        BSWAP_32BIG_C(0x18144922U), BSWAP_32BIG_C(0xbcc3b5e3U), BSWAP_32BIG_C(0x34a0b1a5U), BSWAP_32BIG_C(0xdcba0ed8U),
    };
    r_rsip_func101(Param_p7f_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f03U);

    static const uint32_t Param_p7f_func101_003[] =
    {
        BSWAP_32BIG_C(0x75953895U), BSWAP_32BIG_C(0x3c8fdc07U), BSWAP_32BIG_C(0x6fb72b01U), BSWAP_32BIG_C(0x5d45af39U),
    };
    r_rsip_func101(Param_p7f_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f04U);

    static const uint32_t Param_p7f_func101_004[] =
    {
        BSWAP_32BIG_C(0x5ccfe545U), BSWAP_32BIG_C(0xb3366274U), BSWAP_32BIG_C(0x15e4ece5U), BSWAP_32BIG_C(0xfe09e606U),
    };
    r_rsip_func101(Param_p7f_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f05U);

    static const uint32_t Param_p7f_func101_005[] =
    {
        BSWAP_32BIG_C(0x26c7ecfaU), BSWAP_32BIG_C(0x6ee3e568U), BSWAP_32BIG_C(0x67932456U), BSWAP_32BIG_C(0x2e309189U),
    };
    r_rsip_func101(Param_p7f_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0808000aU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub001(0x00c00009U);

    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x08080007U);

    static const uint32_t Param_p7f_func100_002[] =
    {
        BSWAP_32BIG_C(0xe16eed57U), BSWAP_32BIG_C(0x62b7998fU), BSWAP_32BIG_C(0xbde7205aU), BSWAP_32BIG_C(0xd06a7542U),
    };
    r_rsip_func100(Param_p7f_func100_002);
    r_rsip_func_sub025(0x00000800U, 0x00000821U, 0x00000863U);

    WR1_PROG(REG_1404H, 0x12080000U);
    WR1_PROG(REG_1608H, 0x80920001U);
    r_rsip_func_sub001(0x03430049U);

    for (iLoop = 0U; iLoop < 18U; iLoop++)
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

    WR1_PROG(REG_1404H, 0x14380000U);
    r_rsip_func_sub001(0x00c00049U);

    r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x00003403U);

    WR1_PROG(REG_1600H, 0x00003060U);

    r_rsip_func_sub016(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x09090007U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);

        WR1_PROG(REG_1600H, 0x00003060U);

        static const uint32_t Param_p7f_func101_006[] =
        {
            BSWAP_32BIG_C(0x30ee8d88U), BSWAP_32BIG_C(0x16979f3fU), BSWAP_32BIG_C(0x57d0d490U), BSWAP_32BIG_C(
                0xb2bcbf6cU),
        };
        r_rsip_func101(Param_p7f_func101_006);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c03U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub001(0x00c00049U);

    static const uint32_t Param_p7f_func100_003[] =
    {
        BSWAP_32BIG_C(0x4b897e49U), BSWAP_32BIG_C(0x7d1831e2U), BSWAP_32BIG_C(0x46692325U), BSWAP_32BIG_C(0x2e9c902dU),
    };
    r_rsip_func100(Param_p7f_func100_003);
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1600H, 0x00000040U);

    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        static const uint32_t Param_p7f_func100_004[] =
        {
            BSWAP_32BIG_C(0x52f593edU), BSWAP_32BIG_C(0xa2e355e5U), BSWAP_32BIG_C(0x7afc8d29U), BSWAP_32BIG_C(
                0xfbfb25b6U),
        };
        r_rsip_func100(Param_p7f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x09090009U);

            static const uint32_t Param_p7f_func101_007[] =
            {
                BSWAP_32BIG_C(0xccce46b0U), BSWAP_32BIG_C(0x50c4511aU), BSWAP_32BIG_C(0x2f62b421U), BSWAP_32BIG_C(
                    0x07fd240bU),
            };
            r_rsip_func101(Param_p7f_func101_007);
        }

        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_func_sub005(0x00000250U, 0x0909000cU, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x09090009U);
        WR1_PROG(REG_1600H, 0x00003000U);

        static const uint32_t Param_p7f_func101_008[] =
        {
            BSWAP_32BIG_C(0x17412c72U), BSWAP_32BIG_C(0x53c62442U), BSWAP_32BIG_C(0xad9b9736U), BSWAP_32BIG_C(
                0xc7bac056U),
        };
        r_rsip_func101(Param_p7f_func101_008);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x08080009U);

    static const uint32_t Param_p7f_func100_005[] =
    {
        BSWAP_32BIG_C(0xd6d26e4dU), BSWAP_32BIG_C(0x39464ad5U), BSWAP_32BIG_C(0x607ca214U), BSWAP_32BIG_C(0x9733f380U),
    };
    r_rsip_func100(Param_p7f_func100_005);

    r_rsip_func079(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007fU);

    static const uint32_t Param_p7f_func101_009[] =
    {
        BSWAP_32BIG_C(0x07a2297aU), BSWAP_32BIG_C(0x7c43aabbU), BSWAP_32BIG_C(0x04ff8982U), BSWAP_32BIG_C(0x4e7fce0bU),
    };
    r_rsip_func101(Param_p7f_func101_009);
    r_rsip_func090();

    static const uint32_t Param_p7f_func100_006[] =
    {
        BSWAP_32BIG_C(0xf1be6d53U), BSWAP_32BIG_C(0x589febacU), BSWAP_32BIG_C(0x0bbcb3feU), BSWAP_32BIG_C(0x8f71aa98U),
    };
    r_rsip_func100(Param_p7f_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7f_func102_001[] =
        {
            BSWAP_32BIG_C(0x6be6d185U), BSWAP_32BIG_C(0xc538f1ecU), BSWAP_32BIG_C(0xe40e2c30U), BSWAP_32BIG_C(
                0x1843e07dU),
        };
        r_rsip_func102(Param_p7f_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f06U);

        static const uint32_t Param_p7f_func101_010[] =
        {
            BSWAP_32BIG_C(0x88d0eb42U), BSWAP_32BIG_C(0xb8d6de00U), BSWAP_32BIG_C(0x9f28fbffU), BSWAP_32BIG_C(
                0xdc5e5d9cU),
        };
        r_rsip_func101(Param_p7f_func101_010);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007fU);

        static const uint32_t Param_p7f_func101_011[] =
        {
            BSWAP_32BIG_C(0x303476ecU), BSWAP_32BIG_C(0x0155afe6U), BSWAP_32BIG_C(0xc4d91facU), BSWAP_32BIG_C(
                0xdf52308eU),
        };
        r_rsip_func101(Param_p7f_func101_011);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000021U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007fU);

        static const uint32_t Param_p7f_func101_012[] =
        {
            BSWAP_32BIG_C(0x70e1c7feU), BSWAP_32BIG_C(0x0138322dU), BSWAP_32BIG_C(0xf398475cU), BSWAP_32BIG_C(
                0xc3fb3069U),
        };
        r_rsip_func101(Param_p7f_func101_012);
        r_rsip_func044();

        static const uint32_t Param_p7f_func100_007[] =
        {
            BSWAP_32BIG_C(0x91c80ab5U), BSWAP_32BIG_C(0x5263068aU), BSWAP_32BIG_C(0xbaddce64U), BSWAP_32BIG_C(
                0x8900e6e5U),
        };
        r_rsip_func100(Param_p7f_func100_007);
        r_rsip_func_sub040(0x40000200U, 0xe7009d07U, 0x13000000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_008[] =
        {
            BSWAP_32BIG_C(0x4109408aU), BSWAP_32BIG_C(0x587f99d3U), BSWAP_32BIG_C(0xf762c3e1U), BSWAP_32BIG_C(
                0xf7e5d027U),
        };
        r_rsip_func100(Param_p7f_func100_008);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 1]);

        static const uint32_t Param_p7f_func100_009[] =
        {
            BSWAP_32BIG_C(0x43ba6491U), BSWAP_32BIG_C(0x60811b77U), BSWAP_32BIG_C(0xadb9473bU), BSWAP_32BIG_C(
                0xb1f770efU),
        };
        r_rsip_func100(Param_p7f_func100_009);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);

        static const uint32_t Param_p7f_func100_010[] =
        {
            BSWAP_32BIG_C(0x4e0fcbeeU), BSWAP_32BIG_C(0x42cba817U), BSWAP_32BIG_C(0xbd5b5bf4U), BSWAP_32BIG_C(
                0xb8332224U),
        };
        r_rsip_func100(Param_p7f_func100_010);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007f07U);

        static const uint32_t Param_p7f_func101_013[] =
        {
            BSWAP_32BIG_C(0xb69a104cU), BSWAP_32BIG_C(0x95c21417U), BSWAP_32BIG_C(0x33b94211U), BSWAP_32BIG_C(
                0x5e95bba6U),
        };
        r_rsip_func101(Param_p7f_func101_013);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000009U);

        static const uint32_t Param_p7f_func101_014[] =
        {
            BSWAP_32BIG_C(0xd20f65c9U), BSWAP_32BIG_C(0x68553b5fU), BSWAP_32BIG_C(0x694b33b9U), BSWAP_32BIG_C(
                0x1d1c6b58U),
        };
        r_rsip_func101(Param_p7f_func101_014);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000020U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000009U);

        static const uint32_t Param_p7f_func101_015[] =
        {
            BSWAP_32BIG_C(0x9934de7eU), BSWAP_32BIG_C(0x02c70f36U), BSWAP_32BIG_C(0xc2b390c6U), BSWAP_32BIG_C(
                0x8a13a94bU),
        };
        r_rsip_func101(Param_p7f_func101_015);
        r_rsip_func044();

        static const uint32_t Param_p7f_func100_011[] =
        {
            BSWAP_32BIG_C(0xdf078b1dU), BSWAP_32BIG_C(0x716b8744U), BSWAP_32BIG_C(0x78b30b6dU), BSWAP_32BIG_C(
                0x6b613ab9U),
        };
        r_rsip_func100(Param_p7f_func100_011);
        r_rsip_func_sub040(0x40000200U, 0xe8009107U, 0x12600000U);
        r_rsip_func_sub001(0x00830031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_012[] =
        {
            BSWAP_32BIG_C(0xd0473553U), BSWAP_32BIG_C(0x7c9a3d42U), BSWAP_32BIG_C(0x2e717892U), BSWAP_32BIG_C(
                0xa6b4ba99U),
        };
        r_rsip_func100(Param_p7f_func100_012);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830011U);
        WR1_PROG(REG_1404H, 0x12b00000U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_013[] =
        {
            BSWAP_32BIG_C(0xa60ac965U), BSWAP_32BIG_C(0x7a6d796eU), BSWAP_32BIG_C(0x104b36d2U), BSWAP_32BIG_C(
                0x55097464U),
        };
        r_rsip_func100(Param_p7f_func100_013);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_func_sub001(0x00830021U);

        WR1_PROG(REG_1408H, 0x00002022U);
        for (iLoop = 24; iLoop < 32U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p7f_func100_014[] =
        {
            BSWAP_32BIG_C(0x3b815981U), BSWAP_32BIG_C(0x5e445616U), BSWAP_32BIG_C(0x8b00d3a0U), BSWAP_32BIG_C(
                0x8bdd02efU),
        };
        r_rsip_func100(Param_p7f_func100_014);
        r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 1]);

        static const uint32_t Param_p7f_func100_015[] =
        {
            BSWAP_32BIG_C(0xc53fe2abU), BSWAP_32BIG_C(0x13d03f6fU), BSWAP_32BIG_C(0xc7427f28U), BSWAP_32BIG_C(
                0xf08bc4a5U),
        };
        r_rsip_func100(Param_p7f_func100_015);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_p7f_func102_002[] =
        {
            BSWAP_32BIG_C(0x900dbd47U), BSWAP_32BIG_C(0x130a8bd6U), BSWAP_32BIG_C(0x19e789d9U), BSWAP_32BIG_C(
                0xb99d95e8U),
        };
        r_rsip_func102(Param_p7f_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
