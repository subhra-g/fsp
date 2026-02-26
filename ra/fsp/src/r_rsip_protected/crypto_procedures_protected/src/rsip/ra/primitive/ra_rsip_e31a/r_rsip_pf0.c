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
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00f00001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3420a800U, 0x00000003U);
    WR1_PROG(REG_0094H, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000002U);

    r_rsip_func070(InData_DomainParam);

    static const uint32_t Param_pf0_func100_001[] =
    {
        BSWAP_32BIG_C(0x34c3e345U), BSWAP_32BIG_C(0xd4967a3eU), BSWAP_32BIG_C(0x9640d322U), BSWAP_32BIG_C(0x03bb67adU),
    };
    r_rsip_func100(Param_pf0_func100_001);

    WR1_PROG(REG_00B0H, 0x0000140fU);
    r_rsip_func103();
    static const uint32_t Param_pf0_func100_002[] =
    {
        BSWAP_32BIG_C(0x9c3e1fbdU), BSWAP_32BIG_C(0xed3fc243U), BSWAP_32BIG_C(0x30aa6952U), BSWAP_32BIG_C(0x89d69956U),
    };
    r_rsip_func100(Param_pf0_func100_002);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x00001428U, 0x00c0001dU, 0x00000001U);

    r_rsip_func_sub003(0x00001419U, 0x00c0001dU, 0x00000002U);

    r_rsip_func_sub001(0x0019000aU, 0x00140000U, 0x0404000aU);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B8H, 0x00000014U);

    WR1_PROG(REG_00A4H, 0x04040010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub001(0x0028000fU, 0x002d0014U, 0x04040002U);

    r_rsip_func_sub001(0x0028002dU, 0x00320000U, 0x04040009U);

    r_rsip_func071(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f0U, 0x00000000U);

    static const uint32_t Param_pf0_func101_001[] =
    {
        BSWAP_32BIG_C(0x258f6197U), BSWAP_32BIG_C(0xfd1ab13bU), BSWAP_32BIG_C(0x45e121b7U), BSWAP_32BIG_C(0x1da6fa29U),
    };
    r_rsip_func101(Param_pf0_func101_001);
    r_rsip_func088();

    static const uint32_t Param_pf0_func100_003[] =
    {
        BSWAP_32BIG_C(0xc5c60ce9U), BSWAP_32BIG_C(0x7369d5d6U), BSWAP_32BIG_C(0x3bd7a56eU), BSWAP_32BIG_C(0x11781508U),
    };
    r_rsip_func100(Param_pf0_func100_003);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf0_func102_001[] =
        {
            BSWAP_32BIG_C(0x12087763U), BSWAP_32BIG_C(0xd9aa88b7U), BSWAP_32BIG_C(0xfe29156bU), BSWAP_32BIG_C(
                0xc687bf72U),
        };
        r_rsip_func102(Param_pf0_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00B8H, 0x0000000aU);

        WR1_PROG(REG_00A4H, 0x04040010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x005a0028U, 0x002d000aU, 0x04040002U);

        WR1_PROG(REG_0014H, 0x000000a5U);
        r_rsip_func_sub009(0x0000140fU, 0x00c0001dU, 0x00001800U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x000f002dU, 0x0028000aU, 0x04040002U);

        r_rsip_func_sub001(0x000f0028U, 0x00140000U, 0x0404000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_pf0_func100_004[] =
        {
            BSWAP_32BIG_C(0x96939109U), BSWAP_32BIG_C(0xb9ec7100U), BSWAP_32BIG_C(0x1a257696U), BSWAP_32BIG_C(
                0x1d6d486dU),
        };
        r_rsip_func100(Param_pf0_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pf0_func102_002[] =
            {
                BSWAP_32BIG_C(0x52bc1482U), BSWAP_32BIG_C(0x00d6d89bU), BSWAP_32BIG_C(0xe8cbc722U), BSWAP_32BIG_C(
                    0x573432d9U),
            };
            r_rsip_func102(Param_pf0_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf0_func100_005[] =
            {
                BSWAP_32BIG_C(0xecbf2ea1U), BSWAP_32BIG_C(0x7447c70bU), BSWAP_32BIG_C(0x583093a0U), BSWAP_32BIG_C(
                    0x7325cb8dU),
            };
            r_rsip_func100(Param_pf0_func100_005);
            r_rsip_func_sub003(0x00001414U, 0x00c0001dU, 0x00000002U);

            r_rsip_func_sub001(0x0014000aU, 0x000f0000U, 0x0404000aU);

            r_rsip_func_sub021(0x000f0032U, 0x0014000aU, 0x04040000U);
            r_rsip_func_sub020(0x20010001U, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x005a0014U, 0x000f000aU, 0x04040002U);

            WR1_PROG(REG_0014H, 0x000007c5U);
            WR1_PROG(REG_00B0H, 0x00001414U);
            WAIT_STS(REG_0014H, 31, 1);
            WR8_ADDR(REG_002CH, &InData_MsgDgst[0]);

            r_rsip_func074();

            WR1_PROG(REG_0094H, 0x000034a6U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f0U, 0x00000000U);

            static const uint32_t Param_pf0_func101_002[] =
            {
                BSWAP_32BIG_C(0xf01ade83U), BSWAP_32BIG_C(0xafe97d77U), BSWAP_32BIG_C(0xcac3a570U), BSWAP_32BIG_C(
                    0xefc95585U),
            };
            r_rsip_func101(Param_pf0_func101_002);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_pf0_func100_006[] =
            {
                BSWAP_32BIG_C(0x30685087U), BSWAP_32BIG_C(0x5d2a2f15U), BSWAP_32BIG_C(0x8aedf40eU), BSWAP_32BIG_C(
                    0x619138e2U),
            };
            r_rsip_func100(Param_pf0_func100_006);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pf0_func102_003[] =
                {
                    BSWAP_32BIG_C(0x10da12a3U), BSWAP_32BIG_C(0x86e46290U), BSWAP_32BIG_C(0xb5e7d62dU), BSWAP_32BIG_C(
                        0xa04b30d9U),
                };
                r_rsip_func102(Param_pf0_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub001(0x005a001eU, 0x0019000aU, 0x04040002U);

                r_rsip_func_sub001(0x00280019U, 0x001e000aU, 0x04040002U);

                r_rsip_func_sub001(0x001e0014U, 0x0019000aU, 0x04040005U);

                r_rsip_func_sub001(0x0019000fU, 0x001e000aU, 0x04040002U);

                r_rsip_func_sub003(0x0000140fU, 0x00c0001dU, 0x00000001U);

                r_rsip_func_sub001(0x000f001eU, 0x00140000U, 0x0404000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_pf0_func100_007[] =
                {
                    BSWAP_32BIG_C(0xd1c871edU), BSWAP_32BIG_C(0x0fef4acfU), BSWAP_32BIG_C(0x931999f9U), BSWAP_32BIG_C(
                        0x2b494d7aU),
                };
                r_rsip_func100(Param_pf0_func100_007);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pf0_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x897e9fc1U), BSWAP_32BIG_C(0xcadeed9fU), BSWAP_32BIG_C(0x8f04078eU),
                        BSWAP_32BIG_C(0x9d6dbcdfU),
                    };
                    r_rsip_func102(Param_pf0_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pf0_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x40cca4c2U), BSWAP_32BIG_C(0x522c33e7U), BSWAP_32BIG_C(0x4eeaeae2U),
                        BSWAP_32BIG_C(0xca2f4a34U),
                    };
                    r_rsip_func100(Param_pf0_func100_008);
                    WR1_PROG(REG_00B0H, 0x00001828U);
                    WR1_PROG(REG_0008H, 0x00006022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD8_ADDR(REG_002CH, &OutData_Signature[0]);

                    static const uint32_t Param_pf0_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x8facb085U), BSWAP_32BIG_C(0x7ff28e46U), BSWAP_32BIG_C(0xcfa11c71U),
                        BSWAP_32BIG_C(0xe7c0df9eU),
                    };
                    r_rsip_func100(Param_pf0_func100_009);
                    WR1_PROG(REG_00B0H, 0x0000181eU);
                    WR1_PROG(REG_0008H, 0x00006022U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD8_ADDR(REG_002CH, &OutData_Signature[8]);

                    static const uint32_t Param_pf0_func102_005[] =
                    {
                        BSWAP_32BIG_C(0xc12ea2deU), BSWAP_32BIG_C(0x07d52d93U), BSWAP_32BIG_C(0xda934e73U),
                        BSWAP_32BIG_C(0x2b1df489U),
                    };
                    r_rsip_func102(Param_pf0_func102_005);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
