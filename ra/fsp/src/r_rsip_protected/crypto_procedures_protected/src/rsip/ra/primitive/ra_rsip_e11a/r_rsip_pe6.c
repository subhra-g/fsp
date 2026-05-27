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

rsip_ret_t r_rsip_pe6 (const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataLength[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00e60001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub016(0x0000b4c0U, 0x00000002U, 0x0000b4e0U);
    r_rsip_func_sub013(0x00000020U, 0x800100a0U);
    WR1_PROG(REG_002CH, InData_KDFInfo_Count[0]);
    r_rsip_func_sub012(0x38000ca5U, 0x00260000U);

    WR1_PROG(REG_0094H, 0x342028c5U);
    WR1_PROG(REG_009CH, 0x00000080U);
    WR1_PROG(REG_0040H, 0x00260000U);

    static const uint32_t Param_pe6_func100_001[] =
    {
        BSWAP_32BIG_C(0x20cfe3d4U), BSWAP_32BIG_C(0x451cc906U), BSWAP_32BIG_C(0x5198b83fU), BSWAP_32BIG_C(0x4604403dU),
    };
    r_rsip_func100(Param_pe6_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe6_func102_001[] =
        {
            BSWAP_32BIG_C(0x30882420U), BSWAP_32BIG_C(0x04d7282eU), BSWAP_32BIG_C(0xa2a6f5c9U), BSWAP_32BIG_C(
                0x163b78b1U),
        };
        r_rsip_func102(Param_pe6_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010080U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_OutDataLength[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x300030a0U, 0x00030020U, 0x00003407U);

        r_rsip_func_sub016(0x00000060U, 0x0000b400U, 0x00000040U);

        r_rsip_func_sub007(0x00000080U, 0x34202887U, 0x00260000U);

        WR1_PROG(REG_0094H, 0x34202804U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00260000U);

        static const uint32_t Param_pe6_func100_002[] =
        {
            BSWAP_32BIG_C(0x08d38495U), BSWAP_32BIG_C(0x920c9e34U), BSWAP_32BIG_C(0x21dd5b37U), BSWAP_32BIG_C(
                0x2d69e0caU),
        };
        r_rsip_func100(Param_pe6_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pe6_func102_002[] =
            {
                BSWAP_32BIG_C(0x03b44537U), BSWAP_32BIG_C(0x4e85c811U), BSWAP_32BIG_C(0xe10cad73U), BSWAP_32BIG_C(
                    0x09555257U),
            };
            r_rsip_func102(Param_pe6_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe6_func100_003[] =
            {
                BSWAP_32BIG_C(0xa5498848U), BSWAP_32BIG_C(0xad3a0e49U), BSWAP_32BIG_C(0x9994f242U), BSWAP_32BIG_C(
                    0xdb8aae74U),
            };
            r_rsip_func100(Param_pe6_func100_003);
            WR1_PROG(REG_009CH, 0x810100a0U);
            WR1_PROG(REG_0008H, 0x00005006U);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_0094H, 0x00000800U);

            WR1_PROG(REG_0094H, 0x00000821U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_0014H, 0x000000c7U);
                WR1_PROG(REG_009CH, 0x800100c0U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_KDFInfo[iLoop * 13]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e601U);

                static const uint32_t Param_pe6_func101_001[] =
                {
                    BSWAP_32BIG_C(0xa209288cU), BSWAP_32BIG_C(0xcd3095b5U), BSWAP_32BIG_C(0xfa236ad6U), BSWAP_32BIG_C(
                        0x506baa04U),
                };
                r_rsip_func101(Param_pe6_func101_001);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x01799093U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e601U);

                static const uint32_t Param_pe6_func101_002[] =
                {
                    BSWAP_32BIG_C(0xe0ce776fU), BSWAP_32BIG_C(0x0321d253U), BSWAP_32BIG_C(0x726bd435U), BSWAP_32BIG_C(
                        0x9ccdc149U),
                };
                r_rsip_func101(Param_pe6_func101_002);
                r_rsip_func044();

                WR1_PROG(REG_0094H, 0x38000c00U);
                WR1_PROG(REG_009CH, 0x00000080U);
                WR1_PROG(REG_0040H, 0x00260000U);

                static const uint32_t Param_pe6_func100_004[] =
                {
                    BSWAP_32BIG_C(0xa49efb84U), BSWAP_32BIG_C(0xb920e982U), BSWAP_32BIG_C(0x2da2a944U), BSWAP_32BIG_C(
                        0xe9f4d000U),
                };
                r_rsip_func100(Param_pe6_func100_004);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_00B0H, 0x00001404U);

                    static const uint32_t Param_pe6_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x9d821e21U), BSWAP_32BIG_C(0x69557f4aU), BSWAP_32BIG_C(0x2a264e32U),
                        BSWAP_32BIG_C(0x529f0444U),
                    };
                    r_rsip_func101(Param_pe6_func101_003);
                }
                else
                {
                    WR1_PROG(REG_00B0H, 0x00001408U);

                    static const uint32_t Param_pe6_func101_004[] =
                    {
                        BSWAP_32BIG_C(0x522d907aU), BSWAP_32BIG_C(0x1f770ed6U), BSWAP_32BIG_C(0xf7e46941U),
                        BSWAP_32BIG_C(0x021e5f78U),
                    };
                    r_rsip_func101(Param_pe6_func101_004);
                }

                r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

                r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

                r_rsip_func_sub008(0x000007c1U, 0x40000100U, 0xf7008d07U);
                WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 1]);
                WAIT_STS(REG_0014H, 31, 1);
                WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 5]);

                WR1_PROG(REG_0000H, 0x00c10021U);
                WAIT_STS(REG_0004H, 30, 0);
                WR1_PROG(REG_0040H, 0x00001800U);

                r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_002CH, &InData_KDFInfo[iLoop * 13 + 9]);

                r_rsip_func_sub006(0x9c100005U, 0x00410011U);

                WR1_PROG(REG_0094H, 0x00002c00U);

                static const uint32_t Param_pe6_func100_005[] =
                {
                    BSWAP_32BIG_C(0xf5346c31U), BSWAP_32BIG_C(0x78de56a8U), BSWAP_32BIG_C(0x8e8558c1U), BSWAP_32BIG_C(
                        0x318405a8U),
                };
                r_rsip_func100(Param_pe6_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_0094H, 0x0000d020U);
                    static const uint32_t Param_pe6_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x82a70818U), BSWAP_32BIG_C(0xf74b476dU), BSWAP_32BIG_C(0x1c8c4240U),
                        BSWAP_32BIG_C(0xf7b38dd5U),
                    };
                    r_rsip_func101(Param_pe6_func101_005);
                }
                else
                {
                    static const uint32_t Param_pe6_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x8c3e0b5fU), BSWAP_32BIG_C(0x68caaa36U), BSWAP_32BIG_C(0x4839b538U),
                        BSWAP_32BIG_C(0xa4a4ef33U),
                    };
                    r_rsip_func101(Param_pe6_func101_006);
                }
            }

            r_rsip_func_sub010(0x38000805U);

            WR1_PROG(REG_0094H, 0x38000c21U);
            WR1_PROG(REG_009CH, 0x00000080U);
            WR1_PROG(REG_0040H, 0x00A60000U);
            static const uint32_t Param_pe6_func100_006[] =
            {
                BSWAP_32BIG_C(0x61cef410U), BSWAP_32BIG_C(0x407b4ca8U), BSWAP_32BIG_C(0xd18323f7U), BSWAP_32BIG_C(
                    0x3ae86062U),
            };
            r_rsip_func100(Param_pe6_func100_006);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe6_func102_003[] =
                {
                    BSWAP_32BIG_C(0xee185f82U), BSWAP_32BIG_C(0xb1aacdcbU), BSWAP_32BIG_C(0xd55d5328U), BSWAP_32BIG_C(
                        0x937f4a2aU),
                };
                r_rsip_func102(Param_pe6_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe6_func100_007[] =
                {
                    BSWAP_32BIG_C(0x200c313bU), BSWAP_32BIG_C(0x5fafe012U), BSWAP_32BIG_C(0x721fb248U), BSWAP_32BIG_C(
                        0x26af1662U),
                };
                r_rsip_func100(Param_pe6_func100_007);
                WR1_PROG(REG_009CH, 0x81010080U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                static const uint32_t Param_pe6_func100_008[] =
                {
                    BSWAP_32BIG_C(0xaaf4aa8dU), BSWAP_32BIG_C(0x44f565f7U), BSWAP_32BIG_C(0x8803a113U), BSWAP_32BIG_C(
                        0x04cce116U),
                };
                r_rsip_func100(Param_pe6_func100_008);
                r_rsip_func103();

                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e602U);

                static const uint32_t Param_pe6_func101_007[] =
                {
                    BSWAP_32BIG_C(0x8d9acd07U), BSWAP_32BIG_C(0xff275fb8U), BSWAP_32BIG_C(0xbee5c178U), BSWAP_32BIG_C(
                        0x22f1762cU),
                };
                r_rsip_func101(Param_pe6_func101_007);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x0000b4c0U);
                WR1_PROG(REG_0094H, 0x01b41ce9U);

                r_rsip_func_sub002(0x800100e0U, 0x0000e602U);

                static const uint32_t Param_pe6_func101_008[] =
                {
                    BSWAP_32BIG_C(0xf9d685d9U), BSWAP_32BIG_C(0xda65a1bfU), BSWAP_32BIG_C(0xe3242dc5U), BSWAP_32BIG_C(
                        0x4f26c0fcU),
                };
                r_rsip_func101(Param_pe6_func101_008);
                r_rsip_func044();

                static const uint32_t Param_pe6_func100_009[] =
                {
                    BSWAP_32BIG_C(0xf14b02fdU), BSWAP_32BIG_C(0x7909695cU), BSWAP_32BIG_C(0x4efa728cU), BSWAP_32BIG_C(
                        0x676d3017U),
                };
                r_rsip_func100(Param_pe6_func100_009);
                WR1_PROG(REG_00B0H, 0x00001804U);
                WR1_PROG(REG_00D4H, 0x40000100U);
                r_rsip_func_sub006(0xe7009d07U, 0x00430021U);

                WR1_PROG(REG_0008H, 0x00001022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[1]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[5]);

                WR1_PROG(REG_0094H, 0x000008e7U);

                r_rsip_func_sub007(0x3420a880U, 0x00000021U, 0x00A60000U);

                static const uint32_t Param_pe6_func100_010[] =
                {
                    BSWAP_32BIG_C(0x00550419U), BSWAP_32BIG_C(0x0a2f8e14U), BSWAP_32BIG_C(0xf6fc9b2fU), BSWAP_32BIG_C(
                        0x5ffd4263U),
                };
                r_rsip_func100(Param_pe6_func100_010);
                WR1_PROG(REG_0040H, 0x00400000U);
                WR1_PROG(REG_0024H, 0x00000000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    WR1_PROG(REG_00B0H, 0x00001808U);
                    r_rsip_func_sub003(0x80880007U, 0x03430021U);

                    static const uint32_t Param_pe6_func101_009[] =
                    {
                        BSWAP_32BIG_C(0xf388c3ceU), BSWAP_32BIG_C(0xfe4ee7f6U), BSWAP_32BIG_C(0x455312f8U),
                        BSWAP_32BIG_C(0x1f2f3a5aU),
                    };
                    r_rsip_func101(Param_pe6_func101_009);
                }

                r_rsip_func_sub016(0x00000842U, 0x0000b460U, 0x00000040U);
                r_rsip_func_sub016(0x00002864U, 0x000008a5U, 0x00003424U);
                WR1_PROG(REG_0094H, 0x0000a820U);
                WR1_PROG(REG_0094H, 0x00000020U);

                for (iLoop = S_RAM[0]; iLoop < 64U; iLoop++)
                {
                    r_rsip_func_sub016(0x02003c41U, 0x00002ca0U, 0x00002c20U);
                    static const uint32_t Param_pe6_func101_010[] =
                    {
                        BSWAP_32BIG_C(0xa168bbb4U), BSWAP_32BIG_C(0x93265c75U), BSWAP_32BIG_C(0x07481254U),
                        BSWAP_32BIG_C(0xdc8828e3U),
                    };
                    r_rsip_func101(Param_pe6_func101_010);
                }

                r_rsip_func_sub010(0x380008a3U);

                static const uint32_t Param_pe6_func100_011[] =
                {
                    BSWAP_32BIG_C(0xce4a06c1U), BSWAP_32BIG_C(0x3c46211fU), BSWAP_32BIG_C(0x3a0c01a5U), BSWAP_32BIG_C(
                        0x3ebd2cceU),
                };
                r_rsip_func100(Param_pe6_func100_011);
                WR1_PROG(REG_0094H, 0x000008e7U);
                WR1_PROG(REG_00D4H, 0x40000100U);
                WR1_PROG(REG_00D0H, 0xe7008d07U);

                r_rsip_func_sub003(0x81880007U, 0x00490021U);
                WR1_PROG(REG_0008H, 0x00001022U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[9]);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[13]);

                static const uint32_t Param_pe6_func100_012[] =
                {
                    BSWAP_32BIG_C(0x809b53f3U), BSWAP_32BIG_C(0xd7da97b2U), BSWAP_32BIG_C(0x2a8b4a5aU), BSWAP_32BIG_C(
                        0x30ff78c7U),
                };
                r_rsip_func100(Param_pe6_func100_012);
                r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                WR1_PROG(REG_00D4H, 0x40000000U);
                r_rsip_func_sub006(0x09108105U, 0x00410011U);

                WR1_PROG(REG_0008H, 0x00001012U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[17]);

                static const uint32_t Param_pe6_func100_013[] =
                {
                    BSWAP_32BIG_C(0xbb10578eU), BSWAP_32BIG_C(0xe0c4fcf5U), BSWAP_32BIG_C(0xcb8e4ce7U), BSWAP_32BIG_C(
                        0x5eeeb4baU),
                };
                r_rsip_func100(Param_pe6_func100_013);
                WR1_PROG(REG_009CH, 0x81010000U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe6_func102_004[] =
                {
                    BSWAP_32BIG_C(0x207a6380U), BSWAP_32BIG_C(0x0c5f9a14U), BSWAP_32BIG_C(0x46862211U), BSWAP_32BIG_C(
                        0x9a010ab7U),
                };
                r_rsip_func102(Param_pe6_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
