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

void r_rsip_func311 (void)
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
    WR1_PROG(REG_1404H, 0x1b680000U);
    r_rsip_func_sub001(0x00c00331U);
    WR1_PROG(REG_1014H, 0x00000530U);
    WR1_PROG(REG_1018H, 0x00000c78U);
    r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
    r_rsip_func_sub026(0x00000630U, 0x00000c78U);
    r_rsip_func_sub005(0x00000e98U, 0x20200009U, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x1ae00000U);
        WR1_PROG(REG_1608H, 0x80010080U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub017(0x38000c84U, 0x00A60000U);
        static const uint32_t Param_func311_func100_001[] =
        {
            BSWAP_32BIG_C(0x6c3f5059U), BSWAP_32BIG_C(0xc0742058U), BSWAP_32BIG_C(0x72caad39U), BSWAP_32BIG_C(
                0xcf4dc557U),
        };
        r_rsip_func100(Param_func311_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000b68U);
            WR1_PROG(REG_1018H, 0x00000d88U);
            r_rsip_func_sub005(0x00000b68U, 0x11110009U, 0x00010001U);
            r_rsip_func_sub026(0x00000948U, 0x00000e98U);
            r_rsip_func_sub005(0x00000948U, 0x21210009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func311_func101_001[] =
            {
                BSWAP_32BIG_C(0xf065cebbU), BSWAP_32BIG_C(0xb4a2e3ceU), BSWAP_32BIG_C(0x22713327U), BSWAP_32BIG_C(
                    0x0a5a29a7U),
            };
            r_rsip_func101(Param_func311_func101_001);
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b68U);
            WR1_PROG(REG_1018H, 0x00000d88U);
            r_rsip_func_sub005(0x00000a58U, 0x1111000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x19d00000U);
            WR1_PROG(REG_1608H, 0x800100a0U);
            r_rsip_func_sub001(0x03430005U);
            r_rsip_func_sub001(0x00030005U);
            WR1_PROG(REG_1014H, 0x00000d88U);
            WR1_PROG(REG_1018H, 0x00000b68U);
            r_rsip_func_sub005(0x00000a58U, 0x1111000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x19d00000U);
            WR1_PROG(REG_1608H, 0x800100c0U);
            r_rsip_func_sub001(0x03430005U);
            r_rsip_func_sub001(0x00030005U);
            r_rsip_func_sub017(0x38000cc6U, 0x00260000U);
            static const uint32_t Param_func311_func100_002[] =
            {
                BSWAP_32BIG_C(0x9233eb27U), BSWAP_32BIG_C(0xb080aa8aU), BSWAP_32BIG_C(0x4f2e9fbeU), BSWAP_32BIG_C(
                    0x62b0be4fU),
            };
            r_rsip_func100(Param_func311_func100_002);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                WR1_PROG(REG_1608H, 0x800100e0U);
                r_rsip_func_sub001(0x03430005U);
                r_rsip_func_sub001(0x00030005U);
                r_rsip_func_sub017(0x38000ce7U, 0x00A60000U);
                static const uint32_t Param_func311_func100_003[] =
                {
                    BSWAP_32BIG_C(0x41cb113bU), BSWAP_32BIG_C(0xc311954fU), BSWAP_32BIG_C(0x2411cb1aU), BSWAP_32BIG_C(
                        0xcce1c8a9U),
                };
                r_rsip_func100(Param_func311_func100_003);
                WR1_PROG(REG_143CH, 0x00400000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x00000c78U);
                    WR1_PROG(REG_1018H, 0x00000948U);
                    r_rsip_func_sub005(0x00000a58U, 0x2121000aU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x80010100U);
                    r_rsip_func_sub001(0x00030005U);
                    r_rsip_func_sub001(0x03430005U);
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1404H, 0x19d00000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    r_rsip_func_sub001(0x00c00085U);
                    r_rsip_func_sub001(0x00c90005U);
                    WR1_PROG(REG_1014H, 0x00000b68U);
                    WR1_PROG(REG_1018H, 0x00000a58U);
                    r_rsip_func_sub005(0x00000b68U, 0x1111000aU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    r_rsip_func_sub001(0x00c00005U);
                    r_rsip_func_sub001(0x00c90005U);
                    r_rsip_func_sub001(0x00c00101U);
                    WR1_PROG(REG_1014H, 0x00000948U);
                    WR1_PROG(REG_1018H, 0x00000a58U);
                    r_rsip_func_sub005(0x00000948U, 0x21210009U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    static const uint32_t Param_func311_func101_002[] =
                    {
                        BSWAP_32BIG_C(0xd97d7079U), BSWAP_32BIG_C(0xece70de5U), BSWAP_32BIG_C(0x88c3762eU),
                        BSWAP_32BIG_C(0xe1ed94fdU),
                    };
                    r_rsip_func101(Param_func311_func101_002);
                }
                else
                {
                    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);
                    static const uint32_t Param_func311_func100_004[] =
                    {
                        BSWAP_32BIG_C(0x28f035e2U), BSWAP_32BIG_C(0x2acfbfc5U), BSWAP_32BIG_C(0x82581072U),
                        BSWAP_32BIG_C(0xc4691dd6U),
                    };
                    r_rsip_func100(Param_func311_func100_004);
                    WR1_PROG(REG_143CH, 0x00400000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000948U);
                        WR1_PROG(REG_1018H, 0x00000e98U);
                        r_rsip_func_sub005(0x00000a58U, 0x2121000aU, 0x00010001U);
                        WAIT_STS(REG_1000H, 0U, 0U);
                        WR1_PROG(REG_1404H, 0x19500000U);
                        WR1_PROG(REG_1608H, 0x80010100U);
                        r_rsip_func_sub001(0x03430005U);
                        r_rsip_func_sub001(0x00030005U);
                        r_rsip_func_sub017(0x38000d08U, 0x00A60000U);
                        static const uint32_t Param_func311_func100_005[] =
                        {
                            BSWAP_32BIG_C(0x61607ae2U), BSWAP_32BIG_C(0xcac66caeU), BSWAP_32BIG_C(0x15336fe6U),
                            BSWAP_32BIG_C(0x125a931bU),
                        };
                        r_rsip_func100(Param_func311_func100_005);
                        WR1_PROG(REG_143CH, 0x00400000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            static const uint32_t Param_func311_func101_003[] =
                            {
                                BSWAP_32BIG_C(0x612561b1U), BSWAP_32BIG_C(0x69a6b19aU), BSWAP_32BIG_C(0xb89806e3U),
                                BSWAP_32BIG_C(0xecaba86aU),
                            };
                            r_rsip_func101(Param_func311_func101_003);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_func_sub001(0x00c00109U);
                            WR1_PROG(REG_1014H, 0x00000b68U);
                            WR1_PROG(REG_1018H, 0x00000d88U);
                            r_rsip_func_sub005(0x00000b68U, 0x1111000aU, 0x00010001U);
                            r_rsip_func_sub026(0x00000a58U, 0x00000948U);
                            r_rsip_func_sub005(0x00000948U, 0x21210009U, 0x00010001U);
                            WAIT_STS(REG_1000H, 0U, 0U);
                            static const uint32_t Param_func311_func101_004[] =
                            {
                                BSWAP_32BIG_C(0xcdeaef1eU), BSWAP_32BIG_C(0xc960fb74U), BSWAP_32BIG_C(0x69ae4e67U),
                                BSWAP_32BIG_C(0xfd8d1626U),
                            };
                            r_rsip_func101(Param_func311_func101_004);
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x18400000U);
                        WR1_PROG(REG_1608H, 0x80010120U);
                        r_rsip_func_sub001(0x00030005U);
                        r_rsip_func_sub001(0x03430005U);
                        r_rsip_func_sub017(0x38000d29U, 0x00260000U);
                        static const uint32_t Param_func311_func100_006[] =
                        {
                            BSWAP_32BIG_C(0x2b1a9745U), BSWAP_32BIG_C(0xd5150c15U), BSWAP_32BIG_C(0xcd8ab433U),
                            BSWAP_32BIG_C(0x432e8cd7U),
                        };
                        r_rsip_func100(Param_func311_func100_006);
                        WR1_PROG(REG_143CH, 0x00400000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            static const uint32_t Param_func311_func101_005[] =
                            {
                                BSWAP_32BIG_C(0x0684953fU), BSWAP_32BIG_C(0x4ff4772aU), BSWAP_32BIG_C(0xdb4046e8U),
                                BSWAP_32BIG_C(0xeed45ea7U),
                            };
                            r_rsip_func101(Param_func311_func101_005);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_func_sub001(0x00c00009U);
                            WR1_PROG(REG_1404H, 0x19d00000U);
                            WR1_PROG(REG_1608H, 0x81010120U);
                            r_rsip_func_sub001(0x00c00085U);
                            r_rsip_func_sub001(0x00c90005U);
                            WR1_PROG(REG_1014H, 0x00000b68U);
                            WR1_PROG(REG_1018H, 0x00000a58U);
                            r_rsip_func_sub005(0x00000b68U, 0x21210009U, 0x00010001U);
                            WAIT_STS(REG_1000H, 0U, 0U);
                            static const uint32_t Param_func311_func101_006[] =
                            {
                                BSWAP_32BIG_C(0xd03bebfaU), BSWAP_32BIG_C(0x248a6525U), BSWAP_32BIG_C(0x5de0f709U),
                                BSWAP_32BIG_C(0x6183dfe7U),
                            };
                            r_rsip_func101(Param_func311_func101_006);
                        }
                    }
                }
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b68U);
                WR1_PROG(REG_1018H, 0x00000d88U);
                r_rsip_func_sub005(0x00000b68U, 0x1111000aU, 0x00010001U);
                r_rsip_func_sub026(0x00000948U, 0x00000e98U);
                r_rsip_func_sub005(0x00000948U, 0x2121000aU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                static const uint32_t Param_func311_func101_007[] =
                {
                    BSWAP_32BIG_C(0x2d4d6fecU), BSWAP_32BIG_C(0x5332f872U), BSWAP_32BIG_C(0xeb3db6dcU), BSWAP_32BIG_C(
                        0x2099468eU),
                };
                r_rsip_func101(Param_func311_func101_007);
            }
        }
    }

    WR1_PROG(REG_1014H, 0x00000948U);
    WR1_PROG(REG_1018H, 0x00000c78U);
    r_rsip_func_sub005(0x00000838U, 0x20200009U, 0x00010001U);
    r_rsip_func_sub026(0x00000b68U, 0x00000c78U);
    r_rsip_func_sub005(0x00000738U, 0x10100009U, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
