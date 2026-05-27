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
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub030(0x00f50001U, 0x000007f0U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_pf5_func100_001[] =
    {
        BSWAP_32BIG_C(0x3ef37318U), BSWAP_32BIG_C(0x2d122113U), BSWAP_32BIG_C(0xdb403830U), BSWAP_32BIG_C(0xd8d6220eU),
    };
    r_rsip_func100(Param_pf5_func100_001);
    r_rsip_func027(InData_DomainParam);

    WR1_PROG(REG_1404H, 0x11300000U);
    r_rsip_func_sub004(0x08000104U, 0x00000002U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);

    r_rsip_func_sub018(0x00000020U, 0x00000410U, 0x06060010U);

    r_rsip_func_sub018(0x00000018U, 0x00000070U, 0x06060010U);

    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f501U);

    static const uint32_t Param_pf5_func101_001[] =
    {
        BSWAP_32BIG_C(0xc32a8626U), BSWAP_32BIG_C(0xc6b3fd98U), BSWAP_32BIG_C(0x1becfb7eU), BSWAP_32BIG_C(0x3b645497U),
    };
    r_rsip_func101(Param_pf5_func101_001);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f502U);

    static const uint32_t Param_pf5_func101_002[] =
    {
        BSWAP_32BIG_C(0x0bdb34b3U), BSWAP_32BIG_C(0x07744e2cU), BSWAP_32BIG_C(0x02c84356U), BSWAP_32BIG_C(0xa1a4adadU),
    };
    r_rsip_func101(Param_pf5_func101_002);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000f503U);

    static const uint32_t Param_pf5_func101_003[] =
    {
        BSWAP_32BIG_C(0xcfef2c29U), BSWAP_32BIG_C(0x781d91daU), BSWAP_32BIG_C(0x6bdfcde3U), BSWAP_32BIG_C(0x6e329512U),
    };
    r_rsip_func101(Param_pf5_func101_003);
    r_rsip_func113();
    r_rsip_func_sub004(0x0c200104U, 0x00000000U);
    r_rsip_func_sub001(0x00c20011U);

    WR1_PROG(REG_1014H, 0x00000110U);
    r_rsip_func_sub021(0x00000410U, 0x00000160U, 0x00000020U, 0x06060004U);

    WR1_PROG(REG_1404H, 0x14180000U);
    r_rsip_func_sub004(0x08000104U, 0x00000001U);
    r_rsip_func_sub001(0x00c0002dU);
    r_rsip_func_sub001(0x00c20005U);
    r_rsip_func_sub001(0x0002000dU);

    r_rsip_func_sub002(0x00000160U, 0x00000448U, 0x00000340U, 0x06060009U);

    r_rsip_func_sub018(0x00000020U, 0x000000c0U, 0x06060010U);

    static const uint32_t Param_pf5_func100_002[] =
    {
        BSWAP_32BIG_C(0xec9bcc1bU), BSWAP_32BIG_C(0x5408880fU), BSWAP_32BIG_C(0xeed25a5aU), BSWAP_32BIG_C(0x97bf2c48U),
    };
    r_rsip_func100(Param_pf5_func100_002);
    r_rsip_func028(InData_DomainParam);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f5U);

    static const uint32_t Param_pf5_func101_004[] =
    {
        BSWAP_32BIG_C(0x2cfa0e64U), BSWAP_32BIG_C(0x0554fcc1U), BSWAP_32BIG_C(0xdaccf65eU), BSWAP_32BIG_C(0x15a2d89dU),
    };
    r_rsip_func101(Param_pf5_func101_004);
    r_rsip_func089();

    static const uint32_t Param_pf5_func100_003[] =
    {
        BSWAP_32BIG_C(0xebd612ebU), BSWAP_32BIG_C(0x3c495939U), BSWAP_32BIG_C(0xee28a7c0U), BSWAP_32BIG_C(0x8d54b5a6U),
    };
    r_rsip_func100(Param_pf5_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pf5_func102_001[] =
        {
            BSWAP_32BIG_C(0x30d99e8cU), BSWAP_32BIG_C(0xc8cdf727U), BSWAP_32BIG_C(0xad5d62d2U), BSWAP_32BIG_C(
                0xf66a9da1U),
        };
        r_rsip_func102(Param_pf5_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        r_rsip_func_sub021(0x000000c0U, 0x000002f0U, 0x00000020U, 0x06060002U);

        WR1_PROG(REG_1014H, 0x000002f0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        r_rsip_func_sub005(0x000002a0U, 0x06060004U, 0x00010001U);
        WAIT_STS(REG_1000H, 0, 0);

        WR1_PROG(REG_1404H, 0x10e00000U);
        r_rsip_func_sub004(0x08000104U, 0x00000001U);
        r_rsip_func_sub001(0x00c0002dU);
        r_rsip_func_sub001(0x00c20005U);
        r_rsip_func_sub001(0x0002000dU);

        r_rsip_func_sub002(0x000002a0U, 0x00000110U, 0x00000160U, 0x0606000aU);

        WR1_PROG(REG_143CH, 0x00210000U);

        static const uint32_t Param_pf5_func100_004[] =
        {
            BSWAP_32BIG_C(0xd29da73aU), BSWAP_32BIG_C(0xf2992113U), BSWAP_32BIG_C(0x8cb77152U), BSWAP_32BIG_C(
                0xaff34196U),
        };
        r_rsip_func100(Param_pf5_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pf5_func102_002[] =
            {
                BSWAP_32BIG_C(0x6b5c3b4bU), BSWAP_32BIG_C(0xbf208582U), BSWAP_32BIG_C(0x24dc273fU), BSWAP_32BIG_C(
                    0xd05de7c1U),
            };
            r_rsip_func102(Param_pf5_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pf5_func100_005[] =
            {
                BSWAP_32BIG_C(0x59dfd870U), BSWAP_32BIG_C(0x9c9f4200U), BSWAP_32BIG_C(0x131c417bU), BSWAP_32BIG_C(
                    0xc21dddf4U),
            };
            r_rsip_func100(Param_pf5_func100_005);
            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_func_sub004(0x08000104U, 0x00000002U);
            r_rsip_func_sub001(0x00c0002dU);
            r_rsip_func_sub001(0x00c20005U);
            r_rsip_func_sub001(0x0002000dU);

            r_rsip_func_sub002(0x000000c0U, 0x00000160U, 0x00000110U, 0x0606000aU);

            r_rsip_func_sub013(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0606000fU, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);
            WR1_PROG(REG_143CH, 0x00000d00U);

            r_rsip_func_sub022(0x00000160U, 0x00000840U, 0x000000c0U);
            r_rsip_func_sub005(0x00000110U, 0x06060002U, 0x00010001U);
            WAIT_STS(REG_1000H, 0, 0);

            r_rsip_func_sub023(0x00000bc2U, 0x00000200U, 0x08008107U);

            WR1_PROG(REG_1404H, 0x11300000U);
            for (iLoop = 0U; iLoop < 12U; )
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

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f5U);

            static const uint32_t Param_pf5_func101_005[] =
            {
                BSWAP_32BIG_C(0xd33b9a11U), BSWAP_32BIG_C(0x4478cc94U), BSWAP_32BIG_C(0xe104d378U), BSWAP_32BIG_C(
                    0xe9d5c89cU),
            };
            r_rsip_func101(Param_pf5_func101_005);
            r_rsip_func043();

            r_rsip_func076();

            WR1_PROG(REG_1600H, 0x000034feU);

            r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000f5U);

            static const uint32_t Param_pf5_func101_006[] =
            {
                BSWAP_32BIG_C(0xbb5e4aa9U), BSWAP_32BIG_C(0x271ec5fbU), BSWAP_32BIG_C(0x28ad57c3U), BSWAP_32BIG_C(
                    0x5ac0b029U),
            };
            r_rsip_func101(Param_pf5_func101_006);
            r_rsip_func044();

            r_rsip_func_sub023(0x00000bc2U, 0x40000200U, 0xf7009d07U);

            for (iLoop = 0U; iLoop < 12U; )
            {
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            WR1_PROG(REG_1404H, 0x11d00000U);
            r_rsip_func_sub001(0x00c20031U);

            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_func_sub001(0x00820011U);

            static const uint32_t Param_pf5_func100_006[] =
            {
                BSWAP_32BIG_C(0x41eb651eU), BSWAP_32BIG_C(0xc62f40efU), BSWAP_32BIG_C(0x18071c33U), BSWAP_32BIG_C(
                    0xe1b1b6afU),
            };
            r_rsip_func100(Param_pf5_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pf5_func102_003[] =
                {
                    BSWAP_32BIG_C(0x1709626fU), BSWAP_32BIG_C(0xa4e527a1U), BSWAP_32BIG_C(0xf9d2d845U), BSWAP_32BIG_C(
                        0xe7a7e284U),
                };
                r_rsip_func102(Param_pf5_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub022(0x00000200U, 0x00000840U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x000001b0U, 0x000002a0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                r_rsip_func_sub007(0x00000160U, 0x00000200U, 0x000000c0U);
                r_rsip_func_sub005(0x000001b0U, 0x06060005U, 0x00010001U);
                r_rsip_func_sub007(0x00000110U, 0x000001b0U, 0x000000c0U);
                r_rsip_func_sub005(0x00000200U, 0x06060002U, 0x00010001U);
                WAIT_STS(REG_1000H, 0, 0);

                WR1_PROG(REG_1404H, 0x10e00000U);
                r_rsip_func_sub004(0x08000104U, 0x00000001U);
                r_rsip_func_sub001(0x00c0002dU);
                r_rsip_func_sub001(0x00c20005U);
                r_rsip_func_sub001(0x0002000dU);

                r_rsip_func_sub002(0x00000200U, 0x00000110U, 0x00000160U, 0x0606000aU);

                WR1_PROG(REG_143CH, 0x00210000U);

                static const uint32_t Param_pf5_func100_007[] =
                {
                    BSWAP_32BIG_C(0xf652b323U), BSWAP_32BIG_C(0xb8ce19c9U), BSWAP_32BIG_C(0xc73ea39dU), BSWAP_32BIG_C(
                        0x9702e254U),
                };
                r_rsip_func100(Param_pf5_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pf5_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x7349fdfcU), BSWAP_32BIG_C(0xb1d6025eU), BSWAP_32BIG_C(0xffb8d22cU),
                        BSWAP_32BIG_C(0x467d0df9U),
                    };
                    r_rsip_func102(Param_pf5_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_pf5_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x10140491U), BSWAP_32BIG_C(0xf5677872U), BSWAP_32BIG_C(0x62dd4ea9U),
                        BSWAP_32BIG_C(0xa2c52141U),
                    };
                    r_rsip_func100(Param_pf5_func100_008);
                    WR1_PROG(REG_1404H, 0x12700000U);
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

                    static const uint32_t Param_pf5_func100_009[] =
                    {
                        BSWAP_32BIG_C(0x5265c986U), BSWAP_32BIG_C(0x8aef69f4U), BSWAP_32BIG_C(0x04e10e93U),
                        BSWAP_32BIG_C(0x990d6caaU),
                    };
                    r_rsip_func100(Param_pf5_func100_009);
                    WR1_PROG(REG_1404H, 0x11d00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_func_sub001(0x00830031U);

                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[12]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[16]);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_Signature[20]);

                    static const uint32_t Param_pf5_func102_005[] =
                    {
                        BSWAP_32BIG_C(0x4ab13da4U), BSWAP_32BIG_C(0xc18379dcU), BSWAP_32BIG_C(0xb2c21c27U),
                        BSWAP_32BIG_C(0x45d1af2bU),
                    };
                    r_rsip_func102(Param_pf5_func102_005);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
