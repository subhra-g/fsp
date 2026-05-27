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

rsip_ret_t r_rsip_pf1 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00f10001U, 0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x3420a800U, 0x00000003U, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000002U);

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

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x800100c0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_KeyIndex[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub002(0x800100e0U, 0x000000f1U);

    static const uint32_t Param_pf1_func101_001[] =
    {
        BSWAP_32BIG_C(0x723ed470U), BSWAP_32BIG_C(0x9a1f19e2U), BSWAP_32BIG_C(0xab8a6079U), BSWAP_32BIG_C(0x2c527727U),
    };
    r_rsip_func101(Param_pf1_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func075();

    r_rsip_func_sub002(0x800100e0U, 0x000000f1U);

    static const uint32_t Param_pf1_func101_002[] =
    {
        BSWAP_32BIG_C(0x144187a9U), BSWAP_32BIG_C(0xfdc0336bU), BSWAP_32BIG_C(0xba1a7686U), BSWAP_32BIG_C(0xe98024b8U),
    };
    r_rsip_func101(Param_pf1_func101_002);
    r_rsip_func044();

    r_rsip_func_sub005(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub005(0x000000a1U, 0x08000054U, 0x00000000U);

    r_rsip_func_sub008(0x00000fc1U, 0x40000300U, 0xe8008107U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[1]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[5]);

    r_rsip_func_sub004(0x0000347aU, 0x00c10021U);

    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[9]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[13]);

    WR1_PROG(REG_0000H, 0x00c10021U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[17]);

    r_rsip_func_sub006(0x9c100005U, 0x00410011U);

    static const uint32_t Param_pf1_func100_001[] =
    {
        BSWAP_32BIG_C(0x06705d4bU), BSWAP_32BIG_C(0x2febcb7bU), BSWAP_32BIG_C(0xb6966c38U), BSWAP_32BIG_C(0x18b81d18U),
    };
    r_rsip_func100(Param_pf1_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf1_func102_001[] =
        {
            BSWAP_32BIG_C(0x3179c095U), BSWAP_32BIG_C(0xc1a7a8ffU), BSWAP_32BIG_C(0xd6fb1ec3U), BSWAP_32BIG_C(
                0xccf52c3cU),
        };
        r_rsip_func102(Param_pf1_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub002(0x800100e0U, 0x000000f1U);

        static const uint32_t Param_pf1_func101_003[] =
        {
            BSWAP_32BIG_C(0x099d6605U), BSWAP_32BIG_C(0x20658a1bU), BSWAP_32BIG_C(0x6a7cec78U), BSWAP_32BIG_C(
                0x67fc2fadU),
        };
        r_rsip_func101(Param_pf1_func101_003);
        r_rsip_func073(InData_DomainParam);

        static const uint32_t Param_pf1_func100_002[] =
        {
            BSWAP_32BIG_C(0xa86dbdd3U), BSWAP_32BIG_C(0x90dccd1bU), BSWAP_32BIG_C(0xd23aaf45U), BSWAP_32BIG_C(
                0xe5c65591U),
        };
        r_rsip_func100(Param_pf1_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pf1_func102_002[] =
            {
                BSWAP_32BIG_C(0x729b0c76U), BSWAP_32BIG_C(0x3185b90fU), BSWAP_32BIG_C(0x85cd00daU), BSWAP_32BIG_C(
                    0xcd12674bU),
            };
            r_rsip_func102(Param_pf1_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf1_func102_003[] =
            {
                BSWAP_32BIG_C(0x35eb969fU), BSWAP_32BIG_C(0x1d95789bU), BSWAP_32BIG_C(0x29fee037U), BSWAP_32BIG_C(
                    0xb41a5fb1U),
            };
            r_rsip_func102(Param_pf1_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
