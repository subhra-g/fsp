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

rsip_ret_t r_rsip_p55 (const uint32_t InData_Cmd[], uint32_t OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00550001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func049(InData_Cmd);

    WR1_PROG(REG_0094H, 0x00003464U);

    r_rsip_func_sub007(0x3420a880U, 0x00000020U, 0x00A60000U);

    WR1_PROG(REG_0094H, 0x00000842U);

    WR1_PROG(REG_0094H, 0x0000b440U);
    r_rsip_func_sub007(0x0C0000A0U, 0x38005844U, 0x00260000U);

    static const uint32_t Param_p55_func100_001[] =
    {
        BSWAP_32BIG_C(0x9c135772U), BSWAP_32BIG_C(0xac963d85U), BSWAP_32BIG_C(0x13e5e0c0U), BSWAP_32BIG_C(0x584b50f4U),
    };
    r_rsip_func100(Param_p55_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p55_func102_001[] =
        {
            BSWAP_32BIG_C(0x3fde5415U), BSWAP_32BIG_C(0xe1579012U), BSWAP_32BIG_C(0x6a3cca88U), BSWAP_32BIG_C(
                0x65fe3540U),
        };
        r_rsip_func102(Param_p55_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p55_func100_002[] =
        {
            BSWAP_32BIG_C(0x13964a2aU), BSWAP_32BIG_C(0xc9ea30c3U), BSWAP_32BIG_C(0x4178ceccU), BSWAP_32BIG_C(
                0xc86fe4a4U),
        };
        r_rsip_func100(Param_p55_func100_002);

        r_rsip_func_sub016(0x000008a5U, 0x38008860U, 0x00000005U);
        r_rsip_func_sub016(0x1000b420U, 0x00000004U, 0x38008860U);
        r_rsip_func_sub016(0x00000007U, 0x1000b420U, 0x00000008U);

        r_rsip_func_sub016(0x38008860U, 0x0000001aU, 0x1000b420U);
        r_rsip_func_sub016(0x00000004U, 0x1000d0a0U, 0x38008860U);
        r_rsip_func_sub016(0x0000001bU, 0x1000b420U, 0x00000008U);

        r_rsip_func103();
        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        r_rsip_func_sub009(0x0001000dU, 0x000034c0U);

        r_rsip_func_sub002(0x800100e0U, 0x00000055U);

        static const uint32_t Param_p55_func101_001[] =
        {
            BSWAP_32BIG_C(0xcce658aeU), BSWAP_32BIG_C(0x39807420U), BSWAP_32BIG_C(0xea81ae4aU), BSWAP_32BIG_C(
                0x831feb04U),
        };
        r_rsip_func101(Param_p55_func101_001);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x000034c3U);

        r_rsip_func_sub002(0x800100e0U, 0x00000055U);

        static const uint32_t Param_p55_func101_002[] =
        {
            BSWAP_32BIG_C(0xb04eea46U), BSWAP_32BIG_C(0x8f632f8fU), BSWAP_32BIG_C(0x7fb17ce4U), BSWAP_32BIG_C(
                0xe648ca84U),
        };
        r_rsip_func101(Param_p55_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p55_func100_003[] =
        {
            BSWAP_32BIG_C(0x63acbe8aU), BSWAP_32BIG_C(0x1ce74e45U), BSWAP_32BIG_C(0x6b3e49cbU), BSWAP_32BIG_C(
                0x0967c305U),
        };
        r_rsip_func100(Param_p55_func100_003);
        r_rsip_func_sub005(0x000001a1U, 0x08000044U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x08000054U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        WR1_PROG(REG_009CH, 0x81010020U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_p55_func100_004[] =
            {
                BSWAP_32BIG_C(0xcda64d78U), BSWAP_32BIG_C(0xddf056c5U), BSWAP_32BIG_C(0xc93173caU), BSWAP_32BIG_C(
                    0xaec17e67U),
            };
            r_rsip_func100(Param_p55_func100_004);
            r_rsip_func103();
            static const uint32_t Param_p55_func100_005[] =
            {
                BSWAP_32BIG_C(0x01595bb8U), BSWAP_32BIG_C(0x6e3821a2U), BSWAP_32BIG_C(0x6264df51U), BSWAP_32BIG_C(
                    0x0e249e51U),
            };
            r_rsip_func100(Param_p55_func100_005);
            r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

            WR1_PROG(REG_00D4H, 0x40000000U);
            r_rsip_func_sub006(0xe7008d45U, 0x00410011U);

            WR1_PROG(REG_0008H, 0x00001012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

            WR1_PROG(REG_0094H, 0x0000a820U);
            WR1_PROG(REG_0094H, 0x00000004U);

            static const uint32_t Param_p55_func101_003[] =
            {
                BSWAP_32BIG_C(0xb27e7411U), BSWAP_32BIG_C(0xc68e8f46U), BSWAP_32BIG_C(0xe0dc37d4U), BSWAP_32BIG_C(
                    0x5d4daf4fU),
            };
            r_rsip_func101(Param_p55_func101_003);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_0094H, 0x00007c01U);
        WR1_PROG(REG_0040H, 0x00602000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub007(0x380088a0U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p55_func100_006[] =
        {
            BSWAP_32BIG_C(0x1fd842b3U), BSWAP_32BIG_C(0x2a6fc58dU), BSWAP_32BIG_C(0xf05b9b09U), BSWAP_32BIG_C(
                0x8795699eU),
        };
        r_rsip_func100(Param_p55_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p55_func100_007[] =
            {
                BSWAP_32BIG_C(0xf4554eb7U), BSWAP_32BIG_C(0xc8b1abbdU), BSWAP_32BIG_C(0x050fe163U), BSWAP_32BIG_C(
                    0xcda150e9U),
            };
            r_rsip_func100(Param_p55_func100_007);
            r_rsip_func103();
            static const uint32_t Param_p55_func100_008[] =
            {
                BSWAP_32BIG_C(0x0814b485U), BSWAP_32BIG_C(0x012b9877U), BSWAP_32BIG_C(0xa36dccebU), BSWAP_32BIG_C(
                    0xac9afa49U),
            };
            r_rsip_func100(Param_p55_func100_008);
            r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

            WR1_PROG(REG_00D4H, 0x40000000U);
            r_rsip_func_sub006(0xe7008d45U, 0x0041000dU);
            WR1_PROG(REG_0000H, 0x00010005U);
            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);
            WR1_PROG(REG_0000H, 0x00400005U);
            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);

            WR1_PROG(REG_0008H, 0x00001012U);
            WAIT_STS(REG_0008H, 30, 1);
            RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

            iLoop = iLoop + 4;

            static const uint32_t Param_p55_func101_004[] =
            {
                BSWAP_32BIG_C(0x520c4893U), BSWAP_32BIG_C(0x12898616U), BSWAP_32BIG_C(0x789aabeaU), BSWAP_32BIG_C(
                    0xa9caf0b7U),
            };
            r_rsip_func101(Param_p55_func101_004);
        }

        static const uint32_t Param_p55_func100_009[] =
        {
            BSWAP_32BIG_C(0xf4afa520U), BSWAP_32BIG_C(0x8c632b72U), BSWAP_32BIG_C(0xa995c4dfU), BSWAP_32BIG_C(
                0x5dbe661cU),
        };
        r_rsip_func100(Param_p55_func100_009);
        r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func_sub006(0x09108105U, 0x00410011U);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

        static const uint32_t Param_p55_func100_010[] =
        {
            BSWAP_32BIG_C(0x5fa4822eU), BSWAP_32BIG_C(0xa7b3d99dU), BSWAP_32BIG_C(0xdbc16406U), BSWAP_32BIG_C(
                0x3dc6f375U),
        };
        r_rsip_func100(Param_p55_func100_010);
        WR1_PROG(REG_009CH, 0x81010000U);
        WR1_PROG(REG_0008H, 0x00005006U);
        WAIT_STS(REG_0008H, 30, 1);
        RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

        static const uint32_t Param_p55_func102_002[] =
        {
            BSWAP_32BIG_C(0xcd00b494U), BSWAP_32BIG_C(0x8bc54bb0U), BSWAP_32BIG_C(0x81c1f51dU), BSWAP_32BIG_C(
                0x93a60225U),
        };
        r_rsip_func102(Param_p55_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
