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

rsip_ret_t r_rsip_pf4 (const uint32_t InData_CurveType[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00f40001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_CurveType[0]);
    r_rsip_func_sub018(0x00000000U, 0x3420a800U, 0x00000003U);
    WR1_PROG(REG_0094H, 0x2000b400U);
    WR1_PROG(REG_0094H, 0x00000002U);

    r_rsip_func070(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x000034c0U);

    WR1_PROG(REG_00A0H, 0x20010000U);
    WR1_PROG(REG_00B0H, 0x00002428U);

    static const uint32_t Param_pf4_func100_001[] =
    {
        BSWAP_32BIG_C(0x13f1b684U), BSWAP_32BIG_C(0x365a1141U), BSWAP_32BIG_C(0x31071003U), BSWAP_32BIG_C(0x11f8c2c0U),
    };
    r_rsip_func100(Param_pf4_func100_001);
    r_rsip_func103();
    static const uint32_t Param_pf4_func100_002[] =
    {
        BSWAP_32BIG_C(0x911498f1U), BSWAP_32BIG_C(0x261697f3U), BSWAP_32BIG_C(0x77492b05U), BSWAP_32BIG_C(0xa3f907cdU),
    };
    r_rsip_func100(Param_pf4_func100_002);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10009U, 0x00001800U);
    r_rsip_func_sub015(0x00010009U, 0x00001800U);

    r_rsip_func103();
    static const uint32_t Param_pf4_func100_003[] =
    {
        BSWAP_32BIG_C(0xf5b03aa5U), BSWAP_32BIG_C(0x8d48c9d0U), BSWAP_32BIG_C(0x72d8177dU), BSWAP_32BIG_C(0x27ba43cbU),
    };
    r_rsip_func100(Param_pf4_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func103();
    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);
    r_rsip_func_sub015(0x00c10011U, 0x00001800U);

    r_rsip_func_sub003(0x0000140fU, 0x00c0001dU, 0x00000001U);

    r_rsip_func_sub001(0x000f000aU, 0x00140000U, 0x0404000aU);

    r_rsip_func_sub003(0x0000143cU, 0x00c0001dU, 0x00000002U);

    r_rsip_func_sub009(0x00001419U, 0x00c00021U, 0x00001800U);

    r_rsip_func_sub022(0x00000821U, 0x00000863U, 0x000008a5U);

    for (iLoop = 0U; iLoop < 64U; iLoop++)
    {
        r_rsip_func_sub001(0x00140027U, 0x001e0000U, 0x0404000aU);

        WR1_PROG(REG_00B0H, 0x0000081aU);
        r_rsip_func_sub006(0x80020000U, 0x03430009U, 0x00000884U, 0x38000c21U);
        r_rsip_func_sub022(0x2000d080U, 0x38000c63U, 0x1000d081U);

        r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

        static const uint32_t Param_pf4_func100_004[] =
        {
            BSWAP_32BIG_C(0xce48aec5U), BSWAP_32BIG_C(0xd2ed005dU), BSWAP_32BIG_C(0xe154b08bU), BSWAP_32BIG_C(
                0x9dbd275eU),
        };
        r_rsip_func100(Param_pf4_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub001(0x0019001eU, 0x004b0000U, 0x04040009U);

            static const uint32_t Param_pf4_func101_001[] =
            {
                BSWAP_32BIG_C(0x0cc490a1U), BSWAP_32BIG_C(0xa102f2c9U), BSWAP_32BIG_C(0x9754effdU), BSWAP_32BIG_C(
                    0x9099a4b6U),
            };
            r_rsip_func101(Param_pf4_func101_001);
        }
        else
        {
            r_rsip_func_sub001(0x0019001eU, 0x00270000U, 0x04040009U);

            static const uint32_t Param_pf4_func101_002[] =
            {
                BSWAP_32BIG_C(0xb9ad28c4U), BSWAP_32BIG_C(0xc0328791U), BSWAP_32BIG_C(0xe799f16bU), BSWAP_32BIG_C(
                    0x4a9c9d32U),
            };
            r_rsip_func101(Param_pf4_func101_002);
        }

        r_rsip_func_sub001(0x003c002bU, 0x001e0000U, 0x04040007U);

        r_rsip_func_sub001(0x003c0027U, 0x00230000U, 0x04040007U);

        WR1_PROG(REG_00B0H, 0x0000081fU);
        r_rsip_func_sub012(0x80020040U, 0x03430009U);

        r_rsip_func_sub001(0x0019001eU, 0x002b0000U, 0x04040009U);

        r_rsip_func_sub001(0x001a0023U, 0x00270000U, 0x04040009U);

        WR1_PROG(REG_0094H, 0x00002ca0U);

        static const uint32_t Param_pf4_func101_003[] =
        {
            BSWAP_32BIG_C(0x93fd36d8U), BSWAP_32BIG_C(0x43463d05U), BSWAP_32BIG_C(0xd0b1ff66U), BSWAP_32BIG_C(
                0x4abd6b63U),
        };
        r_rsip_func101(Param_pf4_func101_003);
    }

    r_rsip_func_sub010(0x380088a0U, 0x00000040U, 0x00270000U);

    WR1_PROG(REG_0040H, 0x00402000U);

    r_rsip_func_sub001(0x00140027U, 0x001e0000U, 0x0404000aU);

    WR1_PROG(REG_00B0H, 0x0000081aU);
    r_rsip_func_sub006(0x80020000U, 0x03430009U, 0x00000884U, 0x38000c21U);
    r_rsip_func_sub022(0x2000d080U, 0x38000c63U, 0x1000d081U);

    r_rsip_func_sub010(0x38008880U, 0x00000003U, 0x00270000U);

    static const uint32_t Param_pf4_func100_005[] =
    {
        BSWAP_32BIG_C(0xf98a3d95U), BSWAP_32BIG_C(0x02565abbU), BSWAP_32BIG_C(0xd2096571U), BSWAP_32BIG_C(0x3b77c0d2U),
    };
    r_rsip_func100(Param_pf4_func100_005);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        r_rsip_func_sub001(0x0019001eU, 0x004b0000U, 0x04040009U);

        static const uint32_t Param_pf4_func101_004[] =
        {
            BSWAP_32BIG_C(0xc6c6a805U), BSWAP_32BIG_C(0x12018fcaU), BSWAP_32BIG_C(0xbdeed2b9U), BSWAP_32BIG_C(
                0x8f5e67b5U),
        };
        r_rsip_func101(Param_pf4_func101_004);
    }
    else
    {
        r_rsip_func_sub001(0x0019001eU, 0x00270000U, 0x04040009U);

        static const uint32_t Param_pf4_func101_005[] =
        {
            BSWAP_32BIG_C(0x8d4ad51cU), BSWAP_32BIG_C(0x8df7b2caU), BSWAP_32BIG_C(0x0034691eU), BSWAP_32BIG_C(
                0xd0add1adU),
        };
        r_rsip_func101(Param_pf4_func101_005);
    }

    r_rsip_func_sub001(0x000f0027U, 0x00320000U, 0x04040009U);

    WR1_PROG(REG_0094H, 0x00003406U);

    r_rsip_func071(InData_DomainParam);

    WR1_PROG(REG_0094H, 0x00003420U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000f4U, 0x00000000U);

    static const uint32_t Param_pf4_func101_006[] =
    {
        BSWAP_32BIG_C(0x91795881U), BSWAP_32BIG_C(0x926ed40aU), BSWAP_32BIG_C(0x01b0599dU), BSWAP_32BIG_C(0xadf7fc94U),
    };
    r_rsip_func101(Param_pf4_func101_006);
    r_rsip_func088();

    static const uint32_t Param_pf4_func100_006[] =
    {
        BSWAP_32BIG_C(0x0dad361bU), BSWAP_32BIG_C(0x15b4e378U), BSWAP_32BIG_C(0x00533265U), BSWAP_32BIG_C(0x702821d9U),
    };
    r_rsip_func100(Param_pf4_func100_006);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pf4_func102_001[] =
        {
            BSWAP_32BIG_C(0xbaec3eadU), BSWAP_32BIG_C(0x9bea23a5U), BSWAP_32BIG_C(0x90a5f53dU), BSWAP_32BIG_C(
                0x8dbbcf46U),
        };
        r_rsip_func102(Param_pf4_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pf4_func100_007[] =
        {
            BSWAP_32BIG_C(0x02e93871U), BSWAP_32BIG_C(0x3c4bd4a2U), BSWAP_32BIG_C(0xb7dce22dU), BSWAP_32BIG_C(
                0xeadcd567U),
        };
        r_rsip_func100(Param_pf4_func100_007);
        r_rsip_func103();
        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f401U, 0x00000000U);

        static const uint32_t Param_pf4_func101_007[] =
        {
            BSWAP_32BIG_C(0x39997967U), BSWAP_32BIG_C(0xb5db9ef4U), BSWAP_32BIG_C(0xbe1daeafU), BSWAP_32BIG_C(
                0x0b78bd83U),
        };
        r_rsip_func101(Param_pf4_func101_007);
        r_rsip_func143();

        r_rsip_func074();

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f401U, 0x00000000U);

        static const uint32_t Param_pf4_func101_008[] =
        {
            BSWAP_32BIG_C(0xe41ce6c6U), BSWAP_32BIG_C(0x7b6eefd9U), BSWAP_32BIG_C(0xe6ba8143U), BSWAP_32BIG_C(
                0xba614fe9U),
        };
        r_rsip_func101(Param_pf4_func101_008);
        r_rsip_func044();

        static const uint32_t Param_pf4_func100_008[] =
        {
            BSWAP_32BIG_C(0xc57e8272U), BSWAP_32BIG_C(0x02ceb6abU), BSWAP_32BIG_C(0x815c79aaU), BSWAP_32BIG_C(
                0xde1a2cfcU),
        };
        r_rsip_func100(Param_pf4_func100_008);
        WR1_PROG(REG_00B0H, 0x00001832U);

        r_rsip_func_sub004(0x40000100U, 0xe7009d07U, 0x00430021U, 0x00001022U);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[5]);

        static const uint32_t Param_pf4_func100_009[] =
        {
            BSWAP_32BIG_C(0x7b8719ccU), BSWAP_32BIG_C(0xa2494cc9U), BSWAP_32BIG_C(0xfc640c5fU), BSWAP_32BIG_C(
                0xc20bf7b7U),
        };
        r_rsip_func100(Param_pf4_func100_009);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_PrivKeyIndex[9]);

        static const uint32_t Param_pf4_func100_010[] =
        {
            BSWAP_32BIG_C(0xd35c73a0U), BSWAP_32BIG_C(0x79f5402eU), BSWAP_32BIG_C(0xa18dce30U), BSWAP_32BIG_C(
                0x1f9614c1U),
        };
        r_rsip_func100(Param_pf4_func100_010);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_PrivKeyIndex[0]);

        static const uint32_t Param_pf4_func100_011[] =
        {
            BSWAP_32BIG_C(0x3fb5c751U), BSWAP_32BIG_C(0xa650eda6U), BSWAP_32BIG_C(0x9335614bU), BSWAP_32BIG_C(
                0x34f2e99eU),
        };
        r_rsip_func100(Param_pf4_func100_011);
        r_rsip_func103();
        r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        WR1_PROG(REG_0094H, 0x000034c0U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f402U, 0x00000000U);

        static const uint32_t Param_pf4_func101_009[] =
        {
            BSWAP_32BIG_C(0x290cac46U), BSWAP_32BIG_C(0x5785ca71U), BSWAP_32BIG_C(0x142f403bU), BSWAP_32BIG_C(
                0xb5950b17U),
        };
        r_rsip_func101(Param_pf4_func101_009);
        r_rsip_func143();

        r_rsip_func075();

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000f402U, 0x00000000U);

        static const uint32_t Param_pf4_func101_010[] =
        {
            BSWAP_32BIG_C(0xa371ffb6U), BSWAP_32BIG_C(0x5f51d128U), BSWAP_32BIG_C(0xe28ab86cU), BSWAP_32BIG_C(
                0x8706827bU),
        };
        r_rsip_func101(Param_pf4_func101_010);
        r_rsip_func044();

        r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

        r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

        static const uint32_t Param_pf4_func100_012[] =
        {
            BSWAP_32BIG_C(0x9fab42dfU), BSWAP_32BIG_C(0xd457b86bU), BSWAP_32BIG_C(0xa26d110fU), BSWAP_32BIG_C(
                0xec2d9cc5U),
        };
        r_rsip_func100(Param_pf4_func100_012);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub009(0x00001828U, 0x00430021U, 0x00001800U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[5]);

        static const uint32_t Param_pf4_func100_013[] =
        {
            BSWAP_32BIG_C(0xeb7fcb99U), BSWAP_32BIG_C(0x697747eaU), BSWAP_32BIG_C(0xff2a1caaU), BSWAP_32BIG_C(
                0x045d0981U),
        };
        r_rsip_func100(Param_pf4_func100_013);
        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xe8008107U);
        r_rsip_func_sub009(0x0000182dU, 0x00430021U, 0x00001800U);

        WR1_PROG(REG_0008H, 0x00001022U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[9]);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[13]);

        static const uint32_t Param_pf4_func100_014[] =
        {
            BSWAP_32BIG_C(0xf2d6fff1U), BSWAP_32BIG_C(0xe722bc5eU), BSWAP_32BIG_C(0x32cc805cU), BSWAP_32BIG_C(
                0x1c73ef4cU),
        };
        r_rsip_func100(Param_pf4_func100_014);
        r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

        r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
        RD4_ADDR(REG_002CH, &OutData_PubKeyIndex[17]);

        static const uint32_t Param_pf4_func100_015[] =
        {
            BSWAP_32BIG_C(0x60a72b01U), BSWAP_32BIG_C(0x8536c151U), BSWAP_32BIG_C(0xde26ca14U), BSWAP_32BIG_C(
                0x201e2a4bU),
        };
        r_rsip_func100(Param_pf4_func100_015);
        r_rsip_func_sub017(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_002CH, &OutData_PubKeyIndex[0]);

        static const uint32_t Param_pf4_func102_002[] =
        {
            BSWAP_32BIG_C(0x207522f5U), BSWAP_32BIG_C(0x42951c70U), BSWAP_32BIG_C(0x4397f554U), BSWAP_32BIG_C(
                0xf657201dU),
        };
        r_rsip_func102(Param_pf4_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
