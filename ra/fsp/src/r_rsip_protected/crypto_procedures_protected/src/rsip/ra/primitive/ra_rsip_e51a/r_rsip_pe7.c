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

rsip_ret_t r_rsip_pe7 (const uint32_t InData_HashType[],
                       const uint32_t InData_KDFInfo[],
                       const uint32_t InData_KDFInfo_Count[],
                       const uint32_t InData_OutDataType[],
                       const uint32_t InData_OutDataLocation[],
                       const uint32_t InData_SeqNum[],
                       uint32_t       OutData_HMACKeyIndex[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       OutData_EncIV[])
{
    uint32_t OFS_ADR = 0U;
    uint32_t iLoop   = 0U;
    uint32_t jLoop   = 0U;

    if (RD1_MASK(REG_14B8H, 0x0000001eU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e70001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000002c7U, 0x80030080U);
    WR1_PROG(REG_1420H, InData_HashType[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_KDFInfo_Count[0]);
    WAIT_STS(REG_1444H, 31, 1);
    WR1_PROG(REG_1420H, InData_OutDataType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub024(0x3000a880U, 0x00000003U, 0x00010020U, 0x0000b480U);
    r_rsip_func_sub024(0x00000002U, 0x00000080U, 0x30003080U, 0x00070020U);
    r_rsip_func_sub024(0x0000b680U, 0x08000000U, 0x00030040U, 0x0000b680U);
    r_rsip_func_sub024(0x05555555U, 0x00050040U, 0x0000b680U, 0x04000000U);
    r_rsip_func_sub024(0x00000080U, 0x3000a8c0U, 0x00000009U, 0x00010020U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1600H, 0x00000008U);
    r_rsip_func_sub006(0x00000080U, 0x38000ca5U, 0x00260000U);

    r_rsip_func_sub017(0x34202a85U, 0x00260000U);

    r_rsip_func_sub006(0x380088c0U, 0x00000005U, 0x00260000U);

    static const uint32_t Param_pe7_func100_001[] =
    {
        BSWAP_32BIG_C(0x66e78dc6U), BSWAP_32BIG_C(0x82f80f9cU), BSWAP_32BIG_C(0xea743073U), BSWAP_32BIG_C(0x06cba152U),
    };
    r_rsip_func100(Param_pe7_func100_001);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe7_func102_001[] =
        {
            BSWAP_32BIG_C(0x2f151912U), BSWAP_32BIG_C(0x65d514e8U), BSWAP_32BIG_C(0x8617efe7U), BSWAP_32BIG_C(
                0xb7f69aa0U),
        };
        r_rsip_func102(Param_pe7_func102_001);
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        static const uint32_t Param_pe7_func100_002[] =
        {
            BSWAP_32BIG_C(0xbbc82708U), BSWAP_32BIG_C(0xd2269029U), BSWAP_32BIG_C(0xc7c7e100U), BSWAP_32BIG_C(
                0xe7b8f696U),
        };
        r_rsip_func100(Param_pe7_func100_002);
        r_rsip_func_sub014(0x00007c06U, 0x00600000U);

        if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000005U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_001[] =
            {
                BSWAP_32BIG_C(0xf2f5a516U), BSWAP_32BIG_C(0x06a3b8f1U), BSWAP_32BIG_C(0xcb1dfdb6U), BSWAP_32BIG_C(
                    0x6c39b842U),
            };
            r_rsip_func101(Param_pe7_func101_001);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000007U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_002[] =
            {
                BSWAP_32BIG_C(0x12bd3407U), BSWAP_32BIG_C(0x3cfdda92U), BSWAP_32BIG_C(0x568480cbU), BSWAP_32BIG_C(
                    0x41c5a77eU),
            };
            r_rsip_func101(Param_pe7_func101_002);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000000fU);

            static const uint32_t Param_pe7_func101_003[] =
            {
                BSWAP_32BIG_C(0xc8e83836U), BSWAP_32BIG_C(0x5eae7d6aU), BSWAP_32BIG_C(0x523963bdU), BSWAP_32BIG_C(
                    0x8b39b682U),
            };
            r_rsip_func101(Param_pe7_func101_003);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x00000003U);

            static const uint32_t Param_pe7_func101_004[] =
            {
                BSWAP_32BIG_C(0xe4cf8d06U), BSWAP_32BIG_C(0xb76e6bcdU), BSWAP_32BIG_C(0x0f93404fU), BSWAP_32BIG_C(
                    0xe5bd611dU),
            };
            r_rsip_func101(Param_pe7_func101_004);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x0199e556U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000000bU);

            static const uint32_t Param_pe7_func101_005[] =
            {
                BSWAP_32BIG_C(0xec3e3599U), BSWAP_32BIG_C(0x7b92e833U), BSWAP_32BIG_C(0xf039b581U), BSWAP_32BIG_C(
                    0x8e41bc87U),
            };
            r_rsip_func101(Param_pe7_func101_005);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x0000001bU);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000001fU);

            static const uint32_t Param_pe7_func101_006[] =
            {
                BSWAP_32BIG_C(0x9f21502aU), BSWAP_32BIG_C(0x5940cf6cU), BSWAP_32BIG_C(0x317a571aU), BSWAP_32BIG_C(
                    0xfbde2f68U),
            };
            r_rsip_func101(Param_pe7_func101_006);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000007U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000028U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000002fU);

            static const uint32_t Param_pe7_func101_007[] =
            {
                BSWAP_32BIG_C(0x8f124057U), BSWAP_32BIG_C(0xcc7e625dU), BSWAP_32BIG_C(0x5f49a9c8U), BSWAP_32BIG_C(
                    0x9f11f08fU),
            };
            r_rsip_func101(Param_pe7_func101_007);
        }
        else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000008U)
        {
            WR1_PROG(REG_1600H, 0x0000b520U);
            WR1_PROG(REG_1600H, 0x00000029U);

            r_rsip_func_sub003(0x000000a7U, 0x800101c0U, 0x0000003fU);

            static const uint32_t Param_pe7_func101_008[] =
            {
                BSWAP_32BIG_C(0xb3fa54f9U), BSWAP_32BIG_C(0x128fcf24U), BSWAP_32BIG_C(0xa9193973U), BSWAP_32BIG_C(
                    0xeac5840eU),
            };
            r_rsip_func101(Param_pe7_func101_008);
        }

        r_rsip_func_sub010(0x000000c7U, 0x80010100U);
        WR1_PROG(REG_1420H, InData_OutDataLocation[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub024(0x30003080U, 0x00070020U, 0x0000b600U, 0x0000001fU);

        r_rsip_func_sub024(0x0000b460U, 0x0000000dU, 0x00003685U, 0x00056e94U);
        r_rsip_func_sub024(0x00003280U, 0x00000080U, 0x30003080U, 0x00030020U);

        r_rsip_func_sub024(0x0000b600U, 0x0000002fU, 0x0000b460U, 0x00000011U);

        r_rsip_func_sub024(0x00003685U, 0x00046e94U, 0x000036a5U, 0x00056eb4U);
        r_rsip_func_sub024(0x00002695U, 0x00003280U, 0x00000080U, 0x30003080U);
        r_rsip_func_sub024(0x00050020U, 0x0000b600U, 0x0000003fU, 0x0000b460U);
        r_rsip_func_sub024(0x00000015U, 0x00003685U, 0x00066e94U, 0x00003280U);

        WR1_PROG(REG_1600H, 0x00000080U);

        WR1_PROG(REG_1600H, 0x00003628U);
        r_rsip_func_sub006(0x0000262eU, 0x34202a91U, 0x00260000U);

        r_rsip_func_sub017(0x34202911U, 0x00A60000U);

        static const uint32_t Param_pe7_func100_003[] =
        {
            BSWAP_32BIG_C(0x17ecf5d1U), BSWAP_32BIG_C(0x81f878a2U), BSWAP_32BIG_C(0x038d4301U), BSWAP_32BIG_C(
                0x8f2051eaU),
        };
        r_rsip_func100(Param_pe7_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe7_func102_002[] =
            {
                BSWAP_32BIG_C(0x6233df11U), BSWAP_32BIG_C(0x4c81567cU), BSWAP_32BIG_C(0x4700e274U), BSWAP_32BIG_C(
                    0x4b64a2b9U),
            };
            r_rsip_func102(Param_pe7_func102_002);
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe7_func100_004[] =
            {
                BSWAP_32BIG_C(0x50061ef5U), BSWAP_32BIG_C(0x743fb9ebU), BSWAP_32BIG_C(0x1e955c91U), BSWAP_32BIG_C(
                    0xfff04a32U),
            };
            r_rsip_func100(Param_pe7_func100_004);

            r_rsip_func_sub024(0x00000a73U, 0x00000ab5U, 0x000009efU, 0x00000a94U);

            WR1_PROG(REG_1600H, 0x00000ad6U);

            WR1_PROG(REG_1600H, 0x00000af7U);

            r_rsip_func_sub016(0x81010060U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            OFS_ADR  = S_RAM[0];

            static const uint32_t Param_pe7_func100_005[] =
            {
                BSWAP_32BIG_C(0x693e116bU), BSWAP_32BIG_C(0x67b68b94U), BSWAP_32BIG_C(0xf6860e15U), BSWAP_32BIG_C(
                    0x3d09544eU),
            };
            r_rsip_func100(Param_pe7_func100_005);
            r_rsip_func_sub016(0x810100a0U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1600H, 0x34202a65U);
                WR1_PROG(REG_1600H, 0x2000d2c0U);
                r_rsip_func_sub014(0x00007c16U, 0x00602000U);

                r_rsip_func_sub017(0x34202a35U, 0x00260000U);

                WR1_PROG(REG_1600H, 0x000026b0U);

                WR1_PROG(REG_1600H, 0x34202aa8U);
                r_rsip_func_sub006(0x100026f0U, 0x10002ee0U, 0x00260000U);

                static const uint32_t Param_pe7_func100_006[] =
                {
                    BSWAP_32BIG_C(0xcc04d82fU), BSWAP_32BIG_C(0xfca1088dU), BSWAP_32BIG_C(0x19b61a23U), BSWAP_32BIG_C(
                        0xcd72ff27U),
                };
                r_rsip_func100(Param_pe7_func100_006);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pe7_func101_009[] =
                    {
                        BSWAP_32BIG_C(0xace5090fU), BSWAP_32BIG_C(0xd63de514U), BSWAP_32BIG_C(0xd79a14aaU),
                        BSWAP_32BIG_C(0x3a35994bU),
                    };
                    r_rsip_func101(Param_pe7_func101_009);
                }
                else
                {
                    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
                    WR1_PROG(REG_1420H, InData_KDFInfo[iLoop * OFS_ADR]);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e701U);

                    static const uint32_t Param_pe7_func101_010[] =
                    {
                        BSWAP_32BIG_C(0x0992a21fU), BSWAP_32BIG_C(0x06e5a9a3U), BSWAP_32BIG_C(0xef1cec55U),
                        BSWAP_32BIG_C(0x142cecb4U),
                    };
                    r_rsip_func101(Param_pe7_func101_010);
                    r_rsip_func043();

                    WR1_PROG(REG_1600H, 0x0000b4e0U);
                    WR1_PROG(REG_1600H, 0x01799093U);

                    r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e701U);

                    static const uint32_t Param_pe7_func101_011[] =
                    {
                        BSWAP_32BIG_C(0x9c61fffbU), BSWAP_32BIG_C(0x09e3315bU), BSWAP_32BIG_C(0xcfd3ddfdU),
                        BSWAP_32BIG_C(0x24fcc7abU),
                    };
                    r_rsip_func101(Param_pe7_func101_011);
                    r_rsip_func044();

                    r_rsip_func_sub004(0x08000044U, 0x00000000U);

                    r_rsip_func_sub004(0x08000054U, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x00000842U);

                    for (jLoop = 0U; jLoop < OFS_ADR - 5; )
                    {
                        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
                        WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                        WR1_PROG(REG_1608H, 0x8084000fU);
                        r_rsip_func_sub001(0x03420011U);

                        r_rsip_func_sub024(0x0000a5e0U, 0x00000010U, 0x0000a440U, 0x00000004U);

                        static const uint32_t Param_pe7_func101_012[] =
                        {
                            BSWAP_32BIG_C(0xa571703aU), BSWAP_32BIG_C(0x25c45bd7U), BSWAP_32BIG_C(0x7bed084bU),
                            BSWAP_32BIG_C(0xaa19d7ddU),
                        };
                        r_rsip_func101(Param_pe7_func101_012);
                        jLoop = jLoop + 4U;
                    }

                    r_rsip_func_sub039(0x000037e3U, 0x0000abe0U);
                    r_rsip_func_sub006(0x00000005U, 0x38000be2U, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
                    WR4_ADDR(REG_1420H, &InData_KDFInfo[1 + jLoop + iLoop * OFS_ADR]);

                    WR1_PROG(REG_1A24H, 0x9c100005U);
                    r_rsip_func_sub001(0x00820011U);

                    static const uint32_t Param_pe7_func100_007[] =
                    {
                        BSWAP_32BIG_C(0x6cc70a6cU), BSWAP_32BIG_C(0xf6257653U), BSWAP_32BIG_C(0x5f254811U),
                        BSWAP_32BIG_C(0x51683710U),
                    };
                    r_rsip_func100(Param_pe7_func100_007);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1600H, 0x0000d280U);
                        static const uint32_t Param_pe7_func101_013[] =
                        {
                            BSWAP_32BIG_C(0x351a8e36U), BSWAP_32BIG_C(0x7ae7c091U), BSWAP_32BIG_C(0x8d865b3bU),
                            BSWAP_32BIG_C(0xc77621ecU),
                        };
                        r_rsip_func101(Param_pe7_func101_013);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func101_014[] =
                        {
                            BSWAP_32BIG_C(0x05209ca6U), BSWAP_32BIG_C(0x1e31a528U), BSWAP_32BIG_C(0x509d513bU),
                            BSWAP_32BIG_C(0x21856440U),
                        };
                        r_rsip_func101(Param_pe7_func101_014);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1600H, 0x00002ea0U);

                WR1_PROG(REG_1600H, 0x00002e60U);

                static const uint32_t Param_pe7_func101_015[] =
                {
                    BSWAP_32BIG_C(0x0f72f0e1U), BSWAP_32BIG_C(0xdf4699edU), BSWAP_32BIG_C(0x39f23856U), BSWAP_32BIG_C(
                        0x5e7b7138U),
                };
                r_rsip_func101(Param_pe7_func101_015);
            }

            r_rsip_func_sub011(0x38000a65U);

            r_rsip_func_sub017(0x38000e94U, 0x00A60000U);
            static const uint32_t Param_pe7_func100_008[] =
            {
                BSWAP_32BIG_C(0xda13e26eU), BSWAP_32BIG_C(0xe133728eU), BSWAP_32BIG_C(0xaf77d4a4U), BSWAP_32BIG_C(
                    0x4db6ce65U),
            };
            r_rsip_func100(Param_pe7_func100_008);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe7_func102_003[] =
                {
                    BSWAP_32BIG_C(0xd78e043cU), BSWAP_32BIG_C(0x3dc1bafcU), BSWAP_32BIG_C(0x8e723d8bU), BSWAP_32BIG_C(
                        0x63220465U),
                };
                r_rsip_func102(Param_pe7_func102_003);
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x000000e7U);

                static const uint32_t Param_pe7_func101_016[] =
                {
                    BSWAP_32BIG_C(0xdc3b6733U), BSWAP_32BIG_C(0x382f721dU), BSWAP_32BIG_C(0xc9407de3U), BSWAP_32BIG_C(
                        0x5f0b3e87U),
                };
                r_rsip_func101(Param_pe7_func101_016);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e702U);

                static const uint32_t Param_pe7_func101_017[] =
                {
                    BSWAP_32BIG_C(0x2e0b0276U), BSWAP_32BIG_C(0xad5fab07U), BSWAP_32BIG_C(0xf3d5e64fU), BSWAP_32BIG_C(
                        0x93b1ee25U),
                };
                r_rsip_func101(Param_pe7_func101_017);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034e9U);

                r_rsip_func_sub003(0x000000a7U, 0x800103a0U, 0x0000e702U);

                static const uint32_t Param_pe7_func101_018[] =
                {
                    BSWAP_32BIG_C(0x2135551dU), BSWAP_32BIG_C(0x1ea02da0U), BSWAP_32BIG_C(0xd7ef2847U), BSWAP_32BIG_C(
                        0x5394ae29U),
                };
                r_rsip_func101(Param_pe7_func101_018);
                r_rsip_func044();

                r_rsip_func_sub025(0x00002917U, 0x0000b5e0U, 0x00000080U);

                r_rsip_func_sub006(0x3420a8c0U, 0x00000002U, 0x00260000U);

                static const uint32_t Param_pe7_func100_009[] =
                {
                    BSWAP_32BIG_C(0xcdadaf95U), BSWAP_32BIG_C(0xd3a0e66aU), BSWAP_32BIG_C(0x7b13edaaU), BSWAP_32BIG_C(
                        0xf2ca94f7U),
                };
                r_rsip_func100(Param_pe7_func100_009);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    for (iLoop = 0U; iLoop < 32U; iLoop++)
                    {
                        r_rsip_func_sub024(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                        WR1_PROG(REG_1600H, 0x00002de0U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    WR1_PROG(REG_1600H, 0x0000b5e0U);
                    r_rsip_func_sub006(0x00000080U, 0x38000cc6U, 0x00260000U);

                    static const uint32_t Param_pe7_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x7fa36711U), BSWAP_32BIG_C(0x6a700b27U), BSWAP_32BIG_C(0xea1b607cU),
                        BSWAP_32BIG_C(0x7ddb8d2dU),
                    };
                    r_rsip_func100(Param_pe7_func100_010);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        static const uint32_t Param_pe7_func100_011[] =
                        {
                            BSWAP_32BIG_C(0x44053fd0U), BSWAP_32BIG_C(0x1a0e3326U), BSWAP_32BIG_C(0xe2ed1fd7U),
                            BSWAP_32BIG_C(0xabd3cbfbU),
                        };
                        r_rsip_func100(Param_pe7_func100_011);
                        r_rsip_func_sub029(0x40000000U, 0xe7009d05U, 0x8184000fU);
                        r_rsip_func_sub001(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);

                        static const uint32_t Param_pe7_func100_012[] =
                        {
                            BSWAP_32BIG_C(0xcdcc2e2eU), BSWAP_32BIG_C(0x6a772b76U), BSWAP_32BIG_C(0x44bdff0eU),
                            BSWAP_32BIG_C(0x76dff7feU),
                        };
                        r_rsip_func100(Param_pe7_func100_012);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func101_019[] =
                        {
                            BSWAP_32BIG_C(0x1bc30a38U), BSWAP_32BIG_C(0x93df629bU), BSWAP_32BIG_C(0x557aa8cdU),
                            BSWAP_32BIG_C(0xbb007b11U),
                        };
                        r_rsip_func101(Param_pe7_func101_019);
                    }
                    else
                    {
                        static const uint32_t Param_pe7_func100_013[] =
                        {
                            BSWAP_32BIG_C(0x864f4d31U), BSWAP_32BIG_C(0xc126923bU), BSWAP_32BIG_C(0xb1917342U),
                            BSWAP_32BIG_C(0xb6a08bb0U),
                        };
                        r_rsip_func100(Param_pe7_func100_013);
                        r_rsip_func_sub029(0x40000100U, 0xe7009d07U, 0x8188000fU);
                        r_rsip_func_sub001(0x00890021U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[5]);

                        static const uint32_t Param_pe7_func100_014[] =
                        {
                            BSWAP_32BIG_C(0x42246865U), BSWAP_32BIG_C(0x2b683870U), BSWAP_32BIG_C(0x9e1aff84U),
                            BSWAP_32BIG_C(0x52fc3ab5U),
                        };
                        r_rsip_func100(Param_pe7_func100_014);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_KeyIndex[9]);

                        static const uint32_t Param_pe7_func101_020[] =
                        {
                            BSWAP_32BIG_C(0xa03af004U), BSWAP_32BIG_C(0xe69b5053U), BSWAP_32BIG_C(0x7a3c7f56U),
                            BSWAP_32BIG_C(0x13733d7cU),
                        };
                        r_rsip_func101(Param_pe7_func101_020);
                    }

                    static const uint32_t Param_pe7_func100_015[] =
                    {
                        BSWAP_32BIG_C(0xbfac564aU), BSWAP_32BIG_C(0x479f3edaU), BSWAP_32BIG_C(0xf4bf26c8U),
                        BSWAP_32BIG_C(0xbf659d4fU),
                    };
                    r_rsip_func100(Param_pe7_func100_015);
                    r_rsip_func_sub016(0x81010000U, 0x00005006U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                    static const uint32_t Param_pe7_func102_004[] =
                    {
                        BSWAP_32BIG_C(0x104da134U), BSWAP_32BIG_C(0x22eaaa9fU), BSWAP_32BIG_C(0x7e331779U),
                        BSWAP_32BIG_C(0xd6b28d59U),
                    };
                    r_rsip_func102(Param_pe7_func102_004);
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12, 0);

                    return RSIP_RET_PASS;
                }
                else
                {
                    r_rsip_func_sub006(0x3420a8c0U, 0x00000005U, 0x00A60000U);

                    static const uint32_t Param_pe7_func100_016[] =
                    {
                        BSWAP_32BIG_C(0xccfd197aU), BSWAP_32BIG_C(0x5f232ab6U), BSWAP_32BIG_C(0xfe915969U),
                        BSWAP_32BIG_C(0xa69328d8U),
                    };
                    r_rsip_func100(Param_pe7_func100_016);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        for (iLoop = 0U; iLoop < 64U; iLoop++)
                        {
                            r_rsip_func_sub024(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);

                        r_rsip_func_sub025(0x0000b5e0U, 0x00000080U, 0x000008e7U);

                        static const uint32_t Param_pe7_func100_017[] =
                        {
                            BSWAP_32BIG_C(0x79ae61a0U), BSWAP_32BIG_C(0x1608da44U), BSWAP_32BIG_C(0x0549ac71U),
                            BSWAP_32BIG_C(0xf737a3c3U),
                        };
                        r_rsip_func100(Param_pe7_func100_017);
                        r_rsip_func_sub004(0x08000044U, 0x00000000U);

                        r_rsip_func_sub004(0x08000054U, 0x00000000U);

                        WR1_PROG(REG_1600H, 0x00002dc0U);
                        WR1_PROG(REG_1600H, 0x000269ceU);

                        r_rsip_func_sub016(0x810101c0U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &S_RAM[0]);
                        S_RAM[0] = bswap_32big(S_RAM[0]);

                        for (iLoop = 0U; iLoop < S_RAM[0]; )
                        {
                            static const uint32_t Param_pe7_func100_018[] =
                            {
                                BSWAP_32BIG_C(0xb95fec6bU), BSWAP_32BIG_C(0xcd02edb3U), BSWAP_32BIG_C(0x08a72052U),
                                BSWAP_32BIG_C(0xead94f63U),
                            };
                            r_rsip_func100(Param_pe7_func100_018);
                            r_rsip_func_sub029(0x40000000U, 0xe7008d05U, 0x8184000fU);
                            r_rsip_func_sub001(0x00890011U);

                            WR1_PROG(REG_1408H, 0x00002012U);
                            WAIT_STS(REG_1408H, 30, 1);
                            RD4_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 1]);

                            r_rsip_func_sub024(0x0000a5e0U, 0x00000010U, 0x0000a4e0U, 0x00000004U);

                            static const uint32_t Param_pe7_func101_021[] =
                            {
                                BSWAP_32BIG_C(0x584cbaa9U), BSWAP_32BIG_C(0x4100b76fU), BSWAP_32BIG_C(0x25422872U),
                                BSWAP_32BIG_C(0x8fdedb23U),
                            };
                            r_rsip_func101(Param_pe7_func101_021);
                            iLoop = iLoop + 4U;
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);

                        r_rsip_func_sub011(0x380009c7U);

                        static const uint32_t Param_pe7_func100_019[] =
                        {
                            BSWAP_32BIG_C(0xc1f4458dU), BSWAP_32BIG_C(0xc6ed5e97U), BSWAP_32BIG_C(0x99814f08U),
                            BSWAP_32BIG_C(0xd2bbb6acU),
                        };
                        r_rsip_func100(Param_pe7_func100_019);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_HMACKeyIndex[iLoop + 1]);

                        static const uint32_t Param_pe7_func100_020[] =
                        {
                            BSWAP_32BIG_C(0xe2576ba7U), BSWAP_32BIG_C(0x024d360fU), BSWAP_32BIG_C(0x1de5cf02U),
                            BSWAP_32BIG_C(0xbe08c4d2U),
                        };
                        r_rsip_func100(Param_pe7_func100_020);
                        r_rsip_func_sub016(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &OutData_HMACKeyIndex[0]);

                        static const uint32_t Param_pe7_func102_005[] =
                        {
                            BSWAP_32BIG_C(0x5e1bac4aU), BSWAP_32BIG_C(0x09f27b17U), BSWAP_32BIG_C(0xc35619beU),
                            BSWAP_32BIG_C(0x1f53ac69U),
                        };
                        r_rsip_func102(Param_pe7_func102_005);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                    else
                    {
                        for (iLoop = 0U; iLoop < 16U; iLoop++)
                        {
                            r_rsip_func_sub024(0x00000ab5U, 0x02003aa8U, 0x02003eafU, 0x00002d00U);
                            WR1_PROG(REG_1600H, 0x00002de0U);
                        }

                        r_rsip_func_sub039(0x0000b5e0U, 0x00000080U);

                        r_rsip_func_sub006(0x380088c0U, 0x00000002U, 0x00260000U);

                        static const uint32_t Param_pe7_func100_021[] =
                        {
                            BSWAP_32BIG_C(0xc6903c6bU), BSWAP_32BIG_C(0x21f6649bU), BSWAP_32BIG_C(0x6ff1fb50U),
                            BSWAP_32BIG_C(0x935ca698U),
                        };
                        r_rsip_func100(Param_pe7_func100_021);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            WR1_PROG(REG_1A24H, 0x08000105U);
                            WR1_PROG(REG_1608H, 0x8184000fU);
                            r_rsip_func_sub001(0x00890011U);
                            WR1_PROG(REG_1608H, 0x80040140U);
                            r_rsip_func_sub001(0x03420011U);

                            static const uint32_t Param_pe7_func101_022[] =
                            {
                                BSWAP_32BIG_C(0x07d58005U), BSWAP_32BIG_C(0xa6d5047dU), BSWAP_32BIG_C(0xa47b7ac7U),
                                BSWAP_32BIG_C(0xfc6f30b8U),
                            };
                            r_rsip_func101(Param_pe7_func101_022);
                        }
                        else
                        {
                            r_rsip_func_sub010(0x000001c7U, 0x80020080U);
                            WR1_PROG(REG_1420H, InData_SeqNum[0]);
                            WAIT_STS(REG_1444H, 31, 1);
                            WR1_PROG(REG_1420H, InData_SeqNum[1]);
                            WR1_PROG(REG_1458H, 0x00000000U);

                            r_rsip_func_sub006(0x380088c0U, 0x00000003U, 0x00260000U);

                            static const uint32_t Param_pe7_func100_022[] =
                            {
                                BSWAP_32BIG_C(0x8d6174c4U), BSWAP_32BIG_C(0x662a3f1eU), BSWAP_32BIG_C(0xe8a69f4cU),
                                BSWAP_32BIG_C(0x0f408ceeU),
                            };
                            r_rsip_func100(Param_pe7_func100_022);
                            WR1_PROG(REG_143CH, 0x00400000U);

                            if (CHCK_STS(REG_143CH, 22, 1))
                            {
                                r_rsip_func_sub024(0x0000394fU, 0x00003564U, 0x00003585U, 0x0000b5a0U);
                                WR1_PROG(REG_1600H, 0x00000001U);

                                static const uint32_t Param_pe7_func101_023[] =
                                {
                                    BSWAP_32BIG_C(0xf2d48b40U), BSWAP_32BIG_C(0x28b9ddbcU), BSWAP_32BIG_C(0xdca6df5eU),
                                    BSWAP_32BIG_C(0xfe98daeeU),
                                };
                                r_rsip_func101(Param_pe7_func101_023);
                            }
                            else
                            {
                                WR1_PROG(REG_1A24H, 0x08000105U);
                                WR1_PROG(REG_1608H, 0x8183000fU);
                                r_rsip_func_sub001(0x0089000dU);
                                r_rsip_func_sub001(0x00800005U);
                                WR1_PROG(REG_1608H, 0x80040140U);
                                r_rsip_func_sub001(0x03420011U);

                                r_rsip_func_sub024(0x00000964U, 0x00000985U, 0x0000b5a0U, 0x00000001U);

                                static const uint32_t Param_pe7_func101_024[] =
                                {
                                    BSWAP_32BIG_C(0x67366776U), BSWAP_32BIG_C(0xfc5de326U), BSWAP_32BIG_C(0x93ceaed1U),
                                    BSWAP_32BIG_C(0xa99d8678U),
                                };
                                r_rsip_func101(Param_pe7_func101_024);
                            }
                        }

                        static const uint32_t Param_pe7_func100_023[] =
                        {
                            BSWAP_32BIG_C(0x2fe01943U), BSWAP_32BIG_C(0x678b398fU), BSWAP_32BIG_C(0x55180509U),
                            BSWAP_32BIG_C(0xb177a085U),
                        };
                        r_rsip_func100(Param_pe7_func100_023);
                        r_rsip_func_sub029(0x40000000U, 0xe7009d05U, 0x81040140U);
                        r_rsip_func_sub001(0x00890011U);
                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_EncIV[1]);

                        static const uint32_t Param_pe7_func100_024[] =
                        {
                            BSWAP_32BIG_C(0x515aac5fU), BSWAP_32BIG_C(0x5176d607U), BSWAP_32BIG_C(0xd5aee535U),
                            BSWAP_32BIG_C(0x97d45531U),
                        };
                        r_rsip_func100(Param_pe7_func100_024);
                        r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                        WR1_PROG(REG_1A2CH, 0x40000000U);
                        WR1_PROG(REG_1A24H, 0x09108105U);
                        r_rsip_func_sub001(0x00820011U);

                        WR1_PROG(REG_1408H, 0x00002012U);
                        WAIT_STS(REG_1408H, 30, 1);
                        RD4_ADDR(REG_1420H, &OutData_EncIV[5]);

                        static const uint32_t Param_pe7_func100_025[] =
                        {
                            BSWAP_32BIG_C(0x541431d4U), BSWAP_32BIG_C(0xf3518144U), BSWAP_32BIG_C(0x15642c73U),
                            BSWAP_32BIG_C(0xf072531dU),
                        };
                        r_rsip_func100(Param_pe7_func100_025);
                        r_rsip_func_sub016(0x81010000U, 0x00005006U);
                        RD1_ADDR(REG_1420H, &OutData_EncIV[0]);

                        static const uint32_t Param_pe7_func102_006[] =
                        {
                            BSWAP_32BIG_C(0xdc55094cU), BSWAP_32BIG_C(0x1ea32b4eU), BSWAP_32BIG_C(0x2e3c8351U),
                            BSWAP_32BIG_C(0x9ce89533U),
                        };
                        r_rsip_func102(Param_pe7_func102_006);
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12, 0);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
