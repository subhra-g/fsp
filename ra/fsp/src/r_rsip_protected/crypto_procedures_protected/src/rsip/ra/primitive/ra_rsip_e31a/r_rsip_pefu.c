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

rsip_ret_t r_rsip_pefu (const uint32_t InData_Msg1[],
                        const uint32_t InData_Msg1Length[],
                        const uint32_t InData_EncMsg[],
                        const uint32_t InData_EncMsgLength[],
                        const uint32_t InData_Msg2[],
                        const uint32_t InData_Msg2Length[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub014(0x000002c7U, 0x80030060U);
    WR1_PROG(REG_002CH, InData_Msg1Length[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_Msg2Length[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub010(0x38008c60U, 0xfffffffeU, 0x00A70000U);

    r_rsip_func_sub022(0x00000821U, 0x00002423U, 0x00002424U);
    WR1_PROG(REG_0094H, 0x00002425U);

    static const uint32_t Param_pefu_func100_001[] =
    {
        BSWAP_32BIG_C(0xff64a057U), BSWAP_32BIG_C(0x86cee4b4U), BSWAP_32BIG_C(0xc91b36fdU), BSWAP_32BIG_C(0x0a6f1e13U),
    };
    r_rsip_func100(Param_pefu_func100_001);
    WR1_PROG(REG_0094H, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        r_rsip_func_sub010(0x38008c80U, 0xfffffff7U, 0x00A70000U);

        r_rsip_func_sub010(0x38008c20U, 0x0000000fU, 0x00A70000U);

        static const uint32_t Param_pefu_func101_001[] =
        {
            BSWAP_32BIG_C(0xe6bfbc10U), BSWAP_32BIG_C(0xaaceb13eU), BSWAP_32BIG_C(0x807481a9U), BSWAP_32BIG_C(
                0xbd688306U),
        };
        r_rsip_func101(Param_pefu_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        r_rsip_func_sub010(0x38008c80U, 0xfffffff3U, 0x00A70000U);

        r_rsip_func_sub010(0x38008c20U, 0x0000001fU, 0x00A70000U);

        static const uint32_t Param_pefu_func101_002[] =
        {
            BSWAP_32BIG_C(0xdac1d33dU), BSWAP_32BIG_C(0x286928afU), BSWAP_32BIG_C(0x544cd454U), BSWAP_32BIG_C(
                0xe5d49026U),
        };
        r_rsip_func101(Param_pefu_func101_002);
    }

    static const uint32_t Param_pefu_func100_002[] =
    {
        BSWAP_32BIG_C(0xa8f4fd74U), BSWAP_32BIG_C(0xc4156e06U), BSWAP_32BIG_C(0xd26d034bU), BSWAP_32BIG_C(0x497b9f2dU),
    };
    r_rsip_func100(Param_pefu_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pefu_func102_001[] =
        {
            BSWAP_32BIG_C(0x1c728a35U), BSWAP_32BIG_C(0x0ed0200dU), BSWAP_32BIG_C(0xb2840e39U), BSWAP_32BIG_C(
                0x1218f1b4U),
        };
        r_rsip_func102(Param_pefu_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00000821U);

        r_rsip_func_sub010(0x00003405U, 0x38000c84U, 0x00A70000U);

        static const uint32_t Param_pefu_func100_003[] =
        {
            BSWAP_32BIG_C(0x0fc045faU), BSWAP_32BIG_C(0x7a6dc5afU), BSWAP_32BIG_C(0xc2fee67cU), BSWAP_32BIG_C(
                0x8555fb20U),
        };
        r_rsip_func100(Param_pefu_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x00003847U);

            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            static const uint32_t Param_pefu_func100_004[] =
            {
                BSWAP_32BIG_C(0x9c5cac86U), BSWAP_32BIG_C(0x5072f33dU), BSWAP_32BIG_C(0x3adab18eU), BSWAP_32BIG_C(
                    0x541d1eadU),
            };
            r_rsip_func100(Param_pefu_func100_004);
            WR1_PROG(REG_0094H, 0x00007c02U);
            WR1_PROG(REG_0040H, 0x00600000U);

            if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
            {
                static const uint32_t Param_pefu_sub100_001[] =
                {
                    BSWAP_32BIG_C(0x0000ef01U), BSWAP_32BIG_C(0xd4f51a01U), BSWAP_32BIG_C(0xc51c5c8eU),
                    BSWAP_32BIG_C(0x35f2fd69U),
                    BSWAP_32BIG_C(0x934175faU), BSWAP_32BIG_C(0x0000ef01U), BSWAP_32BIG_C(0x6a6f76ddU),
                    BSWAP_32BIG_C(0x6f46bb68U),
                    BSWAP_32BIG_C(0x34c3cbd6U),
                    BSWAP_32BIG_C(0x5453a632U), 0x00001404U,
                };
                r_rsip_func_sub100(InData_EncMsg, Param_pefu_sub100_001, RSIP_SEL_BIT_LENGTH_256);

                static const uint32_t Param_pefu_func101_003[] =
                {
                    BSWAP_32BIG_C(0xbaca535aU), BSWAP_32BIG_C(0x2a07944eU), BSWAP_32BIG_C(0x3cf254efU), BSWAP_32BIG_C(
                        0xead2e502U),
                };
                r_rsip_func101(Param_pefu_func101_003);
            }
            else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
            {
                static const uint32_t Param_pefu_sub100_002[] =
                {
                    BSWAP_32BIG_C(0x0000ef02U), BSWAP_32BIG_C(0x39c5d7fbU), BSWAP_32BIG_C(0xa089ad07U),
                    BSWAP_32BIG_C(0x33150623U),
                    BSWAP_32BIG_C(0xea1ef341U), BSWAP_32BIG_C(0x0000ef02U), BSWAP_32BIG_C(0x543732eeU),
                    BSWAP_32BIG_C(0x62443bdfU),
                    BSWAP_32BIG_C(0x9f3912dcU),
                    BSWAP_32BIG_C(0x82e3da77U), 0x00009406U,
                };
                r_rsip_func_sub100(InData_EncMsg, Param_pefu_sub100_002, RSIP_SEL_BIT_LENGTH_384);

                static const uint32_t Param_pefu_func101_004[] =
                {
                    BSWAP_32BIG_C(0xd27ece6cU), BSWAP_32BIG_C(0x7c96092aU), BSWAP_32BIG_C(0xece0fa66U), BSWAP_32BIG_C(
                        0xd2589e09U),
                };
                r_rsip_func101(Param_pefu_func101_004);
            }

            static const uint32_t Param_pefu_func100_005[] =
            {
                BSWAP_32BIG_C(0x8754f038U), BSWAP_32BIG_C(0x826eae1aU), BSWAP_32BIG_C(0xac79b134U), BSWAP_32BIG_C(
                    0x96c972cfU),
            };
            r_rsip_func100(Param_pefu_func100_005);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0094H, 0x00002c20U);
                static const uint32_t Param_pefu_func101_005[] =
                {
                    BSWAP_32BIG_C(0x9cb09171U), BSWAP_32BIG_C(0x156f8362U), BSWAP_32BIG_C(0x0938168eU), BSWAP_32BIG_C(
                        0xea6e0a09U),
                };
                r_rsip_func101(Param_pefu_func101_005);
            }

            static const uint32_t Param_pefu_func101_006[] =
            {
                BSWAP_32BIG_C(0xe0f69c2bU), BSWAP_32BIG_C(0xe463b145U), BSWAP_32BIG_C(0x67c022ccU), BSWAP_32BIG_C(
                    0x269b75e5U),
            };
            r_rsip_func101(Param_pefu_func101_006);
        }

        r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_pefu_func100_006[] =
        {
            BSWAP_32BIG_C(0x1c3894f0U), BSWAP_32BIG_C(0x60ebf507U), BSWAP_32BIG_C(0x53d67cc8U), BSWAP_32BIG_C(
                0x98ff88aeU),
        };
        r_rsip_func100(Param_pefu_func100_006);
        WR1_PROG(REG_0040H, 0x00400000U);
        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pefu_func102_002[] =
            {
                BSWAP_32BIG_C(0x87d2ca05U), BSWAP_32BIG_C(0xaaadac9bU), BSWAP_32BIG_C(0xd75e727fU), BSWAP_32BIG_C(
                    0xd40fddd3U),
            };
            r_rsip_func102(Param_pefu_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub022(0x0000b4e0U, 0x00000010U, 0x000038a7U);

            WAIT_STS(REG_0118H, 0, 1);

            r_rsip_func_sub016(0x38000c63U, 0x00000080U, 0x00A70000U);

            static const uint32_t Param_pefu_func100_007[] =
            {
                BSWAP_32BIG_C(0xdaffde07U), BSWAP_32BIG_C(0x139d2a67U), BSWAP_32BIG_C(0xb326f3b7U), BSWAP_32BIG_C(
                    0xae3e968dU),
            };
            r_rsip_func100(Param_pefu_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                WR1_PROG(REG_0014H, 0x000000c4U);
                WAIT_STS(REG_0014H, 31, 1);
                WR1_PROG(REG_002CH, InData_Msg1[0]);

                static const uint32_t Param_pefu_func101_007[] =
                {
                    BSWAP_32BIG_C(0xdda53785U), BSWAP_32BIG_C(0xd002c26eU), BSWAP_32BIG_C(0xc1951870U), BSWAP_32BIG_C(
                        0xc096d2e7U),
                };
                r_rsip_func101(Param_pefu_func101_007);
            }

            r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00A70000U);

            static const uint32_t Param_pefu_func100_008[] =
            {
                BSWAP_32BIG_C(0x0ddbdd28U), BSWAP_32BIG_C(0x2df72907U), BSWAP_32BIG_C(0x8d3ecaeeU), BSWAP_32BIG_C(
                    0xaf02c042U),
            };
            r_rsip_func100(Param_pefu_func100_008);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pefu_func100_009[] =
                {
                    BSWAP_32BIG_C(0x91f34d74U), BSWAP_32BIG_C(0x59ba81e9U), BSWAP_32BIG_C(0x9d43b1e5U), BSWAP_32BIG_C(
                        0x6e073eccU),
                };
                r_rsip_func100(Param_pefu_func100_009);

                WR1_PROG(REG_0094H, 0x00007c05U);
                WR1_PROG(REG_0040H, 0x00600000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    r_rsip_func_sub009(0x00001804U, 0x01430021U, 0x00001800U);

                    static const uint32_t Param_pefu_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x47b5ed69U), BSWAP_32BIG_C(0xcc01986cU), BSWAP_32BIG_C(0x03e4615bU),
                        BSWAP_32BIG_C(0xe4bb10f3U),
                    };
                    r_rsip_func101(Param_pefu_func101_008);
                }
                else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
                {
                    r_rsip_func_sub009(0x00009806U, 0x01430031U, 0x00001800U);

                    static const uint32_t Param_pefu_func101_009[] =
                    {
                        BSWAP_32BIG_C(0xb5412875U), BSWAP_32BIG_C(0x6dd29a68U), BSWAP_32BIG_C(0xdb53f414U),
                        BSWAP_32BIG_C(0x94f91be1U),
                    };
                    r_rsip_func101(Param_pefu_func101_009);
                }

                static const uint32_t Param_pefu_func101_010[] =
                {
                    BSWAP_32BIG_C(0xa30c561fU), BSWAP_32BIG_C(0x7cd03c08U), BSWAP_32BIG_C(0xb6789f13U), BSWAP_32BIG_C(
                        0x92392fd7U),
                };
                r_rsip_func101(Param_pefu_func101_010);
            }

            static const uint32_t Param_pefu_func100_010[] =
            {
                BSWAP_32BIG_C(0x483e7c36U), BSWAP_32BIG_C(0xa7e0e24eU), BSWAP_32BIG_C(0x6872fc41U), BSWAP_32BIG_C(
                    0x47373fa2U),
            };
            r_rsip_func100(Param_pefu_func100_010);

            r_rsip_func_sub017(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_0014H, 0x00020064U);

            WAIT_STS(REG_0014H, 31, 1);
            for (iLoop = 0; iLoop < (S_RAM[0] & 0x0000000fU); iLoop++)
            {
                WR1_PROG(REG_002CH, InData_Msg2[iLoop]);
            }

            WAIT_STS(REG_0014H, 31, 1);
            for (iLoop = (S_RAM[0] & 0x0000000fU); iLoop < S_RAM[0]; )
            {
                WAIT_STS(REG_0014H, 31, 1);
                WR16_ADDR(REG_002CH, &InData_Msg2[iLoop]);
                iLoop = iLoop + 16U;
            }

            WR1_PROG(REG_0014H, 0x00000000U);
            WAIT_STS(REG_0118H, 8, 0);
            WR1_PROG(REG_0040H, 0x00001600U);

            r_rsip_func_sub022(0x0000b420U, 0x00000010U, 0x00003801U);

            static const uint32_t Param_pefu_func101_011[] =
            {
                BSWAP_32BIG_C(0xf15bb351U), BSWAP_32BIG_C(0x70c1d967U), BSWAP_32BIG_C(0xc97ac4c8U), BSWAP_32BIG_C(
                    0x41f582c9U),
            };
            r_rsip_func101(Param_pefu_func101_011);

            return RSIP_RET_PASS;
        }
    }
}
