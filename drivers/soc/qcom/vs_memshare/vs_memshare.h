/* Copyright (c) 2013-2016, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _LINUX_VS_MEM_SHARE_H
#define _LINUX_VS_MEM_SHARE_H

#define VS_MEM_SHARE_SERVICE_SVC_ID 0x000000E3
#define VS_MEM_SHARE_SERVICE_INS_ID 1
#define VS_MEM_SHARE_SERVICE_VERS 1

#define MEMORY_CMA	1
#define MEMORY_NON_CMA	0
#define MAX_CLIENTS 10
#define CHECK	0
#define FREE	1

struct vs_mem_blocks {
	/* Client Id information */
	uint32_t client_id;
	/* Sequence Id */
	uint32_t sequence_id;
	/* CMA or Non-CMA region */
	uint32_t memory_type;
	/* Guaranteed Memory */
	uint32_t guarantee;
	/* Memory alloted or not */
	uint32_t alloted;
	/* Size required for client */
	uint32_t size;
	/*
	 * start address of the memory block reserved by server memory
	 * subsystem to client
	 */
	phys_addr_t phy_addr;
	/* Virtual address for the physical address allocated */
	void *virtual_addr;
	/* Release memory only when XPU is released*/
	uint8_t free_memory;
	/* Need Hypervisor mapping*/
	uint8_t hyp_mapping;
	/* Status flag which checks if ramdump file is created*/
	int file_created;

};

int vs_memshare_alloc(struct device *dev,
					int client_id,
					unsigned int block_size,
					struct vs_mem_blocks *pblk);
void vs_memshare_free(unsigned int block_size,
					struct vs_mem_blocks *pblk);
#endif /* _LINUX_VS_MEM_SHARE_H */
