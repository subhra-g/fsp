/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_LWIP_PPP_H
#define RM_LWIP_PPP_H

/* LwIP PPP includes. */
#include "netif/ppp/pppapi.h"
#include "netif/ppp/ppp.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

typedef struct st_rm_lwip_ppp_cfg
{
    /* PPP link status callback function. */
    ppp_link_status_cb_fn link_status_cb;
    void                * p_extended_cfg;
} rm_lwip_ppp_cfg_t;

typedef struct st_rm_lwip_ppp_ctrl
{
    /* lwIP PPP control block. */
    ppp_pcb * p_ppp_pcb;

    /* Pointer to the configuration structure */
    rm_lwip_ppp_cfg_t const * p_cfg;
} rm_lwip_ppp_ctrl_t;

typedef struct st_rm_lwip_ppp_instance
{
    rm_lwip_ppp_ctrl_t      * p_ctrl;
    rm_lwip_ppp_cfg_t const * p_cfg;
} rm_lwip_ppp_instance_t;

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
