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

void r_rsip_p89u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p89u_func100_001[] =
        {
            BSWAP_32BIG_C(0xf303b8e1U), BSWAP_32BIG_C(0x1af85895U), BSWAP_32BIG_C(0xd5b03a02U), BSWAP_32BIG_C(
                0x6e44dc9dU),
        };
        r_rsip_func100(Param_p89u_func100_001);

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x0a008106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p89u_func100_002[] =
        {
            BSWAP_32BIG_C(0x5edc1b03U), BSWAP_32BIG_C(0xd9391454U), BSWAP_32BIG_C(0xe3126acdU), BSWAP_32BIG_C(
                0x3ea084ddU),
        };
        r_rsip_func100(Param_p89u_func100_002);

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x0a00810eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p89u_func100_003[] =
        {
            BSWAP_32BIG_C(0xe455a433U), BSWAP_32BIG_C(0xe1a0e21aU), BSWAP_32BIG_C(0x4c3ca482U), BSWAP_32BIG_C(
                0x8168c8a7U),
        };
        r_rsip_func100(Param_p89u_func100_003);

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x0e008506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p89u_func100_004[] =
        {
            BSWAP_32BIG_C(0xe41e0443U), BSWAP_32BIG_C(0x1f8369b5U), BSWAP_32BIG_C(0x188c6164U), BSWAP_32BIG_C(
                0xf34dee1eU),
        };
        r_rsip_func100(Param_p89u_func100_004);

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x0900890eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        static const uint32_t Param_p89u_func100_005[] =
        {
            BSWAP_32BIG_C(0x7ad2412cU), BSWAP_32BIG_C(0x32e3ba10U), BSWAP_32BIG_C(0x81728959U), BSWAP_32BIG_C(
                0x3e431a0dU),
        };
        r_rsip_func100(Param_p89u_func100_005);

        r_rsip_func_sub028(0x00020061U, 0x40000010U, 0x07008d06U);
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

        static const uint32_t Param_p89u_func101_001[] =
        {
            BSWAP_32BIG_C(0xe314fed8U), BSWAP_32BIG_C(0x2f1b277fU), BSWAP_32BIG_C(0x5ee0601eU), BSWAP_32BIG_C(
                0x20dc8d93U),
        };
        r_rsip_func101(Param_p89u_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func214();

        static const uint32_t Param_p89u_func101_002[] =
        {
            BSWAP_32BIG_C(0xac21296cU), BSWAP_32BIG_C(0x74c982d6U), BSWAP_32BIG_C(0x9c2cd4b5U), BSWAP_32BIG_C(
                0x228a3134U),
        };
        r_rsip_func101(Param_p89u_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func214();

        static const uint32_t Param_p89u_func101_003[] =
        {
            BSWAP_32BIG_C(0xd04cf276U), BSWAP_32BIG_C(0x0f2de17eU), BSWAP_32BIG_C(0x4b5d93f7U), BSWAP_32BIG_C(
                0x7b7feebaU),
        };
        r_rsip_func101(Param_p89u_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        r_rsip_func214();

        static const uint32_t Param_p89u_func101_004[] =
        {
            BSWAP_32BIG_C(0xb99d2cb7U), BSWAP_32BIG_C(0xd1c91f22U), BSWAP_32BIG_C(0xb66687b5U), BSWAP_32BIG_C(
                0x3ce6f5dbU),
        };
        r_rsip_func101(Param_p89u_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        r_rsip_func214();

        static const uint32_t Param_p89u_func101_005[] =
        {
            BSWAP_32BIG_C(0x9654977aU), BSWAP_32BIG_C(0xd9dab7afU), BSWAP_32BIG_C(0x60d4b208U), BSWAP_32BIG_C(
                0xda074296U),
        };
        r_rsip_func101(Param_p89u_func101_005);
    }
    else
    {
        ;
    }
}
