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

void r_rsip_func321 (void)
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
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        WR1_PROG(REG_1404H, 0x16580000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);
        r_rsip_func_sub006(0x0000135bU, 0x3800db40U, 0x00260000U);
        static const uint32_t Param_func321_func100_001[] =
        {
            BSWAP_32BIG_C(0x9fbf56b4U), BSWAP_32BIG_C(0x8223cb62U), BSWAP_32BIG_C(0x962e59e4U), BSWAP_32BIG_C(
                0xfb25eb44U),
        };
        r_rsip_func100(Param_func321_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000230U);
            r_rsip_func_sub005(0x00000230U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000660U);
            r_rsip_func_sub005(0x00000660U, 0x4040000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            static const uint32_t Param_func321_func101_001[] =
            {
                BSWAP_32BIG_C(0x44f55146U), BSWAP_32BIG_C(0x39157059U), BSWAP_32BIG_C(0x47eedb79U), BSWAP_32BIG_C(
                    0x9717cabdU),
            };
            r_rsip_func101(Param_func321_func101_001);
        }
        else
        {
            static const uint32_t Param_func321_func101_002[] =
            {
                BSWAP_32BIG_C(0xac380e98U), BSWAP_32BIG_C(0xcc7999acU), BSWAP_32BIG_C(0xac1ad7a5U), BSWAP_32BIG_C(
                    0x1afbca7aU),
            };
            r_rsip_func101(Param_func321_func101_002);
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_func_sub001(0x00c00211U);
    r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
    OFS_ADR = 136;
    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
    r_rsip_func_sub009(0x00003211U);
    static const uint32_t Param_func321_func101_003[] =
    {
        BSWAP_32BIG_C(0x7b3532fcU), BSWAP_32BIG_C(0xeb1bf883U), BSWAP_32BIG_C(0x00fed6bcU), BSWAP_32BIG_C(0x26e8635fU),
    };
    r_rsip_func101(Param_func321_func101_003);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
    OFS_ADR = 272;
    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
    r_rsip_func_sub009(0x00003212U);
    static const uint32_t Param_func321_func101_004[] =
    {
        BSWAP_32BIG_C(0xcf2862b1U), BSWAP_32BIG_C(0x50f66644U), BSWAP_32BIG_C(0xdd1e69e6U), BSWAP_32BIG_C(0x3bd0702eU),
    };
    r_rsip_func101(Param_func321_func101_004);
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub015(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
    OFS_ADR = 0;
    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
    r_rsip_func_sub009(0x00003213U);
    static const uint32_t Param_func321_func101_005[] =
    {
        BSWAP_32BIG_C(0x6d1e6169U), BSWAP_32BIG_C(0x2d1ef853U), BSWAP_32BIG_C(0x2db10e1dU), BSWAP_32BIG_C(0xb6a93b58U),
    };
    r_rsip_func101(Param_func321_func101_005);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
    OFS_ADR = 408;
    r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
    r_rsip_func_sub009(0x00003214U);
    static const uint32_t Param_func321_func101_006[] =
    {
        BSWAP_32BIG_C(0x8080e075U), BSWAP_32BIG_C(0x0c4533caU), BSWAP_32BIG_C(0xebc35eddU), BSWAP_32BIG_C(0xf08cf298U),
    };
    r_rsip_func101(Param_func321_func101_006);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x7edfb1abU);
    OFS_ADR = 544;
    r_rsip_func_sub012(0x10300000U, 0x0000b400U, 0x00000080U);
    r_rsip_func_sub009(0x00003215U);
    static const uint32_t Param_func321_func101_007[] =
    {
        BSWAP_32BIG_C(0x53d2dd71U), BSWAP_32BIG_C(0x3d8ee4fbU), BSWAP_32BIG_C(0x79175aa7U), BSWAP_32BIG_C(0xd2b4ab6dU),
    };
    r_rsip_func101(Param_func321_func101_007);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x8162b38bU);
    OFS_ADR = 676;
    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);
    r_rsip_func_sub009(0x00003216U);
    static const uint32_t Param_func321_func101_008[] =
    {
        BSWAP_32BIG_C(0x9568d133U), BSWAP_32BIG_C(0x58f5dcefU), BSWAP_32BIG_C(0x236add2fU), BSWAP_32BIG_C(0xf5ef8219U),
    };
    r_rsip_func101(Param_func321_func101_008);
    r_rsip_func016(OFS_ADR);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x18900000U);
        r_rsip_func_sub015(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);
        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000a90U);
        r_rsip_func_sub005(0x00000878U, 0x4040000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func321_func100_002[] =
        {
            BSWAP_32BIG_C(0x1d8ba92cU), BSWAP_32BIG_C(0x17411a79U), BSWAP_32BIG_C(0x47417322U), BSWAP_32BIG_C(
                0x9e584798U),
        };
        r_rsip_func100(Param_func321_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            static const uint32_t Param_func321_func101_009[] =
            {
                BSWAP_32BIG_C(0x89796701U), BSWAP_32BIG_C(0x8341c97cU), BSWAP_32BIG_C(0xa6b336d9U), BSWAP_32BIG_C(
                    0x6c55c63bU),
            };
            r_rsip_func101(Param_func321_func101_009);
            break;
        }
        else
        {
            r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003211U);
            static const uint32_t Param_func321_func101_010[] =
            {
                BSWAP_32BIG_C(0x1dd9dd9cU), BSWAP_32BIG_C(0x9de4554bU), BSWAP_32BIG_C(0x77f1fb6dU), BSWAP_32BIG_C(
                    0xabe6bbfdU),
            };
            r_rsip_func101(Param_func321_func101_010);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
            OFS_ADR = 136;
            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003212U);
            static const uint32_t Param_func321_func101_011[] =
            {
                BSWAP_32BIG_C(0x3d46da21U), BSWAP_32BIG_C(0xff05b75aU), BSWAP_32BIG_C(0x4d87c0dbU), BSWAP_32BIG_C(
                    0x03fcd064U),
            };
            r_rsip_func101(Param_func321_func101_011);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub009(0x00003211U);
            static const uint32_t Param_func321_func101_012[] =
            {
                BSWAP_32BIG_C(0x6acb1c01U), BSWAP_32BIG_C(0xa1c06746U), BSWAP_32BIG_C(0x7ac8e8abU), BSWAP_32BIG_C(
                    0xd1b9c376U),
            };
            r_rsip_func101(Param_func321_func101_012);
            r_rsip_func322();
            r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003217U);
            static const uint32_t Param_func321_func101_013[] =
            {
                BSWAP_32BIG_C(0xb4e80901U), BSWAP_32BIG_C(0xfc24583eU), BSWAP_32BIG_C(0x49b69976U), BSWAP_32BIG_C(
                    0x46b50d3aU),
            };
            r_rsip_func101(Param_func321_func101_013);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
            OFS_ADR = 136;
            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003218U);
            static const uint32_t Param_func321_func101_014[] =
            {
                BSWAP_32BIG_C(0xa1bd20ffU), BSWAP_32BIG_C(0x92bf4ff4U), BSWAP_32BIG_C(0x8e6a924cU), BSWAP_32BIG_C(
                    0x0dc79eb9U),
            };
            r_rsip_func101(Param_func321_func101_014);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
            OFS_ADR = 272;
            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003213U);
            static const uint32_t Param_func321_func101_015[] =
            {
                BSWAP_32BIG_C(0x3632c743U), BSWAP_32BIG_C(0x65913f6eU), BSWAP_32BIG_C(0xf2168e91U), BSWAP_32BIG_C(
                    0x9ea6d521U),
            };
            r_rsip_func101(Param_func321_func101_015);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
            OFS_ADR = 408;
            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003214U);
            static const uint32_t Param_func321_func101_016[] =
            {
                BSWAP_32BIG_C(0x63d18077U), BSWAP_32BIG_C(0x4b97bc8aU), BSWAP_32BIG_C(0x5deb77e4U), BSWAP_32BIG_C(
                    0xe02632e3U),
            };
            r_rsip_func101(Param_func321_func101_016);
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_func_sub001(0x00c00201U);
            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x40400009U, 0x00010001U);
            r_rsip_func_sub026(0x00000660U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000230U, 0x40400009U, 0x00010001U);
            r_rsip_func_sub026(0x00000878U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000660U, 0x40400009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_func_sub009(0x00003212U);
            static const uint32_t Param_func321_func101_017[] =
            {
                BSWAP_32BIG_C(0xa156624aU), BSWAP_32BIG_C(0x2c2cba01U), BSWAP_32BIG_C(0x93144528U), BSWAP_32BIG_C(
                    0xab329f07U),
            };
            r_rsip_func101(Param_func321_func101_017);
            r_rsip_func322();
            r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
            OFS_ADR = 272;
            r_rsip_func_sub012(0x12380000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x00003219U);
            static const uint32_t Param_func321_func101_018[] =
            {
                BSWAP_32BIG_C(0x5f356242U), BSWAP_32BIG_C(0x72a86cefU), BSWAP_32BIG_C(0xff3dffbaU), BSWAP_32BIG_C(
                    0x918a69beU),
            };
            r_rsip_func101(Param_func321_func101_018);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
            OFS_ADR = 408;
            r_rsip_func_sub012(0x18800000U, 0x0000b400U, 0x00000084U);
            r_rsip_func_sub009(0x0000321aU);
            static const uint32_t Param_func321_func101_019[] =
            {
                BSWAP_32BIG_C(0x596679b2U), BSWAP_32BIG_C(0xcacd9491U), BSWAP_32BIG_C(0xdbb55f84U), BSWAP_32BIG_C(
                    0x7d68411fU),
            };
            r_rsip_func101(Param_func321_func101_019);
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_func_sub001(0x00c00201U);
            WR1_PROG(REG_1014H, 0x00000230U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000878U, 0x40400009U, 0x00010001U);
            r_rsip_func_sub026(0x00000660U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000230U, 0x40400009U, 0x00010001U);
            r_rsip_func_sub026(0x00000878U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000660U, 0x40400009U, 0x00010001U);
            r_rsip_func_sub026(0x00000230U, 0x00000660U);
            r_rsip_func_sub005(0x00000878U, 0x4040000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00a10000U);
            static const uint32_t Param_func321_func100_003[] =
            {
                BSWAP_32BIG_C(0x00231b00U), BSWAP_32BIG_C(0xdc997757U), BSWAP_32BIG_C(0xa4740cafU), BSWAP_32BIG_C(
                    0xed0f13c3U),
            };
            r_rsip_func100(Param_func321_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000878U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                r_rsip_func_sub005(0x00000230U, 0x40400009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x00003215U);
                static const uint32_t Param_func321_func101_020[] =
                {
                    BSWAP_32BIG_C(0xd84ca561U), BSWAP_32BIG_C(0xad70c105U), BSWAP_32BIG_C(0x28e4027aU), BSWAP_32BIG_C(
                        0xb0d884ecU),
                };
                r_rsip_func101(Param_func321_func101_020);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
                OFS_ADR = 272;
                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x00003216U);
                static const uint32_t Param_func321_func101_021[] =
                {
                    BSWAP_32BIG_C(0x16c60115U), BSWAP_32BIG_C(0x93561bb6U), BSWAP_32BIG_C(0x7d2e750dU), BSWAP_32BIG_C(
                        0xbb9ed60aU),
                };
                r_rsip_func101(Param_func321_func101_021);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003211U);
                static const uint32_t Param_func321_func101_022[] =
                {
                    BSWAP_32BIG_C(0xef0708cbU), BSWAP_32BIG_C(0x8628fe83U), BSWAP_32BIG_C(0x9a49d347U), BSWAP_32BIG_C(
                        0x036db239U),
                };
                r_rsip_func101(Param_func321_func101_022);
                r_rsip_func324();
                r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321bU);
                static const uint32_t Param_func321_func101_023[] =
                {
                    BSWAP_32BIG_C(0x6be35146U), BSWAP_32BIG_C(0x567ad338U), BSWAP_32BIG_C(0x5ae17855U), BSWAP_32BIG_C(
                        0x3a670e7aU),
                };
                r_rsip_func101(Param_func321_func101_023);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
                OFS_ADR = 136;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x00003217U);
                static const uint32_t Param_func321_func101_024[] =
                {
                    BSWAP_32BIG_C(0x2f0648d1U), BSWAP_32BIG_C(0xc68a8d27U), BSWAP_32BIG_C(0x022c552cU), BSWAP_32BIG_C(
                        0xc58aa259U),
                };
                r_rsip_func101(Param_func321_func101_024);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
                OFS_ADR = 408;
                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x00003218U);
                static const uint32_t Param_func321_func101_025[] =
                {
                    BSWAP_32BIG_C(0x2672f28cU), BSWAP_32BIG_C(0x1c4ac3e7U), BSWAP_32BIG_C(0x6052c13fU), BSWAP_32BIG_C(
                        0x46adbb60U),
                };
                r_rsip_func101(Param_func321_func101_025);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003212U);
                static const uint32_t Param_func321_func101_026[] =
                {
                    BSWAP_32BIG_C(0x183e9ef2U), BSWAP_32BIG_C(0x42bf1d42U), BSWAP_32BIG_C(0x47e15dbfU), BSWAP_32BIG_C(
                        0x7fbfbccbU),
                };
                r_rsip_func101(Param_func321_func101_026);
                r_rsip_func324();
                r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
                OFS_ADR = 136;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321cU);
                static const uint32_t Param_func321_func101_027[] =
                {
                    BSWAP_32BIG_C(0x3479179fU), BSWAP_32BIG_C(0x448b4373U), BSWAP_32BIG_C(0xfd09bf8fU), BSWAP_32BIG_C(
                        0xcf754ed6U),
                };
                r_rsip_func101(Param_func321_func101_027);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func321_func101_028[] =
                {
                    BSWAP_32BIG_C(0x03b2d372U), BSWAP_32BIG_C(0x93e05cd4U), BSWAP_32BIG_C(0xb1b6b0e0U), BSWAP_32BIG_C(
                        0x9ee92f95U),
                };
                r_rsip_func101(Param_func321_func101_028);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000660U);
                WR1_PROG(REG_1018H, 0x00000230U);
                r_rsip_func_sub005(0x00000660U, 0x4040000aU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
                OFS_ADR = 272;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321aU);
                static const uint32_t Param_func321_func101_029[] =
                {
                    BSWAP_32BIG_C(0x10325768U), BSWAP_32BIG_C(0xd6697732U), BSWAP_32BIG_C(0x18b0f0fdU), BSWAP_32BIG_C(
                        0x25c358f1U),
                };
                r_rsip_func101(Param_func321_func101_029);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x9fd531f0U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321bU);
                static const uint32_t Param_func321_func101_030[] =
                {
                    BSWAP_32BIG_C(0x0baf3cf6U), BSWAP_32BIG_C(0x48984e2cU), BSWAP_32BIG_C(0x6ee7cc5aU), BSWAP_32BIG_C(
                        0x32d455d9U),
                };
                r_rsip_func101(Param_func321_func101_030);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003213U);
                static const uint32_t Param_func321_func101_031[] =
                {
                    BSWAP_32BIG_C(0xc4f1c16bU), BSWAP_32BIG_C(0x8fbeb87aU), BSWAP_32BIG_C(0xe76928e2U), BSWAP_32BIG_C(
                        0xfce7e9d3U),
                };
                r_rsip_func101(Param_func321_func101_031);
                r_rsip_func324();
                r_rsip_func_sub015(0x0b040184U, 0x5bfa91b0U);
                OFS_ADR = 272;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321dU);
                static const uint32_t Param_func321_func101_032[] =
                {
                    BSWAP_32BIG_C(0x9e0262e1U), BSWAP_32BIG_C(0x1fdca22bU), BSWAP_32BIG_C(0x52b05ef2U), BSWAP_32BIG_C(
                        0xf38b5633U),
                };
                r_rsip_func101(Param_func321_func101_032);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
                OFS_ADR = 408;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321cU);
                static const uint32_t Param_func321_func101_033[] =
                {
                    BSWAP_32BIG_C(0xe3088868U), BSWAP_32BIG_C(0x45bb0fe8U), BSWAP_32BIG_C(0x01ffcd20U), BSWAP_32BIG_C(
                        0x14ed4107U),
                };
                r_rsip_func101(Param_func321_func101_033);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xf9bf3112U);
                OFS_ADR = 136;
                r_rsip_func_sub012(0x1dc80000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321dU);
                static const uint32_t Param_func321_func101_034[] =
                {
                    BSWAP_32BIG_C(0xff98eea3U), BSWAP_32BIG_C(0xdc4178efU), BSWAP_32BIG_C(0xa49dcb8bU), BSWAP_32BIG_C(
                        0x1c05f1c9U),
                };
                r_rsip_func101(Param_func321_func101_034);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003214U);
                static const uint32_t Param_func321_func101_035[] =
                {
                    BSWAP_32BIG_C(0xd6bb27deU), BSWAP_32BIG_C(0xc8df4617U), BSWAP_32BIG_C(0x877446b0U), BSWAP_32BIG_C(
                        0xdb743a5cU),
                };
                r_rsip_func101(Param_func321_func101_035);
                r_rsip_func324();
                r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
                OFS_ADR = 408;
                r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
                r_rsip_func_sub009(0x0000321eU);
                static const uint32_t Param_func321_func101_036[] =
                {
                    BSWAP_32BIG_C(0x19273b21U), BSWAP_32BIG_C(0xe89208a1U), BSWAP_32BIG_C(0x19abbf79U), BSWAP_32BIG_C(
                        0x3682d180U),
                };
                r_rsip_func101(Param_func321_func101_036);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func321_func101_037[] =
                {
                    BSWAP_32BIG_C(0xd9eab1c7U), BSWAP_32BIG_C(0xe8cf11d7U), BSWAP_32BIG_C(0xad23639aU), BSWAP_32BIG_C(
                        0xb3f7e648U),
                };
                r_rsip_func101(Param_func321_func101_037);
            }
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0x7edfb1abU);
    OFS_ADR = 544;
    r_rsip_func_sub012(0x10300000U, 0x0000b400U, 0x00000080U);
    r_rsip_func_sub009(0x0000321eU);
    static const uint32_t Param_func321_func101_038[] =
    {
        BSWAP_32BIG_C(0x39d7cce0U), BSWAP_32BIG_C(0x85759887U), BSWAP_32BIG_C(0x7e2ec732U), BSWAP_32BIG_C(0xf985c637U),
    };
    r_rsip_func101(Param_func321_func101_038);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub015(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);
        static const uint32_t Param_func321_func100_004[] =
        {
            BSWAP_32BIG_C(0x4e7eea18U), BSWAP_32BIG_C(0xccbf3c25U), BSWAP_32BIG_C(0x9e149799U), BSWAP_32BIG_C(
                0x3321db56U),
        };
        r_rsip_func100(Param_func321_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000a90U);
            WR1_PROG(REG_1018H, 0x00000660U);
            r_rsip_func_sub005(0x00000660U, 0x40400008U, 0x00010001U);
            r_rsip_func_sub026(0x00000a90U, 0x00000230U);
            r_rsip_func_sub005(0x00000230U, 0x40400008U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            static const uint32_t Param_func321_func101_039[] =
            {
                BSWAP_32BIG_C(0x70e12068U), BSWAP_32BIG_C(0x17e56877U), BSWAP_32BIG_C(0xcf9b1f9dU), BSWAP_32BIG_C(
                    0xd91eb19eU),
            };
            r_rsip_func101(Param_func321_func101_039);
        }
        else
        {
            static const uint32_t Param_func321_func101_040[] =
            {
                BSWAP_32BIG_C(0xd30c0b7dU), BSWAP_32BIG_C(0x047d3c99U), BSWAP_32BIG_C(0xa4408661U), BSWAP_32BIG_C(
                    0x3b91b033U),
            };
            r_rsip_func101(Param_func321_func101_040);
            break;
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0x0c0ab7c4U);
    OFS_ADR = 408;
    r_rsip_func_sub012(0x16680000U, 0x0000b400U, 0x00000084U);
    r_rsip_func_sub009(0x0000321fU);
    static const uint32_t Param_func321_func101_041[] =
    {
        BSWAP_32BIG_C(0x27c3d09dU), BSWAP_32BIG_C(0x2b99a4acU), BSWAP_32BIG_C(0x12d082ceU), BSWAP_32BIG_C(0x2972f09eU),
    };
    r_rsip_func101(Param_func321_func101_041);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    while (1)
    {
        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000878U);
        r_rsip_func_sub005(0x00000a90U, 0x4141000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func321_func100_005[] =
        {
            BSWAP_32BIG_C(0xd8bf9319U), BSWAP_32BIG_C(0xcdbf5f8aU), BSWAP_32BIG_C(0x6f4bbb0cU), BSWAP_32BIG_C(
                0x60062f0eU),
        };
        r_rsip_func100(Param_func321_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000878U);
            WR1_PROG(REG_1018H, 0x00000230U);
            r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func321_func101_042[] =
            {
                BSWAP_32BIG_C(0x61ff77fdU), BSWAP_32BIG_C(0x7f775e7fU), BSWAP_32BIG_C(0x795224a5U), BSWAP_32BIG_C(
                    0x380c81faU),
            };
            r_rsip_func101(Param_func321_func101_042);
        }
        else
        {
            static const uint32_t Param_func321_func101_043[] =
            {
                BSWAP_32BIG_C(0x1fa2bf08U), BSWAP_32BIG_C(0xc0a9a249U), BSWAP_32BIG_C(0xac2d290dU), BSWAP_32BIG_C(
                    0x60d67742U),
            };
            r_rsip_func101(Param_func321_func101_043);
            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);
    static const uint32_t Param_func321_func100_006[] =
    {
        BSWAP_32BIG_C(0xf3d04496U), BSWAP_32BIG_C(0x656599b8U), BSWAP_32BIG_C(0x0c44dc80U), BSWAP_32BIG_C(0x37ef4bccU),
    };
    r_rsip_func100(Param_func321_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1014H, 0x00000230U);
        WR1_PROG(REG_1018H, 0x00000878U);
        r_rsip_func_sub005(0x00000878U, 0x4141000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        static const uint32_t Param_func321_func101_044[] =
        {
            BSWAP_32BIG_C(0x254702a9U), BSWAP_32BIG_C(0xe88e33ceU), BSWAP_32BIG_C(0x9fb2e846U), BSWAP_32BIG_C(
                0x37706fffU),
        };
        r_rsip_func101(Param_func321_func101_044);
    }
    else
    {
        static const uint32_t Param_func321_func101_045[] =
        {
            BSWAP_32BIG_C(0x3aa5f4c0U), BSWAP_32BIG_C(0x1b50bf80U), BSWAP_32BIG_C(0x055b0e62U), BSWAP_32BIG_C(
                0xb1e1b0efU),
        };
        r_rsip_func101(Param_func321_func101_045);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
