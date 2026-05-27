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

rsip_ret_t r_rsip_pe5r (const uint32_t InData_KeyType[], const uint32_t InData_KeyIndex[],
                        const uint32_t InData_State[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00e50001U, 0x000000c7U, 0x80010020U);
    WR1_PROG(REG_002CH, InData_KeyType[0]);
    r_rsip_func_sub012(0x38000c21U, 0x00260000U);

    static const uint32_t Param_pe5r_func100_001[] =
    {
        BSWAP_32BIG_C(0xf04cda47U), BSWAP_32BIG_C(0xf17bdc5aU), BSWAP_32BIG_C(0x761b7410U), BSWAP_32BIG_C(0x96a102ceU),
    };
    r_rsip_func100(Param_pe5r_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x0000001bU);

        static const uint32_t Param_pe5r_sub100_001[] =
        {
            BSWAP_32BIG_C(0x0000e503U), BSWAP_32BIG_C(0x1401464fU), BSWAP_32BIG_C(0x167df56fU),
            BSWAP_32BIG_C(0x5e886de6U),
            BSWAP_32BIG_C(0x3ffd91f8U), BSWAP_32BIG_C(0x0000e503U), BSWAP_32BIG_C(0x2bd9e30cU),
            BSWAP_32BIG_C(0x93f28449U),
            BSWAP_32BIG_C(0xc43b0127U),
            BSWAP_32BIG_C(0xe3ecccebU), 0x00001404U,
        };
        r_rsip_func_sub100(InData_KeyIndex, Param_pe5r_sub100_001, RSIP_SEL_BIT_LENGTH_256);

        static const uint32_t Param_pe5r_func101_001[] =
        {
            BSWAP_32BIG_C(0x01730e1aU), BSWAP_32BIG_C(0x438959d5U), BSWAP_32BIG_C(0x5aac3cd9U), BSWAP_32BIG_C(
                0x2afed569U),
        };
        r_rsip_func101(Param_pe5r_func101_001);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x01b41ce9U);

        static const uint32_t Param_pe5r_sub100_002[] =
        {
            BSWAP_32BIG_C(0x0000e504U), BSWAP_32BIG_C(0xa9487e3bU), BSWAP_32BIG_C(0xd9229c77U),
            BSWAP_32BIG_C(0xe8de0f7cU),
            BSWAP_32BIG_C(0xb98b46c1U), BSWAP_32BIG_C(0x0000e504U), BSWAP_32BIG_C(0x75e84797U),
            BSWAP_32BIG_C(0x70c1979fU),
            BSWAP_32BIG_C(0xf386c5d3U),
            BSWAP_32BIG_C(0x323164acU), 0x00001404U,
        };
        r_rsip_func_sub100(InData_KeyIndex, Param_pe5r_sub100_002, RSIP_SEL_BIT_LENGTH_512);

        static const uint32_t Param_pe5r_func101_002[] =
        {
            BSWAP_32BIG_C(0x07b97985U), BSWAP_32BIG_C(0x84b0079dU), BSWAP_32BIG_C(0xc6a22b9cU), BSWAP_32BIG_C(
                0x265ef694U),
        };
        r_rsip_func101(Param_pe5r_func101_002);
    }

    static const uint32_t Param_pe5r_func100_002[] =
    {
        BSWAP_32BIG_C(0x6035972fU), BSWAP_32BIG_C(0x6b506ad2U), BSWAP_32BIG_C(0x48489250U), BSWAP_32BIG_C(0x1bc95f09U),
    };
    r_rsip_func100(Param_pe5r_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5r_func102_001[] =
        {
            BSWAP_32BIG_C(0xd5583b9fU), BSWAP_32BIG_C(0xf348650dU), BSWAP_32BIG_C(0x07562135U), BSWAP_32BIG_C(
                0xbaa436c2U),
        };
        r_rsip_func102(Param_pe5r_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_00F4H, 0x00000010U);

        WR1_PROG(REG_0014H, 0x000007c4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR8_ADDR(REG_002CH, &InData_State[0]);

        WR1_PROG(REG_00F4H, 0x00000011U);

        static const uint32_t Param_pe5r_func101_003[] =
        {
            BSWAP_32BIG_C(0x44bf4205U), BSWAP_32BIG_C(0xec2b31b4U), BSWAP_32BIG_C(0x589cf283U), BSWAP_32BIG_C(
                0xfb7396c1U),
        };
        r_rsip_func101(Param_pe5r_func101_003);

        return RSIP_RET_PASS;
    }
}
