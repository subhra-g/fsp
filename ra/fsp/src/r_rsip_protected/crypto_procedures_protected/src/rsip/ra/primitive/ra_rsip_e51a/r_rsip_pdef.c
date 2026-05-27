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

rsip_ret_t r_rsip_pdef (const uint32_t InData_SignatureType[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Salt[],
                        const uint32_t InData_SaltLength[],
                        uint32_t       OutData_EncCertificateInfo[])
{
    r_rsip_func_sub010(0x000001c7U, 0x80020080U);
    WR1_PROG(REG_1420H, InData_SignatureType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000deU);

    static const uint32_t Param_pdef_func101_001[] =
    {
        BSWAP_32BIG_C(0x51501677U), BSWAP_32BIG_C(0x788eb155U), BSWAP_32BIG_C(0x4fafaa48U), BSWAP_32BIG_C(0xf2e0412eU),
    };
    r_rsip_func101(Param_pdef_func101_001);
    r_rsip_func411(InData_MsgDgst);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_pdef_func100_001[] =
    {
        BSWAP_32BIG_C(0x7c257e73U), BSWAP_32BIG_C(0x83d9f88cU), BSWAP_32BIG_C(0x5b476ba1U), BSWAP_32BIG_C(0x1bef4b48U),
    };
    r_rsip_func100(Param_pdef_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        WR1_PROG(REG_1404H, 0x17f80000U);
        WR1_PROG(REG_1608H, 0x80900001U);
        r_rsip_func_sub001(0x03430041U);

        WR1_PROG(REG_1600H, 0x00000842U);

        static const uint32_t Param_pdef_func101_002[] =
        {
            BSWAP_32BIG_C(0x1367afd4U), BSWAP_32BIG_C(0xb70f41c6U), BSWAP_32BIG_C(0x0a10027fU), BSWAP_32BIG_C(
                0x513ae345U),
        };
        r_rsip_func101(Param_pdef_func101_002);
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_SaltLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000deU);

        static const uint32_t Param_pdef_func101_003[] =
        {
            BSWAP_32BIG_C(0x766f0198U), BSWAP_32BIG_C(0xe29b7d5aU), BSWAP_32BIG_C(0xcbe0ff70U), BSWAP_32BIG_C(
                0xb829c445U),
        };
        r_rsip_func101(Param_pdef_func101_003);
        r_rsip_func412(InData_Salt);

        r_rsip_func_sub006(0x38008bc0U, 0x76bea7b0U, 0x00A60000U);
        static const uint32_t Param_pdef_func100_002[] =
        {
            BSWAP_32BIG_C(0xe3fad6c4U), BSWAP_32BIG_C(0x60d28969U), BSWAP_32BIG_C(0xe680f67cU), BSWAP_32BIG_C(
                0x1a0c7474U),
        };
        r_rsip_func100(Param_pdef_func100_002);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pdef_func102_001[] =
            {
                BSWAP_32BIG_C(0x38b6f92fU), BSWAP_32BIG_C(0xe78aaa48U), BSWAP_32BIG_C(0xd680122fU), BSWAP_32BIG_C(
                    0x1568e958U),
            };
            r_rsip_func102(Param_pdef_func102_001);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pdef_func101_004[] =
            {
                BSWAP_32BIG_C(0xc50d6f41U), BSWAP_32BIG_C(0x00258b12U), BSWAP_32BIG_C(0x0746a245U), BSWAP_32BIG_C(
                    0x69b107c3U),
            };
            r_rsip_func101(Param_pdef_func101_004);
        }
    }

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000deU);

    static const uint32_t Param_pdef_func101_005[] =
    {
        BSWAP_32BIG_C(0x7dba4a96U), BSWAP_32BIG_C(0x9b1babf5U), BSWAP_32BIG_C(0x97b319f9U), BSWAP_32BIG_C(0x9e196780U),
    };
    r_rsip_func101(Param_pdef_func101_005);
    r_rsip_func413();

    r_rsip_func_sub006(0x38008be0U, 0xa7cd232fU, 0x00A60000U);
    static const uint32_t Param_pdef_func100_003[] =
    {
        BSWAP_32BIG_C(0xefb77471U), BSWAP_32BIG_C(0x34f7e1bfU), BSWAP_32BIG_C(0x022cb347U), BSWAP_32BIG_C(0x01c0df09U),
    };
    r_rsip_func100(Param_pdef_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pdef_func102_002[] =
        {
            BSWAP_32BIG_C(0x04d9a659U), BSWAP_32BIG_C(0xd946ca73U), BSWAP_32BIG_C(0x3ede3354U), BSWAP_32BIG_C(
                0xe69cba12U),
        };
        r_rsip_func102(Param_pdef_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000deU);

        static const uint32_t Param_pdef_func101_006[] =
        {
            BSWAP_32BIG_C(0x2cbc719fU), BSWAP_32BIG_C(0xcc4fcd46U), BSWAP_32BIG_C(0xc2812bb7U), BSWAP_32BIG_C(
                0xbea885a9U),
        };
        r_rsip_func101(Param_pdef_func101_006);
        r_rsip_func414(OutData_EncCertificateInfo);

        static const uint32_t Param_pdef_func102_003[] =
        {
            BSWAP_32BIG_C(0x992234b3U), BSWAP_32BIG_C(0x99aa94a4U), BSWAP_32BIG_C(0x00361d97U), BSWAP_32BIG_C(
                0xcc03ef5eU),
        };
        r_rsip_func102(Param_pdef_func102_003);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
