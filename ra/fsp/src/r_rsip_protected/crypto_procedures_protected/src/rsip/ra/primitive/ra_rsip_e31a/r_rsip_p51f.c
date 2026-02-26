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

rsip_ret_t r_rsip_p51f (uint32_t OutData_EncCertificateInfo[])
{
    r_rsip_func_sub011(0x00000bc1U, 0x00000200U, 0xf7029d07U);
    WR4_ADDR(REG_002CH, &S_HEAP[0]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &S_HEAP[4]);
    WAIT_STS(REG_0014H, 31, 1);
    WR4_ADDR(REG_002CH, &S_HEAP[8]);

    r_rsip_func_sub009(0x000094a1U, 0x00c10031U, 0x00001800U);

    r_rsip_func_sub019(0x000003c1U, 0x07020d05U);
    WR4_ADDR(REG_002CH, &S_HEAP[12]);

    r_rsip_func_sub013(0x8c100005U, 0x00410011U);

    static const uint32_t Param_p51f_func100_001[] =
    {
        BSWAP_32BIG_C(0xfd82d4f5U), BSWAP_32BIG_C(0xf5b66892U), BSWAP_32BIG_C(0x9f4ec2edU), BSWAP_32BIG_C(0x83637324U),
    };
    r_rsip_func100(Param_p51f_func100_001);
    r_rsip_func103();

    r_rsip_func_sub008(0x000000a1U, 0x0c200104U, 0x00000000U);

    r_rsip_func_sub005(0x80010000U, 0x03410005U, 0x0001000dU);

    WR1_PROG(REG_0094H, 0x000034c0U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00005102U, 0x00000000U);

    static const uint32_t Param_p51f_func101_001[] =
    {
        BSWAP_32BIG_C(0xcc459173U), BSWAP_32BIG_C(0x9671f15dU), BSWAP_32BIG_C(0x7146683dU), BSWAP_32BIG_C(0x4d2284f1U),
    };
    r_rsip_func101(Param_p51f_func101_001);
    r_rsip_func143();

    WR1_PROG(REG_0094H, 0x0000b4c0U);
    WR1_PROG(REG_0094H, 0x01f6c222U);

    r_rsip_func_sub002(0x000000a7U, 0x800100e0U, 0x00005102U, 0x00000000U);

    static const uint32_t Param_p51f_func101_002[] =
    {
        BSWAP_32BIG_C(0x169bfd27U), BSWAP_32BIG_C(0x09083280U), BSWAP_32BIG_C(0xf21663abU), BSWAP_32BIG_C(0x61ca4a59U),
    };
    r_rsip_func101(Param_p51f_func101_002);
    r_rsip_func044();

    static const uint32_t Param_p51f_func100_002[] =
    {
        BSWAP_32BIG_C(0xfe039474U), BSWAP_32BIG_C(0x7d24ebc6U), BSWAP_32BIG_C(0xf2d4e012U), BSWAP_32BIG_C(0xa2302adeU),
    };
    r_rsip_func100(Param_p51f_func100_002);
    WR1_PROG(REG_00B0H, 0x000098a1U);

    r_rsip_func_sub004(0x40000200U, 0xe7009d07U, 0x00430031U, 0x00001032U);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[5]);
    WAIT_STS(REG_0008H, 30, 1);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[9]);

    static const uint32_t Param_p51f_func100_003[] =
    {
        BSWAP_32BIG_C(0x2710a628U), BSWAP_32BIG_C(0xe37d29dcU), BSWAP_32BIG_C(0x866b8e97U), BSWAP_32BIG_C(0x778547e1U),
    };
    r_rsip_func100(Param_p51f_func100_003);
    r_rsip_func_sub008(0x000000a1U, 0x0c000104U, 0x00000000U);

    r_rsip_func_sub004(0x40000000U, 0x09108105U, 0x00410011U, 0x00001012U);
    RD4_ADDR(REG_002CH, &OutData_EncCertificateInfo[13]);

    static const uint32_t Param_p51f_func100_004[] =
    {
        BSWAP_32BIG_C(0x592dbdc3U), BSWAP_32BIG_C(0xb5c8e716U), BSWAP_32BIG_C(0x1d877095U), BSWAP_32BIG_C(0x2487c2f5U),
    };
    r_rsip_func100(Param_p51f_func100_004);
    r_rsip_func_sub017(0x81010000U, 0x00005006U);
    RD1_ADDR(REG_002CH, &OutData_EncCertificateInfo[0]);

    static const uint32_t Param_p51f_func102_001[] =
    {
        BSWAP_32BIG_C(0x9590be2bU), BSWAP_32BIG_C(0x224b8e63U), BSWAP_32BIG_C(0xdf524aadU), BSWAP_32BIG_C(0x25d41f3dU),
    };
    r_rsip_func102(Param_p51f_func102_001);
    WR1_PROG(REG_006CH, 0x00000040U);
    WAIT_STS(REG_0020H, 12, 0);

    return RSIP_RET_PASS;
}
