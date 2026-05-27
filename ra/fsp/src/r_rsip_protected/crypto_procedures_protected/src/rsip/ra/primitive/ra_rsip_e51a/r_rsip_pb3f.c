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

rsip_ret_t r_rsip_pb3f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb3f_func100_001[] =
    {
        BSWAP_32BIG_C(0xa2b329ebU), BSWAP_32BIG_C(0x631fbbc4U), BSWAP_32BIG_C(0x3e5601bdU), BSWAP_32BIG_C(0x4923be50U),
    };
    r_rsip_func100(Param_pb3f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb3f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc624de30U), BSWAP_32BIG_C(0x11850024U), BSWAP_32BIG_C(0xcb45900bU), BSWAP_32BIG_C(
                0xf67dbfa0U),
        };
        r_rsip_func102(Param_pb3f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb3f_func100_002[] =
        {
            BSWAP_32BIG_C(0x9e4d72d9U), BSWAP_32BIG_C(0x9d3b5addU), BSWAP_32BIG_C(0x39d9dda4U), BSWAP_32BIG_C(
                0x4e3323efU),
        };
        r_rsip_func100(Param_pb3f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb3f_func100_003[] =
        {
            BSWAP_32BIG_C(0xd6eebc9eU), BSWAP_32BIG_C(0x3873f55cU), BSWAP_32BIG_C(0xd13a7613U), BSWAP_32BIG_C(
                0xe00fe575U),
        };
        r_rsip_func100(Param_pb3f_func100_003);

        r_rsip_func_sub028(0x00020061U, 0x00000020U, 0x0d008906U);
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

        static const uint32_t Param_pb3f_func100_004[] =
        {
            BSWAP_32BIG_C(0x5c4a9214U), BSWAP_32BIG_C(0xb45b8579U), BSWAP_32BIG_C(0x87506f29U), BSWAP_32BIG_C(
                0xb429c63fU),
        };
        r_rsip_func100(Param_pb3f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x00000020U, 0x0d008905U);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b3U);

            static const uint32_t Param_pb3f_func101_001[] =
            {
                BSWAP_32BIG_C(0x4803c617U), BSWAP_32BIG_C(0xf08fb4caU), BSWAP_32BIG_C(0x755f1b83U), BSWAP_32BIG_C(
                    0xc88eb0a8U),
            };
            r_rsip_func101(Param_pb3f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb3f_func100_005[] =
            {
                BSWAP_32BIG_C(0xea499061U), BSWAP_32BIG_C(0x2b90e310U), BSWAP_32BIG_C(0x696d9aa1U), BSWAP_32BIG_C(
                    0x9274c340U),
            };
            r_rsip_func100(Param_pb3f_func100_005);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x00000020U);
            WR1_PROG(REG_1824H, 0x0d008905U);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000b3U);

            static const uint32_t Param_pb3f_func101_002[] =
            {
                BSWAP_32BIG_C(0xde3eab7eU), BSWAP_32BIG_C(0x79f979a2U), BSWAP_32BIG_C(0x2dead3fcU), BSWAP_32BIG_C(
                    0x95e5a368U),
            };
            r_rsip_func101(Param_pb3f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb3f_func101_003[] =
            {
                BSWAP_32BIG_C(0x43ed870dU), BSWAP_32BIG_C(0x7e283c7fU), BSWAP_32BIG_C(0xc056fbaaU), BSWAP_32BIG_C(
                    0xb1a22f90U),
            };
            r_rsip_func101(Param_pb3f_func101_003);
        }

        static const uint32_t Param_pb3f_func102_002[] =
        {
            BSWAP_32BIG_C(0x1ccc8f5bU), BSWAP_32BIG_C(0xe70f7b76U), BSWAP_32BIG_C(0x2946320dU), BSWAP_32BIG_C(
                0x53287152U),
        };
        r_rsip_func102(Param_pb3f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
