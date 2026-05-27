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

rsip_ret_t r_rsip_pefu (const uint32_t InData_Msg1[],
                        const uint32_t InData_Msg1Length[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        const uint32_t InData_Msg2[],
                        const uint32_t InData_Msg2Length[])
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

    r_rsip_func_sub021(0x00000821U, 0x00002423U, 0x00002424U, 0x00002425U);

    static const uint32_t Param_pefu_func100_001[] =
    {
        BSWAP_32BIG_C(0x1c49160aU), BSWAP_32BIG_C(0x7fe24e0fU), BSWAP_32BIG_C(0xc384a3bdU), BSWAP_32BIG_C(0x768406deU),
    };
    r_rsip_func100(Param_pefu_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xfffffff7U, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_001[] =
        {
            BSWAP_32BIG_C(0x1cef1d86U), BSWAP_32BIG_C(0x3fb53619U), BSWAP_32BIG_C(0x6d633336U), BSWAP_32BIG_C(
                0x17338866U),
        };
        r_rsip_func101(Param_pefu_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub022(0x38000c84U, 0x00020020U, 0x38008880U);
        r_rsip_func_sub006(0x0000000cU, 0x00000080U, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000001fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_002[] =
        {
            BSWAP_32BIG_C(0x62893ae0U), BSWAP_32BIG_C(0xc3ec2c9eU), BSWAP_32BIG_C(0xd0b6684eU), BSWAP_32BIG_C(
                0x31f6e357U),
        };
        r_rsip_func101(Param_pefu_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub006(0x38008c80U, 0xffffffefU, 0x00A60000U);

        r_rsip_func_sub006(0x38008c20U, 0x0000001fU, 0x00A60000U);

        static const uint32_t Param_pefu_func101_003[] =
        {
            BSWAP_32BIG_C(0x2a3db5b9U), BSWAP_32BIG_C(0x040eae05U), BSWAP_32BIG_C(0xefd85633U), BSWAP_32BIG_C(
                0x712a5bfeU),
        };
        r_rsip_func101(Param_pefu_func101_003);
    }

    static const uint32_t Param_pefu_func100_002[] =
    {
        BSWAP_32BIG_C(0xdf3b3537U), BSWAP_32BIG_C(0xff9e4402U), BSWAP_32BIG_C(0x76d5381bU), BSWAP_32BIG_C(0x45e54921U),
    };
    r_rsip_func100(Param_pefu_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pefu_func102_001[] =
        {
            BSWAP_32BIG_C(0x94f24b7bU), BSWAP_32BIG_C(0x5adde9deU), BSWAP_32BIG_C(0x629a27a7U), BSWAP_32BIG_C(
                0xf4c22bf6U),
        };
        r_rsip_func102(Param_pefu_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x00000821U);

        r_rsip_func_sub006(0x00003405U, 0x38000c84U, 0x00A60000U);

        static const uint32_t Param_pefu_func100_003[] =
        {
            BSWAP_32BIG_C(0x17e531a9U), BSWAP_32BIG_C(0x4dd1b1b6U), BSWAP_32BIG_C(0x21bb2f5cU), BSWAP_32BIG_C(
                0x4c74e2d6U),
        };
        r_rsip_func100(Param_pefu_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_EncMsg[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x0000ef01U);

            static const uint32_t Param_pefu_func101_004[] =
            {
                BSWAP_32BIG_C(0x523d1173U), BSWAP_32BIG_C(0x462beca5U), BSWAP_32BIG_C(0xb2cfe07cU), BSWAP_32BIG_C(
                    0xc37b7158U),
            };
            r_rsip_func101(Param_pefu_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x01799093U);

            r_rsip_func_sub003(0x800103a0U, 0x0000ef01U);

            static const uint32_t Param_pefu_func101_005[] =
            {
                BSWAP_32BIG_C(0x4a3cb98eU), BSWAP_32BIG_C(0x4d794415U), BSWAP_32BIG_C(0xd8b528ffU), BSWAP_32BIG_C(
                    0x142012d1U),
            };
            r_rsip_func101(Param_pefu_func101_005);
            r_rsip_func044();

            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            static const uint32_t Param_pefu_func100_004[] =
            {
                BSWAP_32BIG_C(0x17bd9c23U), BSWAP_32BIG_C(0x813e23d0U), BSWAP_32BIG_C(0x8921e85eU), BSWAP_32BIG_C(
                    0x772983c6U),
            };
            r_rsip_func100(Param_pefu_func100_004);

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

                static const uint32_t Param_pefu_func101_006[] =
                {
                    BSWAP_32BIG_C(0xad13ae01U), BSWAP_32BIG_C(0xe9ccdee6U), BSWAP_32BIG_C(0xbcdb1f08U), BSWAP_32BIG_C(
                        0x338d143aU),
                };
                r_rsip_func101(Param_pefu_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                r_rsip_func_sub024(0x00000bc2U, 0x40000200U, 0xf7009d07U);

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

                static const uint32_t Param_pefu_func101_007[] =
                {
                    BSWAP_32BIG_C(0xb963669fU), BSWAP_32BIG_C(0x41453a72U), BSWAP_32BIG_C(0xe5c6220aU), BSWAP_32BIG_C(
                        0xa2758202U),
                };
                r_rsip_func101(Param_pefu_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

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

                static const uint32_t Param_pefu_func101_008[] =
                {
                    BSWAP_32BIG_C(0x46e4c005U), BSWAP_32BIG_C(0x6720cb79U), BSWAP_32BIG_C(0x47a1144fU), BSWAP_32BIG_C(
                        0x38e8f66dU),
                };
                r_rsip_func101(Param_pefu_func101_008);
            }

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pefu_func100_005[] =
            {
                BSWAP_32BIG_C(0x7bc7555bU), BSWAP_32BIG_C(0xc2bfa16bU), BSWAP_32BIG_C(0x150655d5U), BSWAP_32BIG_C(
                    0x94ad17e1U),
            };
            r_rsip_func100(Param_pefu_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002c20U);
                static const uint32_t Param_pefu_func101_009[] =
                {
                    BSWAP_32BIG_C(0x220aae16U), BSWAP_32BIG_C(0x8761fa71U), BSWAP_32BIG_C(0xe0369152U), BSWAP_32BIG_C(
                        0x68c7e246U),
                };
                r_rsip_func101(Param_pefu_func101_009);
            }

            static const uint32_t Param_pefu_func101_010[] =
            {
                BSWAP_32BIG_C(0x27e7d387U), BSWAP_32BIG_C(0x94fe36e6U), BSWAP_32BIG_C(0x9017d7bdU), BSWAP_32BIG_C(
                    0xbc18f312U),
            };
            r_rsip_func101(Param_pefu_func101_010);
        }

        r_rsip_func_sub017(0x38000c21U, 0x00A60000U);

        static const uint32_t Param_pefu_func100_006[] =
        {
            BSWAP_32BIG_C(0x42700e5eU), BSWAP_32BIG_C(0x8fb54b9bU), BSWAP_32BIG_C(0xd44313ecU), BSWAP_32BIG_C(
                0x81e83bbeU),
        };
        r_rsip_func100(Param_pefu_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pefu_func102_002[] =
            {
                BSWAP_32BIG_C(0x7bc54fc3U), BSWAP_32BIG_C(0x6240d020U), BSWAP_32BIG_C(0x7e292cb8U), BSWAP_32BIG_C(
                    0x5f5fb6caU),
            };
            r_rsip_func102(Param_pefu_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WAIT_STS(REG_2030H, 0, 1);

            r_rsip_func_sub017(0x38000c63U, 0x00A60000U);

            static const uint32_t Param_pefu_func100_007[] =
            {
                BSWAP_32BIG_C(0x1a427d46U), BSWAP_32BIG_C(0x63db502eU), BSWAP_32BIG_C(0x9cadf6d2U), BSWAP_32BIG_C(
                    0x3d065d25U),
            };
            r_rsip_func100(Param_pefu_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1444H, 0x000000c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Msg1[0]);

                static const uint32_t Param_pefu_func101_011[] =
                {
                    BSWAP_32BIG_C(0xeb3f2e4cU), BSWAP_32BIG_C(0x342bb020U), BSWAP_32BIG_C(0x11383c25U), BSWAP_32BIG_C(
                        0xc4b583a9U),
                };
                r_rsip_func101(Param_pefu_func101_011);
            }

            r_rsip_func_sub017(0x38000c84U, 0x00A60000U);

            static const uint32_t Param_pefu_func100_008[] =
            {
                BSWAP_32BIG_C(0x92a3fdc3U), BSWAP_32BIG_C(0xd97d08bdU), BSWAP_32BIG_C(0x4ced105bU), BSWAP_32BIG_C(
                    0xa9a349c7U),
            };
            r_rsip_func100(Param_pefu_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pefu_func100_009[] =
                {
                    BSWAP_32BIG_C(0xd9753f61U), BSWAP_32BIG_C(0x5a4498b5U), BSWAP_32BIG_C(0x50c902fbU), BSWAP_32BIG_C(
                        0xcf683ddeU),
                };
                r_rsip_func100(Param_pefu_func100_009);

                r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430021U);

                    static const uint32_t Param_pefu_func101_012[] =
                    {
                        BSWAP_32BIG_C(0xebc76093U), BSWAP_32BIG_C(0xd25821b0U), BSWAP_32BIG_C(0x7b4f2340U),
                        BSWAP_32BIG_C(0x01c279dbU),
                    };
                    r_rsip_func101(Param_pefu_func101_012);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430031U);

                    static const uint32_t Param_pefu_func101_013[] =
                    {
                        BSWAP_32BIG_C(0x110d28faU), BSWAP_32BIG_C(0x5d2d66bcU), BSWAP_32BIG_C(0x4615e1f0U),
                        BSWAP_32BIG_C(0xae1ac68eU),
                    };
                    r_rsip_func101(Param_pefu_func101_013);
                }
                else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                {
                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x01430041U);

                    static const uint32_t Param_pefu_func101_014[] =
                    {
                        BSWAP_32BIG_C(0x60b54b34U), BSWAP_32BIG_C(0x823cf648U), BSWAP_32BIG_C(0x0103f407U),
                        BSWAP_32BIG_C(0x160e80e1U),
                    };
                    r_rsip_func101(Param_pefu_func101_014);
                }

                static const uint32_t Param_pefu_func101_015[] =
                {
                    BSWAP_32BIG_C(0x63dd2833U), BSWAP_32BIG_C(0x8d5f6f8aU), BSWAP_32BIG_C(0x5fad6ca0U), BSWAP_32BIG_C(
                        0xf2ef5838U),
                };
                r_rsip_func101(Param_pefu_func101_015);
            }

            static const uint32_t Param_pefu_func100_010[] =
            {
                BSWAP_32BIG_C(0xbbebbd41U), BSWAP_32BIG_C(0x115ea27dU), BSWAP_32BIG_C(0x0585a162U), BSWAP_32BIG_C(
                    0xfae7f1eeU),
            };
            r_rsip_func100(Param_pefu_func100_010);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1444H, 0x00020064U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0; iLoop < (S_RAM[0] & 0x0000000fU); iLoop++)
            {
                WR1_PROG(REG_1420H, InData_Msg2[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = (S_RAM[0] & 0x0000000fU); iLoop < S_RAM[0]; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR16_ADDR(REG_1420H, &InData_Msg2[iLoop]);
                iLoop = iLoop + 16U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000000U);
            WAIT_STS(REG_2030H, 8, 0);
            WR1_PROG(REG_143CH, 0x00001600U);

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003801U);

            static const uint32_t Param_pefu_func101_016[] =
            {
                BSWAP_32BIG_C(0x1d50d86fU), BSWAP_32BIG_C(0xca4de9f8U), BSWAP_32BIG_C(0xadaa5f11U), BSWAP_32BIG_C(
                    0xe8524ff6U),
            };
            r_rsip_func101(Param_pefu_func101_016);

            return RSIP_RET_PASS;
        }
    }
}
