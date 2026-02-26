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

rsip_ret_t r_rsip_p73r (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00730001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00F0H, 0x00000001U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00270000U);

    static const uint32_t Param_p73r_func100_001[] =
    {
        BSWAP_32BIG_C(0x909ac921U), BSWAP_32BIG_C(0x00d2d1beU), BSWAP_32BIG_C(0x8d6e21ceU), BSWAP_32BIG_C(0xce587e11U),
    };
    r_rsip_func100(Param_p73r_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p73r_func102_001[] =
        {
            BSWAP_32BIG_C(0x5c57a08eU), BSWAP_32BIG_C(0x38aa694bU), BSWAP_32BIG_C(0xe7fc39bdU), BSWAP_32BIG_C(
                0x88f8e66eU),
        };
        r_rsip_func102(Param_p73r_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p73r_func100_002[] =
        {
            BSWAP_32BIG_C(0x072e9c18U), BSWAP_32BIG_C(0xbf4fa3e0U), BSWAP_32BIG_C(0x83056207U), BSWAP_32BIG_C(
                0x1b9aa55bU),
        };
        r_rsip_func100(Param_p73r_func100_002);
        r_rsip_func_sub022(0x3420a800U, 0x00000007U, 0x2000b400U);
        WR1_PROG(REG_0094H, 0x00000006U);

        WR1_PROG(REG_0094H, 0x00007c00U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_00F4H, 0x00001040U);

            static const uint32_t Param_p73r_func101_001[] =
            {
                BSWAP_32BIG_C(0xd21f9e46U), BSWAP_32BIG_C(0xcd4817a6U), BSWAP_32BIG_C(0xc1b10b75U), BSWAP_32BIG_C(
                    0x99126488U),
            };
            r_rsip_func101(Param_p73r_func101_001);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_00F4H, 0x00001050U);

            static const uint32_t Param_p73r_func101_002[] =
            {
                BSWAP_32BIG_C(0x172b20f9U), BSWAP_32BIG_C(0x03e34d06U), BSWAP_32BIG_C(0x69f51978U), BSWAP_32BIG_C(
                    0xa4ccdd9eU),
            };
            r_rsip_func101(Param_p73r_func101_002);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_00F4H, 0x00001080U);

            static const uint32_t Param_p73r_func101_003[] =
            {
                BSWAP_32BIG_C(0x6b6a0864U), BSWAP_32BIG_C(0xbf88b3f1U), BSWAP_32BIG_C(0xc89126a5U), BSWAP_32BIG_C(
                    0xf1a39ff0U),
            };
            r_rsip_func101(Param_p73r_func101_003);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_00F4H, 0x00001090U);

            static const uint32_t Param_p73r_func101_004[] =
            {
                BSWAP_32BIG_C(0x44037066U), BSWAP_32BIG_C(0x75aac28bU), BSWAP_32BIG_C(0x2924e92fU), BSWAP_32BIG_C(
                    0xb462a447U),
            };
            r_rsip_func101(Param_p73r_func101_004);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_00F4H, 0x000010a0U);

            static const uint32_t Param_p73r_func101_005[] =
            {
                BSWAP_32BIG_C(0x5812bdecU), BSWAP_32BIG_C(0x874e01d2U), BSWAP_32BIG_C(0x954f5e02U), BSWAP_32BIG_C(
                    0x0f36a76fU),
            };
            r_rsip_func101(Param_p73r_func101_005);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_00F4H, 0x000010b0U);

            static const uint32_t Param_p73r_func101_006[] =
            {
                BSWAP_32BIG_C(0xb976c145U), BSWAP_32BIG_C(0x53f67fe8U), BSWAP_32BIG_C(0x05e2d1caU), BSWAP_32BIG_C(
                    0xe0c64b6dU),
            };
            r_rsip_func101(Param_p73r_func101_006);
        }

        WR1_PROG(REG_0014H, 0x00000040U);
        WR1_PROG(REG_0104H, InData_State[18]);
        WR1_PROG(REG_0014H, 0x00000040U);
        WR1_PROG(REG_0100H, InData_State[19]);

        for (iLoop = 0U; iLoop < 18U; iLoop++)
        {
            WR1_PROG(REG_0014H, 0x00000040U);
            WR1_PROG(REG_0110H, InData_State[iLoop]);
        }

        static const uint32_t Param_p73r_func101_007[] =
        {
            BSWAP_32BIG_C(0xd3ef283cU), BSWAP_32BIG_C(0xea509580U), BSWAP_32BIG_C(0xaca673d4U), BSWAP_32BIG_C(
                0x677c7c0dU),
        };
        r_rsip_func101(Param_p73r_func101_007);

        return RSIP_RET_PASS;
    }
}
