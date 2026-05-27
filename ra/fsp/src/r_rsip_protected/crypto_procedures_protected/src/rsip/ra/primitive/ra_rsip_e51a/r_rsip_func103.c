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

void r_rsip_func103 (void)
{
    static const uint32_t Param_func103_func100_001[] =
    {
        BSWAP_32BIG_C(0xa65e93d4U), BSWAP_32BIG_C(0x3be84215U), BSWAP_32BIG_C(0x521e4cafU), BSWAP_32BIG_C(0xf50c43a4U),
    };
    r_rsip_func100(Param_func103_func100_001);
    r_rsip_func_sub008(0x000004a2U, 0x40000000U, 0x07328c04U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub032(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1A24H, 0x08000065U);
    r_rsip_func_sub001(0x00820011U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub032(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1404H, 0x1fd80000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub032(0x07328d04U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    r_rsip_func_sub032(0x06328074U, 0x00000000U);

    WR1_PROG(REG_1404H, 0x1fd80000U);
    WR1_PROG(REG_1A24H, 0x080000a5U);
    r_rsip_func_sub001(0x00830011U);

    static const uint32_t Param_func103_func100_002[] =
    {
        BSWAP_32BIG_C(0xc504ca52U), BSWAP_32BIG_C(0x2669871fU), BSWAP_32BIG_C(0x4e1f35b8U), BSWAP_32BIG_C(0x14c73cb2U),
    };
    r_rsip_func100(Param_func103_func100_002);
    WR1_PROG(REG_1A24H, 0x080000b5U);
    r_rsip_func_sub001(0x00820011U);
    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
