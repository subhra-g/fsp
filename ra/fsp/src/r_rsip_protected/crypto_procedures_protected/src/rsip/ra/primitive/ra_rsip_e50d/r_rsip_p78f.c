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

rsip_ret_t r_rsip_p78f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); )
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; )
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
            jLoop = jLoop + 2;
        }

        iLoop = iLoop + S_RAM[0];
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    WAIT_STS(REG_2440H, 4, 1);

    static const uint32_t Param_p78f_func100_001[] =
    {
        BSWAP_32BIG_C(0x821d6b06U), BSWAP_32BIG_C(0x5848947aU), BSWAP_32BIG_C(0x5e41f7a2U), BSWAP_32BIG_C(0x10e0f686U),
    };
    r_rsip_func100(Param_p78f_func100_001);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p78f_func100_002[] =
        {
            BSWAP_32BIG_C(0x81883187U), BSWAP_32BIG_C(0x51d34f14U), BSWAP_32BIG_C(0xe98fd1a7U), BSWAP_32BIG_C(
                0x727b8cf7U),
        };
        r_rsip_func100(Param_p78f_func100_002);
        WR1_PROG(REG_1408H, 0x0000601eU);
        WAIT_STS(REG_1408H, 30, 1);
        RD7_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_001[] =
        {
            BSWAP_32BIG_C(0xe032ece8U), BSWAP_32BIG_C(0xd7fab98cU), BSWAP_32BIG_C(0xeb863875U), BSWAP_32BIG_C(
                0xeebb3619U),
        };
        r_rsip_func102(Param_p78f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p78f_func100_003[] =
        {
            BSWAP_32BIG_C(0xf599829aU), BSWAP_32BIG_C(0x7697c8a5U), BSWAP_32BIG_C(0x5a729547U), BSWAP_32BIG_C(
                0x7947ab83U),
        };
        r_rsip_func100(Param_p78f_func100_003);
        WR1_PROG(REG_1408H, 0x00006022U);
        WAIT_STS(REG_1408H, 30, 1);
        RD8_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_002[] =
        {
            BSWAP_32BIG_C(0x86ed2579U), BSWAP_32BIG_C(0xda8378a5U), BSWAP_32BIG_C(0x81b51eb8U), BSWAP_32BIG_C(
                0xc72bcfc8U),
        };
        r_rsip_func102(Param_p78f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p78f_func100_004[] =
        {
            BSWAP_32BIG_C(0xcbfdffe6U), BSWAP_32BIG_C(0x0b0b5955U), BSWAP_32BIG_C(0xa1d63f89U), BSWAP_32BIG_C(
                0x4a6233fdU),
        };
        r_rsip_func100(Param_p78f_func100_004);
        WR1_PROG(REG_1408H, 0x00006032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD12_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_003[] =
        {
            BSWAP_32BIG_C(0x4b1f9169U), BSWAP_32BIG_C(0x40ba17e2U), BSWAP_32BIG_C(0x8b807cc9U), BSWAP_32BIG_C(
                0x81191506U),
        };
        r_rsip_func102(Param_p78f_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        static const uint32_t Param_p78f_func100_005[] =
        {
            BSWAP_32BIG_C(0x2bc0e784U), BSWAP_32BIG_C(0xef533ca5U), BSWAP_32BIG_C(0x1800bbcfU), BSWAP_32BIG_C(
                0x4615151cU),
        };
        r_rsip_func100(Param_p78f_func100_005);
        WR1_PROG(REG_1408H, 0x00006042U);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_MsgDigest[0]);

        static const uint32_t Param_p78f_func102_004[] =
        {
            BSWAP_32BIG_C(0xf2e9ffb3U), BSWAP_32BIG_C(0x4ac6cf8dU), BSWAP_32BIG_C(0x3854cdb7U), BSWAP_32BIG_C(
                0x70b53668U),
        };
        r_rsip_func102(Param_p78f_func102_004);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return RSIP_RET_PASS;
}
