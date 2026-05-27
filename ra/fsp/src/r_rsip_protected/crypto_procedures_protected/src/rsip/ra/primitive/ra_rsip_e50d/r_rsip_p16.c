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

rsip_ret_t r_rsip_p16 (uint32_t OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00160001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00001601U);

    static const uint32_t Param_p16_func101_001[] =
    {
        BSWAP_32BIG_C(0xccec78feU), BSWAP_32BIG_C(0x71a49ea2U), BSWAP_32BIG_C(0xe7f02cc8U), BSWAP_32BIG_C(0x7425ffbaU),
    };
    r_rsip_func101(Param_p16_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e4U);

    r_rsip_func_sub003(0x800103a0U, 0x00000016U);

    static const uint32_t Param_p16_func101_002[] =
    {
        BSWAP_32BIG_C(0x664653eeU), BSWAP_32BIG_C(0x7d099655U), BSWAP_32BIG_C(0xfb8881f8U), BSWAP_32BIG_C(0xe684e8b0U),
    };
    r_rsip_func101(Param_p16_func101_002);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000008U);

    r_rsip_func_sub003(0x800103a0U, 0x00000016U);

    static const uint32_t Param_p16_func101_003[] =
    {
        BSWAP_32BIG_C(0xa4b38418U), BSWAP_32BIG_C(0xc019998cU), BSWAP_32BIG_C(0xe88e49d4U), BSWAP_32BIG_C(0x17b28f5eU),
    };
    r_rsip_func101(Param_p16_func101_003);
    r_rsip_func044();

    r_rsip_func_sub003(0x800103a0U, 0x00001602U);

    static const uint32_t Param_p16_func101_004[] =
    {
        BSWAP_32BIG_C(0xdc413898U), BSWAP_32BIG_C(0xa3d9b7b8U), BSWAP_32BIG_C(0x166aec8aU), BSWAP_32BIG_C(0x5a944b33U),
    };
    r_rsip_func101(Param_p16_func101_004);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1608H, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00001603U);

    static const uint32_t Param_p16_func101_005[] =
    {
        BSWAP_32BIG_C(0xe1565636U), BSWAP_32BIG_C(0x67d25116U), BSWAP_32BIG_C(0xd47a0e94U), BSWAP_32BIG_C(0xc3aeeda3U),
    };
    r_rsip_func101(Param_p16_func101_005);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b7e0U, 0x00000010U, 0x8084001fU);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub022(0x00000800U, 0x0000b420U, 0x00000010U);

    r_rsip_func424();

    r_rsip_func_sub006(0x38008be0U, 0x1ae211e9U, 0x00A60000U);

    static const uint32_t Param_p16_func100_001[] =
    {
        BSWAP_32BIG_C(0x3fb09c52U), BSWAP_32BIG_C(0xf4ad40f7U), BSWAP_32BIG_C(0x2031c436U), BSWAP_32BIG_C(0x42e2665cU),
    };
    r_rsip_func100(Param_p16_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p16_func102_001[] =
        {
            BSWAP_32BIG_C(0xd93fb26bU), BSWAP_32BIG_C(0x02d104f7U), BSWAP_32BIG_C(0x2245df9cU), BSWAP_32BIG_C(
                0xc6545e89U),
        };
        r_rsip_func102(Param_p16_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p16_func100_002[] =
        {
            BSWAP_32BIG_C(0x8d19f931U), BSWAP_32BIG_C(0x5fc78a7eU), BSWAP_32BIG_C(0x5879765dU), BSWAP_32BIG_C(
                0x39d3f0ceU),
        };
        r_rsip_func100(Param_p16_func100_002);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7009d47U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x8188001fU);
        r_rsip_func_sub001(0x00890021U);

        r_rsip_func_sub008(0x000003a2U, 0x40000000U, 0x09108105U);
        WR4_PROG(REG_1420H, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
                 bswap_32big(0x00000002U));

        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

        static const uint32_t Param_p16_func100_003[] =
        {
            BSWAP_32BIG_C(0xc010a668U), BSWAP_32BIG_C(0x48133b28U), BSWAP_32BIG_C(0x602a9f2cU), BSWAP_32BIG_C(
                0xb18eda2fU),
        };
        r_rsip_func100(Param_p16_func100_003);
        r_rsip_func_sub016(0x81010080U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_p16_func102_002[] =
        {
            BSWAP_32BIG_C(0x7a131d71U), BSWAP_32BIG_C(0x792b5edbU), BSWAP_32BIG_C(0x672c8d6dU), BSWAP_32BIG_C(
                0x27b12dcaU),
        };
        r_rsip_func102(Param_p16_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
