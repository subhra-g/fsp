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

rsip_ret_t r_rsip_p47i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00470001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    r_rsip_func_sub018(0x00000000U, 0x0000b4a0U, 0x00000005U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004701U, 0x00000000U);

    static const uint32_t Param_p47i_func101_001[] =
    {
        BSWAP_32BIG_C(0x722f5066U), BSWAP_32BIG_C(0x00843c82U), BSWAP_32BIG_C(0x2f5d9ed1U), BSWAP_32BIG_C(0x54ff5e39U),
    };
    r_rsip_func101(Param_p47i_func101_001);
    r_rsip_func440(InData_KeyIndex);

    static const uint32_t Param_p47i_func100_001[] =
    {
        BSWAP_32BIG_C(0xdb8bd860U), BSWAP_32BIG_C(0x2b613286U), BSWAP_32BIG_C(0x3c670360U), BSWAP_32BIG_C(0x4fc01d4dU),
    };
    r_rsip_func100(Param_p47i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p47i_func102_001[] =
        {
            BSWAP_32BIG_C(0x2405e15eU), BSWAP_32BIG_C(0x2bf57863U), BSWAP_32BIG_C(0x73a29c16U), BSWAP_32BIG_C(
                0xbbf6056eU),
        };
        r_rsip_func102(Param_p47i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_009CH, 0x80840000U);
        r_rsip_func_sub009(0x00000801U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub009(0x00000802U, 0x03430009U, 0x00001800U);

        r_rsip_func_sub010(0x3c00a880U, 0x00000002U, 0x00270000U);

        static const uint32_t Param_p47i_func100_002[] =
        {
            BSWAP_32BIG_C(0x8a9cf995U), BSWAP_32BIG_C(0x86f42795U), BSWAP_32BIG_C(0x52c46571U), BSWAP_32BIG_C(
                0x870687a6U),
        };
        r_rsip_func100(Param_p47i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x000008a5U);

            r_rsip_func_sub010(0x3c00a880U, 0x00000004U, 0x00A70000U);

            static const uint32_t Param_p47i_func100_003[] =
            {
                BSWAP_32BIG_C(0xde52627aU), BSWAP_32BIG_C(0x00f93636U), BSWAP_32BIG_C(0x0a56258bU), BSWAP_32BIG_C(
                    0xafdb528eU),
            };
            r_rsip_func100(Param_p47i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
                WR1_PROG(REG_002CH, InData_IVType[0]);
                WR1_PROG(REG_0024H, 0x00000000U);

                static const uint32_t Param_p47i_func101_002[] =
                {
                    BSWAP_32BIG_C(0x93bb54d2U), BSWAP_32BIG_C(0x3bc828a9U), BSWAP_32BIG_C(0x751ec07fU), BSWAP_32BIG_C(
                        0xe6ab5965U),
                };
                r_rsip_func101(Param_p47i_func101_002);
            }

            r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00270000U);

            static const uint32_t Param_p47i_func100_004[] =
            {
                BSWAP_32BIG_C(0x2a57ea16U), BSWAP_32BIG_C(0x2d53ec98U), BSWAP_32BIG_C(0x2525871bU), BSWAP_32BIG_C(
                    0x03391f45U),
            };
            r_rsip_func100(Param_p47i_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                r_rsip_func_sub019(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_002CH, &InData_IV[0]);

                static const uint32_t Param_p47i_func101_003[] =
                {
                    BSWAP_32BIG_C(0xbe199501U), BSWAP_32BIG_C(0xf08ab8f4U), BSWAP_32BIG_C(0x02ece9caU), BSWAP_32BIG_C(
                        0x172e7381U),
                };
                r_rsip_func101(Param_p47i_func101_003);
            }
            else
            {
                WR1_PROG(REG_0094H, 0x0000b4a0U);
                WR1_PROG(REG_0094H, 0x0199e556U);

                r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00004702U, 0x00000000U);

                static const uint32_t Param_p47i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x1669ae4eU), BSWAP_32BIG_C(0x8f26a5a4U), BSWAP_32BIG_C(0x4113a9e2U), BSWAP_32BIG_C(
                        0x0c412992U),
                };
                r_rsip_func101(Param_p47i_func101_004);
                r_rsip_func440(InData_IV);

                static const uint32_t Param_p47i_func100_005[] =
                {
                    BSWAP_32BIG_C(0x4f6dedf0U), BSWAP_32BIG_C(0x4af5e622U), BSWAP_32BIG_C(0xa3b7d412U), BSWAP_32BIG_C(
                        0xa0a5ffa5U),
                };
                r_rsip_func100(Param_p47i_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p47i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0xe058af49U), BSWAP_32BIG_C(0xc898725aU), BSWAP_32BIG_C(0x8b6e8a31U),
                        BSWAP_32BIG_C(0xe5fbc204U),
                    };
                    r_rsip_func102(Param_p47i_func102_002);
                    WR1_PROG(REG_006CH, 0x00000040U);
                    WAIT_STS(REG_0020H, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_00D0H, 0x08000045U);
                    r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                    r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                    static const uint32_t Param_p47i_func101_005[] =
                    {
                        BSWAP_32BIG_C(0xc53f9494U), BSWAP_32BIG_C(0x279cd20dU), BSWAP_32BIG_C(0x49d879deU),
                        BSWAP_32BIG_C(0x1212ac44U),
                    };
                    r_rsip_func101(Param_p47i_func101_005);
                }
            }
        }

        static const uint32_t Param_p47i_func100_006[] =
        {
            BSWAP_32BIG_C(0xa8c4c812U), BSWAP_32BIG_C(0xd8ca79f9U), BSWAP_32BIG_C(0x5d340b23U), BSWAP_32BIG_C(
                0x1ac250d3U),
        };
        r_rsip_func100(Param_p47i_func100_006);
        WR1_PROG(REG_0094H, 0x0000b400U);
        WR1_PROG(REG_0094H, 0x00000010U);

        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub006(0x81840000U, 0x00490011U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub022(0x0a000100U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub022(0x0a000108U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub022(0x0e000500U, 0x0c003080U, 0x2000b4e0U);
        r_rsip_func_sub022(0x09000908U, 0x0c00a880U, 0xfffffffcU);
        WR1_PROG(REG_0094H, 0x2000b4e0U);
        WR1_PROG(REG_0094H, 0x07000d00U);

        static const uint32_t Param_p47i_func101_006[] =
        {
            BSWAP_32BIG_C(0x517cf2dbU), BSWAP_32BIG_C(0xbd26b748U), BSWAP_32BIG_C(0x3172b529U), BSWAP_32BIG_C(
                0x230c22b0U),
        };
        r_rsip_func101(Param_p47i_func101_006);

        return RSIP_RET_PASS;
    }
}
