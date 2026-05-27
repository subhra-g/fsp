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

void r_rsip_func323 (void)
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
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1404H, 0x1dc80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    WR1_PROG(REG_1014H, 0x00000878U);
    WR1_PROG(REG_1018H, 0x00000fd8U);
    r_rsip_func_sub005(0x00000dc0U, 0x4141000aU, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_143CH, 0x00a10000U);
    static const uint32_t Param_func323_func100_001[] =
    {
        BSWAP_32BIG_C(0x945462eeU), BSWAP_32BIG_C(0xa59c720eU), BSWAP_32BIG_C(0x18768e73U), BSWAP_32BIG_C(0xf844a00bU),
    };
    r_rsip_func100(Param_func323_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func323_func100_002[] =
        {
            BSWAP_32BIG_C(0xeadc10a8U), BSWAP_32BIG_C(0x04cc18bcU), BSWAP_32BIG_C(0xe8bf6fbaU), BSWAP_32BIG_C(
                0x9df19199U),
        };
        r_rsip_func100(Param_func323_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x41410009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func323_func101_001[] =
            {
                BSWAP_32BIG_C(0xcd0914feU), BSWAP_32BIG_C(0x2ac84f0cU), BSWAP_32BIG_C(0x9c6493a8U), BSWAP_32BIG_C(
                    0x090c5e0dU),
            };
            r_rsip_func101(Param_func323_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func323_func101_002[] =
            {
                BSWAP_32BIG_C(0xeb6b2e3aU), BSWAP_32BIG_C(0x4f31f872U), BSWAP_32BIG_C(0x655c3e6aU), BSWAP_32BIG_C(
                    0xc2a68a7cU),
            };
            r_rsip_func101(Param_func323_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func323_func100_003[] =
        {
            BSWAP_32BIG_C(0x7d255405U), BSWAP_32BIG_C(0xf9d0f42cU), BSWAP_32BIG_C(0x8c5c4764U), BSWAP_32BIG_C(
                0x9908b252U),
        };
        r_rsip_func100(Param_func323_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x41410009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func323_func101_003[] =
            {
                BSWAP_32BIG_C(0x6ac26427U), BSWAP_32BIG_C(0x7f7a4df2U), BSWAP_32BIG_C(0x6062a048U), BSWAP_32BIG_C(
                    0x89ecfeffU),
            };
            r_rsip_func101(Param_func323_func101_003);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000878U);
            r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            static const uint32_t Param_func323_func101_004[] =
            {
                BSWAP_32BIG_C(0x3e061fc7U), BSWAP_32BIG_C(0x1e6904fbU), BSWAP_32BIG_C(0x1723f88aU), BSWAP_32BIG_C(
                    0x9e02fea2U),
            };
            r_rsip_func101(Param_func323_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
