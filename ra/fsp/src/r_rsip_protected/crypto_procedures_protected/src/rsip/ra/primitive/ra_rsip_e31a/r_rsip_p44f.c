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

rsip_ret_t r_rsip_p44f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
{
    uint32_t iLoop = 0U;

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
    {
        r_rsip_func_sub011(0x000000a1U, 0x40000000U, 0x4a008104U);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_001[] =
        {
            BSWAP_32BIG_C(0x276a10c9U), BSWAP_32BIG_C(0xe0f33c61U), BSWAP_32BIG_C(0x37944f61U), BSWAP_32BIG_C(
                0x2de566d9U),
        };
        r_rsip_func101(Param_p44f_func101_001);
    }
    else
    {
        r_rsip_func_sub011(0x000000a1U, 0x40000000U, 0x5a008104U);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        static const uint32_t Param_p44f_func101_002[] =
        {
            BSWAP_32BIG_C(0x8e62deadU), BSWAP_32BIG_C(0xe6915aeeU), BSWAP_32BIG_C(0x2eb4110eU), BSWAP_32BIG_C(
                0xacecc8c2U),
        };
        r_rsip_func101(Param_p44f_func101_002);
    }

    r_rsip_func_sub013(0x0c000045U, 0x00410011U);

    if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
    {
        static const uint32_t Param_p44f_func100_001[] =
        {
            BSWAP_32BIG_C(0xeab9cd2aU), BSWAP_32BIG_C(0x54cf93d9U), BSWAP_32BIG_C(0x5dec354bU), BSWAP_32BIG_C(
                0x9f4c86e3U),
        };
        r_rsip_func100(Param_p44f_func100_001);
        r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x0e008505U);
        WR4_ADDR(REG_002CH, &InData_Text[0]);

        WR1_PROG(REG_0008H, 0x00001012U);
        WAIT_STS(REG_0008H, 30, 1);
        RD4_ADDR(REG_002CH, &OutData_DataT[0]);

        static const uint32_t Param_p44f_func102_001[] =
        {
            BSWAP_32BIG_C(0xc17d54b1U), BSWAP_32BIG_C(0xcc1de4f0U), BSWAP_32BIG_C(0xbf2535ddU), BSWAP_32BIG_C(
                0x452f043fU),
        };
        r_rsip_func102(Param_p44f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func_sub014(0x000000c7U, 0x80010040U);
        WR1_PROG(REG_002CH, InData_DataTLen[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub010(0x3420a840U, 0x00000010U, 0x00270000U);

        WR1_PROG(REG_0094H, 0x0000b460U);
        r_rsip_func_sub010(0x00000080U, 0x34202862U, 0x00270000U);

        static const uint32_t Param_p44f_func100_002[] =
        {
            BSWAP_32BIG_C(0xfe82f015U), BSWAP_32BIG_C(0x0645d3ecU), BSWAP_32BIG_C(0xe7898414U), BSWAP_32BIG_C(
                0xe6bcc45eU),
        };
        r_rsip_func100(Param_p44f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p44f_func102_002[] =
            {
                BSWAP_32BIG_C(0x8612252fU), BSWAP_32BIG_C(0x62b84b31U), BSWAP_32BIG_C(0xb14ed490U), BSWAP_32BIG_C(
                    0xe10ad400U),
            };
            r_rsip_func102(Param_p44f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x0e008505U);
            WR4_ADDR(REG_002CH, &InData_Text[0]);

            WR1_PROG(REG_0094H, 0x00000821U);
            r_rsip_func_sub006(0x80840001U, 0x03410011U, 0x000034e2U, 0x000568e7U);
            r_rsip_func_sub022(0x00026ce7U, 0x00003827U, 0x0000b4c0U);
            r_rsip_func_sub022(0x00000020U, 0x00003402U, 0x00008c00U);
            r_rsip_func_sub022(0x0000001fU, 0x000028c0U, 0x00008cc0U);
            r_rsip_func_sub022(0x0000001fU, 0x00004406U, 0x00007421U);
            r_rsip_func_sub022(0x00007821U, 0x00003c27U, 0x000034c2U);
            r_rsip_func_sub022(0x0000a4c0U, 0x0000001fU, 0x000568c6U);

            r_rsip_func_sub022(0x000034e6U, 0x00026ce7U, 0x00000821U);

            for (iLoop = 0U; iLoop < 4; iLoop++)
            {
                r_rsip_func_sub022(0x3420a8e0U, 0x0000000dU, 0x10003c27U);

                WR1_PROG(REG_0094H, 0x1000a4e0U);
                WR1_PROG(REG_0094H, 0x00000004U);
            }

            WR1_PROG(REG_00D0H, 0x08000045U);
            r_rsip_func_sub012(0x81840001U, 0x00490011U);

            r_rsip_func_sub019(0x000003c1U, 0x9c000005U);
            WR4_ADDR(REG_002CH, &InData_DataT[0]);

            static const uint32_t Param_p44f_func100_003[] =
            {
                BSWAP_32BIG_C(0x1b74208eU), BSWAP_32BIG_C(0x005c7bb7U), BSWAP_32BIG_C(0xdf9466d8U), BSWAP_32BIG_C(
                    0xf1e6a51aU),
            };
            r_rsip_func100(Param_p44f_func100_003);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p44f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x0132a139U), BSWAP_32BIG_C(0x9dd37622U), BSWAP_32BIG_C(0x3e28a8efU), BSWAP_32BIG_C(
                        0x0baf6c1eU),
                };
                r_rsip_func102(Param_p44f_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_AUTH_FAIL;
            }
            else
            {
                static const uint32_t Param_p44f_func102_004[] =
                {
                    BSWAP_32BIG_C(0x0db3a55bU), BSWAP_32BIG_C(0xa0a2383aU), BSWAP_32BIG_C(0x321bc0dcU), BSWAP_32BIG_C(
                        0xf8a968b7U),
                };
                r_rsip_func102(Param_p44f_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
