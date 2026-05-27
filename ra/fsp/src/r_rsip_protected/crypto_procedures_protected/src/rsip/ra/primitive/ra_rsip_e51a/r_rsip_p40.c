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

rsip_ret_t r_rsip_p40 (const uint32_t InData_LC[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00400001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func_sub024(0x0000b420U, 0x0000000aU, 0x38008800U, 0x00000002U);
    r_rsip_func_sub024(0x10003401U, 0x38008800U, 0x00000003U, 0x10003401U);

    r_rsip_func_sub024(0x38008800U, 0x00000005U, 0x10003401U, 0x34202801U);
    WR1_PROG(REG_1600H, 0x20003401U);

    r_rsip_func_sub014(0x00007c00U, 0x00602000U);

    if (InData_LC[0] == 0x00000000U)
    {
        WR1_PROG(REG_143CH, 0x00b80000U);

        static const uint32_t Param_p40_func101_001[] =
        {
            BSWAP_32BIG_C(0x87d73112U), BSWAP_32BIG_C(0x99489c5eU), BSWAP_32BIG_C(0xf20e6c89U), BSWAP_32BIG_C(
                0x032ed21cU),
        };
        r_rsip_func101(Param_p40_func101_001);
    }
    else if (InData_LC[0] == 0x00000001U)
    {
        WR1_PROG(REG_143CH, 0x00b00000U);

        static const uint32_t Param_p40_func101_002[] =
        {
            BSWAP_32BIG_C(0xec9bfc30U), BSWAP_32BIG_C(0xfb4affb3U), BSWAP_32BIG_C(0x6bb08ff3U), BSWAP_32BIG_C(
                0x62202101U),
        };
        r_rsip_func101(Param_p40_func101_002);
    }
    else if (InData_LC[0] == 0x00000004U)
    {
        WR1_PROG(REG_143CH, 0x00b30000U);

        static const uint32_t Param_p40_func101_003[] =
        {
            BSWAP_32BIG_C(0x86402685U), BSWAP_32BIG_C(0x1b8cfb91U), BSWAP_32BIG_C(0x6abda81cU), BSWAP_32BIG_C(
                0x62d9c55fU),
        };
        r_rsip_func101(Param_p40_func101_003);
    }
    else if (InData_LC[0] == 0x00000006U)
    {
        WR1_PROG(REG_143CH, 0x00b50000U);

        static const uint32_t Param_p40_func101_004[] =
        {
            BSWAP_32BIG_C(0x3e0f61a3U), BSWAP_32BIG_C(0xb24c4426U), BSWAP_32BIG_C(0x9999b1daU), BSWAP_32BIG_C(
                0x6facaf71U),
        };
        r_rsip_func101(Param_p40_func101_004);
    }
    else if (InData_LC[0] == 0x00000007U)
    {
        WR1_PROG(REG_143CH, 0x00b60000U);

        static const uint32_t Param_p40_func101_005[] =
        {
            BSWAP_32BIG_C(0x7895e3f6U), BSWAP_32BIG_C(0x5ff712f1U), BSWAP_32BIG_C(0x7ff1876fU), BSWAP_32BIG_C(
                0x5cdceddcU),
        };
        r_rsip_func101(Param_p40_func101_005);
    }
    else if (InData_LC[0] == 0x00000008U)
    {
        WR1_PROG(REG_143CH, 0x00b70000U);

        static const uint32_t Param_p40_func101_006[] =
        {
            BSWAP_32BIG_C(0x3a062cc7U), BSWAP_32BIG_C(0x70fe1d0cU), BSWAP_32BIG_C(0x75bc5cdcU), BSWAP_32BIG_C(
                0xbc4ea24fU),
        };
        r_rsip_func101(Param_p40_func101_006);
    }
    else if (InData_LC[0] == 0x00000009U)
    {
        WR1_PROG(REG_143CH, 0x00b90000U);

        static const uint32_t Param_p40_func101_007[] =
        {
            BSWAP_32BIG_C(0x2d92e5ebU), BSWAP_32BIG_C(0xa26ef03dU), BSWAP_32BIG_C(0x08914987U), BSWAP_32BIG_C(
                0x5f530e60U),
        };
        r_rsip_func101(Param_p40_func101_007);
    }
    else
    {
        r_rsip_func_sub017(0x38000c00U, 0x00A60000U);

        static const uint32_t Param_p40_func101_008[] =
        {
            BSWAP_32BIG_C(0x5de847ccU), BSWAP_32BIG_C(0x6e822bb4U), BSWAP_32BIG_C(0x1d247d2fU), BSWAP_32BIG_C(
                0xf1d42455U),
        };
        r_rsip_func101(Param_p40_func101_008);
    }

    static const uint32_t Param_p40_func100_001[] =
    {
        BSWAP_32BIG_C(0xccdbfba4U), BSWAP_32BIG_C(0x31d111c4U), BSWAP_32BIG_C(0x885a0cd4U), BSWAP_32BIG_C(0xe3b36ac9U),
    };
    r_rsip_func100(Param_p40_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p40_func102_001[] =
        {
            BSWAP_32BIG_C(0x415a6dceU), BSWAP_32BIG_C(0x7a2bb17bU), BSWAP_32BIG_C(0x784354ccU), BSWAP_32BIG_C(
                0xfda5486eU),
        };
        r_rsip_func102(Param_p40_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000040U);

        static const uint32_t Param_p40_func101_009[] =
        {
            BSWAP_32BIG_C(0x193e2eddU), BSWAP_32BIG_C(0x8264c7ccU), BSWAP_32BIG_C(0x702c0503U), BSWAP_32BIG_C(
                0x7a200f8bU),
        };
        r_rsip_func101(Param_p40_func101_009);
        r_rsip_func040();

        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d05U);
        WR1_PROG(REG_1438H, 0x20000000U);
        r_rsip_func_sub001(0x00880011U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7008d05U);
        WR1_PROG(REG_1438H, 0x20000010U);
        r_rsip_func_sub001(0x00880011U);

        r_rsip_func_sub026(0x0000b420U, 0x000001d0U, 0x80880001U);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub025(0x0000b420U, 0x000001b0U, 0x00003c01U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WR1_PROG(REG_1438H, 0x20000020U);
        r_rsip_func_sub001(0x00880011U);
        WR1_PROG(REG_1A24H, 0x8c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p40_func100_002[] =
        {
            BSWAP_32BIG_C(0x8f0ea4ceU), BSWAP_32BIG_C(0xdebcbecfU), BSWAP_32BIG_C(0x253b5caaU), BSWAP_32BIG_C(
                0x8407d742U),
        };
        r_rsip_func100(Param_p40_func100_002);
        r_rsip_func_sub032(0x4a470044U, 0x00000000U);

        r_rsip_func_sub032(0x0e4704c4U, 0x0152db38U);

        r_rsip_func_sub032(0x4a040044U, 0x00000000U);

        r_rsip_func_sub032(0x0e040504U, 0x01f7370eU);

        r_rsip_func_sub026(0x0000b420U, 0x000001c0U, 0x80840001U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1B08H, 0x00000202U);

        static const uint32_t Param_p40_func102_002[] =
        {
            BSWAP_32BIG_C(0x14440fd8U), BSWAP_32BIG_C(0x7bc5db83U), BSWAP_32BIG_C(0x360b67c8U), BSWAP_32BIG_C(
                0xeb01427aU),
        };
        r_rsip_func102(Param_p40_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
