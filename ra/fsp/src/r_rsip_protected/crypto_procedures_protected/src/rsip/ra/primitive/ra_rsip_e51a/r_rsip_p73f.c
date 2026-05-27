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

rsip_ret_t r_rsip_p73f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
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
    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 15]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    static const uint32_t Param_p73f_func100_001[] =
    {
        BSWAP_32BIG_C(0x613b57a1U), BSWAP_32BIG_C(0x38d28e4fU), BSWAP_32BIG_C(0x4b09cd77U), BSWAP_32BIG_C(0x8bfdc1d0U),
    };
    r_rsip_func100(Param_p73f_func100_001);
    r_rsip_func_sub024(0x38008800U, 0x00000003U, 0x1000b400U, 0x00000001U);
    r_rsip_func_sub024(0x38008800U, 0x00000004U, 0x1000b400U, 0x00000002U);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        static const uint32_t Param_p73f_func100_002[] =
        {
            BSWAP_32BIG_C(0xc75eca98U), BSWAP_32BIG_C(0x1508e263U), BSWAP_32BIG_C(0x8f4ec345U), BSWAP_32BIG_C(
                0x120a26f4U),
        };
        r_rsip_func100(Param_p73f_func100_002);
        WR1_PROG(REG_1408H, 0x00004016U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        static const uint32_t Param_p73f_func102_001[] =
        {
            BSWAP_32BIG_C(0x69817aadU), BSWAP_32BIG_C(0x2fb02a70U), BSWAP_32BIG_C(0x66054079U), BSWAP_32BIG_C(
                0xef752c92U),
        };
        r_rsip_func102(Param_p73f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        static const uint32_t Param_p73f_func100_003[] =
        {
            BSWAP_32BIG_C(0x847fb73eU), BSWAP_32BIG_C(0xb646991bU), BSWAP_32BIG_C(0x14997e83U), BSWAP_32BIG_C(
                0x4395df73U),
        };
        r_rsip_func100(Param_p73f_func100_003);
        WR1_PROG(REG_1408H, 0x0000401eU);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        static const uint32_t Param_p73f_func102_002[] =
        {
            BSWAP_32BIG_C(0xf1554fc6U), BSWAP_32BIG_C(0x172cf756U), BSWAP_32BIG_C(0xc99402ccU), BSWAP_32BIG_C(
                0x1f826902U),
        };
        r_rsip_func102(Param_p73f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        static const uint32_t Param_p73f_func100_004[] =
        {
            BSWAP_32BIG_C(0xcffad43aU), BSWAP_32BIG_C(0x6a8ffd50U), BSWAP_32BIG_C(0xf5113be8U), BSWAP_32BIG_C(
                0x74dcf42aU),
        };
        r_rsip_func100(Param_p73f_func100_004);
        WR1_PROG(REG_1408H, 0x00004022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        static const uint32_t Param_p73f_func102_003[] =
        {
            BSWAP_32BIG_C(0x7333795fU), BSWAP_32BIG_C(0x1b3df1e3U), BSWAP_32BIG_C(0xfbad3912U), BSWAP_32BIG_C(
                0x873b50f8U),
        };
        r_rsip_func102(Param_p73f_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        static const uint32_t Param_p73f_func100_005[] =
        {
            BSWAP_32BIG_C(0xeccf52aaU), BSWAP_32BIG_C(0xcfe6d35aU), BSWAP_32BIG_C(0xab729384U), BSWAP_32BIG_C(
                0x91f8352fU),
        };
        r_rsip_func100(Param_p73f_func100_005);
        WR1_PROG(REG_1408H, 0x00004032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        static const uint32_t Param_p73f_func102_004[] =
        {
            BSWAP_32BIG_C(0x02b2d092U), BSWAP_32BIG_C(0xa0f3ae9eU), BSWAP_32BIG_C(0xbf85d244U), BSWAP_32BIG_C(
                0xd2000f8cU),
        };
        r_rsip_func102(Param_p73f_func102_004);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        static const uint32_t Param_p73f_func100_006[] =
        {
            BSWAP_32BIG_C(0xa5cbf736U), BSWAP_32BIG_C(0x790cf329U), BSWAP_32BIG_C(0xb2d617c5U), BSWAP_32BIG_C(
                0xfdd5d816U),
        };
        r_rsip_func100(Param_p73f_func100_006);
        WR1_PROG(REG_1408H, 0x00004042U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[12]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[13]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[14]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[15]);
        static const uint32_t Param_p73f_func102_005[] =
        {
            BSWAP_32BIG_C(0x857b2da2U), BSWAP_32BIG_C(0x1c05c7d2U), BSWAP_32BIG_C(0xc96239a2U), BSWAP_32BIG_C(
                0xc51438b2U),
        };
        r_rsip_func102(Param_p73f_func102_005);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }

    return RSIP_RET_PASS;
}
