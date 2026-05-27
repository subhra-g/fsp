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

rsip_ret_t r_rsip_p73i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
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
    static const uint32_t Param_p73i_func100_001[] =
    {
        BSWAP_32BIG_C(0x10536e75U), BSWAP_32BIG_C(0x331466a8U), BSWAP_32BIG_C(0x7eefde91U), BSWAP_32BIG_C(0xe28e803fU),
    };
    r_rsip_func100(Param_p73i_func100_001);
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub021(0x3420a800U, 0x00000007U, 0x2000b400U, 0x00000006U);
    r_rsip_func_sub014(0x00007c00U, 0x00600000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000000U);
        static const uint32_t Param_p73i_func101_001[] =
        {
            BSWAP_32BIG_C(0xd96bfc9eU), BSWAP_32BIG_C(0x487c02b2U), BSWAP_32BIG_C(0xfc75625fU), BSWAP_32BIG_C(
                0x6053b6c3U),
        };
        r_rsip_func101(Param_p73i_func101_001);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000040U);
        static const uint32_t Param_p73i_func101_002[] =
        {
            BSWAP_32BIG_C(0xd82c8e37U), BSWAP_32BIG_C(0x57edf2f6U), BSWAP_32BIG_C(0x44321c10U), BSWAP_32BIG_C(
                0x9549981fU),
        };
        r_rsip_func101(Param_p73i_func101_002);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000050U);
        static const uint32_t Param_p73i_func101_003[] =
        {
            BSWAP_32BIG_C(0x3aa12cabU), BSWAP_32BIG_C(0x7b307f76U), BSWAP_32BIG_C(0x8d4e154cU), BSWAP_32BIG_C(
                0x61e17003U),
        };
        r_rsip_func101(Param_p73i_func101_003);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000080U);
        static const uint32_t Param_p73i_func101_004[] =
        {
            BSWAP_32BIG_C(0xf197febfU), BSWAP_32BIG_C(0x0acf8d75U), BSWAP_32BIG_C(0x65ffcf05U), BSWAP_32BIG_C(
                0xca09fd44U),
        };
        r_rsip_func101(Param_p73i_func101_004);
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000090U);
        static const uint32_t Param_p73i_func101_005[] =
        {
            BSWAP_32BIG_C(0xf34ef58fU), BSWAP_32BIG_C(0x907ea3cfU), BSWAP_32BIG_C(0xa313eeecU), BSWAP_32BIG_C(
                0x2445166eU),
        };
        r_rsip_func101(Param_p73i_func101_005);
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000a0U);
        static const uint32_t Param_p73i_func101_006[] =
        {
            BSWAP_32BIG_C(0x98d7fc97U), BSWAP_32BIG_C(0xa91c8662U), BSWAP_32BIG_C(0xb76231c5U), BSWAP_32BIG_C(
                0xff218a00U),
        };
        r_rsip_func101(Param_p73i_func101_006);
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000b0U);
        static const uint32_t Param_p73i_func101_007[] =
        {
            BSWAP_32BIG_C(0xd91630c6U), BSWAP_32BIG_C(0x254dddb8U), BSWAP_32BIG_C(0x87ef4539U), BSWAP_32BIG_C(
                0x831051b2U),
        };
        r_rsip_func101(Param_p73i_func101_007);
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);
        static const uint32_t Param_p73i_func101_008[] =
        {
            BSWAP_32BIG_C(0xd7e4dd58U), BSWAP_32BIG_C(0x6deb38e7U), BSWAP_32BIG_C(0x38547147U), BSWAP_32BIG_C(
                0xcea045caU),
        };
        r_rsip_func101(Param_p73i_func101_008);
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2014H, &InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2010H, &InData_MsgLen[1]);
        static const uint32_t Param_p73i_func101_009[] =
        {
            BSWAP_32BIG_C(0xe64467f0U), BSWAP_32BIG_C(0x1ec38968U), BSWAP_32BIG_C(0xace088cfU), BSWAP_32BIG_C(
                0xa6ae0529U),
        };
        r_rsip_func101(Param_p73i_func101_009);
    }

    return RSIP_RET_PASS;
}
