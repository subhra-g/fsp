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

rsip_ret_t r_rsip_p57 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    r_rsip_func_sub030(0x00570001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000057U);

    static const uint32_t Param_p57_func101_001[] =
    {
        BSWAP_32BIG_C(0xe15a983dU), BSWAP_32BIG_C(0x25e4dbb2U), BSWAP_32BIG_C(0xe2cb762dU), BSWAP_32BIG_C(0x5e6f04c0U),
    };
    r_rsip_func101(Param_p57_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000dU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000057U);

    static const uint32_t Param_p57_func101_002[] =
    {
        BSWAP_32BIG_C(0xf4191e9bU), BSWAP_32BIG_C(0x041bc057U), BSWAP_32BIG_C(0x3ab4533dU), BSWAP_32BIG_C(0x6216fc62U),
    };
    r_rsip_func101(Param_p57_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x00007fc2U, 0x40000f00U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    r_rsip_func_sub040(0x40000f00U, 0xf7008d07U, 0x13280000U);
    for (iLoop = 64U; iLoop < 128U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[129]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p57_func100_001[] =
    {
        BSWAP_32BIG_C(0x6aee409aU), BSWAP_32BIG_C(0x3321046bU), BSWAP_32BIG_C(0x152f14cfU), BSWAP_32BIG_C(0x99f21627U),
    };
    r_rsip_func100(Param_p57_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p57_func102_001[] =
        {
            BSWAP_32BIG_C(0x0c5b5bf2U), BSWAP_32BIG_C(0x3c3a9775U), BSWAP_32BIG_C(0xc7dbf5d5U), BSWAP_32BIG_C(
                0x11bac0e2U),
        };
        r_rsip_func102(Param_p57_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x20200010U);

        r_rsip_func_sub023(0x00003fc2U, 0x40000f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x11200000U);
        for (iLoop = 0U; iLoop < 64U; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
            iLoop = iLoop + 8U;
        }

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p57_func100_002[] =
        {
            BSWAP_32BIG_C(0x2ec44c3dU), BSWAP_32BIG_C(0xcbf25f29U), BSWAP_32BIG_C(0x5348411fU), BSWAP_32BIG_C(
                0xf1f61fe5U),
        };
        r_rsip_func100(Param_p57_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p57_func102_002[] =
            {
                BSWAP_32BIG_C(0xe2d44466U), BSWAP_32BIG_C(0x3a8d162aU), BSWAP_32BIG_C(0xb56eca9fU), BSWAP_32BIG_C(
                    0x6ca90f50U),
            };
            r_rsip_func102(Param_p57_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p57_func100_003[] =
            {
                BSWAP_32BIG_C(0x9b3c92c6U), BSWAP_32BIG_C(0x4f694f8fU), BSWAP_32BIG_C(0xed239c4bU), BSWAP_32BIG_C(
                    0xd74e8cfcU),
            };
            r_rsip_func100(Param_p57_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x20200000U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub025(0x00000bffU, 0x0000b400U, 0x00000040U);

            WR1_PROG(REG_1404H, 0x17380000U);

            for (iLoop = 0U; iLoop < 64U; )
            {
                r_rsip_func_sub024(0x00000bdeU, 0x34202be0U, 0x2000d3c0U, 0x00007c1eU);
                WR1_PROG(REG_143CH, 0x00602000U);

                static const uint32_t Param_p57_func100_004[] =
                {
                    BSWAP_32BIG_C(0x014ba15aU), BSWAP_32BIG_C(0x7f4c137eU), BSWAP_32BIG_C(0x3bbe1a5cU), BSWAP_32BIG_C(
                        0xe79546b3U),
                };
                r_rsip_func100(Param_p57_func100_004);
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

                static const uint32_t Param_p57_func101_003[] =
                {
                    BSWAP_32BIG_C(0x4aec129dU), BSWAP_32BIG_C(0xe4bad574U), BSWAP_32BIG_C(0x6c904ba2U), BSWAP_32BIG_C(
                        0xbd7c9ff8U),
                };
                r_rsip_func101(Param_p57_func101_003);
                iLoop = iLoop + 8U;
            }

            r_rsip_func_sub017(0x38000be0U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);

            static const uint32_t Param_p57_func100_005[] =
            {
                BSWAP_32BIG_C(0x7ac71450U), BSWAP_32BIG_C(0xe6c53a4eU), BSWAP_32BIG_C(0xb051db8cU), BSWAP_32BIG_C(
                    0xdf66788eU),
            };
            r_rsip_func100(Param_p57_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p57_func102_003[] =
            {
                BSWAP_32BIG_C(0xb1cb1895U), BSWAP_32BIG_C(0xf9bf12ecU), BSWAP_32BIG_C(0x52b3c1b8U), BSWAP_32BIG_C(
                    0xde7fb8f0U),
            };
            r_rsip_func102(Param_p57_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
