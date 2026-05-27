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

rsip_ret_t r_rsip_p90 (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       WRAPPED_KEY_SIZE,
                       uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;
    int32_t  jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00900001U, 0x000001c7U, 0x800200c0U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_WrappedKeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00003407U);

    r_rsip_func_sub007(0x3420a8c0U, 0x00000002U, 0x00A60000U);

    r_rsip_func_sub007(0x3420a800U, 0x00000003U, 0x00A60000U);

    r_rsip_func_sub007(0x38008800U, 0x00000001U, 0x00260000U);

    static const uint32_t Param_p90_func100_001[] =
    {
        BSWAP_32BIG_C(0x00014046U), BSWAP_32BIG_C(0x9f4d276dU), BSWAP_32BIG_C(0x4025a588U), BSWAP_32BIG_C(0x7e7147a3U),
    };
    r_rsip_func100(Param_p90_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p90_func102_001[] =
        {
            BSWAP_32BIG_C(0x2f74a54dU), BSWAP_32BIG_C(0x29126b48U), BSWAP_32BIG_C(0x63187731U), BSWAP_32BIG_C(
                0x73bb1014U),
        };
        r_rsip_func102(Param_p90_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub007(0x00003486U, 0x38000c84U, 0x00260000U);

        static const uint32_t Param_p90_func100_002[] =
        {
            BSWAP_32BIG_C(0x7a75a934U), BSWAP_32BIG_C(0x615d99ddU), BSWAP_32BIG_C(0x3061d32bU), BSWAP_32BIG_C(
                0x2d930e1fU),
        };
        r_rsip_func100(Param_p90_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            r_rsip_func_sub002(0x800100e0U, 0x00000090U);

            static const uint32_t Param_p90_func101_001[] =
            {
                BSWAP_32BIG_C(0xdf466da4U), BSWAP_32BIG_C(0xc77c9b15U), BSWAP_32BIG_C(0x14ae8c91U), BSWAP_32BIG_C(
                    0x58ce2367U),
            };
            r_rsip_func101(Param_p90_func101_001);
            r_rsip_func440(InData_KeyIndex);

            static const uint32_t Param_p90_func100_003[] =
            {
                BSWAP_32BIG_C(0x6e3b8584U), BSWAP_32BIG_C(0x88600ec1U), BSWAP_32BIG_C(0x898d0267U), BSWAP_32BIG_C(
                    0x321352c6U),
            };
            r_rsip_func100(Param_p90_func100_003);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub004(0x00000801U, 0x00430009U);

            r_rsip_func_sub004(0x00000802U, 0x00430009U);

            WR1_PROG(REG_00D4H, 0x00000000U);

            static const uint32_t Param_p90_func101_002[] =
            {
                BSWAP_32BIG_C(0xf2eedabfU), BSWAP_32BIG_C(0x3ca12f26U), BSWAP_32BIG_C(0x78c8dedfU), BSWAP_32BIG_C(
                    0xabdd1047U),
            };
            r_rsip_func101(Param_p90_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000007U);

            r_rsip_func_sub002(0x800100e0U, 0x00000090U);

            static const uint32_t Param_p90_func101_003[] =
            {
                BSWAP_32BIG_C(0xe25a67a9U), BSWAP_32BIG_C(0x23f56bd0U), BSWAP_32BIG_C(0xefc3758fU), BSWAP_32BIG_C(
                    0xdf5be74cU),
            };
            r_rsip_func101(Param_p90_func101_003);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_p90_func100_004[] =
            {
                BSWAP_32BIG_C(0x5fd1f896U), BSWAP_32BIG_C(0xce5bf3d3U), BSWAP_32BIG_C(0x5a740d79U), BSWAP_32BIG_C(
                    0x991abba9U),
            };
            r_rsip_func100(Param_p90_func100_004);
            WR1_PROG(REG_00D0H, 0x08000085U);
            r_rsip_func_sub004(0x0000181eU, 0x00430011U);

            static const uint32_t Param_p90_func100_005[] =
            {
                BSWAP_32BIG_C(0x98dbdbe9U), BSWAP_32BIG_C(0x43f2c012U), BSWAP_32BIG_C(0xb1a6df20U), BSWAP_32BIG_C(
                    0x4ac5f672U),
            };
            r_rsip_func100(Param_p90_func100_005);
            r_rsip_func_sub006(0x08000095U, 0x00430011U);

            WR1_PROG(REG_00D4H, 0x40000000U);

            static const uint32_t Param_p90_func101_004[] =
            {
                BSWAP_32BIG_C(0x4cf5631fU), BSWAP_32BIG_C(0x34e2c3ffU), BSWAP_32BIG_C(0xc89b74daU), BSWAP_32BIG_C(
                    0xeb763b87U),
            };
            r_rsip_func101(Param_p90_func101_004);
        }

        static const uint32_t Param_p90_func100_006[] =
        {
            BSWAP_32BIG_C(0xdf6c721bU), BSWAP_32BIG_C(0x459ecad6U), BSWAP_32BIG_C(0x09647fe1U), BSWAP_32BIG_C(
                0xfada669cU),
        };
        r_rsip_func100(Param_p90_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p90_func102_002[] =
            {
                BSWAP_32BIG_C(0xa61ca121U), BSWAP_32BIG_C(0xd0f8d815U), BSWAP_32BIG_C(0x9996d866U), BSWAP_32BIG_C(
                    0x2284e80aU),
            };
            r_rsip_func102(Param_p90_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            WR1_PROG(REG_0094H, 0x00002ca0U);

            WR1_PROG(REG_00D0H, 0x08000044U);
            r_rsip_func_sub003(0x810100c0U, 0x00490005U);

            WR1_PROG(REG_00D0H, 0x08000054U);
            r_rsip_func_sub003(0x810100e0U, 0x00490005U);

            WR1_PROG(REG_0014H, 0x000001c7U);
            WR1_PROG(REG_009CH, 0x80020000U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_Text[0]);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_Text[1]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub016(0x00000884U, 0x00000863U, 0x00002c60U);

            for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; )
            {
                WR1_PROG(REG_0014H, 0x000001c7U);
                WR1_PROG(REG_009CH, 0x80820004U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Text[iLoop]);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Text[iLoop + 1]);
                WR1_PROG(REG_0024H, 0x00000000U);

                r_rsip_func_sub016(0x0000a480U, 0x00000008U, 0x00002c60U);

                static const uint32_t Param_p90_func101_005[] =
                {
                    BSWAP_32BIG_C(0x143b45ecU), BSWAP_32BIG_C(0xd0e1b81fU), BSWAP_32BIG_C(0x6beb14b3U), BSWAP_32BIG_C(
                        0xe9ec3c67U),
                };
                r_rsip_func101(Param_p90_func101_005);
                iLoop = iLoop + 2;
            }

            r_rsip_func_sub010(0x38000865U);

            WR1_PROG(REG_0094H, 0x0000a880U);
            WR1_PROG(REG_0094H, 0x00000008U);

            WR1_PROG(REG_00D0H, 0x08000065U);
            r_rsip_func_sub003(0x81020080U, 0x00490009U);
            r_rsip_func_sub009(0x00400009U, 0x000034c5U);
            r_rsip_func_sub016(0x000030c0U, 0x00003486U, 0x00026c84U);
            r_rsip_func_sub016(0x00016cc6U, 0x00002486U, 0x000008a5U);

            for (jLoop = 5; jLoop >= 0; jLoop = jLoop - 1)
            {
                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x800100e0U, 0x03410005U);

                r_rsip_func_sub003(0x800100c0U, 0x03410005U);
                r_rsip_func_sub009(0x00010009U, 0x000030c0U);

                for (iLoop = (WRAPPED_KEY_SIZE / 2) - 1; iLoop >= 1; iLoop = iLoop - 1)
                {
                    WR1_PROG(REG_0094H, 0x00000824U);

                    WR1_PROG(REG_00D0H, 0x0a00810dU);
                    r_rsip_func_sub003(0x81020000U, 0x00490009U);
                    r_rsip_func_sub003(0x81820007U, 0x00490009U);

                    r_rsip_func_sub003(0x80040000U, 0x03410011U);

                    r_rsip_func_sub016(0x00003c47U, 0x0000a4e0U, 0x00000004U);
                    r_rsip_func_sub016(0x00003c67U, 0x0000a8e0U, 0x0000000cU);

                    WR1_PROG(REG_0094H, 0x00003080U);

                    WR1_PROG(REG_0094H, 0x000030c0U);

                    static const uint32_t Param_p90_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xc232f32dU), BSWAP_32BIG_C(0x84747eabU), BSWAP_32BIG_C(0xcbb2b5b4U),
                        BSWAP_32BIG_C(0xfa96e8a8U),
                    };
                    r_rsip_func101(Param_p90_func101_006);
                }

                r_rsip_func_sub010(0x38000cc6U);

                WR1_PROG(REG_0094H, 0x00002ca0U);

                static const uint32_t Param_p90_func101_007[] =
                {
                    BSWAP_32BIG_C(0x8a239735U), BSWAP_32BIG_C(0xccc0343bU), BSWAP_32BIG_C(0xb35704f0U), BSWAP_32BIG_C(
                        0x9c9c21f3U),
                };
                r_rsip_func101(Param_p90_func101_007);
            }

            r_rsip_func_sub007(0x380088a0U, 0x00000006U, 0x00260000U);

            WR1_PROG(REG_0040H, 0x00402000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub007(0x38008800U, 0xa6a6a6a6U, 0x00A60000U);

            r_rsip_func_sub007(0x38008820U, 0xa6a6a6a6U, 0x00A60000U);

            static const uint32_t Param_p90_func100_007[] =
            {
                BSWAP_32BIG_C(0x843a96b4U), BSWAP_32BIG_C(0xd4bdef13U), BSWAP_32BIG_C(0xbe59b4d7U), BSWAP_32BIG_C(
                    0xa5f221f7U),
            };
            r_rsip_func100(Param_p90_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p90_func102_003[] =
                {
                    BSWAP_32BIG_C(0x852cd333U), BSWAP_32BIG_C(0x5cf1eea8U), BSWAP_32BIG_C(0x7a724b27U), BSWAP_32BIG_C(
                        0xce8b6148U),
                };
                r_rsip_func102(Param_p90_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p90_func100_008[] =
                {
                    BSWAP_32BIG_C(0xd6579601U), BSWAP_32BIG_C(0x68ff4a7dU), BSWAP_32BIG_C(0x2d789293U), BSWAP_32BIG_C(
                        0x8f5c7227U),
                };
                r_rsip_func100(Param_p90_func100_008);

                WR1_PROG(REG_0094H, 0x00000842U);
                WR1_PROG(REG_009CH, 0x81880002U);
                r_rsip_func_sub004(0x00001404U, 0x00c90021U);

                r_rsip_func_sub005(0x000000a1U, 0x0c100104U, 0x00000000U);

                r_rsip_func_sub003(0x80010020U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x0000a820U);
                WR1_PROG(REG_0094H, 0x00000005U);

                r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                r_rsip_func_sub003(0x80010080U, 0x03410005U);
                WR1_PROG(REG_0000H, 0x0001000dU);
                WAIT_STS(REG_0004H, 30, 0);
                WR1_PROG(REG_0040H, 0x00001800U);

                r_rsip_func103();
                r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

                r_rsip_func_sub003(0x80010000U, 0x03410005U);
                r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

                r_rsip_func_sub002(0x800100e0U, 0x00000090U);

                static const uint32_t Param_p90_func101_008[] =
                {
                    BSWAP_32BIG_C(0xf7081179U), BSWAP_32BIG_C(0x9cade6a2U), BSWAP_32BIG_C(0x96a5a8c0U), BSWAP_32BIG_C(
                        0xab6ac2f0U),
                };
                r_rsip_func101(Param_p90_func101_008);
                r_rsip_func143();

                WR1_PROG(REG_0094H, 0x000034c4U);

                r_rsip_func_sub002(0x800100e0U, 0x00000090U);

                static const uint32_t Param_p90_func101_009[] =
                {
                    BSWAP_32BIG_C(0x848a98a7U), BSWAP_32BIG_C(0x4a94b3f8U), BSWAP_32BIG_C(0xd8c178eeU), BSWAP_32BIG_C(
                        0xe21ab8bdU),
                };
                r_rsip_func101(Param_p90_func101_009);
                r_rsip_func044();

                WR1_PROG(REG_0094H, 0x00000842U);
                WR1_PROG(REG_00B0H, 0x00001804U);
                r_rsip_func_sub003(0x80880002U, 0x03430021U);

                WR1_PROG(REG_0094H, 0x000008e7U);

                r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

                r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

                WR1_PROG(REG_0094H, 0x00000884U);

                for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
                {
                    r_rsip_func_sub016(0x000008c6U, 0x34202881U, 0x2000d0c0U);

                    WR1_PROG(REG_0094H, 0x00007c06U);
                    WR1_PROG(REG_0040H, 0x00602000U);
                    WR1_PROG(REG_0024H, 0x00000000U);

                    static const uint32_t Param_p90_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x41d44a4eU), BSWAP_32BIG_C(0x5489e84cU), BSWAP_32BIG_C(0x0ff51badU),
                        BSWAP_32BIG_C(0x91c4665bU),
                    };
                    r_rsip_func100(Param_p90_func100_009);
                    WR1_PROG(REG_00D4H, 0x40000000U);
                    WR1_PROG(REG_00D0H, 0xe7008d05U);
                    r_rsip_func_sub003(0x81840007U, 0x00490011U);

                    WR1_PROG(REG_0008H, 0x00001012U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_KeyIndex[iLoop + 1]);

                    r_rsip_func_sub016(0x0000a4e0U, 0x00000010U, 0x0000a480U);
                    WR1_PROG(REG_0094H, 0x00000004U);

                    static const uint32_t Param_p90_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x4a33f8c2U), BSWAP_32BIG_C(0x929a25eaU), BSWAP_32BIG_C(0xb8ff5213U),
                        BSWAP_32BIG_C(0xab785803U),
                    };
                    r_rsip_func101(Param_p90_func101_010);
                    iLoop = iLoop + 4U;
                }

                r_rsip_func_sub010(0x38000881U);

                static const uint32_t Param_p90_func100_010[] =
                {
                    BSWAP_32BIG_C(0x8929bd67U), BSWAP_32BIG_C(0xc2048be5U), BSWAP_32BIG_C(0x96d0004aU), BSWAP_32BIG_C(
                        0xeb1102ecU),
                };
                r_rsip_func100(Param_p90_func100_010);
                r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

                WR1_PROG(REG_00D4H, 0x40000000U);
                r_rsip_func_sub006(0x09108105U, 0x00410011U);

                WR1_PROG(REG_0008H, 0x00001012U);
                WAIT_STS(REG_0008H, 30, 1);
                RD4_ADDR(REG_002CH, &OutData_KeyIndex[iLoop + 1]);

                static const uint32_t Param_p90_func100_011[] =
                {
                    BSWAP_32BIG_C(0x2c271bc7U), BSWAP_32BIG_C(0x89f679d0U), BSWAP_32BIG_C(0x94e34e74U), BSWAP_32BIG_C(
                        0xd850e47cU),
                };
                r_rsip_func100(Param_p90_func100_011);
                WR1_PROG(REG_009CH, 0x81010000U);
                WR1_PROG(REG_0008H, 0x00005006U);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

                static const uint32_t Param_p90_func102_004[] =
                {
                    BSWAP_32BIG_C(0x86bebb64U), BSWAP_32BIG_C(0x34fae816U), BSWAP_32BIG_C(0x99af984fU), BSWAP_32BIG_C(
                        0x320ae070U),
                };
                r_rsip_func102(Param_p90_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
