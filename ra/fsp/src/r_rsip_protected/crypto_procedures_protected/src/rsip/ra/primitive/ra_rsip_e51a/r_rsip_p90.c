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

rsip_ret_t r_rsip_p90 (const uint32_t InData_KeyType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       WRAPPED_KEY_SIZE,
                       uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;
    int32_t  jLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00900001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000002c7U, 0x80030100U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_WrappedKeyType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x00000bffU, 0x00003409U, 0x3420a900U, 0x00000002U);
    r_rsip_func_sub024(0x1000d3e0U, 0x38008940U, 0x00000000U, 0x00030020U);
    r_rsip_func_sub024(0x3420a800U, 0x00000003U, 0x1000d3e1U, 0x00000080U);

    r_rsip_func_sub006(0x38008be0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_p90_func100_001[] =
    {
        BSWAP_32BIG_C(0xad66c77fU), BSWAP_32BIG_C(0x3d58a044U), BSWAP_32BIG_C(0x7177f584U), BSWAP_32BIG_C(0xaaaca63aU),
    };
    r_rsip_func100(Param_p90_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p90_func102_001[] =
        {
            BSWAP_32BIG_C(0x53dd04acU), BSWAP_32BIG_C(0x2687190cU), BSWAP_32BIG_C(0x19117b61U), BSWAP_32BIG_C(
                0x2450fea0U),
        };
        r_rsip_func102(Param_p90_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00009001U);

        static const uint32_t Param_p90_func101_001[] =
        {
            BSWAP_32BIG_C(0x6df902f9U), BSWAP_32BIG_C(0x8fdd71f6U), BSWAP_32BIG_C(0xc334a2a2U), BSWAP_32BIG_C(
                0x98fd07f4U),
        };
        r_rsip_func101(Param_p90_func101_001);
        r_rsip_func043();

        r_rsip_func_sub017(0x38000d08U, 0x00260000U);

        static const uint32_t Param_p90_func100_002[] =
        {
            BSWAP_32BIG_C(0xc67dcc4fU), BSWAP_32BIG_C(0xbf0b42d2U), BSWAP_32BIG_C(0x1ba21cb8U), BSWAP_32BIG_C(
                0xd0848d2bU),
        };
        r_rsip_func100(Param_p90_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00009001U);

            static const uint32_t Param_p90_func101_002[] =
            {
                BSWAP_32BIG_C(0x71a4d79dU), BSWAP_32BIG_C(0x19fd9f09U), BSWAP_32BIG_C(0x8a323c35U), BSWAP_32BIG_C(
                    0x16e814dfU),
            };
            r_rsip_func101(Param_p90_func101_002);
            r_rsip_func044();

            static const uint32_t Param_p90_func100_003[] =
            {
                BSWAP_32BIG_C(0x97a9554eU), BSWAP_32BIG_C(0xb7ed34d5U), BSWAP_32BIG_C(0x63433838U), BSWAP_32BIG_C(
                    0xded20c05U),
            };
            r_rsip_func100(Param_p90_func100_003);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_182CH, 0x00000000U);

            static const uint32_t Param_p90_func101_003[] =
            {
                BSWAP_32BIG_C(0x88a11ba8U), BSWAP_32BIG_C(0x25d2dd49U), BSWAP_32BIG_C(0xc54547e5U), BSWAP_32BIG_C(
                    0xb5e51761U),
            };
            r_rsip_func101(Param_p90_func101_003);
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00009002U);

            static const uint32_t Param_p90_func101_004[] =
            {
                BSWAP_32BIG_C(0x976d8b53U), BSWAP_32BIG_C(0x4cdebaeeU), BSWAP_32BIG_C(0x2117aa2eU), BSWAP_32BIG_C(
                    0x6bfeccceU),
            };
            r_rsip_func101(Param_p90_func101_004);
            r_rsip_func044();

            static const uint32_t Param_p90_func100_004[] =
            {
                BSWAP_32BIG_C(0x2c4b16b2U), BSWAP_32BIG_C(0xc212d40aU), BSWAP_32BIG_C(0xde528630U), BSWAP_32BIG_C(
                    0xe71e6ac1U),
            };
            r_rsip_func100(Param_p90_func100_004);
            r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            static const uint32_t Param_p90_func100_005[] =
            {
                BSWAP_32BIG_C(0xcd4d0f80U), BSWAP_32BIG_C(0x1ee104bcU), BSWAP_32BIG_C(0x8c7c1df8U), BSWAP_32BIG_C(
                    0xdcce2de5U),
            };
            r_rsip_func100(Param_p90_func100_005);
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_182CH, 0x40000000U);

            static const uint32_t Param_p90_func101_005[] =
            {
                BSWAP_32BIG_C(0x6954764aU), BSWAP_32BIG_C(0x1e9645f4U), BSWAP_32BIG_C(0x2fa7f32cU), BSWAP_32BIG_C(
                    0x4a62ae8cU),
            };
            r_rsip_func101(Param_p90_func101_005);
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p90_func100_006[] =
        {
            BSWAP_32BIG_C(0xd662c849U), BSWAP_32BIG_C(0xe7917962U), BSWAP_32BIG_C(0xe9c510afU), BSWAP_32BIG_C(
                0xdb7207c6U),
        };
        r_rsip_func100(Param_p90_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p90_func102_002[] =
            {
                BSWAP_32BIG_C(0x7e8b4a58U), BSWAP_32BIG_C(0x3b9b4932U), BSWAP_32BIG_C(0xa71d5890U), BSWAP_32BIG_C(
                    0x220057e4U),
            };
            r_rsip_func102(Param_p90_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_1600H, 0x00002ca0U);

            WR1_PROG(REG_1600H, 0x000035c7U);

            r_rsip_func_sub010(0x000001c7U, 0x80020000U);
            WR1_PROG(REG_1420H, InData_Text[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_Text[1]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub024(0x0000b7e0U, 0x00000008U, 0x00000bdeU, 0x00002fc0U);

            WR1_PROG(REG_1600H, 0x0000b780U);
            WR1_PROG(REG_1600H, 0x00000008U);

            for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; )
            {
                r_rsip_func_sub010(0x000001c7U, 0x8082001fU);
                WR1_PROG(REG_1420H, InData_Text[iLoop]);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_Text[iLoop + 1]);
                r_rsip_func_sub039(0x000027fcU, 0x00002fc0U);

                static const uint32_t Param_p90_func101_006[] =
                {
                    BSWAP_32BIG_C(0xe32ea363U), BSWAP_32BIG_C(0x7ef18789U), BSWAP_32BIG_C(0xfeeb6aaaU), BSWAP_32BIG_C(
                        0x415870dfU),
                };
                r_rsip_func101(Param_p90_func101_006);
                iLoop = iLoop + 2;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000bc5U);

            r_rsip_func_sub024(0x0000377fU, 0x0000ab60U, 0x00000008U, 0x00003785U);
            r_rsip_func_sub024(0x00003380U, 0x0000349cU, 0x00026c84U, 0x00016f9cU);
            r_rsip_func_sub024(0x0000249cU, 0x00000bdeU, 0x0000b720U, 0x00000004U);

            r_rsip_func_sub024(0x0000b740U, 0x0000000cU, 0x00003785U, 0x00003380U);

            for (jLoop = 5; jLoop >= 0; jLoop = jLoop - 1)
            {
                WR1_PROG(REG_1600H, 0x000037fbU);

                WR1_PROG(REG_1600H, 0x00000bbdU);

                for (iLoop = (WRAPPED_KEY_SIZE / 2) - 1; iLoop >= 1; iLoop = iLoop - 1)
                {
                    WR1_PROG(REG_1600H, 0x00000824U);

                    WR1_PROG(REG_1824H, 0x0a00810dU);
                    WR1_PROG(REG_1608H, 0x81020000U);
                    r_rsip_func_sub001(0x00490009U);
                    WR1_PROG(REG_1608H, 0x8182001fU);
                    r_rsip_func_sub001(0x00490009U);

                    WR1_PROG(REG_1608H, 0x80040000U);
                    r_rsip_func_sub001(0x03410011U);

                    r_rsip_func_sub024(0x00003c5fU, 0x000027f9U, 0x00003c7fU, 0x00002bfaU);

                    WR1_PROG(REG_1600H, 0x00003080U);

                    WR1_PROG(REG_1600H, 0x00002fa0U);

                    static const uint32_t Param_p90_func101_007[] =
                    {
                        BSWAP_32BIG_C(0xcb6a02e1U), BSWAP_32BIG_C(0xf88fab4fU), BSWAP_32BIG_C(0x1fe350eeU),
                        BSWAP_32BIG_C(0x32a572beU),
                    };
                    r_rsip_func101(Param_p90_func101_007);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x38000bbcU);

                WR1_PROG(REG_1600H, 0x00002fc0U);

                static const uint32_t Param_p90_func101_008[] =
                {
                    BSWAP_32BIG_C(0xa540fd47U), BSWAP_32BIG_C(0x45625612U), BSWAP_32BIG_C(0x80525ae6U), BSWAP_32BIG_C(
                        0xc9c79756U),
                };
                r_rsip_func101(Param_p90_func101_008);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub006(0x38008bc0U, 0x00000006U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub006(0x38008800U, 0xa6a6a6a6U, 0x00A60000U);

            r_rsip_func_sub006(0x38008820U, 0xa6a6a6a6U, 0x00A60000U);

            static const uint32_t Param_p90_func100_007[] =
            {
                BSWAP_32BIG_C(0xeedf8f42U), BSWAP_32BIG_C(0x3e20cbb6U), BSWAP_32BIG_C(0x83827a1dU), BSWAP_32BIG_C(
                    0x013c7fbcU),
            };
            r_rsip_func100(Param_p90_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p90_func102_003[] =
                {
                    BSWAP_32BIG_C(0x0a3b2562U), BSWAP_32BIG_C(0x888edb8cU), BSWAP_32BIG_C(0x08a8aae0U), BSWAP_32BIG_C(
                        0x84120fb9U),
                };
                r_rsip_func102(Param_p90_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000090U);

                static const uint32_t Param_p90_func101_009[] =
                {
                    BSWAP_32BIG_C(0xfeb36c48U), BSWAP_32BIG_C(0xac56c762U), BSWAP_32BIG_C(0xb8f9255dU), BSWAP_32BIG_C(
                        0xe9b4b8e6U),
                };
                r_rsip_func101(Param_p90_func101_009);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00009002U);

                static const uint32_t Param_p90_func101_010[] =
                {
                    BSWAP_32BIG_C(0xf32a56abU), BSWAP_32BIG_C(0x1995610bU), BSWAP_32BIG_C(0xb14ed73aU), BSWAP_32BIG_C(
                        0x405ebba5U),
                };
                r_rsip_func101(Param_p90_func101_010);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034e6U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00009003U);

                static const uint32_t Param_p90_func101_011[] =
                {
                    BSWAP_32BIG_C(0xd231b630U), BSWAP_32BIG_C(0xaab41079U), BSWAP_32BIG_C(0xd7808171U), BSWAP_32BIG_C(
                        0xca2e20a9U),
                };
                r_rsip_func101(Param_p90_func101_011);
                r_rsip_func044();

                r_rsip_func_sub025(0x000034eeU, 0x0000b7e0U, 0x00000008U);

                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                r_rsip_func_sub024(0x00000bdeU, 0x0000b760U, 0x00000004U, 0x0000b780U);
                r_rsip_func_sub025(0x00000010U, 0x0000a8e0U, 0x00000005U);

                for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
                {
                    r_rsip_func_sub025(0x000008c6U, 0x34202bc7U, 0x2000d0c0U);

                    r_rsip_func_sub014(0x00007c06U, 0x00602000U);

                    static const uint32_t Param_p90_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xb16f7bf8U), BSWAP_32BIG_C(0xa92cda17U), BSWAP_32BIG_C(0xebb4c7e2U),
                        BSWAP_32BIG_C(0x6918513aU),
                    };
                    r_rsip_func100(Param_p90_func100_008);
                    r_rsip_func_sub023(0x000003c2U, 0x40000000U, 0xe7008d05U);

                    WR1_PROG(REG_1608H, 0x8184001fU);
                    r_rsip_func_sub001(0x00890011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

                    WR1_PROG(REG_1600H, 0x000027fcU);

                    WR1_PROG(REG_1600H, 0x000027dbU);

                    static const uint32_t Param_p90_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x5e610fafU), BSWAP_32BIG_C(0x48fe9b73U), BSWAP_32BIG_C(0xf4a55d6cU),
                        BSWAP_32BIG_C(0xd8840f81U),
                    };
                    r_rsip_func101(Param_p90_func101_012);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000bc7U);

                static const uint32_t Param_p90_func100_009[] =
                {
                    BSWAP_32BIG_C(0xf2af22c3U), BSWAP_32BIG_C(0x971f99baU), BSWAP_32BIG_C(0x6e689b1aU), BSWAP_32BIG_C(
                        0x2b1cbfbbU),
                };
                r_rsip_func100(Param_p90_func100_009);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

                static const uint32_t Param_p90_func100_010[] =
                {
                    BSWAP_32BIG_C(0x905de4baU), BSWAP_32BIG_C(0xd744a462U), BSWAP_32BIG_C(0xf7df0b72U), BSWAP_32BIG_C(
                        0x09349832U),
                };
                r_rsip_func100(Param_p90_func100_010);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_p90_func102_004[] =
                {
                    BSWAP_32BIG_C(0xa33f3031U), BSWAP_32BIG_C(0xc68a2934U), BSWAP_32BIG_C(0x3bfc0b83U), BSWAP_32BIG_C(
                        0x78b48cbfU),
                };
                r_rsip_func102(Param_p90_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
