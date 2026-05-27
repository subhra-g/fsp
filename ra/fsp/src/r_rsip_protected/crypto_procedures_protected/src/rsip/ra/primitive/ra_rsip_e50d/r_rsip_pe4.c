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

rsip_ret_t r_rsip_pe4 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e40001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a880U, 0x00000003U, 0x2000b480U, 0x00000002U);

    WR1_PROG(REG_1600H, 0x000009ceU);

    static const uint32_t Param_pe4_func100_001[] =
    {
        BSWAP_32BIG_C(0x44f75652U), BSWAP_32BIG_C(0x911e1e9eU), BSWAP_32BIG_C(0x9aadcceaU), BSWAP_32BIG_C(0x960d23a4U),
    };
    r_rsip_func100(Param_pe4_func100_001);
    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x015c5d71U);

        r_rsip_func_sub003(0x800100c0U, 0x00000008U);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x01b41ce9U);

        r_rsip_func_sub003(0x80010120U, 0x00000008U);

        static const uint32_t Param_pe4_func101_001[] =
        {
            BSWAP_32BIG_C(0x3c270202U), BSWAP_32BIG_C(0xdfdb6142U), BSWAP_32BIG_C(0x3aa0cf77U), BSWAP_32BIG_C(
                0x37e6976dU),
        };
        r_rsip_func101(Param_pe4_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0165e3d8U);

        r_rsip_func_sub003(0x800100c0U, 0x0000000cU);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x0199f119U);

        r_rsip_func_sub003(0x80010120U, 0x0000000cU);

        static const uint32_t Param_pe4_func101_002[] =
        {
            BSWAP_32BIG_C(0x8ea958a9U), BSWAP_32BIG_C(0x1bc55f60U), BSWAP_32BIG_C(0x3fc668afU), BSWAP_32BIG_C(
                0x131203f3U),
        };
        r_rsip_func101(Param_pe4_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800101c0U);
        WR1_PROG(REG_1420H, InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x30000dceU, 0x00030020U, 0x0000b4a0U, 0x01ea2366U);

        r_rsip_func_sub021(0x0000b4c0U, 0x00000014U, 0x00000060U, 0x0000b4a0U);
        r_rsip_func_sub021(0x015d7825U, 0x0000b4c0U, 0x00000010U, 0x00000080U);

        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1600H, 0x01b4cab0U);

        static const uint32_t Param_pe4_func101_003[] =
        {
            BSWAP_32BIG_C(0xd387ed79U), BSWAP_32BIG_C(0x1f303a0aU), BSWAP_32BIG_C(0x8ed72cf8U), BSWAP_32BIG_C(
                0xff15f104U),
        };
        r_rsip_func101(Param_pe4_func101_003);
    }

    r_rsip_func_sub003(0x800103a0U, 0x000000e4U);

    static const uint32_t Param_pe4_func101_004[] =
    {
        BSWAP_32BIG_C(0x3fc5e441U), BSWAP_32BIG_C(0xb5c7d2fcU), BSWAP_32BIG_C(0x04706163U), BSWAP_32BIG_C(0x7b3250a3U),
    };
    r_rsip_func101(Param_pe4_func101_004);
    r_rsip_func407(InData_EncSecret);

    static const uint32_t Param_pe4_func100_002[] =
    {
        BSWAP_32BIG_C(0x931c5b02U), BSWAP_32BIG_C(0xf9413ac0U), BSWAP_32BIG_C(0x87526a56U), BSWAP_32BIG_C(0x2a2c4c57U),
    };
    r_rsip_func100(Param_pe4_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe4_func102_001[] =
        {
            BSWAP_32BIG_C(0x0426806bU), BSWAP_32BIG_C(0x87c13f95U), BSWAP_32BIG_C(0xc597726aU), BSWAP_32BIG_C(
                0xe2e2252dU),
        };
        r_rsip_func102(Param_pe4_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

        static const uint32_t Param_pe4_func100_003[] =
        {
            BSWAP_32BIG_C(0x52c1c885U), BSWAP_32BIG_C(0x74c0903aU), BSWAP_32BIG_C(0xd3b54501U), BSWAP_32BIG_C(
                0x91ddcbffU),
        };
        r_rsip_func100(Param_pe4_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub017(0x38000dceU, 0x00260000U);

            static const uint32_t Param_pe4_func100_004[] =
            {
                BSWAP_32BIG_C(0xe3839f24U), BSWAP_32BIG_C(0x71393db6U), BSWAP_32BIG_C(0xbf77f0f8U), BSWAP_32BIG_C(
                    0x8c5ea1beU),
            };
            r_rsip_func100(Param_pe4_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000210U);

                r_rsip_func408();

                WR1_PROG(REG_1600H, 0x000008a5U);

                WR1_PROG(REG_1608H, 0x81910005U);
                r_rsip_func_sub001(0x01490045U);

                WAIT_STS(REG_2030H, 8, 0);
                WR1_PROG(REG_143CH, 0x00001600U);

                WR1_PROG(REG_1608H, 0x80900005U);
                r_rsip_func_sub001(0x03450041U);

                static const uint32_t Param_pe4_func101_005[] =
                {
                    BSWAP_32BIG_C(0xdcd38b42U), BSWAP_32BIG_C(0xaaff8b32U), BSWAP_32BIG_C(0x2dfec636U), BSWAP_32BIG_C(
                        0xa4ecf99bU),
                };
                r_rsip_func101(Param_pe4_func101_005);
            }
            else
            {
                static const uint32_t Param_pe4_func101_006[] =
                {
                    BSWAP_32BIG_C(0x77110b06U), BSWAP_32BIG_C(0xcf64708aU), BSWAP_32BIG_C(0x8c4310c7U), BSWAP_32BIG_C(
                        0xe20443a1U),
                };
                r_rsip_func101(Param_pe4_func101_006);
            }
        }
        else
        {
            static const uint32_t Param_pe4_func100_005[] =
            {
                BSWAP_32BIG_C(0x6223ae3eU), BSWAP_32BIG_C(0xc7588bb3U), BSWAP_32BIG_C(0xedeab21cU), BSWAP_32BIG_C(
                    0x9f2bcfe0U),
            };
            r_rsip_func100(Param_pe4_func100_005);
            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = S_RAM[0]; iLoop < 16U; )
            {
                WR1_PROG(REG_1608H, 0x80840005U);
                r_rsip_func_sub001(0x03400011U);

                r_rsip_func_sub021(0x0000a4e0U, 0x00000004U, 0x0000a4a0U, 0x00000010U);

                static const uint32_t Param_pe4_func101_007[] =
                {
                    BSWAP_32BIG_C(0x22c46f05U), BSWAP_32BIG_C(0xeabd6d34U), BSWAP_32BIG_C(0xe06a5f4fU), BSWAP_32BIG_C(
                        0x75117038U),
                };
                r_rsip_func101(Param_pe4_func101_007);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub006(0x380088e0U, 0x00000010U, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_pe4_func101_008[] =
            {
                BSWAP_32BIG_C(0xff08fe16U), BSWAP_32BIG_C(0xff16525cU), BSWAP_32BIG_C(0x36078c43U), BSWAP_32BIG_C(
                    0x09a58395U),
            };
            r_rsip_func101(Param_pe4_func101_008);
        }

        r_rsip_func_sub003(0x800103a0U, 0x000000e4U);

        static const uint32_t Param_pe4_func101_009[] =
        {
            BSWAP_32BIG_C(0xdcc62c05U), BSWAP_32BIG_C(0xee9ca8f6U), BSWAP_32BIG_C(0x1b41e61dU), BSWAP_32BIG_C(
                0xb59bcc06U),
        };
        r_rsip_func101(Param_pe4_func101_009);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x800103a0U, 0x000000e4U);

        static const uint32_t Param_pe4_func101_010[] =
        {
            BSWAP_32BIG_C(0x6c1d6fb2U), BSWAP_32BIG_C(0x5f449d72U), BSWAP_32BIG_C(0xda70c5a5U), BSWAP_32BIG_C(
                0x911509b0U),
        };
        r_rsip_func101(Param_pe4_func101_010);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e8U);

        r_rsip_func_sub003(0x800103a0U, 0x000000e4U);

        static const uint32_t Param_pe4_func101_011[] =
        {
            BSWAP_32BIG_C(0x6b3ab4beU), BSWAP_32BIG_C(0xd886991aU), BSWAP_32BIG_C(0xc245b521U), BSWAP_32BIG_C(
                0xc8e2b593U),
        };
        r_rsip_func101(Param_pe4_func101_011);
        r_rsip_func044();

        static const uint32_t Param_pe4_func100_006[] =
        {
            BSWAP_32BIG_C(0x4e85b904U), BSWAP_32BIG_C(0xc3dfba74U), BSWAP_32BIG_C(0x17571f6cU), BSWAP_32BIG_C(
                0x92d82d0aU),
        };
        r_rsip_func100(Param_pe4_func100_006);
        WR1_PROG(REG_1600H, 0x000008a5U);
        r_rsip_func_sub027(0x40000100U, 0xe7009d07U, 0x81900005U);
        r_rsip_func_sub001(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

        static const uint32_t Param_pe4_func100_007[] =
        {
            BSWAP_32BIG_C(0x25d9af11U), BSWAP_32BIG_C(0x2741f014U), BSWAP_32BIG_C(0x441910dcU), BSWAP_32BIG_C(
                0x2087bd83U),
        };
        r_rsip_func100(Param_pe4_func100_007);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_func_sub001(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

        static const uint32_t Param_pe4_func100_008[] =
        {
            BSWAP_32BIG_C(0xacc36738U), BSWAP_32BIG_C(0x12ede9c3U), BSWAP_32BIG_C(0x3715382fU), BSWAP_32BIG_C(
                0xf837907aU),
        };
        r_rsip_func100(Param_pe4_func100_008);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

        static const uint32_t Param_pe4_func100_009[] =
        {
            BSWAP_32BIG_C(0x4ad190fdU), BSWAP_32BIG_C(0x0c4229d9U), BSWAP_32BIG_C(0xbc068aa0U), BSWAP_32BIG_C(
                0xeb4c7341U),
        };
        r_rsip_func100(Param_pe4_func100_009);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_pe4_func102_002[] =
        {
            BSWAP_32BIG_C(0x6e22f4d9U), BSWAP_32BIG_C(0x9584fd4bU), BSWAP_32BIG_C(0x46c38572U), BSWAP_32BIG_C(
                0xb34526ecU),
        };
        r_rsip_func102(Param_pe4_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
