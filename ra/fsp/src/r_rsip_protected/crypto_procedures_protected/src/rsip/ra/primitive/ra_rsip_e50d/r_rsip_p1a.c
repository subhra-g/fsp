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

rsip_ret_t r_rsip_p1a (const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x0001a001U, 0x000008c8U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a01U);

    static const uint32_t Param_p1a_func101_001[] =
    {
        BSWAP_32BIG_C(0xd554bd5dU), BSWAP_32BIG_C(0xc8ce8c28U), BSWAP_32BIG_C(0x3f23c0f6U), BSWAP_32BIG_C(0x21d5d25aU),
    };
    r_rsip_func101(Param_p1a_func101_001);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b400U, 0x00000050U, 0x80840000U);
    r_rsip_func_sub001(0x03420011U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a02U);

    static const uint32_t Param_p1a_func101_002[] =
    {
        BSWAP_32BIG_C(0xc591e0cdU), BSWAP_32BIG_C(0xb821a25fU), BSWAP_32BIG_C(0x7da1151cU), BSWAP_32BIG_C(0xfd90c1bbU),
    };
    r_rsip_func101(Param_p1a_func101_002);
    r_rsip_func103();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub023(0x0000b400U, 0x00000040U, 0x80840000U);
    r_rsip_func_sub001(0x03420011U);

    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_2004H, 0x000000b0U);

    r_rsip_func_sub033(0x00000020U, 0x00000000U, 0x00000020U, 0x00000100U);

    WR1_PROG(REG_1608H, 0x81880000U);
    r_rsip_func_sub001(0x01490021U);

    WAIT_STS(REG_2030H, 4, 1);

    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1608H, 0x80880000U);
    r_rsip_func_sub001(0x03450021U);
    r_rsip_func_sub001(0x00050021U);

    r_rsip_func_sub021(0x00003820U, 0x00008c20U, 0xf8ffffffU, 0x00003c20U);

    r_rsip_func_sub021(0x0000b400U, 0x0000001cU, 0x00003820U, 0x00008c20U);
    r_rsip_func_sub021(0xffffff3fU, 0x00009020U, 0x00000040U, 0x00003c20U);

    r_rsip_func_sub021(0x00000800U, 0x00000821U, 0x00000842U, 0x0000b460U);
    WR1_PROG(REG_1600H, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1600H, 0x00003060U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1004H, 0x00000000U);
    WR1_PROG(REG_1004H, 0x04040000U);

    static const uint32_t Param_p1a_func100_001[] =
    {
        BSWAP_32BIG_C(0x7f914ae6U), BSWAP_32BIG_C(0x5cb3110dU), BSWAP_32BIG_C(0x6e09a0a2U), BSWAP_32BIG_C(0xa0c9863eU),
    };
    r_rsip_func100(Param_p1a_func100_001);
    r_rsip_func401(InData_DomainParam);

    static const uint32_t Param_p1a_func100_002[] =
    {
        BSWAP_32BIG_C(0x102c581fU), BSWAP_32BIG_C(0x63de2631U), BSWAP_32BIG_C(0x332030d7U), BSWAP_32BIG_C(0x6e1d3e98U),
    };
    r_rsip_func100(Param_p1a_func100_002);
    r_rsip_func406(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x15000000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x16400000U);
    r_rsip_func_sub001(0x00c00021U);

    WR1_PROG(REG_1404H, 0x16900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x16e00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x1b400000U);
    r_rsip_func_sub001(0x00c00021U);

    WR1_PROG(REG_1404H, 0x1b900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    WR1_PROG(REG_1404H, 0x1be00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000026U);
    r_rsip_func_sub001(0x00c00015U);
    r_rsip_func_sub001(0x00c2000dU);
    r_rsip_func_sub001(0x00020005U);

    r_rsip_func_sub021(0x00000908U, 0x00000800U, 0x0000b420U, 0x0000001fU);

    r_rsip_func_sub021(0x0000b660U, 0x00000001U, 0x0000b520U, 0x00000100U);

    r_rsip_func_sub003(0x800103a0U, 0x0000001aU);

    for (iLoop = 0U; iLoop < 256U; iLoop++)
    {
        r_rsip_func405();

        r_rsip_func403();

        static const uint32_t Param_p1a_func101_003[] =
        {
            BSWAP_32BIG_C(0xec1b2ce2U), BSWAP_32BIG_C(0x09d227bfU), BSWAP_32BIG_C(0xd1ed09e3U), BSWAP_32BIG_C(
                0x090c4fecU),
        };
        r_rsip_func101(Param_p1a_func101_003);
        r_rsip_func402();

        r_rsip_func404();

        WR1_PROG(REG_1600H, 0x00002d00U);

        static const uint32_t Param_p1a_func101_004[] =
        {
            BSWAP_32BIG_C(0xe554e47eU), BSWAP_32BIG_C(0x3296aebcU), BSWAP_32BIG_C(0x412a548aU), BSWAP_32BIG_C(
                0x9eeec0cfU),
        };
        r_rsip_func101(Param_p1a_func101_004);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x08000909U);

    r_rsip_func_sub002(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);

    r_rsip_func_sub002(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);

    r_rsip_func_sub002(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);

    WR1_PROG(REG_1014H, 0x00000610U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1020H, 0x00000250U);
    WR1_PROG(REG_1010H, 0x00000008U);

    WR1_PROG(REG_1004H, 0x04040004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x12d00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0001dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);

    static const uint32_t Param_p1a_func100_003[] =
    {
        BSWAP_32BIG_C(0x0c9982c0U), BSWAP_32BIG_C(0xcbb05197U), BSWAP_32BIG_C(0x583cce74U), BSWAP_32BIG_C(0x22f03686U),
    };
    r_rsip_func100(Param_p1a_func100_003);
    r_rsip_func_sub013(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00010001U);
    r_rsip_func_sub007(0x00000570U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub005(0x00000250U, 0x04040002U, 0x00010001U);
    r_rsip_func_sub007(0x000005c0U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub005(0x000002a0U, 0x04040002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub030(0x12800000U, 0x00000821U, 0x80880001U);
    r_rsip_func_sub001(0x03430021U);

    r_rsip_func_sub022(0x00003801U, 0x00008c00U, 0x7fffffffU);

    r_rsip_func_sub012(0x12300000U, 0x0000b420U, 0x00000020U);
    WR1_PROG(REG_1608H, 0x80880001U);
    r_rsip_func_sub001(0x03430021U);

    r_rsip_func_sub021(0x0000b420U, 0x0000003cU, 0x00003841U, 0x001f6c42U);
    r_rsip_func_sub021(0x00001002U, 0x00000821U, 0x00003c01U, 0x00000800U);
    r_rsip_func_sub021(0x00000821U, 0x00000842U, 0x0000b460U, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub021(0x02003801U, 0x02003843U, 0x02003c41U, 0x02003c03U);

        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1600H, 0x00003060U);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a03U);

    static const uint32_t Param_p1a_func101_005[] =
    {
        BSWAP_32BIG_C(0x7b72a8abU), BSWAP_32BIG_C(0x8a09952eU), BSWAP_32BIG_C(0x3e852eacU), BSWAP_32BIG_C(0x3808d940U),
    };
    r_rsip_func101(Param_p1a_func101_005);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a01U);

    static const uint32_t Param_p1a_func101_006[] =
    {
        BSWAP_32BIG_C(0x09b991b9U), BSWAP_32BIG_C(0xc0a78c03U), BSWAP_32BIG_C(0x9295e8c3U), BSWAP_32BIG_C(0x37b6e1a5U),
    };
    r_rsip_func101(Param_p1a_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000027U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a01U);

    static const uint32_t Param_p1a_func101_007[] =
    {
        BSWAP_32BIG_C(0x8e8f190bU), BSWAP_32BIG_C(0x18f82bb9U), BSWAP_32BIG_C(0x551416bfU), BSWAP_32BIG_C(0xbfe9a918U),
    };
    r_rsip_func101(Param_p1a_func101_007);
    r_rsip_func044();

    static const uint32_t Param_p1a_func100_004[] =
    {
        BSWAP_32BIG_C(0x32ed748dU), BSWAP_32BIG_C(0x7931b41fU), BSWAP_32BIG_C(0xb590287aU), BSWAP_32BIG_C(0x6f4df683U),
    };
    r_rsip_func100(Param_p1a_func100_004);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    r_rsip_func_sub023(0x0000b420U, 0x00000040U, 0x81880001U);
    r_rsip_func_sub001(0x00890021U);

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);

    static const uint32_t Param_p1a_func100_005[] =
    {
        BSWAP_32BIG_C(0x93ecbffbU), BSWAP_32BIG_C(0xb67331d4U), BSWAP_32BIG_C(0x8b2eb2a4U), BSWAP_32BIG_C(0x91dab59bU),
    };
    r_rsip_func100(Param_p1a_func100_005);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);

    static const uint32_t Param_p1a_func100_006[] =
    {
        BSWAP_32BIG_C(0xce3b75bbU), BSWAP_32BIG_C(0xd25eccfeU), BSWAP_32BIG_C(0x220f01a3U), BSWAP_32BIG_C(0xfbce9766U),
    };
    r_rsip_func100(Param_p1a_func100_006);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub003(0x800103a0U, 0x00001a04U);

    static const uint32_t Param_p1a_func101_008[] =
    {
        BSWAP_32BIG_C(0xc6606eceU), BSWAP_32BIG_C(0x66f719e9U), BSWAP_32BIG_C(0xa978cb01U), BSWAP_32BIG_C(0x4b4415ceU),
    };
    r_rsip_func101(Param_p1a_func101_008);
    r_rsip_func103();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a02U);

    static const uint32_t Param_p1a_func101_009[] =
    {
        BSWAP_32BIG_C(0x9f07471dU), BSWAP_32BIG_C(0xb8fc4dcbU), BSWAP_32BIG_C(0xf9562fe2U), BSWAP_32BIG_C(0x954692e7U),
    };
    r_rsip_func101(Param_p1a_func101_009);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000026U);

    r_rsip_func_sub003(0x800103a0U, 0x00001a02U);

    static const uint32_t Param_p1a_func101_010[] =
    {
        BSWAP_32BIG_C(0xda7399faU), BSWAP_32BIG_C(0xef82f87cU), BSWAP_32BIG_C(0xa46328b2U), BSWAP_32BIG_C(0xbb4bbc13U),
    };
    r_rsip_func101(Param_p1a_func101_010);
    r_rsip_func044();

    static const uint32_t Param_p1a_func100_007[] =
    {
        BSWAP_32BIG_C(0x4a15e963U), BSWAP_32BIG_C(0x5fc230e4U), BSWAP_32BIG_C(0x48ffe099U), BSWAP_32BIG_C(0xdecc5d81U),
    };
    r_rsip_func100(Param_p1a_func100_007);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1608H, 0x81880001U);
    r_rsip_func_sub001(0x00890021U);

    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);

    static const uint32_t Param_p1a_func100_008[] =
    {
        BSWAP_32BIG_C(0xa5557d94U), BSWAP_32BIG_C(0x07c7160eU), BSWAP_32BIG_C(0xbde5e463U), BSWAP_32BIG_C(0xc038adcfU),
    };
    r_rsip_func100(Param_p1a_func100_008);
    r_rsip_func_sub008(0x000000a2U, 0x40000000U, 0x09108104U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);

    static const uint32_t Param_p1a_func100_009[] =
    {
        BSWAP_32BIG_C(0x53dc76eaU), BSWAP_32BIG_C(0xa52ec353U), BSWAP_32BIG_C(0x06f66599U), BSWAP_32BIG_C(0xf6502fdaU),
    };
    r_rsip_func100(Param_p1a_func100_009);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p1a_func102_001[] =
    {
        BSWAP_32BIG_C(0xf08d02c7U), BSWAP_32BIG_C(0x51e1a254U), BSWAP_32BIG_C(0x5de71d48U), BSWAP_32BIG_C(0x681da887U),
    };
    r_rsip_func102(Param_p1a_func102_001);
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
