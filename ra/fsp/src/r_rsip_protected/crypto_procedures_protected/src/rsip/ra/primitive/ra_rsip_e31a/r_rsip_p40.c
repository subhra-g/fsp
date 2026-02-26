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

    r_rsip_func_sub022(0x0000b420U, 0x00000009U, 0x34202801U);
    WR1_PROG(REG_0094H, 0x20003401U);

    WR1_PROG(REG_0094H, 0x00007c00U);
    WR1_PROG(REG_0040H, 0x00602000U);

    if (InData_LC[0] == 0x00000000U)
    {
        WR1_PROG(REG_0040H, 0x00b00000U);

        static const uint32_t Param_p40_func101_001[] =
        {
            BSWAP_32BIG_C(0xbb935e20U), BSWAP_32BIG_C(0x6e50ce70U), BSWAP_32BIG_C(0xeb71e41bU), BSWAP_32BIG_C(
                0xf82de90fU),
        };
        r_rsip_func101(Param_p40_func101_001);
    }
    else if (InData_LC[0] == 0x00000001U)
    {
        WR1_PROG(REG_0040H, 0x00b10000U);

        static const uint32_t Param_p40_func101_002[] =
        {
            BSWAP_32BIG_C(0x3873d0d6U), BSWAP_32BIG_C(0x085b896cU), BSWAP_32BIG_C(0xc93e4029U), BSWAP_32BIG_C(
                0x91205c03U),
        };
        r_rsip_func101(Param_p40_func101_002);
    }
    else if (InData_LC[0] == 0x00000002U)
    {
        WR1_PROG(REG_0040H, 0x00b20000U);

        static const uint32_t Param_p40_func101_003[] =
        {
            BSWAP_32BIG_C(0xbc5dffdaU), BSWAP_32BIG_C(0x78d99371U), BSWAP_32BIG_C(0x1667199aU), BSWAP_32BIG_C(
                0xa82d2d9aU),
        };
        r_rsip_func101(Param_p40_func101_003);
    }
    else if (InData_LC[0] == 0x00000003U)
    {
        WR1_PROG(REG_0040H, 0x00b30000U);

        static const uint32_t Param_p40_func101_004[] =
        {
            BSWAP_32BIG_C(0x8d0740b2U), BSWAP_32BIG_C(0x858ef57bU), BSWAP_32BIG_C(0xd234878dU), BSWAP_32BIG_C(
                0x4bc3f558U),
        };
        r_rsip_func101(Param_p40_func101_004);
    }
    else if (InData_LC[0] == 0x00000004U)
    {
        WR1_PROG(REG_0040H, 0x00b40000U);

        static const uint32_t Param_p40_func101_005[] =
        {
            BSWAP_32BIG_C(0x2383cec4U), BSWAP_32BIG_C(0xc84ac230U), BSWAP_32BIG_C(0xf78b5fb0U), BSWAP_32BIG_C(
                0x848bb4b9U),
        };
        r_rsip_func101(Param_p40_func101_005);
    }
    else if (InData_LC[0] == 0x00000005U)
    {
        WR1_PROG(REG_0040H, 0x00b50000U);

        static const uint32_t Param_p40_func101_006[] =
        {
            BSWAP_32BIG_C(0x522fb782U), BSWAP_32BIG_C(0x62d73b91U), BSWAP_32BIG_C(0x95d8785aU), BSWAP_32BIG_C(
                0x038ec5d5U),
        };
        r_rsip_func101(Param_p40_func101_006);
    }
    else if (InData_LC[0] == 0x00000006U)
    {
        WR1_PROG(REG_0040H, 0x00b60000U);

        static const uint32_t Param_p40_func101_007[] =
        {
            BSWAP_32BIG_C(0x6b91ea31U), BSWAP_32BIG_C(0x9b60c730U), BSWAP_32BIG_C(0xa9b6d36cU), BSWAP_32BIG_C(
                0x125b7f76U),
        };
        r_rsip_func101(Param_p40_func101_007);
    }
    else if (InData_LC[0] == 0x00000007U)
    {
        WR1_PROG(REG_0040H, 0x00b70000U);

        static const uint32_t Param_p40_func101_008[] =
        {
            BSWAP_32BIG_C(0x8f307de7U), BSWAP_32BIG_C(0x791431c7U), BSWAP_32BIG_C(0x61410df8U), BSWAP_32BIG_C(
                0x388f2816U),
        };
        r_rsip_func101(Param_p40_func101_008);
    }
    else if (InData_LC[0] == 0x00000008U)
    {
        WR1_PROG(REG_0040H, 0x00b80000U);

        static const uint32_t Param_p40_func101_009[] =
        {
            BSWAP_32BIG_C(0xbffeeb94U), BSWAP_32BIG_C(0x3fb8bdfeU), BSWAP_32BIG_C(0x23eab46aU), BSWAP_32BIG_C(
                0x894936d8U),
        };
        r_rsip_func101(Param_p40_func101_009);
    }
    else
    {
        r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_p40_func101_010[] =
        {
            BSWAP_32BIG_C(0x1dc66a94U), BSWAP_32BIG_C(0x6957c711U), BSWAP_32BIG_C(0xa9f07efcU), BSWAP_32BIG_C(
                0xd39e6c68U),
        };
        r_rsip_func101(Param_p40_func101_010);
    }

    static const uint32_t Param_p40_func100_001[] =
    {
        BSWAP_32BIG_C(0xf3ed8513U), BSWAP_32BIG_C(0x2ac1dceeU), BSWAP_32BIG_C(0xcd8910cbU), BSWAP_32BIG_C(0xe79ba28aU),
    };
    r_rsip_func100(Param_p40_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p40_func102_001[] =
        {
            BSWAP_32BIG_C(0x62bba183U), BSWAP_32BIG_C(0xa32d1a03U), BSWAP_32BIG_C(0xa71a937dU), BSWAP_32BIG_C(
                0x634b23b3U),
        };
        r_rsip_func102(Param_p40_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00000040U, 0x00000000U);

        static const uint32_t Param_p40_func101_011[] =
        {
            BSWAP_32BIG_C(0x07a6f0adU), BSWAP_32BIG_C(0xfcd6e6d9U), BSWAP_32BIG_C(0x49137872U), BSWAP_32BIG_C(
                0x58751beeU),
        };
        r_rsip_func101(Param_p40_func101_011);
        r_rsip_func040();

        WR1_PROG(REG_00D4H, 0x40000100U);
        WR1_PROG(REG_00D0H, 0xf7009d05U);
        WR1_PROG(REG_00D8H, 0x20000000U);
        r_rsip_func_sub015(0x00480011U, 0x00001800U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0xf7008d05U);
        WR1_PROG(REG_00D8H, 0x20000010U);
        r_rsip_func_sub015(0x00480011U, 0x00001800U);

        WR1_PROG(REG_00A0H, 0x00010000U);

        r_rsip_func_sub009(0x000014b8U, 0x00c10021U, 0x00001800U);

        r_rsip_func_sub009(0x000004b2U, 0x00c00005U, 0x00001800U);
        r_rsip_func_sub012(0x81010000U, 0x00c90005U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        WR1_PROG(REG_00D0H, 0x07008d05U);
        WR1_PROG(REG_00D8H, 0x20000020U);
        r_rsip_func_sub015(0x00480011U, 0x00001800U);
        r_rsip_func_sub013(0x8c100005U, 0x00410011U);

        static const uint32_t Param_p40_func100_002[] =
        {
            BSWAP_32BIG_C(0x380fa304U), BSWAP_32BIG_C(0x0b35a1d2U), BSWAP_32BIG_C(0x62b4b939U), BSWAP_32BIG_C(
                0xd5f60a03U),
        };
        r_rsip_func100(Param_p40_func100_002);
        WR1_PROG(REG_00D0H, 0x4a470044U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        WR1_PROG(REG_00D0H, 0x0e4704c4U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x01417d25U));

        WR1_PROG(REG_00D0H, 0x4a040044U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        WR1_PROG(REG_00D0H, 0x0e040504U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x01ed9651U));

        r_rsip_func_sub009(0x000004b3U, 0x00c10009U, 0x00001800U);

        r_rsip_func_sub009(0x000004b4U, 0x00c10009U, 0x00001800U);

        WR1_PROG(REG_0078H, 0x00000222U);

        static const uint32_t Param_p40_func102_002[] =
        {
            BSWAP_32BIG_C(0xee238fedU), BSWAP_32BIG_C(0xbe5722e3U), BSWAP_32BIG_C(0x2af56f54U), BSWAP_32BIG_C(
                0xd5e1f3c3U),
        };
        r_rsip_func102(Param_p40_func102_002);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
}
