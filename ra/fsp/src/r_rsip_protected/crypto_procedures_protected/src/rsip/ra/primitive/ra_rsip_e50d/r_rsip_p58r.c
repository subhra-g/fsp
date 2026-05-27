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

rsip_ret_t r_rsip_p58r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00580001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2400H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_p58r_func100_001[] =
    {
        BSWAP_32BIG_C(0xb26fddd0U), BSWAP_32BIG_C(0xb0887826U), BSWAP_32BIG_C(0xa30ac192U), BSWAP_32BIG_C(0xdae37ab6U),
    };
    r_rsip_func100(Param_p58r_func100_001);
    r_rsip_func_sub021(0x3420a880U, 0x00000004U, 0x2000b480U, 0x00000003U);

    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002cU);

        WR1_PROG(REG_2404H, 0x00001001U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000024U);

        static const uint32_t Param_p58r_func101_001[] =
        {
            BSWAP_32BIG_C(0xe7be5e76U), BSWAP_32BIG_C(0xc4bd1713U), BSWAP_32BIG_C(0x02d82234U), BSWAP_32BIG_C(
                0x1fe3026dU),
        };
        r_rsip_func101(Param_p58r_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002dU);

        WR1_PROG(REG_2404H, 0x00001011U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000022U);

        static const uint32_t Param_p58r_func101_002[] =
        {
            BSWAP_32BIG_C(0x7eca4c1bU), BSWAP_32BIG_C(0xd0e8220aU), BSWAP_32BIG_C(0x80ebce92U), BSWAP_32BIG_C(
                0xea1912e3U),
        };
        r_rsip_func101(Param_p58r_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002eU);

        WR1_PROG(REG_2404H, 0x00001021U);

        r_rsip_func_sub021(0x0000b460U, 0x0000000cU, 0x0000b420U, 0x0000001aU);

        static const uint32_t Param_p58r_func101_003[] =
        {
            BSWAP_32BIG_C(0xdccac0e9U), BSWAP_32BIG_C(0x57929e8aU), BSWAP_32BIG_C(0x5225b10bU), BSWAP_32BIG_C(
                0x882db5e9U),
        };
        r_rsip_func101(Param_p58r_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002fU);

        WR1_PROG(REG_2404H, 0x00001031U);

        r_rsip_func_sub021(0x0000b460U, 0x00000010U, 0x0000b420U, 0x00000012U);

        static const uint32_t Param_p58r_func101_004[] =
        {
            BSWAP_32BIG_C(0x83244c01U), BSWAP_32BIG_C(0x31ba6e4dU), BSWAP_32BIG_C(0x9f707b40U), BSWAP_32BIG_C(
                0xf2790705U),
        };
        r_rsip_func101(Param_p58r_func101_004);
    }

    WR1_PROG(REG_2408H, 0x00000003U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00005802U);

    static const uint32_t Param_p58r_func101_005[] =
    {
        BSWAP_32BIG_C(0xcbfcd51cU), BSWAP_32BIG_C(0xc7889e8dU), BSWAP_32BIG_C(0x6de32157U), BSWAP_32BIG_C(0xc277abdfU),
    };
    r_rsip_func101(Param_p58r_func101_005);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub003(0x800103a0U, 0x00005802U);

    static const uint32_t Param_p58r_func101_006[] =
    {
        BSWAP_32BIG_C(0xe8b35125U), BSWAP_32BIG_C(0x1f672437U), BSWAP_32BIG_C(0x9d6dfa37U), BSWAP_32BIG_C(0x18af6411U),
    };
    r_rsip_func101(Param_p58r_func101_006);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

        r_rsip_func_sub001(0x01820011U);

        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1600H, 0x00000004U);

        static const uint32_t Param_p58r_func101_007[] =
        {
            BSWAP_32BIG_C(0x95156f2bU), BSWAP_32BIG_C(0xaa030551U), BSWAP_32BIG_C(0xec0e1243U), BSWAP_32BIG_C(
                0x60708c62U),
        };
        r_rsip_func101(Param_p58r_func101_007);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x380008e3U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p58r_func100_002[] =
    {
        BSWAP_32BIG_C(0xffbe2511U), BSWAP_32BIG_C(0xb4cb1cb4U), BSWAP_32BIG_C(0xafeaa1aaU), BSWAP_32BIG_C(0x8a1923d2U),
    };
    r_rsip_func100(Param_p58r_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p58r_func102_001[] =
        {
            BSWAP_32BIG_C(0xc29842aeU), BSWAP_32BIG_C(0x526aa878U), BSWAP_32BIG_C(0xf2fdad1cU), BSWAP_32BIG_C(
                0x147e6ea0U),
        };
        r_rsip_func102(Param_p58r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p58r_func100_003[] =
        {
            BSWAP_32BIG_C(0xc4f5e9edU), BSWAP_32BIG_C(0x0eade5ebU), BSWAP_32BIG_C(0x03d6ca4cU), BSWAP_32BIG_C(
                0x76323e9fU),
        };
        r_rsip_func100(Param_p58r_func100_003);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2414H, InData_State[50]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_PROG(REG_2410H, InData_State[51]);

        for (iLoop = 0U; iLoop < 50; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2438H, InData_State[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub016(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_p58r_func101_008[] =
        {
            BSWAP_32BIG_C(0xf73c707cU), BSWAP_32BIG_C(0x53901768U), BSWAP_32BIG_C(0x8e0f9a8eU), BSWAP_32BIG_C(
                0xc932d392U),
        };
        r_rsip_func101(Param_p58r_func101_008);

        return RSIP_RET_PASS;
    }
}
