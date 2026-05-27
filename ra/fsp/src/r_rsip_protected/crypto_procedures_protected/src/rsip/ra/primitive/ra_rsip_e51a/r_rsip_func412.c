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

void r_rsip_func412 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub024(0x00003527U, 0x000035abU, 0x00026dadU, 0x0000252dU);
    WR1_PROG(REG_1600H, 0x0000a520U);
    WR1_PROG(REG_1600H, 0x00000002U);

    r_rsip_func_sub006(0x3420a920U, 0x00000101U, 0x00A60000U);

    static const uint32_t Param_func412_func100_001[] =
    {
        BSWAP_32BIG_C(0x49b35c1fU), BSWAP_32BIG_C(0x5cba1ceeU), BSWAP_32BIG_C(0x4ebc4a2fU), BSWAP_32BIG_C(0x6b0fc75aU),
    };
    r_rsip_func100(Param_func412_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000bdeU);

        static const uint32_t Param_func412_func101_001[] =
        {
            BSWAP_32BIG_C(0x42df8067U), BSWAP_32BIG_C(0x6d925ba4U), BSWAP_32BIG_C(0xcd2675e8U), BSWAP_32BIG_C(
                0xd50dcb87U),
        };
        r_rsip_func101(Param_func412_func101_001);
    }
    else
    {
        static const uint32_t Param_func412_func100_002[] =
        {
            BSWAP_32BIG_C(0xf64b3322U), BSWAP_32BIG_C(0x3bb05adaU), BSWAP_32BIG_C(0x671b252cU), BSWAP_32BIG_C(
                0x3e41cfaaU),
        };
        r_rsip_func100(Param_func412_func100_002);
        WR1_PROG(REG_1404H, 0x17f00000U);
        r_rsip_func_sub001(0x1003001dU);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x13430101U);
        r_rsip_func_sub001(0x10030005U);

        WR1_PROG(REG_1600H, 0x0000b440U);
        WR1_PROG(REG_1600H, 0x00000040U);

        WR1_PROG(REG_2000H, 0x00000001U);

        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_2004H, 0x00000040U);

            static const uint32_t Param_func412_func101_002[] =
            {
                BSWAP_32BIG_C(0x4194bb25U), BSWAP_32BIG_C(0xec617981U), BSWAP_32BIG_C(0x1ca437f4U), BSWAP_32BIG_C(
                    0xf577fe95U),
            };
            r_rsip_func101(Param_func412_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_2004H, 0x00000050U);

            static const uint32_t Param_func412_func101_003[] =
            {
                BSWAP_32BIG_C(0x8ccd031cU), BSWAP_32BIG_C(0x327c0a97U), BSWAP_32BIG_C(0xcc56b935U), BSWAP_32BIG_C(
                    0x6f7e854dU),
            };
            r_rsip_func101(Param_func412_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_2004H, 0x00000080U);

            static const uint32_t Param_func412_func101_004[] =
            {
                BSWAP_32BIG_C(0x6a39f13cU), BSWAP_32BIG_C(0xce3a67e6U), BSWAP_32BIG_C(0xc29687f1U), BSWAP_32BIG_C(
                    0x0aebe001U),
            };
            r_rsip_func101(Param_func412_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_2004H, 0x00000090U);

            static const uint32_t Param_func412_func101_005[] =
            {
                BSWAP_32BIG_C(0x8ba8fc71U), BSWAP_32BIG_C(0x73c68ba6U), BSWAP_32BIG_C(0xf158ee9fU), BSWAP_32BIG_C(
                    0xb9b31ec1U),
            };
            r_rsip_func101(Param_func412_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_2004H, 0x000000a0U);

            static const uint32_t Param_func412_func101_006[] =
            {
                BSWAP_32BIG_C(0x62107dbcU), BSWAP_32BIG_C(0xec9f7d4dU), BSWAP_32BIG_C(0x60c6583cU), BSWAP_32BIG_C(
                    0x680ee515U),
            };
            r_rsip_func101(Param_func412_func101_006);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_2004H, 0x000000b0U);

            static const uint32_t Param_func412_func101_007[] =
            {
                BSWAP_32BIG_C(0x088cf7e7U), BSWAP_32BIG_C(0x54b196c4U), BSWAP_32BIG_C(0x702d8402U), BSWAP_32BIG_C(
                    0x036d77eeU),
            };
            r_rsip_func101(Param_func412_func101_007);
        }

        static const uint32_t Param_func412_func100_003[] =
        {
            BSWAP_32BIG_C(0x4f64ba93U), BSWAP_32BIG_C(0xee1a0cd7U), BSWAP_32BIG_C(0xe48fc452U), BSWAP_32BIG_C(
                0xdfe1010eU),
        };
        r_rsip_func100(Param_func412_func100_003);
        r_rsip_func_sub024(0x0000a520U, 0x00000006U, 0x00000908U, 0x01836d09U);
        WR1_PROG(REG_1600H, 0x00036d29U);

        r_rsip_func_sub016(0x81020100U, 0x0000500aU);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        static const uint32_t Param_func412_func100_004[] =
        {
            BSWAP_32BIG_C(0x5cd11614U), BSWAP_32BIG_C(0x086717a9U), BSWAP_32BIG_C(0x25382cfcU), BSWAP_32BIG_C(
                0xef898493U),
        };
        r_rsip_func100(Param_func412_func100_004);
        r_rsip_func_sub036(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

        r_rsip_func_sub001(0x01400009U);

        WR1_PROG(REG_1600H, 0x00000800U);

        WR1_PROG(REG_1600H, 0x0000094aU);

        r_rsip_func_sub016(0x81010160U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x81810000U);
            r_rsip_func_sub001(0x01490005U);

            r_rsip_func_sub025(0x0000a400U, 0x00000004U, 0x00002d40U);

            static const uint32_t Param_func412_func101_008[] =
            {
                BSWAP_32BIG_C(0xb5b3aeb2U), BSWAP_32BIG_C(0x7e888c23U), BSWAP_32BIG_C(0x8c72b6cdU), BSWAP_32BIG_C(
                    0x36610b58U),
            };
            r_rsip_func101(Param_func412_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_func412_func100_005[] =
        {
            BSWAP_32BIG_C(0x8a5fb0ecU), BSWAP_32BIG_C(0x395d42c3U), BSWAP_32BIG_C(0xd1808866U), BSWAP_32BIG_C(
                0x361a4dbfU),
        };
        r_rsip_func100(Param_func412_func100_005);
        r_rsip_func_sub011(0x3800094bU);

        r_rsip_func_sub024(0x0000a4e0U, 0x00000003U, 0x000268e7U, 0x0000094aU);

        r_rsip_func_sub016(0x810100e0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        for (iLoop = 0U; iLoop < S_RAM[0 + 1]; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x000000c4U);
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, ARG1[iLoop]);

            WR1_PROG(REG_1600H, 0x00002d40U);

            static const uint32_t Param_func412_func101_009[] =
            {
                BSWAP_32BIG_C(0x21efd131U), BSWAP_32BIG_C(0x9d92195fU), BSWAP_32BIG_C(0x5e44ba19U), BSWAP_32BIG_C(
                    0xc539849cU),
            };
            r_rsip_func101(Param_func412_func101_009);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000947U);

        WAIT_STS(REG_2030H, 8, 0);
        WR1_PROG(REG_143CH, 0x00001600U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x0000094aU);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x80810002U);
            r_rsip_func_sub001(0x03450005U);

            r_rsip_func_sub025(0x0000a440U, 0x00000004U, 0x00002d40U);

            static const uint32_t Param_func412_func101_010[] =
            {
                BSWAP_32BIG_C(0x28742ea9U), BSWAP_32BIG_C(0x303ad91aU), BSWAP_32BIG_C(0x9e8d4dbfU), BSWAP_32BIG_C(
                    0x95a3e0c7U),
            };
            r_rsip_func101(Param_func412_func101_010);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x3800094bU);

        r_rsip_func_sub024(0x0000b440U, 0x00000040U, 0x0000b7c0U, 0x76bea7b0U);

        static const uint32_t Param_func412_func101_011[] =
        {
            BSWAP_32BIG_C(0xc069eea6U), BSWAP_32BIG_C(0x4bf33da8U), BSWAP_32BIG_C(0xa8582d13U), BSWAP_32BIG_C(
                0x16856b74U),
        };
        r_rsip_func101(Param_func412_func101_011);
    }

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
