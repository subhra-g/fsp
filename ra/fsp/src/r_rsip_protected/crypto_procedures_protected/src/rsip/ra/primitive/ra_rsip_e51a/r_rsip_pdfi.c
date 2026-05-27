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

rsip_ret_t r_rsip_pdfi (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00df0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000dfU);

    static const uint32_t Param_pdfi_func101_001[] =
    {
        BSWAP_32BIG_C(0x710a2aeeU), BSWAP_32BIG_C(0x2cc99f09U), BSWAP_32BIG_C(0xd8f6f1a9U), BSWAP_32BIG_C(0x842c4be1U),
    };
    r_rsip_func101(Param_pdfi_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000dfU);

    static const uint32_t Param_pdfi_func101_002[] =
    {
        BSWAP_32BIG_C(0x01c2a927U), BSWAP_32BIG_C(0x39895b7dU), BSWAP_32BIG_C(0x8f8f573dU), BSWAP_32BIG_C(0xbe540aa8U),
    };
    r_rsip_func101(Param_pdfi_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x00007fc2U, 0x40001f00U, 0xe8009107U);

    WR1_PROG(REG_1404H, 0x14300000U);
    for (iLoop = 0U; iLoop < 128U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xe8008105U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1404H, 0x12200000U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pdfi_func100_001[] =
    {
        BSWAP_32BIG_C(0x5610195dU), BSWAP_32BIG_C(0xe48222daU), BSWAP_32BIG_C(0x9bf0801eU), BSWAP_32BIG_C(0x4633d69fU),
    };
    r_rsip_func100(Param_pdfi_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdfi_func102_001[] =
        {
            BSWAP_32BIG_C(0x717d1d90U), BSWAP_32BIG_C(0xef8844baU), BSWAP_32BIG_C(0xbee75794U), BSWAP_32BIG_C(
                0x0248da39U),
        };
        r_rsip_func102(Param_pdfi_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x40400010U);

        r_rsip_func_sub023(0x00007fc2U, 0x40001f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10200000U);
        for (iLoop = 0U; iLoop < 128U; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
            iLoop = iLoop + 8U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x4040000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pdfi_func100_002[] =
        {
            BSWAP_32BIG_C(0x0f01e0b7U), BSWAP_32BIG_C(0x85ee4d94U), BSWAP_32BIG_C(0x4765ec9bU), BSWAP_32BIG_C(
                0x376fbb7cU),
        };
        r_rsip_func100(Param_pdfi_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdfi_func102_002[] =
            {
                BSWAP_32BIG_C(0xfbc65d8bU), BSWAP_32BIG_C(0x7a0a7dd7U), BSWAP_32BIG_C(0xf67b55d1U), BSWAP_32BIG_C(
                    0xb0b99ffcU),
            };
            r_rsip_func102(Param_pdfi_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdfi_func100_003[] =
            {
                BSWAP_32BIG_C(0x9aa63739U), BSWAP_32BIG_C(0x7414ebcbU), BSWAP_32BIG_C(0x543266bbU), BSWAP_32BIG_C(
                    0x2280e897U),
            };
            r_rsip_func100(Param_pdfi_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000228U, 0x00000630U, 0x00000838U, 0x0140000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub025(0x00000bffU, 0x0000b400U, 0x00000080U);

            WR1_PROG(REG_1404H, 0x16380000U);

            for (iLoop = 0U; iLoop < 128U; )
            {
                r_rsip_func_sub025(0x00000bdeU, 0x34202be0U, 0x2000d3c0U);

                r_rsip_func_sub014(0x00007c1eU, 0x00602000U);

                static const uint32_t Param_pdfi_func100_004[] =
                {
                    BSWAP_32BIG_C(0x9218603bU), BSWAP_32BIG_C(0x311fbcfcU), BSWAP_32BIG_C(0xf3968359U), BSWAP_32BIG_C(
                        0x6a4c88baU),
                };
                r_rsip_func100(Param_pdfi_func100_004);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                static const uint32_t Param_pdfi_func101_003[] =
                {
                    BSWAP_32BIG_C(0x9fddc8aaU), BSWAP_32BIG_C(0x14e0afbbU), BSWAP_32BIG_C(0xe0cb12aeU), BSWAP_32BIG_C(
                        0x4d540c34U),
                };
                r_rsip_func101(Param_pdfi_func101_003);
                iLoop = iLoop + 8U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_pdfi_func100_005[] =
            {
                BSWAP_32BIG_C(0xcf137ac9U), BSWAP_32BIG_C(0x5b833fbcU), BSWAP_32BIG_C(0x4b544ab1U), BSWAP_32BIG_C(
                    0xb1c5c561U),
            };
            r_rsip_func100(Param_pdfi_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pdfi_func101_004[] =
            {
                BSWAP_32BIG_C(0x80c2f747U), BSWAP_32BIG_C(0x4518df72U), BSWAP_32BIG_C(0xc4b749e1U), BSWAP_32BIG_C(
                    0x2830ed08U),
            };
            r_rsip_func101(Param_pdfi_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
