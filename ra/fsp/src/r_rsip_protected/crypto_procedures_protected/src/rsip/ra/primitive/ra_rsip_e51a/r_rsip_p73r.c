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
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p73r (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00730001U);
    WR1_PROG(REG_144CH, 0x00000000U);
    static const uint32_t Param_p73r_func100_001[] =
    {
        BSWAP_32BIG_C(0x10536e75U), BSWAP_32BIG_C(0x331466a8U), BSWAP_32BIG_C(0x7eefde91U), BSWAP_32BIG_C(0xe28e803fU),
    };
    r_rsip_func100(Param_p73r_func100_001);
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub024(0x3420a800U, 0x00000007U, 0x2000b400U, 0x00000006U);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001000U);
        static const uint32_t Param_p73r_func101_001[] =
        {
            BSWAP_32BIG_C(0x2e718b88U), BSWAP_32BIG_C(0xdb4b75c2U), BSWAP_32BIG_C(0xb3a8b0acU), BSWAP_32BIG_C(
                0xf3e09da0U),
        };
        r_rsip_func101(Param_p73r_func101_001);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001040U);
        static const uint32_t Param_p73r_func101_002[] =
        {
            BSWAP_32BIG_C(0xe379ab73U), BSWAP_32BIG_C(0x404c8b84U), BSWAP_32BIG_C(0xe6897dedU), BSWAP_32BIG_C(
                0xf7ab42c5U),
        };
        r_rsip_func101(Param_p73r_func101_002);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001050U);
        static const uint32_t Param_p73r_func101_003[] =
        {
            BSWAP_32BIG_C(0x2316ff0eU), BSWAP_32BIG_C(0xc5fde60dU), BSWAP_32BIG_C(0x863172d9U), BSWAP_32BIG_C(
                0xf9cc187eU),
        };
        r_rsip_func101(Param_p73r_func101_003);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001080U);
        static const uint32_t Param_p73r_func101_004[] =
        {
            BSWAP_32BIG_C(0x11f65666U), BSWAP_32BIG_C(0x499bd4a0U), BSWAP_32BIG_C(0xd344b1f9U), BSWAP_32BIG_C(
                0xf2a866a5U),
        };
        r_rsip_func101(Param_p73r_func101_004);
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001090U);
        static const uint32_t Param_p73r_func101_005[] =
        {
            BSWAP_32BIG_C(0xac484580U), BSWAP_32BIG_C(0xdefd0225U), BSWAP_32BIG_C(0x8430b2c6U), BSWAP_32BIG_C(
                0xfbf4d22fU),
        };
        r_rsip_func101(Param_p73r_func101_005);
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010a0U);
        static const uint32_t Param_p73r_func101_006[] =
        {
            BSWAP_32BIG_C(0xf2ac21deU), BSWAP_32BIG_C(0xa6584e00U), BSWAP_32BIG_C(0xd0dcec5cU), BSWAP_32BIG_C(
                0xac5f5b57U),
        };
        r_rsip_func101(Param_p73r_func101_006);
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010b0U);
        static const uint32_t Param_p73r_func101_007[] =
        {
            BSWAP_32BIG_C(0x20311c6cU), BSWAP_32BIG_C(0xfaa52075U), BSWAP_32BIG_C(0x4cabf318U), BSWAP_32BIG_C(
                0xecbb34e5U),
        };
        r_rsip_func101(Param_p73r_func101_007);
    }

    WR1_PROG(REG_1444H, 0x00000040U);
    WR1_ADDR(REG_2014H, &InData_State[18]);
    WR1_PROG(REG_1444H, 0x00000040U);
    WR1_ADDR(REG_2010H, &InData_State[19]);
    for (iLoop = 0; iLoop < 18; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2028H, &InData_State[iLoop + 0]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    static const uint32_t Param_p73r_func101_008[] =
    {
        BSWAP_32BIG_C(0xafa17b39U), BSWAP_32BIG_C(0x8c4f9b53U), BSWAP_32BIG_C(0x049691c3U), BSWAP_32BIG_C(0x4a78e698U),
    };
    r_rsip_func101(Param_p73r_func101_008);

    return RSIP_RET_PASS;
}
