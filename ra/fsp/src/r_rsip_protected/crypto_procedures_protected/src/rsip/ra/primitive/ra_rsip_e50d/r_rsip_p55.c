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

rsip_ret_t r_rsip_p55 (const uint32_t InData_Cmd[], uint32_t OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00550001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub006(0x3420a880U, 0x0000002cU, 0x00260000U);

    r_rsip_func_sub006(0x3420a880U, 0x00000031U, 0x00A60000U);

    static const uint32_t Param_p55_func100_001[] =
    {
        BSWAP_32BIG_C(0x25f53514U), BSWAP_32BIG_C(0x4e795847U), BSWAP_32BIG_C(0x5ca52748U), BSWAP_32BIG_C(0x4aecca8cU),
    };
    r_rsip_func100(Param_p55_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p55_func102_001[] =
        {
            BSWAP_32BIG_C(0x2922edddU), BSWAP_32BIG_C(0xab541a66U), BSWAP_32BIG_C(0x5b26b20bU), BSWAP_32BIG_C(
                0xadb2fda8U),
        };
        r_rsip_func102(Param_p55_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub021(0x00000842U, 0x38008880U, 0x0000002cU, 0x1000b420U);
        r_rsip_func_sub021(0x00000004U, 0x1000d040U, 0x38008880U, 0x0000002dU);
        r_rsip_func_sub021(0x1000b420U, 0x00000008U, 0x38008880U, 0x0000002eU);
        r_rsip_func_sub021(0x1000b420U, 0x0000000cU, 0x38008880U, 0x0000002fU);
        r_rsip_func_sub021(0x1000b420U, 0x00000010U, 0x38008880U, 0x00000030U);
        WR1_PROG(REG_1600H, 0x1000b420U);
        WR1_PROG(REG_1600H, 0x00000008U);

        r_rsip_func_sub003(0x800103a0U, 0x00005501U);

        static const uint32_t Param_p55_func101_001[] =
        {
            BSWAP_32BIG_C(0x01d67142U), BSWAP_32BIG_C(0xf158f8d8U), BSWAP_32BIG_C(0xac92a39cU), BSWAP_32BIG_C(
                0xeaded7f1U),
        };
        r_rsip_func101(Param_p55_func101_001);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x800103a0U, 0x00000055U);

        static const uint32_t Param_p55_func101_002[] =
        {
            BSWAP_32BIG_C(0xd08e331fU), BSWAP_32BIG_C(0x4acc2a2dU), BSWAP_32BIG_C(0xc6b51699U), BSWAP_32BIG_C(
                0x800193c6U),
        };
        r_rsip_func101(Param_p55_func101_002);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e4U);

        r_rsip_func_sub003(0x800103a0U, 0x00000055U);

        static const uint32_t Param_p55_func101_003[] =
        {
            BSWAP_32BIG_C(0x63fa0293U), BSWAP_32BIG_C(0x25246d62U), BSWAP_32BIG_C(0xe2d4a116U), BSWAP_32BIG_C(
                0x97d4385fU),
        };
        r_rsip_func101(Param_p55_func101_003);
        r_rsip_func044();

        static const uint32_t Param_p55_func100_002[] =
        {
            BSWAP_32BIG_C(0x6ed44cd5U), BSWAP_32BIG_C(0x7c39c6dcU), BSWAP_32BIG_C(0x6ed6fc54U), BSWAP_32BIG_C(
                0x341d5027U),
        };
        r_rsip_func100(Param_p55_func100_002);
        WR1_PROG(REG_1444H, 0x000001a2U);
        r_rsip_func_sub028(0x08000044U, 0x00000000U);

        r_rsip_func_sub028(0x08000054U, 0x00000000U);

        r_rsip_func_sub016(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            r_rsip_func_sub003(0x800103a0U, 0x00005502U);

            static const uint32_t Param_p55_func101_004[] =
            {
                BSWAP_32BIG_C(0xe7d3d7b8U), BSWAP_32BIG_C(0x6ede0484U), BSWAP_32BIG_C(0x35b9aa75U), BSWAP_32BIG_C(
                    0xf4bb09d2U),
            };
            r_rsip_func101(Param_p55_func101_004);
            r_rsip_func103();

            static const uint32_t Param_p55_func100_003[] =
            {
                BSWAP_32BIG_C(0x20f34906U), BSWAP_32BIG_C(0x4b2c704bU), BSWAP_32BIG_C(0x32267cbfU), BSWAP_32BIG_C(
                    0x22ec09e3U),
            };
            r_rsip_func100(Param_p55_func100_003);
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d45U);
            r_rsip_func_sub001(0x00820011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

            WR1_PROG(REG_1600H, 0x0000a820U);
            WR1_PROG(REG_1600H, 0x00000004U);

            static const uint32_t Param_p55_func101_005[] =
            {
                BSWAP_32BIG_C(0x5ab7cc39U), BSWAP_32BIG_C(0x87ca52e9U), BSWAP_32BIG_C(0x4a742c18U), BSWAP_32BIG_C(
                    0x40a53984U),
            };
            r_rsip_func101(Param_p55_func101_005);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub014(0x00007c01U, 0x00602000U);

        r_rsip_func_sub006(0x38008840U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_p55_func100_004[] =
        {
            BSWAP_32BIG_C(0x2d08b593U), BSWAP_32BIG_C(0x40a9394bU), BSWAP_32BIG_C(0x65cc2bdaU), BSWAP_32BIG_C(
                0xb3391897U),
        };
        r_rsip_func100(Param_p55_func100_004);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func_sub003(0x800103a0U, 0x00005503U);

            static const uint32_t Param_p55_func101_006[] =
            {
                BSWAP_32BIG_C(0x8d281cd0U), BSWAP_32BIG_C(0xae624d6cU), BSWAP_32BIG_C(0xddc28f36U), BSWAP_32BIG_C(
                    0x4a177e45U),
            };
            r_rsip_func101(Param_p55_func101_006);
            r_rsip_func103();

            static const uint32_t Param_p55_func100_005[] =
            {
                BSWAP_32BIG_C(0x5bc23946U), BSWAP_32BIG_C(0xf119d092U), BSWAP_32BIG_C(0x986f1886U), BSWAP_32BIG_C(
                    0x9a319746U),
            };
            r_rsip_func100(Param_p55_func100_005);
            r_rsip_func_sub004(0x0c200104U, 0x00000000U);

            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d45U);
            r_rsip_func_sub001(0x0082000dU);
            r_rsip_func_sub001(0x00020005U);
            r_rsip_func_sub001(0x00800005U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

            iLoop = iLoop + 4;

            static const uint32_t Param_p55_func101_007[] =
            {
                BSWAP_32BIG_C(0xdeb71047U), BSWAP_32BIG_C(0x496f533fU), BSWAP_32BIG_C(0xd5a2bfe4U), BSWAP_32BIG_C(
                    0xc9cc6563U),
            };
            r_rsip_func101(Param_p55_func101_007);
        }

        static const uint32_t Param_p55_func100_006[] =
        {
            BSWAP_32BIG_C(0x8ade5af3U), BSWAP_32BIG_C(0xee5e4482U), BSWAP_32BIG_C(0xbd81a41aU), BSWAP_32BIG_C(
                0xc412be4bU),
        };
        r_rsip_func100(Param_p55_func100_006);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

        static const uint32_t Param_p55_func100_007[] =
        {
            BSWAP_32BIG_C(0x71a4a31dU), BSWAP_32BIG_C(0x0ad940a2U), BSWAP_32BIG_C(0x9bf3a013U), BSWAP_32BIG_C(
                0x7b662f53U),
        };
        r_rsip_func100(Param_p55_func100_007);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

        static const uint32_t Param_p55_func102_002[] =
        {
            BSWAP_32BIG_C(0xbff625f8U), BSWAP_32BIG_C(0x491d55c9U), BSWAP_32BIG_C(0x0b652d79U), BSWAP_32BIG_C(
                0x55d5255fU),
        };
        r_rsip_func102(Param_p55_func102_002);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
