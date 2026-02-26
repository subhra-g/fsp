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

rsip_ret_t r_rsip_peei (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00ee0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00A0H, 0x00010000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3420a800U, 0x00000002U);
    WR1_PROG(REG_0094H, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000001U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_0014H, 0x00000fc5U);
    WR1_PROG(REG_00B0H, 0x00001469U);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_ADDR(REG_002CH, &InData_Signature[0]);

    WR1_PROG(REG_00B0H, 0x0000146eU);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_ADDR(REG_002CH, &InData_Signature[8]);

    WR1_PROG(REG_0014H, 0x000007c5U);
    WR1_PROG(REG_00B0H, 0x0000147eU);
    WAIT_STS(REG_0014H, 31, 1);
    WR8_ADDR(REG_002CH, &InData_MsgDgst[0]);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
    WR1_PROG(REG_002CH, InData_KeyIndex[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ee01U, 0x00000000U);

    static const uint32_t Param_peei_func101_001[] =
    {
        BSWAP_32BIG_C(0x0a7cc86dU), BSWAP_32BIG_C(0x628d7c2eU), BSWAP_32BIG_C(0xb1c2ffdbU), BSWAP_32BIG_C(0xd3f1591aU),
    };
    r_rsip_func101(Param_peei_func101_001);
    r_rsip_func143();

    r_rsip_func075();

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000ee01U, 0x00000000U);

    static const uint32_t Param_peei_func101_002[] =
    {
        BSWAP_32BIG_C(0x973f081bU), BSWAP_32BIG_C(0xf4c7b275U), BSWAP_32BIG_C(0x3c344601U), BSWAP_32BIG_C(0x85cb9767U),
    };
    r_rsip_func101(Param_peei_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

    r_rsip_func_sub011(0x00000fc1U, 0x40000300U, 0xe8008107U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[1]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[5]);

    r_rsip_func_sub009(0x0000347aU, 0x00c10021U, 0x00001800U);

    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[9]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[13]);

    r_rsip_func_sub015(0x00c10021U, 0x00001800U);

    r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[17]);

    r_rsip_func_sub013(0x9c100005U, 0x00410011U);

    static const uint32_t Param_peei_func100_001[] =
    {
        BSWAP_32BIG_C(0xce294062U), BSWAP_32BIG_C(0xd8f76878U), BSWAP_32BIG_C(0x12a7f838U), BSWAP_32BIG_C(0x975ede1dU),
    };
    r_rsip_func100(Param_peei_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_peei_func102_001[] =
        {
            BSWAP_32BIG_C(0x2dbad623U), BSWAP_32BIG_C(0x700338f5U), BSWAP_32BIG_C(0xc50446b5U), BSWAP_32BIG_C(
                0x36b70d19U),
        };
        r_rsip_func102(Param_peei_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000eeU, 0x00000000U);

        static const uint32_t Param_peei_func101_003[] =
        {
            BSWAP_32BIG_C(0x54e90452U), BSWAP_32BIG_C(0xed52ff96U), BSWAP_32BIG_C(0x52724bd9U), BSWAP_32BIG_C(
                0x3313c42aU),
        };
        r_rsip_func101(Param_peei_func101_003);
        r_rsip_func073(InData_DomainParam);

        static const uint32_t Param_peei_func100_002[] =
        {
            BSWAP_32BIG_C(0x1b892943U), BSWAP_32BIG_C(0xd659b951U), BSWAP_32BIG_C(0x593a158dU), BSWAP_32BIG_C(
                0x1fae3c4fU),
        };
        r_rsip_func100(Param_peei_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_peei_func102_002[] =
            {
                BSWAP_32BIG_C(0x82ebbf4dU), BSWAP_32BIG_C(0x21585fe2U), BSWAP_32BIG_C(0x260d0f5aU), BSWAP_32BIG_C(
                    0xc7edd4cdU),
            };
            r_rsip_func102(Param_peei_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_peei_func101_004[] =
            {
                BSWAP_32BIG_C(0x34bb20fbU), BSWAP_32BIG_C(0xa1eae23aU), BSWAP_32BIG_C(0xa315f3dfU), BSWAP_32BIG_C(
                    0x7ebc76bcU),
            };
            r_rsip_func101(Param_peei_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
