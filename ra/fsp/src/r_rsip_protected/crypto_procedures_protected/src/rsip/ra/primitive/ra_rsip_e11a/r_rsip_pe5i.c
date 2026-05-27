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

rsip_ret_t r_rsip_pe5i (const uint32_t InData_KeyType[], const uint32_t InData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    r_rsip_func_sub011(0x00e50001U, 0x000000c7U, 0x80010020U);
    WR1_PROG(REG_002CH, InData_KeyType[0]);
    r_rsip_func_sub012(0x38000c21U, 0x00260000U);

    static const uint32_t Param_pe5i_func100_001[] =
    {
        BSWAP_32BIG_C(0xf04cda47U), BSWAP_32BIG_C(0xf17bdc5aU), BSWAP_32BIG_C(0x761b7410U), BSWAP_32BIG_C(0x96a102ceU),
    };
    r_rsip_func100(Param_pe5i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x0000001bU);

        static const uint32_t Param_pe5i_sub100_001[] =
        {
            BSWAP_32BIG_C(0x0000e501U), BSWAP_32BIG_C(0xd413d91eU), BSWAP_32BIG_C(0xb6342abbU),
            BSWAP_32BIG_C(0xed6d3600U),
            BSWAP_32BIG_C(0xf624bdfcU), BSWAP_32BIG_C(0x0000e501U), BSWAP_32BIG_C(0xd117b21fU),
            BSWAP_32BIG_C(0xae664b64U),
            BSWAP_32BIG_C(0x0f153347U),
            BSWAP_32BIG_C(0x10a6ff54U), 0x00001404U,
        };
        r_rsip_func_sub100(InData_KeyIndex, Param_pe5i_sub100_001, RSIP_SEL_BIT_LENGTH_256);

        static const uint32_t Param_pe5i_func101_001[] =
        {
            BSWAP_32BIG_C(0xf3195d61U), BSWAP_32BIG_C(0x63408b23U), BSWAP_32BIG_C(0x7e195a1fU), BSWAP_32BIG_C(
                0x99cb05b8U),
        };
        r_rsip_func101(Param_pe5i_func101_001);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x0000b4a0U);
        WR1_PROG(REG_0094H, 0x01b41ce9U);

        static const uint32_t Param_pe5i_sub100_002[] =
        {
            BSWAP_32BIG_C(0x0000e502U), BSWAP_32BIG_C(0x718e26e8U), BSWAP_32BIG_C(0x08368549U),
            BSWAP_32BIG_C(0xcb646698U),
            BSWAP_32BIG_C(0xac03859eU), BSWAP_32BIG_C(0x0000e502U), BSWAP_32BIG_C(0x7ac6d611U),
            BSWAP_32BIG_C(0x27193249U),
            BSWAP_32BIG_C(0xd1fd99fcU),
            BSWAP_32BIG_C(0x478d0457U), 0x00001404U,
        };
        r_rsip_func_sub100(InData_KeyIndex, Param_pe5i_sub100_002, RSIP_SEL_BIT_LENGTH_512);

        static const uint32_t Param_pe5i_func101_002[] =
        {
            BSWAP_32BIG_C(0x220ff082U), BSWAP_32BIG_C(0x7557f02eU), BSWAP_32BIG_C(0xacae16d8U), BSWAP_32BIG_C(
                0xb154b704U),
        };
        r_rsip_func101(Param_pe5i_func101_002);
    }

    static const uint32_t Param_pe5i_func100_002[] =
    {
        BSWAP_32BIG_C(0x6ac004eeU), BSWAP_32BIG_C(0xe11cd3a9U), BSWAP_32BIG_C(0xb295f1b3U), BSWAP_32BIG_C(0x9c736117U),
    };
    r_rsip_func100(Param_pe5i_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5i_func102_001[] =
        {
            BSWAP_32BIG_C(0xb72737c2U), BSWAP_32BIG_C(0xae55dee6U), BSWAP_32BIG_C(0xfe921861U), BSWAP_32BIG_C(
                0x673d6aa2U),
        };
        r_rsip_func102(Param_pe5i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func004();

        WR1_PROG(REG_00F4H, 0x00000011U);

        WR1_PROG(REG_0094H, 0x38000c21U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00260000U);

        static const uint32_t Param_pe5i_func100_003[] =
        {
            BSWAP_32BIG_C(0x382ea248U), BSWAP_32BIG_C(0x3057620eU), BSWAP_32BIG_C(0x6361a7b3U), BSWAP_32BIG_C(
                0xde9656e6U),
        };
        r_rsip_func100(Param_pe5i_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func001();

            static const uint32_t Param_pe5i_func101_003[] =
            {
                BSWAP_32BIG_C(0xab6d6670U), BSWAP_32BIG_C(0x612c4546U), BSWAP_32BIG_C(0x39c5fe15U), BSWAP_32BIG_C(
                    0x0dee9feaU),
            };
            r_rsip_func101(Param_pe5i_func101_003);
        }
        else
        {
            WR1_PROG(REG_00D0H, 0x08000045U);
            r_rsip_func_sub004(0x00001804U, 0x00430011U);

            r_rsip_func_sub006(0x08000055U, 0x00430011U);

            WR1_PROG(REG_0000H, 0x01410021U);
            WR1_PROG(REG_0014H, 0x000007a1U);

            WR1_PROG(REG_00D0H, 0x0c000105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U));

            WR1_PROG(REG_00D0H, 0x0c100105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U));

            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);

            WR1_PROG(REG_00D0H, 0x08000045U);
            r_rsip_func_sub004(0x00001808U, 0x00430011U);

            r_rsip_func_sub006(0x08000055U, 0x00430011U);

            WR1_PROG(REG_0000H, 0x01410021U);
            WR1_PROG(REG_0014H, 0x000007a1U);

            WR1_PROG(REG_00D0H, 0x0c000105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U));

            WR1_PROG(REG_00D0H, 0x0c100105U);
            WAIT_STS(REG_0014H, 31, 1);
            WR4_PROG(REG_002CH,
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U),
                     bswap_32big(0x36363636U));

            WAIT_STS(REG_0004H, 30, 0);
            WR1_PROG(REG_0040H, 0x00001800U);

            static const uint32_t Param_pe5i_func101_004[] =
            {
                BSWAP_32BIG_C(0x1d31e258U), BSWAP_32BIG_C(0xb0a13d34U), BSWAP_32BIG_C(0x6a2ac6caU), BSWAP_32BIG_C(
                    0x77af20ccU),
            };
            r_rsip_func101(Param_pe5i_func101_004);
        }

        static const uint32_t Param_pe5i_func101_005[] =
        {
            BSWAP_32BIG_C(0x0b4eb894U), BSWAP_32BIG_C(0x43ccfa0eU), BSWAP_32BIG_C(0xd8c88f8cU), BSWAP_32BIG_C(
                0x8658fbf2U),
        };
        r_rsip_func101(Param_pe5i_func101_005);

        return RSIP_RET_PASS;
    }
}
