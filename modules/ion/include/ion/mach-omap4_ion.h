/*
 * arch/arm/mach-omap2/board-blaze.h
 *
 * Copyright (C) 2011 Texas Instruments
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _OMAP4_ION_H
#define _OMAP4_ION_H

/* FIXME-HASH: Included from plat-omap/include/plat/memory.h */
#define PLAT_PHYS_OFFSET		UL(0x80000000)

#define PHYS_ADDR_DUCATI_SIZE			(SZ_1M * 55)
#define PHYS_ADDR_DUCATI_MEM			(0x80000000 + SZ_512M - PHYS_ADDR_DUCATI_SIZE)
#define PHYS_ADDR_SMC_SIZE			(SZ_1M * 3)
#define PHYS_ADDR_SMC_MEM			(PHYS_ADDR_DUCATI_MEM - PHYS_ADDR_SMC_SIZE)
// #ifdef CONFIG_OMAP_REMOTE_PROC_DSP
#define PHYS_ADDR_TESLA_SIZE			(SZ_1M * 4)
#define PHYS_ADDR_TESLA_MEM			(PHYS_ADDR_SMC_MEM - PHYS_ADDR_TESLA_SIZE)
// #endif
#define OMAP4_ION_HEAP_TILER_SIZE		(SZ_512K)
#define PHYS_ADDR_ION_HEAP_TILER		(PHYS_ADDR_TESLA_MEM - OMAP4_ION_HEAP_TILER_SIZE)
#define OMAP4_ION_HEAP_SECURE_INPUT_SIZE	(SZ_512K)
#define PHYS_ADDR_ION_HEAP_SECURE_INPUT		(PHYS_ADDR_ION_HEAP_TILER - OMAP4_ION_HEAP_SECURE_INPUT_SIZE)
#define OMAP_RAM_CONSOLE_SIZE 			(SZ_1M)
#define PHYS_ADDR_OMAP_RAM_CONSOLE		(PHYS_ADDR_ION_HEAP_SECURE_INPUT - OMAP_RAM_CONSOLE_SIZE)


#if 0
#define OMAP4_RAMCONSOLE_START	(PLAT_PHYS_OFFSET + SZ_512M)
#define OMAP4_RAMCONSOLE_SIZE	SZ_2M
#define OMAP4_ION_HEAP_SECURE_INPUT_SIZE	(SZ_1M * 90)
#define OMAP4_ION_HEAP_TILER_SIZE		(SZ_128M - SZ_32M)
#define OMAP4_ION_HEAP_NONSECURE_TILER_SIZE	SZ_32M

#define PHYS_ADDR_SMC_SIZE	(SZ_1M * 3)
#define PHYS_ADDR_SMC_MEM	(0x80000000 + SZ_1G - PHYS_ADDR_SMC_SIZE)
#define PHYS_ADDR_DUCATI_SIZE	(SZ_1M * 105)
#define PHYS_ADDR_DUCATI_MEM	(PHYS_ADDR_SMC_MEM - PHYS_ADDR_DUCATI_SIZE - \
				OMAP4_ION_HEAP_SECURE_INPUT_SIZE)
#endif

#ifdef CONFIG_ION_OMAP
void omap_ion_init(void);
void omap4_register_ion(void);
#else
inline void omap_ion_init(void) { return; }
inline void omap4_register_ion(void) { return; }
#endif

#endif
