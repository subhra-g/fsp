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

rsip_ret_t r_rsip_pf6 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00f60001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_0014H, 0x000017c5U);
    WR1_PROG(REG_00B0H, 0x00009493U);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[4]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[8]);

    WR1_PROG(REG_00B0H, 0x0000949aU);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[12]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[16]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_Signature[20]);

    WR1_PROG(REG_0014H, 0x00000bc5U);
    WR1_PROG(REG_00B0H, 0x000094a1U);
    WAIT_STS(REG_0014H, 31, 1);
    WR12_ADDR(REG_002CH, &InData_MsgDgst[0]);

    r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
    WR1_PROG(REG_002CH, InData_KeyIndex[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f6U, 0x00000000U);

    static const uint32_t Param_pf6_func101_001[] =
    {
        BSWAP_32BIG_C(0xfd5ca943U), BSWAP_32BIG_C(0x1501ea86U), BSWAP_32BIG_C(0x79fd6af2U), BSWAP_32BIG_C(0x5a291c61U),
    };
    r_rsip_func101(Param_pf6_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func077();

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f6U, 0x00000000U);

    static const uint32_t Param_pf6_func101_002[] =
    {
        BSWAP_32BIG_C(0xf5aa0462U), BSWAP_32BIG_C(0xdeb09faaU), BSWAP_32BIG_C(0x626c9abfU), BSWAP_32BIG_C(0x86a7e8e9U),
    };
    r_rsip_func101(Param_pf6_func101_002);
    r_rsip_func044();

    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

    r_rsip_func_sub011(0x000017c1U, 0x40000500U, 0xe8008107U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[1]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[5]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[9]);

    r_rsip_func_sub009(0x0000b4adU, 0x00c10031U, 0x00001800U);

    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[13]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[17]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[21]);

    r_rsip_func_sub015(0x00c10031U, 0x00001800U);

    r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[25]);

    r_rsip_func_sub013(0x9c100005U, 0x00410011U);

    static const uint32_t Param_pf6_func100_001[] =
    {
        BSWAP_32BIG_C(0xc3604f31U), BSWAP_32BIG_C(0x8c4f9c51U), BSWAP_32BIG_C(0x439e1fecU), BSWAP_32BIG_C(0xe5d8f867U),
    };
    r_rsip_func100(Param_pf6_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf6_func102_001[] =
        {
            BSWAP_32BIG_C(0x662dae7bU), BSWAP_32BIG_C(0x6bf5e54fU), BSWAP_32BIG_C(0xaab2d638U), BSWAP_32BIG_C(
                0xe3933879U),
        };
        r_rsip_func102(Param_pf6_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f6U, 0x00000000U);

        static const uint32_t Param_pf6_func101_003[] =
        {
            BSWAP_32BIG_C(0x3d9870c7U), BSWAP_32BIG_C(0x4258b71eU), BSWAP_32BIG_C(0x9168754dU), BSWAP_32BIG_C(
                0x4a61378eU),
        };
        r_rsip_func101(Param_pf6_func101_003);
        r_rsip_func029(InData_DomainParam);

        static const uint32_t Param_pf6_func100_002[] =
        {
            BSWAP_32BIG_C(0x2fab6b59U), BSWAP_32BIG_C(0x012fd908U), BSWAP_32BIG_C(0x085d6f70U), BSWAP_32BIG_C(
                0x48c67ec7U),
        };
        r_rsip_func100(Param_pf6_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pf6_func102_002[] =
            {
                BSWAP_32BIG_C(0x373a21d6U), BSWAP_32BIG_C(0xe8b70c2cU), BSWAP_32BIG_C(0x4a075d64U), BSWAP_32BIG_C(
                    0x537f56a1U),
            };
            r_rsip_func102(Param_pf6_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf6_func102_003[] =
            {
                BSWAP_32BIG_C(0x2c2f951cU), BSWAP_32BIG_C(0x363f23e4U), BSWAP_32BIG_C(0x84580eb8U), BSWAP_32BIG_C(
                    0xa78c744fU),
            };
            r_rsip_func102(Param_pf6_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
