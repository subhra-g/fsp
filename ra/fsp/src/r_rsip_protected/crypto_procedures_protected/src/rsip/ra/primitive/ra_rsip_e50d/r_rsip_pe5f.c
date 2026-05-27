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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        uint32_t       OutData_KDFInfo[],
                        uint32_t       MAX_CNT)
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000d08U, 0x00A60000U);

    static const uint32_t Param_pe5f_func100_001[] =
    {
        BSWAP_32BIG_C(0xb1896bd9U), BSWAP_32BIG_C(0xa91c0f26U), BSWAP_32BIG_C(0xaeb0a8bfU), BSWAP_32BIG_C(0x94a1395aU),
    };
    r_rsip_func100(Param_pe5f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x800103a0U, 0x0000e504U);

        static const uint32_t Param_pe5f_func101_001[] =
        {
            BSWAP_32BIG_C(0xec72c040U), BSWAP_32BIG_C(0x6c2c86d4U), BSWAP_32BIG_C(0xbbb97d59U), BSWAP_32BIG_C(
                0x1023c135U),
        };
        r_rsip_func101(Param_pe5f_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01799093U);

        r_rsip_func_sub003(0x800103a0U, 0x0000e504U);

        static const uint32_t Param_pe5f_func101_002[] =
        {
            BSWAP_32BIG_C(0xded0afd4U), BSWAP_32BIG_C(0xa2c280a4U), BSWAP_32BIG_C(0x87f4dbe4U), BSWAP_32BIG_C(
                0x9e31e8a9U),
        };
        r_rsip_func101(Param_pe5f_func101_002);
        r_rsip_func044();

        WAIT_STS(REG_2030H, 0, 1);

        static const uint32_t Param_pe5f_func100_002[] =
        {
            BSWAP_32BIG_C(0x7bf28682U), BSWAP_32BIG_C(0xe7ae7329U), BSWAP_32BIG_C(0x50df69c9U), BSWAP_32BIG_C(
                0xcd440b78U),
        };
        r_rsip_func100(Param_pe5f_func100_002);
        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        r_rsip_func_sub016(0x81010100U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        OFS_ADR  = S_RAM[0];

        r_rsip_func_sub022(0x0000a900U, 0x00000002U, 0x00026908U);

        r_rsip_func_sub006(0x3800a900U, 0x00000005U, 0x00260000U);

        static const uint32_t Param_pe5f_func100_003[] =
        {
            BSWAP_32BIG_C(0x12a3c29aU), BSWAP_32BIG_C(0x810222eeU), BSWAP_32BIG_C(0xe789a2f0U), BSWAP_32BIG_C(
                0x21232183U),
        };
        r_rsip_func100(Param_pe5f_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000929U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 9; )
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub001(0x01420011U);

                WR1_PROG(REG_1600H, 0x00002d20U);

                static const uint32_t Param_pe5f_func101_003[] =
                {
                    BSWAP_32BIG_C(0xd2773096U), BSWAP_32BIG_C(0xbaf68399U), BSWAP_32BIG_C(0xe5a2c4cbU), BSWAP_32BIG_C(
                        0x17010487U),
                };
                r_rsip_func101(Param_pe5f_func101_003);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x000037e8U);
            r_rsip_func_sub006(0x000033e0U, 0x38000be9U, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub001(0x01420005U);
            r_rsip_func_sub001(0x0002000dU);

            iLoop = iLoop + 4;

            static const uint32_t Param_pe5f_func101_004[] =
            {
                BSWAP_32BIG_C(0xf85ba35aU), BSWAP_32BIG_C(0x06a0faf9U), BSWAP_32BIG_C(0x6802de4fU), BSWAP_32BIG_C(
                    0x89462668U),
            };
            r_rsip_func101(Param_pe5f_func101_004);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00000929U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
            {
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub001(0x01420011U);

                WR1_PROG(REG_1600H, 0x00002d20U);

                static const uint32_t Param_pe5f_func101_005[] =
                {
                    BSWAP_32BIG_C(0xe150ba60U), BSWAP_32BIG_C(0xb1270c63U), BSWAP_32BIG_C(0x43b6791cU), BSWAP_32BIG_C(
                        0x622f74e7U),
                };
                r_rsip_func101(Param_pe5f_func101_005);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000909U);

            static const uint32_t Param_pe5f_func101_006[] =
            {
                BSWAP_32BIG_C(0xe25c20e9U), BSWAP_32BIG_C(0x58f11451U), BSWAP_32BIG_C(0xabc26729U), BSWAP_32BIG_C(
                    0xfcc3e350U),
            };
            r_rsip_func101(Param_pe5f_func101_006);
        }

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pe5f_func100_004[] =
        {
            BSWAP_32BIG_C(0xeaa14ebfU), BSWAP_32BIG_C(0x24acec4cU), BSWAP_32BIG_C(0xa3eb01c5U), BSWAP_32BIG_C(
                0x8333f327U),
        };
        r_rsip_func100(Param_pe5f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe5f_func102_001[] =
            {
                BSWAP_32BIG_C(0x83a8b714U), BSWAP_32BIG_C(0xddd80255U), BSWAP_32BIG_C(0x25219c4dU), BSWAP_32BIG_C(
                    0x4457c6e4U),
            };
            r_rsip_func102(Param_pe5f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe5f_func101_007[] =
            {
                BSWAP_32BIG_C(0x3e8a4746U), BSWAP_32BIG_C(0x8e173806U), BSWAP_32BIG_C(0xe176550eU), BSWAP_32BIG_C(
                    0x962dd445U),
            };
            r_rsip_func101(Param_pe5f_func101_007);
        }
    }
    else
    {
        static const uint32_t Param_pe5f_func101_008[] =
        {
            BSWAP_32BIG_C(0xbd4c386cU), BSWAP_32BIG_C(0xb9e0fd63U), BSWAP_32BIG_C(0xe405a54aU), BSWAP_32BIG_C(
                0x3dd9a9dfU),
        };
        r_rsip_func101(Param_pe5f_func101_008);
    }

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < MAX_CNT; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);

    WAIT_STS(REG_2030H, 4, 1);

    r_rsip_func_sub003(0x800103a0U, 0x0000e502U);

    static const uint32_t Param_pe5f_func101_009[] =
    {
        BSWAP_32BIG_C(0x3d3c1ad9U), BSWAP_32BIG_C(0xcbc4c635U), BSWAP_32BIG_C(0xd3808280U), BSWAP_32BIG_C(0x93334145U),
    };
    r_rsip_func101(Param_pe5f_func101_009);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000e505U);

    static const uint32_t Param_pe5f_func101_010[] =
    {
        BSWAP_32BIG_C(0x7f05e88fU), BSWAP_32BIG_C(0xa83b2a5aU), BSWAP_32BIG_C(0x270d4df1U), BSWAP_32BIG_C(0xbbe68252U),
    };
    r_rsip_func101(Param_pe5f_func101_010);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x01799093U);

    r_rsip_func_sub003(0x800103a0U, 0x0000e505U);

    static const uint32_t Param_pe5f_func101_011[] =
    {
        BSWAP_32BIG_C(0x735cc6e3U), BSWAP_32BIG_C(0xf70c4002U), BSWAP_32BIG_C(0x36840f1aU), BSWAP_32BIG_C(0xc61fe8e5U),
    };
    r_rsip_func101(Param_pe5f_func101_011);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    static const uint32_t Param_pe5f_func100_005[] =
    {
        BSWAP_32BIG_C(0x984a8143U), BSWAP_32BIG_C(0x2e1c593eU), BSWAP_32BIG_C(0x4e2be20eU), BSWAP_32BIG_C(0x852e3962U),
    };
    r_rsip_func100(Param_pe5f_func100_005);
    r_rsip_func_sub016(0x810101e0U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        static const uint32_t Param_pe5f_func100_006[] =
        {
            BSWAP_32BIG_C(0x6c0dcf65U), BSWAP_32BIG_C(0x7b61b86cU), BSWAP_32BIG_C(0x20df57daU), BSWAP_32BIG_C(
                0xa3591191U),
        };
        r_rsip_func100(Param_pe5f_func100_006);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00850011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 1]);

        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1600H, 0x00000004U);

        static const uint32_t Param_pe5f_func101_012[] =
        {
            BSWAP_32BIG_C(0xc3f481c8U), BSWAP_32BIG_C(0xa5e9d05bU), BSWAP_32BIG_C(0x60d06abcU), BSWAP_32BIG_C(
                0x8d829611U),
        };
        r_rsip_func101(Param_pe5f_func101_012);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x380008efU);

    static const uint32_t Param_pe5f_func100_007[] =
    {
        BSWAP_32BIG_C(0x549ed717U), BSWAP_32BIG_C(0x869ed820U), BSWAP_32BIG_C(0xbe78d0ecU), BSWAP_32BIG_C(0xd92fb865U),
    };
    r_rsip_func100(Param_pe5f_func100_007);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 1]);

    static const uint32_t Param_pe5f_func100_008[] =
    {
        BSWAP_32BIG_C(0x4e724bf8U), BSWAP_32BIG_C(0xee974c4cU), BSWAP_32BIG_C(0x98d4dc10U), BSWAP_32BIG_C(0x0be67138U),
    };
    r_rsip_func100(Param_pe5f_func100_008);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);

    static const uint32_t Param_pe5f_func102_002[] =
    {
        BSWAP_32BIG_C(0xcd88c46fU), BSWAP_32BIG_C(0x72fb7e60U), BSWAP_32BIG_C(0x97072eafU), BSWAP_32BIG_C(0x84477f7cU),
    };
    r_rsip_func102(Param_pe5f_func102_002);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
