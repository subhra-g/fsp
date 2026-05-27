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

void r_rsip_func317 (void)
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
    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1404H, 0x1f080000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1014H, 0x00000838U);
    WR1_PROG(REG_1018H, 0x00000fd8U);
    r_rsip_func_sub005(0x00000e40U, 0x1919000aU, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_143CH, 0x00a10000U);
    static const uint32_t Param_func317_func100_001[] =
    {
        BSWAP_32BIG_C(0xf8e56780U), BSWAP_32BIG_C(0x3a4fdfc3U), BSWAP_32BIG_C(0x6e457e11U), BSWAP_32BIG_C(0x9fa6f941U),
    };
    r_rsip_func100(Param_func317_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func317_func100_002[] =
        {
            BSWAP_32BIG_C(0xa4fe85bfU), BSWAP_32BIG_C(0xff262367U), BSWAP_32BIG_C(0xd5bb1200U), BSWAP_32BIG_C(
                0xfd0dc3e3U),
        };
        r_rsip_func100(Param_func317_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x19190009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func317_func101_001[] =
            {
                BSWAP_32BIG_C(0x08b452a4U), BSWAP_32BIG_C(0xd8df04f6U), BSWAP_32BIG_C(0xc00fdc23U), BSWAP_32BIG_C(
                    0x0abc3e5fU),
            };
            r_rsip_func101(Param_func317_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func317_func101_002[] =
            {
                BSWAP_32BIG_C(0xf2f2891eU), BSWAP_32BIG_C(0xd3f679d5U), BSWAP_32BIG_C(0xd16af82eU), BSWAP_32BIG_C(
                    0xff68bb0cU),
            };
            r_rsip_func101(Param_func317_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func317_func100_003[] =
        {
            BSWAP_32BIG_C(0xf7e82dc0U), BSWAP_32BIG_C(0x531eddacU), BSWAP_32BIG_C(0x9c9094cfU), BSWAP_32BIG_C(
                0xa5e8a2d3U),
        };
        r_rsip_func100(Param_func317_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x19190009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func317_func101_003[] =
            {
                BSWAP_32BIG_C(0x21b9808cU), BSWAP_32BIG_C(0x0f0f51f2U), BSWAP_32BIG_C(0x15e955c8U), BSWAP_32BIG_C(
                    0xd6165721U),
            };
            r_rsip_func101(Param_func317_func101_003);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000838U);
            r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            static const uint32_t Param_func317_func101_004[] =
            {
                BSWAP_32BIG_C(0xebe6b879U), BSWAP_32BIG_C(0xd20a4ba3U), BSWAP_32BIG_C(0x309915fbU), BSWAP_32BIG_C(
                    0x58c816eeU),
            };
            r_rsip_func101(Param_func317_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
