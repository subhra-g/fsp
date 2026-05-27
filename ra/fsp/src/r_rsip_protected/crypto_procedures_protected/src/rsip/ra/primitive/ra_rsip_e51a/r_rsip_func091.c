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

void r_rsip_func091 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0909000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003e0U, 0x09090010U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f09101U);

    static const uint32_t Param_func091_func101_001[] =
    {
        BSWAP_32BIG_C(0x3de075e8U), BSWAP_32BIG_C(0x1a41184cU), BSWAP_32BIG_C(0xd065c5c7U), BSWAP_32BIG_C(0x03a784e6U),
    };
    r_rsip_func101(Param_func091_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f09102U);

    static const uint32_t Param_func091_func101_002[] =
    {
        BSWAP_32BIG_C(0x42e9f698U), BSWAP_32BIG_C(0xa79a4ec6U), BSWAP_32BIG_C(0x77e3b250U), BSWAP_32BIG_C(0x37b7205eU),
    };
    r_rsip_func101(Param_func091_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f09103U);

    static const uint32_t Param_func091_func101_003[] =
    {
        BSWAP_32BIG_C(0xfd1c7dd9U), BSWAP_32BIG_C(0x9edb7d40U), BSWAP_32BIG_C(0x1b143160U), BSWAP_32BIG_C(0x30361622U),
    };
    r_rsip_func101(Param_func091_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f09104U);

    static const uint32_t Param_func091_func101_004[] =
    {
        BSWAP_32BIG_C(0xbeb89ebdU), BSWAP_32BIG_C(0xf930ebd1U), BSWAP_32BIG_C(0x96788c89U), BSWAP_32BIG_C(0xda7aff3eU),
    };
    r_rsip_func101(Param_func091_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00f09105U);

    static const uint32_t Param_func091_func101_005[] =
    {
        BSWAP_32BIG_C(0xafad0640U), BSWAP_32BIG_C(0x3515d4cbU), BSWAP_32BIG_C(0x5d57d18cU), BSWAP_32BIG_C(0xc5de0bd7U),
    };
    r_rsip_func101(Param_func091_func101_005);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub021(0x000003e0U, 0x00000480U, 0x00000020U, 0x09090004U);
    WR1_PROG(REG_1404H, 0x13e80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c00045U);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000430U, 0x00000160U, 0x09090009U);

    r_rsip_func_sub038(0x00000020U, 0x000000c0U, 0x09090010U);
    r_rsip_func_sub007(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x09090005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000430U, 0x00000480U, 0x0909000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func091_func100_001[] =
    {
        BSWAP_32BIG_C(0x45038653U), BSWAP_32BIG_C(0x97f8962cU), BSWAP_32BIG_C(0x9b6b2223U), BSWAP_32BIG_C(0x3893c652U),
    };
    r_rsip_func100(Param_func091_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func091_func101_006[] =
        {
            BSWAP_32BIG_C(0x0d682d78U), BSWAP_32BIG_C(0xa24969e3U), BSWAP_32BIG_C(0x62f979f8U), BSWAP_32BIG_C(
                0xac30c52cU),
        };
        r_rsip_func101(Param_func091_func101_006);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_func_sub021(0x00000070U, 0x00000250U, 0x00000018U, 0x09090004U);

        WR1_PROG(REG_1404H, 0x13980000U);
        r_rsip_func_sub001(0x00c00049U);

        r_rsip_func_sub002(0x00000890U, 0x000003e0U, 0x000002a0U, 0x09090009U);

        r_rsip_func_sub002(0x00000070U, 0x000003e0U, 0x000002f0U, 0x09090009U);

        static const uint32_t Param_func091_func100_002[] =
        {
            BSWAP_32BIG_C(0xbef74487U), BSWAP_32BIG_C(0x3ecd92e4U), BSWAP_32BIG_C(0x829a5c2dU), BSWAP_32BIG_C(
                0x0f6931f4U),
        };
        r_rsip_func100(Param_func091_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x09090015U, 0x00010001U);
        r_rsip_func_sub042(0x10c80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x000004d0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func091_func100_003[] =
        {
            BSWAP_32BIG_C(0x3791dc9bU), BSWAP_32BIG_C(0x610720b5U), BSWAP_32BIG_C(0xabc3a633U), BSWAP_32BIG_C(
                0xc07cba9aU),
        };
        r_rsip_func100(Param_func091_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func091_func101_007[] =
            {
                BSWAP_32BIG_C(0xe70b82fbU), BSWAP_32BIG_C(0xabf095caU), BSWAP_32BIG_C(0x49486f9cU), BSWAP_32BIG_C(
                    0xd6566215U),
            };
            r_rsip_func101(Param_func091_func101_007);
        }
        else
        {
            static const uint32_t Param_func091_func100_004[] =
            {
                BSWAP_32BIG_C(0xe7729f5cU), BSWAP_32BIG_C(0x26178a74U), BSWAP_32BIG_C(0xe18b5794U), BSWAP_32BIG_C(
                    0x09e90530U),
            };
            r_rsip_func100(Param_func091_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x09090015U, 0x00010001U);
            r_rsip_func_sub042(0x10c80000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func091_func100_005[] =
            {
                BSWAP_32BIG_C(0x38c5b2eaU), BSWAP_32BIG_C(0x0e5a6c1bU), BSWAP_32BIG_C(0xd1089241U), BSWAP_32BIG_C(
                    0x2860aa6dU),
            };
            r_rsip_func100(Param_func091_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func091_func101_008[] =
                {
                    BSWAP_32BIG_C(0x61164a14U), BSWAP_32BIG_C(0x67e2b504U), BSWAP_32BIG_C(0xb49689b2U), BSWAP_32BIG_C(
                        0x974b8da1U),
                };
                r_rsip_func101(Param_func091_func101_008);
            }
            else
            {
                static const uint32_t Param_func091_func100_006[] =
                {
                    BSWAP_32BIG_C(0x50e8870cU), BSWAP_32BIG_C(0x724b086bU), BSWAP_32BIG_C(0xf21fa813U), BSWAP_32BIG_C(
                        0xe3e7157cU),
                };
                r_rsip_func100(Param_func091_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x09090004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x000004d0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x00000520U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000520U, 0x09090002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub001(0x00c00049U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x000004d0U, 0x09090009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x09090004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                r_rsip_func_sub042(0x12a80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func091_func100_007[] =
                {
                    BSWAP_32BIG_C(0x6a964e25U), BSWAP_32BIG_C(0xc775c3a2U), BSWAP_32BIG_C(0xe504b19eU), BSWAP_32BIG_C(
                        0x57b3bfb0U),
                };
                r_rsip_func100(Param_func091_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func091_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x4bad2f29U), BSWAP_32BIG_C(0xa0d6cf16U), BSWAP_32BIG_C(0x02d82627U),
                        BSWAP_32BIG_C(0xbb1abb25U),
                    };
                    r_rsip_func101(Param_func091_func101_009);
                }
                else
                {
                    static const uint32_t Param_func091_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xfd18a6f6U), BSWAP_32BIG_C(0x4d152486U), BSWAP_32BIG_C(0x8006344eU),
                        BSWAP_32BIG_C(0x71cfccd3U),
                    };
                    r_rsip_func100(Param_func091_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c00045U);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    r_rsip_func_sub022(0x000001b0U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x09090002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000200U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x09090002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x313622d7U);

                    static const uint32_t Param_func091_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x9bce78ceU), BSWAP_32BIG_C(0xe8f9b531U), BSWAP_32BIG_C(0x769390ddU),
                        BSWAP_32BIG_C(0xefa73291U),
                    };
                    r_rsip_func101(Param_func091_func101_010);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x313622d7U, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
