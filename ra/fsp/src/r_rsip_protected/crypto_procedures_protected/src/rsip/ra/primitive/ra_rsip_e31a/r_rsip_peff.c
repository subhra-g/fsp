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

    r_rsip_func_sub014(0x000002c7U, 0x80030060U);
    WR1_PROG(REG_002CH, InData_Msg1Length[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_Msg2Length[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub010(0x38008c60U, 0xfffffffeU, 0x00A70000U);

    static const uint32_t Param_peff_func100_001[] =
    {
        BSWAP_32BIG_C(0x77c79546U), BSWAP_32BIG_C(0x5b883fa9U), BSWAP_32BIG_C(0x68eec830U), BSWAP_32BIG_C(0x37f823b6U),
    };
    r_rsip_func100(Param_peff_func100_001);
    WR1_PROG(REG_0094H, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub010(0x38008c80U, 0xfffffff7U, 0x00A70000U);

        static const uint32_t Param_peff_func101_001[] =
        {
            BSWAP_32BIG_C(0x5a83a99dU), BSWAP_32BIG_C(0x9a3e5d68U), BSWAP_32BIG_C(0x84ecd58fU), BSWAP_32BIG_C(
                0x5450d810U),
        };
        r_rsip_func101(Param_peff_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub010(0x38008c80U, 0xfffffff3U, 0x00A70000U);

        static const uint32_t Param_peff_func101_002[] =
        {
            BSWAP_32BIG_C(0x22846764U), BSWAP_32BIG_C(0x34e6ffe5U), BSWAP_32BIG_C(0x60532fedU), BSWAP_32BIG_C(
                0x8d7b27d1U),
        };
        r_rsip_func101(Param_peff_func101_002);
    }

    static const uint32_t Param_peff_func100_002[] =
    {
        BSWAP_32BIG_C(0xa87977abU), BSWAP_32BIG_C(0xd113bd2bU), BSWAP_32BIG_C(0x143acc5aU), BSWAP_32BIG_C(0xb1cf0984U),
    };
    r_rsip_func100(Param_peff_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_peff_func102_001[] =
        {
            BSWAP_32BIG_C(0x10c20255U), BSWAP_32BIG_C(0x6c2416b0U), BSWAP_32BIG_C(0x5ac23861U), BSWAP_32BIG_C(
                0x6b3af435U),
        };
        r_rsip_func102(Param_peff_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00000821U);

        r_rsip_func_sub010(0x00003405U, 0x38000c84U, 0x00A70000U);

        static const uint32_t Param_peff_func100_003[] =
        {
            BSWAP_32BIG_C(0x2f59c109U), BSWAP_32BIG_C(0x6ce5c1a7U), BSWAP_32BIG_C(0x6ee8ac2fU), BSWAP_32BIG_C(
                0xf366437dU),
        };
        r_rsip_func100(Param_peff_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x00003847U);

            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            static const uint32_t Param_peff_func100_004[] =
            {
                BSWAP_32BIG_C(0xde9e62a6U), BSWAP_32BIG_C(0x5ec305fbU), BSWAP_32BIG_C(0x20bd8a32U), BSWAP_32BIG_C(
                    0x2c837383U),
            };
            r_rsip_func100(Param_peff_func100_004);
            WR1_PROG(REG_0094H, 0x00007c02U);
            WR1_PROG(REG_0040H, 0x00600000U);

            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
            {
                static const uint32_t Param_peff_sub100_001[] =
                {
                    BSWAP_32BIG_C(0x0000ef03U), BSWAP_32BIG_C(0x22708a5eU), BSWAP_32BIG_C(0x802d0065U),
                    BSWAP_32BIG_C(0x3b8f77fcU),
                    BSWAP_32BIG_C(0xd9264600U), BSWAP_32BIG_C(0x0000ef03U), BSWAP_32BIG_C(0x3d28e2d0U),
                    BSWAP_32BIG_C(0xb4d74b76U),
                    BSWAP_32BIG_C(0xe96893c4U),
                    BSWAP_32BIG_C(0x91874100U), 0x00001404U,
                };
                r_rsip_func_sub100(InData_EncMsg, Param_peff_sub100_001, RSIP_SEL_BIT_LENGTH_256);

                static const uint32_t Param_peff_func101_003[] =
                {
                    BSWAP_32BIG_C(0xcfab1206U), BSWAP_32BIG_C(0x506f7835U), BSWAP_32BIG_C(0x508c143eU), BSWAP_32BIG_C(
                        0x47810567U),
                };
                r_rsip_func101(Param_peff_func101_003);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
            {
                static const uint32_t Param_peff_sub100_002[] =
                {
                    BSWAP_32BIG_C(0x0000ef04U), BSWAP_32BIG_C(0xc6ca488dU), BSWAP_32BIG_C(0x437db172U),
                    BSWAP_32BIG_C(0xbb33be5cU),
                    BSWAP_32BIG_C(0x042235e2U), BSWAP_32BIG_C(0x0000ef04U), BSWAP_32BIG_C(0xe72fecc1U),
                    BSWAP_32BIG_C(0x515a4eeaU),
                    BSWAP_32BIG_C(0x59b07211U),
                    BSWAP_32BIG_C(0x9d2e250aU), 0x00009406U,
                };
                r_rsip_func_sub100(InData_EncMsg, Param_peff_sub100_002, RSIP_SEL_BIT_LENGTH_384);

                static const uint32_t Param_peff_func101_004[] =
                {
                    BSWAP_32BIG_C(0x46edfe54U), BSWAP_32BIG_C(0x8199fb57U), BSWAP_32BIG_C(0x1adc4726U), BSWAP_32BIG_C(
                        0xe22b631eU),
                };
                r_rsip_func101(Param_peff_func101_004);
            }

            static const uint32_t Param_peff_func100_005[] =
            {
                BSWAP_32BIG_C(0x8754f038U), BSWAP_32BIG_C(0x826eae1aU), BSWAP_32BIG_C(0xac79b134U), BSWAP_32BIG_C(
                    0x96c972cfU),
            };
            r_rsip_func100(Param_peff_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00002c20U);
                static const uint32_t Param_peff_func101_005[] =
                {
                    BSWAP_32BIG_C(0x9cb09171U), BSWAP_32BIG_C(0x156f8362U), BSWAP_32BIG_C(0x0938168eU), BSWAP_32BIG_C(
                        0xea6e0a09U),
                };
                r_rsip_func101(Param_peff_func101_005);
            }

            static const uint32_t Param_peff_func101_006[] =
            {
                BSWAP_32BIG_C(0x3983aaeeU), BSWAP_32BIG_C(0x5005d6c0U), BSWAP_32BIG_C(0x21a0a817U), BSWAP_32BIG_C(
                    0x032cba34U),
            };
            r_rsip_func101(Param_peff_func101_006);
        }

        r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_peff_func100_006[] =
        {
            BSWAP_32BIG_C(0xb5c50105U), BSWAP_32BIG_C(0x7538e135U), BSWAP_32BIG_C(0xf914df10U), BSWAP_32BIG_C(
                0x06fa2843U),
        };
        r_rsip_func100(Param_peff_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);
        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_peff_func102_002[] =
            {
                BSWAP_32BIG_C(0xa9b92298U), BSWAP_32BIG_C(0xe13a7b4fU), BSWAP_32BIG_C(0xb94aba3fU), BSWAP_32BIG_C(
                    0xfc318108U),
            };
            r_rsip_func102(Param_peff_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            WAIT_STS(REG_0118H, 0, 1);

            r_rsip_func_sub016(0x38000c63U, 0x00000080U, 0x00A70000U);

            static const uint32_t Param_peff_func100_007[] =
            {
                BSWAP_32BIG_C(0xe2fea01aU), BSWAP_32BIG_C(0xb70cfb21U), BSWAP_32BIG_C(0xb1be895dU), BSWAP_32BIG_C(
                    0x9f918889U),
            };
            r_rsip_func100(Param_peff_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000000c4U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Msg1[0]);

                static const uint32_t Param_peff_func101_007[] =
                {
                    BSWAP_32BIG_C(0x6081ee4dU), BSWAP_32BIG_C(0x16c69499U), BSWAP_32BIG_C(0x195698d6U), BSWAP_32BIG_C(
                        0xf7756b58U),
                };
                r_rsip_func101(Param_peff_func101_007);
            }

            r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00A70000U);

            static const uint32_t Param_peff_func100_008[] =
            {
                BSWAP_32BIG_C(0x1a96bc76U), BSWAP_32BIG_C(0x6b774a8aU), BSWAP_32BIG_C(0x6bb8df5dU), BSWAP_32BIG_C(
                    0x999e27b6U),
            };
            r_rsip_func100(Param_peff_func100_008);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_peff_func100_009[] =
                {
                    BSWAP_32BIG_C(0x272d6160U), BSWAP_32BIG_C(0x28c97791U), BSWAP_32BIG_C(0x20fd1ac0U), BSWAP_32BIG_C(
                        0xe07621e2U),
                };
                r_rsip_func100(Param_peff_func100_009);

                WR1_PROG(REG_0094H, 0x00007c05U);
                WR1_PROG(REG_0040H, 0x00600000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    r_rsip_func_sub009(0x00001804U, 0x01430021U, 0x00001800U);

                    static const uint32_t Param_peff_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x824db73fU), BSWAP_32BIG_C(0x0cd07191U), BSWAP_32BIG_C(0xc7a0f354U),
                        BSWAP_32BIG_C(0xa4ba8fd4U),
                    };
                    r_rsip_func101(Param_peff_func101_008);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                {
                    r_rsip_func_sub009(0x00009806U, 0x01430031U, 0x00001800U);

                    static const uint32_t Param_peff_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x573d3e7eU), BSWAP_32BIG_C(0x95692313U), BSWAP_32BIG_C(0xcc25a569U),
                        BSWAP_32BIG_C(0x01b3ad83U),
                    };
                    r_rsip_func101(Param_peff_func101_009);
                }

                static const uint32_t Param_peff_func101_010[] =
                {
                    BSWAP_32BIG_C(0xad9c2e0aU), BSWAP_32BIG_C(0xe14219d9U), BSWAP_32BIG_C(0xbb31fcb2U), BSWAP_32BIG_C(
                        0xf55341e9U),
                };
                r_rsip_func101(Param_peff_func101_010);
            }

            static const uint32_t Param_peff_func100_010[] =
            {
                BSWAP_32BIG_C(0x22954808U), BSWAP_32BIG_C(0x47a83692U), BSWAP_32BIG_C(0xdd871b50U), BSWAP_32BIG_C(
                    0x8ae1b922U),
            };
            r_rsip_func100(Param_peff_func100_010);

            r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
            WR1_PROG(REG_002CH, InData_Msg2Length[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub017(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_0014H, 0x00020064U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Msg2[iLoop]);
            }

            WR1_PROG(REG_0014H, 0x00000000U);
            WAIT_STS(REG_0118H, 8, 0);
            WR1_PROG(REG_0040H, 0x00001600U);

            WAIT_STS(REG_0118H, 4, 1);

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003801U);

            static const uint32_t Param_peff_func100_011[] =
            {
                BSWAP_32BIG_C(0x81a13868U), BSWAP_32BIG_C(0x8bff1a38U), BSWAP_32BIG_C(0xa3af98bcU), BSWAP_32BIG_C(
                    0xed9aa5afU),
            };
            r_rsip_func100(Param_peff_func100_011);
            r_rsip_func103();

            r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

            r_rsip_func_sub005(0x80010020U, 0x03410005U, 0x0001000dU);

            WR1_PROG(REG_0094H, 0x000034c1U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ef05U, 0x00000000U);

            static const uint32_t Param_peff_func101_011[] =
            {
                BSWAP_32BIG_C(0xb33ddbaaU), BSWAP_32BIG_C(0xc2b95b84U), BSWAP_32BIG_C(0xa878194cU), BSWAP_32BIG_C(
                    0xd05843f9U),
            };
            r_rsip_func101(Param_peff_func101_011);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x0000b4c0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ef05U, 0x00000000U);

            static const uint32_t Param_peff_func101_012[] =
            {
                BSWAP_32BIG_C(0xcd467e90U), BSWAP_32BIG_C(0x1b45c4d8U), BSWAP_32BIG_C(0xe42c1f6bU), BSWAP_32BIG_C(
                    0xd522d66dU),
            };
            r_rsip_func101(Param_peff_func101_012);
            r_rsip_func044();

            static const uint32_t Param_peff_func100_012[] =
            {
                BSWAP_32BIG_C(0xd1bc3da6U), BSWAP_32BIG_C(0xa7def8ddU), BSWAP_32BIG_C(0x6bda8020U), BSWAP_32BIG_C(
                    0x97160018U),
            };
            r_rsip_func100(Param_peff_func100_012);
            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            WR1_PROG(REG_0094H, 0x00007c00U);
            WR1_PROG(REG_0040H, 0x00600000U);

            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
            {
                static const uint32_t Param_peff_func100_013[] =
                {
                    BSWAP_32BIG_C(0xf6f108baU), BSWAP_32BIG_C(0xe7937aabU), BSWAP_32BIG_C(0xe23733b2U), BSWAP_32BIG_C(
                        0xffa4efefU),
                };
                r_rsip_func100(Param_peff_func100_013);
                r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00450021U, 0x00001022U);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[5]);

                static const uint32_t Param_peff_func100_014[] =
                {
                    BSWAP_32BIG_C(0x838a72d8U), BSWAP_32BIG_C(0x150c8e46U), BSWAP_32BIG_C(0x168ee76fU), BSWAP_32BIG_C(
                        0x2abeec3fU),
                };
                r_rsip_func100(Param_peff_func100_014);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func101_013[] =
                {
                    BSWAP_32BIG_C(0x0243d168U), BSWAP_32BIG_C(0xc93c9700U), BSWAP_32BIG_C(0x51e1e495U), BSWAP_32BIG_C(
                        0xcfcdbbbaU),
                };
                r_rsip_func101(Param_peff_func101_013);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
            {
                static const uint32_t Param_peff_func100_015[] =
                {
                    BSWAP_32BIG_C(0x01826cffU), BSWAP_32BIG_C(0xeb28bdd7U), BSWAP_32BIG_C(0x5885fa89U), BSWAP_32BIG_C(
                        0xc2706519U),
                };
                r_rsip_func100(Param_peff_func100_015);
                r_rsip_func_sub004(0x40000200U, 0xe7009d07U, 0x00450031U, 0x00001032U);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[5]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[9]);

                static const uint32_t Param_peff_func100_016[] =
                {
                    BSWAP_32BIG_C(0xdc2c8e7eU), BSWAP_32BIG_C(0x386d4a24U), BSWAP_32BIG_C(0x59cd3a69U), BSWAP_32BIG_C(
                        0xa84d4376U),
                };
                r_rsip_func100(Param_peff_func100_016);
                r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[13]);

                static const uint32_t Param_peff_func101_014[] =
                {
                    BSWAP_32BIG_C(0x0bacbbe3U), BSWAP_32BIG_C(0x2af9464bU), BSWAP_32BIG_C(0xcfd57c96U), BSWAP_32BIG_C(
                        0x717ee693U),
                };
                r_rsip_func101(Param_peff_func101_014);
            }

            static const uint32_t Param_peff_func100_017[] =
            {
                BSWAP_32BIG_C(0xc1d9a534U), BSWAP_32BIG_C(0x1e70ed82U), BSWAP_32BIG_C(0x390a25c8U), BSWAP_32BIG_C(
                    0x64e83dcaU),
            };
            r_rsip_func100(Param_peff_func100_017);
            r_rsip_func_sub017(0x81010020U, 0x00005006U);
            RD1_ADDR(REG_002CH, &OutData_KDFInfo[0]);

            static const uint32_t Param_peff_func102_003[] =
            {
                BSWAP_32BIG_C(0x0c115460U), BSWAP_32BIG_C(0x7101a3e6U), BSWAP_32BIG_C(0x84657003U), BSWAP_32BIG_C(
                    0xba37eb5fU),
            };
            r_rsip_func102(Param_peff_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
