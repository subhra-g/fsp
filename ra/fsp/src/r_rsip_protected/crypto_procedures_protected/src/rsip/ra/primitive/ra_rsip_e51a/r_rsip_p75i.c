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

rsip_ret_t r_rsip_p75i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[],
                        uint32_t       KEY_INDEX_SIZE)
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00750001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    WR1_PROG(REG_2000H, 0x00000001U);

    r_rsip_func_sub010(0x000000c7U, 0x80010080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub017(0x38000c84U, 0x00260000U);

    static const uint32_t Param_p75i_func100_001[] =
    {
        BSWAP_32BIG_C(0x2d865bb4U), BSWAP_32BIG_C(0x73643b86U), BSWAP_32BIG_C(0x5d89599aU), BSWAP_32BIG_C(0x2e5e2b92U),
    };
    r_rsip_func100(Param_p75i_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_p75i_func102_001[] =
        {
            BSWAP_32BIG_C(0x7155a1a7U), BSWAP_32BIG_C(0x1ba2bb55U), BSWAP_32BIG_C(0x7b41333cU), BSWAP_32BIG_C(
                0x452ff8b9U),
        };
        r_rsip_func102(Param_p75i_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_p75i_func100_002[] =
        {
            BSWAP_32BIG_C(0x3ba63249U), BSWAP_32BIG_C(0xa8ac12b5U), BSWAP_32BIG_C(0xff89ab0eU), BSWAP_32BIG_C(
                0x06a90e7aU),
        };
        r_rsip_func100(Param_p75i_func100_002);
        r_rsip_func_sub024(0x3420a880U, 0x00000007U, 0x2000b480U, 0x00000006U);

        r_rsip_func_sub014(0x00007c04U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000001aU, 0x00000040U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            static const uint32_t Param_p75i_func101_001[] =
            {
                BSWAP_32BIG_C(0xea753b5bU), BSWAP_32BIG_C(0xd577eea0U), BSWAP_32BIG_C(0xb3b1ca4bU), BSWAP_32BIG_C(
                    0xdcdfcfc0U),
            };
            r_rsip_func101(Param_p75i_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000001bU, 0x00000050U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000008U);

            static const uint32_t Param_p75i_func101_002[] =
            {
                BSWAP_32BIG_C(0x76eb904aU), BSWAP_32BIG_C(0x98cda184U), BSWAP_32BIG_C(0x9466122cU), BSWAP_32BIG_C(
                    0xeb9aa8daU),
            };
            r_rsip_func101(Param_p75i_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000002aU, 0x00000080U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75i_func101_003[] =
            {
                BSWAP_32BIG_C(0x5471504fU), BSWAP_32BIG_C(0x25967a0dU), BSWAP_32BIG_C(0x14f94fb5U), BSWAP_32BIG_C(
                    0x161e01a1U),
            };
            r_rsip_func101(Param_p75i_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x0000002bU, 0x00000090U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75i_func101_004[] =
            {
                BSWAP_32BIG_C(0xc1648b70U), BSWAP_32BIG_C(0x56b78a9dU), BSWAP_32BIG_C(0xde60230dU), BSWAP_32BIG_C(
                    0x3a4c7e0aU),
            };
            r_rsip_func101(Param_p75i_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x00000028U, 0x000000a0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x0000000cU);

            static const uint32_t Param_p75i_func101_005[] =
            {
                BSWAP_32BIG_C(0x7663e154U), BSWAP_32BIG_C(0xc0e1f0f1U), BSWAP_32BIG_C(0x18b15dbeU), BSWAP_32BIG_C(
                    0xcfadade5U),
            };
            r_rsip_func101(Param_p75i_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            r_rsip_func_sub035(0x0000b4a0U, 0x00000029U, 0x000000b0U);

            WR1_PROG(REG_1600H, 0x0000b460U);
            WR1_PROG(REG_1600H, 0x00000010U);

            static const uint32_t Param_p75i_func101_006[] =
            {
                BSWAP_32BIG_C(0x1e1eb3aaU), BSWAP_32BIG_C(0xf03b1a2eU), BSWAP_32BIG_C(0xb98cc9ddU), BSWAP_32BIG_C(
                    0x860e23a3U),
            };
            r_rsip_func101(Param_p75i_func101_006);
        }

        WR1_PROG(REG_2008H, 0x00000003U);

        r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
        WR1_PROG(REG_1420H, InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007501U);

        static const uint32_t Param_p75i_func101_007[] =
        {
            BSWAP_32BIG_C(0x3526cf5cU), BSWAP_32BIG_C(0x5cd9659cU), BSWAP_32BIG_C(0xa7a6c9e7U), BSWAP_32BIG_C(
                0xd54caea0U),
        };
        r_rsip_func101(Param_p75i_func101_007);
        r_rsip_func043();

        WR1_PROG(REG_1600H, 0x000034e5U);

        r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x00007501U);

        static const uint32_t Param_p75i_func101_008[] =
        {
            BSWAP_32BIG_C(0xcf3bb4bdU), BSWAP_32BIG_C(0x5f4b1c1eU), BSWAP_32BIG_C(0x2015072bU), BSWAP_32BIG_C(
                0xadd68673U),
        };
        r_rsip_func101(Param_p75i_func101_008);
        r_rsip_func044();

        r_rsip_func_sub004(0x08000044U, 0x00000000U);

        r_rsip_func_sub004(0x08000054U, 0x00000000U);

        WR1_PROG(REG_1600H, 0x000008e7U);

        for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
        {
            r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
            WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

            r_rsip_func_sub001(0x01420011U);

            WR1_PROG(REG_1600H, 0x0000a4e0U);
            WR1_PROG(REG_1600H, 0x00000004U);

            static const uint32_t Param_p75i_func101_009[] =
            {
                BSWAP_32BIG_C(0x8f90b383U), BSWAP_32BIG_C(0x5eb9a5a9U), BSWAP_32BIG_C(0x9d5d27cfU), BSWAP_32BIG_C(
                    0x58810b56U),
            };
            r_rsip_func101(Param_p75i_func101_009);
            iLoop = iLoop + 4U;
        }

        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func_sub011(0x380008e3U);

        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 1]);

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_func_sub001(0x00820011U);

        static const uint32_t Param_p75i_func100_003[] =
        {
            BSWAP_32BIG_C(0x3df2ca0dU), BSWAP_32BIG_C(0x9f76b229U), BSWAP_32BIG_C(0x321840daU), BSWAP_32BIG_C(
                0x929577afU),
        };
        r_rsip_func100(Param_p75i_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_p75i_func102_002[] =
            {
                BSWAP_32BIG_C(0xb02910c8U), BSWAP_32BIG_C(0x3c497f61U), BSWAP_32BIG_C(0x29dfba2dU), BSWAP_32BIG_C(
                    0x69d830ccU),
            };
            r_rsip_func102(Param_p75i_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
            {
                r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000080U);

                WR1_PROG(REG_200CH, 0x00000001U);

                WAIT_STS(REG_2030H, 8, 0);

                r_rsip_func_sub036(0x00000020U, 0x00000000U, 0x00000020U, 0x00000000U);

                WR1_PROG(REG_200CH, 0x00000100U);

                static const uint32_t Param_p75i_func101_010[] =
                {
                    BSWAP_32BIG_C(0x35007ef2U), BSWAP_32BIG_C(0xeae17f70U), BSWAP_32BIG_C(0x5941fe37U), BSWAP_32BIG_C(
                        0x02799ba3U),
                };
                r_rsip_func101(Param_p75i_func101_010);
            }
            else
            {
                r_rsip_func_sub036(0x00000040U, InData_MsgLen[0], 0x00000040U, InData_MsgLen[1]);

                WR1_PROG(REG_200CH, 0x00000001U);

                static const uint32_t Param_p75i_func101_011[] =
                {
                    BSWAP_32BIG_C(0xee738e30U), BSWAP_32BIG_C(0x088a20d8U), BSWAP_32BIG_C(0x78bb2b09U), BSWAP_32BIG_C(
                        0x7a2eb843U),
                };
                r_rsip_func101(Param_p75i_func101_011);
            }

            return RSIP_RET_PASS;
        }
    }
}
