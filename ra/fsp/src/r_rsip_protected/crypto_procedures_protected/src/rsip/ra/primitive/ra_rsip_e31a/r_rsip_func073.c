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

void r_rsip_func073 (const uint32_t ARG1[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t kLoop = 0U;

    r_rsip_func070(ARG1);

    WR1_PROG(REG_00A0H, 0x20010000U);

    WR1_PROG(REG_00B8H, 0x0000000aU);

    WR1_PROG(REG_00A4H, 0x04040010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub003(0x0000141eU, 0x00c0001dU, 0x00000001U);

    r_rsip_func_sub001(0x001e000aU, 0x00140000U, 0x0404000aU);

    r_rsip_func_sub001(0x00690014U, 0x00190000U, 0x0404000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x001e0069U, 0x00190000U, 0x0404000aU);
    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x006e0014U, 0x00190000U, 0x0404000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    r_rsip_func_sub001(0x001e006eU, 0x00190000U, 0x0404000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    static const uint32_t Param_func073_func100_001[] =
    {
        BSWAP_32BIG_C(0xe4799c35U), BSWAP_32BIG_C(0xd1908904U), BSWAP_32BIG_C(0x9aa829f3U), BSWAP_32BIG_C(0x0854254eU),
    };
    r_rsip_func100(Param_func073_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func073_func101_001[] =
        {
            BSWAP_32BIG_C(0x6d1308c3U), BSWAP_32BIG_C(0x4aea4cb8U), BSWAP_32BIG_C(0xa09420a1U), BSWAP_32BIG_C(
                0x1180f75eU),
        };
        r_rsip_func101(Param_func073_func101_001);
    }
    else
    {
        static const uint32_t Param_func073_func100_002[] =
        {
            BSWAP_32BIG_C(0x2e28b8e1U), BSWAP_32BIG_C(0xfd407768U), BSWAP_32BIG_C(0x98e2e591U), BSWAP_32BIG_C(
                0xae0b992aU),
        };
        r_rsip_func100(Param_func073_func100_002);

        r_rsip_func_sub001(0x001e0014U, 0x00190000U, 0x0404000aU);

        r_rsip_func_sub021(0x0019006eU, 0x000f000aU, 0x04040000U);
        r_rsip_func_sub020(0x20010001U, 0x00000001U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub001(0x005a000fU, 0x0014000aU, 0x04040002U);

        r_rsip_func_sub009(0x00001423U, 0x00c00021U, 0x00001800U);

        r_rsip_func_sub001(0x0023007eU, 0x000f0000U, 0x04040009U);

        r_rsip_func_sub001(0x0014000fU, 0x000f000aU, 0x04040002U);

        r_rsip_func_sub001(0x00140069U, 0x0032000aU, 0x04040002U);

        WR1_PROG(REG_00B8H, 0x00000005U);

        WR1_PROG(REG_00A4H, 0x04040010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x00230069U, 0x000a0000U, 0x04040009U);

        r_rsip_func_sub001(0x00370076U, 0x004b0005U, 0x04040002U);

        r_rsip_func_sub001(0x0037007aU, 0x00500005U, 0x04040002U);

        r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000001U);

        r_rsip_func_sub001(0x00140037U, 0x00550005U, 0x04040002U);

        r_rsip_func_sub001(0x0023005fU, 0x00280000U, 0x04040009U);

        r_rsip_func_sub001(0x00230005U, 0x002d0000U, 0x04040009U);

        r_rsip_func_sub009(0x00000415U, 0x00c00009U, 0x00001800U);

        r_rsip_func_sub009(0x0000041aU, 0x00c00009U, 0x00001800U);
        r_rsip_func071(ARG1);

        r_rsip_func_sub001(0x00230019U, 0x005a0000U, 0x04040009U);

        r_rsip_func_sub001(0x0023001eU, 0x005f0000U, 0x04040009U);

        r_rsip_func_sub001(0x00230055U, 0x00640000U, 0x04040009U);

        r_rsip_func_sub009(0x0000046fU, 0x00c00009U, 0x00001800U);

        r_rsip_func_sub001(0x004b005aU, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x005a004bU, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x0050005fU, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        r_rsip_func_sub001(0x005f0050U, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func073_func100_003[] =
        {
            BSWAP_32BIG_C(0x72552dbeU), BSWAP_32BIG_C(0xa0b5d9b1U), BSWAP_32BIG_C(0x9f03ecfeU), BSWAP_32BIG_C(
                0xde061076U),
        };
        r_rsip_func100(Param_func073_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x00550064U, 0x00730005U, 0x04040013U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func073_func101_002[] =
            {
                BSWAP_32BIG_C(0xa75674f8U), BSWAP_32BIG_C(0x559f161dU), BSWAP_32BIG_C(0xb5989385U), BSWAP_32BIG_C(
                    0x356621dbU),
            };
            r_rsip_func101(Param_func073_func101_002);
        }
        else
        {
            r_rsip_func_sub001(0x00000064U, 0x0073002dU, 0x04040014U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func073_func101_003[] =
            {
                BSWAP_32BIG_C(0xe757df62U), BSWAP_32BIG_C(0x0ddb49d9U), BSWAP_32BIG_C(0x70e52916U), BSWAP_32BIG_C(
                    0x1852d2dfU),
            };
            r_rsip_func101(Param_func073_func101_003);
        }

        r_rsip_func_sub001(0x0023000fU, 0x00370000U, 0x04040009U);

        r_rsip_func_sub001(0x00190019U, 0x00190000U, 0x0404000aU);

        r_rsip_func_sub001(0x001e001eU, 0x001e0000U, 0x0404000aU);

        r_rsip_func_sub001(0x00230023U, 0x00230000U, 0x0404000aU);

        WR1_PROG(REG_0094H, 0x00000800U);
        for (iLoop = 0U; iLoop < 2U; iLoop++)
        {
            r_rsip_func_sub010(0x000008a5U, 0x38000c00U, 0x00270000U);

            static const uint32_t Param_func073_func100_004[] =
            {
                BSWAP_32BIG_C(0x3a05bea8U), BSWAP_32BIG_C(0x768d99b3U), BSWAP_32BIG_C(0x720acd1eU), BSWAP_32BIG_C(
                    0x2dd1efe2U),
            };
            r_rsip_func100(Param_func073_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_00B0H, 0x00000834U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000835U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x0000082fU);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000830U);
                r_rsip_func_sub012(0x80820005U, 0x03430009U);

                static const uint32_t Param_func073_func101_004[] =
                {
                    BSWAP_32BIG_C(0xd7b36b3fU), BSWAP_32BIG_C(0x56a8eb98U), BSWAP_32BIG_C(0xcd9e01bbU), BSWAP_32BIG_C(
                        0xb68e57bdU),
                };
                r_rsip_func101(Param_func073_func101_004);
            }
            else
            {
                WR1_PROG(REG_00B0H, 0x00000836U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000837U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000831U);
                r_rsip_func_sub006(0x80820005U, 0x03430009U, 0x0000a4a0U, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000832U);
                r_rsip_func_sub012(0x80820005U, 0x03430009U);

                static const uint32_t Param_func073_func101_005[] =
                {
                    BSWAP_32BIG_C(0xe90e8014U), BSWAP_32BIG_C(0xbc68f990U), BSWAP_32BIG_C(0x0d597c9bU), BSWAP_32BIG_C(
                        0x604d1b6dU),
                };
                r_rsip_func101(Param_func073_func101_005);
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

                    r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000001U);

                    r_rsip_func_sub001(0x00140019U, 0x000f0000U, 0x0404000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    r_rsip_func_sub001(0x00140023U, 0x000f0000U, 0x0404000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    static const uint32_t Param_func073_func100_005[] =
                    {
                        BSWAP_32BIG_C(0x7b46f476U), BSWAP_32BIG_C(0xa47f8404U), BSWAP_32BIG_C(0x20f8574cU),
                        BSWAP_32BIG_C(0x2060d2bfU),
                    };
                    r_rsip_func100(Param_func073_func100_005);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub001(0x00000023U, 0x0023002dU, 0x04040014U);
                        WR1_PROG(REG_0040H, 0x00000d00U);

                        static const uint32_t Param_func073_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x7ddf3913U), BSWAP_32BIG_C(0xb15f5ca8U), BSWAP_32BIG_C(0x4c7def48U),
                            BSWAP_32BIG_C(0x4e8abd62U),
                        };
                        r_rsip_func101(Param_func073_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_func073_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x9e766aa6U), BSWAP_32BIG_C(0x90f35ebeU), BSWAP_32BIG_C(0xa9205c65U),
                            BSWAP_32BIG_C(0xb7c88365U),
                        };
                        r_rsip_func101(Param_func073_func101_007);
                    }

                    r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00A70000U);

                    static const uint32_t Param_func073_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x81a1e390U), BSWAP_32BIG_C(0xe52817dfU), BSWAP_32BIG_C(0xc018ac9dU),
                        BSWAP_32BIG_C(0xef19d160U),
                    };
                    r_rsip_func100(Param_func073_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_func073_func100_007[] =
                        {
                            BSWAP_32BIG_C(0x7053f177U), BSWAP_32BIG_C(0xcb75b0b6U), BSWAP_32BIG_C(0x153201b9U),
                            BSWAP_32BIG_C(0x975a4f81U),
                        };
                        r_rsip_func100(Param_func073_func100_007);

                        r_rsip_func_sub009(0x00001414U, 0x00c00021U, 0x00001800U);

                        WR1_PROG(REG_0094H, 0x00007c05U);
                        WR1_PROG(REG_0040H, 0x00600000U);

                        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub001(0x0014004bU, 0x003c0000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140050U, 0x00410000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140055U, 0x00460000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_008[] =
                            {
                                BSWAP_32BIG_C(0xa3051ea0U), BSWAP_32BIG_C(0x29317afdU), BSWAP_32BIG_C(0x7f31aec0U),
                                BSWAP_32BIG_C(0xd46c175dU),
                            };
                            r_rsip_func101(Param_func073_func101_008);
                        }
                        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub001(0x0014005aU, 0x003c0000U, 0x04040009U);

                            r_rsip_func_sub001(0x0014005fU, 0x00410000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140064U, 0x00460000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_009[] =
                            {
                                BSWAP_32BIG_C(0xa03aed2bU), BSWAP_32BIG_C(0x4b9c8da6U), BSWAP_32BIG_C(0x8d7037efU),
                                BSWAP_32BIG_C(0xae729e27U),
                            };
                            r_rsip_func101(Param_func073_func101_009);
                        }
                        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub001(0x00140069U, 0x003c0000U, 0x04040009U);

                            r_rsip_func_sub001(0x0014006eU, 0x00410000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140073U, 0x00460000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x8ef7d770U), BSWAP_32BIG_C(0x44fea75aU), BSWAP_32BIG_C(0x89b332cdU),
                                BSWAP_32BIG_C(0x8d31afdeU),
                            };
                            r_rsip_func101(Param_func073_func101_010);
                        }

                        r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000001U);

                        r_rsip_func_sub001(0x00140019U, 0x000f0000U, 0x0404000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        r_rsip_func_sub001(0x00140023U, 0x000f0000U, 0x0404000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        static const uint32_t Param_func073_func100_008[] =
                        {
                            BSWAP_32BIG_C(0xdf2b9ee7U), BSWAP_32BIG_C(0xca103e5dU), BSWAP_32BIG_C(0x54f52d59U),
                            BSWAP_32BIG_C(0x22dcad63U),
                        };
                        r_rsip_func100(Param_func073_func100_008);
                        WR1_PROG(REG_0040H, 0x00400000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            r_rsip_func_sub001(0x0014003cU, 0x000f0000U, 0x0404000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            r_rsip_func_sub001(0x00140046U, 0x000f0000U, 0x0404000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            static const uint32_t Param_func073_func100_009[] =
                            {
                                BSWAP_32BIG_C(0x6703b7c3U), BSWAP_32BIG_C(0x66dff0bbU), BSWAP_32BIG_C(0x9a95b2bcU),
                                BSWAP_32BIG_C(0x2b857d7eU),
                            };
                            r_rsip_func100(Param_func073_func100_009);
                            WR1_PROG(REG_0040H, 0x00400000U);

                            if (CHCK_STS(REG_0040H, 22, 1))
                            {
                                r_rsip_func_sub001(0x003c0019U, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x0019003cU, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x0041001eU, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x001e0041U, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x00460023U, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                r_rsip_func_sub001(0x00230046U, 0x000f0000U, 0x0404000aU);

                                WR1_PROG(REG_0040H, 0x00210000U);

                                static const uint32_t Param_func073_func100_010[] =
                                {
                                    BSWAP_32BIG_C(0xdcb84fa8U), BSWAP_32BIG_C(0xc1c6c3a5U), BSWAP_32BIG_C(0xff8f5cecU),
                                    BSWAP_32BIG_C(0x51db98d0U),
                                };
                                r_rsip_func100(Param_func073_func100_010);
                                WR1_PROG(REG_0040H, 0x00400000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub001(0x00460023U, 0x00230005U, 0x04040013U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func073_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0xb3653215U), BSWAP_32BIG_C(0x855b3026U), BSWAP_32BIG_C(
                                            0x76e9210cU),           BSWAP_32BIG_C(0xcb3d4fe4U),
                                    };
                                    r_rsip_func101(Param_func073_func101_011);
                                }
                                else
                                {
                                    r_rsip_func_sub001(0x00000023U, 0x0023002dU, 0x04040014U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func073_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x8862eea8U), BSWAP_32BIG_C(0x8872966dU), BSWAP_32BIG_C(
                                            0x54b90d85U),           BSWAP_32BIG_C(0xce984103U),
                                    };
                                    r_rsip_func101(Param_func073_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_func073_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xf4eed56eU), BSWAP_32BIG_C(0xda9fb427U), BSWAP_32BIG_C(0x78a8f046U),
                                    BSWAP_32BIG_C(0x4da9fa67U),
                                };
                                r_rsip_func101(Param_func073_func101_013);
                            }
                        }
                        else
                        {
                            r_rsip_func_sub009(0x00001414U, 0x00c00021U, 0x00001800U);

                            r_rsip_func_sub001(0x0014003cU, 0x00190000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140041U, 0x001e0000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140046U, 0x00230000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x4a6ec644U), BSWAP_32BIG_C(0x1b38ba4fU), BSWAP_32BIG_C(0xe85b31f3U),
                                BSWAP_32BIG_C(0x563786eeU),
                            };
                            r_rsip_func101(Param_func073_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_func073_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x7407e7bbU), BSWAP_32BIG_C(0x643c049bU), BSWAP_32BIG_C(0x3a560941U),
                            BSWAP_32BIG_C(0x2a3a38c5U),
                        };
                        r_rsip_func101(Param_func073_func101_015);
                    }

                    WR1_PROG(REG_0094H, 0x00002c40U);
                    static const uint32_t Param_func073_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x5a459c8dU), BSWAP_32BIG_C(0x95145248U), BSWAP_32BIG_C(0x82ce5720U),
                        BSWAP_32BIG_C(0x089ccbacU),
                    };
                    r_rsip_func101(Param_func073_func101_016);
                }

                r_rsip_func_sub010(0x38008840U, 0x00000020U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                WR1_PROG(REG_0094H, 0x00002c20U);

                static const uint32_t Param_func073_func101_017[] =
                {
                    BSWAP_32BIG_C(0x597da616U), BSWAP_32BIG_C(0x0ac41546U), BSWAP_32BIG_C(0x6f108361U), BSWAP_32BIG_C(
                        0xad56a7b5U),
                };
                r_rsip_func101(Param_func073_func101_017);
            }

            r_rsip_func_sub010(0x38008820U, 0x00000004U, 0x00270000U);

            WR1_PROG(REG_0040H, 0x00402000U);

            WR1_PROG(REG_0094H, 0x00002c00U);

            static const uint32_t Param_func073_func101_018[] =
            {
                BSWAP_32BIG_C(0xfdf186ddU), BSWAP_32BIG_C(0x89debddaU), BSWAP_32BIG_C(0xc7ffe95dU), BSWAP_32BIG_C(
                    0x7cb64360U),
            };
            r_rsip_func101(Param_func073_func101_018);
        }

        r_rsip_func_sub010(0x38008800U, 0x00000002U, 0x00270000U);

        WR1_PROG(REG_0040H, 0x00402000U);

        r_rsip_func_sub009(0x00001414U, 0x00c00021U, 0x00001800U);

        r_rsip_func_sub001(0x0014000aU, 0x00690000U, 0x04040009U);

        r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000001U);

        r_rsip_func_sub001(0x00140023U, 0x002d0000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func073_func100_011[] =
        {
            BSWAP_32BIG_C(0xfb1950f8U), BSWAP_32BIG_C(0x541678a1U), BSWAP_32BIG_C(0x125a3700U), BSWAP_32BIG_C(
                0x48e985d9U),
        };
        r_rsip_func100(Param_func073_func100_011);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func073_func101_019[] =
            {
                BSWAP_32BIG_C(0xe9610ddeU), BSWAP_32BIG_C(0x7f04cb63U), BSWAP_32BIG_C(0xa0dfac12U), BSWAP_32BIG_C(
                    0x171f4c2eU),
            };
            r_rsip_func101(Param_func073_func101_019);
        }
        else
        {
            static const uint32_t Param_func073_func100_012[] =
            {
                BSWAP_32BIG_C(0x24f45b8eU), BSWAP_32BIG_C(0x72317c29U), BSWAP_32BIG_C(0xf3e0472aU), BSWAP_32BIG_C(
                    0xf2df13c3U),
            };
            r_rsip_func100(Param_func073_func100_012);

            r_rsip_func_sub001(0x00140023U, 0x00280005U, 0x04040002U);

            r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000002U);

            r_rsip_func_sub001(0x00140005U, 0x000f0000U, 0x0404000aU);

            r_rsip_func_sub021(0x000f0028U, 0x00140005U, 0x04040000U);
            r_rsip_func_sub020(0x20010001U, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x00140019U, 0x00280005U, 0x04040002U);

            r_rsip_func_sub001(0x00690028U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            r_rsip_func_sub001(0x00280069U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func073_func100_013[] =
            {
                BSWAP_32BIG_C(0x678af566U), BSWAP_32BIG_C(0xdebeae10U), BSWAP_32BIG_C(0x3078fa48U), BSWAP_32BIG_C(
                    0x75905acbU),
            };
            r_rsip_func100(Param_func073_func100_013);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func073_func101_020[] =
                {
                    BSWAP_32BIG_C(0xd0f56c5cU), BSWAP_32BIG_C(0x923a0f8bU), BSWAP_32BIG_C(0x2da6d99fU), BSWAP_32BIG_C(
                        0x75c5053cU),
                };
                r_rsip_func101(Param_func073_func101_020);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b400U);
                WR1_PROG(REG_0094H, 0xd8f48c0dU);

                static const uint32_t Param_func073_func101_021[] =
                {
                    BSWAP_32BIG_C(0x2da902bfU), BSWAP_32BIG_C(0x0a201fe9U), BSWAP_32BIG_C(0x218eba73U), BSWAP_32BIG_C(
                        0x74a9525dU),
                };
                r_rsip_func101(Param_func073_func101_021);
            }
        }
    }

    r_rsip_func_sub010(0x38008800U, 0xd8f48c0dU, 0x00A70000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
