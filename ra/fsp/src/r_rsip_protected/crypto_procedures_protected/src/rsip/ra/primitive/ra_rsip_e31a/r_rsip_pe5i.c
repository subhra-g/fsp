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

rsip_ret_t r_rsip_pe5i (const uint32_t InData_KeyType[],
                        const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_MsgLen[])
{
    uint32_t iLoop = 0U;

    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x00e50001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func_sub014(0x000001c7U, 0x80010020U);
    WR1_PROG(REG_002CH, InData_KeyType[0]);
    WR1_PROG(REG_0024H, 0x00000000U);
    WR1_PROG(REG_009CH, 0x80010080U);
    WAIT_STS(REG_0014H, 31, 1);
    WR1_PROG(REG_002CH, InData_HashType[0]);

    WR1_PROG(REG_00F0H, 0x00000001U);

    static const uint32_t Param_pe5i_func100_001[] =
    {
        BSWAP_32BIG_C(0xb8f450beU), BSWAP_32BIG_C(0xc16aa67aU), BSWAP_32BIG_C(0x12ac29b5U), BSWAP_32BIG_C(0x3908380bU),
    };
    r_rsip_func100(Param_pe5i_func100_001);
    r_rsip_func_sub022(0x3420a880U, 0x00000002U, 0x2000b480U);
    WR1_PROG(REG_0094H, 0x00000001U);

    WR1_PROG(REG_0094H, 0x00007c04U);
    WR1_PROG(REG_0040H, 0x00600000U);

    if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000000U)
    {
        WR1_PROG(REG_00F4H, 0x00000050U);

        static const uint32_t Param_pe5i_func101_001[] =
        {
            BSWAP_32BIG_C(0xf5501d62U), BSWAP_32BIG_C(0x482fdfeaU), BSWAP_32BIG_C(0x253adad7U), BSWAP_32BIG_C(
                0x5a97f568U),
        };
        r_rsip_func101(Param_pe5i_func101_001);
    }
    else if (RD1_MASK(REG_0044H, 0xffffffffU) == 0x00000001U)
    {
        WR1_PROG(REG_00F4H, 0x000000a0U);

        static const uint32_t Param_pe5i_func101_002[] =
        {
            BSWAP_32BIG_C(0x3f4970c6U), BSWAP_32BIG_C(0xdf9d5e9eU), BSWAP_32BIG_C(0xea6528ecU), BSWAP_32BIG_C(
                0xa72e1b45U),
        };
        r_rsip_func101(Param_pe5i_func101_002);
    }

    WR1_PROG(REG_00F8H, 0x00000003U);

    r_rsip_func_sub016(0x38000c21U, 0x00000080U, 0x00270000U);

    static const uint32_t Param_pe5i_func100_002[] =
    {
        BSWAP_32BIG_C(0xaa99615fU), BSWAP_32BIG_C(0xc448ff0dU), BSWAP_32BIG_C(0x1734e0ceU), BSWAP_32BIG_C(0xdf9f7ffeU),
    };
    r_rsip_func100(Param_pe5i_func100_002);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        r_rsip_func_sub022(0x30003080U, 0x00070020U, 0x0000b4a0U);
        r_rsip_func_sub022(0x0000001bU, 0x0000b460U, 0x00000008U);

        r_rsip_func_sub022(0x00030040U, 0x0000b4a0U, 0x00000028U);

        r_rsip_func_sub022(0x0000b460U, 0x0000000cU, 0x00000080U);
        static const uint32_t Param_pe5i_func101_003[] =
        {
            BSWAP_32BIG_C(0x5176d14dU), BSWAP_32BIG_C(0x2df6c7e9U), BSWAP_32BIG_C(0x2ccdf0a8U), BSWAP_32BIG_C(
                0x44cf8bfdU),
        };
        r_rsip_func101(Param_pe5i_func101_003);
    }
    else
    {
        r_rsip_func_sub022(0x30003080U, 0x00070020U, 0x0000b4a0U);
        r_rsip_func_sub022(0x01b41ce9U, 0x0000b460U, 0x00000010U);

        r_rsip_func_sub022(0x00030040U, 0x0000b4a0U, 0x0199f119U);

        r_rsip_func_sub022(0x0000b460U, 0x00000010U, 0x00000080U);
        static const uint32_t Param_pe5i_func101_004[] =
        {
            BSWAP_32BIG_C(0x9b87e1eaU), BSWAP_32BIG_C(0xca0b3f0eU), BSWAP_32BIG_C(0x52f71078U), BSWAP_32BIG_C(
                0x9302377dU),
        };
        r_rsip_func101(Param_pe5i_func101_004);
    }

    r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
    WR1_PROG(REG_002CH, InData_KeyIndex[0]);
    WR1_PROG(REG_0024H, 0x00000000U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e501U, 0x00000000U);

    static const uint32_t Param_pe5i_func101_005[] =
    {
        BSWAP_32BIG_C(0xee48d1b3U), BSWAP_32BIG_C(0x2c825c02U), BSWAP_32BIG_C(0x19f46de3U), BSWAP_32BIG_C(0xbc7b0d5fU),
    };
    r_rsip_func101(Param_pe5i_func101_005);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x000034c5U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000e501U, 0x00000000U);

    static const uint32_t Param_pe5i_func101_006[] =
    {
        BSWAP_32BIG_C(0xc89d9494U), BSWAP_32BIG_C(0xc9d9bd19U), BSWAP_32BIG_C(0xfbe84003U), BSWAP_32BIG_C(0xd38dc5acU),
    };
    r_rsip_func101(Param_pe5i_func101_006);
    r_rsip_func044();

    static const uint32_t Param_pe5i_func100_003[] =
    {
        BSWAP_32BIG_C(0xc97ec6afU), BSWAP_32BIG_C(0x35d6fb6eU), BSWAP_32BIG_C(0xc9031329U), BSWAP_32BIG_C(0xe01158e3U),
    };
    r_rsip_func100(Param_pe5i_func100_003);
    r_rsip_func_sub017(0x81010060U, 0x00005006U);
    RD1_ADDR(REG_002CH, &S_RAM[0]);
    S_RAM[0] = bswap_32big(S_RAM[0]);

    WR1_PROG(REG_0094H, 0x000008e7U);
    r_rsip_func_sub008(0x000000a1U, 0x08000044U, 0x00000000U);

    r_rsip_func_sub008(0x000000a1U, 0x08000054U, 0x00000000U);

    for (iLoop = 0U; iLoop < S_RAM[0]; )
    {
        r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0xf7008d05U);
        WR4_ADDR(REG_002CH, &InData_KeyIndex[iLoop + 1]);

        r_rsip_func_sub015(0x01410011U, 0x00001800U);

        WR1_PROG(REG_0094H, 0x0000a4e0U);
        WR1_PROG(REG_0094H, 0x00000004U);

        static const uint32_t Param_pe5i_func101_007[] =
        {
            BSWAP_32BIG_C(0xf2ea9863U), BSWAP_32BIG_C(0x7e6ca7eeU), BSWAP_32BIG_C(0x1129ef93U), BSWAP_32BIG_C(
                0x09af1d95U),
        };
        r_rsip_func101(Param_pe5i_func101_007);
        iLoop = iLoop + 4U;
    }

    r_rsip_func_sub016(0x380008e3U, 0x00000080U, 0x00270000U);
    WR1_PROG(REG_0040H, 0x00402000U);

    r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
    WR4_ADDR(REG_002CH, &InData_KeyIndex[iLoop + 1]);

    r_rsip_func_sub013(0x9c100005U, 0x00410011U);

    static const uint32_t Param_pe5i_func100_004[] =
    {
        BSWAP_32BIG_C(0x550d97c7U), BSWAP_32BIG_C(0xaf79750bU), BSWAP_32BIG_C(0x96508788U), BSWAP_32BIG_C(0xc7fe7542U),
    };
    r_rsip_func100(Param_pe5i_func100_004);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_pe5i_func102_001[] =
        {
            BSWAP_32BIG_C(0x6d220011U), BSWAP_32BIG_C(0x7b64b947U), BSWAP_32BIG_C(0xf90c9a5aU), BSWAP_32BIG_C(
                0xd81491edU),
        };
        r_rsip_func102(Param_pe5i_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
        {
            WR1_PROG(REG_0014H, 0x00000020U);
            WR1_PROG(REG_0104H, 0x00000000U);
            WR1_PROG(REG_0014H, 0x00000020U);
            WR1_PROG(REG_0100H, 0x00000080U);

            WR1_PROG(REG_00FCH, 0x00000001U);

            WAIT_STS(REG_0118H, 8, 0);

            WR1_PROG(REG_0014H, 0x00000020U);
            WR1_PROG(REG_0104H, 0x00000000U);
            WR1_PROG(REG_0014H, 0x00000020U);
            WR1_PROG(REG_0100H, 0x00000000U);

            WR1_PROG(REG_00FCH, 0x00000100U);

            static const uint32_t Param_pe5i_func101_008[] =
            {
                BSWAP_32BIG_C(0x116c7367U), BSWAP_32BIG_C(0x0e9747a7U), BSWAP_32BIG_C(0x1b721addU), BSWAP_32BIG_C(
                    0xde8599daU),
            };
            r_rsip_func101(Param_pe5i_func101_008);
        }
        else
        {
            WR1_PROG(REG_0014H, 0x00000040U);
            WR1_PROG(REG_0104H, InData_MsgLen[0]);
            WR1_PROG(REG_0014H, 0x00000040U);
            WR1_PROG(REG_0100H, InData_MsgLen[1]);

            WR1_PROG(REG_00FCH, 0x00000001U);

            static const uint32_t Param_pe5i_func101_009[] =
            {
                BSWAP_32BIG_C(0x285e6963U), BSWAP_32BIG_C(0x506c24e5U), BSWAP_32BIG_C(0x3565c57dU), BSWAP_32BIG_C(
                    0x0296bb93U),
            };
            r_rsip_func101(Param_pe5i_func101_009);
        }

        return RSIP_RET_PASS;
    }
}
