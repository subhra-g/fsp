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

rsip_ret_t r_rsip_p6f (const uint32_t InData_LC[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x006f0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    WR1_PROG(REG_00A0H, 0x00010000U);

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x0000001cU);

    WR1_PROG(REG_00B0H, 0x00000892U);
    r_rsip_func_sub003(0x80810006U, 0x00030005U);
    WR1_PROG(REG_0000H, 0x03430005U);
    WAIT_STS(REG_0004H, 30, 0);
    WR1_PROG(REG_0040H, 0x00001800U);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub016(0x00000842U, 0x3420a800U, 0x00000009U);
    r_rsip_func_sub016(0x1000b440U, 0x3CC000A0U, 0x000034a4U);

    r_rsip_func_sub016(0x38008880U, 0x00000023U, 0x1000b480U);
    r_rsip_func_sub016(0x00000005U, 0x38008880U, 0x00000022U);
    WR1_PROG(REG_0094H, 0x1000b480U);
    WR1_PROG(REG_0094H, 0x00000005U);

    r_rsip_func056();

    static const uint32_t Param_p6f_func100_001[] =
    {
        BSWAP_32BIG_C(0x7ec8e296U), BSWAP_32BIG_C(0x98f2f934U), BSWAP_32BIG_C(0x2e0dcff5U), BSWAP_32BIG_C(0x887c4c86U),
    };
    r_rsip_func100(Param_p6f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p6f_func102_001[] =
        {
            BSWAP_32BIG_C(0xe7acc52fU), BSWAP_32BIG_C(0xc0a7bd00U), BSWAP_32BIG_C(0xcd3e7067U), BSWAP_32BIG_C(
                0x1426e57aU),
        };
        r_rsip_func102(Param_p6f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00003485U);

        r_rsip_func_sub005(0x000001a1U, 0x07330c04U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x07330d04U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        r_rsip_func_sub003(0x80010000U, 0x03410005U);
        WR1_PROG(REG_0000H, 0x0001000dU);
        WAIT_STS(REG_0004H, 30, 0);
        WR1_PROG(REG_0040H, 0x00001800U);

        r_rsip_func_sub005(0x000001a1U, 0x07330d04U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x06330104U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        r_rsip_func_sub004(0x00001404U, 0x00c10021U);
        WR1_PROG(REG_0014H, 0x000000c7U);
        WR1_PROG(REG_009CH, 0x800100c0U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, S_INST2[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub002(0x800100e0U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_001[] =
        {
            BSWAP_32BIG_C(0x434ec55dU), BSWAP_32BIG_C(0x5a204099U), BSWAP_32BIG_C(0xa5fae365U), BSWAP_32BIG_C(
                0x672ccb97U),
        };
        r_rsip_func101(Param_p6f_func101_001);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x0000b4c0U);
        WR1_PROG(REG_0094H, 0x000000ffU);

        r_rsip_func_sub002(0x800100e0U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_002[] =
        {
            BSWAP_32BIG_C(0xd959ecc1U), BSWAP_32BIG_C(0x92a3b73bU), BSWAP_32BIG_C(0xc39a69c7U), BSWAP_32BIG_C(
                0x3dc68e2aU),
        };
        r_rsip_func101(Param_p6f_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p6f_func100_002[] =
        {
            BSWAP_32BIG_C(0xb67ae076U), BSWAP_32BIG_C(0xa2302888U), BSWAP_32BIG_C(0xc2132e3fU), BSWAP_32BIG_C(
                0xa88beb00U),
        };
        r_rsip_func100(Param_p6f_func100_002);
        r_rsip_func_sub008(0x000007c1U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 1]);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 5]);

        r_rsip_func_sub006(0x080000a5U, 0x00410011U);

        static const uint32_t Param_p6f_func100_003[] =
        {
            BSWAP_32BIG_C(0x820c73e1U), BSWAP_32BIG_C(0x42ab1dcfU), BSWAP_32BIG_C(0xb53d6407U), BSWAP_32BIG_C(
                0xaad627d1U),
        };
        r_rsip_func100(Param_p6f_func100_003);
        r_rsip_func_sub006(0x080000b5U, 0x00410011U);

        r_rsip_func_sub008(0x000003c1U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 9]);

        r_rsip_func_sub006(0x8c100005U, 0x00410011U);

        r_rsip_func_sub002(0x800100e0U, 0x0000006fU);

        static const uint32_t Param_p6f_func101_003[] =
        {
            BSWAP_32BIG_C(0x5aa5724dU), BSWAP_32BIG_C(0x10cd729dU), BSWAP_32BIG_C(0xba3cc7acU), BSWAP_32BIG_C(
                0x32617d1fU),
        };
        r_rsip_func101(Param_p6f_func101_003);
        r_rsip_func157(InData_IV, InData_InstData, OutData_KeyIndex);

        static const uint32_t Param_p6f_func100_004[] =
        {
            BSWAP_32BIG_C(0xdca87a2dU), BSWAP_32BIG_C(0xb22b908bU), BSWAP_32BIG_C(0xc793f014U), BSWAP_32BIG_C(
                0x06d24e3bU),
        };
        r_rsip_func100(Param_p6f_func100_004);
        WR1_PROG(REG_00B0H, 0x00001804U);

        r_rsip_func_sub006(0x080000b5U, 0x00430011U);

        r_rsip_func_sub006(0x08000075U, 0x00430011U);

        static const uint32_t Param_p6f_func100_005[] =
        {
            BSWAP_32BIG_C(0x44871b27U), BSWAP_32BIG_C(0xb7e2c72eU), BSWAP_32BIG_C(0xa9eff8dfU), BSWAP_32BIG_C(
                0x386c6797U),
        };
        r_rsip_func100(Param_p6f_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p6f_func102_002[] =
            {
                BSWAP_32BIG_C(0x6eb1c767U), BSWAP_32BIG_C(0xfa909053U), BSWAP_32BIG_C(0xa95e487fU), BSWAP_32BIG_C(
                    0xec14938eU),
            };
            r_rsip_func102(Param_p6f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p6f_func100_006[] =
            {
                BSWAP_32BIG_C(0xa73cfa0bU), BSWAP_32BIG_C(0xd353256aU), BSWAP_32BIG_C(0x2c0398d6U), BSWAP_32BIG_C(
                    0x51b43811U),
            };
            r_rsip_func100(Param_p6f_func100_006);
            WR1_PROG(REG_009CH, 0x81010000U);
            WR1_PROG(REG_0008H, 0x00005006U);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

            static const uint32_t Param_p6f_func102_003[] =
            {
                BSWAP_32BIG_C(0x68bcb25eU), BSWAP_32BIG_C(0x64dcf4ddU), BSWAP_32BIG_C(0x3e4fac0eU), BSWAP_32BIG_C(
                    0x9a8368d0U),
            };
            r_rsip_func102(Param_p6f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
