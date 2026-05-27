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

rsip_ret_t r_rsip_pe3 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_EncMsg[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e30001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a880U, 0x00000003U, 0x2000b480U, 0x00000002U);

    WR1_PROG(REG_1600H, 0x000009ceU);

    static const uint32_t Param_pe3_func100_001[] =
    {
        BSWAP_32BIG_C(0xf21ced96U), BSWAP_32BIG_C(0x2209af79U), BSWAP_32BIG_C(0x88c43d63U), BSWAP_32BIG_C(0x10c70cd9U),
    };
    r_rsip_func100(Param_pe3_func100_001);
    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x015c5d71U);

        r_rsip_func_sub003(0x800100c0U, 0x00000008U);

        static const uint32_t Param_pe3_func101_001[] =
        {
            BSWAP_32BIG_C(0xa32f8fc2U), BSWAP_32BIG_C(0xf350b842U), BSWAP_32BIG_C(0x12aa11b5U), BSWAP_32BIG_C(
                0x44c2a6e7U),
        };
        r_rsip_func101(Param_pe3_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0165e3d8U);

        r_rsip_func_sub003(0x800100c0U, 0x0000000cU);

        static const uint32_t Param_pe3_func101_002[] =
        {
            BSWAP_32BIG_C(0x252d1d91U), BSWAP_32BIG_C(0x1b08e080U), BSWAP_32BIG_C(0xe433575bU), BSWAP_32BIG_C(
                0xab04af85U),
        };
        r_rsip_func101(Param_pe3_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        r_rsip_func_sub010(0x000000c7U, 0x800101c0U);
        WR1_PROG(REG_1420H, InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub021(0x30000dceU, 0x00030020U, 0x0000b4a0U, 0x01ea2366U);

        r_rsip_func_sub021(0x0000b4c0U, 0x00000014U, 0x00000060U, 0x0000b4a0U);
        r_rsip_func_sub021(0x015d7825U, 0x0000b4c0U, 0x00000010U, 0x00000080U);

        static const uint32_t Param_pe3_func101_003[] =
        {
            BSWAP_32BIG_C(0xa77ef864U), BSWAP_32BIG_C(0x757f1c86U), BSWAP_32BIG_C(0xce660a05U), BSWAP_32BIG_C(
                0xa1eb575eU),
        };
        r_rsip_func101(Param_pe3_func101_003);
    }

    r_rsip_func_sub003(0x800103a0U, 0x000000e3U);

    static const uint32_t Param_pe3_func101_004[] =
    {
        BSWAP_32BIG_C(0x0550f34eU), BSWAP_32BIG_C(0xde7e5fbeU), BSWAP_32BIG_C(0x01c1ea86U), BSWAP_32BIG_C(0x7a2df0f5U),
    };
    r_rsip_func101(Param_pe3_func101_004);
    r_rsip_func407(InData_EncSecret);

    static const uint32_t Param_pe3_func100_002[] =
    {
        BSWAP_32BIG_C(0xfb0c75c1U), BSWAP_32BIG_C(0xdae08bd5U), BSWAP_32BIG_C(0xc48096e1U), BSWAP_32BIG_C(0x2c7c7242U),
    };
    r_rsip_func100(Param_pe3_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe3_func102_001[] =
        {
            BSWAP_32BIG_C(0xd17ba5a2U), BSWAP_32BIG_C(0xa727a069U), BSWAP_32BIG_C(0xf0bc4b3aU), BSWAP_32BIG_C(
                0xc7eeb797U),
        };
        r_rsip_func102(Param_pe3_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub021(0x00000800U, 0x30008880U, 0x00000002U, 0x00030020U);
        r_rsip_func_sub022(0x38000dceU, 0x10002c00U, 0x00000080U);
        r_rsip_func_sub006(0x38008800U, 0x00000001U, 0x00260000U);

        static const uint32_t Param_pe3_func100_003[] =
        {
            BSWAP_32BIG_C(0x48171020U), BSWAP_32BIG_C(0x7e81b5edU), BSWAP_32BIG_C(0xc3a46c45U), BSWAP_32BIG_C(
                0xd66485ccU),
        };
        r_rsip_func100(Param_pe3_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            r_rsip_func408();

            static const uint32_t Param_pe3_func101_005[] =
            {
                BSWAP_32BIG_C(0x5b471199U), BSWAP_32BIG_C(0x4c515d7dU), BSWAP_32BIG_C(0xd9cbe831U), BSWAP_32BIG_C(
                    0x32072ad0U),
            };
            r_rsip_func101(Param_pe3_func101_005);
        }

        r_rsip_func_sub003(0x800103a0U, 0x000000e3U);

        static const uint32_t Param_pe3_func101_006[] =
        {
            BSWAP_32BIG_C(0xe6ce8517U), BSWAP_32BIG_C(0x04e273dcU), BSWAP_32BIG_C(0x2292fc76U), BSWAP_32BIG_C(
                0x534a162eU),
        };
        r_rsip_func101(Param_pe3_func101_006);
        r_rsip_func103();

        r_rsip_func_sub004(0x0c200104U, 0x00000000U);

        WR1_PROG(REG_1608H, 0x80010000U);
        r_rsip_func_sub001(0x03420005U);
        r_rsip_func_sub001(0x0002000dU);

        WR1_PROG(REG_1600H, 0x000034e0U);

        r_rsip_func_sub003(0x800103a0U, 0x000000e3U);

        static const uint32_t Param_pe3_func101_007[] =
        {
            BSWAP_32BIG_C(0x4cf2df9bU), BSWAP_32BIG_C(0x940f65b0U), BSWAP_32BIG_C(0xd0e669faU), BSWAP_32BIG_C(
                0x5852a67bU),
        };
        r_rsip_func101(Param_pe3_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1600H, 0x01799093U);

        r_rsip_func_sub003(0x800103a0U, 0x000000e3U);

        static const uint32_t Param_pe3_func101_008[] =
        {
            BSWAP_32BIG_C(0x326fc89eU), BSWAP_32BIG_C(0xe057a14eU), BSWAP_32BIG_C(0x06940d24U), BSWAP_32BIG_C(
                0x9b9c4bfcU),
        };
        r_rsip_func101(Param_pe3_func101_008);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        WR1_PROG(REG_1600H, 0x000008e7U);

        WR1_PROG(REG_1600H, 0x000008a5U);

        for (iLoop = 0U; iLoop < S_RAM[0]; )
        {
            static const uint32_t Param_pe3_func100_004[] =
            {
                BSWAP_32BIG_C(0x6393feb6U), BSWAP_32BIG_C(0xc2f2d86dU), BSWAP_32BIG_C(0xfac11f66U), BSWAP_32BIG_C(
                    0x173607f8U),
            };
            r_rsip_func100(Param_pe3_func100_004);
            r_rsip_func_sub027(0x40000000U, 0xe7008d05U, 0x81840005U);
            r_rsip_func_sub001(0x00890011U);

            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30, 1);
            RD4_ADDR(REG_1420H, &OutData_EncMsg[1 + iLoop]);

            r_rsip_func_sub021(0x0000a4a0U, 0x00000010U, 0x0000a4e0U, 0x00000004U);

            static const uint32_t Param_pe3_func101_009[] =
            {
                BSWAP_32BIG_C(0x7c97ad8fU), BSWAP_32BIG_C(0x35987e49U), BSWAP_32BIG_C(0x2e3707edU), BSWAP_32BIG_C(
                    0x34872db6U),
            };
            r_rsip_func101(Param_pe3_func101_009);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub011(0x380008c7U);

        static const uint32_t Param_pe3_func100_005[] =
        {
            BSWAP_32BIG_C(0xb060c049U), BSWAP_32BIG_C(0xa32490c7U), BSWAP_32BIG_C(0x565f4714U), BSWAP_32BIG_C(
                0xb9637c90U),
        };
        r_rsip_func100(Param_pe3_func100_005);
        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_func_sub001(0x00820011U);

        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30, 1);
        RD4_ADDR(REG_1420H, &OutData_EncMsg[1 + iLoop]);

        static const uint32_t Param_pe3_func100_006[] =
        {
            BSWAP_32BIG_C(0x9f1e770bU), BSWAP_32BIG_C(0x09bde06fU), BSWAP_32BIG_C(0x27db0297U), BSWAP_32BIG_C(
                0xdff480acU),
        };
        r_rsip_func100(Param_pe3_func100_006);
        r_rsip_func_sub016(0x81010000U, 0x00005006U);
        RD1_ADDR(REG_1420H, &OutData_EncMsg[0]);

        static const uint32_t Param_pe3_func102_002[] =
        {
            BSWAP_32BIG_C(0xaa28efb0U), BSWAP_32BIG_C(0x392d3709U), BSWAP_32BIG_C(0xde45a6d2U), BSWAP_32BIG_C(
                0xa37cf0e3U),
        };
        r_rsip_func102(Param_pe3_func102_002);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_PASS;
    }
}
