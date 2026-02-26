/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ELC_H
#define BSP_ELC_H

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA0E3
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* UNCRUSTIFY-OFF */

/** Fixed vector enumeration
 * @note This list is device specific.
 * */
typedef enum e_icu_event_ra0e3
{
    ICU_EVENT_IWDT_UNDERFLOW                = (0), // IWDT underflow
    ICU_EVENT_LVD_LVD1                      = (1), // Voltage monitor 1 interrupt
    ICU_EVENT_ICU_IRQ0                      = (2), // External pin interrupt 0
    ICU_EVENT_ICU_IRQ1                      = (3), // External pin interrupt 1
    ICU_EVENT_ICU_IRQ2                      = (4), // External pin interrupt 2
    ICU_EVENT_ICU_IRQ3                      = (5), // External pin interrupt 3
    ICU_EVENT_ICU_IRQ4                      = (6), // External pin interrupt 4
    ICU_EVENT_ICU_IRQ5                      = (7), // External pin interrupt 5
    ICU_EVENT_DTC_COMPLETE                  = (10), // DTC transfer complete
    ICU_EVENT_FCU_FRDYI                     = (11), // Flash ready interrupt
    ICU_EVENT_SAU0_UART_TXI0                = (18), // SAU UART TX 0/I2C 00/SPI 00
    ICU_EVENT_SAU0_SPI_TXRXI00              = (18), // SAU UART TX 0/I2C 00/SPI 00
    ICU_EVENT_SAU0_IIC_TXRXI00              = (18), // SAU UART TX 0/I2C 00/SPI 00
    ICU_EVENT_TAU0_TMI00                    = (19), // End of timer channel 00 count or capture
    ICU_EVENT_SAU0_UART_ERRI0               = (20), // SAU UART Error
    ICU_EVENT_TAU0_TMI01H                   = (21), // End of timer channel 01 count or capture (higher operation)
    ICU_EVENT_SAU0_UART_TXI1                = (22), // SAU UART TX 1/I2C 10/SPI 10
    ICU_EVENT_SAU0_UART_RXI1                = (23), // SAU UART RX 1/I2C 11/SPI 11
    ICU_EVENT_SAU0_SPI_TXRXI11              = (23), // SAU UART RX 1/I2C 11/SPI 11
    ICU_EVENT_SAU0_IIC_TXRXI11              = (23), // SAU UART RX 1/I2C 11/SPI 11
    ICU_EVENT_SAU0_UART_ERRI1               = (24), // SAU UART Error
    ICU_EVENT_TAU0_TMI03H                   = (25), // End of timer channel 03 count or capture (higher operation)
    ICU_EVENT_IICA0_TXRXI                   = (26), // End of IICA0 communication
    ICU_EVENT_SAU0_UART_RXI0                = (27), // SAU UART RX 0/I2C 01/SPI 01
    ICU_EVENT_TAU0_TMI01                    = (28), // End of timer channel 01 count or capture
    ICU_EVENT_TAU0_TMI02                    = (29), // End of timer channel 02 count or capture
    ICU_EVENT_TAU0_TMI03                    = (30), // End of timer channel 03 count or capture
    ICU_EVENT_ADC0_SCAN_END                 = (31), // End of A/D scanning operation
    ICU_EVENT_TML0_ITL_OR                   = (33), // TML timer event
    ICU_EVENT_TML0_ITL0                     = (34), // TML timer0 compare-match
    ICU_EVENT_TAU0_TMI04                    = (35), // End of timer channel 04 count or capture
    ICU_EVENT_TAU0_TMI05                    = (36), // End of timer channel 05 count or capture
    ICU_EVENT_TAU0_TMI06                    = (37), // End of timer channel 06 count or capture
    ICU_EVENT_TAU0_TMI07                    = (38)  // End of timer channel 07 count or capture
} icu_event_t;

#define BSP_PRV_VECT_ENUM(event, group)  (ICU_ ## event)

/* UNCRUSTIFY-ON */
/** @} (end addtogroup BSP_MCU_RA0E3) */

#endif
