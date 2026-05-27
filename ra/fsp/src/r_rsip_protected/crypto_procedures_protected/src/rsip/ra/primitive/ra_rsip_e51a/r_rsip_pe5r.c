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

rsip_ret_t r_rsip_pe5r (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e50001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000001c7U, 0x800200a0U);
    WR1_PROG(REG_1420H, InData_KeyType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    static const uint32_t Param_pe5r_func100_001[] =
    {
        BSWAP_32BIG_C(0x0cbb78cdU), BSWAP_32BIG_C(0x4aa20986U), BSWAP_32BIG_C(0x1f395d0bU), BSWAP_32BIG_C(0x9964ccc5U),
    };
    r_rsip_func100(Param_pe5r_func100_001);
    r_rsip_func_sub024(0x3420a8c0U, 0x00000003U, 0x2000b4c0U, 0x00000002U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00001050U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x00000008U);

        static const uint32_t Param_pe5r_func101_001[] =
        {
            BSWAP_32BIG_C(0x89854a1bU), BSWAP_32BIG_C(0xd04bf489U), BSWAP_32BIG_C(0x23ccfa80U), BSWAP_32BIG_C(
                0x857432a6U),
        };
        r_rsip_func101(Param_pe5r_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x000010a0U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x0000000cU);

        static const uint32_t Param_pe5r_func101_002[] =
        {
            BSWAP_32BIG_C(0xa64a6421U), BSWAP_32BIG_C(0xa9dcbe9dU), BSWAP_32BIG_C(0xf3322753U), BSWAP_32BIG_C(
                0xd399663aU),
        };
        r_rsip_func101(Param_pe5r_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x000010b0U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x00000010U);

        static const uint32_t Param_pe5r_func101_003[] =
        {
            BSWAP_32BIG_C(0xd45f974aU), BSWAP_32BIG_C(0x66cbeca0U), BSWAP_32BIG_C(0xf75b9c3fU), BSWAP_32BIG_C(
                0x4476bb9aU),
        };
        r_rsip_func101(Param_pe5r_func101_003);
    }

    WR1_PROG(REG_2008H, 0x00000003U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    static const uint32_t Param_pe5r_func100_002[] =
    {
        BSWAP_32BIG_C(0x9c13dff9U), BSWAP_32BIG_C(0xe0b2faadU), BSWAP_32BIG_C(0x5cde3eb5U), BSWAP_32BIG_C(0xa189e097U),
    };
    r_rsip_func100(Param_pe5r_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub024(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x0000001bU);

        r_rsip_func_sub024(0x0000b500U, 0x00000008U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub024(0x00000028U, 0x0000b500U, 0x0000000cU, 0x00050040U);
        r_rsip_func_sub024(0x0000b4a0U, 0x00000029U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5r_func101_004[] =
        {
            BSWAP_32BIG_C(0x222a0b9aU), BSWAP_32BIG_C(0xe324feaaU), BSWAP_32BIG_C(0x30a2a070U), BSWAP_32BIG_C(
                0x3d362e21U),
        };
        r_rsip_func101(Param_pe5r_func101_004);
    }
    else
    {
        r_rsip_func_sub024(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x01b41ce9U);

        r_rsip_func_sub024(0x0000b500U, 0x00000010U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub024(0x0199f119U, 0x0000b500U, 0x00000010U, 0x00050040U);
        r_rsip_func_sub024(0x0000b4a0U, 0x01b4cab0U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5r_func101_005[] =
        {
            BSWAP_32BIG_C(0x5f88ea82U), BSWAP_32BIG_C(0xa3ed2f14U), BSWAP_32BIG_C(0x8255cf9bU), BSWAP_32BIG_C(
                0x4f27e946U),
        };
        r_rsip_func101(Param_pe5r_func101_005);
    }

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e502U);

    static const uint32_t Param_pe5r_func101_006[] =
    {
        BSWAP_32BIG_C(0xcec7b850U), BSWAP_32BIG_C(0x709c9182U), BSWAP_32BIG_C(0x21f1a1a8U), BSWAP_32BIG_C(0x20838db3U),
    };
    r_rsip_func101(Param_pe5r_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e502U);

    static const uint32_t Param_pe5r_func101_007[] =
    {
        BSWAP_32BIG_C(0x4389585eU), BSWAP_32BIG_C(0xbd0f1b8cU), BSWAP_32BIG_C(0x97d773c4U), BSWAP_32BIG_C(0x42246fbcU),
    };
    r_rsip_func101(Param_pe5r_func101_007);
    r_rsip_func044();

    static const uint32_t Param_pe5r_func100_003[] =
    {
        BSWAP_32BIG_C(0xa39fd439U), BSWAP_32BIG_C(0x68871382U), BSWAP_32BIG_C(0xca8af331U), BSWAP_32BIG_C(0x5d89f6b0U),
    };
    r_rsip_func100(Param_pe5r_func100_003);
    r_rsip_func_sub016(0x81010100U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_1600H, 0x00000929U);
    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x01420011U);

        WR1_PROG(REG_1600H, 0x0000a520U);
        WR1_PROG(REG_1600H, 0x00000004U);
        static const uint32_t Param_pe5r_func101_008[] =
        {
            BSWAP_32BIG_C(0x2f58d9b8U), BSWAP_32BIG_C(0xc77bcc0eU), BSWAP_32BIG_C(0xcea1b11bU), BSWAP_32BIG_C(
                0x3125e5cbU),
        };
        r_rsip_func101(Param_pe5r_func101_008);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000909U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe5r_func100_004[] =
    {
        BSWAP_32BIG_C(0x84887498U), BSWAP_32BIG_C(0x81cde991U), BSWAP_32BIG_C(0xf9e94a91U), BSWAP_32BIG_C(0x565e3767U),
    };
    r_rsip_func100(Param_pe5r_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe5r_func102_001[] =
        {
            BSWAP_32BIG_C(0x98af6c21U), BSWAP_32BIG_C(0xeef21691U), BSWAP_32BIG_C(0x5aba8ebfU), BSWAP_32BIG_C(
                0x4e04cd03U),
        };
        r_rsip_func102(Param_pe5r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub036(0x00000040U, InData_State[18], 0x00000040U, InData_State[19]);

        for (iLoop = 0U; iLoop < 18U; iLoop++)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2028H, InData_State[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_pe5r_func101_009[] =
        {
            BSWAP_32BIG_C(0x7b647f3dU), BSWAP_32BIG_C(0xb5488a44U), BSWAP_32BIG_C(0x808092f0U), BSWAP_32BIG_C(
                0x81a2ae84U),
        };
        r_rsip_func101(Param_pe5r_func101_009);

        return RSIP_RET_PASS;
    }
}
