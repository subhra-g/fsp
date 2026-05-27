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

rsip_ret_t r_rsip_p5e (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x005e0001U, 0x000007f0U);

    static const uint32_t Param_p5e_func100_001[] =
    {
        BSWAP_32BIG_C(0x9ec81dc5U), BSWAP_32BIG_C(0x86a5f7bfU), BSWAP_32BIG_C(0xfc961526U), BSWAP_32BIG_C(0x5ecad9e4U),
    };
    r_rsip_func100(Param_p5e_func100_001);
    r_rsip_func078(InData_DomainParam);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00005e01U);

    static const uint32_t Param_p5e_func101_001[] =
    {
        BSWAP_32BIG_C(0x22707a71U), BSWAP_32BIG_C(0x31419731U), BSWAP_32BIG_C(0x9631ab58U), BSWAP_32BIG_C(0x8e3b21f2U),
    };
    r_rsip_func101(Param_p5e_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000021U);

    r_rsip_func_sub003(0x800103a0U, 0x00005e01U);

    static const uint32_t Param_p5e_func101_002[] =
    {
        BSWAP_32BIG_C(0xa2f406b9U), BSWAP_32BIG_C(0xc6ff63bfU), BSWAP_32BIG_C(0x0f3ba4dfU), BSWAP_32BIG_C(0x186d194dU),
    };
    r_rsip_func101(Param_p5e_func101_002);
    r_rsip_func044();

    r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xf7009d07U);

    WR1_PROG(REG_1404H, 0x13000000U);

    for (iLoop = 0U; iLoop < 16U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x00c20011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p5e_func100_002[] =
    {
        BSWAP_32BIG_C(0xb534c47cU), BSWAP_32BIG_C(0x460553cfU), BSWAP_32BIG_C(0xffd9ab01U), BSWAP_32BIG_C(0xf1496075U),
    };
    r_rsip_func100(Param_p5e_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p5e_func102_001[] =
        {
            BSWAP_32BIG_C(0xc3187250U), BSWAP_32BIG_C(0x643e388cU), BSWAP_32BIG_C(0x59b298e7U), BSWAP_32BIG_C(
                0x404437b6U),
        };
        r_rsip_func102(Param_p5e_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x80010360U);
        WR1_PROG(REG_1420H, InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub017(0x38000f7bU, 0x00260000U);

        static const uint32_t Param_p5e_func100_003[] =
        {
            BSWAP_32BIG_C(0x21f4316cU), BSWAP_32BIG_C(0x6812877bU), BSWAP_32BIG_C(0xb6353afeU), BSWAP_32BIG_C(
                0xdb4ffc30U),
        };
        r_rsip_func100(Param_p5e_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1444H, 0x00000fd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 64U; )
            {
                WR1_ADDR((&(REG_00D0H))[iLoop / 4], &InData_PubKey[0 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1444H, 0x00000fd0U);
            WAIT_STS(REG_1444H, 31, 1);
            for (iLoop = 0U; iLoop < 64U; )
            {
                WR1_ADDR((&(REG_0120H))[iLoop / 4], &InData_PubKey[16 + (iLoop / 4)]);
                iLoop = iLoop + 4U;
            }

            static const uint32_t Param_p5e_func101_003[] =
            {
                BSWAP_32BIG_C(0x720ea1c9U), BSWAP_32BIG_C(0x509767cbU), BSWAP_32BIG_C(0xd4b5ad8cU), BSWAP_32BIG_C(
                    0xf606a66dU),
            };
            r_rsip_func101(Param_p5e_func101_003);
        }
        else
        {
            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x800103a0U, 0x00005e02U);

            static const uint32_t Param_p5e_func101_004[] =
            {
                BSWAP_32BIG_C(0x750dba55U), BSWAP_32BIG_C(0xf32bcd6cU), BSWAP_32BIG_C(0x8ef2d430U), BSWAP_32BIG_C(
                    0x94eb9988U),
            };
            r_rsip_func101(Param_p5e_func101_004);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000020U);

            r_rsip_func_sub003(0x800103a0U, 0x00005e02U);

            static const uint32_t Param_p5e_func101_005[] =
            {
                BSWAP_32BIG_C(0xace84df0U), BSWAP_32BIG_C(0x78a593eaU), BSWAP_32BIG_C(0x65d2b1c6U), BSWAP_32BIG_C(
                    0x50c53192U),
            };
            r_rsip_func101(Param_p5e_func101_005);
            r_rsip_func044();

            r_rsip_func_sub004(0x08000044U, 0x00000000U);

            r_rsip_func_sub024(0x00001fc2U, 0x40000700U, 0xe8009107U);

            WR1_PROG(REG_1404H, 0x10d00000U);

            for (iLoop = 0U; iLoop < 16U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);
                r_rsip_func_sub001(0x00c20011U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x11200000U);

            for (iLoop = 16; iLoop < 32U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);
                r_rsip_func_sub001(0x00c20011U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_PubKey[1 + iLoop]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p5e_func100_004[] =
            {
                BSWAP_32BIG_C(0x665ae25fU), BSWAP_32BIG_C(0xca1b48c7U), BSWAP_32BIG_C(0x65e2d8f3U), BSWAP_32BIG_C(
                    0x4c74b596U),
            };
            r_rsip_func100(Param_p5e_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p5e_func102_002[] =
                {
                    BSWAP_32BIG_C(0xe03e2e65U), BSWAP_32BIG_C(0x2a928c08U), BSWAP_32BIG_C(0x9bc7a7dbU), BSWAP_32BIG_C(
                        0xccd11a61U),
                };
                r_rsip_func102(Param_p5e_func102_002);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                static const uint32_t Param_p5e_func101_006[] =
                {
                    BSWAP_32BIG_C(0x6df9e95cU), BSWAP_32BIG_C(0xff4b6e67U), BSWAP_32BIG_C(0x286c4209U), BSWAP_32BIG_C(
                        0x29649bc4U),
                };
                r_rsip_func101(Param_p5e_func101_006);
            }
        }

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x00000390U, 0x00000070U);
        r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080001U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x00000890U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x08080005U, 0x00010001U);
        r_rsip_func_sub007(0x00000160U, 0x000001b0U, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
        r_rsip_func_sub007(0x00000110U, 0x000008e0U, 0x00000070U);
        r_rsip_func_sub005(0x00000160U, 0x08080005U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        r_rsip_func_sub005(0x00000110U, 0x08080001U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x00000250U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000110U, 0x00000250U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p5e_func100_005[] =
        {
            BSWAP_32BIG_C(0xf9261bc1U), BSWAP_32BIG_C(0xd6eaa74eU), BSWAP_32BIG_C(0xe3fae5a7U), BSWAP_32BIG_C(
                0xe8b40460U),
        };
        r_rsip_func100(Param_p5e_func100_005);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p5e_func102_003[] =
            {
                BSWAP_32BIG_C(0x0658321aU), BSWAP_32BIG_C(0x3e292b30U), BSWAP_32BIG_C(0x88c93ec2U), BSWAP_32BIG_C(
                    0xef3abf45U),
            };
            r_rsip_func102(Param_p5e_func102_003);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_func_sub001(0x00c00041U);

            r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000208U, 0x08080009U);

            r_rsip_func_sub002(0x000001b0U, 0x00000110U, 0x000001c0U, 0x08080009U);

            r_rsip_func_sub003(0x800103a0U, 0x0000005eU);

            static const uint32_t Param_p5e_func101_007[] =
            {
                BSWAP_32BIG_C(0x0a0b6ae8U), BSWAP_32BIG_C(0xb114e1eeU), BSWAP_32BIG_C(0xe370d62eU), BSWAP_32BIG_C(
                    0xce8d26f0U),
            };
            r_rsip_func101(Param_p5e_func101_007);
            r_rsip_func090();

            static const uint32_t Param_p5e_func100_006[] =
            {
                BSWAP_32BIG_C(0x49c88b2bU), BSWAP_32BIG_C(0xdc0090b7U), BSWAP_32BIG_C(0x34344d74U), BSWAP_32BIG_C(
                    0xa064f96aU),
            };
            r_rsip_func100(Param_p5e_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p5e_func102_004[] =
                {
                    BSWAP_32BIG_C(0x27b9a001U), BSWAP_32BIG_C(0x37c6afa0U), BSWAP_32BIG_C(0xede4928fU), BSWAP_32BIG_C(
                        0x297f3a72U),
                };
                r_rsip_func102(Param_p5e_func102_004);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x800103a0U, 0x0000005eU);

                static const uint32_t Param_p5e_func101_008[] =
                {
                    BSWAP_32BIG_C(0x702bd440U), BSWAP_32BIG_C(0x5b3ea5b1U), BSWAP_32BIG_C(0x9bd39d87U), BSWAP_32BIG_C(
                        0xb2a75b85U),
                };
                r_rsip_func101(Param_p5e_func101_008);
                r_rsip_func113();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x800103a0U, 0x00005e03U);

                static const uint32_t Param_p5e_func101_009[] =
                {
                    BSWAP_32BIG_C(0x92330e87U), BSWAP_32BIG_C(0x643389e0U), BSWAP_32BIG_C(0xf25824c8U), BSWAP_32BIG_C(
                        0x7421bb3eU),
                };
                r_rsip_func101(Param_p5e_func101_009);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x015d7825U);

                r_rsip_func_sub003(0x800103a0U, 0x00005e03U);

                static const uint32_t Param_p5e_func101_010[] =
                {
                    BSWAP_32BIG_C(0x174d22bcU), BSWAP_32BIG_C(0xf26e30bfU), BSWAP_32BIG_C(0x5407034eU), BSWAP_32BIG_C(
                        0xa17ba109U),
                };
                r_rsip_func101(Param_p5e_func101_010);
                r_rsip_func044();

                static const uint32_t Param_p5e_func100_007[] =
                {
                    BSWAP_32BIG_C(0x7e29937dU), BSWAP_32BIG_C(0x61bc20caU), BSWAP_32BIG_C(0xaef4813bU), BSWAP_32BIG_C(
                        0x632b9baaU),
                };
                r_rsip_func100(Param_p5e_func100_007);
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12600000U);
                r_rsip_func_sub001(0x00830031U);

                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0U; iLoop < 12U; )
                {
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_EncSecret[1 + iLoop]);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                static const uint32_t Param_p5e_func100_008[] =
                {
                    BSWAP_32BIG_C(0x93d49611U), BSWAP_32BIG_C(0x929805f6U), BSWAP_32BIG_C(0x31345036U), BSWAP_32BIG_C(
                        0xb9a57ec4U),
                };
                r_rsip_func100(Param_p5e_func100_008);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_func_sub001(0x00830011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[1 + iLoop]);
                static const uint32_t Param_p5e_func100_009[] =
                {
                    BSWAP_32BIG_C(0x62ef240fU), BSWAP_32BIG_C(0x0b0221caU), BSWAP_32BIG_C(0xb85408d3U), BSWAP_32BIG_C(
                        0x69196231U),
                };
                r_rsip_func100(Param_p5e_func100_009);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_EncSecret[5 + iLoop]);

                static const uint32_t Param_p5e_func100_010[] =
                {
                    BSWAP_32BIG_C(0x7f39e817U), BSWAP_32BIG_C(0x646ce88eU), BSWAP_32BIG_C(0x24272f19U), BSWAP_32BIG_C(
                        0x4ed2645fU),
                };
                r_rsip_func100(Param_p5e_func100_010);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);

                static const uint32_t Param_p5e_func102_005[] =
                {
                    BSWAP_32BIG_C(0x8e7c47bcU), BSWAP_32BIG_C(0xed24f5d3U), BSWAP_32BIG_C(0x39f9ef60U), BSWAP_32BIG_C(
                        0x70f95a1cU),
                };
                r_rsip_func102(Param_p5e_func102_005);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
