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

rsip_ret_t r_rsip_p11 (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00110001U, 0x000007f0U);

    static const uint32_t Param_p11_func100_001[] =
    {
        BSWAP_32BIG_C(0xb103b486U), BSWAP_32BIG_C(0x83ed4464U), BSWAP_32BIG_C(0x6344798cU), BSWAP_32BIG_C(0xeecedabbU),
    };
    r_rsip_func100(Param_p11_func100_001);
    r_rsip_func086(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0909000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003e0U, 0x09090010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001101U);

    static const uint32_t Param_p11_func101_001[] =
    {
        BSWAP_32BIG_C(0x42fc2300U), BSWAP_32BIG_C(0x8a8dfa7eU), BSWAP_32BIG_C(0x2671a38bU), BSWAP_32BIG_C(0xd7b72925U),
    };
    r_rsip_func101(Param_p11_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001102U);

    static const uint32_t Param_p11_func101_002[] =
    {
        BSWAP_32BIG_C(0x24d983c0U), BSWAP_32BIG_C(0xcdf28ca5U), BSWAP_32BIG_C(0x1300bc10U), BSWAP_32BIG_C(0x3f36b533U),
    };
    r_rsip_func101(Param_p11_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001103U);

    static const uint32_t Param_p11_func101_003[] =
    {
        BSWAP_32BIG_C(0x15ea59efU), BSWAP_32BIG_C(0x53c69a43U), BSWAP_32BIG_C(0x344ea90eU), BSWAP_32BIG_C(0x0ae5614fU),
    };
    r_rsip_func101(Param_p11_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001104U);

    static const uint32_t Param_p11_func101_004[] =
    {
        BSWAP_32BIG_C(0x52f46d82U), BSWAP_32BIG_C(0x57636582U), BSWAP_32BIG_C(0x31cc6848U), BSWAP_32BIG_C(0x75e8451aU),
    };
    r_rsip_func101(Param_p11_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00001105U);

    static const uint32_t Param_p11_func101_005[] =
    {
        BSWAP_32BIG_C(0xde428e4dU), BSWAP_32BIG_C(0x43b44a95U), BSWAP_32BIG_C(0xdf56afd9U), BSWAP_32BIG_C(0x3060bfeaU),
    };
    r_rsip_func101(Param_p11_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20009U);
    r_rsip_func_sub001(0x00020009U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub021(0x000003e0U, 0x00000160U, 0x00000020U, 0x09090004U);

    WR1_PROG(REG_1404H, 0x13e80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000430U, 0x00000340U, 0x09090009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

    static const uint32_t Param_p11_func100_002[] =
    {
        BSWAP_32BIG_C(0xc101ac12U), BSWAP_32BIG_C(0x69b6c30aU), BSWAP_32BIG_C(0x27c865f4U), BSWAP_32BIG_C(0xf6e95160U),
    };
    r_rsip_func100(Param_p11_func100_002);
    r_rsip_func087(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000011U);

    static const uint32_t Param_p11_func101_006[] =
    {
        BSWAP_32BIG_C(0x1bd661f0U), BSWAP_32BIG_C(0x8c2ea8ebU), BSWAP_32BIG_C(0x9ef92135U), BSWAP_32BIG_C(0xf793329cU),
    };
    r_rsip_func101(Param_p11_func101_006);
    r_rsip_func091();

    static const uint32_t Param_p11_func100_003[] =
    {
        BSWAP_32BIG_C(0xcb316579U), BSWAP_32BIG_C(0x8e24b11eU), BSWAP_32BIG_C(0xc7cdb982U), BSWAP_32BIG_C(0xd52b2c15U),
    };
    r_rsip_func100(Param_p11_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p11_func102_001[] =
        {
            BSWAP_32BIG_C(0x8a0e868aU), BSWAP_32BIG_C(0x1d90cae9U), BSWAP_32BIG_C(0xf07330ddU), BSWAP_32BIG_C(
                0x2424ba66U),
        };
        r_rsip_func102(Param_p11_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        r_rsip_func_sub021(0x000000c0U, 0x000002f0U, 0x00000020U, 0x09090002U);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10c80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p11_func100_004[] =
        {
            BSWAP_32BIG_C(0x962887e7U), BSWAP_32BIG_C(0xedcfd914U), BSWAP_32BIG_C(0x4c0fa660U), BSWAP_32BIG_C(
                0x9e04e476U),
        };
        r_rsip_func100(Param_p11_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p11_func102_002[] =
            {
                BSWAP_32BIG_C(0x5831f58eU), BSWAP_32BIG_C(0xe2da9811U), BSWAP_32BIG_C(0x50965d66U), BSWAP_32BIG_C(
                    0xc8d85f47U),
            };
            r_rsip_func102(Param_p11_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p11_func100_005[] =
            {
                BSWAP_32BIG_C(0x92e20826U), BSWAP_32BIG_C(0xc3e144edU), BSWAP_32BIG_C(0xad7f1485U), BSWAP_32BIG_C(
                    0x52a08b6fU),
            };
            r_rsip_func100(Param_p11_func100_005);
            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0909000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0909000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x11100000U);
            r_rsip_func_sub001(0x00c00011U);

            r_rsip_func_sub023(0x00000fc2U, 0x00000300U, 0x08008107U);

            WR1_PROG(REG_1404H, 0x11200000U);
            for (iLoop = 0U; iLoop < 16U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_MsgDgst[iLoop]);
                r_rsip_func_sub001(0x00c20011U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000011U);

            static const uint32_t Param_p11_func101_007[] =
            {
                BSWAP_32BIG_C(0xc8721aa1U), BSWAP_32BIG_C(0x7cb308ceU), BSWAP_32BIG_C(0xa75121a2U), BSWAP_32BIG_C(
                    0x20685becU),
            };
            r_rsip_func101(Param_p11_func101_007);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000025U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000011U);

            static const uint32_t Param_p11_func101_008[] =
            {
                BSWAP_32BIG_C(0xd7699770U), BSWAP_32BIG_C(0x38505c18U), BSWAP_32BIG_C(0x469b0415U), BSWAP_32BIG_C(
                    0xc32bb772U),
            };
            r_rsip_func101(Param_p11_func101_008);
            r_rsip_func044();

            r_rsip_func_sub023(0x000013c2U, 0x40000400U, 0xf7009d07U);

            WR1_PROG(REG_1404H, 0x11b00000U);

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

            static const uint32_t Param_p11_func100_006[] =
            {
                BSWAP_32BIG_C(0x6313fcadU), BSWAP_32BIG_C(0x361a2ec1U), BSWAP_32BIG_C(0x41eb99eeU), BSWAP_32BIG_C(
                    0xc65d7adbU),
            };
            r_rsip_func100(Param_p11_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p11_func102_003[] =
                {
                    BSWAP_32BIG_C(0x62673a05U), BSWAP_32BIG_C(0x359b65a2U), BSWAP_32BIG_C(0xef997146U), BSWAP_32BIG_C(
                        0x5c9a3cadU),
                };
                r_rsip_func102(Param_p11_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub022(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x09090005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10c80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p11_func100_007[] =
                {
                    BSWAP_32BIG_C(0xf770b793U), BSWAP_32BIG_C(0x31fb5339U), BSWAP_32BIG_C(0x7f5d8d88U), BSWAP_32BIG_C(
                        0xee20a21fU),
                };
                r_rsip_func100(Param_p11_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p11_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x1497597cU), BSWAP_32BIG_C(0xd6b9bef5U), BSWAP_32BIG_C(0x2f9fed19U),
                        BSWAP_32BIG_C(0xdf871c5dU),
                    };
                    r_rsip_func102(Param_p11_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p11_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xf9fdfb4dU), BSWAP_32BIG_C(0xcd33b420U), BSWAP_32BIG_C(0x5b336872U),
                        BSWAP_32BIG_C(0x81db458aU),
                    };
                    r_rsip_func100(Param_p11_func100_008);
                    WR1_PROG(REG_1404H, 0x12500000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[4]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[8]);

                    static const uint32_t Param_p11_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x119159c1U), BSWAP_32BIG_C(0xe83d5cadU), BSWAP_32BIG_C(0x6e55ccb7U),
                        BSWAP_32BIG_C(0xdd621891U),
                    };
                    r_rsip_func100(Param_p11_func100_009);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830021U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);

                    static const uint32_t Param_p11_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x91db8be3U), BSWAP_32BIG_C(0x71d53c35U), BSWAP_32BIG_C(0xc2397199U),
                        BSWAP_32BIG_C(0x31f93c1bU),
                    };
                    r_rsip_func100(Param_p11_func100_010);
                    WR1_PROG(REG_1404H, 0x11b00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[24]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[28]);

                    static const uint32_t Param_p11_func100_011[] =
                    {
                        BSWAP_32BIG_C(0x97a391d0U), BSWAP_32BIG_C(0x15d994f3U), BSWAP_32BIG_C(0x749950c5U),
                        BSWAP_32BIG_C(0x5a7f0a52U),
                    };
                    r_rsip_func100(Param_p11_func100_011);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830021U);

                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[32]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[36]);

                    static const uint32_t Param_p11_func102_005[] =
                    {
                        BSWAP_32BIG_C(0xd8e1d01eU), BSWAP_32BIG_C(0x8ccd7af7U), BSWAP_32BIG_C(0xa1fae8e2U),
                        BSWAP_32BIG_C(0x1d29b55eU),
                    };
                    r_rsip_func102(Param_p11_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
