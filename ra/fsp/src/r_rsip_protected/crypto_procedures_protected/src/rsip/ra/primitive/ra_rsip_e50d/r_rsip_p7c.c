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

rsip_ret_t r_rsip_p7c (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }
    else
    {
        ;
    }

    r_rsip_func_sub029(0x007c0001U, 0x00000e50U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000007cU);

    static const uint32_t Param_p7c_func101_001[] =
    {
        BSWAP_32BIG_C(0x362e9ad8U), BSWAP_32BIG_C(0x04a83840U), BSWAP_32BIG_C(0x4f7f1e2fU), BSWAP_32BIG_C(0xd6b96791U),
    };
    r_rsip_func101(Param_p7c_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000011U);

    r_rsip_func_sub003(0x800103a0U, 0x0000007cU);

    static const uint32_t Param_p7c_func101_002[] =
    {
        BSWAP_32BIG_C(0xfce9d75eU), BSWAP_32BIG_C(0x21347283U), BSWAP_32BIG_C(0x46ea3918U), BSWAP_32BIG_C(0x07a3bfa2U),
    };
    r_rsip_func101(Param_p7c_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x0000ffc2U, 0x40001f00U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x14300000U);
    for (iLoop = 0U; iLoop < 128U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1A2CH, 0x40001f00U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);

    WR1_PROG(REG_1404H, 0x12280000U);
    for (iLoop = 128U; iLoop < 256U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        r_rsip_func_sub001(0x00c20021U);
        iLoop = iLoop + 8U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p7c_func100_001[] =
    {
        BSWAP_32BIG_C(0xe5f4a65dU), BSWAP_32BIG_C(0x31889f37U), BSWAP_32BIG_C(0x3b190fecU), BSWAP_32BIG_C(0x3be25c17U),
    };
    r_rsip_func100(Param_p7c_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7c_func102_001[] =
        {
            BSWAP_32BIG_C(0xc1b673d3U), BSWAP_32BIG_C(0xb8978998U), BSWAP_32BIG_C(0xd635a110U), BSWAP_32BIG_C(
                0x854b8e4cU),
        };
        r_rsip_func102(Param_p7c_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub018(0x00000020U, 0x00000630U, 0x40400010U);

        r_rsip_func_sub024(0x00007fc2U, 0x40001f00U, 0x08008107U);

        WR1_PROG(REG_1404H, 0x10200000U);
        for (iLoop = 0U; iLoop < 128U; )
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
            r_rsip_func_sub001(0x00c20021U);
            iLoop = iLoop + 8U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        r_rsip_func_sub001(0x00030005U);
        r_rsip_func_sub001(0x03430005U);

        r_rsip_func_sub017(0x3800dbe0U, 0x00260000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000a40U, 0x00000220U, 0x00000838U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00a10000U);

        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c001fdU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000630U, 0x00000a40U, 0x00000838U, 0x4040000aU);

        r_rsip_func_sub002(0x00000838U, 0x00000220U, 0x00000a40U, 0x4040000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p7c_func100_002[] =
        {
            BSWAP_32BIG_C(0x89399558U), BSWAP_32BIG_C(0x15cc5ee4U), BSWAP_32BIG_C(0xad83de04U), BSWAP_32BIG_C(
                0x5c82fb11U),
        };
        r_rsip_func100(Param_p7c_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7c_func102_002[] =
            {
                BSWAP_32BIG_C(0x1057cb7bU), BSWAP_32BIG_C(0x12345758U), BSWAP_32BIG_C(0x66c4e385U), BSWAP_32BIG_C(
                    0xc45ec2bfU),
            };
            r_rsip_func102(Param_p7c_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7c_func100_003[] =
            {
                BSWAP_32BIG_C(0x0a4dc214U), BSWAP_32BIG_C(0x6c3f140fU), BSWAP_32BIG_C(0xa3ecde91U), BSWAP_32BIG_C(
                    0x87ac39d9U),
            };
            r_rsip_func100(Param_p7c_func100_003);
            r_rsip_func_sub013(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x40400000U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000bffU, 0x0000b400U, 0x00000080U);

            WR1_PROG(REG_1404H, 0x16380000U);

            for (iLoop = 0U; iLoop < 128U; )
            {
                r_rsip_func_sub022(0x00000bdeU, 0x34202be0U, 0x2000d3c0U);

                r_rsip_func_sub014(0x00007c1eU, 0x00602000U);

                static const uint32_t Param_p7c_func100_004[] =
                {
                    BSWAP_32BIG_C(0xcc4cef5bU), BSWAP_32BIG_C(0x5261e04aU), BSWAP_32BIG_C(0x2ca4a0e5U), BSWAP_32BIG_C(
                        0x7ab37fa7U),
                };
                r_rsip_func100(Param_p7c_func100_004);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_func_sub001(0x00830021U);

                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop]);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);

                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                static const uint32_t Param_p7c_func101_003[] =
                {
                    BSWAP_32BIG_C(0x481d6c36U), BSWAP_32BIG_C(0xd7d44a2cU), BSWAP_32BIG_C(0xdb5658c6U), BSWAP_32BIG_C(
                        0xc565db94U),
                };
                r_rsip_func101(Param_p7c_func101_003);
                iLoop = iLoop + 8U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000be0U);

            static const uint32_t Param_p7c_func100_005[] =
            {
                BSWAP_32BIG_C(0x7dec56faU), BSWAP_32BIG_C(0xf4139241U), BSWAP_32BIG_C(0x79efc7b8U), BSWAP_32BIG_C(
                    0x41cb3d1bU),
            };
            r_rsip_func100(Param_p7c_func100_005);
            WR1_PROG(REG_1408H, 0x00020000U);

            static const uint32_t Param_p7c_func102_003[] =
            {
                BSWAP_32BIG_C(0xfcf441cfU), BSWAP_32BIG_C(0xe0243144U), BSWAP_32BIG_C(0x3a8e946aU), BSWAP_32BIG_C(
                    0x7e6fc8a2U),
            };
            r_rsip_func102(Param_p7c_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
