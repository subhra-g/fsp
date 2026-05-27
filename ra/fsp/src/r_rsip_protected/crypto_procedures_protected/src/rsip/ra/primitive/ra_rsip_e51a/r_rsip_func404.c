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

void r_rsip_func404 (void)
{
    WR1_PROG(REG_1014H, 0x00000610U);
    WR1_PROG(REG_1018H, 0x000007f0U);
    r_rsip_func_sub021(0x00000070U, 0x00000250U, 0x00000008U, 0x04040002U);

    r_rsip_func_sub002(0x00000250U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);
    r_rsip_func_sub022(0x00000250U, 0x00000ac0U, 0x00000070U);
    r_rsip_func_sub027(0x00000700U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000570U, 0x00000750U, 0x00000070U);
    r_rsip_func_sub027(0x000002f0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x000005c0U, 0x000007a0U, 0x00000070U);
    r_rsip_func_sub027(0x00000340U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000160U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub027(0x00000390U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000390U, 0x00000340U, 0x00000070U);
    r_rsip_func_sub027(0x000002a0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000700U, 0x000002a0U, 0x00000070U);
    r_rsip_func_sub027(0x00000390U, 0x00000008U, 0x04040006U);
    r_rsip_func_sub007(0x00000700U, 0x000002a0U, 0x00000070U);
    r_rsip_func_sub027(0x000003e0U, 0x00000008U, 0x04040005U);
    r_rsip_func_sub007(0x00000390U, 0x000003e0U, 0x00000070U);
    r_rsip_func_sub027(0x00000700U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000250U, 0x000003e0U, 0x00000070U);
    r_rsip_func_sub027(0x00000660U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000110U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub027(0x000002a0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000340U, 0x000002a0U, 0x00000070U);
    r_rsip_func_sub027(0x000003e0U, 0x00000008U, 0x04040006U);
    r_rsip_func_sub007(0x00000660U, 0x000003e0U, 0x00000070U);
    r_rsip_func_sub027(0x000006b0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000250U, 0x00000390U, 0x00000070U);
    r_rsip_func_sub027(0x000002a0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x00000570U, 0x000005c0U, 0x00000070U);
    r_rsip_func_sub027(0x00000250U, 0x00000008U, 0x04040005U);
    r_rsip_func_sub007(0x00000750U, 0x000007a0U, 0x00000070U);
    r_rsip_func_sub027(0x00000390U, 0x00000008U, 0x04040005U);
    r_rsip_func_sub007(0x00000250U, 0x00000390U, 0x00000070U);
    r_rsip_func_sub027(0x000003e0U, 0x00000008U, 0x04040002U);
    r_rsip_func_sub007(0x000003e0U, 0x000002f0U, 0x00000070U);
    r_rsip_func_sub027(0x00000250U, 0x00000008U, 0x04040006U);
    r_rsip_func_sub007(0x00000250U, 0x00000340U, 0x00000070U);
    r_rsip_func_sub027(0x00000390U, 0x00000008U, 0x04040006U);
    r_rsip_func_sub007(0x000002a0U, 0x00000390U, 0x00000070U);
    r_rsip_func_sub027(0x00000660U, 0x00000008U, 0x04040002U);
    WAIT_STS(REG_1000H, 0, 0);
}
