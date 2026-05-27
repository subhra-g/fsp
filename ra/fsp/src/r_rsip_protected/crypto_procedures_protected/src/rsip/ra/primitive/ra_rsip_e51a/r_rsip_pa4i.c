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

rsip_ret_t r_rsip_pa4i (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00a40001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0a4500e5U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &S_RAM[16 + 0]);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_pa4i_func100_001[] =
    {
        BSWAP_32BIG_C(0xff3f702aU), BSWAP_32BIG_C(0x1ae8edc4U), BSWAP_32BIG_C(0xc128b4f6U), BSWAP_32BIG_C(0x951ef814U),
    };
    r_rsip_func100(Param_pa4i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa4i_func102_001[] =
        {
            BSWAP_32BIG_C(0x06b37adaU), BSWAP_32BIG_C(0xc91ee093U), BSWAP_32BIG_C(0xb4fd0ccbU), BSWAP_32BIG_C(
                0xb112cce2U),
        };
        r_rsip_func102(Param_pa4i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub017(0x38000c00U, 0x00260000U);

        static const uint32_t Param_pa4i_func100_002[] =
        {
            BSWAP_32BIG_C(0x94c2109cU), BSWAP_32BIG_C(0xd1a6f9c0U), BSWAP_32BIG_C(0x475e625bU), BSWAP_32BIG_C(
                0x95ebb36bU),
        };
        r_rsip_func100(Param_pa4i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a4U);

            static const uint32_t Param_pa4i_func101_001[] =
            {
                BSWAP_32BIG_C(0xae9cb379U), BSWAP_32BIG_C(0x4c67c054U), BSWAP_32BIG_C(0x31d6662dU), BSWAP_32BIG_C(
                    0x232457efU),
            };
            r_rsip_func101(Param_pa4i_func101_001);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            static const uint32_t Param_pa4i_func101_002[] =
            {
                BSWAP_32BIG_C(0x7905e5e8U), BSWAP_32BIG_C(0xd3ee20b1U), BSWAP_32BIG_C(0xd8fb193bU), BSWAP_32BIG_C(
                    0x69d82933U),
            };
            r_rsip_func101(Param_pa4i_func101_002);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010140U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a4U);

            static const uint32_t Param_pa4i_func101_003[] =
            {
                BSWAP_32BIG_C(0xec0b0fafU), BSWAP_32BIG_C(0x047cf2ceU), BSWAP_32BIG_C(0xc66b14a9U), BSWAP_32BIG_C(
                    0x965c7ba2U),
            };
            r_rsip_func101(Param_pa4i_func101_003);
            r_rsip_func068();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x85d04999U);

            static const uint32_t Param_pa4i_func101_004[] =
            {
                BSWAP_32BIG_C(0x1af9d5f2U), BSWAP_32BIG_C(0x9f40d4a3U), BSWAP_32BIG_C(0x40a045cfU), BSWAP_32BIG_C(
                    0x41000653U),
            };
            r_rsip_func101(Param_pa4i_func101_004);
        }

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a4U);

        static const uint32_t Param_pa4i_func101_005[] =
        {
            BSWAP_32BIG_C(0x606013b5U), BSWAP_32BIG_C(0x8581da59U), BSWAP_32BIG_C(0x99728532U), BSWAP_32BIG_C(
                0x6bd20243U),
        };
        r_rsip_func101(Param_pa4i_func101_005);
        r_rsip_func044();

        static const uint32_t Param_pa4i_func100_003[] =
        {
            BSWAP_32BIG_C(0x30c1e35bU), BSWAP_32BIG_C(0x4bb00969U), BSWAP_32BIG_C(0xb170457cU), BSWAP_32BIG_C(
                0x16683880U),
        };
        r_rsip_func100(Param_pa4i_func100_003);
        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1824H, 0x08000085U);
        r_rsip_func_sub001(0x00420011U);

        static const uint32_t Param_pa4i_func100_004[] =
        {
            BSWAP_32BIG_C(0x37509494U), BSWAP_32BIG_C(0x27745a5aU), BSWAP_32BIG_C(0xef2512b3U), BSWAP_32BIG_C(
                0x846cb5ffU),
        };
        r_rsip_func100(Param_pa4i_func100_004);
        WR1_PROG(REG_1824H, 0x08000095U);
        r_rsip_func_sub001(0x00420011U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pa4i_func100_005[] =
        {
            BSWAP_32BIG_C(0xaece102dU), BSWAP_32BIG_C(0xc926df6bU), BSWAP_32BIG_C(0x2513dc0eU), BSWAP_32BIG_C(
                0xf4e44517U),
        };
        r_rsip_func100(Param_pa4i_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pa4i_func102_002[] =
            {
                BSWAP_32BIG_C(0x20dd73d6U), BSWAP_32BIG_C(0x66252f67U), BSWAP_32BIG_C(0x5e1ed339U), BSWAP_32BIG_C(
                    0x55124a1aU),
            };
            r_rsip_func102(Param_pa4i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000145U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            WR1_PROG(REG_1824H, 0x08000065U);
            r_rsip_func_sub001(0x00410011U);

            r_rsip_func_sub020(0x000000a1U, 0x07000c04U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub020(0x000000a1U, 0x08000054U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x0e108406U);

            for (iLoop = 0U; iLoop < Header_Len; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Header[iLoop]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func216();

            return RSIP_RET_PASS;
        }
    }
}
