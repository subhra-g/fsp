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

rsip_ret_t r_rsip_p75r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00750001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_p75r_func100_001[] =
    {
        BSWAP_32BIG_C(0x2d865bb4U), BSWAP_32BIG_C(0x73643b86U), BSWAP_32BIG_C(0x5d89599aU), BSWAP_32BIG_C(0x2e5e2b92U),
    };
    r_rsip_func100(Param_p75r_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75r_func102_001[] =
        {
            BSWAP_32BIG_C(0x7155a1a7U), BSWAP_32BIG_C(0x1ba2bb55U), BSWAP_32BIG_C(0x7b41333cU), BSWAP_32BIG_C(
                0x452ff8b9U),
        };
        r_rsip_func102(Param_p75r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p75r_func100_002[] =
        {
            BSWAP_32BIG_C(0x3ba63249U), BSWAP_32BIG_C(0xa8ac12b5U), BSWAP_32BIG_C(0xff89ab0eU), BSWAP_32BIG_C(
                0x06a90e7aU),
        };
        r_rsip_func100(Param_p75r_func100_002);
        r_rsip_func_sub024(0x3420a880U, 0x00000007U, 0x2000b480U, 0x00000006U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000001aU, 0x00001040U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            static const uint32_t Param_p75r_func101_001[] =
            {
                BSWAP_32BIG_C(0x59adde80U), BSWAP_32BIG_C(0x1b4f6096U), BSWAP_32BIG_C(0x26008318U), BSWAP_32BIG_C(
                    0xfe16bf0fU),
            };
            r_rsip_func101(Param_p75r_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000001bU, 0x00001050U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            static const uint32_t Param_p75r_func101_002[] =
            {
                BSWAP_32BIG_C(0xb78ae1d4U), BSWAP_32BIG_C(0x8752e769U), BSWAP_32BIG_C(0x1128876fU), BSWAP_32BIG_C(
                    0x2ffa3c95U),
            };
            r_rsip_func101(Param_p75r_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000002aU, 0x00001080U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75r_func101_003[] =
            {
                BSWAP_32BIG_C(0x0fe7c9c2U), BSWAP_32BIG_C(0xb360d56cU), BSWAP_32BIG_C(0xa8c5c611U), BSWAP_32BIG_C(
                    0x28683944U),
            };
            r_rsip_func101(Param_p75r_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000002bU, 0x00001090U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75r_func101_004[] =
            {
                BSWAP_32BIG_C(0xff5e9f5bU), BSWAP_32BIG_C(0x5169b76bU), BSWAP_32BIG_C(0x72c53e24U), BSWAP_32BIG_C(
                    0xeed550acU),
            };
            r_rsip_func101(Param_p75r_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x00000028U, 0x000010a0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000000cU);

            static const uint32_t Param_p75r_func101_005[] =
            {
                BSWAP_32BIG_C(0x43dc6227U), BSWAP_32BIG_C(0xe629605dU), BSWAP_32BIG_C(0xe695c664U), BSWAP_32BIG_C(
                    0x9465ae58U),
            };
            r_rsip_func101(Param_p75r_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x00000029U, 0x000010b0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75r_func101_006[] =
            {
                BSWAP_32BIG_C(0xc5361812U), BSWAP_32BIG_C(0x1d43b137U), BSWAP_32BIG_C(0xdc0bbc62U), BSWAP_32BIG_C(
                    0xc76ed1c3U),
            };
            r_rsip_func101(Param_p75r_func101_006);
        }

        WR1_PROG(REG_2008H, 0x00000003U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007502U);

        static const uint32_t Param_p75r_func101_007[] =
        {
            BSWAP_32BIG_C(0x881a15b7U), BSWAP_32BIG_C(0x04c57eddU), BSWAP_32BIG_C(0x9ca1bc1aU), BSWAP_32BIG_C(
                0xb7f036dcU),
        };
        r_rsip_func101(Param_p75r_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e5U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007502U);

        static const uint32_t Param_p75r_func101_008[] =
        {
            BSWAP_32BIG_C(0xff774896U), BSWAP_32BIG_C(0x5f32303dU), BSWAP_32BIG_C(0x6ccc1b06U), BSWAP_32BIG_C(
                0x6c1e1a70U),
        };
        r_rsip_func101(Param_p75r_func101_008);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
        {
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            r_rsip_func_sub001(0x01420011U);

            WR1_PROG(REG_1600H, 0x0000a4e0U);
            WR1_PROG(REG_1600H, 0x00000004U);

            static const uint32_t Param_p75r_func101_009[] =
            {
                BSWAP_32BIG_C(0xa39a5550U), BSWAP_32BIG_C(0xec37e9e5U), BSWAP_32BIG_C(0x17b1b88dU), BSWAP_32BIG_C(
                    0x421e19a0U),
            };
            r_rsip_func101(Param_p75r_func101_009);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x380008e3U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p75r_func100_003[] =
        {
            BSWAP_32BIG_C(0x42c7d303U), BSWAP_32BIG_C(0x269e96a5U), BSWAP_32BIG_C(0xfd7d36f3U), BSWAP_32BIG_C(
                0x71865308U),
        };
        r_rsip_func100(Param_p75r_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75r_func102_002[] =
            {
                BSWAP_32BIG_C(0xd87d9593U), BSWAP_32BIG_C(0x990073e2U), BSWAP_32BIG_C(0x77b02d52U), BSWAP_32BIG_C(
                    0xaefa97d8U),
            };
            r_rsip_func102(Param_p75r_func102_002);
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

            static const uint32_t Param_p75r_func101_010[] =
            {
                BSWAP_32BIG_C(0xf843ec47U), BSWAP_32BIG_C(0x58697af4U), BSWAP_32BIG_C(0x62f1f47cU), BSWAP_32BIG_C(
                    0xb7f44d3cU),
            };
            r_rsip_func101(Param_p75r_func101_010);

            return RSIP_RET_PASS;
        }
    }
}
