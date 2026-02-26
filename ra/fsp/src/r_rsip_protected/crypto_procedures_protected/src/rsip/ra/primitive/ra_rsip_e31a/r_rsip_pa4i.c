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

rsip_ret_t r_rsip_pa4i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00a40001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000007U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000a4U, 0x00000000U);

    static const uint32_t Param_pa4i_func101_001[] =
    {
        BSWAP_32BIG_C(0xf689dc77U), BSWAP_32BIG_C(0x9bd4496aU), BSWAP_32BIG_C(0x255e49b9U), BSWAP_32BIG_C(0x11e8ee2cU),
    };
    r_rsip_func101(Param_pa4i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_pa4i_func100_001[] =
    {
        BSWAP_32BIG_C(0xe33f4d70U), BSWAP_32BIG_C(0xf4cdcd36U), BSWAP_32BIG_C(0x2ab280faU), BSWAP_32BIG_C(0x3be45fdbU),
    };
    r_rsip_func100(Param_pa4i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pa4i_func102_001[] =
        {
            BSWAP_32BIG_C(0x7f177045U), BSWAP_32BIG_C(0xa76c5b9cU), BSWAP_32BIG_C(0x5c2630cbU), BSWAP_32BIG_C(
                0xfe6d441cU),
        };
        r_rsip_func102(Param_pa4i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_pa4i_func100_002[] =
        {
            BSWAP_32BIG_C(0xbf34319dU), BSWAP_32BIG_C(0x4cc95aa6U), BSWAP_32BIG_C(0x3531da6cU), BSWAP_32BIG_C(
                0xf0484378U),
        };
        r_rsip_func100(Param_pa4i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_pa4i_func101_002[] =
            {
                BSWAP_32BIG_C(0xc82f4253U), BSWAP_32BIG_C(0x95d3cd4eU), BSWAP_32BIG_C(0x2dc33eebU), BSWAP_32BIG_C(
                    0x44bb3900U),
            };
            r_rsip_func101(Param_pa4i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000a4U, 0x00000000U);

            static const uint32_t Param_pa4i_func101_003[] =
            {
                BSWAP_32BIG_C(0x22ffc139U), BSWAP_32BIG_C(0xec4ad117U), BSWAP_32BIG_C(0xa09ba276U), BSWAP_32BIG_C(
                    0x307b4fecU),
            };
            r_rsip_func101(Param_pa4i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_pa4i_func100_003[] =
            {
                BSWAP_32BIG_C(0xb795a95fU), BSWAP_32BIG_C(0xf46857c0U), BSWAP_32BIG_C(0xf1ff80f3U), BSWAP_32BIG_C(
                    0x5189afc3U),
            };
            r_rsip_func100(Param_pa4i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pa4i_func102_002[] =
                {
                    BSWAP_32BIG_C(0x27332e7dU), BSWAP_32BIG_C(0x15b908a6U), BSWAP_32BIG_C(0x8f351135U), BSWAP_32BIG_C(
                        0xca61f428U),
                };
                r_rsip_func102(Param_pa4i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                static const uint32_t Param_pa4i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x1d607feeU), BSWAP_32BIG_C(0xf95e0d6bU), BSWAP_32BIG_C(0x75e3260fU), BSWAP_32BIG_C(
                        0x21afb4f1U),
                };
                r_rsip_func101(Param_pa4i_func101_004);
            }
        }

        static const uint32_t Param_pa4i_func100_004[] =
        {
            BSWAP_32BIG_C(0x358c6d16U), BSWAP_32BIG_C(0x08893465U), BSWAP_32BIG_C(0x9061c122U), BSWAP_32BIG_C(
                0x3b91cb3eU),
        };
        r_rsip_func100(Param_pa4i_func100_004);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

        static const uint32_t Param_pa4i_func100_005[] =
        {
            BSWAP_32BIG_C(0xdd7387cbU), BSWAP_32BIG_C(0x83ec9314U), BSWAP_32BIG_C(0x0eafe9bbU), BSWAP_32BIG_C(
                0x4c4f9ea6U),
        };
        r_rsip_func100(Param_pa4i_func100_005);
        r_rsip_func_sub013(0x08000095U, 0x00430011U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa4i_func101_005[] =
        {
            BSWAP_32BIG_C(0x3754bbb3U), BSWAP_32BIG_C(0xc4ba2214U), BSWAP_32BIG_C(0xae0e67edU), BSWAP_32BIG_C(
                0x7762bd8eU),
        };
        r_rsip_func101(Param_pa4i_func101_005);

        return RSIP_RET_PASS;
    }
}
