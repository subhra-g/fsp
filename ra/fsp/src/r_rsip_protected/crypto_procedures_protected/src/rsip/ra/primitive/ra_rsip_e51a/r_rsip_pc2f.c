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

rsip_ret_t r_rsip_pc2f (const uint32_t InData_TextBitLen[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextBitLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func420();

    static const uint32_t Param_pc2f_func100_001[] =
    {
        BSWAP_32BIG_C(0xbf1c7addU), BSWAP_32BIG_C(0xededf14dU), BSWAP_32BIG_C(0xac838c61U), BSWAP_32BIG_C(0x3d35fda6U),
    };
    r_rsip_func100(Param_pc2f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pc2f_func102_001[] =
        {
            BSWAP_32BIG_C(0xf8e17c5bU), BSWAP_32BIG_C(0xeb3f055fU), BSWAP_32BIG_C(0xd4d20c47U), BSWAP_32BIG_C(
                0x9763c0d2U),
        };
        r_rsip_func102(Param_pc2f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pc2f_func100_002[] =
        {
            BSWAP_32BIG_C(0xb2b1b68bU), BSWAP_32BIG_C(0xe5eeb010U), BSWAP_32BIG_C(0x0669c80cU), BSWAP_32BIG_C(
                0x02935b69U),
        };
        r_rsip_func100(Param_pc2f_func100_002);
        r_rsip_func_sub016(0x810103c0U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        static const uint32_t Param_pc2f_func100_003[] =
        {
            BSWAP_32BIG_C(0x1e5442f7U), BSWAP_32BIG_C(0x57477c26U), BSWAP_32BIG_C(0xdffdd3f3U), BSWAP_32BIG_C(
                0x5cf6e44dU),
        };
        r_rsip_func100(Param_pc2f_func100_003);

        r_rsip_func_sub028(0x00020061U, 0x40000020U, 0x0d00890eU);
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

        static const uint32_t Param_pc2f_func100_004[] =
        {
            BSWAP_32BIG_C(0x2fca3410U), BSWAP_32BIG_C(0xa091cbdcU), BSWAP_32BIG_C(0x2e8d4dd9U), BSWAP_32BIG_C(
                0xaff73664U),
        };
        r_rsip_func100(Param_pc2f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040140U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub019(0x000000a1U, 0x40000020U, 0x0d00880cU);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub019(0x000003c1U, 0x40000020U, 0x0d00890dU);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);

            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1608H, 0x80840006U);
            r_rsip_func_sub001(0x03410011U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000c2U);

            static const uint32_t Param_pc2f_func101_001[] =
            {
                BSWAP_32BIG_C(0x86849b58U), BSWAP_32BIG_C(0x217a910eU), BSWAP_32BIG_C(0xf97aac2aU), BSWAP_32BIG_C(
                    0x7eea2488U),
            };
            r_rsip_func101(Param_pc2f_func101_001);
            r_rsip_func422(InData_Text, iLoop);

            static const uint32_t Param_pc2f_func100_005[] =
            {
                BSWAP_32BIG_C(0xfa07c7d4U), BSWAP_32BIG_C(0x4724d180U), BSWAP_32BIG_C(0x9253a8e2U), BSWAP_32BIG_C(
                    0x765ccfcaU),
            };
            r_rsip_func100(Param_pc2f_func100_005);
            WR1_PROG(REG_1824H, 0x08000045U);
            WR1_PROG(REG_1608H, 0x81040140U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_182CH, 0x40000020U);
            WR1_PROG(REG_1824H, 0x0d00890dU);
            WR1_PROG(REG_1608H, 0x81840007U);
            r_rsip_func_sub001(0x00490011U);

            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000c2U);

            static const uint32_t Param_pc2f_func101_002[] =
            {
                BSWAP_32BIG_C(0xf8e7e138U), BSWAP_32BIG_C(0xf6492db4U), BSWAP_32BIG_C(0x4ac79170U), BSWAP_32BIG_C(
                    0x128c38e2U),
            };
            r_rsip_func101(Param_pc2f_func101_002);
            r_rsip_func423(OutData_Text, iLoop);

            static const uint32_t Param_pc2f_func101_003[] =
            {
                BSWAP_32BIG_C(0x829d5553U), BSWAP_32BIG_C(0xc2cf0baeU), BSWAP_32BIG_C(0xe303b324U), BSWAP_32BIG_C(
                    0xb737b6f8U),
            };
            r_rsip_func101(Param_pc2f_func101_003);
        }

        static const uint32_t Param_pc2f_func102_002[] =
        {
            BSWAP_32BIG_C(0x9d25dfb7U), BSWAP_32BIG_C(0x5a17938fU), BSWAP_32BIG_C(0x0ea6cda6U), BSWAP_32BIG_C(
                0xc571ca1fU),
        };
        r_rsip_func102(Param_pc2f_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
