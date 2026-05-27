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

void r_rsip_func040 (void)
{
    static const uint32_t Param_func040_func100_001[] =
    {
        BSWAP_32BIG_C(0xe960a74fU), BSWAP_32BIG_C(0x4d3fc9fbU), BSWAP_32BIG_C(0x5d4eb718U), BSWAP_32BIG_C(0xffb5a7a7U),
    };
    r_rsip_func100(Param_func040_func100_001);
    r_rsip_func_sub028(0x4a470044U, 0x00000000U);

    r_rsip_func_sub028(0x0e470484U, 0x01ea725dU);

    static const uint32_t Param_func040_func100_002[] =
    {
        BSWAP_32BIG_C(0xb2141d54U), BSWAP_32BIG_C(0x49dba92cU), BSWAP_32BIG_C(0x92aa10b5U), BSWAP_32BIG_C(0x6f4942dfU),
    };
    r_rsip_func100(Param_func040_func100_002);
    r_rsip_func_sub028(0x4a470044U, 0x00000000U);

    r_rsip_func_sub028(0x0e470494U, 0x02ea725dU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
