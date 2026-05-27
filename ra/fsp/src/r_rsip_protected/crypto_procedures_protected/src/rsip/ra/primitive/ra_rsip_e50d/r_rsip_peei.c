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

rsip_ret_t r_rsip_peei (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ee0001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010340U);
    WR1_PROG(REG_1420H, InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420ab40U, 0x00000002U, 0x2000b740U, 0x00000001U);

    WR1_PROG(REG_1600H, 0x00000b9cU);

    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);

    WR1_PROG(REG_1404H, 0x19100000U);
    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
    WR4_ADDR(REG_1420H, &InData_Signature[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Signature[4]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1404H, 0x19600000U);
    r_rsip_func_sub008(0x000007c2U, 0x00000100U, 0x08008107U);
    WR4_ADDR(REG_1420H, &InData_Signature[8]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_Signature[12]);
    r_rsip_func_sub001(0x00c20021U);

    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    for (iLoop = 0U; iLoop < 8U; iLoop++)
    {
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_MsgDgst[iLoop]);
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000ee01U);

    static const uint32_t Param_peei_func101_001[] =
    {
        BSWAP_32BIG_C(0x6881723dU), BSWAP_32BIG_C(0x5e922605U), BSWAP_32BIG_C(0x654594d2U), BSWAP_32BIG_C(0x80dd84f1U),
    };
    r_rsip_func101(Param_peei_func101_001);
    r_rsip_func043();

    r_rsip_func075();

    WR1_PROG(REG_1600H, 0x000034feU);

    r_rsip_func_sub003(0x800103a0U, 0x0000ee01U);

    static const uint32_t Param_peei_func101_002[] =
    {
        BSWAP_32BIG_C(0x975d4441U), BSWAP_32BIG_C(0x3dc40588U), BSWAP_32BIG_C(0x69e740a6U), BSWAP_32BIG_C(0x01acd926U),
    };
    r_rsip_func101(Param_peei_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub024(0x00000fc2U, 0x40000300U, 0xe8009107U);

    r_rsip_func_sub023(0x0000b420U, 0x00000060U, 0x80900001U);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);
    r_rsip_func_sub001(0x03420021U);

    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[13]);
    r_rsip_func_sub001(0x03420021U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[17]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_peei_func100_001[] =
    {
        BSWAP_32BIG_C(0x76572b3eU), BSWAP_32BIG_C(0x075bbbfcU), BSWAP_32BIG_C(0x41fc863aU), BSWAP_32BIG_C(0x674614aaU),
    };
    r_rsip_func100(Param_peei_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_peei_func102_001[] =
        {
            BSWAP_32BIG_C(0x517e323cU), BSWAP_32BIG_C(0xf49aea0dU), BSWAP_32BIG_C(0xca6b6433U), BSWAP_32BIG_C(
                0xb4180c01U),
        };
        r_rsip_func102(Param_peei_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1A2CH, 0x00000100U);
        WR1_PROG(REG_1A24H, 0x08008107U);

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1608H, 0x8188001eU);
        r_rsip_func_sub001(0x00890021U);

        r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x8088001eU);
        r_rsip_func_sub001(0x03420021U);

        r_rsip_func_sub003(0x800103a0U, 0x000000eeU);

        static const uint32_t Param_peei_func101_003[] =
        {
            BSWAP_32BIG_C(0xaa484c6bU), BSWAP_32BIG_C(0x9ac723ecU), BSWAP_32BIG_C(0x696da0a4U), BSWAP_32BIG_C(
                0xd259590fU),
        };
        r_rsip_func101(Param_peei_func101_003);
        r_rsip_func073(InData_DomainParam);

        static const uint32_t Param_peei_func100_002[] =
        {
            BSWAP_32BIG_C(0xcfc165e8U), BSWAP_32BIG_C(0x2b4d6258U), BSWAP_32BIG_C(0x5d798fd0U), BSWAP_32BIG_C(
                0xd7166b79U),
        };
        r_rsip_func100(Param_peei_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_peei_func102_002[] =
            {
                BSWAP_32BIG_C(0xf8faf438U), BSWAP_32BIG_C(0xd93145d3U), BSWAP_32BIG_C(0xdf989204U), BSWAP_32BIG_C(
                    0x3c62bc37U),
            };
            r_rsip_func102(Param_peei_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);

            r_rsip_func_sub023(0x0000b7c0U, 0x00000100U, 0x8188001eU);
            r_rsip_func_sub001(0x00890021U);

            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1608H, 0x8088001eU);
            r_rsip_func_sub001(0x03420021U);

            static const uint32_t Param_peei_func101_004[] =
            {
                BSWAP_32BIG_C(0x65df5d46U), BSWAP_32BIG_C(0x165b64f4U), BSWAP_32BIG_C(0x5f9c8edfU), BSWAP_32BIG_C(
                    0x385a15f8U),
            };
            r_rsip_func101(Param_peei_func101_004);

            return RSIP_RET_PASS;
        }
    }
}
