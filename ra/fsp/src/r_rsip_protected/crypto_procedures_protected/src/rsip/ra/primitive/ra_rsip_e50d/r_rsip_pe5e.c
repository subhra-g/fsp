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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t InData_EncMsgLength[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;

    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
    WR1_PROG(REG_1420H, InData_EncMsgLength[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000d08U, 0x00A60000U);

    static const uint32_t Param_pe5e_func100_001[] =
    {
        BSWAP_32BIG_C(0xb1896bd9U), BSWAP_32BIG_C(0xa91c0f26U), BSWAP_32BIG_C(0xaeb0a8bfU), BSWAP_32BIG_C(0x94a1395aU),
    };
    r_rsip_func100(Param_pe5e_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x800103a0U, 0x0000e503U);

        static const uint32_t Param_pe5e_func101_001[] =
        {
            BSWAP_32BIG_C(0xc12bffadU), BSWAP_32BIG_C(0xefa1a2b5U), BSWAP_32BIG_C(0x993f55fcU), BSWAP_32BIG_C(
                0x4613e8deU),
        };
        r_rsip_func101(Param_pe5e_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01799093U);

        r_rsip_func_sub003(0x800103a0U, 0x0000e503U);

        static const uint32_t Param_pe5e_func101_002[] =
        {
            BSWAP_32BIG_C(0xfbda1c8aU), BSWAP_32BIG_C(0x5b3a2b82U), BSWAP_32BIG_C(0x0231fbb2U), BSWAP_32BIG_C(
                0x1df93cb9U),
        };
        r_rsip_func101(Param_pe5e_func101_002);
        r_rsip_func044();

        WAIT_STS(REG_2030H, 0, 1);

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        r_rsip_func_sub020(0x000000a1U, 0x08000044U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub020(0x000000a1U, 0x08000054U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

        r_rsip_func_sub003(0x800103a0U, 0x0000e501U);

        static const uint32_t Param_pe5e_func101_003[] =
        {
            BSWAP_32BIG_C(0xa258d38fU), BSWAP_32BIG_C(0x94adbc0dU), BSWAP_32BIG_C(0x74a32a5fU), BSWAP_32BIG_C(
                0x143659e2U),
        };
        r_rsip_func101(Param_pe5e_func101_003);
        r_rsip_func103();

        static const uint32_t Param_pe5e_func100_002[] =
        {
            BSWAP_32BIG_C(0xab76a25eU), BSWAP_32BIG_C(0xc89af2bfU), BSWAP_32BIG_C(0xc2c770ecU), BSWAP_32BIG_C(
                0x6a6ca66aU),
        };
        r_rsip_func100(Param_pe5e_func100_002);
        r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

        static const uint32_t Param_pe5e_func100_003[] =
        {
            BSWAP_32BIG_C(0x3027a54bU), BSWAP_32BIG_C(0xb93d2d09U), BSWAP_32BIG_C(0x4a9c61ccU), BSWAP_32BIG_C(
                0xd3a79ac9U),
        };
        r_rsip_func100(Param_pe5e_func100_003);
        r_rsip_func_sub016(0x81010100U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        OFS_ADR  = S_RAM[0];

        r_rsip_func_sub021(0x0000a900U, 0x00000002U, 0x00026908U, 0x00000929U);

        for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
        {
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_EncMsg[1 + iLoop]);

            static const uint32_t Param_pe5e_func100_004[] =
            {
                BSWAP_32BIG_C(0x0804c50cU), BSWAP_32BIG_C(0x1336dbb5U), BSWAP_32BIG_C(0xa981bc60U), BSWAP_32BIG_C(
                    0xbe7903a7U),
            };
            r_rsip_func100(Param_pe5e_func100_004);
            WR1_PROG(REG_1824H, 0xe7040d05U);
            r_rsip_func_sub001(0x00420011U);
            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &S_HEAP[iLoop]);

            WR1_PROG(REG_1600H, 0x00002d20U);

            static const uint32_t Param_pe5e_func101_004[] =
            {
                BSWAP_32BIG_C(0x3ac3c074U), BSWAP_32BIG_C(0x51e374b3U), BSWAP_32BIG_C(0xb929cf87U), BSWAP_32BIG_C(
                    0x26464566U),
            };
            r_rsip_func101(Param_pe5e_func101_004);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000909U);

        static const uint32_t Param_pe5e_func100_005[] =
        {
            BSWAP_32BIG_C(0x11f013b6U), BSWAP_32BIG_C(0xd6573539U), BSWAP_32BIG_C(0xbe2315baU), BSWAP_32BIG_C(
                0x2ceaac82U),
        };
        r_rsip_func100(Param_pe5e_func100_005);
        r_rsip_func_sub020(0x000000a1U, 0x0c000104U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1824H, 0x09140105U);
        r_rsip_func_sub001(0x00410011U);

        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &S_HEAP[iLoop]);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_pe5e_func100_006[] =
        {
            BSWAP_32BIG_C(0x0c8ea856U), BSWAP_32BIG_C(0x41a67e36U), BSWAP_32BIG_C(0xb14d5042U), BSWAP_32BIG_C(
                0xcadf5d71U),
        };
        r_rsip_func100(Param_pe5e_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe5e_func101_005[] =
            {
                BSWAP_32BIG_C(0xd025a147U), BSWAP_32BIG_C(0xc746a03dU), BSWAP_32BIG_C(0xbefde3feU), BSWAP_32BIG_C(
                    0x758aaa01U),
            };
            r_rsip_func101(Param_pe5e_func101_005);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub020(0x000000a1U, 0x08000044U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub020(0x000000a1U, 0x08000054U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

            r_rsip_func_sub006(0x3800a900U, 0x00000005U, 0x00260000U);

            static const uint32_t Param_pe5e_func100_007[] =
            {
                BSWAP_32BIG_C(0xd72edd61U), BSWAP_32BIG_C(0x0a711c0fU), BSWAP_32BIG_C(0x19cb9fd1U), BSWAP_32BIG_C(
                    0xb25bddbcU),
            };
            r_rsip_func100(Param_pe5e_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000929U);

                for (iLoop = 0U; iLoop < S_RAM[0] - 9; )
                {
                    r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                    WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                    r_rsip_func_sub001(0x01410011U);

                    WR1_PROG(REG_1600H, 0x00002d20U);

                    static const uint32_t Param_pe5e_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x0dab4927U), BSWAP_32BIG_C(0xd02d1833U), BSWAP_32BIG_C(0x518a5a85U),
                        BSWAP_32BIG_C(0x4cdc3d6aU),
                    };
                    r_rsip_func101(Param_pe5e_func101_006);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x000037e8U);
                r_rsip_func_sub006(0x000033e0U, 0x38000be9U, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                r_rsip_func_sub001(0x01410005U);
                r_rsip_func_sub001(0x0001000dU);

                iLoop = iLoop + 4;

                static const uint32_t Param_pe5e_func101_007[] =
                {
                    BSWAP_32BIG_C(0x57043d22U), BSWAP_32BIG_C(0xa0d5491aU), BSWAP_32BIG_C(0x66f0e4bfU), BSWAP_32BIG_C(
                        0x168a271eU),
                };
                r_rsip_func101(Param_pe5e_func101_007);
            }
            else
            {
                WR1_PROG(REG_1600H, 0x00000929U);

                for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
                {
                    r_rsip_func_sub020(0x000003c1U, 0xf7040d05U);
                    WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);
                    r_rsip_func_sub001(0x01410011U);

                    WR1_PROG(REG_1600H, 0x00002d20U);

                    static const uint32_t Param_pe5e_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x942bfd40U), BSWAP_32BIG_C(0x6607090aU), BSWAP_32BIG_C(0x9dd1a346U),
                        BSWAP_32BIG_C(0x128d6cb2U),
                    };
                    r_rsip_func101(Param_pe5e_func101_008);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x38000909U);

                static const uint32_t Param_pe5e_func101_009[] =
                {
                    BSWAP_32BIG_C(0x5df4da92U), BSWAP_32BIG_C(0x093b4a45U), BSWAP_32BIG_C(0x6148ead7U), BSWAP_32BIG_C(
                        0x6a6ad0c5U),
                };
                r_rsip_func101(Param_pe5e_func101_009);
            }

            r_rsip_func_sub020(0x000003c1U, 0x07040d05U);
            WR4_ADDR(REG_1420H, &S_HEAP[iLoop]);

            WR1_PROG(REG_1824H, 0x8c100005U);
            r_rsip_func_sub001(0x00410011U);

            static const uint32_t Param_pe5e_func100_008[] =
            {
                BSWAP_32BIG_C(0xfd9d845cU), BSWAP_32BIG_C(0xc4400d41U), BSWAP_32BIG_C(0x0b42e199U), BSWAP_32BIG_C(
                    0x77133469U),
            };
            r_rsip_func100(Param_pe5e_func100_008);

            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_pe5e_func101_010[] =
            {
                BSWAP_32BIG_C(0x5510ea78U), BSWAP_32BIG_C(0x12d5fdceU), BSWAP_32BIG_C(0x30e3f9a1U), BSWAP_32BIG_C(
                    0xdd405250U),
            };
            r_rsip_func101(Param_pe5e_func101_010);

            return RSIP_RET_PASS;
        }
    }
    else
    {
        static const uint32_t Param_pe5e_func101_011[] =
        {
            BSWAP_32BIG_C(0x7be6d59aU), BSWAP_32BIG_C(0x660960d3U), BSWAP_32BIG_C(0x1385e7fdU), BSWAP_32BIG_C(
                0x1f28b2a5U),
        };
        r_rsip_func101(Param_pe5e_func101_011);

        return RSIP_RET_PASS;
    }
}
