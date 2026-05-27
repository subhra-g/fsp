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

void r_rsip_func324 (void)
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
    static const uint32_t Param_func324_func100_001[] =
    {
        BSWAP_32BIG_C(0xf69c273aU), BSWAP_32BIG_C(0x13d0dc4dU), BSWAP_32BIG_C(0xef687aceU), BSWAP_32BIG_C(0xccb6d252U),
    };
    r_rsip_func100(Param_func324_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func324_func100_002[] =
        {
            BSWAP_32BIG_C(0x406125cdU), BSWAP_32BIG_C(0xd12ca7cbU), BSWAP_32BIG_C(0x25017b67U), BSWAP_32BIG_C(
                0x526a9fefU),
        };
        r_rsip_func100(Param_func324_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func324_func101_001[] =
            {
                BSWAP_32BIG_C(0x969cc120U), BSWAP_32BIG_C(0x822333ffU), BSWAP_32BIG_C(0xdbf5ec45U), BSWAP_32BIG_C(
                    0x8dd3c9a4U),
            };
            r_rsip_func101(Param_func324_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x41410009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func324_func101_002[] =
            {
                BSWAP_32BIG_C(0x1a9be375U), BSWAP_32BIG_C(0xfdeef395U), BSWAP_32BIG_C(0x16e7995aU), BSWAP_32BIG_C(
                    0xf1e06273U),
            };
            r_rsip_func101(Param_func324_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);
        static const uint32_t Param_func324_func100_003[] =
        {
            BSWAP_32BIG_C(0x124150baU), BSWAP_32BIG_C(0x81090e58U), BSWAP_32BIG_C(0x5a3038f5U), BSWAP_32BIG_C(
                0x45812fc7U),
        };
        r_rsip_func100(Param_func324_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000fd8U);
            WR1_PROG(REG_1018H, 0x00000878U);
            r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            static const uint32_t Param_func324_func101_003[] =
            {
                BSWAP_32BIG_C(0x92f2b483U), BSWAP_32BIG_C(0x76827772U), BSWAP_32BIG_C(0x72c80721U), BSWAP_32BIG_C(
                    0x8ae46f4bU),
            };
            r_rsip_func101(Param_func324_func101_003);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x41410009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func324_func101_004[] =
            {
                BSWAP_32BIG_C(0xecbd178dU), BSWAP_32BIG_C(0xa4583182U), BSWAP_32BIG_C(0x104893bdU), BSWAP_32BIG_C(
                    0x8b6b5a49U),
            };
            r_rsip_func101(Param_func324_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
