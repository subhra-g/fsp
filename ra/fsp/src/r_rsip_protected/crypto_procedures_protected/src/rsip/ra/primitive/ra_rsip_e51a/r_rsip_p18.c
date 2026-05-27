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

rsip_ret_t r_rsip_p18 (const uint32_t InData_PrivKeyIndex[],
                       const uint32_t InData_PubKeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[],
                       uint64_t       MAX_CNT)
{
    uint64_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00180001U, 0x000008c8U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_PrivKeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000018U);

    static const uint32_t Param_p18_func101_001[] =
    {
        BSWAP_32BIG_C(0x94f522baU), BSWAP_32BIG_C(0x0eea8e03U), BSWAP_32BIG_C(0x4595497aU), BSWAP_32BIG_C(0x5cc50199U),
    };
    r_rsip_func101(Param_p18_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000027U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000018U);

    static const uint32_t Param_p18_func101_002[] =
    {
        BSWAP_32BIG_C(0x33f4fda5U), BSWAP_32BIG_C(0x0368fe5eU), BSWAP_32BIG_C(0x8879fbf7U), BSWAP_32BIG_C(0x10a0d100U),
    };
    r_rsip_func101(Param_p18_func101_002);
    r_rsip_func044();

    r_rsip_func_sub023(0x000007c2U, 0x40000100U, 0xf7009d07U);

    for (iLoop = 0U; iLoop < 8U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 1]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1608H, 0x80880000U);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p18_func100_001[] =
    {
        BSWAP_32BIG_C(0x7bb45a99U), BSWAP_32BIG_C(0x4ccccec5U), BSWAP_32BIG_C(0x8ffa3a9aU), BSWAP_32BIG_C(0x4eda35fcU),
    };
    r_rsip_func100(Param_p18_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p18_func102_001[] =
        {
            BSWAP_32BIG_C(0x36aa8486U), BSWAP_32BIG_C(0x7b06a90eU), BSWAP_32BIG_C(0x1d6624ecU), BSWAP_32BIG_C(
                0xdd6da797U),
        };
        r_rsip_func102(Param_p18_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_PubKeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000118U);

        static const uint32_t Param_p18_func101_003[] =
        {
            BSWAP_32BIG_C(0x55ebe36dU), BSWAP_32BIG_C(0x4018b866U), BSWAP_32BIG_C(0x7d3035d5U), BSWAP_32BIG_C(
                0xd9016dd0U),
        };
        r_rsip_func101(Param_p18_func101_003);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000026U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000118U);

        static const uint32_t Param_p18_func101_004[] =
        {
            BSWAP_32BIG_C(0x5ac59946U), BSWAP_32BIG_C(0x12bad022U), BSWAP_32BIG_C(0x377b00deU), BSWAP_32BIG_C(
                0xfa177bf3U),
        };
        r_rsip_func101(Param_p18_func101_004);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub023(0x000007c2U, 0x40000100U, 0xe8009107U);

        for (iLoop = 0U; iLoop < 8U; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_PubKeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x19100000U);
        r_rsip_func_sub001(0x00c20021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_PubKeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p18_func100_002[] =
        {
            BSWAP_32BIG_C(0x554f1971U), BSWAP_32BIG_C(0x7e628bbdU), BSWAP_32BIG_C(0x2669b605U), BSWAP_32BIG_C(
                0xb23c74cfU),
        };
        r_rsip_func100(Param_p18_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p18_func102_002[] =
            {
                BSWAP_32BIG_C(0xf0563577U), BSWAP_32BIG_C(0x04be4d92U), BSWAP_32BIG_C(0xe8b24446U), BSWAP_32BIG_C(
                    0x7f2633ccU),
            };
            r_rsip_func102(Param_p18_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR2_ADDR(REG_1420H, &InData_MsgLen[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub024(0x00000bffU, 0x30008800U, 0xffffffffU, 0x00030020U);
            r_rsip_func_sub024(0x3000a820U, 0xfffffdffU, 0x00050020U, 0x1000d3e0U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1600H, 0x00000080U);
            r_rsip_func_sub006(0x38008be0U, 0x00000001U, 0x00260000U);

            static const uint32_t Param_p18_func100_003[] =
            {
                BSWAP_32BIG_C(0xcfb57323U), BSWAP_32BIG_C(0xb367d1cdU), BSWAP_32BIG_C(0x162ed74fU), BSWAP_32BIG_C(
                    0x10adf402U),
            };
            r_rsip_func100(Param_p18_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p18_func102_003[] =
                {
                    BSWAP_32BIG_C(0x3548e285U), BSWAP_32BIG_C(0x04f27027U), BSWAP_32BIG_C(0x194fe286U), BSWAP_32BIG_C(
                        0x6ae1e54eU),
                };
                r_rsip_func102(Param_p18_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p18_func100_004[] =
                {
                    BSWAP_32BIG_C(0xc19f4c21U), BSWAP_32BIG_C(0xaab90c0eU), BSWAP_32BIG_C(0xdc09dc9eU), BSWAP_32BIG_C(
                        0x08c9bc19U),
                };
                r_rsip_func100(Param_p18_func100_004);
                r_rsip_func_sub024(0x00000842U, 0x0c00a420U, 0x00000100U, 0x00802402U);

                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                static const uint32_t Param_p18_func100_005[] =
                {
                    BSWAP_32BIG_C(0x5e5c29f8U), BSWAP_32BIG_C(0xe938cb33U), BSWAP_32BIG_C(0x84df03d6U), BSWAP_32BIG_C(
                        0xec2d6d15U),
                };
                r_rsip_func100(Param_p18_func100_005);
                r_rsip_func_sub024(0x00000842U, 0x0c00a420U, 0x00000100U, 0x00802402U);

                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 2]);
                S_RAM[0 + 2] = bswap_32big(S_RAM[0 + 2]);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 3]);
                S_RAM[0 + 3] = bswap_32big(S_RAM[0 + 3]);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000100U);

                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1608H, 0x8188001eU);
                r_rsip_func_sub001(0x01490021U);

                WAIT_STS(REG_2030H, 4, 1);

                r_rsip_func_sub026(0x00000821U, 0x00000842U, 0x80900001U);
                r_rsip_func_sub001(0x03450041U);

                r_rsip_func_sub024(0x00003841U, 0x00008c40U, 0xf8ffffffU, 0x00003c41U);

                r_rsip_func_sub024(0x0000b420U, 0x0000001cU, 0x00003841U, 0x00008c40U);
                r_rsip_func_sub024(0xffffff3fU, 0x00009040U, 0x00000040U, 0x00003c41U);

                r_rsip_func_sub033(0x19600000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub036(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                r_rsip_func_sub026(0x0000b420U, 0x00000020U, 0x81880001U);
                r_rsip_func_sub001(0x01490021U);

                WR1_PROG(REG_1444H, 0x00020064U);

                for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffffffffffff0U); )
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR8_ADDR(REG_1420H, &InData_Msg[iLoop]);
                    iLoop = iLoop + 8U;
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

                r_rsip_func_sub026(0x00000821U, 0x00000842U, 0x80900001U);
                r_rsip_func_sub001(0x03450041U);

                r_rsip_func_sub024(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000003fU);

                for (iLoop = 0U; iLoop < 32U; iLoop++)
                {
                    r_rsip_func_sub024(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1004H, 0x00000000U);
                WR1_PROG(REG_1004H, 0x04040000U);

                static const uint32_t Param_p18_func100_006[] =
                {
                    BSWAP_32BIG_C(0xc00166d4U), BSWAP_32BIG_C(0x377facbaU), BSWAP_32BIG_C(0x9d4b46a8U), BSWAP_32BIG_C(
                        0x73897090U),
                };
                r_rsip_func100(Param_p18_func100_006);
                r_rsip_func401(InData_DomainParam);

                static const uint32_t Param_p18_func100_007[] =
                {
                    BSWAP_32BIG_C(0xca31355fU), BSWAP_32BIG_C(0xe31e3c3bU), BSWAP_32BIG_C(0x77c985ccU), BSWAP_32BIG_C(
                        0xedb1fdfeU),
                };
                r_rsip_func100(Param_p18_func100_007);
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

                r_rsip_func_sub033(0x12800000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                r_rsip_func_sub021(0x000000c0U, 0x000002f0U, 0x00000010U, 0x04040002U);

                r_rsip_func_sub012(0x12300000U, 0x0000b420U, 0x00000020U);
                WR1_PROG(REG_1608H, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                r_rsip_func_sub022(0x00000250U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub041(0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x00000250U, 0x000002f0U, 0x000000c0U);
                r_rsip_func_sub005(0x000009d0U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

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

                r_rsip_func_sub033(0x19b00000U, 0x00000bffU, 0x8088001fU);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub024(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub024(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000018U);

                for (iLoop = 0U; iLoop < 256U; iLoop++)
                {
                    r_rsip_func405();

                    r_rsip_func403();

                    static const uint32_t Param_p18_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xf277a28bU), BSWAP_32BIG_C(0x801c2c7fU), BSWAP_32BIG_C(0x86b03079U),
                        BSWAP_32BIG_C(0x73c1961aU),
                    };
                    r_rsip_func101(Param_p18_func101_005);
                    r_rsip_func402();

                    r_rsip_func404();

                    WR1_PROG(REG_1600H, 0x00002d00U);

                    static const uint32_t Param_p18_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x9ae1bb93U), BSWAP_32BIG_C(0x02131eedU), BSWAP_32BIG_C(0x40407ec4U),
                        BSWAP_32BIG_C(0xcfeda0dcU),
                    };
                    r_rsip_func101(Param_p18_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x08000909U);

                r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);

                r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

                r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);

                WR1_PROG(REG_1014H, 0x00000610U);
                r_rsip_func_sub021(0x00000070U, 0x00000250U, 0x00000008U, 0x04040004U);

                WR1_PROG(REG_1404H, 0x12d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

                static const uint32_t Param_p18_func100_008[] =
                {
                    BSWAP_32BIG_C(0x037807b7U), BSWAP_32BIG_C(0x36742391U), BSWAP_32BIG_C(0x3960ff58U), BSWAP_32BIG_C(
                        0x2884a15aU),
                };
                r_rsip_func100(Param_p18_func100_008);
                r_rsip_func_sub013(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00010001U);
                r_rsip_func_sub007(0x00000570U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub007(0x000005c0U, 0x000002f0U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub033(0x12800000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub025(0x00003801U, 0x00008c00U, 0x7fffffffU);

                r_rsip_func_sub012(0x12300000U, 0x0000b420U, 0x00000020U);
                WR1_PROG(REG_1608H, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub024(0x0000b420U, 0x0000003cU, 0x00003841U, 0x001f6c42U);
                r_rsip_func_sub024(0x00001002U, 0x00000821U, 0x00003c01U, 0x00000800U);
                r_rsip_func_sub024(0x00000821U, 0x00000842U, 0x0000b460U, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub024(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub033(0x1c300000U, 0x00000821U, 0x81880001U);
                r_rsip_func_sub001(0x00c90021U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub036(0x00000040U, S_RAM[0 + 2], 0x00000040U, S_RAM[0 + 3]);

                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x81880001U);
                r_rsip_func_sub001(0x01490021U);

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

                r_rsip_func_sub026(0x00000821U, 0x00000842U, 0x80900001U);
                r_rsip_func_sub001(0x03450041U);

                r_rsip_func_sub024(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000003fU);

                for (iLoop = 0U; iLoop < 32U; iLoop++)
                {
                    r_rsip_func_sub024(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

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

                r_rsip_func_sub033(0x19600000U, 0x00000821U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                r_rsip_func_sub024(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                WR1_PROG(REG_1600H, 0x0000001fU);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub024(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub033(0x19600000U, 0x00000821U, 0x81880001U);
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

                r_rsip_func_sub022(0x00000250U, 0x00000a20U, 0x000000c0U);
                r_rsip_func_sub027(0x000002a0U, 0x00000010U, 0x04040002U);
                r_rsip_func_sub007(0x00000a70U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
                r_rsip_func_sub041(0x00000250U, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040004U, 0x00010001U);
                r_rsip_func_sub007(0x000003e0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000340U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000980U, 0x00000b10U, 0x00000430U, 0x0404000aU);

                r_rsip_func_sub022(0x00000200U, 0x00000340U, 0x000000c0U);
                r_rsip_func_sub027(0x00000390U, 0x00000010U, 0x04040002U);
                r_rsip_func_sub007(0x00000390U, 0x00000430U, 0x000000c0U);
                r_rsip_func_sub005(0x000003e0U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000009d0U, 0x00000b10U, 0x000002f0U, 0x0404000aU);

                r_rsip_func_sub022(0x000002f0U, 0x000003e0U, 0x000000c0U);
                r_rsip_func_sub005(0x000002a0U, 0x04040005U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub024(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
                r_rsip_func_sub044(0x0000001fU, 0x12800000U, 0x80880001U);
                r_rsip_func_sub001(0x03430021U);

                for (iLoop = 0U; iLoop < 16U; iLoop++)
                {
                    r_rsip_func_sub024(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                static const uint32_t Param_p18_func100_009[] =
                {
                    BSWAP_32BIG_C(0xacb6bdf2U), BSWAP_32BIG_C(0x0c21cf38U), BSWAP_32BIG_C(0x9d4d21b3U), BSWAP_32BIG_C(
                        0x121b1e56U),
                };
                r_rsip_func100(Param_p18_func100_009);
                r_rsip_func_sub040(0x40000100U, 0x08008107U, 0x1c300000U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Signature[4]);

                static const uint32_t Param_p18_func100_010[] =
                {
                    BSWAP_32BIG_C(0xd714cbb8U), BSWAP_32BIG_C(0xb4c37a98U), BSWAP_32BIG_C(0xea20def9U), BSWAP_32BIG_C(
                        0x7e46ecefU),
                };
                r_rsip_func100(Param_p18_func100_010);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1408H, 0x00005022U);
                for (iLoop = 8; iLoop < 16U; iLoop++)
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD1_ADDR(REG_1420H, &OutData_Signature[iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p18_func102_004[] =
                {
                    BSWAP_32BIG_C(0x111f4c92U), BSWAP_32BIG_C(0xb9d8b869U), BSWAP_32BIG_C(0x17016699U), BSWAP_32BIG_C(
                        0x1c3a0990U),
                };
                r_rsip_func102(Param_p18_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
