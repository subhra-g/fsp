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

    r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    r_rsip_func_sub018(0x00000000U, 0x000008e7U, 0x300088a0U);
    r_rsip_func_sub022(0x00000000U, 0x00030020U, 0x00002ce0U);

    r_rsip_func_sub022(0x00000080U, 0x300088a0U, 0x0000000dU);
    r_rsip_func_sub022(0x00030020U, 0x00002ce0U, 0x00000080U);

    r_rsip_func_sub022(0x300088a0U, 0x00000011U, 0x00030020U);

    WR1_PROG(REG_0094H, 0x00002ce0U);

    r_rsip_func_sub010(0x00000080U, 0x38000ce7U, 0x00270000U);

    static const uint32_t Param_pe5f_func100_001[] =
    {
        BSWAP_32BIG_C(0xbb586cafU), BSWAP_32BIG_C(0xedfb77e0U), BSWAP_32BIG_C(0x04de4fdaU), BSWAP_32BIG_C(0x6a15df92U),
    };
    r_rsip_func100(Param_pe5f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5f_func102_001[] =
        {
            BSWAP_32BIG_C(0x12ba7348U), BSWAP_32BIG_C(0x1ca4682fU), BSWAP_32BIG_C(0x1a9b773eU), BSWAP_32BIG_C(
                0xe5fd36fdU),
        };
        r_rsip_func102(Param_pe5f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_pe5f_func100_002[] =
        {
            BSWAP_32BIG_C(0xc032819bU), BSWAP_32BIG_C(0x5f824611U), BSWAP_32BIG_C(0x3f66c088U), BSWAP_32BIG_C(
                0xaacd8effU),
        };
        r_rsip_func100(Param_pe5f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_EncMsg[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e504U, 0x00000000U);

            static const uint32_t Param_pe5f_func101_001[] =
            {
                BSWAP_32BIG_C(0x73b4d1a4U), BSWAP_32BIG_C(0x9d8952b7U), BSWAP_32BIG_C(0x3c33282aU), BSWAP_32BIG_C(
                    0x1ff91b6bU),
            };
            r_rsip_func101(Param_pe5f_func101_001);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x0000b4c0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e504U, 0x00000000U);

            static const uint32_t Param_pe5f_func101_002[] =
            {
                BSWAP_32BIG_C(0x86a2e62eU), BSWAP_32BIG_C(0x987d153dU), BSWAP_32BIG_C(0x9b599951U), BSWAP_32BIG_C(
                    0x96e13fdeU),
            };
            r_rsip_func101(Param_pe5f_func101_002);
            r_rsip_func044();

            WAIT_STS(REG_0118H, 0, 1);

            static const uint32_t Param_pe5f_func100_003[] =
            {
                BSWAP_32BIG_C(0x149c0475U), BSWAP_32BIG_C(0x19e36a4cU), BSWAP_32BIG_C(0x5359f0caU), BSWAP_32BIG_C(
                    0x1f872997U),
            };
            r_rsip_func100(Param_pe5f_func100_003);
            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub017(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub022(0x0000a8a0U, 0x00000002U, 0x000268a5U);

            WR1_PROG(REG_0094H, 0x00000821U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
            {
                r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub015(0x01410011U, 0x00001800U);

                WR1_PROG(REG_0094H, 0x00002c20U);

                static const uint32_t Param_pe5f_func101_003[] =
                {
                    BSWAP_32BIG_C(0x8205e9aaU), BSWAP_32BIG_C(0xecfae505U), BSWAP_32BIG_C(0x063c3e34U), BSWAP_32BIG_C(
                        0x5f1eadefU),
                };
                r_rsip_func101(Param_pe5f_func101_003);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub016(0x38000825U, 0x00000080U, 0x00270000U);
            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub013(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe5f_func100_004[] =
            {
                BSWAP_32BIG_C(0x5179dcdeU), BSWAP_32BIG_C(0x87e7900eU), BSWAP_32BIG_C(0x348e5b5dU), BSWAP_32BIG_C(
                    0x703e409dU),
            };
            r_rsip_func100(Param_pe5f_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe5f_func102_002[] =
                {
                    BSWAP_32BIG_C(0x326e92a6U), BSWAP_32BIG_C(0x79de6402U), BSWAP_32BIG_C(0xc5ecca70U), BSWAP_32BIG_C(
                        0x985893eaU),
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
                    BSWAP_32BIG_C(0x245b9a59U), BSWAP_32BIG_C(0xd0f4d6ebU), BSWAP_32BIG_C(0x31a63f71U), BSWAP_32BIG_C(
                        0x2769a979U),
                };
                r_rsip_func101(Param_pe5f_func101_004);
            }
        }
        else
        {
            static const uint32_t Param_pe5f_func101_005[] =
            {
                BSWAP_32BIG_C(0x85e76a12U), BSWAP_32BIG_C(0x9c4bf558U), BSWAP_32BIG_C(0x4c3647c2U), BSWAP_32BIG_C(
                    0xacc156a4U),
            };
            r_rsip_func101(Param_pe5f_func101_005);
        }

        WAIT_STS(REG_0118H, 0, 1);

        WR1_PROG(REG_0014H, 0x00020064U);

        for (iLoop = 0U; iLoop < MAX_CNT; iLoop++)
        {
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_Msg[iLoop]);
        }

        WR1_PROG(REG_0014H, 0x00000000U);
        WAIT_STS(REG_0118H, 8, 0);
        WR1_PROG(REG_0040H, 0x00001600U);

        WAIT_STS(REG_0118H, 4, 1);

        static const uint32_t Param_pe5f_func100_005[] =
        {
            BSWAP_32BIG_C(0x88acafeeU), BSWAP_32BIG_C(0x8174c3c7U), BSWAP_32BIG_C(0xe454bc47U), BSWAP_32BIG_C(
                0x1908feaeU),
        };
        r_rsip_func100(Param_pe5f_func100_005);
        r_rsip_func103();

        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e505U, 0x00000000U);

        static const uint32_t Param_pe5f_func101_006[] =
        {
            BSWAP_32BIG_C(0xfb3300b0U), BSWAP_32BIG_C(0x6e830222U), BSWAP_32BIG_C(0x765622d1U), BSWAP_32BIG_C(
                0xcbef19c5U),
        };
        r_rsip_func101(Param_pe5f_func101_006);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x0000b4c0U);
        WR1_PROG(REG_0094H, 0x01799093U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e505U, 0x00000000U);

        static const uint32_t Param_pe5f_func101_007[] =
        {
            BSWAP_32BIG_C(0xd470580fU), BSWAP_32BIG_C(0x833eefcaU), BSWAP_32BIG_C(0xa828b622U), BSWAP_32BIG_C(
                0x1e4332a9U),
        };
        r_rsip_func101(Param_pe5f_func101_007);
        r_rsip_func044();

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

        r_rsip_func_sub022(0x000008e7U, 0x30003080U, 0x00070020U);
        r_rsip_func_sub022(0x0000b4a0U, 0x00000008U, 0x00030040U);
        r_rsip_func_sub022(0x0000b4a0U, 0x0000000cU, 0x00000080U);

        static const uint32_t Param_pe5f_func100_006[] =
        {
            BSWAP_32BIG_C(0xe1d2adeeU), BSWAP_32BIG_C(0xc37666b7U), BSWAP_32BIG_C(0xb333e257U), BSWAP_32BIG_C(
                0x36bb84c2U),
        };
        r_rsip_func100(Param_pe5f_func100_006);
        r_rsip_func_sub017(0x810100a0U, 0x00005006U);
        RD1_ADDR(REG_002CH, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_pe5f_func100_007[] =
            {
                BSWAP_32BIG_C(0x7cfb2a2eU), BSWAP_32BIG_C(0xd46ede94U), BSWAP_32BIG_C(0xe57abad1U), BSWAP_32BIG_C(
                    0x360215e4U),
            };
            r_rsip_func100(Param_pe5f_func100_007);
            r_rsip_func_sub004(0x40000000U, 0xe7008d05U, 0x00450011U, 0x00001012U);
            RD4_ADDR(REG_002CH, &OutData_KDFInfo[iLoop + 1]);

            WR1_PROG(REG_0094H, 0x0000a4e0U);
            WR1_PROG(REG_0094H, 0x00000004U);

            static const uint32_t Param_pe5f_func101_008[] =
            {
                BSWAP_32BIG_C(0x032750eeU), BSWAP_32BIG_C(0x17625f29U), BSWAP_32BIG_C(0x13459aeeU), BSWAP_32BIG_C(
                    0x7c8d5c4eU),
            };
            r_rsip_func101(Param_pe5f_func101_008);
            iLoop = iLoop + 4U;
        }

        r_rsip_func_sub016(0x380008e5U, 0x00000080U, 0x00270000U);
        WR1_PROG(REG_0040H, 0x00402000U);

        static const uint32_t Param_pe5f_func100_008[] =
        {
            BSWAP_32BIG_C(0x8eaf4c4eU), BSWAP_32BIG_C(0x0c08232cU), BSWAP_32BIG_C(0x370576d4U), BSWAP_32BIG_C(
                0xdd1f1b63U),
        };
        r_rsip_func100(Param_pe5f_func100_008);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_KDFInfo[iLoop + 1]);

        static const uint32_t Param_pe5f_func100_009[] =
        {
            BSWAP_32BIG_C(0xd952bb3aU), BSWAP_32BIG_C(0xde2f723eU), BSWAP_32BIG_C(0x60ee51f9U), BSWAP_32BIG_C(
                0xc9ba7393U),
        };
        r_rsip_func100(Param_pe5f_func100_009);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_KDFInfo[0]);

        static const uint32_t Param_pe5f_func102_003[] =
        {
            BSWAP_32BIG_C(0x7e0a4f62U), BSWAP_32BIG_C(0xde7e611cU), BSWAP_32BIG_C(0x4a6df031U), BSWAP_32BIG_C(
                0xcd4cda98U),
        };
        r_rsip_func102(Param_pe5f_func102_003);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
