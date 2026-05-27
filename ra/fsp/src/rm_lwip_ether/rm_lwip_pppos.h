/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_LWIP_PPPOS_H
#define RM_LWIP_PPPOS_H

/* LwIP PPPoS includes. */
#include "netif/ppp/pppos.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

typedef struct st_rm_lwip_pppos_specific_cfg
{
    /* Output callback function */
    pppos_output_cb_fn output_cb;

    /* Hardware Instance (UART or USB). */
    void * p_hw_instance;
} rm_lwip_pppos_specific_cfg_t;

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
