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

void r_rsip_p34a (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    r_rsip_func430(InData_DataA, MAX_CNT);

    static const uint32_t Param_p34a_func101_001[] =
    {
        BSWAP_32BIG_C(0x2daaf071U), BSWAP_32BIG_C(0x262437afU), BSWAP_32BIG_C(0xfd3ce8f0U), BSWAP_32BIG_C(0x382c9952U),
    };
    r_rsip_func101(Param_p34a_func101_001);
}
