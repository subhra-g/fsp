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

void r_rsip_func318 (void)
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
    static const uint32_t Param_func318_func100_001[] =
    {
        BSWAP_32BIG_C(0x030bb516U), BSWAP_32BIG_C(0xa9363583U), BSWAP_32BIG_C(0xc6b220d9U), BSWAP_32BIG_C(0x84195d60U),
    };
    r_rsip_func100(Param_func318_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func318_func100_002[] =
        {
            BSWAP_32BIG_C(0x157f6cebU), BSWAP_32BIG_C(0x0d0ea321U), BSWAP_32BIG_C(0x2d4eba59U), BSWAP_32BIG_C(
                0xb3073413U),
        };
        r_rsip_func100(Param_func318_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func318_func101_001[] =
            {
                BSWAP_32BIG_C(0x312282acU), BSWAP_32BIG_C(0xc49f1e0aU), BSWAP_32BIG_C(0x990e458eU), BSWAP_32BIG_C(
                    0x320fc040U),
            };
            r_rsip_func101(Param_func318_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x19190009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func318_func101_002[] =
            {
                BSWAP_32BIG_C(0x8a6da6a6U), BSWAP_32BIG_C(0xca2f50cdU), BSWAP_32BIG_C(0x185a481fU), BSWAP_32BIG_C(
                    0x6b6d11b2U),
            };
            r_rsip_func101(Param_func318_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func318_func100_003[] =
        {
            BSWAP_32BIG_C(0x848b466bU), BSWAP_32BIG_C(0xf1b2db4fU), BSWAP_32BIG_C(0x5d4f5aecU), BSWAP_32BIG_C(
                0x35f9ab17U),
        };
        r_rsip_func100(Param_func318_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000838U);
            r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            static const uint32_t Param_func318_func101_003[] =
            {
                BSWAP_32BIG_C(0xf4ec94fcU), BSWAP_32BIG_C(0xf09fb31eU), BSWAP_32BIG_C(0x52b4cf42U), BSWAP_32BIG_C(
                    0x444b5c93U),
            };
            r_rsip_func101(Param_func318_func101_003);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x19190009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func318_func101_004[] =
            {
                BSWAP_32BIG_C(0xed48e28cU), BSWAP_32BIG_C(0x82424e00U), BSWAP_32BIG_C(0x6ab07c7fU), BSWAP_32BIG_C(
                    0xa6c9792bU),
            };
            r_rsip_func101(Param_func318_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
