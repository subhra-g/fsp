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

rsip_ret_t r_rsip_pf4 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
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

    r_rsip_func_sub029(0x00f40001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010380U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3020ab80U, 0x00000003U, 0x00060020U, 0x0000b780U);
    r_rsip_func_sub021(0x00000002U, 0x00000080U, 0x00000bffU, 0x30000f5aU);
    r_rsip_func_sub021(0x00030020U, 0x0000d3e1U, 0x00000060U, 0x38000f9cU);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1600H, 0x00000080U);

    r_rsip_func_sub006(0x38008be0U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_pf4_func100_001[] =
    {
        BSWAP_32BIG_C(0x6617e00fU), BSWAP_32BIG_C(0x0fb8c49eU), BSWAP_32BIG_C(0xe1cc6ecfU), BSWAP_32BIG_C(0x3a150746U),
    };
    r_rsip_func100(Param_pf4_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf4_func102_001[] =
        {
            BSWAP_32BIG_C(0xb2c5c516U), BSWAP_32BIG_C(0xcf74eae2U), BSWAP_32BIG_C(0x1ac38a14U), BSWAP_32BIG_C(
                0xf5838829U),
        };
        r_rsip_func102(Param_pf4_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf4_func100_002[] =
        {
            BSWAP_32BIG_C(0x4fc8d376U), BSWAP_32BIG_C(0x3234f97bU), BSWAP_32BIG_C(0x03936940U), BSWAP_32BIG_C(
                0xe204a09eU),
        };
        r_rsip_func100(Param_pf4_func100_002);
        r_rsip_func070(InData_DomainParam);

        static const uint32_t Param_pf4_func100_003[] =
        {
            BSWAP_32BIG_C(0xba76b48aU), BSWAP_32BIG_C(0xffcb8b5eU), BSWAP_32BIG_C(0xab7f7920U), BSWAP_32BIG_C(
                0x1d6486d6U),
        };
        r_rsip_func100(Param_pf4_func100_003);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

        WR1_PROG(REG_1404H, 0x12c80000U);

        r_rsip_func_sub014(0x00007c1cU, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            r_rsip_func_sub001(0x00c00009U);
            r_rsip_func_sub003(0x800103a0U, 0x0000f401U);

            static const uint32_t Param_pf4_func101_001[] =
            {
                BSWAP_32BIG_C(0x121d9228U), BSWAP_32BIG_C(0xb3ab30a1U), BSWAP_32BIG_C(0xbefc1aecU), BSWAP_32BIG_C(
                    0x42caee82U),
            };
            r_rsip_func101(Param_pf4_func101_001);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);
            r_rsip_func_sub001(0x00c20009U);
            r_rsip_func_sub001(0x00020009U);

            static const uint32_t Param_pf4_func101_002[] =
            {
                BSWAP_32BIG_C(0xa81c241eU), BSWAP_32BIG_C(0xb0ccc0e3U), BSWAP_32BIG_C(0x66f381c6U), BSWAP_32BIG_C(
                    0xee14dfe1U),
            };
            r_rsip_func101(Param_pf4_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub001(0x00c0000dU);

            r_rsip_func_sub003(0x800103a0U, 0x0000f402U);

            static const uint32_t Param_pf4_func101_003[] =
            {
                BSWAP_32BIG_C(0x030e7475U), BSWAP_32BIG_C(0x43af69dbU), BSWAP_32BIG_C(0x90e0f899U), BSWAP_32BIG_C(
                    0x91cd0fb0U),
            };
            r_rsip_func101(Param_pf4_func101_003);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            static const uint32_t Param_pf4_func101_004[] =
            {
                BSWAP_32BIG_C(0x867aacf0U), BSWAP_32BIG_C(0xef1ce7eaU), BSWAP_32BIG_C(0x4f422872U), BSWAP_32BIG_C(
                    0x951f706cU),
            };
            r_rsip_func101(Param_pf4_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub001(0x00c00011U);

            static const uint32_t Param_pf4_func101_005[] =
            {
                BSWAP_32BIG_C(0x1aa1bed1U), BSWAP_32BIG_C(0x62cd093bU), BSWAP_32BIG_C(0x756238baU), BSWAP_32BIG_C(
                    0x2e530390U),
            };
            r_rsip_func101(Param_pf4_func101_005);
        }

        r_rsip_func_sub003(0x800103a0U, 0x0000f403U);

        static const uint32_t Param_pf4_func101_006[] =
        {
            BSWAP_32BIG_C(0x3cafc8faU), BSWAP_32BIG_C(0xe3836cf7U), BSWAP_32BIG_C(0xc1a7138eU), BSWAP_32BIG_C(
                0x90673b2cU),
        };
        r_rsip_func101(Param_pf4_func101_006);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        r_rsip_func_sub003(0x800103a0U, 0x0000f404U);

        static const uint32_t Param_pf4_func101_007[] =
        {
            BSWAP_32BIG_C(0xda0b62cbU), BSWAP_32BIG_C(0xa5df7097U), BSWAP_32BIG_C(0x54555e3aU), BSWAP_32BIG_C(
                0x470607f8U),
        };
        r_rsip_func101(Param_pf4_func101_007);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0404000aU);

        WR1_PROG(REG_1404H, 0x11380000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);
        r_rsip_func_sub001(0x00c00009U);

        r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000250U, 0x04040007U);

        static const uint32_t Param_pf4_func100_004[] =
        {
            BSWAP_32BIG_C(0x38f7eaaaU), BSWAP_32BIG_C(0xb7d43038U), BSWAP_32BIG_C(0xd016b84bU), BSWAP_32BIG_C(
                0x121d4e16U),
        };
        r_rsip_func100(Param_pf4_func100_004);
        r_rsip_func_sub022(0x00000800U, 0x00000821U, 0x00000863U);

        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x808a0001U);
        r_rsip_func_sub001(0x03430029U);

        for (iLoop = 0U; iLoop < 10U; iLoop++)
        {
            r_rsip_func_sub021(0x38000c63U, 0x20000842U, 0x10003841U, 0x0000b7c0U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            for (jLoop = 0U; jLoop < 32U; jLoop++)
            {
                r_rsip_func_sub021(0x3800585eU, 0x20003460U, 0x20002c60U, 0x10002c00U);
                WR1_PROG(REG_1600H, 0x100033c0U);
            }

            r_rsip_func_sub034(0x0000a420U, 0x00000004U);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x14580000U);
        r_rsip_func_sub001(0x00c00029U);

        r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);

        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c00025U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x00003403U);

        WR1_PROG(REG_1600H, 0x00003060U);

        r_rsip_func_sub016(0x81010060U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x00000250U, 0x05050007U);

            r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);

            WR1_PROG(REG_1600H, 0x00003060U);

            static const uint32_t Param_pf4_func101_008[] =
            {
                BSWAP_32BIG_C(0x4ab93b5bU), BSWAP_32BIG_C(0x9d8bb4fcU), BSWAP_32BIG_C(0xf4a2808dU), BSWAP_32BIG_C(
                    0x5e7762e9U),
            };
            r_rsip_func101(Param_pf4_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c03U, 0x00602000U);

        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_func_sub001(0x00c00029U);

        static const uint32_t Param_pf4_func100_005[] =
        {
            BSWAP_32BIG_C(0x9b8acc57U), BSWAP_32BIG_C(0x98ffda68U), BSWAP_32BIG_C(0x07642549U), BSWAP_32BIG_C(
                0x974b479aU),
        };
        r_rsip_func100(Param_pf4_func100_005);
        WR1_PROG(REG_1600H, 0x0000a400U);
        WR1_PROG(REG_1600H, 0x00000040U);

        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub002(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0505000aU);

            WR1_PROG(REG_143CH, 0x00a10000U);

            static const uint32_t Param_pf4_func100_006[] =
            {
                BSWAP_32BIG_C(0xfcda584eU), BSWAP_32BIG_C(0x9a5753a8U), BSWAP_32BIG_C(0x3c1c82cfU), BSWAP_32BIG_C(
                    0x09f97e1aU),
            };
            r_rsip_func100(Param_pf4_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000002f0U, 0x05050009U);

                static const uint32_t Param_pf4_func101_009[] =
                {
                    BSWAP_32BIG_C(0x31605fe6U), BSWAP_32BIG_C(0xb6cc87d4U), BSWAP_32BIG_C(0x5560877fU), BSWAP_32BIG_C(
                        0xa719936bU),
                };
                r_rsip_func101(Param_pf4_func101_009);
            }

            WR1_PROG(REG_1014H, 0x000001b0U);
            r_rsip_func_sub005(0x00000250U, 0x0505000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000250U, 0x00000110U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003000U);

            static const uint32_t Param_pf4_func101_010[] =
            {
                BSWAP_32BIG_C(0xffd3a8abU), BSWAP_32BIG_C(0xe8ef3151U), BSWAP_32BIG_C(0x295be620U), BSWAP_32BIG_C(
                    0xb73d897aU),
            };
            r_rsip_func101(Param_pf4_func101_010);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c00U, 0x00602000U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002f0U, 0x00000110U, 0x00000340U, 0x04040009U);

        static const uint32_t Param_pf4_func100_007[] =
        {
            BSWAP_32BIG_C(0x6ebb04e4U), BSWAP_32BIG_C(0x616b080aU), BSWAP_32BIG_C(0xa4559d22U), BSWAP_32BIG_C(
                0x95548ccbU),
        };
        r_rsip_func100(Param_pf4_func100_007);
        r_rsip_func071(InData_DomainParam);

        r_rsip_func_sub003(0x800103a0U, 0x000000f4U);

        static const uint32_t Param_pf4_func101_011[] =
        {
            BSWAP_32BIG_C(0xdbfa7d1bU), BSWAP_32BIG_C(0xb95a5a9eU), BSWAP_32BIG_C(0xb5783729U), BSWAP_32BIG_C(
                0xc7ddaa5cU),
        };
        r_rsip_func101(Param_pf4_func101_011);
        r_rsip_func088();

        static const uint32_t Param_pf4_func100_008[] =
        {
            BSWAP_32BIG_C(0x512701b5U), BSWAP_32BIG_C(0xe76bc5d0U), BSWAP_32BIG_C(0x5af27f93U), BSWAP_32BIG_C(
                0xb45e135dU),
        };
        r_rsip_func100(Param_pf4_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf4_func102_002[] =
            {
                BSWAP_32BIG_C(0x91afc90dU), BSWAP_32BIG_C(0xf08caab6U), BSWAP_32BIG_C(0xf7bfcf93U), BSWAP_32BIG_C(
                    0x27cf3b6dU),
            };
            r_rsip_func102(Param_pf4_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub003(0x800103a0U, 0x0000f405U);

            static const uint32_t Param_pf4_func101_012[] =
            {
                BSWAP_32BIG_C(0x4e75d797U), BSWAP_32BIG_C(0xc97d0bb2U), BSWAP_32BIG_C(0x18a8e4f3U), BSWAP_32BIG_C(
                    0xa4174d71U),
            };
            r_rsip_func101(Param_pf4_func101_012);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010000U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e0U);

            r_rsip_func_sub003(0x800103a0U, 0x000000f4U);

            static const uint32_t Param_pf4_func101_013[] =
            {
                BSWAP_32BIG_C(0xd0dfd48aU), BSWAP_32BIG_C(0x9f822fbeU), BSWAP_32BIG_C(0xf956a0ffU), BSWAP_32BIG_C(
                    0x19af8925U),
            };
            r_rsip_func101(Param_pf4_func101_013);
            r_rsip_func043();

            r_rsip_func074();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub003(0x800103a0U, 0x000000f4U);

            static const uint32_t Param_pf4_func101_014[] =
            {
                BSWAP_32BIG_C(0xa252b155U), BSWAP_32BIG_C(0xdca02fb6U), BSWAP_32BIG_C(0xf3af16c7U), BSWAP_32BIG_C(
                    0x2ad3315cU),
            };
            r_rsip_func101(Param_pf4_func101_014);
            r_rsip_func044();

            static const uint32_t Param_pf4_func100_009[] =
            {
                BSWAP_32BIG_C(0x3e14d045U), BSWAP_32BIG_C(0x0cf82f3eU), BSWAP_32BIG_C(0xfc01e8b8U), BSWAP_32BIG_C(
                    0x5f74db59U),
            };
            r_rsip_func100(Param_pf4_func100_009);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1404H, 0x13200000U);
            r_rsip_func_sub001(0x00830021U);

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);

            static const uint32_t Param_pf4_func100_010[] =
            {
                BSWAP_32BIG_C(0x1e2c02d0U), BSWAP_32BIG_C(0x6e5128cdU), BSWAP_32BIG_C(0x94b2c72aU), BSWAP_32BIG_C(
                    0x4a8add71U),
            };
            r_rsip_func100(Param_pf4_func100_010);
            r_rsip_func_sub004(0x0c000104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x09108105U);
            r_rsip_func_sub001(0x00820011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

            static const uint32_t Param_pf4_func100_011[] =
            {
                BSWAP_32BIG_C(0x3cb32abbU), BSWAP_32BIG_C(0x48517c70U), BSWAP_32BIG_C(0xc074a8ceU), BSWAP_32BIG_C(
                    0xe7a6df28U),
            };
            r_rsip_func100(Param_pf4_func100_011);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

            r_rsip_func_sub003(0x800103a0U, 0x0000f406U);

            static const uint32_t Param_pf4_func101_015[] =
            {
                BSWAP_32BIG_C(0x83b3de63U), BSWAP_32BIG_C(0x0f64b293U), BSWAP_32BIG_C(0xea88a295U), BSWAP_32BIG_C(
                    0x0cb2cbdaU),
            };
            r_rsip_func101(Param_pf4_func101_015);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010000U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e0U);

            r_rsip_func_sub003(0x800103a0U, 0x00000001U);

            static const uint32_t Param_pf4_func101_016[] =
            {
                BSWAP_32BIG_C(0x7f209fdaU), BSWAP_32BIG_C(0x6d8eee4fU), BSWAP_32BIG_C(0x99c90cbbU), BSWAP_32BIG_C(
                    0x0c1f1884U),
            };
            r_rsip_func101(Param_pf4_func101_016);
            r_rsip_func043();

            r_rsip_func075();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub003(0x800103a0U, 0x00000002U);

            static const uint32_t Param_pf4_func101_017[] =
            {
                BSWAP_32BIG_C(0x902b3e4dU), BSWAP_32BIG_C(0x310844d1U), BSWAP_32BIG_C(0xe02ccdeeU), BSWAP_32BIG_C(
                    0x3d85fcbbU),
            };
            r_rsip_func101(Param_pf4_func101_017);
            r_rsip_func044();

            static const uint32_t Param_pf4_func100_012[] =
            {
                BSWAP_32BIG_C(0xd68bf4faU), BSWAP_32BIG_C(0x1cf10efcU), BSWAP_32BIG_C(0x31c86effU), BSWAP_32BIG_C(
                    0x4393d99eU),
            };
            r_rsip_func100(Param_pf4_func100_012);
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1404H, 0x12800000U);
            r_rsip_func_sub001(0x00830021U);
            WR1_PROG(REG_1404H, 0x12d00000U);
            r_rsip_func_sub001(0x00830011U);

            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

            static const uint32_t Param_pf4_func100_013[] =
            {
                BSWAP_32BIG_C(0xb90cb549U), BSWAP_32BIG_C(0xa95583caU), BSWAP_32BIG_C(0x52b1ae93U), BSWAP_32BIG_C(
                    0x4fe2a324U),
            };
            r_rsip_func100(Param_pf4_func100_013);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_func_sub001(0x00830011U);

            r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);

            static const uint32_t Param_pf4_func100_014[] =
            {
                BSWAP_32BIG_C(0xa4474311U), BSWAP_32BIG_C(0xa02f8b22U), BSWAP_32BIG_C(0x0df9f58cU), BSWAP_32BIG_C(
                    0xbd7ef89cU),
            };
            r_rsip_func100(Param_pf4_func100_014);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

            static const uint32_t Param_pf4_func102_003[] =
            {
                BSWAP_32BIG_C(0x318dfa65U), BSWAP_32BIG_C(0xdedb0689U), BSWAP_32BIG_C(0x78293accU), BSWAP_32BIG_C(
                    0x6192aedfU),
            };
            r_rsip_func102(Param_pf4_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
