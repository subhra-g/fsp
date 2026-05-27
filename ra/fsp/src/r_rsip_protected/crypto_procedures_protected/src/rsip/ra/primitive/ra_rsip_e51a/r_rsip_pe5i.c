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

rsip_ret_t r_rsip_pe5i (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[])
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

    static const uint32_t Param_pe5i_func100_001[] =
    {
        BSWAP_32BIG_C(0x0cbb78cdU), BSWAP_32BIG_C(0x4aa20986U), BSWAP_32BIG_C(0x1f395d0bU), BSWAP_32BIG_C(0x9964ccc5U),
    };
    r_rsip_func100(Param_pe5i_func100_001);
    r_rsip_func_sub024(0x3420a8c0U, 0x00000003U, 0x2000b4c0U, 0x00000002U);

    r_rsip_func_sub014(0x00007c06U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00000050U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x00000008U);

        static const uint32_t Param_pe5i_func101_001[] =
        {
            BSWAP_32BIG_C(0xfe3ecd34U), BSWAP_32BIG_C(0x33737111U), BSWAP_32BIG_C(0xbd751474U), BSWAP_32BIG_C(
                0x4dea6e5dU),
        };
        r_rsip_func101(Param_pe5i_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x000000a0U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x0000000cU);

        static const uint32_t Param_pe5i_func101_002[] =
        {
            BSWAP_32BIG_C(0x96614930U), BSWAP_32BIG_C(0x0d7e985dU), BSWAP_32BIG_C(0xc165abc0U), BSWAP_32BIG_C(
                0x88546956U),
        };
        r_rsip_func101(Param_pe5i_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x000000b0U);

        WR1_PROG(REG_1600H, 0x0000b5e0U);
        WR1_PROG(REG_1600H, 0x00000010U);

        static const uint32_t Param_pe5i_func101_003[] =
        {
            BSWAP_32BIG_C(0xe4e8284dU), BSWAP_32BIG_C(0xe0eb7cf5U), BSWAP_32BIG_C(0xb2c9e2d9U), BSWAP_32BIG_C(
                0xcf184edaU),
        };
        r_rsip_func101(Param_pe5i_func101_003);
    }

    WR1_PROG(REG_2008H, 0x00000003U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    static const uint32_t Param_pe5i_func100_002[] =
    {
        BSWAP_32BIG_C(0x6c3b9d72U), BSWAP_32BIG_C(0xc33928c6U), BSWAP_32BIG_C(0xde2c9bceU), BSWAP_32BIG_C(0x04c3e575U),
    };
    r_rsip_func100(Param_pe5i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub024(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x0000001bU);

        r_rsip_func_sub024(0x0000b500U, 0x00000008U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub024(0x00000028U, 0x0000b500U, 0x0000000cU, 0x00050040U);
        r_rsip_func_sub024(0x0000b4a0U, 0x00000029U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5i_func101_004[] =
        {
            BSWAP_32BIG_C(0x91825c5aU), BSWAP_32BIG_C(0x6ce3a2b5U), BSWAP_32BIG_C(0xe4f579aaU), BSWAP_32BIG_C(
                0x1ad7037fU),
        };
        r_rsip_func101(Param_pe5i_func101_004);
    }
    else
    {
        r_rsip_func_sub024(0x300030c0U, 0x00070020U, 0x0000b4a0U, 0x01b41ce9U);

        r_rsip_func_sub024(0x0000b500U, 0x00000010U, 0x00030040U, 0x0000b4a0U);
        r_rsip_func_sub024(0x0199f119U, 0x0000b500U, 0x00000010U, 0x00050040U);
        r_rsip_func_sub024(0x0000b4a0U, 0x01b4cab0U, 0x0000b500U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00000080U);
        static const uint32_t Param_pe5i_func101_005[] =
        {
            BSWAP_32BIG_C(0x91927292U), BSWAP_32BIG_C(0x3c1a7908U), BSWAP_32BIG_C(0x33c017d8U), BSWAP_32BIG_C(
                0x263aa7a1U),
        };
        r_rsip_func101(Param_pe5i_func101_005);
    }

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e501U);

    static const uint32_t Param_pe5i_func101_006[] =
    {
        BSWAP_32BIG_C(0x7aac6cefU), BSWAP_32BIG_C(0xd2d33543U), BSWAP_32BIG_C(0x7a29cc7eU), BSWAP_32BIG_C(0x95eaea5aU),
    };
    r_rsip_func101(Param_pe5i_func101_006);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e501U);

    static const uint32_t Param_pe5i_func101_007[] =
    {
        BSWAP_32BIG_C(0x5ba5844cU), BSWAP_32BIG_C(0x721d7f04U), BSWAP_32BIG_C(0x1d57dac6U), BSWAP_32BIG_C(0x0c2df8b8U),
    };
    r_rsip_func101(Param_pe5i_func101_007);
    r_rsip_func044();

    static const uint32_t Param_pe5i_func100_003[] =
    {
        BSWAP_32BIG_C(0x710840adU), BSWAP_32BIG_C(0xeacfebffU), BSWAP_32BIG_C(0x84b86d05U), BSWAP_32BIG_C(0x2e05a482U),
    };
    r_rsip_func100(Param_pe5i_func100_003);
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
        static const uint32_t Param_pe5i_func101_008[] =
        {
            BSWAP_32BIG_C(0xe592ddabU), BSWAP_32BIG_C(0x88eb6311U), BSWAP_32BIG_C(0x5fa8d0a0U), BSWAP_32BIG_C(
                0x09fd2a62U),
        };
        r_rsip_func101(Param_pe5i_func101_008);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000909U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe5i_func100_004[] =
    {
        BSWAP_32BIG_C(0xabe6dfcdU), BSWAP_32BIG_C(0xf5ac1900U), BSWAP_32BIG_C(0x15a859dbU), BSWAP_32BIG_C(0x3186e75dU),
    };
    r_rsip_func100(Param_pe5i_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe5i_func102_001[] =
        {
            BSWAP_32BIG_C(0xe2c3950dU), BSWAP_32BIG_C(0xc8b2db48U), BSWAP_32BIG_C(0x0a9a1ba1U), BSWAP_32BIG_C(
                0x56287b76U),
        };
        r_rsip_func102(Param_pe5i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

            WR1_PROG(REG_200CH, 0x00000001U);

            WAIT_STS(REG_2030H, 8, 0);

            r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

            WR1_PROG(REG_200CH, 0x00000100U);

            static const uint32_t Param_pe5i_func101_009[] =
            {
                BSWAP_32BIG_C(0x2c7c2ac4U), BSWAP_32BIG_C(0x7f4b33dfU), BSWAP_32BIG_C(0xcb61ad34U), BSWAP_32BIG_C(
                    0xae0c057cU),
            };
            r_rsip_func101(Param_pe5i_func101_009);
        }
        else
        {
            r_rsip_func_sub036(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

            WR1_PROG(REG_200CH, 0x00000001U);

            static const uint32_t Param_pe5i_func101_010[] =
            {
                BSWAP_32BIG_C(0xc9b6e2c3U), BSWAP_32BIG_C(0x31d41c34U), BSWAP_32BIG_C(0x22f8cb2fU), BSWAP_32BIG_C(
                    0x16f0834bU),
            };
            r_rsip_func101(Param_pe5i_func101_010);
        }

        return RSIP_RET_PASS;
    }
}
