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
        BSWAP_32BIG_C(0xfcd8c748U), BSWAP_32BIG_C(0xc2307edfU), BSWAP_32BIG_C(0xad33248bU), BSWAP_32BIG_C(0x39126f9eU),
    };
    r_rsip_func100(Param_func088_func100_001);

    WR1_PROG(REG_00A0H, 0x20010000U);
    r_rsip_func103();
    static const uint32_t Param_func088_func100_002[] =
    {
        BSWAP_32BIG_C(0x83c53387U), BSWAP_32BIG_C(0x8db9301eU), BSWAP_32BIG_C(0x60c83150U), BSWAP_32BIG_C(0xe8133015U),
    };
    r_rsip_func100(Param_func088_func100_002);
    WR1_PROG(REG_00B0H, 0x0000140fU);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x00001428U, 0x00c0001dU, 0x00000001U);

    r_rsip_func_sub003(0x0000142dU, 0x00c0001dU, 0x00000002U);

    r_rsip_func_sub001(0x002d000aU, 0x00140000U, 0x0404000aU);

    WR1_PROG(REG_00B8H, 0x00000014U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub001(0x0028000fU, 0x00230014U, 0x04040002U);

    r_rsip_func_sub001(0x00280023U, 0x00140000U, 0x04040009U);

    r_rsip_func_sub001(0x00140032U, 0x000f000aU, 0x04040005U);

    r_rsip_func_sub001(0x0028000fU, 0x002d0000U, 0x0404000aU);

    WR1_PROG(REG_0040H, 0x00210000U);

    static const uint32_t Param_func088_func100_003[] =
    {
        BSWAP_32BIG_C(0x9f6d0e67U), BSWAP_32BIG_C(0x53513639U), BSWAP_32BIG_C(0x4cf66898U), BSWAP_32BIG_C(0x96d841f3U),
    };
    r_rsip_func100(Param_func088_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x00000800U);

        static const uint32_t Param_func088_func101_001[] =
        {
            BSWAP_32BIG_C(0x31fe6608U), BSWAP_32BIG_C(0x786fe276U), BSWAP_32BIG_C(0xad730323U), BSWAP_32BIG_C(
                0xf7ce5b8aU),
        };
        r_rsip_func101(Param_func088_func101_001);
    }
    else
    {
        static const uint32_t Param_func088_func100_004[] =
        {
            BSWAP_32BIG_C(0x18cde02aU), BSWAP_32BIG_C(0xa1af898fU), BSWAP_32BIG_C(0x82889b22U), BSWAP_32BIG_C(
                0xdb7023a1U),
        };
        r_rsip_func100(Param_func088_func100_004);
        WR1_PROG(REG_00B8H, 0x00000005U);

        WR1_PROG(REG_00A4H, 0x04040010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x00280037U, 0x00230005U, 0x04040002U);

        r_rsip_func_sub009(0x0000143cU, 0x00c00021U, 0x00001800U);

        r_rsip_func_sub001(0x003c005fU, 0x00280000U, 0x04040009U);

        r_rsip_func_sub001(0x003c0005U, 0x002d0000U, 0x04040009U);

        r_rsip_func_sub001(0x000f0023U, 0x0046002dU, 0x04040015U);
        WR1_PROG(REG_0040H, 0x00000d00U);

        r_rsip_func_sub003(0x0000140fU, 0x00c0001dU, 0x00000001U);

        r_rsip_func_sub001(0x000f0046U, 0x004b0000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_func088_func100_005[] =
        {
            BSWAP_32BIG_C(0xd595629cU), BSWAP_32BIG_C(0xb13a03d7U), BSWAP_32BIG_C(0x6f519fe0U), BSWAP_32BIG_C(
                0x8540a863U),
        };
        r_rsip_func100(Param_func088_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x00000800U);

            static const uint32_t Param_func088_func101_002[] =
            {
                BSWAP_32BIG_C(0x879d4cf6U), BSWAP_32BIG_C(0x2e3471b7U), BSWAP_32BIG_C(0x9aad8b23U), BSWAP_32BIG_C(
                    0x837889f3U),
            };
            r_rsip_func101(Param_func088_func101_002);
        }
        else
        {
            static const uint32_t Param_func088_func100_006[] =
            {
                BSWAP_32BIG_C(0xbd8f7b56U), BSWAP_32BIG_C(0x6fa86a8eU), BSWAP_32BIG_C(0x26cee92eU), BSWAP_32BIG_C(
                    0x9b27f4b4U),
            };
            r_rsip_func100(Param_func088_func100_006);
            r_rsip_func_sub001(0x00140023U, 0x0055002dU, 0x04040015U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub003(0x0000140fU, 0x00c0001dU, 0x00000001U);

            r_rsip_func_sub001(0x000f0055U, 0x00190000U, 0x0404000aU);

            WR1_PROG(REG_0040H, 0x00210000U);

            static const uint32_t Param_func088_func100_007[] =
            {
                BSWAP_32BIG_C(0x95a604b7U), BSWAP_32BIG_C(0x2fd4316bU), BSWAP_32BIG_C(0xa1b732cbU), BSWAP_32BIG_C(
                    0x9cec0513U),
            };
            r_rsip_func100(Param_func088_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00000800U);

                static const uint32_t Param_func088_func101_003[] =
                {
                    BSWAP_32BIG_C(0x40ca68bcU), BSWAP_32BIG_C(0x122a08eeU), BSWAP_32BIG_C(0xbefa74f8U), BSWAP_32BIG_C(
                        0x9a3805efU),
                };
                r_rsip_func101(Param_func088_func101_003);
            }
            else
            {
                static const uint32_t Param_func088_func100_008[] =
                {
                    BSWAP_32BIG_C(0xe132d8a5U), BSWAP_32BIG_C(0x45928744U), BSWAP_32BIG_C(0x16901808U), BSWAP_32BIG_C(
                        0xa54c441aU),
                };
                r_rsip_func100(Param_func088_func100_008);
                r_rsip_func_sub001(0x000f0055U, 0x00230005U, 0x04040002U);

                r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000002U);

                r_rsip_func_sub001(0x00140005U, 0x000f0000U, 0x0404000aU);

                r_rsip_func_sub021(0x000f0023U, 0x00140005U, 0x04040000U);
                r_rsip_func_sub020(0x20010001U, 0x00000001U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x0014004bU, 0x00190005U, 0x04040002U);

                r_rsip_func_sub001(0x00140050U, 0x001e0005U, 0x04040002U);

                r_rsip_func_sub001(0x001e0005U, 0x000f0000U, 0x0404000aU);

                r_rsip_func_sub001(0x0037000fU, 0x00500005U, 0x04040002U);

                r_rsip_func_sub001(0x00370019U, 0x000f0005U, 0x04040002U);

                r_rsip_func_sub009(0x00001414U, 0x00c00021U, 0x00001800U);

                r_rsip_func_sub001(0x0014000fU, 0x004b0000U, 0x04040009U);

                r_rsip_func_sub003(0x0000142dU, 0x00c0001dU, 0x00000001U);

                r_rsip_func_sub001(0x002d0037U, 0x00550005U, 0x04040002U);

                r_rsip_func_sub001(0x00550046U, 0x00230005U, 0x04040013U);
                WR1_PROG(REG_0040H, 0x00000d00U);

                r_rsip_func_sub001(0x002d0023U, 0x00280000U, 0x0404000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_func088_func100_009[] =
                {
                    BSWAP_32BIG_C(0x9d8640edU), BSWAP_32BIG_C(0x9a0e9231U), BSWAP_32BIG_C(0x8def4afeU), BSWAP_32BIG_C(
                        0xc0b9c480U),
                };
                r_rsip_func100(Param_func088_func100_009);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x00000800U);

                    static const uint32_t Param_func088_func101_004[] =
                    {
                        BSWAP_32BIG_C(0x7fbe47abU), BSWAP_32BIG_C(0xa644294dU), BSWAP_32BIG_C(0xc6105a93U),
                        BSWAP_32BIG_C(0x29526c41U),
                    };
                    r_rsip_func101(Param_func088_func101_004);
                }
                else
                {
                    static const uint32_t Param_func088_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x773dc358U), BSWAP_32BIG_C(0xbaf636b5U), BSWAP_32BIG_C(0x239b3d38U),
                        BSWAP_32BIG_C(0xb4fce1c2U),
                    };
                    r_rsip_func100(Param_func088_func100_010);
                    r_rsip_func_sub001(0x002d0023U, 0x00280005U, 0x04040002U);

                    r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000002U);

                    r_rsip_func_sub001(0x00140005U, 0x000f0000U, 0x0404000aU);

                    r_rsip_func_sub021(0x000f0028U, 0x00140005U, 0x04040000U);
                    r_rsip_func_sub020(0x20010001U, 0x00000001U);
                    WR1_PROG(REG_0040H, 0x00000d00U);

                    r_rsip_func_sub001(0x00140019U, 0x00280005U, 0x04040002U);

                    r_rsip_func_sub001(0x0014001eU, 0x002d0005U, 0x04040002U);

                    WR1_PROG(REG_0094H, 0x0000b400U);
                    WR1_PROG(REG_0094H, 0x19253b14U);

                    static const uint32_t Param_func088_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xc95d1f17U), BSWAP_32BIG_C(0x26936725U), BSWAP_32BIG_C(0x3db46a16U),
                        BSWAP_32BIG_C(0xabc09f4eU),
                    };
                    r_rsip_func101(Param_func088_func101_005);
                }
            }
        }
    }

    r_rsip_func_sub010(0x38008800U, 0x19253b14U, 0x00A70000U);

    WR1_PROG(REG_0094H, 0x00007c07U);
    WR1_PROG(REG_0040H, 0x00602000U);
}
