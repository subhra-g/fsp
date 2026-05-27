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

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_p76u (const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT)
{
    r_rsip_func000(InData_PaddedMsg, MAX_CNT);
    static const uint32_t Param_p76u_func101_001[] =
    {
        BSWAP_32BIG_C(0xb6206caaU), BSWAP_32BIG_C(0x2f50cb05U), BSWAP_32BIG_C(0x84a3a896U), BSWAP_32BIG_C(0x5c33b3a1U),
    };
    r_rsip_func101(Param_p76u_func101_001);
}
