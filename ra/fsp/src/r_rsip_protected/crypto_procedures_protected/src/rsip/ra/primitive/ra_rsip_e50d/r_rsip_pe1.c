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

rsip_ret_t r_rsip_pe1 (const uint32_t InData_Sel_KeyType[],
                       const uint32_t InData_HashType[],
                       const uint32_t InData_Certificate[],
                       const uint32_t InData_CertificateLength[],
                       const uint32_t InData_CertificatePubKey[],
                       const uint32_t InData_EncCertificateInfo[],
                       uint32_t       OutData_KeyIndex[])
{
    uint32_t iLoop = 0U;
    uint32_t jLoop = 0U;
    uint32_t iTemp = 0U;

    if (RD1_MASK(REG_14BCH, 0x0000001fU) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00e10001U);
    WR1_PROG(REG_144CH, 0x00000000U);

    r_rsip_func_sub010(0x000000c7U, 0x800101e0U);
    WR1_PROG(REG_1420H, InData_Sel_KeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub021(0x3420a9e0U, 0x00000009U, 0x2000b5e0U, 0x00000008U);

    r_rsip_func_sub021(0x3000a9e0U, 0x00000006U, 0x00070020U, 0x3000a9e0U);
    r_rsip_func_sub021(0x00000004U, 0x00070020U, 0x0000b5c0U, 0x010f6caaU);

    r_rsip_func_sub021(0x0000b600U, 0x00000008U, 0x00030040U, 0x0000b5c0U);
    r_rsip_func_sub021(0x01f6c222U, 0x0000b600U, 0x0000000cU, 0x00050040U);
    r_rsip_func_sub021(0x0000b5c0U, 0x013a8e02U, 0x0000b600U, 0x00000010U);
    r_rsip_func_sub021(0x00000080U, 0x00000060U, 0x3000a9e0U, 0x00000007U);
    r_rsip_func_sub021(0x00070020U, 0x0000b5c0U, 0x010f6caaU, 0x0000b600U);
    r_rsip_func_sub021(0x00000008U, 0x00030040U, 0x0000b5c0U, 0x01f6c222U);

    r_rsip_func_sub021(0x0000b600U, 0x0000000cU, 0x00050040U, 0x0000b5c0U);
    r_rsip_func_sub021(0x013a8e02U, 0x0000b600U, 0x00000010U, 0x00000080U);
    WR1_PROG(REG_1600H, 0x00000080U);

    static const uint32_t Param_pe1_func100_001[] =
    {
        BSWAP_32BIG_C(0xb402967aU), BSWAP_32BIG_C(0x8a37a034U), BSWAP_32BIG_C(0xa7ea0e94U), BSWAP_32BIG_C(0x3e94e8ceU),
    };
    r_rsip_func100(Param_pe1_func100_001);
    r_rsip_func_sub016(0x81010200U, 0x00005006U);
    RD1_ADDR(REG_1420H, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    r_rsip_func_sub010(0x000000c7U, 0x800100e0U);
    WR1_PROG(REG_1420H, InData_EncCertificateInfo[0]);
    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub003(0x800103a0U, 0x0000e101U);

    static const uint32_t Param_pe1_func101_001[] =
    {
        BSWAP_32BIG_C(0x0a04597dU), BSWAP_32BIG_C(0xf2d8041eU), BSWAP_32BIG_C(0xbc5e29f9U), BSWAP_32BIG_C(0xfc2c346fU),
    };
    r_rsip_func101(Param_pe1_func101_001);
    r_rsip_func043();

    WR1_PROG(REG_1600H, 0x000034eeU);

    r_rsip_func_sub003(0x800103a0U, 0x0000e101U);

    static const uint32_t Param_pe1_func101_002[] =
    {
        BSWAP_32BIG_C(0xc9540137U), BSWAP_32BIG_C(0xd995ff31U), BSWAP_32BIG_C(0xb0a7cf4eU), BSWAP_32BIG_C(0xc2e287a6U),
    };
    r_rsip_func101(Param_pe1_func101_002);
    r_rsip_func044();

    r_rsip_func_sub004(0x08000044U, 0x00000000U);

    r_rsip_func_sub004(0x08000054U, 0x00000000U);

    WR1_PROG(REG_1600H, 0x000008a5U);

    WR1_PROG(REG_1600H, 0x00000800U);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_1420H, &InData_EncCertificateInfo[1 + iLoop]);

        WR1_PROG(REG_1608H, 0x80840000U);
        r_rsip_func_sub001(0x03420011U);

        r_rsip_func_sub021(0x0000a400U, 0x00000010U, 0x0000a4a0U, 0x00000004U);

        static const uint32_t Param_pe1_func101_003[] =
        {
            BSWAP_32BIG_C(0xe6724a0dU), BSWAP_32BIG_C(0x45c62eb2U), BSWAP_32BIG_C(0x2c607da4U), BSWAP_32BIG_C(
                0x92de6debU),
        };
        r_rsip_func101(Param_pe1_func101_003);
        iLoop = iLoop + 4U;
    }

    WR1_PROG(REG_1458H, 0x00000000U);

    r_rsip_func_sub011(0x38000a05U);

    r_rsip_func_sub008(0x000003c2U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_1420H, &InData_EncCertificateInfo[1 + iLoop]);

    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_func_sub001(0x00820011U);

    static const uint32_t Param_pe1_func100_002[] =
    {
        BSWAP_32BIG_C(0xbf71ef6cU), BSWAP_32BIG_C(0xff5c0fdbU), BSWAP_32BIG_C(0xc76f6c8bU), BSWAP_32BIG_C(0x4a4ebcfcU),
    };
    r_rsip_func100(Param_pe1_func100_002);
    WR1_PROG(REG_143CH, 0x00400000U);

    if (CHCK_STS(REG_143CH, 22, 1))
    {
        static const uint32_t Param_pe1_func102_001[] =
        {
            BSWAP_32BIG_C(0xab87a1a5U), BSWAP_32BIG_C(0xf5e9b4b2U), BSWAP_32BIG_C(0x4265aa06U), BSWAP_32BIG_C(
                0x0db6f774U),
        };
        r_rsip_func102(Param_pe1_func102_001);
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func_sub010(0x000000c7U, 0x800102c0U);
        WR1_PROG(REG_1420H, InData_CertificateLength[0]);
        WR1_PROG(REG_1458H, 0x00000000U);

        r_rsip_func_sub010(0x000003c7U, 0x800402e0U);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[0]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[1]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[2]);
        WAIT_STS(REG_1444H, 31, 1);
        WR1_PROG(REG_1420H, InData_CertificatePubKey[3]);
        WR1_PROG(REG_1458H, 0x00000000U);

        WR1_PROG(REG_2000H, 0x00000001U);

        WR1_PROG(REG_1600H, 0x0000b7e0U);
        WR1_PROG(REG_1600H, 0x208e11f0U);

        r_rsip_func_sub006(0x3420a9e0U, 0x00000003U, 0x00260000U);

        static const uint32_t Param_pe1_func100_003[] =
        {
            BSWAP_32BIG_C(0xa33c1fdeU), BSWAP_32BIG_C(0x731ae725U), BSWAP_32BIG_C(0x31065fccU), BSWAP_32BIG_C(
                0x3c4f7d2cU),
        };
        r_rsip_func100(Param_pe1_func100_003);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe1_func100_004[] =
            {
                BSWAP_32BIG_C(0xce200afaU), BSWAP_32BIG_C(0x912432f8U), BSWAP_32BIG_C(0xefa74d9bU), BSWAP_32BIG_C(
                    0x206d6a2eU),
            };
            r_rsip_func100(Param_pe1_func100_004);

            r_rsip_func_sub010(0x000000c7U, 0x80010080U);
            WR1_PROG(REG_1420H, InData_HashType[0]);
            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub021(0x3420a880U, 0x00000006U, 0x2000b480U, 0x00000005U);

            r_rsip_func_sub014(0x00007c04U, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000000U)
            {
                WR1_PROG(REG_2004H, 0x00000040U);

                static const uint32_t Param_pe1_func101_004[] =
                {
                    BSWAP_32BIG_C(0x26294db9U), BSWAP_32BIG_C(0x715e900aU), BSWAP_32BIG_C(0x2f1f1a30U), BSWAP_32BIG_C(
                        0xa66b7cf9U),
                };
                r_rsip_func101(Param_pe1_func101_004);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000001U)
            {
                WR1_PROG(REG_2004H, 0x00000050U);

                static const uint32_t Param_pe1_func101_005[] =
                {
                    BSWAP_32BIG_C(0x799404d4U), BSWAP_32BIG_C(0xa0c7f57aU), BSWAP_32BIG_C(0x2af59006U), BSWAP_32BIG_C(
                        0xcad971efU),
                };
                r_rsip_func101(Param_pe1_func101_005);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000002U)
            {
                WR1_PROG(REG_2004H, 0x00000080U);

                static const uint32_t Param_pe1_func101_006[] =
                {
                    BSWAP_32BIG_C(0xca12218eU), BSWAP_32BIG_C(0x8ac39178U), BSWAP_32BIG_C(0xd92077d5U), BSWAP_32BIG_C(
                        0x37a1cf71U),
                };
                r_rsip_func101(Param_pe1_func101_006);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
            {
                WR1_PROG(REG_2004H, 0x00000090U);

                static const uint32_t Param_pe1_func101_007[] =
                {
                    BSWAP_32BIG_C(0x5441e459U), BSWAP_32BIG_C(0x99ebd00aU), BSWAP_32BIG_C(0x4fb1e2b4U), BSWAP_32BIG_C(
                        0xcd47a6b4U),
                };
                r_rsip_func101(Param_pe1_func101_007);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
            {
                WR1_PROG(REG_2004H, 0x000000a0U);

                static const uint32_t Param_pe1_func101_008[] =
                {
                    BSWAP_32BIG_C(0xb3790030U), BSWAP_32BIG_C(0xe65f6e44U), BSWAP_32BIG_C(0x4bff579aU), BSWAP_32BIG_C(
                        0x622ab2ddU),
                };
                r_rsip_func101(Param_pe1_func101_008);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
            {
                WR1_PROG(REG_2004H, 0x000000b0U);

                static const uint32_t Param_pe1_func101_009[] =
                {
                    BSWAP_32BIG_C(0x6c2bb682U), BSWAP_32BIG_C(0xaf30bba9U), BSWAP_32BIG_C(0xdb97e219U), BSWAP_32BIG_C(
                        0xa4eacc42U),
                };
                r_rsip_func101(Param_pe1_func101_009);
            }

            r_rsip_func_sub021(0x300031e0U, 0x00070020U, 0x0000b400U, 0x000000ffU);

            r_rsip_func_sub021(0x0000b760U, 0x00000040U, 0x0000b5c0U, 0x0000000cU);
            r_rsip_func_sub021(0x00030040U, 0x0000b400U, 0x0000017fU, 0x0000b760U);
            r_rsip_func_sub021(0x00000060U, 0x0000b5c0U, 0x0000000eU, 0x00050040U);
            r_rsip_func_sub021(0x0000b400U, 0x000001ffU, 0x0000b760U, 0x00000080U);

            r_rsip_func_sub021(0x0000b5c0U, 0x00000010U, 0x00000080U, 0x0000b420U);
            r_rsip_func_sub021(0x00000003U, 0x3c002b59U, 0x20000bffU, 0x00002439U);
            WR1_PROG(REG_1600H, 0x3c00283aU);
            WR1_PROG(REG_1600H, 0x20000bffU);

            static const uint32_t Param_pe1_func101_010[] =
            {
                BSWAP_32BIG_C(0x0d93ee35U), BSWAP_32BIG_C(0x8e7d114aU), BSWAP_32BIG_C(0x392877c6U), BSWAP_32BIG_C(
                    0x1fcf1c0aU),
            };
            r_rsip_func101(Param_pe1_func101_010);
        }
        else
        {
            static const uint32_t Param_pe1_func100_005[] =
            {
                BSWAP_32BIG_C(0xe5d267c4U), BSWAP_32BIG_C(0x094f10a9U), BSWAP_32BIG_C(0xa63a1694U), BSWAP_32BIG_C(
                    0x215cf415U),
            };
            r_rsip_func100(Param_pe1_func100_005);
            r_rsip_func_sub014(0x00007c0fU, 0x00600000U);

            if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000003U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                r_rsip_func_sub021(0x0000b400U, 0x0000001fU, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000010U, 0x0000b5c0U, 0x00000016U);

                static const uint32_t Param_pe1_func101_011[] =
                {
                    BSWAP_32BIG_C(0x973b8d7fU), BSWAP_32BIG_C(0x5b5f7d6dU), BSWAP_32BIG_C(0xa7e666e4U), BSWAP_32BIG_C(
                        0x05dbfe4dU),
                };
                r_rsip_func101(Param_pe1_func101_011);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000004U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_2004H, 0x000000a0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000002fU, 0x0000b420U, 0x0000002fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000018U, 0x0000b5c0U, 0x00000018U);

                static const uint32_t Param_pe1_func101_012[] =
                {
                    BSWAP_32BIG_C(0x880ba5aeU), BSWAP_32BIG_C(0x7edf426fU), BSWAP_32BIG_C(0x98dcb40fU), BSWAP_32BIG_C(
                        0xc690cd49U),
                };
                r_rsip_func101(Param_pe1_func101_012);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000005U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000005U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub021(0x0000b400U, 0x00000041U, 0x0000b420U, 0x00000041U);

                r_rsip_func_sub021(0x0000b760U, 0x00000028U, 0x0000b5c0U, 0x00000024U);

                static const uint32_t Param_pe1_func101_013[] =
                {
                    BSWAP_32BIG_C(0xfa2eb851U), BSWAP_32BIG_C(0x97508001U), BSWAP_32BIG_C(0x0eb07d73U), BSWAP_32BIG_C(
                        0xd57be4c5U),
                };
                r_rsip_func101(Param_pe1_func101_013);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000006U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000001U);

                WR1_PROG(REG_2004H, 0x00000050U);

                r_rsip_func_sub021(0x0000b400U, 0x0000001fU, 0x0000b420U, 0x0000001fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000010U, 0x0000b5c0U, 0x0000001cU);

                static const uint32_t Param_pe1_func101_014[] =
                {
                    BSWAP_32BIG_C(0xd0f4b7a5U), BSWAP_32BIG_C(0x68846f8cU), BSWAP_32BIG_C(0x1f127327U), BSWAP_32BIG_C(
                        0x18664eb0U),
                };
                r_rsip_func101(Param_pe1_func101_014);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000007U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_2004H, 0x000000a0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000002fU, 0x0000b420U, 0x0000002fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000018U, 0x0000b5c0U, 0x0000001eU);

                static const uint32_t Param_pe1_func101_015[] =
                {
                    BSWAP_32BIG_C(0x1948eaaaU), BSWAP_32BIG_C(0x6cc5e630U), BSWAP_32BIG_C(0x5063e0e2U), BSWAP_32BIG_C(
                        0xc48f6f02U),
                };
                r_rsip_func101(Param_pe1_func101_015);
            }
            else if (RD1_MASK(REG_1440H, 0xffffffffU) == 0x00000008U)
            {
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1600H, 0x00000005U);

                WR1_PROG(REG_2004H, 0x000000b0U);

                r_rsip_func_sub021(0x0000b400U, 0x0000003fU, 0x0000b420U, 0x0000003fU);

                r_rsip_func_sub021(0x0000b760U, 0x00000020U, 0x0000b5c0U, 0x00000020U);

                static const uint32_t Param_pe1_func101_016[] =
                {
                    BSWAP_32BIG_C(0x954b37a0U), BSWAP_32BIG_C(0x1c9f495bU), BSWAP_32BIG_C(0x5f866e9eU), BSWAP_32BIG_C(
                        0xee3d5d02U),
                };
                r_rsip_func101(Param_pe1_func101_016);
            }

            r_rsip_func_sub021(0x3c002b3aU, 0x10000bffU, 0x00002439U, 0x0800283aU);
            WR1_PROG(REG_1600H, 0x20000bffU);

            static const uint32_t Param_pe1_func101_017[] =
            {
                BSWAP_32BIG_C(0xadc2022aU), BSWAP_32BIG_C(0x0920a5ddU), BSWAP_32BIG_C(0x3861bd08U), BSWAP_32BIG_C(
                    0xc508ce01U),
            };
            r_rsip_func101(Param_pe1_func101_017);
        }

        r_rsip_func_sub021(0x3c002af8U, 0x10000bffU, 0x3c002b19U, 0x10000bffU);

        r_rsip_func_sub021(0x00002417U, 0x08002818U, 0x20000bffU, 0x3c002b56U);
        WR1_PROG(REG_1600H, 0x10000bffU);

        r_rsip_func_sub006(0x38008be0U, 0x208e11f0U, 0x00A60000U);

        static const uint32_t Param_pe1_func100_006[] =
        {
            BSWAP_32BIG_C(0x4876bf4cU), BSWAP_32BIG_C(0x45b7c2c9U), BSWAP_32BIG_C(0x95828be7U), BSWAP_32BIG_C(
                0xa8fbcc75U),
        };
        r_rsip_func100(Param_pe1_func100_006);
        WR1_PROG(REG_143CH, 0x00400000U);

        if (CHCK_STS(REG_143CH, 22, 1))
        {
            static const uint32_t Param_pe1_func102_002[] =
            {
                BSWAP_32BIG_C(0x32c9b1baU), BSWAP_32BIG_C(0x52d5d084U), BSWAP_32BIG_C(0xe2ab3eafU), BSWAP_32BIG_C(
                    0x99d46e4eU),
            };
            r_rsip_func102(Param_pe1_func102_002);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_pe1_func100_007[] =
            {
                BSWAP_32BIG_C(0x24e83f8fU), BSWAP_32BIG_C(0xa4b6cbabU), BSWAP_32BIG_C(0xa5eb01b4U), BSWAP_32BIG_C(
                    0x95bbb57cU),
            };
            r_rsip_func100(Param_pe1_func100_007);
            r_rsip_func_sub021(0x00000800U, 0x00003436U, 0x01836c01U, 0x00036c21U);

            r_rsip_func_sub016(0x81020000U, 0x0000500aU);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);
            WAIT_STS(REG_1408H, 30, 1);
            RD1_ADDR(REG_1420H, &S_RAM[0 + 1]);
            S_RAM[0 + 1] = bswap_32big(S_RAM[0 + 1]);

            static const uint32_t Param_pe1_func100_008[] =
            {
                BSWAP_32BIG_C(0xd46e31b6U), BSWAP_32BIG_C(0x1d90066fU), BSWAP_32BIG_C(0xf2d62e50U), BSWAP_32BIG_C(
                    0x310783baU),
            };
            r_rsip_func100(Param_pe1_func100_008);
            r_rsip_func_sub033(0x00000040U, S_RAM[0], 0x00000040U, S_RAM[0 + 1]);

            r_rsip_func_sub022(0x00003417U, 0x00046800U, 0x00026c00U);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1600H, 0x000008a5U);

            for (iLoop = 0U; iLoop < S_RAM[0]; )
            {
                WR1_PROG(REG_1444H, 0x000003c4U);
                WAIT_STS(REG_1444H, 31, 1);
                WR4_ADDR(REG_1420H, &InData_Certificate[iLoop]);

                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1600H, 0x00000004U);

                static const uint32_t Param_pe1_func101_018[] =
                {
                    BSWAP_32BIG_C(0x13591c52U), BSWAP_32BIG_C(0x905bbe48U), BSWAP_32BIG_C(0xc8638718U), BSWAP_32BIG_C(
                        0x2cfba1f2U),
                };
                r_rsip_func101(Param_pe1_func101_018);
                iLoop = iLoop + 4U;
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            static const uint32_t Param_pe1_func100_009[] =
            {
                BSWAP_32BIG_C(0x0e1580b9U), BSWAP_32BIG_C(0x233979bbU), BSWAP_32BIG_C(0x31f258e1U), BSWAP_32BIG_C(
                    0xa48e8808U),
            };
            r_rsip_func100(Param_pe1_func100_009);

            r_rsip_func_sub011(0x38000805U);

            WR1_PROG(REG_1000H, 0x00010000U);
            r_rsip_func_sub012(0x10000000U, 0x00003416U, 0x0000a400U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1600H, 0x00026800U);

            r_rsip_func_sub016(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub021(0x00003445U, 0x00026c42U, 0x000034d6U, 0x000030c0U);

            iTemp = iLoop;
            for (iLoop = iTemp; iLoop < S_RAM[0]; iLoop++)
            {
                r_rsip_func_sub010(0x000000c7U, 0x80010120U);
                WR1_PROG(REG_1420H, InData_Certificate[iLoop]);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00000821U);

                for (jLoop = 0U; jLoop < 4; jLoop++)
                {
                    r_rsip_func_sub021(0x00002c20U, 0x01886d09U, 0x00086d29U, 0x00000863U);
                    r_rsip_func_sub022(0x3c002859U, 0x20002c60U, 0x3c002b42U);
                    r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                    static const uint32_t Param_pe1_func100_010[] =
                    {
                        BSWAP_32BIG_C(0x71450306U), BSWAP_32BIG_C(0x57fdef8dU), BSWAP_32BIG_C(0xaef2556fU),
                        BSWAP_32BIG_C(0xb8b5f7c6U),
                    };
                    r_rsip_func100(Param_pe1_func100_010);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        r_rsip_func_sub006(0x3420a9e0U, 0x00000003U, 0x00260000U);

                        static const uint32_t Param_pe1_func100_011[] =
                        {
                            BSWAP_32BIG_C(0xf483fc54U), BSWAP_32BIG_C(0x220c0845U), BSWAP_32BIG_C(0x18062506U),
                            BSWAP_32BIG_C(0x4dfec519U),
                        };
                        r_rsip_func100(Param_pe1_func100_011);
                        WR1_PROG(REG_143CH, 0x00400000U);

                        if (CHCK_STS(REG_143CH, 22, 1))
                        {
                            r_rsip_func_sub022(0x00186d08U, 0x01886e88U, 0x00186908U);

                            static const uint32_t Param_pe1_func101_019[] =
                            {
                                BSWAP_32BIG_C(0xc674d7efU), BSWAP_32BIG_C(0x22406e0fU), BSWAP_32BIG_C(0xf29f06a5U),
                                BSWAP_32BIG_C(0xa10e591fU),
                            };
                            r_rsip_func101(Param_pe1_func101_019);
                        }
                        else
                        {
                            WR1_PROG(REG_1608H, 0x81010100U);
                            r_rsip_func_sub001(0x1009000dU);
                            r_rsip_func_sub001(0x10c90005U);

                            static const uint32_t Param_pe1_func101_020[] =
                            {
                                BSWAP_32BIG_C(0xe22aac5fU), BSWAP_32BIG_C(0xcabf4d08U), BSWAP_32BIG_C(0x0293845bU),
                                BSWAP_32BIG_C(0x56efdb26U),
                            };
                            r_rsip_func101(Param_pe1_func101_020);
                        }

                        WR1_PROG(REG_1458H, 0x00000000U);
                    }

                    WR1_PROG(REG_1458H, 0x00000000U);

                    r_rsip_func_sub021(0x00000863U, 0x3c002857U, 0x20002c60U, 0x3c002b02U);
                    r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                    static const uint32_t Param_pe1_func100_012[] =
                    {
                        BSWAP_32BIG_C(0xad22ce31U), BSWAP_32BIG_C(0xa50828b3U), BSWAP_32BIG_C(0x12e5326bU),
                        BSWAP_32BIG_C(0xff1b0daeU),
                    };
                    r_rsip_func100(Param_pe1_func100_012);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1608H, 0x81010100U);
                        r_rsip_func_sub001(0x1009000dU);
                        r_rsip_func_sub001(0x10c90005U);

                        static const uint32_t Param_pe1_func101_021[] =
                        {
                            BSWAP_32BIG_C(0xd8065143U), BSWAP_32BIG_C(0x67c1794dU), BSWAP_32BIG_C(0x965c3d6aU),
                            BSWAP_32BIG_C(0x8e11a4e9U),
                        };
                        r_rsip_func101(Param_pe1_func101_021);
                    }

                    WR1_PROG(REG_1600H, 0x00000863U);
                    WR1_PROG(REG_1600H, 0x3c0028c2U);
                    r_rsip_func_sub006(0x20002c60U, 0x38000c63U, 0x00260000U);

                    static const uint32_t Param_pe1_func100_013[] =
                    {
                        BSWAP_32BIG_C(0x742d6fe5U), BSWAP_32BIG_C(0x3b79cafcU), BSWAP_32BIG_C(0x17264b0aU),
                        BSWAP_32BIG_C(0x06bf85fbU),
                    };
                    r_rsip_func100(Param_pe1_func100_013);
                    WR1_PROG(REG_143CH, 0x00400000U);

                    if (CHCK_STS(REG_143CH, 22, 1))
                    {
                        WR1_PROG(REG_1608H, 0x81010100U);
                        r_rsip_func_sub001(0x1009000dU);
                        r_rsip_func_sub001(0x11490005U);

                        static const uint32_t Param_pe1_func101_022[] =
                        {
                            BSWAP_32BIG_C(0xd4cd4943U), BSWAP_32BIG_C(0x3a839d96U), BSWAP_32BIG_C(0x6f558885U),
                            BSWAP_32BIG_C(0x456b3c1bU),
                        };
                        r_rsip_func101(Param_pe1_func101_022);
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);

                    static const uint32_t Param_pe1_func101_023[] =
                    {
                        BSWAP_32BIG_C(0xdca6f4f8U), BSWAP_32BIG_C(0xa26290cfU), BSWAP_32BIG_C(0x1e252c82U),
                        BSWAP_32BIG_C(0x825d8dd7U),
                    };
                    r_rsip_func101(Param_pe1_func101_023);
                }

                r_rsip_func_sub006(0x38008820U, 0x00000004U, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_024[] =
                {
                    BSWAP_32BIG_C(0x7e51fdb2U), BSWAP_32BIG_C(0xe1ac117dU), BSWAP_32BIG_C(0x26da5907U), BSWAP_32BIG_C(
                        0x8461c2c5U),
                };
                r_rsip_func101(Param_pe1_func101_024);
            }

            r_rsip_func_sub011(0x38000805U);

            static const uint32_t Param_pe1_func100_014[] =
            {
                BSWAP_32BIG_C(0x42ad859cU), BSWAP_32BIG_C(0xd7099bb7U), BSWAP_32BIG_C(0x3a32a82aU), BSWAP_32BIG_C(
                    0xfbfd699eU),
            };
            r_rsip_func100(Param_pe1_func100_014);
            r_rsip_func_sub021(0x00003416U, 0x00008c00U, 0x00000003U, 0x0000b440U);
            r_rsip_func_sub021(0x00000004U, 0x00002840U, 0x00008c40U, 0x00000003U);

            r_rsip_func_sub016(0x81010040U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            WR1_PROG(REG_1600H, 0x000008a5U);

            WR1_PROG(REG_1600H, 0x00000863U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1608H, 0x81010060U);
                r_rsip_func_sub001(0x11490005U);
                r_rsip_func_sub001(0x1009000dU);

                WR1_PROG(REG_1600H, 0x00086c63U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_025[] =
                {
                    BSWAP_32BIG_C(0x4690b214U), BSWAP_32BIG_C(0xc8131e4fU), BSWAP_32BIG_C(0x3b8eeb54U), BSWAP_32BIG_C(
                        0x36d6c04dU),
                };
                r_rsip_func101(Param_pe1_func101_025);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000845U);

            WAIT_STS(REG_2030H, 4, 1);

            r_rsip_func_sub006(0x00000800U, 0x38000c84U, 0x00260000U);

            r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

            static const uint32_t Param_pe1_func100_015[] =
            {
                BSWAP_32BIG_C(0x054318f1U), BSWAP_32BIG_C(0xe1667fc6U), BSWAP_32BIG_C(0x8a7ecfc2U), BSWAP_32BIG_C(
                    0x762e6989U),
            };
            r_rsip_func100(Param_pe1_func100_015);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                WR1_PROG(REG_1600H, 0x00003200U);

                static const uint32_t Param_pe1_func101_026[] =
                {
                    BSWAP_32BIG_C(0x1f2bfa65U), BSWAP_32BIG_C(0x95a59903U), BSWAP_32BIG_C(0x37c9b0b6U), BSWAP_32BIG_C(
                        0xc04a560aU),
                };
                r_rsip_func101(Param_pe1_func101_026);
            }

            static const uint32_t Param_pe1_func100_016[] =
            {
                BSWAP_32BIG_C(0xa9c81b0bU), BSWAP_32BIG_C(0x77c18a3aU), BSWAP_32BIG_C(0xc494f4e3U), BSWAP_32BIG_C(
                    0xb88ecfc1U),
            };
            r_rsip_func100(Param_pe1_func100_016);
            r_rsip_func_sub016(0x81010200U, 0x00005006U);
            RD1_ADDR(REG_1420H, &S_RAM[0]);
            S_RAM[0] = bswap_32big(S_RAM[0]);

            r_rsip_func_sub022(0x000008a5U, 0x0000b7e0U, 0x208e11f0U);

            for (iLoop = 0U; iLoop < S_RAM[0]; iLoop++)
            {
                WR1_PROG(REG_1608H, 0x80010020U);
                r_rsip_func_sub001(0x03450005U);

                r_rsip_func_sub021(0x00003840U, 0x08002822U, 0x20000bffU, 0x0000a400U);
                WR1_PROG(REG_1600H, 0x00000004U);

                WR1_PROG(REG_1600H, 0x00002ca0U);

                static const uint32_t Param_pe1_func101_027[] =
                {
                    BSWAP_32BIG_C(0x951208c1U), BSWAP_32BIG_C(0x9beabaf8U), BSWAP_32BIG_C(0xb1b7972cU), BSWAP_32BIG_C(
                        0xfc554aa9U),
                };
                r_rsip_func101(Param_pe1_func101_027);
            }

            WR1_PROG(REG_1458H, 0x00000000U);

            r_rsip_func_sub011(0x38000a05U);

            r_rsip_func_sub017(0x38000c84U, 0x00260000U);

            r_rsip_func_sub006(0x38008880U, 0x00000002U, 0x00260000U);

            static const uint32_t Param_pe1_func100_017[] =
            {
                BSWAP_32BIG_C(0x1fb9702eU), BSWAP_32BIG_C(0x652a692eU), BSWAP_32BIG_C(0xdc0e4c52U), BSWAP_32BIG_C(
                    0xfdad16faU),
            };
            r_rsip_func100(Param_pe1_func100_017);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                r_rsip_func_sub022(0x00003840U, 0x38000c42U, 0x20000bffU);

                static const uint32_t Param_pe1_func101_028[] =
                {
                    BSWAP_32BIG_C(0xa77c6bdeU), BSWAP_32BIG_C(0xe5fff345U), BSWAP_32BIG_C(0xaff87867U), BSWAP_32BIG_C(
                        0x2646d99bU),
                };
                r_rsip_func101(Param_pe1_func101_028);
            }

            r_rsip_func_sub006(0x38008be0U, 0x208e11f0U, 0x00A60000U);

            static const uint32_t Param_pe1_func100_018[] =
            {
                BSWAP_32BIG_C(0xb408ff10U), BSWAP_32BIG_C(0xc90828d2U), BSWAP_32BIG_C(0x78a0d6efU), BSWAP_32BIG_C(
                    0x470528f3U),
            };
            r_rsip_func100(Param_pe1_func100_018);
            WR1_PROG(REG_143CH, 0x00400000U);

            if (CHCK_STS(REG_143CH, 22, 1))
            {
                static const uint32_t Param_pe1_func102_003[] =
                {
                    BSWAP_32BIG_C(0xc14fff5cU), BSWAP_32BIG_C(0x965aacfaU), BSWAP_32BIG_C(0x84666b2dU), BSWAP_32BIG_C(
                        0x8c2463bbU),
                };
                r_rsip_func102(Param_pe1_func102_003);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func_sub006(0x380089e0U, 0x00000005U, 0x00260000U);

                static const uint32_t Param_pe1_func100_019[] =
                {
                    BSWAP_32BIG_C(0xeaacafecU), BSWAP_32BIG_C(0xcd1900f5U), BSWAP_32BIG_C(0x36eeb236U), BSWAP_32BIG_C(
                        0x0f2bd19bU),
                };
                r_rsip_func100(Param_pe1_func100_019);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);

                    WR1_PROG(REG_1608H, 0x80a80000U);

                    r_rsip_func_sub001(0x13400039U);

                    WR1_PROG(REG_1404H, 0x10000000U);
                    r_rsip_func_sub001(0x13430109U);

                    r_rsip_func_sub001(0x13400039U);

                    r_rsip_func_sub001(0x13430109U);

                    WR1_PROG(REG_1404H, 0x10000000U);
                    WR1_PROG(REG_1608H, 0x81a80000U);
                    r_rsip_func_sub001(0x00c900a1U);

                    static const uint32_t Param_pe1_func101_029[] =
                    {
                        BSWAP_32BIG_C(0x7cd544faU), BSWAP_32BIG_C(0x0246ad23U), BSWAP_32BIG_C(0x5a00143bU),
                        BSWAP_32BIG_C(0x605649a7U),
                    };
                    r_rsip_func101(Param_pe1_func101_029);
                }

                r_rsip_func_sub003(0x800103a0U, 0x000000e1U);

                static const uint32_t Param_pe1_func101_030[] =
                {
                    BSWAP_32BIG_C(0x9b162d8eU), BSWAP_32BIG_C(0xfe16eca8U), BSWAP_32BIG_C(0x8ac7381dU), BSWAP_32BIG_C(
                        0x0a60e955U),
                };
                r_rsip_func101(Param_pe1_func101_030);
                r_rsip_func103();

                r_rsip_func_sub004(0x0c200104U, 0x00000000U);

                WR1_PROG(REG_1608H, 0x80010000U);
                r_rsip_func_sub001(0x03420005U);
                r_rsip_func_sub001(0x0002000dU);

                WR1_PROG(REG_1600H, 0x000034e0U);

                r_rsip_func_sub003(0x800103a0U, 0x0000e102U);

                static const uint32_t Param_pe1_func101_031[] =
                {
                    BSWAP_32BIG_C(0xeb6f5947U), BSWAP_32BIG_C(0x151c1644U), BSWAP_32BIG_C(0x81c8cb11U), BSWAP_32BIG_C(
                        0x86206473U),
                };
                r_rsip_func101(Param_pe1_func101_031);
                r_rsip_func043();

                WR1_PROG(REG_1600H, 0x000034eeU);

                r_rsip_func_sub003(0x800103a0U, 0x0000e102U);

                static const uint32_t Param_pe1_func101_032[] =
                {
                    BSWAP_32BIG_C(0xa77ef16fU), BSWAP_32BIG_C(0xea9e995fU), BSWAP_32BIG_C(0x91934b4aU), BSWAP_32BIG_C(
                        0x84159788U),
                };
                r_rsip_func101(Param_pe1_func101_032);
                r_rsip_func044();

                static const uint32_t Param_pe1_func100_020[] =
                {
                    BSWAP_32BIG_C(0xabe3b7a4U), BSWAP_32BIG_C(0x9c77a9a4U), BSWAP_32BIG_C(0xc8e6bf51U), BSWAP_32BIG_C(
                        0xbd315ed7U),
                };
                r_rsip_func100(Param_pe1_func100_020);
                r_rsip_func_sub004(0x08000044U, 0x00000000U);

                r_rsip_func_sub004(0x08000054U, 0x00000000U);

                r_rsip_func_sub016(0x81010360U, 0x00005006U);
                RD1_ADDR(REG_1420H, &S_RAM[0]);
                S_RAM[0] = bswap_32big(S_RAM[0]);

                r_rsip_func_sub031(0x00000884U, 0x000008a5U, 0x10000000U);
                for (iLoop = 0U; iLoop < S_RAM[0]; )
                {
                    WR1_PROG(REG_1600H, 0x342028bbU);
                    WR1_PROG(REG_1600H, 0x2000d080U);
                    r_rsip_func_sub014(0x00007c04U, 0x00602000U);

                    static const uint32_t Param_pe1_func100_021[] =
                    {
                        BSWAP_32BIG_C(0x016b8e8cU), BSWAP_32BIG_C(0x05e9e3e6U), BSWAP_32BIG_C(0x7009f85dU),
                        BSWAP_32BIG_C(0x4f281387U),
                    };
                    r_rsip_func100(Param_pe1_func100_021);
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe8008105U);
                    r_rsip_func_sub001(0x00830011U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

                    WR1_PROG(REG_1600H, 0x0000a4a0U);
                    WR1_PROG(REG_1600H, 0x00000004U);

                    static const uint32_t Param_pe1_func101_033[] =
                    {
                        BSWAP_32BIG_C(0xff204b58U), BSWAP_32BIG_C(0x42605f17U), BSWAP_32BIG_C(0x5c4fc156U),
                        BSWAP_32BIG_C(0xf2a74e8fU),
                    };
                    r_rsip_func101(Param_pe1_func101_033);
                    iLoop = iLoop + 4U;
                }

                WR1_PROG(REG_1458H, 0x00000000U);

                r_rsip_func_sub011(0x380008bbU);

                r_rsip_func_sub006(0x3420a9e0U, 0x00000003U, 0x00260000U);

                static const uint32_t Param_pe1_func100_022[] =
                {
                    BSWAP_32BIG_C(0x4ed6c8c5U), BSWAP_32BIG_C(0xaf8eb071U), BSWAP_32BIG_C(0xd4ca9cadU), BSWAP_32BIG_C(
                        0xe053a9c6U),
                };
                r_rsip_func100(Param_pe1_func100_022);
                WR1_PROG(REG_143CH, 0x00400000U);

                if (CHCK_STS(REG_143CH, 22, 1))
                {
                    static const uint32_t Param_pe1_func100_023[] =
                    {
                        BSWAP_32BIG_C(0x1db47114U), BSWAP_32BIG_C(0x32808e97U), BSWAP_32BIG_C(0xe150c690U),
                        BSWAP_32BIG_C(0x55923281U),
                    };
                    r_rsip_func100(Param_pe1_func100_023);
                    r_rsip_func_sub027(0x40000000U, 0xe8008104U, 0x81010280U);
                    r_rsip_func_sub001(0x00890005U);

                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30, 1);
                    RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);
                    iLoop = iLoop + 4;

                    static const uint32_t Param_pe1_func101_034[] =
                    {
                        BSWAP_32BIG_C(0xb51a835dU), BSWAP_32BIG_C(0x70ac051fU), BSWAP_32BIG_C(0x0e356288U),
                        BSWAP_32BIG_C(0x54221436U),
                    };
                    r_rsip_func101(Param_pe1_func101_034);
                }

                static const uint32_t Param_pe1_func100_024[] =
                {
                    BSWAP_32BIG_C(0xed394d43U), BSWAP_32BIG_C(0x93b1089fU), BSWAP_32BIG_C(0x596f1803U), BSWAP_32BIG_C(
                        0xbcf31b70U),
                };
                r_rsip_func100(Param_pe1_func100_024);
                r_rsip_func_sub004(0x0c000104U, 0x00000000U);

                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_func_sub001(0x00820011U);

                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30, 1);
                RD4_ADDR(REG_1420H, &OutData_KeyIndex[1 + iLoop]);

                static const uint32_t Param_pe1_func100_025[] =
                {
                    BSWAP_32BIG_C(0xe2ecd172U), BSWAP_32BIG_C(0xd32b3232U), BSWAP_32BIG_C(0x43f1ec7aU), BSWAP_32BIG_C(
                        0xfa8d9e7cU),
                };
                r_rsip_func100(Param_pe1_func100_025);
                r_rsip_func_sub016(0x81010000U, 0x00005006U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);

                static const uint32_t Param_pe1_func102_004[] =
                {
                    BSWAP_32BIG_C(0x6f1dabfeU), BSWAP_32BIG_C(0xead6bdbcU), BSWAP_32BIG_C(0x656e7494U), BSWAP_32BIG_C(
                        0x4a1d48b8U),
                };
                r_rsip_func102(Param_pe1_func102_004);
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12, 0);

                return RSIP_RET_PASS;
            }
        }
    }
}
