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

rsip_ret_t r_rsip_pb9f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb9f_func100_001[] =
    {
        BSWAP_32BIG_C(0xcaa40270U), BSWAP_32BIG_C(0x7da17216U), BSWAP_32BIG_C(0x238f142dU), BSWAP_32BIG_C(0x50d3d8beU),
    };
    r_rsip_func100(Param_pb9f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb9f_func102_001[] =
        {
            BSWAP_32BIG_C(0xbb0b0d7cU), BSWAP_32BIG_C(0x1ff1722eU), BSWAP_32BIG_C(0x88300f3eU), BSWAP_32BIG_C(
                0xcfa81d52U),
        };
        r_rsip_func102(Param_pb9f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb9f_func100_002[] =
        {
            BSWAP_32BIG_C(0xb3cda820U), BSWAP_32BIG_C(0x0e5740e9U), BSWAP_32BIG_C(0x16a78d29U), BSWAP_32BIG_C(
                0x2076db4fU),
        };
        r_rsip_func100(Param_pb9f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb9f_func100_003[] =
        {
            BSWAP_32BIG_C(0x4aa02ed9U), BSWAP_32BIG_C(0xf90cbfb5U), BSWAP_32BIG_C(0x96581b6eU), BSWAP_32BIG_C(
                0x376132d8U),
        };
        r_rsip_func100(Param_pb9f_func100_003);

        r_rsip_func_sub028(0x00020061U, 0x40000020U, 0x0d008906U);
        WR1_PROG(REG_1408H, 0x000c1000U);

        iLoop = 0U;
        if (S_RAM[0] >= 4)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[0]);
            for (iLoop = 4; iLoop < S_RAM[0]; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        }

        r_rsip_func214();

        r_rsip_func421();

        static const uint32_t Param_pb9f_func100_004[] =
        {
            BSWAP_32BIG_C(0x1e330196U), BSWAP_32BIG_C(0x55d1b27eU), BSWAP_32BIG_C(0x18afca81U), BSWAP_32BIG_C(
                0x793f6f0fU),
        };
        r_rsip_func100(Param_pb9f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x40000020U, 0x0d008905U);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b9U);

            static const uint32_t Param_pb9f_func101_001[] =
            {
                BSWAP_32BIG_C(0x8c17f287U), BSWAP_32BIG_C(0x48a92d97U), BSWAP_32BIG_C(0x13a872d1U), BSWAP_32BIG_C(
                    0x012792ceU),
            };
            r_rsip_func101(Param_pb9f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb9f_func100_005[] =
            {
                BSWAP_32BIG_C(0x3db01d75U), BSWAP_32BIG_C(0x87517df7U), BSWAP_32BIG_C(0xd4d775b5U), BSWAP_32BIG_C(
                    0xb8a52900U),
            };
            r_rsip_func100(Param_pb9f_func100_005);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x40000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b9U);

            static const uint32_t Param_pb9f_func101_002[] =
            {
                BSWAP_32BIG_C(0x4df2d62aU), BSWAP_32BIG_C(0xba2e6df6U), BSWAP_32BIG_C(0x3f408632U), BSWAP_32BIG_C(
                    0xe43d421bU),
            };
            r_rsip_func101(Param_pb9f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb9f_func101_003[] =
            {
                BSWAP_32BIG_C(0x2772d859U), BSWAP_32BIG_C(0x2292abdaU), BSWAP_32BIG_C(0x306ca261U), BSWAP_32BIG_C(
                    0x87c613fbU),
            };
            r_rsip_func101(Param_pb9f_func101_003);
        }

        static const uint32_t Param_pb9f_func102_002[] =
        {
            BSWAP_32BIG_C(0x85e21266U), BSWAP_32BIG_C(0x0d8a895bU), BSWAP_32BIG_C(0x38aedaefU), BSWAP_32BIG_C(
                0x07600079U),
        };
        r_rsip_func102(Param_pb9f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
