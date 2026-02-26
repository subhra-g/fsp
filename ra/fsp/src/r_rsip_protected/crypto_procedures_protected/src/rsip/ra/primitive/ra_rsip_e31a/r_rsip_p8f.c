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

rsip_ret_t r_rsip_p8f (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_WrappedKeyIndex[],
                       uint32_t       OutData_Text[],
                       uint32_t       KEY_INDEX_SIZE,
                       uint32_t       WRAPPED_KEY_SIZE)
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x008f0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000001c7U, 0x800200c0U);
    WR1_PROG(REG_002CH, InData_Cmd[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_WrappedKeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    WR1_PROG(REG_0094H, 0x00003407U);

    r_rsip_func_sub010(0x3420a8c0U, 0x00000002U, 0x00A70000U);

    r_rsip_func_sub010(0x3420a800U, 0x00000003U, 0x00A70000U);

    r_rsip_func_sub010(0x38008800U, 0x00000001U, 0x00270000U);

    static const uint32_t Param_p8f_func100_001[] =
    {
        BSWAP_32BIG_C(0x6bdf5203U), BSWAP_32BIG_C(0x100cee15U), BSWAP_32BIG_C(0x6f825f89U), BSWAP_32BIG_C(0x8a64f422U),
    };
    r_rsip_func100(Param_p8f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p8f_func102_001[] =
        {
            BSWAP_32BIG_C(0x8547f411U), BSWAP_32BIG_C(0x6f8292f1U), BSWAP_32BIG_C(0xc35f6d75U), BSWAP_32BIG_C(
                0x24c7ff17U),
        };
        r_rsip_func102(Param_p8f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x00003486U, 0x38000c84U, 0x00270000U);

        static const uint32_t Param_p8f_func100_002[] =
        {
            BSWAP_32BIG_C(0x9b208424U), BSWAP_32BIG_C(0xf8f96fe3U), BSWAP_32BIG_C(0xee039ac7U), BSWAP_32BIG_C(
                0x9a9142e7U),
        };
        r_rsip_func100(Param_p8f_func100_002);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000008fU, 0x00000000U);

            static const uint32_t Param_p8f_func101_001[] =
            {
                BSWAP_32BIG_C(0xa1008e0dU), BSWAP_32BIG_C(0x3c1664fbU), BSWAP_32BIG_C(0x5091f263U), BSWAP_32BIG_C(
                    0xc6960c83U),
            };
            r_rsip_func101(Param_p8f_func101_001);
            r_rsip_func440(InData_KeyIndex);

            static const uint32_t Param_p8f_func101_002[] =
            {
                BSWAP_32BIG_C(0xe4e2028eU), BSWAP_32BIG_C(0x0621621aU), BSWAP_32BIG_C(0x699e2c29U), BSWAP_32BIG_C(
                    0xf76a65feU),
            };
            r_rsip_func101(Param_p8f_func101_002);
        }
        else
        {
            WR1_PROG(REG_0094H, 0x0000b4a0U);
            WR1_PROG(REG_0094H, 0x00000007U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000008fU, 0x00000000U);

            static const uint32_t Param_p8f_func101_003[] =
            {
                BSWAP_32BIG_C(0x3ed1eb53U), BSWAP_32BIG_C(0x09904c91U), BSWAP_32BIG_C(0xdb6bf867U), BSWAP_32BIG_C(
                    0x1dd8a24aU),
            };
            r_rsip_func101(Param_p8f_func101_003);
            r_rsip_func441(InData_KeyIndex);

            static const uint32_t Param_p8f_func101_004[] =
            {
                BSWAP_32BIG_C(0x6cebc5ebU), BSWAP_32BIG_C(0x34d98932U), BSWAP_32BIG_C(0x61876f03U), BSWAP_32BIG_C(
                    0xa14f939eU),
            };
            r_rsip_func101(Param_p8f_func101_004);
        }

        static const uint32_t Param_p8f_func100_003[] =
        {
            BSWAP_32BIG_C(0xb3af5de1U), BSWAP_32BIG_C(0x5e447bb6U), BSWAP_32BIG_C(0x8a4840b4U), BSWAP_32BIG_C(
                0x33702ee4U),
        };
        r_rsip_func100(Param_p8f_func100_003);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p8f_func102_002[] =
            {
                BSWAP_32BIG_C(0xa6722325U), BSWAP_32BIG_C(0xfea8bcc2U), BSWAP_32BIG_C(0xbd0f1e2fU), BSWAP_32BIG_C(
                    0xf7e9b445U),
            };
            r_rsip_func102(Param_p8f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            r_rsip_func030();

            r_rsip_func_sub022(0x00003427U, 0x0000b460U, 0x00000010U);

            WR1_PROG(REG_0094H, 0x00003ca3U);

            WR1_PROG(REG_0094H, 0x00003466U);

            r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
            WR1_PROG(REG_002CH, InData_WrappedKeyIndex[0]);
            WR1_PROG(REG_0024H, 0x00000000U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000008fU, 0x00000000U);

            static const uint32_t Param_p8f_func101_005[] =
            {
                BSWAP_32BIG_C(0xd76a6756U), BSWAP_32BIG_C(0xaf91306eU), BSWAP_32BIG_C(0x5c2ecf2cU), BSWAP_32BIG_C(
                    0xc1c41047U),
            };
            r_rsip_func101(Param_p8f_func101_005);
            r_rsip_func143();

            WR1_PROG(REG_0094H, 0x000034c3U);

            r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000008fU, 0x00000000U);

            static const uint32_t Param_p8f_func101_006[] =
            {
                BSWAP_32BIG_C(0x8eb845cdU), BSWAP_32BIG_C(0x39d4d420U), BSWAP_32BIG_C(0xf3cdc38aU), BSWAP_32BIG_C(
                    0x2a02045aU),
            };
            r_rsip_func101(Param_p8f_func101_006);
            r_rsip_func044();

            r_rsip_func_sub022(0x000034e1U, 0x0000b460U, 0x00000010U);

            WR1_PROG(REG_0094H, 0x000038a3U);

            r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

            r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

            r_rsip_func_sub022(0x00000863U, 0x0000b420U, 0x00000010U);

            r_rsip_func_sub022(0x00000842U, 0x0000b400U, 0x00000004U);

            WR1_PROG(REG_0094H, 0x0000a8e0U);
            WR1_PROG(REG_0094H, 0x00000005U);

            for (iLoop = 0U; iLoop < KEY_INDEX_SIZE - 5; )
            {
                r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0xf7008d05U);
                WR4_ADDR(REG_002CH, &InData_WrappedKeyIndex[iLoop + 1]);

                r_rsip_func_sub006(0x80840003U, 0x03410011U, 0x00002461U, 0x00002440U);

                static const uint32_t Param_p8f_func101_007[] =
                {
                    BSWAP_32BIG_C(0x17d38572U), BSWAP_32BIG_C(0xc85cf38aU), BSWAP_32BIG_C(0xc82dd22aU), BSWAP_32BIG_C(
                        0xcaa78cbbU),
                };
                r_rsip_func101(Param_p8f_func101_007);
                iLoop = iLoop + 4U;
            }

            r_rsip_func_sub016(0x38000847U, 0x00000080U, 0x00270000U);

            WR1_PROG(REG_0040H, 0x00402000U);

            r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
            WR4_ADDR(REG_002CH, &InData_WrappedKeyIndex[iLoop + 1]);

            r_rsip_func_sub013(0x9c100005U, 0x00410011U);

            static const uint32_t Param_p8f_func100_004[] =
            {
                BSWAP_32BIG_C(0x75bbd83cU), BSWAP_32BIG_C(0x23a579a9U), BSWAP_32BIG_C(0x4045e828U), BSWAP_32BIG_C(
                    0xbc74141aU),
            };
            r_rsip_func100(Param_p8f_func100_004);
            WR1_PROG(REG_0040H, 0x00400000U);

            if (CHCK_STS(REG_0040H, 22, 1))
            {
                static const uint32_t Param_p8f_func102_003[] =
                {
                    BSWAP_32BIG_C(0x3b0460f9U), BSWAP_32BIG_C(0xe369c89eU), BSWAP_32BIG_C(0x65423aaaU), BSWAP_32BIG_C(
                        0x76791c44U),
                };
                r_rsip_func102(Param_p8f_func102_003);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func_sub016(0x38000c84U, 0x00000080U, 0x00270000U);

                static const uint32_t Param_p8f_func100_005[] =
                {
                    BSWAP_32BIG_C(0x1df3bd3aU), BSWAP_32BIG_C(0xb36560b3U), BSWAP_32BIG_C(0x7bbb6b20U), BSWAP_32BIG_C(
                        0x1dafb02bU),
                };
                r_rsip_func100(Param_p8f_func100_005);
                WR1_PROG(REG_0040H, 0x00400000U);

                if (CHCK_STS(REG_0040H, 22, 1))
                {
                    static const uint32_t Param_p8f_func100_006[] =
                    {
                        BSWAP_32BIG_C(0x882e7c90U), BSWAP_32BIG_C(0xef6d64dfU), BSWAP_32BIG_C(0x722a0431U),
                        BSWAP_32BIG_C(0xd44f3774U),
                    };
                    r_rsip_func100(Param_p8f_func100_006);

                    WR1_PROG(REG_00D0H, 0x08000085U);
                    r_rsip_func_sub009(0x00000801U, 0x00430009U, 0x00001800U);

                    r_rsip_func_sub009(0x00000802U, 0x00430009U, 0x00001800U);

                    WR1_PROG(REG_00D4H, 0x00000000U);

                    static const uint32_t Param_p8f_func101_008[] =
                    {
                        BSWAP_32BIG_C(0x14dd885bU), BSWAP_32BIG_C(0x2783dd9cU), BSWAP_32BIG_C(0x7cf03258U),
                        BSWAP_32BIG_C(0x799f97a5U),
                    };
                    r_rsip_func101(Param_p8f_func101_008);
                }
                else
                {
                    static const uint32_t Param_p8f_func100_007[] =
                    {
                        BSWAP_32BIG_C(0xca6ac8fcU), BSWAP_32BIG_C(0x7b1be157U), BSWAP_32BIG_C(0xfdab8e4fU),
                        BSWAP_32BIG_C(0x64d6fcf0U),
                    };
                    r_rsip_func100(Param_p8f_func100_007);

                    WR1_PROG(REG_00D0H, 0x08000085U);
                    r_rsip_func_sub009(0x0000181eU, 0x00430011U, 0x00001800U);

                    static const uint32_t Param_p8f_func100_008[] =
                    {
                        BSWAP_32BIG_C(0x3a567b5dU), BSWAP_32BIG_C(0x8171a245U), BSWAP_32BIG_C(0x3674b621U),
                        BSWAP_32BIG_C(0x15bc4d6bU),
                    };
                    r_rsip_func100(Param_p8f_func100_008);
                    r_rsip_func_sub013(0x08000095U, 0x00430011U);

                    WR1_PROG(REG_00D4H, 0x40000000U);

                    static const uint32_t Param_p8f_func101_009[] =
                    {
                        BSWAP_32BIG_C(0x509fcf21U), BSWAP_32BIG_C(0x4a2606d4U), BSWAP_32BIG_C(0x078af485U),
                        BSWAP_32BIG_C(0xb6a5bde6U),
                    };
                    r_rsip_func101(Param_p8f_func101_009);
                }

                r_rsip_func_sub022(0x0000b400U, 0xa6a6a6a6U, 0x00003420U);

                r_rsip_func_sub022(0x0000b480U, 0x00000001U, 0x000008c6U);

                WR1_PROG(REG_0094H, 0x00036ca5U);

                for (jLoop = 0U; jLoop <= 5; jLoop++)
                {
                    WR1_PROG(REG_0094H, 0x000008e7U);

                    for (iLoop = 1; iLoop <= (WRAPPED_KEY_SIZE - 2) / 2; iLoop++)
                    {
                        WR1_PROG(REG_00D0H, 0x0a008105U);
                        r_rsip_func_sub012(0x81020000U, 0x00490009U);
                        r_rsip_func_sub012(0x81820007U, 0x00490009U);

                        r_rsip_func_sub006(0x80040000U, 0x03410011U, 0x00000824U, 0x00003c47U);
                        r_rsip_func_sub022(0x0000a4e0U, 0x00000004U, 0x00003c67U);
                        r_rsip_func_sub022(0x0000a4e0U, 0x00000004U, 0x00002c80U);

                        static const uint32_t Param_p8f_func101_010[] =
                        {
                            BSWAP_32BIG_C(0x86591fc1U), BSWAP_32BIG_C(0x7ac576b6U), BSWAP_32BIG_C(0xe4e61d93U),
                            BSWAP_32BIG_C(0x6a631b88U),
                        };
                        r_rsip_func101(Param_p8f_func101_010);
                    }

                    r_rsip_func_sub016(0x380008e5U, 0x00000080U, 0x00270000U);

                    WR1_PROG(REG_0040H, 0x00402000U);

                    WR1_PROG(REG_0094H, 0x00002cc0U);

                    static const uint32_t Param_p8f_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x31a73bdeU), BSWAP_32BIG_C(0xd5700f7cU), BSWAP_32BIG_C(0x9c886a7eU),
                        BSWAP_32BIG_C(0xafc98011U),
                    };
                    r_rsip_func101(Param_p8f_func101_011);
                }

                r_rsip_func_sub010(0x380088c0U, 0x00000006U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                static const uint32_t Param_p8f_func100_009[] =
                {
                    BSWAP_32BIG_C(0xe7925d08U), BSWAP_32BIG_C(0xf1ab9484U), BSWAP_32BIG_C(0x0962a014U), BSWAP_32BIG_C(
                        0xb83dbbc1U),
                };
                r_rsip_func100(Param_p8f_func100_009);
                r_rsip_func_sub017(0x81020000U, 0x0000500aU);
                RD1_ADDR(REG_002CH, &OutData_Text[0]);
                WAIT_STS(REG_0008H, 30, 1);
                RD1_ADDR(REG_002CH, &OutData_Text[1]);

                r_rsip_func_sub022(0x000008e7U, 0x00000863U, 0x000368a5U);

                for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; )
                {
                    r_rsip_func_sub022(0x000008c6U, 0x34202865U, 0x2000d0c0U);

                    WR1_PROG(REG_0094H, 0x00007c06U);
                    WR1_PROG(REG_0040H, 0x00602000U);

                    static const uint32_t Param_p8f_func100_010[] =
                    {
                        BSWAP_32BIG_C(0xbd92fde4U), BSWAP_32BIG_C(0x5cbaf69bU), BSWAP_32BIG_C(0x86662d92U),
                        BSWAP_32BIG_C(0x73f91c6eU),
                    };
                    r_rsip_func100(Param_p8f_func100_010);
                    r_rsip_func_sub017(0x81820007U, 0x0000500aU);
                    RD1_ADDR(REG_002CH, &OutData_Text[iLoop]);
                    WAIT_STS(REG_0008H, 30, 1);
                    RD1_ADDR(REG_002CH, &OutData_Text[iLoop + 1]);

                    r_rsip_func_sub022(0x0000a4e0U, 0x00000008U, 0x00002c60U);

                    static const uint32_t Param_p8f_func101_012[] =
                    {
                        BSWAP_32BIG_C(0xda605fdfU), BSWAP_32BIG_C(0x30c29b99U), BSWAP_32BIG_C(0xca6fb82fU),
                        BSWAP_32BIG_C(0x612ddfc2U),
                    };
                    r_rsip_func101(Param_p8f_func101_012);
                    iLoop = iLoop + 2;
                }

                r_rsip_func_sub016(0x38000865U, 0x00000080U, 0x00270000U);

                WR1_PROG(REG_0040H, 0x00402000U);

                static const uint32_t Param_p8f_func102_004[] =
                {
                    BSWAP_32BIG_C(0xace8f447U), BSWAP_32BIG_C(0x586e40b4U), BSWAP_32BIG_C(0x97d84f7dU), BSWAP_32BIG_C(
                        0xe080e1e4U),
                };
                r_rsip_func102(Param_p8f_func102_004);
                WR1_PROG(REG_006CH, 0x00000040U);
                WAIT_STS(REG_0020H, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
