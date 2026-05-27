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

rsip_ret_t r_rsip_pf4 (const uint32_t InData_CurveType[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00f40001U, 0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3420a800U, 0x00000003U, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000002U);

    r_rsip_func070(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x000034c0U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B0H, 0x00002428U);

    static const uint32_t Param_pf4_func100_001[] =
    {
        BSWAP_32BIG_C(0x8cd7e01eU), BSWAP_32BIG_C(0x170298ccU), BSWAP_32BIG_C(0xdc4acbd2U), BSWAP_32BIG_C(0x584d5fc3U),
    };
    r_rsip_func100(Param_pf4_func100_001);
    r_rsip_func103();
    static const uint32_t Param_pf4_func100_002[] =
    {
        BSWAP_32BIG_C(0xeb363f75U), BSWAP_32BIG_C(0x12e08338U), BSWAP_32BIG_C(0x6d4688a5U), BSWAP_32BIG_C(0x07aa49d8U),
    };
    r_rsip_func100(Param_pf4_func100_002);
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10009U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00010009U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_pf4_func100_003[] =
    {
        BSWAP_32BIG_C(0x21a93817U), BSWAP_32BIG_C(0xf12135d3U), BSWAP_32BIG_C(0xe03918ffU), BSWAP_32BIG_C(0xa2d1bfd9U),
    };
    r_rsip_func100(Param_pf4_func100_003);
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00c10011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func_sub004(0x0000140fU, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

    r_rsip_func_sub001(0x000f000aU, 0x00140000U, 0x0404000aU);

    r_rsip_func_sub004(0x0000143cU, 0x00c0001dU);
    WR1_PROG(REG_0014H, 0x000000a5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(0x00000002U));

    r_rsip_func_sub004(0x00001419U, 0x00c00021U);

    r_rsip_func_sub016(0x00000821U, 0x00000863U, 0x000008a5U);

    for (iLoop = 0U; iLoop < 64U; iLoop++)
    {
        r_rsip_func_sub001(0x00140027U, 0x001e0000U, 0x0404000aU);

        WR1_PROG(REG_00B0H, 0x0000081aU);
        r_rsip_func_sub003(0x80020000U, 0x03430009U);

        r_rsip_func_sub016(0x00000884U, 0x38000c21U, 0x2000d080U);

        WR1_PROG(REG_0094H, 0x38000c63U);
        WR1_PROG(REG_0094H, 0x1000d081U);

        r_rsip_func_sub007(0x38008880U, 0x00000003U, 0x00260000U);

        static const uint32_t Param_pf4_func100_004[] =
        {
            BSWAP_32BIG_C(0xcc14d369U), BSWAP_32BIG_C(0xf57f9322U), BSWAP_32BIG_C(0xc6db123eU), BSWAP_32BIG_C(
                0xff2adde3U),
        };
        r_rsip_func100(Param_pf4_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x0019001eU, 0x004b0000U, 0x04040009U);

            static const uint32_t Param_pf4_func101_001[] =
            {
                BSWAP_32BIG_C(0xae2694b3U), BSWAP_32BIG_C(0x7bfda795U), BSWAP_32BIG_C(0x65ac1cd2U), BSWAP_32BIG_C(
                    0x10b4c759U),
            };
            r_rsip_func101(Param_pf4_func101_001);
        }
        else
        {
            r_rsip_func_sub001(0x0019001eU, 0x00270000U, 0x04040009U);

            static const uint32_t Param_pf4_func101_002[] =
            {
                BSWAP_32BIG_C(0x50b3c820U), BSWAP_32BIG_C(0x0c5d5e17U), BSWAP_32BIG_C(0xc47efc5bU), BSWAP_32BIG_C(
                    0x39276c98U),
            };
            r_rsip_func101(Param_pf4_func101_002);
        }

        r_rsip_func_sub001(0x003c002bU, 0x001e0000U, 0x04040007U);

        r_rsip_func_sub001(0x003c0027U, 0x00230000U, 0x04040007U);

        WR1_PROG(REG_00B0H, 0x0000081fU);
        r_rsip_func_sub003(0x80020040U, 0x03430009U);

        r_rsip_func_sub001(0x0019001eU, 0x002b0000U, 0x04040009U);

        r_rsip_func_sub001(0x001a0023U, 0x00270000U, 0x04040009U);

        WR1_PROG(REG_0094H, 0x00002ca0U);

        static const uint32_t Param_pf4_func101_003[] =
        {
            BSWAP_32BIG_C(0x215accdeU), BSWAP_32BIG_C(0x5e8874bbU), BSWAP_32BIG_C(0x5d1c8883U), BSWAP_32BIG_C(
                0xdedfcd2eU),
        };
        r_rsip_func101(Param_pf4_func101_003);
    }

    r_rsip_func_sub007(0x380088a0U, 0x00000040U, 0x00260000U);

    WR1_PROG(REG_0040H, 0x00402000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub001(0x00140027U, 0x001e0000U, 0x0404000aU);

    WR1_PROG(REG_00B0H, 0x0000081aU);
    r_rsip_func_sub003(0x80020000U, 0x03430009U);

    r_rsip_func_sub016(0x00000884U, 0x38000c21U, 0x2000d080U);

    WR1_PROG(REG_0094H, 0x38000c63U);
    WR1_PROG(REG_0094H, 0x1000d081U);

    r_rsip_func_sub007(0x38008880U, 0x00000003U, 0x00260000U);

    static const uint32_t Param_pf4_func100_005[] =
    {
        BSWAP_32BIG_C(0x1567e14aU), BSWAP_32BIG_C(0x92dfb41bU), BSWAP_32BIG_C(0xa8c4d888U), BSWAP_32BIG_C(0xc08b3a48U),
    };
    r_rsip_func100(Param_pf4_func100_005);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        r_rsip_func_sub001(0x0019001eU, 0x004b0000U, 0x04040009U);

        static const uint32_t Param_pf4_func101_004[] =
        {
            BSWAP_32BIG_C(0x59dbd988U), BSWAP_32BIG_C(0x7918f851U), BSWAP_32BIG_C(0x0f89a197U), BSWAP_32BIG_C(
                0x84b77d1eU),
        };
        r_rsip_func101(Param_pf4_func101_004);
    }
    else
    {
        r_rsip_func_sub001(0x0019001eU, 0x00270000U, 0x04040009U);

        static const uint32_t Param_pf4_func101_005[] =
        {
            BSWAP_32BIG_C(0x6e51fd92U), BSWAP_32BIG_C(0x7d7737c6U), BSWAP_32BIG_C(0xb5f7e8efU), BSWAP_32BIG_C(
                0x8640d0e8U),
        };
        r_rsip_func101(Param_pf4_func101_005);
    }

    r_rsip_func_sub001(0x000f0027U, 0x00320000U, 0x04040009U);

    WR1_PROG(REG_0094H, 0x00003406U);

    r_rsip_func071(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x800100e0U, 0x000000f4U);

    static const uint32_t Param_pf4_func101_006[] =
    {
        BSWAP_32BIG_C(0xb3bfaac0U), BSWAP_32BIG_C(0x0375002bU), BSWAP_32BIG_C(0x3361cb72U), BSWAP_32BIG_C(0xab63dd04U),
    };
    r_rsip_func101(Param_pf4_func101_006);
    r_rsip_func088();

    static const uint32_t Param_pf4_func100_006[] =
    {
        BSWAP_32BIG_C(0x293ee29aU), BSWAP_32BIG_C(0xaa07287fU), BSWAP_32BIG_C(0x192cd524U), BSWAP_32BIG_C(0xdc5f77b6U),
    };
    r_rsip_func100(Param_pf4_func100_006);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf4_func102_001[] =
        {
            BSWAP_32BIG_C(0x0fb53e3aU), BSWAP_32BIG_C(0xfffe91acU), BSWAP_32BIG_C(0x23bfef53U), BSWAP_32BIG_C(
                0x3861f37dU),
        };
        r_rsip_func102(Param_pf4_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf4_func100_007[] =
        {
            BSWAP_32BIG_C(0xafb699ccU), BSWAP_32BIG_C(0x2610da2cU), BSWAP_32BIG_C(0x72f3ac7eU), BSWAP_32BIG_C(
                0x7aff8395U),
        };
        r_rsip_func100(Param_pf4_func100_007);
        r_rsip_func103();
        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

        r_rsip_func_sub002(0x800100e0U, 0x0000f401U);

        static const uint32_t Param_pf4_func101_007[] =
        {
            BSWAP_32BIG_C(0x78d46a48U), BSWAP_32BIG_C(0x80218bdcU), BSWAP_32BIG_C(0x3f223f8cU), BSWAP_32BIG_C(
                0x3eb11913U),
        };
        r_rsip_func101(Param_pf4_func101_007);
        r_rsip_func143();

        r_rsip_func074();

        r_rsip_func_sub002(0x800100e0U, 0x0000f401U);

        static const uint32_t Param_pf4_func101_008[] =
        {
            BSWAP_32BIG_C(0x75a0dedfU), BSWAP_32BIG_C(0x9da5b390U), BSWAP_32BIG_C(0xe8fb5be4U), BSWAP_32BIG_C(
                0xa653b83eU),
        };
        r_rsip_func101(Param_pf4_func101_008);
        r_rsip_func044();

        static const uint32_t Param_pf4_func100_008[] =
        {
            BSWAP_32BIG_C(0x366eec1aU), BSWAP_32BIG_C(0xc4401494U), BSWAP_32BIG_C(0x383425f0U), BSWAP_32BIG_C(
                0xe577b13bU),
        };
        r_rsip_func100(Param_pf4_func100_008);
        WR1_PROG(REG_00B0H, 0x00001832U);

        WR1_PROG(REG_00D4H, 0x40000100U);
        r_rsip_func_sub006(0xe7009d07U, 0x00430021U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[5]);

        static const uint32_t Param_pf4_func100_009[] =
        {
            BSWAP_32BIG_C(0xd2dcd677U), BSWAP_32BIG_C(0x7c09e1e1U), BSWAP_32BIG_C(0xdeab4a5dU), BSWAP_32BIG_C(
                0xee062981U),
        };
        r_rsip_func100(Param_pf4_func100_009);
        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0x09108105U, 0x00410011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[9]);

        static const uint32_t Param_pf4_func100_010[] =
        {
            BSWAP_32BIG_C(0xb6958c79U), BSWAP_32BIG_C(0x8166bee4U), BSWAP_32BIG_C(0x1c29ada2U), BSWAP_32BIG_C(
                0xc5e2eeb8U),
        };
        r_rsip_func100(Param_pf4_func100_010);
        WR1_PROG(REG_009CH, 0x81010000U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_PrivKeyIndex[0]);

        static const uint32_t Param_pf4_func100_011[] =
        {
            BSWAP_32BIG_C(0x658990c0U), BSWAP_32BIG_C(0x960a4694U), BSWAP_32BIG_C(0xbd4b07f1U), BSWAP_32BIG_C(
                0xd2c591f2U),
        };
        r_rsip_func100(Param_pf4_func100_011);
        r_rsip_func103();
        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

        r_rsip_func_sub002(0x800100e0U, 0x0000f402U);

        static const uint32_t Param_pf4_func101_009[] =
        {
            BSWAP_32BIG_C(0xf4c311a3U), BSWAP_32BIG_C(0x7f67975eU), BSWAP_32BIG_C(0x5eb3dcbbU), BSWAP_32BIG_C(
                0xc5fbda44U),
        };
        r_rsip_func101(Param_pf4_func101_009);
        r_rsip_func143();

        r_rsip_func075();

        r_rsip_func_sub002(0x800100e0U, 0x0000f402U);

        static const uint32_t Param_pf4_func101_010[] =
        {
            BSWAP_32BIG_C(0xaa44acebU), BSWAP_32BIG_C(0x1e336a48U), BSWAP_32BIG_C(0x0281a75bU), BSWAP_32BIG_C(
                0x7b2bf8ecU),
        };
        r_rsip_func101(Param_pf4_func101_010);
        r_rsip_func044();

        r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pf4_func100_012[] =
        {
            BSWAP_32BIG_C(0xb9ba30f2U), BSWAP_32BIG_C(0xd3999c4eU), BSWAP_32BIG_C(0xb9e6b152U), BSWAP_32BIG_C(
                0x0e80bef4U),
        };
        r_rsip_func100(Param_pf4_func100_012);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub004(0x00001828U, 0x00430021U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[5]);

        static const uint32_t Param_pf4_func100_013[] =
        {
            BSWAP_32BIG_C(0xf09f7f27U), BSWAP_32BIG_C(0x77eb6bedU), BSWAP_32BIG_C(0x6ee4a585U), BSWAP_32BIG_C(
                0x4e04a8ccU),
        };
        r_rsip_func100(Param_pf4_func100_013);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub004(0x0000182dU, 0x00430021U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[9]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[13]);

        static const uint32_t Param_pf4_func100_014[] =
        {
            BSWAP_32BIG_C(0x0c51302eU), BSWAP_32BIG_C(0x28fa170bU), BSWAP_32BIG_C(0x0b760704U), BSWAP_32BIG_C(
                0x28748307U),
        };
        r_rsip_func100(Param_pf4_func100_014);
        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0x09108105U, 0x00410011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[17]);

        static const uint32_t Param_pf4_func100_015[] =
        {
            BSWAP_32BIG_C(0x207e0522U), BSWAP_32BIG_C(0x4741c96fU), BSWAP_32BIG_C(0x839b6797U), BSWAP_32BIG_C(
                0x417ac9a8U),
        };
        r_rsip_func100(Param_pf4_func100_015);
        WR1_PROG(REG_009CH, 0x81010000U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_pf4_func102_002[] =
        {
            BSWAP_32BIG_C(0xb24e3550U), BSWAP_32BIG_C(0x8ce59a45U), BSWAP_32BIG_C(0x9e461e39U), BSWAP_32BIG_C(
                0x2ffc1ac4U),
        };
        r_rsip_func102(Param_pf4_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
