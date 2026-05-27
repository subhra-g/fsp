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

rsip_ret_t r_rsip_p95i (const uint32_t InData_KeyType[],
                        const uint32_t InData_DataType[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_TextLen[],
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

    WR1_PROG(REG_1B00H, 0x00950001U);
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

    r_rsip_func_sub006(0x38008800U, 0x00000004U, 0x00260000U);

    static const uint32_t Param_p95i_func100_001[] =
    {
        BSWAP_32BIG_C(0x28fe8c10U), BSWAP_32BIG_C(0x351c0eadU), BSWAP_32BIG_C(0x802ce382U), BSWAP_32BIG_C(0xbf51357eU),
    };
    r_rsip_func100(Param_p95i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub006(0x3420a920U, 0x00004101U, 0x00A60000U);

        static const uint32_t Param_p95i_func101_001[] =
        {
            BSWAP_32BIG_C(0x42640d0bU), BSWAP_32BIG_C(0xee27a885U), BSWAP_32BIG_C(0x330402edU), BSWAP_32BIG_C(
                0x54459ca6U),
        };
        r_rsip_func101(Param_p95i_func101_001);
    }

    r_rsip_func_sub006(0x38008800U, 0x00000001U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000003U, 0x00260000U);

    static const uint32_t Param_p95i_func100_002[] =
    {
        BSWAP_32BIG_C(0x6c3c524fU), BSWAP_32BIG_C(0x31422a56U), BSWAP_32BIG_C(0x61f0cf00U), BSWAP_32BIG_C(0x53c27a42U),
    };
    r_rsip_func100(Param_p95i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p95i_func102_001[] =
        {
            BSWAP_32BIG_C(0xe8526d3aU), BSWAP_32BIG_C(0x2922e025U), BSWAP_32BIG_C(0xe8c8ffd0U), BSWAP_32BIG_C(
                0x09be2a1bU),
        };
        r_rsip_func102(Param_p95i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub006(0x3420a800U, 0x00000004U, 0x00260000U);

        static const uint32_t Param_p95i_func100_003[] =
        {
            BSWAP_32BIG_C(0x6db572deU), BSWAP_32BIG_C(0x87930f61U), BSWAP_32BIG_C(0x5d49264cU), BSWAP_32BIG_C(
                0xb83417eeU),
        };
        r_rsip_func100(Param_p95i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p95i_func100_004[] =
            {
                BSWAP_32BIG_C(0xe4dc1b19U), BSWAP_32BIG_C(0x00bc5646U), BSWAP_32BIG_C(0xbe08c9f4U), BSWAP_32BIG_C(
                    0x55c74592U),
            };
            r_rsip_func100(Param_p95i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000095U);

                static const uint32_t Param_p95i_func101_002[] =
                {
                    BSWAP_32BIG_C(0xe43624e0U), BSWAP_32BIG_C(0xe4b1a9c2U), BSWAP_32BIG_C(0xb8468791U), BSWAP_32BIG_C(
                        0x1f1e7a18U),
                };
                r_rsip_func101(Param_p95i_func101_002);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x00000005U);

                static const uint32_t Param_p95i_func101_003[] =
                {
                    BSWAP_32BIG_C(0xfa9d7930U), BSWAP_32BIG_C(0xaa0bf54bU), BSWAP_32BIG_C(0x681d26f1U), BSWAP_32BIG_C(
                        0x8f9da5eeU),
                };
                r_rsip_func101(Param_p95i_func101_003);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010140U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000095U);

                static const uint32_t Param_p95i_func101_004[] =
                {
                    BSWAP_32BIG_C(0xbda29cb3U), BSWAP_32BIG_C(0x3eb81b4fU), BSWAP_32BIG_C(0x3851b8bcU), BSWAP_32BIG_C(
                        0x2730facdU),
                };
                r_rsip_func101(Param_p95i_func101_004);
                r_rsip_func068();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x2a46c04bU);

                static const uint32_t Param_p95i_func101_005[] =
                {
                    BSWAP_32BIG_C(0xa3fbc8bcU), BSWAP_32BIG_C(0x9e3acd2fU), BSWAP_32BIG_C(0xba61703aU), BSWAP_32BIG_C(
                        0xbdeaebb7U),
                };
                r_rsip_func101(Param_p95i_func101_005);
            }

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000095U);

            static const uint32_t Param_p95i_func101_006[] =
            {
                BSWAP_32BIG_C(0x2da82aaaU), BSWAP_32BIG_C(0xba91ffe4U), BSWAP_32BIG_C(0xb15309d1U), BSWAP_32BIG_C(
                    0x82b077b6U),
            };
            r_rsip_func101(Param_p95i_func101_006);
            r_rsip_func044();

            static const uint32_t Param_p95i_func100_005[] =
            {
                BSWAP_32BIG_C(0xd89a5596U), BSWAP_32BIG_C(0x79932fb5U), BSWAP_32BIG_C(0xce04f76bU), BSWAP_32BIG_C(
                    0x52970cf7U),
            };
            r_rsip_func100(Param_p95i_func100_005);
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_func_sub001(0x00420011U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p95i_func101_007[] =
            {
                BSWAP_32BIG_C(0x4272e8daU), BSWAP_32BIG_C(0xf35091c0U), BSWAP_32BIG_C(0x8eecf4cdU), BSWAP_32BIG_C(
                    0xb3c1a270U),
            };
            r_rsip_func101(Param_p95i_func101_007);
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

            static const uint32_t Param_p95i_func100_006[] =
            {
                BSWAP_32BIG_C(0x04b09d73U), BSWAP_32BIG_C(0xf03a84ccU), BSWAP_32BIG_C(0x99c99ec4U), BSWAP_32BIG_C(
                    0x2cd0aab4U),
            };
            r_rsip_func100(Param_p95i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010000U);
                WR1_PROG(REG_1420H, InData_Cmd[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub025(0x000036a0U, 0x0000b6c0U, 0x4cc18a1aU);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000095U);

                static const uint32_t Param_p95i_func101_008[] =
                {
                    BSWAP_32BIG_C(0x4bb3c619U), BSWAP_32BIG_C(0x3cf25d1bU), BSWAP_32BIG_C(0x53cf2426U), BSWAP_32BIG_C(
                        0x323544fdU),
                };
                r_rsip_func101(Param_p95i_func101_008);
                r_rsip_func092();

                static const uint32_t Param_p95i_func101_009[] =
                {
                    BSWAP_32BIG_C(0xad03e763U), BSWAP_32BIG_C(0xf463fa26U), BSWAP_32BIG_C(0x4023d4e6U), BSWAP_32BIG_C(
                        0x6dd2bee7U),
                };
                r_rsip_func101(Param_p95i_func101_009);
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000dfU);

                static const uint32_t Param_p95i_func101_010[] =
                {
                    BSWAP_32BIG_C(0xb16f26f4U), BSWAP_32BIG_C(0x38f5e084U), BSWAP_32BIG_C(0x529da794U), BSWAP_32BIG_C(
                        0xd4b85e49U),
                };
                r_rsip_func101(Param_p95i_func101_010);
                r_rsip_func068();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x6ad6575eU);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000ebU);

                static const uint32_t Param_p95i_func101_011[] =
                {
                    BSWAP_32BIG_C(0x91435511U), BSWAP_32BIG_C(0x21b8a36fU), BSWAP_32BIG_C(0x3e71e1d9U), BSWAP_32BIG_C(
                        0x6cc7ecf8U),
                };
                r_rsip_func101(Param_p95i_func101_011);
                r_rsip_func044();

                static const uint32_t Param_p95i_func101_012[] =
                {
                    BSWAP_32BIG_C(0x21b0e26aU), BSWAP_32BIG_C(0x7f26f817U), BSWAP_32BIG_C(0x433805deU), BSWAP_32BIG_C(
                        0x61c4c017U),
                };
                r_rsip_func101(Param_p95i_func101_012);
            }

            static const uint32_t Param_p95i_func100_007[] =
            {
                BSWAP_32BIG_C(0xffb15aefU), BSWAP_32BIG_C(0xb1a0c5cdU), BSWAP_32BIG_C(0x3a281150U), BSWAP_32BIG_C(
                    0x3b326628U),
            };
            r_rsip_func100(Param_p95i_func100_007);
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

            static const uint32_t Param_p95i_func101_013[] =
            {
                BSWAP_32BIG_C(0x5c27ea77U), BSWAP_32BIG_C(0x451a92afU), BSWAP_32BIG_C(0x0e946632U), BSWAP_32BIG_C(
                    0x71657b58U),
            };
            r_rsip_func101(Param_p95i_func101_013);
        }

        static const uint32_t Param_p95i_func100_008[] =
        {
            BSWAP_32BIG_C(0x18e89b1bU), BSWAP_32BIG_C(0x24ad6f3bU), BSWAP_32BIG_C(0x9714058aU), BSWAP_32BIG_C(
                0xa6e54852U),
        };
        r_rsip_func100(Param_p95i_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p95i_func102_002[] =
            {
                BSWAP_32BIG_C(0x863a2e91U), BSWAP_32BIG_C(0x291c0f32U), BSWAP_32BIG_C(0x94f4fb73U), BSWAP_32BIG_C(
                    0xadd64ef2U),
            };
            r_rsip_func102(Param_p95i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00003412U);

            r_rsip_func_sub006(0x3420a800U, 0x00000004U, 0x00260000U);

            static const uint32_t Param_p95i_func100_009[] =
            {
                BSWAP_32BIG_C(0x295088a0U), BSWAP_32BIG_C(0x2144fe6eU), BSWAP_32BIG_C(0x9457b560U), BSWAP_32BIG_C(
                    0x204b5d40U),
            };
            r_rsip_func100(Param_p95i_func100_009);
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

                static const uint32_t Param_p95i_func101_014[] =
                {
                    BSWAP_32BIG_C(0x6a10897eU), BSWAP_32BIG_C(0xc1e73e37U), BSWAP_32BIG_C(0x1cd4acceU), BSWAP_32BIG_C(
                        0x5c2c8f55U),
                };
                r_rsip_func101(Param_p95i_func101_014);
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

                WR1_PROG(REG_1600H, 0x0000b540U);
                WR1_PROG(REG_1600H, 0x00000010U);
                r_rsip_func031(InData_Header);

                static const uint32_t Param_p95i_func101_015[] =
                {
                    BSWAP_32BIG_C(0x0934175bU), BSWAP_32BIG_C(0x6529f37bU), BSWAP_32BIG_C(0x7d0c1e5cU), BSWAP_32BIG_C(
                        0xb987c71fU),
                };
                r_rsip_func101(Param_p95i_func101_015);
            }

            return RSIP_RET_PASS;
        }
    }
}
