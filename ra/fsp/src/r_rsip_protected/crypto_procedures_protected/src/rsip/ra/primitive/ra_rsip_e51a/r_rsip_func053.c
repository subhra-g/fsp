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

void r_rsip_func053 (void)
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

        static const uint32_t Param_func053_func100_001[] =
        {
            BSWAP_32BIG_C(0xe6bfc659U), BSWAP_32BIG_C(0xaf9aa26cU), BSWAP_32BIG_C(0xc8e73f5cU), BSWAP_32BIG_C(
                0x199a1c3dU),
        };
        r_rsip_func100(Param_func053_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1010000cU, 0x00010001U);
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

            static const uint32_t Param_func053_func100_002[] =
            {
                BSWAP_32BIG_C(0x12dd95b0U), BSWAP_32BIG_C(0xbe6c58beU), BSWAP_32BIG_C(0x9bdf49fcU), BSWAP_32BIG_C(
                    0x221d17fcU),
            };
            r_rsip_func100(Param_func053_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x13980000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19b00000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000428U);
                r_rsip_func_sub005(0x00000428U, 0x1111000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1014H, 0x00000a40U);
                r_rsip_func_sub005(0x00000a40U, 0x1111000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func053_func101_001[] =
                {
                    BSWAP_32BIG_C(0xc13881d8U), BSWAP_32BIG_C(0x8f55227dU), BSWAP_32BIG_C(0xb9d32959U), BSWAP_32BIG_C(
                        0xce03406eU),
                };
                r_rsip_func101(Param_func053_func101_001);
            }
            else
            {
                r_rsip_func_sub033(0x1f480000U, 0x00000b7bU, 0x81a0001bU);
                r_rsip_func_sub001(0x00c00011U);
                r_rsip_func_sub001(0x00c90081U);

                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_func_sub001(0x00c00091U);
                r_rsip_func_sub002(0x00000428U, 0x00000838U, 0x00000838U, 0x12120009U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f053U);

                static const uint32_t Param_func053_func101_002[] =
                {
                    BSWAP_32BIG_C(0xccf9c189U), BSWAP_32BIG_C(0x98d77cf7U), BSWAP_32BIG_C(0xad66dba6U), BSWAP_32BIG_C(
                        0x1f2c9932U),
                };
                r_rsip_func101(Param_func053_func101_002);
                r_rsip_func302();

                WR1_PROG(REG_1404H, 0x17a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000428U, 0x1111000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                WR1_PROG(REG_1404H, 0x1f480000U);
                r_rsip_func_sub001(0x00c00091U);

                r_rsip_func_sub004(0x0b040184U, 0x093b7d04U);

                OFS_ADR = 160;

                r_rsip_func_sub012(0x1f580000U, 0x0000b400U, 0x00000020U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f053U);

                static const uint32_t Param_func053_func101_003[] =
                {
                    BSWAP_32BIG_C(0x508b97d6U), BSWAP_32BIG_C(0x0506d2e3U), BSWAP_32BIG_C(0x539b32c2U), BSWAP_32BIG_C(
                        0x86244960U),
                };
                r_rsip_func101(Param_func053_func101_003);
                r_rsip_func017(OFS_ADR);

                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_func_sub001(0x00c00091U);
                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000838U, 0x12120009U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f053U);

                static const uint32_t Param_func053_func101_004[] =
                {
                    BSWAP_32BIG_C(0x9662b54eU), BSWAP_32BIG_C(0x60ac207aU), BSWAP_32BIG_C(0x8ef02d9dU), BSWAP_32BIG_C(
                        0x9a705dceU),
                };
                r_rsip_func101(Param_func053_func101_004);
                r_rsip_func303();

                WR1_PROG(REG_1404H, 0x17a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);

                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_func_sub001(0x00c00009U);

                WR1_PROG(REG_1014H, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x1111000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);

                static const uint32_t Param_func053_func101_005[] =
                {
                    BSWAP_32BIG_C(0xffc80b1aU), BSWAP_32BIG_C(0x97eae19fU), BSWAP_32BIG_C(0xf22d352bU), BSWAP_32BIG_C(
                        0xd442eedbU),
                };
                r_rsip_func101(Param_func053_func101_005);
            }
        }
        else
        {
            static const uint32_t Param_func053_func101_006[] =
            {
                BSWAP_32BIG_C(0x15aec9a0U), BSWAP_32BIG_C(0xa660fc1aU), BSWAP_32BIG_C(0x3b76b919U), BSWAP_32BIG_C(
                    0x2f5393d5U),
            };
            r_rsip_func101(Param_func053_func101_006);

            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
