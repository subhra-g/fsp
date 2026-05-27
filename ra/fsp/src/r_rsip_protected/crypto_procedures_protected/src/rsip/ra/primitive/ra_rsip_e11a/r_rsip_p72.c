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

rsip_ret_t r_rsip_p72 (const uint32_t InData_InitVal[],
                       const uint32_t InData_PaddedMsg[],
                       uint32_t       MAX_CNT,
                       uint32_t       OutData_MsgDigest[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_0068H, 0x00000016U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00720001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00F4H, 0x00000010U);

    WAIT_STS(REG_00F8H, 0, 1);

    WR1_PROG(REG_0014H, 0x000007c4U);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_ADDR(REG_002CH, &InData_InitVal[0]);

    WR1_PROG(REG_00F4H, 0x00000011U);

    WAIT_STS(REG_00F8H, 0, 1);

    WR1_PROG(REG_0014H, 0x00000064U);
    for (iLoop = 0U; iLoop < MAX_CNT; )
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR16_ADDR(REG_002CH, &InData_PaddedMsg[iLoop]);
        iLoop = iLoop + 16U;
    }

    WAIT_STS(REG_00F8H, 2, 0);

    WR1_PROG(REG_0014H, 0x00000000U);

    WR1_PROG(REG_00F4H, 0x00000100U);

    WR1_PROG(REG_00F4H, 0x00000020U);

    WAIT_STS(REG_00F8H, 1, 1);

    static const uint32_t Param_p72_func100_001[] =
    {
        BSWAP_32BIG_C(0xd5c794efU), BSWAP_32BIG_C(0xce7c7a3eU), BSWAP_32BIG_C(0xc28e8f4dU), BSWAP_32BIG_C(0x0397efbaU),
    };
    r_rsip_func100(Param_p72_func100_001);
    WR1_PROG(REG_0008H, 0x00004022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD8_ADDR(REG_002CH, &OutData_MsgDigest[0]);

    static const uint32_t Param_p72_func102_001[] =
    {
        BSWAP_32BIG_C(0x0ba55075U), BSWAP_32BIG_C(0x2f2be51dU), BSWAP_32BIG_C(0x2589c3e2U), BSWAP_32BIG_C(0x152821acU),
    };
    r_rsip_func102(Param_p72_func102_001);
    WR1_PROG(REG_0068H, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
