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

void r_rsip_func319 (void)
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
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1404H, 0x1e480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1014H, 0x00000838U);
    WR1_PROG(REG_1018H, 0x00000fd8U);
    r_rsip_func_sub005(0x00000e40U, 0x3131000aU, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_143CH, 0x00a10000U);
    static const uint32_t Param_func319_func100_001[] =
    {
        BSWAP_32BIG_C(0x2b18a501U), BSWAP_32BIG_C(0x6b9f9bf3U), BSWAP_32BIG_C(0x10db1661U), BSWAP_32BIG_C(0x070c2bb6U),
    };
    r_rsip_func100(Param_func319_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func319_func100_002[] =
        {
            BSWAP_32BIG_C(0x8c104e84U), BSWAP_32BIG_C(0x3f065813U), BSWAP_32BIG_C(0x2fe38abaU), BSWAP_32BIG_C(
                0xdba122edU),
        };
        r_rsip_func100(Param_func319_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x31310009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func319_func101_001[] =
            {
                BSWAP_32BIG_C(0x44352d4fU), BSWAP_32BIG_C(0xc5abe092U), BSWAP_32BIG_C(0xd7d518d4U), BSWAP_32BIG_C(
                    0x0fb7c4b3U),
            };
            r_rsip_func101(Param_func319_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x3131000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func319_func101_002[] =
            {
                BSWAP_32BIG_C(0x502b4635U), BSWAP_32BIG_C(0x883c5953U), BSWAP_32BIG_C(0x5c2122c6U), BSWAP_32BIG_C(
                    0x495ea657U),
            };
            r_rsip_func101(Param_func319_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func319_func100_003[] =
        {
            BSWAP_32BIG_C(0x961ec9e4U), BSWAP_32BIG_C(0xd6027f90U), BSWAP_32BIG_C(0xa6205a40U), BSWAP_32BIG_C(
                0x64a8132aU),
        };
        r_rsip_func100(Param_func319_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x31310009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func319_func101_003[] =
            {
                BSWAP_32BIG_C(0x15b42ad3U), BSWAP_32BIG_C(0xfeb82206U), BSWAP_32BIG_C(0xa3ebfadaU), BSWAP_32BIG_C(
                    0xd1298d6bU),
            };
            r_rsip_func101(Param_func319_func101_003);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000838U);
            r_rsip_func_sub005(0x00000838U, 0x3131000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            static const uint32_t Param_func319_func101_004[] =
            {
                BSWAP_32BIG_C(0x85e8786bU), BSWAP_32BIG_C(0x2e80211bU), BSWAP_32BIG_C(0xb617e995U), BSWAP_32BIG_C(
                    0x40f7463dU),
            };
            r_rsip_func101(Param_func319_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
