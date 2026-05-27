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

void r_rsip_func313 (void)
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
        static const uint32_t Param_func313_func100_001[] =
        {
            BSWAP_32BIG_C(0x601736b6U), BSWAP_32BIG_C(0x19fb0987U), BSWAP_32BIG_C(0x68ead324U), BSWAP_32BIG_C(
                0x0bafc5cfU),
        };
        r_rsip_func100(Param_func313_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x1818000cU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            static const uint32_t Param_func313_func101_001[] =
            {
                BSWAP_32BIG_C(0x6b757ba9U), BSWAP_32BIG_C(0x333b00b6U), BSWAP_32BIG_C(0x0926d849U), BSWAP_32BIG_C(
                    0xdea75fecU),
            };
            r_rsip_func101(Param_func313_func101_001);
        }
        else
        {
            static const uint32_t Param_func313_func101_002[] =
            {
                BSWAP_32BIG_C(0xc2fd8664U), BSWAP_32BIG_C(0x1607d0a7U), BSWAP_32BIG_C(0xce650d98U), BSWAP_32BIG_C(
                    0x44c5103cU),
            };
            r_rsip_func101(Param_func313_func101_002);
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_func_sub001(0x00c000d1U);
    r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
    OFS_ADR = 56;
    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
    r_rsip_func_sub009(0x00003131U);
    static const uint32_t Param_func313_func101_003[] =
    {
        BSWAP_32BIG_C(0x9f7b69d4U), BSWAP_32BIG_C(0xda3ba583U), BSWAP_32BIG_C(0xfb075510U), BSWAP_32BIG_C(0xaa01f531U),
    };
    r_rsip_func101(Param_func313_func101_003);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
    OFS_ADR = 112;
    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
    r_rsip_func_sub009(0x00003132U);
    static const uint32_t Param_func313_func101_004[] =
    {
        BSWAP_32BIG_C(0x6a87e9d0U), BSWAP_32BIG_C(0x17c15a85U), BSWAP_32BIG_C(0x751d056dU), BSWAP_32BIG_C(0x2d96f3fcU),
    };
    r_rsip_func101(Param_func313_func101_004);
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub015(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    r_rsip_func_sub015(0x0b040184U, 0xab580788U);
    OFS_ADR = 0;
    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
    r_rsip_func_sub009(0x00003133U);
    static const uint32_t Param_func313_func101_005[] =
    {
        BSWAP_32BIG_C(0xf30204aeU), BSWAP_32BIG_C(0xe707b24cU), BSWAP_32BIG_C(0x60e62817U), BSWAP_32BIG_C(0xfc5cdffaU),
    };
    r_rsip_func101(Param_func313_func101_005);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
    OFS_ADR = 168;
    r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
    r_rsip_func_sub009(0x00003134U);
    static const uint32_t Param_func313_func101_006[] =
    {
        BSWAP_32BIG_C(0xe847ce29U), BSWAP_32BIG_C(0xc7ff1346U), BSWAP_32BIG_C(0xb3798ac0U), BSWAP_32BIG_C(0x66179da1U),
    };
    r_rsip_func101(Param_func313_func101_006);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub015(0x0b040184U, 0xf6428095U);
    OFS_ADR = 224;
    r_rsip_func_sub012(0x11600000U, 0x0000b400U, 0x00000030U);
    r_rsip_func_sub009(0x00003135U);
    static const uint32_t Param_func313_func101_007[] =
    {
        BSWAP_32BIG_C(0x60439d51U), BSWAP_32BIG_C(0x6c02fbeaU), BSWAP_32BIG_C(0xac8cd97dU), BSWAP_32BIG_C(0xe3062ea0U),
    };
    r_rsip_func101(Param_func313_func101_007);
    r_rsip_func016(OFS_ADR);
    r_rsip_func_sub033(0x15700000U, 0x00000b7bU, 0x80b0001bU);
    r_rsip_func_sub001(0x034300c1U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub015(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000a40U);
        r_rsip_func_sub005(0x00000838U, 0x1818000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func313_func100_002[] =
        {
            BSWAP_32BIG_C(0xa4928d99U), BSWAP_32BIG_C(0x8ccb6d81U), BSWAP_32BIG_C(0xb273c1cdU), BSWAP_32BIG_C(
                0xdb626188U),
        };
        r_rsip_func100(Param_func313_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            static const uint32_t Param_func313_func101_008[] =
            {
                BSWAP_32BIG_C(0xe052148bU), BSWAP_32BIG_C(0xf0ecd87bU), BSWAP_32BIG_C(0x5f593ca7U), BSWAP_32BIG_C(
                    0xac34cd3bU),
            };
            r_rsip_func101(Param_func313_func101_008);
            break;
        }
        else
        {
            r_rsip_func_sub015(0x0b040184U, 0xab580788U);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003131U);
            static const uint32_t Param_func313_func101_009[] =
            {
                BSWAP_32BIG_C(0x36c1d3aeU), BSWAP_32BIG_C(0xb1fd7c31U), BSWAP_32BIG_C(0x866d0b43U), BSWAP_32BIG_C(
                    0x8ae28132U),
            };
            r_rsip_func101(Param_func313_func101_009);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
            OFS_ADR = 56;
            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003132U);
            static const uint32_t Param_func313_func101_010[] =
            {
                BSWAP_32BIG_C(0x93695a66U), BSWAP_32BIG_C(0x1b406f63U), BSWAP_32BIG_C(0x49196257U), BSWAP_32BIG_C(
                    0x671b5c6bU),
            };
            r_rsip_func101(Param_func313_func101_010);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub009(0x00003131U);
            static const uint32_t Param_func313_func101_011[] =
            {
                BSWAP_32BIG_C(0x9271668aU), BSWAP_32BIG_C(0xef4f78ddU), BSWAP_32BIG_C(0xcada7454U), BSWAP_32BIG_C(
                    0xd8a8648fU),
            };
            r_rsip_func101(Param_func313_func101_011);
            r_rsip_func314();
            r_rsip_func_sub015(0x0b040184U, 0xab580788U);
            OFS_ADR = 0;
            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003136U);
            static const uint32_t Param_func313_func101_012[] =
            {
                BSWAP_32BIG_C(0x11c23b1fU), BSWAP_32BIG_C(0x462a935fU), BSWAP_32BIG_C(0xf30a0e6fU), BSWAP_32BIG_C(
                    0x7df428dfU),
            };
            r_rsip_func101(Param_func313_func101_012);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
            OFS_ADR = 56;
            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003137U);
            static const uint32_t Param_func313_func101_013[] =
            {
                BSWAP_32BIG_C(0x9cefca6dU), BSWAP_32BIG_C(0x956fd979U), BSWAP_32BIG_C(0xf07c01d0U), BSWAP_32BIG_C(
                    0xa1542807U),
            };
            r_rsip_func101(Param_func313_func101_013);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
            OFS_ADR = 112;
            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003133U);
            static const uint32_t Param_func313_func101_014[] =
            {
                BSWAP_32BIG_C(0x3b4efc9fU), BSWAP_32BIG_C(0x66f98bd7U), BSWAP_32BIG_C(0x2ce42495U), BSWAP_32BIG_C(
                    0xc0d2a9f1U),
            };
            r_rsip_func101(Param_func313_func101_014);
            r_rsip_func017(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
            OFS_ADR = 168;
            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003134U);
            static const uint32_t Param_func313_func101_015[] =
            {
                BSWAP_32BIG_C(0xe7013b3eU), BSWAP_32BIG_C(0xa2c5ad8aU), BSWAP_32BIG_C(0x6d827c74U), BSWAP_32BIG_C(
                    0xf0770fa0U),
            };
            r_rsip_func101(Param_func313_func101_015);
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_func_sub001(0x00c000c1U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x18180009U, 0x00010001U);
            r_rsip_func_sub031(0x00000630U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000220U, 0x18180009U, 0x00010001U);
            r_rsip_func_sub031(0x00000838U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000630U, 0x18180009U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_func_sub009(0x00003132U);
            static const uint32_t Param_func313_func101_016[] =
            {
                BSWAP_32BIG_C(0x186cc5b7U), BSWAP_32BIG_C(0x7420d5a4U), BSWAP_32BIG_C(0xcfc756e2U), BSWAP_32BIG_C(
                    0xf9183b48U),
            };
            r_rsip_func101(Param_func313_func101_016);
            r_rsip_func314();
            r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
            OFS_ADR = 112;
            r_rsip_func_sub012(0x13580000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003138U);
            static const uint32_t Param_func313_func101_017[] =
            {
                BSWAP_32BIG_C(0x29ce0bd2U), BSWAP_32BIG_C(0x4cdbcf3cU), BSWAP_32BIG_C(0x77ab84c0U), BSWAP_32BIG_C(
                    0x878595a7U),
            };
            r_rsip_func101(Param_func313_func101_017);
            r_rsip_func016(OFS_ADR);
            r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
            OFS_ADR = 168;
            r_rsip_func_sub012(0x19700000U, 0x0000b400U, 0x00000034U);
            r_rsip_func_sub009(0x00003139U);
            static const uint32_t Param_func313_func101_018[] =
            {
                BSWAP_32BIG_C(0xf75fd450U), BSWAP_32BIG_C(0x6079636fU), BSWAP_32BIG_C(0x8abd4af0U), BSWAP_32BIG_C(
                    0x8973d947U),
            };
            r_rsip_func101(Param_func313_func101_018);
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_func_sub001(0x00c000c1U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_1018H, 0x00000fd8U);
            r_rsip_func_sub005(0x00000838U, 0x18180009U, 0x00010001U);
            r_rsip_func_sub031(0x00000630U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000220U, 0x18180009U, 0x00010001U);
            r_rsip_func_sub031(0x00000838U, 0x00000fd8U);
            r_rsip_func_sub005(0x00000630U, 0x18180009U, 0x00010001U);
            r_rsip_func_sub031(0x00000220U, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x1818000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00a10000U);
            static const uint32_t Param_func313_func100_003[] =
            {
                BSWAP_32BIG_C(0xe300f11fU), BSWAP_32BIG_C(0x8b2e4275U), BSWAP_32BIG_C(0x0323bde9U), BSWAP_32BIG_C(
                    0xb705bcd9U),
            };
            r_rsip_func100(Param_func313_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000838U);
                WR1_PROG(REG_1018H, 0x00000fd8U);
                r_rsip_func_sub005(0x00000220U, 0x18180009U, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0xab580788U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x00003135U);
                static const uint32_t Param_func313_func101_019[] =
                {
                    BSWAP_32BIG_C(0x72449468U), BSWAP_32BIG_C(0x97696a0aU), BSWAP_32BIG_C(0x0e1e6703U), BSWAP_32BIG_C(
                        0x5f6d0728U),
                };
                r_rsip_func101(Param_func313_func101_019);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
                OFS_ADR = 112;
                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x00003136U);
                static const uint32_t Param_func313_func101_020[] =
                {
                    BSWAP_32BIG_C(0x41182fa3U), BSWAP_32BIG_C(0xc99bbdb0U), BSWAP_32BIG_C(0x334b6958U), BSWAP_32BIG_C(
                        0x644f9a03U),
                };
                r_rsip_func101(Param_func313_func101_020);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003131U);
                static const uint32_t Param_func313_func101_021[] =
                {
                    BSWAP_32BIG_C(0xbe82515aU), BSWAP_32BIG_C(0x55489f24U), BSWAP_32BIG_C(0x528e969bU), BSWAP_32BIG_C(
                        0x03f8f718U),
                };
                r_rsip_func101(Param_func313_func101_021);
                r_rsip_func318();
                r_rsip_func_sub015(0x0b040184U, 0xab580788U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313aU);
                static const uint32_t Param_func313_func101_022[] =
                {
                    BSWAP_32BIG_C(0x2b135aa0U), BSWAP_32BIG_C(0x2e45d35eU), BSWAP_32BIG_C(0x3c4e2ff2U), BSWAP_32BIG_C(
                        0x559e8e9aU),
                };
                r_rsip_func101(Param_func313_func101_022);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
                OFS_ADR = 56;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x00003137U);
                static const uint32_t Param_func313_func101_023[] =
                {
                    BSWAP_32BIG_C(0xfac50d60U), BSWAP_32BIG_C(0x0576dd30U), BSWAP_32BIG_C(0xc16c18a9U), BSWAP_32BIG_C(
                        0xd6a8f7c3U),
                };
                r_rsip_func101(Param_func313_func101_023);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
                OFS_ADR = 168;
                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x00003138U);
                static const uint32_t Param_func313_func101_024[] =
                {
                    BSWAP_32BIG_C(0xebaec341U), BSWAP_32BIG_C(0xb6b145e3U), BSWAP_32BIG_C(0x1a6814e4U), BSWAP_32BIG_C(
                        0x8f20f3aaU),
                };
                r_rsip_func101(Param_func313_func101_024);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003132U);
                static const uint32_t Param_func313_func101_025[] =
                {
                    BSWAP_32BIG_C(0xac0accfbU), BSWAP_32BIG_C(0xb717f228U), BSWAP_32BIG_C(0xeaee71b3U), BSWAP_32BIG_C(
                        0x0f24f3cfU),
                };
                r_rsip_func101(Param_func313_func101_025);
                r_rsip_func318();
                r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
                OFS_ADR = 56;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313bU);
                static const uint32_t Param_func313_func101_026[] =
                {
                    BSWAP_32BIG_C(0xdad3dae3U), BSWAP_32BIG_C(0x0c8e7e1bU), BSWAP_32BIG_C(0x6e1a0d23U), BSWAP_32BIG_C(
                        0xbf77ba47U),
                };
                r_rsip_func101(Param_func313_func101_026);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func313_func101_027[] =
                {
                    BSWAP_32BIG_C(0x7df2e2d1U), BSWAP_32BIG_C(0x72ae1bb1U), BSWAP_32BIG_C(0xd8ca81e6U), BSWAP_32BIG_C(
                        0x189cf641U),
                };
                r_rsip_func101(Param_func313_func101_027);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                WR1_PROG(REG_1018H, 0x00000220U);
                r_rsip_func_sub005(0x00000630U, 0x1818000aU, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
                OFS_ADR = 112;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313aU);
                static const uint32_t Param_func313_func101_028[] =
                {
                    BSWAP_32BIG_C(0xa0c300c3U), BSWAP_32BIG_C(0x289d5f26U), BSWAP_32BIG_C(0x83278ddcU), BSWAP_32BIG_C(
                        0xde65c683U),
                };
                r_rsip_func101(Param_func313_func101_028);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xab580788U);
                OFS_ADR = 0;
                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313bU);
                static const uint32_t Param_func313_func101_029[] =
                {
                    BSWAP_32BIG_C(0xb1a5c137U), BSWAP_32BIG_C(0x4d82510aU), BSWAP_32BIG_C(0x2afbd7f9U), BSWAP_32BIG_C(
                        0x7b036221U),
                };
                r_rsip_func101(Param_func313_func101_029);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003133U);
                static const uint32_t Param_func313_func101_030[] =
                {
                    BSWAP_32BIG_C(0xcf433d64U), BSWAP_32BIG_C(0xdd50045cU), BSWAP_32BIG_C(0x5e6b31f3U), BSWAP_32BIG_C(
                        0x44001b9fU),
                };
                r_rsip_func101(Param_func313_func101_030);
                r_rsip_func318();
                r_rsip_func_sub015(0x0b040184U, 0x4db9e5b0U);
                OFS_ADR = 112;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313cU);
                static const uint32_t Param_func313_func101_031[] =
                {
                    BSWAP_32BIG_C(0xb9d83081U), BSWAP_32BIG_C(0xcc17117aU), BSWAP_32BIG_C(0x179ce4d6U), BSWAP_32BIG_C(
                        0xb0984394U),
                };
                r_rsip_func101(Param_func313_func101_031);
                r_rsip_func016(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
                OFS_ADR = 168;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313cU);
                static const uint32_t Param_func313_func101_032[] =
                {
                    BSWAP_32BIG_C(0xf4a60cb1U), BSWAP_32BIG_C(0x1071ad70U), BSWAP_32BIG_C(0x494fb89cU), BSWAP_32BIG_C(
                        0xd25acd29U),
                };
                r_rsip_func101(Param_func313_func101_032);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub015(0x0b040184U, 0xa277852fU);
                OFS_ADR = 56;
                r_rsip_func_sub012(0x1f080000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313dU);
                static const uint32_t Param_func313_func101_033[] =
                {
                    BSWAP_32BIG_C(0xb6d74ebfU), BSWAP_32BIG_C(0x70ee8bd8U), BSWAP_32BIG_C(0x824af075U), BSWAP_32BIG_C(
                        0xc190dff2U),
                };
                r_rsip_func101(Param_func313_func101_033);
                r_rsip_func017(OFS_ADR);
                r_rsip_func_sub009(0x00003134U);
                static const uint32_t Param_func313_func101_034[] =
                {
                    BSWAP_32BIG_C(0xb89562cfU), BSWAP_32BIG_C(0x1d4c335aU), BSWAP_32BIG_C(0x4acb6936U), BSWAP_32BIG_C(
                        0x1bd9ee01U),
                };
                r_rsip_func101(Param_func313_func101_034);
                r_rsip_func318();
                r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
                OFS_ADR = 168;
                r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
                r_rsip_func_sub009(0x0000313dU);
                static const uint32_t Param_func313_func101_035[] =
                {
                    BSWAP_32BIG_C(0xea0750fcU), BSWAP_32BIG_C(0xec110227U), BSWAP_32BIG_C(0xce067e1dU), BSWAP_32BIG_C(
                        0x2bfb6617U),
                };
                r_rsip_func101(Param_func313_func101_035);
                r_rsip_func016(OFS_ADR);
                static const uint32_t Param_func313_func101_036[] =
                {
                    BSWAP_32BIG_C(0x1f0d3f81U), BSWAP_32BIG_C(0x126b48aaU), BSWAP_32BIG_C(0x87efc409U), BSWAP_32BIG_C(
                        0x229c44bfU),
                };
                r_rsip_func101(Param_func313_func101_036);
            }
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0xf6428095U);
    OFS_ADR = 224;
    r_rsip_func_sub012(0x11600000U, 0x0000b400U, 0x00000030U);
    r_rsip_func_sub009(0x0000313eU);
    static const uint32_t Param_func313_func101_037[] =
    {
        BSWAP_32BIG_C(0xd6b7e1abU), BSWAP_32BIG_C(0x3019af4aU), BSWAP_32BIG_C(0xc68d9fd0U), BSWAP_32BIG_C(0x053798a8U),
    };
    r_rsip_func101(Param_func313_func101_037);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub015(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);
    while (1)
    {
        r_rsip_func_sub017(0x38000fdeU, 0x00A60000U);
        static const uint32_t Param_func313_func100_004[] =
        {
            BSWAP_32BIG_C(0x699e3e0dU), BSWAP_32BIG_C(0x3bf794f4U), BSWAP_32BIG_C(0xad74dc44U), BSWAP_32BIG_C(
                0x04223bf8U),
        };
        r_rsip_func100(Param_func313_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000a40U);
            WR1_PROG(REG_1018H, 0x00000630U);
            r_rsip_func_sub005(0x00000630U, 0x18180008U, 0x00010001U);
            r_rsip_func_sub031(0x00000a40U, 0x00000220U);
            r_rsip_func_sub005(0x00000220U, 0x18180008U, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            static const uint32_t Param_func313_func101_038[] =
            {
                BSWAP_32BIG_C(0x2206fab3U), BSWAP_32BIG_C(0x44f06b9bU), BSWAP_32BIG_C(0xa8e9eb51U), BSWAP_32BIG_C(
                    0x06e705cdU),
            };
            r_rsip_func101(Param_func313_func101_038);
        }
        else
        {
            static const uint32_t Param_func313_func101_039[] =
            {
                BSWAP_32BIG_C(0x71e9a522U), BSWAP_32BIG_C(0x75f83d15U), BSWAP_32BIG_C(0x805eac24U), BSWAP_32BIG_C(
                    0x73853ef7U),
            };
            r_rsip_func101(Param_func313_func101_039);
            break;
        }
    }

    r_rsip_func_sub015(0x0b040184U, 0xc447d111U);
    OFS_ADR = 168;
    r_rsip_func_sub012(0x17680000U, 0x0000b400U, 0x00000034U);
    r_rsip_func_sub009(0x0000313fU);
    static const uint32_t Param_func313_func101_040[] =
    {
        BSWAP_32BIG_C(0x2f926c08U), BSWAP_32BIG_C(0xa43d848aU), BSWAP_32BIG_C(0x7b7f81aaU), BSWAP_32BIG_C(0xd98a8350U),
    };
    r_rsip_func101(Param_func313_func101_040);
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);
    while (1)
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        r_rsip_func_sub005(0x00000a40U, 0x1919000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00210000U);
        static const uint32_t Param_func313_func100_005[] =
        {
            BSWAP_32BIG_C(0xa621e6aaU), BSWAP_32BIG_C(0x3fc6b52eU), BSWAP_32BIG_C(0x18bfb9a5U), BSWAP_32BIG_C(
                0x76e5cecaU),
        };
        r_rsip_func100(Param_func313_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            static const uint32_t Param_func313_func101_041[] =
            {
                BSWAP_32BIG_C(0x4c0ddd5aU), BSWAP_32BIG_C(0xbba73c23U), BSWAP_32BIG_C(0x72898d56U), BSWAP_32BIG_C(
                    0xc55e31d6U),
            };
            r_rsip_func101(Param_func313_func101_041);
        }
        else
        {
            static const uint32_t Param_func313_func101_042[] =
            {
                BSWAP_32BIG_C(0xeca9afafU), BSWAP_32BIG_C(0xeda04ec6U), BSWAP_32BIG_C(0xd7d96c40U), BSWAP_32BIG_C(
                    0x4b48a5b3U),
            };
            r_rsip_func101(Param_func313_func101_042);
            break;
        }
    }

    r_rsip_func_sub017(0x3800db60U, 0x00A60000U);
    static const uint32_t Param_func313_func100_006[] =
    {
        BSWAP_32BIG_C(0xa60bfb3aU), BSWAP_32BIG_C(0x8d4bd31cU), BSWAP_32BIG_C(0xdf36912eU), BSWAP_32BIG_C(0x07c6f6d5U),
    };
    r_rsip_func100(Param_func313_func100_006);
    WR1_PROG(REG_143CH, 0x00400000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_1018H, 0x00000838U);
        r_rsip_func_sub005(0x00000838U, 0x1919000aU, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        static const uint32_t Param_func313_func101_043[] =
        {
            BSWAP_32BIG_C(0x997b6084U), BSWAP_32BIG_C(0x4a9f74b8U), BSWAP_32BIG_C(0x68ef78b0U), BSWAP_32BIG_C(
                0x7407aeafU),
        };
        r_rsip_func101(Param_func313_func101_043);
    }
    else
    {
        static const uint32_t Param_func313_func101_044[] =
        {
            BSWAP_32BIG_C(0x9db08274U), BSWAP_32BIG_C(0x56fcc2dfU), BSWAP_32BIG_C(0xa05cdb0cU), BSWAP_32BIG_C(
                0x60fd4729U),
        };
        r_rsip_func101(Param_func313_func101_044);
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
