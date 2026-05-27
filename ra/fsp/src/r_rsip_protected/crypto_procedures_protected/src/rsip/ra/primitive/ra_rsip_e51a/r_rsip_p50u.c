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

void r_rsip_p50u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p50u_func100_001[] =
        {
            BSWAP_32BIG_C(0x02e2bebbU), BSWAP_32BIG_C(0x197f36b2U), BSWAP_32BIG_C(0x2dab0db6U), BSWAP_32BIG_C(
                0x8a6edbf4U),
        };
        r_rsip_func100(Param_p50u_func100_001);

        r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x0a008106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p50u_func100_002[] =
        {
            BSWAP_32BIG_C(0x8e117143U), BSWAP_32BIG_C(0xf50e82bbU), BSWAP_32BIG_C(0x24d387a5U), BSWAP_32BIG_C(
                0x08be162cU),
        };
        r_rsip_func100(Param_p50u_func100_002);

        r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x0a00810eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p50u_func100_003[] =
        {
            BSWAP_32BIG_C(0x8f5136ceU), BSWAP_32BIG_C(0xcc92a0bfU), BSWAP_32BIG_C(0xae1d5aa4U), BSWAP_32BIG_C(
                0x4c80ddc3U),
        };
        r_rsip_func100(Param_p50u_func100_003);

        r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x0e008506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p50u_func100_004[] =
        {
            BSWAP_32BIG_C(0xc5831880U), BSWAP_32BIG_C(0x638beea0U), BSWAP_32BIG_C(0xef27fe4fU), BSWAP_32BIG_C(
                0x39eb4be1U),
        };
        r_rsip_func100(Param_p50u_func100_004);

        r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x0900890eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p50u_func100_005[] =
        {
            BSWAP_32BIG_C(0x7c9a6a45U), BSWAP_32BIG_C(0x1458c047U), BSWAP_32BIG_C(0xbe0431e0U), BSWAP_32BIG_C(
                0x4f94615bU),
        };
        r_rsip_func100(Param_p50u_func100_005);

        r_rsip_func_sub028(0x00020061U, 0x40000000U, 0x07008d06U);
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

        static const uint32_t Param_p50u_func101_001[] =
        {
            BSWAP_32BIG_C(0x08d83b3aU), BSWAP_32BIG_C(0xf809bf2eU), BSWAP_32BIG_C(0x078e4610U), BSWAP_32BIG_C(
                0x221efdd8U),
        };
        r_rsip_func101(Param_p50u_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func214();

        static const uint32_t Param_p50u_func101_002[] =
        {
            BSWAP_32BIG_C(0xe5187f09U), BSWAP_32BIG_C(0xac474836U), BSWAP_32BIG_C(0x1afc0432U), BSWAP_32BIG_C(
                0x958fd8faU),
        };
        r_rsip_func101(Param_p50u_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func214();

        static const uint32_t Param_p50u_func101_003[] =
        {
            BSWAP_32BIG_C(0xf3dc0990U), BSWAP_32BIG_C(0x5239d741U), BSWAP_32BIG_C(0xe177e8caU), BSWAP_32BIG_C(
                0xaedd1c19U),
        };
        r_rsip_func101(Param_p50u_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        r_rsip_func214();

        static const uint32_t Param_p50u_func101_004[] =
        {
            BSWAP_32BIG_C(0x6c296703U), BSWAP_32BIG_C(0x3ab077efU), BSWAP_32BIG_C(0xc39ef4e1U), BSWAP_32BIG_C(
                0x8d60bf8fU),
        };
        r_rsip_func101(Param_p50u_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        r_rsip_func214();

        static const uint32_t Param_p50u_func101_005[] =
        {
            BSWAP_32BIG_C(0x27bd620fU), BSWAP_32BIG_C(0xbf71e04aU), BSWAP_32BIG_C(0xf2b0b401U), BSWAP_32BIG_C(
                0x39d52466U),
        };
        r_rsip_func101(Param_p50u_func101_005);
    }
    else
    {
        ;
    }
}
