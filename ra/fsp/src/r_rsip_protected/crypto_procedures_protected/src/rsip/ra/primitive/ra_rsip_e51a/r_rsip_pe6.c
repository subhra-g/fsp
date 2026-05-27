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

rsip_ret_t r_rsip_pe6 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataLength[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e60001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x3000a880U, 0x00000003U, 0x00010020U, 0x0000b480U);
    r_rsip_func_sub024(0x00000002U, 0x00000080U, 0x30003080U, 0x00070020U);
    r_rsip_func_sub024(0x0000b4c0U, 0x00000002U, 0x0000b4e0U, 0x00000020U);

    r_rsip_func_sub024(0x0000b460U, 0x0000000dU, 0x0000b680U, 0x01b41ce9U);
    r_rsip_func_sub024(0x00030040U, 0x0000b4c0U, 0x00000002U, 0x0000b4e0U);
    r_rsip_func_sub024(0x00000030U, 0x0000b460U, 0x00000011U, 0x0000b680U);
    r_rsip_func_sub024(0x0199f119U, 0x00050040U, 0x0000b4c0U, 0x00000001U);

    r_rsip_func_sub024(0x0000b4e0U, 0x00000040U, 0x0000b460U, 0x00000015U);

    r_rsip_func_sub025(0x0000b680U, 0x01b4cab0U, 0x00000080U);

    r_rsip_func_sub010(0x000000c7U, 0x800100a0U);
    WR1_PROG(REG_1420H, InData_KDFInfo_Count[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000ca5U, 0x00260000U);

    r_rsip_func_sub017(0x342028c5U, 0x00260000U);

    static const uint32_t Param_pe6_func100_001[] =
    {
        BSWAP_32BIG_C(0x86fc6261U), BSWAP_32BIG_C(0x73413f58U), BSWAP_32BIG_C(0x024cd898U), BSWAP_32BIG_C(0x9da756c8U),
    };
    r_rsip_func100(Param_pe6_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe6_func102_001[] =
        {
            BSWAP_32BIG_C(0x74346ae0U), BSWAP_32BIG_C(0x2823702fU), BSWAP_32BIG_C(0x5196d508U), BSWAP_32BIG_C(
                0x6cd6abc2U),
        };
        r_rsip_func102(Param_pe6_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_1420H, InData_OutDataLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub024(0x300030a0U, 0x00030020U, 0x00003547U, 0x00000060U);
        WR1_PROG(REG_1600H, 0x0000b540U);
        WR1_PROG(REG_1600H, 0x00000040U);

        r_rsip_func_sub006(0x00000080U, 0x342028c7U, 0x00260000U);

        r_rsip_func_sub017(0x34202946U, 0x00260000U);

        static const uint32_t Param_pe6_func100_002[] =
        {
            BSWAP_32BIG_C(0x4be3e91fU), BSWAP_32BIG_C(0x3ca3b0f1U), BSWAP_32BIG_C(0x4ccae43cU), BSWAP_32BIG_C(
                0xc7db144eU),
        };
        r_rsip_func100(Param_pe6_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe6_func102_002[] =
            {
                BSWAP_32BIG_C(0x09b0f5b5U), BSWAP_32BIG_C(0x5bb2b55dU), BSWAP_32BIG_C(0x61eb8d8bU), BSWAP_32BIG_C(
                    0x902b2564U),
            };
            r_rsip_func102(Param_pe6_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe6_func100_003[] =
            {
                BSWAP_32BIG_C(0x71ac79acU), BSWAP_32BIG_C(0xd98054ffU), BSWAP_32BIG_C(0x755acf41U), BSWAP_32BIG_C(
                    0x5fa060e1U),
            };
            r_rsip_func100(Param_pe6_func100_003);
            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            static const uint32_t Param_pe6_func100_004[] =
            {
                BSWAP_32BIG_C(0xaed15345U), BSWAP_32BIG_C(0xe647ff87U), BSWAP_32BIG_C(0xfe9d70d4U), BSWAP_32BIG_C(
                    0x159524a7U),
            };
            r_rsip_func100(Param_pe6_func100_004);
            r_rsip_func_sub016(0x81010060U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);
            OFS_ADR      = S_RAM[0 + 1];

            r_rsip_func_sub024(0x00000908U, 0x00000929U, 0x000009ceU, 0x000009efU);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x34202905U);
                WR1_PROG(REG_1600H, 0x2000d1e0U);
                r_rsip_func_sub014(0x00007c0fU, 0x00602000U);
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KDFInfo[iLoop * OFS_ADR]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e601U);

                static const uint32_t Param_pe6_func101_001[] =
                {
                    BSWAP_32BIG_C(0x2600618eU), BSWAP_32BIG_C(0xfd61db2cU), BSWAP_32BIG_C(0xf31ea1c0U), BSWAP_32BIG_C(
                        0x05799483U),
                };
                r_rsip_func101(Param_pe6_func101_001);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x01799093U);
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e601U);

                static const uint32_t Param_pe6_func101_002[] =
                {
                    BSWAP_32BIG_C(0x5d60f3faU), BSWAP_32BIG_C(0x2db9487aU), BSWAP_32BIG_C(0xe10967efU), BSWAP_32BIG_C(
                        0xfa6b512eU),
                };
                r_rsip_func101(Param_pe6_func101_002);
                r_rsip_func044();

                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000842U);

                for (jLoop = 0U; jLoop < OFS_ADR - 5; )
                {
                    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                    WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                    WR1_PROG(REG_1608H, 0x80840009U);
                    r_rsip_func_sub001(0x03420011U);

                    r_rsip_func_sub024(0x0000a520U, 0x00000010U, 0x0000a440U, 0x00000004U);

                    static const uint32_t Param_pe6_func101_003[] =
                    {
                        BSWAP_32BIG_C(0x60b34839U), BSWAP_32BIG_C(0xf4f4d07cU), BSWAP_32BIG_C(0x5dbcf28bU),
                        BSWAP_32BIG_C(0x3e5f6892U),
                    };
                    r_rsip_func101(Param_pe6_func101_003);
                    jLoop = jLoop + 4U;
                }

                r_rsip_func_sub039(0x000037e3U, 0x0000abe0U);
                r_rsip_func_sub006(0x00000005U, 0x38000be2U, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1600H, 0x00002d00U);

                static const uint32_t Param_pe6_func100_005[] =
                {
                    BSWAP_32BIG_C(0x0afd354dU), BSWAP_32BIG_C(0xc30bbd44U), BSWAP_32BIG_C(0xf1ce9ac0U), BSWAP_32BIG_C(
                        0x1b2b7350U),
                };
                r_rsip_func100(Param_pe6_func100_005);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x0000d1c0U);
                    static const uint32_t Param_pe6_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xd23de98cU), BSWAP_32BIG_C(0xdc9fde27U), BSWAP_32BIG_C(0x5561a79eU),
                        BSWAP_32BIG_C(0xf911f5eeU),
                    };
                    r_rsip_func101(Param_pe6_func101_004);
                }
                else
                {
                    static const uint32_t Param_pe6_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xbe0b111cU), BSWAP_32BIG_C(0x9774077dU), BSWAP_32BIG_C(0xe1b9ba3fU),
                        BSWAP_32BIG_C(0x2f1f9d4fU),
                    };
                    r_rsip_func101(Param_pe6_func101_005);
                }

                WR1_PROG(REG_1458H, 0x00000000U);
            }

            r_rsip_func_sub011(0x38000905U);

            r_rsip_func_sub017(0x38000dceU, 0x00A60000U);
            static const uint32_t Param_pe6_func100_006[] =
            {
                BSWAP_32BIG_C(0xe53c68e9U), BSWAP_32BIG_C(0x190addaeU), BSWAP_32BIG_C(0x292144a6U), BSWAP_32BIG_C(
                    0x5242f435U),
            };
            r_rsip_func100(Param_pe6_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe6_func102_003[] =
                {
                    BSWAP_32BIG_C(0xb8d7f1c4U), BSWAP_32BIG_C(0x471e9524U), BSWAP_32BIG_C(0x2e5f6656U), BSWAP_32BIG_C(
                        0x1066d94dU),
                };
                r_rsip_func102(Param_pe6_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe6_func100_007[] =
                {
                    BSWAP_32BIG_C(0x745c3c70U), BSWAP_32BIG_C(0x1988cc90U), BSWAP_32BIG_C(0x7a9fbd1fU), BSWAP_32BIG_C(
                        0x6d6dec98U),
                };
                r_rsip_func100(Param_pe6_func100_007);
                r_rsip_func_sub016(0x810100c0U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub024(0x0000094aU, 0x0000b560U, 0x00000040U, 0x00002966U);

                WR1_PROG(REG_1600H, 0x00000908U);
                WR1_PROG(REG_1600H, 0x00003526U);

                for (iLoop = S_RAM[0]; iLoop < 64U; iLoop++)
                {
                    r_rsip_func_sub025(0x02003d49U, 0x00002d00U, 0x00002d20U);
                    static const uint32_t Param_pe6_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x8598ab1aU), BSWAP_32BIG_C(0xa1d4fab4U), BSWAP_32BIG_C(0x31fe2d86U),
                        BSWAP_32BIG_C(0x29c272dbU),
                    };
                    r_rsip_func101(Param_pe6_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x3800090bU);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000e6U);

                static const uint32_t Param_pe6_func101_007[] =
                {
                    BSWAP_32BIG_C(0xf9f9cfd4U), BSWAP_32BIG_C(0x3681b8b3U), BSWAP_32BIG_C(0xe81449d0U), BSWAP_32BIG_C(
                        0x599f8951U),
                };
                r_rsip_func101(Param_pe6_func101_007);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e602U);

                static const uint32_t Param_pe6_func101_008[] =
                {
                    BSWAP_32BIG_C(0xd7a83816U), BSWAP_32BIG_C(0xc165a7bdU), BSWAP_32BIG_C(0x6b34c42cU), BSWAP_32BIG_C(
                        0x33ef8033U),
                };
                r_rsip_func101(Param_pe6_func101_008);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034f4U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e602U);

                static const uint32_t Param_pe6_func101_009[] =
                {
                    BSWAP_32BIG_C(0x9ec70516U), BSWAP_32BIG_C(0x279ab210U), BSWAP_32BIG_C(0x4afd0185U), BSWAP_32BIG_C(
                        0x971c06bdU),
                };
                r_rsip_func101(Param_pe6_func101_009);
                r_rsip_func044();

                static const uint32_t Param_pe6_func100_008[] =
                {
                    BSWAP_32BIG_C(0x5b824665U), BSWAP_32BIG_C(0x31202ed1U), BSWAP_32BIG_C(0x929e7270U), BSWAP_32BIG_C(
                        0x17a91801U),
                };
                r_rsip_func100(Param_pe6_func100_008);
                WR1_PROG(REG_1600H, 0x00000929U);
                r_rsip_func_sub029(0x40000100U, 0xe7009d07U, 0x81900009U);
                r_rsip_func_sub001(0x00890021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                static const uint32_t Param_pe6_func100_009[] =
                {
                    BSWAP_32BIG_C(0x03e2f623U), BSWAP_32BIG_C(0x9931a480U), BSWAP_32BIG_C(0xdd19d07aU), BSWAP_32BIG_C(
                        0xb96ead96U),
                };
                r_rsip_func100(Param_pe6_func100_009);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7008d07U);
                r_rsip_func_sub001(0x00890021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[13]);

                static const uint32_t Param_pe6_func100_010[] =
                {
                    BSWAP_32BIG_C(0x05855d7aU), BSWAP_32BIG_C(0x59e3f930U), BSWAP_32BIG_C(0xa1cc8cd3U), BSWAP_32BIG_C(
                        0xe596233bU),
                };
                r_rsip_func100(Param_pe6_func100_010);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[17]);

                static const uint32_t Param_pe6_func100_011[] =
                {
                    BSWAP_32BIG_C(0x0c3a9da3U), BSWAP_32BIG_C(0xce12cd51U), BSWAP_32BIG_C(0x40140142U), BSWAP_32BIG_C(
                        0x2d298f8eU),
                };
                r_rsip_func100(Param_pe6_func100_011);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe6_func102_004[] =
                {
                    BSWAP_32BIG_C(0x7b06b4eeU), BSWAP_32BIG_C(0xfd66a282U), BSWAP_32BIG_C(0xbb25d0ffU), BSWAP_32BIG_C(
                        0xe5dd99f1U),
                };
                r_rsip_func102(Param_pe6_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
