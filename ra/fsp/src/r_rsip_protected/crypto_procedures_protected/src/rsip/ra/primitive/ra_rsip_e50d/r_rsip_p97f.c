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

rsip_ret_t r_rsip_p97f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[],
                        uint32_t       MAX_CNT)
{
    uint32_t iLoop = 0U;

    static const uint32_t Param_p97f_func100_001[] =
    {
        BSWAP_32BIG_C(0x4f97827cU), BSWAP_32BIG_C(0x3197bb3bU), BSWAP_32BIG_C(0xbf3cb88dU), BSWAP_32BIG_C(0xfefa1498U),
    };
    r_rsip_func100(Param_p97f_func100_001);

    r_rsip_func_sub010(0x000000c7U, 0x80010020U);
    WR1_PROG(REG_1420H, MAX_CNT);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    static const uint32_t Param_p97f_func100_002[] =
    {
        BSWAP_32BIG_C(0x39004fa3U), BSWAP_32BIG_C(0xce9d2ef8U), BSWAP_32BIG_C(0x6fa63133U), BSWAP_32BIG_C(0x59d92bd9U),
    };
    r_rsip_func100(Param_p97f_func100_002);

    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);

    for (iLoop = 0U; iLoop < (S_RAM[0] & 0xfffffff0U); )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Text[iLoop]);
        WAIT_STS(REG_1408H, 30, 1);
        RD16_ADDR(REG_1420H, &OutData_Text[iLoop]);
        iLoop = iLoop + 16U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop++)
    {
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001c00U);

    static const uint32_t Param_p97f_func100_003[] =
    {
        BSWAP_32BIG_C(0x98bc0b8dU), BSWAP_32BIG_C(0x7e4ef363U), BSWAP_32BIG_C(0x33c4b477U), BSWAP_32BIG_C(0x4a376644U),
    };
    r_rsip_func100(Param_p97f_func100_003);
    r_rsip_func_sub021(0x00008c20U, 0x0000000fU, 0x38000c21U, 0x1000b420U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub016(0x81010020U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    for (iLoop = S_RAM[0]; iLoop < 16U; iLoop++)
    {
        r_rsip_func_sub001(0x00070005U);

        WR1_PROG(REG_1600H, 0x00002c20U);

        static const uint32_t Param_p97f_func101_001[] =
        {
            BSWAP_32BIG_C(0x256b027eU), BSWAP_32BIG_C(0x4b4d1e0dU), BSWAP_32BIG_C(0x562ec933U), BSWAP_32BIG_C(
                0x8a688078U),
        };
        r_rsip_func101(Param_p97f_func101_001);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub006(0x38008820U, 0x00000010U, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97f_func100_004[] =
    {
        BSWAP_32BIG_C(0xe26ae406U), BSWAP_32BIG_C(0xba7cdf8bU), BSWAP_32BIG_C(0x893931eeU), BSWAP_32BIG_C(0x3a0b0cfaU),
    };
    r_rsip_func100(Param_p97f_func100_004);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97f_func100_005[] =
        {
            BSWAP_32BIG_C(0x4a95c84eU), BSWAP_32BIG_C(0x374f1582U), BSWAP_32BIG_C(0x15a50a87U), BSWAP_32BIG_C(
                0x4dc391a0U),
        };
        r_rsip_func100(Param_p97f_func100_005);
        WR1_PROG(REG_1408H, 0x00007012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_DataT[0]);

        static const uint32_t Param_p97f_func102_001[] =
        {
            BSWAP_32BIG_C(0x71451674U), BSWAP_32BIG_C(0xcbb808b9U), BSWAP_32BIG_C(0x5f43c4d7U), BSWAP_32BIG_C(
                0x2eb0afd4U),
        };
        r_rsip_func102(Param_p97f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_DataT[0]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00870011U);

        static const uint32_t Param_p97f_func100_006[] =
        {
            BSWAP_32BIG_C(0x4e1c6d4cU), BSWAP_32BIG_C(0xc717b102U), BSWAP_32BIG_C(0x048163adU), BSWAP_32BIG_C(
                0x87fed261U),
        };
        r_rsip_func100(Param_p97f_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97f_func102_002[] =
            {
                BSWAP_32BIG_C(0x353c4e40U), BSWAP_32BIG_C(0x67102343U), BSWAP_32BIG_C(0x9510403eU), BSWAP_32BIG_C(
                    0x09cf7499U),
            };
            r_rsip_func102(Param_p97f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p97f_func102_003[] =
            {
                BSWAP_32BIG_C(0x9080c024U), BSWAP_32BIG_C(0x817ac5c7U), BSWAP_32BIG_C(0x9083bb66U), BSWAP_32BIG_C(
                    0x20f1b82aU),
            };
            r_rsip_func102(Param_p97f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
