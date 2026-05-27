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

rsip_ret_t r_rsip_p58f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2440H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020065U);

    for (iLoop = 0U; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); )
    {
        WAIT_STS(REG_1444H, 31, 1);
        for (jLoop = 0U; jLoop < S_RAM[0]; )
        {
            WR2_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop]);
            jLoop = jLoop + 2;
        }

        iLoop = iLoop + S_RAM[0];
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001400U);

    WAIT_STS(REG_2440H, 4, 1);

    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p58f_func100_001[] =
    {
        BSWAP_32BIG_C(0x1b663455U), BSWAP_32BIG_C(0x83676a5aU), BSWAP_32BIG_C(0x81065dc3U), BSWAP_32BIG_C(0x1a0be867U),
    };
    r_rsip_func100(Param_p58f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p58f_func100_002[] =
        {
            BSWAP_32BIG_C(0x0582d459U), BSWAP_32BIG_C(0x2a610757U), BSWAP_32BIG_C(0xb2cf99ddU), BSWAP_32BIG_C(
                0x7253fd56U),
        };
        r_rsip_func100(Param_p58f_func100_002);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            static const uint32_t Param_p58f_func100_003[] =
            {
                BSWAP_32BIG_C(0x77d94127U), BSWAP_32BIG_C(0xa34dc2c3U), BSWAP_32BIG_C(0x3adbe20bU), BSWAP_32BIG_C(
                    0xb60fd967U),
            };
            r_rsip_func100(Param_p58f_func100_003);
            WR1_PROG(REG_1408H, 0x0000601eU);
            WAIT_STS(REG_1408H, 30, 1);
            RD7_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_001[] =
            {
                BSWAP_32BIG_C(0xd928085aU), BSWAP_32BIG_C(0xb3146735U), BSWAP_32BIG_C(0xef322628U), BSWAP_32BIG_C(
                    0xe6a58383U),
            };
            r_rsip_func102(Param_p58f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p58f_func100_004[] =
            {
                BSWAP_32BIG_C(0xac20ec6eU), BSWAP_32BIG_C(0x169ad5d6U), BSWAP_32BIG_C(0x3f7490f9U), BSWAP_32BIG_C(
                    0xa9647042U),
            };
            r_rsip_func100(Param_p58f_func100_004);
            WR1_PROG(REG_1408H, 0x00006022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD8_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_002[] =
            {
                BSWAP_32BIG_C(0x73d9dfdbU), BSWAP_32BIG_C(0x01243bccU), BSWAP_32BIG_C(0xd5e436b7U), BSWAP_32BIG_C(
                    0x3a27b603U),
            };
            r_rsip_func102(Param_p58f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            static const uint32_t Param_p58f_func100_005[] =
            {
                BSWAP_32BIG_C(0xbd9874a5U), BSWAP_32BIG_C(0x53dd0f65U), BSWAP_32BIG_C(0x3736e6e9U), BSWAP_32BIG_C(
                    0x97616a6fU),
            };
            r_rsip_func100(Param_p58f_func100_005);
            WR1_PROG(REG_1408H, 0x00006032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD12_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_003[] =
            {
                BSWAP_32BIG_C(0x9c634129U), BSWAP_32BIG_C(0xa8be3eeaU), BSWAP_32BIG_C(0xbfea7672U), BSWAP_32BIG_C(
                    0x6515577cU),
            };
            r_rsip_func102(Param_p58f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            static const uint32_t Param_p58f_func100_006[] =
            {
                BSWAP_32BIG_C(0xb794a411U), BSWAP_32BIG_C(0x5062275cU), BSWAP_32BIG_C(0xe9839aceU), BSWAP_32BIG_C(
                    0x3d287bc8U),
            };
            r_rsip_func100(Param_p58f_func100_006);
            WR1_PROG(REG_1408H, 0x00006042U);
            WAIT_STS(REG_1408H, 30, 1);
            RD16_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p58f_func102_004[] =
            {
                BSWAP_32BIG_C(0x409720adU), BSWAP_32BIG_C(0x637c2ee6U), BSWAP_32BIG_C(0x1150250bU), BSWAP_32BIG_C(
                    0x70276503U),
            };
            r_rsip_func102(Param_p58f_func102_004);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        static const uint32_t Param_p58f_func100_007[] =
        {
            BSWAP_32BIG_C(0xd8aa49ceU), BSWAP_32BIG_C(0x9b93ce91U), BSWAP_32BIG_C(0xb0caad3cU), BSWAP_32BIG_C(
                0xf176a9b2U),
        };
        r_rsip_func100(Param_p58f_func100_007);

        r_rsip_func_sub010(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_1420H, InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x0000001cU);

            static const uint32_t Param_p58f_func101_001[] =
            {
                BSWAP_32BIG_C(0x21188269U), BSWAP_32BIG_C(0xe4236d97U), BSWAP_32BIG_C(0x75936575U), BSWAP_32BIG_C(
                    0x526b4028U),
            };
            r_rsip_func101(Param_p58f_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000020U);

            static const uint32_t Param_p58f_func101_002[] =
            {
                BSWAP_32BIG_C(0xc4e42b09U), BSWAP_32BIG_C(0x43eed9f7U), BSWAP_32BIG_C(0x92257d2bU), BSWAP_32BIG_C(
                    0x076fafedU),
            };
            r_rsip_func101(Param_p58f_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000030U);

            static const uint32_t Param_p58f_func101_003[] =
            {
                BSWAP_32BIG_C(0xf597cfe2U), BSWAP_32BIG_C(0x9a3a7431U), BSWAP_32BIG_C(0xafa68f59U), BSWAP_32BIG_C(
                    0x030d1659U),
            };
            r_rsip_func101(Param_p58f_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000040U);

            static const uint32_t Param_p58f_func101_004[] =
            {
                BSWAP_32BIG_C(0xfaf18e5cU), BSWAP_32BIG_C(0xb584cb10U), BSWAP_32BIG_C(0xb75a1fe1U), BSWAP_32BIG_C(
                    0x4198b1fbU),
            };
            r_rsip_func101(Param_p58f_func101_004);
        }

        r_rsip_func_sub006(0x3420a820U, 0x00000004U, 0x00260000U);

        r_rsip_func_sub017(0x34202841U, 0x00260000U);

        static const uint32_t Param_p58f_func100_008[] =
        {
            BSWAP_32BIG_C(0x1d16639aU), BSWAP_32BIG_C(0xe9f1f69eU), BSWAP_32BIG_C(0xe39d7c5cU), BSWAP_32BIG_C(
                0x88979ee7U),
        };
        r_rsip_func100(Param_p58f_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p58f_func102_005[] =
            {
                BSWAP_32BIG_C(0x049738bbU), BSWAP_32BIG_C(0xf68baa0bU), BSWAP_32BIG_C(0xb113829aU), BSWAP_32BIG_C(
                    0x0c779cafU),
            };
            r_rsip_func102(Param_p58f_func102_005);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p58f_func100_009[] =
            {
                BSWAP_32BIG_C(0xa2f59859U), BSWAP_32BIG_C(0xcc4ff410U), BSWAP_32BIG_C(0x5c365707U), BSWAP_32BIG_C(
                    0x0ace6933U),
            };
            r_rsip_func100(Param_p58f_func100_009);

            r_rsip_func_sub021(0x000008c6U, 0x000008a5U, 0x0000a440U, 0x0000000fU);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1600H, 0x00026c42U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; )
            {
                static const uint32_t Param_p58f_func100_010[] =
                {
                    BSWAP_32BIG_C(0x69515051U), BSWAP_32BIG_C(0x17749538U), BSWAP_32BIG_C(0x00a2c09dU), BSWAP_32BIG_C(
                        0xc6624c79U),
                };
                r_rsip_func100(Param_p58f_func100_010);

                r_rsip_func_sub021(0x000008e7U, 0x00000863U, 0x380088c0U, 0x00000004U);
                r_rsip_func_sub022(0x2000d060U, 0x38000c84U, 0x2000d060U);

                r_rsip_func_sub014(0x00007c03U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    r_rsip_func_sub001(0x0346000dU);

                    r_rsip_func_sub020(0x000002c1U, 0x08000045U);
                    WR3_ADDR(REG_1420H, &InData_MAC[iLoop]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                    static const uint32_t Param_p58f_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xb4f9282fU), BSWAP_32BIG_C(0x081337f9U), BSWAP_32BIG_C(0xc9750af7U),
                        BSWAP_32BIG_C(0x4e2f8e9bU),
                    };
                    r_rsip_func101(Param_p58f_func101_005);
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    r_rsip_func_sub001(0x03460011U);

                    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                    WR4_ADDR(REG_1420H, &InData_MAC[iLoop]);

                    static const uint32_t Param_p58f_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xc1d78fa7U), BSWAP_32BIG_C(0x10b6fdeeU), BSWAP_32BIG_C(0x1698fedcU),
                        BSWAP_32BIG_C(0x7f10e2e0U),
                    };
                    r_rsip_func101(Param_p58f_func101_006);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000800U);
                for (jLoop = 0U; jLoop < 16U; jLoop++)
                {
                    r_rsip_func_sub021(0x3c0028a1U, 0x12003c07U, 0x00002ce0U, 0x00002ca0U);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1608H, 0x81840007U);
                r_rsip_func_sub001(0x00490011U);

                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                static const uint32_t Param_p58f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x3028413bU), BSWAP_32BIG_C(0x908b9e2bU), BSWAP_32BIG_C(0x12f03891U), BSWAP_32BIG_C(
                        0xabcc9296U),
                };
                r_rsip_func101(Param_p58f_func101_007);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1600H, 0x000008c2U);

            r_rsip_func_sub014(0x00007c06U, 0x00602000U);

            static const uint32_t Param_p58f_func100_011[] =
            {
                BSWAP_32BIG_C(0xc525e927U), BSWAP_32BIG_C(0x561cfd3fU), BSWAP_32BIG_C(0x9609b056U), BSWAP_32BIG_C(
                    0x914f98d2U),
            };
            r_rsip_func100(Param_p58f_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p58f_func102_006[] =
                {
                    BSWAP_32BIG_C(0xa394acffU), BSWAP_32BIG_C(0x2a5ac803U), BSWAP_32BIG_C(0x9766ab31U), BSWAP_32BIG_C(
                        0xe26a6389U),
                };
                r_rsip_func102(Param_p58f_func102_006);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p58f_func102_007[] =
                {
                    BSWAP_32BIG_C(0xf6c7e3adU), BSWAP_32BIG_C(0x25619a67U), BSWAP_32BIG_C(0x9c772178U), BSWAP_32BIG_C(
                        0x2f7d27f0U),
                };
                r_rsip_func102(Param_p58f_func102_007);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
