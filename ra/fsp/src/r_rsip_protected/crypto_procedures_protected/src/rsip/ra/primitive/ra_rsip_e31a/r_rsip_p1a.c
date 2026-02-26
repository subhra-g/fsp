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

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x0001a001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B0H, 0x000014a0U);

    static const uint32_t Param_p1a_func100_001[] =
    {
        BSWAP_32BIG_C(0x7f72aa34U), BSWAP_32BIG_C(0x3efbae99U), BSWAP_32BIG_C(0x21efae5dU), BSWAP_32BIG_C(0x692e2f19U),
    };
    r_rsip_func100(Param_p1a_func100_001);
    r_rsip_func103();
    static const uint32_t Param_p1a_func100_002[] =
    {
        BSWAP_32BIG_C(0xde3a1f67U), BSWAP_32BIG_C(0xa48a6ad6U), BSWAP_32BIG_C(0x4fc602e5U), BSWAP_32BIG_C(0xe56880a3U),
    };
    r_rsip_func100(Param_p1a_func100_002);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    WR1_PROG(REG_00F0H, 0x00000001U);
    WR1_PROG(REG_00F4H, 0x000000b0U);

    WR1_PROG(REG_0014H, 0x00000020U);
    WR1_PROG(REG_0104H, 0x00000000U);
    WR1_PROG(REG_0014H, 0x00000020U);
    WR1_PROG(REG_0100H, 0x00000100U);

    r_rsip_func_sub009(0x000018a0U, 0x01430021U, 0x00001800U);

    WAIT_STS(REG_0118H, 4, 1);

    WR1_PROG(REG_0094H, 0x00000800U);
    r_rsip_func_sub005(0x80880000U, 0x03450021U, 0x00050021U);

    r_rsip_func_sub022(0x00003820U, 0x00008c20U, 0xf8ffffffU);
    r_rsip_func_sub022(0x00003c20U, 0x0000b400U, 0x0000001cU);

    r_rsip_func_sub022(0x00003820U, 0x00008c20U, 0xffffff3fU);
    r_rsip_func_sub022(0x00009020U, 0x00000040U, 0x00003c20U);

    r_rsip_func_sub022(0x00000800U, 0x00000821U, 0x00000842U);
    WR1_PROG(REG_0094H, 0x0000b460U);
    WR1_PROG(REG_0094H, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub022(0x02003801U, 0x02003843U, 0x02003c41U);
        r_rsip_func_sub022(0x02003c03U, 0x00002c20U, 0x00003060U);
    }

    r_rsip_func401(InData_DomainParam);

    r_rsip_func406(InData_DomainParam);

    r_rsip_func_sub009(0x00001487U, 0x00c00021U, 0x00001800U);

    WR1_PROG(REG_00B0H, 0x00000840U);
    r_rsip_func_sub012(0x80020000U, 0x03430009U);
    WR1_PROG(REG_00B0H, 0x000004b1U);
    r_rsip_func_sub012(0x81020000U, 0x00c90009U);

    r_rsip_func_sub003(0x00001450U, 0x00c00015U, 0x00000026U);
    r_rsip_func_sub015(0x00c00009U, 0x00001800U);

    r_rsip_func_sub009(0x00001464U, 0x00c00021U, 0x00001800U);

    r_rsip_func_sub003(0x00001469U, 0x00c00015U, 0x00000026U);
    r_rsip_func_sub015(0x00c00009U, 0x00001800U);

    r_rsip_func_sub003(0x0000146eU, 0x00c00015U, 0x00000026U);
    r_rsip_func_sub015(0x00c00009U, 0x00001800U);

    r_rsip_func_sub009(0x0000148cU, 0x00c00021U, 0x00001800U);

    r_rsip_func_sub003(0x00001491U, 0x00c00015U, 0x00000026U);
    r_rsip_func_sub015(0x00c00009U, 0x00001800U);

    r_rsip_func_sub003(0x00001496U, 0x00c00015U, 0x00000026U);
    r_rsip_func_sub015(0x00c00009U, 0x00001800U);

    r_rsip_func_sub022(0x000008c6U, 0x00000800U, 0x0000b420U);
    r_rsip_func_sub022(0x0000001fU, 0x0000b440U, 0x00000001U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000001aU, 0x00000000U);

    for (iLoop = 0U; iLoop < 256U; iLoop++)
    {
        r_rsip_func405();

        r_rsip_func403();

        static const uint32_t Param_p1a_func101_001[] =
        {
            BSWAP_32BIG_C(0x567a8c23U), BSWAP_32BIG_C(0x898796f0U), BSWAP_32BIG_C(0xcc2a15cdU), BSWAP_32BIG_C(
                0x87d028c3U),
        };
        r_rsip_func101(Param_p1a_func101_001);
        r_rsip_func402();

        r_rsip_func404();

        WR1_PROG(REG_0094H, 0x00002cc0U);

        static const uint32_t Param_p1a_func101_002[] =
        {
            BSWAP_32BIG_C(0xbfedc25bU), BSWAP_32BIG_C(0x375f4b46U), BSWAP_32BIG_C(0xb0bfebdaU), BSWAP_32BIG_C(
                0x363b0c19U),
        };
        r_rsip_func101(Param_p1a_func101_002);
    }

    r_rsip_func_sub010(0x380088c0U, 0x00000100U, 0x00270000U);

    WR1_PROG(REG_0040H, 0x00402000U);

    static const uint32_t Param_p1a_func100_003[] =
    {
        BSWAP_32BIG_C(0xd03a1851U), BSWAP_32BIG_C(0x90315fa9U), BSWAP_32BIG_C(0x50f4675eU), BSWAP_32BIG_C(0xf6f688f5U),
    };
    r_rsip_func100(Param_p1a_func100_003);

    r_rsip_func_sub001(0x00870064U, 0x00550000U, 0x0404000aU);

    r_rsip_func_sub001(0x00870069U, 0x005a0000U, 0x0404000aU);

    r_rsip_func_sub001(0x0087006eU, 0x005f0000U, 0x0404000aU);

    r_rsip_func_sub003(0x00001482U, 0x00c0001dU, 0x00000001U);

    r_rsip_func_sub001(0x0082005fU, 0x00230005U, 0x04040002U);

    r_rsip_func_sub003(0x0000142dU, 0x00c0001dU, 0x00000002U);

    r_rsip_func_sub001(0x002d0005U, 0x00280000U, 0x0404000aU);

    r_rsip_func_sub021(0x00280023U, 0x002d0005U, 0x04040000U);
    r_rsip_func_sub020(0x20010001U, 0x00000001U);
    WR1_PROG(REG_0040H, 0x00000d00U);

    r_rsip_func_sub001(0x002d0055U, 0x00230005U, 0x04040002U);

    r_rsip_func_sub001(0x002d005aU, 0x00280005U, 0x04040002U);

    WR1_PROG(REG_00B0H, 0x00001823U);
    WR1_PROG(REG_0094H, 0x00000821U);
    r_rsip_func_sub006(0x80880001U, 0x03430021U, 0x0000b420U, 0x0000001cU);
    WR1_PROG(REG_0094H, 0x00003841U);

    WR1_PROG(REG_0094H, 0x001f6c42U);

    WR1_PROG(REG_00B0H, 0x00001828U);
    WR1_PROG(REG_0094H, 0x00000821U);
    r_rsip_func_sub006(0x80880001U, 0x03430021U, 0x00003801U, 0x00008c00U);
    r_rsip_func_sub022(0x7fffffffU, 0x00001002U, 0x00003c01U);

    r_rsip_func_sub022(0x00000800U, 0x00000821U, 0x00000842U);
    WR1_PROG(REG_0094H, 0x0000b460U);
    WR1_PROG(REG_0094H, 0x0000001fU);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub022(0x02003801U, 0x02003843U, 0x02003c41U);
        r_rsip_func_sub022(0x02003c03U, 0x00002c20U, 0x00003060U);
    }

    WR1_PROG(REG_0094H, 0x00000800U);

    WR1_PROG(REG_00B0H, 0x000014a5U);
    r_rsip_func_sub012(0x81880000U, 0x00c90021U);

    static const uint32_t Param_p1a_func100_004[] =
    {
        BSWAP_32BIG_C(0x83c5af9fU), BSWAP_32BIG_C(0xfef15c09U), BSWAP_32BIG_C(0x8ff99f7cU), BSWAP_32BIG_C(0x0c7f41a7U),
    };
    r_rsip_func100(Param_p1a_func100_004);
    r_rsip_func103();

    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

    r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00001a01U, 0x00000000U);

    static const uint32_t Param_p1a_func101_003[] =
    {
        BSWAP_32BIG_C(0x0fac098dU), BSWAP_32BIG_C(0xaf8bf61aU), BSWAP_32BIG_C(0x0afaa949U), BSWAP_32BIG_C(0x68139733U),
    };
    r_rsip_func101(Param_p1a_func101_003);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x00000027U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00001a01U, 0x00000000U);

    static const uint32_t Param_p1a_func101_004[] =
    {
        BSWAP_32BIG_C(0x83240c67U), BSWAP_32BIG_C(0x8ae0a714U), BSWAP_32BIG_C(0xd580b879U), BSWAP_32BIG_C(0x93a7e439U),
    };
    r_rsip_func101(Param_p1a_func101_004);
    r_rsip_func044();

    static const uint32_t Param_p1a_func100_005[] =
    {
        BSWAP_32BIG_C(0xc3b8d78bU), BSWAP_32BIG_C(0x9a9b0a47U), BSWAP_32BIG_C(0x5b987aaeU), BSWAP_32BIG_C(0x6bd7b57eU),
    };
    r_rsip_func100(Param_p1a_func100_005);
    WR1_PROG(REG_00B0H, 0x000018a0U);

    r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00430021U, 0x00001022U);
    RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[5]);

    static const uint32_t Param_p1a_func100_006[] =
    {
        BSWAP_32BIG_C(0x19f98e1fU), BSWAP_32BIG_C(0xb284c875U), BSWAP_32BIG_C(0x9a86de85U), BSWAP_32BIG_C(0x4bc4f3e7U),
    };
    r_rsip_func100(Param_p1a_func100_006);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[9]);

    static const uint32_t Param_p1a_func100_007[] =
    {
        BSWAP_32BIG_C(0xf9c1349cU), BSWAP_32BIG_C(0x2325a667U), BSWAP_32BIG_C(0x6917b236U), BSWAP_32BIG_C(0x6ab09828U),
    };
    r_rsip_func100(Param_p1a_func100_007);
    r_rsip_func_sub017(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_002CH, &OutData_PrivKeyIndex[0]);

    static const uint32_t Param_p1a_func100_008[] =
    {
        BSWAP_32BIG_C(0x6e654757U), BSWAP_32BIG_C(0x3eeedb19U), BSWAP_32BIG_C(0xc1fe89c3U), BSWAP_32BIG_C(0x0ea3b7f7U),
    };
    r_rsip_func100(Param_p1a_func100_008);
    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

    r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00001a02U, 0x00000000U);

    static const uint32_t Param_p1a_func101_005[] =
    {
        BSWAP_32BIG_C(0x5f3bea9eU), BSWAP_32BIG_C(0x90827fb5U), BSWAP_32BIG_C(0x0d7daeb2U), BSWAP_32BIG_C(0x6abea2c1U),
    };
    r_rsip_func101(Param_p1a_func101_005);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x00000026U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00001a02U, 0x00000000U);

    static const uint32_t Param_p1a_func101_006[] =
    {
        BSWAP_32BIG_C(0x14d7f3fcU), BSWAP_32BIG_C(0x74e9c0d3U), BSWAP_32BIG_C(0x379fa929U), BSWAP_32BIG_C(0x15ea30d8U),
    };
    r_rsip_func101(Param_p1a_func101_006);
    r_rsip_func044();

    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

    static const uint32_t Param_p1a_func100_009[] =
    {
        BSWAP_32BIG_C(0x68249370U), BSWAP_32BIG_C(0xe955ac24U), BSWAP_32BIG_C(0x6f6ad3eaU), BSWAP_32BIG_C(0xffc032faU),
    };
    r_rsip_func100(Param_p1a_func100_009);
    WR1_PROG(REG_00D4H, 0x40000100U);
    WR1_PROG(REG_00D0H, 0xe8008107U);
    r_rsip_func_sub009(0x000018a5U, 0x00430021U, 0x00001800U);

    WR1_PROG(REG_0008H, 0x00001022U);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[5]);

    static const uint32_t Param_p1a_func100_010[] =
    {
        BSWAP_32BIG_C(0x1f4f3833U), BSWAP_32BIG_C(0x58992e73U), BSWAP_32BIG_C(0x116c1a2bU), BSWAP_32BIG_C(0xdc12a38fU),
    };
    r_rsip_func100(Param_p1a_func100_010);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[9]);

    static const uint32_t Param_p1a_func100_011[] =
    {
        BSWAP_32BIG_C(0x65416297U), BSWAP_32BIG_C(0x9aac5868U), BSWAP_32BIG_C(0x75c85bd4U), BSWAP_32BIG_C(0x16e8886eU),
    };
    r_rsip_func100(Param_p1a_func100_011);
    r_rsip_func_sub017(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_002CH, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p1a_func102_001[] =
    {
        BSWAP_32BIG_C(0xe3659444U), BSWAP_32BIG_C(0xedaf0d68U), BSWAP_32BIG_C(0x173c9684U), BSWAP_32BIG_C(0x9f9c40beU),
    };
    r_rsip_func102(Param_p1a_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
