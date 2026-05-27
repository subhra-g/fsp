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

rsip_ret_t r_rsip_pa1i (const uint32_t InData_KeyType[],
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

    WR1_PROG(REG_1B00H, 0x00a10001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0a4500e5U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &S_RAM[16 + 0]);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_pa1i_func100_001[] =
    {
        BSWAP_32BIG_C(0x2180f8a5U), BSWAP_32BIG_C(0x5f517e8aU), BSWAP_32BIG_C(0x3888aba0U), BSWAP_32BIG_C(0x1822a59bU),
    };
    r_rsip_func100(Param_pa1i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pa1i_func102_001[] =
        {
            BSWAP_32BIG_C(0x5cd308eaU), BSWAP_32BIG_C(0x25a53a91U), BSWAP_32BIG_C(0x8d0e273aU), BSWAP_32BIG_C(
                0xf25800a2U),
        };
        r_rsip_func102(Param_pa1i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub017(0x38000c00U, 0x00260000U);

        static const uint32_t Param_pa1i_func100_002[] =
        {
            BSWAP_32BIG_C(0xafec45fdU), BSWAP_32BIG_C(0x2f687662U), BSWAP_32BIG_C(0xa5851f2aU), BSWAP_32BIG_C(
                0x5df143e8U),
        };
        r_rsip_func100(Param_pa1i_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a1U);

            static const uint32_t Param_pa1i_func101_001[] =
            {
                BSWAP_32BIG_C(0x357eb2ecU), BSWAP_32BIG_C(0x53f0d1fbU), BSWAP_32BIG_C(0xf36ed08aU), BSWAP_32BIG_C(
                    0xe997ad4fU),
            };
            r_rsip_func101(Param_pa1i_func101_001);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            static const uint32_t Param_pa1i_func101_002[] =
            {
                BSWAP_32BIG_C(0x6a968522U), BSWAP_32BIG_C(0x9e379da3U), BSWAP_32BIG_C(0xe47daad6U), BSWAP_32BIG_C(
                    0x9bf9c2faU),
            };
            r_rsip_func101(Param_pa1i_func101_002);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010140U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a1U);

            static const uint32_t Param_pa1i_func101_003[] =
            {
                BSWAP_32BIG_C(0x88b3c802U), BSWAP_32BIG_C(0x43021533U), BSWAP_32BIG_C(0x5dae71e6U), BSWAP_32BIG_C(
                    0xc11f739eU),
            };
            r_rsip_func101(Param_pa1i_func101_003);
            r_rsip_func068();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x85d04999U);

            static const uint32_t Param_pa1i_func101_004[] =
            {
                BSWAP_32BIG_C(0x03bf4f95U), BSWAP_32BIG_C(0x7d1f7b6aU), BSWAP_32BIG_C(0x4ba55fb1U), BSWAP_32BIG_C(
                    0x5fb2fbfcU),
            };
            r_rsip_func101(Param_pa1i_func101_004);
        }

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000a1U);

        static const uint32_t Param_pa1i_func101_005[] =
        {
            BSWAP_32BIG_C(0xfdd9e5baU), BSWAP_32BIG_C(0x88bd16f5U), BSWAP_32BIG_C(0x40135118U), BSWAP_32BIG_C(
                0xc8ffd98dU),
        };
        r_rsip_func101(Param_pa1i_func101_005);
        r_rsip_func044();

        static const uint32_t Param_pa1i_func100_003[] =
        {
            BSWAP_32BIG_C(0x0600a1acU), BSWAP_32BIG_C(0xceb3af36U), BSWAP_32BIG_C(0x526a98ccU), BSWAP_32BIG_C(
                0x455d0559U),
        };
        r_rsip_func100(Param_pa1i_func100_003);
        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        WR1_PROG(REG_1824H, 0x08000085U);
        r_rsip_func_sub001(0x00420011U);

        static const uint32_t Param_pa1i_func100_004[] =
        {
            BSWAP_32BIG_C(0x6ea94097U), BSWAP_32BIG_C(0xc75f42d5U), BSWAP_32BIG_C(0x00f1e439U), BSWAP_32BIG_C(
                0x0c0190bdU),
        };
        r_rsip_func100(Param_pa1i_func100_004);
        WR1_PROG(REG_1824H, 0x08000095U);
        r_rsip_func_sub001(0x00420011U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pa1i_func100_005[] =
        {
            BSWAP_32BIG_C(0x8cbbdc09U), BSWAP_32BIG_C(0x08bc0974U), BSWAP_32BIG_C(0x49e41958U), BSWAP_32BIG_C(
                0x5d2f6346U),
        };
        r_rsip_func100(Param_pa1i_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pa1i_func102_002[] =
            {
                BSWAP_32BIG_C(0x3da7e49dU), BSWAP_32BIG_C(0x7ecc2848U), BSWAP_32BIG_C(0x910953efU), BSWAP_32BIG_C(
                    0x46427edfU),
            };
            r_rsip_func102(Param_pa1i_func102_002);
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
