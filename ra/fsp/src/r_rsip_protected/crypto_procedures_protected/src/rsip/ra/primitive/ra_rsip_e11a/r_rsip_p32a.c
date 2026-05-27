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

void r_rsip_p32a (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    r_rsip_func430(InData_DataA, MAX_CNT);

    static const uint32_t Param_p32a_func101_001[] =
    {
        BSWAP_32BIG_C(0xf256afe8U), BSWAP_32BIG_C(0xaccfe63eU), BSWAP_32BIG_C(0x34f2f691U), BSWAP_32BIG_C(0xa3182d5eU),
    };
    r_rsip_func101(Param_p32a_func101_001);
}
