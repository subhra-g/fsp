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

rsip_ret_t r_rsip_pa1i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_IVType[],
                        const uint32_t InData_IV[],
                        const uint32_t InData_Header[],
                        uint32_t       Header_Len)
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00a10001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    WR1_PROG(REG_0094H, 0x0000b4a0U);
    WR1_PROG(REG_0094H, 0x00000007U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000a1U, 0x00000000U);

    static const uint32_t Param_pa1i_func101_001[] =
    {
        BSWAP_32BIG_C(0x22302275U), BSWAP_32BIG_C(0x49226d9fU), BSWAP_32BIG_C(0xce987bd4U), BSWAP_32BIG_C(0x399cc35fU),
    };
    r_rsip_func101(Param_pa1i_func101_001);
    r_rsip_func441(InData_KeyIndex);

    static const uint32_t Param_pa1i_func100_001[] =
    {
        BSWAP_32BIG_C(0x2f50e473U), BSWAP_32BIG_C(0xa4c566cdU), BSWAP_32BIG_C(0x293a0c6eU), BSWAP_32BIG_C(0x5ace7e66U),
    };
    r_rsip_func100(Param_pa1i_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pa1i_func102_001[] =
        {
            BSWAP_32BIG_C(0x9735d668U), BSWAP_32BIG_C(0x38a63afbU), BSWAP_32BIG_C(0x22646ffaU), BSWAP_32BIG_C(
                0xf522f862U),
        };
        r_rsip_func102(Param_pa1i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x80010080U);
        WR1_PROG(REG_002CH, InData_IVType[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

        static const uint32_t Param_pa1i_func100_002[] =
        {
            BSWAP_32BIG_C(0x3bd23a55U), BSWAP_32BIG_C(0x3ca67f54U), BSWAP_32BIG_C(0x9bc4fb87U), BSWAP_32BIG_C(
                0x7d538c13U),
        };
        r_rsip_func100(Param_pa1i_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            r_rsip_func_sub019(0x000003c1U, 0x08000045U);
            WR4_ADDR(REG_002CH, &InData_IV[0]);

            static const uint32_t Param_pa1i_func101_002[] =
            {
                BSWAP_32BIG_C(0xac92b4e3U), BSWAP_32BIG_C(0x78aa40b9U), BSWAP_32BIG_C(0xda8e6feaU), BSWAP_32BIG_C(
                    0xb8e3dec7U),
            };
            r_rsip_func101(Param_pa1i_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x0199e556U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x000000a1U, 0x00000000U);

            static const uint32_t Param_pa1i_func101_003[] =
            {
                BSWAP_32BIG_C(0xca247e08U), BSWAP_32BIG_C(0x75b11917U), BSWAP_32BIG_C(0xda00d62cU), BSWAP_32BIG_C(
                    0xbd2dfdacU),
            };
            r_rsip_func101(Param_pa1i_func101_003);
            r_rsip_func440(InData_IV);

            static const uint32_t Param_pa1i_func100_003[] =
            {
                BSWAP_32BIG_C(0x864fb30aU), BSWAP_32BIG_C(0x5c0ed444U), BSWAP_32BIG_C(0x097f03d7U), BSWAP_32BIG_C(
                    0x5524d05fU),
            };
            r_rsip_func100(Param_pa1i_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_pa1i_func102_002[] =
                {
                    BSWAP_32BIG_C(0xa8de2ebdU), BSWAP_32BIG_C(0x3b17eb4eU), BSWAP_32BIG_C(0x9b63a096U), BSWAP_32BIG_C(
                        0xa7885e70U),
                };
                r_rsip_func102(Param_pa1i_func102_002);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_00D0H, 0x08000045U);
                r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                static const uint32_t Param_pa1i_func101_004[] =
                {
                    BSWAP_32BIG_C(0x35ea48ddU), BSWAP_32BIG_C(0x101f9735U), BSWAP_32BIG_C(0x5da2c3f1U), BSWAP_32BIG_C(
                        0xe8fc5ce9U),
                };
                r_rsip_func101(Param_pa1i_func101_004);
            }
        }

        static const uint32_t Param_pa1i_func100_004[] =
        {
            BSWAP_32BIG_C(0xc9499d65U), BSWAP_32BIG_C(0xba80ee68U), BSWAP_32BIG_C(0x10454215U), BSWAP_32BIG_C(
                0xcb218c48U),
        };
        r_rsip_func100(Param_pa1i_func100_004);
        WR1_PROG(REG_00D0H, 0x08000085U);
        r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

        static const uint32_t Param_pa1i_func100_005[] =
        {
            BSWAP_32BIG_C(0xfcb7219cU), BSWAP_32BIG_C(0x3cda4615U), BSWAP_32BIG_C(0x672505f6U), BSWAP_32BIG_C(
                0x1f198156U),
        };
        r_rsip_func100(Param_pa1i_func100_005);
        r_rsip_func_sub013(0x08000095U, 0x00430011U);

        WR1_PROG(REG_00D4H, 0x40000000U);
        r_rsip_func501(InData_Header, Header_Len);

        static const uint32_t Param_pa1i_func101_005[] =
        {
            BSWAP_32BIG_C(0xa0999066U), BSWAP_32BIG_C(0x4c0ad98aU), BSWAP_32BIG_C(0x92e42675U), BSWAP_32BIG_C(
                0x715cfb95U),
        };
        r_rsip_func101(Param_pa1i_func101_005);

        return RSIP_RET_PASS;
    }
}
