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

rsip_ret_t r_rsip_p98i (const uint32_t InData_KeyType[],
                        const uint32_t InData_DataType[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_MACLength[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        const uint32_t InData_SeqNum[],
                        uint32_t       Header_Len)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00980001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x0a4500e5U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &S_RAM[16 + 0]);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00003640U);

    r_rsip_func_sub010(0x000000c7U, 0x80010120U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00003689U);

    r_rsip_func_sub006(0x3420a800U, 0x00000004U, 0x00260000U);

    static const uint32_t Param_p98i_func100_001[] =
    {
        BSWAP_32BIG_C(0x07f7d3adU), BSWAP_32BIG_C(0xe7e18e46U), BSWAP_32BIG_C(0x0c7c9777U), BSWAP_32BIG_C(0x08fcd417U),
    };
    r_rsip_func100(Param_p98i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010140U);
        WR1_PROG(REG_1420H, InData_MACLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p98i_func101_001[] =
        {
            BSWAP_32BIG_C(0xd2d21e10U), BSWAP_32BIG_C(0x38dc7f8cU), BSWAP_32BIG_C(0x571b1409U), BSWAP_32BIG_C(
                0x03814f66U),
        };
        r_rsip_func101(Param_p98i_func101_001);
    }
    else
    {
        WR1_PROG(REG_1600H, 0x0000b540U);
        WR1_PROG(REG_1600H, 0x00000010U);

        r_rsip_func_sub006(0x3420a920U, 0x00004101U, 0x00A60000U);

        static const uint32_t Param_p98i_func101_002[] =
        {
            BSWAP_32BIG_C(0xb80412b3U), BSWAP_32BIG_C(0x6a869691U), BSWAP_32BIG_C(0xc5f6796aU), BSWAP_32BIG_C(
                0x08883696U),
        };
        r_rsip_func101(Param_p98i_func101_002);
    }

    WR1_PROG(REG_1600H, 0x0000366aU);

    r_rsip_func_sub006(0x38008800U, 0x00000001U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000003U, 0x00260000U);

    static const uint32_t Param_p98i_func100_002[] =
    {
        BSWAP_32BIG_C(0x780f33baU), BSWAP_32BIG_C(0xe21013f8U), BSWAP_32BIG_C(0xbd489679U), BSWAP_32BIG_C(0x21a911e8U),
    };
    r_rsip_func100(Param_p98i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p98i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc08b2bd8U), BSWAP_32BIG_C(0x2650909dU), BSWAP_32BIG_C(0x0be12f4eU), BSWAP_32BIG_C(
                0x33e8bbb0U),
        };
        r_rsip_func102(Param_p98i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x3420a800U, 0x00000004U, 0x00260000U);

        static const uint32_t Param_p98i_func100_003[] =
        {
            BSWAP_32BIG_C(0x1377180bU), BSWAP_32BIG_C(0xd0efb08bU), BSWAP_32BIG_C(0xa4dd7d8eU), BSWAP_32BIG_C(
                0xf599f9b8U),
        };
        r_rsip_func100(Param_p98i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p98i_func100_004[] =
            {
                BSWAP_32BIG_C(0xeb3e68bdU), BSWAP_32BIG_C(0x1624ece4U), BSWAP_32BIG_C(0xaef68fe4U), BSWAP_32BIG_C(
                    0x8295253aU),
            };
            r_rsip_func100(Param_p98i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000098U);

                static const uint32_t Param_p98i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x2a6743e3U), BSWAP_32BIG_C(0xc5f99062U), BSWAP_32BIG_C(0xc0036048U), BSWAP_32BIG_C(
                        0xcd77e7beU),
                };
                r_rsip_func101(Param_p98i_func101_003);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x00000005U);

                static const uint32_t Param_p98i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xfb66bbdeU), BSWAP_32BIG_C(0x0dc61ec7U), BSWAP_32BIG_C(0x01c0c80bU), BSWAP_32BIG_C(
                        0xfe5079ffU),
                };
                r_rsip_func101(Param_p98i_func101_004);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010140U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000098U);

                static const uint32_t Param_p98i_func101_005[] =
                {
                    BSWAP_32BIG_C(0xf326e5f9U), BSWAP_32BIG_C(0x3b4f3a4dU), BSWAP_32BIG_C(0x85f9f081U), BSWAP_32BIG_C(
                        0xeeb7a449U),
                };
                r_rsip_func101(Param_p98i_func101_005);
                r_rsip_func068();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x2a46c04bU);

                static const uint32_t Param_p98i_func101_006[] =
                {
                    BSWAP_32BIG_C(0xad61608bU), BSWAP_32BIG_C(0xb4f1990aU), BSWAP_32BIG_C(0xbccbb331U), BSWAP_32BIG_C(
                        0xb2ec6be9U),
                };
                r_rsip_func101(Param_p98i_func101_006);
            }

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000098U);

            static const uint32_t Param_p98i_func101_007[] =
            {
                BSWAP_32BIG_C(0xd7b6888bU), BSWAP_32BIG_C(0x53b1ffbbU), BSWAP_32BIG_C(0xf528690eU), BSWAP_32BIG_C(
                    0xf634547dU),
            };
            r_rsip_func101(Param_p98i_func101_007);
            r_rsip_func044();

            static const uint32_t Param_p98i_func100_005[] =
            {
                BSWAP_32BIG_C(0xdfb9e6fdU), BSWAP_32BIG_C(0x038dc6bcU), BSWAP_32BIG_C(0x3baba902U), BSWAP_32BIG_C(
                    0xdc91ad82U),
            };
            r_rsip_func100(Param_p98i_func100_005);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p98i_func101_008[] =
            {
                BSWAP_32BIG_C(0x0dd4724eU), BSWAP_32BIG_C(0x002c51f3U), BSWAP_32BIG_C(0xa7562e3fU), BSWAP_32BIG_C(
                    0xb0530559U),
            };
            r_rsip_func101(Param_p98i_func101_008);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010140U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub010(0x000000c7U, 0x80010020U);
            WR1_PROG(REG_1420H, InData_DataType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c21U, 0x00260000U);

            static const uint32_t Param_p98i_func100_006[] =
            {
                BSWAP_32BIG_C(0xb1483cf3U), BSWAP_32BIG_C(0x9395000fU), BSWAP_32BIG_C(0xbf42cfbdU), BSWAP_32BIG_C(
                    0x47e0d856U),
            };
            r_rsip_func100(Param_p98i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010000U);
                WR1_PROG(REG_1420H, InData_Cmd[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub025(0x000036a0U, 0x0000b6c0U, 0x8026ee7fU);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000098U);

                static const uint32_t Param_p98i_func101_009[] =
                {
                    BSWAP_32BIG_C(0x7c0fea46U), BSWAP_32BIG_C(0x86f3c34aU), BSWAP_32BIG_C(0x85bc3dffU), BSWAP_32BIG_C(
                        0xee522f80U),
                };
                r_rsip_func101(Param_p98i_func101_009);
                r_rsip_func092();

                static const uint32_t Param_p98i_func101_010[] =
                {
                    BSWAP_32BIG_C(0xee21bc6fU), BSWAP_32BIG_C(0x78c6b471U), BSWAP_32BIG_C(0x2f5d5cb8U), BSWAP_32BIG_C(
                        0x0baa76d7U),
                };
                r_rsip_func101(Param_p98i_func101_010);
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000003U);

                static const uint32_t Param_p98i_func101_011[] =
                {
                    BSWAP_32BIG_C(0xbd535448U), BSWAP_32BIG_C(0x23995423U), BSWAP_32BIG_C(0x703ed7f2U), BSWAP_32BIG_C(
                        0x28c7c4daU),
                };
                r_rsip_func101(Param_p98i_func101_011);
                r_rsip_func068();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x98bae316U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000ccU);

                static const uint32_t Param_p98i_func101_012[] =
                {
                    BSWAP_32BIG_C(0x311549fdU), BSWAP_32BIG_C(0x4178cdfdU), BSWAP_32BIG_C(0x85f2e598U), BSWAP_32BIG_C(
                        0xdefc168fU),
                };
                r_rsip_func101(Param_p98i_func101_012);
                r_rsip_func044();

                static const uint32_t Param_p98i_func101_013[] =
                {
                    BSWAP_32BIG_C(0x03fc24f6U), BSWAP_32BIG_C(0xb2214770U), BSWAP_32BIG_C(0x5f764c4dU), BSWAP_32BIG_C(
                        0xe34f086eU),
                };
                r_rsip_func101(Param_p98i_func101_013);
            }

            static const uint32_t Param_p98i_func100_007[] =
            {
                BSWAP_32BIG_C(0x2800bbc9U), BSWAP_32BIG_C(0x8f5414aeU), BSWAP_32BIG_C(0x937101efU), BSWAP_32BIG_C(
                    0x349a0e0aU),
            };
            r_rsip_func100(Param_p98i_func100_007);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1608H, 0x80040080U);
            r_rsip_func_sub001(0x03420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p98i_func101_014[] =
            {
                BSWAP_32BIG_C(0x48f2ab55U), BSWAP_32BIG_C(0xec4d6b94U), BSWAP_32BIG_C(0x821c67e2U), BSWAP_32BIG_C(
                    0xf5e5b8c6U),
            };
            r_rsip_func101(Param_p98i_func101_014);
        }

        static const uint32_t Param_p98i_func100_008[] =
        {
            BSWAP_32BIG_C(0x1e044adeU), BSWAP_32BIG_C(0x56e26d1cU), BSWAP_32BIG_C(0xfa4cf9b6U), BSWAP_32BIG_C(
                0x24ff0d46U),
        };
        r_rsip_func100(Param_p98i_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p98i_func102_002[] =
            {
                BSWAP_32BIG_C(0x58130d85U), BSWAP_32BIG_C(0x1f1691b3U), BSWAP_32BIG_C(0x8234a9b0U), BSWAP_32BIG_C(
                    0xd8aba884U),
            };
            r_rsip_func102(Param_p98i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub025(0x00003534U, 0x00003553U, 0x00003412U);

            r_rsip_func_sub006(0x3420a800U, 0x00000004U, 0x00260000U);

            static const uint32_t Param_p98i_func100_009[] =
            {
                BSWAP_32BIG_C(0xfee8981dU), BSWAP_32BIG_C(0xd8fd762aU), BSWAP_32BIG_C(0x780dde0aU), BSWAP_32BIG_C(
                    0x7c586fe9U),
            };
            r_rsip_func100(Param_p98i_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000145U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                WR1_PROG(REG_1824H, 0x08000065U);
                r_rsip_func_sub001(0x00410011U);

                r_rsip_func_sub020(0x000000a1U, 0x07000c04U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                r_rsip_func_sub020(0x000000a1U, 0x08000054U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                WR1_PROG(REG_1444H, 0x00020061U);
                WR1_PROG(REG_1824H, 0xf8000006U);

                for (iLoop = 0U; iLoop < Header_Len; )
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_Header[iLoop]);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func216();

                static const uint32_t Param_p98i_func101_015[] =
                {
                    BSWAP_32BIG_C(0xedd9569fU), BSWAP_32BIG_C(0x05dccab3U), BSWAP_32BIG_C(0x413b5813U), BSWAP_32BIG_C(
                        0xb1f5ea28U),
                };
                r_rsip_func101(Param_p98i_func101_015);
            }
            else
            {
                r_rsip_func_sub010(0x000001c7U, 0x800201c0U);
                WR1_PROG(REG_1420H, InData_SeqNum[0]);
                WAIT_STS(REG_1444H, 31, 1);
                WR1_PROG(REG_1420H, InData_SeqNum[1]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub024(0x000008aeU, 0x000008cfU, 0x0000b460U, 0x00000002U);

                r_rsip_func_sub024(0x01986c64U, 0x01986c85U, 0x01986ca6U, 0x00186cc6U);

                WR1_PROG(REG_1824H, 0x08000145U);
                WR1_PROG(REG_1608H, 0x81040060U);
                r_rsip_func_sub001(0x00490011U);

                WR1_PROG(REG_1824H, 0x08000065U);
                r_rsip_func_sub001(0x00410011U);

                r_rsip_func_sub020(0x000000a1U, 0x07000c04U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                r_rsip_func_sub020(0x000000a1U, 0x08000054U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                r_rsip_func031(InData_Header);

                static const uint32_t Param_p98i_func101_016[] =
                {
                    BSWAP_32BIG_C(0x3e8ee2feU), BSWAP_32BIG_C(0xbcf98c4eU), BSWAP_32BIG_C(0x5adc5e56U), BSWAP_32BIG_C(
                        0xc1ae4c8bU),
                };
                r_rsip_func101(Param_p98i_func101_016);
            }

            return RSIP_RET_PASS;
        }
    }
}
