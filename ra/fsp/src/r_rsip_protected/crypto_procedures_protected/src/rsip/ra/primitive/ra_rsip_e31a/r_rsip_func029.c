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

void r_rsip_func029 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t kLoop = 0U;

    r_rsip_func027(ARG1);

    WR1_PROG(REG_00A0H, 0x20010000U);

    WR1_PROG(REG_00B8H, 0x0000000eU);

    WR1_PROG(REG_00A4H, 0x06060010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub003(0x0000942aU, 0x00c0002dU, 0x00000001U);

    r_rsip_func_sub001(0x002a000eU, 0x001c0000U, 0x0606000aU);

    r_rsip_func_sub001(0x0093001cU, 0x00230000U, 0x0606000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x002a0093U, 0x00230000U, 0x0606000aU);
    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x009a001cU, 0x00230000U, 0x0606000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x002a009aU, 0x00230000U, 0x0606000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    static const uint32_t Param_func029_func100_001[] =
    {
        BSWAP_32BIG_C(0x1c9cd66aU), BSWAP_32BIG_C(0x6c0686dcU), BSWAP_32BIG_C(0x227f68afU), BSWAP_32BIG_C(0x9a49da99U),
    };
    r_rsip_func100(Param_func029_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func029_func101_001[] =
        {
            BSWAP_32BIG_C(0x8e7f2421U), BSWAP_32BIG_C(0x6ad18893U), BSWAP_32BIG_C(0x1d9f9f25U), BSWAP_32BIG_C(
                0xc38d01d1U),
        };
        r_rsip_func101(Param_func029_func101_001);
    }
    else
    {
        static const uint32_t Param_func029_func100_002[] =
        {
            BSWAP_32BIG_C(0x5fba907bU), BSWAP_32BIG_C(0x8e56b274U), BSWAP_32BIG_C(0xd1bd2dbfU), BSWAP_32BIG_C(
                0xe7af088cU),
        };
        r_rsip_func100(Param_func029_func100_002);

        r_rsip_func_sub001(0x002a001cU, 0x00230000U, 0x0606000aU);

        r_rsip_func_sub021(0x0023009aU, 0x0015000eU, 0x06060000U);
        r_rsip_func_sub020(0x20010001U, 0x00000001U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub001(0x007e0015U, 0x001c000eU, 0x06060002U);

        r_rsip_func_sub009(0x00009431U, 0x00c00031U, 0x00001800U);

        r_rsip_func_sub001(0x003100a1U, 0x00150000U, 0x06060009U);

        r_rsip_func_sub001(0x001c0015U, 0x0015000eU, 0x06060002U);

        r_rsip_func_sub001(0x001c0093U, 0x0046000eU, 0x06060002U);

        WR1_PROG(REG_00B8H, 0x00000007U);

        WR1_PROG(REG_00A4H, 0x06060010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x00310093U, 0x000e0000U, 0x06060009U);

        r_rsip_func_sub001(0x004d00a7U, 0x00690007U, 0x06060002U);

        r_rsip_func_sub001(0x004d00adU, 0x00700007U, 0x06060002U);

        r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000001U);

        r_rsip_func_sub001(0x001c004dU, 0x00770007U, 0x06060002U);

        r_rsip_func_sub001(0x00310085U, 0x00380000U, 0x06060009U);

        r_rsip_func_sub001(0x00310007U, 0x003f0000U, 0x06060009U);

        r_rsip_func_sub009(0x0000041dU, 0x00c00009U, 0x00001800U);

        r_rsip_func_sub009(0x00000424U, 0x00c00009U, 0x00001800U);
        r_rsip_func028(ARG1);

        r_rsip_func_sub001(0x00310023U, 0x007e0000U, 0x06060009U);

        r_rsip_func_sub001(0x0031002aU, 0x00850000U, 0x06060009U);

        r_rsip_func_sub001(0x00310077U, 0x008c0000U, 0x06060009U);

        r_rsip_func_sub001(0x0069007eU, 0x001c0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x007e0069U, 0x001c0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x00700085U, 0x001c0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x00850070U, 0x001c0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func029_func100_003[] =
        {
            BSWAP_32BIG_C(0x48479999U), BSWAP_32BIG_C(0x10fe0d30U), BSWAP_32BIG_C(0xb3f6f38eU), BSWAP_32BIG_C(
                0xf9ba9f81U),
        };
        r_rsip_func100(Param_func029_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x0077008cU, 0x00a10007U, 0x06060013U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func029_func101_002[] =
            {
                BSWAP_32BIG_C(0x059b1185U), BSWAP_32BIG_C(0xba56f272U), BSWAP_32BIG_C(0x33af6f5dU), BSWAP_32BIG_C(
                    0xcbe66441U),
            };
            r_rsip_func101(Param_func029_func101_002);
        }
        else
        {
            r_rsip_func_sub001(0x0000008cU, 0x00a1003fU, 0x06060014U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func029_func101_003[] =
            {
                BSWAP_32BIG_C(0x859c8251U), BSWAP_32BIG_C(0xfe7fdb56U), BSWAP_32BIG_C(0x64897002U), BSWAP_32BIG_C(
                    0xa48c8e30U),
            };
            r_rsip_func101(Param_func029_func101_003);
        }

        r_rsip_func_sub001(0x00310015U, 0x004d0000U, 0x06060009U);

        r_rsip_func_sub001(0x00230023U, 0x00230000U, 0x0606000aU);

        r_rsip_func_sub001(0x002a002aU, 0x002a0000U, 0x0606000aU);

        r_rsip_func_sub001(0x00310031U, 0x00310000U, 0x0606000aU);

        WR1_PROG(REG_0094H, 0x00000800U);
        for (iLoop = 0U; iLoop < 3U; iLoop++)
        {
            static const uint32_t Param_func029_func100_004[] =
            {
                BSWAP_32BIG_C(0xa7a8cb90U), BSWAP_32BIG_C(0x895fa2c6U), BSWAP_32BIG_C(0xb7c2d34dU), BSWAP_32BIG_C(
                    0x4b5f143aU),
            };
            r_rsip_func100(Param_func029_func100_004);
            WR1_PROG(REG_0094H, 0x000008a5U);

            WR1_PROG(REG_0094H, 0x00007c00U);
            WR1_PROG(REG_0040H, 0x00600000U);

            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
            {
                WR1_PROG(REG_00B0H, 0x00000848U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000849U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000841U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000842U);
                r_rsip_func_sub012(0x80820005U, 0x03430009U);

                static const uint32_t Param_func029_func101_004[] =
                {
                    BSWAP_32BIG_C(0x357bdc1bU), BSWAP_32BIG_C(0x02a7d11aU), BSWAP_32BIG_C(0xd882cc36U), BSWAP_32BIG_C(
                        0x8fc37427U),
                };
                r_rsip_func101(Param_func029_func101_004);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
            {
                WR1_PROG(REG_00B0H, 0x0000084aU);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x0000084bU);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000843U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000844U);
                r_rsip_func_sub012(0x80820005U, 0x03430009U);

                static const uint32_t Param_func029_func101_005[] =
                {
                    BSWAP_32BIG_C(0xfc5cc89bU), BSWAP_32BIG_C(0x20bee20eU), BSWAP_32BIG_C(0x8e6bc75eU), BSWAP_32BIG_C(
                        0xe2821838U),
                };
                r_rsip_func101(Param_func029_func101_005);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
            {
                WR1_PROG(REG_00B0H, 0x0000084cU);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x0000084dU);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000845U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000846U);
                r_rsip_func_sub012(0x80820005U, 0x03430009U);

                static const uint32_t Param_func029_func101_006[] =
                {
                    BSWAP_32BIG_C(0xae28d97dU), BSWAP_32BIG_C(0xb59bddd6U), BSWAP_32BIG_C(0x09386c63U), BSWAP_32BIG_C(
                        0xeba677c4U),
                };
                r_rsip_func101(Param_func029_func101_006);
            }

            WR1_PROG(REG_0094H, 0x00000821U);

            for (jLoop = 0U; jLoop < 4; jLoop++)
            {
                r_rsip_func_sub022(0x000034a1U, 0x00026ca5U, 0x00003865U);

                r_rsip_func_sub022(0x0000a4a0U, 0x00000010U, 0x00003885U);

                WR1_PROG(REG_0094H, 0x00000842U);

                for (kLoop = 0U; kLoop < 32U; kLoop++)
                {
                    r_rsip_func_sub022(0x000008a5U, 0x01816ca3U, 0x01816ca4U);
                    WR1_PROG(REG_0094H, 0x00016c63U);
                    WR1_PROG(REG_0094H, 0x00016c84U);

                    r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000001U);

                    r_rsip_func_sub001(0x001c0023U, 0x00150000U, 0x0606000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    r_rsip_func_sub001(0x001c0031U, 0x00150000U, 0x0606000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    static const uint32_t Param_func029_func100_005[] =
                    {
                        BSWAP_32BIG_C(0xb1340d49U), BSWAP_32BIG_C(0xc14f9913U), BSWAP_32BIG_C(0x38eae8bfU),
                        BSWAP_32BIG_C(0x7d5d1ba8U),
                    };
                    r_rsip_func100(Param_func029_func100_005);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub001(0x00000031U, 0x0031003fU, 0x06060014U);
                        WR1_PROG(REG_0040H, 0x00000d00U);

                        static const uint32_t Param_func029_func101_007[] =
                        {
                            BSWAP_32BIG_C(0xdba42418U), BSWAP_32BIG_C(0x5fdc197cU), BSWAP_32BIG_C(0x4aea159aU),
                            BSWAP_32BIG_C(0xf4f70e6bU),
                        };
                        r_rsip_func101(Param_func029_func101_007);
                    }
                    else
                    {
                        static const uint32_t Param_func029_func101_008[] =
                        {
                            BSWAP_32BIG_C(0x00c468d8U), BSWAP_32BIG_C(0x194187caU), BSWAP_32BIG_C(0xfb4d1db0U),
                            BSWAP_32BIG_C(0x6ab259d1U),
                        };
                        r_rsip_func101(Param_func029_func101_008);
                    }

                    r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00A70000U);

                    static const uint32_t Param_func029_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x6053e84cU), BSWAP_32BIG_C(0x804f5a96U), BSWAP_32BIG_C(0xeda2756eU),
                        BSWAP_32BIG_C(0x309f2cd1U),
                    };
                    r_rsip_func100(Param_func029_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_func029_func100_007[] =
                        {
                            BSWAP_32BIG_C(0x830b05edU), BSWAP_32BIG_C(0xfb2539cfU), BSWAP_32BIG_C(0xb76091bfU),
                            BSWAP_32BIG_C(0x61325be1U),
                        };
                        r_rsip_func100(Param_func029_func100_007);

                        r_rsip_func_sub009(0x0000941cU, 0x00c00031U, 0x00001800U);

                        WR1_PROG(REG_0094H, 0x00007c05U);
                        WR1_PROG(REG_0040H, 0x00600000U);

                        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub001(0x001c0069U, 0x00540000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c0070U, 0x005b0000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c0077U, 0x00620000U, 0x06060009U);

                            static const uint32_t Param_func029_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x40f6d1c7U), BSWAP_32BIG_C(0x5248f83aU), BSWAP_32BIG_C(0x0aca5d41U),
                                BSWAP_32BIG_C(0xaa5bf654U),
                            };
                            r_rsip_func101(Param_func029_func101_009);
                        }
                        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub001(0x001c007eU, 0x00540000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c0085U, 0x005b0000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c008cU, 0x00620000U, 0x06060009U);

                            static const uint32_t Param_func029_func101_010[] =
                            {
                                BSWAP_32BIG_C(0xc83a25e9U), BSWAP_32BIG_C(0xfc99de22U), BSWAP_32BIG_C(0x3e05b138U),
                                BSWAP_32BIG_C(0x9f48c140U),
                            };
                            r_rsip_func101(Param_func029_func101_010);
                        }
                        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub001(0x001c0093U, 0x00540000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c009aU, 0x005b0000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c00a1U, 0x00620000U, 0x06060009U);

                            static const uint32_t Param_func029_func101_011[] =
                            {
                                BSWAP_32BIG_C(0xae850568U), BSWAP_32BIG_C(0xae6ecedaU), BSWAP_32BIG_C(0xe17c35e5U),
                                BSWAP_32BIG_C(0xf5deb148U),
                            };
                            r_rsip_func101(Param_func029_func101_011);
                        }

                        r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000001U);

                        r_rsip_func_sub001(0x001c0023U, 0x00150000U, 0x0606000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        r_rsip_func_sub001(0x001c0031U, 0x00150000U, 0x0606000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        static const uint32_t Param_func029_func100_008[] =
                        {
                            BSWAP_32BIG_C(0xfec61ac8U), BSWAP_32BIG_C(0x791d1f57U), BSWAP_32BIG_C(0xd424b15cU),
                            BSWAP_32BIG_C(0x9d4ef2d9U),
                        };
                        r_rsip_func100(Param_func029_func100_008);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            r_rsip_func_sub001(0x001c0054U, 0x00150000U, 0x0606000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            r_rsip_func_sub001(0x001c0062U, 0x00150000U, 0x0606000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            static const uint32_t Param_func029_func100_009[] =
                            {
                                BSWAP_32BIG_C(0xba3a1b1dU), BSWAP_32BIG_C(0xaf721cb7U), BSWAP_32BIG_C(0x07f77197U),
                                BSWAP_32BIG_C(0x7b8c89c5U),
                            };
                            r_rsip_func100(Param_func029_func100_009);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub001(0x00540023U, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x00230054U, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x005b002aU, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x002a005bU, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x00620031U, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x00310062U, 0x00150000U, 0x0606000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                static const uint32_t Param_func029_func100_010[] =
                                {
                                    BSWAP_32BIG_C(0x2021f60aU), BSWAP_32BIG_C(0x1ebeb1a2U), BSWAP_32BIG_C(0x1a07aa53U),
                                    BSWAP_32BIG_C(0xc6f79d47U),
                                };
                                r_rsip_func100(Param_func029_func100_010);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub001(0x00620031U, 0x00310007U, 0x06060013U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func029_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x62b326a7U), BSWAP_32BIG_C(0x25ed0afcU), BSWAP_32BIG_C(
                                            0x82e367e5U),           BSWAP_32BIG_C(0xc8fd333cU),
                                    };
                                    r_rsip_func101(Param_func029_func101_012);
                                }
                                else
                                {
                                    r_rsip_func_sub001(0x00000031U, 0x0031003fU, 0x06060014U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func029_func101_013[] =
                                    {
                                        BSWAP_32BIG_C(0xd24a2374U), BSWAP_32BIG_C(0x06cee0d3U), BSWAP_32BIG_C(
                                            0x47eff067U),           BSWAP_32BIG_C(0xabb08c1eU),
                                    };
                                    r_rsip_func101(Param_func029_func101_013);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_func029_func101_014[] =
                                {
                                    BSWAP_32BIG_C(0xbc5b0905U), BSWAP_32BIG_C(0xd8f18706U), BSWAP_32BIG_C(0x1f48e8c5U),
                                    BSWAP_32BIG_C(0x652bd716U),
                                };
                                r_rsip_func101(Param_func029_func101_014);
                            }
                        }
                        else
                        {
                            r_rsip_func_sub009(0x0000941cU, 0x00c00031U, 0x00001800U);

                            r_rsip_func_sub001(0x001c0054U, 0x00230000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c005bU, 0x002a0000U, 0x06060009U);

                            r_rsip_func_sub001(0x001c0062U, 0x00310000U, 0x06060009U);

                            static const uint32_t Param_func029_func101_015[] =
                            {
                                BSWAP_32BIG_C(0x6bea40b5U), BSWAP_32BIG_C(0x5d32cc36U), BSWAP_32BIG_C(0xd064339fU),
                                BSWAP_32BIG_C(0x20f18b97U),
                            };
                            r_rsip_func101(Param_func029_func101_015);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_func029_func101_016[] =
                        {
                            BSWAP_32BIG_C(0xff2792c3U), BSWAP_32BIG_C(0x812a6ef7U), BSWAP_32BIG_C(0xd033b03bU),
                            BSWAP_32BIG_C(0x2ef27adaU),
                        };
                        r_rsip_func101(Param_func029_func101_016);
                    }

                    WR1_PROG(REG_0094H, 0x00002c40U);
                    static const uint32_t Param_func029_func101_017[] =
                    {
                        BSWAP_32BIG_C(0x4f9fc63eU), BSWAP_32BIG_C(0x2f82ec8cU), BSWAP_32BIG_C(0xfe3015acU),
                        BSWAP_32BIG_C(0x68129f4eU),
                    };
                    r_rsip_func101(Param_func029_func101_017);
                }

                r_rsip_func_sub010(0x38008840U, 0x00000020U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00002c20U);

                static const uint32_t Param_func029_func101_018[] =
                {
                    BSWAP_32BIG_C(0x18d83ee5U), BSWAP_32BIG_C(0x12d8dae2U), BSWAP_32BIG_C(0x7580ebb2U), BSWAP_32BIG_C(
                        0xc8f88c8bU),
                };
                r_rsip_func101(Param_func029_func101_018);
            }

            r_rsip_func_sub010(0x38008820U, 0x00000004U, 0x00270000U);

            WR1_PROG(REG_0040H, 0x00402000U);

            WR1_PROG(REG_0094H, 0x00002c00U);

            static const uint32_t Param_func029_func101_019[] =
            {
                BSWAP_32BIG_C(0x3d8e7e91U), BSWAP_32BIG_C(0xe3c03935U), BSWAP_32BIG_C(0xfeebbf11U), BSWAP_32BIG_C(
                    0x2ed92729U),
            };
            r_rsip_func101(Param_func029_func101_019);
        }

        r_rsip_func_sub010(0x38008800U, 0x00000003U, 0x00270000U);

        WR1_PROG(REG_0040H, 0x00402000U);

        r_rsip_func_sub009(0x0000941cU, 0x00c00031U, 0x00001800U);

        r_rsip_func_sub001(0x001c000eU, 0x00930000U, 0x06060009U);

        r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000001U);

        r_rsip_func_sub001(0x001c0031U, 0x003f0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func029_func100_011[] =
        {
            BSWAP_32BIG_C(0xfcce7918U), BSWAP_32BIG_C(0x723f11ccU), BSWAP_32BIG_C(0x0c065489U), BSWAP_32BIG_C(
                0xe4708d2eU),
        };
        r_rsip_func100(Param_func029_func100_011);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func029_func101_020[] =
            {
                BSWAP_32BIG_C(0x87f139a6U), BSWAP_32BIG_C(0xd584f906U), BSWAP_32BIG_C(0x89f8b7a4U), BSWAP_32BIG_C(
                    0x0b6bd1efU),
            };
            r_rsip_func101(Param_func029_func101_020);
        }
        else
        {
            static const uint32_t Param_func029_func100_012[] =
            {
                BSWAP_32BIG_C(0xcbf8c725U), BSWAP_32BIG_C(0x35c02352U), BSWAP_32BIG_C(0x811cbd1fU), BSWAP_32BIG_C(
                    0x7c500d8bU),
            };
            r_rsip_func100(Param_func029_func100_012);

            r_rsip_func_sub001(0x001c0031U, 0x00380007U, 0x06060002U);

            r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000002U);

            r_rsip_func_sub001(0x001c0007U, 0x00150000U, 0x0606000aU);

            r_rsip_func_sub021(0x00150038U, 0x001c0007U, 0x06060000U);
            r_rsip_func_sub020(0x20010001U, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x001c0023U, 0x00380007U, 0x06060002U);

            r_rsip_func_sub001(0x00930038U, 0x00230000U, 0x0606000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            r_rsip_func_sub001(0x00380093U, 0x00230000U, 0x0606000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func029_func100_013[] =
            {
                BSWAP_32BIG_C(0x90fe9cc9U), BSWAP_32BIG_C(0x2835c704U), BSWAP_32BIG_C(0xef5881aaU), BSWAP_32BIG_C(
                    0x33f71106U),
            };
            r_rsip_func100(Param_func029_func100_013);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func029_func101_021[] =
                {
                    BSWAP_32BIG_C(0xd8778b32U), BSWAP_32BIG_C(0x65ecb25cU), BSWAP_32BIG_C(0xc01b8c84U), BSWAP_32BIG_C(
                        0x772ea7a6U),
                };
                r_rsip_func101(Param_func029_func101_021);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b400U);
                WR1_PROG(REG_0094H, 0xbf434bdeU);

                static const uint32_t Param_func029_func101_022[] =
                {
                    BSWAP_32BIG_C(0xe1ec7e83U), BSWAP_32BIG_C(0x86bdd3efU), BSWAP_32BIG_C(0x344509abU), BSWAP_32BIG_C(
                        0xd820076bU),
                };
                r_rsip_func101(Param_func029_func101_022);
            }
        }
    }

    r_rsip_func_sub010(0x38008800U, 0xbf434bdeU, 0x00A70000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
