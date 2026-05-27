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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t InData_EncMsgLength[])
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

    static const uint32_t Param_pe5e_func100_001[] =
    {
        BSWAP_32BIG_C(0x44f4025eU), BSWAP_32BIG_C(0x9b213911U), BSWAP_32BIG_C(0x9da2ee54U), BSWAP_32BIG_C(0xf1841a6cU),
    };
    r_rsip_func100(Param_pe5e_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5e_func102_001[] =
        {
            BSWAP_32BIG_C(0xe2090228U), BSWAP_32BIG_C(0x202d8015U), BSWAP_32BIG_C(0x62bc6475U), BSWAP_32BIG_C(
                0x1e84a15aU),
        };
        r_rsip_func102(Param_pe5e_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x38000ca5U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00A60000U);

        static const uint32_t Param_pe5e_func100_002[] =
        {
            BSWAP_32BIG_C(0xc99f732cU), BSWAP_32BIG_C(0xe455318bU), BSWAP_32BIG_C(0xb3942fa6U), BSWAP_32BIG_C(
                0xefbcf5c9U),
        };
        r_rsip_func100(Param_pe5e_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0014H, 0x000000c7U);
            WR1_PROG(REG_009CH, 0x800100c0U);
            WAIT_STS(REG_0014H, 31, 1);
            WR1_PROG(REG_002CH, InData_EncMsg[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x800100e0U, 0x0000e503U);

            static const uint32_t Param_pe5e_func101_001[] =
            {
                BSWAP_32BIG_C(0x9a0dc906U), BSWAP_32BIG_C(0xf1707ebbU), BSWAP_32BIG_C(0xc84c3f64U), BSWAP_32BIG_C(
                    0xca91d374U),
            };
            r_rsip_func101(Param_pe5e_func101_001);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x0000b4c0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            r_rsip_func_sub002(0x800100e0U, 0x0000e503U);

            static const uint32_t Param_pe5e_func101_002[] =
            {
                BSWAP_32BIG_C(0x1618b0d5U), BSWAP_32BIG_C(0xa852907cU), BSWAP_32BIG_C(0xb17fc45dU), BSWAP_32BIG_C(
                    0x039e6b80U),
            };
            r_rsip_func101(Param_pe5e_func101_002);
            r_rsip_func044();

            WAIT_STS(REG_00F8H, 0, 1);

            r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

            static const uint32_t Param_pe5e_func100_003[] =
            {
                BSWAP_32BIG_C(0xbd2b2fb0U), BSWAP_32BIG_C(0x8ae84c1dU), BSWAP_32BIG_C(0x0371bf94U), BSWAP_32BIG_C(
                    0x92db4e88U),
            };
            r_rsip_func100(Param_pe5e_func100_003);
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

                static const uint32_t Param_pe5e_func101_003[] =
                {
                    BSWAP_32BIG_C(0xe25df6e0U), BSWAP_32BIG_C(0x9ccce299U), BSWAP_32BIG_C(0x930c6830U), BSWAP_32BIG_C(
                        0x49b8594eU),
                };
                r_rsip_func101(Param_pe5e_func101_003);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub010(0x38000885U);

            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub006(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe5e_func100_004[] =
            {
                BSWAP_32BIG_C(0x6a2fd603U), BSWAP_32BIG_C(0x5a339d7dU), BSWAP_32BIG_C(0x6092bf17U), BSWAP_32BIG_C(
                    0xd0c74361U),
            };
            r_rsip_func100(Param_pe5e_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe5e_func101_004[] =
                {
                    BSWAP_32BIG_C(0x118b9391U), BSWAP_32BIG_C(0x36a46826U), BSWAP_32BIG_C(0x14286a92U), BSWAP_32BIG_C(
                        0x0f35064aU),
                };
                r_rsip_func101(Param_pe5e_func101_004);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe5e_func101_005[] =
                {
                    BSWAP_32BIG_C(0x1903d8a2U), BSWAP_32BIG_C(0x40239b76U), BSWAP_32BIG_C(0x2075ee06U), BSWAP_32BIG_C(
                        0xaeb764adU),
                };
                r_rsip_func101(Param_pe5e_func101_005);

                return RSIP_RET_PASS;
            }
        }
        else
        {
            static const uint32_t Param_pe5e_func101_006[] =
            {
                BSWAP_32BIG_C(0x0732e560U), BSWAP_32BIG_C(0xb53c2b66U), BSWAP_32BIG_C(0x55e071edU), BSWAP_32BIG_C(
                    0x9e7cd9e4U),
            };
            r_rsip_func101(Param_pe5e_func101_006);

            return RSIP_RET_PASS;
        }
    }
}
