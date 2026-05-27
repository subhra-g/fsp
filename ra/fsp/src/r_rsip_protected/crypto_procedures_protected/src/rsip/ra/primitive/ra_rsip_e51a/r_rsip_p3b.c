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

rsip_ret_t r_rsip_p3b (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x003b0001U, 0x00000e50U);

    WR1_PROG(REG_1600H, 0x00000a31U);
    for (kLoop = 0U; kLoop < MAX_CNT; kLoop++)
    {
        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0160H, bswap_32big(0x00030005U));
        WR1_PROG(REG_0164H, bswap_32big(0x0007000bU));
        WR1_PROG(REG_0168H, bswap_32big(0x000d0011U));
        WR1_PROG(REG_016CH, bswap_32big(0x00130017U));
        WR1_PROG(REG_0170H, bswap_32big(0x001d001fU));
        WR1_PROG(REG_0174H, bswap_32big(0x00250029U));
        WR1_PROG(REG_0178H, bswap_32big(0x002b002fU));
        WR1_PROG(REG_017CH, bswap_32big(0x003b003dU));
        WR1_PROG(REG_0180H, bswap_32big(0x00430047U));
        WR1_PROG(REG_0184H, bswap_32big(0x0049004fU));
        WR1_PROG(REG_0188H, bswap_32big(0x00530059U));
        WR1_PROG(REG_018CH, bswap_32big(0x00610065U));
        WR1_PROG(REG_0190H, bswap_32big(0x0067006bU));
        WR1_PROG(REG_0194H, bswap_32big(0x006d0071U));
        WR1_PROG(REG_0198H, bswap_32big(0x007f0083U));
        WR1_PROG(REG_019CH, bswap_32big(0x0089008bU));
        WR1_PROG(REG_01A0H, bswap_32big(0x00950097U));
        WR1_PROG(REG_01A4H, bswap_32big(0x009d00a3U));
        WR1_PROG(REG_01A8H, bswap_32big(0x00a700adU));
        WR1_PROG(REG_01ACH, bswap_32big(0x00b300b5U));
        WR1_PROG(REG_01B0H, bswap_32big(0x00bf00c1U));
        WR1_PROG(REG_01B4H, bswap_32big(0x00c500c7U));
        WR1_PROG(REG_01B8H, bswap_32big(0x00d300dfU));
        WR1_PROG(REG_01BCH, bswap_32big(0x00e300e5U));
        WR1_PROG(REG_01C0H, bswap_32big(0x00e900efU));
        WR1_PROG(REG_01C4H, bswap_32big(0x00f100fbU));
        WR1_PROG(REG_01C8H, bswap_32big(0x01010107U));
        WR1_PROG(REG_01CCH, bswap_32big(0x010d010fU));
        WR1_PROG(REG_01D0H, bswap_32big(0x01150119U));
        WR1_PROG(REG_01D4H, bswap_32big(0x011b0125U));
        WR1_PROG(REG_01D8H, bswap_32big(0x01330137U));
        WR1_PROG(REG_01DCH, bswap_32big(0x0139013dU));
        WR1_PROG(REG_01E0H, bswap_32big(0x014b0151U));
        WR1_PROG(REG_01E4H, bswap_32big(0x015b015dU));
        WR1_PROG(REG_01E8H, bswap_32big(0x01610167U));
        WR1_PROG(REG_01ECH, bswap_32big(0x016f0175U));
        WR1_PROG(REG_01F0H, bswap_32big(0x017b017fU));
        WR1_PROG(REG_01F4H, bswap_32big(0x0185018dU));
        WR1_PROG(REG_01F8H, bswap_32big(0x01910199U));
        WR1_PROG(REG_01FCH, bswap_32big(0x01a301a5U));
        WR1_PROG(REG_0200H, bswap_32big(0x01af01b1U));
        WR1_PROG(REG_0204H, bswap_32big(0x01b701bbU));
        WR1_PROG(REG_0208H, bswap_32big(0x01c101c9U));
        WR1_PROG(REG_020CH, bswap_32big(0x01cd01cfU));
        WR1_PROG(REG_0210H, bswap_32big(0x01d301dfU));
        WR1_PROG(REG_0214H, bswap_32big(0x01e701ebU));
        WR1_PROG(REG_0218H, bswap_32big(0x01f301f7U));
        WR1_PROG(REG_021CH, bswap_32big(0x01fd0000U));

        r_rsip_func_sub026(0x0000b4c0U, 0x000000c0U, 0x80b00006U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x034300c1U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

        static const uint32_t Param_p3b_func101_001[] =
        {
            BSWAP_32BIG_C(0x2fc1e1cfU), BSWAP_32BIG_C(0x23797578U), BSWAP_32BIG_C(0x8e47bcedU), BSWAP_32BIG_C(
                0x846b3dbaU),
        };
        r_rsip_func101(Param_p3b_func101_001);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11200000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000038U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 56U; )
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

            static const uint32_t Param_p3b_func101_002[] =
            {
                BSWAP_32BIG_C(0x60b27d92U), BSWAP_32BIG_C(0xbe9d23abU), BSWAP_32BIG_C(0x897293e6U), BSWAP_32BIG_C(
                    0xa7b4b582U),
            };
            r_rsip_func101(Param_p3b_func101_002);
            r_rsip_func113();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p3b_func101_003[] =
            {
                BSWAP_32BIG_C(0x05101202U), BSWAP_32BIG_C(0x27fe0d14U), BSWAP_32BIG_C(0x7f440cbcU), BSWAP_32BIG_C(
                    0xaf4c7cc2U),
            };
            r_rsip_func101(Param_p3b_func101_003);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b03U);

        static const uint32_t Param_p3b_func101_004[] =
        {
            BSWAP_32BIG_C(0x74df1227U), BSWAP_32BIG_C(0x5d58d46fU), BSWAP_32BIG_C(0xdfdfeedfU), BSWAP_32BIG_C(
                0x24a350adU),
        };
        r_rsip_func101(Param_p3b_func101_004);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1444H, 0x00003fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0940H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0944H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0948H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_094CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0950H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0954H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0958H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_095CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0960H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0964H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0968H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_096CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0970H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0974H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0978H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_097CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0980H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0984H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0988H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_098CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0990H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0994H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0998H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_099CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09A8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ACH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09B8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09BCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09C8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09CCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09D8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09DCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09E8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09ECH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09F8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09FCH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A00H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A04H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A08H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A0CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A10H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A14H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A18H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A1CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A20H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A24H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A28H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A2CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A30H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A34H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A38H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A3CH, bswap_32big(0xB851EB85U));

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3b_func100_001[] =
        {
            BSWAP_32BIG_C(0xc97748faU), BSWAP_32BIG_C(0xab884819U), BSWAP_32BIG_C(0x9b85f9acU), BSWAP_32BIG_C(
                0x38955739U),
        };
        r_rsip_func100(Param_p3b_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_005[] =
            {
                BSWAP_32BIG_C(0xdf9a48a5U), BSWAP_32BIG_C(0xe6e71d7bU), BSWAP_32BIG_C(0x3505f1e3U), BSWAP_32BIG_C(
                    0x5c861a45U),
            };
            r_rsip_func101(Param_p3b_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p3b_func101_006[] =
            {
                BSWAP_32BIG_C(0x0813b602U), BSWAP_32BIG_C(0xc87e6c80U), BSWAP_32BIG_C(0xe094433bU), BSWAP_32BIG_C(
                    0x9cf2adffU),
            };
            r_rsip_func101(Param_p3b_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3b_func100_002[] =
        {
            BSWAP_32BIG_C(0x3ba6e686U), BSWAP_32BIG_C(0x626c44f4U), BSWAP_32BIG_C(0x9bf1beecU), BSWAP_32BIG_C(
                0x77a633c8U),
        };
        r_rsip_func100(Param_p3b_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_003[] =
            {
                BSWAP_32BIG_C(0x74f3a65dU), BSWAP_32BIG_C(0x1848676eU), BSWAP_32BIG_C(0x8a28c37aU), BSWAP_32BIG_C(
                    0x9a274586U),
            };
            r_rsip_func100(Param_p3b_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x2020000aU);

                static const uint32_t Param_p3b_func101_007[] =
                {
                    BSWAP_32BIG_C(0xbbb1a687U), BSWAP_32BIG_C(0x82e66be3U), BSWAP_32BIG_C(0x7d8b5f5cU), BSWAP_32BIG_C(
                        0x457c201eU),
                };
                r_rsip_func101(Param_p3b_func101_007);
            }
            else
            {
                static const uint32_t Param_p3b_func101_008[] =
                {
                    BSWAP_32BIG_C(0x732839fdU), BSWAP_32BIG_C(0xe4c1b727U), BSWAP_32BIG_C(0xaa9b81e6U), BSWAP_32BIG_C(
                        0x4de5d5b9U),
                };
                r_rsip_func101(Param_p3b_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c000f1U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_004[] =
            {
                BSWAP_32BIG_C(0x79334c80U), BSWAP_32BIG_C(0x0b4dee97U), BSWAP_32BIG_C(0x8129b330U), BSWAP_32BIG_C(
                    0x04176892U),
            };
            r_rsip_func100(Param_p3b_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3b_func101_009[] =
                {
                    BSWAP_32BIG_C(0x9b4cb7fcU), BSWAP_32BIG_C(0x384a7416U), BSWAP_32BIG_C(0x221b74fcU), BSWAP_32BIG_C(
                        0x16621e18U),
                };
                r_rsip_func101(Param_p3b_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p3b_func101_010[] =
                {
                    BSWAP_32BIG_C(0xbb9be7b4U), BSWAP_32BIG_C(0xbe40177dU), BSWAP_32BIG_C(0x6e845b37U), BSWAP_32BIG_C(
                        0x1fc001baU),
                };
                r_rsip_func101(Param_p3b_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p3b_func101_011[] =
            {
                BSWAP_32BIG_C(0xe1c7b987U), BSWAP_32BIG_C(0x5d733990U), BSWAP_32BIG_C(0x6b3226b0U), BSWAP_32BIG_C(
                    0xe6645d86U),
            };
            r_rsip_func101(Param_p3b_func101_011);
        }

        r_rsip_func_sub025(0x0000b4c0U, 0x000000c0U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub025(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x15300000U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x20200010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x20200004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19400000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_005[] =
            {
                BSWAP_32BIG_C(0x0f6a6285U), BSWAP_32BIG_C(0x0ab5fc1bU), BSWAP_32BIG_C(0x5ccbaf23U), BSWAP_32BIG_C(
                    0xa9d5db6eU),
            };
            r_rsip_func100(Param_p3b_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p3b_func101_012[] =
                {
                    BSWAP_32BIG_C(0xb8394cf3U), BSWAP_32BIG_C(0x7d8048d4U), BSWAP_32BIG_C(0x7781eb32U), BSWAP_32BIG_C(
                        0x719c9025U),
                };
                r_rsip_func101(Param_p3b_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p3b_func101_013[] =
                {
                    BSWAP_32BIG_C(0xcfb15a84U), BSWAP_32BIG_C(0x8f5b0ef6U), BSWAP_32BIG_C(0x0a648675U), BSWAP_32BIG_C(
                        0x018207ebU),
                };
                r_rsip_func101(Param_p3b_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3b_func100_006[] =
        {
            BSWAP_32BIG_C(0x339aee89U), BSWAP_32BIG_C(0x8f9281f7U), BSWAP_32BIG_C(0xc1ae3ffaU), BSWAP_32BIG_C(
                0x8a2a8345U),
        };
        r_rsip_func100(Param_p3b_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_014[] =
            {
                BSWAP_32BIG_C(0xad24540eU), BSWAP_32BIG_C(0x34c5cc9bU), BSWAP_32BIG_C(0x312d5413U), BSWAP_32BIG_C(
                    0x1a09a2bcU),
            };
            r_rsip_func101(Param_p3b_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_func_sub001(0x00c00101U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x20200009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x2020000aU);

        WR1_PROG(REG_1404H, 0x15300000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x20200010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x20200004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3b_func100_007[] =
        {
            BSWAP_32BIG_C(0xcbe3691cU), BSWAP_32BIG_C(0x3d37eecdU), BSWAP_32BIG_C(0x2cbf8f32U), BSWAP_32BIG_C(
                0xb6558f40U),
        };
        r_rsip_func100(Param_p3b_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3b_func101_015[] =
            {
                BSWAP_32BIG_C(0x7c285b39U), BSWAP_32BIG_C(0xd94fe5fcU), BSWAP_32BIG_C(0x2ced59f3U), BSWAP_32BIG_C(
                    0x9d597440U),
            };
            r_rsip_func101(Param_p3b_func101_015);
        }
        else
        {
            static const uint32_t Param_p3b_func100_008[] =
            {
                BSWAP_32BIG_C(0xddacf41fU), BSWAP_32BIG_C(0x8dd867daU), BSWAP_32BIG_C(0xa5bcb447U), BSWAP_32BIG_C(
                    0xa1a3368cU),
            };
            r_rsip_func100(Param_p3b_func100_008);
            WR1_PROG(REG_1404H, 0x17380000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c000fdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub038(0x00000018U, 0x00000428U, 0x20200010U);
            r_rsip_func_sub007(0x00000838U, 0x00000220U, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);

            r_rsip_func_sub037(0x20200000U, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x2020000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3b_func100_009[] =
            {
                BSWAP_32BIG_C(0xbefabb5cU), BSWAP_32BIG_C(0x56de6de1U), BSWAP_32BIG_C(0x3172e3c0U), BSWAP_32BIG_C(
                    0x7ba2c65cU),
            };
            r_rsip_func100(Param_p3b_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3b_func101_016[] =
                {
                    BSWAP_32BIG_C(0xa24b7be6U), BSWAP_32BIG_C(0x7339b2c7U), BSWAP_32BIG_C(0x5b215e79U), BSWAP_32BIG_C(
                        0x54ebc466U),
                };
                r_rsip_func101(Param_p3b_func101_016);
                continue;
            }

            static const uint32_t Param_p3b_func100_010[] =
            {
                BSWAP_32BIG_C(0x440ad503U), BSWAP_32BIG_C(0xb865ceafU), BSWAP_32BIG_C(0x9cf41037U), BSWAP_32BIG_C(
                    0x7dfedf87U),
            };
            r_rsip_func100(Param_p3b_func100_010);

            r_rsip_func_sub025(0x0000b560U, 0x00000001U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80c0000aU);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub001(0x03430101U);

            r_rsip_func_sub024(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x000000fcU);

            for (iLoop = 0U; iLoop < 64U; iLoop++)
            {
                r_rsip_func_sub025(0x000038e6U, 0x0000a8c0U, 0x00000004U);
                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub024(0x38008900U, 0x00000000U, 0x11816907U, 0x38008900U);
                    r_rsip_func_sub025(0x00000000U, 0x10002d20U, 0x000168e7U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub016(0x81010120U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);

            r_rsip_func_sub033(0x15300000U, 0x0000094aU, 0x81c0000aU);
            r_rsip_func_sub001(0x00c90101U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x2020000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x20200009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p3b_func101_017[] =
                {
                    BSWAP_32BIG_C(0xf4c051cdU), BSWAP_32BIG_C(0x85faeffdU), BSWAP_32BIG_C(0x11f39e9cU), BSWAP_32BIG_C(
                        0x68ca93caU),
                };
                r_rsip_func101(Param_p3b_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p3b_func100_011[] =
            {
                BSWAP_32BIG_C(0xaa2f3502U), BSWAP_32BIG_C(0x2e7d6e14U), BSWAP_32BIG_C(0xf5d25804U), BSWAP_32BIG_C(
                    0x637fb462U),
            };
            r_rsip_func100(Param_p3b_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub034(0x00000040U, 0x000008e7U, 0x11200000U);
                for (jLoop = 0U; jLoop < 64U; )
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b04U);

                    static const uint32_t Param_p3b_func101_018[] =
                    {
                        BSWAP_32BIG_C(0x8974bbd1U), BSWAP_32BIG_C(0x456aeee3U), BSWAP_32BIG_C(0xfefddb03U),
                        BSWAP_32BIG_C(0xf7ee3065U),
                    };
                    r_rsip_func101(Param_p3b_func101_018);
                    r_rsip_func113();

                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p3b_func101_019[] =
                    {
                        BSWAP_32BIG_C(0xd23841ccU), BSWAP_32BIG_C(0x0b85fcb8U), BSWAP_32BIG_C(0x5900c61cU),
                        BSWAP_32BIG_C(0x2013006eU),
                    };
                    r_rsip_func101(Param_p3b_func101_019);
                    jLoop = jLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p3b_func100_012[] =
                {
                    BSWAP_32BIG_C(0xc7fd0ed7U), BSWAP_32BIG_C(0xccd04254U), BSWAP_32BIG_C(0x5caa8a30U), BSWAP_32BIG_C(
                        0xc87ab93fU),
                };
                r_rsip_func100(Param_p3b_func100_012);
                WR1_PROG(REG_1404H, 0x19400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x2020000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x20200010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x20200004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17380000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x20200009U);

                r_rsip_func_sub038(0x00000018U, 0x00000428U, 0x20200010U);
                r_rsip_func_sub007(0x00000220U, 0x00000630U, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);

                r_rsip_func_sub037(0x20200000U, 0x00010001U);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c000fdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p3b_func100_013[] =
                {
                    BSWAP_32BIG_C(0x7af3ef3dU), BSWAP_32BIG_C(0x501e059eU), BSWAP_32BIG_C(0xbd913ac0U), BSWAP_32BIG_C(
                        0xf6206e97U),
                };
                r_rsip_func100(Param_p3b_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p3b_func101_020[] =
                    {
                        BSWAP_32BIG_C(0xb81f3c12U), BSWAP_32BIG_C(0xfabc508fU), BSWAP_32BIG_C(0x2ebd007eU),
                        BSWAP_32BIG_C(0xe9279829U),
                    };
                    r_rsip_func101(Param_p3b_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p3b_func100_014[] =
                    {
                        BSWAP_32BIG_C(0xda07bc27U), BSWAP_32BIG_C(0xaa7b7215U), BSWAP_32BIG_C(0x5a56c5cbU),
                        BSWAP_32BIG_C(0x39a236cdU),
                    };
                    r_rsip_func100(Param_p3b_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19400000U);
                        WR1_PROG(REG_1608H, 0x81c0000aU);
                        r_rsip_func_sub001(0x00c90101U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p3b_func100_015[] =
                        {
                            BSWAP_32BIG_C(0x4a92d88fU), BSWAP_32BIG_C(0x71beda31U), BSWAP_32BIG_C(0x675a2e4dU),
                            BSWAP_32BIG_C(0x2cbb75d8U),
                        };
                        r_rsip_func100(Param_p3b_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p3b_func101_021[] =
                            {
                                BSWAP_32BIG_C(0xf05b995fU), BSWAP_32BIG_C(0xef88e2d4U), BSWAP_32BIG_C(0x7eb27f3aU),
                                BSWAP_32BIG_C(0xaa63d751U),
                            };
                            r_rsip_func101(Param_p3b_func101_021);
                            break;
                        }
                        else
                        {
                            static const uint32_t Param_p3b_func100_016[] =
                            {
                                BSWAP_32BIG_C(0xe8e2cf85U), BSWAP_32BIG_C(0x528ef2f8U), BSWAP_32BIG_C(0x1761cd5cU),
                                BSWAP_32BIG_C(0x3c4bd2e8U),
                            };
                            r_rsip_func100(Param_p3b_func100_016);
                            WR1_PROG(REG_1404H, 0x19400000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c000fdU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x20200000U,
                                               0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x20200009U);

                            static const uint32_t Param_p3b_func101_022[] =
                            {
                                BSWAP_32BIG_C(0xdecb8abeU), BSWAP_32BIG_C(0x1cb92eabU), BSWAP_32BIG_C(0x79853ce1U),
                                BSWAP_32BIG_C(0xbc388166U),
                            };
                            r_rsip_func101(Param_p3b_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p3b_func100_017[] =
                    {
                        BSWAP_32BIG_C(0xd9ecd517U), BSWAP_32BIG_C(0xf99dbecbU), BSWAP_32BIG_C(0xc2dbd955U),
                        BSWAP_32BIG_C(0x9ccc3bceU),
                    };
                    r_rsip_func100(Param_p3b_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p3b_func101_023[] =
                        {
                            BSWAP_32BIG_C(0xdf36d6a6U), BSWAP_32BIG_C(0x880a7c8eU), BSWAP_32BIG_C(0xc6657bdeU),
                            BSWAP_32BIG_C(0xf65aee7cU),
                        };
                        r_rsip_func101(Param_p3b_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p3b_func101_024[] =
                        {
                            BSWAP_32BIG_C(0x7acff248U), BSWAP_32BIG_C(0x8366309bU), BSWAP_32BIG_C(0x0c1b9eb5U),
                            BSWAP_32BIG_C(0x8dd52387U),
                        };
                        r_rsip_func101(Param_p3b_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p3b_func100_018[] =
            {
                BSWAP_32BIG_C(0x765635b4U), BSWAP_32BIG_C(0xd2820434U), BSWAP_32BIG_C(0x7fc0b664U), BSWAP_32BIG_C(
                    0x90cf302eU),
            };
            r_rsip_func100(Param_p3b_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p3b_func100_019[] =
                {
                    BSWAP_32BIG_C(0xd5601d34U), BSWAP_32BIG_C(0xe1de9099U), BSWAP_32BIG_C(0x04392bb1U), BSWAP_32BIG_C(
                        0xdaa4151bU),
                };
                r_rsip_func100(Param_p3b_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p3b_func101_025[] =
                    {
                        BSWAP_32BIG_C(0x069e5338U), BSWAP_32BIG_C(0x02450d07U), BSWAP_32BIG_C(0x7d3f34a8U),
                        BSWAP_32BIG_C(0x32d9fd1fU),
                    };
                    r_rsip_func101(Param_p3b_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x20200009U);

                    static const uint32_t Param_p3b_func101_026[] =
                    {
                        BSWAP_32BIG_C(0xab33dde8U), BSWAP_32BIG_C(0x9e2bf4f3U), BSWAP_32BIG_C(0x7784a8ffU),
                        BSWAP_32BIG_C(0x88a39058U),
                    };
                    r_rsip_func101(Param_p3b_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p3b_func101_027[] =
                {
                    BSWAP_32BIG_C(0xaf8b4143U), BSWAP_32BIG_C(0xc2a4d2faU), BSWAP_32BIG_C(0x47126475U), BSWAP_32BIG_C(
                        0x3ce7f66bU),
                };
                r_rsip_func101(Param_p3b_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p3b_func100_020[] =
    {
        BSWAP_32BIG_C(0xaf77d897U), BSWAP_32BIG_C(0x35892c72U), BSWAP_32BIG_C(0x426f53abU), BSWAP_32BIG_C(0xac579fd0U),
    };
    r_rsip_func100(Param_p3b_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_001[] =
        {
            BSWAP_32BIG_C(0xd043e820U), BSWAP_32BIG_C(0x89c7fb14U), BSWAP_32BIG_C(0xe944a3b5U), BSWAP_32BIG_C(
                0xa7a4b951U),
        };
        r_rsip_func102(Param_p3b_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x20200009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000738U, 0x20200009U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b05U);

    static const uint32_t Param_p3b_func101_028[] =
    {
        BSWAP_32BIG_C(0xfe9e64e4U), BSWAP_32BIG_C(0x722b100dU), BSWAP_32BIG_C(0x6e831b5cU), BSWAP_32BIG_C(0xab76c28dU),
    };
    r_rsip_func101(Param_p3b_func101_028);
    r_rsip_func113();

    static const uint32_t Param_p3b_func100_021[] =
    {
        BSWAP_32BIG_C(0xfac3916eU), BSWAP_32BIG_C(0x007aeb65U), BSWAP_32BIG_C(0x2d3a8d6eU), BSWAP_32BIG_C(0xe04a7c35U),
    };
    r_rsip_func100(Param_p3b_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x16380000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

    static const uint32_t Param_p3b_func101_029[] =
    {
        BSWAP_32BIG_C(0x6c59c3e9U), BSWAP_32BIG_C(0xff39b0a1U), BSWAP_32BIG_C(0x80ce95aaU), BSWAP_32BIG_C(0xbb628179U),
    };
    r_rsip_func101(Param_p3b_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x2020000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x2020000aU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000003bU);

    static const uint32_t Param_p3b_func101_030[] =
    {
        BSWAP_32BIG_C(0x4cb5bf94U), BSWAP_32BIG_C(0xc862ac8aU), BSWAP_32BIG_C(0x688ce218U), BSWAP_32BIG_C(0xa438740dU),
    };
    r_rsip_func101(Param_p3b_func101_030);
    r_rsip_func054();

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_func_sub001(0x00c00101U);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000660U, 0x20200009U);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000dc0U);

    WR1_PROG(REG_1404H, 0x14500000U);
    r_rsip_func_sub001(0x00c00111U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x16780000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

    static const uint32_t Param_p3b_func101_031[] =
    {
        BSWAP_32BIG_C(0xba7ce631U), BSWAP_32BIG_C(0x2f615e20U), BSWAP_32BIG_C(0x0c448cb2U), BSWAP_32BIG_C(0x57c85c63U),
    };
    r_rsip_func101(Param_p3b_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000778U, 0x00000878U, 0x00000230U, 0x20200007U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

    static const uint32_t Param_p3b_func101_032[] =
    {
        BSWAP_32BIG_C(0xede19902U), BSWAP_32BIG_C(0x622636f0U), BSWAP_32BIG_C(0x12ae68b1U), BSWAP_32BIG_C(0x6a701ecaU),
    };
    r_rsip_func101(Param_p3b_func101_032);
    r_rsip_func321();

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3b_func100_022[] =
    {
        BSWAP_32BIG_C(0x92dcf757U), BSWAP_32BIG_C(0xf576443fU), BSWAP_32BIG_C(0xb35cef75U), BSWAP_32BIG_C(0xdec1ecaaU),
    };
    r_rsip_func100(Param_p3b_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_002[] =
        {
            BSWAP_32BIG_C(0x57fca3a9U), BSWAP_32BIG_C(0x6469b8afU), BSWAP_32BIG_C(0x1c921ed4U), BSWAP_32BIG_C(
                0xd58983ceU),
        };
        r_rsip_func102(Param_p3b_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x12480000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

    static const uint32_t Param_p3b_func101_033[] =
    {
        BSWAP_32BIG_C(0x0ba82be5U), BSWAP_32BIG_C(0x4c795556U), BSWAP_32BIG_C(0x51bc5ebfU), BSWAP_32BIG_C(0xc947aa3dU),
    };
    r_rsip_func101(Param_p3b_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000348U, 0x00000448U, 0x00000660U, 0x20200007U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

    static const uint32_t Param_p3b_func101_034[] =
    {
        BSWAP_32BIG_C(0xa15ef1f3U), BSWAP_32BIG_C(0xce8ed8ceU), BSWAP_32BIG_C(0x4f4c7bd0U), BSWAP_32BIG_C(0xa0a1cd2eU),
    };
    r_rsip_func101(Param_p3b_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000448U, 0x00000a90U, 0x00000230U, 0x2020000aU);

    r_rsip_func_sub002(0x00000348U, 0x00000a90U, 0x00000130U, 0x2020000aU);

    r_rsip_func_sub002(0x00000130U, 0x00000230U, 0x00000448U, 0x20200007U);

    r_rsip_func_sub038(0x00000018U, 0x00000660U, 0x40400010U);
    r_rsip_func_sub007(0x00000448U, 0x00000878U, 0x00000660U);
    r_rsip_func_sub005(0x00000448U, 0x40400002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000660U);
    r_rsip_func_sub005(0x00000230U, 0x40400003U, 0x00010001U);
    r_rsip_func_sub007(0x00000448U, 0x00000230U, 0x00000660U);
    r_rsip_func_sub005(0x00000230U, 0x40400002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14600000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

    static const uint32_t Param_p3b_func101_035[] =
    {
        BSWAP_32BIG_C(0x75f6ae8aU), BSWAP_32BIG_C(0x62d61efdU), BSWAP_32BIG_C(0x6002bbccU), BSWAP_32BIG_C(0x0fd08483U),
    };
    r_rsip_func101(Param_p3b_func101_035);
    r_rsip_func321();

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c001fdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3b_func100_023[] =
    {
        BSWAP_32BIG_C(0x509f3ab6U), BSWAP_32BIG_C(0x67fdc39eU), BSWAP_32BIG_C(0xa206f2ccU), BSWAP_32BIG_C(0x9537d209U),
    };
    r_rsip_func100(Param_p3b_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3b_func102_003[] =
        {
            BSWAP_32BIG_C(0xd78663c1U), BSWAP_32BIG_C(0x8dec69ffU), BSWAP_32BIG_C(0xbb663cb7U), BSWAP_32BIG_C(
                0xf6ce8835U),
        };
        r_rsip_func102(Param_p3b_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_func_sub001(0x00c00201U);

    r_rsip_func_sub002(0x00000878U, 0x00000a90U, 0x00000448U, 0x40400009U);

    r_rsip_func_sub004(0x0b040184U, 0x360905f3U);

    OFS_ADR = 808;

    r_rsip_func_sub012(0x14600000U, 0x0000b400U, 0x00000080U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b03U);

    static const uint32_t Param_p3b_func101_036[] =
    {
        BSWAP_32BIG_C(0x460b701bU), BSWAP_32BIG_C(0xf27a8b01U), BSWAP_32BIG_C(0x86637c6eU), BSWAP_32BIG_C(0x15a10f2fU),
    };
    r_rsip_func101(Param_p3b_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b06U);

    static const uint32_t Param_p3b_func101_037[] =
    {
        BSWAP_32BIG_C(0x8bb0aa17U), BSWAP_32BIG_C(0xc52cf8a7U), BSWAP_32BIG_C(0x236250abU), BSWAP_32BIG_C(0x3ab6186bU),
    };
    r_rsip_func101(Param_p3b_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

    static const uint32_t Param_p3b_func101_038[] =
    {
        BSWAP_32BIG_C(0x32ed4c3fU), BSWAP_32BIG_C(0xfc9853daU), BSWAP_32BIG_C(0x69a8e333U), BSWAP_32BIG_C(0x8f2c6ae9U),
    };
    r_rsip_func101(Param_p3b_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b01U);

    static const uint32_t Param_p3b_func101_039[] =
    {
        BSWAP_32BIG_C(0xbab165dfU), BSWAP_32BIG_C(0xea5f053fU), BSWAP_32BIG_C(0x9cc97e5fU), BSWAP_32BIG_C(0xa3ab25eeU),
    };
    r_rsip_func101(Param_p3b_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000080U, 0x000008e7U, 0x14600000U);
    for (iLoop = 0U; iLoop < 128U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_024[] =
        {
            BSWAP_32BIG_C(0x417b502eU), BSWAP_32BIG_C(0xabbdaf08U), BSWAP_32BIG_C(0xab0e9843U), BSWAP_32BIG_C(
                0x4489b2b7U),
        };
        r_rsip_func100(Param_p3b_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_040[] =
        {
            BSWAP_32BIG_C(0x476fdeb3U), BSWAP_32BIG_C(0xc68ebad2U), BSWAP_32BIG_C(0x30fd0d92U), BSWAP_32BIG_C(
                0xa00cd93eU),
        };
        r_rsip_func101(Param_p3b_func101_040);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000080U, 0x000008e7U, 0x12480000U);
    for (iLoop = 0U; iLoop < 128U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_025[] =
        {
            BSWAP_32BIG_C(0x763f5e48U), BSWAP_32BIG_C(0x72927fdaU), BSWAP_32BIG_C(0x820bdc09U), BSWAP_32BIG_C(
                0xc44ae84fU),
        };
        r_rsip_func100(Param_p3b_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[129 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_041[] =
        {
            BSWAP_32BIG_C(0x459ba85bU), BSWAP_32BIG_C(0x899a5235U), BSWAP_32BIG_C(0x20383419U), BSWAP_32BIG_C(
                0x29a83e03U),
        };
        r_rsip_func101(Param_p3b_func101_041);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3b_func100_026[] =
    {
        BSWAP_32BIG_C(0x1e2a72bdU), BSWAP_32BIG_C(0x5db0e968U), BSWAP_32BIG_C(0xc34f2212U), BSWAP_32BIG_C(0x022b33cdU),
    };
    r_rsip_func100(Param_p3b_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[257]);

    static const uint32_t Param_p3b_func100_027[] =
    {
        BSWAP_32BIG_C(0x1676c8baU), BSWAP_32BIG_C(0x97e09d5dU), BSWAP_32BIG_C(0x1212dd81U), BSWAP_32BIG_C(0x9fe7c745U),
    };
    r_rsip_func100(Param_p3b_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b07U);

    static const uint32_t Param_p3b_func101_042[] =
    {
        BSWAP_32BIG_C(0xbc6b2673U), BSWAP_32BIG_C(0x04551e73U), BSWAP_32BIG_C(0xf0cef891U), BSWAP_32BIG_C(0x6677ccfdU),
    };
    r_rsip_func101(Param_p3b_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

    static const uint32_t Param_p3b_func101_043[] =
    {
        BSWAP_32BIG_C(0x19538ee2U), BSWAP_32BIG_C(0x8bd76535U), BSWAP_32BIG_C(0x8b3362a6U), BSWAP_32BIG_C(0x0698f638U),
    };
    r_rsip_func101(Param_p3b_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000010U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003b02U);

    static const uint32_t Param_p3b_func101_044[] =
    {
        BSWAP_32BIG_C(0xdfe0280dU), BSWAP_32BIG_C(0xa02a7c45U), BSWAP_32BIG_C(0x115f778dU), BSWAP_32BIG_C(0xdcd304fdU),
    };
    r_rsip_func101(Param_p3b_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000080U, 0x000008e7U, 0x14600000U);
    for (iLoop = 0U; iLoop < 128U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3b_func100_028[] =
        {
            BSWAP_32BIG_C(0x51749134U), BSWAP_32BIG_C(0xee71497eU), BSWAP_32BIG_C(0x9d76c078U), BSWAP_32BIG_C(
                0xa8af4895U),
        };
        r_rsip_func100(Param_p3b_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3b_func101_045[] =
        {
            BSWAP_32BIG_C(0xf5cc0599U), BSWAP_32BIG_C(0x207d18a2U), BSWAP_32BIG_C(0xdaf0184bU), BSWAP_32BIG_C(
                0x32b8b67dU),
        };
        r_rsip_func101(Param_p3b_func101_045);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3b_func100_029[] =
    {
        BSWAP_32BIG_C(0xea7c6de5U), BSWAP_32BIG_C(0x52aac35eU), BSWAP_32BIG_C(0xeada5e0dU), BSWAP_32BIG_C(0x3bb4b6d5U),
    };
    r_rsip_func100(Param_p3b_func100_029);
    r_rsip_func_sub029(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[129]);

    static const uint32_t Param_p3b_func100_030[] =
    {
        BSWAP_32BIG_C(0x86877c2bU), BSWAP_32BIG_C(0xc8186f67U), BSWAP_32BIG_C(0xf68c387aU), BSWAP_32BIG_C(0x75a031d5U),
    };
    r_rsip_func100(Param_p3b_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[133]);

    static const uint32_t Param_p3b_func100_031[] =
    {
        BSWAP_32BIG_C(0xd2936377U), BSWAP_32BIG_C(0x5a5d7e76U), BSWAP_32BIG_C(0xc7a4e8eaU), BSWAP_32BIG_C(0xc56946d9U),
    };
    r_rsip_func100(Param_p3b_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p3b_func102_004[] =
    {
        BSWAP_32BIG_C(0x4c252cefU), BSWAP_32BIG_C(0x7702e86bU), BSWAP_32BIG_C(0x01808324U), BSWAP_32BIG_C(0x5967d15fU),
    };
    r_rsip_func102(Param_p3b_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
