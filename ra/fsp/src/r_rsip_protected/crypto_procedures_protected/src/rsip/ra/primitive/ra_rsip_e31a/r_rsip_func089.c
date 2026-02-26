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

void r_rsip_func089 (void)
{
    static const uint32_t Param_func089_func100_001[] =
    {
        BSWAP_32BIG_C(0xa081619aU), BSWAP_32BIG_C(0x669f173bU), BSWAP_32BIG_C(0xcc7cae79U), BSWAP_32BIG_C(0x09688aa3U),
    };
    r_rsip_func100(Param_func089_func100_001);

    WR1_PROG(REG_00A0H, 0x20010000U);
    r_rsip_func103();
    static const uint32_t Param_func089_func100_002[] =
    {
        BSWAP_32BIG_C(0xf468b22aU), BSWAP_32BIG_C(0x2e9e36b6U), BSWAP_32BIG_C(0x85b97e0dU), BSWAP_32BIG_C(0xf4d4db03U),
    };
    r_rsip_func100(Param_func089_func100_002);
    WR1_PROG(REG_00B0H, 0x00009415U);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_func089_func100_003[] =
    {
        BSWAP_32BIG_C(0xdda97fa1U), BSWAP_32BIG_C(0x65d8f083U), BSWAP_32BIG_C(0x4e0544fbU), BSWAP_32BIG_C(0x283f8a4eU),
    };
    r_rsip_func100(Param_func089_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x00009438U, 0x00c0002dU, 0x00000001U);

    r_rsip_func_sub003(0x0000943fU, 0x00c0002dU, 0x00000002U);

    r_rsip_func_sub001(0x003f000eU, 0x001c0000U, 0x0606000aU);

    WR1_PROG(REG_00B8H, 0x0000001cU);

    WR1_PROG(REG_00A4H, 0x06060010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub001(0x00380015U, 0x0031001cU, 0x06060002U);

    r_rsip_func_sub001(0x00380031U, 0x001c0000U, 0x06060009U);

    r_rsip_func_sub001(0x001c0046U, 0x0015000eU, 0x06060005U);

    r_rsip_func_sub001(0x00380015U, 0x003f0000U, 0x0606000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    static const uint32_t Param_func089_func100_004[] =
    {
        BSWAP_32BIG_C(0xde782a88U), BSWAP_32BIG_C(0xc7bb9f39U), BSWAP_32BIG_C(0x474433d8U), BSWAP_32BIG_C(0x04e0c1e2U),
    };
    r_rsip_func100(Param_func089_func100_004);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func089_func101_001[] =
        {
            BSWAP_32BIG_C(0x811db785U), BSWAP_32BIG_C(0xc41ee48dU), BSWAP_32BIG_C(0xe70d779dU), BSWAP_32BIG_C(
                0x64f2ca5aU),
        };
        r_rsip_func101(Param_func089_func101_001);
    }
    else
    {
        static const uint32_t Param_func089_func100_005[] =
        {
            BSWAP_32BIG_C(0x1dc28ce3U), BSWAP_32BIG_C(0x5e5ba176U), BSWAP_32BIG_C(0x4f1fceadU), BSWAP_32BIG_C(
                0xf91eace0U),
        };
        r_rsip_func100(Param_func089_func100_005);
        WR1_PROG(REG_00B8H, 0x00000007U);

        WR1_PROG(REG_00A4H, 0x06060010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x0038004dU, 0x00310007U, 0x06060002U);

        r_rsip_func_sub009(0x00009454U, 0x00c00031U, 0x00001800U);

        r_rsip_func_sub001(0x00540085U, 0x00380000U, 0x06060009U);

        r_rsip_func_sub001(0x00540007U, 0x003f0000U, 0x06060009U);

        r_rsip_func_sub001(0x00150031U, 0x0062003fU, 0x06060015U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub003(0x00009415U, 0x00c0002dU, 0x00000001U);

        r_rsip_func_sub001(0x00150062U, 0x00690000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func089_func100_006[] =
        {
            BSWAP_32BIG_C(0x553cd13cU), BSWAP_32BIG_C(0x1404e71aU), BSWAP_32BIG_C(0x44a272e0U), BSWAP_32BIG_C(
                0x5b166ff8U),
        };
        r_rsip_func100(Param_func089_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func089_func101_002[] =
            {
                BSWAP_32BIG_C(0x14e4b3a8U), BSWAP_32BIG_C(0x7e7f27daU), BSWAP_32BIG_C(0x2d40fb28U), BSWAP_32BIG_C(
                    0xd03669d8U),
            };
            r_rsip_func101(Param_func089_func101_002);
        }
        else
        {
            static const uint32_t Param_func089_func100_007[] =
            {
                BSWAP_32BIG_C(0x2237ea98U), BSWAP_32BIG_C(0xac1f5bcdU), BSWAP_32BIG_C(0xe2b4a0baU), BSWAP_32BIG_C(
                    0x7ba1018eU),
            };
            r_rsip_func100(Param_func089_func100_007);
            r_rsip_func_sub001(0x001c0031U, 0x0077003fU, 0x06060015U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub003(0x00009415U, 0x00c0002dU, 0x00000001U);

            r_rsip_func_sub001(0x00150077U, 0x00230000U, 0x0606000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func089_func100_008[] =
            {
                BSWAP_32BIG_C(0x5d2c0b68U), BSWAP_32BIG_C(0xcd7d8497U), BSWAP_32BIG_C(0x69f433bcU), BSWAP_32BIG_C(
                    0xeac95009U),
            };
            r_rsip_func100(Param_func089_func100_008);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func089_func101_003[] =
                {
                    BSWAP_32BIG_C(0x0f99e57eU), BSWAP_32BIG_C(0xc33fe2a4U), BSWAP_32BIG_C(0x6bd96190U), BSWAP_32BIG_C(
                        0x5010b874U),
                };
                r_rsip_func101(Param_func089_func101_003);
            }
            else
            {
                static const uint32_t Param_func089_func100_009[] =
                {
                    BSWAP_32BIG_C(0x0061e522U), BSWAP_32BIG_C(0x8e4aa423U), BSWAP_32BIG_C(0xe2102d6cU), BSWAP_32BIG_C(
                        0xdc6d8e0fU),
                };
                r_rsip_func100(Param_func089_func100_009);
                r_rsip_func_sub001(0x00150077U, 0x00310007U, 0x06060002U);

                r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000002U);

                r_rsip_func_sub001(0x001c0007U, 0x00150000U, 0x0606000aU);

                r_rsip_func_sub021(0x00150031U, 0x001c0007U, 0x06060000U);
                r_rsip_func_sub020(0x20010001U, 0x00000001U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x001c0069U, 0x00230007U, 0x06060002U);

                r_rsip_func_sub001(0x001c0070U, 0x002a0007U, 0x06060002U);

                r_rsip_func_sub001(0x002a0007U, 0x00150000U, 0x0606000aU);

                r_rsip_func_sub001(0x004d0015U, 0x00700007U, 0x06060002U);

                r_rsip_func_sub001(0x004d0023U, 0x00150007U, 0x06060002U);

                r_rsip_func_sub009(0x0000941cU, 0x00c00031U, 0x00001800U);

                r_rsip_func_sub001(0x001c0015U, 0x00690000U, 0x06060009U);

                r_rsip_func_sub003(0x0000943fU, 0x00c0002dU, 0x00000001U);

                r_rsip_func_sub001(0x003f004dU, 0x00770007U, 0x06060002U);

                r_rsip_func_sub001(0x00770062U, 0x00310007U, 0x06060013U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x003f0031U, 0x00380000U, 0x0606000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_func089_func100_010[] =
                {
                    BSWAP_32BIG_C(0x842b8b98U), BSWAP_32BIG_C(0x51f03565U), BSWAP_32BIG_C(0xee186ad5U), BSWAP_32BIG_C(
                        0x7f58c3c6U),
                };
                r_rsip_func100(Param_func089_func100_010);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x00000800U);

                    static const uint32_t Param_func089_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xbae88fddU), BSWAP_32BIG_C(0x3049eb7eU), BSWAP_32BIG_C(0x887bef8fU),
                        BSWAP_32BIG_C(0x620acad0U),
                    };
                    r_rsip_func101(Param_func089_func101_004);
                }
                else
                {
                    static const uint32_t Param_func089_func100_011[] =
                    {
                        BSWAP_32BIG_C(0xa25f3780U), BSWAP_32BIG_C(0xe55a5a12U), BSWAP_32BIG_C(0x0020ca57U),
                        BSWAP_32BIG_C(0xe89bc7baU),
                    };
                    r_rsip_func100(Param_func089_func100_011);
                    r_rsip_func_sub001(0x003f0031U, 0x00380007U, 0x06060002U);

                    r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000002U);

                    r_rsip_func_sub001(0x001c0007U, 0x00150000U, 0x0606000aU);

                    r_rsip_func_sub021(0x00150038U, 0x001c0007U, 0x06060000U);
                    r_rsip_func_sub020(0x20010001U, 0x00000001U);
                    WR1_PROG(REG_0040H, 0x00000d00U);

                    r_rsip_func_sub001(0x001c0023U, 0x00380007U, 0x06060002U);

                    r_rsip_func_sub001(0x001c002aU, 0x003f0007U, 0x06060002U);

                    WR1_PROG(REG_0094H, 0x0000b400U);
                    WR1_PROG(REG_0094H, 0x4390e124U);

                    static const uint32_t Param_func089_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x5d4eb789U), BSWAP_32BIG_C(0x2bc43ebbU), BSWAP_32BIG_C(0xdfe12b4dU),
                        BSWAP_32BIG_C(0x0a6634fdU),
                    };
                    r_rsip_func101(Param_func089_func101_005);
                }
            }
        }
    }

    r_rsip_func_sub010(0x38008800U, 0x4390e124U, 0x00A70000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
