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

rsip_ret_t r_rsip_p32f (const uint32_t InData_Text[],
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

    static const uint32_t Param_p32f_func100_001[] =
    {
        BSWAP_32BIG_C(0xfc41ad69U), BSWAP_32BIG_C(0xb9a339dcU), BSWAP_32BIG_C(0x75a21d55U), BSWAP_32BIG_C(0x37828b15U),
    };
    r_rsip_func100(Param_p32f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);
    WR1_PROG(REG_0024H, 0x00000000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p32f_func102_001[] =
        {
            BSWAP_32BIG_C(0x212ee083U), BSWAP_32BIG_C(0x240ee409U), BSWAP_32BIG_C(0xad062819U), BSWAP_32BIG_C(
                0xd03a5565U),
        };
        r_rsip_func102(Param_p32f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00003403U);
        WR1_PROG(REG_0094H, 0x00036800U);

        r_rsip_func_sub007(0x08008c00U, 0x0000000fU, 0x00A60000U);

        static const uint32_t Param_p32f_func100_002[] =
        {
            BSWAP_32BIG_C(0x3e6c3d95U), BSWAP_32BIG_C(0x2db0c32eU), BSWAP_32BIG_C(0x128e818dU), BSWAP_32BIG_C(
                0x786c7cd0U),
        };
        r_rsip_func100(Param_p32f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p32f_func100_003[] =
            {
                BSWAP_32BIG_C(0xb8117709U), BSWAP_32BIG_C(0x963f552bU), BSWAP_32BIG_C(0x8b7a8806U), BSWAP_32BIG_C(
                    0xf57f320fU),
            };
            r_rsip_func100(Param_p32f_func100_003);
            r_rsip_func_sub008(0x000003c1U, 0x00008020U, 0x20008d05U);
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

            static const uint32_t Param_p32f_func101_001[] =
            {
                BSWAP_32BIG_C(0x5dcab225U), BSWAP_32BIG_C(0x5798af9cU), BSWAP_32BIG_C(0xdae01ab6U), BSWAP_32BIG_C(
                    0xed1b4b96U),
            };
            r_rsip_func101(Param_p32f_func101_001);
        }

        r_rsip_func433(InData_DataALen, InData_DataT);

        static const uint32_t Param_p32f_func100_004[] =
        {
            BSWAP_32BIG_C(0x5b1a94bdU), BSWAP_32BIG_C(0x77b2488eU), BSWAP_32BIG_C(0x5850ff16U), BSWAP_32BIG_C(
                0x8268a879U),
        };
        r_rsip_func100(Param_p32f_func100_004);
        WR1_PROG(REG_0040H, 0x00400000U);
        WR1_PROG(REG_0024H, 0x00000000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p32f_func102_002[] =
            {
                BSWAP_32BIG_C(0xf35c2f9dU), BSWAP_32BIG_C(0x2a9064fdU), BSWAP_32BIG_C(0x42db116fU), BSWAP_32BIG_C(
                    0x61426118U),
            };
            r_rsip_func102(Param_p32f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            static const uint32_t Param_p32f_func102_003[] =
            {
                BSWAP_32BIG_C(0x117ab50bU), BSWAP_32BIG_C(0x31e99034U), BSWAP_32BIG_C(0x4e317492U), BSWAP_32BIG_C(
                    0x3a28b28bU),
            };
            r_rsip_func102(Param_p32f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
