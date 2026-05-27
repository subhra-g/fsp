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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_p47u (uint32_t const InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p47u_func100_001[] =
        {
            BSWAP_32BIG_C(0x3a2354a1U), BSWAP_32BIG_C(0x54199b04U), BSWAP_32BIG_C(0xc4156b93U), BSWAP_32BIG_C(
                0xd55f6ebaU),
        };
        r_rsip_func100(Param_p47u_func100_001);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0a000106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p47u_func100_002[] =
        {
            BSWAP_32BIG_C(0x99ba8cefU), BSWAP_32BIG_C(0x63f5414cU), BSWAP_32BIG_C(0x8cdcd890U), BSWAP_32BIG_C(
                0x24d210d7U),
        };
        r_rsip_func100(Param_p47u_func100_002);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0a00010eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p47u_func100_003[] =
        {
            BSWAP_32BIG_C(0x993f883fU), BSWAP_32BIG_C(0x7920a7f7U), BSWAP_32BIG_C(0x9e2488a7U), BSWAP_32BIG_C(
                0x7db23ae7U),
        };
        r_rsip_func100(Param_p47u_func100_003);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0e000506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p47u_func100_004[] =
        {
            BSWAP_32BIG_C(0x395149eaU), BSWAP_32BIG_C(0x82cecc13U), BSWAP_32BIG_C(0xc38d8759U), BSWAP_32BIG_C(
                0x077fa6dbU),
        };
        r_rsip_func100(Param_p47u_func100_004);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0900090eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p47u_func100_005[] =
        {
            BSWAP_32BIG_C(0xdbb0efd9U), BSWAP_32BIG_C(0xecf2f4e6U), BSWAP_32BIG_C(0x7084cfb6U), BSWAP_32BIG_C(
                0x5b481e64U),
        };
        r_rsip_func100(Param_p47u_func100_005);

        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x07000d06U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else
    {
        ;
    }

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Text[0]);
    for (iLoop = 4U; iLoop < MAX_CNT; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func214();

        static const uint32_t Param_p47u_func101_001[] =
        {
            BSWAP_32BIG_C(0xe0ab8198U), BSWAP_32BIG_C(0x89323c6bU), BSWAP_32BIG_C(0xecfdb396U), BSWAP_32BIG_C(
                0x2b843bcaU),
        };
        r_rsip_func101(Param_p47u_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func214();

        static const uint32_t Param_p47u_func101_002[] =
        {
            BSWAP_32BIG_C(0x7d057555U), BSWAP_32BIG_C(0x69c1a7ecU), BSWAP_32BIG_C(0x590253c9U), BSWAP_32BIG_C(
                0xcccd5b37U),
        };
        r_rsip_func101(Param_p47u_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func214();

        static const uint32_t Param_p47u_func101_003[] =
        {
            BSWAP_32BIG_C(0x8d3652b1U), BSWAP_32BIG_C(0x1b846e72U), BSWAP_32BIG_C(0xdeb48362U), BSWAP_32BIG_C(
                0x2b00c63fU),
        };
        r_rsip_func101(Param_p47u_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        r_rsip_func214();

        static const uint32_t Param_p47u_func101_004[] =
        {
            BSWAP_32BIG_C(0x9f659e29U), BSWAP_32BIG_C(0x934675e9U), BSWAP_32BIG_C(0xa9b54b7bU), BSWAP_32BIG_C(
                0xb93e085dU),
        };
        r_rsip_func101(Param_p47u_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        r_rsip_func214();

        static const uint32_t Param_p47u_func101_005[] =
        {
            BSWAP_32BIG_C(0x2c71731eU), BSWAP_32BIG_C(0x60d7f514U), BSWAP_32BIG_C(0x169e094eU), BSWAP_32BIG_C(
                0xfa9f7109U),
        };
        r_rsip_func101(Param_p47u_func101_005);
    }
    else
    {
        ;
    }
}
