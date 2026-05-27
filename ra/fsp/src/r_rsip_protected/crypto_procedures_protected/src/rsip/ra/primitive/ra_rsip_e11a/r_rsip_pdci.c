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

rsip_ret_t r_rsip_pdci (const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub014(0x00dc0001U, 0x0000001aU);

    static const uint32_t Param_pdci_sub100_001[] =
    {
        BSWAP_32BIG_C(0x000000dcU), BSWAP_32BIG_C(0x237dcde3U), BSWAP_32BIG_C(0x9a082f28U),
        BSWAP_32BIG_C(0x3784032eU),
        BSWAP_32BIG_C(0x73d5fc41U), BSWAP_32BIG_C(0x000000dcU), BSWAP_32BIG_C(0x4c512280U),
        BSWAP_32BIG_C(0x7d582cedU),
        BSWAP_32BIG_C(0xfe0e57f3U),
        BSWAP_32BIG_C(0xeba01fd6U), 0x00001404U,
    };
    r_rsip_func_sub100(InData_KeyIndex, Param_pdci_sub100_001, RSIP_SEL_BIT_LENGTH_256);

    static const uint32_t Param_pdci_func100_001[] =
    {
        BSWAP_32BIG_C(0xeef6f8d0U), BSWAP_32BIG_C(0x7c484370U), BSWAP_32BIG_C(0xe39ba42dU), BSWAP_32BIG_C(0x3a1929b0U),
    };
    r_rsip_func100(Param_pdci_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pdci_func102_001[] =
        {
            BSWAP_32BIG_C(0xbaa3e24fU), BSWAP_32BIG_C(0x3434286fU), BSWAP_32BIG_C(0x2886e279U), BSWAP_32BIG_C(
                0xb25d9d06U),
        };
        r_rsip_func102(Param_pdci_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func003();

        WR1_PROG(REG_00F4H, 0x00000011U);

        r_rsip_func001();

        static const uint32_t Param_pdci_func101_001[] =
        {
            BSWAP_32BIG_C(0xf7f66beaU), BSWAP_32BIG_C(0x9a2860d2U), BSWAP_32BIG_C(0x47c25ea1U), BSWAP_32BIG_C(
                0x247e6b15U),
        };
        r_rsip_func101(Param_pdci_func101_001);

        return RSIP_RET_PASS;
    }
}
