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

void r_rsip_func_sub001 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_00B4H, arg1);
    WR1_PROG(REG_00B8H, arg2);
    WR1_PROG(REG_00A4H, arg3);
    WR1_PROG(REG_00A0H, 0x20010001U);
    WAIT_STS(REG_00A8H, 0, 1);
    WR1_PROG(REG_00ACH, 0x00000001U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub002 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_0014H, 0x000000a7U);
    WR1_PROG(REG_009CH, arg1);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(arg2));
    WR1_PROG(REG_0024H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub003 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_009CH, arg1);
    WR1_PROG(REG_0000H, arg2);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub004 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_00B0H, arg1);
    WR1_PROG(REG_0000H, arg2);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub005 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0014H, arg1);
    WR1_PROG(REG_00D0H, arg2);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, bswap_32big(arg3));
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub006 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_00D0H, arg1);
    WR1_PROG(REG_0000H, arg2);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub007 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_0094H, arg2);
    WR1_PROG(REG_009CH, 0x00000080U);
    WR1_PROG(REG_0040H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub008 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0014H, arg1);
    WR1_PROG(REG_00D4H, arg2);
    WR1_PROG(REG_00D0H, arg3);
    WAIT_STS(REG_0014H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub009 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_0000H, arg1);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
    WR1_PROG(REG_0094H, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub010 (uint32_t arg1)
{
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_009CH, 0x00000080U);
    WR1_PROG(REG_0040H, 0x00260000U);
    WR1_PROG(REG_0040H, 0x00402000U);
    WR1_PROG(REG_0024H, 0x00000000U);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub011 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0070H, arg1);
    WR1_PROG(REG_004CH, 0x00000000U);
    WR1_PROG(REG_0014H, arg2);
    WR1_PROG(REG_009CH, arg3);
    WAIT_STS(REG_0014H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub012 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_0024H, 0x00000000U);
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_009CH, 0x00000080U);
    WR1_PROG(REG_0040H, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub013 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, arg2);
    WAIT_STS(REG_0014H, 31, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub014 (uint32_t arg1, uint32_t arg2)
{
    WR1_PROG(REG_0070H, arg1);
    WR1_PROG(REG_004CH, 0x00000000U);
    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, arg2);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub015 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_009CH, arg2);
    WR1_PROG(REG_0008H, arg3);
    WAIT_STS(REG_0008H, 30, 1);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub016 (uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
    WR1_PROG(REG_0094H, arg1);
    WR1_PROG(REG_0094H, arg2);
    WR1_PROG(REG_0094H, arg3);
}

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_func_sub100 (const uint32_t ARG1[], const uint32_t PARAM[], rsip_sel_bit_length_t bit_len)
{
    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x800100c0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, ARG1[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0014H, 0x000000a7U);
    WR1_PROG(REG_009CH, 0x800100e0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, PARAM[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func101(&PARAM[1]);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x000034c5U);

    WR1_PROG(REG_0014H, 0x000000a7U);
    WR1_PROG(REG_009CH, 0x800100e0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, PARAM[5]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func101(&PARAM[6]);
    r_rsip_func044();

    if (bit_len == RSIP_SEL_BIT_LENGTH_256)
    {
        WR1_PROG(REG_0014H, 0x000007c1U);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xf7009d07U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[1]);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[5]);

        WR1_PROG(REG_00B0H, PARAM[10]);
        WR1_PROG(REG_0000H, 0x00c10021U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_0014H, 0x000003c1U);
        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0x07008d05U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[9]);
    }
    else
    {
        WR1_PROG(REG_0014H, 0x000007c1U);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xf7009d07U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[1]);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[5]);

        WR1_PROG(REG_00B0H, PARAM[10]);
        WR1_PROG(REG_0000H, 0x00c10021U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_0014H, 0x000007c1U);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xf7008d07U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[9]);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[13]);

        WR1_PROG(REG_00B0H, 0x00001408U);
        WR1_PROG(REG_0000H, 0x00c10021U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_0014H, 0x000003c1U);
        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0x07008d05U);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &ARG1[17]);
    }

    WR1_PROG(REG_00D0H, 0x9c100005U);
    WR1_PROG(REG_0000H, 0x00410011U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);
}
