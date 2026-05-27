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

void r_rsip_func402 (void)
{
    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_func402_func100_001[] =
    {
        BSWAP_32BIG_C(0xe7c7a388U), BSWAP_32BIG_C(0x6405c604U), BSWAP_32BIG_C(0xa473c22aU), BSWAP_32BIG_C(0xa487fa46U),
    };
    r_rsip_func100(Param_func402_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub002(0x00000b60U, 0x00000b10U, 0x00000750U, 0x0404000aU);

        r_rsip_func_sub002(0x00000bb0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

        r_rsip_func_sub002(0x00000c00U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

        static const uint32_t Param_func402_func101_001[] =
        {
            BSWAP_32BIG_C(0x872cd0c2U), BSWAP_32BIG_C(0x3971cf55U), BSWAP_32BIG_C(0x47df5790U), BSWAP_32BIG_C(
                0x98c9a2f9U),
        };
        r_rsip_func101(Param_func402_func101_001);
    }
    else
    {
        r_rsip_func_sub002(0x00000480U, 0x00000b10U, 0x00000750U, 0x0404000aU);

        r_rsip_func_sub002(0x000004d0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);

        r_rsip_func_sub002(0x00000520U, 0x00000b10U, 0x000007f0U, 0x0404000aU);

        static const uint32_t Param_func402_func101_002[] =
        {
            BSWAP_32BIG_C(0xdfcff10dU), BSWAP_32BIG_C(0xdd0d6da3U), BSWAP_32BIG_C(0x80135499U), BSWAP_32BIG_C(
                0xc7b3463aU),
        };
        r_rsip_func101(Param_func402_func101_002);
    }

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
