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

rsip_ret_t r_rsip_p0d (const uint32_t InData_KeyCertificate[],
                       const uint32_t InData_KeyCertificateLength[],
                       const uint32_t InData_KeyCertificateSignature[],
                       const uint32_t InData_KeyCertificatePubKey[],
                       const uint32_t InData_ImgPkHash[],
                       const uint32_t InData_OemRootPkHashIndex[],
                       const uint32_t InData_CodeCertificate[],
                       const uint32_t InData_CodeCertificateLength[],
                       const uint32_t InData_CodeCertificateSignature[],
                       const uint32_t InData_CodeCertificatePubKey[],
                       const uint32_t InData_Image[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       MAX_CNT,
                       uint32_t       OutData_MAC[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t iTemp = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000d0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000004c7U, 0x800501e0U);
    WR1_PROG(REG_1420H, InData_CodeCertificateLength[0]);
    for (iLoop = 0U; iLoop < 4; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CodeCertificatePubKey[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000006c7U, 0x800702c0U);
    WR1_PROG(REG_1420H, InData_KeyCertificateLength[0]);
    for (iLoop = 0U; iLoop < 4; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_KeyCertificatePubKey[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0U; iLoop < 2U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_ImgPkHash[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x00000bffU, 0x34202af8U, 0x2000d3e0U, 0x34202b19U);
    r_rsip_func_sub024(0x2000d3e0U, 0x34202b3aU, 0x2000d3e0U, 0x34202b5bU);
    r_rsip_func_sub024(0x2000d3e0U, 0x34202b7cU, 0x2000d3e0U, 0x34202b96U);
    r_rsip_func_sub024(0x2000d3e0U, 0x00003417U, 0x0000a400U, 0x0000001fU);
    r_rsip_func_sub024(0x08000818U, 0x2000d3e0U, 0x00003419U, 0x0000a400U);
    r_rsip_func_sub024(0x0000001fU, 0x0800081aU, 0x2000d3e0U, 0x0000341bU);
    r_rsip_func_sub024(0x0000a400U, 0x0000001fU, 0x0800081cU, 0x2000d3e0U);

    r_rsip_func_sub024(0x0000b7c0U, 0x0000001fU, 0x34202bd0U, 0x2000d3e0U);

    r_rsip_func_sub024(0x34202a11U, 0x2000d3e0U, 0x34202a32U, 0x2000d3e0U);

    r_rsip_func_sub024(0x34202a53U, 0x2000d3e0U, 0x34202a6fU, 0x2000d3e0U);

    r_rsip_func_sub024(0x00003410U, 0x0000a400U, 0x0000001fU, 0x08000811U);
    r_rsip_func_sub024(0x2000d3e0U, 0x00003412U, 0x0000a400U, 0x0000001fU);
    WR1_PROG(REG_1600H, 0x08000813U);
    r_rsip_func_sub006(0x2000d3e0U, 0x38000fffU, 0x00A60000U);

    static const uint32_t Param_p0d_func100_001[] =
    {
        BSWAP_32BIG_C(0x5a19a28aU), BSWAP_32BIG_C(0xc3fce2b4U), BSWAP_32BIG_C(0x0a45ed75U), BSWAP_32BIG_C(0xbf0e93e6U),
    };
    r_rsip_func100(Param_p0d_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_14BCH, 0x00000020U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PARAM_FAIL;
    }
    else
    {
        static const uint32_t Param_p0d_func100_002[] =
        {
            BSWAP_32BIG_C(0x3d321d68U), BSWAP_32BIG_C(0x7b98f83cU), BSWAP_32BIG_C(0xe3d49b91U), BSWAP_32BIG_C(
                0x3c8ef22dU),
        };
        r_rsip_func100(Param_p0d_func100_002);

        WR1_PROG(REG_2000H, 0x00000001U);

        WR1_PROG(REG_2004H, 0x00000050U);

        r_rsip_func_sub024(0x00000800U, 0x00003436U, 0x01836c01U, 0x00036c21U);

        r_rsip_func_sub016(0x81020000U, 0x0000500aU);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);
        WAIT_STS(REG_1408H, 30, 1);
        RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
        S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

        static const uint32_t Param_p0d_func100_003[] =
        {
            BSWAP_32BIG_C(0xcf472b35U), BSWAP_32BIG_C(0x51d463b2U), BSWAP_32BIG_C(0x683122a4U), BSWAP_32BIG_C(
                0xef03e8e6U),
        };
        r_rsip_func100(Param_p0d_func100_003);
        r_rsip_func_sub036(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

        r_rsip_func_sub025(0x00003417U, 0x00046800U, 0x00026c00U);

        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        WR1_PROG(REG_1600H, 0x000008a5U);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            WR1_PROG(REG_1444H, 0x000003c4U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyCertificate[iLoop]);
            r_rsip_func_sub039(0x0000a4a0U, 0x00000004U);

            static const uint32_t Param_p0d_func101_001[] =
            {
                BSWAP_32BIG_C(0x5081cf2aU), BSWAP_32BIG_C(0xb75c1a81U), BSWAP_32BIG_C(0xdfd26d14U), BSWAP_32BIG_C(
                    0x22a59465U),
            };
            r_rsip_func101(Param_p0d_func101_001);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        static const uint32_t Param_p0d_func100_004[] =
        {
            BSWAP_32BIG_C(0xf7f01f28U), BSWAP_32BIG_C(0x22a79eddU), BSWAP_32BIG_C(0xbd0db958U), BSWAP_32BIG_C(
                0x62431676U),
        };
        r_rsip_func100(Param_p0d_func100_004);

        r_rsip_func_sub011(0x38000805U);

        WR1_PROG(REG_1000H, 0x00010000U);
        r_rsip_func_sub012(0x10000000U, 0x00003416U, 0x00026800U);
        r_rsip_func_sub025(0x38008ec0U, 0x00000003U, 0x20002c00U);

        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        r_rsip_func_sub024(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1600H, 0x00000180U);

        iTemp = iLoop;
        for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010100U);
            WR1_PROG(REG_1420H, InData_KeyCertificate[iLoop]);
            r_rsip_func_sub039(0x0000b420U, 0x00000004U);

            for (jLoop = 0U; jLoop < 4; jLoop++)
            {
                r_rsip_func_sub024(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                r_rsip_func_sub025(0x3c002859U, 0x20002c60U, 0x3c002b42U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_005[] =
                {
                    BSWAP_32BIG_C(0xebe2ac0eU), BSWAP_32BIG_C(0x78ec0a6cU), BSWAP_32BIG_C(0x70feb889U), BSWAP_32BIG_C(
                        0x78e0d136U),
                };
                r_rsip_func100(Param_p0d_func100_005);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x10c90005U);

                    static const uint32_t Param_p0d_func101_002[] =
                    {
                        BSWAP_32BIG_C(0x89721c48U), BSWAP_32BIG_C(0x99e823a3U), BSWAP_32BIG_C(0xd38c74f1U),
                        BSWAP_32BIG_C(0xe470a45dU),
                    };
                    r_rsip_func101(Param_p0d_func101_002);
                }

                r_rsip_func_sub024(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_006[] =
                {
                    BSWAP_32BIG_C(0xc43af23bU), BSWAP_32BIG_C(0xe09d4306U), BSWAP_32BIG_C(0xb6ffe941U), BSWAP_32BIG_C(
                        0x84ff5436U),
                };
                r_rsip_func100(Param_p0d_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x10c90005U);

                    static const uint32_t Param_p0d_func101_003[] =
                    {
                        BSWAP_32BIG_C(0xe9471574U), BSWAP_32BIG_C(0x4340cc57U), BSWAP_32BIG_C(0xcdb1caa3U),
                        BSWAP_32BIG_C(0x37a86996U),
                    };
                    r_rsip_func101(Param_p0d_func101_003);
                }

                r_rsip_func_sub024(0x00000863U, 0x3c00285bU, 0x20002c60U, 0x3c002b82U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_007[] =
                {
                    BSWAP_32BIG_C(0xa9784474U), BSWAP_32BIG_C(0x615bc6edU), BSWAP_32BIG_C(0xd250cc05U), BSWAP_32BIG_C(
                        0xe48f0defU),
                };
                r_rsip_func100(Param_p0d_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x02003ce9U);
                    WR1_PROG(REG_1600H, 0x00002d20U);
                    static const uint32_t Param_p0d_func101_004[] =
                    {
                        BSWAP_32BIG_C(0xe2108c5cU), BSWAP_32BIG_C(0x69bf3cd0U), BSWAP_32BIG_C(0x69f2cd61U),
                        BSWAP_32BIG_C(0xcd0cb441U),
                    };
                    r_rsip_func101(Param_p0d_func101_004);
                }

                WR1_PROG(REG_1600H, 0x00000863U);
                WR1_PROG(REG_1600H, 0x3c0028c2U);
                r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                static const uint32_t Param_p0d_func100_008[] =
                {
                    BSWAP_32BIG_C(0x0fcb4f5aU), BSWAP_32BIG_C(0x3fb69779U), BSWAP_32BIG_C(0xc8405c5dU), BSWAP_32BIG_C(
                        0x2c245611U),
                };
                r_rsip_func100(Param_p0d_func100_008);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1608H, 0x810100e0U);
                    r_rsip_func_sub001(0x1009000dU);
                    r_rsip_func_sub001(0x11490005U);

                    static const uint32_t Param_p0d_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xa17f657bU), BSWAP_32BIG_C(0xa2c98cdfU), BSWAP_32BIG_C(0xfa206f23U),
                        BSWAP_32BIG_C(0x6b449d7fU),
                    };
                    r_rsip_func101(Param_p0d_func101_005);
                }

                WR1_PROG(REG_1600H, 0x00002c40U);

                static const uint32_t Param_p0d_func101_006[] =
                {
                    BSWAP_32BIG_C(0x0f39f874U), BSWAP_32BIG_C(0x115e6b00U), BSWAP_32BIG_C(0x7e87ceebU), BSWAP_32BIG_C(
                        0x0187cd32U),
                };
                r_rsip_func101(Param_p0d_func101_006);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x08000c21U);

            WR1_PROG(REG_1600H, 0x00002ca0U);

            static const uint32_t Param_p0d_func101_007[] =
            {
                BSWAP_32BIG_C(0x5f998a3bU), BSWAP_32BIG_C(0x45335dd5U), BSWAP_32BIG_C(0x8922604aU), BSWAP_32BIG_C(
                    0xc8e4775fU),
            };
            r_rsip_func101(Param_p0d_func101_007);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000805U);

        static const uint32_t Param_p0d_func100_009[] =
        {
            BSWAP_32BIG_C(0x0d2466fbU), BSWAP_32BIG_C(0xde474549U), BSWAP_32BIG_C(0xb5a9eca5U), BSWAP_32BIG_C(
                0x3095153fU),
        };
        r_rsip_func100(Param_p0d_func100_009);
        r_rsip_func_sub024(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
        r_rsip_func_sub024(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

        r_rsip_func_sub016(0x81010040U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        r_rsip_func_sub025(0x000008a5U, 0x0000b460U, 0x00000000U);

        for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
        {
            WR1_PROG(REG_1608H, 0x81010060U);
            r_rsip_func_sub001(0x11490005U);
            r_rsip_func_sub001(0x1009000dU);

            WR1_PROG(REG_1600H, 0x00086c63U);

            WR1_PROG(REG_1600H, 0x00002ca0U);

            static const uint32_t Param_p0d_func101_008[] =
            {
                BSWAP_32BIG_C(0xd2e2a759U), BSWAP_32BIG_C(0xfff888c7U), BSWAP_32BIG_C(0x29f1d2d0U), BSWAP_32BIG_C(
                    0xc0c1e4ebU),
            };
            r_rsip_func101(Param_p0d_func101_008);
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x38000845U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x00000929U);
        WR1_PROG(REG_1608H, 0x80880009U);
        r_rsip_func_sub001(0x03450021U);

        WR1_PROG(REG_2000H, 0x00000001U);

        WR1_PROG(REG_2004H, 0x00000050U);

        WR1_PROG(REG_2014H, 0x00000000U);
        WR1_PROG(REG_2010H, 0x00000200U);

        WR1_PROG(REG_1404H, 0x10000000U);
        r_rsip_func_sub001(0x01430041U);

        WAIT_STS(REG_2030H, 4, 1);

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x000000fdU);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000dU);

        static const uint32_t Param_p0d_func101_009[] =
        {
            BSWAP_32BIG_C(0xdb3052a8U), BSWAP_32BIG_C(0xb7f1af97U), BSWAP_32BIG_C(0xdf35612aU), BSWAP_32BIG_C(
                0xc22fb133U),
        };
        r_rsip_func101(Param_p0d_func101_009);
        r_rsip_func043();

        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x08000045U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_PROG(REG_1420H, bswap_32big(0x37b96c17U), bswap_32big(0xf6bb586aU), bswap_32big(0x4c781037U),
                 bswap_32big(0x17ba4317U));

        r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0x0900890fU);
        WR4_ADDR(REG_1420H, &InData_OemRootPkHashIndex[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_OemRootPkHashIndex[4]);

        WR1_PROG(REG_1A24H, 0x08000055U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00850011U);

        WR1_PROG(REG_1A24H, 0x08000055U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00850011U);

        static const uint32_t Param_p0d_func100_010[] =
        {
            BSWAP_32BIG_C(0xf18ea06fU), BSWAP_32BIG_C(0x273dad0dU), BSWAP_32BIG_C(0x3dde803eU), BSWAP_32BIG_C(
                0xa801896eU),
        };
        r_rsip_func100(Param_p0d_func100_010);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_VERIFICATION_FAIL;
        }
        else
        {
            r_rsip_func_sub012(0x10000000U, 0x0000b420U, 0x00000060U);
            WR1_PROG(REG_1608H, 0x80900001U);
            r_rsip_func_sub001(0x03430041U);

            WR1_PROG(REG_1404H, 0x19100000U);
            r_rsip_func_sub019(0x00000fc1U, 0x00000300U, 0x08008107U);
            WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[0]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[4]);
            r_rsip_func_sub001(0x00c10021U);

            WR1_PROG(REG_1404H, 0x19600000U);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[8]);
            WAIT_STS(REG_1444H, 31, 1);
            WR4_ADDR(REG_1420H, &InData_KeyCertificateSignature[12]);
            r_rsip_func_sub001(0x00c10021U);

            WR1_PROG(REG_1600H, 0x00000b5aU);
            WR1_PROG(REG_1600H, 0x00000b9cU);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000d01U);

            static const uint32_t Param_p0d_func101_010[] =
            {
                BSWAP_32BIG_C(0x1cbf9403U), BSWAP_32BIG_C(0xff5237f6U), BSWAP_32BIG_C(0x1aea544cU), BSWAP_32BIG_C(
                    0xdb30e1bdU),
            };
            r_rsip_func101(Param_p0d_func101_010);
            r_rsip_func073(InData_DomainParam);

            static const uint32_t Param_p0d_func100_011[] =
            {
                BSWAP_32BIG_C(0xda978056U), BSWAP_32BIG_C(0x812e105dU), BSWAP_32BIG_C(0x3d36d693U), BSWAP_32BIG_C(
                    0xe9f42218U),
            };
            r_rsip_func100(Param_p0d_func100_011);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_14BCH, 0x00000020U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_VERIFICATION_FAIL;
            }
            else
            {
                static const uint32_t Param_p0d_func100_012[] =
                {
                    BSWAP_32BIG_C(0x4506db4aU), BSWAP_32BIG_C(0x401df0a0U), BSWAP_32BIG_C(0xf695b240U), BSWAP_32BIG_C(
                        0x20b6de78U),
                };
                r_rsip_func100(Param_p0d_func100_012);

                r_rsip_func_sub024(0x000036cfU, 0x000036f0U, 0x00003711U, 0x00003732U);
                WR1_PROG(REG_1600H, 0x00003753U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                r_rsip_func_sub010(0x000000c7U, 0x80010160U);
                WR1_PROG(REG_1420H, MAX_CNT);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub024(0x00000800U, 0x0000342bU, 0x01826c01U, 0x00026c21U);

                r_rsip_func_sub024(0x000008c6U, 0x0c002436U, 0x00802406U, 0x01836c01U);
                WR1_PROG(REG_1600H, 0x00036c21U);

                r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);
                WAIT_STS(REG_1408H, 30, 1);
                RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                static const uint32_t Param_p0d_func100_013[] =
                {
                    BSWAP_32BIG_C(0x4fe5e312U), BSWAP_32BIG_C(0xb57c2757U), BSWAP_32BIG_C(0xb4663336U), BSWAP_32BIG_C(
                        0x744515d8U),
                };
                r_rsip_func100(Param_p0d_func100_013);
                r_rsip_func_sub036(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                r_rsip_func_sub025(0x00003417U, 0x00046800U, 0x00026c00U);

                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000dU);

                static const uint32_t Param_p0d_func101_011[] =
                {
                    BSWAP_32BIG_C(0x501f45b0U), BSWAP_32BIG_C(0xcf4c42d9U), BSWAP_32BIG_C(0xf3329b50U), BSWAP_32BIG_C(
                        0xc52a8eebU),
                };
                r_rsip_func101(Param_p0d_func101_011);
                r_rsip_func103();

                static const uint32_t Param_p0d_func100_014[] =
                {
                    BSWAP_32BIG_C(0x0601662cU), BSWAP_32BIG_C(0x07d78a49U), BSWAP_32BIG_C(0xd0710447U), BSWAP_32BIG_C(
                        0x796ca9e2U),
                };
                r_rsip_func100(Param_p0d_func100_014);
                r_rsip_func_sub004(0x0c200184U, 0x00000000U);

                r_rsip_func_sub020(0x000003a1U, 0x08000045U);
                WR4_PROG(REG_1420H,
                         bswap_32big(0x8ab22685U),
                         bswap_32big(0xbfab115bU),
                         bswap_32big(0x841c0f17U),
                         bswap_32big(0xa1af8aa1U));

                WR1_PROG(REG_1824H, 0x0e0c0446U);

                WR1_PROG(REG_1600H, 0x0000b7e0U);
                WR1_PROG(REG_1600H, 0x00000090U);

                WR1_PROG(REG_1444H, 0x000007c7U);
                WR1_PROG(REG_1608H, 0x8088001fU);
                for (iLoop = 0U; iLoop < 8U; iLoop++)
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1608H, 0x8188001fU);
                r_rsip_func_sub001(0x02490021U);

                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1600H, 0x00000008U);

                for (iLoop = 8; iLoop < S_RAM[0]; )
                {
                    WR1_PROG(REG_1444H, 0x000003caU);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_CodeCertificate[iLoop]);

                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1600H, 0x00000004U);

                    static const uint32_t Param_p0d_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x505bd04aU), BSWAP_32BIG_C(0x6f02fbc4U), BSWAP_32BIG_C(0xa1cf524aU),
                        BSWAP_32BIG_C(0xe64025b6U),
                    };
                    r_rsip_func101(Param_p0d_func101_012);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p0d_func100_015[] =
                {
                    BSWAP_32BIG_C(0x83bff524U), BSWAP_32BIG_C(0xed503092U), BSWAP_32BIG_C(0x9ffd14dfU), BSWAP_32BIG_C(
                        0x9d981f0eU),
                };
                r_rsip_func100(Param_p0d_func100_015);

                r_rsip_func_sub011(0x38000805U);

                r_rsip_func_sub012(0x10000000U, 0x00003416U, 0x00026800U);
                r_rsip_func_sub025(0x38008ec0U, 0x00000003U, 0x20002c00U);

                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub024(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

                iTemp = iLoop;
                for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                {
                    r_rsip_func_sub010(0x000000c7U, 0x80010100U);
                    WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                    r_rsip_func_sub039(0x0000b420U, 0x00000004U);

                    for (jLoop = 0U; jLoop < 4; jLoop++)
                    {
                        r_rsip_func_sub024(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                        r_rsip_func_sub025(0x3c002859U, 0x20002c60U, 0x3c002b42U);
                        r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                        static const uint32_t Param_p0d_func100_016[] =
                        {
                            BSWAP_32BIG_C(0x8c164b95U), BSWAP_32BIG_C(0x3c32fd0fU), BSWAP_32BIG_C(0x0a516bb1U),
                            BSWAP_32BIG_C(0xddf95c50U),
                        };
                        r_rsip_func100(Param_p0d_func100_016);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            r_rsip_func_sub001(0x1009000dU);
                            r_rsip_func_sub001(0x10c90005U);

                            static const uint32_t Param_p0d_func101_013[] =
                            {
                                BSWAP_32BIG_C(0xec0fc5c8U), BSWAP_32BIG_C(0x6144c68aU), BSWAP_32BIG_C(0xb7e7bcbeU),
                                BSWAP_32BIG_C(0xb7ede7f5U),
                            };
                            r_rsip_func101(Param_p0d_func101_013);
                        }

                        r_rsip_func_sub024(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                        r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                        static const uint32_t Param_p0d_func100_017[] =
                        {
                            BSWAP_32BIG_C(0x0af6d1f2U), BSWAP_32BIG_C(0x8665d3c5U), BSWAP_32BIG_C(0x50d1dd0eU),
                            BSWAP_32BIG_C(0x3ef364c4U),
                        };
                        r_rsip_func100(Param_p0d_func100_017);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            r_rsip_func_sub001(0x1009000dU);
                            r_rsip_func_sub001(0x10c90005U);

                            static const uint32_t Param_p0d_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xb1432e78U), BSWAP_32BIG_C(0x0995a7b7U), BSWAP_32BIG_C(0x66d6bf47U),
                                BSWAP_32BIG_C(0xd08fde38U),
                            };
                            r_rsip_func101(Param_p0d_func101_014);
                        }

                        WR1_PROG(REG_1600H, 0x00000863U);
                        WR1_PROG(REG_1600H, 0x3c0028c2U);
                        r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                        static const uint32_t Param_p0d_func100_018[] =
                        {
                            BSWAP_32BIG_C(0x65ccdc79U), BSWAP_32BIG_C(0xaf4bfebfU), BSWAP_32BIG_C(0x673edc84U),
                            BSWAP_32BIG_C(0x009b678cU),
                        };
                        r_rsip_func100(Param_p0d_func100_018);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_1608H, 0x810100e0U);
                            r_rsip_func_sub001(0x1009000dU);
                            r_rsip_func_sub001(0x12490005U);

                            static const uint32_t Param_p0d_func101_015[] =
                            {
                                BSWAP_32BIG_C(0x5ad8157eU), BSWAP_32BIG_C(0x08efb79bU), BSWAP_32BIG_C(0x8435a772U),
                                BSWAP_32BIG_C(0x9a2b12d9U),
                            };
                            r_rsip_func101(Param_p0d_func101_015);
                        }

                        WR1_PROG(REG_1600H, 0x00002c40U);

                        static const uint32_t Param_p0d_func101_016[] =
                        {
                            BSWAP_32BIG_C(0xd3d39bcaU), BSWAP_32BIG_C(0x465e7014U), BSWAP_32BIG_C(0x83a9b1c2U),
                            BSWAP_32BIG_C(0x44ddb393U),
                        };
                        r_rsip_func101(Param_p0d_func101_016);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub011(0x08000c21U);

                    WR1_PROG(REG_1600H, 0x00002ca0U);

                    static const uint32_t Param_p0d_func101_017[] =
                    {
                        BSWAP_32BIG_C(0xace4cca9U), BSWAP_32BIG_C(0xb4da0198U), BSWAP_32BIG_C(0x44496754U),
                        BSWAP_32BIG_C(0x94724b21U),
                    };
                    r_rsip_func101(Param_p0d_func101_017);
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x38000805U);

                WR1_PROG(REG_1600H, 0x0000b7c0U);
                WR1_PROG(REG_1600H, 0x00000030U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000d01U);

                static const uint32_t Param_p0d_func101_018[] =
                {
                    BSWAP_32BIG_C(0x7dda89d5U), BSWAP_32BIG_C(0x7fe11744U), BSWAP_32BIG_C(0x2b9e0094U), BSWAP_32BIG_C(
                        0xc98f0645U),
                };
                r_rsip_func101(Param_p0d_func101_018);
                r_rsip_func083(InData_Image);

                WR1_PROG(REG_1600H, 0x00000929U);
                WR1_PROG(REG_1608H, 0x80880009U);
                r_rsip_func_sub001(0x03450021U);

                WR1_PROG(REG_2000H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000200U);

                WR1_PROG(REG_1404H, 0x10000000U);
                r_rsip_func_sub001(0x01430041U);

                WAIT_STS(REG_2030H, 4, 1);

                WR1_PROG(REG_1600H, 0x0000b520U);
                WR1_PROG(REG_1600H, 0x00000180U);
                WR1_PROG(REG_1A24H, 0x08000045U);
                WR1_PROG(REG_1608H, 0x81840009U);
                r_rsip_func_sub001(0x00890011U);

                WR1_PROG(REG_1A24H, 0x9c000005U);
                r_rsip_func_sub001(0x00850011U);

                WR1_PROG(REG_1600H, 0x0000a520U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1A24H, 0x08000045U);
                WR1_PROG(REG_1608H, 0x81840009U);
                r_rsip_func_sub001(0x00890011U);

                WR1_PROG(REG_1A24H, 0x9c000005U);
                r_rsip_func_sub001(0x00850011U);

                static const uint32_t Param_p0d_func100_019[] =
                {
                    BSWAP_32BIG_C(0x7e6c155eU), BSWAP_32BIG_C(0xe34ab487U), BSWAP_32BIG_C(0xdb30c0afU), BSWAP_32BIG_C(
                        0x42fa0182U),
                };
                r_rsip_func100(Param_p0d_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_14BCH, 0x00000020U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_VERIFICATION_FAIL;
                }
                else
                {
                    r_rsip_func_sub012(0x10000000U, 0x0000b420U, 0x00000060U);
                    WR1_PROG(REG_1608H, 0x80900001U);
                    r_rsip_func_sub001(0x03430041U);

                    WR1_PROG(REG_1404H, 0x19100000U);
                    r_rsip_func_sub019(0x00000fc1U, 0x00000300U, 0x08008107U);
                    WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[0]);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[4]);
                    r_rsip_func_sub001(0x00c10021U);

                    WR1_PROG(REG_1404H, 0x19600000U);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[8]);
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_CodeCertificateSignature[12]);
                    r_rsip_func_sub001(0x00c10021U);

                    WR1_PROG(REG_1600H, 0x00000b5aU);
                    WR1_PROG(REG_1600H, 0x00000b9cU);

                    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000d02U);

                    static const uint32_t Param_p0d_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x032af6f9U), BSWAP_32BIG_C(0x1566cf9aU), BSWAP_32BIG_C(0x17afdde4U),
                        BSWAP_32BIG_C(0xa92c3c12U),
                    };
                    r_rsip_func101(Param_p0d_func101_019);
                    r_rsip_func073(InData_DomainParam);

                    static const uint32_t Param_p0d_func100_020[] =
                    {
                        BSWAP_32BIG_C(0x1f6c4198U), BSWAP_32BIG_C(0x9c46fd47U), BSWAP_32BIG_C(0xa53c2456U),
                        BSWAP_32BIG_C(0x3c2e5212U),
                    };
                    r_rsip_func100(Param_p0d_func100_020);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_14BCH, 0x00000020U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_VERIFICATION_FAIL;
                    }
                    else
                    {
                        WR1_PROG(REG_2000H, 0x00000001U);

                        WR1_PROG(REG_2004H, 0x00000050U);

                        WR1_PROG(REG_2008H, 0x00000013U);

                        r_rsip_func_sub025(0x000037ebU, 0x0000b4e0U, 0x01522594U);

                        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000000dU);

                        static const uint32_t Param_p0d_func101_020[] =
                        {
                            BSWAP_32BIG_C(0x810d03cbU), BSWAP_32BIG_C(0x3b5ba7afU), BSWAP_32BIG_C(0xfceb03bbU),
                            BSWAP_32BIG_C(0x128b21b9U),
                        };
                        r_rsip_func101(Param_p0d_func101_020);
                        r_rsip_func082();

                        r_rsip_func_sub024(0x0000357fU, 0x00000800U, 0x00003436U, 0x01836c01U);
                        r_rsip_func_sub024(0x00036c21U, 0x00000842U, 0x0000346bU, 0x01856c43U);
                        r_rsip_func_sub024(0x00056c63U, 0x0c002423U, 0x00802402U, 0x00000842U);
                        WR1_PROG(REG_1600H, 0x0c00a420U);
                        WR1_PROG(REG_1600H, 0x00000200U);
                        r_rsip_func_sub006(0x00802402U, 0x38001001U, 0x00260000U);

                        static const uint32_t Param_p0d_func100_021[] =
                        {
                            BSWAP_32BIG_C(0x28a09012U), BSWAP_32BIG_C(0x32c1bbe5U), BSWAP_32BIG_C(0x75350176U),
                            BSWAP_32BIG_C(0x07ea20f0U),
                        };
                        r_rsip_func100(Param_p0d_func100_021);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

                            WR1_PROG(REG_200CH, 0x00000001U);

                            WAIT_STS(REG_2030H, 8, 0);

                            r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

                            WR1_PROG(REG_200CH, 0x00000100U);

                            WAIT_STS(REG_2030H, 4, 1);

                            static const uint32_t Param_p0d_func100_022[] =
                            {
                                BSWAP_32BIG_C(0x3470fe60U), BSWAP_32BIG_C(0x6038d875U), BSWAP_32BIG_C(0x5c49920cU),
                                BSWAP_32BIG_C(0x1466ad29U),
                            };
                            r_rsip_func100(Param_p0d_func100_022);
                            WR1_PROG(REG_1408H, 0x00004022U);
                            for (iLoop = 0U; iLoop < 8U; iLoop++)
                            {
                                WAIT_STS(REG_1408H, 30, 1);
                                RD1_ADDR(REG_1420H, &OutData_MAC[iLoop]);
                            }

                            WR1_PROG(REG_1458H, 0x00000000U);

                            WR1_PROG(REG_1B08H, 0x00000216U);

                            static const uint32_t Param_p0d_func102_001[] =
                            {
                                BSWAP_32BIG_C(0x23089c47U), BSWAP_32BIG_C(0xbacad5d2U), BSWAP_32BIG_C(0x1aaf3f13U),
                                BSWAP_32BIG_C(0xd09fa1e1U),
                            };
                            r_rsip_func102(Param_p0d_func102_001);
                            WR1_PROG(REG_149CH, 0x00000040U);
                            WAIT_STS(REG_142CH, 12, 0);

                            return RSIP_RET_PASS;
                        }
                        else
                        {
                            static const uint32_t Param_p0d_func100_023[] =
                            {
                                BSWAP_32BIG_C(0xd4c123c7U), BSWAP_32BIG_C(0x1a9ed1c9U), BSWAP_32BIG_C(0x8e8a5ab1U),
                                BSWAP_32BIG_C(0xf78792fdU),
                            };
                            r_rsip_func100(Param_p0d_func100_023);
                            r_rsip_func_sub016(0x81020000U, 0x0000500aU);
                            RD1_ADDR(REG_1420H, &S_RAM[0]);
                            S_RAM[0] = bswap_32big(S_RAM[0]);
                            WAIT_STS(REG_1408H, 30, 1);
                            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
                            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

                            r_rsip_func_sub036(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

                            WR1_PROG(REG_200CH, 0x00000001U);

                            static const uint32_t Param_p0d_func100_024[] =
                            {
                                BSWAP_32BIG_C(0x1a9d11bfU), BSWAP_32BIG_C(0x62cf9404U), BSWAP_32BIG_C(0x6962b083U),
                                BSWAP_32BIG_C(0xf19a64d2U),
                            };
                            r_rsip_func100(Param_p0d_func100_024);
                            r_rsip_func_sub020(0x000003a1U, 0x08000045U);
                            WR4_PROG(REG_1420H, bswap_32big(0x8ab22685U), bswap_32big(0xbfab115bU),
                                     bswap_32big(0x841c0f17U), bswap_32big(0xa1af8aa1U));

                            r_rsip_func_sub024(0x00003416U, 0x00026800U, 0x00008c00U, 0xfffffffcU);

                            r_rsip_func_sub016(0x81010000U, 0x00005006U);
                            RD1_ADDR(REG_1420H, &S_RAM[0]);
                            S_RAM[0] = bswap_32big(S_RAM[0]);

                            WR1_PROG(REG_1600H, 0x000008a5U);

                            WR1_PROG(REG_1824H, 0x0e0c0446U);

                            for (iLoop = 0U; iLoop < S_RAM[0]; )
                            {
                                WR1_PROG(REG_1444H, 0x000003caU);
                                WAIT_STS(REG_1444H, 31, 1);
                                WR4_ADDR(REG_1420H, &InData_CodeCertificate[iLoop]);

                                WR1_PROG(REG_1600H, 0x0000a4a0U);
                                WR1_PROG(REG_1600H, 0x00000004U);

                                static const uint32_t Param_p0d_func101_021[] =
                                {
                                    BSWAP_32BIG_C(0x5c292978U), BSWAP_32BIG_C(0x60c7bff0U), BSWAP_32BIG_C(0x3ef9b0a2U),
                                    BSWAP_32BIG_C(0x96ff5accU),
                                };
                                r_rsip_func101(Param_p0d_func101_021);
                                iLoop = iLoop + 4U;
                            }

                            WR1_PROG(REG_1458H, 0x00000000U);
                            static const uint32_t Param_p0d_func100_025[] =
                            {
                                BSWAP_32BIG_C(0x807d1fd1U), BSWAP_32BIG_C(0xafdd4ee9U), BSWAP_32BIG_C(0x6121e6b6U),
                                BSWAP_32BIG_C(0x4fc0714bU),
                            };
                            r_rsip_func100(Param_p0d_func100_025);

                            r_rsip_func_sub011(0x38000805U);

                            r_rsip_func_sub024(0x00003416U, 0x0000a400U, 0x00000003U, 0x00026800U);

                            r_rsip_func_sub016(0x81010000U, 0x00005006U);
                            RD1_ADDR(REG_1420H, &S_RAM[0]);
                            S_RAM[0] = bswap_32big(S_RAM[0]);

                            r_rsip_func_sub024(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

                            iTemp = iLoop;
                            for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
                            {
                                r_rsip_func_sub010(0x000000c7U, 0x80010100U);
                                WR1_PROG(REG_1420H, InData_CodeCertificate[iLoop]);
                                r_rsip_func_sub039(0x0000b420U, 0x00000004U);

                                for (jLoop = 0U; jLoop < 4; jLoop++)
                                {
                                    r_rsip_func_sub024(0x00003020U, 0x01886ce8U, 0x00086d08U, 0x00000863U);
                                    WR1_PROG(REG_1600H, 0x3c0028c2U);
                                    r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                                    static const uint32_t Param_p0d_func100_026[] =
                                    {
                                        BSWAP_32BIG_C(0x94552a48U), BSWAP_32BIG_C(0xe58be834U), BSWAP_32BIG_C(
                                            0x9ff2f743U),           BSWAP_32BIG_C(0xb0673975U),
                                    };
                                    r_rsip_func100(Param_p0d_func100_026);
                                    WR1_PROG(REG_143CH, 0x00400000U);

                                    if (CHCK_STS(REG_143CH, 22, 1))
                                    {
                                        WR1_PROG(REG_1608H, 0x810100e0U);
                                        r_rsip_func_sub001(0x1009000dU);
                                        r_rsip_func_sub001(0x12490005U);

                                        static const uint32_t Param_p0d_func101_022[] =
                                        {
                                            BSWAP_32BIG_C(0x81c74b5cU), BSWAP_32BIG_C(0x4453b1cdU), BSWAP_32BIG_C(
                                                0x3ce7e6f4U),           BSWAP_32BIG_C(0xcdd3e4a0U),
                                        };
                                        r_rsip_func101(Param_p0d_func101_022);
                                    }

                                    WR1_PROG(REG_1600H, 0x00002c40U);

                                    static const uint32_t Param_p0d_func101_023[] =
                                    {
                                        BSWAP_32BIG_C(0x3260293cU), BSWAP_32BIG_C(0xcff54e13U), BSWAP_32BIG_C(
                                            0x2b81adb4U),           BSWAP_32BIG_C(0xcac1a2daU),
                                    };
                                    r_rsip_func101(Param_p0d_func101_023);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);
                                r_rsip_func_sub011(0x08000c21U);

                                WR1_PROG(REG_1600H, 0x00002ca0U);

                                static const uint32_t Param_p0d_func101_024[] =
                                {
                                    BSWAP_32BIG_C(0x4af10ec7U), BSWAP_32BIG_C(0x81f4dd98U), BSWAP_32BIG_C(0x067aea8cU),
                                    BSWAP_32BIG_C(0xd733d0a5U),
                                };
                                r_rsip_func101(Param_p0d_func101_024);
                            }

                            WR1_PROG(REG_1458H, 0x00000000U);

                            r_rsip_func_sub011(0x38000805U);

                            WR1_PROG(REG_1404H, 0x19100000U);
                            r_rsip_func_sub001(0x11430081U);
                            WR1_PROG(REG_1404H, 0x19600000U);
                            r_rsip_func_sub001(0x11430081U);

                            WR1_PROG(REG_1600H, 0x0000b7c0U);
                            WR1_PROG(REG_1600H, 0x00000080U);

                            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00000d02U);

                            static const uint32_t Param_p0d_func101_025[] =
                            {
                                BSWAP_32BIG_C(0x0ea2b246U), BSWAP_32BIG_C(0x20949da3U), BSWAP_32BIG_C(0xb7b4fd6fU),
                                BSWAP_32BIG_C(0x1f73d099U),
                            };
                            r_rsip_func101(Param_p0d_func101_025);
                            r_rsip_func083(InData_Image);

                            WR1_PROG(REG_1824H, 0x9c000005U);
                            r_rsip_func_sub026(0x0000b7e0U, 0x00000030U, 0x8184001fU);
                            r_rsip_func_sub001(0x00490011U);

                            static const uint32_t Param_p0d_func100_027[] =
                            {
                                BSWAP_32BIG_C(0x34d0cf7cU), BSWAP_32BIG_C(0xa8cff4e4U), BSWAP_32BIG_C(0x82ae773bU),
                                BSWAP_32BIG_C(0x3893daa4U),
                            };
                            r_rsip_func100(Param_p0d_func100_027);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                static const uint32_t Param_p0d_func102_002[] =
                                {
                                    BSWAP_32BIG_C(0x651d6ce0U), BSWAP_32BIG_C(0xeb3ef632U), BSWAP_32BIG_C(0x6ff722e0U),
                                    BSWAP_32BIG_C(0xfb5aa02bU),
                                };
                                r_rsip_func102(Param_p0d_func102_002);
                                WR1_PROG(REG_14BCH, 0x00000020U);
                                WAIT_STS(REG_142CH, 12, 0);

                                return RSIP_RET_FAIL;
                            }
                            else
                            {
                                static const uint32_t Param_p0d_func100_028[] =
                                {
                                    BSWAP_32BIG_C(0xdb69aebfU), BSWAP_32BIG_C(0x07da4621U), BSWAP_32BIG_C(0x6540a723U),
                                    BSWAP_32BIG_C(0xe2d99dddU),
                                };
                                r_rsip_func100(Param_p0d_func100_028);

                                WR1_PROG(REG_1408H, 0x00004022U);
                                for (iLoop = 0U; iLoop < 8U; iLoop++)
                                {
                                    WAIT_STS(REG_1408H, 30, 1);
                                    RD1_ADDR(REG_1420H, &OutData_MAC[iLoop]);
                                }

                                WR1_PROG(REG_1458H, 0x00000000U);

                                WR1_PROG(REG_1B08H, 0x00000216U);

                                static const uint32_t Param_p0d_func102_003[] =
                                {
                                    BSWAP_32BIG_C(0x0a5197c9U), BSWAP_32BIG_C(0xa558050dU), BSWAP_32BIG_C(0x79626149U),
                                    BSWAP_32BIG_C(0x69be5213U),
                                };
                                r_rsip_func102(Param_p0d_func102_003);
                                WR1_PROG(REG_149CH, 0x00000040U);
                                WAIT_STS(REG_142CH, 12, 0);

                                return RSIP_RET_PASS;
                            }
                        }
                    }
                }
            }
        }
    }
}
