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

rsip_ret_t r_rsip_p6f (const uint32_t InData_LC[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x006f0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub006(0x3420a800U, 0x0000000aU, 0x00A60000U);

    r_rsip_func_sub006(0x38008800U, 0x00000002U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000003U, 0x00260000U);

    r_rsip_func_sub006(0x38008800U, 0x00000005U, 0x00260000U);

    r_rsip_func_sub006(0x3420a880U, 0x00000005U, 0x00260000U);

    r_rsip_func_sub021(0x00000bffU, 0x3000a880U, 0x00000031U, 0x00010020U);
    r_rsip_func_sub022(0x38008880U, 0x000000feU, 0x200053e0U);
    r_rsip_func_sub006(0x00000080U, 0x38000fffU, 0x00A60000U);

    static const uint32_t Param_p6f_func100_001[] =
    {
        BSWAP_32BIG_C(0x2af0938fU), BSWAP_32BIG_C(0x2b2e1a35U), BSWAP_32BIG_C(0xb08eac75U), BSWAP_32BIG_C(0x0a8209a1U),
    };
    r_rsip_func100(Param_p6f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p6f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc27d960fU), BSWAP_32BIG_C(0xb72d0e04U), BSWAP_32BIG_C(0xde58a50fU), BSWAP_32BIG_C(
                0xc43d8ed1U),
        };
        r_rsip_func102(Param_p6f_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, S_INST2[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x800103a0U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_001[] =
        {
            BSWAP_32BIG_C(0xe50f6002U), BSWAP_32BIG_C(0xfacc4395U), BSWAP_32BIG_C(0x0af5221eU), BSWAP_32BIG_C(
                0xead04a75U),
        };
        r_rsip_func101(Param_p6f_func101_001);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x000000ffU);

        r_rsip_func_sub003(0x800103a0U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_002[] =
        {
            BSWAP_32BIG_C(0x36afbad5U), BSWAP_32BIG_C(0xf81d945aU), BSWAP_32BIG_C(0x2561308aU), BSWAP_32BIG_C(
                0x4f6f5627U),
        };
        r_rsip_func101(Param_p6f_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p6f_func100_002[] =
        {
            BSWAP_32BIG_C(0x37f30ac5U), BSWAP_32BIG_C(0x75212a82U), BSWAP_32BIG_C(0x056a8b10U), BSWAP_32BIG_C(
                0xb78017bbU),
        };
        r_rsip_func100(Param_p6f_func100_002);
        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 5]);

        WR1_PROG(REG_1824H, 0x08000085U);
        r_rsip_func_sub001(0x00420011U);

        static const uint32_t Param_p6f_func100_003[] =
        {
            BSWAP_32BIG_C(0x71a6d22bU), BSWAP_32BIG_C(0x9f32e2beU), BSWAP_32BIG_C(0xa66fbb19U), BSWAP_32BIG_C(
                0xdd1ef0d8U),
        };
        r_rsip_func100(Param_p6f_func100_003);
        WR1_PROG(REG_1824H, 0x08000095U);
        r_rsip_func_sub001(0x00420011U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &S_INST2[0 + 9]);

        WR1_PROG(REG_1A24H, 0x8c100005U);
        r_rsip_func_sub001(0x00820011U);

        r_rsip_func_sub003(0x80010380U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_003[] =
        {
            BSWAP_32BIG_C(0x98da1074U), BSWAP_32BIG_C(0x58f92990U), BSWAP_32BIG_C(0xd35e17d3U), BSWAP_32BIG_C(
                0x3185cd7bU),
        };
        r_rsip_func101(Param_p6f_func101_003);
        r_rsip_func057(InData_IV, InData_InstData, OutData_KeyIndex);

        static const uint32_t Param_p6f_func100_004[] =
        {
            BSWAP_32BIG_C(0x30e04173U), BSWAP_32BIG_C(0xea6e2476U), BSWAP_32BIG_C(0x48aa88adU), BSWAP_32BIG_C(
                0x0193b5b7U),
        };
        r_rsip_func100(Param_p6f_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p6f_func102_002[] =
            {
                BSWAP_32BIG_C(0xced94e07U), BSWAP_32BIG_C(0xee2b7843U), BSWAP_32BIG_C(0x03ef9ce3U), BSWAP_32BIG_C(
                    0x97c5bff8U),
            };
            r_rsip_func102(Param_p6f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p6f_func100_005[] =
            {
                BSWAP_32BIG_C(0x305b75f8U), BSWAP_32BIG_C(0x632c0526U), BSWAP_32BIG_C(0x6dbb827fU), BSWAP_32BIG_C(
                    0x0728db73U),
            };
            r_rsip_func100(Param_p6f_func100_005);
            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

            static const uint32_t Param_p6f_func102_003[] =
            {
                BSWAP_32BIG_C(0x15944db0U), BSWAP_32BIG_C(0x864cdea2U), BSWAP_32BIG_C(0x5080a1f3U), BSWAP_32BIG_C(
                    0x5966ea9fU),
            };
            r_rsip_func102(Param_p6f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
