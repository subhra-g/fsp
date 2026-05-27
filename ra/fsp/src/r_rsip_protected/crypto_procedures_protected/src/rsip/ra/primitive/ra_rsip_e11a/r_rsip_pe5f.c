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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        uint32_t       OutData_KDFInfo[],
                        uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x800100a0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x000008e7U, 0x300088a0U, 0x00000000U);
    r_rsip_func_sub016(0x00030020U, 0x00002ce0U, 0x00000080U);

    r_rsip_func_sub016(0x300088a0U, 0x0000000dU, 0x00030020U);

    WR1_PROG(REG_0094H, 0x00002ce0U);

    r_rsip_func_sub007(0x00000080U, 0x38000ce7U, 0x00260000U);

    static const uint32_t Param_pe5f_func100_001[] =
    {
        BSWAP_32BIG_C(0x44f4025eU), BSWAP_32BIG_C(0x9b213911U), BSWAP_32BIG_C(0x9da2ee54U), BSWAP_32BIG_C(0xf1841a6cU),
    };
    r_rsip_func100(Param_pe5f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5f_func102_001[] =
        {
            BSWAP_32BIG_C(0xe2090228U), BSWAP_32BIG_C(0x202d8015U), BSWAP_32BIG_C(0x62bc6475U), BSWAP_32BIG_C(
                0x1e84a15aU),
        };
        r_rsip_func102(Param_pe5f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x38000ca5U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00A60000U);

        static const uint32_t Param_pe5f_func100_002[] =
        {
            BSWAP_32BIG_C(0xc99f732cU), BSWAP_32BIG_C(0xe455318bU), BSWAP_32BIG_C(0xb3942fa6U), BSWAP_32BIG_C(
                0xefbcf5c9U),
        };
        r_rsip_func100(Param_pe5f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x800100c0U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_EncMsg[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x800100e0U, 0x0000e504U);

            static const uint32_t Param_pe5f_func101_001[] =
            {
                BSWAP_32BIG_C(0x52569860U), BSWAP_32BIG_C(0x66c317a8U), BSWAP_32BIG_C(0xeb35316aU), BSWAP_32BIG_C(
                    0xe47cd3c5U),
            };
            r_rsip_func101(Param_pe5f_func101_001);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x0000b4c0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            r_rsip_func_sub002(0x800100e0U, 0x0000e504U);

            static const uint32_t Param_pe5f_func101_002[] =
            {
                BSWAP_32BIG_C(0x4d2301aeU), BSWAP_32BIG_C(0x6f21a515U), BSWAP_32BIG_C(0xf71aa2dbU), BSWAP_32BIG_C(
                    0xf1f9e924U),
            };
            r_rsip_func101(Param_pe5f_func101_002);
            r_rsip_func044();

            WAIT_STS(REG_00F8H, 0, 1);

            static const uint32_t Param_pe5f_func100_003[] =
            {
                BSWAP_32BIG_C(0x291eda37U), BSWAP_32BIG_C(0x54661415U), BSWAP_32BIG_C(0x24f96d86U), BSWAP_32BIG_C(
                    0x9810e22eU),
            };
            r_rsip_func100(Param_pe5f_func100_003);
            r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

            WR1_PROG(REG_009CH, 0x810100a0U);
            WR1_PROG(REG_0008H, 0x00005006U);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub016(0x0000a8a0U, 0x00000002U, 0x000268a5U);

            WR1_PROG(REG_0094H, 0x00000884U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
            {
                r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub009(0x01410011U, 0x00002c80U);

                static const uint32_t Param_pe5f_func101_003[] =
                {
                    BSWAP_32BIG_C(0xae784995U), BSWAP_32BIG_C(0xc5402b9aU), BSWAP_32BIG_C(0xf4104232U), BSWAP_32BIG_C(
                        0xe3c7d703U),
                };
                r_rsip_func101(Param_pe5f_func101_003);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub010(0x38000885U);

            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub006(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe5f_func100_004[] =
            {
                BSWAP_32BIG_C(0xb778a933U), BSWAP_32BIG_C(0x03c45ec8U), BSWAP_32BIG_C(0x11fe896fU), BSWAP_32BIG_C(
                    0xeb476a27U),
            };
            r_rsip_func100(Param_pe5f_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe5f_func102_002[] =
                {
                    BSWAP_32BIG_C(0x939d1d40U), BSWAP_32BIG_C(0x175a4a0dU), BSWAP_32BIG_C(0xad7486ccU), BSWAP_32BIG_C(
                        0x925c76eaU),
                };
                r_rsip_func102(Param_pe5f_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe5f_func101_004[] =
                {
                    BSWAP_32BIG_C(0x1784d33bU), BSWAP_32BIG_C(0x91ca4667U), BSWAP_32BIG_C(0x0ce242ffU), BSWAP_32BIG_C(
                        0xe64c7d9fU),
                };
                r_rsip_func101(Param_pe5f_func101_004);
            }
        }
        else
        {
            static const uint32_t Param_pe5f_func101_005[] =
            {
                BSWAP_32BIG_C(0x2916cc0aU), BSWAP_32BIG_C(0x31c74cb1U), BSWAP_32BIG_C(0xf019e318U), BSWAP_32BIG_C(
                    0x6f75c56cU),
            };
            r_rsip_func101(Param_pe5f_func101_005);
        }

        WAIT_STS(REG_00F8H, 0, 1);

        WR1_PROG(REG_0014H, 0x00020064U);

        for (iLoop = 0U; iLoop < MAX_CNT; iLoop++)
        {
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_Msg[iLoop]);
        }

        WAIT_STS(REG_00F8H, 2, 0);

        WR1_PROG(REG_0014H, 0x00000000U);

        WR1_PROG(REG_0040H, 0x00001600U);

        WR1_PROG(REG_00F4H, 0x00000100U);

        WR1_PROG(REG_00F4H, 0x00000020U);

        r_rsip_func_sub004(0x0000140cU, 0x00c50021U);

        r_rsip_func004();

        WR1_PROG(REG_00F4H, 0x00000011U);

        WR1_PROG(REG_00D0H, 0x08000045U);
        r_rsip_func_sub004(0x00001804U, 0x00430011U);

        r_rsip_func_sub006(0x08000055U, 0x00430011U);

        WR1_PROG(REG_0094H, 0x38000c21U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00260000U);

        static const uint32_t Param_pe5f_func100_005[] =
        {
            BSWAP_32BIG_C(0xfc55180aU), BSWAP_32BIG_C(0xf703bfd1U), BSWAP_32BIG_C(0x0db9e328U), BSWAP_32BIG_C(
                0x58a83a1bU),
        };
        r_rsip_func100(Param_pe5f_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func002();

            static const uint32_t Param_pe5f_func101_006[] =
            {
                BSWAP_32BIG_C(0x4f39addaU), BSWAP_32BIG_C(0x38199c51U), BSWAP_32BIG_C(0x806273c5U), BSWAP_32BIG_C(
                    0x22677792U),
            };
            r_rsip_func101(Param_pe5f_func101_006);
        }
        else
        {
            WR1_PROG(REG_0000H, 0x01410021U);
            WR1_PROG(REG_0014H, 0x000007a1U);

            WR1_PROG(REG_00D0H, 0x0c000105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU));

            WR1_PROG(REG_00D0H, 0x0c100105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU));

            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);

            WR1_PROG(REG_00D0H, 0x08000045U);
            r_rsip_func_sub004(0x00001808U, 0x00430011U);

            r_rsip_func_sub006(0x08000055U, 0x00430011U);

            WR1_PROG(REG_0000H, 0x01410021U);
            WR1_PROG(REG_0014H, 0x000007a1U);

            WR1_PROG(REG_00D0H, 0x0c000105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU));

            WR1_PROG(REG_00D0H, 0x0c100105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU),
                     bswap_32big(0x5c5c5c5cU));

            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);

            static const uint32_t Param_pe5f_func101_007[] =
            {
                BSWAP_32BIG_C(0xc200c3b5U), BSWAP_32BIG_C(0xd577b378U), BSWAP_32BIG_C(0x0bf80a71U), BSWAP_32BIG_C(
                    0x5c130897U),
            };
            r_rsip_func101(Param_pe5f_func101_007);
        }

        r_rsip_func_sub004(0x0000180cU, 0x01430021U);

        WR1_PROG(REG_0014H, 0x000000a4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x80000000U));

        WR1_PROG(REG_0000H, 0x01400015U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_0014H, 0x000001a4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR2_PROG(REG_002CH, bswap_32big(0x00000000U), bswap_32big(0x00000300U));

        WAIT_STS(REG_00F8H, 2, 0);

        WR1_PROG(REG_00F4H, 0x00000100U);

        WR1_PROG(REG_0040H, 0x00001600U);

        static const uint32_t Param_pe5f_func100_006[] =
        {
            BSWAP_32BIG_C(0xa7751a8bU), BSWAP_32BIG_C(0x7a6858dcU), BSWAP_32BIG_C(0xa462822fU), BSWAP_32BIG_C(
                0x1fa3a720U),
        };
        r_rsip_func100(Param_pe5f_func100_006);
        r_rsip_func103();

        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

        r_rsip_func_sub002(0x800100e0U, 0x0000e505U);

        static const uint32_t Param_pe5f_func101_008[] =
        {
            BSWAP_32BIG_C(0x4882d44fU), BSWAP_32BIG_C(0x3d1a8e30U), BSWAP_32BIG_C(0xcd21bed3U), BSWAP_32BIG_C(
                0xf24ba31aU),
        };
        r_rsip_func101(Param_pe5f_func101_008);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x0000b4c0U);
        WR1_PROG(REG_0094H, 0x01799093U);

        r_rsip_func_sub002(0x800100e0U, 0x0000e505U);

        static const uint32_t Param_pe5f_func101_009[] =
        {
            BSWAP_32BIG_C(0x7a87c052U), BSWAP_32BIG_C(0x511b3e14U), BSWAP_32BIG_C(0xac886483U), BSWAP_32BIG_C(
                0x3179c944U),
        };
        r_rsip_func101(Param_pe5f_func101_009);
        r_rsip_func044();

        WR1_PROG(REG_00F4H, 0x00000020U);

        r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pe5f_func100_007[] =
        {
            BSWAP_32BIG_C(0xa861e49bU), BSWAP_32BIG_C(0x752e79cfU), BSWAP_32BIG_C(0x7ea59d25U), BSWAP_32BIG_C(
                0x532f0bc4U),
        };
        r_rsip_func100(Param_pe5f_func100_007);
        WR1_PROG(REG_00D4H, 0x40000100U);
        r_rsip_func_sub006(0xe7008d07U, 0x00450021U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_KDFInfo[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_KDFInfo[5]);

        static const uint32_t Param_pe5f_func100_008[] =
        {
            BSWAP_32BIG_C(0x2169e4acU), BSWAP_32BIG_C(0xfdc8a492U), BSWAP_32BIG_C(0x4fb9b467U), BSWAP_32BIG_C(
                0x471c978dU),
        };
        r_rsip_func100(Param_pe5f_func100_008);
        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0x09108105U, 0x00410011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_KDFInfo[9]);

        static const uint32_t Param_pe5f_func100_009[] =
        {
            BSWAP_32BIG_C(0xf67c5beeU), BSWAP_32BIG_C(0x5054c4bdU), BSWAP_32BIG_C(0x4febccd9U), BSWAP_32BIG_C(
                0x634fe56fU),
        };
        r_rsip_func100(Param_pe5f_func100_009);
        WR1_PROG(REG_009CH, 0x81010000U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_KDFInfo[0]);

        static const uint32_t Param_pe5f_func102_003[] =
        {
            BSWAP_32BIG_C(0x69192b72U), BSWAP_32BIG_C(0x31e41757U), BSWAP_32BIG_C(0xeca3af7eU), BSWAP_32BIG_C(
                0xfce4d307U),
        };
        r_rsip_func102(Param_pe5f_func102_003);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
