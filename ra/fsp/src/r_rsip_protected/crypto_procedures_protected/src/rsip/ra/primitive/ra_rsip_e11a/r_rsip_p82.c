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

rsip_ret_t r_rsip_p82 (void)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00820001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub005(0x000000a1U, 0x0b0700c4U, 0x013e68caU);

    r_rsip_func_sub005(0x000000a1U, 0x08000074U, 0x00000000U);

    r_rsip_func_sub016(0x3000a820U, 0x00000003U, 0x00010020U);
    WR1_PROG(REG_0094H, 0x00000821U);
    WR1_PROG(REG_0094H, 0x00000080U);

    WAIT_STS(REG_00E8H, 0, 0);

    static const uint32_t Param_p82_func100_001[] =
    {
        BSWAP_32BIG_C(0x869b3c42U), BSWAP_32BIG_C(0x51263821U), BSWAP_32BIG_C(0x821ebba4U), BSWAP_32BIG_C(0xed64efedU),
    };
    r_rsip_func100(Param_p82_func100_001);
    WR1_PROG(REG_0094H, 0x00007c01U);
    WR1_PROG(REG_0040H, 0x00600000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (RD1_MASK(REG_0044H, 0x0000ffffU) == 0x00000000U)
    {
        WAIT_STS(REG_00E8H, 0, 0);
        WR1_PROG(REG_00E4H, 0x00200003U);

        static const uint32_t Param_p82_func101_001[] =
        {
            BSWAP_32BIG_C(0x02ba031eU), BSWAP_32BIG_C(0x37813b54U), BSWAP_32BIG_C(0xc118d76bU), BSWAP_32BIG_C(
                0xfe686544U),
        };
        r_rsip_func101(Param_p82_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0x0000ffffU) == 0x00000001U)
    {
        WAIT_STS(REG_00E8H, 0, 0);
        WR1_PROG(REG_00E4H, 0x00200001U);

        static const uint32_t Param_p82_func101_002[] =
        {
            BSWAP_32BIG_C(0x9a273f1dU), BSWAP_32BIG_C(0xf5123ebdU), BSWAP_32BIG_C(0xc736eccdU), BSWAP_32BIG_C(
                0x018c4880U),
        };
        r_rsip_func101(Param_p82_func101_002);
    }
    else if (RD1_MASK(REG_0044H, 0x0000ffffU) == 0x00000002U)
    {
        WAIT_STS(REG_00E8H, 0, 0);
        WR1_PROG(REG_00E4H, 0x00200002U);

        static const uint32_t Param_p82_func101_003[] =
        {
            BSWAP_32BIG_C(0x17dd015cU), BSWAP_32BIG_C(0xee695ed1U), BSWAP_32BIG_C(0x483e796fU), BSWAP_32BIG_C(
                0xa36cf3a5U),
        };
        r_rsip_func101(Param_p82_func101_003);
    }

    WR1_PROG(REG_00D0H, 0x08000044U);
    r_rsip_func_sub003(0x81010020U, 0x00490005U);

    WR1_PROG(REG_0094H, 0x00000800U);
    r_rsip_func_sub003(0x80880000U, 0x03400021U);

    r_rsip_func_sub016(0x000008e7U, 0x0000b480U, 0xffffffffU);

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x00000001U);

    WR1_PROG(REG_00D0H, 0x0e340406U);

    for (iLoop = 0U; iLoop < 32U; iLoop++)
    {
        r_rsip_func_sub003(0x80010000U, 0x03440005U);

        r_rsip_func_sub003(0x81010000U, 0x00490005U);

        WR1_PROG(REG_0094H, 0x00003420U);

        for (jLoop = 0U; jLoop < 8U; jLoop++)
        {
            r_rsip_func_sub016(0x00003441U, 0x00008c40U, 0x0000000fU);

            r_rsip_func_sub016(0x00016c42U, 0x01003862U, 0x00002c60U);

            WR1_PROG(REG_0094H, 0x01003c62U);

            WR1_PROG(REG_0094H, 0x00046821U);
        }

        r_rsip_func_sub016(0x00003420U, 0x00003441U, 0x00008c40U);
        r_rsip_func_sub016(0x80000000U, 0x38000882U, 0x00030020U);

        r_rsip_func_sub016(0x00002ca0U, 0x342028c5U, 0x100034c5U);

        r_rsip_func_sub016(0x00000060U, 0x0000b4a0U, 0x00000001U);

        WR1_PROG(REG_0094H, 0x00000080U);

        for (jLoop = 0U; jLoop < 31; jLoop++)
        {
            r_rsip_func_sub016(0x00016c21U, 0x00003481U, 0x00008c80U);
            r_rsip_func_sub016(0x80000000U, 0x38000882U, 0x00030020U);

            r_rsip_func_sub016(0x00002ca0U, 0x342028c5U, 0x100034c5U);

            r_rsip_func_sub016(0x00000060U, 0x00003444U, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000001U);

            WR1_PROG(REG_0094H, 0x00000080U);
        }

        WR1_PROG(REG_0094H, 0x00003420U);

        for (jLoop = 0U; jLoop < 32U; jLoop++)
        {
            r_rsip_func_sub016(0x38008c20U, 0x00000001U, 0x00020020U);

            r_rsip_func_sub016(0x00002ce0U, 0x00000060U, 0x0000a4e0U);
            r_rsip_func_sub016(0x00010000U, 0x00000080U, 0x00016821U);
        }
    }

    WR1_PROG(REG_0040H, 0x00001200U);
    WAIT_STS(REG_00C8H, 6, 0);
    WR1_PROG(REG_00D0H, 0x00000000U);
    WR1_PROG(REG_0040H, 0x00000400U);

    r_rsip_func_sub016(0x00000800U, 0x0000b420U, 0x00000033U);

    r_rsip_func_sub016(0x342028c1U, 0x2000d011U, 0x0000b4a0U);
    r_rsip_func_sub016(0x00000348U, 0x0000b4c0U, 0x000000b7U);

    r_rsip_func_sub016(0x00003467U, 0x00008c60U, 0x0000ffffU);

    r_rsip_func_sub016(0x34202865U, 0x2000d012U, 0x342028c3U);
    r_rsip_func_sub016(0x2000d012U, 0x001068e7U, 0x342028e5U);
    r_rsip_func_sub016(0x2000d013U, 0x342028c7U, 0x2000d013U);

    WR1_PROG(REG_0094H, 0x00002467U);

    static const uint32_t Param_p82_func100_002[] =
    {
        BSWAP_32BIG_C(0xe51d9bd1U), BSWAP_32BIG_C(0x08064450U), BSWAP_32BIG_C(0x3c90aa9cU), BSWAP_32BIG_C(0x56592491U),
    };
    r_rsip_func100(Param_p82_func100_002);
    r_rsip_func_sub007(0x38008860U, 0x00000400U, 0x00260000U);

    WR1_PROG(REG_0040H, 0x00402000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0008H, 0x00020000U);

    r_rsip_func_sub016(0x0000b420U, 0x0000005AU, 0x00000842U);

    r_rsip_func_sub016(0x00000863U, 0x00000884U, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000002U);

    for (iLoop = 0U; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub016(0x010038c4U, 0x34202826U, 0x10005002U);

        r_rsip_func_sub016(0x00002466U, 0x00002c40U, 0x00002485U);
    }

    static const uint32_t Param_p82_func100_003[] =
    {
        BSWAP_32BIG_C(0x8493fd57U), BSWAP_32BIG_C(0x807be07eU), BSWAP_32BIG_C(0x9693dc53U), BSWAP_32BIG_C(0xf141011eU),
    };
    r_rsip_func100(Param_p82_func100_003);
    r_rsip_func_sub007(0x38008860U, 0x00000100U, 0x00260000U);

    WR1_PROG(REG_0040H, 0x00402000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0008H, 0x00020000U);

    r_rsip_func_sub005(0x000000a1U, 0x0c000104U, 0x00000000U);
    r_rsip_func_sub003(0x80010020U, 0x03410005U);
    WR1_PROG(REG_0000H, 0x0001000dU);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func_sub007(0x00002c20U, 0x38000c00U, 0x00A60000U);

    static const uint32_t Param_p82_func100_004[] =
    {
        BSWAP_32BIG_C(0x3d511ae0U), BSWAP_32BIG_C(0x00f2c4b5U), BSWAP_32BIG_C(0x0d73b1d9U), BSWAP_32BIG_C(0x71ad1793U),
    };
    r_rsip_func100(Param_p82_func100_004);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p82_func102_001[] =
        {
            BSWAP_32BIG_C(0x422babd7U), BSWAP_32BIG_C(0xc3833acfU), BSWAP_32BIG_C(0x0e409217U), BSWAP_32BIG_C(
                0xfbb526d2U),
        };
        r_rsip_func102(Param_p82_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_RETRY;
    }
    else
    {
        static const uint32_t Param_p82_func100_005[] =
        {
            BSWAP_32BIG_C(0x91b39c03U), BSWAP_32BIG_C(0x1a733febU), BSWAP_32BIG_C(0x96bf867bU), BSWAP_32BIG_C(
                0x6e999f41U),
        };
        r_rsip_func100(Param_p82_func100_005);

        r_rsip_func_sub005(0x000000a1U, 0x0c300104U, 0x00000000U);
        r_rsip_func_sub003(0x80040000U, 0x03410011U);

        WR1_PROG(REG_00D4H, 0x00000600U);
        WR1_PROG(REG_00D0H, 0x0e349407U);
        WAIT_STS(REG_00E8H, 0, 0);
        WR1_PROG(REG_00E4H, 0x00200003U);
        WR1_PROG(REG_0000H, 0x00440071U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);
        r_rsip_func_sub006(0x0e340505U, 0x00440011U);

        WAIT_STS(REG_00E8H, 3, 0);
        WR1_PROG(REG_00E0H, 0x00000000U);
        r_rsip_func_sub003(0x80040080U, 0x03410011U);

        r_rsip_func_sub005(0x000000a1U, 0x080000b4U, 0x00000000U);

        static const uint32_t Param_p82_func100_006[] =
        {
            BSWAP_32BIG_C(0x115bccc8U), BSWAP_32BIG_C(0x8dc77d91U), BSWAP_32BIG_C(0x1ea9bdffU), BSWAP_32BIG_C(
                0x4d64f882U),
        };
        r_rsip_func100(Param_p82_func100_006);
        WR1_PROG(REG_0014H, 0x000003a1U);
        WR1_PROG(REG_00D0H, 0x08000075U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_PROG(REG_002CH, bswap_32big(0x00000000U), bswap_32big(0x00000000U), bswap_32big(0x00000000U),
                 bswap_32big(0x00000001U));

        WR1_PROG(REG_00D4H, 0x00000100U);
        WR1_PROG(REG_00D0H, 0x07338d07U);
        r_rsip_func_sub003(0x81080000U, 0x00490021U);

        r_rsip_func_sub006(0x080000b5U, 0x00410011U);

        static const uint32_t Param_p82_func100_007[] =
        {
            BSWAP_32BIG_C(0x1b4918e3U), BSWAP_32BIG_C(0xd02a381bU), BSWAP_32BIG_C(0xbdbda91bU), BSWAP_32BIG_C(
                0xe029dcadU),
        };
        r_rsip_func100(Param_p82_func100_007);
        r_rsip_func_sub006(0x08000075U, 0x00410011U);

        r_rsip_func103();
        static const uint32_t Param_p82_func100_008[] =
        {
            BSWAP_32BIG_C(0x17b89998U), BSWAP_32BIG_C(0x555ab9c3U), BSWAP_32BIG_C(0x7dd3d4fcU), BSWAP_32BIG_C(
                0xbd10c10bU),
        };
        r_rsip_func100(Param_p82_func100_008);
        r_rsip_func_sub005(0x000000a1U, 0x0c2000d4U, 0x00000000U);

        static const uint32_t Param_p82_func100_009[] =
        {
            BSWAP_32BIG_C(0x8cc5e8a1U), BSWAP_32BIG_C(0xf5a4c4b6U), BSWAP_32BIG_C(0x09b81925U), BSWAP_32BIG_C(
                0x98e790edU),
        };
        r_rsip_func100(Param_p82_func100_009);
        r_rsip_func103();
        r_rsip_func_sub005(0x000000a1U, 0x0c200104U, 0x00000000U);

        WR1_PROG(REG_00A0H, 0x00030000U);
        WR1_PROG(REG_0004H, 0x20000000U);
        r_rsip_func_sub004(0x00000401U, 0x00c10009U);
        WR1_PROG(REG_0000H, 0x00010009U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_0004H, 0x00000000U);
        WR1_PROG(REG_00A0H, 0x00030000U);
        r_rsip_func_sub004(0x000074c0U, 0x00c00601U);

        WR1_PROG(REG_0070H, 0x00008002U);
        WR1_PROG(REG_0078H, 0x00000d01U);

        WR1_PROG(REG_0070H, 0x00008001U);

        WR1_PROG(REG_0078H, 0x00000214U);

        static const uint32_t Param_p82_func102_002[] =
        {
            BSWAP_32BIG_C(0x84053bdbU), BSWAP_32BIG_C(0xbbe3627dU), BSWAP_32BIG_C(0xa7926190U), BSWAP_32BIG_C(
                0x8fbd6cbdU),
        };
        r_rsip_func102(Param_p82_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
