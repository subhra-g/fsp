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

rsip_ret_t r_rsip_p75f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    WAIT_STS(REG_2030H, 0, 1);

    WR1_PROG(REG_1444H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR16_ADDR(REG_1420H, &InData_Msg[iLoop]);
        iLoop = iLoop + 16U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WAIT_STS(REG_1444H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_1420H, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8, 0);
    WR1_PROG(REG_143CH, 0x00001600U);

    WAIT_STS(REG_2030H, 4, 1);

    r_rsip_func_sub021(0x38008880U, 0x00000003U, 0x1000b480U, 0x00000001U);

    r_rsip_func_sub021(0x38008880U, 0x00000004U, 0x1000b480U, 0x00000002U);
    r_rsip_func_sub010(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c00U, 0x00260000U);

    static const uint32_t Param_p75f_func100_001[] =
    {
        BSWAP_32BIG_C(0x8f26de5cU), BSWAP_32BIG_C(0x3584c737U), BSWAP_32BIG_C(0xaa67e0a2U), BSWAP_32BIG_C(0x26998ff0U),
    };
    r_rsip_func100(Param_p75f_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75f_func100_002[] =
        {
            BSWAP_32BIG_C(0xac24d026U), BSWAP_32BIG_C(0x2fdd6c90U), BSWAP_32BIG_C(0x65ad857eU), BSWAP_32BIG_C(
                0x22b1bdf0U),
        };
        r_rsip_func100(Param_p75f_func100_002);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p75f_func100_003[] =
            {
                BSWAP_32BIG_C(0xed864825U), BSWAP_32BIG_C(0x68261803U), BSWAP_32BIG_C(0xcb5836f6U), BSWAP_32BIG_C(
                    0xb755dc1eU),
            };
            r_rsip_func100(Param_p75f_func100_003);
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30, 1);
            RD7_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_001[] =
            {
                BSWAP_32BIG_C(0xddbf612bU), BSWAP_32BIG_C(0xa582587aU), BSWAP_32BIG_C(0x7ed46e28U), BSWAP_32BIG_C(
                    0x93cd04efU),
            };
            r_rsip_func102(Param_p75f_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            static const uint32_t Param_p75f_func100_004[] =
            {
                BSWAP_32BIG_C(0x4539a7adU), BSWAP_32BIG_C(0x0baa0303U), BSWAP_32BIG_C(0x8ae5339bU), BSWAP_32BIG_C(
                    0xfccb6369U),
            };
            r_rsip_func100(Param_p75f_func100_004);
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30, 1);
            RD8_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_002[] =
            {
                BSWAP_32BIG_C(0x92643616U), BSWAP_32BIG_C(0xfb9e9561U), BSWAP_32BIG_C(0xf3a2423bU), BSWAP_32BIG_C(
                    0xf640f66bU),
            };
            r_rsip_func102(Param_p75f_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            static const uint32_t Param_p75f_func100_005[] =
            {
                BSWAP_32BIG_C(0x54da3e9dU), BSWAP_32BIG_C(0x033d8ff1U), BSWAP_32BIG_C(0x94c3793fU), BSWAP_32BIG_C(
                    0x21c066d9U),
            };
            r_rsip_func100(Param_p75f_func100_005);
            WR1_PROG(REG_1408H, 0x00004032U);
            WAIT_STS(REG_1408H, 30, 1);
            RD12_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_003[] =
            {
                BSWAP_32BIG_C(0xc797cbf0U), BSWAP_32BIG_C(0x63825071U), BSWAP_32BIG_C(0xa95a50ffU), BSWAP_32BIG_C(
                    0x3d356e9eU),
            };
            r_rsip_func102(Param_p75f_func102_003);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            static const uint32_t Param_p75f_func100_006[] =
            {
                BSWAP_32BIG_C(0x1c2533eeU), BSWAP_32BIG_C(0x0b48c304U), BSWAP_32BIG_C(0x4a5ca286U), BSWAP_32BIG_C(
                    0x47bac3dfU),
            };
            r_rsip_func100(Param_p75f_func100_006);
            WR1_PROG(REG_1408H, 0x00004042U);
            WAIT_STS(REG_1408H, 30, 1);
            RD16_ADDR(REG_1420H, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_004[] =
            {
                BSWAP_32BIG_C(0x3cf02eafU), BSWAP_32BIG_C(0x62e61407U), BSWAP_32BIG_C(0x3bc6445eU), BSWAP_32BIG_C(
                    0xa3943767U),
            };
            r_rsip_func102(Param_p75f_func102_004);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        static const uint32_t Param_p75f_func100_007[] =
        {
            BSWAP_32BIG_C(0x27b493a5U), BSWAP_32BIG_C(0x11583282U), BSWAP_32BIG_C(0x360126acU), BSWAP_32BIG_C(
                0x9656790fU),
        };
        r_rsip_func100(Param_p75f_func100_007);

        r_rsip_func_sub010(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_1420H, InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x0000001cU);

            static const uint32_t Param_p75f_func101_001[] =
            {
                BSWAP_32BIG_C(0xbdcf856aU), BSWAP_32BIG_C(0x7d3b9b31U), BSWAP_32BIG_C(0x72a9c0d0U), BSWAP_32BIG_C(
                    0xffdd2e6dU),
            };
            r_rsip_func101(Param_p75f_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000020U);

            static const uint32_t Param_p75f_func101_002[] =
            {
                BSWAP_32BIG_C(0xa34bc379U), BSWAP_32BIG_C(0x65f649baU), BSWAP_32BIG_C(0x18a303e4U), BSWAP_32BIG_C(
                    0xc6b0f1a7U),
            };
            r_rsip_func101(Param_p75f_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000030U);

            static const uint32_t Param_p75f_func101_003[] =
            {
                BSWAP_32BIG_C(0x463509c2U), BSWAP_32BIG_C(0x8277a129U), BSWAP_32BIG_C(0x18ca3529U), BSWAP_32BIG_C(
                    0x4c3da5d5U),
            };
            r_rsip_func101(Param_p75f_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1600H, 0x00000040U);

            static const uint32_t Param_p75f_func101_004[] =
            {
                BSWAP_32BIG_C(0xf99cd1e9U), BSWAP_32BIG_C(0x311aa5e3U), BSWAP_32BIG_C(0x3dd24839U), BSWAP_32BIG_C(
                    0xc1a85e88U),
            };
            r_rsip_func101(Param_p75f_func101_004);
        }

        r_rsip_func_sub006(0x3420a820U, 0x00000004U, 0x00260000U);

        r_rsip_func_sub017(0x34202841U, 0x00260000U);

        static const uint32_t Param_p75f_func100_008[] =
        {
            BSWAP_32BIG_C(0x288cc714U), BSWAP_32BIG_C(0xb2576d89U), BSWAP_32BIG_C(0x51b3dbd5U), BSWAP_32BIG_C(
                0x74dda411U),
        };
        r_rsip_func100(Param_p75f_func100_008);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75f_func102_005[] =
            {
                BSWAP_32BIG_C(0xa591d5d6U), BSWAP_32BIG_C(0x0db6ba0aU), BSWAP_32BIG_C(0xc58cd089U), BSWAP_32BIG_C(
                    0xe475a057U),
            };
            r_rsip_func102(Param_p75f_func102_005);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p75f_func100_009[] =
            {
                BSWAP_32BIG_C(0x8baea9e4U), BSWAP_32BIG_C(0x7d429282U), BSWAP_32BIG_C(0x074aeb80U), BSWAP_32BIG_C(
                    0xbe27aba0U),
            };
            r_rsip_func100(Param_p75f_func100_009);

            r_rsip_func_sub021(0x000008c6U, 0x000008a5U, 0x0000a440U, 0x0000000fU);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1600H, 0x00026c42U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; )
            {
                static const uint32_t Param_p75f_func100_010[] =
                {
                    BSWAP_32BIG_C(0xda719471U), BSWAP_32BIG_C(0x7b6e23daU), BSWAP_32BIG_C(0x84d9cf3bU), BSWAP_32BIG_C(
                        0x9e8619abU),
                };
                r_rsip_func100(Param_p75f_func100_010);

                r_rsip_func_sub021(0x000008e7U, 0x00000863U, 0x380088c0U, 0x00000004U);
                r_rsip_func_sub021(0x2000d060U, 0x38008880U, 0x00000001U, 0x2000d060U);

                r_rsip_func_sub014(0x00007c03U, 0x00600000U);

                if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    r_rsip_func_sub001(0x0345000dU);

                    r_rsip_func_sub020(0x000002c1U, 0x08000045U);
                    WR3_ADDR(REG_1420H, &InData_MAC[iLoop]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));

                    static const uint32_t Param_p75f_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x29f7ab0aU), BSWAP_32BIG_C(0xad41feb8U), BSWAP_32BIG_C(0x65713280U),
                        BSWAP_32BIG_C(0xfd39715eU),
                    };
                    r_rsip_func101(Param_p75f_func101_005);
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    r_rsip_func_sub001(0x03450011U);

                    r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                    WR4_ADDR(REG_1420H, &InData_MAC[iLoop]);

                    static const uint32_t Param_p75f_func101_006[] =
                    {
                        BSWAP_32BIG_C(0x771de06aU), BSWAP_32BIG_C(0x427323c3U), BSWAP_32BIG_C(0x5f6f85f0U),
                        BSWAP_32BIG_C(0x57bd697cU),
                    };
                    r_rsip_func101(Param_p75f_func101_006);
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

                static const uint32_t Param_p75f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x298e2ab0U), BSWAP_32BIG_C(0x9a2d1b27U), BSWAP_32BIG_C(0xec3c2ceaU), BSWAP_32BIG_C(
                        0xd524cbf6U),
                };
                r_rsip_func101(Param_p75f_func101_007);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1600H, 0x000008c2U);

            r_rsip_func_sub014(0x00007c06U, 0x00602000U);

            static const uint32_t Param_p75f_func100_011[] =
            {
                BSWAP_32BIG_C(0xaf6f5e67U), BSWAP_32BIG_C(0x773f2216U), BSWAP_32BIG_C(0x094b1d18U), BSWAP_32BIG_C(
                    0x8548d3f2U),
            };
            r_rsip_func100(Param_p75f_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p75f_func102_006[] =
                {
                    BSWAP_32BIG_C(0x252b31a1U), BSWAP_32BIG_C(0x91cc3fbfU), BSWAP_32BIG_C(0x7447417eU), BSWAP_32BIG_C(
                        0x435514d4U),
                };
                r_rsip_func102(Param_p75f_func102_006);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p75f_func102_007[] =
                {
                    BSWAP_32BIG_C(0x5b1ad2ecU), BSWAP_32BIG_C(0x7e0c8e9cU), BSWAP_32BIG_C(0x85adf7f4U), BSWAP_32BIG_C(
                        0xe831d6deU),
                };
                r_rsip_func102(Param_p75f_func102_007);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
