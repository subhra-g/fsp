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

void r_rsip_func315 (void)
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
    WR1_PROG(REG_1600H, 0x0000373dU);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);
        static const uint32_t Param_func315_func100_001[] =
        {
            BSWAP_32BIG_C(0x4975fa91U), BSWAP_32BIG_C(0x1532f1f9U), BSWAP_32BIG_C(0xec5cacc2U), BSWAP_32BIG_C(
                0xfd81d448U),
        };
        r_rsip_func100(Param_func315_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x3030000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x3030000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            static const uint32_t Param_func315_func101_001[] =
            {
                BSWAP_32BIG_C(0xd97da2beU), BSWAP_32BIG_C(0xa977bedcU), BSWAP_32BIG_C(0x4ebc2ac9U), BSWAP_32BIG_C(
                    0xc9d90b10U),
            };
            r_rsip_func101(Param_func315_func101_001);
        }
        else
        {
            static const uint32_t Param_func315_func101_002[] =
            {
                BSWAP_32BIG_C(0x6206722fU), BSWAP_32BIG_C(0xf409b6c4U), BSWAP_32BIG_C(0x30ff1809U), BSWAP_32BIG_C(
                    0xe78d678bU),
            };
            r_rsip_func101(Param_func315_func101_002);
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_func_sub001(0x00c00191U);
    r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
    OFS_ADR = 104;
    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
    r_rsip_func_sub009(0x00003151U);
    static const uint32_t Param_func315_func101_003[] =
    {
        BSWAP_32BIG_C(0x93fec043U), BSWAP_32BIG_C(0x5adb0d4aU), BSWAP_32BIG_C(0xb4f6ae87U), BSWAP_32BIG_C(0x5ae18a3dU),
    };
    r_rsip_func101(Param_func315_func101_003);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
    OFS_ADR = 208;
    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
    r_rsip_func_sub009(0x00003152U);
    static const uint32_t Param_func315_func101_004[] =
    {
        BSWAP_32BIG_C(0x7226f94cU), BSWAP_32BIG_C(0x9b145f5cU), BSWAP_32BIG_C(0x10d888d4U), BSWAP_32BIG_C(0x52f0316bU),
    };
    r_rsip_func101(Param_func315_func101_004);
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub015(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
    OFS_ADR = 0;
    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
    r_rsip_func_sub009(0x00003153U);
    static const uint32_t Param_func315_func101_005[] =
    {
        BSWAP_32BIG_C(0x76f63cefU), BSWAP_32BIG_C(0x0855a73eU), BSWAP_32BIG_C(0xd1b447ddU), BSWAP_32BIG_C(0xa233885dU),
    };
    r_rsip_func101(Param_func315_func101_005);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
    OFS_ADR = 312;
    r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
    r_rsip_func_sub009(0x00003154U);
    static const uint32_t Param_func315_func101_006[] =
    {
        BSWAP_32BIG_C(0xb94af777U), BSWAP_32BIG_C(0x2504aebcU), BSWAP_32BIG_C(0x5ea20de5U), BSWAP_32BIG_C(0xc952f41dU),
    };
    r_rsip_func101(Param_func315_func101_006);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0xe4f152fdU);
    OFS_ADR = 416;
    r_rsip_func_sub012(0x10a00000U, 0x0000b400U, 0x00000060U);
    r_rsip_func_sub009(0x00003155U);
    static const uint32_t Param_func315_func101_007[] =
    {
        BSWAP_32BIG_C(0x39d49654U), BSWAP_32BIG_C(0xb6cc376fU), BSWAP_32BIG_C(0xf7494985U), BSWAP_32BIG_C(0xc4d5ed5dU),
    };
    r_rsip_func101(Param_func315_func101_007);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub030(0x14b00000U, 0x00000b7bU, 0x80e0001bU);
    r_rsip_func_sub001(0x03430181U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_func_sub015(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0017dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        r_rsip_func_sub005(0x00000838U, 0x3030000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func315_func100_002[] =
        {
            BSWAP_32BIG_C(0x4dd93322U), BSWAP_32BIG_C(0xe5482d5fU), BSWAP_32BIG_C(0xe2b64e20U), BSWAP_32BIG_C(
                0x0c82572dU),
        };
        r_rsip_func100(Param_func315_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            static const uint32_t Param_func315_func101_008[] =
            {
                BSWAP_32BIG_C(0x15594be0U), BSWAP_32BIG_C(0x7d6eb3ccU), BSWAP_32BIG_C(0x7e43c1d1U), BSWAP_32BIG_C(
                    0xdf472f20U),
            };
            r_rsip_func101(Param_func315_func101_008);
            break;
        }
        else
        {
            r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003151U);
            static const uint32_t Param_func315_func101_009[] =
            {
                BSWAP_32BIG_C(0x9fb9f627U), BSWAP_32BIG_C(0xcaa1618cU), BSWAP_32BIG_C(0x90ab3e22U), BSWAP_32BIG_C(
                    0x3c11754aU),
            };
            r_rsip_func101(Param_func315_func101_009);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
            OFS_ADR = 104;
            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003152U);
            static const uint32_t Param_func315_func101_010[] =
            {
                BSWAP_32BIG_C(0xb8f64342U), BSWAP_32BIG_C(0xb76f531fU), BSWAP_32BIG_C(0x43170ecbU), BSWAP_32BIG_C(
                    0xb50be53eU),
            };
            r_rsip_func101(Param_func315_func101_010);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub009(0x00003151U);
            static const uint32_t Param_func315_func101_011[] =
            {
                BSWAP_32BIG_C(0x8259f7eaU), BSWAP_32BIG_C(0x4ab12ff4U), BSWAP_32BIG_C(0xcc6ad8cdU), BSWAP_32BIG_C(
                    0x65133952U),
            };
            r_rsip_func101(Param_func315_func101_011);
            r_rsip_func316();
            r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003156U);
            static const uint32_t Param_func315_func101_012[] =
            {
                BSWAP_32BIG_C(0x66f2156cU), BSWAP_32BIG_C(0xd1dc279fU), BSWAP_32BIG_C(0xc0faa6b7U), BSWAP_32BIG_C(
                    0xedbbaec1U),
            };
            r_rsip_func101(Param_func315_func101_012);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
            OFS_ADR = 104;
            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003157U);
            static const uint32_t Param_func315_func101_013[] =
            {
                BSWAP_32BIG_C(0xc4626285U), BSWAP_32BIG_C(0x5b72c90bU), BSWAP_32BIG_C(0x3d917904U), BSWAP_32BIG_C(
                    0x5cabc377U),
            };
            r_rsip_func101(Param_func315_func101_013);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
            OFS_ADR = 208;
            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003153U);
            static const uint32_t Param_func315_func101_014[] =
            {
                BSWAP_32BIG_C(0x33383fa2U), BSWAP_32BIG_C(0x991d6706U), BSWAP_32BIG_C(0x27c05051U), BSWAP_32BIG_C(
                    0x28d2d4d4U),
            };
            r_rsip_func101(Param_func315_func101_014);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
            OFS_ADR = 312;
            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003154U);
            static const uint32_t Param_func315_func101_015[] =
            {
                BSWAP_32BIG_C(0x4bc0a8d6U), BSWAP_32BIG_C(0x435ddfdcU), BSWAP_32BIG_C(0x0b105d9aU), BSWAP_32BIG_C(
                    0x1ad9f12dU),
            };
            r_rsip_func101(Param_func315_func101_015);
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_func_sub001(0x00c00181U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x30300009U, 0x00010001U);
            r_rsip_func_sub026(0x00000630U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000220U, 0x30300009U, 0x00010001U);
            r_rsip_func_sub026(0x00000838U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000630U, 0x30300009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_func_sub009(0x00003152U);
            static const uint32_t Param_func315_func101_016[] =
            {
                BSWAP_32BIG_C(0x5c85df00U), BSWAP_32BIG_C(0x60dfd3d0U), BSWAP_32BIG_C(0x7fb65d8cU), BSWAP_32BIG_C(
                    0x390b3fc8U),
            };
            r_rsip_func101(Param_func315_func101_016);
            r_rsip_func316();
            r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
            OFS_ADR = 208;
            r_rsip_func_sub012(0x12980000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003158U);
            static const uint32_t Param_func315_func101_017[] =
            {
                BSWAP_32BIG_C(0x75f1c2baU), BSWAP_32BIG_C(0x985d1b64U), BSWAP_32BIG_C(0x0fee9c8bU), BSWAP_32BIG_C(
                    0xacb45ce0U),
            };
            r_rsip_func101(Param_func315_func101_017);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
            OFS_ADR = 312;
            r_rsip_func_sub012(0x18b00000U, 0x0000b400U, 0x00000064U);
            r_rsip_func_sub009(0x00003159U);
            static const uint32_t Param_func315_func101_018[] =
            {
                BSWAP_32BIG_C(0x39e85691U), BSWAP_32BIG_C(0xc6fbfb49U), BSWAP_32BIG_C(0x31ddf6efU), BSWAP_32BIG_C(
                    0xe09b5090U),
            };
            r_rsip_func101(Param_func315_func101_018);
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_func_sub001(0x00c00181U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x30300009U, 0x00010001U);
            r_rsip_func_sub026(0x00000630U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000220U, 0x30300009U, 0x00010001U);
            r_rsip_func_sub026(0x00000838U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000630U, 0x30300009U, 0x00010001U);
            r_rsip_func_sub026(0x00000220U, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x3030000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00a10000U);
            static const uint32_t Param_func315_func100_003[] =
            {
                BSWAP_32BIG_C(0xa41658b7U), BSWAP_32BIG_C(0xafd3eb25U), BSWAP_32BIG_C(0x62211efaU), BSWAP_32BIG_C(
                    0x87ffc091U),
            };
            r_rsip_func100(Param_func315_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                r_rsip_func_sub005(0x00000220U, 0x30300009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x00003155U);
                static const uint32_t Param_func315_func101_019[] =
                {
                    BSWAP_32BIG_C(0x09c1bfd2U), BSWAP_32BIG_C(0x6ade80c9U), BSWAP_32BIG_C(0x01779f89U), BSWAP_32BIG_C(
                        0x290dd163U),
                };
                r_rsip_func101(Param_func315_func101_019);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
                OFS_ADR = 208;
                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x00003156U);
                static const uint32_t Param_func315_func101_020[] =
                {
                    BSWAP_32BIG_C(0xe0f52561U), BSWAP_32BIG_C(0x579cf0b3U), BSWAP_32BIG_C(0xf1a29ad4U), BSWAP_32BIG_C(
                        0x82616033U),
                };
                r_rsip_func101(Param_func315_func101_020);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003151U);
                static const uint32_t Param_func315_func101_021[] =
                {
                    BSWAP_32BIG_C(0x675f4223U), BSWAP_32BIG_C(0x90c24f48U), BSWAP_32BIG_C(0xa74d8581U), BSWAP_32BIG_C(
                        0x0599ecd5U),
                };
                r_rsip_func101(Param_func315_func101_021);
                r_rsip_func320();
                r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315aU);
                static const uint32_t Param_func315_func101_022[] =
                {
                    BSWAP_32BIG_C(0xbe0a9565U), BSWAP_32BIG_C(0x673a64b5U), BSWAP_32BIG_C(0x289ee459U), BSWAP_32BIG_C(
                        0x648c3a3dU),
                };
                r_rsip_func101(Param_func315_func101_022);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
                OFS_ADR = 104;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x00003157U);
                static const uint32_t Param_func315_func101_023[] =
                {
                    BSWAP_32BIG_C(0x960ea839U), BSWAP_32BIG_C(0x5988481dU), BSWAP_32BIG_C(0x1e8730d5U), BSWAP_32BIG_C(
                        0xaa684d13U),
                };
                r_rsip_func101(Param_func315_func101_023);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
                OFS_ADR = 312;
                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x00003158U);
                static const uint32_t Param_func315_func101_024[] =
                {
                    BSWAP_32BIG_C(0x5f59d61eU), BSWAP_32BIG_C(0xaa12525cU), BSWAP_32BIG_C(0xcddb3b02U), BSWAP_32BIG_C(
                        0xb41d0da0U),
                };
                r_rsip_func101(Param_func315_func101_024);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003152U);
                static const uint32_t Param_func315_func101_025[] =
                {
                    BSWAP_32BIG_C(0x9f74a68cU), BSWAP_32BIG_C(0x45d0a134U), BSWAP_32BIG_C(0xc4fd10feU), BSWAP_32BIG_C(
                        0x8b1faa17U),
                };
                r_rsip_func101(Param_func315_func101_025);
                r_rsip_func320();
                r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
                OFS_ADR = 104;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315bU);
                static const uint32_t Param_func315_func101_026[] =
                {
                    BSWAP_32BIG_C(0xebe34980U), BSWAP_32BIG_C(0xbdb23805U), BSWAP_32BIG_C(0xd9ce5f71U), BSWAP_32BIG_C(
                        0xb7fe7da3U),
                };
                r_rsip_func101(Param_func315_func101_026);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func315_func101_027[] =
                {
                    BSWAP_32BIG_C(0xec5b3909U), BSWAP_32BIG_C(0xdba91c42U), BSWAP_32BIG_C(0x89fd4a71U), BSWAP_32BIG_C(
                        0x7f13ba31U),
                };
                r_rsip_func101(Param_func315_func101_027);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                r_rsip_func_sub005(0x00000630U, 0x3030000aU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
                OFS_ADR = 208;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315aU);
                static const uint32_t Param_func315_func101_028[] =
                {
                    BSWAP_32BIG_C(0x326a6804U), BSWAP_32BIG_C(0x38aa7513U), BSWAP_32BIG_C(0xf967864fU), BSWAP_32BIG_C(
                        0x5d22c1a3U),
                };
                r_rsip_func101(Param_func315_func101_028);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xabf7a97eU);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315bU);
                static const uint32_t Param_func315_func101_029[] =
                {
                    BSWAP_32BIG_C(0x31fae08dU), BSWAP_32BIG_C(0x5136bb91U), BSWAP_32BIG_C(0x5018b59bU), BSWAP_32BIG_C(
                        0xd650926bU),
                };
                r_rsip_func101(Param_func315_func101_029);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003153U);
                static const uint32_t Param_func315_func101_030[] =
                {
                    BSWAP_32BIG_C(0x192f36d5U), BSWAP_32BIG_C(0x8690953eU), BSWAP_32BIG_C(0x247a9bb1U), BSWAP_32BIG_C(
                        0x4a95df0dU),
                };
                r_rsip_func101(Param_func315_func101_030);
                r_rsip_func320();
                r_rsip_func_sub015(0x0b040184U, 0x3cc10901U);
                OFS_ADR = 208;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315cU);
                static const uint32_t Param_func315_func101_031[] =
                {
                    BSWAP_32BIG_C(0x700b56aeU), BSWAP_32BIG_C(0xe3fdf1beU), BSWAP_32BIG_C(0xc3968460U), BSWAP_32BIG_C(
                        0xa74b7513U),
                };
                r_rsip_func101(Param_func315_func101_031);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
                OFS_ADR = 312;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315cU);
                static const uint32_t Param_func315_func101_032[] =
                {
                    BSWAP_32BIG_C(0xc37fcc6aU), BSWAP_32BIG_C(0xcc8514b8U), BSWAP_32BIG_C(0x648cbc46U), BSWAP_32BIG_C(
                        0xec3a3488U),
                };
                r_rsip_func101(Param_func315_func101_032);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x2517e7b7U);
                OFS_ADR = 104;
                r_rsip_func_sub012(0x1e480000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315dU);
                static const uint32_t Param_func315_func101_033[] =
                {
                    BSWAP_32BIG_C(0x26a16ea6U), BSWAP_32BIG_C(0x43f32d5bU), BSWAP_32BIG_C(0xacfcde43U), BSWAP_32BIG_C(
                        0xc234ce39U),
                };
                r_rsip_func101(Param_func315_func101_033);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003154U);
                static const uint32_t Param_func315_func101_034[] =
                {
                    BSWAP_32BIG_C(0x224d18daU), BSWAP_32BIG_C(0xf22ba6a6U), BSWAP_32BIG_C(0x117f799cU), BSWAP_32BIG_C(
                        0x54cd0da0U),
                };
                r_rsip_func101(Param_func315_func101_034);
                r_rsip_func320();
                r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
                OFS_ADR = 312;
                r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
                r_rsip_func_sub009(0x0000315dU);
                static const uint32_t Param_func315_func101_035[] =
                {
                    BSWAP_32BIG_C(0xa5b026bfU), BSWAP_32BIG_C(0x14eb53b0U), BSWAP_32BIG_C(0xc62c7015U), BSWAP_32BIG_C(
                        0xf9e4c051U),
                };
                r_rsip_func101(Param_func315_func101_035);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func315_func101_036[] =
                {
                    BSWAP_32BIG_C(0xcb6e050cU), BSWAP_32BIG_C(0x07651356U), BSWAP_32BIG_C(0xeb1cf7d4U), BSWAP_32BIG_C(
                        0xc17a4b41U),
                };
                r_rsip_func101(Param_func315_func101_036);
            }
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0xe4f152fdU);
    OFS_ADR = 416;
    r_rsip_func_sub012(0x10a00000U, 0x0000b400U, 0x00000060U);
    r_rsip_func_sub009(0x0000315eU);
    static const uint32_t Param_func315_func101_037[] =
    {
        BSWAP_32BIG_C(0x2c98b618U), BSWAP_32BIG_C(0xe752d6abU), BSWAP_32BIG_C(0xa64e6560U), BSWAP_32BIG_C(0xb763b5caU),
    };
    r_rsip_func101(Param_func315_func101_037);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub015(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);
        static const uint32_t Param_func315_func100_004[] =
        {
            BSWAP_32BIG_C(0xf8e45450U), BSWAP_32BIG_C(0xa979e463U), BSWAP_32BIG_C(0xd2e64d4bU), BSWAP_32BIG_C(
                0xc4c3be64U),
        };
        r_rsip_func100(Param_func315_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x30300008U, 0x00010001U);
            r_rsip_func_sub026(0x00000a40U, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x30300008U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            static const uint32_t Param_func315_func101_038[] =
            {
                BSWAP_32BIG_C(0x76f2d52fU), BSWAP_32BIG_C(0x790f8ec8U), BSWAP_32BIG_C(0x6b38ba89U), BSWAP_32BIG_C(
                    0x1929685bU),
            };
            r_rsip_func101(Param_func315_func101_038);
        }
        else
        {
            static const uint32_t Param_func315_func101_039[] =
            {
                BSWAP_32BIG_C(0xd21a70c8U), BSWAP_32BIG_C(0xd7e466e1U), BSWAP_32BIG_C(0x850cd447U), BSWAP_32BIG_C(
                    0xa3913442U),
            };
            r_rsip_func101(Param_func315_func101_039);
            break;
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0x0b097e1fU);
    OFS_ADR = 312;
    r_rsip_func_sub012(0x16a80000U, 0x0000b400U, 0x00000064U);
    r_rsip_func_sub009(0x0000315fU);
    static const uint32_t Param_func315_func101_040[] =
    {
        BSWAP_32BIG_C(0x94ddae8cU), BSWAP_32BIG_C(0x15253fc2U), BSWAP_32BIG_C(0xdfe1bcc6U), BSWAP_32BIG_C(0xa1c3de06U),
    };
    r_rsip_func101(Param_func315_func101_040);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    while (1)
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        r_rsip_func_sub005(0x00000a40U, 0x3131000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func315_func100_005[] =
        {
            BSWAP_32BIG_C(0x517e289dU), BSWAP_32BIG_C(0x0e29cb98U), BSWAP_32BIG_C(0x45c614ddU), BSWAP_32BIG_C(
                0x6af9f19aU),
        };
        r_rsip_func100(Param_func315_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            r_rsip_func_sub005(0x00000838U, 0x3131000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func315_func101_041[] =
            {
                BSWAP_32BIG_C(0x3791207eU), BSWAP_32BIG_C(0xcacea114U), BSWAP_32BIG_C(0xb686dbc6U), BSWAP_32BIG_C(
                    0xdb2c506aU),
            };
            r_rsip_func101(Param_func315_func101_041);
        }
        else
        {
            static const uint32_t Param_func315_func101_042[] =
            {
                BSWAP_32BIG_C(0x6d8e3bd2U), BSWAP_32BIG_C(0xb95d84e3U), BSWAP_32BIG_C(0x8e7bd357U), BSWAP_32BIG_C(
                    0x4d8511feU),
            };
            r_rsip_func101(Param_func315_func101_042);
            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);
    static const uint32_t Param_func315_func100_006[] =
    {
        BSWAP_32BIG_C(0xc6360c41U), BSWAP_32BIG_C(0x003108c9U), BSWAP_32BIG_C(0xea2d9fc8U), BSWAP_32BIG_C(0x99dde586U),
    };
    r_rsip_func100(Param_func315_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        r_rsip_func_sub005(0x00000838U, 0x3131000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        static const uint32_t Param_func315_func101_043[] =
        {
            BSWAP_32BIG_C(0xd18f913cU), BSWAP_32BIG_C(0x94e33e81U), BSWAP_32BIG_C(0xe2efb21fU), BSWAP_32BIG_C(
                0x9d415515U),
        };
        r_rsip_func101(Param_func315_func101_043);
    }
    else
    {
        static const uint32_t Param_func315_func101_044[] =
        {
            BSWAP_32BIG_C(0x6c4f55f2U), BSWAP_32BIG_C(0x2e9cceb3U), BSWAP_32BIG_C(0x052b4f15U), BSWAP_32BIG_C(
                0x364ab236U),
        };
        r_rsip_func101(Param_func315_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
