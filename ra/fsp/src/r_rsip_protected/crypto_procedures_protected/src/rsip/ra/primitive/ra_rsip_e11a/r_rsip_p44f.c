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

rsip_ret_t r_rsip_p44f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
    {
        r_rsip_func_sub008(0x000000a1U, 0x40000000U, 0x4a008104U);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_001[] =
        {
            BSWAP_32BIG_C(0x2b2fac46U), BSWAP_32BIG_C(0x4cfd9331U), BSWAP_32BIG_C(0x3a02e95cU), BSWAP_32BIG_C(
                0x77b09f2cU),
        };
        r_rsip_func101(Param_p44f_func101_001);
    }
    else
    {
        r_rsip_func_sub008(0x000000a1U, 0x40000000U, 0x5a008104U);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_002[] =
        {
            BSWAP_32BIG_C(0xa16afd81U), BSWAP_32BIG_C(0x9c7a4989U), BSWAP_32BIG_C(0xec5ae07eU), BSWAP_32BIG_C(
                0x1cbc2cd5U),
        };
        r_rsip_func101(Param_p44f_func101_002);
    }

    r_rsip_func_sub006(0x0c000045U, 0x00410011U);

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
    {
        static const uint32_t Param_p44f_func100_001[] =
        {
            BSWAP_32BIG_C(0x699e140fU), BSWAP_32BIG_C(0x6f29dbd4U), BSWAP_32BIG_C(0x6d1e5fc8U), BSWAP_32BIG_C(
                0x37900dcfU),
        };
        r_rsip_func100(Param_p44f_func100_001);
        r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x0e008505U);
        WR4_ADDR(REG_002CH, &InData_Text[0]);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_DataT[0]);

        static const uint32_t Param_p44f_func102_001[] =
        {
            BSWAP_32BIG_C(0xa6d0dba9U), BSWAP_32BIG_C(0xe79aa318U), BSWAP_32BIG_C(0xddc1b63eU), BSWAP_32BIG_C(
                0x1180528dU),
        };
        r_rsip_func102(Param_p44f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x80010040U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, InData_DataTLen[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub007(0x3420a840U, 0x00000010U, 0x00260000U);

        WR1_PROG(REG_0094H, 0x0000b460U);
        r_rsip_func_sub007(0x00000080U, 0x34202862U, 0x00260000U);

        static const uint32_t Param_p44f_func100_002[] =
        {
            BSWAP_32BIG_C(0xce02d159U), BSWAP_32BIG_C(0x427266c4U), BSWAP_32BIG_C(0xec0ddfccU), BSWAP_32BIG_C(
                0xe842d308U),
        };
        r_rsip_func100(Param_p44f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p44f_func102_002[] =
            {
                BSWAP_32BIG_C(0x0db29496U), BSWAP_32BIG_C(0x4584bfe3U), BSWAP_32BIG_C(0x6644cb09U), BSWAP_32BIG_C(
                    0x7052b0a0U),
            };
            r_rsip_func102(Param_p44f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x0e008505U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x80840001U, 0x03410011U);

            r_rsip_func_sub016(0x000034e2U, 0x000568e7U, 0x00026ce7U);

            r_rsip_func_sub016(0x00003827U, 0x0000b4c0U, 0x00000020U);
            r_rsip_func_sub016(0x00003402U, 0x00008c00U, 0x0000001fU);
            r_rsip_func_sub016(0x000028c0U, 0x00008cc0U, 0x0000001fU);

            r_rsip_func_sub016(0x00004406U, 0x00007421U, 0x00007821U);

            r_rsip_func_sub016(0x00003c27U, 0x000034c2U, 0x0000a4c0U);
            r_rsip_func_sub016(0x0000001fU, 0x000568c6U, 0x000034e6U);
            WR1_PROG(REG_0094H, 0x00026ce7U);

            WR1_PROG(REG_0094H, 0x00000821U);

            for (iLoop = 0U; iLoop < 4; iLoop++)
            {
                r_rsip_func_sub016(0x3420a8e0U, 0x0000000dU, 0x10003c27U);

                WR1_PROG(REG_0094H, 0x1000a4e0U);
                WR1_PROG(REG_0094H, 0x00000004U);
            }

            WR1_PROG(REG_00D0H, 0x08000045U);
            r_rsip_func_sub003(0x81840001U, 0x00490011U);

            WR1_PROG(REG_0014H, 0x000003c1U);
            WR1_PROG(REG_00D0H, 0x9c000005U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_DataT[0]);

            static const uint32_t Param_p44f_func100_003[] =
            {
                BSWAP_32BIG_C(0xa307c5c1U), BSWAP_32BIG_C(0x44bd7c85U), BSWAP_32BIG_C(0x9fd5d331U), BSWAP_32BIG_C(
                    0x38e86218U),
            };
            r_rsip_func100(Param_p44f_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);
            WR1_PROG(REG_0024H, 0x00000000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p44f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x77b8aee7U), BSWAP_32BIG_C(0x8d97c1d9U), BSWAP_32BIG_C(0x4b904f5dU), BSWAP_32BIG_C(
                        0x04dffed0U),
                };
                r_rsip_func102(Param_p44f_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_AUTH_FAIL;
            }
            else
            {
                static const uint32_t Param_p44f_func102_004[] =
                {
                    BSWAP_32BIG_C(0xbc1f2e0eU), BSWAP_32BIG_C(0xfe6d563aU), BSWAP_32BIG_C(0xbdefdc78U), BSWAP_32BIG_C(
                        0xa37a58adU),
                };
                r_rsip_func102(Param_p44f_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
