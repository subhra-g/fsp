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

rsip_ret_t r_rsip_p2b (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x002b0001U, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub008(0x00002fa2U, 0x00000b00U, 0x08008107U);
        WR4_PROG(REG_1420H, bswap_32big(0x00030005U), bswap_32big(0x0007000bU), bswap_32big(0x000d0011U),
                 bswap_32big(0x00130017U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x001d001fU), bswap_32big(0x00250029U), bswap_32big(0x002b002fU),
                 bswap_32big(0x003b003dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00430047U), bswap_32big(0x0049004fU), bswap_32big(0x00530059U),
                 bswap_32big(0x00610065U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x0067006bU), bswap_32big(0x006d0071U), bswap_32big(0x007f0083U),
                 bswap_32big(0x0089008bU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00950097U), bswap_32big(0x009d00a3U), bswap_32big(0x00a700adU),
                 bswap_32big(0x00b300b5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00bf00c1U), bswap_32big(0x00c500c7U), bswap_32big(0x00d300dfU),
                 bswap_32big(0x00e300e5U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x00e900efU), bswap_32big(0x00f100fbU), bswap_32big(0x01010107U),
                 bswap_32big(0x010d010fU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01150119U), bswap_32big(0x011b0125U), bswap_32big(0x01330137U),
                 bswap_32big(0x0139013dU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x014b0151U), bswap_32big(0x015b015dU), bswap_32big(0x01610167U),
                 bswap_32big(0x016f0175U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x017b017fU), bswap_32big(0x0185018dU), bswap_32big(0x01910199U),
                 bswap_32big(0x01a301a5U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01af01b1U), bswap_32big(0x01b701bbU), bswap_32big(0x01c101c9U),
                 bswap_32big(0x01cd01cfU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x01d301dfU), bswap_32big(0x01e701ebU), bswap_32big(0x01f301f7U),
                 bswap_32big(0x01fd0000U));
        r_rsip_func_sub001(0x00c20031U);

        r_rsip_func_sub023(0x0000b4c0U, 0x00000080U, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x034300c1U);

        WR1_PROG(REG_1404H, 0x10180000U);
        r_rsip_func_sub001(0x00c00209U);

        r_rsip_func_sub003(0x800103a0U, 0x00002b01U);

        static const uint32_t Param_p2b_func101_001[] =
        {
            BSWAP_32BIG_C(0xbb530268U), BSWAP_32BIG_C(0x86be24bdU), BSWAP_32BIG_C(0x31100f57U), BSWAP_32BIG_C(
                0x2e89b1ccU),
        };
        r_rsip_func101(Param_p2b_func101_001);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11a00000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000018U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 24U; )
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub003(0x800103a0U, 0x00002b02U);

            static const uint32_t Param_p2b_func101_002[] =
            {
                BSWAP_32BIG_C(0xc36ab3dfU), BSWAP_32BIG_C(0xe8556e28U), BSWAP_32BIG_C(0x20fa6b9cU), BSWAP_32BIG_C(
                    0xea48406aU),
            };
            r_rsip_func101(Param_p2b_func101_002);
            r_rsip_func113();
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p2b_func101_003[] =
            {
                BSWAP_32BIG_C(0xb252d49aU), BSWAP_32BIG_C(0x6b5f12c9U), BSWAP_32BIG_C(0xd96b0aedU), BSWAP_32BIG_C(
                    0x5808c2e4U),
            };
            r_rsip_func101(Param_p2b_func101_003);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub003(0x800103a0U, 0x00002b03U);

        static const uint32_t Param_p2b_func101_004[] =
        {
            BSWAP_32BIG_C(0x637b82fbU), BSWAP_32BIG_C(0xf5506346U), BSWAP_32BIG_C(0x825ed69bU), BSWAP_32BIG_C(
                0xf8143d90U),
        };
        r_rsip_func101(Param_p2b_func101_004);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub008(0x00001fa2U, 0x00000700U, 0x08008107U);
        WR4_PROG(REG_1420H, bswap_32big(0xB51EB851U), bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU),
                 bswap_32big(0xB851EB85U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U),
                 bswap_32big(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U),
                 bswap_32big(0xEB851EB8U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x51EB851EU), bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU),
                 bswap_32big(0x851EB851U));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU), bswap_32big(0xB851EB85U),
                 bswap_32big(0x1EB851EBU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U), bswap_32big(0x51EB851EU),
                 bswap_32big(0xB851EB85U));
        r_rsip_func_sub001(0x00c20031U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U), bswap_32big(0xEB851EB8U),
                 bswap_32big(0x51EB851EU));
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0xB851EB85U), bswap_32big(0x1EB851EBU), bswap_32big(0x851EB851U),
                 bswap_32big(0xEB851B5CU));
        r_rsip_func_sub001(0x00c20021U);

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p2b_func100_001[] =
        {
            BSWAP_32BIG_C(0x8e46c456U), BSWAP_32BIG_C(0xb0ad90cfU), BSWAP_32BIG_C(0x432af280U), BSWAP_32BIG_C(
                0xc6361c70U),
        };
        r_rsip_func100(Param_p2b_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_005[] =
            {
                BSWAP_32BIG_C(0xbb3f0232U), BSWAP_32BIG_C(0x4a30784bU), BSWAP_32BIG_C(0x087a4415U), BSWAP_32BIG_C(
                    0x255bb714U),
            };
            r_rsip_func101(Param_p2b_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p2b_func101_006[] =
            {
                BSWAP_32BIG_C(0xd8d31c1eU), BSWAP_32BIG_C(0xe481e37bU), BSWAP_32BIG_C(0x4a2fdbcbU), BSWAP_32BIG_C(
                    0xdba2085eU),
            };
            r_rsip_func101(Param_p2b_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p2b_func100_002[] =
        {
            BSWAP_32BIG_C(0x82623a48U), BSWAP_32BIG_C(0x360943b0U), BSWAP_32BIG_C(0x86cb9003U), BSWAP_32BIG_C(
                0x90c5e7f1U),
        };
        r_rsip_func100(Param_p2b_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_003[] =
            {
                BSWAP_32BIG_C(0xebfc321dU), BSWAP_32BIG_C(0x69e6ac74U), BSWAP_32BIG_C(0xcfc75ad5U), BSWAP_32BIG_C(
                    0xa973618fU),
            };
            r_rsip_func100(Param_p2b_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x1010000aU);

                static const uint32_t Param_p2b_func101_007[] =
                {
                    BSWAP_32BIG_C(0x4753c441U), BSWAP_32BIG_C(0x2a4a0092U), BSWAP_32BIG_C(0x7e7c91f6U), BSWAP_32BIG_C(
                        0x4e613a52U),
                };
                r_rsip_func101(Param_p2b_func101_007);
            }
            else
            {
                static const uint32_t Param_p2b_func101_008[] =
                {
                    BSWAP_32BIG_C(0x24564178U), BSWAP_32BIG_C(0xf395bcddU), BSWAP_32BIG_C(0xf97bd94fU), BSWAP_32BIG_C(
                        0x8adef143U),
                };
                r_rsip_func101(Param_p2b_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c00071U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_004[] =
            {
                BSWAP_32BIG_C(0xc9b40780U), BSWAP_32BIG_C(0x95b7d3d5U), BSWAP_32BIG_C(0x1d099d15U), BSWAP_32BIG_C(
                    0xfa56ecfcU),
            };
            r_rsip_func100(Param_p2b_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p2b_func101_009[] =
                {
                    BSWAP_32BIG_C(0xa6c844bbU), BSWAP_32BIG_C(0x8f8eb81dU), BSWAP_32BIG_C(0xf26cd015U), BSWAP_32BIG_C(
                        0x42cc6109U),
                };
                r_rsip_func101(Param_p2b_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p2b_func101_010[] =
                {
                    BSWAP_32BIG_C(0x2128cd0bU), BSWAP_32BIG_C(0x3c41b095U), BSWAP_32BIG_C(0x9e32b1aaU), BSWAP_32BIG_C(
                        0x8ff9c54cU),
                };
                r_rsip_func101(Param_p2b_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p2b_func101_011[] =
            {
                BSWAP_32BIG_C(0x7602a5e2U), BSWAP_32BIG_C(0xc8a1ffe8U), BSWAP_32BIG_C(0xa23756c8U), BSWAP_32BIG_C(
                    0x9b19fd78U),
            };
            r_rsip_func101(Param_p2b_func101_011);
        }

        r_rsip_func_sub022(0x0000b4c0U, 0x00000080U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub022(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x14280000U);
            r_rsip_func_sub001(0x00c00209U);

            WR1_PROG(REG_1404H, 0x15b00000U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x10100010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x10100004U, 0x00010201U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19c00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_005[] =
            {
                BSWAP_32BIG_C(0x63524f27U), BSWAP_32BIG_C(0xfa1597c1U), BSWAP_32BIG_C(0x0720b17dU), BSWAP_32BIG_C(
                    0x53c6accbU),
            };
            r_rsip_func100(Param_p2b_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p2b_func101_012[] =
                {
                    BSWAP_32BIG_C(0xbecf55d1U), BSWAP_32BIG_C(0xec6f66cbU), BSWAP_32BIG_C(0x3a6d3108U), BSWAP_32BIG_C(
                        0x4e537c0eU),
                };
                r_rsip_func101(Param_p2b_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p2b_func101_013[] =
                {
                    BSWAP_32BIG_C(0xfe55d5e2U), BSWAP_32BIG_C(0x5d4a9194U), BSWAP_32BIG_C(0x470d9229U), BSWAP_32BIG_C(
                        0xfb1c905cU),
                };
                r_rsip_func101(Param_p2b_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p2b_func100_006[] =
        {
            BSWAP_32BIG_C(0xcdcd1581U), BSWAP_32BIG_C(0x009054c9U), BSWAP_32BIG_C(0xbe572e37U), BSWAP_32BIG_C(
                0x9d8069deU),
        };
        r_rsip_func100(Param_p2b_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_014[] =
            {
                BSWAP_32BIG_C(0xe5940a94U), BSWAP_32BIG_C(0xf443718dU), BSWAP_32BIG_C(0xfe1a3622U), BSWAP_32BIG_C(
                    0xe4ebb2eaU),
            };
            r_rsip_func101(Param_p2b_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18b80000U);
        r_rsip_func_sub001(0x00c00081U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x10100009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);

        WR1_PROG(REG_1404H, 0x14280000U);
        r_rsip_func_sub001(0x00c00209U);

        WR1_PROG(REG_1404H, 0x15b00000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x10100010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x10100004U, 0x00010201U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19c00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0007dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p2b_func100_007[] =
        {
            BSWAP_32BIG_C(0xe9c26dffU), BSWAP_32BIG_C(0x3d99b9fdU), BSWAP_32BIG_C(0xae2d1c34U), BSWAP_32BIG_C(
                0x5407874aU),
        };
        r_rsip_func100(Param_p2b_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p2b_func101_015[] =
            {
                BSWAP_32BIG_C(0x63f068f5U), BSWAP_32BIG_C(0x8611299cU), BSWAP_32BIG_C(0x792ec17dU), BSWAP_32BIG_C(
                    0x5641808bU),
            };
            r_rsip_func101(Param_p2b_func101_015);
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            r_rsip_func_sub001(0x00c00209U);

            static const uint32_t Param_p2b_func100_008[] =
            {
                BSWAP_32BIG_C(0x4d9468cbU), BSWAP_32BIG_C(0xea66de8cU), BSWAP_32BIG_C(0x2b851535U), BSWAP_32BIG_C(
                    0x6b721743U),
            };
            r_rsip_func100(Param_p2b_func100_008);
            WR1_PROG(REG_1404H, 0x17b80000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0007dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub036(0x00000018U, 0x00000428U, 0x10100010U);
            WR1_PROG(REG_1000H, 0x00010001U);
            r_rsip_func_sub007(0x00000838U, 0x00000220U, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);

            WR1_PROG(REG_1004H, 0x10100000U);
            r_rsip_func_sub035(0x00010201U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x1010000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p2b_func100_009[] =
            {
                BSWAP_32BIG_C(0x0d9f8f2bU), BSWAP_32BIG_C(0x094d13f2U), BSWAP_32BIG_C(0xb7594226U), BSWAP_32BIG_C(
                    0x4eae1821U),
            };
            r_rsip_func100(Param_p2b_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p2b_func101_016[] =
                {
                    BSWAP_32BIG_C(0x899c588aU), BSWAP_32BIG_C(0x1bcf9d61U), BSWAP_32BIG_C(0x7dc52458U), BSWAP_32BIG_C(
                        0xea61c5f0U),
                };
                r_rsip_func101(Param_p2b_func101_016);
                continue;
            }

            static const uint32_t Param_p2b_func100_010[] =
            {
                BSWAP_32BIG_C(0xb39e2c0dU), BSWAP_32BIG_C(0x62b67a14U), BSWAP_32BIG_C(0xb17917cdU), BSWAP_32BIG_C(
                    0x1128f2fcU),
            };
            r_rsip_func100(Param_p2b_func100_010);

            r_rsip_func_sub022(0x0000b560U, 0x00000003U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80a0000aU);
            WR1_PROG(REG_1404H, 0x11a00000U);
            r_rsip_func_sub001(0x03430081U);

            r_rsip_func_sub021(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x0000007cU);

            for (iLoop = 0U; iLoop < 32U; iLoop++)
            {
                r_rsip_func_sub022(0x000038e6U, 0x0000a8c0U, 0x00000004U);
                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub021(0x38008900U, 0x00000000U, 0x11816907U, 0x38008900U);
                    r_rsip_func_sub022(0x00000000U, 0x10002d20U, 0x000168e7U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);

            r_rsip_func_sub030(0x15b00000U, 0x0000094aU, 0x81a0000aU);
            r_rsip_func_sub001(0x00c90081U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x1010000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x10100009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p2b_func101_017[] =
                {
                    BSWAP_32BIG_C(0xebe483f9U), BSWAP_32BIG_C(0x7f993974U), BSWAP_32BIG_C(0x03fc5bd1U), BSWAP_32BIG_C(
                        0xd3bbe7d8U),
                };
                r_rsip_func101(Param_p2b_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p2b_func100_011[] =
            {
                BSWAP_32BIG_C(0xdd4e4379U), BSWAP_32BIG_C(0x97e1d8b7U), BSWAP_32BIG_C(0xe6d16aa9U), BSWAP_32BIG_C(
                    0x41b25071U),
            };
            r_rsip_func100(Param_p2b_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x10180000U);
                r_rsip_func_sub001(0x00c00209U);

                r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub031(0x00000020U, 0x000008e7U, 0x11a00000U);
                for (jLoop = 0U; jLoop < 32U; )
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub003(0x800103a0U, 0x00002b04U);

                    static const uint32_t Param_p2b_func101_018[] =
                    {
                        BSWAP_32BIG_C(0xe58d33a0U), BSWAP_32BIG_C(0x7c69bf69U), BSWAP_32BIG_C(0x48559794U),
                        BSWAP_32BIG_C(0xb7f000bbU),
                    };
                    r_rsip_func101(Param_p2b_func101_018);
                    r_rsip_func113();
                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p2b_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x3ba33a78U), BSWAP_32BIG_C(0xc2b5450bU), BSWAP_32BIG_C(0x4346d088U),
                        BSWAP_32BIG_C(0x26d422bbU),
                    };
                    r_rsip_func101(Param_p2b_func101_019);
                    jLoop = jLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p2b_func100_012[] =
                {
                    BSWAP_32BIG_C(0xe2bdd415U), BSWAP_32BIG_C(0xb005ac7dU), BSWAP_32BIG_C(0x9686839fU), BSWAP_32BIG_C(
                        0x6a3391feU),
                };
                r_rsip_func100(Param_p2b_func100_012);
                WR1_PROG(REG_1404H, 0x19c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x1010000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x10100010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x10100004U, 0x00010201U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17b80000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x10100009U);

                r_rsip_func_sub036(0x00000018U, 0x00000428U, 0x10100010U);
                WR1_PROG(REG_1000H, 0x00010001U);
                r_rsip_func_sub007(0x00000220U, 0x00000630U, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);

                WR1_PROG(REG_1004H, 0x10100000U);
                r_rsip_func_sub035(0x00010201U);

                WR1_PROG(REG_1404H, 0x19c00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0007dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p2b_func100_013[] =
                {
                    BSWAP_32BIG_C(0xad7b5a4aU), BSWAP_32BIG_C(0x4251f0ecU), BSWAP_32BIG_C(0xd704ec98U), BSWAP_32BIG_C(
                        0x3fc74685U),
                };
                r_rsip_func100(Param_p2b_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p2b_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x7951c756U), BSWAP_32BIG_C(0x1ba6a758U), BSWAP_32BIG_C(0xc07ee7b5U),
                        BSWAP_32BIG_C(0xfbe04689U),
                    };
                    r_rsip_func101(Param_p2b_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p2b_func100_014[] =
                    {
                        BSWAP_32BIG_C(0x3b2ec828U), BSWAP_32BIG_C(0x96ebf625U), BSWAP_32BIG_C(0x2bcadd21U),
                        BSWAP_32BIG_C(0x4e03f99cU),
                    };
                    r_rsip_func100(Param_p2b_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19c00000U);
                        WR1_PROG(REG_1608H, 0x81a0000aU);
                        r_rsip_func_sub001(0x00c90081U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p2b_func100_015[] =
                        {
                            BSWAP_32BIG_C(0xfb37f76aU), BSWAP_32BIG_C(0xd59daafeU), BSWAP_32BIG_C(0x626e174dU),
                            BSWAP_32BIG_C(0x3e14ba40U),
                        };
                        r_rsip_func100(Param_p2b_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p2b_func101_021[] =
                            {
                                BSWAP_32BIG_C(0x67c4c84eU), BSWAP_32BIG_C(0x41b857d5U), BSWAP_32BIG_C(0xf51dd4ceU),
                                BSWAP_32BIG_C(0xe391a6feU),
                            };
                            r_rsip_func101(Param_p2b_func101_021);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            r_rsip_func_sub001(0x00c00209U);

                            static const uint32_t Param_p2b_func100_016[] =
                            {
                                BSWAP_32BIG_C(0x6684158aU), BSWAP_32BIG_C(0xc9376f6dU), BSWAP_32BIG_C(0x7f62e650U),
                                BSWAP_32BIG_C(0x1acdaa27U),
                            };
                            r_rsip_func100(Param_p2b_func100_016);
                            WR1_PROG(REG_1404H, 0x19c00000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c0007dU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x10100000U,
                                               0x00010201U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x10100009U);

                            static const uint32_t Param_p2b_func101_022[] =
                            {
                                BSWAP_32BIG_C(0xa4ed964fU), BSWAP_32BIG_C(0xabdfb25cU), BSWAP_32BIG_C(0x0c148259U),
                                BSWAP_32BIG_C(0x88080bbcU),
                            };
                            r_rsip_func101(Param_p2b_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p2b_func100_017[] =
                    {
                        BSWAP_32BIG_C(0xd11aadcdU), BSWAP_32BIG_C(0xc24162c2U), BSWAP_32BIG_C(0xe3d87713U),
                        BSWAP_32BIG_C(0xa3763f14U),
                    };
                    r_rsip_func100(Param_p2b_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p2b_func101_023[] =
                        {
                            BSWAP_32BIG_C(0x590b9213U), BSWAP_32BIG_C(0xed101946U), BSWAP_32BIG_C(0xed0fee9cU),
                            BSWAP_32BIG_C(0x21767261U),
                        };
                        r_rsip_func101(Param_p2b_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p2b_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x1d5a9314U), BSWAP_32BIG_C(0x58137212U), BSWAP_32BIG_C(0xcfcc2771U),
                            BSWAP_32BIG_C(0x8c483a24U),
                        };
                        r_rsip_func101(Param_p2b_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p2b_func100_018[] =
            {
                BSWAP_32BIG_C(0x8c869ae5U), BSWAP_32BIG_C(0x10ea9640U), BSWAP_32BIG_C(0xa82e46d7U), BSWAP_32BIG_C(
                    0xc382c209U),
            };
            r_rsip_func100(Param_p2b_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p2b_func100_019[] =
                {
                    BSWAP_32BIG_C(0x258a1fd0U), BSWAP_32BIG_C(0x68c2cd28U), BSWAP_32BIG_C(0x03a73d82U), BSWAP_32BIG_C(
                        0x2c2a1a30U),
                };
                r_rsip_func100(Param_p2b_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p2b_func101_025[] =
                    {
                        BSWAP_32BIG_C(0xa97af9e4U), BSWAP_32BIG_C(0x01e9e11fU), BSWAP_32BIG_C(0xadc04141U),
                        BSWAP_32BIG_C(0x723a5cacU),
                    };
                    r_rsip_func101(Param_p2b_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x10100009U);

                    static const uint32_t Param_p2b_func101_026[] =
                    {
                        BSWAP_32BIG_C(0x8802cba2U), BSWAP_32BIG_C(0xc021b2ffU), BSWAP_32BIG_C(0xf1d4f4a0U),
                        BSWAP_32BIG_C(0xe2ea6b63U),
                    };
                    r_rsip_func101(Param_p2b_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p2b_func101_027[] =
                {
                    BSWAP_32BIG_C(0xacf17654U), BSWAP_32BIG_C(0x5f1bb542U), BSWAP_32BIG_C(0xd5350120U), BSWAP_32BIG_C(
                        0x84f2f020U),
                };
                r_rsip_func101(Param_p2b_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p2b_func100_020[] =
    {
        BSWAP_32BIG_C(0xa87ea8beU), BSWAP_32BIG_C(0xf939b193U), BSWAP_32BIG_C(0x3854dfbcU), BSWAP_32BIG_C(0xbf42173dU),
    };
    r_rsip_func100(Param_p2b_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_001[] =
        {
            BSWAP_32BIG_C(0x07725832U), BSWAP_32BIG_C(0x40764facU), BSWAP_32BIG_C(0x57588b7fU), BSWAP_32BIG_C(
                0x6b18e449U),
        };
        r_rsip_func102(Param_p2b_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub001(0x00c00081U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x10100009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x000007b8U, 0x10100009U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b05U);

    static const uint32_t Param_p2b_func101_028[] =
    {
        BSWAP_32BIG_C(0x5e585107U), BSWAP_32BIG_C(0x21c740b5U), BSWAP_32BIG_C(0xcbed30efU), BSWAP_32BIG_C(0x99ff6045U),
    };
    r_rsip_func101(Param_p2b_func101_028);
    r_rsip_func113();
    static const uint32_t Param_p2b_func100_021[] =
    {
        BSWAP_32BIG_C(0x990e2718U), BSWAP_32BIG_C(0x268d6f56U), BSWAP_32BIG_C(0x97d0fd7fU), BSWAP_32BIG_C(0xd35f02dfU),
    };
    r_rsip_func100(Param_p2b_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x17380000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b01U);

    static const uint32_t Param_p2b_func101_029[] =
    {
        BSWAP_32BIG_C(0x0a0cbac9U), BSWAP_32BIG_C(0xc597808dU), BSWAP_32BIG_C(0x1498d75dU), BSWAP_32BIG_C(0xd3bb1225U),
    };
    r_rsip_func101(Param_p2b_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x1010000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x1010000aU);

    r_rsip_func_sub003(0x800103a0U, 0x0000002bU);

    static const uint32_t Param_p2b_func101_030[] =
    {
        BSWAP_32BIG_C(0x7429725fU), BSWAP_32BIG_C(0xd7677e50U), BSWAP_32BIG_C(0xa55acd14U), BSWAP_32BIG_C(0xedee8c08U),
    };
    r_rsip_func101(Param_p2b_func101_030);
    r_rsip_func052();

    WR1_PROG(REG_1404H, 0x15200000U);
    r_rsip_func_sub001(0x00c00091U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x17380000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b01U);

    static const uint32_t Param_p2b_func101_031[] =
    {
        BSWAP_32BIG_C(0x825ffb2bU), BSWAP_32BIG_C(0x0cc8e2b7U), BSWAP_32BIG_C(0x49549332U), BSWAP_32BIG_C(0x56069029U),
    };
    r_rsip_func101(Param_p2b_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x000007b8U, 0x00000838U, 0x00000220U, 0x10100007U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b01U);

    static const uint32_t Param_p2b_func101_032[] =
    {
        BSWAP_32BIG_C(0xadf847acU), BSWAP_32BIG_C(0x2836ad74U), BSWAP_32BIG_C(0xf0d0f352U), BSWAP_32BIG_C(0x6280e7d5U),
    };
    r_rsip_func101(Param_p2b_func101_032);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p2b_func100_022[] =
    {
        BSWAP_32BIG_C(0xa55dff21U), BSWAP_32BIG_C(0x94ad7ebaU), BSWAP_32BIG_C(0x6aab3825U), BSWAP_32BIG_C(0x012bd1f6U),
    };
    r_rsip_func100(Param_p2b_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_002[] =
        {
            BSWAP_32BIG_C(0x68fd14daU), BSWAP_32BIG_C(0x728b9501U), BSWAP_32BIG_C(0xaca5d927U), BSWAP_32BIG_C(
                0x3873d145U),
        };
        r_rsip_func102(Param_p2b_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x13280000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b02U);

    static const uint32_t Param_p2b_func101_033[] =
    {
        BSWAP_32BIG_C(0xeb36ad34U), BSWAP_32BIG_C(0x3fc0caf7U), BSWAP_32BIG_C(0xdbf5fca9U), BSWAP_32BIG_C(0x023786ccU),
    };
    r_rsip_func101(Param_p2b_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x000003a8U, 0x00000428U, 0x00000630U, 0x10100007U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x15300000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b02U);

    static const uint32_t Param_p2b_func101_034[] =
    {
        BSWAP_32BIG_C(0xc55e11b8U), BSWAP_32BIG_C(0xb8ccdc46U), BSWAP_32BIG_C(0x02f87d20U), BSWAP_32BIG_C(0x04e7b0d2U),
    };
    r_rsip_func101(Param_p2b_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x17280000U);
    r_rsip_func_sub001(0x00c00011U);

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0007dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);

    r_rsip_func_sub002(0x000003a8U, 0x00000a40U, 0x000001a0U, 0x1010000aU);

    r_rsip_func_sub002(0x000001a0U, 0x00000220U, 0x00000428U, 0x10100007U);

    r_rsip_func_sub036(0x00000018U, 0x00000630U, 0x20200010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    r_rsip_func_sub007(0x00000428U, 0x00000838U, 0x00000630U);
    r_rsip_func_sub005(0x00000428U, 0x20200002U, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x20200003U, 0x00010201U);
    r_rsip_func_sub007(0x00000428U, 0x00000220U, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x20200002U, 0x00010201U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x15300000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub003(0x800103a0U, 0x00002b02U);

    static const uint32_t Param_p2b_func101_035[] =
    {
        BSWAP_32BIG_C(0xdc89b916U), BSWAP_32BIG_C(0x589e71e2U), BSWAP_32BIG_C(0x0ca1e88dU), BSWAP_32BIG_C(0x5277c589U),
    };
    r_rsip_func101(Param_p2b_func101_035);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p2b_func100_023[] =
    {
        BSWAP_32BIG_C(0xa5f6927cU), BSWAP_32BIG_C(0xc62797c1U), BSWAP_32BIG_C(0x292a7c7eU), BSWAP_32BIG_C(0xc1cf2ddcU),
    };
    r_rsip_func100(Param_p2b_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p2b_func102_003[] =
        {
            BSWAP_32BIG_C(0xe3bdb8f7U), BSWAP_32BIG_C(0xfd76c5aeU), BSWAP_32BIG_C(0x38779653U), BSWAP_32BIG_C(
                0x95252ecfU),
        };
        r_rsip_func102(Param_p2b_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000428U, 0x20200009U);

    r_rsip_func_sub004(0x0b040184U, 0x820edca6U);

    OFS_ADR = 356;

    r_rsip_func_sub012(0x15300000U, 0x0000b400U, 0x00000040U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b03U);

    static const uint32_t Param_p2b_func101_036[] =
    {
        BSWAP_32BIG_C(0x9f1aa4e4U), BSWAP_32BIG_C(0xed5f8d05U), BSWAP_32BIG_C(0x5a6b230aU), BSWAP_32BIG_C(0x0852a232U),
    };
    r_rsip_func101(Param_p2b_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub003(0x800103a0U, 0x00002b06U);

    static const uint32_t Param_p2b_func101_037[] =
    {
        BSWAP_32BIG_C(0x996c9594U), BSWAP_32BIG_C(0x90cc5f3aU), BSWAP_32BIG_C(0x524b6560U), BSWAP_32BIG_C(0x9d153078U),
    };
    r_rsip_func101(Param_p2b_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000012bU);

    static const uint32_t Param_p2b_func101_038[] =
    {
        BSWAP_32BIG_C(0xed1cda30U), BSWAP_32BIG_C(0x334686bdU), BSWAP_32BIG_C(0x816bf3b7U), BSWAP_32BIG_C(0x43377c39U),
    };
    r_rsip_func101(Param_p2b_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000dU);

    r_rsip_func_sub003(0x800103a0U, 0x0000012bU);

    static const uint32_t Param_p2b_func101_039[] =
    {
        BSWAP_32BIG_C(0x664d989aU), BSWAP_32BIG_C(0x52909cefU), BSWAP_32BIG_C(0x21909a2cU), BSWAP_32BIG_C(0x7ce84d7fU),
    };
    r_rsip_func101(Param_p2b_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_024[] =
        {
            BSWAP_32BIG_C(0xf2ca3e59U), BSWAP_32BIG_C(0x09038dc1U), BSWAP_32BIG_C(0x0307f2bfU), BSWAP_32BIG_C(
                0x7096f49bU),
        };
        r_rsip_func100(Param_p2b_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_040[] =
        {
            BSWAP_32BIG_C(0x34f180e5U), BSWAP_32BIG_C(0xbc03ad81U), BSWAP_32BIG_C(0x0a00fc87U), BSWAP_32BIG_C(
                0xd6f824e2U),
        };
        r_rsip_func101(Param_p2b_func101_040);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x13280000U);
    for (iLoop = 0U; iLoop < 64U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_025[] =
        {
            BSWAP_32BIG_C(0x6e87a8b3U), BSWAP_32BIG_C(0x5cdcdc0aU), BSWAP_32BIG_C(0xad4f55bfU), BSWAP_32BIG_C(
                0x55501825U),
        };
        r_rsip_func100(Param_p2b_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[65 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_041[] =
        {
            BSWAP_32BIG_C(0x20dd5579U), BSWAP_32BIG_C(0x76f98691U), BSWAP_32BIG_C(0xa4d56a56U), BSWAP_32BIG_C(
                0x83d6edacU),
        };
        r_rsip_func101(Param_p2b_func101_041);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p2b_func100_026[] =
    {
        BSWAP_32BIG_C(0x730a33f4U), BSWAP_32BIG_C(0x5283eb94U), BSWAP_32BIG_C(0x6003d614U), BSWAP_32BIG_C(0xfb79f788U),
    };
    r_rsip_func100(Param_p2b_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[129]);

    static const uint32_t Param_p2b_func100_027[] =
    {
        BSWAP_32BIG_C(0xed1995c9U), BSWAP_32BIG_C(0x6e05e204U), BSWAP_32BIG_C(0x7afa7656U), BSWAP_32BIG_C(0xe7b8a4ebU),
    };
    r_rsip_func100(Param_p2b_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub003(0x800103a0U, 0x00002b07U);

    static const uint32_t Param_p2b_func101_042[] =
    {
        BSWAP_32BIG_C(0x146fc0a2U), BSWAP_32BIG_C(0x634c8bffU), BSWAP_32BIG_C(0xf043c233U), BSWAP_32BIG_C(0x395030f0U),
    };
    r_rsip_func101(Param_p2b_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x800103a0U, 0x0000022bU);

    static const uint32_t Param_p2b_func101_043[] =
    {
        BSWAP_32BIG_C(0xff1f14f1U), BSWAP_32BIG_C(0xc7af1d18U), BSWAP_32BIG_C(0xeffa7b2eU), BSWAP_32BIG_C(0xd652d31aU),
    };
    r_rsip_func101(Param_p2b_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000cU);

    r_rsip_func_sub003(0x800103a0U, 0x0000022bU);

    static const uint32_t Param_p2b_func101_044[] =
    {
        BSWAP_32BIG_C(0xee9ad686U), BSWAP_32BIG_C(0x09917a25U), BSWAP_32BIG_C(0x9e5053b6U), BSWAP_32BIG_C(0xa7057d3fU),
    };
    r_rsip_func101(Param_p2b_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub021(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub031(0x00000040U, 0x000008e7U, 0x15300000U);
    for (iLoop = 0U; iLoop < 64U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p2b_func100_028[] =
        {
            BSWAP_32BIG_C(0x257419b0U), BSWAP_32BIG_C(0x6ad86520U), BSWAP_32BIG_C(0xbed94152U), BSWAP_32BIG_C(
                0x2d4ade36U),
        };
        r_rsip_func100(Param_p2b_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p2b_func101_045[] =
        {
            BSWAP_32BIG_C(0xaed61b5fU), BSWAP_32BIG_C(0x1ee228e0U), BSWAP_32BIG_C(0x1b842116U), BSWAP_32BIG_C(
                0x650a2e84U),
        };
        r_rsip_func101(Param_p2b_func101_045);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p2b_func100_029[] =
    {
        BSWAP_32BIG_C(0xdd6e990fU), BSWAP_32BIG_C(0x94f91542U), BSWAP_32BIG_C(0x82e17b98U), BSWAP_32BIG_C(0x8c7188e6U),
    };
    r_rsip_func100(Param_p2b_func100_029);
    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[65]);

    static const uint32_t Param_p2b_func100_030[] =
    {
        BSWAP_32BIG_C(0x42b59108U), BSWAP_32BIG_C(0xbad484dbU), BSWAP_32BIG_C(0xcf686ff8U), BSWAP_32BIG_C(0x39bf0675U),
    };
    r_rsip_func100(Param_p2b_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[69]);

    static const uint32_t Param_p2b_func100_031[] =
    {
        BSWAP_32BIG_C(0xb6897939U), BSWAP_32BIG_C(0x090f1ff0U), BSWAP_32BIG_C(0x30137ca0U), BSWAP_32BIG_C(0xfb423244U),
    };
    r_rsip_func100(Param_p2b_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p2b_func102_004[] =
    {
        BSWAP_32BIG_C(0xe31b4f49U), BSWAP_32BIG_C(0x4ce5b5cfU), BSWAP_32BIG_C(0x6d32d151U), BSWAP_32BIG_C(0x787b8d98U),
    };
    r_rsip_func102(Param_p2b_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
