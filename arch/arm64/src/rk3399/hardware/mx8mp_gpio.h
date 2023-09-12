/****************************************************************************
 * arch/arm/src/mx8mp/hardware/mx8mp_gpio.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/* Reference:
 *   "i.MX 8M Plus Applications Processor Reference Manual",
 *   Document Number: IMX8MPRM Rev. 1, 06/2021. NXP
 */

#ifndef __ARCH_ARM_SRC_MX8MP_HARDWARE_MX8MP_GPIO_H
#define __ARCH_ARM_SRC_MX8MP_HARDWARE_MX8MP_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "hardware/rk3399_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define GPIO_NPORTS               5      /* Five total ports */
#define GPIO_NPINS                32     /* Up to 32 pins per port */

/* GPIO Register Offsets ****************************************************/

#define DR_OFFSET                 0x0000  /* Data Register */
#define GDIR_OFFSET               0x0004  /* Data Direction Register */
#define PSR_OFFSET                0x0050  /* GPIO External Port Register */
#define ICR1_OFFSET               0x000c  /* Interrupt Configuration Register 1 */
#define ICR2_OFFSET               0x0010  /* Interrupt Configuration Register 2 */
#define IMR_OFFSET                0x0014  /* Interrupt Mask Register */
#define ISR_OFFSET                0x0018  /* Interrupt Status Register */
#define EDGE_OFFSET               0x001c  /* Interrupt Status Register */

/* GPIO Register Addresses **************************************************/
//if gpio2 add + 6 0000 due to different base address
//TODO: should we do this as a inline function 
#define GPIO_BASE_ADDR(n)            ((2 >= n ) ? RK3399_GPIO0_ADDR : RK3399_GPIO2_ADDR)
#define GPIO_DR(n)                (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + DR_OFFSET)
#define GPIO_GDIR(n)              (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + GDIR_OFFSET)
#define GPIO_PSR(n)               (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + PSR_OFFSET)
#define GPIO_ICR1(n)              (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + ICR1_OFFSET)
#define GPIO_ICR2(n)              (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + ICR2_OFFSET)
#define GPIO_IMR(n)               (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + IMR_OFFSET)
#define GPIO_ISR(n)               (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + ISR_OFFSET)
#define GPIO_EDGE(n)              (((n - 1) * 0x10000 + GPIO_BASE_ADDR(n - 1)) + EDGE_OFFSET)

/* GPIO Register Bit Definitions ********************************************/

/* Most registers are laid out simply with one bit per pin */

#define GPIO_PIN(n)              (1 << (n)) /* Bit n: Pin n, n=0-31 */

/* GPIO interrupt configuration register 1/2 */

#define ICR_INDEX(n)              (((n) >> 4) & 1)
#define ICR_OFFSET(n)             (ICR1_OFFSET + (ICR_INDEX(n) << 2))

#define ICR_LOW_LEVEL             0          /* Interrupt is low-level sensitive */
#define ICR_HIGH_LEVEL            1          /* Interrupt is high-level sensitive */
#define ICR_RISING_EDGE           2          /* Interrupt is rising-edge sensitive */
#define ICR_FALLING_EDGE          3          /* Interrupt is falling-edge sensitive */

/* General Purpose Input/Output (GPIO) */

typedef struct
{
    uint32_t swporta_dr;            /* 0x00 */
    uint32_t swporta_ddr;           /* 0x04 */
    uint32_t swporta_ctl;           /* 0x08 */
    uint32_t reserved8[9];               /* 0x18-0x2c portC&D */
    uint32_t inten;                 /* 0x30 */
    uint32_t intmask;               /* 0x34 */
    uint32_t inttype_level;         /* 0x38 */
    uint32_t int_polarity;          /* 0x3c */
    uint32_t int_status;            /* 0x40 */
    uint32_t raw_instatus;          /* 0x44 */
    uint32_t debounce;              /* 0x48 */
    uint32_t porta_eoi;             /* 0x4c */
    uint32_t ext_porta;             /* 0x50 */
    uint32_t reserved9[3];               /* 0x58 0x5c */
    uint32_t ls_sync;               /* 0x60 */
} AP_GPIO_TypeDef;
#define ICR_SHIFT(n)              (((n) & 15) << 1)
#define ICR_MASK(n)               (3 << ICR_SHIFT(n))
#define ICR(i,n)                  ((uint32_t)(i) << ICR_SHIFT(n))

#endif /* __ARCH_ARM_SRC_MX8MP_HARDWARE_MX8MP_GPIO_H */
