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

    WR1_PROG(REG_00A0H, 0x20010001U);
    WAIT_STS(REG_00A8H, 0, 1);
    WR1_PROG(REG_00ACH, 0x00000001U);

    r_rsip_func_sub004(0x0000141eU, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

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
        BSWAP_32BIG_C(0xe51f8c65U), BSWAP_32BIG_C(0xafa0f132U), BSWAP_32BIG_C(0x457067c3U), BSWAP_32BIG_C(0x63aa4fc3U),
    };
    r_rsip_func100(Param_func073_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func073_func101_001[] =
        {
            BSWAP_32BIG_C(0x0d051ebaU), BSWAP_32BIG_C(0x01857d55U), BSWAP_32BIG_C(0x0e7c2091U), BSWAP_32BIG_C(
                0x456e85efU),
        };
        r_rsip_func101(Param_func073_func101_001);
    }
    else
    {
        static const uint32_t Param_func073_func100_002[] =
        {
            BSWAP_32BIG_C(0x7095fd7cU), BSWAP_32BIG_C(0x9d8da667U), BSWAP_32BIG_C(0xb72431feU), BSWAP_32BIG_C(
                0xa3cc89b9U),
        };
        r_rsip_func100(Param_func073_func100_002);

        r_rsip_func_sub001(0x001e0014U, 0x00190000U, 0x0404000aU);

        WR1_PROG(REG_00B4H, 0x0019006eU);
        WR1_PROG(REG_00B8H, 0x000f000aU);

        WR1_PROG(REG_00A4H, 0x04040000U);
        WR1_PROG(REG_0008H, 0x00020000U);
        WR1_PROG(REG_00A0H, 0x20010001U);
        WAIT_STS(REG_00A8H, 0, 1);
        WR1_PROG(REG_00ACH, 0x00000001U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub001(0x005a000fU, 0x0014000aU, 0x04040002U);

        r_rsip_func_sub004(0x00001423U, 0x00c00021U);

        r_rsip_func_sub001(0x0023007eU, 0x000f0000U, 0x04040009U);

        r_rsip_func_sub001(0x0014000fU, 0x000f000aU, 0x04040002U);

        r_rsip_func_sub001(0x00140069U, 0x0032000aU, 0x04040002U);

        WR1_PROG(REG_00B8H, 0x00000005U);

        WR1_PROG(REG_00A4H, 0x04040010U);

        WR1_PROG(REG_00A0H, 0x20010001U);
        WAIT_STS(REG_00A8H, 0, 1);
        WR1_PROG(REG_00ACH, 0x00000001U);

        r_rsip_func_sub001(0x00230069U, 0x000a0000U, 0x04040009U);

        r_rsip_func_sub001(0x00370076U, 0x004b0005U, 0x04040002U);

        r_rsip_func_sub001(0x0037007aU, 0x00500005U, 0x04040002U);

        r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
        WR1_PROG(REG_0014H, 0x000000a5U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x00140037U, 0x00550005U, 0x04040002U);

        r_rsip_func_sub001(0x0023005fU, 0x00280000U, 0x04040009U);

        r_rsip_func_sub001(0x00230005U, 0x002d0000U, 0x04040009U);

        r_rsip_func_sub004(0x00000415U, 0x00c00009U);

        r_rsip_func_sub004(0x0000041aU, 0x00c00009U);
        r_rsip_func071(ARG1);

        r_rsip_func_sub001(0x00230019U, 0x005a0000U, 0x04040009U);

        r_rsip_func_sub001(0x0023001eU, 0x005f0000U, 0x04040009U);

        r_rsip_func_sub001(0x00230055U, 0x00640000U, 0x04040009U);

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
            BSWAP_32BIG_C(0xb9566077U), BSWAP_32BIG_C(0xa869a624U), BSWAP_32BIG_C(0x91c0a503U), BSWAP_32BIG_C(
                0xb237a2feU),
        };
        r_rsip_func100(Param_func073_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x00550064U, 0x00730005U, 0x04040013U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func073_func101_002[] =
            {
                BSWAP_32BIG_C(0xd7e3cecdU), BSWAP_32BIG_C(0x8b7b1ee1U), BSWAP_32BIG_C(0xbc67898aU), BSWAP_32BIG_C(
                    0x8b664f2cU),
            };
            r_rsip_func101(Param_func073_func101_002);
        }
        else
        {
            r_rsip_func_sub001(0x00000064U, 0x0073002dU, 0x04040014U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            static const uint32_t Param_func073_func101_003[] =
            {
                BSWAP_32BIG_C(0xbedc3908U), BSWAP_32BIG_C(0x59a03f6bU), BSWAP_32BIG_C(0xe822c771U), BSWAP_32BIG_C(
                    0x836f8299U),
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
            r_rsip_func_sub007(0x000008a5U, 0x38000c00U, 0x00260000U);

            static const uint32_t Param_func073_func100_004[] =
            {
                BSWAP_32BIG_C(0x7e0f99f1U), BSWAP_32BIG_C(0x81ee8e4bU), BSWAP_32BIG_C(0x5086e2c3U), BSWAP_32BIG_C(
                    0xd795b1a0U),
            };
            r_rsip_func100(Param_func073_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_00B0H, 0x00000834U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);
                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000835U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);
                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x0000082fU);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);

                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000830U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);

                static const uint32_t Param_func073_func101_004[] =
                {
                    BSWAP_32BIG_C(0xdf46a32cU), BSWAP_32BIG_C(0x72583a76U), BSWAP_32BIG_C(0xe3721519U), BSWAP_32BIG_C(
                        0xe77e20c1U),
                };
                r_rsip_func101(Param_func073_func101_004);
            }
            else
            {
                WR1_PROG(REG_00B0H, 0x00000836U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);
                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000837U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);
                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000831U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);

                WR1_PROG(REG_0094H, 0x0000a4a0U);
                WR1_PROG(REG_0094H, 0x00000008U);

                WR1_PROG(REG_00B0H, 0x00000832U);
                r_rsip_func_sub003(0x80820005U, 0x03430009U);

                static const uint32_t Param_func073_func101_005[] =
                {
                    BSWAP_32BIG_C(0x96205348U), BSWAP_32BIG_C(0xdfbab52aU), BSWAP_32BIG_C(0xe2032801U), BSWAP_32BIG_C(
                        0x738733c3U),
                };
                r_rsip_func101(Param_func073_func101_005);
            }

            WR1_PROG(REG_0094H, 0x00000821U);

            for (jLoop = 0U; jLoop < 4; jLoop++)
            {
                r_rsip_func_sub016(0x000034a1U, 0x00026ca5U, 0x00003865U);

                r_rsip_func_sub016(0x0000a4a0U, 0x00000010U, 0x00003885U);

                WR1_PROG(REG_0094H, 0x00000842U);

                for (kLoop = 0U; kLoop < 32U; kLoop++)
                {
                    r_rsip_func_sub016(0x000008a5U, 0x01816ca3U, 0x01816ca4U);
                    WR1_PROG(REG_0094H, 0x00016c63U);
                    WR1_PROG(REG_0094H, 0x00016c84U);

                    r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
                    WR1_PROG(REG_0014H, 0x000000a5U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

                    r_rsip_func_sub001(0x00140019U, 0x000f0000U, 0x0404000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    r_rsip_func_sub001(0x00140023U, 0x000f0000U, 0x0404000aU);

                    WR1_PROG(REG_0040H, 0x00a10000U);

                    static const uint32_t Param_func073_func100_005[] =
                    {
                        BSWAP_32BIG_C(0x2b1f86b5U), BSWAP_32BIG_C(0xf5b9d861U), BSWAP_32BIG_C(0xc82f2c65U),
                        BSWAP_32BIG_C(0xc4687346U),
                    };
                    r_rsip_func100(Param_func073_func100_005);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        r_rsip_func_sub001(0x00000023U, 0x0023002dU, 0x04040014U);
                        WR1_PROG(REG_0040H, 0x00000d00U);

                        static const uint32_t Param_func073_func101_006[] =
                        {
                            BSWAP_32BIG_C(0xbde49965U), BSWAP_32BIG_C(0x0d0d1696U), BSWAP_32BIG_C(0x1c607d76U),
                            BSWAP_32BIG_C(0x7f417cf7U),
                        };
                        r_rsip_func101(Param_func073_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_func073_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x6b2aaa69U), BSWAP_32BIG_C(0x00bf2424U), BSWAP_32BIG_C(0xf2ffd601U),
                            BSWAP_32BIG_C(0xaba2b99dU),
                        };
                        r_rsip_func101(Param_func073_func101_007);
                    }

                    WR1_PROG(REG_0094H, 0x38000ca5U);
                    WR1_PROG(REG_009CH, 0x00000080U);
                    WR1_PROG(REG_0040H, 0x00A60000U);

                    static const uint32_t Param_func073_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x67212861U), BSWAP_32BIG_C(0xd8c310acU), BSWAP_32BIG_C(0x9b689d3cU),
                        BSWAP_32BIG_C(0x9afd5f3aU),
                    };
                    r_rsip_func100(Param_func073_func100_006);
                    WR1_PROG(REG_0040H, 0x00400000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    if (CHCK_STS(REG_0040H, 22, 1))
                    {
                        static const uint32_t Param_func073_func100_007[] =
                        {
                            BSWAP_32BIG_C(0xf479a314U), BSWAP_32BIG_C(0xdfe9af19U), BSWAP_32BIG_C(0x185e9d85U),
                            BSWAP_32BIG_C(0x4f87fb86U),
                        };
                        r_rsip_func100(Param_func073_func100_007);

                        r_rsip_func_sub004(0x00001414U, 0x00c00021U);

                        WR1_PROG(REG_0094H, 0x00007c05U);
                        WR1_PROG(REG_0040H, 0x00600000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub001(0x0014004bU, 0x003c0000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140050U, 0x00410000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140055U, 0x00460000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x1425e8e3U), BSWAP_32BIG_C(0x31e98008U), BSWAP_32BIG_C(0x2877e31bU),
                                BSWAP_32BIG_C(0xb45b870aU),
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
                                BSWAP_32BIG_C(0xe12eda4eU), BSWAP_32BIG_C(0xb8c2ed9fU), BSWAP_32BIG_C(0x10f27d9dU),
                                BSWAP_32BIG_C(0x73707f8dU),
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
                                BSWAP_32BIG_C(0x623a11c3U), BSWAP_32BIG_C(0xf034b81eU), BSWAP_32BIG_C(0xc4078888U),
                                BSWAP_32BIG_C(0xbd54d177U),
                            };
                            r_rsip_func101(Param_func073_func101_010);
                        }

                        r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
                        WR1_PROG(REG_0014H, 0x000000a5U);
                        WAIT_STS(REG_0014H, 31, 1);
                        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

                        r_rsip_func_sub001(0x00140019U, 0x000f0000U, 0x0404000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        r_rsip_func_sub001(0x00140023U, 0x000f0000U, 0x0404000aU);

                        WR1_PROG(REG_0040H, 0x00a10000U);

                        static const uint32_t Param_func073_func100_008[] =
                        {
                            BSWAP_32BIG_C(0xdaa956deU), BSWAP_32BIG_C(0x0c7c031eU), BSWAP_32BIG_C(0x7c42c768U),
                            BSWAP_32BIG_C(0xfe329550U),
                        };
                        r_rsip_func100(Param_func073_func100_008);
                        WR1_PROG(REG_0040H, 0x00400000U);
                        WR1_PROG(REG_0024H, 0x00000000U);

                        if (CHCK_STS(REG_0040H, 22, 1))
                        {
                            r_rsip_func_sub001(0x0014003cU, 0x000f0000U, 0x0404000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            r_rsip_func_sub001(0x00140046U, 0x000f0000U, 0x0404000aU);

                            WR1_PROG(REG_0040H, 0x00a10000U);

                            static const uint32_t Param_func073_func100_009[] =
                            {
                                BSWAP_32BIG_C(0x59d010c3U), BSWAP_32BIG_C(0x1fc32a4cU), BSWAP_32BIG_C(0x0aacd4b9U),
                                BSWAP_32BIG_C(0xc083d948U),
                            };
                            r_rsip_func100(Param_func073_func100_009);
                            WR1_PROG(REG_0040H, 0x00400000U);
                            WR1_PROG(REG_0024H, 0x00000000U);

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
                                    BSWAP_32BIG_C(0x7fa3a6f4U), BSWAP_32BIG_C(0x35b13a28U), BSWAP_32BIG_C(0xf73f700bU),
                                    BSWAP_32BIG_C(0x2d1d21cfU),
                                };
                                r_rsip_func100(Param_func073_func100_010);
                                WR1_PROG(REG_0040H, 0x00400000U);
                                WR1_PROG(REG_0024H, 0x00000000U);

                                if (CHCK_STS(REG_0040H, 22, 1))
                                {
                                    r_rsip_func_sub001(0x00460023U, 0x00230005U, 0x04040013U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func073_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0xcc940023U), BSWAP_32BIG_C(0x9773c658U), BSWAP_32BIG_C(
                                            0x1cbf869fU),           BSWAP_32BIG_C(0xa3c137ccU),
                                    };
                                    r_rsip_func101(Param_func073_func101_011);
                                }
                                else
                                {
                                    r_rsip_func_sub001(0x00000023U, 0x0023002dU, 0x04040014U);
                                    WR1_PROG(REG_0040H, 0x00000d00U);

                                    static const uint32_t Param_func073_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0xab00fed4U), BSWAP_32BIG_C(0xea4b72ceU), BSWAP_32BIG_C(
                                            0xd2d32f79U),           BSWAP_32BIG_C(0xb80bf60cU),
                                    };
                                    r_rsip_func101(Param_func073_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_func073_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0x2f10472bU), BSWAP_32BIG_C(0xa565ceabU), BSWAP_32BIG_C(0x84fb7398U),
                                    BSWAP_32BIG_C(0x79aa14b7U),
                                };
                                r_rsip_func101(Param_func073_func101_013);
                            }
                        }
                        else
                        {
                            r_rsip_func_sub004(0x00001414U, 0x00c00021U);

                            r_rsip_func_sub001(0x0014003cU, 0x00190000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140041U, 0x001e0000U, 0x04040009U);

                            r_rsip_func_sub001(0x00140046U, 0x00230000U, 0x04040009U);

                            static const uint32_t Param_func073_func101_014[] =
                            {
                                BSWAP_32BIG_C(0x52fb41bdU), BSWAP_32BIG_C(0x99656440U), BSWAP_32BIG_C(0xd8a369d6U),
                                BSWAP_32BIG_C(0xed622873U),
                            };
                            r_rsip_func101(Param_func073_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_func073_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x4af66ec9U), BSWAP_32BIG_C(0x1f247ddaU), BSWAP_32BIG_C(0x42447029U),
                            BSWAP_32BIG_C(0x06ad03a0U),
                        };
                        r_rsip_func101(Param_func073_func101_015);
                    }

                    WR1_PROG(REG_0094H, 0x00002c40U);
                    static const uint32_t Param_func073_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x38cc1e35U), BSWAP_32BIG_C(0x10cde69dU), BSWAP_32BIG_C(0xb85b0c0dU),
                        BSWAP_32BIG_C(0x4b92ca7aU),
                    };
                    r_rsip_func101(Param_func073_func101_016);
                }

                r_rsip_func_sub007(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_0040H, 0x00402000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                WR1_PROG(REG_0094H, 0x00002c20U);

                static const uint32_t Param_func073_func101_017[] =
                {
                    BSWAP_32BIG_C(0xc997ce56U), BSWAP_32BIG_C(0x92887195U), BSWAP_32BIG_C(0x8307ccfeU), BSWAP_32BIG_C(
                        0x52858abaU),
                };
                r_rsip_func101(Param_func073_func101_017);
            }

            r_rsip_func_sub007(0x38008820U, 0x00000004U, 0x00260000U);

            WR1_PROG(REG_0040H, 0x00402000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            WR1_PROG(REG_0094H, 0x00002c00U);

            static const uint32_t Param_func073_func101_018[] =
            {
                BSWAP_32BIG_C(0x7122c320U), BSWAP_32BIG_C(0x33c9265dU), BSWAP_32BIG_C(0xff4872d5U), BSWAP_32BIG_C(
                    0x9775d9ebU),
            };
            r_rsip_func101(Param_func073_func101_018);
        }

        r_rsip_func_sub007(0x38008800U, 0x00000002U, 0x00260000U);

        WR1_PROG(REG_0040H, 0x00402000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub004(0x00001414U, 0x00c00021U);

        r_rsip_func_sub001(0x0014000aU, 0x00690000U, 0x04040009U);

        r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
        WR1_PROG(REG_0014H, 0x000000a5U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x00140023U, 0x002d0000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func073_func100_011[] =
        {
            BSWAP_32BIG_C(0x03cb7535U), BSWAP_32BIG_C(0x24719250U), BSWAP_32BIG_C(0x8a837ee3U), BSWAP_32BIG_C(
                0x760a920bU),
        };
        r_rsip_func100(Param_func073_func100_011);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func073_func101_019[] =
            {
                BSWAP_32BIG_C(0x5953f40eU), BSWAP_32BIG_C(0x96487652U), BSWAP_32BIG_C(0x9b0925e2U), BSWAP_32BIG_C(
                    0x2f78b031U),
            };
            r_rsip_func101(Param_func073_func101_019);
        }
        else
        {
            static const uint32_t Param_func073_func100_012[] =
            {
                BSWAP_32BIG_C(0x643c0951U), BSWAP_32BIG_C(0x6782e12aU), BSWAP_32BIG_C(0x17098bcfU), BSWAP_32BIG_C(
                    0x0e3ac121U),
            };
            r_rsip_func100(Param_func073_func100_012);

            r_rsip_func_sub001(0x00140023U, 0x00280005U, 0x04040002U);

            r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
            WR1_PROG(REG_0014H, 0x000000a5U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

            r_rsip_func_sub001(0x00140005U, 0x000f0000U, 0x0404000aU);

            WR1_PROG(REG_00B4H, 0x000f0028U);
            WR1_PROG(REG_00B8H, 0x00140005U);

            WR1_PROG(REG_00A4H, 0x04040000U);
            WR1_PROG(REG_0008H, 0x00020000U);
            WR1_PROG(REG_00A0H, 0x20010001U);
            WAIT_STS(REG_00A8H, 0, 1);
            WR1_PROG(REG_00ACH, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x00140019U, 0x00280005U, 0x04040002U);

            r_rsip_func_sub001(0x00690028U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            r_rsip_func_sub001(0x00280069U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func073_func100_013[] =
            {
                BSWAP_32BIG_C(0xf7d1e4a6U), BSWAP_32BIG_C(0xddf205c8U), BSWAP_32BIG_C(0xc5208fc0U), BSWAP_32BIG_C(
                    0xa45a0551U),
            };
            r_rsip_func100(Param_func073_func100_013);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func073_func101_020[] =
                {
                    BSWAP_32BIG_C(0x13ac2c4eU), BSWAP_32BIG_C(0x5fb35462U), BSWAP_32BIG_C(0x74e9ad80U), BSWAP_32BIG_C(
                        0xdb70185fU),
                };
                r_rsip_func101(Param_func073_func101_020);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b400U);
                WR1_PROG(REG_0094H, 0x665331ecU);

                static const uint32_t Param_func073_func101_021[] =
                {
                    BSWAP_32BIG_C(0x6058aaeaU), BSWAP_32BIG_C(0xbdb73076U), BSWAP_32BIG_C(0x7cef9943U), BSWAP_32BIG_C(
                        0xc19bf57eU),
                };
                r_rsip_func101(Param_func073_func101_021);
            }
        }
    }

    r_rsip_func_sub007(0x38008800U, 0x665331ecU, 0x00A60000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
