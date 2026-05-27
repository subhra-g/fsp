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

rsip_ret_t r_rsip_p50i (const uint32_t InData_Cmd[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[])
{
    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00500001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3000a880U, 0x00000004U, 0x00010020U, 0x0000b480U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1600H, 0x00000080U);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x00005001U);

    static const uint32_t Param_p50i_func101_001[] =
    {
        BSWAP_32BIG_C(0x07d48aa4U), BSWAP_32BIG_C(0xfce58dc0U), BSWAP_32BIG_C(0xe6eb1757U), BSWAP_32BIG_C(0x7af98fe1U),
    };
    r_rsip_func101(Param_p50i_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1600H, 0x00000007U);

    r_rsip_func_sub003(0x800103a0U, 0x00005001U);

    static const uint32_t Param_p50i_func101_002[] =
    {
        BSWAP_32BIG_C(0x09ef5af8U), BSWAP_32BIG_C(0x33632767U), BSWAP_32BIG_C(0x0037a094U), BSWAP_32BIG_C(0x2bc79f18U),
    };
    r_rsip_func101(Param_p50i_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p50i_func100_001[] =
    {
        BSWAP_32BIG_C(0x2893cb10U), BSWAP_32BIG_C(0xa00b4d81U), BSWAP_32BIG_C(0xce253840U), BSWAP_32BIG_C(0xa539a52cU),
    };
    r_rsip_func100(Param_p50i_func100_001);
    r_rsip_func_sub008(0x000007c2U, 0x40000100U, 0xf7009d07U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WAIT_STS(REG_1444H, 31, 1);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[5]);

    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_func_sub001(0x00420011U);

    static const uint32_t Param_p50i_func100_002[] =
    {
        BSWAP_32BIG_C(0x5daf2d71U), BSWAP_32BIG_C(0x82aeec58U), BSWAP_32BIG_C(0x90161142U), BSWAP_32BIG_C(0x712ec473U),
    };
    r_rsip_func100(Param_p50i_func100_002);
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_func_sub001(0x00420011U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_KeyIndex[9]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_p50i_func100_003[] =
    {
        BSWAP_32BIG_C(0xeac6d05aU), BSWAP_32BIG_C(0x9194b36cU), BSWAP_32BIG_C(0x2326e45bU), BSWAP_32BIG_C(0x409dd77bU),
    };
    r_rsip_func100(Param_p50i_func100_003);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p50i_func102_001[] =
        {
            BSWAP_32BIG_C(0xd3eb92e7U), BSWAP_32BIG_C(0x35113d8aU), BSWAP_32BIG_C(0xe3a20c4eU), BSWAP_32BIG_C(
                0xfcd563aaU),
        };
        r_rsip_func102(Param_p50i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        static const uint32_t Param_p50i_func100_004[] =
        {
            BSWAP_32BIG_C(0xd088896bU), BSWAP_32BIG_C(0x2a0ec2b9U), BSWAP_32BIG_C(0x2b6c0529U), BSWAP_32BIG_C(
                0xeca5cbcbU),
        };
        r_rsip_func100(Param_p50i_func100_004);
        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            static const uint32_t Param_p50i_func101_003[] =
            {
                BSWAP_32BIG_C(0xe8554663U), BSWAP_32BIG_C(0x8ba5263cU), BSWAP_32BIG_C(0xd5fa24acU), BSWAP_32BIG_C(
                    0x3f225584U),
            };
            r_rsip_func101(Param_p50i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            static const uint32_t Param_p50i_func101_004[] =
            {
                BSWAP_32BIG_C(0xaf0dcb42U), BSWAP_32BIG_C(0x4360d11eU), BSWAP_32BIG_C(0xcb02ae2bU), BSWAP_32BIG_C(
                    0x1a49073aU),
            };
            r_rsip_func101(Param_p50i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_IVType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            static const uint32_t Param_p50i_func100_005[] =
            {
                BSWAP_32BIG_C(0x7006b5ddU), BSWAP_32BIG_C(0x9c1a1bc3U), BSWAP_32BIG_C(0xb542f271U), BSWAP_32BIG_C(
                    0xd83ae465U),
            };
            r_rsip_func100(Param_p50i_func100_005);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p50i_func101_005[] =
                {
                    BSWAP_32BIG_C(0x41086f0eU), BSWAP_32BIG_C(0xf7d4349aU), BSWAP_32BIG_C(0x11af1146U), BSWAP_32BIG_C(
                        0x1b6f3745U),
                };
                r_rsip_func101(Param_p50i_func101_005);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x800103a0U, 0x00005002U);

                static const uint32_t Param_p50i_func101_006[] =
                {
                    BSWAP_32BIG_C(0x6f20a273U), BSWAP_32BIG_C(0x0c425446U), BSWAP_32BIG_C(0x3de3e6ddU), BSWAP_32BIG_C(
                        0x89c113fdU),
                };
                r_rsip_func101(Param_p50i_func101_006);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0199e556U);

                r_rsip_func_sub003(0x800103a0U, 0x00005002U);

                static const uint32_t Param_p50i_func101_007[] =
                {
                    BSWAP_32BIG_C(0xba8fb78eU), BSWAP_32BIG_C(0x9a191ccaU), BSWAP_32BIG_C(0x9bcb575fU), BSWAP_32BIG_C(
                        0xfd5e6bfeU),
                };
                r_rsip_func101(Param_p50i_func101_007);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p50i_func100_006[] =
                {
                    BSWAP_32BIG_C(0x4923ba69U), BSWAP_32BIG_C(0x5185aa2fU), BSWAP_32BIG_C(0x934832f8U), BSWAP_32BIG_C(
                        0x4c8bfdc0U),
                };
                r_rsip_func100(Param_p50i_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p50i_func102_002[] =
                    {
                        BSWAP_32BIG_C(0x1b883993U), BSWAP_32BIG_C(0x53f0c711U), BSWAP_32BIG_C(0x4c536dc7U),
                        BSWAP_32BIG_C(0xfa4c45fcU),
                    };
                    r_rsip_func102(Param_p50i_func102_002);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p50i_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x38b5a76fU), BSWAP_32BIG_C(0xda0f55b9U), BSWAP_32BIG_C(0xfa38a034U),
                        BSWAP_32BIG_C(0x35e70887U),
                    };
                    r_rsip_func101(Param_p50i_func101_008);
                }
            }
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_IVType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            static const uint32_t Param_p50i_func100_007[] =
            {
                BSWAP_32BIG_C(0x9e03769bU), BSWAP_32BIG_C(0x140508ccU), BSWAP_32BIG_C(0x5da32492U), BSWAP_32BIG_C(
                    0x91ff19f5U),
            };
            r_rsip_func100(Param_p50i_func100_007);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub020(0x000003c1U, 0x08000045U);
                WR4_ADDR(REG_1420H, &InData_IV[0]);

                static const uint32_t Param_p50i_func101_009[] =
                {
                    BSWAP_32BIG_C(0xd438e58aU), BSWAP_32BIG_C(0x0dfa4c1bU), BSWAP_32BIG_C(0x6a0b1a48U), BSWAP_32BIG_C(
                        0x9f6f52a5U),
                };
                r_rsip_func101(Param_p50i_func101_009);
            }
            else
            {
                r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                WR1_PROG(REG_1420H, InData_IV[0]);
                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub003(0x800103a0U, 0x00005003U);

                static const uint32_t Param_p50i_func101_010[] =
                {
                    BSWAP_32BIG_C(0x4183ec0fU), BSWAP_32BIG_C(0x0a5bbf3cU), BSWAP_32BIG_C(0xfbc03641U), BSWAP_32BIG_C(
                        0x65053724U),
                };
                r_rsip_func101(Param_p50i_func101_010);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1600H, 0x0199e556U);

                r_rsip_func_sub003(0x800103a0U, 0x00005003U);

                static const uint32_t Param_p50i_func101_011[] =
                {
                    BSWAP_32BIG_C(0x7f194fd5U), BSWAP_32BIG_C(0x0628b6d0U), BSWAP_32BIG_C(0x3e117e33U), BSWAP_32BIG_C(
                        0xfddbf996U),
                };
                r_rsip_func101(Param_p50i_func101_011);
                r_rsip_func044();

                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7009d05U);
                WR4_ADDR(REG_1420H, &InData_IV[1]);

                WR1_PROG(REG_1824H, 0x08000045U);
                r_rsip_func_sub001(0x00420011U);
                r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                WR4_ADDR(REG_1420H, &InData_IV[5]);

                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_func_sub001(0x00820011U);

                static const uint32_t Param_p50i_func100_008[] =
                {
                    BSWAP_32BIG_C(0xca98a177U), BSWAP_32BIG_C(0x14b87173U), BSWAP_32BIG_C(0xe9362257U), BSWAP_32BIG_C(
                        0xf2079ac5U),
                };
                r_rsip_func100(Param_p50i_func100_008);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_p50i_func102_003[] =
                    {
                        BSWAP_32BIG_C(0xa4f0386bU), BSWAP_32BIG_C(0x2a2ede76U), BSWAP_32BIG_C(0xe546fa79U),
                        BSWAP_32BIG_C(0x6b0525bdU),
                    };
                    r_rsip_func102(Param_p50i_func102_003);
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    static const uint32_t Param_p50i_func101_012[] =
                    {
                        BSWAP_32BIG_C(0x4ec19d1fU), BSWAP_32BIG_C(0xba63fed0U), BSWAP_32BIG_C(0xd4c011d2U),
                        BSWAP_32BIG_C(0x503718a8U),
                    };
                    r_rsip_func101(Param_p50i_func101_012);
                }
            }
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            r_rsip_func_sub020(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_1420H, &InData_IV[0]);

            static const uint32_t Param_p50i_func101_013[] =
            {
                BSWAP_32BIG_C(0x294146cbU), BSWAP_32BIG_C(0x23e8a782U), BSWAP_32BIG_C(0x1b1bc745U), BSWAP_32BIG_C(
                    0x690a50f5U),
            };
            r_rsip_func101(Param_p50i_func101_013);
        }

        return RSIP_RET_PASS;
    }
}
