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

void r_rsip_func314 (void)
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
    WR1_PROG(REG_1600H, 0x0000379dU);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub017(0x3800db40U, 0x00260000U);
        static const uint32_t Param_func314_func100_001[] =
        {
            BSWAP_32BIG_C(0x5dc4167fU), BSWAP_32BIG_C(0xdfa0e3b1U), BSWAP_32BIG_C(0x3d212490U), BSWAP_32BIG_C(
                0xb10bdaaeU),
        };
        r_rsip_func100(Param_func314_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);
            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);
            static const uint32_t Param_func314_func100_002[] =
            {
                BSWAP_32BIG_C(0x500a3648U), BSWAP_32BIG_C(0x385aed6bU), BSWAP_32BIG_C(0x17e3088cU), BSWAP_32BIG_C(
                    0xc61537c4U),
            };
            r_rsip_func100(Param_func314_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x13580000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19700000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func314_func101_001[] =
                {
                    BSWAP_32BIG_C(0xa0c648b5U), BSWAP_32BIG_C(0x1f9a33f2U), BSWAP_32BIG_C(0x13985f0cU), BSWAP_32BIG_C(
                        0x50f12c36U),
                };
                r_rsip_func101(Param_func314_func101_001);
            }
            else
            {
                r_rsip_func_sub033(0x1f080000U, 0x00000b7bU, 0x81b0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c900c1U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c000d1U);
                WR1_PROG(REG_1014H, 0x00000428U);
                WR1_PROG(REG_1018H, 0x00000838U);
                r_rsip_func_sub005(0x00000838U, 0x1a1a0009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f314U);
                static const uint32_t Param_func314_func101_002[] =
                {
                    BSWAP_32BIG_C(0x06210c5dU), BSWAP_32BIG_C(0x8d0c5b27U), BSWAP_32BIG_C(0x4c1a9e53U), BSWAP_32BIG_C(
                        0x604435feU),
                };
                r_rsip_func101(Param_func314_func101_002);
                r_rsip_func317();
                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1f080000U);
                r_rsip_func_sub001(0x00c000d1U);
                r_rsip_func_sub015(0x0b040184U, 0xf6428095U);
                OFS_ADR = 224;
                r_rsip_func_sub012(0x1f180000U, 0x0000b400U, 0x00000030U);
                r_rsip_func_sub009(0x0000f314U);
                static const uint32_t Param_func314_func101_003[] =
                {
                    BSWAP_32BIG_C(0xf2711aa0U), BSWAP_32BIG_C(0x5dffa914U), BSWAP_32BIG_C(0x619fc2a3U), BSWAP_32BIG_C(
                        0x17082dcbU),
                };
                r_rsip_func101(Param_func314_func101_003);
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c000d1U);
                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                r_rsip_func_sub005(0x00000838U, 0x1a1a0009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f314U);
                static const uint32_t Param_func314_func101_004[] =
                {
                    BSWAP_32BIG_C(0x578e3a3bU), BSWAP_32BIG_C(0x1149611eU), BSWAP_32BIG_C(0x817ba55fU), BSWAP_32BIG_C(
                        0x43d449d0U),
                };
                r_rsip_func101(Param_func314_func101_004);
                r_rsip_func318();
                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x1919000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func314_func101_005[] =
                {
                    BSWAP_32BIG_C(0x50ba135fU), BSWAP_32BIG_C(0x781953f9U), BSWAP_32BIG_C(0xf05b8d42U), BSWAP_32BIG_C(
                        0xbc2c9d9dU),
                };
                r_rsip_func101(Param_func314_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func314_func101_006[] =
            {
                BSWAP_32BIG_C(0xb4a0384fU), BSWAP_32BIG_C(0xcd3cd70fU), BSWAP_32BIG_C(0xad73a83cU), BSWAP_32BIG_C(
                    0xd9e13823U),
            };
            r_rsip_func101(Param_func314_func101_006);
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
