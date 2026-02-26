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

rsip_ret_t r_rsip_pefi (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00ef0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00F0H, 0x00000001U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3000a800U, 0x00000002U);
    r_rsip_func_sub022(0x00010020U, 0x0000b400U, 0x00000001U);
    WR1_PROG(REG_0094H, 0x00000080U);

    static const uint32_t Param_pefi_func100_001[] =
    {
        BSWAP_32BIG_C(0x520a7deeU), BSWAP_32BIG_C(0xad0c4a9dU), BSWAP_32BIG_C(0xd0e29c27U), BSWAP_32BIG_C(0xc9403158U),
    };
    r_rsip_func100(Param_pefi_func100_001);

    WR1_PROG(REG_0094H, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_00F4H, 0x00000050U);

        static const uint32_t Param_pefi_func101_001[] =
        {
            BSWAP_32BIG_C(0x5ab6d0e5U), BSWAP_32BIG_C(0x7f3af3f4U), BSWAP_32BIG_C(0x62206a1cU), BSWAP_32BIG_C(
                0x1593d603U),
        };
        r_rsip_func101(Param_pefi_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_00F4H, 0x000000a0U);

        static const uint32_t Param_pefi_func101_002[] =
        {
            BSWAP_32BIG_C(0x1f1f7124U), BSWAP_32BIG_C(0xbe429551U), BSWAP_32BIG_C(0x7964ba0cU), BSWAP_32BIG_C(
                0x2177bd3eU),
        };
        r_rsip_func101(Param_pefi_func101_002);
    }

    r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003c01U);

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_00FCH, 0x00000100U);

        static const uint32_t Param_pefi_func101_003[] =
        {
            BSWAP_32BIG_C(0x11f562daU), BSWAP_32BIG_C(0xd6132db3U), BSWAP_32BIG_C(0xf2d846b8U), BSWAP_32BIG_C(
                0xd8f560d7U),
        };
        r_rsip_func101(Param_pefi_func101_003);
    }
    else
    {
        WR1_PROG(REG_0014H, 0x00000040U);
        WR1_PROG(REG_0104H, InData_MsgLen[0]);
        WR1_PROG(REG_0014H, 0x00000040U);
        WR1_PROG(REG_0100H, InData_MsgLen[1]);

        static const uint32_t Param_pefi_func101_004[] =
        {
            BSWAP_32BIG_C(0x1af3fa18U), BSWAP_32BIG_C(0xf89ca8e0U), BSWAP_32BIG_C(0x34d44bf7U), BSWAP_32BIG_C(
                0x6685241fU),
        };
        r_rsip_func101(Param_pefi_func101_004);
    }

    return RSIP_RET_PASS;
}
