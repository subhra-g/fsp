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

void r_rsip_func422 (const uint32_t ARG1[], uint32_t ARG2)
{
    uint32_t jLoop = 0U;

    static const uint32_t Param_func422_func100_001[] =
    {
        BSWAP_32BIG_C(0xa5963577U), BSWAP_32BIG_C(0xac8d53eeU), BSWAP_32BIG_C(0xb4eb4162U), BSWAP_32BIG_C(0x3865a5e3U),
    };
    r_rsip_func100(Param_func422_func100_001);
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000010U);
    r_rsip_func_sub010(0x000003c7U, 0x80840007U);
    WR1_PROG(REG_1420H, ARG1[ARG2 + 4]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, ARG1[ARG2 + 5]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, ARG1[ARG2 + 6]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, ARG1[ARG2 + 7]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x0000b4a0U, 0x00000004U, 0x00003500U, 0x00036908U);
    r_rsip_func_sub024(0x00008d00U, 0x0000000cU, 0x000024c8U, 0x000024e8U);

    r_rsip_func_sub024(0x00003826U, 0x00003847U, 0x00003460U, 0x00008c60U);
    r_rsip_func_sub024(0x0000001fU, 0x0000b480U, 0xffffffffU, 0x00004403U);
    r_rsip_func_sub024(0x00007484U, 0x00000c24U, 0x00001484U, 0x00000c44U);

    r_rsip_func_sub024(0x00001041U, 0x00003c47U, 0x000037e0U, 0x00008fe0U);
    r_rsip_func_sub024(0x0000007fU, 0x38008fe0U, 0x0000001fU, 0x1000a7e0U);
    r_rsip_func_sub024(0x00000020U, 0x0000b7c0U, 0x00000080U, 0x00002bdfU);
    WR1_PROG(REG_1600H, 0x00056bdeU);
    WR1_PROG(REG_1600H, 0x0000353eU);

    r_rsip_func_sub016(0x810103c0U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (jLoop = 0U; jLoop < S_RAM[0]; jLoop++)
    {
        r_rsip_func_sub024(0x000024c5U, 0x000024e5U, 0x00003b86U, 0x00003f87U);

        WR1_PROG(REG_1600H, 0x000033c0U);
        static const uint32_t Param_func422_func101_001[] =
        {
            BSWAP_32BIG_C(0xb77f8759U), BSWAP_32BIG_C(0xdaf38eccU), BSWAP_32BIG_C(0x122d89bdU), BSWAP_32BIG_C(
                0xc1f0ee34U),
        };
        r_rsip_func101(Param_func422_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000fdeU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
