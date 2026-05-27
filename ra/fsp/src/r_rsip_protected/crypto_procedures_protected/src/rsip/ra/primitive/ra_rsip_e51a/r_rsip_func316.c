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

void r_rsip_func316 (void)
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
        static const uint32_t Param_func316_func100_001[] =
        {
            BSWAP_32BIG_C(0x1cf2d2c5U), BSWAP_32BIG_C(0x1e04183bU), BSWAP_32BIG_C(0xb85d79d0U), BSWAP_32BIG_C(
                0xa0744604U),
        };
        r_rsip_func100(Param_func316_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x3030000cU, 0x00010001U);
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
            static const uint32_t Param_func316_func100_002[] =
            {
                BSWAP_32BIG_C(0xe5c3df4dU), BSWAP_32BIG_C(0x4ab9b448U), BSWAP_32BIG_C(0x00b32810U), BSWAP_32BIG_C(
                    0xe4571e3bU),
            };
            r_rsip_func100(Param_func316_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x12980000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18b00000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func316_func101_001[] =
                {
                    BSWAP_32BIG_C(0x809dbebcU), BSWAP_32BIG_C(0x014593feU), BSWAP_32BIG_C(0x455020beU), BSWAP_32BIG_C(
                        0x88ef5ffaU),
                };
                r_rsip_func101(Param_func316_func101_001);
            }
            else
            {
                r_rsip_func_sub033(0x1e480000U, 0x00000b7bU, 0x81e0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c90181U);
                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00191U);
                WR1_PROG(REG_1014H, 0x00000428U);
                WR1_PROG(REG_1018H, 0x00000838U);
                r_rsip_func_sub005(0x00000838U, 0x32320009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f316U);
                static const uint32_t Param_func316_func101_002[] =
                {
                    BSWAP_32BIG_C(0x6e536df5U), BSWAP_32BIG_C(0x7bee537eU), BSWAP_32BIG_C(0x1f0db5deU), BSWAP_32BIG_C(
                        0x16040ccaU),
                };
                r_rsip_func101(Param_func316_func101_002);
                r_rsip_func319();
                WR1_PROG(REG_1404H, 0x16a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1e480000U);
                r_rsip_func_sub001(0x00c00191U);
                r_rsip_func_sub015(0x0b040184U, 0xe4f152fdU);
                OFS_ADR = 416;
                r_rsip_func_sub012(0x1e580000U, 0x0000b400U, 0x00000060U);
                r_rsip_func_sub009(0x0000f316U);
                static const uint32_t Param_func316_func101_003[] =
                {
                    BSWAP_32BIG_C(0x8ae55f12U), BSWAP_32BIG_C(0xad1a89feU), BSWAP_32BIG_C(0xa24cb84eU), BSWAP_32BIG_C(
                        0x53ee4b8dU),
                };
                r_rsip_func101(Param_func316_func101_003);
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00191U);
                WR1_PROG(REG_1014H, 0x00000a40U);
                WR1_PROG(REG_1018H, 0x00000838U);
                r_rsip_func_sub005(0x00000838U, 0x32320009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f316U);
                static const uint32_t Param_func316_func101_004[] =
                {
                    BSWAP_32BIG_C(0x4c9ccbf9U), BSWAP_32BIG_C(0x42c0bc08U), BSWAP_32BIG_C(0xb4a217c6U), BSWAP_32BIG_C(
                        0x7f31f200U),
                };
                r_rsip_func101(Param_func316_func101_004);
                r_rsip_func320();
                WR1_PROG(REG_1404H, 0x16a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x16a80000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x3131000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x18b00000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func316_func101_005[] =
                {
                    BSWAP_32BIG_C(0xf2d18d6eU), BSWAP_32BIG_C(0x05c4f242U), BSWAP_32BIG_C(0x22e28684U), BSWAP_32BIG_C(
                        0x46678bbfU),
                };
                r_rsip_func101(Param_func316_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func316_func101_006[] =
            {
                BSWAP_32BIG_C(0x9ffe1754U), BSWAP_32BIG_C(0xaf65feabU), BSWAP_32BIG_C(0x9b77854fU), BSWAP_32BIG_C(
                    0x38a1efa7U),
            };
            r_rsip_func101(Param_func316_func101_006);
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
