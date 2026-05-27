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

rsip_ret_t r_rsip_p3a (const uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;
    uint32_t kLoop   = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x003a0001U, 0x00000e50U);

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

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

        static const uint32_t Param_p3a_func101_001[] =
        {
            BSWAP_32BIG_C(0x059b108aU), BSWAP_32BIG_C(0x33cf2d7aU), BSWAP_32BIG_C(0xb0dfe72aU), BSWAP_32BIG_C(
                0x3c2a6079U),
        };
        r_rsip_func101(Param_p3a_func101_001);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);

        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_func_sub001(0x00c90011U);

        r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
        WR1_PROG(REG_1600H, 0x00000028U);
        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < 40U; )
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            r_rsip_func_sub014(0x00007c07U, 0x00602000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

            static const uint32_t Param_p3a_func101_002[] =
            {
                BSWAP_32BIG_C(0x25a8a496U), BSWAP_32BIG_C(0x3315ed01U), BSWAP_32BIG_C(0x15e94de1U), BSWAP_32BIG_C(
                    0xb3f2277eU),
            };
            r_rsip_func101(Param_p3a_func101_002);
            r_rsip_func113();

            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            r_rsip_func_sub001(0x00c20011U);

            WR1_PROG(REG_1600H, 0x00002485U);

            static const uint32_t Param_p3a_func101_003[] =
            {
                BSWAP_32BIG_C(0x76645b97U), BSWAP_32BIG_C(0x50783d97U), BSWAP_32BIG_C(0xb60f25a0U), BSWAP_32BIG_C(
                    0xa04303e0U),
            };
            r_rsip_func101(Param_p3a_func101_003);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x38000886U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a03U);

        static const uint32_t Param_p3a_func101_004[] =
        {
            BSWAP_32BIG_C(0x354e8599U), BSWAP_32BIG_C(0x95a30707U), BSWAP_32BIG_C(0x5b026884U), BSWAP_32BIG_C(
                0xcec81672U),
        };
        r_rsip_func101(Param_p3a_func101_004);
        r_rsip_func113();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80040000U);
        r_rsip_func_sub001(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1608H, 0x81040000U);
        r_rsip_func_sub001(0x00c90011U);

        WR1_PROG(REG_1444H, 0x00002fb0U);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_0980H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0984H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0988H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_098CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0990H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0994H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0998H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_099CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09A0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09ACH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09B0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09BCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09C0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09CCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09D0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09DCH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09E0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ECH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09F0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09FCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A00H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A04H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A08H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A0CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A10H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A14H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A18H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A1CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A20H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A24H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A28H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A2CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A30H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A34H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A38H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A3CH, bswap_32big(0x51EB851EU));

        r_rsip_func_sub002(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3a_func100_001[] =
        {
            BSWAP_32BIG_C(0xe27795b3U), BSWAP_32BIG_C(0x24fd2d0aU), BSWAP_32BIG_C(0xba146712U), BSWAP_32BIG_C(
                0xad37a529U),
        };
        r_rsip_func100(Param_p3a_func100_001);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_005[] =
            {
                BSWAP_32BIG_C(0x68dae7acU), BSWAP_32BIG_C(0xc7ea0e80U), BSWAP_32BIG_C(0x6044ec52U), BSWAP_32BIG_C(
                    0x2fcec170U),
            };
            r_rsip_func101(Param_p3a_func101_005);
            continue;
        }
        else
        {
            static const uint32_t Param_p3a_func101_006[] =
            {
                BSWAP_32BIG_C(0x2f7de89cU), BSWAP_32BIG_C(0x72744d2bU), BSWAP_32BIG_C(0x1163d3d8U), BSWAP_32BIG_C(
                    0x1fa026f4U),
            };
            r_rsip_func101(Param_p3a_func101_006);
        }

        r_rsip_func_sub006(0x38008a20U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3a_func100_002[] =
        {
            BSWAP_32BIG_C(0xb88ad10eU), BSWAP_32BIG_C(0x6313044cU), BSWAP_32BIG_C(0xa325bbe7U), BSWAP_32BIG_C(
                0x390bc221U),
        };
        r_rsip_func100(Param_p3a_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub002(0x00000320U, 0x00000220U, 0x00000630U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_003[] =
            {
                BSWAP_32BIG_C(0xe18e6709U), BSWAP_32BIG_C(0x6ff7d55cU), BSWAP_32BIG_C(0x6619c490U), BSWAP_32BIG_C(
                    0x50b5cdb7U),
            };
            r_rsip_func100(Param_p3a_func100_003);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub002(0x00000220U, 0x00000320U, 0x00000630U, 0x1818000aU);

                static const uint32_t Param_p3a_func101_007[] =
                {
                    BSWAP_32BIG_C(0x58fb63d4U), BSWAP_32BIG_C(0x41f867aaU), BSWAP_32BIG_C(0x6bf41c65U), BSWAP_32BIG_C(
                        0xae1d756cU),
                };
                r_rsip_func101(Param_p3a_func101_007);
            }
            else
            {
                static const uint32_t Param_p3a_func101_008[] =
                {
                    BSWAP_32BIG_C(0x8032ee5cU), BSWAP_32BIG_C(0xfcb2f2efU), BSWAP_32BIG_C(0x572ea8ffU), BSWAP_32BIG_C(
                        0xd7a91f9aU),
                };
                r_rsip_func101(Param_p3a_func101_008);
            }

            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_PROG(REG_1420H,
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x00000000U),
                     bswap_32big(0x10000000U));
            r_rsip_func_sub001(0x00c20011U);
            r_rsip_func_sub001(0x00c000b1U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_004[] =
            {
                BSWAP_32BIG_C(0x4294f345U), BSWAP_32BIG_C(0xecd8fbeeU), BSWAP_32BIG_C(0x4a0d9c49U), BSWAP_32BIG_C(
                    0xa59a600dU),
            };
            r_rsip_func100(Param_p3a_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3a_func101_009[] =
                {
                    BSWAP_32BIG_C(0xb77a0070U), BSWAP_32BIG_C(0xbcbb75acU), BSWAP_32BIG_C(0xcef06570U), BSWAP_32BIG_C(
                        0x47776768U),
                };
                r_rsip_func101(Param_p3a_func101_009);
                continue;
            }
            else
            {
                static const uint32_t Param_p3a_func101_010[] =
                {
                    BSWAP_32BIG_C(0x1189a973U), BSWAP_32BIG_C(0xe16006c4U), BSWAP_32BIG_C(0x7729730cU), BSWAP_32BIG_C(
                        0xcfb61435U),
                };
                r_rsip_func101(Param_p3a_func101_010);
            }
        }
        else
        {
            static const uint32_t Param_p3a_func101_011[] =
            {
                BSWAP_32BIG_C(0x991ecbb5U), BSWAP_32BIG_C(0xce763731U), BSWAP_32BIG_C(0x421f3cdfU), BSWAP_32BIG_C(
                    0x02ff26ffU),
            };
            r_rsip_func101(Param_p3a_func101_011);
        }

        r_rsip_func_sub025(0x0000b4c0U, 0x000000c0U, 0x0000094aU);

        for (iLoop = 0U; iLoop < 95U; iLoop++)
        {
            r_rsip_func_sub025(0x01003906U, 0x00002cc0U, 0x00002cc0U);
            WR1_PROG(REG_1608H, 0x81010100U);

            WR1_PROG(REG_1404H, 0x15700000U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c90005U);

            r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x18180010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            r_rsip_func_sub005(0x00000838U, 0x18180004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_005[] =
            {
                BSWAP_32BIG_C(0xabcfc090U), BSWAP_32BIG_C(0xe795b5b0U), BSWAP_32BIG_C(0x1cedefb2U), BSWAP_32BIG_C(
                    0x06863ad4U),
            };
            r_rsip_func100(Param_p3a_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);

                static const uint32_t Param_p3a_func101_012[] =
                {
                    BSWAP_32BIG_C(0xf9b28b9eU), BSWAP_32BIG_C(0xc3707843U), BSWAP_32BIG_C(0xca2e9380U), BSWAP_32BIG_C(
                        0xf731c7a9U),
                };
                r_rsip_func101(Param_p3a_func101_012);
                break;
            }
            else
            {
                static const uint32_t Param_p3a_func101_013[] =
                {
                    BSWAP_32BIG_C(0xadab0528U), BSWAP_32BIG_C(0x92420ba3U), BSWAP_32BIG_C(0xb95376b8U), BSWAP_32BIG_C(
                        0xfb595eeaU),
                };
                r_rsip_func101(Param_p3a_func101_013);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
        }

        r_rsip_func_sub006(0x38008940U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p3a_func100_006[] =
        {
            BSWAP_32BIG_C(0xea9e2b61U), BSWAP_32BIG_C(0x2353eae0U), BSWAP_32BIG_C(0x188169dfU), BSWAP_32BIG_C(
                0x95b764a5U),
        };
        r_rsip_func100(Param_p3a_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_014[] =
            {
                BSWAP_32BIG_C(0x58579309U), BSWAP_32BIG_C(0xe1975acfU), BSWAP_32BIG_C(0x18127cbcU), BSWAP_32BIG_C(
                    0x5ddc6536U),
            };
            r_rsip_func101(Param_p3a_func101_014);
            continue;
        }

        WR1_PROG(REG_1404H, 0x18780000U);
        r_rsip_func_sub001(0x00c000c1U);

        r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000428U, 0x18180009U);

        r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);

        WR1_PROG(REG_1404H, 0x15700000U);
        r_rsip_func_sub004(0x08000104U, 0x00010001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub018(0x00000018U, 0x00000630U, 0x18180010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        r_rsip_func_sub005(0x00000838U, 0x18180004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c000bdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p3a_func100_007[] =
        {
            BSWAP_32BIG_C(0xecd29870U), BSWAP_32BIG_C(0x567079e5U), BSWAP_32BIG_C(0xe422e128U), BSWAP_32BIG_C(
                0x9eb22d32U),
        };
        r_rsip_func100(Param_p3a_func100_007);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p3a_func101_015[] =
            {
                BSWAP_32BIG_C(0x4d35366fU), BSWAP_32BIG_C(0x4a73afd6U), BSWAP_32BIG_C(0x1b8d0bf5U), BSWAP_32BIG_C(
                    0xd09d4423U),
            };
            r_rsip_func101(Param_p3a_func101_015);
        }
        else
        {
            static const uint32_t Param_p3a_func100_008[] =
            {
                BSWAP_32BIG_C(0xbb09a539U), BSWAP_32BIG_C(0x8a0b7a57U), BSWAP_32BIG_C(0x4a96229fU), BSWAP_32BIG_C(
                    0x581de666U),
            };
            r_rsip_func100(Param_p3a_func100_008);
            WR1_PROG(REG_1404H, 0x17780000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c000bdU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub038(0x00000018U, 0x00000428U, 0x18180010U);
            r_rsip_func_sub007(0x00000838U, 0x00000220U, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);

            r_rsip_func_sub037(0x18180000U, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000838U, 0x1818000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p3a_func100_009[] =
            {
                BSWAP_32BIG_C(0x119fc6caU), BSWAP_32BIG_C(0x886abd9eU), BSWAP_32BIG_C(0x6c0b8187U), BSWAP_32BIG_C(
                    0x30252fa7U),
            };
            r_rsip_func100(Param_p3a_func100_009);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p3a_func101_016[] =
                {
                    BSWAP_32BIG_C(0xb371d3b4U), BSWAP_32BIG_C(0x7ffc3d0fU), BSWAP_32BIG_C(0x50b47a84U), BSWAP_32BIG_C(
                        0x9e308558U),
                };
                r_rsip_func101(Param_p3a_func101_016);
                continue;
            }

            static const uint32_t Param_p3a_func100_010[] =
            {
                BSWAP_32BIG_C(0x64000d05U), BSWAP_32BIG_C(0x2d83b1bcU), BSWAP_32BIG_C(0x8d4ab7d4U), BSWAP_32BIG_C(
                    0x4697f269U),
            };
            r_rsip_func100(Param_p3a_func100_010);

            r_rsip_func_sub025(0x0000b560U, 0x00000002U, 0x0000094aU);
            WR1_PROG(REG_1608H, 0x80b0000aU);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x034300c1U);

            r_rsip_func_sub024(0x00000929U, 0x00000908U, 0x0000b4c0U, 0x000000bcU);

            for (iLoop = 0U; iLoop < 48U; iLoop++)
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

            r_rsip_func_sub033(0x15700000U, 0x0000094aU, 0x81b0000aU);
            r_rsip_func_sub001(0x00c900c1U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1014H, 0x00000630U);
                r_rsip_func_sub005(0x00000838U, 0x1818000cU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000838U, 0x00000938U, 0x00000630U, 0x18180009U);

                WR1_PROG(REG_1600H, 0x000033e0U);

                static const uint32_t Param_p3a_func101_017[] =
                {
                    BSWAP_32BIG_C(0xff8824bbU), BSWAP_32BIG_C(0x938a0094U), BSWAP_32BIG_C(0x98793950U), BSWAP_32BIG_C(
                        0x31af1027U),
                };
                r_rsip_func101(Param_p3a_func101_017);
            }

            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func_sub014(0x00007c1fU, 0x00602000U);

            static const uint32_t Param_p3a_func100_011[] =
            {
                BSWAP_32BIG_C(0xc2613d0cU), BSWAP_32BIG_C(0x63ff1dffU), BSWAP_32BIG_C(0x40a844bdU), BSWAP_32BIG_C(
                    0x578c7455U),
            };
            r_rsip_func100(Param_p3a_func100_011);
            WR1_PROG(REG_1600H, 0x00000a52U);

            r_rsip_func_sub016(0x81010160U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
                r_rsip_func_sub034(0x00000030U, 0x000008e7U, 0x11600000U);
                for (jLoop = 0U; jLoop < 48U; )
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    r_rsip_func_sub014(0x00007c07U, 0x00602000U);

                    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a04U);

                    static const uint32_t Param_p3a_func101_018[] =
                    {
                        BSWAP_32BIG_C(0x3d58d2fcU), BSWAP_32BIG_C(0xe20a94eaU), BSWAP_32BIG_C(0xac4625b4U),
                        BSWAP_32BIG_C(0xae567f62U),
                    };
                    r_rsip_func101(Param_p3a_func101_018);
                    r_rsip_func113();

                    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                    r_rsip_func_sub001(0x00c20011U);

                    WR1_PROG(REG_1600H, 0x00002485U);

                    static const uint32_t Param_p3a_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x645566d4U), BSWAP_32BIG_C(0x489f6c01U), BSWAP_32BIG_C(0x6a20dea6U),
                        BSWAP_32BIG_C(0xdc691831U),
                    };
                    r_rsip_func101(Param_p3a_func101_019);
                    jLoop = jLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func_sub011(0x38000886U);

                static const uint32_t Param_p3a_func100_012[] =
                {
                    BSWAP_32BIG_C(0x2861afb2U), BSWAP_32BIG_C(0xd011d257U), BSWAP_32BIG_C(0xc75fd5c9U), BSWAP_32BIG_C(
                        0x93e9f032U),
                };
                r_rsip_func100(Param_p3a_func100_012);
                WR1_PROG(REG_1404H, 0x19800000U);
                r_rsip_func_sub004(0x08000104U, 0x00000004U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x1818000aU);

                r_rsip_func_sub018(0x00000018U, 0x00000838U, 0x18180010U);

                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                r_rsip_func_sub005(0x00000a40U, 0x18180004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x17780000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x18180009U);

                r_rsip_func_sub038(0x00000018U, 0x00000428U, 0x18180010U);
                r_rsip_func_sub007(0x00000220U, 0x00000630U, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);

                r_rsip_func_sub037(0x18180000U, 0x00010001U);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x19800000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c000bdU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p3a_func100_013[] =
                {
                    BSWAP_32BIG_C(0x1f157361U), BSWAP_32BIG_C(0xf409a574U), BSWAP_32BIG_C(0x26408614U), BSWAP_32BIG_C(
                        0xf8822277U),
                };
                r_rsip_func100(Param_p3a_func100_013);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 0))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);

                    static const uint32_t Param_p3a_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x1d43f9b3U), BSWAP_32BIG_C(0xc1e4e0b8U), BSWAP_32BIG_C(0xb8b8ceaeU),
                        BSWAP_32BIG_C(0xfc2ff268U),
                    };
                    r_rsip_func101(Param_p3a_func101_020);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);

                    static const uint32_t Param_p3a_func100_014[] =
                    {
                        BSWAP_32BIG_C(0x03591a67U), BSWAP_32BIG_C(0x992c8e0fU), BSWAP_32BIG_C(0x682f6cc0U),
                        BSWAP_32BIG_C(0xf54e0af5U),
                    };
                    r_rsip_func100(Param_p3a_func100_014);
                    r_rsip_func_sub016(0x81010120U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                    S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);

                    for (jLoop = 0U; jLoop < S_RAM[0 + 1]; jLoop++)
                    {
                        WR1_PROG(REG_1404H, 0x19800000U);
                        WR1_PROG(REG_1608H, 0x81b0000aU);
                        r_rsip_func_sub001(0x00c900c1U);

                        r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        r_rsip_func_sub002(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);

                        WR1_PROG(REG_143CH, 0x00210000U);

                        static const uint32_t Param_p3a_func100_015[] =
                        {
                            BSWAP_32BIG_C(0x37f3161bU), BSWAP_32BIG_C(0xf0026a71U), BSWAP_32BIG_C(0xfe04bf66U),
                            BSWAP_32BIG_C(0xa1955ae4U),
                        };
                        r_rsip_func100(Param_p3a_func100_015);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 0))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);

                            static const uint32_t Param_p3a_func101_021[] =
                            {
                                BSWAP_32BIG_C(0x5fcd951fU), BSWAP_32BIG_C(0x60b609aeU), BSWAP_32BIG_C(0xbc6949ebU),
                                BSWAP_32BIG_C(0xb2112e26U),
                            };
                            r_rsip_func101(Param_p3a_func101_021);
                            break;
                        }
                        else
                        {
                            static const uint32_t Param_p3a_func100_016[] =
                            {
                                BSWAP_32BIG_C(0x00511a68U), BSWAP_32BIG_C(0x8e080e33U), BSWAP_32BIG_C(0x38626ffdU),
                                BSWAP_32BIG_C(0xccb16717U),
                            };
                            r_rsip_func100(Param_p3a_func100_016);
                            WR1_PROG(REG_1404H, 0x19800000U);
                            r_rsip_func_sub004(0x08000104U, 0x00000002U);
                            r_rsip_func_sub001(0x00c000bdU);
                            r_rsip_func_sub001(0x00c20005U);
                            r_rsip_func_sub001(0x0002000dU);

                            r_rsip_func_sub013(0x00000838U,
                                               0x00000a40U,
                                               0x00000428U,
                                               0x00000220U,
                                               0x18180000U,
                                               0x00010001U);
                            WAIT_STS(REG_1000H, 0, 0);
                            WR1_PROG(REG_143CH, 0x00000d00U);

                            r_rsip_func_sub002(0x00000220U, 0x00000938U, 0x00000838U, 0x18180009U);

                            static const uint32_t Param_p3a_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x04aeebc1U), BSWAP_32BIG_C(0x8d30a29aU), BSWAP_32BIG_C(0xd5aad5a6U),
                                BSWAP_32BIG_C(0x17bd7135U),
                            };
                            r_rsip_func101(Param_p3a_func101_022);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub006(0x38008a40U, 0x00000000U, 0x00260000U);

                    static const uint32_t Param_p3a_func100_017[] =
                    {
                        BSWAP_32BIG_C(0x73fbb88dU), BSWAP_32BIG_C(0xdf3efe15U), BSWAP_32BIG_C(0x03068327U),
                        BSWAP_32BIG_C(0x2e0a569cU),
                    };
                    r_rsip_func100(Param_p3a_func100_017);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p3a_func101_023[] =
                        {
                            BSWAP_32BIG_C(0xb58f1b0aU), BSWAP_32BIG_C(0x033a71ecU), BSWAP_32BIG_C(0xe5927baaU),
                            BSWAP_32BIG_C(0xdaf40ecdU),
                        };
                        r_rsip_func101(Param_p3a_func101_023);
                        break;
                    }
                    else
                    {
                        static const uint32_t Param_p3a_func101_024[] =
                        {
                            BSWAP_32BIG_C(0xb8dfbbacU), BSWAP_32BIG_C(0x15bf38e5U), BSWAP_32BIG_C(0x966e0c86U),
                            BSWAP_32BIG_C(0x123f036fU),
                        };
                        r_rsip_func101(Param_p3a_func101_024);
                    }
                }
            }

            r_rsip_func_sub017(0x38000a4bU, 0x00260000U);

            static const uint32_t Param_p3a_func100_018[] =
            {
                BSWAP_32BIG_C(0x367e74f9U), BSWAP_32BIG_C(0xb080ecf7U), BSWAP_32BIG_C(0xf7565210U), BSWAP_32BIG_C(
                    0x1fcea309U),
            };
            r_rsip_func100(Param_p3a_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);

                r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_p3a_func100_019[] =
                {
                    BSWAP_32BIG_C(0x6a335ea5U), BSWAP_32BIG_C(0xe60fea76U), BSWAP_32BIG_C(0x379fa5beU), BSWAP_32BIG_C(
                        0x9e430b5dU),
                };
                r_rsip_func100(Param_p3a_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p3a_func101_025[] =
                    {
                        BSWAP_32BIG_C(0xe295a76dU), BSWAP_32BIG_C(0x06a57f61U), BSWAP_32BIG_C(0x533a3207U),
                        BSWAP_32BIG_C(0x66a705c1U),
                    };
                    r_rsip_func101(Param_p3a_func101_025);
                    break;
                }
                else
                {
                    r_rsip_func_sub002(0x00000428U, 0x00000938U, 0x00000320U, 0x18180009U);

                    static const uint32_t Param_p3a_func101_026[] =
                    {
                        BSWAP_32BIG_C(0x78308bb4U), BSWAP_32BIG_C(0x03da16f3U), BSWAP_32BIG_C(0xf77ee47aU),
                        BSWAP_32BIG_C(0x5f42157bU),
                    };
                    r_rsip_func101(Param_p3a_func101_026);
                }
            }
            else
            {
                static const uint32_t Param_p3a_func101_027[] =
                {
                    BSWAP_32BIG_C(0x0e03bb03U), BSWAP_32BIG_C(0xec40616bU), BSWAP_32BIG_C(0xa00da835U), BSWAP_32BIG_C(
                        0xb585c421U),
                };
                r_rsip_func101(Param_p3a_func101_027);
            }
        }
    }

    r_rsip_func_sub006(0x38008a20U, 0x00000002U, 0x00A60000U);

    static const uint32_t Param_p3a_func100_020[] =
    {
        BSWAP_32BIG_C(0x0b36589dU), BSWAP_32BIG_C(0x16c7d192U), BSWAP_32BIG_C(0x1451d3c4U), BSWAP_32BIG_C(0xed17dec2U),
    };
    r_rsip_func100(Param_p3a_func100_020);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_001[] =
        {
            BSWAP_32BIG_C(0x55375e52U), BSWAP_32BIG_C(0xb650783cU), BSWAP_32BIG_C(0xa9abff0dU), BSWAP_32BIG_C(
                0x484622a4U),
        };
        r_rsip_func102(Param_p3a_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub001(0x00c000c1U);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000838U, 0x18180009U);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000778U, 0x18180009U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a05U);

    static const uint32_t Param_p3a_func101_028[] =
    {
        BSWAP_32BIG_C(0x30676847U), BSWAP_32BIG_C(0x0efa16b1U), BSWAP_32BIG_C(0x5676ffebU), BSWAP_32BIG_C(0x0a762bf7U),
    };
    r_rsip_func101(Param_p3a_func101_028);
    r_rsip_func113();

    static const uint32_t Param_p3a_func100_021[] =
    {
        BSWAP_32BIG_C(0xfd2b8c80U), BSWAP_32BIG_C(0x7e644763U), BSWAP_32BIG_C(0xd1bf98efU), BSWAP_32BIG_C(0xdbf9b4b8U),
    };
    r_rsip_func100(Param_p3a_func100_021);
    r_rsip_func_sub004(0x0c2000c4U, 0x00000000U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x16b80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

    static const uint32_t Param_p3a_func101_029[] =
    {
        BSWAP_32BIG_C(0x0e77e8bbU), BSWAP_32BIG_C(0x874d8e30U), BSWAP_32BIG_C(0x5e1951dbU), BSWAP_32BIG_C(0x07f8bbb8U),
    };
    r_rsip_func101(Param_p3a_func101_029);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000320U, 0x00000a40U, 0x00000220U, 0x1818000aU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000630U, 0x1818000aU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000003aU);

    static const uint32_t Param_p3a_func101_030[] =
    {
        BSWAP_32BIG_C(0x8260270cU), BSWAP_32BIG_C(0x90e434d5U), BSWAP_32BIG_C(0xf947b5e6U), BSWAP_32BIG_C(0x02e88732U),
    };
    r_rsip_func101(Param_p3a_func101_030);
    r_rsip_func313();

    WR1_PROG(REG_1404H, 0x14a00000U);
    r_rsip_func_sub001(0x00c000d1U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x16b80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

    static const uint32_t Param_p3a_func101_031[] =
    {
        BSWAP_32BIG_C(0x8d078eeaU), BSWAP_32BIG_C(0xf26917adU), BSWAP_32BIG_C(0x5b288572U), BSWAP_32BIG_C(0xc9e03745U),
    };
    r_rsip_func101(Param_p3a_func101_031);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000778U, 0x00000838U, 0x00000220U, 0x18180007U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

    static const uint32_t Param_p3a_func101_032[] =
    {
        BSWAP_32BIG_C(0x36b45b14U), BSWAP_32BIG_C(0x87ffe652U), BSWAP_32BIG_C(0xb1807ea7U), BSWAP_32BIG_C(0x380ce692U),
    };
    r_rsip_func101(Param_p3a_func101_032);
    r_rsip_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3a_func100_022[] =
    {
        BSWAP_32BIG_C(0xa5cd5aaaU), BSWAP_32BIG_C(0x14c9cb10U), BSWAP_32BIG_C(0x8a0cc2bbU), BSWAP_32BIG_C(0x5bf4a219U),
    };
    r_rsip_func100(Param_p3a_func100_022);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_002[] =
        {
            BSWAP_32BIG_C(0x15080d2bU), BSWAP_32BIG_C(0xe2fadddfU), BSWAP_32BIG_C(0x252e6cc5U), BSWAP_32BIG_C(
                0xc06338e0U),
        };
        r_rsip_func102(Param_p3a_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x12a80000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

    static const uint32_t Param_p3a_func101_033[] =
    {
        BSWAP_32BIG_C(0x89105415U), BSWAP_32BIG_C(0xf94dc8e1U), BSWAP_32BIG_C(0xd0141a2aU), BSWAP_32BIG_C(0x22b3c270U),
    };
    r_rsip_func101(Param_p3a_func101_033);
    r_rsip_func017(OFS_ADR);

    r_rsip_func_sub002(0x00000368U, 0x00000428U, 0x00000630U, 0x18180007U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x14b00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

    static const uint32_t Param_p3a_func101_034[] =
    {
        BSWAP_32BIG_C(0x8f8c5983U), BSWAP_32BIG_C(0xd54250fcU), BSWAP_32BIG_C(0x65533cfaU), BSWAP_32BIG_C(0x299284dfU),
    };
    r_rsip_func101(Param_p3a_func101_034);
    r_rsip_func016(OFS_ADR);

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c000bdU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);

    r_rsip_func_sub002(0x00000368U, 0x00000a40U, 0x00000160U, 0x1818000aU);

    r_rsip_func_sub002(0x00000160U, 0x00000220U, 0x00000428U, 0x18180007U);

    r_rsip_func_sub038(0x00000018U, 0x00000630U, 0x30300010U);
    r_rsip_func_sub007(0x00000428U, 0x00000838U, 0x00000630U);
    r_rsip_func_sub005(0x00000428U, 0x30300002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_101CH, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x30300003U, 0x00010001U);
    r_rsip_func_sub007(0x00000428U, 0x00000220U, 0x00000630U);
    r_rsip_func_sub005(0x00000220U, 0x30300002U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    WR1_PROG(REG_1404H, 0x14b00000U);
    r_rsip_func_sub004(0x08000104U, 0x00010001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

    static const uint32_t Param_p3a_func101_035[] =
    {
        BSWAP_32BIG_C(0xc067acddU), BSWAP_32BIG_C(0x56056f00U), BSWAP_32BIG_C(0x483179feU), BSWAP_32BIG_C(0x508e8eefU),
    };
    r_rsip_func101(Param_p3a_func101_035);
    r_rsip_func315();

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0017dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    r_rsip_func_sub002(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_p3a_func100_023[] =
    {
        BSWAP_32BIG_C(0x88a339c7U), BSWAP_32BIG_C(0x70f930fbU), BSWAP_32BIG_C(0x95ff6462U), BSWAP_32BIG_C(0x1b3c2de9U),
    };
    r_rsip_func100(Param_p3a_func100_023);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p3a_func102_003[] =
        {
            BSWAP_32BIG_C(0x19debb06U), BSWAP_32BIG_C(0x17f8916aU), BSWAP_32BIG_C(0xd5d4e917U), BSWAP_32BIG_C(
                0x5808c9a1U),
        };
        r_rsip_func102(Param_p3a_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_func_sub001(0x00c00181U);

    r_rsip_func_sub002(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);

    r_rsip_func_sub004(0x0b040184U, 0xc9690989U);

    OFS_ADR = 516;

    r_rsip_func_sub012(0x14b00000U, 0x0000b400U, 0x00000060U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a0fU);

    static const uint32_t Param_p3a_func101_036[] =
    {
        BSWAP_32BIG_C(0x316af1c2U), BSWAP_32BIG_C(0x9e922c9aU), BSWAP_32BIG_C(0x27e9da7aU), BSWAP_32BIG_C(0xb58403d6U),
    };
    r_rsip_func101(Param_p3a_func101_036);
    r_rsip_func017(OFS_ADR);

    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1600H, 0x00010001U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a06U);

    static const uint32_t Param_p3a_func101_037[] =
    {
        BSWAP_32BIG_C(0x3d199572U), BSWAP_32BIG_C(0x44312b67U), BSWAP_32BIG_C(0x05f7868dU), BSWAP_32BIG_C(0x61fa46ddU),
    };
    r_rsip_func101(Param_p3a_func101_037);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

    static const uint32_t Param_p3a_func101_038[] =
    {
        BSWAP_32BIG_C(0xad23284dU), BSWAP_32BIG_C(0xae5cab69U), BSWAP_32BIG_C(0xe02a6297U), BSWAP_32BIG_C(0xe46b854bU),
    };
    r_rsip_func101(Param_p3a_func101_038);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000fU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a01U);

    static const uint32_t Param_p3a_func101_039[] =
    {
        BSWAP_32BIG_C(0xc2326d5eU), BSWAP_32BIG_C(0x6a1b2be0U), BSWAP_32BIG_C(0x404b33e3U), BSWAP_32BIG_C(0x413f750dU),
    };
    r_rsip_func101(Param_p3a_func101_039);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000060U, 0x000008e7U, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_024[] =
        {
            BSWAP_32BIG_C(0xe08debdcU), BSWAP_32BIG_C(0xb04a7508U), BSWAP_32BIG_C(0x211b9fa9U), BSWAP_32BIG_C(
                0x65fc1ceeU),
        };
        r_rsip_func100(Param_p3a_func100_024);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_040[] =
        {
            BSWAP_32BIG_C(0x95b1e6a0U), BSWAP_32BIG_C(0x44aebdbeU), BSWAP_32BIG_C(0xa1a24bb9U), BSWAP_32BIG_C(
                0x9962a590U),
        };
        r_rsip_func101(Param_p3a_func101_040);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000060U, 0x000008e7U, 0x12a80000U);
    for (iLoop = 0U; iLoop < 96U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_025[] =
        {
            BSWAP_32BIG_C(0xba0c3c8aU), BSWAP_32BIG_C(0xeb1a4571U), BSWAP_32BIG_C(0xc9fd36b5U), BSWAP_32BIG_C(
                0xbcc17725U),
        };
        r_rsip_func100(Param_p3a_func100_025);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[97 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_041[] =
        {
            BSWAP_32BIG_C(0x83e4efd3U), BSWAP_32BIG_C(0x4ece69baU), BSWAP_32BIG_C(0x233b2912U), BSWAP_32BIG_C(
                0xbcbbda92U),
        };
        r_rsip_func101(Param_p3a_func101_041);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3a_func100_026[] =
    {
        BSWAP_32BIG_C(0x9f7950e9U), BSWAP_32BIG_C(0x3d3eaa6cU), BSWAP_32BIG_C(0xbaa42762U), BSWAP_32BIG_C(0x433b3ac5U),
    };
    r_rsip_func100(Param_p3a_func100_026);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PrivKeyIndex[193]);

    static const uint32_t Param_p3a_func100_027[] =
    {
        BSWAP_32BIG_C(0x2f36ed17U), BSWAP_32BIG_C(0x6aff61d7U), BSWAP_32BIG_C(0xc76cf2feU), BSWAP_32BIG_C(0x8a210309U),
    };
    r_rsip_func100(Param_p3a_func100_027);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a07U);

    static const uint32_t Param_p3a_func101_042[] =
    {
        BSWAP_32BIG_C(0x0bdd40ccU), BSWAP_32BIG_C(0xff6b7a40U), BSWAP_32BIG_C(0x9a911737U), BSWAP_32BIG_C(0x941f54daU),
    };
    r_rsip_func101(Param_p3a_func101_042);
    r_rsip_func113();

    r_rsip_func_sub004(0x0c200104U, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010000U);
    r_rsip_func_sub001(0x03420005U);
    r_rsip_func_sub001(0x0002000dU);

    WR1_PROG(REG_1600H, 0x000034e0U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

    static const uint32_t Param_p3a_func101_043[] =
    {
        BSWAP_32BIG_C(0xda7cf8c4U), BSWAP_32BIG_C(0x8556b916U), BSWAP_32BIG_C(0xeac9be31U), BSWAP_32BIG_C(0x99e5c625U),
    };
    r_rsip_func101(Param_p3a_func101_043);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x0000000eU);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00003a02U);

    static const uint32_t Param_p3a_func101_044[] =
    {
        BSWAP_32BIG_C(0x7367caf9U), BSWAP_32BIG_C(0x9ed8f8c3U), BSWAP_32BIG_C(0x24fb0e8fU), BSWAP_32BIG_C(0xbb47aa94U),
    };
    r_rsip_func101(Param_p3a_func101_044);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    r_rsip_func_sub024(0x00000884U, 0x0000b4a0U, 0x00000004U, 0x0000b4c0U);
    r_rsip_func_sub034(0x00000060U, 0x000008e7U, 0x14b00000U);
    for (iLoop = 0U; iLoop < 96U; )
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        r_rsip_func_sub014(0x00007c07U, 0x00602000U);

        static const uint32_t Param_p3a_func100_028[] =
        {
            BSWAP_32BIG_C(0xeb27ee72U), BSWAP_32BIG_C(0x965385ffU), BSWAP_32BIG_C(0x61eeb388U), BSWAP_32BIG_C(
                0x7896e9b6U),
        };
        r_rsip_func100(Param_p3a_func100_028);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_func_sub001(0x00830011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[1 + iLoop]);

        WR1_PROG(REG_1600H, 0x00002485U);

        static const uint32_t Param_p3a_func101_045[] =
        {
            BSWAP_32BIG_C(0xe3c918dfU), BSWAP_32BIG_C(0x6fa2b2e8U), BSWAP_32BIG_C(0x394cdc83U), BSWAP_32BIG_C(
                0xd1aa66b4U),
        };
        r_rsip_func101(Param_p3a_func101_045);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x38000886U);

    static const uint32_t Param_p3a_func100_029[] =
    {
        BSWAP_32BIG_C(0x472b0262U), BSWAP_32BIG_C(0x1b762b22U), BSWAP_32BIG_C(0xcda17f80U), BSWAP_32BIG_C(0x61826dccU),
    };
    r_rsip_func100(Param_p3a_func100_029);
    r_rsip_func_sub029(0x40000000U, 0xe8008104U, 0x81010280U);
    r_rsip_func_sub001(0x00890005U);

    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[97]);

    static const uint32_t Param_p3a_func100_030[] =
    {
        BSWAP_32BIG_C(0x5dc61d38U), BSWAP_32BIG_C(0xc47387c5U), BSWAP_32BIG_C(0xe719331fU), BSWAP_32BIG_C(0xcf28cb5aU),
    };
    r_rsip_func100(Param_p3a_func100_030);
    r_rsip_func_sub004(0x0c000104U, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_func_sub001(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30, 1);
    RD4_ADDR(REG_1420H, &OutData_PubKeyIndex[101]);

    static const uint32_t Param_p3a_func100_031[] =
    {
        BSWAP_32BIG_C(0x900ba014U), BSWAP_32BIG_C(0x7f8b85fbU), BSWAP_32BIG_C(0x888a1d71U), BSWAP_32BIG_C(0x0bdf52e6U),
    };
    r_rsip_func100(Param_p3a_func100_031);
    r_rsip_func_sub016(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);

    static const uint32_t Param_p3a_func102_004[] =
    {
        BSWAP_32BIG_C(0x5a4d3c3eU), BSWAP_32BIG_C(0x87a7ed15U), BSWAP_32BIG_C(0xd502b61aU), BSWAP_32BIG_C(0x06c13f95U),
    };
    r_rsip_func102(Param_p3a_func102_004);
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12, 0);

    return RSIP_RET_PASS;
}
