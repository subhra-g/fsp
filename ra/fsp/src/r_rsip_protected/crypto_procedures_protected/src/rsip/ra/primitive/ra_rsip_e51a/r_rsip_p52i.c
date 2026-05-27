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

rsip_ret_t r_rsip_p52i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00520001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005201U);

    static const uint32_t Param_p52i_func101_001[] =
    {
        BSWAP_32BIG_C(0x824797a5U), BSWAP_32BIG_C(0x57f03067U), BSWAP_32BIG_C(0xfd436db2U), BSWAP_32BIG_C(0x5ad5c06dU),
    };
    r_rsip_func101(Param_p52i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000024U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00005201U);

    static const uint32_t Param_p52i_func101_002[] =
    {
        BSWAP_32BIG_C(0x6d9f385aU), BSWAP_32BIG_C(0x4c62006eU), BSWAP_32BIG_C(0xb062d09dU), BSWAP_32BIG_C(0x99601c4aU),
    };
    r_rsip_func101(Param_p52i_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub023(0x000027c2U, 0x40000900U, 0xe8009107U);

    r_rsip_func_sub026(0x0000b420U, 0x00000060U, 0x80a80001U);
    for (iLoop = 0U; iLoop < 40U; )
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);
        r_rsip_func_sub001(0x03420011U);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[41]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p52i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb6478413U), BSWAP_32BIG_C(0xd608b3e9U), BSWAP_32BIG_C(0x3fa0458eU), BSWAP_32BIG_C(0xd3ef200aU),
    };
    r_rsip_func100(Param_p52i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p52i_func102_001[] =
        {
            BSWAP_32BIG_C(0x5df08693U), BSWAP_32BIG_C(0x23dca38aU), BSWAP_32BIG_C(0x4fa252f5U), BSWAP_32BIG_C(
                0x71e40057U),
        };
        r_rsip_func102(Param_p52i_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000fc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1608H, 0x8090001fU);
        for (iLoop = 0U; iLoop < 16U; iLoop++)
        {
            WAIT_STS(REG_1444H, 31, 1);
            WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub025(0x00000bdeU, 0x0000b7e0U, 0x00000100U);

        WR1_PROG(REG_1A2CH, 0x00000300U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        for (iLoop = 0U; iLoop < 16U; )
        {
            WR1_PROG(REG_1608H, 0x8184001eU);
            r_rsip_func_sub001(0x00890011U);
            WR1_PROG(REG_1608H, 0x8084001fU);
            r_rsip_func_sub001(0x03420011U);

            r_rsip_func_sub024(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x80010360U, 0x00000052U);

        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);

        static const uint32_t Param_p52i_func100_002[] =
        {
            BSWAP_32BIG_C(0x51e95866U), BSWAP_32BIG_C(0x4b4b88d8U), BSWAP_32BIG_C(0x940769e3U), BSWAP_32BIG_C(
                0x97ded03bU),
        };
        r_rsip_func100(Param_p52i_func100_002);
        r_rsip_func086(InData_DomainParam);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x09090010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x09090010U);

        WR1_PROG(REG_1404H, 0x18e00000U);
        r_rsip_func_sub008(0x000027c2U, 0x00000900U, 0x08008107U);
        WR4_ADDR(REG_1420H, &InData_Signature[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[4]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[8]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[12]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[16]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x19300000U);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[20]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[24]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[28]);
        r_rsip_func_sub001(0x00c20031U);

        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[32]);
        WAIT_STS(REG_1444H, 31, 1);
        WR4_ADDR(REG_1420H, &InData_Signature[36]);
        r_rsip_func_sub001(0x00c20021U);

        WR1_PROG(REG_1404H, 0x11b80000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c00045U);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000200U, 0x00000160U, 0x0909000aU);

        r_rsip_func_sub002(0x00000160U, 0x00000930U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000930U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000160U, 0x00000980U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        r_rsip_func_sub002(0x00000980U, 0x00000200U, 0x000001b0U, 0x0909000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p52i_func100_003[] =
        {
            BSWAP_32BIG_C(0x671645acU), BSWAP_32BIG_C(0xbcb0f4eaU), BSWAP_32BIG_C(0xf5670500U), BSWAP_32BIG_C(
                0xf6cf6767U),
        };
        r_rsip_func100(Param_p52i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            WR1_PROG(REG_1600H, 0x00000800U);

            static const uint32_t Param_p52i_func101_003[] =
            {
                BSWAP_32BIG_C(0x3e87889dU), BSWAP_32BIG_C(0xb685bb8fU), BSWAP_32BIG_C(0xb7379a85U), BSWAP_32BIG_C(
                    0x35cac746U),
            };
            r_rsip_func101(Param_p52i_func101_003);
        }
        else
        {
            static const uint32_t Param_p52i_func100_004[] =
            {
                BSWAP_32BIG_C(0x7dee736eU), BSWAP_32BIG_C(0x97b785e8U), BSWAP_32BIG_C(0xff3026ebU), BSWAP_32BIG_C(
                    0x08c724a4U),
            };
            r_rsip_func100(Param_p52i_func100_004);

            r_rsip_func_sub002(0x00000160U, 0x00000200U, 0x000001b0U, 0x0909000aU);

            r_rsip_func_sub022(0x00000980U, 0x000001b0U, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);

            r_rsip_func_sub037(0x0909000fU, 0x00010001U);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000110U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000160U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x10c00000U);
            r_rsip_func_sub001(0x00c00011U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1608H, 0x8190001fU);
            r_rsip_func_sub001(0x00c90041U);

            r_rsip_func_sub022(0x00000110U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000480U, 0x09090002U, 0x00010001U);
            r_rsip_func_sub007(0x00000930U, 0x00000160U, 0x000000c0U);
            r_rsip_func_sub005(0x00000340U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1010H, 0x00000018U);

            WR1_PROG(REG_1404H, 0x11180000U);
            r_rsip_func_sub001(0x00c00049U);

            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_func_sub001(0x00c002d1U);

            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            r_rsip_func_sub005(0x00000a70U, 0x09090004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub002(0x00000890U, 0x00000160U, 0x000002a0U, 0x09090009U);

            r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x000002f0U, 0x09090009U);

            WR1_PROG(REG_1404H, 0x10c00000U);
            WR1_PROG(REG_1608H, 0x81940001U);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x000009d0U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub012(0x10c00000U, 0x000037e1U, 0x0000a7e0U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1608H, 0x8194001fU);
            r_rsip_func_sub001(0x00c90051U);

            r_rsip_func_sub022(0x00000110U, 0x00000390U, 0x00000070U);
            r_rsip_func_sub005(0x00000a20U, 0x09090002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            static const uint32_t Param_p52i_func100_005[] =
            {
                BSWAP_32BIG_C(0xf26d12b0U), BSWAP_32BIG_C(0x890fd41cU), BSWAP_32BIG_C(0x90f155b5U), BSWAP_32BIG_C(
                    0x40a7d1a6U),
            };
            r_rsip_func100(Param_p52i_func100_005);
            r_rsip_func087(InData_DomainParam);

            r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000ac0U, 0x09090009U);

            r_rsip_func_sub002(0x00000200U, 0x00000160U, 0x00000b10U, 0x09090009U);

            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000b60U, 0x09090009U);

            r_rsip_func_sub002(0x00000ac0U, 0x000009d0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x000009d0U, 0x00000ac0U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            r_rsip_func_sub002(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p52i_func100_006[] =
            {
                BSWAP_32BIG_C(0x90b11d19U), BSWAP_32BIG_C(0x65d28bc0U), BSWAP_32BIG_C(0xae735e97U), BSWAP_32BIG_C(
                    0xf8af19c7U),
            };
            r_rsip_func100(Param_p52i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00000b60U, 0x00000a70U, 0x00000070U);
                r_rsip_func_sub005(0x00000c50U, 0x09090013U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p52i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x0285fb79U), BSWAP_32BIG_C(0x354a5edaU), BSWAP_32BIG_C(0xffdde4b0U), BSWAP_32BIG_C(
                        0x30decf2cU),
                };
                r_rsip_func101(Param_p52i_func101_004);
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_101CH, 0x000002f0U);
                r_rsip_func_sub005(0x00000c50U, 0x09090014U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                static const uint32_t Param_p52i_func101_005[] =
                {
                    BSWAP_32BIG_C(0x67099a2cU), BSWAP_32BIG_C(0x2a99e0bbU), BSWAP_32BIG_C(0x3945d716U), BSWAP_32BIG_C(
                        0x96730fd7U),
                };
                r_rsip_func101(Param_p52i_func101_005);
            }

            r_rsip_func_sub044(0x00000821U, 0x14380000U, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            r_rsip_func_sub034(0x0000a420U, 0x00000050U, 0x12f80000U);
            WR1_PROG(REG_1608H, 0x80920001U);
            r_rsip_func_sub001(0x03430049U);

            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_func_sub001(0x00c000f1U);

            WR1_PROG(REG_1600H, 0x00000821U);

            for (iLoop = 0U; iLoop < 18U; iLoop++)
            {
                r_rsip_func_sub024(0x000034a1U, 0x00026ca5U, 0x00003865U, 0x0000a4a0U);
                r_rsip_func_sub025(0x00000050U, 0x00003885U, 0x00000842U);

                for (jLoop = 0U; jLoop < 32U; jLoop++)
                {
                    r_rsip_func_sub024(0x000008a5U, 0x01816ca3U, 0x01816ca4U, 0x00016c63U);
                    WR1_PROG(REG_1600H, 0x00016c84U);

                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c00045U);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                    WR1_PROG(REG_143CH, 0x00a10000U);

                    static const uint32_t Param_p52i_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x4070a5ecU), BSWAP_32BIG_C(0xdd122245U), BSWAP_32BIG_C(0xfeaccb35U),
                        BSWAP_32BIG_C(0x4158107cU),
                    };
                    r_rsip_func100(Param_p52i_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        WR1_PROG(REG_101CH, 0x000002f0U);
                        r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                        WAIT_STS(REG_1000H, 0, 0);
                        WR1_PROG(REG_143CH, 0x00000d00U);

                        static const uint32_t Param_p52i_func101_006[] =
                        {
                            BSWAP_32BIG_C(0x6917eb4cU), BSWAP_32BIG_C(0xd573edf6U), BSWAP_32BIG_C(0x75ef757dU),
                            BSWAP_32BIG_C(0x44550d26U),
                        };
                        r_rsip_func101(Param_p52i_func101_006);
                    }
                    else
                    {
                        static const uint32_t Param_p52i_func101_007[] =
                        {
                            BSWAP_32BIG_C(0x3efacb03U), BSWAP_32BIG_C(0x1f428bb3U), BSWAP_32BIG_C(0x976e22d4U),
                            BSWAP_32BIG_C(0x6ba8fa12U),
                        };
                        r_rsip_func101(Param_p52i_func101_007);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub017(0x38000ca5U, 0x00A60000U);

                    static const uint32_t Param_p52i_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x6f33f103U), BSWAP_32BIG_C(0x3c2c321fU), BSWAP_32BIG_C(0x67169cdcU),
                        BSWAP_32BIG_C(0xed19607fU),
                    };
                    r_rsip_func100(Param_p52i_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_p52i_func100_009[] =
                        {
                            BSWAP_32BIG_C(0x38bada99U), BSWAP_32BIG_C(0xd983abb7U), BSWAP_32BIG_C(0x31b5111fU),
                            BSWAP_32BIG_C(0x01d5fdffU),
                        };
                        r_rsip_func100(Param_p52i_func100_009);

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub001(0x00c00049U);

                        r_rsip_func_sub014(0x00007c05U, 0x00600000U);

                        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
                        {
                            r_rsip_func_sub002(0x000009d0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a20U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000a70U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_008[] =
                            {
                                BSWAP_32BIG_C(0x53135a18U), BSWAP_32BIG_C(0x477a48f6U), BSWAP_32BIG_C(0x0700cfeeU),
                                BSWAP_32BIG_C(0x6b20099eU),
                            };
                            r_rsip_func101(Param_p52i_func101_008);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
                        {
                            r_rsip_func_sub002(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b10U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000b60U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_009[] =
                            {
                                BSWAP_32BIG_C(0x29d6e969U), BSWAP_32BIG_C(0xa615a87cU), BSWAP_32BIG_C(0x879aadbeU),
                                BSWAP_32BIG_C(0x58244593U),
                            };
                            r_rsip_func101(Param_p52i_func101_009);
                        }
                        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
                        {
                            r_rsip_func_sub002(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c00U, 0x00000160U, 0x00000430U, 0x09090009U);

                            r_rsip_func_sub002(0x00000c50U, 0x00000160U, 0x00000480U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_010[] =
                            {
                                BSWAP_32BIG_C(0x2c987b91U), BSWAP_32BIG_C(0xb435fac6U), BSWAP_32BIG_C(0x2a36dcbeU),
                                BSWAP_32BIG_C(0xccc77745U),
                            };
                            r_rsip_func101(Param_p52i_func101_010);
                        }

                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_func_sub004(0x08000104U, 0x00000001U);
                        r_rsip_func_sub001(0x00c00045U);
                        r_rsip_func_sub001(0x00c20005U);
                        r_rsip_func_sub001(0x0002000dU);

                        r_rsip_func_sub002(0x000001b0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        r_rsip_func_sub002(0x00000250U, 0x00000160U, 0x00000110U, 0x0909000aU);

                        WR1_PROG(REG_143CH, 0x00a10000U);

                        static const uint32_t Param_p52i_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x85def7abU), BSWAP_32BIG_C(0x3df249c1U), BSWAP_32BIG_C(0x0d379028U),
                            BSWAP_32BIG_C(0xe731bc9dU),
                        };
                        r_rsip_func100(Param_p52i_func100_010);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);

                            WR1_PROG(REG_143CH, 0x00a10000U);

                            static const uint32_t Param_p52i_func100_011[] =
                            {
                                BSWAP_32BIG_C(0x0205d824U), BSWAP_32BIG_C(0x1b807af9U), BSWAP_32BIG_C(0xa64a8f6aU),
                                BSWAP_32BIG_C(0xbc2aae1dU),
                            };
                            r_rsip_func100(Param_p52i_func100_011);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub002(0x000001b0U, 0x000003e0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x000003e0U, 0x000001b0U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000200U, 0x00000430U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000430U, 0x00000200U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000250U, 0x00000480U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                r_rsip_func_sub002(0x00000480U, 0x00000250U, 0x00000110U, 0x0909000aU);

                                WR1_PROG(REG_143CH, 0x00210000U);

                                static const uint32_t Param_p52i_func100_012[] =
                                {
                                    BSWAP_32BIG_C(0x43e4ac35U), BSWAP_32BIG_C(0x051b1a08U), BSWAP_32BIG_C(0x3e8adc2cU),
                                    BSWAP_32BIG_C(0xffd4833eU),
                                };
                                r_rsip_func100(Param_p52i_func100_012);
                                WR1_PROG(REG_143CH, 0x00400000U);

                                if (CHCK_STS(REG_143CH, 22, 1))
                                {
                                    r_rsip_func_sub022(0x00000250U, 0x00000480U, 0x00000070U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090013U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p52i_func101_011[] =
                                    {
                                        BSWAP_32BIG_C(0x03ccfeacU), BSWAP_32BIG_C(0xe7b3d540U), BSWAP_32BIG_C(
                                            0x7a4530aaU),           BSWAP_32BIG_C(0x8e0b06f7U),
                                    };
                                    r_rsip_func101(Param_p52i_func101_011);
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_101CH, 0x000002f0U);
                                    r_rsip_func_sub005(0x00000250U, 0x09090014U, 0x00010001U);
                                    WAIT_STS(REG_1000H, 0, 0);
                                    WR1_PROG(REG_143CH, 0x00000d00U);

                                    static const uint32_t Param_p52i_func101_012[] =
                                    {
                                        BSWAP_32BIG_C(0x43805500U), BSWAP_32BIG_C(0x0b91a7abU), BSWAP_32BIG_C(
                                            0xe823e2edU),           BSWAP_32BIG_C(0x6e4268ffU),
                                    };
                                    r_rsip_func101(Param_p52i_func101_012);
                                }
                            }
                            else
                            {
                                static const uint32_t Param_p52i_func101_013[] =
                                {
                                    BSWAP_32BIG_C(0xdca35d74U), BSWAP_32BIG_C(0x4f9525beU), BSWAP_32BIG_C(0xbbfce4cfU),
                                    BSWAP_32BIG_C(0x636d76efU),
                                };
                                r_rsip_func101(Param_p52i_func101_013);
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11180000U);
                            r_rsip_func_sub001(0x00c00049U);

                            r_rsip_func_sub002(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);

                            r_rsip_func_sub002(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);

                            r_rsip_func_sub002(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);

                            static const uint32_t Param_p52i_func101_014[] =
                            {
                                BSWAP_32BIG_C(0xffc56736U), BSWAP_32BIG_C(0x8f2b3023U), BSWAP_32BIG_C(0x5e20acedU),
                                BSWAP_32BIG_C(0x63480805U),
                            };
                            r_rsip_func101(Param_p52i_func101_014);
                        }
                    }
                    else
                    {
                        static const uint32_t Param_p52i_func101_015[] =
                        {
                            BSWAP_32BIG_C(0x6c158e45U), BSWAP_32BIG_C(0xeb388015U), BSWAP_32BIG_C(0x67cd94ecU),
                            BSWAP_32BIG_C(0x37239cfbU),
                        };
                        r_rsip_func101(Param_p52i_func101_015);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    static const uint32_t Param_p52i_func101_016[] =
                    {
                        BSWAP_32BIG_C(0x19b24f84U), BSWAP_32BIG_C(0xa8049242U), BSWAP_32BIG_C(0x0bb04848U),
                        BSWAP_32BIG_C(0xb146b9a1U),
                    };
                    r_rsip_func101(Param_p52i_func101_016);
                }

                r_rsip_func_sub006(0x38008840U, 0x00000020U, 0x00260000U);

                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002c20U);

                static const uint32_t Param_p52i_func101_017[] =
                {
                    BSWAP_32BIG_C(0x1359c46bU), BSWAP_32BIG_C(0xc4d3cb87U), BSWAP_32BIG_C(0x5849afd5U), BSWAP_32BIG_C(
                        0x6757139aU),
                };
                r_rsip_func101(Param_p52i_func101_017);
            }

            r_rsip_func_sub006(0x38008820U, 0x00000012U, 0x00260000U);

            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x12580000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c00045U);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0909000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_p52i_func100_013[] =
            {
                BSWAP_32BIG_C(0xab19cb2cU), BSWAP_32BIG_C(0xb8b9136dU), BSWAP_32BIG_C(0x7ab537f4U), BSWAP_32BIG_C(
                    0x989708dcU),
            };
            r_rsip_func100(Param_p52i_func100_013);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00000800U);

                static const uint32_t Param_p52i_func101_018[] =
                {
                    BSWAP_32BIG_C(0x0be21a3dU), BSWAP_32BIG_C(0x49787983U), BSWAP_32BIG_C(0xfc759863U), BSWAP_32BIG_C(
                        0xe10cff0cU),
                };
                r_rsip_func101(Param_p52i_func101_018);
            }
            else
            {
                static const uint32_t Param_p52i_func100_014[] =
                {
                    BSWAP_32BIG_C(0xb9df1864U), BSWAP_32BIG_C(0x63892907U), BSWAP_32BIG_C(0x393daf28U), BSWAP_32BIG_C(
                        0xc0c2e403U),
                };
                r_rsip_func100(Param_p52i_func100_014);

                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090004U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c00045U);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);

                r_rsip_func_sub013(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                r_rsip_func_sub022(0x000001b0U, 0x00000160U, 0x00000070U);
                r_rsip_func_sub005(0x000002a0U, 0x09090002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                r_rsip_func_sub002(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                r_rsip_func_sub002(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0909000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p52i_func100_015[] =
                {
                    BSWAP_32BIG_C(0x2aad7b9aU), BSWAP_32BIG_C(0x7805b595U), BSWAP_32BIG_C(0xcc9ee34aU), BSWAP_32BIG_C(
                        0xcdd3fadeU),
                };
                r_rsip_func100(Param_p52i_func100_015);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    static const uint32_t Param_p52i_func101_019[] =
                    {
                        BSWAP_32BIG_C(0x1383a66dU), BSWAP_32BIG_C(0x58ee3130U), BSWAP_32BIG_C(0x9642ad83U),
                        BSWAP_32BIG_C(0x0bf0d658U),
                    };
                    r_rsip_func101(Param_p52i_func101_019);
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1600H, 0x797935bbU);

                    static const uint32_t Param_p52i_func101_020[] =
                    {
                        BSWAP_32BIG_C(0x6d6e38e9U), BSWAP_32BIG_C(0x9cf5cc55U), BSWAP_32BIG_C(0x05a3fb49U),
                        BSWAP_32BIG_C(0xe9df2eb8U),
                    };
                    r_rsip_func101(Param_p52i_func101_020);
                }
            }
        }

        r_rsip_func_sub006(0x38008800U, 0x797935bbU, 0x00A60000U);

        r_rsip_func_sub014(0x00007c1bU, 0x00602000U);

        static const uint32_t Param_p52i_func100_016[] =
        {
            BSWAP_32BIG_C(0x7f3cc6fdU), BSWAP_32BIG_C(0xcbc5ff8aU), BSWAP_32BIG_C(0x4e40b518U), BSWAP_32BIG_C(
                0x7ee4bd1aU),
        };
        r_rsip_func100(Param_p52i_func100_016);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p52i_func102_002[] =
            {
                BSWAP_32BIG_C(0x44b00eacU), BSWAP_32BIG_C(0x8ca4259bU), BSWAP_32BIG_C(0x023f9e55U), BSWAP_32BIG_C(
                    0xb10c9afaU),
            };
            r_rsip_func102(Param_p52i_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub025(0x0000b7c0U, 0x00000100U, 0x00000bffU);

            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            for (iLoop = 0U; iLoop < 16U; )
            {
                WR1_PROG(REG_1608H, 0x8184001eU);
                r_rsip_func_sub001(0x00890011U);
                WR1_PROG(REG_1608H, 0x8084001fU);
                r_rsip_func_sub001(0x03420011U);

                r_rsip_func_sub024(0x0000a7c0U, 0x00000010U, 0x0000a7e0U, 0x00000010U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_p52i_func101_021[] =
            {
                BSWAP_32BIG_C(0xc7e2b884U), BSWAP_32BIG_C(0xbcc4794aU), BSWAP_32BIG_C(0x4936fa9fU), BSWAP_32BIG_C(
                    0x9a9fd61cU),
            };
            r_rsip_func101(Param_p52i_func101_021);

            return RSIP_RET_PASS;
        }
    }
}
