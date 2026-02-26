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

rsip_ret_t r_rsip_p6f (const uint32_t InData_LC[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
{
    if (RD1_MASK(REG_006CH, 0x00000017U) != 0)
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0070H, 0x006f0001U);
    WR1_PROG(REG_004CH, 0x00000000U);

    r_rsip_func048(InData_LC);

    WR1_PROG(REG_00A0H, 0x00010000U);

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x0000001cU);

    WR1_PROG(REG_00B0H, 0x000008b2U);
    r_rsip_func_sub005(0x80810006U, 0x00030005U, 0x03430005U);

    r_rsip_func049(InData_Cmd);

    r_rsip_func_sub022(0x00000842U, 0x3420a800U, 0x00000009U);
    r_rsip_func_sub022(0x00070020U, 0x3020a880U, 0x00000020U);
    r_rsip_func_sub022(0x00070020U, 0x0000b440U, 0xFBC000A0U);
    r_rsip_func_sub022(0x00000080U, 0x3020a880U, 0x00000040U);
    r_rsip_func_sub022(0x00070020U, 0x3020a880U, 0x00000020U);
    r_rsip_func_sub022(0x00060020U, 0x0000b440U, 0x00000FCCU);
    r_rsip_func_sub022(0x00000080U, 0x00000080U, 0x00000080U);

    r_rsip_func_sub022(0x000034a4U, 0x00008c80U, 0x0000001fU);

    r_rsip_func056();

    static const uint32_t Param_p6f_func100_001[] =
    {
        BSWAP_32BIG_C(0x117d2578U), BSWAP_32BIG_C(0x597ecda6U), BSWAP_32BIG_C(0xe9e9c784U), BSWAP_32BIG_C(0xcab7460eU),
    };
    r_rsip_func100(Param_p6f_func100_001);
    WR1_PROG(REG_0040H, 0x00400000U);

    if (CHCK_STS(REG_0040H, 22, 1))
    {
        static const uint32_t Param_p6f_func102_001[] =
        {
            BSWAP_32BIG_C(0x3d078b66U), BSWAP_32BIG_C(0xdcf32362U), BSWAP_32BIG_C(0xafdf19d8U), BSWAP_32BIG_C(
                0x7474b7e0U),
        };
        r_rsip_func102(Param_p6f_func102_001);
        WR1_PROG(REG_006CH, 0x00000040U);
        WAIT_STS(REG_0020H, 12, 0);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0094H, 0x00003485U);

        r_rsip_func_sub008(0x000001a1U, 0x07330c04U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x07330d04U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

        r_rsip_func_sub008(0x000001a1U, 0x07330d04U, 0x00000000U);

        WR1_PROG(REG_00D0H, 0x06330104U);
        WAIT_STS(REG_0014H, 31, 1);
        WR1_PROG(REG_002CH, bswap_32big(0x00000000U));

        r_rsip_func_sub009(0x00001404U, 0x00c10021U, 0x00001800U);
        r_rsip_func_sub014(0x000000c7U, 0x800100c0U);
        WR1_PROG(REG_002CH, S_INST2[0]);
        WR1_PROG(REG_0024H, 0x00000000U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000006fU, 0x00000000U);

        static const uint32_t Param_p6f_func101_001[] =
        {
            BSWAP_32BIG_C(0x1fe8c498U), BSWAP_32BIG_C(0x38891264U), BSWAP_32BIG_C(0xc4b80d79U), BSWAP_32BIG_C(
                0xf364bcd7U),
        };
        r_rsip_func101(Param_p6f_func101_001);
        r_rsip_func143();

        WR1_PROG(REG_0094H, 0x0000b4c0U);
        WR1_PROG(REG_0094H, 0x000000ffU);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000006fU, 0x00000000U);

        static const uint32_t Param_p6f_func101_002[] =
        {
            BSWAP_32BIG_C(0xed634e32U), BSWAP_32BIG_C(0x43d18475U), BSWAP_32BIG_C(0x94dcadc2U), BSWAP_32BIG_C(
                0x57b10c95U),
        };
        r_rsip_func101(Param_p6f_func101_002);
        r_rsip_func044();

        static const uint32_t Param_p6f_func100_002[] =
        {
            BSWAP_32BIG_C(0x0fbff413U), BSWAP_32BIG_C(0x51bdb54dU), BSWAP_32BIG_C(0x903947f4U), BSWAP_32BIG_C(
                0x147c0ffdU),
        };
        r_rsip_func100(Param_p6f_func100_002);
        r_rsip_func_sub011(0x000007c1U, 0x40000100U, 0xf7009d07U);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 1]);
        WAIT_STS(REG_0014H, 31, 1);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 5]);

        r_rsip_func_sub013(0x080000a5U, 0x00410011U);

        static const uint32_t Param_p6f_func100_003[] =
        {
            BSWAP_32BIG_C(0x3171f90cU), BSWAP_32BIG_C(0xd184244fU), BSWAP_32BIG_C(0xbb0fd8ccU), BSWAP_32BIG_C(
                0x979e7b58U),
        };
        r_rsip_func100(Param_p6f_func100_003);
        r_rsip_func_sub013(0x080000b5U, 0x00410011U);

        r_rsip_func_sub011(0x000003c1U, 0x40000000U, 0x07008d05U);
        WR4_ADDR(REG_002CH, &S_INST2[0 + 9]);

        r_rsip_func_sub013(0x8c100005U, 0x00410011U);

        r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x0000006fU, 0x00000000U);

        static const uint32_t Param_p6f_func101_003[] =
        {
            BSWAP_32BIG_C(0xfae76168U), BSWAP_32BIG_C(0xc3833d01U), BSWAP_32BIG_C(0xe2533553U), BSWAP_32BIG_C(
                0xc1f1a9f1U),
        };
        r_rsip_func101(Param_p6f_func101_003);
        r_rsip_func157(InData_IV, InData_InstData, OutData_KeyIndex);

        static const uint32_t Param_p6f_func100_004[] =
        {
            BSWAP_32BIG_C(0x117e2f48U), BSWAP_32BIG_C(0x4942e851U), BSWAP_32BIG_C(0x4e178028U), BSWAP_32BIG_C(
                0xfc1b7c0eU),
        };
        r_rsip_func100(Param_p6f_func100_004);
        WR1_PROG(REG_00B0H, 0x00001804U);

        r_rsip_func_sub013(0x080000b5U, 0x00430011U);

        r_rsip_func_sub013(0x08000075U, 0x00430011U);

        static const uint32_t Param_p6f_func100_005[] =
        {
            BSWAP_32BIG_C(0x36e01b0cU), BSWAP_32BIG_C(0x59ea1be8U), BSWAP_32BIG_C(0x0901a3cbU), BSWAP_32BIG_C(
                0x00136dfaU),
        };
        r_rsip_func100(Param_p6f_func100_005);
        WR1_PROG(REG_0040H, 0x00400000U);

        if (CHCK_STS(REG_0040H, 22, 1))
        {
            static const uint32_t Param_p6f_func102_002[] =
            {
                BSWAP_32BIG_C(0xac1fc6b2U), BSWAP_32BIG_C(0xab6c590fU), BSWAP_32BIG_C(0x065dfbf0U), BSWAP_32BIG_C(
                    0x808cd031U),
            };
            r_rsip_func102(Param_p6f_func102_002);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_FAIL;
        }
        else
        {
            static const uint32_t Param_p6f_func100_006[] =
            {
                BSWAP_32BIG_C(0xef4bcc90U), BSWAP_32BIG_C(0x5e1b1c28U), BSWAP_32BIG_C(0x76e6a563U), BSWAP_32BIG_C(
                    0x7c99751bU),
            };
            r_rsip_func100(Param_p6f_func100_006);
            r_rsip_func_sub017(0x81010000U, 0x00005006U);
            RD1_ADDR(REG_002CH, &OutData_KeyIndex[0]);

            static const uint32_t Param_p6f_func102_003[] =
            {
                BSWAP_32BIG_C(0xb3653b43U), BSWAP_32BIG_C(0x24054fa4U), BSWAP_32BIG_C(0xf8f3ab44U), BSWAP_32BIG_C(
                    0xfe284004U),
            };
            r_rsip_func102(Param_p6f_func102_003);
            WR1_PROG(REG_006CH, 0x00000040U);
            WAIT_STS(REG_0020H, 12, 0);

            return RSIP_RET_PASS;
        }
    }
}
