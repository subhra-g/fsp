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

void r_rsip_func413 (void)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_func413_func100_001[] =
    {
        BSWAP_32BIG_C(0xfd3d3f18U), BSWAP_32BIG_C(0x8df77f17U), BSWAP_32BIG_C(0xe919f16aU), BSWAP_32BIG_C(0x3cfb0934U),
    };
    r_rsip_func100(Param_func413_func100_001);
    r_rsip_func_sub024(0x00002d60U, 0x0002696bU, 0x0000094aU, 0x0000b7e0U);
    WR1_PROG(REG_1600H, 0xa7cd232fU);

    r_rsip_func_sub016(0x81010160U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
    {
        WR1_PROG(REG_1824H, 0x08000045U);
        WR1_PROG(REG_1608H, 0x81840002U);
        r_rsip_func_sub001(0x00490011U);

        WR1_PROG(REG_1608H, 0x8184000cU);
        WR1_PROG(REG_1824H, 0x9c000005U);
        r_rsip_func_sub001(0x00490011U);

        static const uint32_t Param_func413_func100_002[] =
        {
            BSWAP_32BIG_C(0x0005ebc0U), BSWAP_32BIG_C(0xc5c3958eU), BSWAP_32BIG_C(0x25e95314U), BSWAP_32BIG_C(
                0x110b4716U),
        };
        r_rsip_func100(Param_func413_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000bffU);

            static const uint32_t Param_func413_func101_001[] =
            {
                BSWAP_32BIG_C(0xf4ffa9f2U), BSWAP_32BIG_C(0xd1efa523U), BSWAP_32BIG_C(0xd0923962U), BSWAP_32BIG_C(
                    0x1582c03bU),
            };
            r_rsip_func101(Param_func413_func101_001);
        }
        else
        {
            static const uint32_t Param_func413_func101_002[] =
            {
                BSWAP_32BIG_C(0x31d8d996U), BSWAP_32BIG_C(0xa8d3178cU), BSWAP_32BIG_C(0xbd90e088U), BSWAP_32BIG_C(
                    0x6e3cabfcU),
            };
            r_rsip_func101(Param_func413_func101_002);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub024(0x0000a440U, 0x00000010U, 0x0000a580U, 0x00000010U);

        WR1_PROG(REG_1600H, 0x00002d40U);

        static const uint32_t Param_func413_func101_003[] =
        {
            BSWAP_32BIG_C(0x70ad61f9U), BSWAP_32BIG_C(0x98bb70bcU), BSWAP_32BIG_C(0x54a3f725U), BSWAP_32BIG_C(
                0x5efcf094U),
        };
        r_rsip_func101(Param_func413_func101_003);
    }

    r_rsip_func_sub011(0x3800094bU);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
