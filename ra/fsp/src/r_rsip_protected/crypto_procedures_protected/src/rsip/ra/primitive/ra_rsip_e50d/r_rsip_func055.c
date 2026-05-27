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

void r_rsip_func055 (void)
{
    uint32_t OFS_ADR = 0U;

    WR1_PROG(REG_1600H, 0x0000379dU);

    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800db40U, 0x00260000U);

        static const uint32_t Param_func055_func100_001[] =
        {
            BSWAP_32BIG_C(0xb2afc141U), BSWAP_32BIG_C(0x44b89cc5U), BSWAP_32BIG_C(0x55a5e2a1U), BSWAP_32BIG_C(
                0x99dffeefU),
        };
        r_rsip_func100(Param_func055_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x2020000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);

            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);

            static const uint32_t Param_func055_func100_002[] =
            {
                BSWAP_32BIG_C(0x516afcbcU), BSWAP_32BIG_C(0x4d21b6b3U), BSWAP_32BIG_C(0x069ab47cU), BSWAP_32BIG_C(
                    0x2bb97c4aU),
            };
            r_rsip_func100(Param_func055_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x13180000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19300000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func055_func101_001[] =
                {
                    BSWAP_32BIG_C(0xbcf1ede3U), BSWAP_32BIG_C(0xd770d388U), BSWAP_32BIG_C(0x1af6933fU), BSWAP_32BIG_C(
                        0xaba770ceU),
                };
                r_rsip_func101(Param_func055_func101_001);
            }
            else
            {
                r_rsip_func_sub030(0x1ec80000U, 0x00000b7bU, 0x81c0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c90101U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00111U);
                r_rsip_func_sub002(0x00000428U, 0x00000838U, 0x00000838U, 0x22220009U);

                r_rsip_func_sub003(0x800103a0U, 0x00000f55U);

                static const uint32_t Param_func055_func101_002[] =
                {
                    BSWAP_32BIG_C(0x781dd1b0U), BSWAP_32BIG_C(0xc76bd809U), BSWAP_32BIG_C(0xb6f78051U), BSWAP_32BIG_C(
                        0x6e5f424dU),
                };
                r_rsip_func101(Param_func055_func101_002);
                r_rsip_func304();

                WR1_PROG(REG_1404H, 0x17280000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13180000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1ec80000U);
                r_rsip_func_sub001(0x00c00111U);

                r_rsip_func_sub004(0x0b040184U, 0x9bee78e8U);

                OFS_ADR = 288;

                r_rsip_func_sub012(0x1ed80000U, 0x0000b400U, 0x00000040U);

                r_rsip_func_sub003(0x800103a0U, 0x00000f55U);

                static const uint32_t Param_func055_func101_003[] =
                {
                    BSWAP_32BIG_C(0x3c082c29U), BSWAP_32BIG_C(0x11235aaaU), BSWAP_32BIG_C(0xf16e22e3U), BSWAP_32BIG_C(
                        0x646ef9d1U),
                };
                r_rsip_func101(Param_func055_func101_003);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00111U);
                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000838U, 0x22220009U);

                r_rsip_func_sub003(0x800103a0U, 0x00000f55U);

                static const uint32_t Param_func055_func101_004[] =
                {
                    BSWAP_32BIG_C(0xf1508e66U), BSWAP_32BIG_C(0x129727f9U), BSWAP_32BIG_C(0x3a5e5508U), BSWAP_32BIG_C(
                        0x9408e4d3U),
                };
                r_rsip_func101(Param_func055_func101_004);
                r_rsip_func305();

                WR1_PROG(REG_1404H, 0x17280000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17280000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x2121000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x19300000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func055_func101_005[] =
                {
                    BSWAP_32BIG_C(0x6ba2e5a3U), BSWAP_32BIG_C(0xee1adb9bU), BSWAP_32BIG_C(0x5cc8fa16U), BSWAP_32BIG_C(
                        0x85250fc8U),
                };
                r_rsip_func101(Param_func055_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func055_func101_006[] =
            {
                BSWAP_32BIG_C(0xcdb5da5eU), BSWAP_32BIG_C(0x081350ddU), BSWAP_32BIG_C(0xd48cfd0aU), BSWAP_32BIG_C(
                    0xbc08f52aU),
            };
            r_rsip_func101(Param_func055_func101_006);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
