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

rsip_ret_t r_rsip_p36f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_Text[])
{
    uint32_t iLoop = 0U;

    WR1_PROG(REG_0014H, 0x000001c7U);
    WR1_PROG(REG_009CH, 0x80020040U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_TextLen[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_TextLen[1]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub016(0x0000b400U, 0x0000007FU, 0x0000b420U);
    WR1_PROG(REG_0094H, 0xFFFFFF00U);
    r_rsip_func_sub007(0x0c002823U, 0x04a02802U, 0x00260000U);

    WR1_PROG(REG_0014H, 0x000000c7U);
    WR1_PROG(REG_009CH, 0x800100a0U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_DataTLen[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub007(0x380088a0U, 0x00000000U, 0x00260000U);

    WR1_PROG(REG_0094H, 0x0000b420U);
    r_rsip_func_sub007(0x00000010U, 0x34202825U, 0x00260000U);

    static const uint32_t Param_p36f_func100_001[] =
    {
        BSWAP_32BIG_C(0xc4dc4c79U), BSWAP_32BIG_C(0xea569800U), BSWAP_32BIG_C(0xe110f2d8U), BSWAP_32BIG_C(0x93c687b8U),
    };
    r_rsip_func100(Param_p36f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p36f_func102_001[] =
        {
            BSWAP_32BIG_C(0x83152824U), BSWAP_32BIG_C(0x0b33fdb3U), BSWAP_32BIG_C(0x03465d7cU), BSWAP_32BIG_C(
                0x349e1411U),
        };
        r_rsip_func102(Param_p36f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00003403U);
        WR1_PROG(REG_0094H, 0x00036800U);

        r_rsip_func_sub007(0x08008c00U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_p36f_func100_002[] =
        {
            BSWAP_32BIG_C(0x35182929U), BSWAP_32BIG_C(0xa0a00ca4U), BSWAP_32BIG_C(0x0e04950dU), BSWAP_32BIG_C(
                0x6bb37f2dU),
        };
        r_rsip_func100(Param_p36f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p36f_func100_003[] =
            {
                BSWAP_32BIG_C(0x6757de0cU), BSWAP_32BIG_C(0x906fd6c8U), BSWAP_32BIG_C(0xe05244f2U), BSWAP_32BIG_C(
                    0x397b19d4U),
            };
            r_rsip_func100(Param_p36f_func100_003);
            r_rsip_func_sub008(0x000003c1U, 0x40008020U, 0x20008d05U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub003(0x80840001U, 0x03410011U);

            WR1_PROG(REG_0094H, 0x00000884U);
            for (iLoop = 0U; iLoop < 16U; iLoop++)
            {
                r_rsip_func_sub016(0x3c002820U, 0x12003c81U, 0x00002c20U);
            }

            r_rsip_func_sub015(0x00000821U, 0x81840001U, 0x00005012U);
            RD1_ADDR(REG_002CH, &OutData_Text[0]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[1]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[2]);
            WAIT_STS(REG_0008H, 30, 1);
            RD1_ADDR(REG_002CH, &OutData_Text[3]);

            static const uint32_t Param_p36f_func101_001[] =
            {
                BSWAP_32BIG_C(0x02fe6f83U), BSWAP_32BIG_C(0x74ea074fU), BSWAP_32BIG_C(0xda514d66U), BSWAP_32BIG_C(
                    0xcf2b07beU),
            };
            r_rsip_func101(Param_p36f_func101_001);
        }

        r_rsip_func437(InData_DataALen, InData_DataT);

        static const uint32_t Param_p36f_func100_004[] =
        {
            BSWAP_32BIG_C(0x8e0eda52U), BSWAP_32BIG_C(0xb4d5aa25U), BSWAP_32BIG_C(0x517ad6edU), BSWAP_32BIG_C(
                0x6d39e443U),
        };
        r_rsip_func100(Param_p36f_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p36f_func102_002[] =
            {
                BSWAP_32BIG_C(0x934cab74U), BSWAP_32BIG_C(0x42e1c27bU), BSWAP_32BIG_C(0xdf51b7d9U), BSWAP_32BIG_C(
                    0x7146dd9dU),
            };
            r_rsip_func102(Param_p36f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p36f_func102_003[] =
            {
                BSWAP_32BIG_C(0xbfa0cefcU), BSWAP_32BIG_C(0xec4d20ceU), BSWAP_32BIG_C(0x8ca2c587U), BSWAP_32BIG_C(
                    0x568737c7U),
            };
            r_rsip_func102(Param_p36f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
