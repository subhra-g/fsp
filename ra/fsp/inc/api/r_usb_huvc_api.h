/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_CONNECTIVITY_INTERFACES
 * @defgroup USB_HUVC_API USB HUVC Interface
 * @brief Interface for USB HUVC functions.
 *
 * @section USB_HUVC_API_Summary Summary
 * The USB HUVC interface provides USB Host USB Video Class functionality.
 *
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_USB_HUVC_API_H
#define R_USB_HUVC_API_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/******************************************************************************
 * Macro definitions
 ******************************************************************************/

/* Video Class Specific Descriptor Types */
#define     USB_HUVC_CS_INTERFACE                       (0x24)
#define     USB_HUVC_CS_ENDPOINT                        (0x25)

/* Interface Descriptor Subclass */
#define     USB_HUVC_INTERFACE_SUBCLASS_UNDEFINED                (0x00)
#define     USB_HUVC_INTERFACE_SUBCLASS_CONTROL                  (0x01)
#define     USB_HUVC_INTERFACE_SUBCLASS_STREAMING                (0x02)
#define     USB_HUVC_INTERFACE_SUBCLASS_INTERFACE_COLLECTION     (0x03)

/* Video Class Request IDs */
#define     USB_HUVC_REQUEST_CODE_UNDEFINED             (0x0000)
#define     USB_HUVC_SET_CUR                            (0x0100)
#define     USB_HUVC_GET_CUR                            (0x8100)
#define     USB_HUVC_GET_MIN                            (0x8200)
#define     USB_HUVC_GET_MAX                            (0x8300)
#define     USB_HUVC_GET_RES                            (0x8400)
#define     USB_HUVC_GET_INFO                           (0x8600)
#define     USB_HUVC_GET_DEF                            (0x8700)

/* Video Control Interface Subtype */
#define     USB_HUVC_VC_DESCRIPTOR_UNDEFINED            (0x00)
#define     USB_HUVC_VC_HEADER                          (0x01)
#define     USB_HUVC_VC_INPUT_TERMINAL                  (0x02)
#define     USB_HUVC_VC_OUTPUT_TERMINAL                 (0x03)
#define     USB_HUVC_VC_SELECTOR_UNIT                   (0x04)
#define     USB_HUVC_VC_PROCESSING_UNIT                 (0x05)
#define     USB_HUVC_VC_EXTENSION_UNIT                  (0x06)
#define     USB_HUVC_VC_ENCODING_UNIT                   (0x07)

/* Video Streaming Interface Subtype */
#define     USB_HUVC_VS_UNDEFINED                       (0x00)
#define     USB_HUVC_VS_INPUT_HEADER                    (0x01)
#define     USB_HUVC_VS_OUTPUT_HEADER                   (0x02)
#define     USB_HUVC_VS_STILL_IMAGE_FRAME               (0x03)
#define     USB_HUVC_VS_FORMAT_UNCOMPRESSED             (0x04)
#define     USB_HUVC_VS_FRAME_UNCOMPRESSED              (0x05)
#define     USB_HUVC_VS_FORMAT_MJPEG                    (0x06)
#define     USB_HUVC_VS_FRAME_MJPEG                     (0x07)
#define     USB_HUVC_VS_FORMAT_MPEG2TS                  (0x0A)
#define     USB_HUVC_VS_FORMAT_DV                       (0x0C)
#define     USB_HUVC_VS_COLORFORMAT                     (0x0D)
#define     USB_HUVC_VS_FORMAT_FRAME_BASED              (0x10)
#define     USB_HUVC_VS_FRAME_FRAME_BASED               (0x11)
#define     USB_HUVC_VS_FORMAT_STREAM_BASED             (0x12)
#define     USB_HUVC_VS_FORMAT_H264                     (0x13)
#define     USB_HUVC_VS_FRAME_H264                      (0x14)
#define     USB_HUVC_VS_FORMAT_H264_SIMULCAST           (0x15)
#define     USB_HUVC_VS_FORMAT_VP8                      (0x16)
#define     USB_HUVC_VS_FRAME_VP8                       (0x17)
#define     USB_HUVC_VS_FORMAT_VP8_SIMULCAST            (0x18)

/* Video Streaming Interface Controls */
#define     USB_HUVC_VS_CONTROL_UNDEFINED               (0x00)
#define     USB_HUVC_VS_PROBE_CONTROL                   (0x01)
#define     USB_HUVC_VS_COMMIT_CONTROL                  (0x02)
#define     USB_HUVC_VS_STILL_PROBE_CONTROL             (0x03)
#define     USB_HUVC_VS_STILL_COMMIT_CONTROL            (0x04)
#define     USB_HUVC_VS_STILL_IMAGE_TRIGGER_CONTROL     (0x05)
#define     USB_HUVC_VS_STREAM_ERROR_CODE_CONTROL       (0x06)
#define     USB_HUVC_VS_GENERATE_KEY_FRAME_CONTROL      (0x07)
#define     USB_HUVC_VS_UPDATE_FRAME_SEGMENT_CONTROL    (0x08)
#define     USB_HUVC_VS_SYNCH_DELAY_CONTROL             (0x09)

/*****************************************************************************
 * Struct definition
 ******************************************************************************/

 /* Video Streaming Setting and Information */
typedef struct st_usb_huvc_streaming_info                   
{                   
    uint32_t  format;                   ///< User Input Parameter : Frame format
    uint32_t  width;                    ///< User Input Parameter : Frame width
    uint32_t  height;                   ///< User Input Parameter : Frame height
    uint32_t  interval;                 ///< User Input Parameter : Frame interval
    uint32_t  max_payload_size;         ///< User Input Parameter (and which is overwritten by HUVC Driver later). : Max payload(packet) size
                    
    uint32_t  interface_number;         ///< Set by HUVC Driver : Interface number
    uint32_t  alternate_number;         ///< Set by HUVC Driver : Alternate number

    uint8_t * p_format_descriptor;      ///< Set by HUVC Driver : Pointer to Video Streaming Payload Format Descriptor
    uint32_t  current_format;           ///< Set by HUVC Driver : Current format index number
    uint8_t * p_frame_descriptor;       ///< Set by HUVC Driver : Pointer to Video Streaming Frame Descriptor
    uint32_t  current_frame;            ///< Set by HUVC Driver : Current frame index number
    uint32_t  current_frame_interval;   ///< Set by HUVC Driver : Current frame interval
} usb_huvc_streaming_info_t; 

/** Video Device Information */
typedef struct st_usb_huvc_device_info
{
    uint16_t  uvc_version;               ///< UVC Version
} usb_huvc_device_info_t;

/*****************************************************************************
 * Typedef definitions
 ******************************************************************************/

/** USB HUVC functions implemented at the HAL layer will follow this API. */
typedef struct st_usb_huvc_api
{
    /** Get connected device information.
     *
     * @param[in]   p_ctrl          Pointer to control structure.
     * @param[out]  p_info          Pointer to store video device information.
     * @param[in]   device_address  Device address.
     */
    fsp_err_t (* infoGet)(usb_ctrl_t * const p_ctrl, usb_huvc_device_info_t * p_info, uint8_t device_address);

    /** Get the appropriate format and frame descriptor information.
     *
     * @param[in]       p_ctrl          Pointer to control structure.
     * @param[in,out]   p_info          Pointer to video streaming information.
     * @param[in]       device_address  Device address.
     */
    fsp_err_t (* formatAndFrameInfoGet)(usb_ctrl_t * const p_ctrl, usb_huvc_streaming_info_t * p_info, uint8_t device_address);

    /** Get the alternate number.
     *
     * @param[in]       p_ctrl          Pointer to control structure.
     * @param[in,out]   p_info          Pointer to video streaming information.
     * @param[in]       device_address  Device address.
     */
    fsp_err_t (* alternateNumberGet)(usb_ctrl_t * const p_ctrl, usb_huvc_streaming_info_t * p_info, uint8_t device_address);

    /** Pipe Setting.
     *
     * @param[in]  p_ctrl               Pointer to control structure.
     * @param[in]  interface_number     Interface number used in SET_INTERFACE.
     * @param[in]  alternate_number     Alternate number used in SET_INTERFACE.
     * @param[in]  device_address       Device address.
     */
    fsp_err_t (* pipeSet)(usb_ctrl_t * const p_ctrl, uint32_t interface_number, uint32_t alternate_number, uint8_t device_address);
} usb_huvc_api_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_USB_HUVC_API_H */

/*******************************************************************************************************************//**
 * @} (end addtogroup USB_HUVC_API)
 **********************************************************************************************************************/
