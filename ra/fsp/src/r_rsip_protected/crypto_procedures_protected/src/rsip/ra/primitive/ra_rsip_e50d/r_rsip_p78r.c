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

rsip_ret_t r_rsip_p78r (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00780001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_p78r_func100_001[] =
    {
        BSWAP_32BIG_C(0xc9de5e79U), BSWAP_32BIG_C(0x94fcc9a8U), BSWAP_32BIG_C(0x6152437dU), BSWAP_32BIG_C(0x45d10fafU),
    };
    r_rsip_func100(Param_p78r_func100_001);
    WR1_PROG(REG_2400H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a800U, 0x00000004U, 0x2000b400U, 0x00000003U);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2404H, 0x00001001U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000024U);

        static const uint32_t Param_p78r_func101_001[] =
        {
            BSWAP_32BIG_C(0xa33c413dU), BSWAP_32BIG_C(0xb0dae658U), BSWAP_32BIG_C(0xdeb98f0cU), BSWAP_32BIG_C(
                0x67830508U),
        };
        r_rsip_func101(Param_p78r_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2404H, 0x00001011U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000022U);

        static const uint32_t Param_p78r_func101_002[] =
        {
            BSWAP_32BIG_C(0x7f2cf0fbU), BSWAP_32BIG_C(0xa219a453U), BSWAP_32BIG_C(0x1be3ab9fU), BSWAP_32BIG_C(
                0x43bd4b0dU),
        };
        r_rsip_func101(Param_p78r_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2404H, 0x00001021U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x0000001aU);

        static const uint32_t Param_p78r_func101_003[] =
        {
            BSWAP_32BIG_C(0xdbe2c707U), BSWAP_32BIG_C(0x9397b085U), BSWAP_32BIG_C(0x11fb3de1U), BSWAP_32BIG_C(
                0x1ab27372U),
        };
        r_rsip_func101(Param_p78r_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2404H, 0x00001031U);

        WR1_PROG(REG_1600H, 0x0000b420U);
        WR1_PROG(REG_1600H, 0x00000012U);

        static const uint32_t Param_p78r_func101_004[] =
        {
            BSWAP_32BIG_C(0x0bc4ba32U), BSWAP_32BIG_C(0xba7188caU), BSWAP_32BIG_C(0xe59ddaefU), BSWAP_32BIG_C(
                0x30e55b98U),
        };
        r_rsip_func101(Param_p78r_func101_004);
    }

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

    static const uint32_t Param_p78r_func100_002[] =
    {
        BSWAP_32BIG_C(0xbf8498aeU), BSWAP_32BIG_C(0x5add2501U), BSWAP_32BIG_C(0xf6717301U), BSWAP_32BIG_C(0x5425d5c0U),
    };
    r_rsip_func100(Param_p78r_func100_002);
    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    static const uint32_t Param_p78r_func101_005[] =
    {
        BSWAP_32BIG_C(0x6cabc4ceU), BSWAP_32BIG_C(0xaa09ecd6U), BSWAP_32BIG_C(0x38b1fdebU), BSWAP_32BIG_C(0xcfe7485aU),
    };
    r_rsip_func101(Param_p78r_func101_005);

    return RSIP_RET_PASS;
}
