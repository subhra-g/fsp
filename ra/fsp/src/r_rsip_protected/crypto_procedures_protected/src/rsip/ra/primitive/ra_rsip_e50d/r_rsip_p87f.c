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

rsip_ret_t r_rsip_p87f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p87f_func100_001[] =
    {
        BSWAP_32BIG_C(0x87eb6ebaU), BSWAP_32BIG_C(0x3509b223U), BSWAP_32BIG_C(0xc0a4899fU), BSWAP_32BIG_C(0x59153b58U),
    };
    r_rsip_func100(Param_p87f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p87f_func102_001[] =
        {
            BSWAP_32BIG_C(0x8f708f63U), BSWAP_32BIG_C(0x47c93bb7U), BSWAP_32BIG_C(0x7515dcbbU), BSWAP_32BIG_C(
                0xaf6e04ecU),
        };
        r_rsip_func102(Param_p87f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
        {
            r_rsip_func_sub019(0x000000a1U, 0x40000010U, 0x4a008104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            static const uint32_t Param_p87f_func101_001[] =
            {
                BSWAP_32BIG_C(0x3817102aU), BSWAP_32BIG_C(0xddc1c982U), BSWAP_32BIG_C(0xa6063cdcU), BSWAP_32BIG_C(
                    0x3de637faU),
            };
            r_rsip_func101(Param_p87f_func101_001);
        }
        else
        {
            r_rsip_func_sub019(0x000000a1U, 0x40000010U, 0x5a008104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            static const uint32_t Param_p87f_func101_002[] =
            {
                BSWAP_32BIG_C(0x72dfc1e7U), BSWAP_32BIG_C(0x06620d71U), BSWAP_32BIG_C(0xe1b44debU), BSWAP_32BIG_C(
                    0x01a9f1c1U),
            };
            r_rsip_func101(Param_p87f_func101_002);
        }

        WR1_PROG(REG_1824H, 0x0c000045U);
        r_rsip_func_sub001(0x00410011U);

        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            static const uint32_t Param_p87f_func100_002[] =
            {
                BSWAP_32BIG_C(0x49c21239U), BSWAP_32BIG_C(0x56a4ce69U), BSWAP_32BIG_C(0x1cf0f8b5U), BSWAP_32BIG_C(
                    0xcca99c3bU),
            };
            r_rsip_func100(Param_p87f_func100_002);
            r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0x0e008505U);
            WR4_ADDR(REG_1420H, &InData_Text[0]);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_DataT[0]);

            static const uint32_t Param_p87f_func102_002[] =
            {
                BSWAP_32BIG_C(0x0cf911a1U), BSWAP_32BIG_C(0x72d726a6U), BSWAP_32BIG_C(0x72dd7dd0U), BSWAP_32BIG_C(
                    0x6848c90dU),
            };
            r_rsip_func102(Param_p87f_func102_002);
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

            static const uint32_t Param_p87f_func100_003[] =
            {
                BSWAP_32BIG_C(0x4c70d0d0U), BSWAP_32BIG_C(0x717f8565U), BSWAP_32BIG_C(0x709e9899U), BSWAP_32BIG_C(
                    0xe00dd203U),
            };
            r_rsip_func100(Param_p87f_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p87f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x46cf0a01U), BSWAP_32BIG_C(0xa1cc7b23U), BSWAP_32BIG_C(0x14f1edd1U), BSWAP_32BIG_C(
                        0x76787cd4U),
                };
                r_rsip_func102(Param_p87f_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub019(0x000003c1U, 0x40000010U, 0x0e008505U);
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

                static const uint32_t Param_p87f_func100_004[] =
                {
                    BSWAP_32BIG_C(0x03990d4fU), BSWAP_32BIG_C(0x4fe64d63U), BSWAP_32BIG_C(0x6f990fe0U), BSWAP_32BIG_C(
                        0x0aaf01a5U),
                };
                r_rsip_func100(Param_p87f_func100_004);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p87f_func102_004[] =
                    {
                        BSWAP_32BIG_C(0xd291cd60U), BSWAP_32BIG_C(0xb5cb891cU), BSWAP_32BIG_C(0xd7819e89U),
                        BSWAP_32BIG_C(0x94a13e4aU),
                    };
                    r_rsip_func102(Param_p87f_func102_004);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_AUTH_FAIL;
                }
                else
                {
                    static const uint32_t Param_p87f_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x5ba60e6eU), BSWAP_32BIG_C(0xcb91a9c0U), BSWAP_32BIG_C(0x5ae38b39U),
                        BSWAP_32BIG_C(0x2dd9e11cU),
                    };
                    r_rsip_func102(Param_p87f_func102_005);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
