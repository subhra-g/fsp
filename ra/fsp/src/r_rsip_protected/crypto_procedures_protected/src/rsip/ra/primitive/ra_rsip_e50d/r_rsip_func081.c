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

void r_rsip_func081 (void)
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub021(0x00003424U, 0x3420a880U, 0x0000000aU, 0x10000821U);

    r_rsip_func_sub021(0x0000b4e0U, 0x0000000dU, 0x342028e4U, 0x10000821U);

    r_rsip_func_sub021(0x38008880U, 0x000000feU, 0x1000b420U, 0x0000000cU);

    r_rsip_func_sub021(0x0000b4e0U, 0x00000012U, 0x0000b7a0U, 0x00000004U);

    WR1_PROG(REG_1600H, 0x00000bffU);
    r_rsip_func_sub010(0x00000ba7U, 0x808c001fU);
    WR1_PROG(REG_1420H, bswap_32big(0x00000012U));
    r_rsip_func_sub037(0x00000014U, 0x00000016U);
    r_rsip_func_sub037(0x00000018U, 0x0000001cU);
    r_rsip_func_sub037(0x0000001eU, 0x00000020U);
    r_rsip_func_sub037(0x0000000eU, 0x00000010U);
    r_rsip_func_sub037(0x00000022U, 0x00000024U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    WR1_PROG(REG_1458H, 0x00000000U);

    for (iLoop = 0U; iLoop < 12U; iLoop++)
    {
        r_rsip_func_sub021(0x00003bdfU, 0x3800089eU, 0x10003427U, 0x000027fdU);
    }
}
