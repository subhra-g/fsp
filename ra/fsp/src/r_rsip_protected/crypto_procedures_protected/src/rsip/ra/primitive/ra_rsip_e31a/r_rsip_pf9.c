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

rsip_ret_t r_rsip_pf9 (const uint32_t InData_CurveType[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00f90001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func027(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x000034c0U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B0H, 0x0000a438U);

    static const uint32_t Param_pf9_func100_001[] =
    {
        BSWAP_32BIG_C(0x5502da09U), BSWAP_32BIG_C(0x2bc831ebU), BSWAP_32BIG_C(0x7ca03579U), BSWAP_32BIG_C(0xadeaf2f6U),
    };
    r_rsip_func100(Param_pf9_func100_001);
    r_rsip_func103();
    static const uint32_t Param_pf9_func100_002[] =
    {
        BSWAP_32BIG_C(0xbc0e9a91U), BSWAP_32BIG_C(0xc663f43fU), BSWAP_32BIG_C(0xf1772460U), BSWAP_32BIG_C(0x736b8c98U),
    };
    r_rsip_func100(Param_pf9_func100_002);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10009U, 0x00001800U);
    r_rsip_func_sub015(0x00010009U, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_pf9_func100_003[] =
    {
        BSWAP_32BIG_C(0x874b3659U), BSWAP_32BIG_C(0x037a6323U), BSWAP_32BIG_C(0x81e8b5c1U), BSWAP_32BIG_C(0xcd2ff8ceU),
    };
    r_rsip_func100(Param_pf9_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_pf9_func100_004[] =
    {
        BSWAP_32BIG_C(0x6d606379U), BSWAP_32BIG_C(0x0286ab85U), BSWAP_32BIG_C(0x85d2aa87U), BSWAP_32BIG_C(0x893299e4U),
    };
    r_rsip_func100(Param_pf9_func100_004);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x00009415U, 0x00c0002dU, 0x00000001U);

    r_rsip_func_sub001(0x0015000eU, 0x001c0000U, 0x0606000aU);

    r_rsip_func_sub003(0x00009454U, 0x00c0002dU, 0x00000002U);

    r_rsip_func_sub009(0x00009423U, 0x00c00031U, 0x00001800U);

    r_rsip_func_sub022(0x00000821U, 0x00000863U, 0x000008a5U);

    for (iLoop = 0U; iLoop < 64U; iLoop++)
    {
        r_rsip_func_sub001(0x001c0037U, 0x002a0000U, 0x0606000aU);

        WR1_PROG(REG_00B0H, 0x00000824U);
        r_rsip_func_sub006(0x80020000U, 0x03430009U, 0x00000884U, 0x38000c21U);
        r_rsip_func_sub022(0x2000d080U, 0x38000c63U, 0x1000d081U);

        r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

        static const uint32_t Param_pf9_func100_005[] =
        {
            BSWAP_32BIG_C(0x6a199833U), BSWAP_32BIG_C(0x21225edfU), BSWAP_32BIG_C(0x7fa7b803U), BSWAP_32BIG_C(
                0x2af8926aU),
        };
        r_rsip_func100(Param_pf9_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x0023002aU, 0x00690000U, 0x06060009U);

            static const uint32_t Param_pf9_func101_001[] =
            {
                BSWAP_32BIG_C(0x4c78fb83U), BSWAP_32BIG_C(0xaec4e66aU), BSWAP_32BIG_C(0xd06a8b40U), BSWAP_32BIG_C(
                    0x9f73cf6bU),
            };
            r_rsip_func101(Param_pf9_func101_001);
        }
        else
        {
            r_rsip_func_sub001(0x0023002aU, 0x00370000U, 0x06060009U);

            static const uint32_t Param_pf9_func101_002[] =
            {
                BSWAP_32BIG_C(0x6d63ad29U), BSWAP_32BIG_C(0x7af200efU), BSWAP_32BIG_C(0x5484f84aU), BSWAP_32BIG_C(
                    0x6b19c7adU),
            };
            r_rsip_func101(Param_pf9_func101_002);
        }

        r_rsip_func_sub001(0x0054003dU, 0x002a0000U, 0x06060007U);

        r_rsip_func_sub001(0x00540037U, 0x00310000U, 0x06060007U);

        WR1_PROG(REG_00B0H, 0x0000082bU);
        r_rsip_func_sub012(0x80020040U, 0x03430009U);

        r_rsip_func_sub001(0x0023002aU, 0x003d0000U, 0x06060009U);

        r_rsip_func_sub001(0x00240031U, 0x00370000U, 0x06060009U);

        WR1_PROG(REG_0094H, 0x00002ca0U);

        static const uint32_t Param_pf9_func101_003[] =
        {
            BSWAP_32BIG_C(0x24205b4fU), BSWAP_32BIG_C(0x8b7497b6U), BSWAP_32BIG_C(0xd46d8732U), BSWAP_32BIG_C(
                0xc92c1cd0U),
        };
        r_rsip_func101(Param_pf9_func101_003);
    }

    r_rsip_func_sub010(0x380088a0U, 0x00000040U, 0x00270000U);

    WR1_PROG(REG_0040H, 0x00402000U);

    r_rsip_func_sub001(0x001c0037U, 0x002a0000U, 0x0606000aU);

    WR1_PROG(REG_00B0H, 0x00000824U);
    r_rsip_func_sub006(0x80020000U, 0x03430009U, 0x00000884U, 0x38000c21U);
    r_rsip_func_sub022(0x2000d080U, 0x38000c63U, 0x1000d081U);

    r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

    static const uint32_t Param_pf9_func100_006[] =
    {
        BSWAP_32BIG_C(0xb80f0fc3U), BSWAP_32BIG_C(0x8130edf7U), BSWAP_32BIG_C(0xbac1b820U), BSWAP_32BIG_C(0x470f5066U),
    };
    r_rsip_func100(Param_pf9_func100_006);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        r_rsip_func_sub001(0x0023002aU, 0x00690000U, 0x06060009U);

        static const uint32_t Param_pf9_func101_004[] =
        {
            BSWAP_32BIG_C(0xb73e7f1eU), BSWAP_32BIG_C(0x2792ddb1U), BSWAP_32BIG_C(0x556968beU), BSWAP_32BIG_C(
                0xd75c42b9U),
        };
        r_rsip_func101(Param_pf9_func101_004);
    }
    else
    {
        r_rsip_func_sub001(0x0023002aU, 0x00370000U, 0x06060009U);

        static const uint32_t Param_pf9_func101_005[] =
        {
            BSWAP_32BIG_C(0xfed810bfU), BSWAP_32BIG_C(0x050ae387U), BSWAP_32BIG_C(0xed8e191dU), BSWAP_32BIG_C(
                0x9abe5e6dU),
        };
        r_rsip_func101(Param_pf9_func101_005);
    }

    r_rsip_func_sub001(0x00150037U, 0x00460000U, 0x06060009U);

    WR1_PROG(REG_0094H, 0x00003406U);

    r_rsip_func028(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f9U, 0x00000000U);

    static const uint32_t Param_pf9_func101_006[] =
    {
        BSWAP_32BIG_C(0x16f649c3U), BSWAP_32BIG_C(0x66e15067U), BSWAP_32BIG_C(0xfdc8d975U), BSWAP_32BIG_C(0xec719d5dU),
    };
    r_rsip_func101(Param_pf9_func101_006);
    r_rsip_func089();

    static const uint32_t Param_pf9_func100_007[] =
    {
        BSWAP_32BIG_C(0xf389ff0dU), BSWAP_32BIG_C(0xa44de422U), BSWAP_32BIG_C(0xb6507f03U), BSWAP_32BIG_C(0xe0229350U),
    };
    r_rsip_func100(Param_pf9_func100_007);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf9_func102_001[] =
        {
            BSWAP_32BIG_C(0xadb68688U), BSWAP_32BIG_C(0x02d8a149U), BSWAP_32BIG_C(0xcaf5985bU), BSWAP_32BIG_C(
                0xfc40cb5eU),
        };
        r_rsip_func102(Param_pf9_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf9_func100_008[] =
        {
            BSWAP_32BIG_C(0x765411acU), BSWAP_32BIG_C(0xa004d3caU), BSWAP_32BIG_C(0xd94248d8U), BSWAP_32BIG_C(
                0xc6a78f17U),
        };
        r_rsip_func100(Param_pf9_func100_008);
        r_rsip_func103();
        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f901U, 0x00000000U);

        static const uint32_t Param_pf9_func101_007[] =
        {
            BSWAP_32BIG_C(0x9c4b0006U), BSWAP_32BIG_C(0x56d9c4b0U), BSWAP_32BIG_C(0x2b85a3b2U), BSWAP_32BIG_C(
                0xd6a01435U),
        };
        r_rsip_func101(Param_pf9_func101_007);
        r_rsip_func143();

        r_rsip_func076();

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f901U, 0x00000000U);

        static const uint32_t Param_pf9_func101_008[] =
        {
            BSWAP_32BIG_C(0x8f00bdf5U), BSWAP_32BIG_C(0x08b3de14U), BSWAP_32BIG_C(0x1d2c0001U), BSWAP_32BIG_C(
                0xb638b8f3U),
        };
        r_rsip_func101(Param_pf9_func101_008);
        r_rsip_func044();

        static const uint32_t Param_pf9_func100_009[] =
        {
            BSWAP_32BIG_C(0x60d506a7U), BSWAP_32BIG_C(0xb89c23cbU), BSWAP_32BIG_C(0x645dec86U), BSWAP_32BIG_C(
                0x62d14b28U),
        };
        r_rsip_func100(Param_pf9_func100_009);
        WR1_PROG(REG_00B0H, 0x00009846U);

        r_rsip_func_sub004(0x40000200U, 0xe7009d07U, 0x00430031U, 0x00001032U);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[5]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[9]);

        static const uint32_t Param_pf9_func100_010[] =
        {
            BSWAP_32BIG_C(0xa8e86076U), BSWAP_32BIG_C(0xc3bdc4c4U), BSWAP_32BIG_C(0x90c3f5f4U), BSWAP_32BIG_C(
                0x00d07867U),
        };
        r_rsip_func100(Param_pf9_func100_010);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[13]);

        static const uint32_t Param_pf9_func100_011[] =
        {
            BSWAP_32BIG_C(0x40cbf55fU), BSWAP_32BIG_C(0x9a2e5dcbU), BSWAP_32BIG_C(0xbefaa4acU), BSWAP_32BIG_C(
                0xc6509d36U),
        };
        r_rsip_func100(Param_pf9_func100_011);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_PrivKeyIndex[0]);

        static const uint32_t Param_pf9_func100_012[] =
        {
            BSWAP_32BIG_C(0x0737beb8U), BSWAP_32BIG_C(0x140fc657U), BSWAP_32BIG_C(0x9fc2d4ceU), BSWAP_32BIG_C(
                0xf13581e2U),
        };
        r_rsip_func100(Param_pf9_func100_012);
        r_rsip_func103();
        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f902U, 0x00000000U);

        static const uint32_t Param_pf9_func101_009[] =
        {
            BSWAP_32BIG_C(0xa2187dfdU), BSWAP_32BIG_C(0x61ba8197U), BSWAP_32BIG_C(0x2378c734U), BSWAP_32BIG_C(
                0xb6d5248fU),
        };
        r_rsip_func101(Param_pf9_func101_009);
        r_rsip_func143();

        r_rsip_func077();

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f902U, 0x00000000U);

        static const uint32_t Param_pf9_func101_010[] =
        {
            BSWAP_32BIG_C(0xde0e336cU), BSWAP_32BIG_C(0xe51dd53bU), BSWAP_32BIG_C(0x24551207U), BSWAP_32BIG_C(
                0x55dfc355U),
        };
        r_rsip_func101(Param_pf9_func101_010);
        r_rsip_func044();

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pf9_func100_013[] =
        {
            BSWAP_32BIG_C(0xbf9235dfU), BSWAP_32BIG_C(0x1e3de2e9U), BSWAP_32BIG_C(0x82323264U), BSWAP_32BIG_C(
                0x59737254U),
        };
        r_rsip_func100(Param_pf9_func100_013);
        WR1_PROG(REG_00D4H, 0x40000200U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub009(0x00009838U, 0x00430031U, 0x00001800U);

        WR1_PROG(REG_0008H, 0x00001032U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[5]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[9]);

        static const uint32_t Param_pf9_func100_014[] =
        {
            BSWAP_32BIG_C(0xb9faede6U), BSWAP_32BIG_C(0xec5bb281U), BSWAP_32BIG_C(0xed6e025dU), BSWAP_32BIG_C(
                0x4548fcb5U),
        };
        r_rsip_func100(Param_pf9_func100_014);
        WR1_PROG(REG_00D4H, 0x40000200U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub009(0x0000983fU, 0x00430031U, 0x00001800U);

        WR1_PROG(REG_0008H, 0x00001032U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[13]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[17]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[21]);

        static const uint32_t Param_pf9_func100_015[] =
        {
            BSWAP_32BIG_C(0x82b4e3d2U), BSWAP_32BIG_C(0x431fed20U), BSWAP_32BIG_C(0xca97a048U), BSWAP_32BIG_C(
                0xceb1aca5U),
        };
        r_rsip_func100(Param_pf9_func100_015);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[25]);

        static const uint32_t Param_pf9_func100_016[] =
        {
            BSWAP_32BIG_C(0x6be56124U), BSWAP_32BIG_C(0x3df9e981U), BSWAP_32BIG_C(0xf15277e2U), BSWAP_32BIG_C(
                0x8078cf72U),
        };
        r_rsip_func100(Param_pf9_func100_016);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_pf9_func102_002[] =
        {
            BSWAP_32BIG_C(0x7aa29a30U), BSWAP_32BIG_C(0x221882f7U), BSWAP_32BIG_C(0x261af4eeU), BSWAP_32BIG_C(
                0x8c74ddfcU),
        };
        r_rsip_func102(Param_pf9_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
