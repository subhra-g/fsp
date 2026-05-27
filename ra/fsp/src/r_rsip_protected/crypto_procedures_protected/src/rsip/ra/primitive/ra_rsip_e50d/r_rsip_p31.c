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

rsip_ret_t r_rsip_p31 (const uint32_t InData_HashType[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       uint32_t       OutData_MsgDigest[],
                       uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    WR1_PROG(REG_1B00H, 0x00310001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    static const uint32_t Param_p31_func100_001[] =
    {
        BSWAP_32BIG_C(0x62385557U), BSWAP_32BIG_C(0x7a5628aeU), BSWAP_32BIG_C(0x9a99514fU), BSWAP_32BIG_C(0xdda38601U),
    };
    r_rsip_func100(Param_p31_func100_001);
    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a800U, 0x00000007U, 0x2000b400U, 0x00000006U);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_2004H, 0x00000000U);

        static const uint32_t Param_p31_func101_001[] =
        {
            BSWAP_32BIG_C(0x22109c28U), BSWAP_32BIG_C(0xba4ec560U), BSWAP_32BIG_C(0x3e908923U), BSWAP_32BIG_C(
                0xba558af6U),
        };
        r_rsip_func101(Param_p31_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_2004H, 0x00000040U);

        static const uint32_t Param_p31_func101_002[] =
        {
            BSWAP_32BIG_C(0x503d0fa1U), BSWAP_32BIG_C(0x25eec85eU), BSWAP_32BIG_C(0x24ca0eb6U), BSWAP_32BIG_C(
                0xff93da2bU),
        };
        r_rsip_func101(Param_p31_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_2004H, 0x00000050U);

        static const uint32_t Param_p31_func101_003[] =
        {
            BSWAP_32BIG_C(0xed233fc0U), BSWAP_32BIG_C(0x04ac4f07U), BSWAP_32BIG_C(0xaf05aa05U), BSWAP_32BIG_C(
                0x11f1cd93U),
        };
        r_rsip_func101(Param_p31_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_2004H, 0x00000080U);

        static const uint32_t Param_p31_func101_004[] =
        {
            BSWAP_32BIG_C(0x4e55f287U), BSWAP_32BIG_C(0x7706d006U), BSWAP_32BIG_C(0x9fe1d6d2U), BSWAP_32BIG_C(
                0x52d55e94U),
        };
        r_rsip_func101(Param_p31_func101_004);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
    {
        WR1_PROG(REG_2004H, 0x00000090U);

        static const uint32_t Param_p31_func101_005[] =
        {
            BSWAP_32BIG_C(0xdd6fcefbU), BSWAP_32BIG_C(0x37de5497U), BSWAP_32BIG_C(0xcb784168U), BSWAP_32BIG_C(
                0xc229c60eU),
        };
        r_rsip_func101(Param_p31_func101_005);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        WR1_PROG(REG_2004H, 0x000000a0U);

        static const uint32_t Param_p31_func101_006[] =
        {
            BSWAP_32BIG_C(0xa38edc66U), BSWAP_32BIG_C(0x349759a9U), BSWAP_32BIG_C(0x0c42227eU), BSWAP_32BIG_C(
                0x1308c0dfU),
        };
        r_rsip_func101(Param_p31_func101_006);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        WR1_PROG(REG_2004H, 0x000000b0U);

        static const uint32_t Param_p31_func101_007[] =
        {
            BSWAP_32BIG_C(0xfa515800U), BSWAP_32BIG_C(0x88647384U), BSWAP_32BIG_C(0xedd52300U), BSWAP_32BIG_C(
                0xa8324a51U),
        };
        r_rsip_func101(Param_p31_func101_007);
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);

        static const uint32_t Param_p31_func101_008[] =
        {
            BSWAP_32BIG_C(0x3ec2055bU), BSWAP_32BIG_C(0x723c11deU), BSWAP_32BIG_C(0xfe0ad62fU), BSWAP_32BIG_C(
                0x8aa8325eU),
        };
        r_rsip_func101(Param_p31_func101_008);
    }
    else
    {
        r_rsip_func_sub033(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

        static const uint32_t Param_p31_func101_009[] =
        {
            BSWAP_32BIG_C(0x619997b2U), BSWAP_32BIG_C(0x57979dc8U), BSWAP_32BIG_C(0xfeec98aeU), BSWAP_32BIG_C(
                0x7d85637cU),
        };
        r_rsip_func101(Param_p31_func101_009);
    }

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);

        iLoop = iLoop + 16U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);

    WAIT_STS(REG_2030H, 4, 1);

    static const uint32_t Param_p31_func100_002[] =
    {
        BSWAP_32BIG_C(0x11df1a6fU), BSWAP_32BIG_C(0x4c46acd1U), BSWAP_32BIG_C(0xafc5fc80U), BSWAP_32BIG_C(0x180ad28dU),
    };
    r_rsip_func100(Param_p31_func100_002);
    r_rsip_func_sub021(0x38008800U, 0x00000003U, 0x1000b400U, 0x00000001U);

    r_rsip_func_sub021(0x38008800U, 0x00000004U, 0x1000b400U, 0x00000002U);

    r_rsip_func_sub014(0x00007c00U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        static const uint32_t Param_p31_func100_003[] =
        {
            BSWAP_32BIG_C(0x6904b628U), BSWAP_32BIG_C(0x35695477U), BSWAP_32BIG_C(0xf951a736U), BSWAP_32BIG_C(
                0x8337e951U),
        };
        r_rsip_func100(Param_p31_func100_003);
        WR1_PROG(REG_1408H, 0x00004016U);
        for (iLoop = 0U; iLoop < 5U; iLoop++)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_MsgDigest[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p31_func102_001[] =
        {
            BSWAP_32BIG_C(0x31ffd17cU), BSWAP_32BIG_C(0xa28ec340U), BSWAP_32BIG_C(0x1d00b5bbU), BSWAP_32BIG_C(
                0x82c82642U),
        };
        r_rsip_func102(Param_p31_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p31_func100_004[] =
        {
            BSWAP_32BIG_C(0xc5895cf7U), BSWAP_32BIG_C(0x8acc4e2bU), BSWAP_32BIG_C(0x3d0a0b09U), BSWAP_32BIG_C(
                0x1a62561bU),
        };
        r_rsip_func100(Param_p31_func100_004);
        WR1_PROG(REG_1408H, 0x0000401eU);
        for (iLoop = 0U; iLoop < 7U; iLoop++)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_MsgDigest[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p31_func102_002[] =
        {
            BSWAP_32BIG_C(0xd82a2cc0U), BSWAP_32BIG_C(0xed085186U), BSWAP_32BIG_C(0xd7832099U), BSWAP_32BIG_C(
                0x6db679cdU),
        };
        r_rsip_func102(Param_p31_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p31_func100_005[] =
        {
            BSWAP_32BIG_C(0x5a0e307dU), BSWAP_32BIG_C(0xbf037881U), BSWAP_32BIG_C(0xe53a0ed6U), BSWAP_32BIG_C(
                0x981ed136U),
        };
        r_rsip_func100(Param_p31_func100_005);
        WR1_PROG(REG_1408H, 0x00004022U);
        for (iLoop = 0U; iLoop < 8U; iLoop++)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_MsgDigest[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p31_func102_003[] =
        {
            BSWAP_32BIG_C(0xa836b017U), BSWAP_32BIG_C(0x4bd4cd31U), BSWAP_32BIG_C(0xfe9e745dU), BSWAP_32BIG_C(
                0xd3f256f2U),
        };
        r_rsip_func102(Param_p31_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
    {
        static const uint32_t Param_p31_func100_006[] =
        {
            BSWAP_32BIG_C(0x8e5b2e04U), BSWAP_32BIG_C(0x8ee752c5U), BSWAP_32BIG_C(0x57ca9f51U), BSWAP_32BIG_C(
                0x44a7024dU),
        };
        r_rsip_func100(Param_p31_func100_006);
        WR1_PROG(REG_1408H, 0x00004032U);
        for (iLoop = 0U; iLoop < 12U; iLoop++)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_MsgDigest[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p31_func102_004[] =
        {
            BSWAP_32BIG_C(0x00266d6eU), BSWAP_32BIG_C(0x072e737aU), BSWAP_32BIG_C(0xacfb1600U), BSWAP_32BIG_C(
                0x052ca8e4U),
        };
        r_rsip_func102(Param_p31_func102_004);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
    {
        static const uint32_t Param_p31_func100_007[] =
        {
            BSWAP_32BIG_C(0xa012e3ecU), BSWAP_32BIG_C(0x015b0f14U), BSWAP_32BIG_C(0xe15eb65fU), BSWAP_32BIG_C(
                0xe65ff9f0U),
        };
        r_rsip_func100(Param_p31_func100_007);
        WR1_PROG(REG_1408H, 0x00004042U);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &OutData_MsgDigest[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p31_func102_005[] =
        {
            BSWAP_32BIG_C(0x0d4bc92fU), BSWAP_32BIG_C(0x8be7f79cU), BSWAP_32BIG_C(0x9a678cfbU), BSWAP_32BIG_C(
                0x9ac5dd79U),
        };
        r_rsip_func102(Param_p31_func102_005);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);
    }

    return RSIP_RET_PASS;
}
