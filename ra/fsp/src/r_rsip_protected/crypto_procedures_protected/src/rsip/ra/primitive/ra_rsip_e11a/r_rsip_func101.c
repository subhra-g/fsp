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

void r_rsip_func101 (const uint32_t ARG1[])
{
    WR1_PROG(REG_00D0H, 0x0a0701e5U);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_PROG(REG_002CH, ARG1[0], ARG1[1], ARG1[2], ARG1[3]);
    WAIT_STS(REG_00C8H, 17, 0);
}
