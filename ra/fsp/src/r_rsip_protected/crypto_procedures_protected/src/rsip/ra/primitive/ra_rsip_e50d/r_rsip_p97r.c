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

rsip_ret_t r_rsip_p97r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_State[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00970001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_State[1]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97r_func100_001[] =
    {
        BSWAP_32BIG_C(0xb0150031U), BSWAP_32BIG_C(0x266de274U), BSWAP_32BIG_C(0x1e2c74fcU), BSWAP_32BIG_C(0x66d80c53U),
    };
    r_rsip_func100(Param_p97r_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97r_func102_001[] =
        {
            BSWAP_32BIG_C(0x5590a46eU), BSWAP_32BIG_C(0xf316ad65U), BSWAP_32BIG_C(0x86315a0fU), BSWAP_32BIG_C(
                0x2459feb7U),
        };
        r_rsip_func102(Param_p97r_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WAIT_STS(REG_1C30H, 8, 0);
        WR1_PROG(REG_143CH, 0x00001c00U);

        static const uint32_t Param_p97r_func100_002[] =
        {
            BSWAP_32BIG_C(0x2b33b59aU), BSWAP_32BIG_C(0x811173c2U), BSWAP_32BIG_C(0xa9f95a3fU), BSWAP_32BIG_C(
                0xa490243bU),
        };
        r_rsip_func100(Param_p97r_func100_002);
        WR1_PROG(REG_1C00H, 0x00000001U);

        WR1_PROG(REG_1C04H, 0x00001001U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00003467U);

        r_rsip_func_sub003(0x800103a0U, 0x00009702U);

        static const uint32_t Param_p97r_func101_001[] =
        {
            BSWAP_32BIG_C(0xe83e9fd7U), BSWAP_32BIG_C(0x8f38b103U), BSWAP_32BIG_C(0x491ebdb2U), BSWAP_32BIG_C(
                0xccd5fd69U),
        };
        r_rsip_func101(Param_p97r_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000030U);

        r_rsip_func_sub003(0x800103a0U, 0x00009702U);

        static const uint32_t Param_p97r_func101_002[] =
        {
            BSWAP_32BIG_C(0x1505ed1fU), BSWAP_32BIG_C(0x7e1bac1cU), BSWAP_32BIG_C(0x71927473U), BSWAP_32BIG_C(
                0x1d2bad84U),
        };
        r_rsip_func101(Param_p97r_func101_002);
        r_rsip_func044();

        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

        r_rsip_func_sub001(0x01c20021U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p97r_func100_003[] =
        {
            BSWAP_32BIG_C(0x04c2fcb8U), BSWAP_32BIG_C(0xd4088d68U), BSWAP_32BIG_C(0x318abd09U), BSWAP_32BIG_C(
                0x0dda7716U),
        };
        r_rsip_func100(Param_p97r_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97r_func102_002[] =
            {
                BSWAP_32BIG_C(0x00467fcaU), BSWAP_32BIG_C(0xf5ab1aacU), BSWAP_32BIG_C(0xd72c0847U), BSWAP_32BIG_C(
                    0xc3fe48b7U),
            };
            r_rsip_func102(Param_p97r_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010000U);
            WR1_PROG(REG_1420H, InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1C04H, 0x00010011U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C10H, InData_State[1]);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C14H, InData_State[2]);

            WR1_PROG(REG_1C04H, 0x00010010U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C08H, InData_State[0]);

            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p97r_func100_004[] =
            {
                BSWAP_32BIG_C(0xd8d9496aU), BSWAP_32BIG_C(0xb2f24522U), BSWAP_32BIG_C(0x6c53fffeU), BSWAP_32BIG_C(
                    0x7a7d03b9U),
            };
            r_rsip_func100(Param_p97r_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);

                static const uint32_t Param_p97r_func101_003[] =
                {
                    BSWAP_32BIG_C(0x39321f0fU), BSWAP_32BIG_C(0x1493eafbU), BSWAP_32BIG_C(0x4d394adfU), BSWAP_32BIG_C(
                        0x82cac298U),
                };
                r_rsip_func101(Param_p97r_func101_003);
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);

                static const uint32_t Param_p97r_func101_004[] =
                {
                    BSWAP_32BIG_C(0xae857e10U), BSWAP_32BIG_C(0x9cf6dcdbU), BSWAP_32BIG_C(0xdf92dbd9U), BSWAP_32BIG_C(
                        0x137311d1U),
                };
                r_rsip_func101(Param_p97r_func101_004);
            }

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[2]);

            for (iLoop = 3; iLoop < 10U; iLoop++)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_PROG(REG_1C28H, InData_State[iLoop]);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1600H, 0x000034e3U);

            r_rsip_func_sub003(0x800103a0U, 0x00009703U);

            static const uint32_t Param_p97r_func101_005[] =
            {
                BSWAP_32BIG_C(0xbb3aecc3U), BSWAP_32BIG_C(0x13711d4fU), BSWAP_32BIG_C(0x49da9bdcU), BSWAP_32BIG_C(
                    0xf434fe79U),
            };
            r_rsip_func101(Param_p97r_func101_005);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x0121608eU);

            r_rsip_func_sub003(0x800103a0U, 0x00009703U);

            static const uint32_t Param_p97r_func101_006[] =
            {
                BSWAP_32BIG_C(0x69de8240U), BSWAP_32BIG_C(0xad177b5cU), BSWAP_32BIG_C(0x99c6b27cU), BSWAP_32BIG_C(
                    0x0bd08a4dU),
            };
            r_rsip_func101(Param_p97r_func101_006);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000c2U, 0x40000000U, 0xe8009104U);
            WR1_PROG(REG_1420H, InData_State[11]);

            WR1_PROG(REG_1608H, 0x80010040U);
            r_rsip_func_sub001(0x03420005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_State[12]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p97r_func100_005[] =
            {
                BSWAP_32BIG_C(0x01788cb2U), BSWAP_32BIG_C(0x3336d536U), BSWAP_32BIG_C(0x26429a72U), BSWAP_32BIG_C(
                    0xb2a10319U),
            };
            r_rsip_func100(Param_p97r_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p97r_func102_003[] =
                {
                    BSWAP_32BIG_C(0xfc31c37fU), BSWAP_32BIG_C(0x15efab87U), BSWAP_32BIG_C(0x57e6e196U), BSWAP_32BIG_C(
                        0xfc5ff628U),
                };
                r_rsip_func102(Param_p97r_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p97r_func100_006[] =
                {
                    BSWAP_32BIG_C(0x5d0e9895U), BSWAP_32BIG_C(0x3bde65f6U), BSWAP_32BIG_C(0x7fbfd892U), BSWAP_32BIG_C(
                        0x99266432U),
                };
                r_rsip_func100(Param_p97r_func100_006);
                r_rsip_func_sub016(0x81010040U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub006(0x38008840U, 0x00000001U, 0x00260000U);

                static const uint32_t Param_p97r_func100_007[] =
                {
                    BSWAP_32BIG_C(0x786012cdU), BSWAP_32BIG_C(0x2b310c36U), BSWAP_32BIG_C(0x948a7bd5U), BSWAP_32BIG_C(
                        0xf0c22467U),
                };
                r_rsip_func100(Param_p97r_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p97r_func101_007[] =
                    {
                        BSWAP_32BIG_C(0x6bd9b2c6U), BSWAP_32BIG_C(0xf162fc04U), BSWAP_32BIG_C(0xba2a4a7bU),
                        BSWAP_32BIG_C(0x20c0adc5U),
                    };
                    r_rsip_func101(Param_p97r_func101_007);

                    return RSIP_RET_PASS_1;
                }
                else
                {
                    static const uint32_t Param_p97r_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x0a2959b1U), BSWAP_32BIG_C(0x43b10899U), BSWAP_32BIG_C(0x360612a9U),
                        BSWAP_32BIG_C(0x9693cad7U),
                    };
                    r_rsip_func101(Param_p97r_func101_008);

                    return RSIP_RET_PASS_2;
                }
            }
        }
    }
}
