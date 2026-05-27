/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/
#include <string.h>

#include <r_usb_basic.h>
#include "r_usb_basic_api.h"
#include "../../../r_usb_basic/src/driver/inc/r_usb_typedef.h"
#include "../../../r_usb_basic/src/driver/inc/r_usb_extern.h"
#include "../../../r_usb_basic/src/hw/inc/r_usb_bitdefine.h"
#include "r_usb_huvc_api.h"
#include "inc/r_usb_huvc_driver.h"

/******************************************************************************
 * Private global variables and functions
 ******************************************************************************/

static void usb_huvc_init(usb_utr_t * ptr, uint16_t data1, uint16_t data2);

/******************************************************************************
 * Exported global variables (to be accessed by other files)
 ******************************************************************************/

const uint16_t g_usb_huvc_device_tpl[] =
{
    USB_CFG_TPLCNT,                    /* Number of tpl table */
    0,                                 /* Reserved */
    USB_CFG_TPL                        /* Vendor ID, Product ID */
};

uint8_t * g_p_usb_huvc_config_table[USB_NUM_USBIP];

#if USB_CFG_COMPLIANCE == USB_CFG_ENABLE
extern const uint16_t USB_CFG_TPL_TABLE[];
#endif                                 /* #if USB_CFG_COMPLIANCE == USB_CFG_ENABLE */

/******************************************************************************
 * Renesas USB Host Video Driver functions
 ******************************************************************************/

#if (BSP_CFG_RTOS == 0)

/******************************************************************************
 * Function Name   : usb_huvc_task
 * Description     : UVC Host task
 * Argument        : stacd    : Task Start Code
 * Return          : none
 ******************************************************************************/
void usb_huvc_task (usb_vp_int_t stacd)
{
    (void) stacd;

    /* Do nothing */
}

/******************************************************************************
 * End of function usb_huvc_task
 ******************************************************************************/
#endif                                 /* (BSP_CFG_RTOS == 0) */

/******************************************************************************
 * Function Name   : usb_huvc_configured
 * Description     : Callback function for UVC device configured
 * Argument        : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *                 : uint16_t     devadr  : Device Adrress
 *                 : uint16_t     data2   : Not used
 * Return value    : none
 ******************************************************************************/
void usb_huvc_configured (usb_utr_t * ptr, uint16_t devadr, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    (void) data2;

    ctrl.module_number  = ptr->ip;               /* Module number setting */
    ctrl.device_address = (uint8_t) devadr;
    ctrl.type           = (usb_class_t) USB_CLASS_HUVC;
    usb_set_event(USB_STATUS_CONFIGURED, &ctrl); /* Set Event()  */
}

/******************************************************************************
 * End of function usb_huvc_configured
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_detach
 * Description     : Callback function for UVC device detach
 * Argument        : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *                 : uint16_t     devadr  : Device Adrress
 *                 : uint16_t     data2   : Not used
 * Return value    : none
 ******************************************************************************/
void usb_huvc_detach (usb_utr_t * ptr, uint16_t devadr, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    (void) data2;
    usb_hstd_clr_pipe_table(ptr->ip, devadr);
    ctrl.module_number  = ptr->ip;           /* Module number setting */
    ctrl.device_address = (uint8_t) devadr;
    ctrl.type           = (usb_class_t) USB_CLASS_HUVC;
    usb_set_event(USB_STATUS_DETACH, &ctrl); /* Set Event()  */

    g_p_usb_huvc_config_table[ptr->ip] = 0;
    g_usb_huvc_iso_in_pipe[ptr->ip]    = 0;
}

/******************************************************************************
 * End of function usb_huvc_detach
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_read_complete
 * Description     : CallBack Function
 * Argument        : usb_utr_t    *mess   : Pointer to usb_utr_t structure.
 *                 : uint16_t     data1   : Not used
 *                 : uint16_t     data2   : Not used
 * Return          : none
 ******************************************************************************/
void usb_huvc_read_complete (usb_utr_t * mess, uint16_t devadr, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    (void) devadr;
    (void) data2;

    ctrl.module_number = mess->ip;                /* Module number setting */
    ctrl.pipe          = (uint8_t) mess->keyword; /* Pipe number setting */
    if (g_usb_huvc_iso_in_pipe[ctrl.module_number] == ctrl.pipe)
    {
        ctrl.type = USB_CLASS_HUVC;
    }

    ctrl.device_address = (uint8_t) (usb_hstd_get_devsel(mess, ctrl.pipe) >> 12);
    ctrl.data_size      = mess->read_req_len - mess->tranlen; /* Set Receive data length */

    switch (mess->status)
    {
        case USB_DATA_OK:
        {
            ctrl.status = FSP_SUCCESS;
            break;
        }

        case USB_DATA_SHT:
        {
            ctrl.status = FSP_ERR_USB_SIZE_SHORT;
            break;
        }

        case USB_DATA_OVR:
        {
            ctrl.status = FSP_ERR_USB_SIZE_OVER;
            break;
        }

        case USB_DATA_ERR:
        default:
        {
            ctrl.status = FSP_ERR_USB_FAILED;
            break;
        }
    }

#if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) mess->cur_task_hdl;
#endif                                              /* (BSP_CFG_RTOS == 2) */

    usb_set_event(USB_STATUS_READ_COMPLETE, &ctrl); /* Set Event()  */
}

/******************************************************************************
 * End of function usb_huvc_read_complete
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_registration
 * Description     : registration of Video class driver
 * Argument        : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 * Return          : none
 ******************************************************************************/
void usb_huvc_registration (usb_utr_t * ptr)
{
    usb_hcdreg_t driver;

    /* Driver registration */
    driver.ifclass = (uint16_t) USB_IFCLS_VID; /* Video Interface */

#if USB_CFG_COMPLIANCE == USB_CFG_ENABLE
    driver.p_tpl = (uint16_t *) USB_CFG_TPL_TABLE;
#else /* #if USB_CFG_COMPLIANCE == USB_CFG_ENABLE */
    driver.p_tpl = (uint16_t *) &g_usb_huvc_device_tpl;         /* Target peripheral list */
#endif /* #if USB_CFG_COMPLIANCE == USB_CFG_ENABLE */
    driver.classinit  = (usb_cb_t) &usb_huvc_init;              /* Driver init */
    driver.classcheck = (usb_cb_check_t) &usb_huvc_class_check; /* Driver check */
    driver.devconfig  = (usb_cb_t) &usb_huvc_configured;        /* Device configured */
    driver.devdetach  = (usb_cb_t) &usb_huvc_detach;            /* Device detach */
    driver.devsuspend = (usb_cb_t) &usb_hstd_dummy_function;    /* Device suspend */
    driver.devresume  = (usb_cb_t) &usb_hstd_dummy_function;    /* Device resume */

    usb_hstd_driver_registration(ptr, &driver);                 /* Host Video class driver registration. */
}

/******************************************************************************
 * End of function usb_huvc_registration
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_init
 * Description     : Initialize of Host Video driver.
 * Arguments       : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *                 : uint16_t     data1   : not use
 *                 : uint16_t     data2   : not use
 * Return value    : none
 ******************************************************************************/
static void usb_huvc_init (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    static uint8_t init = 0;

    (void) data1;
    (void) data2;

    if (0 == (init & (1 << ptr->ip)))
    {
        g_p_usb_huvc_config_table[ptr->ip] = 0;

        init = init | (uint8_t) (1 << ptr->ip);
    }
}

/******************************************************************************
 * End of function usb_huvc_init
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_class_check
 * Description     : class check.
 * Arguments       : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *                 : uint16_t     **table : Pointer to data table.
 * Return          : none
 ******************************************************************************/
void usb_huvc_class_check (usb_utr_t * ptr, uint16_t ** table)
{
    g_p_usb_huvc_config_table[ptr->ip] = (uint8_t *) (table[1]); /* Set configuration descriptor address */

    *table[3] = USB_OK;                                          /* Set class check done  */
}

/******************************************************************************
 * End of function usb_huvc_class_check()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_driver_start
 * Description     : USB host Initialize process
 * Arguments       : none
 * Return          : none
 ******************************************************************************/
void usb_huvc_driver_start (usb_utr_t * ptr)
{
    static uint8_t is_init = USB_NO;

    g_p_usb_huvc_config_table[ptr->ip] = 0;

    if (USB_NO == is_init)
    {
        /* Set host Video Task priority */
#if (BSP_CFG_RTOS == 0)
        usb_cstd_set_task_pri(USB_HUVC_TSK, USB_PRI_4);
#endif                                 /* (BSP_CFG_RTOS == 0) */
        is_init = USB_YES;
    }
}

/******************************************************************************
 * End of function usb_huvc_driver_start()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_input_header_descriptor_get
 * Description     : Find the Video Streaming Input Header Descriptor
 * Arguments       : usb_utr_t  *ptr          : Pointer to usb_utr_t structure
 *                 : uint8_t    **ihd         : Pointer to descriptor
 *                 : uint32_t   *interface_number : Interface number
 * Return          : none
 ******************************************************************************/
void usb_huvc_input_header_descriptor_get (usb_utr_t * ptr, uint8_t ** ihd, uint32_t * interface_number)
{
    uint8_t * descriptor;
    uint32_t  total_descriptor_length;
    uint32_t  descriptor_length;
    uint32_t  descriptor_type;
    uint32_t  interface_found = USB_FALSE;

    *ihd = NULL;

    if (NULL != g_p_usb_huvc_config_table[ptr->ip])
    {
        /* Get the start address of UVC device configuration descriptor */
        descriptor = g_p_usb_huvc_config_table[ptr->ip];

        /* Get the total length of UVC device configuration descriptor */
        total_descriptor_length  = *(descriptor + 2);
        total_descriptor_length |= (uint32_t) (*(descriptor + 3) << 8);

        while (total_descriptor_length)
        {
            descriptor_length = *descriptor;       /* Get each descriptor length */
            descriptor_type   = *(descriptor + 1); /* Get each descriptor type */

            switch (descriptor_type)
            {
                case USB_DT_INTERFACE:
                {
                    if ((USB_IFCLS_VID == descriptor[5]) &&                       /* bInterfaceClass */
                        (USB_HUVC_INTERFACE_SUBCLASS_STREAMING == descriptor[6])) /* bInterfaceSubClass */
                    {
                        interface_found   = USB_TRUE;
                        *interface_number = descriptor[2];                        /* bInterfaceNumber */
                    }
                    else
                    {
                        interface_found = USB_FALSE;
                    }

                    break;
                }

                case USB_HUVC_CS_INTERFACE:
                {
                    if (USB_TRUE == interface_found)
                    {
                        if (USB_HUVC_VS_INPUT_HEADER == descriptor[2]) /* bDescriptorSubtype */
                        {
                            *ihd = descriptor;
                            break;
                        }
                    }
                }
            }

            if (NULL != *ihd)
            {
                break;
            }

            if (descriptor_length > total_descriptor_length)
            {
                return;
            }

            /* Update the pointer to start address of the next descriptor */
            descriptor += descriptor_length;

            total_descriptor_length -= descriptor_length;
        }
    }
}

/******************************************************************************
 * End of function usb_huvc_input_header_descriptor_get()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_format_descriptor_get
 * Description     : Find the Video Streaming Format Type Descriptor
 * Arguments       : usb_utr_t  *ptr          : Pointer to usb_utr_t structure
 *                 : uint32_t   format_index  : Requested format index number
 *                 : uint8_t    **fd          : Pointer to descriptor
 * Return          : none
 ******************************************************************************/
void usb_huvc_format_descriptor_get (usb_utr_t * ptr, uint32_t format_index, uint8_t ** fd)
{
    uint8_t * descriptor;
    uint32_t  total_descriptor_length;
    uint32_t  descriptor_length;
    uint32_t  descriptor_type;
    uint32_t  interface_found = USB_FALSE;

    *fd = NULL;

    if (NULL != g_p_usb_huvc_config_table[ptr->ip])
    {
        /* Get the start address of UVC device configuration descriptor */
        descriptor = g_p_usb_huvc_config_table[ptr->ip];

        /* Get the total length of UVC device configuration descriptor */
        total_descriptor_length  = *(descriptor + 2);
        total_descriptor_length |= (uint32_t) (*(descriptor + 3) << 8);

        while (total_descriptor_length)
        {
            descriptor_length = *descriptor;       /* Get each descriptor length */
            descriptor_type   = *(descriptor + 1); /* Get each descriptor type */

            switch (descriptor_type)
            {
                case USB_DT_INTERFACE:
                {
                    if ((USB_IFCLS_VID == descriptor[5]) &&                       /* bInterfaceClass */
                        (USB_HUVC_INTERFACE_SUBCLASS_STREAMING == descriptor[6])) /* bInterfaceSubClass */
                    {
                        interface_found = USB_TRUE;
                    }
                    else
                    {
                        interface_found = USB_FALSE;
                    }

                    break;
                }

                case USB_HUVC_CS_INTERFACE:
                {
                    if (USB_TRUE == interface_found)
                    {
                        switch (descriptor[2]) /* bDescriptorSubtype */
                        {
                            case USB_HUVC_VS_FORMAT_UNCOMPRESSED:
                            case USB_HUVC_VS_FORMAT_MJPEG:
                            case USB_HUVC_VS_FORMAT_MPEG2TS:
                            case USB_HUVC_VS_FORMAT_DV:
                            case USB_HUVC_VS_FORMAT_FRAME_BASED:
                            case USB_HUVC_VS_FORMAT_STREAM_BASED:
                            {
                                if (format_index == descriptor[3]) /* bFormatIndex */
                                {
                                    *fd = descriptor;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (NULL != *fd)
            {
                break;
            }

            if (descriptor_length > total_descriptor_length)
            {
                return;
            }

            /* Update the pointer to start address of the next descriptor */
            descriptor += descriptor_length;

            total_descriptor_length -= descriptor_length;
        }
    }
}

/******************************************************************************
 * End of function usb_huvc_format_descriptor_get()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_huvc_frame_descriptor_get
 * Description     : Find the Video Streaming Frame Descriptor
 * Arguments       : usb_utr_t  *ptr          : Pointer to usb_utr_t structure
 *                 : uint32_t   frame_index   : Requested frame index number
 *                 : uint8_t    **fd          : Pointer to descriptor
 * Return          : none
 ******************************************************************************/
void usb_huvc_frame_descriptor_get (usb_utr_t * ptr, uint32_t frame_index, uint8_t ** fd)
{
    uint8_t * descriptor;
    uint32_t  total_descriptor_length;
    uint32_t  descriptor_length;
    uint32_t  descriptor_type;
    uint32_t  interface_found = USB_FALSE;

    *fd = NULL;

    if (NULL != g_p_usb_huvc_config_table[ptr->ip])
    {
        /* Get the start address of UVC device configuration descriptor */
        descriptor = g_p_usb_huvc_config_table[ptr->ip];

        /* Get the total length of UVC device configuration descriptor */
        total_descriptor_length  = *(descriptor + 2);
        total_descriptor_length |= (uint32_t) (*(descriptor + 3) << 8);

        while (total_descriptor_length)
        {
            descriptor_length = *descriptor;       /* Get each descriptor length */
            descriptor_type   = *(descriptor + 1); /* Get each descriptor type */

            switch (descriptor_type)
            {
                case USB_DT_INTERFACE:
                {
                    if ((USB_IFCLS_VID == descriptor[5]) &&                       /* bInterfaceClass */
                        (USB_HUVC_INTERFACE_SUBCLASS_STREAMING == descriptor[6])) /* bInterfaceSubClass */
                    {
                        interface_found = USB_TRUE;
                    }
                    else
                    {
                        interface_found = USB_FALSE;
                    }

                    break;
                }

                case USB_HUVC_CS_INTERFACE:
                {
                    if (USB_TRUE == interface_found)
                    {
                        switch (descriptor[2]) /* bDescriptorSubtype */
                        {
                            case USB_HUVC_VS_FRAME_UNCOMPRESSED:
                            case USB_HUVC_VS_FRAME_MJPEG:
                            case USB_HUVC_VS_FRAME_FRAME_BASED:
                            {
                                if (frame_index == descriptor[3]) /* bFrameIndex */
                                {
                                    *fd = descriptor;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (NULL != *fd)
            {
                break;
            }

            if (descriptor_length > total_descriptor_length)
            {
                return;
            }

            /* Update the pointer to start address of the next descriptor */
            descriptor += descriptor_length;

            total_descriptor_length -= descriptor_length;
        }
    }
}

/******************************************************************************
 * End of function usb_huvc_frame_descriptor_get()
 ******************************************************************************/

/******************************************************************************
 * End  Of File
 ******************************************************************************/
