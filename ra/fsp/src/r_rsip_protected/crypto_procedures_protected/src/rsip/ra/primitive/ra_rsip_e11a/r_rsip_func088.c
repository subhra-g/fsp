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

void r_rsip_func088 (void)
{
    static const uint32_t Param_func088_func100_001[] =
    {
        BSWAP_32BIG_C(0x5c666421U), BSWAP_32BIG_C(0x2963c3ffU), BSWAP_32BIG_C(0x2022d203U), BSWAP_32BIG_C(0x56e80e70U),
    };
    r_rsip_func100(Param_func088_func100_001);

    WR1_PROG(REG_00A0H, 0x20010000U);
    r_rsip_func103();
    static const uint32_t Param_func088_func100_002[] =
    {
        BSWAP_32BIG_C(0xd42563ccU), BSWAP_32BIG_C(0xb931ecaeU), BSWAP_32BIG_C(0x63bd533dU), BSWAP_32BIG_C(0x1c8137aeU),
    };
    r_rsip_func100(Param_func088_func100_002);
    WR1_PROG(REG_00B0H, 0x0000140fU);
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func_sub004(0x00001428U, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

    r_rsip_func_sub004(0x0000142dU, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

    r_rsip_func_sub001(0x002d000aU, 0x00140000U, 0x0404000aU);

    WR1_PROG(REG_00B8H, 0x00000014U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    WR1_PROG(REG_00A0H, 0x20010001U);
    WAIT_STS(REG_00A8H, 0, 1);
    WR1_PROG(REG_00ACH, 0x00000001U);

    r_rsip_func_sub001(0x0028000fU, 0x00230014U, 0x04040002U);

    r_rsip_func_sub001(0x00280023U, 0x00140000U, 0x04040009U);

    r_rsip_func_sub001(0x00140032U, 0x000f000aU, 0x04040005U);

    r_rsip_func_sub001(0x0028000fU, 0x002d0000U, 0x0404000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    static const uint32_t Param_func088_func100_003[] =
    {
        BSWAP_32BIG_C(0xa2ade092U), BSWAP_32BIG_C(0x6b6ebe7cU), BSWAP_32BIG_C(0xfafa73aeU), BSWAP_32BIG_C(0x85140ce0U),
    };
    r_rsip_func100(Param_func088_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func088_func101_001[] =
        {
            BSWAP_32BIG_C(0x79195a13U), BSWAP_32BIG_C(0xd82dbf23U), BSWAP_32BIG_C(0x63699928U), BSWAP_32BIG_C(
                0x382528d5U),
        };
        r_rsip_func101(Param_func088_func101_001);
    }
    else
    {
        static const uint32_t Param_func088_func100_004[] =
        {
            BSWAP_32BIG_C(0x74b52af8U), BSWAP_32BIG_C(0x88865dc0U), BSWAP_32BIG_C(0xbbd3fc5aU), BSWAP_32BIG_C(
                0x31db8acdU),
        };
        r_rsip_func100(Param_func088_func100_004);
        WR1_PROG(REG_00B8H, 0x00000005U);

        WR1_PROG(REG_00A4H, 0x04040010U);

        WR1_PROG(REG_00A0H, 0x20010001U);
        WAIT_STS(REG_00A8H, 0, 1);
        WR1_PROG(REG_00ACH, 0x00000001U);

        r_rsip_func_sub001(0x00280037U, 0x00230005U, 0x04040002U);

        r_rsip_func_sub004(0x0000143cU, 0x00c00021U);

        r_rsip_func_sub001(0x003c005fU, 0x00280000U, 0x04040009U);

        r_rsip_func_sub001(0x003c0005U, 0x002d0000U, 0x04040009U);

        r_rsip_func_sub001(0x000f0023U, 0x0046002dU, 0x04040015U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub004(0x0000140fU, 0x00c0001dU);
        WR1_PROG(REG_0014H, 0x000000a5U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x000f0046U, 0x004b0000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func088_func100_005[] =
        {
            BSWAP_32BIG_C(0x6253caa4U), BSWAP_32BIG_C(0xd7cd291dU), BSWAP_32BIG_C(0x090bb075U), BSWAP_32BIG_C(
                0x67ed2452U),
        };
        r_rsip_func100(Param_func088_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func088_func101_002[] =
            {
                BSWAP_32BIG_C(0xe6154ab4U), BSWAP_32BIG_C(0xd8e4fd8fU), BSWAP_32BIG_C(0x683b6099U), BSWAP_32BIG_C(
                    0xa7198ef5U),
            };
            r_rsip_func101(Param_func088_func101_002);
        }
        else
        {
            static const uint32_t Param_func088_func100_006[] =
            {
                BSWAP_32BIG_C(0xdc0f9f3eU), BSWAP_32BIG_C(0x3583eda5U), BSWAP_32BIG_C(0x34d570f4U), BSWAP_32BIG_C(
                    0x2b4b2747U),
            };
            r_rsip_func100(Param_func088_func100_006);
            r_rsip_func_sub001(0x00140023U, 0x0055002dU, 0x04040015U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub004(0x0000140fU, 0x00c0001dU);
            WR1_PROG(REG_0014H, 0x000000a5U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

            r_rsip_func_sub001(0x000f0055U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func088_func100_007[] =
            {
                BSWAP_32BIG_C(0x1abd8e32U), BSWAP_32BIG_C(0x71453684U), BSWAP_32BIG_C(0xd2aabc4eU), BSWAP_32BIG_C(
                    0x40211226U),
            };
            r_rsip_func100(Param_func088_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func088_func101_003[] =
                {
                    BSWAP_32BIG_C(0x7276f790U), BSWAP_32BIG_C(0x31fdfe0bU), BSWAP_32BIG_C(0xd4a62998U), BSWAP_32BIG_C(
                        0xd1219e49U),
                };
                r_rsip_func101(Param_func088_func101_003);
            }
            else
            {
                static const uint32_t Param_func088_func100_008[] =
                {
                    BSWAP_32BIG_C(0x201a9f11U), BSWAP_32BIG_C(0x20b86454U), BSWAP_32BIG_C(0x14e3bf2aU), BSWAP_32BIG_C(
                        0x9db5b48fU),
                };
                r_rsip_func100(Param_func088_func100_008);
                r_rsip_func_sub001(0x000f0055U, 0x00230005U, 0x04040002U);

                r_rsip_func_sub004(0x00001414U, 0x00c0001dU);
                WR1_PROG(REG_0014H, 0x000000a5U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

                r_rsip_func_sub001(0x00140005U, 0x000f0000U, 0x0404000aU);

                WR1_PROG(REG_00B4H, 0x000f0023U);
                WR1_PROG(REG_00B8H, 0x00140005U);

                WR1_PROG(REG_00A4H, 0x04040000U);
                WR1_PROG(REG_0008H, 0x00020000U);
                WR1_PROG(REG_00A0H, 0x20010001U);
                WAIT_STS(REG_00A8H, 0, 1);
                WR1_PROG(REG_00ACH, 0x00000001U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x0014004bU, 0x00190005U, 0x04040002U);

                r_rsip_func_sub001(0x00140050U, 0x001e0005U, 0x04040002U);

                r_rsip_func_sub001(0x001e0005U, 0x000f0000U, 0x0404000aU);

                r_rsip_func_sub001(0x0037000fU, 0x00500005U, 0x04040002U);

                r_rsip_func_sub001(0x00370019U, 0x000f0005U, 0x04040002U);

                r_rsip_func_sub004(0x00001414U, 0x00c00021U);

                r_rsip_func_sub001(0x0014000fU, 0x004b0000U, 0x04040009U);

                r_rsip_func_sub004(0x0000142dU, 0x00c0001dU);
                WR1_PROG(REG_0014H, 0x000000a5U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

                r_rsip_func_sub001(0x002d0037U, 0x00550005U, 0x04040002U);

                r_rsip_func_sub001(0x00550046U, 0x00230005U, 0x04040013U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x002d0023U, 0x00280000U, 0x0404000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_func088_func100_009[] =
                {
                    BSWAP_32BIG_C(0xe519cee2U), BSWAP_32BIG_C(0xe3f09149U), BSWAP_32BIG_C(0x3f7bc365U), BSWAP_32BIG_C(
                        0x18b4e69bU),
                };
                r_rsip_func100(Param_func088_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x00000800U);

                    static const uint32_t Param_func088_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xf5374e2cU), BSWAP_32BIG_C(0x15b06941U), BSWAP_32BIG_C(0xf8a7907aU),
                        BSWAP_32BIG_C(0x5fc4650dU),
                    };
                    r_rsip_func101(Param_func088_func101_004);
                }
                else
                {
                    static const uint32_t Param_func088_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xeddf7cedU), BSWAP_32BIG_C(0x64c33242U), BSWAP_32BIG_C(0x7e928b60U),
                        BSWAP_32BIG_C(0xda393332U),
                    };
                    r_rsip_func100(Param_func088_func100_010);
                    r_rsip_func_sub001(0x002d0023U, 0x00280005U, 0x04040002U);

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

                    r_rsip_func_sub001(0x0014001eU, 0x002d0005U, 0x04040002U);

                    WR1_PROG(REG_0094H, 0x0000b400U);
                    WR1_PROG(REG_0094H, 0xd71b216bU);

                    static const uint32_t Param_func088_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x1e0e1d4fU), BSWAP_32BIG_C(0x205fbbffU), BSWAP_32BIG_C(0xa790208aU),
                        BSWAP_32BIG_C(0x9be31b75U),
                    };
                    r_rsip_func101(Param_func088_func101_005);
                }
            }
        }
    }

    r_rsip_func_sub007(0x38008800U, 0xd71b216bU, 0x00A60000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}
