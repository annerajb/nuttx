/****************************************************************************
 * arch/arm64/src/rk3399/hardware/rk3399_memorymap.h
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

#ifndef __ARCH_ARM64_SRC_RK3399_HARDWARE_RK3399_MEMORYMAP_H
#define __ARCH_ARM64_SRC_RK3399_HARDWARE_RK3399_MEMORYMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Peripheral Base Addresses */
#define RK3399_GPIO0_ADDR        0xff720000
#define RK3399_GPIO1_ADDR        0xff730000

#define RK3399_GPIO2_ADDR        0xff780000
#define RK3399_GPIO3_ADDR        0xff788000
#define RK3399_GPIO4_ADDR        0xff790000

#define RK3399_PIO_ADDR        RK3399_GPIO0_ADDR
#define RK3399_PWM_ADDR        0xff430000
#define RK3399_UART0_ADDR      0xff180000
#define RK3399_UART1_ADDR      0xff190000
#define RK3399_UART2_ADDR      0xff1a0000
#define RK3399_UART3_ADDR      0xff1b0000
#define RK3399_UART4_ADDR      0xff370000

#define RK3399_GRF_ADDR             0xff770000
#define RK3399_PMUGRF_ADDR          0xff320000

#define PMMUGRF_GPIO0A_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x00000)
#define PMMUGRF_GPIO0B_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x00004)
#define PMMUGRF_GPIO1A_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x00010)
#define PMMUGRF_GPIO1B_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x00014)
#define PMMUGRF_GPIO1C_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x00018)
#define PMMUGRF_GPIO1D_IOMUX_ADDR               (RK3399_PMUGRF_ADDR + 0x0001c)


#define GRF_GPIO2A_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e000)
#define GRF_GPIO2B_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e004)
#define GRF_GPIO2C_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e008)
#define GRF_GPIO2D_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e00c)

#define GRF_GPIO3A_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e010)
#define GRF_GPIO3B_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e014)
#define GRF_GPIO3C_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e018)
#define GRF_GPIO3D_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e01c)

#define GRF_GPIO4A_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e020)
#define GRF_GPIO4B_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e024)
#define GRF_GPIO4C_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e028)
#define GRF_GPIO4D_IOMUX_ADDR                   (RK3399_GRF_ADDR + 0x0e02c)

/* make the upper 16 bit mask for a value starting at the specified maskshift position*/
#define RK_HIWORD_UPDATE(val, mask, maskshift) \
		((val) << (maskshift) | (mask) << ((maskshift) + 16))
/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif /* __ARCH_ARM64_SRC_RK3399_HARDWARE_RK3399_MEMORYMAP_H */
