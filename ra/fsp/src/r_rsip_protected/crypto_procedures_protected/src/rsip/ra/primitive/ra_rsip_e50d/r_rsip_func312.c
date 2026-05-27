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

void r_rsip_func312 (void)
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
    r_rsip_func_sub021(0x0000379dU, 0x00000842U, 0x0000b460U, 0x00000003U);
    WR1_PROG(REG_1404H, 0x18380000U);
    r_rsip_func_sub001(0x00c00661U);
    r_rsip_func_sub023(0x0000b480U, 0x00000080U, 0x80a00004U);
    r_rsip_func_sub001(0x03400081U);
    for (oLoop = 0; oLoop < 3; oLoop++)
    {
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_func_sub001(0x00c00091U);
        static const uint32_t Param_func312_func100_001[] =
        {
            BSWAP_32BIG_C(0x1a696e5fU), BSWAP_32BIG_C(0xc828001cU), BSWAP_32BIG_C(0xec6dd6caU), BSWAP_32BIG_C(
                0xe8f80945U),
        };
        r_rsip_func100(Param_func312_func100_001);
        r_rsip_func_sub014(0x00007c02U, 0x00600000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x000008c0U);
            r_rsip_func_sub005(0x00000e98U, 0x10100009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func312_func101_001[] =
            {
                BSWAP_32BIG_C(0x540e146cU), BSWAP_32BIG_C(0xfad7dd2dU), BSWAP_32BIG_C(0xa0cae7b4U), BSWAP_32BIG_C(
                    0x4898d8d3U),
            };
            r_rsip_func101(Param_func312_func101_001);
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1014H, 0x000001a0U);
            WR1_PROG(REG_1018H, 0x000008c0U);
            r_rsip_func_sub005(0x00000e98U, 0x10100009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func312_func101_002[] =
            {
                BSWAP_32BIG_C(0x078b9536U), BSWAP_32BIG_C(0xea684953U), BSWAP_32BIG_C(0x794ecce8U), BSWAP_32BIG_C(
                    0xa6855652U),
            };
            r_rsip_func101(Param_func312_func101_002);
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1014H, 0x00000120U);
            WR1_PROG(REG_1018H, 0x000008c0U);
            r_rsip_func_sub005(0x00000e98U, 0x10100009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func312_func101_003[] =
            {
                BSWAP_32BIG_C(0xbc588686U), BSWAP_32BIG_C(0xf6ac8a2aU), BSWAP_32BIG_C(0xc88d5d35U), BSWAP_32BIG_C(
                    0x56e4a25aU),
            };
            r_rsip_func101(Param_func312_func101_003);
        }

        WR1_PROG(REG_1014H, 0x00000838U);
        WR1_PROG(REG_1018H, 0x000008c0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e98U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000948U);
        r_rsip_func_sub005(0x00000948U, 0x1010000dU, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1d080000U);
        r_rsip_func_sub001(0x00c00081U);
        WR1_PROG(REG_1014H, 0x000008c8U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        r_rsip_func_sub005(0x00000ae8U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_func_sub001(0x00c00091U);
        r_rsip_func_sub030(0x1d080000U, 0x00000884U, 0x81a00004U);
        r_rsip_func_sub001(0x00c90081U);
        WR1_PROG(REG_1014H, 0x00000948U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        r_rsip_func_sub005(0x00000d88U, 0x10100007U, 0x00010001U);
        r_rsip_func_sub026(0x00000d88U, 0x000008c0U);
        r_rsip_func_sub005(0x00000e10U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000630U, 0x000008c0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e10U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000948U);
        r_rsip_func_sub005(0x00000948U, 0x1010000dU, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x000007b8U);
        WR1_PROG(REG_1018H, 0x000009d0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e98U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000a58U);
        r_rsip_func_sub005(0x00000a58U, 0x1010000dU, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_func_sub001(0x00c00111U);
        WR1_PROG(REG_1014H, 0x00000ae8U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000a58U, 0x00000d88U);
        r_rsip_func_sub005(0x00000a58U, 0x20200009U, 0x00010001U);
        r_rsip_func_sub026(0x000009d8U, 0x00000d00U);
        r_rsip_func_sub005(0x00000bf8U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x000005b0U);
        WR1_PROG(REG_1018H, 0x000009d0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e10U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000a58U);
        r_rsip_func_sub005(0x00000d88U, 0x1010000dU, 0x00010201U);
        r_rsip_func_sub026(0x000008c8U, 0x000009d0U);
        r_rsip_func_sub005(0x00000948U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x00000d88U);
        WR1_PROG(REG_1018H, 0x00000948U);
        r_rsip_func_sub005(0x00000948U, 0x20200009U, 0x00010001U);
        r_rsip_func_sub026(0x000008c8U, 0x000009d0U);
        r_rsip_func_sub005(0x000009d8U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1a580000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x00000738U);
        WR1_PROG(REG_1018H, 0x00000ae0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e98U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000b68U);
        r_rsip_func_sub005(0x00000b68U, 0x1010000dU, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_func_sub001(0x00c00111U);
        WR1_PROG(REG_1014H, 0x00000bf8U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000b68U, 0x00000d88U);
        r_rsip_func_sub005(0x00000b68U, 0x20200009U, 0x00010001U);
        r_rsip_func_sub026(0x00000ae8U, 0x00000d00U);
        r_rsip_func_sub005(0x000008c8U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1a580000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x00000530U);
        WR1_PROG(REG_1018H, 0x00000ae0U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000e10U, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000b68U);
        r_rsip_func_sub005(0x00000d88U, 0x1010000dU, 0x00010201U);
        r_rsip_func_sub026(0x000009d8U, 0x00000ae0U);
        r_rsip_func_sub005(0x00000a58U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x00000d88U);
        WR1_PROG(REG_1018H, 0x00000a58U);
        r_rsip_func_sub005(0x00000a58U, 0x20200009U, 0x00010001U);
        r_rsip_func_sub026(0x000009d8U, 0x00000ae0U);
        r_rsip_func_sub005(0x00000ae8U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_func_sub001(0x00c00111U);
        WR1_PROG(REG_1014H, 0x000008c8U);
        WR1_PROG(REG_1018H, 0x00000d00U);
        r_rsip_func_sub005(0x00000d88U, 0x10100009U, 0x00010001U);
        r_rsip_func_sub026(0x00000ae8U, 0x00000d00U);
        r_rsip_func_sub005(0x00000c78U, 0x10100009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1b680000U);
        r_rsip_func_sub001(0x00c00091U);
        WR1_PROG(REG_1014H, 0x00000d88U);
        WR1_PROG(REG_1018H, 0x00000c78U);
        r_rsip_func_sub005(0x00000e98U, 0x20200009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_func_sub012(0x1d080000U, 0x0000b480U, 0x00000080U);
        WR1_PROG(REG_1608H, 0x81a00004U);
        r_rsip_func_sub001(0x00c90081U);
        WR1_PROG(REG_1014H, 0x00000d88U);
        WR1_PROG(REG_1018H, 0x00000e98U);
        r_rsip_func_sub005(0x00000b68U, 0x20200009U, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_func_sub023(0x0000b480U, 0x00000080U, 0x80a00004U);
        WR1_PROG(REG_1404H, 0x1a680000U);
        r_rsip_func_sub001(0x03430081U);
        WR1_PROG(REG_1600H, 0x00002c40U);
        static const uint32_t Param_func312_func101_004[] =
        {
            BSWAP_32BIG_C(0xa3821c57U), BSWAP_32BIG_C(0x1f2d8810U), BSWAP_32BIG_C(0x2b32ccfbU), BSWAP_32BIG_C(
                0xe9c5b595U),
        };
        r_rsip_func101(Param_func312_func101_004);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000843U);
    WR1_PROG(REG_1014H, 0x00000a58U);
    WR1_PROG(REG_1018H, 0x00000d00U);
    r_rsip_func_sub005(0x000008c8U, 0x10100009U, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    r_rsip_func_sub009(0x0000f312U);
    static const uint32_t Param_func312_func101_005[] =
    {
        BSWAP_32BIG_C(0xa02039fdU), BSWAP_32BIG_C(0x7a3bd2e7U), BSWAP_32BIG_C(0xa4e1b28bU), BSWAP_32BIG_C(0x4cc8e0dbU),
    };
    r_rsip_func101(Param_func312_func101_005);
    r_rsip_func311();
    WR1_PROG(REG_1600H, 0x000037bcU);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
