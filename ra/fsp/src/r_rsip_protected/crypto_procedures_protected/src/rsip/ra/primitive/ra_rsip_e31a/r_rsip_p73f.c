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

rsip_ret_t r_rsip_p73f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
{
    uint32_t iLoop = 0U;

    WAIT_STS(REG_0118H, 0, 1);

    WR1_PROG(REG_0014H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16U)
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR16_ADDR(REG_002CH, &InData_Msg[iLoop]);
    }

    WAIT_STS(REG_0014H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_002CH, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_0014H, 0x00000000U);
    WAIT_STS(REG_0118H, 8, 0);
    WR1_PROG(REG_0040H, 0x00001600U);

    WAIT_STS(REG_0118H, 4, 1);

    static const uint32_t Param_p73f_func100_001[] =
    {
        BSWAP_32BIG_C(0xa2c4a1fdU), BSWAP_32BIG_C(0xac08db0eU), BSWAP_32BIG_C(0x5f410eadU), BSWAP_32BIG_C(0xc3c5be3eU),
    };
    r_rsip_func100(Param_p73f_func100_001);
    r_rsip_func_sub022(0x38008800U, 0x00000003U, 0x1000b400U);
    r_rsip_func_sub022(0x00000001U, 0x38008800U, 0x00000004U);
    r_rsip_func_sub022(0x1000b400U, 0x00000002U, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        static const uint32_t Param_p73f_func100_002[] =
        {
            BSWAP_32BIG_C(0xa58082c6U), BSWAP_32BIG_C(0x3f879f00U), BSWAP_32BIG_C(0x816affa0U), BSWAP_32BIG_C(
                0x795273e1U),
        };
        r_rsip_func100(Param_p73f_func100_002);
        WR1_PROG(REG_0008H, 0x0000401eU);
        WAIT_STS(REG_0008H, 30, 1);
        RD7_ADDR(REG_002CH, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc019dcbeU), BSWAP_32BIG_C(0xa552809fU), BSWAP_32BIG_C(0x984fc62eU), BSWAP_32BIG_C(
                0x46b83ae7U),
        };
        r_rsip_func102(Param_p73f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
    {
        static const uint32_t Param_p73f_func100_003[] =
        {
            BSWAP_32BIG_C(0x6248df88U), BSWAP_32BIG_C(0x5b075037U), BSWAP_32BIG_C(0x07a3aaddU), BSWAP_32BIG_C(
                0xb8cd02d1U),
        };
        r_rsip_func100(Param_p73f_func100_003);
        WR1_PROG(REG_0008H, 0x00004022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD8_ADDR(REG_002CH, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_002[] =
        {
            BSWAP_32BIG_C(0x30737869U), BSWAP_32BIG_C(0x1c64302eU), BSWAP_32BIG_C(0x2b4acf3eU), BSWAP_32BIG_C(
                0xdfcaceccU),
        };
        r_rsip_func102(Param_p73f_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000005U)
    {
        static const uint32_t Param_p73f_func100_004[] =
        {
            BSWAP_32BIG_C(0xac6a0371U), BSWAP_32BIG_C(0x2ca41847U), BSWAP_32BIG_C(0x6d2aea84U), BSWAP_32BIG_C(
                0xaf49a2b9U),
        };
        r_rsip_func100(Param_p73f_func100_004);
        WR1_PROG(REG_0008H, 0x00004032U);
        WAIT_STS(REG_0008H, 30, 1);
        RD12_ADDR(REG_002CH, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_003[] =
        {
            BSWAP_32BIG_C(0xf80b2d06U), BSWAP_32BIG_C(0xda6a3270U), BSWAP_32BIG_C(0xa4bdc938U), BSWAP_32BIG_C(
                0x9936eafcU),
        };
        r_rsip_func102(Param_p73f_func102_003);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
    {
        static const uint32_t Param_p73f_func100_005[] =
        {
            BSWAP_32BIG_C(0x68d423e3U), BSWAP_32BIG_C(0xc7a2da06U), BSWAP_32BIG_C(0x24a01e4eU), BSWAP_32BIG_C(
                0x86b44fddU),
        };
        r_rsip_func100(Param_p73f_func100_005);
        WR1_PROG(REG_0008H, 0x00004042U);
        WAIT_STS(REG_0008H, 30, 1);
        RD16_ADDR(REG_002CH, &OutData_MsgDigest[0]);

        static const uint32_t Param_p73f_func102_004[] =
        {
            BSWAP_32BIG_C(0xe6373b9bU), BSWAP_32BIG_C(0x7f30e07aU), BSWAP_32BIG_C(0x7b4fd7a4U), BSWAP_32BIG_C(
                0x52ce06a7U),
        };
        r_rsip_func102(Param_p73f_func102_004);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);
    }

    return RSIP_RET_PASS;
}
