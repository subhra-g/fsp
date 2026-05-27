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

rsip_ret_t r_rsip_pb6f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pb6f_func100_001[] =
    {
        BSWAP_32BIG_C(0x7c01aacbU), BSWAP_32BIG_C(0x864e8f23U), BSWAP_32BIG_C(0x248d218cU), BSWAP_32BIG_C(0x6ec8fa97U),
    };
    r_rsip_func100(Param_pb6f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pb6f_func102_001[] =
        {
            BSWAP_32BIG_C(0xd8028364U), BSWAP_32BIG_C(0x65c84b4eU), BSWAP_32BIG_C(0x2e9aa15dU), BSWAP_32BIG_C(
                0xa14d758cU),
        };
        r_rsip_func102(Param_pb6f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pb6f_func100_002[] =
        {
            BSWAP_32BIG_C(0x67f0ac96U), BSWAP_32BIG_C(0xcd985bacU), BSWAP_32BIG_C(0x2ce6ff2aU), BSWAP_32BIG_C(
                0xf15178dcU),
        };
        r_rsip_func100(Param_pb6f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pb6f_func100_003[] =
        {
            BSWAP_32BIG_C(0x30b4b4a4U), BSWAP_32BIG_C(0x3563885fU), BSWAP_32BIG_C(0x55f7b03bU), BSWAP_32BIG_C(
                0xb4d0cc23U),
        };
        r_rsip_func100(Param_pb6f_func100_003);

        r_rsip_func_sub025(0x00020061U, 0x00000020U, 0x0d00890eU);
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

        static const uint32_t Param_pb6f_func100_004[] =
        {
            BSWAP_32BIG_C(0xe484c135U), BSWAP_32BIG_C(0x0b6e0f08U), BSWAP_32BIG_C(0x90a54cffU), BSWAP_32BIG_C(
                0xb9a10744U),
        };
        r_rsip_func100(Param_pb6f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040140U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub019(0x000000a1U, 0x00000020U, 0x0d00880cU);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub019(0x000003c1U, 0x00000020U, 0x0d00890dU);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub003(0x800103a0U, 0x000000b6U);

            static const uint32_t Param_pb6f_func101_001[] =
            {
                BSWAP_32BIG_C(0xca64a427U), BSWAP_32BIG_C(0xd5c808dbU), BSWAP_32BIG_C(0xfd1b57a0U), BSWAP_32BIG_C(
                    0xeb9f472aU),
            };
            r_rsip_func101(Param_pb6f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pb6f_func100_005[] =
            {
                BSWAP_32BIG_C(0xd5d42889U), BSWAP_32BIG_C(0xee004097U), BSWAP_32BIG_C(0x5b3a2005U), BSWAP_32BIG_C(
                    0x608bbddbU),
            };
            r_rsip_func100(Param_pb6f_func100_005);
            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81040140U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x00000020U);
            WR1_PROG(REG_1824H, 0x0d00890dU);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub003(0x800103a0U, 0x000000b6U);

            static const uint32_t Param_pb6f_func101_002[] =
            {
                BSWAP_32BIG_C(0x2ced1ab9U), BSWAP_32BIG_C(0xadd5c001U), BSWAP_32BIG_C(0x33dd57fdU), BSWAP_32BIG_C(
                    0xa3dfbc27U),
            };
            r_rsip_func101(Param_pb6f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pb6f_func101_003[] =
            {
                BSWAP_32BIG_C(0xade353e8U), BSWAP_32BIG_C(0xb026af43U), BSWAP_32BIG_C(0x7399fd23U), BSWAP_32BIG_C(
                    0x5a0a2916U),
            };
            r_rsip_func101(Param_pb6f_func101_003);
        }

        static const uint32_t Param_pb6f_func102_002[] =
        {
            BSWAP_32BIG_C(0x24589d04U), BSWAP_32BIG_C(0x03fdbb58U), BSWAP_32BIG_C(0xd42e458aU), BSWAP_32BIG_C(
                0x13eaa7beU),
        };
        r_rsip_func102(Param_pb6f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
