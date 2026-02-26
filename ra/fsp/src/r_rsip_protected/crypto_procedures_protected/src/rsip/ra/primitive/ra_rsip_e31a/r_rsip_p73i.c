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

rsip_ret_t r_rsip_p73i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00730001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_00F0H, 0x00000001U);

    r_rsip_func_sub014(0x000000c7U, 0x80010000U);
    WR1_PROG(REG_002CH, InData_HashType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x38000c00U, 0x00000080U, 0x00270000U);

    static const uint32_t Param_p73i_func100_001[] =
    {
        BSWAP_32BIG_C(0x909ac921U), BSWAP_32BIG_C(0x00d2d1beU), BSWAP_32BIG_C(0x8d6e21ceU), BSWAP_32BIG_C(0xce587e11U),
    };
    r_rsip_func100(Param_p73i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p73i_func102_001[] =
        {
            BSWAP_32BIG_C(0x5c57a08eU), BSWAP_32BIG_C(0x38aa694bU), BSWAP_32BIG_C(0xe7fc39bdU), BSWAP_32BIG_C(
                0x88f8e66eU),
        };
        r_rsip_func102(Param_p73i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p73i_func100_002[] =
        {
            BSWAP_32BIG_C(0x072e9c18U), BSWAP_32BIG_C(0xbf4fa3e0U), BSWAP_32BIG_C(0x83056207U), BSWAP_32BIG_C(
                0x1b9aa55bU),
        };
        r_rsip_func100(Param_p73i_func100_002);
        r_rsip_func_sub022(0x3420a800U, 0x00000007U, 0x2000b400U);
        WR1_PROG(REG_0094H, 0x00000006U);

        WR1_PROG(REG_0094H, 0x00007c00U);
        WR1_PROG(REG_0040H, 0x00600000U);

        if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_00F4H, 0x00000040U);

            static const uint32_t Param_p73i_func101_001[] =
            {
                BSWAP_32BIG_C(0x6e8d9c91U), BSWAP_32BIG_C(0x89404aa5U), BSWAP_32BIG_C(0xf542815eU), BSWAP_32BIG_C(
                    0x031cea6fU),
            };
            r_rsip_func101(Param_p73i_func101_001);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_00F4H, 0x00000050U);

            static const uint32_t Param_p73i_func101_002[] =
            {
                BSWAP_32BIG_C(0x33d53a44U), BSWAP_32BIG_C(0x57eee603U), BSWAP_32BIG_C(0xa5a162b5U), BSWAP_32BIG_C(
                    0x62cd5c1dU),
            };
            r_rsip_func101(Param_p73i_func101_002);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_00F4H, 0x00000080U);

            static const uint32_t Param_p73i_func101_003[] =
            {
                BSWAP_32BIG_C(0x15f05247U), BSWAP_32BIG_C(0xaef43d75U), BSWAP_32BIG_C(0x3e969f17U), BSWAP_32BIG_C(
                    0xe6198ae0U),
            };
            r_rsip_func101(Param_p73i_func101_003);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_00F4H, 0x00000090U);

            static const uint32_t Param_p73i_func101_004[] =
            {
                BSWAP_32BIG_C(0x98f7db5eU), BSWAP_32BIG_C(0x10ebd48dU), BSWAP_32BIG_C(0x225a04feU), BSWAP_32BIG_C(
                    0x8b6f9ed7U),
            };
            r_rsip_func101(Param_p73i_func101_004);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000005U)
        {
            WR1_PROG(REG_00F4H, 0x000000a0U);

            static const uint32_t Param_p73i_func101_005[] =
            {
                BSWAP_32BIG_C(0xdeda3998U), BSWAP_32BIG_C(0xf182bf88U), BSWAP_32BIG_C(0x744d8a32U), BSWAP_32BIG_C(
                    0xd90e9855U),
            };
            r_rsip_func101(Param_p73i_func101_005);
        }
        else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_00F4H, 0x000000b0U);

            static const uint32_t Param_p73i_func101_006[] =
            {
                BSWAP_32BIG_C(0x60a19657U), BSWAP_32BIG_C(0x305bcd22U), BSWAP_32BIG_C(0xfa4c989cU), BSWAP_32BIG_C(
                    0xcfb2fe76U),
            };
            r_rsip_func101(Param_p73i_func101_006);
        }

        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            WR1_PROG(REG_00FCH, 0x00000100U);

            static const uint32_t Param_p73i_func101_007[] =
            {
                BSWAP_32BIG_C(0x3b079f3eU), BSWAP_32BIG_C(0xb376ca65U), BSWAP_32BIG_C(0x823af9f0U), BSWAP_32BIG_C(
                    0xf3e46298U),
            };
            r_rsip_func101(Param_p73i_func101_007);
        }
        else
        {
            WR1_PROG(REG_0014H, 0x00000040U);
            WR1_PROG(REG_0104H, InData_MsgLen[0]);
            WR1_PROG(REG_0014H, 0x00000040U);
            WR1_PROG(REG_0100H, InData_MsgLen[1]);

            static const uint32_t Param_p73i_func101_008[] =
            {
                BSWAP_32BIG_C(0x37e554cbU), BSWAP_32BIG_C(0x9153eb17U), BSWAP_32BIG_C(0x9402a051U), BSWAP_32BIG_C(
                    0x3d667edeU),
            };
            r_rsip_func101(Param_p73i_func101_008);
        }

        return RSIP_RET_PASS;
    }
}
