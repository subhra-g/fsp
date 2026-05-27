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

rsip_ret_t r_rsip_pedf (const uint32_t InData_SignatureType[],
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

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000edU);

    static const uint32_t Param_pedf_func101_001[] =
    {
        BSWAP_32BIG_C(0x119a90ecU), BSWAP_32BIG_C(0xf48f43d3U), BSWAP_32BIG_C(0x4871d32aU), BSWAP_32BIG_C(0x06dd0ad5U),
    };
    r_rsip_func101(Param_pedf_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pedf_func100_001[] =
    {
        BSWAP_32BIG_C(0xf476ba07U), BSWAP_32BIG_C(0xb79247e3U), BSWAP_32BIG_C(0xb0700e22U), BSWAP_32BIG_C(0x9c73f442U),
    };
    r_rsip_func100(Param_pedf_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pedf_func101_002[] =
        {
            BSWAP_32BIG_C(0x9c2078feU), BSWAP_32BIG_C(0x36121301U), BSWAP_32BIG_C(0xa7f98603U), BSWAP_32BIG_C(
                0xa74187a3U),
        };
        r_rsip_func101(Param_pedf_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000edU);

        static const uint32_t Param_pedf_func101_003[] =
        {
            BSWAP_32BIG_C(0x7b499d4eU), BSWAP_32BIG_C(0xe87e721dU), BSWAP_32BIG_C(0x4e9d922eU), BSWAP_32BIG_C(
                0x84088891U),
        };
        r_rsip_func101(Param_pedf_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0x76bea7b0U, 0x00A60000U);
        static const uint32_t Param_pedf_func100_002[] =
        {
            BSWAP_32BIG_C(0x21d29c39U), BSWAP_32BIG_C(0xbdddcf99U), BSWAP_32BIG_C(0x9ff56c68U), BSWAP_32BIG_C(
                0x01fe4173U),
        };
        r_rsip_func100(Param_pedf_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pedf_func102_001[] =
            {
                BSWAP_32BIG_C(0xdad8131aU), BSWAP_32BIG_C(0xd1de2085U), BSWAP_32BIG_C(0xe063d185U), BSWAP_32BIG_C(
                    0xec438aceU),
            };
            r_rsip_func102(Param_pedf_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pedf_func101_004[] =
            {
                BSWAP_32BIG_C(0x6ea209beU), BSWAP_32BIG_C(0x15d5fa98U), BSWAP_32BIG_C(0xc9242a93U), BSWAP_32BIG_C(
                    0x9b2e0604U),
            };
            r_rsip_func101(Param_pedf_func101_004);
        }
    }

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000edU);

    static const uint32_t Param_pedf_func101_005[] =
    {
        BSWAP_32BIG_C(0xc3577c62U), BSWAP_32BIG_C(0x854953e1U), BSWAP_32BIG_C(0x7892cb3fU), BSWAP_32BIG_C(0x71a0862bU),
    };
    r_rsip_func101(Param_pedf_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xa7cd232fU, 0x00A60000U);
    static const uint32_t Param_pedf_func100_003[] =
    {
        BSWAP_32BIG_C(0x6c291004U), BSWAP_32BIG_C(0x053d7ed7U), BSWAP_32BIG_C(0xcfa4e109U), BSWAP_32BIG_C(0xf5ff32bdU),
    };
    r_rsip_func100(Param_pedf_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pedf_func102_002[] =
        {
            BSWAP_32BIG_C(0x17836626U), BSWAP_32BIG_C(0xcaf969bdU), BSWAP_32BIG_C(0xfe180470U), BSWAP_32BIG_C(
                0x1799ae3fU),
        };
        r_rsip_func102(Param_pedf_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000edU);

        static const uint32_t Param_pedf_func101_006[] =
        {
            BSWAP_32BIG_C(0x8e408bc7U), BSWAP_32BIG_C(0x95c9b571U), BSWAP_32BIG_C(0xcbbeefdfU), BSWAP_32BIG_C(
                0x244c5209U),
        };
        r_rsip_func101(Param_pedf_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pedf_func102_003[] =
        {
            BSWAP_32BIG_C(0x019717a2U), BSWAP_32BIG_C(0xbf98c470U), BSWAP_32BIG_C(0x2bd50f39U), BSWAP_32BIG_C(
                0x5aa3a128U),
        };
        r_rsip_func102(Param_pedf_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
