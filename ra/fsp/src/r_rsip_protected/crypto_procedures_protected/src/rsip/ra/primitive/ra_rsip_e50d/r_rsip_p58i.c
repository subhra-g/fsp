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

rsip_ret_t r_rsip_p58i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00580001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2400H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    static const uint32_t Param_p58i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb26fddd0U), BSWAP_32BIG_C(0xb0887826U), BSWAP_32BIG_C(0xa30ac192U), BSWAP_32BIG_C(0xdae37ab6U),
    };
    r_rsip_func100(Param_p58i_func100_001);
    r_rsip_func_sub021(0x3420a880U, 0x00000004U, 0x2000b480U, 0x00000003U);

    r_rsip_func_sub014(0x00007c04U, 0x00600000U);

    if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002cU);

        WR1_PROG(REG_2404H, 0x00000001U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000024U);

        static const uint32_t Param_p58i_func101_001[] =
        {
            BSWAP_32BIG_C(0x48a10669U), BSWAP_32BIG_C(0xbb1116dbU), BSWAP_32BIG_C(0x4f94007cU), BSWAP_32BIG_C(
                0xcd9d8e62U),
        };
        r_rsip_func101(Param_p58i_func101_001);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002dU);

        WR1_PROG(REG_2404H, 0x00000011U);

        r_rsip_func_sub021(0x0000b460U, 0x00000008U, 0x0000b420U, 0x00000022U);

        static const uint32_t Param_p58i_func101_002[] =
        {
            BSWAP_32BIG_C(0xd687e7c4U), BSWAP_32BIG_C(0x24c271b0U), BSWAP_32BIG_C(0xf172507aU), BSWAP_32BIG_C(
                0x059cb1dfU),
        };
        r_rsip_func101(Param_p58i_func101_002);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002eU);

        WR1_PROG(REG_2404H, 0x00000021U);

        r_rsip_func_sub021(0x0000b460U, 0x0000000cU, 0x0000b420U, 0x0000001aU);

        static const uint32_t Param_p58i_func101_003[] =
        {
            BSWAP_32BIG_C(0x33c9cdc5U), BSWAP_32BIG_C(0x3f7aa702U), BSWAP_32BIG_C(0xc0a53f8cU), BSWAP_32BIG_C(
                0x0fa8990bU),
        };
        r_rsip_func101(Param_p58i_func101_003);
    }
    else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1600H, 0x0000002fU);

        WR1_PROG(REG_2404H, 0x00000031U);

        r_rsip_func_sub021(0x0000b460U, 0x00000010U, 0x0000b420U, 0x00000012U);

        static const uint32_t Param_p58i_func101_004[] =
        {
            BSWAP_32BIG_C(0x38db19cbU), BSWAP_32BIG_C(0x2630b7fdU), BSWAP_32BIG_C(0xc86bf84aU), BSWAP_32BIG_C(
                0xf032dcabU),
        };
        r_rsip_func101(Param_p58i_func101_004);
    }

    WR1_PROG(REG_2408H, 0x00000003U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00005801U);

    static const uint32_t Param_p58i_func101_005[] =
    {
        BSWAP_32BIG_C(0xb28dcd28U), BSWAP_32BIG_C(0xcd052555U), BSWAP_32BIG_C(0xf4ee1132U), BSWAP_32BIG_C(0x8af1d5a6U),
    };
    r_rsip_func101(Param_p58i_func101_005);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034e5U);

    r_rsip_func_sub003(0x800103a0U, 0x00005801U);

    static const uint32_t Param_p58i_func101_006[] =
    {
        BSWAP_32BIG_C(0x2e457c4eU), BSWAP_32BIG_C(0x6aa419faU), BSWAP_32BIG_C(0x7288facfU), BSWAP_32BIG_C(0xc24bca9eU),
    };
    r_rsip_func101(Param_p58i_func101_006);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008e7U);

    for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

        r_rsip_func_sub001(0x01820011U);

        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1600H, 0x00000004U);

        static const uint32_t Param_p58i_func101_007[] =
        {
            BSWAP_32BIG_C(0x29b00e12U), BSWAP_32BIG_C(0xfdc25869U), BSWAP_32BIG_C(0x2104db36U), BSWAP_32BIG_C(
                0xc2f9602fU),
        };
        r_rsip_func101(Param_p58i_func101_007);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func_sub011(0x380008e3U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p58i_func100_002[] =
    {
        BSWAP_32BIG_C(0xe78182b2U), BSWAP_32BIG_C(0x91f9ae27U), BSWAP_32BIG_C(0x2ab50f19U), BSWAP_32BIG_C(0x74d0b194U),
    };
    r_rsip_func100(Param_p58i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p58i_func102_001[] =
        {
            BSWAP_32BIG_C(0xc6ae1feeU), BSWAP_32BIG_C(0x51502115U), BSWAP_32BIG_C(0x19cb16d9U), BSWAP_32BIG_C(
                0xd3b9f295U),
        };
        r_rsip_func102(Param_p58i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p58i_func100_003[] =
        {
            BSWAP_32BIG_C(0x63c6f18eU), BSWAP_32BIG_C(0x717e1e25U), BSWAP_32BIG_C(0xfc888e08U), BSWAP_32BIG_C(
                0xb5a28d15U),
        };
        r_rsip_func100(Param_p58i_func100_003);
        r_rsip_func_sub016(0x81010020U, 0x00005006U);
        RD1_ADDR(REG_1420H, &S_RAM[0]);
        S_RAM[0] = bswap_32big(S_RAM[0]);

        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2414H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2410H, 0x00000080U);

            WR1_PROG(REG_240CH, 0x00000001U);

            WAIT_STS(REG_2440H, 8, 0);

            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2414H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2410H, 0x00000000U);

            WR1_PROG(REG_240CH, 0x00000100U);

            static const uint32_t Param_p58i_func101_008[] =
            {
                BSWAP_32BIG_C(0x013c0dadU), BSWAP_32BIG_C(0x3351912fU), BSWAP_32BIG_C(0xc9a5a896U), BSWAP_32BIG_C(
                    0x20c3b842U),
            };
            r_rsip_func101(Param_p58i_func101_008);
        }
        else
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2414H, InData_MsgLen[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_PROG(REG_2410H, InData_MsgLen[1]);

            WR1_PROG(REG_240CH, 0x00000001U);

            static const uint32_t Param_p58i_func101_009[] =
            {
                BSWAP_32BIG_C(0xcbd7e70bU), BSWAP_32BIG_C(0xcf531978U), BSWAP_32BIG_C(0xc15ec3dcU), BSWAP_32BIG_C(
                    0x4f29290fU),
            };
            r_rsip_func101(Param_p58i_func101_009);
        }

        return RSIP_RET_PASS;
    }
}
