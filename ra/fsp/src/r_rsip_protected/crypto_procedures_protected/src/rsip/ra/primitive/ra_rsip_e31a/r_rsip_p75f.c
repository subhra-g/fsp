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

    WAIT_STS(REG_0118H, 0, 1);

    WR1_PROG(REG_0014H, 0x00020064U);

    for (iLoop = 0U; iLoop < (MAX_CNT & 0xfffffff0U); )
    {
        WAIT_STS(REG_0014H, 31, 1);
        WR16_ADDR(REG_002CH, &InData_Msg[iLoop]);
        iLoop = iLoop + 16U;
    }

    WAIT_STS(REG_0014H, 31, 1);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop++)
    {
        WR1_PROG(REG_002CH, InData_Msg[iLoop]);
    }

    WR1_PROG(REG_0014H, 0x00000000U);
    WAIT_STS(REG_0118H, 8, 0);
    WR1_PROG(REG_0040H, 0x00001600U);

    WAIT_STS(REG_0118H, 4, 1);

    r_rsip_func_sub022(0x38008880U, 0x00000004U, 0x1000b480U);
    WR1_PROG(REG_0094H, 0x00000002U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00270000U);

    static const uint32_t Param_p75f_func100_001[] =
    {
        BSWAP_32BIG_C(0xc804ffebU), BSWAP_32BIG_C(0x26845802U), BSWAP_32BIG_C(0xc9cd8cfdU), BSWAP_32BIG_C(0xc1a99009U),
    };
    r_rsip_func100(Param_p75f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p75f_func100_002[] =
        {
            BSWAP_32BIG_C(0xcf547221U), BSWAP_32BIG_C(0x005453bbU), BSWAP_32BIG_C(0xe0165c3dU), BSWAP_32BIG_C(
                0x120bf70cU),
        };
        r_rsip_func100(Param_p75f_func100_002);

        WR1_PROG(REG_0094H, 0x00007c04U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            static const uint32_t Param_p75f_func100_003[] =
            {
                BSWAP_32BIG_C(0xac7b7390U), BSWAP_32BIG_C(0xbc1bca0fU), BSWAP_32BIG_C(0x59c728cbU), BSWAP_32BIG_C(
                    0xc16fa142U),
            };
            r_rsip_func100(Param_p75f_func100_003);
            WR1_PROG(REG_0008H, 0x00004022U);
            WAIT_STS(REG_0008H, 30, 1);
            RD8_ADDR(REG_002CH, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_001[] =
            {
                BSWAP_32BIG_C(0xcb60cd78U), BSWAP_32BIG_C(0xfbfc5e79U), BSWAP_32BIG_C(0x35b7a68eU), BSWAP_32BIG_C(
                    0x57ef7c51U),
            };
            r_rsip_func102(Param_p75f_func102_001);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
        {
            static const uint32_t Param_p75f_func100_004[] =
            {
                BSWAP_32BIG_C(0xd59155f3U), BSWAP_32BIG_C(0x3b15c752U), BSWAP_32BIG_C(0x9aa85cebU), BSWAP_32BIG_C(
                    0x14027b3aU),
            };
            r_rsip_func100(Param_p75f_func100_004);
            WR1_PROG(REG_0008H, 0x0000401eU);
            WAIT_STS(REG_0008H, 30, 1);
            RD7_ADDR(REG_002CH, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_002[] =
            {
                BSWAP_32BIG_C(0x47b1204cU), BSWAP_32BIG_C(0x046f1a18U), BSWAP_32BIG_C(0x6bf11294U), BSWAP_32BIG_C(
                    0xb67f7532U),
            };
            r_rsip_func102(Param_p75f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000005U)
        {
            static const uint32_t Param_p75f_func100_005[] =
            {
                BSWAP_32BIG_C(0x28ec35caU), BSWAP_32BIG_C(0x08206558U), BSWAP_32BIG_C(0x91594faeU), BSWAP_32BIG_C(
                    0x52157764U),
            };
            r_rsip_func100(Param_p75f_func100_005);
            WR1_PROG(REG_0008H, 0x00004032U);
            WAIT_STS(REG_0008H, 30, 1);
            RD12_ADDR(REG_002CH, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_003[] =
            {
                BSWAP_32BIG_C(0x198db8baU), BSWAP_32BIG_C(0x8563c421U), BSWAP_32BIG_C(0xde3e0a29U), BSWAP_32BIG_C(
                    0x55702096U),
            };
            r_rsip_func102(Param_p75f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            static const uint32_t Param_p75f_func100_006[] =
            {
                BSWAP_32BIG_C(0x4443231eU), BSWAP_32BIG_C(0xe40aede0U), BSWAP_32BIG_C(0xfb2f24ebU), BSWAP_32BIG_C(
                    0x7c636397U),
            };
            r_rsip_func100(Param_p75f_func100_006);
            WR1_PROG(REG_0008H, 0x00004042U);
            WAIT_STS(REG_0008H, 30, 1);
            RD16_ADDR(REG_002CH, &OutData_MAC[0]);

            static const uint32_t Param_p75f_func102_004[] =
            {
                BSWAP_32BIG_C(0x91661b6cU), BSWAP_32BIG_C(0xe88d5083U), BSWAP_32BIG_C(0x02a175e4U), BSWAP_32BIG_C(
                    0x1b942fe6U),
            };
            r_rsip_func102(Param_p75f_func102_004);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        static const uint32_t Param_p75f_func100_007[] =
        {
            BSWAP_32BIG_C(0x7418a982U), BSWAP_32BIG_C(0x6e2c1a02U), BSWAP_32BIG_C(0x5f52c846U), BSWAP_32BIG_C(
                0x65bf5b9fU),
        };
        r_rsip_func100(Param_p75f_func100_007);

        r_rsip_func_sub014(0x000000c7U, 0x80010020U);
        WR1_PROG(REG_002CH, InData_length[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        WR1_PROG(REG_0094H, 0x00007c04U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_0094H, 0x0000b440U);
            WR1_PROG(REG_0094H, 0x00000020U);

            static const uint32_t Param_p75f_func101_001[] =
            {
                BSWAP_32BIG_C(0x3d75fd16U), BSWAP_32BIG_C(0xab91f882U), BSWAP_32BIG_C(0x3c2eb166U), BSWAP_32BIG_C(
                    0x960acdd5U),
            };
            r_rsip_func101(Param_p75f_func101_001);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_0094H, 0x0000b440U);
            WR1_PROG(REG_0094H, 0x0000001cU);

            static const uint32_t Param_p75f_func101_002[] =
            {
                BSWAP_32BIG_C(0x025a0f7eU), BSWAP_32BIG_C(0xc22bbc0cU), BSWAP_32BIG_C(0x0f12f27dU), BSWAP_32BIG_C(
                    0x95e1152dU),
            };
            r_rsip_func101(Param_p75f_func101_002);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_0094H, 0x0000b440U);
            WR1_PROG(REG_0094H, 0x00000030U);

            static const uint32_t Param_p75f_func101_003[] =
            {
                BSWAP_32BIG_C(0xf2ca4ab1U), BSWAP_32BIG_C(0x3ef93e51U), BSWAP_32BIG_C(0x25c1297aU), BSWAP_32BIG_C(
                    0xf28ae78bU),
            };
            r_rsip_func101(Param_p75f_func101_003);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_0094H, 0x0000b440U);
            WR1_PROG(REG_0094H, 0x00000040U);

            static const uint32_t Param_p75f_func101_004[] =
            {
                BSWAP_32BIG_C(0x0f14e019U), BSWAP_32BIG_C(0x81701c20U), BSWAP_32BIG_C(0xb922a6a9U), BSWAP_32BIG_C(
                    0x28895353U),
            };
            r_rsip_func101(Param_p75f_func101_004);
        }

        r_rsip_func_sub010(0x3420a820U, 0x00000004U, 0x00270000U);

        r_rsip_func_sub016(0x34202841U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_p75f_func100_008[] =
        {
            BSWAP_32BIG_C(0x4e3bf61eU), BSWAP_32BIG_C(0xdb075a96U), BSWAP_32BIG_C(0x244900a3U), BSWAP_32BIG_C(
                0x2e615c48U),
        };
        r_rsip_func100(Param_p75f_func100_008);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p75f_func102_005[] =
            {
                BSWAP_32BIG_C(0x6ffd75f0U), BSWAP_32BIG_C(0xaed03082U), BSWAP_32BIG_C(0x83d71c37U), BSWAP_32BIG_C(
                    0xaaa9fd7dU),
            };
            r_rsip_func102(Param_p75f_func102_005);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p75f_func100_009[] =
            {
                BSWAP_32BIG_C(0x2a91c254U), BSWAP_32BIG_C(0xbb2973e5U), BSWAP_32BIG_C(0x969fdac2U), BSWAP_32BIG_C(
                    0xc363c3d8U),
            };
            r_rsip_func100(Param_p75f_func100_009);

            r_rsip_func_sub022(0x000008c6U, 0x000008a5U, 0x0000a440U);
            r_rsip_func_sub022(0x0000000fU, 0x00046842U, 0x00026c42U);

            r_rsip_func_sub017(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; )
            {
                static const uint32_t Param_p75f_func100_010[] =
                {
                    BSWAP_32BIG_C(0xe1c09621U), BSWAP_32BIG_C(0x2b25e470U), BSWAP_32BIG_C(0x86565725U), BSWAP_32BIG_C(
                        0x6d85ea43U),
                };
                r_rsip_func100(Param_p75f_func100_010);

                r_rsip_func_sub022(0x000008e7U, 0x00000863U, 0x380088c0U);
                r_rsip_func_sub022(0x00000004U, 0x2000d060U, 0x38008880U);
                r_rsip_func_sub022(0x00000003U, 0x2000d060U, 0x00007c03U);
                WR1_PROG(REG_0040H, 0x00600000U);

                if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
                {
                    r_rsip_func_sub012(0x80830007U, 0x0345000dU);

                    r_rsip_func_sub019(0x000002c1U, 0x08000045U);
                    WR3_ADDR(REG_002CH, &InData_MAC[iLoop]);
                    WR1_PROG(REG_0014H, 0x000000a1U);
                    WAIT_STS(REG_0014H, 31, 1);
                    WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

                    static const uint32_t Param_p75f_func101_005[] =
                    {
                        BSWAP_32BIG_C(0x33b99784U), BSWAP_32BIG_C(0x7f033d55U), BSWAP_32BIG_C(0x5af14d38U),
                        BSWAP_32BIG_C(0x6fb85706U),
                    };
                    r_rsip_func101(Param_p75f_func101_005);
                }
                else
                {
                    r_rsip_func_sub012(0x80840007U, 0x03450011U);

                    r_rsip_func_sub019(0x000003c1U, 0x08000045U);
                    WR4_ADDR(REG_002CH, &InData_MAC[iLoop]);

                    static const uint32_t Param_p75f_func101_006[] =
                    {
                        BSWAP_32BIG_C(0xedbcb1a4U), BSWAP_32BIG_C(0x2421498eU), BSWAP_32BIG_C(0x6d2f87d6U),
                        BSWAP_32BIG_C(0xe7da88b6U),
                    };
                    r_rsip_func101(Param_p75f_func101_006);
                }

                WR1_PROG(REG_0094H, 0x00000800U);
                for (jLoop = 0U; jLoop < 16U; jLoop++)
                {
                    r_rsip_func_sub022(0x3c0028a1U, 0x12003c07U, 0x00002ce0U);
                    WR1_PROG(REG_0094H, 0x00002ca0U);
                }

                WR1_PROG(REG_00D0H, 0x9c000005U);
                WR1_PROG(REG_0094H, 0x000008e7U);
                r_rsip_func_sub006(0x81840007U, 0x00490011U, 0x0000a4c0U, 0x00000004U);

                static const uint32_t Param_p75f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x4d6a3c37U), BSWAP_32BIG_C(0xd78f1487U), BSWAP_32BIG_C(0x919e88a0U), BSWAP_32BIG_C(
                        0x4c10a08fU),
                };
                r_rsip_func101(Param_p75f_func101_007);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_0094H, 0x000008c2U);

            WR1_PROG(REG_0094H, 0x00007c06U);
            WR1_PROG(REG_0040H, 0x00602000U);

            static const uint32_t Param_p75f_func100_011[] =
            {
                BSWAP_32BIG_C(0x0b5eaa49U), BSWAP_32BIG_C(0x58ee993fU), BSWAP_32BIG_C(0x1cc81ccdU), BSWAP_32BIG_C(
                    0x872b9da5U),
            };
            r_rsip_func100(Param_p75f_func100_011);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p75f_func102_006[] =
                {
                    BSWAP_32BIG_C(0xc51e996bU), BSWAP_32BIG_C(0x586b7f9bU), BSWAP_32BIG_C(0xf8e594a7U), BSWAP_32BIG_C(
                        0x9b348cd0U),
                };
                r_rsip_func102(Param_p75f_func102_006);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_p75f_func102_007[] =
                {
                    BSWAP_32BIG_C(0x7cb9840dU), BSWAP_32BIG_C(0x5e1108b0U), BSWAP_32BIG_C(0xe491a274U), BSWAP_32BIG_C(
                        0x907056ceU),
                };
                r_rsip_func102(Param_p75f_func102_007);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
