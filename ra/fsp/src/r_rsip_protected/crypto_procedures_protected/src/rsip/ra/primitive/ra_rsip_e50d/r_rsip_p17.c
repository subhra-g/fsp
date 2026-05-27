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

rsip_ret_t r_rsip_p17 (uint32_t OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00170001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00001701U);

    static const uint32_t Param_p17_func101_001[] =
    {
        BSWAP_32BIG_C(0xcf8c8a27U), BSWAP_32BIG_C(0x28848b77U), BSWAP_32BIG_C(0xadf202d8U), BSWAP_32BIG_C(0x647626fbU),
    };
    r_rsip_func101(Param_p17_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub003(0x800103a0U, 0x00000017U);

    static const uint32_t Param_p17_func101_002[] =
    {
        BSWAP_32BIG_C(0x21f862e7U), BSWAP_32BIG_C(0x481f83e3U), BSWAP_32BIG_C(0xc30db4b5U), BSWAP_32BIG_C(0x8bad2b97U),
    };
    r_rsip_func101(Param_p17_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000009U);

    r_rsip_func_sub003(0x800103a0U, 0x00000017U);

    static const uint32_t Param_p17_func101_003[] =
    {
        BSWAP_32BIG_C(0xe1d69d56U), BSWAP_32BIG_C(0x1be35341U), BSWAP_32BIG_C(0x59973756U), BSWAP_32BIG_C(0x10541ca2U),
    };
    r_rsip_func101(Param_p17_func101_003);
    r_rsip_func044();

    r_rsip_func_sub003(0x800103a0U, 0x00001702U);

    static const uint32_t Param_p17_func101_004[] =
    {
        BSWAP_32BIG_C(0xb83cd1a8U), BSWAP_32BIG_C(0x027febf0U), BSWAP_32BIG_C(0xefaf15e6U), BSWAP_32BIG_C(0xa33f968cU),
    };
    r_rsip_func101(Param_p17_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00001703U);

    static const uint32_t Param_p17_func101_005[] =
    {
        BSWAP_32BIG_C(0x8dfb4c22U), BSWAP_32BIG_C(0xa1339bacU), BSWAP_32BIG_C(0x2349adfeU), BSWAP_32BIG_C(0x1e5e62c5U),
    };
    r_rsip_func101(Param_p17_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000010U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00001704U);

    static const uint32_t Param_p17_func101_006[] =
    {
        BSWAP_32BIG_C(0x764130fbU), BSWAP_32BIG_C(0xa1caf8b7U), BSWAP_32BIG_C(0x7397dbdaU), BSWAP_32BIG_C(0xbb44fe42U),
    };
    r_rsip_func101(Param_p17_func101_006);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000020U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00001705U);

    static const uint32_t Param_p17_func101_007[] =
    {
        BSWAP_32BIG_C(0xe985771dU), BSWAP_32BIG_C(0x7cc1f0c6U), BSWAP_32BIG_C(0xcf1501fbU), BSWAP_32BIG_C(0x9abfeca5U),
    };
    r_rsip_func101(Param_p17_func101_007);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000030U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    static const uint32_t Param_p17_func101_008[] =
    {
        BSWAP_32BIG_C(0xc58be4e5U), BSWAP_32BIG_C(0x3665fd3fU), BSWAP_32BIG_C(0x0812489bU), BSWAP_32BIG_C(0xc511c547U),
    };
    r_rsip_func101(Param_p17_func101_008);

    r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000020U);

    r_rsip_func424();

    r_rsip_func_sub021(0x000037dfU, 0x0000b400U, 0x00000010U, 0x0000b420U);
    WR1_PROG(REG_1600H, 0x00000030U);
    r_rsip_func424();

    WR1_PROG(REG_1600H, 0x000013feU);

    r_rsip_func_sub006(0x38008be0U, 0x1ae211e9U, 0x00A60000U);

    static const uint32_t Param_p17_func100_001[] =
    {
        BSWAP_32BIG_C(0xf9dedee6U), BSWAP_32BIG_C(0x2932b2f1U), BSWAP_32BIG_C(0xf21e5c1dU), BSWAP_32BIG_C(0xce6c4f7fU),
    };
    r_rsip_func100(Param_p17_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p17_func102_001[] =
        {
            BSWAP_32BIG_C(0x4240baecU), BSWAP_32BIG_C(0xf3433138U), BSWAP_32BIG_C(0x6ed8e4c8U), BSWAP_32BIG_C(
                0x8038d4c1U),
        };
        r_rsip_func102(Param_p17_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p17_func100_002[] =
        {
            BSWAP_32BIG_C(0x32f7427eU), BSWAP_32BIG_C(0x512efebeU), BSWAP_32BIG_C(0x16d76bdfU), BSWAP_32BIG_C(
                0xad0cd42bU),
        };
        r_rsip_func100(Param_p17_func100_002);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d47U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x818c001fU);
        r_rsip_func_sub001(0x00890031U);

        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0U; iLoop < 12U; )
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p17_func100_003[] =
        {
            BSWAP_32BIG_C(0x6d703f7cU), BSWAP_32BIG_C(0x0f3ffcd8U), BSWAP_32BIG_C(0xf687ee03U), BSWAP_32BIG_C(
                0x7fdef46cU),
        };
        r_rsip_func100(Param_p17_func100_003);
        r_rsip_func_sub027(0x40000000U, 0xe7008d47U, 0x81040180U);
        r_rsip_func_sub001(0x00890011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 1]);

        static const uint32_t Param_p17_func100_004[] =
        {
            BSWAP_32BIG_C(0x14f3700dU), BSWAP_32BIG_C(0xcd0a474eU), BSWAP_32BIG_C(0x800d10eeU), BSWAP_32BIG_C(
                0xe60fdf20U),
        };
        r_rsip_func100(Param_p17_func100_004);
        r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
        WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
                 bswap_32big(0x00000004U));

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);

        static const uint32_t Param_p17_func100_005[] =
        {
            BSWAP_32BIG_C(0x4d0a6be0U), BSWAP_32BIG_C(0x4687b6ebU), BSWAP_32BIG_C(0xea50581cU), BSWAP_32BIG_C(
                0xebd9602eU),
        };
        r_rsip_func100(Param_p17_func100_005);
        r_rsip_func_sub016(0x81010080U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_p17_func102_002[] =
        {
            BSWAP_32BIG_C(0xe1ad7e5dU), BSWAP_32BIG_C(0xecd79ba3U), BSWAP_32BIG_C(0x74e142bcU), BSWAP_32BIG_C(
                0x38c93b59U),
        };
        r_rsip_func102(Param_p17_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
