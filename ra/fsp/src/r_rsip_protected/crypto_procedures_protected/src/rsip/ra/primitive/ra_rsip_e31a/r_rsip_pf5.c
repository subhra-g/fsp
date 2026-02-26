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

rsip_ret_t r_rsip_pf5 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00f50001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func027(InData_DomainParam);

    static const uint32_t Param_pf5_func100_001[] =
    {
        BSWAP_32BIG_C(0xb115ceb5U), BSWAP_32BIG_C(0x8c87476bU), BSWAP_32BIG_C(0x1f0e9b19U), BSWAP_32BIG_C(0xc6f5e166U),
    };
    r_rsip_func100(Param_pf5_func100_001);

    WR1_PROG(REG_00B0H, 0x00009415U);
    r_rsip_func103();
    static const uint32_t Param_pf5_func100_002[] =
    {
        BSWAP_32BIG_C(0x8de8c312U), BSWAP_32BIG_C(0xfbb6fe82U), BSWAP_32BIG_C(0xabaa8e2bU), BSWAP_32BIG_C(0xbd973d0dU),
    };
    r_rsip_func100(Param_pf5_func100_002);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_pf5_func100_003[] =
    {
        BSWAP_32BIG_C(0xbbe97b0eU), BSWAP_32BIG_C(0x307b19acU), BSWAP_32BIG_C(0xdf32f693U), BSWAP_32BIG_C(0xd28f4a14U),
    };
    r_rsip_func100(Param_pf5_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x00009438U, 0x00c0002dU, 0x00000001U);

    r_rsip_func_sub003(0x00009423U, 0x00c0002dU, 0x00000002U);

    r_rsip_func_sub001(0x0023000eU, 0x001c0000U, 0x0606000aU);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B8H, 0x0000001cU);

    WR1_PROG(REG_00A4H, 0x06060010U);

    r_rsip_func_sub020(0x20010001U, 0x00000001U);

    r_rsip_func_sub001(0x00380015U, 0x003f001cU, 0x06060002U);

    r_rsip_func_sub001(0x0038003fU, 0x00460000U, 0x06060009U);

    r_rsip_func028(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f5U, 0x00000000U);

    static const uint32_t Param_pf5_func101_001[] =
    {
        BSWAP_32BIG_C(0x79a8737eU), BSWAP_32BIG_C(0x86fd90f7U), BSWAP_32BIG_C(0xdb7b4eddU), BSWAP_32BIG_C(0xb6110de8U),
    };
    r_rsip_func101(Param_pf5_func101_001);
    r_rsip_func089();

    static const uint32_t Param_pf5_func100_004[] =
    {
        BSWAP_32BIG_C(0x022b0067U), BSWAP_32BIG_C(0xb48a833cU), BSWAP_32BIG_C(0x2461b931U), BSWAP_32BIG_C(0xcc167a69U),
    };
    r_rsip_func100(Param_pf5_func100_004);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf5_func102_001[] =
        {
            BSWAP_32BIG_C(0x5df28191U), BSWAP_32BIG_C(0x067185b6U), BSWAP_32BIG_C(0x10059891U), BSWAP_32BIG_C(
                0xf5b6a1dbU),
        };
        r_rsip_func102(Param_pf5_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00B8H, 0x0000000eU);

        WR1_PROG(REG_00A4H, 0x06060010U);

        r_rsip_func_sub020(0x20010001U, 0x00000001U);

        r_rsip_func_sub001(0x007e0038U, 0x003f000eU, 0x06060002U);

        WR1_PROG(REG_0014H, 0x000000a5U);
        r_rsip_func_sub009(0x00009415U, 0x00c0002dU, 0x00001800U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000001U));

        r_rsip_func_sub001(0x0015003fU, 0x0038000eU, 0x06060002U);

        r_rsip_func_sub001(0x00150038U, 0x001c0000U, 0x0606000aU);

        WR1_PROG(REG_0040H, 0x00210000U);

        static const uint32_t Param_pf5_func100_005[] =
        {
            BSWAP_32BIG_C(0x9befea36U), BSWAP_32BIG_C(0x75988304U), BSWAP_32BIG_C(0x3a5795d8U), BSWAP_32BIG_C(
                0x79f1e06bU),
        };
        r_rsip_func100(Param_pf5_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_pf5_func102_002[] =
            {
                BSWAP_32BIG_C(0xb31cda1dU), BSWAP_32BIG_C(0xff486971U), BSWAP_32BIG_C(0x457ca05fU), BSWAP_32BIG_C(
                    0x5a303a3aU),
            };
            r_rsip_func102(Param_pf5_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf5_func100_006[] =
            {
                BSWAP_32BIG_C(0xa9c8370cU), BSWAP_32BIG_C(0x7c04069eU), BSWAP_32BIG_C(0xc413c550U), BSWAP_32BIG_C(
                    0xbf5ad3dbU),
            };
            r_rsip_func100(Param_pf5_func100_006);
            r_rsip_func_sub003(0x0000941cU, 0x00c0002dU, 0x00000002U);

            r_rsip_func_sub001(0x001c000eU, 0x00150000U, 0x0606000aU);

            r_rsip_func_sub021(0x00150046U, 0x001c000eU, 0x06060000U);
            r_rsip_func_sub020(0x20010001U, 0x00000001U);
            WR1_PROG(REG_0040H, 0x00000d00U);

            r_rsip_func_sub001(0x007e001cU, 0x0015000eU, 0x06060002U);

            WR1_PROG(REG_0014H, 0x00000bc5U);
            WR1_PROG(REG_00B0H, 0x0000941cU);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_MsgDgst[0]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_MsgDgst[4]);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_ADDR(REG_002CH, &InData_MsgDgst[8]);

            r_rsip_func076();

            WR1_PROG(REG_0094H, 0x000034a6U);

            static const uint32_t Param_pf5_sub100_001[] =
            {
                BSWAP_32BIG_C(0x000000f5U), BSWAP_32BIG_C(0xf266a80eU), BSWAP_32BIG_C(0xc127f856U),
                BSWAP_32BIG_C(0xbd34ee9eU),
                BSWAP_32BIG_C(0x227643beU), BSWAP_32BIG_C(0x000000f5U), BSWAP_32BIG_C(0xc6af6aeaU),
                BSWAP_32BIG_C(0xb1c4c414U),
                BSWAP_32BIG_C(0xf99ee529U),
                BSWAP_32BIG_C(0x3ec957bfU), 0x0000942aU,
            };
            r_rsip_func_sub100(InData_KeyIndex, Param_pf5_sub100_001, RSIP_SEL_BIT_LENGTH_384);

            static const uint32_t Param_pf5_func100_007[] =
            {
                BSWAP_32BIG_C(0x2c474d3dU), BSWAP_32BIG_C(0x9bda990fU), BSWAP_32BIG_C(0xf7967fb9U), BSWAP_32BIG_C(
                    0x3f00e90dU),
            };
            r_rsip_func100(Param_pf5_func100_007);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pf5_func102_003[] =
                {
                    BSWAP_32BIG_C(0x4db8f271U), BSWAP_32BIG_C(0x39b281b0U), BSWAP_32BIG_C(0x782e0921U), BSWAP_32BIG_C(
                        0x1a235e53U),
                };
                r_rsip_func102(Param_pf5_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub001(0x007e002aU, 0x0023000eU, 0x06060002U);

                r_rsip_func_sub001(0x00380023U, 0x002a000eU, 0x06060002U);

                r_rsip_func_sub001(0x002a001cU, 0x0023000eU, 0x06060005U);

                r_rsip_func_sub001(0x00230015U, 0x002a000eU, 0x06060002U);

                r_rsip_func_sub003(0x00009415U, 0x00c0002dU, 0x00000001U);

                r_rsip_func_sub001(0x0015002aU, 0x001c0000U, 0x0606000aU);

                WR1_PROG(REG_0040H, 0x00210000U);

                static const uint32_t Param_pf5_func100_008[] =
                {
                    BSWAP_32BIG_C(0xaffe395eU), BSWAP_32BIG_C(0xd517c071U), BSWAP_32BIG_C(0x6e990641U), BSWAP_32BIG_C(
                        0x090c9765U),
                };
                r_rsip_func100(Param_pf5_func100_008);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_pf5_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x744a0831U), BSWAP_32BIG_C(0x203e67abU), BSWAP_32BIG_C(0xf28f8ee1U),
                        BSWAP_32BIG_C(0x7a0e4df0U),
                    };
                    r_rsip_func102(Param_pf5_func102_004);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pf5_func100_009[] =
                    {
                        BSWAP_32BIG_C(0xb95f1927U), BSWAP_32BIG_C(0x25b0bcb4U), BSWAP_32BIG_C(0xed0ae2dfU),
                        BSWAP_32BIG_C(0xaa1519c4U),
                    };
                    r_rsip_func100(Param_pf5_func100_009);
                    WR1_PROG(REG_00B0H, 0x00009838U);
                    WR1_PROG(REG_0008H, 0x00006032U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[0]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[4]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[8]);

                    static const uint32_t Param_pf5_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x8c2521aaU), BSWAP_32BIG_C(0x134e1f4bU), BSWAP_32BIG_C(0x8049b2ecU),
                        BSWAP_32BIG_C(0xd71d88d1U),
                    };
                    r_rsip_func100(Param_pf5_func100_010);
                    WR1_PROG(REG_00B0H, 0x0000982aU);
                    WR1_PROG(REG_0008H, 0x00006032U);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[12]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[16]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD4_ADDR(REG_002CH, &OutData_Signature[20]);

                    static const uint32_t Param_pf5_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x8d4ac452U), BSWAP_32BIG_C(0xc0e5e098U), BSWAP_32BIG_C(0xc9dfadd4U),
                        BSWAP_32BIG_C(0x4d6c935fU),
                    };
                    r_rsip_func102(Param_pf5_func102_005);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
