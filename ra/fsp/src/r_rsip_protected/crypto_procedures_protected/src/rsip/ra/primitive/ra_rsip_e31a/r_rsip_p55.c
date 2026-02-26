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

    r_rsip_func_sub010(0x3420a880U, 0x00000040U, 0x00A70000U);

    r_rsip_func_sub022(0x00000842U, 0x3020a880U, 0x00000020U);
    r_rsip_func_sub022(0x00070020U, 0x0000b440U, 0x080000A0U);
    r_rsip_func_sub022(0x00000080U, 0x3020a880U, 0x00000040U);
    r_rsip_func_sub022(0x00070020U, 0x3020a880U, 0x00000020U);
    r_rsip_func_sub022(0x00060020U, 0x0000b440U, 0x00000F00U);
    r_rsip_func_sub022(0x00000080U, 0x00000080U, 0x00008c80U);
    r_rsip_func_sub010(0x0000001fU, 0x38005844U, 0x00270000U);

    static const uint32_t Param_p55_func100_001[] =
    {
        BSWAP_32BIG_C(0xf50dffd3U), BSWAP_32BIG_C(0x208f8053U), BSWAP_32BIG_C(0x7023ffbbU), BSWAP_32BIG_C(0x751cc77aU),
    };
    r_rsip_func100(Param_p55_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p55_func102_001[] =
        {
            BSWAP_32BIG_C(0x141586d4U), BSWAP_32BIG_C(0xf6baa90fU), BSWAP_32BIG_C(0x421cc7a4U), BSWAP_32BIG_C(
                0x0b7a4adeU),
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
            BSWAP_32BIG_C(0x9ab205fbU), BSWAP_32BIG_C(0xaba6ef50U), BSWAP_32BIG_C(0x1d2d384cU), BSWAP_32BIG_C(
                0x37ce48efU),
        };
        r_rsip_func100(Param_p55_func100_002);

        r_rsip_func_sub022(0x38008860U, 0x00000005U, 0x1000b420U);
        r_rsip_func_sub022(0x00000004U, 0x38008860U, 0x00000007U);
        r_rsip_func_sub022(0x1000b420U, 0x00000008U, 0x38008860U);
        r_rsip_func_sub022(0x0000001bU, 0x1000b420U, 0x00000008U);

        r_rsip_func_sub022(0x38008860U, 0x00000028U, 0x1000b420U);
        r_rsip_func_sub022(0x0000000cU, 0x38008860U, 0x00000029U);
        r_rsip_func_sub022(0x1000b420U, 0x00000010U, 0x38008860U);
        r_rsip_func_sub022(0x0000002aU, 0x1000b420U, 0x00000010U);

        r_rsip_func_sub022(0x38008860U, 0x0000002bU, 0x1000b420U);
        WR1_PROG(REG_0094H, 0x00000010U);

        r_rsip_func103();
        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000055U, 0x00000000U);

        static const uint32_t Param_p55_func101_001[] =
        {
            BSWAP_32BIG_C(0xfeef56e1U), BSWAP_32BIG_C(0xfd2c8278U), BSWAP_32BIG_C(0xd1cb0351U), BSWAP_32BIG_C(
                0xa8b51ca6U),
        };
        r_rsip_func101(Param_p55_func101_001);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x000034c3U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000055U, 0x00000000U);

        static const uint32_t Param_p55_func101_002[] =
        {
            BSWAP_32BIG_C(0xecd822c5U), BSWAP_32BIG_C(0x7d82d5a5U), BSWAP_32BIG_C(0xee3f7c23U), BSWAP_32BIG_C(
                0x13c36798U),
        };
        r_rsip_func101(Param_p55_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p55_func100_003[] =
        {
            BSWAP_32BIG_C(0xb166a527U), BSWAP_32BIG_C(0xaaea16d4U), BSWAP_32BIG_C(0xbe2ad30dU), BSWAP_32BIG_C(
                0x2b2906d8U),
        };
        r_rsip_func100(Param_p55_func100_003);
        r_rsip_func_sub008(0x000001a1U, 0x08000044U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x08000054U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        r_rsip_func_sub017(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_002CH, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_p55_func100_004[] =
            {
                BSWAP_32BIG_C(0x7aaa2f11U), BSWAP_32BIG_C(0xb0d4b830U), BSWAP_32BIG_C(0x0090b6b6U), BSWAP_32BIG_C(
                    0x0e3f9819U),
            };
            r_rsip_func100(Param_p55_func100_004);
            r_rsip_func103();
            static const uint32_t Param_p55_func100_005[] =
            {
                BSWAP_32BIG_C(0x6f582d86U), BSWAP_32BIG_C(0x0e9f313cU), BSWAP_32BIG_C(0x3f080277U), BSWAP_32BIG_C(
                    0xdc8a5d80U),
            };
            r_rsip_func100(Param_p55_func100_005);
            r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

            r_rsip_func_sub004(0x40000000U, 0xe7008d45U, 0x00410011U, 0x00001012U);
            RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

            WR1_PROG(REG_0094H, 0x0000a820U);
            WR1_PROG(REG_0094H, 0x00000004U);

            static const uint32_t Param_p55_func101_003[] =
            {
                BSWAP_32BIG_C(0xca2c396eU), BSWAP_32BIG_C(0x0789afbaU), BSWAP_32BIG_C(0x67fa33bdU), BSWAP_32BIG_C(
                    0xebb67988U),
            };
            r_rsip_func101(Param_p55_func101_003);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_0094H, 0x00007c01U);
        WR1_PROG(REG_0040H, 0x00602000U);

        static const uint32_t Param_p55_func100_006[] =
        {
            BSWAP_32BIG_C(0x64692c60U), BSWAP_32BIG_C(0x4f6425fcU), BSWAP_32BIG_C(0x9210fa13U), BSWAP_32BIG_C(
                0x9d0d2cbdU),
        };
        r_rsip_func100(Param_p55_func100_006);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_KeyIndex[1 + iLoop]);

        static const uint32_t Param_p55_func100_007[] =
        {
            BSWAP_32BIG_C(0xe7fcd84cU), BSWAP_32BIG_C(0x221b3161U), BSWAP_32BIG_C(0x285709e7U), BSWAP_32BIG_C(
                0x49689d31U),
        };
        r_rsip_func100(Param_p55_func100_007);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

        static const uint32_t Param_p55_func102_002[] =
        {
            BSWAP_32BIG_C(0xec877988U), BSWAP_32BIG_C(0x3962c42dU), BSWAP_32BIG_C(0x588edd5eU), BSWAP_32BIG_C(
                0xb0981464U),
        };
        r_rsip_func102(Param_p55_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
