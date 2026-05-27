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

rsip_ret_t r_rsip_pef (const uint32_t InData_InitVal[],
                       const uint32_t InData_Msg1[],
                       const uint32_t InData_Msg1Length[],
                       const uint32_t InData_EncMsg[],
                       const uint32_t InData_EncMsgLength[],
                       const uint32_t InData_Msg2[],
                       const uint32_t InData_Msg2Length[],
                       const uint32_t InData_OutDataType[],
                       uint32_t       OutData_MsgDigest[],
                       uint32_t       OutData_KDFInfo[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00ef0001U, 0x000003c7U, 0x80040040U);
    WR1_PROG(REG_002CH, InData_OutDataType[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_Msg1Length[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_Msg2Length[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3420a840U, 0x00000002U, 0x2000b440U);
    WR1_PROG(REG_0094H, 0x00000001U);

    r_rsip_func_sub007(0x38008c80U, 0xffffffdfU, 0x00A60000U);

    r_rsip_func_sub007(0x3420a8a0U, 0x00000009U, 0x00260000U);

    r_rsip_func_sub016(0x00000800U, 0x00002403U, 0x00002404U);
    WR1_PROG(REG_0094H, 0x00002405U);

    r_rsip_func_sub007(0x38008c00U, 0x0000003fU, 0x00A60000U);

    static const uint32_t Param_pef_func100_001[] =
    {
        BSWAP_32BIG_C(0x696ca684U), BSWAP_32BIG_C(0x704fd1ceU), BSWAP_32BIG_C(0x8647501eU), BSWAP_32BIG_C(0x48458f0aU),
    };
    r_rsip_func100(Param_pef_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pef_func102_001[] =
        {
            BSWAP_32BIG_C(0x14db3da2U), BSWAP_32BIG_C(0x0d170b37U), BSWAP_32BIG_C(0x7ac66831U), BSWAP_32BIG_C(
                0xab5d72f3U),
        };
        r_rsip_func102(Param_pef_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub016(0x0000b420U, 0x00000010U, 0x00003c41U);

        WR1_PROG(REG_0094H, 0x00000821U);

        r_rsip_func_sub007(0x00003405U, 0x38000c84U, 0x00A60000U);

        static const uint32_t Param_pef_func100_002[] =
        {
            BSWAP_32BIG_C(0x4481ba76U), BSWAP_32BIG_C(0x393be736U), BSWAP_32BIG_C(0x735aef59U), BSWAP_32BIG_C(
                0xf41bd278U),
        };
        r_rsip_func100(Param_pef_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            static const uint32_t Param_pef_sub100_001[] =
            {
                BSWAP_32BIG_C(0x0000ef01U), BSWAP_32BIG_C(0x33fc4b5bU), BSWAP_32BIG_C(0x58e86718U),
                BSWAP_32BIG_C(0x8f4cf43cU),
                BSWAP_32BIG_C(0xdab2838dU), BSWAP_32BIG_C(0x0000ef01U), BSWAP_32BIG_C(0x341357b6U),
                BSWAP_32BIG_C(0x638d8023U),
                BSWAP_32BIG_C(0xfcf8dcc0U),
                BSWAP_32BIG_C(0x7539d571U), 0x00001404U,
            };
            r_rsip_func_sub100(InData_EncMsg, Param_pef_sub100_001, RSIP_SEL_BIT_LENGTH_256);

            static const uint32_t Param_pef_func100_003[] =
            {
                BSWAP_32BIG_C(0x3e268571U), BSWAP_32BIG_C(0x4418e672U), BSWAP_32BIG_C(0x24651cdaU), BSWAP_32BIG_C(
                    0xc631e030U),
            };
            r_rsip_func100(Param_pef_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00002c20U);
                static const uint32_t Param_pef_func101_001[] =
                {
                    BSWAP_32BIG_C(0x53e9821eU), BSWAP_32BIG_C(0xe29359c2U), BSWAP_32BIG_C(0xefff844eU), BSWAP_32BIG_C(
                        0x3a60df2cU),
                };
                r_rsip_func101(Param_pef_func101_001);
            }

            static const uint32_t Param_pef_func101_002[] =
            {
                BSWAP_32BIG_C(0xdc6aac19U), BSWAP_32BIG_C(0x3670fbeaU), BSWAP_32BIG_C(0xe257baabU), BSWAP_32BIG_C(
                    0x0a90a920U),
            };
            r_rsip_func101(Param_pef_func101_002);
        }

        WR1_PROG(REG_0094H, 0x38000c21U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00A60000U);

        static const uint32_t Param_pef_func100_004[] =
        {
            BSWAP_32BIG_C(0x7da5a0eaU), BSWAP_32BIG_C(0xa6fd16e0U), BSWAP_32BIG_C(0x1b2f935fU), BSWAP_32BIG_C(
                0x2fd43e0fU),
        };
        r_rsip_func100(Param_pef_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);
        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pef_func102_002[] =
            {
                BSWAP_32BIG_C(0x60afac5cU), BSWAP_32BIG_C(0xeb8418a2U), BSWAP_32BIG_C(0xd69ec92fU), BSWAP_32BIG_C(
                    0x38f68456U),
            };
            r_rsip_func102(Param_pef_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00F4H, 0x00000010U);

            WR1_PROG(REG_0014H, 0x000007c4U);
            WAIT_STS(REG_0014H, 31, 1);
            WR8_ADDR(REG_002CH, &InData_InitVal[0]);

            WR1_PROG(REG_00F4H, 0x00000011U);

            WR1_PROG(REG_0094H, 0x00000821U);

            r_rsip_func_sub007(0x00003c01U, 0x38000c63U, 0x00A60000U);

            static const uint32_t Param_pef_func100_005[] =
            {
                BSWAP_32BIG_C(0xb980043fU), BSWAP_32BIG_C(0xd69b0853U), BSWAP_32BIG_C(0xaf720807U), BSWAP_32BIG_C(
                    0x2d8d8e78U),
            };
            r_rsip_func100(Param_pef_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pef_func100_006[] =
                {
                    BSWAP_32BIG_C(0x1e05cf35U), BSWAP_32BIG_C(0xf62dc2fbU), BSWAP_32BIG_C(0x82aafce6U), BSWAP_32BIG_C(
                        0x8c985fc7U),
                };
                r_rsip_func100(Param_pef_func100_006);

                r_rsip_func_sub016(0x00000800U, 0x00003443U, 0x0000a440U);
                WR1_PROG(REG_0094H, 0x00000003U);
                r_rsip_func_sub015(0x00026842U, 0x81010040U, 0x00005006U);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                WR1_PROG(REG_0094H, 0x000008a5U);

                WR1_PROG(REG_0094H, 0x000008c6U);

                for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
                {
                    WR1_PROG(REG_0014H, 0x000000c7U);
                    WR1_PROG(REG_009CH, 0x80010020U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR1_PROG(REG_002CH, InData_Msg1[iLoop]);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    WR1_PROG(REG_0094H, 0x000008e7U);

                    for (jLoop = 0U; jLoop < 4; jLoop++)
                    {
                        WR1_PROG(REG_0094H, 0x01886c01U);
                        r_rsip_func_sub007(0x00086c21U, 0x342028a3U, 0x00260000U);
                        static const uint32_t Param_pef_func100_007[] =
                        {
                            BSWAP_32BIG_C(0xef3f4551U), BSWAP_32BIG_C(0xbc5b3433U), BSWAP_32BIG_C(0x90f75e47U),
                            BSWAP_32BIG_C(0x2072ca2dU),
                        };
                        r_rsip_func100(Param_pef_func100_007);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                            r_rsip_func_sub009(0x11490005U, 0x00002ca0U);
                            static const uint32_t Param_pef_func101_003[] =
                            {
                                BSWAP_32BIG_C(0x3990559eU), BSWAP_32BIG_C(0x4e4baaf0U), BSWAP_32BIG_C(0x6b5f1a49U),
                                BSWAP_32BIG_C(0x3fc5e7bcU),
                            };
                            r_rsip_func101(Param_pef_func101_003);
                        }

                        WR1_PROG(REG_0094H, 0x00002ce0U);

                        static const uint32_t Param_pef_func101_004[] =
                        {
                            BSWAP_32BIG_C(0x15532271U), BSWAP_32BIG_C(0x88991257U), BSWAP_32BIG_C(0x551aeab2U),
                            BSWAP_32BIG_C(0x95c69f47U),
                        };
                        r_rsip_func101(Param_pef_func101_004);
                    }

                    r_rsip_func_sub007(0x380088e0U, 0x00000004U, 0x00260000U);
                    WR1_PROG(REG_0040H, 0x00402000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    WR1_PROG(REG_0094H, 0x00002cc0U);

                    static const uint32_t Param_pef_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xd2f1c8acU), BSWAP_32BIG_C(0xef8d15c8U), BSWAP_32BIG_C(0xff7cf5cfU),
                        BSWAP_32BIG_C(0xfb879120U),
                    };
                    r_rsip_func101(Param_pef_func101_005);
                }

                r_rsip_func_sub010(0x380008c2U);

                static const uint32_t Param_pef_func101_006[] =
                {
                    BSWAP_32BIG_C(0x3d3520d1U), BSWAP_32BIG_C(0x11ba7f6aU), BSWAP_32BIG_C(0x380a503cU), BSWAP_32BIG_C(
                        0x2ade55eeU),
                };
                r_rsip_func101(Param_pef_func101_006);
            }

            WR1_PROG(REG_0094H, 0x38000c84U);
            WR1_PROG(REG_009CH, 0x00000080U);
            WR1_PROG(REG_0040H, 0x00A60000U);

            static const uint32_t Param_pef_func100_008[] =
            {
                BSWAP_32BIG_C(0x6823b52dU), BSWAP_32BIG_C(0x76b0d997U), BSWAP_32BIG_C(0xed0e9469U), BSWAP_32BIG_C(
                    0xfcfca565U),
            };
            r_rsip_func100(Param_pef_func100_008);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub004(0x00001804U, 0x11430081U);

                static const uint32_t Param_pef_func101_007[] =
                {
                    BSWAP_32BIG_C(0xbf0375d5U), BSWAP_32BIG_C(0x21774b1aU), BSWAP_32BIG_C(0x695dfa15U), BSWAP_32BIG_C(
                        0xba75648bU),
                };
                r_rsip_func101(Param_pef_func101_007);
            }

            WR1_PROG(REG_0094H, 0x00000821U);
            WR1_PROG(REG_0094H, 0x00003861U);

            static const uint32_t Param_pef_func100_009[] =
            {
                BSWAP_32BIG_C(0xde8d8373U), BSWAP_32BIG_C(0xe1285f51U), BSWAP_32BIG_C(0xedbf96f8U), BSWAP_32BIG_C(
                    0xebc2eb7eU),
            };
            r_rsip_func100(Param_pef_func100_009);

            r_rsip_func_sub016(0x00000800U, 0x00003443U, 0x0000a440U);
            WR1_PROG(REG_0094H, 0x00000003U);
            r_rsip_func_sub015(0x00026842U, 0x81010040U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_0094H, 0x000008a5U);

            WR1_PROG(REG_0094H, 0x000008c6U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x80010020U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Msg2[iLoop]);
                WR1_PROG(REG_0024H, 0x00000000U);

                WR1_PROG(REG_0094H, 0x000008e7U);

                for (jLoop = 0U; jLoop < 4; jLoop++)
                {
                    WR1_PROG(REG_0094H, 0x01886c01U);
                    r_rsip_func_sub007(0x00086c21U, 0x342028a3U, 0x00260000U);
                    static const uint32_t Param_pef_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x802fd208U), BSWAP_32BIG_C(0x852a16bbU), BSWAP_32BIG_C(0x6222a4b9U),
                        BSWAP_32BIG_C(0xee57f4a1U),
                    };
                    r_rsip_func100(Param_pef_func100_010);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub003(0x81010000U, 0x1009000dU);
                        r_rsip_func_sub009(0x11490005U, 0x00002ca0U);
                        static const uint32_t Param_pef_func101_008[] =
                        {
                            BSWAP_32BIG_C(0x9ab12738U), BSWAP_32BIG_C(0xd9cf92fbU), BSWAP_32BIG_C(0xba45b3bcU),
                            BSWAP_32BIG_C(0x04049f16U),
                        };
                        r_rsip_func101(Param_pef_func101_008);
                    }

                    WR1_PROG(REG_0094H, 0x00002ce0U);

                    static const uint32_t Param_pef_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x083b4bf2U), BSWAP_32BIG_C(0xa47d2036U), BSWAP_32BIG_C(0x675b04c9U),
                        BSWAP_32BIG_C(0xbbd48ccbU),
                    };
                    r_rsip_func101(Param_pef_func101_009);
                }

                r_rsip_func_sub007(0x380088e0U, 0x00000004U, 0x00260000U);
                WR1_PROG(REG_0040H, 0x00402000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                WR1_PROG(REG_0094H, 0x00002cc0U);

                static const uint32_t Param_pef_func101_010[] =
                {
                    BSWAP_32BIG_C(0xc7318646U), BSWAP_32BIG_C(0x210e9c83U), BSWAP_32BIG_C(0xf2b77dd2U), BSWAP_32BIG_C(
                        0x25f498cfU),
                };
                r_rsip_func101(Param_pef_func101_010);
            }

            r_rsip_func_sub010(0x380008c2U);

            WAIT_STS(REG_00F8H, 2, 0);

            WR1_PROG(REG_00F4H, 0x00000100U);

            WR1_PROG(REG_0040H, 0x00001600U);

            WR1_PROG(REG_00F4H, 0x00000020U);

            WR1_PROG(REG_0094H, 0x0000b400U);
            WR1_PROG(REG_0094H, 0x00000010U);
            r_rsip_func_sub007(0x00003820U, 0x38000c21U, 0x00260000U);

            static const uint32_t Param_pef_func100_011[] =
            {
                BSWAP_32BIG_C(0xe51c62b4U), BSWAP_32BIG_C(0x45798338U), BSWAP_32BIG_C(0xc0a5abcfU), BSWAP_32BIG_C(
                    0x89534c8bU),
            };
            r_rsip_func100(Param_pef_func100_011);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pef_func100_012[] =
                {
                    BSWAP_32BIG_C(0xe0e1d800U), BSWAP_32BIG_C(0x00766ab0U), BSWAP_32BIG_C(0x7ea2ddcdU), BSWAP_32BIG_C(
                        0x5c42921fU),
                };
                r_rsip_func100(Param_pef_func100_012);

                WR1_PROG(REG_0008H, 0x00004022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD8_ADDR(REG_002CH, &OutData_MsgDigest[0]);

                static const uint32_t Param_pef_func102_003[] =
                {
                    BSWAP_32BIG_C(0xcbc2cd77U), BSWAP_32BIG_C(0x11d02e6eU), BSWAP_32BIG_C(0x46567163U), BSWAP_32BIG_C(
                        0x5b3128efU),
                };
                r_rsip_func102(Param_pef_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
            else
            {
                static const uint32_t Param_pef_func100_013[] =
                {
                    BSWAP_32BIG_C(0x4cb6659eU), BSWAP_32BIG_C(0x07626121U), BSWAP_32BIG_C(0x44d7c138U), BSWAP_32BIG_C(
                        0xb702f23aU),
                };
                r_rsip_func100(Param_pef_func100_013);
                r_rsip_func103();

                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x0000ef02U);

                static const uint32_t Param_pef_func101_011[] =
                {
                    BSWAP_32BIG_C(0x5cf8bd91U), BSWAP_32BIG_C(0x839bd995U), BSWAP_32BIG_C(0xd3b52a8cU), BSWAP_32BIG_C(
                        0xb6c0329fU),
                };
                r_rsip_func101(Param_pef_func101_011);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x01799093U);

                r_rsip_func_sub002(0x800100e0U, 0x0000ef02U);

                static const uint32_t Param_pef_func101_012[] =
                {
                    BSWAP_32BIG_C(0xd4a29238U), BSWAP_32BIG_C(0x101a31f8U), BSWAP_32BIG_C(0x22cc405dU), BSWAP_32BIG_C(
                        0xc608d1e0U),
                };
                r_rsip_func101(Param_pef_func101_012);
                r_rsip_func044();

                static const uint32_t Param_pef_func100_014[] =
                {
                    BSWAP_32BIG_C(0xfc3c89afU), BSWAP_32BIG_C(0xac7169caU), BSWAP_32BIG_C(0x71547106U), BSWAP_32BIG_C(
                        0x5f554f0fU),
                };
                r_rsip_func100(Param_pef_func100_014);
                r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

                r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

                WR1_PROG(REG_00D4H, 0x40000100U);
                r_rsip_func_sub006(0xe7009d07U, 0x00450021U);

                WR1_PROG(REG_0008H, 0x00001022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[5]);

                static const uint32_t Param_pef_func100_015[] =
                {
                    BSWAP_32BIG_C(0x03cb5bc7U), BSWAP_32BIG_C(0x4db758ebU), BSWAP_32BIG_C(0x204f610cU), BSWAP_32BIG_C(
                        0x8d6b6577U),
                };
                r_rsip_func100(Param_pef_func100_015);
                r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                WR1_PROG(REG_00D4H, 0x40000000U);
                r_rsip_func_sub006(0x09108105U, 0x00410011U);

                WR1_PROG(REG_0008H, 0x00001012U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KDFInfo[9]);

                static const uint32_t Param_pef_func100_016[] =
                {
                    BSWAP_32BIG_C(0x7a7c257fU), BSWAP_32BIG_C(0x7228db43U), BSWAP_32BIG_C(0xdbd827c7U), BSWAP_32BIG_C(
                        0x3316f326U),
                };
                r_rsip_func100(Param_pef_func100_016);
                WR1_PROG(REG_009CH, 0x81010000U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_KDFInfo[0]);

                static const uint32_t Param_pef_func102_004[] =
                {
                    BSWAP_32BIG_C(0xe31084a9U), BSWAP_32BIG_C(0xf8f3f4e3U), BSWAP_32BIG_C(0xcf71bfaaU), BSWAP_32BIG_C(
                        0x94b9f8f8U),
                };
                r_rsip_func102(Param_pef_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
