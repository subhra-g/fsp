/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/

#include "r_usb_basic.h"
#include "../r_usb_basic/src/driver/inc/r_usb_typedef.h"
#include "../r_usb_basic/src/driver/inc/r_usb_extern.h"
#include "../r_usb_basic/src/hw/inc/r_usb_reg_access.h"

#include "r_usb_huvc_api.h"
#include "r_usb_huvc.h"
#include "r_usb_huvc_driver.h"

/*******************************************************************************************************************//**
 * @addtogroup USB_HUVC USB_HUVC
 * @{
 **********************************************************************************************************************/

/******************************************************************************
 * Macro definitions
 ******************************************************************************/
#define VALUE_32    (32)
#define VALUE_33    (33)
#define VALUE_34    (34)
#define VALUE_35    (35)
#define VALUE_36    (36)
#define VALUE_37    (37)

/******************************************************************************
 * Exported global variables (to be accessed by other files)
 ******************************************************************************/
extern volatile uint32_t g_usb_open_class[];

/*************************************************************************//**
 * @brief Check video version of connected device.
 *
 * @retval FSP_SUCCESS           Successfully completed.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION     Parameter Null pointer error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_HUVC_DeviceInfoGet (usb_ctrl_t * const       p_api_ctrl,
                                    usb_huvc_device_info_t * p_info,
                                    uint8_t                  device_address)
{
    usb_info_t info;
    fsp_err_t  err = FSP_ERR_USB_FAILED;

    usb_instance_ctrl_t * p_ctrl = (usb_instance_ctrl_t *) p_api_ctrl;

    uint8_t * descriptor;
    uint32_t  total_descriptor_length;
    uint32_t  descriptor_length;
    uint32_t  descriptor_type;
    uint32_t  interface_found = USB_FALSE;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_api_ctrl)
    FSP_ASSERT(USB_NULL != p_info)

    FSP_ERROR_RETURN(0 != device_address, FSP_ERR_USB_PARAMETER);
    FSP_ERROR_RETURN(USB_ADDRESS5 >= device_address, FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_ctrl->device_address = device_address;

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_ctrl->module_number) && (USB_IP1 != p_ctrl->module_number)), FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_ctrl->module_number] &
                                  (1 << p_ctrl->type)),
                     FSP_ERR_USB_PARAMETER)                      /* Check USB Open device class */
#endif                                                           /* USB_CFG_PARAM_CHECKING_ENABLE */

    (void) R_USB_InfoGet(p_ctrl, &info, p_ctrl->device_address); /* Get UVC device status */
    if (USB_STATUS_CONFIGURED == info.device_status)             /* Check if UVC device status is CONFIGURED */
    {
        if (NULL != g_p_usb_huvc_config_table[p_ctrl->module_number])
        {
            /* Get the start address of UVC device configuration descriptor */
            descriptor = g_p_usb_huvc_config_table[p_ctrl->module_number];

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
                        if ((USB_IFCLS_VID == descriptor[5]) &&                     /* bInterfaceClass */
                            (USB_HUVC_INTERFACE_SUBCLASS_CONTROL == descriptor[6])) /* bInterfaceSubClass */
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
                            if (USB_HUVC_VC_HEADER == descriptor[2])       /* bDescriptorSubType */
                            {
                                p_info->uvc_version  = descriptor[3];      /* bcdUVC (lo) */
                                p_info->uvc_version |= descriptor[4] << 8; /* bcdUVC (Hi) */
                                return FSP_SUCCESS;
                            }
                        }

                        break;
                    }

                    default:
                    {
                        break;
                    }
                }

                if (descriptor_length > total_descriptor_length)
                {
                    return FSP_ERR_USB_FAILED;
                }

                /* Update the pointer to start address of the next descriptor */
                descriptor += descriptor_length;

                total_descriptor_length -= descriptor_length;
            }

            return FSP_ERR_USB_FAILED;
        }
    }

    return err;
}

/******************************************************************************
 * End of R_USB_HUVC_DeviceInfoGet
 ******************************************************************************/

/*************************************************************************//**
 * @brief Get the appropriate format and frame descriptor information.
 *
 * @retval FSP_SUCCESS           Successfully completed.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION     Parameter Null pointer error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_HUVC_FormatAndFrameInfoGet (usb_ctrl_t * const          p_api_ctrl,
                                            usb_huvc_streaming_info_t * p_info,
                                            uint8_t                     device_address)
{
    usb_info_t info;
    fsp_err_t  err = FSP_ERR_USB_FAILED;
    usb_utr_t  utr;

    usb_instance_ctrl_t * p_ctrl = (usb_instance_ctrl_t *) p_api_ctrl;

    uint32_t  format_index;
    uint32_t  number_of_formats = 0;
    uint8_t * p_ihd             = NULL;
    uint8_t * p_fd              = NULL;
    uint32_t  number_of_frames  = 0;
    uint32_t  frame_index;
    uint32_t  frame_height;
    uint32_t  frame_width;
    uint32_t  min_frame_interval;
    uint32_t  max_frame_interval;
    uint32_t  frame_interval_step;
    uint32_t  frame_interval;
    uint32_t  i;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_api_ctrl)
    FSP_ASSERT(USB_NULL != p_info)

    FSP_ERROR_RETURN(0 != device_address, FSP_ERR_USB_PARAMETER);
    FSP_ERROR_RETURN(USB_ADDRESS5 >= device_address, FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_ctrl->device_address = device_address;

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_ctrl->module_number) && (USB_IP1 != p_ctrl->module_number)), FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_ctrl->module_number] &
                                  (1 << p_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
#endif                                      /* USB_CFG_PARAM_CHECKING_ENABLE */

    /* Initialize the output parameter */
    p_info->p_format_descriptor    = NULL;
    p_info->p_frame_descriptor     = NULL;
    p_info->current_format         = 0;
    p_info->current_frame          = 0;
    p_info->current_frame_interval = 0;

    (void) R_USB_InfoGet(p_ctrl, &info, p_ctrl->device_address); /* Get UVC device status */
    if (USB_STATUS_CONFIGURED == info.device_status)             /* Check if UVC device status is CONFIGURED */
    {
        utr.ip  = p_ctrl->module_number;
        utr.ipp = usb_hstd_get_usb_ip_adr((uint16_t) p_ctrl->module_number);

        usb_huvc_input_header_descriptor_get(&utr, &p_ihd, &p_info->interface_number);

        if (NULL != p_ihd)
        {
            number_of_formats = p_ihd[3]; /* bNumFormats */
        }

        for (format_index = 1; format_index <= number_of_formats; format_index++)
        {
            usb_huvc_format_descriptor_get(&utr, format_index, &p_fd);

            if (NULL != p_fd)
            {
                /* Check the subtype if it same to user requested format type */
                if (p_info->format == p_fd[2])             /* bDescriptorSubtype */
                {
                    /* Save descriptor and format index */
                    p_info->p_format_descriptor = p_fd;
                    p_info->current_format      = p_fd[3]; /* bFormatIndex */
                    number_of_frames            = p_fd[4]; /* bNumFrameDescriptors */

                    break;
                }
            }
        }

        if (format_index > number_of_formats)
        {
            return FSP_ERR_USB_FAILED;
        }

        for (frame_index = 1; frame_index <= number_of_frames; frame_index++)
        {
            usb_huvc_frame_descriptor_get(&utr, frame_index, &p_fd);

            if (NULL != p_fd)
            {
                frame_width  = (uint16_t) p_fd[5];         /* wWidth (Lo) */
                frame_width |= (uint16_t) (p_fd[6] << 8);  /* wWidth (Hi) */

                frame_height  = (uint16_t) p_fd[7];        /* wHeight (Lo) */
                frame_height |= (uint16_t) (p_fd[8] << 8); /* wHeight (Hi) */

                /* Check the frame resolution if it same to requested value */
                if ((frame_width == p_info->width) && (frame_height == p_info->height))
                {
                    /* Save descriptor and frame index. */
                    p_info->p_frame_descriptor = p_fd;
                    p_info->current_frame      = p_fd[3]; /* bFrameIndex */

                    /* Save default interval (dwDefaultFrameInterval) */
                    p_info->current_frame_interval  = (uint32_t) p_fd[21];
                    p_info->current_frame_interval |= (uint32_t) p_fd[22] << 8;
                    p_info->current_frame_interval |= (uint32_t) p_fd[23] << 16;
                    p_info->current_frame_interval |= (uint32_t) p_fd[24] << 24;

                    break;
                }
            }
        }

        if (frame_index > number_of_frames)
        {
            return FSP_ERR_USB_FAILED;
        }

        /* Check the frame interval type */
        if (0 == p_fd[25])             /* bFrameIntervalType (0 : continuous, 1~255 : discrete) */
        {
            /* Frame interval type : continuous */

            /* Get the value of dwMInFrameInterval */
            min_frame_interval  = (uint32_t) p_fd[26];
            min_frame_interval |= (uint32_t) p_fd[27] << 8;
            min_frame_interval |= (uint32_t) p_fd[28] << 16;
            min_frame_interval |= (uint32_t) p_fd[29] << 24;

            /* Get the value of dwMaxFrameInterval */
            max_frame_interval  = (uint32_t) p_fd[30];
            max_frame_interval |= (uint32_t) p_fd[31] << 8;
            max_frame_interval |= (uint32_t) p_fd[VALUE_32] << 16;
            max_frame_interval |= (uint32_t) p_fd[VALUE_33] << 24;

            /* Get the value of dwFrameIntervalStep */
            frame_interval_step  = (uint32_t) p_fd[VALUE_34];
            frame_interval_step |= (uint32_t) p_fd[VALUE_35] << 8;
            frame_interval_step |= (uint32_t) p_fd[VALUE_36] << 16;
            frame_interval_step |= (uint32_t) p_fd[VALUE_37] << 24;

            /* Check the frame interval */
            if (((p_info->interval >= min_frame_interval) && (p_info->interval <= max_frame_interval)) &&
                ((0 == frame_interval_step) || (0 == (p_info->interval - min_frame_interval) % frame_interval_step)))
            {
                /* Save the frame interval */
                p_info->current_frame_interval = p_info->interval;
                err = FSP_SUCCESS;
            }
        }
        else
        {
            /* Frame interval type : discrete */

            for (i = 0; i < p_fd[25]; i++) /* bFrameIntervalType */
            {
                /* Check the frame interval */
                frame_interval  = (uint32_t) p_fd[26 + i * sizeof(uint32_t)];
                frame_interval |= (uint32_t) p_fd[27 + i * sizeof(uint32_t)] << 8;
                frame_interval |= (uint32_t) p_fd[28 + i * sizeof(uint32_t)] << 16;
                frame_interval |= (uint32_t) p_fd[29 + i * sizeof(uint32_t)] << 24;

                if (frame_interval == p_info->interval) /* p_info->interval : User Input */
                {
                    /* Save the frame interval */
                    p_info->current_frame_interval = p_info->interval;
                    err = FSP_SUCCESS;
                    break;
                }
            }
        }
    }

    return err;
}

/******************************************************************************
 * End of R_USB_HUVC_FormatAndFrameInfoGet
 ******************************************************************************/

/*************************************************************************//**
 * @brief Get the alternate number for SET_INTERFACE.
 *
 * @retval FSP_SUCCESS           Successfully completed.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION     Parameter Null pointer error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_HUVC_AlternateNumberGet (usb_ctrl_t * const          p_api_ctrl,
                                         usb_huvc_streaming_info_t * p_info,
                                         uint8_t                     device_address)
{
    usb_info_t info;
    fsp_err_t  err = FSP_ERR_USB_FAILED;

    usb_instance_ctrl_t * p_ctrl = (usb_instance_ctrl_t *) p_api_ctrl;

    uint8_t * descriptor;
    uint32_t  total_descriptor_length;
    uint32_t  descriptor_length;
    uint32_t  descriptor_type;
    uint32_t  interface_found      = USB_FALSE;
    uint32_t  alternate_number     = 0;
    uint32_t  alternate_found      = USB_FALSE;
    uint16_t  payload_size         = 0;
    uint16_t  current_payload_size = 0;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_api_ctrl)
    FSP_ASSERT(USB_NULL != p_info)

    FSP_ERROR_RETURN(0 != device_address, FSP_ERR_USB_PARAMETER);
    FSP_ERROR_RETURN(USB_ADDRESS5 >= device_address, FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_ctrl->device_address = device_address;

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_ctrl->module_number) && (USB_IP1 != p_ctrl->module_number)), FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_ctrl->module_number] &
                                  (1 << p_ctrl->type)),
                     FSP_ERR_USB_PARAMETER) /* Check USB Open device class */
#endif                                      /* USB_CFG_PARAM_CHECKING_ENABLE */

    if (0 == p_info->max_payload_size)
    {
        return FSP_ERR_USB_PARAMETER;
    }

    (void) R_USB_InfoGet(p_ctrl, &info, p_ctrl->device_address); /* Get UVC device status */
    if (USB_STATUS_CONFIGURED == info.device_status)             /* Check if UVC device status is CONFIGURED */
    {
        if (NULL != g_p_usb_huvc_config_table[p_ctrl->module_number])
        {
            /* Get the start address of UVC device configuration descriptor */
            descriptor = g_p_usb_huvc_config_table[p_ctrl->module_number];

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
                            if (0 != descriptor[3])                                   /* bAlternateSetting */
                            {
                                alternate_number = descriptor[3];                     /* bAlternateSetting */
                                interface_found  = USB_TRUE;
                            }
                        }
                        else
                        {
                            interface_found = USB_FALSE;
                        }

                        break;
                    }

                    case USB_DT_ENDPOINT:
                    {
                        if (interface_found)
                        {
                            payload_size = (uint16_t) ((uint16_t) descriptor[4] + (((uint16_t) descriptor[5]) << 8));

                            /* Since RA does not support high-bandwidth transfers,
                             * high-bandwidth endpoints are excluded from the selection. */
                            if (0 == (USB_UVC_VS_EP_MPS_ADDITIONAL_TRANSACTION_PER_MICROFRAME & payload_size))
                            {
                                payload_size &= USB_UVC_VS_EP_MPS_0_ADDITIONAL_TRANSACTION_PER_MICROFRAME;

                                if (payload_size >= p_info->max_payload_size)
                                {
                                    if (USB_FALSE == alternate_found)
                                    {
                                        alternate_found      = USB_TRUE;
                                        current_payload_size = payload_size;

                                        /* Save the alternator number */
                                        p_info->alternate_number = alternate_number;
                                        p_info->max_payload_size = current_payload_size;

                                        err = FSP_SUCCESS;
                                    }
                                    else
                                    {
                                        if (payload_size < current_payload_size)
                                        {
                                            current_payload_size = payload_size;

                                            /* Update the saved alternate number */
                                            p_info->alternate_number = alternate_number;
                                            p_info->max_payload_size = current_payload_size;
                                        }
                                    }
                                }
                            }
                        }

                        break;
                    }

                    default:
                    {
                        break;
                    }
                }

                if (descriptor_length > total_descriptor_length)
                {
                    return FSP_ERR_USB_FAILED;
                }

                /* Update the pointer to start address of the next descriptor */
                descriptor += descriptor_length;

                total_descriptor_length -= descriptor_length;
            }
        }
    }

    return err;
}

/******************************************************************************
 * End of R_USB_HUVC_AlternateNumberGet
 ******************************************************************************/

/*************************************************************************//**
 * @brief Find the interface descriptor for streaming data transfer
 *        and configure the pipe.
 *
 * @retval FSP_SUCCESS           Successfully completed.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_ASSERTION     Parameter Null pointer error.
 * @retval FSP_ERR_USB_PARAMETER Parameter error.
 ******************************************************************************/
fsp_err_t R_USB_HUVC_PipeSet (usb_ctrl_t * const p_api_ctrl,
                              uint32_t           interface_number,
                              uint32_t           alternate_number,
                              uint8_t            device_address)
{
    usb_info_t info;
    fsp_err_t  err = FSP_ERR_USB_FAILED;
    usb_utr_t  utr;

    uint16_t             is_interface_discovered = 0;
    uint16_t             usb_class               = USB_CLASS_INTERNAL_HUVC;
    uint16_t             length = 0;
    uint16_t             offset = 0;
    uint8_t            * p_config;
    uint8_t              pipe_no;
    usb_pipe_table_reg_t ep_tbl;

    usb_instance_ctrl_t * p_ctrl = (usb_instance_ctrl_t *) p_api_ctrl;

#if USB_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(USB_NULL != p_api_ctrl)

    FSP_ERROR_RETURN(0 != device_address, FSP_ERR_USB_PARAMETER);
    FSP_ERROR_RETURN(USB_ADDRESS5 >= device_address, FSP_ERR_USB_PARAMETER)
#endif                                 /* USB_CFG_PARAM_CHECKING_ENABLE */

    p_ctrl->device_address = device_address;

#if USB_CFG_PARAM_CHECKING_ENABLE

    /* Argument Checking */
    FSP_ERROR_RETURN(!((USB_IP0 != p_ctrl->module_number) && (USB_IP1 != p_ctrl->module_number)), FSP_ERR_USB_PARAMETER)

    FSP_ERROR_RETURN(USB_NULL != (g_usb_open_class[p_ctrl->module_number] &
                                  (1 << p_ctrl->type)),
                     FSP_ERR_USB_PARAMETER)                      /* Check USB Open device class */
#endif                                                           /* USB_CFG_PARAM_CHECKING_ENABLE */

    (void) R_USB_InfoGet(p_ctrl, &info, p_ctrl->device_address); /* Get UVC device status */
    if (USB_STATUS_CONFIGURED == info.device_status)             /* Check if UVC device status is CONFIGURED */
    {
        utr.ip            = p_ctrl->module_number;
        utr.ipp           = usb_hstd_get_usb_ip_adr((uint16_t) p_ctrl->module_number);
        utr.p_transfer_rx = p_ctrl->p_transfer_rx;
        utr.p_transfer_tx = p_ctrl->p_transfer_tx;

        if (NULL != g_p_usb_huvc_config_table[p_ctrl->module_number])
        {
            /* Get the start address of UVC device configuration descriptor */
            p_config = g_p_usb_huvc_config_table[p_ctrl->module_number];

            /* Get the total length of UVC device configuration descriptor */
            length = (uint16_t) (*(p_config + 3) << 8);
            length = (uint16_t) (length + *(p_config + 2));

            offset = 0;

            while (offset < length)
            {
                if (USB_DT_INTERFACE == *(p_config + offset + 1))
                {
                    if (interface_number == *(p_config + offset + 2))
                    {
                        if ((alternate_number == *(p_config + offset + 3)) &&
                            (USB_HUVC_INTERFACE_SUBCLASS_STREAMING == *(p_config + offset + 6)))
                        {
                            is_interface_discovered = 1;
                        }
                        else
                        {
                            is_interface_discovered = 0;
                        }
                    }
                }

                if (1 == is_interface_discovered)
                {
                    if (USB_DT_ENDPOINT == *(p_config + offset + USB_EP_B_DESCRIPTORTYPE))
                    {
                        pipe_no =
                            usb_hstd_make_pipe_reg_info(utr.ip, device_address, usb_class,
                                                        g_usb_hstd_device_speed[utr.ip], (p_config + offset), &ep_tbl);
                        if (USB_NULL != pipe_no)
                        {
                            usb_hstd_set_pipe_info(utr.ip, pipe_no, &ep_tbl);
                        }

                        usb_hstd_set_pipe_reg(&utr, pipe_no);
                        err = FSP_SUCCESS;
                        break;
                    }
                }

                /* Update the offset to start address of the next descriptor */
                offset = (uint16_t) (offset + (*(p_config + offset)));
            }
        }
    }

    return err;
}

/******************************************************************************
 * End of R_USB_HUVC_PipeSet
 ******************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup USB_HUVC)
 **********************************************************************************************************************/
