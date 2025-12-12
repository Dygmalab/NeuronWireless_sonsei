/*
 *
 * Common file to select the project build type
 *
 * The MIT License (MIT)
 *
 * Copyright (C) 2020  Dygma Lab S.L.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Author: Juan Hauara @JuanHauara
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#include "stdint.h"

// clang-format off

#define COMPILE_FOR_SONSHI_HARDWARE_V1_0      1

//#define TWI_MASTER_SCL_PIN   5
//#define TWI_MASTER_SDA_PIN   4
//#define TWI_MASTER_FLASH_CLK NRF_TWIM_FREQ_100K  /* flashing doesn't work reliably at higher clock speeds */

#if COMPILE_FOR_SONSHI_HARDWARE_V1_0
    #define BSP_GPIO_nRST_KS NRF_GPIO_PIN_MAP(0, 20)  /* nRESET signal OUT to keyscanner; HIGH = running, LOW = reset */

    #define LED_GREEN_PIN NRF_GPIO_PIN_MAP(0, 30)
    #define LED_RED_PIN   NRF_GPIO_PIN_MAP(0, 29)

    /* Note: The RESET input is used as general input BOOT signal for entering the bootloader mode */
    #define BSP_GPIO_RESET   NRF_GPIO_PIN_MAP(0, 18)  /* Connected to LOW activated. */
    #define BSP_GPIO_BOOT    BSP_GPIO_RESET           /* Connected to LOW activated. */
#endif

#endif  /* __COMMON_H__ */
