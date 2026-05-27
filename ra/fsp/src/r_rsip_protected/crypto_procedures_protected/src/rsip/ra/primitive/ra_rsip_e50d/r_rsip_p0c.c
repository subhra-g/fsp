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

rsip_ret_t r_rsip_p0c (const uint32_t InData_CurrentVer[], const uint32_t InData_NextVer[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000c0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_CurrentVer);

    r_rsip_func049(InData_NextVer);

    r_rsip_func_sub017(0x34202880U, 0x00260000U);

    static const uint32_t Param_p0c_func100_001[] =
    {
        BSWAP_32BIG_C(0xa006fff8U), BSWAP_32BIG_C(0xd93cd0bbU), BSWAP_32BIG_C(0xcdb66f1eU), BSWAP_32BIG_C(0x184dd992U),
    };
    r_rsip_func100(Param_p0c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_14BCH, 0x00000020U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_VERIFICATION_FAIL;
    }
    else
    {
        r_rsip_func_sub017(0x38002880U, 0x00260000U);

        static const uint32_t Param_p0c_func100_002[] =
        {
            BSWAP_32BIG_C(0x3983300cU), BSWAP_32BIG_C(0xf424286cU), BSWAP_32BIG_C(0x74c57a20U), BSWAP_32BIG_C(
                0x880d5960U),
        };
        r_rsip_func100(Param_p0c_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1B08H, 0x00000215U);

            static const uint32_t Param_p0c_func102_001[] =
            {
                BSWAP_32BIG_C(0x937ec401U), BSWAP_32BIG_C(0x67c174b4U), BSWAP_32BIG_C(0xc32d39c1U), BSWAP_32BIG_C(
                    0x80bc13f3U),
            };
            r_rsip_func102(Param_p0c_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_VERSION_MATCH;
        }
        else
        {
            WR1_PROG(REG_1B08H, 0x00000215U);

            static const uint32_t Param_p0c_func102_002[] =
            {
                BSWAP_32BIG_C(0x3adff011U), BSWAP_32BIG_C(0xf98f1382U), BSWAP_32BIG_C(0xcc6f21a7U), BSWAP_32BIG_C(
                    0x9774e299U),
            };
            r_rsip_func102(Param_p0c_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
