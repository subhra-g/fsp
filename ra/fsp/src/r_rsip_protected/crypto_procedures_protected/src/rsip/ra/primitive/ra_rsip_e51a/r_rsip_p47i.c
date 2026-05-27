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
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00470001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x3000a880U, 0x00000004U, 0x00010020U, 0x0000b480U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00000080U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004701U);

    static const uint32_t Param_p47i_func101_001[] =
    {
        BSWAP_32BIG_C(0xb9bcb3c4U), BSWAP_32BIG_C(0x6cb3d81dU), BSWAP_32BIG_C(0x9bb85f89U), BSWAP_32BIG_C(0x08237be6U),
    };
    r_rsip_func101(Param_p47i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000005U);

    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004701U);

    static const uint32_t Param_p47i_func101_002[] =
    {
        BSWAP_32BIG_C(0xcb83f1e8U), BSWAP_32BIG_C(0xb4f2c99eU), BSWAP_32BIG_C(0xbfda355aU), BSWAP_32BIG_C(0x7ce0213eU),
    };
    r_rsip_func101(Param_p47i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p47i_func100_001[] =
    {
        BSWAP_32BIG_C(0x8032119eU), BSWAP_32BIG_C(0x30108072U), BSWAP_32BIG_C(0xc7cc37fbU), BSWAP_32BIG_C(0x057cc8a1U),
    };
    r_rsip_func100(Param_p47i_func100_001);
    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p47i_func100_002[] =
    {
        BSWAP_32BIG_C(0xa6d18dccU), BSWAP_32BIG_C(0xfd16a4f3U), BSWAP_32BIG_C(0x80d6c565U), BSWAP_32BIG_C(0x4d75e0d7U),
    };
    r_rsip_func100(Param_p47i_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p47i_func102_001[] =
        {
            BSWAP_32BIG_C(0xf0d55e55U), BSWAP_32BIG_C(0x923fe84fU), BSWAP_32BIG_C(0x999fba4eU), BSWAP_32BIG_C(
                0xa60d7687U),
        };
        r_rsip_func102(Param_p47i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p47i_func100_003[] =
        {
            BSWAP_32BIG_C(0xcb5741cfU), BSWAP_32BIG_C(0x4cd2d194U), BSWAP_32BIG_C(0xb3ac9123U), BSWAP_32BIG_C(
                0x9784b967U),
        };
        r_rsip_func100(Param_p47i_func100_003);
        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            static const uint32_t Param_p47i_func101_003[] =
            {
                BSWAP_32BIG_C(0x56cecea4U), BSWAP_32BIG_C(0x47013527U), BSWAP_32BIG_C(0x67043742U), BSWAP_32BIG_C(
                    0xbf699041U),
            };
            r_rsip_func101(Param_p47i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p47i_func101_004[] =
            {
                BSWAP_32BIG_C(0x341a9cabU), BSWAP_32BIG_C(0x0c02b2d2U), BSWAP_32BIG_C(0x2c2ded9cU), BSWAP_32BIG_C(
                    0x98b3b5b1U),
            };
            r_rsip_func101(Param_p47i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_IVType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            static const uint32_t Param_p47i_func100_004[] =
            {
                BSWAP_32BIG_C(0x89692601U), BSWAP_32BIG_C(0x9bb1b334U), BSWAP_32BIG_C(0xe03e41eeU), BSWAP_32BIG_C(
                    0xed931863U),
            };
            r_rsip_func100(Param_p47i_func100_004);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p47i_func101_005[] =
                {
                    BSWAP_32BIG_C(0x9f76eb48U), BSWAP_32BIG_C(0xc5cf0284U), BSWAP_32BIG_C(0x5bc40a5eU), BSWAP_32BIG_C(
                        0xf18894b3U),
                };
                r_rsip_func101(Param_p47i_func101_005);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004702U);

                static const uint32_t Param_p47i_func101_006[] =
                {
                    BSWAP_32BIG_C(0xcfbd5020U), BSWAP_32BIG_C(0xe2f50848U), BSWAP_32BIG_C(0x369abb25U), BSWAP_32BIG_C(
                        0x8ca4bde3U),
                };
                r_rsip_func101(Param_p47i_func101_006);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0199e556U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004702U);

                static const uint32_t Param_p47i_func101_007[] =
                {
                    BSWAP_32BIG_C(0x994df9f9U), BSWAP_32BIG_C(0xcbab2babU), BSWAP_32BIG_C(0xfeea75c2U), BSWAP_32BIG_C(
                        0xcafe8272U),
                };
                r_rsip_func101(Param_p47i_func101_007);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p47i_func100_005[] =
                {
                    BSWAP_32BIG_C(0x60e95fddU), BSWAP_32BIG_C(0xd75c4ac2U), BSWAP_32BIG_C(0x31bceebaU), BSWAP_32BIG_C(
                        0xe062eb33U),
                };
                r_rsip_func100(Param_p47i_func100_005);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p47i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0x8f336eeeU), BSWAP_32BIG_C(0xb8b12e91U), BSWAP_32BIG_C(0xd26a0aa8U),
                        BSWAP_32BIG_C(0x4b7256b3U),
                    };
                    r_rsip_func102(Param_p47i_func102_002);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p47i_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x670937bfU), BSWAP_32BIG_C(0x7d1d1629U), BSWAP_32BIG_C(0xc7bba2d3U),
                        BSWAP_32BIG_C(0xbb2f23c8U),
                    };
                    r_rsip_func101(Param_p47i_func101_008);
                }
            }
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_IVType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            static const uint32_t Param_p47i_func100_006[] =
            {
                BSWAP_32BIG_C(0x034c5cd1U), BSWAP_32BIG_C(0x69fb51c6U), BSWAP_32BIG_C(0x1f3e4060U), BSWAP_32BIG_C(
                    0x1ea59594U),
            };
            r_rsip_func100(Param_p47i_func100_006);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p47i_func101_009[] =
                {
                    BSWAP_32BIG_C(0xde100001U), BSWAP_32BIG_C(0x97b13960U), BSWAP_32BIG_C(0x2e1e4b2aU), BSWAP_32BIG_C(
                        0x30aef1baU),
                };
                r_rsip_func101(Param_p47i_func101_009);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004703U);

                static const uint32_t Param_p47i_func101_010[] =
                {
                    BSWAP_32BIG_C(0x3e260afaU), BSWAP_32BIG_C(0xc6bdeed9U), BSWAP_32BIG_C(0x044fb040U), BSWAP_32BIG_C(
                        0x93d2e350U),
                };
                r_rsip_func101(Param_p47i_func101_010);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0199e556U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00004703U);

                static const uint32_t Param_p47i_func101_011[] =
                {
                    BSWAP_32BIG_C(0x2f2f51edU), BSWAP_32BIG_C(0x1d4c1a06U), BSWAP_32BIG_C(0x2c73bff7U), BSWAP_32BIG_C(
                        0x3ad3f7d3U),
                };
                r_rsip_func101(Param_p47i_func101_011);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p47i_func100_007[] =
                {
                    BSWAP_32BIG_C(0x64b4ee4aU), BSWAP_32BIG_C(0x8aa717beU), BSWAP_32BIG_C(0x39f54073U), BSWAP_32BIG_C(
                        0x797106dfU),
                };
                r_rsip_func100(Param_p47i_func100_007);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p47i_func102_003[] =
                    {
                        BSWAP_32BIG_C(0xe95b4b1bU), BSWAP_32BIG_C(0x745fc20dU), BSWAP_32BIG_C(0xdb42cac6U),
                        BSWAP_32BIG_C(0x919073b9U),
                    };
                    r_rsip_func102(Param_p47i_func102_003);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p47i_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x6a50ea03U), BSWAP_32BIG_C(0xa5ebc98bU), BSWAP_32BIG_C(0x92ca60a3U),
                        BSWAP_32BIG_C(0x1dfac49bU),
                    };
                    r_rsip_func101(Param_p47i_func101_012);
                }
            }
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p47i_func101_013[] =
            {
                BSWAP_32BIG_C(0x14c0f2b9U), BSWAP_32BIG_C(0xfce4e9c3U), BSWAP_32BIG_C(0x0788c085U), BSWAP_32BIG_C(
                    0x79d3b46dU),
            };
            r_rsip_func101(Param_p47i_func101_013);
        }
        else
        {
        }

        return RSIP_RET_PASS;
    }
}
