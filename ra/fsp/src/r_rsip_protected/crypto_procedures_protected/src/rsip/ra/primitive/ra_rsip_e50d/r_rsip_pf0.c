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

rsip_ret_t r_rsip_pf0 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub029(0x00f00001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010380U);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    WR1_PROG(REG_1600H, 0x00000bdeU);

    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    for (iLoop = 0U; iLoop < 8U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x00000bffU, 0x30003380U, 0x00070020U, 0x0000d3e0U);
    r_rsip_func_sub021(0x00030040U, 0x0000381eU, 0x38000c00U, 0x1000d3e0U);
    r_rsip_func_sub021(0x00050040U, 0x0000381eU, 0x000037beU, 0x0000a7a0U);
    r_rsip_func_sub021(0x00000004U, 0x0000383dU, 0x38001001U, 0x1000d3e0U);
    r_rsip_func_sub021(0x00000080U, 0x30000f5aU, 0x00030020U, 0x0000d3e1U);
    r_rsip_func_sub021(0x00000060U, 0x38000f9cU, 0x1000d3e1U, 0x00000080U);

    r_rsip_func_sub006(0x38008be0U, 0x00000003U, 0x00A60000U);

    static const uint32_t Param_pf0_func100_001[] =
    {
        BSWAP_32BIG_C(0xad943cc7U), BSWAP_32BIG_C(0xe6faf11eU), BSWAP_32BIG_C(0x75731945U), BSWAP_32BIG_C(0xaec8b31eU),
    };
    r_rsip_func100(Param_pf0_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf0_func102_001[] =
        {
            BSWAP_32BIG_C(0x3440fab9U), BSWAP_32BIG_C(0xb217c936U), BSWAP_32BIG_C(0x795ccbfbU), BSWAP_32BIG_C(
                0x44b6f3e0U),
        };
        r_rsip_func102(Param_pf0_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf0_func100_002[] =
        {
            BSWAP_32BIG_C(0x5fcd8054U), BSWAP_32BIG_C(0x2eaeb900U), BSWAP_32BIG_C(0x91b1ee4aU), BSWAP_32BIG_C(
                0xd74e38a1U),
        };
        r_rsip_func100(Param_pf0_func100_002);
        r_rsip_func070(InData_DomainParam);

        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_func_sub004(0x08000104U, 0x00000002U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000430U, 0x0404000aU);

        r_rsip_func_sub018(0x00000020U, 0x00000430U, 0x04040010U);

        r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x04040010U);

        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func_sub003(0x800103a0U, 0x0000f001U);

        static const uint32_t Param_pf0_func101_001[] =
        {
            BSWAP_32BIG_C(0x84f434acU), BSWAP_32BIG_C(0x938080e5U), BSWAP_32BIG_C(0xe62dbce0U), BSWAP_32BIG_C(
                0xa9ebae07U),
        };
        r_rsip_func101(Param_pf0_func101_001);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        r_rsip_func_sub003(0x800103a0U, 0x0000f002U);

        static const uint32_t Param_pf0_func101_002[] =
        {
            BSWAP_32BIG_C(0xe8640a31U), BSWAP_32BIG_C(0x16a3646cU), BSWAP_32BIG_C(0x8906c9d5U), BSWAP_32BIG_C(
                0x75db279fU),
        };
        r_rsip_func101(Param_pf0_func101_002);
        r_rsip_func113();
        r_rsip_func_sub004(0x0c200104U, 0x00000000U);
        r_rsip_func_sub001(0x00c20011U);

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_101CH, 0x00000430U);
        WR1_PROG(REG_1020H, 0x00000160U);
        WR1_PROG(REG_1010H, 0x00000020U);

        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x14380000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0001dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x00000160U, 0x00000458U, 0x00000340U, 0x04040009U);

        r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x04040010U);

        static const uint32_t Param_pf0_func100_003[] =
        {
            BSWAP_32BIG_C(0xc717cd39U), BSWAP_32BIG_C(0x370fb1e7U), BSWAP_32BIG_C(0x21e731f0U), BSWAP_32BIG_C(
                0x0e1ce929U),
        };
        r_rsip_func100(Param_pf0_func100_003);
        r_rsip_func071(InData_DomainParam);

        r_rsip_func_sub003(0x800103a0U, 0x000000f0U);

        static const uint32_t Param_pf0_func101_003[] =
        {
            BSWAP_32BIG_C(0x9582e4d9U), BSWAP_32BIG_C(0xfca7c231U), BSWAP_32BIG_C(0xac8ed480U), BSWAP_32BIG_C(
                0xaecf2821U),
        };
        r_rsip_func101(Param_pf0_func101_003);
        r_rsip_func088();

        static const uint32_t Param_pf0_func100_004[] =
        {
            BSWAP_32BIG_C(0x42e18846U), BSWAP_32BIG_C(0x1dcfc5b9U), BSWAP_32BIG_C(0x410a9ab0U), BSWAP_32BIG_C(
                0x91e72c5aU),
        };
        r_rsip_func100(Param_pf0_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf0_func102_002[] =
            {
                BSWAP_32BIG_C(0x8884fc72U), BSWAP_32BIG_C(0x82cd92b1U), BSWAP_32BIG_C(0x0fd25f5fU), BSWAP_32BIG_C(
                    0xb215300aU),
            };
            r_rsip_func102(Param_pf0_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1014H, 0x000002a0U);
            WR1_PROG(REG_1018H, 0x00000840U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000020U);

            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            r_rsip_func_sub005(0x000002a0U, 0x04040004U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            WR1_PROG(REG_1404H, 0x10f00000U);
            r_rsip_func_sub004(0x08000104U, 0x00000001U);
            r_rsip_func_sub001(0x00c0001dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0404000aU);

            WR1_PROG(REG_143CH, 0x00210000U);

            static const uint32_t Param_pf0_func100_005[] =
            {
                BSWAP_32BIG_C(0xd5125762U), BSWAP_32BIG_C(0x18717b28U), BSWAP_32BIG_C(0x5f8d167bU), BSWAP_32BIG_C(
                    0x44add58bU),
            };
            r_rsip_func100(Param_pf0_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pf0_func102_003[] =
                {
                    BSWAP_32BIG_C(0xda04515fU), BSWAP_32BIG_C(0x1946f207U), BSWAP_32BIG_C(0x05d99e7aU), BSWAP_32BIG_C(
                        0xf2f48948U),
                };
                r_rsip_func102(Param_pf0_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pf0_func100_006[] =
                {
                    BSWAP_32BIG_C(0x336ee2bfU), BSWAP_32BIG_C(0x6be97e52U), BSWAP_32BIG_C(0x05013765U), BSWAP_32BIG_C(
                        0x4fbb3ac7U),
                };
                r_rsip_func100(Param_pf0_func100_006);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub004(0x08000104U, 0x00000002U);
                r_rsip_func_sub001(0x00c0001dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0404000aU);

                r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0404000fU, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);
                WR1_PROG(REG_143CH, 0x00000d00U);

                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000840U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                r_rsip_func_sub005(0x00000110U, 0x04040002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1608H, 0x8188001eU);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_func_sub001(0x00c90021U);

                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_KeyIndex[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x800103a0U, 0x000000f0U);

                static const uint32_t Param_pf0_func101_004[] =
                {
                    BSWAP_32BIG_C(0x8cefeb2fU), BSWAP_32BIG_C(0x6bf813b3U), BSWAP_32BIG_C(0xe62da24fU), BSWAP_32BIG_C(
                        0x82f7a1bcU),
                };
                r_rsip_func101(Param_pf0_func101_004);
                r_rsip_func043();

                r_rsip_func074();

                WR1_PROG(REG_1600H, 0x000034feU);

                r_rsip_func_sub003(0x800103a0U, 0x000000f0U);

                static const uint32_t Param_pf0_func101_005[] =
                {
                    BSWAP_32BIG_C(0xa803a5ffU), BSWAP_32BIG_C(0x6704c1d5U), BSWAP_32BIG_C(0xe152d377U), BSWAP_32BIG_C(
                        0x3fda26a9U),
                };
                r_rsip_func101(Param_pf0_func101_005);
                r_rsip_func044();

                r_rsip_func_sub024(0x000007c2U, 0x40000100U, 0xf7009d07U);

                for (iLoop = 0U; iLoop < 8U; )
                {
                    WAIT_STS(REG_1444H, 31, 1);
                    WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1404H, 0x11e00000U);
                r_rsip_func_sub001(0x00c20021U);

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_pf0_func100_007[] =
                {
                    BSWAP_32BIG_C(0x284c7d1cU), BSWAP_32BIG_C(0x31266d0bU), BSWAP_32BIG_C(0xb846f628U), BSWAP_32BIG_C(
                        0x7d9fa82aU),
                };
                r_rsip_func100(Param_pf0_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pf0_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x12eaaabbU), BSWAP_32BIG_C(0x36e0f4e4U), BSWAP_32BIG_C(0x35e2998cU),
                        BSWAP_32BIG_C(0x5496f823U),
                    };
                    r_rsip_func102(Param_pf0_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_KEY_FAIL;
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x00000200U);
                    WR1_PROG(REG_1018H, 0x00000840U);
                    WR1_PROG(REG_101CH, 0x000000c0U);
                    r_rsip_func_sub005(0x000001b0U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                    r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                    r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                    r_rsip_func_sub005(0x000001b0U, 0x04040005U, 0x00010001U);
                    r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                    r_rsip_func_sub005(0x00000200U, 0x04040002U, 0x00010001U);
                    WAIT_STS(REG_1000H, 0, 0);

                    WR1_PROG(REG_1404H, 0x10f00000U);
                    r_rsip_func_sub004(0x08000104U, 0x00000001U);
                    r_rsip_func_sub001(0x00c0001dU);
                    r_rsip_func_sub001(0x00c20005U);
                    r_rsip_func_sub001(0x0002000dU);

                    r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0404000aU);

                    WR1_PROG(REG_143CH, 0x00210000U);

                    static const uint32_t Param_pf0_func100_008[] =
                    {
                        BSWAP_32BIG_C(0xb188891eU), BSWAP_32BIG_C(0xe2bbf010U), BSWAP_32BIG_C(0x357aca8cU),
                        BSWAP_32BIG_C(0x4845a5ceU),
                    };
                    r_rsip_func100(Param_pf0_func100_008);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pf0_func102_005[] =
                        {
                            BSWAP_32BIG_C(0xe8fa1c64U), BSWAP_32BIG_C(0xb61ec85bU), BSWAP_32BIG_C(0x853af6f9U),
                            BSWAP_32BIG_C(0x9af14fa2U),
                        };
                        r_rsip_func102(Param_pf0_func102_005);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_FAIL;
                    }
                    else
                    {
                        static const uint32_t Param_pf0_func100_009[] =
                        {
                            BSWAP_32BIG_C(0xb1f27de4U), BSWAP_32BIG_C(0x6a2e2908U), BSWAP_32BIG_C(0xe615c1b9U),
                            BSWAP_32BIG_C(0xadf8770cU),
                        };
                        r_rsip_func100(Param_pf0_func100_009);
                        WR1_PROG(REG_1404H, 0x12800000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_func_sub001(0x00830021U);

                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[4]);

                        static const uint32_t Param_pf0_func100_010[] =
                        {
                            BSWAP_32BIG_C(0x4ed203a4U), BSWAP_32BIG_C(0xce65a2c9U), BSWAP_32BIG_C(0xad4a4f8fU),
                            BSWAP_32BIG_C(0x20cbd77cU),
                        };
                        r_rsip_func100(Param_pf0_func100_010);
                        WR1_PROG(REG_1404H, 0x11e00000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_func_sub001(0x00830021U);

                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[8]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_Signature[12]);

                        static const uint32_t Param_pf0_func102_006[] =
                        {
                            BSWAP_32BIG_C(0xf23a5a50U), BSWAP_32BIG_C(0xfedaaef1U), BSWAP_32BIG_C(0x4c4b0d63U),
                            BSWAP_32BIG_C(0x66910e7eU),
                        };
                        r_rsip_func102(Param_pf0_func102_006);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
