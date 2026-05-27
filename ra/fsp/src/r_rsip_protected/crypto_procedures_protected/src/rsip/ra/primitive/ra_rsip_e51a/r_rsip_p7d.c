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

rsip_ret_t r_rsip_p7d (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x007d0001U, 0x000007f0U);

    static const uint32_t Param_p7d_func100_001[] =
    {
        BSWAP_32BIG_C(0x226b7ec9U), BSWAP_32BIG_C(0xc49622b5U), BSWAP_32BIG_C(0x165d3ba3U), BSWAP_32BIG_C(0x9e56d2d9U),
    };
    r_rsip_func100(Param_p7d_func100_001);
    r_rsip_func078(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11200000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);

    r_rsip_func_sub018(0x00000020U, 0x000003f0U, 0x08080010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x08080010U);

    WR1_PROG(REG_1404H, 0x10d00000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007d01U);

    static const uint32_t Param_p7d_func101_001[] =
    {
        BSWAP_32BIG_C(0xe3d2d535U), BSWAP_32BIG_C(0x11118722U), BSWAP_32BIG_C(0xb24c0c16U), BSWAP_32BIG_C(0xd9546668U),
    };
    r_rsip_func101(Param_p7d_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007d02U);

    static const uint32_t Param_p7d_func101_002[] =
    {
        BSWAP_32BIG_C(0x8468b6fbU), BSWAP_32BIG_C(0x018c392fU), BSWAP_32BIG_C(0xe75778c1U), BSWAP_32BIG_C(0x21690b73U),
    };
    r_rsip_func101(Param_p7d_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007d03U);

    static const uint32_t Param_p7d_func101_003[] =
    {
        BSWAP_32BIG_C(0xc200a7abU), BSWAP_32BIG_C(0x931934fcU), BSWAP_32BIG_C(0x0853b8bcU), BSWAP_32BIG_C(0xbe6224baU),
    };
    r_rsip_func101(Param_p7d_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007d04U);

    static const uint32_t Param_p7d_func101_004[] =
    {
        BSWAP_32BIG_C(0x96f9dedbU), BSWAP_32BIG_C(0xb2c47447U), BSWAP_32BIG_C(0x63c3bfdeU), BSWAP_32BIG_C(0xaca23388U),
    };
    r_rsip_func101(Param_p7d_func101_004);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub021(0x000003f0U, 0x00000160U, 0x00000020U, 0x08080004U);

    WR1_PROG(REG_1404H, 0x13f80000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0003dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000438U, 0x00000340U, 0x08080009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x08080010U);

    static const uint32_t Param_p7d_func100_002[] =
    {
        BSWAP_32BIG_C(0x3645d6a4U), BSWAP_32BIG_C(0xb7ad9bc2U), BSWAP_32BIG_C(0xd5f982d7U), BSWAP_32BIG_C(0x3162cdacU),
    };
    r_rsip_func100(Param_p7d_func100_002);
    r_rsip_func079(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007dU);

    static const uint32_t Param_p7d_func101_005[] =
    {
        BSWAP_32BIG_C(0xbd7f9e39U), BSWAP_32BIG_C(0x8f084548U), BSWAP_32BIG_C(0x53e5d5f2U), BSWAP_32BIG_C(0x6e94da99U),
    };
    r_rsip_func101(Param_p7d_func101_005);
    r_rsip_func090();

    static const uint32_t Param_p7d_func100_003[] =
    {
        BSWAP_32BIG_C(0x59efd58bU), BSWAP_32BIG_C(0x973f6461U), BSWAP_32BIG_C(0x90a0639eU), BSWAP_32BIG_C(0x4953eff5U),
    };
    r_rsip_func100(Param_p7d_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p7d_func102_001[] =
        {
            BSWAP_32BIG_C(0x6bb54e2aU), BSWAP_32BIG_C(0x8c52fe07U), BSWAP_32BIG_C(0x8591f226U), BSWAP_32BIG_C(
                0x331baa83U),
        };
        r_rsip_func102(Param_p7d_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        r_rsip_func_sub021(0x000000c0U, 0x000002f0U, 0x00000020U, 0x08080002U);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x08080004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10d00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0003dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0808000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_p7d_func100_004[] =
        {
            BSWAP_32BIG_C(0x20899469U), BSWAP_32BIG_C(0xa18871b2U), BSWAP_32BIG_C(0x8fa9bac4U), BSWAP_32BIG_C(
                0x8bbf9040U),
        };
        r_rsip_func100(Param_p7d_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p7d_func102_002[] =
            {
                BSWAP_32BIG_C(0x8793dc46U), BSWAP_32BIG_C(0x7b64c9f9U), BSWAP_32BIG_C(0x2171944dU), BSWAP_32BIG_C(
                    0xcca22c83U),
            };
            r_rsip_func102(Param_p7d_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p7d_func100_005[] =
            {
                BSWAP_32BIG_C(0xf20b1d30U), BSWAP_32BIG_C(0xaf1b7d1aU), BSWAP_32BIG_C(0xdc5fa6deU), BSWAP_32BIG_C(
                    0xca2c4a42U),
            };
            r_rsip_func100(Param_p7d_func100_005);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0003dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0808000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0808000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x08080002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub023(0x00000fc2U, 0x00000300U, 0x08008107U);

            WR1_PROG(REG_1404H, 0x11200000U);
            for (iLoop = 0U; iLoop < 16U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_MsgDgst[iLoop]);
                r_rsip_func_sub001(0x00c20011U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
            WR1_PROG(REG_1420H, InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007dU);

            static const uint32_t Param_p7d_func101_006[] =
            {
                BSWAP_32BIG_C(0x9a4665bdU), BSWAP_32BIG_C(0xd6f4f875U), BSWAP_32BIG_C(0x9bed833fU), BSWAP_32BIG_C(
                    0xeb2c17d4U),
            };
            r_rsip_func101(Param_p7d_func101_006);
            r_rsip_func043();

            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1600H, 0x00000021U);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000007dU);

            static const uint32_t Param_p7d_func101_007[] =
            {
                BSWAP_32BIG_C(0x5eda6f34U), BSWAP_32BIG_C(0xdc9d6819U), BSWAP_32BIG_C(0x57e49badU), BSWAP_32BIG_C(
                    0x87faa64dU),
            };
            r_rsip_func101(Param_p7d_func101_007);
            r_rsip_func044();

            r_rsip_func_sub023(0x00000fc2U, 0x40000300U, 0xf7009d07U);

            WR1_PROG(REG_1404H, 0x11c00000U);

            for (iLoop = 0U; iLoop < 16U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
                r_rsip_func_sub001(0x00c20011U);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_p7d_func100_006[] =
            {
                BSWAP_32BIG_C(0x28fca00eU), BSWAP_32BIG_C(0x1f226297U), BSWAP_32BIG_C(0xd639908aU), BSWAP_32BIG_C(
                    0x8d0a3ee6U),
            };
            r_rsip_func100(Param_p7d_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_p7d_func102_003[] =
                {
                    BSWAP_32BIG_C(0xab6da78eU), BSWAP_32BIG_C(0x51d793eaU), BSWAP_32BIG_C(0xcc2d9c0eU), BSWAP_32BIG_C(
                        0x6dd6493bU),
                };
                r_rsip_func102(Param_p7d_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub022(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x08080005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x08080002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10d00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0003dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0808000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_p7d_func100_007[] =
                {
                    BSWAP_32BIG_C(0x88d5e3a6U), BSWAP_32BIG_C(0x2efe7c9bU), BSWAP_32BIG_C(0xc65cccacU), BSWAP_32BIG_C(
                        0x9ac2435bU),
                };
                r_rsip_func100(Param_p7d_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p7d_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x8f9f5fb2U), BSWAP_32BIG_C(0xe1f3dadeU), BSWAP_32BIG_C(0x7b2b6e9eU),
                        BSWAP_32BIG_C(0x07aed491U),
                    };
                    r_rsip_func102(Param_p7d_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p7d_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x6a794c71U), BSWAP_32BIG_C(0x38f53e3eU), BSWAP_32BIG_C(0x2481daf2U),
                        BSWAP_32BIG_C(0xdb759557U),
                    };
                    r_rsip_func100(Param_p7d_func100_008);
                    WR1_PROG(REG_1404H, 0x12600000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[0]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[4]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[8]);

                    static const uint32_t Param_p7d_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x787e5833U), BSWAP_32BIG_C(0x63e79074U), BSWAP_32BIG_C(0x894b8dacU),
                        BSWAP_32BIG_C(0x1461fe21U),
                    };
                    r_rsip_func100(Param_p7d_func100_009);
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);

                    static const uint32_t Param_p7d_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x51bc7897U), BSWAP_32BIG_C(0x8db48b4dU), BSWAP_32BIG_C(0x7069a5a5U),
                        BSWAP_32BIG_C(0xb9892961U),
                    };
                    r_rsip_func100(Param_p7d_func100_010);
                    WR1_PROG(REG_1404H, 0x11c00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[24]);

                    static const uint32_t Param_p7d_func100_011[] =
                    {
                        BSWAP_32BIG_C(0xd22d841bU), BSWAP_32BIG_C(0x4e939954U), BSWAP_32BIG_C(0x6c2b270eU),
                        BSWAP_32BIG_C(0xf4d33c72U),
                    };
                    r_rsip_func100(Param_p7d_func100_011);
                    WR1_PROG(REG_1A24H, 0x08000105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[28]);

                    static const uint32_t Param_p7d_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x30aec445U), BSWAP_32BIG_C(0x7dd64da5U), BSWAP_32BIG_C(0xfd7aa994U),
                        BSWAP_32BIG_C(0x25d892caU),
                    };
                    r_rsip_func102(Param_p7d_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
