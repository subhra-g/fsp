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

rsip_ret_t r_rsip_pdff (const uint32_t InData_SignatureType[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Salt[],
                        const uint32_t InData_SaltLength[],
                        uint32_t       OutData_EncCertificateInfo[])
{
    r_rsip_func_sub010(0x000001c7U, 0x80020080U);
    WR1_PROG(REG_1420H, InData_SignatureType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x000000dfU);

    static const uint32_t Param_pdff_func101_001[] =
    {
        BSWAP_32BIG_C(0x48091e57U), BSWAP_32BIG_C(0xfcee2fbeU), BSWAP_32BIG_C(0x9136b80eU), BSWAP_32BIG_C(0xecceff77U),
    };
    r_rsip_func101(Param_pdff_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pdff_func100_001[] =
    {
        BSWAP_32BIG_C(0x3393cb12U), BSWAP_32BIG_C(0xfdb4c735U), BSWAP_32BIG_C(0x75ea0a35U), BSWAP_32BIG_C(0xf4ba8b1aU),
    };
    r_rsip_func100(Param_pdff_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pdff_func101_002[] =
        {
            BSWAP_32BIG_C(0x7029b128U), BSWAP_32BIG_C(0xc7d024ecU), BSWAP_32BIG_C(0x12bd214aU), BSWAP_32BIG_C(
                0x04ac9d5aU),
        };
        r_rsip_func101(Param_pdff_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x800103a0U, 0x000000dfU);

        static const uint32_t Param_pdff_func101_003[] =
        {
            BSWAP_32BIG_C(0x3a34ae5cU), BSWAP_32BIG_C(0x09260276U), BSWAP_32BIG_C(0xa2ef34a9U), BSWAP_32BIG_C(
                0xd779b984U),
        };
        r_rsip_func101(Param_pdff_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0x76bea7b0U, 0x00A60000U);
        static const uint32_t Param_pdff_func100_002[] =
        {
            BSWAP_32BIG_C(0xad806a3bU), BSWAP_32BIG_C(0x5cdbe7bcU), BSWAP_32BIG_C(0xaa2a3b53U), BSWAP_32BIG_C(
                0xf665b3adU),
        };
        r_rsip_func100(Param_pdff_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdff_func102_001[] =
            {
                BSWAP_32BIG_C(0x6539c8e6U), BSWAP_32BIG_C(0x568c99f3U), BSWAP_32BIG_C(0xd72b9450U), BSWAP_32BIG_C(
                    0x9f564166U),
            };
            r_rsip_func102(Param_pdff_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdff_func101_004[] =
            {
                BSWAP_32BIG_C(0xc2d8d45fU), BSWAP_32BIG_C(0x3b1f7c24U), BSWAP_32BIG_C(0x963492ecU), BSWAP_32BIG_C(
                    0x8de58b05U),
            };
            r_rsip_func101(Param_pdff_func101_004);
        }
    }

    r_rsip_func_sub003(0x800103a0U, 0x000000dfU);

    static const uint32_t Param_pdff_func101_005[] =
    {
        BSWAP_32BIG_C(0xab3ab7d4U), BSWAP_32BIG_C(0x781b94e9U), BSWAP_32BIG_C(0x4afcea55U), BSWAP_32BIG_C(0x1609f609U),
    };
    r_rsip_func101(Param_pdff_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xa7cd232fU, 0x00A60000U);
    static const uint32_t Param_pdff_func100_003[] =
    {
        BSWAP_32BIG_C(0x8b276b40U), BSWAP_32BIG_C(0x58fbbba4U), BSWAP_32BIG_C(0xeaf25734U), BSWAP_32BIG_C(0xf5fe96b6U),
    };
    r_rsip_func100(Param_pdff_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdff_func102_002[] =
        {
            BSWAP_32BIG_C(0xdd4ac8d9U), BSWAP_32BIG_C(0x7bae02ffU), BSWAP_32BIG_C(0x6fd89237U), BSWAP_32BIG_C(
                0x3b135667U),
        };
        r_rsip_func102(Param_pdff_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x800103a0U, 0x000000dfU);

        static const uint32_t Param_pdff_func101_006[] =
        {
            BSWAP_32BIG_C(0x28da9d6cU), BSWAP_32BIG_C(0x0c771456U), BSWAP_32BIG_C(0xd1b030b1U), BSWAP_32BIG_C(
                0x70f7eb30U),
        };
        r_rsip_func101(Param_pdff_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pdff_func102_003[] =
        {
            BSWAP_32BIG_C(0xa2eab718U), BSWAP_32BIG_C(0xb8f557f3U), BSWAP_32BIG_C(0x473fad4aU), BSWAP_32BIG_C(
                0x50f5f19aU),
        };
        r_rsip_func102(Param_pdff_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
