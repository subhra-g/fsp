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

void r_rsip_func305 (void)
{
    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    WR1_PROG(REG_1404H, 0x1ec80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    r_rsip_func_sub001(0x00030005U);
    r_rsip_func_sub001(0x03430005U);

    r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x2121000aU);

    WR1_PROG(REG_143CH, 0x00a10000U);

    static const uint32_t Param_func305_func100_001[] =
    {
        BSWAP_32BIG_C(0xbe680dbdU), BSWAP_32BIG_C(0xceabf173U), BSWAP_32BIG_C(0x05e7bbdaU), BSWAP_32BIG_C(0x6fef9e92U),
    };
    r_rsip_func100(Param_func305_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func305_func100_002[] =
        {
            BSWAP_32BIG_C(0x15949ac5U), BSWAP_32BIG_C(0x8f936c29U), BSWAP_32BIG_C(0x447b111eU), BSWAP_32BIG_C(
                0x45265351U),
        };
        r_rsip_func100(Param_func305_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x2121000aU);

            static const uint32_t Param_func305_func101_001[] =
            {
                BSWAP_32BIG_C(0xecadebbcU), BSWAP_32BIG_C(0x24d0f771U), BSWAP_32BIG_C(0xa27202bbU), BSWAP_32BIG_C(
                    0x92b49c90U),
            };
            r_rsip_func101(Param_func305_func101_001);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func305_func101_002[] =
            {
                BSWAP_32BIG_C(0x19969077U), BSWAP_32BIG_C(0xebe6d931U), BSWAP_32BIG_C(0xf1a6782aU), BSWAP_32BIG_C(
                    0x25ed47b8U),
            };
            r_rsip_func101(Param_func305_func101_002);
        }
    }
    else
    {
        r_rsip_func_sub017(0x38000af8U, 0x00260000U);

        static const uint32_t Param_func305_func100_003[] =
        {
            BSWAP_32BIG_C(0x2fcb44c9U), BSWAP_32BIG_C(0xe7e96fe6U), BSWAP_32BIG_C(0xe8f6a90fU), BSWAP_32BIG_C(
                0x3183efb5U),
        };
        r_rsip_func100(Param_func305_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000fd8U, 0x00000838U, 0x00000838U, 0x2121000aU);

            WR1_PROG(REG_1600H, 0x0000dee0U);

            static const uint32_t Param_func305_func101_003[] =
            {
                BSWAP_32BIG_C(0xff78d412U), BSWAP_32BIG_C(0xe685424aU), BSWAP_32BIG_C(0x4f3ce470U), BSWAP_32BIG_C(
                    0x7b6272f5U),
            };
            r_rsip_func101(Param_func305_func101_003);
        }
        else
        {
            r_rsip_func_sub002(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);

            static const uint32_t Param_func305_func101_004[] =
            {
                BSWAP_32BIG_C(0xb71b9f81U), BSWAP_32BIG_C(0x9296d29bU), BSWAP_32BIG_C(0xeeb6a69eU), BSWAP_32BIG_C(
                    0xb8309f65U),
            };
            r_rsip_func101(Param_func305_func101_004);
        }
    }

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    r_rsip_func_sub001(0x00c00005U);
    r_rsip_func_sub001(0x00c90005U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
