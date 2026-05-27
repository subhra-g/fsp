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

rsip_ret_t r_rsip_peff (const uint32_t InData_Msg1[],
                        const uint32_t InData_Msg1Length[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        const uint32_t InData_Msg2[],
                        const uint32_t InData_Msg2Length[],
                        uint32_t       OutData_KDFInfo[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000002c7U, 0x80030060U);
    WR1_PROG(REG_1420H, InData_Msg1Length[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Msg2Length[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008c60U, 0xfffffffeU, 0x00A60000U);

    static const uint32_t Param_peff_func100_001[] =
    {
        BSWAP_32BIG_C(0x912b85b6U), BSWAP_32BIG_C(0xc9c65800U), BSWAP_32BIG_C(0x0ecf516cU), BSWAP_32BIG_C(0xb7d4a2c8U),
    };
    r_rsip_func100(Param_peff_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xfffffff7U, 0x00A60000U);

        static const uint32_t Param_peff_func101_001[] =
        {
            BSWAP_32BIG_C(0x0a2f296eU), BSWAP_32BIG_C(0xc606cf0bU), BSWAP_32BIG_C(0x9affb101U), BSWAP_32BIG_C(
                0x7e1e7e36U),
        };
        r_rsip_func101(Param_peff_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub025(0x38000c84U, 0x00020020U, 0x38008880U);
        r_rsip_func_sub006(0x0000000cU, 0x00000080U, 0x00A60000U);

        static const uint32_t Param_peff_func101_002[] =
        {
            BSWAP_32BIG_C(0xcd51157aU), BSWAP_32BIG_C(0x0c3a92e1U), BSWAP_32BIG_C(0xcb95470fU), BSWAP_32BIG_C(
                0x7e3a5af1U),
        };
        r_rsip_func101(Param_peff_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xffffffefU, 0x00A60000U);

        static const uint32_t Param_peff_func101_003[] =
        {
            BSWAP_32BIG_C(0x5e5592d3U), BSWAP_32BIG_C(0x8d9821f9U), BSWAP_32BIG_C(0x4f34ebe2U), BSWAP_32BIG_C(
                0x7a197f1dU),
        };
        r_rsip_func101(Param_peff_func101_003);
    }

    static const uint32_t Param_peff_func100_002[] =
    {
        BSWAP_32BIG_C(0xa75ea818U), BSWAP_32BIG_C(0x90e4b2c7U), BSWAP_32BIG_C(0x72d98995U), BSWAP_32BIG_C(0x9b71096bU),
    };
    r_rsip_func100(Param_peff_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_peff_func102_001[] =
        {
            BSWAP_32BIG_C(0x036781c8U), BSWAP_32BIG_C(0x9f77c096U), BSWAP_32BIG_C(0x24876c15U), BSWAP_32BIG_C(
                0xc3fce0e3U),
        };
        r_rsip_func102(Param_peff_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);

        r_rsip_func_sub006(0x00003405U, 0x38000c84U, 0x00A60000U);

        static const uint32_t Param_peff_func100_003[] =
        {
            BSWAP_32BIG_C(0x17e6f7b5U), BSWAP_32BIG_C(0x2326a538U), BSWAP_32BIG_C(0xd1c2e2afU), BSWAP_32BIG_C(
                0xe3ba47e2U),
        };
        r_rsip_func100(Param_peff_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_EncMsg[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000ef02U);

            static const uint32_t Param_peff_func101_004[] =
            {
                BSWAP_32BIG_C(0xf8ad8543U), BSWAP_32BIG_C(0xb60379ecU), BSWAP_32BIG_C(0xf31ef472U), BSWAP_32BIG_C(
                    0x3f52931aU),
            };
            r_rsip_func101(Param_peff_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01799093U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000ef02U);

            static const uint32_t Param_peff_func101_005[] =
            {
                BSWAP_32BIG_C(0xbf6fe5b4U), BSWAP_32BIG_C(0x6d602e23U), BSWAP_32BIG_C(0xd6043141U), BSWAP_32BIG_C(
                    0x00e9a965U),
            };
            r_rsip_func101(Param_peff_func101_005);
            r_rsip_func044();

            r_rsip_func_sub025(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            static const uint32_t Param_peff_func100_004[] =
            {
                BSWAP_32BIG_C(0x86a9c72cU), BSWAP_32BIG_C(0x59f68636U), BSWAP_32BIG_C(0x658afa86U), BSWAP_32BIG_C(
                    0x75cb3ea4U),
            };
            r_rsip_func100(Param_peff_func100_004);

            r_rsip_func_sub014(0x00007c05U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1]);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_EncMsg[5]);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20021U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[9]);

                static const uint32_t Param_peff_func101_006[] =
                {
                    BSWAP_32BIG_C(0x04512293U), BSWAP_32BIG_C(0xd03dd040U), BSWAP_32BIG_C(0xb0ffbdc5U), BSWAP_32BIG_C(
                        0x5bb5a28eU),
                };
                r_rsip_func101(Param_peff_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                r_rsip_func_sub023(0x00000bc2U, 0x40000200U, 0xf7009d07U);

                for (iLoop = 0U; iLoop < 12U; )
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x00c20031U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[13]);

                static const uint32_t Param_peff_func101_007[] =
                {
                    BSWAP_32BIG_C(0x7da17820U), BSWAP_32BIG_C(0x3dc3c98dU), BSWAP_32BIG_C(0x33620ba5U), BSWAP_32BIG_C(
                        0x8d267a3eU),
                };
                r_rsip_func101(Param_peff_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                r_rsip_func_sub023(0x00000fc2U, 0x40000300U, 0xf7009d07U);

                WR1_PROG(REG_1404H, 0x10000000U);
                for (iLoop = 0U; iLoop < 16U; )
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);
                    r_rsip_func_sub001(0x00c20011U);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[17]);

                static const uint32_t Param_peff_func101_008[] =
                {
                    BSWAP_32BIG_C(0x6d0c5278U), BSWAP_32BIG_C(0x1cd6495cU), BSWAP_32BIG_C(0x02d01bc7U), BSWAP_32BIG_C(
                        0x45c3ac69U),
                };
                r_rsip_func101(Param_peff_func101_008);
            }

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_peff_func100_005[] =
            {
                BSWAP_32BIG_C(0x4f6ef73aU), BSWAP_32BIG_C(0x7877b4bbU), BSWAP_32BIG_C(0xb8e03eb4U), BSWAP_32BIG_C(
                    0x3b2cec27U),
            };
            r_rsip_func100(Param_peff_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002c20U);
                static const uint32_t Param_peff_func101_009[] =
                {
                    BSWAP_32BIG_C(0x488fd84dU), BSWAP_32BIG_C(0x6ab92535U), BSWAP_32BIG_C(0x7c734030U), BSWAP_32BIG_C(
                        0x028b0329U),
                };
                r_rsip_func101(Param_peff_func101_009);
            }

            static const uint32_t Param_peff_func101_010[] =
            {
                BSWAP_32BIG_C(0xacb377d6U), BSWAP_32BIG_C(0xf7eab2e3U), BSWAP_32BIG_C(0x0992b677U), BSWAP_32BIG_C(
                    0xeac7afaaU),
            };
            r_rsip_func101(Param_peff_func101_010);
        }

        r_rsip_func_sub017(0x38000c21U, 0x00A60000U);

        static const uint32_t Param_peff_func100_006[] =
        {
            BSWAP_32BIG_C(0x88ba8b6aU), BSWAP_32BIG_C(0x0c08c1e4U), BSWAP_32BIG_C(0x33c85669U), BSWAP_32BIG_C(
                0x8edf50f8U),
        };
        r_rsip_func100(Param_peff_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_peff_func102_002[] =
            {
                BSWAP_32BIG_C(0xb21eadebU), BSWAP_32BIG_C(0x78879f51U), BSWAP_32BIG_C(0x5d3b12deU), BSWAP_32BIG_C(
                    0x30c6729cU),
            };
            r_rsip_func102(Param_peff_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WAIT_STS(REG_2030H, 0, 1);

            r_rsip_func_sub017(0x38000c63U, 0x00A60000U);

            static const uint32_t Param_peff_func100_007[] =
            {
                BSWAP_32BIG_C(0x7d890719U), BSWAP_32BIG_C(0xc5c3b34fU), BSWAP_32BIG_C(0x3e89f683U), BSWAP_32BIG_C(
                    0x4cd6c80bU),
            };
            r_rsip_func100(Param_peff_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1444H, 0x000000c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg1[0]);

                static const uint32_t Param_peff_func101_011[] =
                {
                    BSWAP_32BIG_C(0x501f8b00U), BSWAP_32BIG_C(0x5e170e1eU), BSWAP_32BIG_C(0xc13a5fd4U), BSWAP_32BIG_C(
                        0x6df67ceeU),
                };
                r_rsip_func101(Param_peff_func101_011);
            }

            r_rsip_func_sub017(0x38000c84U, 0x00A60000U);

            static const uint32_t Param_peff_func100_008[] =
            {
                BSWAP_32BIG_C(0xe2b05523U), BSWAP_32BIG_C(0xcd9ac643U), BSWAP_32BIG_C(0x202624f6U), BSWAP_32BIG_C(
                    0x4467a339U),
            };
            r_rsip_func100(Param_peff_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_peff_func100_009[] =
                {
                    BSWAP_32BIG_C(0x3f7c9559U), BSWAP_32BIG_C(0x1cb2f266U), BSWAP_32BIG_C(0x1ed18246U), BSWAP_32BIG_C(
                        0x44906e2dU),
                };
                r_rsip_func100(Param_peff_func100_009);

                r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430021U);

                    static const uint32_t Param_peff_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x2df5a0d4U), BSWAP_32BIG_C(0x5f54bdd2U), BSWAP_32BIG_C(0x5c573239U),
                        BSWAP_32BIG_C(0xbf216d24U),
                    };
                    r_rsip_func101(Param_peff_func101_012);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430031U);

                    static const uint32_t Param_peff_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x700ec984U), BSWAP_32BIG_C(0x50d7688aU), BSWAP_32BIG_C(0xc52af0c3U),
                        BSWAP_32BIG_C(0x5e28323dU),
                    };
                    r_rsip_func101(Param_peff_func101_013);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430041U);

                    static const uint32_t Param_peff_func101_014[] =
                    {
                        BSWAP_32BIG_C(0xa114f4acU), BSWAP_32BIG_C(0x83154917U), BSWAP_32BIG_C(0x665ef640U),
                        BSWAP_32BIG_C(0x3e1ff64eU),
                    };
                    r_rsip_func101(Param_peff_func101_014);
                }

                static const uint32_t Param_peff_func101_015[] =
                {
                    BSWAP_32BIG_C(0x41819c42U), BSWAP_32BIG_C(0x4fb29b8bU), BSWAP_32BIG_C(0xd16b3cb0U), BSWAP_32BIG_C(
                        0x0c412750U),
                };
                r_rsip_func101(Param_peff_func101_015);
            }

            static const uint32_t Param_peff_func100_010[] =
            {
                BSWAP_32BIG_C(0x52796222U), BSWAP_32BIG_C(0xfed00517U), BSWAP_32BIG_C(0xbad5c650U), BSWAP_32BIG_C(
                    0x48fa0f45U),
            };
            r_rsip_func100(Param_peff_func100_010);

            r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
            WR1_PROG(REG_1420H, InData_Msg2Length[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1444H, 0x00020064U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg2[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000000U);
            WAIT_STS(REG_2030H, 8, 0);
            WR1_PROG(REG_143CH, 0x00001600U);

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub025(0x0000b420U, 0x00000010U, 0x00003801U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000efU);

            static const uint32_t Param_peff_func101_016[] =
            {
                BSWAP_32BIG_C(0x0b2da105U), BSWAP_32BIG_C(0xaa38adb9U), BSWAP_32BIG_C(0xdfe8408aU), BSWAP_32BIG_C(
                    0x1dc7e855U),
            };
            r_rsip_func101(Param_peff_func101_016);
            r_rsip_func103();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1608H, 0x80010020U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1600H, 0x000034e1U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000ef03U);

            static const uint32_t Param_peff_func101_017[] =
            {
                BSWAP_32BIG_C(0xb7920be7U), BSWAP_32BIG_C(0xc312de92U), BSWAP_32BIG_C(0x409425a8U), BSWAP_32BIG_C(
                    0xed7f5f8bU),
            };
            r_rsip_func101(Param_peff_func101_017);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01799093U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000ef03U);

            static const uint32_t Param_peff_func101_018[] =
            {
                BSWAP_32BIG_C(0x011c06d2U), BSWAP_32BIG_C(0xdc4be9c6U), BSWAP_32BIG_C(0xadc89543U), BSWAP_32BIG_C(
                    0x6102e536U),
            };
            r_rsip_func101(Param_peff_func101_018);
            r_rsip_func044();

            static const uint32_t Param_peff_func100_011[] =
            {
                BSWAP_32BIG_C(0x054b0e03U), BSWAP_32BIG_C(0x71cfd4c5U), BSWAP_32BIG_C(0xb2a0c86dU), BSWAP_32BIG_C(
                    0x87c222a7U),
            };
            r_rsip_func100(Param_peff_func100_011);
            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub004(0x08000054U, 0x00000000U);

            r_rsip_func_sub014(0x00007c00U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                static const uint32_t Param_peff_func100_012[] =
                {
                    BSWAP_32BIG_C(0xef20b281U), BSWAP_32BIG_C(0x56b0b01aU), BSWAP_32BIG_C(0xf7d53e08U), BSWAP_32BIG_C(
                        0xbcb036a3U),
                };
                r_rsip_func100(Param_peff_func100_012);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);

                static const uint32_t Param_peff_func100_013[] =
                {
                    BSWAP_32BIG_C(0xb3e26965U), BSWAP_32BIG_C(0xa7b6d986U), BSWAP_32BIG_C(0x9bdd98bcU), BSWAP_32BIG_C(
                        0xbb8bccf0U),
                };
                r_rsip_func100(Param_peff_func100_013);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func101_019[] =
                {
                    BSWAP_32BIG_C(0x08c90d6fU), BSWAP_32BIG_C(0xf5d0ec43U), BSWAP_32BIG_C(0x7553999bU), BSWAP_32BIG_C(
                        0x67e888beU),
                };
                r_rsip_func101(Param_peff_func101_019);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                static const uint32_t Param_peff_func100_014[] =
                {
                    BSWAP_32BIG_C(0xad1b458fU), BSWAP_32BIG_C(0x43784c70U), BSWAP_32BIG_C(0x7655bfc3U), BSWAP_32BIG_C(
                        0x9f05da3fU),
                };
                r_rsip_func100(Param_peff_func100_014);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func100_015[] =
                {
                    BSWAP_32BIG_C(0x4123d9a2U), BSWAP_32BIG_C(0x19d41800U), BSWAP_32BIG_C(0x6e094d6dU), BSWAP_32BIG_C(
                        0xf1da9dbaU),
                };
                r_rsip_func100(Param_peff_func100_015);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[13]);

                static const uint32_t Param_peff_func101_020[] =
                {
                    BSWAP_32BIG_C(0x27f4521cU), BSWAP_32BIG_C(0x678099edU), BSWAP_32BIG_C(0x37e88438U), BSWAP_32BIG_C(
                        0x2d4a9601U),
                };
                r_rsip_func101(Param_peff_func101_020);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                static const uint32_t Param_peff_func100_016[] =
                {
                    BSWAP_32BIG_C(0x2ec912e6U), BSWAP_32BIG_C(0xb5de665eU), BSWAP_32BIG_C(0x8ce1e6ecU), BSWAP_32BIG_C(
                        0xd1b841b8U),
                };
                r_rsip_func100(Param_peff_func100_016);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                r_rsip_func_sub001(0x00850031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[5]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func100_017[] =
                {
                    BSWAP_32BIG_C(0xc93aa478U), BSWAP_32BIG_C(0x48ea67b5U), BSWAP_32BIG_C(0x210da8f3U), BSWAP_32BIG_C(
                        0x694da1c1U),
                };
                r_rsip_func100(Param_peff_func100_017);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_func_sub001(0x00850011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[13]);

                static const uint32_t Param_peff_func100_018[] =
                {
                    BSWAP_32BIG_C(0x47ba62f2U), BSWAP_32BIG_C(0xa601884bU), BSWAP_32BIG_C(0x100a9752U), BSWAP_32BIG_C(
                        0x34f435e9U),
                };
                r_rsip_func100(Param_peff_func100_018);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KDFInfo[17]);

                static const uint32_t Param_peff_func101_021[] =
                {
                    BSWAP_32BIG_C(0x9cdc393bU), BSWAP_32BIG_C(0xb0454583U), BSWAP_32BIG_C(0x13ff90f1U), BSWAP_32BIG_C(
                        0x0f998ac5U),
                };
                r_rsip_func101(Param_peff_func101_021);
            }

            static const uint32_t Param_peff_func100_019[] =
            {
                BSWAP_32BIG_C(0x6ea82957U), BSWAP_32BIG_C(0x243be52dU), BSWAP_32BIG_C(0x0ac00f8eU), BSWAP_32BIG_C(
                    0xf231232eU),
            };
            r_rsip_func100(Param_peff_func100_019);
            r_rsip_func_sub016(0x81010020U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);

            static const uint32_t Param_peff_func102_003[] =
            {
                BSWAP_32BIG_C(0x37543e22U), BSWAP_32BIG_C(0x1c3ee44bU), BSWAP_32BIG_C(0x867b3852U), BSWAP_32BIG_C(
                    0xe9f5ef60U),
            };
            r_rsip_func102(Param_peff_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
