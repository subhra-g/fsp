/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSIP_SUB_FUNC_HEADER_FILE
#define R_RSIP_SUB_FUNC_HEADER_FILE

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_rsip_sel_bit_length
{
    RSIP_SEL_BIT_LENGTH_256,
    RSIP_SEL_BIT_LENGTH_512,
} rsip_sel_bit_length_t;

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
void r_rsip_func_sub001(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub002(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub003(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub004(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub005(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub006(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub007(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub008(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub009(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub010(uint32_t arg1);
void r_rsip_func_sub011(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub012(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub013(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub014(uint32_t arg1, uint32_t arg2);
void r_rsip_func_sub015(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub016(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void r_rsip_func_sub100(const uint32_t ARG1[], const uint32_t PARAM[], rsip_sel_bit_length_t bit_len);

#endif                                 /* R_RSIP_SUB_FUNC_HEADER_FILE */
