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

void r_rsip_func090 (void)
{
    WR1_PROG(REG_1600H, 0x0000373dU);

    WR1_PROG(REG_1404H, 0x11200000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003f0U, 0x08080010U);

    r_rsip_func_sub003(0x800103a0U, 0x00f09001U);

    static const uint32_t Param_func090_func101_001[] =
    {
        BSWAP_32BIG_C(0x146efdfaU), BSWAP_32BIG_C(0xfd2f475aU), BSWAP_32BIG_C(0x6477acd1U), BSWAP_32BIG_C(0x8b500af8U),
    };
    r_rsip_func101(Param_func090_func101_001);
    r_rsip_func113();
    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x800103a0U, 0x00f09002U);

    static const uint32_t Param_func090_func101_002[] =
    {
        BSWAP_32BIG_C(0x522c8c7bU), BSWAP_32BIG_C(0x680bbfc5U), BSWAP_32BIG_C(0x7593b7e9U), BSWAP_32BIG_C(0x0f87ff5dU),
    };
    r_rsip_func101(Param_func090_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x800103a0U, 0x00f09003U);

    static const uint32_t Param_func090_func101_003[] =
    {
        BSWAP_32BIG_C(0x000b6d47U), BSWAP_32BIG_C(0xe24b3cefU), BSWAP_32BIG_C(0x3c991f7aU), BSWAP_32BIG_C(0x8fa72b7cU),
    };
    r_rsip_func101(Param_func090_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x800103a0U, 0x00f09004U);

    static const uint32_t Param_func090_func101_004[] =
    {
        BSWAP_32BIG_C(0x4a77a2ebU), BSWAP_32BIG_C(0xcf0adf66U), BSWAP_32BIG_C(0x0f6b1e2bU), BSWAP_32BIG_C(0x13cdf571U),
    };
    r_rsip_func101(Param_func090_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x000003f0U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);

    WR1_PROG(REG_1004H, 0x08080004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);
    WR1_PROG(REG_1404H, 0x13f80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000480U, 0x00000438U, 0x00000160U, 0x08080009U);

    r_rsip_func_sub036(0x00000020U, 0x000000c0U, 0x08080010U);
    WR1_PROG(REG_1000H, 0x00010001U);
    r_rsip_func_sub007(0x00000340U, 0x00000160U, 0x000000c0U);
    r_rsip_func_sub005(0x00000110U, 0x08080005U, 0x00010001U);
    WAIT_STS(REG_1000H, 0, 0);

    r_rsip_func_sub002(0x00000110U, 0x00000438U, 0x00000480U, 0x0808000aU);

    WR1_PROG(REG_143CH, 0x00210000U);

    static const uint32_t Param_func090_func100_001[] =
    {
        BSWAP_32BIG_C(0x7b9ab5a1U), BSWAP_32BIG_C(0xc9e75f70U), BSWAP_32BIG_C(0xd0d198deU), BSWAP_32BIG_C(0x72f479afU),
    };
    r_rsip_func100(Param_func090_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1600H, 0x00000800U);

        static const uint32_t Param_func090_func101_005[] =
        {
            BSWAP_32BIG_C(0xa120cc82U), BSWAP_32BIG_C(0x6dc2dee0U), BSWAP_32BIG_C(0xd7da71cfU), BSWAP_32BIG_C(
                0x7b065620U),
        };
        r_rsip_func101(Param_func090_func101_005);
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);

        WR1_PROG(REG_1004H, 0x08080004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x13b00000U);
        r_rsip_func_sub001(0x00c00041U);

        r_rsip_func_sub002(0x00000890U, 0x000003f0U, 0x000002a8U, 0x08080009U);

        r_rsip_func_sub002(0x00000070U, 0x000003f0U, 0x000002f0U, 0x08080009U);

        static const uint32_t Param_func090_func100_002[] =
        {
            BSWAP_32BIG_C(0x9f659b48U), BSWAP_32BIG_C(0x3f1f3f6bU), BSWAP_32BIG_C(0x1836eeebU), BSWAP_32BIG_C(
                0x75bcf669U),
        };
        r_rsip_func100(Param_func090_func100_002);
        r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x08080015U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);
        WR1_PROG(REG_143CH, 0x00000d00U);

        WR1_PROG(REG_1404H, 0x10d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000480U, 0x00000110U, 0x000004e0U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_func090_func100_003[] =
        {
            BSWAP_32BIG_C(0xa78fb95eU), BSWAP_32BIG_C(0x939c3302U), BSWAP_32BIG_C(0x82e97960U), BSWAP_32BIG_C(
                0xbed0aa1bU),
        };
        r_rsip_func100(Param_func090_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_func090_func101_006[] =
            {
                BSWAP_32BIG_C(0x847e2179U), BSWAP_32BIG_C(0x8fe44a08U), BSWAP_32BIG_C(0xaa6c1ebcU), BSWAP_32BIG_C(
                    0x0cc1882aU),
            };
            r_rsip_func101(Param_func090_func101_006);
        }
        else
        {
            static const uint32_t Param_func090_func100_004[] =
            {
                BSWAP_32BIG_C(0xabcb0a0fU), BSWAP_32BIG_C(0x7c251845U), BSWAP_32BIG_C(0xee97c110U), BSWAP_32BIG_C(
                    0xdc3d1906U),
            };
            r_rsip_func100(Param_func090_func100_004);
            r_rsip_func_sub013(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x08080015U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000570U, 0x00000110U, 0x000001b0U, 0x0808000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_func090_func100_005[] =
            {
                BSWAP_32BIG_C(0xd9f79d72U), BSWAP_32BIG_C(0xe905c49eU), BSWAP_32BIG_C(0xe962554dU), BSWAP_32BIG_C(
                    0x599d7a7dU),
            };
            r_rsip_func100(Param_func090_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_func090_func101_007[] =
                {
                    BSWAP_32BIG_C(0xed590de9U), BSWAP_32BIG_C(0x3b4d5a05U), BSWAP_32BIG_C(0x5abc4d98U), BSWAP_32BIG_C(
                        0x2df5cc3eU),
                };
                r_rsip_func101(Param_func090_func101_007);
            }
            else
            {
                static const uint32_t Param_func090_func100_006[] =
                {
                    BSWAP_32BIG_C(0x139f3739U), BSWAP_32BIG_C(0x4049c13eU), BSWAP_32BIG_C(0x495a2bcdU), BSWAP_32BIG_C(
                        0x2df01342U),
                };
                r_rsip_func100(Param_func090_func100_006);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x08080004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);

                r_rsip_func_sub013(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1014H, 0x000004e0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x00000528U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x00000070U, 0x00000200U, 0x00000110U, 0x0808000aU);

                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000528U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x00000390U, 0x00000070U);
                r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_func_sub001(0x00c00041U);

                r_rsip_func_sub002(0x00000110U, 0x00000160U, 0x000004e0U, 0x08080009U);

                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x00000570U, 0x08080004U, 0x00010001U);
                r_rsip_func_sub007(0x00000480U, 0x00000570U, 0x00000070U);
                r_rsip_func_sub005(0x00000250U, 0x08080013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1404H, 0x12b00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_func090_func100_007[] =
                {
                    BSWAP_32BIG_C(0xeb8d1d62U), BSWAP_32BIG_C(0xa755d3cfU), BSWAP_32BIG_C(0x195f4c82U), BSWAP_32BIG_C(
                        0xfd7a9716U),
                };
                r_rsip_func100(Param_func090_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_func090_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x720de485U), BSWAP_32BIG_C(0x07e1bcafU), BSWAP_32BIG_C(0xabc24dedU),
                        BSWAP_32BIG_C(0x06ae438cU),
                    };
                    r_rsip_func101(Param_func090_func101_008);
                }
                else
                {
                    static const uint32_t Param_func090_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x345bc152U), BSWAP_32BIG_C(0x256d9aa7U), BSWAP_32BIG_C(0x9562dbfaU),
                        BSWAP_32BIG_C(0xb61b9073U),
                    };
                    r_rsip_func100(Param_func090_func100_008);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x08080004U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000002U);
                    r_rsip_func_sub001(0x00c0003dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);

                    r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);
                    WR1_PROG(REG_143CH, 0x00000d00U);

                    WR1_PROG(REG_1014H, 0x000001c0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    r_rsip_func_sub005(0x000002a0U, 0x08080002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000208U, 0x00000160U, 0x00000070U);
                    r_rsip_func_sub005(0x000002f0U, 0x08080002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x1b8be139U);

                    static const uint32_t Param_func090_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x5c6be6c6U), BSWAP_32BIG_C(0xd96bdaaaU), BSWAP_32BIG_C(0xd6ecd6ebU),
                        BSWAP_32BIG_C(0xe05c243cU),
                    };
                    r_rsip_func101(Param_func090_func101_009);
                }
            }
        }
    }

    r_rsip_func_sub006(0x38008800U, 0x1b8be139U, 0x00A60000U);

    WR1_PROG(REG_1600H, 0x000037b9U);

    r_rsip_func_sub014(0x00007c1dU, 0x00602000U);
}
