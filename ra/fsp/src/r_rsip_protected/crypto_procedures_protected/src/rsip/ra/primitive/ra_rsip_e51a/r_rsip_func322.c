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

void r_rsip_func322 (void)
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
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub017(0x3800db40U, 0x00260000U);
        static const uint32_t Param_func322_func100_001[] =
        {
            BSWAP_32BIG_C(0xb1dd5988U), BSWAP_32BIG_C(0x6724050aU), BSWAP_32BIG_C(0x1fb6da00U), BSWAP_32BIG_C(
                0xcb12386dU),
        };
        r_rsip_func100(Param_func322_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000230U);
            r_rsip_func_sub005(0x00000230U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a880000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub001(0x03430005U);
            r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);
            static const uint32_t Param_func322_func100_002[] =
            {
                BSWAP_32BIG_C(0x70785f8eU), BSWAP_32BIG_C(0xf531bb18U), BSWAP_32BIG_C(0xd3f02cd6U), BSWAP_32BIG_C(
                    0xabcc7de7U),
            };
            r_rsip_func100(Param_func322_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x12380000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18800000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000448U);
                r_rsip_func_sub005(0x00000448U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000a90U);
                r_rsip_func_sub005(0x00000a90U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func322_func101_001[] =
                {
                    BSWAP_32BIG_C(0xb4b65d12U), BSWAP_32BIG_C(0x0b0077e7U), BSWAP_32BIG_C(0xb41fa2b3U), BSWAP_32BIG_C(
                        0x65c2a4c8U),
                };
                r_rsip_func101(Param_func322_func101_001);
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_func_sub001(0x00c00211U);
                r_rsip_func_sub015(0x0b040184U, 0x8162b38bU);
                OFS_ADR = 676;
                r_rsip_func_sub012(0x1dd80000U, 0x0000b400U, 0x00000080U);
                r_rsip_func_sub009(0x00003221U);
                static const uint32_t Param_func322_func101_002[] =
                {
                    BSWAP_32BIG_C(0xacf207f3U), BSWAP_32BIG_C(0x152726d7U), BSWAP_32BIG_C(0x7e0bcc84U), BSWAP_32BIG_C(
                        0x4f5dc8e5U),
                };
                r_rsip_func101(Param_func322_func101_002);
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00211U);
                WR1_PROG(REG_1014H, 0x00000448U);
                WR1_PROG(REG_1018H, 0x00000878U);
                r_rsip_func_sub005(0x00000878U, 0x42420009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f322U);
                static const uint32_t Param_func322_func101_003[] =
                {
                    BSWAP_32BIG_C(0xa2fa752eU), BSWAP_32BIG_C(0x67b01aafU), BSWAP_32BIG_C(0x7fa73a51U), BSWAP_32BIG_C(
                        0x78169ab1U),
                };
                r_rsip_func101(Param_func322_func101_003);
                r_rsip_func323();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000878U);
                r_rsip_func_sub005(0x00000448U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_func_sub001(0x00c00211U);
                r_rsip_func_sub015(0x0b040184U, 0x7edfb1abU);
                OFS_ADR = 544;
                r_rsip_func_sub012(0x1dd80000U, 0x0000b400U, 0x00000080U);
                r_rsip_func_sub009(0x00003222U);
                static const uint32_t Param_func322_func101_004[] =
                {
                    BSWAP_32BIG_C(0xf66ac87eU), BSWAP_32BIG_C(0xa61626cdU), BSWAP_32BIG_C(0xc7b198c4U), BSWAP_32BIG_C(
                        0x17f1dfe4U),
                };
                r_rsip_func101(Param_func322_func101_004);
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00211U);
                WR1_PROG(REG_1014H, 0x00000a90U);
                WR1_PROG(REG_1018H, 0x00000878U);
                r_rsip_func_sub005(0x00000878U, 0x42420009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub009(0x0000f322U);
                static const uint32_t Param_func322_func101_005[] =
                {
                    BSWAP_32BIG_C(0x600e5cf9U), BSWAP_32BIG_C(0xa890991eU), BSWAP_32BIG_C(0xb69ce047U), BSWAP_32BIG_C(
                        0x336790b2U),
                };
                r_rsip_func101(Param_func322_func101_005);
                r_rsip_func324();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub001(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_func_sub001(0x00c00009U);
                WR1_PROG(REG_1014H, 0x00000878U);
                r_rsip_func_sub005(0x00000a90U, 0x4141000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                r_rsip_func_sub001(0x00c00005U);
                r_rsip_func_sub001(0x00c90005U);
                static const uint32_t Param_func322_func101_006[] =
                {
                    BSWAP_32BIG_C(0x0e7039f5U), BSWAP_32BIG_C(0x30767f49U), BSWAP_32BIG_C(0x0ef2e8fbU), BSWAP_32BIG_C(
                        0x29d1f692U),
                };
                r_rsip_func101(Param_func322_func101_006);
            }
        }
        else
        {
            static const uint32_t Param_func322_func101_007[] =
            {
                BSWAP_32BIG_C(0x7e9a673eU), BSWAP_32BIG_C(0x90a84e5fU), BSWAP_32BIG_C(0xfdf8ac6dU), BSWAP_32BIG_C(
                    0xa0987c1fU),
            };
            r_rsip_func101(Param_func322_func101_007);
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
