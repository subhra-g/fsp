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

rsip_ret_t r_rsip_p40 (const uint32_t InData_LC[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00400001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    r_rsip_func_sub016(0x0000b420U, 0x00000009U, 0x34202801U);
    WR1_PROG(REG_0094H, 0x20003401U);

    WR1_PROG(REG_0094H, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00602000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (InData_LC[0] == 0x00000000U)
    {
        WR1_PROG(REG_0040H, 0x00b00000U);

        static const uint32_t Param_p40_func101_001[] =
        {
            BSWAP_32BIG_C(0x18a76540U), BSWAP_32BIG_C(0x1efe0190U), BSWAP_32BIG_C(0x45f830b4U), BSWAP_32BIG_C(
                0xe49d1eacU),
        };
        r_rsip_func101(Param_p40_func101_001);
    }
    else if (InData_LC[0] == 0x00000001U)
    {
        WR1_PROG(REG_0040H, 0x00b10000U);

        static const uint32_t Param_p40_func101_002[] =
        {
            BSWAP_32BIG_C(0x43aff45cU), BSWAP_32BIG_C(0x4fbbf1c7U), BSWAP_32BIG_C(0xf5063a7cU), BSWAP_32BIG_C(
                0xd3de6c3fU),
        };
        r_rsip_func101(Param_p40_func101_002);
    }
    else if (InData_LC[0] == 0x00000002U)
    {
        WR1_PROG(REG_0040H, 0x00b20000U);

        static const uint32_t Param_p40_func101_003[] =
        {
            BSWAP_32BIG_C(0xcd4465dfU), BSWAP_32BIG_C(0xd248e542U), BSWAP_32BIG_C(0x0f2b75baU), BSWAP_32BIG_C(
                0x77477e00U),
        };
        r_rsip_func101(Param_p40_func101_003);
    }
    else if (InData_LC[0] == 0x00000003U)
    {
        WR1_PROG(REG_0040H, 0x00b30000U);

        static const uint32_t Param_p40_func101_004[] =
        {
            BSWAP_32BIG_C(0xf0335eccU), BSWAP_32BIG_C(0x3871b7d5U), BSWAP_32BIG_C(0x56fd5f61U), BSWAP_32BIG_C(
                0x02d083dfU),
        };
        r_rsip_func101(Param_p40_func101_004);
    }
    else if (InData_LC[0] == 0x00000004U)
    {
        WR1_PROG(REG_0040H, 0x00b40000U);

        static const uint32_t Param_p40_func101_005[] =
        {
            BSWAP_32BIG_C(0xd4ff22e8U), BSWAP_32BIG_C(0x9a8992d7U), BSWAP_32BIG_C(0x044482b8U), BSWAP_32BIG_C(
                0x5fb3568dU),
        };
        r_rsip_func101(Param_p40_func101_005);
    }
    else if (InData_LC[0] == 0x00000005U)
    {
        WR1_PROG(REG_0040H, 0x00b50000U);

        static const uint32_t Param_p40_func101_006[] =
        {
            BSWAP_32BIG_C(0xdc69b8e1U), BSWAP_32BIG_C(0xc42ca9a4U), BSWAP_32BIG_C(0x5ccdbe97U), BSWAP_32BIG_C(
                0x79a740d6U),
        };
        r_rsip_func101(Param_p40_func101_006);
    }
    else if (InData_LC[0] == 0x00000006U)
    {
        WR1_PROG(REG_0040H, 0x00b60000U);

        static const uint32_t Param_p40_func101_007[] =
        {
            BSWAP_32BIG_C(0x84af7869U), BSWAP_32BIG_C(0xb7d37084U), BSWAP_32BIG_C(0x6e1a6e29U), BSWAP_32BIG_C(
                0x9856e438U),
        };
        r_rsip_func101(Param_p40_func101_007);
    }
    else if (InData_LC[0] == 0x00000007U)
    {
        WR1_PROG(REG_0040H, 0x00b70000U);

        static const uint32_t Param_p40_func101_008[] =
        {
            BSWAP_32BIG_C(0x9d0328c4U), BSWAP_32BIG_C(0xfb18f859U), BSWAP_32BIG_C(0xb73edfbfU), BSWAP_32BIG_C(
                0xca0b6303U),
        };
        r_rsip_func101(Param_p40_func101_008);
    }
    else if (InData_LC[0] == 0x00000008U)
    {
        WR1_PROG(REG_0040H, 0x00b80000U);

        static const uint32_t Param_p40_func101_009[] =
        {
            BSWAP_32BIG_C(0xc88ac57fU), BSWAP_32BIG_C(0x139c3084U), BSWAP_32BIG_C(0xbc8fd1a7U), BSWAP_32BIG_C(
                0x62760011U),
        };
        r_rsip_func101(Param_p40_func101_009);
    }
    else
    {
        WR1_PROG(REG_0094H, 0x38000c00U);
        WR1_PROG(REG_009CH, 0x00000080U);
        WR1_PROG(REG_0040H, 0x00A60000U);

        static const uint32_t Param_p40_func101_010[] =
        {
            BSWAP_32BIG_C(0x5bc658fdU), BSWAP_32BIG_C(0xc358f8a7U), BSWAP_32BIG_C(0xdcee7e82U), BSWAP_32BIG_C(
                0x724ff081U),
        };
        r_rsip_func101(Param_p40_func101_010);
    }

    static const uint32_t Param_p40_func100_001[] =
    {
        BSWAP_32BIG_C(0x9cc10949U), BSWAP_32BIG_C(0x18f1d566U), BSWAP_32BIG_C(0xfea8279cU), BSWAP_32BIG_C(0xa6fc53adU),
    };
    r_rsip_func100(Param_p40_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p40_func102_001[] =
        {
            BSWAP_32BIG_C(0x5e528cbbU), BSWAP_32BIG_C(0x3d49fc22U), BSWAP_32BIG_C(0xccd0f740U), BSWAP_32BIG_C(
                0x156b69ffU),
        };
        r_rsip_func102(Param_p40_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub002(0x800100e0U, 0x00000040U);

        static const uint32_t Param_p40_func101_011[] =
        {
            BSWAP_32BIG_C(0xa7bf41d7U), BSWAP_32BIG_C(0xc69fac6cU), BSWAP_32BIG_C(0xe65f5b28U), BSWAP_32BIG_C(
                0xfd8f6cc7U),
        };
        r_rsip_func101(Param_p40_func101_011);
        r_rsip_func040();

        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xf7009d05U);
        WR1_PROG(REG_00D8H, 0x20000000U);
        WR1_PROG(REG_0000H, 0x00480011U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0xf7008d05U);
        WR1_PROG(REG_00D8H, 0x20000010U);
        WR1_PROG(REG_0000H, 0x00480011U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        WR1_PROG(REG_00A0H, 0x00010000U);

        r_rsip_func_sub004(0x00001498U, 0x00c10021U);

        r_rsip_func_sub004(0x00000492U, 0x00c00005U);
        r_rsip_func_sub003(0x81010000U, 0x00c90005U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0x07008d05U);
        WR1_PROG(REG_00D8H, 0x20000020U);
        WR1_PROG(REG_0000H, 0x00480011U);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);
        r_rsip_func_sub006(0x8c100005U, 0x00410011U);

        static const uint32_t Param_p40_func100_002[] =
        {
            BSWAP_32BIG_C(0x21bdf056U), BSWAP_32BIG_C(0x9377682aU), BSWAP_32BIG_C(0xf879e106U), BSWAP_32BIG_C(
                0x1a792e23U),
        };
        r_rsip_func100(Param_p40_func100_002);
        WR1_PROG(REG_00D0H, 0x4a470044U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        WR1_PROG(REG_00D0H, 0x0e4704c4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x0152db38U));

        WR1_PROG(REG_00D0H, 0x4a040044U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        WR1_PROG(REG_00D0H, 0x0e040504U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x01f7370eU));

        r_rsip_func_sub004(0x00000493U, 0x00c10009U);

        r_rsip_func_sub004(0x00000494U, 0x00c10009U);

        WR1_PROG(REG_0078H, 0x00000202U);

        static const uint32_t Param_p40_func102_002[] =
        {
            BSWAP_32BIG_C(0xb9a20652U), BSWAP_32BIG_C(0xdc55b7ceU), BSWAP_32BIG_C(0xfe4e13c7U), BSWAP_32BIG_C(
                0x645b9504U),
        };
        r_rsip_func102(Param_p40_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
