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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t InData_EncMsgLength[])
{
    uint32_t iLoop = 0U;

    r_rsip_func_sub014(0x000000c7U, 0x800100a0U);
    WR1_PROG(REG_002CH, InData_EncMsgLength[0]);
    r_rsip_func_sub018(0x00000000U, 0x000008e7U, 0x300088a0U);
    r_rsip_func_sub022(0x00000000U, 0x00030020U, 0x00002ce0U);

    r_rsip_func_sub022(0x00000080U, 0x300088a0U, 0x0000000dU);
    r_rsip_func_sub022(0x00030020U, 0x00002ce0U, 0x00000080U);

    r_rsip_func_sub022(0x300088a0U, 0x00000011U, 0x00030020U);

    WR1_PROG(REG_0094H, 0x00002ce0U);

    r_rsip_func_sub010(0x00000080U, 0x38000ce7U, 0x00270000U);

    static const uint32_t Param_pe5e_func100_001[] =
    {
        BSWAP_32BIG_C(0xbb586cafU), BSWAP_32BIG_C(0xedfb77e0U), BSWAP_32BIG_C(0x04de4fdaU), BSWAP_32BIG_C(0x6a15df92U),
    };
    r_rsip_func100(Param_pe5e_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5e_func102_001[] =
        {
            BSWAP_32BIG_C(0x12ba7348U), BSWAP_32BIG_C(0x1ca4682fU), BSWAP_32BIG_C(0x1a9b773eU), BSWAP_32BIG_C(
                0xe5fd36fdU),
        };
        r_rsip_func102(Param_pe5e_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub016(0x38000ca5U, 0x00000080U, 0x00A70000U);

        static const uint32_t Param_pe5e_func100_002[] =
        {
            BSWAP_32BIG_C(0xc032819bU), BSWAP_32BIG_C(0x5f824611U), BSWAP_32BIG_C(0x3f66c088U), BSWAP_32BIG_C(
                0xaacd8effU),
        };
        r_rsip_func100(Param_pe5e_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_EncMsg[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e503U, 0x00000000U);

            static const uint32_t Param_pe5e_func101_001[] =
            {
                BSWAP_32BIG_C(0xcd1e2290U), BSWAP_32BIG_C(0xaf7cfe9fU), BSWAP_32BIG_C(0x877f7f1bU), BSWAP_32BIG_C(
                    0x89e29d1fU),
            };
            r_rsip_func101(Param_pe5e_func101_001);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x0000b4c0U);
            WR1_PROG(REG_0094H, 0x01799093U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e503U, 0x00000000U);

            static const uint32_t Param_pe5e_func101_002[] =
            {
                BSWAP_32BIG_C(0x3f2d253cU), BSWAP_32BIG_C(0x49228e4bU), BSWAP_32BIG_C(0xcd505acaU), BSWAP_32BIG_C(
                    0xca7a1e60U),
            };
            r_rsip_func101(Param_pe5e_func101_002);
            r_rsip_func044();

            WAIT_STS(REG_0118H, 0, 1);

            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            static const uint32_t Param_pe5e_func100_003[] =
            {
                BSWAP_32BIG_C(0x9ac1fca9U), BSWAP_32BIG_C(0xc9504199U), BSWAP_32BIG_C(0x80f5e047U), BSWAP_32BIG_C(
                    0xa2ecf57dU),
            };
            r_rsip_func100(Param_pe5e_func100_003);
            r_rsip_func_sub017(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_002CH, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub022(0x0000a8a0U, 0x00000002U, 0x000268a5U);

            WR1_PROG(REG_0094H, 0x00000821U);

            for (iLoop = 0U; iLoop < S_RAM[0] - 5; )
            {
                r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

                r_rsip_func_sub015(0x01410011U, 0x00001800U);

                WR1_PROG(REG_0094H, 0x00002c20U);

                static const uint32_t Param_pe5e_func101_003[] =
                {
                    BSWAP_32BIG_C(0x425d1c9aU), BSWAP_32BIG_C(0x0c4747edU), BSWAP_32BIG_C(0x6eaeda7dU), BSWAP_32BIG_C(
                        0xdca5d420U),
                };
                r_rsip_func101(Param_pe5e_func101_003);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub016(0x38000825U, 0x00000080U, 0x00270000U);
            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_EncMsg[1 + iLoop]);

            r_rsip_func_sub013(0x9c100005U, 0x00410011U);

            static const uint32_t Param_pe5e_func100_004[] =
            {
                BSWAP_32BIG_C(0x85da840fU), BSWAP_32BIG_C(0x218f78bfU), BSWAP_32BIG_C(0xeccf0ed1U), BSWAP_32BIG_C(
                    0xd2ee313aU),
            };
            r_rsip_func100(Param_pe5e_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pe5e_func101_004[] =
                {
                    BSWAP_32BIG_C(0x24f3b5fcU), BSWAP_32BIG_C(0xbda9a57bU), BSWAP_32BIG_C(0x10c7a068U), BSWAP_32BIG_C(
                        0x83a39d14U),
                };
                r_rsip_func101(Param_pe5e_func101_004);

                return RSIP_RET_FAIL;
            }
            else
            {
                static const uint32_t Param_pe5e_func101_005[] =
                {
                    BSWAP_32BIG_C(0x6b3112a0U), BSWAP_32BIG_C(0x770983f0U), BSWAP_32BIG_C(0xfe58faaeU), BSWAP_32BIG_C(
                        0x3e38a962U),
                };
                r_rsip_func101(Param_pe5e_func101_005);

                return RSIP_RET_PASS;
            }
        }
        else
        {
            static const uint32_t Param_pe5e_func101_006[] =
            {
                BSWAP_32BIG_C(0x86106522U), BSWAP_32BIG_C(0x1926328fU), BSWAP_32BIG_C(0x2dde8f5cU), BSWAP_32BIG_C(
                    0xec6670fbU),
            };
            r_rsip_func101(Param_pe5e_func101_006);

            return RSIP_RET_PASS;
        }
    }
}
