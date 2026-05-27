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
        r_rsip_func_sub019(0x000000a1U, 0x40000000U, 0x4a008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_001[] =
        {
            BSWAP_32BIG_C(0x113a7aa4U), BSWAP_32BIG_C(0xa2a042f8U), BSWAP_32BIG_C(0xf49fd5a9U), BSWAP_32BIG_C(
                0x9288ad77U),
        };
        r_rsip_func101(Param_p44f_func101_001);
    }
    else
    {
        r_rsip_func_sub019(0x000000a1U, 0x40000000U, 0x5a008104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_002[] =
        {
            BSWAP_32BIG_C(0x987246faU), BSWAP_32BIG_C(0x5e4c9e7eU), BSWAP_32BIG_C(0xb76e4cfdU), BSWAP_32BIG_C(
                0x0396ac5aU),
        };
        r_rsip_func101(Param_p44f_func101_002);
    }

    WR1_PROG(REG_1824H, 0x0c000045U);
    r_rsip_func_sub001(0x00410011U);

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
    {
        static const uint32_t Param_p44f_func100_001[] =
        {
            BSWAP_32BIG_C(0x1b2c8827U), BSWAP_32BIG_C(0x43f78b12U), BSWAP_32BIG_C(0x1f267e0aU), BSWAP_32BIG_C(
                0x80bce919U),
        };
        r_rsip_func100(Param_p44f_func100_001);
        r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0e008505U);
        WR4_ADDR(REG_1420H, &InData_Text[0]);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        static const uint32_t Param_p44f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc239f9daU), BSWAP_32BIG_C(0x3e59d635U), BSWAP_32BIG_C(0xb2eb9f3bU), BSWAP_32BIG_C(
                0xe067516aU),
        };
        r_rsip_func102(Param_p44f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010040U);
        WR1_PROG(REG_1420H, InData_DataTLen[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub006(0x3420a840U, 0x00000010U, 0x00260000U);

        WR1_PROG(REG_1600H, 0x0000b460U);
        r_rsip_func_sub006(0x00000080U, 0x34202862U, 0x00260000U);

        static const uint32_t Param_p44f_func100_002[] =
        {
            BSWAP_32BIG_C(0xb00ad243U), BSWAP_32BIG_C(0xa3abf242U), BSWAP_32BIG_C(0x572d859cU), BSWAP_32BIG_C(
                0x7b9e5f54U),
        };
        r_rsip_func100(Param_p44f_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p44f_func102_002[] =
            {
                BSWAP_32BIG_C(0x7e9ac66eU), BSWAP_32BIG_C(0xe56d4d0bU), BSWAP_32BIG_C(0x26566ac9U), BSWAP_32BIG_C(
                    0xcb790c98U),
            };
            r_rsip_func102(Param_p44f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000000U, 0x0e008505U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1608H, 0x80840001U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub021(0x000034e2U, 0x000568e7U, 0x00026ce7U, 0x00003827U);

            r_rsip_func_sub021(0x0000b4c0U, 0x00000020U, 0x00003402U, 0x00008c00U);
            r_rsip_func_sub021(0x0000001fU, 0x000028c0U, 0x00008cc0U, 0x0000001fU);

            r_rsip_func_sub021(0x00004406U, 0x00007421U, 0x00007821U, 0x00003c27U);

            r_rsip_func_sub021(0x000034c2U, 0x0000a4c0U, 0x0000001fU, 0x000568c6U);

            r_rsip_func_sub022(0x000034e6U, 0x00026ce7U, 0x00000821U);

            for (iLoop = 0U; iLoop < 4U; iLoop++)
            {
                r_rsip_func_sub021(0x3420a8e0U, 0x0000000dU, 0x10003c27U, 0x1000a4e0U);
                WR1_PROG(REG_1600H, 0x00000004U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81840001U);
            r_rsip_func_sub001(0x00490011U);

            r_rsip_func_sub020(0x000003c1U, 0x9c000005U);
            WR4_ADDR(REG_1420H, &InData_DataT[0]);

            static const uint32_t Param_p44f_func100_003[] =
            {
                BSWAP_32BIG_C(0x2a41951aU), BSWAP_32BIG_C(0x8ce2fa9dU), BSWAP_32BIG_C(0x1cadbefbU), BSWAP_32BIG_C(
                    0xdef11839U),
            };
            r_rsip_func100(Param_p44f_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p44f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x910189b1U), BSWAP_32BIG_C(0x5b2dce1eU), BSWAP_32BIG_C(0xeaada42cU), BSWAP_32BIG_C(
                        0xc0d95f0bU),
                };
                r_rsip_func102(Param_p44f_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_AUTH_FAIL;
            }
            else
            {
                static const uint32_t Param_p44f_func102_004[] =
                {
                    BSWAP_32BIG_C(0x6b83036cU), BSWAP_32BIG_C(0xe702a8afU), BSWAP_32BIG_C(0x597e6f5eU), BSWAP_32BIG_C(
                        0x4ba8a982U),
                };
                r_rsip_func102(Param_p44f_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
