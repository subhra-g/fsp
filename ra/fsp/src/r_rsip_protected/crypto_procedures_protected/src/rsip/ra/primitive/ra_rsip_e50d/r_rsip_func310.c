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

void r_rsip_func310 (void)
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
    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub001(0x00c00089U);
    WR1_PROG(REG_1404H, 0x19d00000U);
    r_rsip_func_sub015(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00085U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    WR1_PROG(REG_1014H, 0x00000630U);
    WR1_PROG(REG_1018H, 0x00000948U);
    r_rsip_func_sub005(0x00000b68U, 0x10100009U, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x1bf00000U);
    r_rsip_func_sub001(0x00c00089U);
    r_rsip_func_sub021(0x00000800U, 0x0000b420U, 0x00000400U, 0x00000bffU);
    for (oLoop = 0; oLoop < 1024; oLoop++)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);
        static const uint32_t Param_func310_func100_001[] =
        {
            BSWAP_32BIG_C(0x2eece453U), BSWAP_32BIG_C(0x6125f4d8U), BSWAP_32BIG_C(0xb74b814cU), BSWAP_32BIG_C(
                0xa399c4f3U),
        };
        r_rsip_func100(Param_func310_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000948U);
            WR1_PROG(REG_1018H, 0x00000b68U);
            r_rsip_func_sub005(0x00000948U, 0x11110009U, 0x00010001U);
            r_rsip_func_sub026(0x00000c78U, 0x00000a58U);
            r_rsip_func_sub005(0x00000c78U, 0x11110009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func310_func101_001[] =
            {
                BSWAP_32BIG_C(0x688c7b7aU), BSWAP_32BIG_C(0xf70cba72U), BSWAP_32BIG_C(0x6a0fc07bU), BSWAP_32BIG_C(
                    0x23469096U),
            };
            r_rsip_func101(Param_func310_func101_001);
        }
        else
        {
            static const uint32_t Param_func310_func101_002[] =
            {
                BSWAP_32BIG_C(0x8655e943U), BSWAP_32BIG_C(0x2c1ad69bU), BSWAP_32BIG_C(0x272a1d76U), BSWAP_32BIG_C(
                    0xabb40233U),
            };
            r_rsip_func101(Param_func310_func101_002);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1014H, 0x00000948U);
        r_rsip_func_sub005(0x00000948U, 0x1111000cU, 0x00010001U);
        r_rsip_func_sub026(0x00000a58U, 0x00000a58U);
        r_rsip_func_sub005(0x00000a58U, 0x11110009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1600H, 0x00002c00U);
        static const uint32_t Param_func310_func101_003[] =
        {
            BSWAP_32BIG_C(0x5c64a44bU), BSWAP_32BIG_C(0xa3ec9fb2U), BSWAP_32BIG_C(0x6ced5b8dU), BSWAP_32BIG_C(
                0xf6e113e5U),
        };
        r_rsip_func101(Param_func310_func101_003);
    }

    r_rsip_func_sub011(0x38000801U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1608H, 0x80a00000U);
    WR1_PROG(REG_1404H, 0x1bf80000U);
    r_rsip_func_sub001(0x03430081U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
