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

rsip_ret_t r_rsip_p19 (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[],
                       uint64_t       MAX_CNT)
{
    uint64_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00190001U, 0x000008c8U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00000019U);

    static const uint32_t Param_p19_func101_001[] =
    {
        BSWAP_32BIG_C(0x001b32f4U), BSWAP_32BIG_C(0x9fc51ec7U), BSWAP_32BIG_C(0xd029cc80U), BSWAP_32BIG_C(0x9b6cde81U),
    };
    r_rsip_func101(Param_p19_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000026U);

    r_rsip_func_sub003(0x800103a0U, 0x00000019U);

    static const uint32_t Param_p19_func101_002[] =
    {
        BSWAP_32BIG_C(0x55d624e3U), BSWAP_32BIG_C(0x998d1936U), BSWAP_32BIG_C(0x455d5e96U), BSWAP_32BIG_C(0x8ecec968U),
    };
    r_rsip_func101(Param_p19_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xe8009107U);

    for (iLoop = 0U; iLoop < 8U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1404H, 0x19100000U);
    r_rsip_func_sub001(0x00c20021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p19_func100_001[] =
    {
        BSWAP_32BIG_C(0xf2556ae3U), BSWAP_32BIG_C(0x604d314dU), BSWAP_32BIG_C(0xd9e9efecU), BSWAP_32BIG_C(0xf4683450U),
    };
    r_rsip_func100(Param_p19_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p19_func102_001[] =
        {
            BSWAP_32BIG_C(0x52956e58U), BSWAP_32BIG_C(0x8090efbfU), BSWAP_32BIG_C(0x195701c3U), BSWAP_32BIG_C(
                0x6eec9c70U),
        };
        r_rsip_func102(Param_p19_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000001c7U, 0x80020000U);
        WR2_ADDR(REG_1420H, &InData_MsgLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x00000bffU, 0x30008800U, 0xffffffffU, 0x00030020U);
        r_rsip_func_sub021(0x3000a820U, 0xfffffdffU, 0x00050020U, 0x1000d3e0U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1600H, 0x00000080U);

        r_rsip_func_sub006(0x38008be0U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p19_func100_002[] =
        {
            BSWAP_32BIG_C(0xb9bbea0aU), BSWAP_32BIG_C(0x09e927b6U), BSWAP_32BIG_C(0x32b3f4d2U), BSWAP_32BIG_C(
                0xd5cccf8fU),
        };
        r_rsip_func100(Param_p19_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p19_func102_002[] =
            {
                BSWAP_32BIG_C(0xd5bd341bU), BSWAP_32BIG_C(0xec484dc2U), BSWAP_32BIG_C(0xecc5a082U), BSWAP_32BIG_C(
                    0x7b17aa94U),
            };
            r_rsip_func102(Param_p19_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub024(0x000007c2U, 0x00000100U, 0x08008107U);
            WR1_PROG(REG_1404H, 0x1c300000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Signature[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Signature[4]);
            r_rsip_func_sub001(0x00c20021U);

            static const uint32_t Param_p19_func100_003[] =
            {
                BSWAP_32BIG_C(0x31890f62U), BSWAP_32BIG_C(0x2a971356U), BSWAP_32BIG_C(0x70a996cbU), BSWAP_32BIG_C(
                    0x4c52d809U),
            };
            r_rsip_func100(Param_p19_func100_003);
            r_rsip_func_sub021(0x00000842U, 0x0c00a420U, 0x00000200U, 0x00802402U);

            r_rsip_func_sub016(0x81020000U, 0x0000500aU);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

            WR1_PROG(REG_2000H, 0x00000001U);

            WR1_PROG(REG_2004H, 0x000000b0U);

            r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

            WR1_PROG(REG_1404H, 0x1c300000U);
            r_rsip_func_sub001(0x01430021U);

            WR1_PROG(REG_1404H, 0x19100000U);
            r_rsip_func_sub001(0x01430021U);

            WR1_PROG(REG_1444H, 0x00020064U);

            for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffffffffffff0U); )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
                iLoop = iLoop + 16U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = (MAX_CNT & 0xfffffffffffffff0U); iLoop < MAX_CNT; iLoop++)
            {
                WR1_PROG(REG_1420H, InData_Msg[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000000U);

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub023(0x00000821U, 0x00000842U, 0x80900001U);
            r_rsip_func_sub001(0x03450041U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000003fU);

            for (iLoop = 0U; iLoop < 32U; iLoop++)
            {
                r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                WR1_PROG(REG_1600H, 0x00002c20U);
                WR1_PROG(REG_1600H, 0x00003060U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x81900001U);

            WR1_PROG(REG_1404H, 0x1a000000U);
            r_rsip_func_sub001(0x00c90021U);

            WR1_PROG(REG_1404H, 0x1a500000U);
            r_rsip_func_sub001(0x00c90021U);

            WR1_PROG(REG_1004H, 0x00000000U);
            WR1_PROG(REG_1004H, 0x04040000U);

            static const uint32_t Param_p19_func100_004[] =
            {
                BSWAP_32BIG_C(0x6b42fd6bU), BSWAP_32BIG_C(0x3449d7dcU), BSWAP_32BIG_C(0x50dd60e8U), BSWAP_32BIG_C(
                    0xbf8a8cecU),
            };
            r_rsip_func100(Param_p19_func100_004);
            r_rsip_func406(InData_DomainParam);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0EEC73D2U),
                     bswap_32big(0x17F5BE65U),
                     bswap_32big(0xCB5C63AAU),
                     bswap_32big(0x97A331B5U));
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0665E1DBU),
                     bswap_32big(0x6EABA043U),
                     bswap_32big(0xF98B4BAAU),
                     bswap_32big(0x9C78F954U));
            r_rsip_func_sub001(0x00c20021U);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000a20U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1010H, 0x00000010U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000a70U, 0x00000200U, 0x000000c0U);
            r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
            r_rsip_func_sub007(0x000003e0U, 0x000002a0U, 0x000000c0U);
            r_rsip_func_sub005(0x000009d0U, 0x04040005U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14300000U);
            r_rsip_func_sub001(0x00c000f1U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000001fU);

            WR1_PROG(REG_1404H, 0x19100000U);
            WR1_PROG(REG_1608H, 0x80880001U);
            r_rsip_func_sub001(0x03430021U);

            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                WR1_PROG(REG_1600H, 0x00002c20U);
                WR1_PROG(REG_1600H, 0x00003060U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x02003801U, 0x00003440U);
            r_rsip_func_sub021(0x00076800U, 0x000037e0U, 0x00008c40U, 0x0000007FU);
            r_rsip_func_sub023(0x02003c41U, 0x00000800U, 0x81880000U);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub001(0x00c90021U);

            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000004d0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000004d0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);

            WR1_PROG(REG_1014H, 0x000004d0U);
            WR1_PROG(REG_1018H, 0x00000ac0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000250U, 0x000002a0U, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000250U, 0x00000160U, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000390U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000390U, 0x000002a0U, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000340U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040005U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000340U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x12800000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            WR1_PROG(REG_1014H, 0x00000070U);
            WR1_PROG(REG_1018H, 0x000002a0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000003e0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p19_func100_005[] =
            {
                BSWAP_32BIG_C(0x1f89d167U), BSWAP_32BIG_C(0x0d317a0cU), BSWAP_32BIG_C(0x7810843aU), BSWAP_32BIG_C(
                    0x3ba8dc3bU),
            };
            r_rsip_func100(Param_p19_func100_005);
            r_rsip_func_sub013(0x00000250U, 0x000003e0U, 0x00000070U, 0x000002a0U, 0x0404000fU, 0x00010001U);
            r_rsip_func_sub007(0x000002f0U, 0x000002a0U, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000390U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x0FFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU));
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFFU),
                     bswap_32big(0xFFFFFFFEU));
            r_rsip_func_sub001(0x00c20021U);

            static const uint32_t Param_p19_func100_006[] =
            {
                BSWAP_32BIG_C(0x7c70b179U), BSWAP_32BIG_C(0x97c68724U), BSWAP_32BIG_C(0x4c3e1871U), BSWAP_32BIG_C(
                    0x9c461616U),
            };
            r_rsip_func100(Param_p19_func100_006);
            r_rsip_func_sub013(0x00000390U, 0x00000250U, 0x00000070U, 0x000003e0U, 0x0404000fU, 0x00010001U);
            r_rsip_func_sub007(0x000003e0U, 0x000001b0U, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x000002f0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);
            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_1018H, 0x00000ac0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000340U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x00000340U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);

            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000070U, 0x00000390U, 0x00000250U, 0x04040006U);

            WR1_PROG(REG_1404H, 0x14100000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000002f0U, 0x00000390U, 0x00000ac0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000390U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p19_func100_007[] =
            {
                BSWAP_32BIG_C(0x1edc2a2eU), BSWAP_32BIG_C(0x32ac9153U), BSWAP_32BIG_C(0x494bdf4dU), BSWAP_32BIG_C(
                    0xe86b6955U),
            };
            r_rsip_func100(Param_p19_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x000002f0U, 0x00000250U, 0x00000ac0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p19_func100_008[] =
                {
                    BSWAP_32BIG_C(0x58d7f675U), BSWAP_32BIG_C(0x969077d2U), BSWAP_32BIG_C(0xe5de2d28U), BSWAP_32BIG_C(
                        0x986e9ea8U),
                };
                r_rsip_func100(Param_p19_func100_008);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0xd4cfa273U);

                    static const uint32_t Param_p19_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x6c687933U), BSWAP_32BIG_C(0x5ee2fa1aU), BSWAP_32BIG_C(0x56161375U),
                        BSWAP_32BIG_C(0xdd82d05bU),
                    };
                    r_rsip_func101(Param_p19_func101_003);
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x000003e0U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000250U);
                    WR1_PROG(REG_1010H, 0x00000008U);

                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x12800000U);
                    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
                    WR4_PROG(REG_1420H,
                             bswap_32big(0x2B832480U),
                             bswap_32big(0x4FC1DF0BU),
                             bswap_32big(0x2B4D0099U),
                             bswap_32big(0x3DFBD7A7U));
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_PROG(REG_1420H,
                             bswap_32big(0x2F431806U),
                             bswap_32big(0xAD2FE478U),
                             bswap_32big(0xC4EE1B27U),
                             bswap_32big(0x4A0EA0B0U));
                    r_rsip_func_sub001(0x00c20021U);

                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_1018H, 0x000002a0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000003e0U);
                    WR1_PROG(REG_1010H, 0x00000008U);

                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xca9e321cU), BSWAP_32BIG_C(0x1a0300daU), BSWAP_32BIG_C(0x296652d1U),
                        BSWAP_32BIG_C(0x90e95f26U),
                    };
                    r_rsip_func101(Param_p19_func101_004);
                }

                static const uint32_t Param_p19_func101_005[] =
                {
                    BSWAP_32BIG_C(0x3f231481U), BSWAP_32BIG_C(0xf7e00a43U), BSWAP_32BIG_C(0x95a6f5dfU), BSWAP_32BIG_C(
                        0x050706d1U),
                };
                r_rsip_func101(Param_p19_func101_005);
            }
            else
            {
                static const uint32_t Param_p19_func101_006[] =
                {
                    BSWAP_32BIG_C(0xe69b1d96U), BSWAP_32BIG_C(0xd1b1cb00U), BSWAP_32BIG_C(0x8c45f536U), BSWAP_32BIG_C(
                        0xebd571d9U),
                };
                r_rsip_func101(Param_p19_func101_006);
            }

            r_rsip_func_sub006(0x38008800U, 0xd4cfa273U, 0x00260000U);

            static const uint32_t Param_p19_func100_009[] =
            {
                BSWAP_32BIG_C(0x5709d7afU), BSWAP_32BIG_C(0x10de8807U), BSWAP_32BIG_C(0xda6649f8U), BSWAP_32BIG_C(
                    0x52b49393U),
            };
            r_rsip_func100(Param_p19_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p19_func102_003[] =
                {
                    BSWAP_32BIG_C(0x57170f45U), BSWAP_32BIG_C(0x7492f626U), BSWAP_32BIG_C(0x059e71bdU), BSWAP_32BIG_C(
                        0x6430cdbfU),
                };
                r_rsip_func102(Param_p19_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1b100000U);
                r_rsip_func_sub001(0x00c000f1U);

                r_rsip_func_sub030(0x13c00000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x0000b420U, 0x0000001fU, 0x02003841U, 0x00008c40U);
                r_rsip_func_sub006(0x00000001U, 0x3800085fU, 0x00260000U);

                static const uint32_t Param_p19_func100_010[] =
                {
                    BSWAP_32BIG_C(0x04f96973U), BSWAP_32BIG_C(0x83047dbbU), BSWAP_32BIG_C(0x0be2a2e1U), BSWAP_32BIG_C(
                        0x6bc4218dU),
                };
                r_rsip_func100(Param_p19_func100_010);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1014H, 0x000003e0U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000480U);
                    WR1_PROG(REG_1010H, 0x00000008U);

                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x59ff83e6U), BSWAP_32BIG_C(0x17ef5b9dU), BSWAP_32BIG_C(0x0d474589U),
                        BSWAP_32BIG_C(0xde9739dcU),
                    };
                    r_rsip_func101(Param_p19_func101_007);
                }
                else
                {
                    r_rsip_func_sub002(0x00000070U, 0x000003e0U, 0x00000250U, 0x04040006U);

                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000480U);
                    WR1_PROG(REG_1010H, 0x00000008U);

                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    static const uint32_t Param_p19_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x2a7ee098U), BSWAP_32BIG_C(0x9ad03f87U), BSWAP_32BIG_C(0x376ae2bfU),
                        BSWAP_32BIG_C(0x9c6e6722U),
                    };
                    r_rsip_func101(Param_p19_func101_008);
                }

                WR1_PROG(REG_1010H, 0x00000008U);

                WR1_PROG(REG_1404H, 0x15000000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x16900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x1b400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x1b900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x1be00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                r_rsip_func_sub030(0x19b00000U, 0x00000bffU, 0x8088001fU);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

                r_rsip_func_sub003(0x800103a0U, 0x00000019U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p19_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x3bb4f2c7U), BSWAP_32BIG_C(0x23226412U), BSWAP_32BIG_C(0x6e28ca8fU),
                        BSWAP_32BIG_C(0xc137cf42U),
                    };
                    r_rsip_func101(Param_p19_func101_009);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p19_func101_010[] =
                    {
                        BSWAP_32BIG_C(0xfddab528U), BSWAP_32BIG_C(0x6c368f90U), BSWAP_32BIG_C(0x4e21ada5U),
                        BSWAP_32BIG_C(0x20d84629U),
                    };
                    r_rsip_func101(Param_p19_func101_010);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x00000cf0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000d40U, 0x0404000aU);

                WR1_PROG(REG_1444H, 0x000007c7U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x80880001U);
                for (iLoop = 8; iLoop < 16U; iLoop++)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, InData_Signature[iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub030(0x19600000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_1404H, 0x12300000U);
                r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
                WR4_PROG(REG_1420H,
                         bswap_32big(0x0EEC73D2U),
                         bswap_32big(0x17F5BE65U),
                         bswap_32big(0xCB5C63AAU),
                         bswap_32big(0x97A331B5U));
                WAIT_STS(REG_1444H, 31, 1);
                WR4_PROG(REG_1420H,
                         bswap_32big(0x0665E1DBU),
                         bswap_32big(0x6EABA043U),
                         bswap_32big(0xF98B4BAAU),
                         bswap_32big(0x9C78F954U));
                r_rsip_func_sub001(0x00c20021U);

                WR1_PROG(REG_1404H, 0x12800000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1014H, 0x000002a0U);
                WR1_PROG(REG_1018H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                WR1_PROG(REG_1020H, 0x000002f0U);
                WR1_PROG(REG_1010H, 0x00000010U);

                WR1_PROG(REG_1004H, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                r_rsip_func_sub007(0x00000980U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x000003e0U, 0x000002f0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000980U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1010H, 0x00000008U);

                static const uint32_t Param_p19_func100_011[] =
                {
                    BSWAP_32BIG_C(0x13529bdaU), BSWAP_32BIG_C(0x3c2e69deU), BSWAP_32BIG_C(0x3b0eb06fU), BSWAP_32BIG_C(
                        0x2b7717cbU),
                };
                r_rsip_func100(Param_p19_func100_011);
                r_rsip_func401(InData_DomainParam);

                WR1_PROG(REG_1404H, 0x15000000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16400000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1404H, 0x16900000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                WR1_PROG(REG_1404H, 0x16e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000026U);
                r_rsip_func_sub001(0x00c00015U);
                r_rsip_func_sub001(0x00c2000dU);
                r_rsip_func_sub001(0x00020005U);

                r_rsip_func_sub030(0x19600000U, 0x00000bffU, 0x8088001fU);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

                r_rsip_func_sub003(0x800103a0U, 0x00000119U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p19_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x9cef4dc9U), BSWAP_32BIG_C(0x7f44facbU), BSWAP_32BIG_C(0xd2f07f98U),
                        BSWAP_32BIG_C(0xad11a491U),
                    };
                    r_rsip_func101(Param_p19_func101_011);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p19_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x60e155d5U), BSWAP_32BIG_C(0x5eb44f02U), BSWAP_32BIG_C(0x7ffe0b1cU),
                        BSWAP_32BIG_C(0xa94f3bfcU),
                    };
                    r_rsip_func101(Param_p19_func101_012);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000750U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

                WR1_PROG(REG_1404H, 0x12300000U);
                r_rsip_func_sub001(0x00c00021U);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000ca0U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x04040006U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000ca0U, 0x00000b10U, 0x00000570U, 0x0404000aU);

                r_rsip_func_sub002(0x00000cf0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000d40U, 0x00000b10U, 0x00000610U, 0x0404000aU);

                r_rsip_func404();

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);

                WR1_PROG(REG_1014H, 0x00000610U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000250U);
                WR1_PROG(REG_1010H, 0x00000008U);

                WR1_PROG(REG_1004H, 0x04040004U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x12d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x04040006U);

                static const uint32_t Param_p19_func100_012[] =
                {
                    BSWAP_32BIG_C(0x56edf6ccU), BSWAP_32BIG_C(0xab944d61U), BSWAP_32BIG_C(0xa448d41dU), BSWAP_32BIG_C(
                        0x99e63537U),
                };
                r_rsip_func100(Param_p19_func100_012);
                r_rsip_func_sub013(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00010001U);
                r_rsip_func_sub007(0x00000570U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x000005c0U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub030(0x12800000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub022(0x00003801U, 0x00008c00U, 0x7fffffffU);

                r_rsip_func_sub012(0x12300000U, 0x0000b420U, 0x00000020U);
                WR1_PROG(REG_1608H, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub021(0x0000b420U, 0x0000003cU, 0x00003841U, 0x001f6c42U);
                r_rsip_func_sub021(0x00001002U, 0x00000821U, 0x00003c01U, 0x00000800U);
                r_rsip_func_sub021(0x00000821U, 0x00000842U, 0x0000b460U, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub030(0x12300000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_1404H, 0x14100000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x00000c50U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000c50U, 0x00000250U, 0x000002a0U, 0x0404000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p19_func100_013[] =
                {
                    BSWAP_32BIG_C(0x02bf6fcfU), BSWAP_32BIG_C(0x99992eccU), BSWAP_32BIG_C(0x99e8e91bU), BSWAP_32BIG_C(
                        0x56fa2ce1U),
                };
                r_rsip_func100(Param_p19_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p19_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x97247c18U), BSWAP_32BIG_C(0xdead177fU), BSWAP_32BIG_C(0x1aa0050bU),
                        BSWAP_32BIG_C(0x95597667U),
                    };
                    r_rsip_func102(Param_p19_func102_004);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p19_func102_005[] =
                    {
                        BSWAP_32BIG_C(0xac87ba00U), BSWAP_32BIG_C(0x30ca0b6eU), BSWAP_32BIG_C(0xa225e1bcU),
                        BSWAP_32BIG_C(0x37fd9dcfU),
                    };
                    r_rsip_func102(Param_p19_func102_005);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
