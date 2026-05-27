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

rsip_ret_t r_rsip_p97i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataALen[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00970001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p97i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb0150031U), BSWAP_32BIG_C(0x266de274U), BSWAP_32BIG_C(0x1e2c74fcU), BSWAP_32BIG_C(0x66d80c53U),
    };
    r_rsip_func100(Param_p97i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p97i_func102_001[] =
        {
            BSWAP_32BIG_C(0x5590a46eU), BSWAP_32BIG_C(0xf316ad65U), BSWAP_32BIG_C(0x86315a0fU), BSWAP_32BIG_C(
                0x2459feb7U),
        };
        r_rsip_func102(Param_p97i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p97i_func100_002[] =
        {
            BSWAP_32BIG_C(0x9defdc3aU), BSWAP_32BIG_C(0x19c22e12U), BSWAP_32BIG_C(0x2afca4bdU), BSWAP_32BIG_C(
                0x58aa46efU),
        };
        r_rsip_func100(Param_p97i_func100_002);
        WR1_PROG(REG_1C00H, 0x00000001U);

        WR1_PROG(REG_1C04H, 0x00001001U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1600H, 0x00003467U);

        r_rsip_func_sub003(0x800103a0U, 0x00009701U);

        static const uint32_t Param_p97i_func101_001[] =
        {
            BSWAP_32BIG_C(0xd1cee385U), BSWAP_32BIG_C(0x4e3957c1U), BSWAP_32BIG_C(0xe5df63f6U), BSWAP_32BIG_C(
                0x7ebe6e0aU),
        };
        r_rsip_func101(Param_p97i_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x00000030U);

        r_rsip_func_sub003(0x800103a0U, 0x00009701U);

        static const uint32_t Param_p97i_func101_002[] =
        {
            BSWAP_32BIG_C(0x75559f0bU), BSWAP_32BIG_C(0x4884ec64U), BSWAP_32BIG_C(0x996855bbU), BSWAP_32BIG_C(
                0x304b298aU),
        };
        r_rsip_func101(Param_p97i_func101_002);
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

        static const uint32_t Param_p97i_func100_003[] =
        {
            BSWAP_32BIG_C(0x6199e6e1U), BSWAP_32BIG_C(0x19b91040U), BSWAP_32BIG_C(0x10972b6cU), BSWAP_32BIG_C(
                0x06c3181eU),
        };
        r_rsip_func100(Param_p97i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p97i_func102_002[] =
            {
                BSWAP_32BIG_C(0x475894a4U), BSWAP_32BIG_C(0xc116412cU), BSWAP_32BIG_C(0xa4ec260aU), BSWAP_32BIG_C(
                    0x952bef6eU),
            };
            r_rsip_func102(Param_p97i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010000U);
            WR1_PROG(REG_1420H, InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c00U, 0x00260000U);

            static const uint32_t Param_p97i_func100_004[] =
            {
                BSWAP_32BIG_C(0x1a847c62U), BSWAP_32BIG_C(0x24d4a834U), BSWAP_32BIG_C(0xbea480c0U), BSWAP_32BIG_C(
                    0xd2d85c64U),
            };
            r_rsip_func100(Param_p97i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1C04H, 0x00000011U);

                static const uint32_t Param_p97i_func101_003[] =
                {
                    BSWAP_32BIG_C(0x6439928dU), BSWAP_32BIG_C(0xb2fafb1eU), BSWAP_32BIG_C(0xcf09bea5U), BSWAP_32BIG_C(
                        0xab940f06U),
                };
                r_rsip_func101(Param_p97i_func101_003);
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00000031U);

                static const uint32_t Param_p97i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x291896a1U), BSWAP_32BIG_C(0x0566e9a9U), BSWAP_32BIG_C(0x9e51e11aU), BSWAP_32BIG_C(
                        0x67cc6911U),
                };
                r_rsip_func101(Param_p97i_func101_004);
            }

            static const uint32_t Param_p97i_func100_005[] =
            {
                BSWAP_32BIG_C(0xfde48defU), BSWAP_32BIG_C(0x5b7a3477U), BSWAP_32BIG_C(0xe986c942U), BSWAP_32BIG_C(
                    0x9b3ead54U),
            };
            r_rsip_func100(Param_p97i_func100_005);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C10H, InData_TextLen[0]);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C14H, InData_DataALen[0]);

            WR1_PROG(REG_1C08H, 0x00000000U);

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_1C0CH, InData_Nonce[2]);

            WAIT_STS(REG_1C30H, 0, 1);

            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000001U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            static const uint32_t Param_p97i_func101_005[] =
            {
                BSWAP_32BIG_C(0x5e32a39fU), BSWAP_32BIG_C(0x7974cc0bU), BSWAP_32BIG_C(0x394b359dU), BSWAP_32BIG_C(
                    0x72083e7bU),
            };
            r_rsip_func101(Param_p97i_func101_005);

            return RSIP_RET_PASS;
        }
    }
}
