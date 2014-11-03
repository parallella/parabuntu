/* coprthr_device.h 
 *
 * Copyright (c) 2009-2013 Brown Deer Technology, LLC.  All Rights Reserved.
 *
 * This software was developed by Brown Deer Technology, LLC.
 * For more information contact info@browndeertechnology.com
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3 (LGPLv3)
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* DAR */

#ifndef _coprthr_device_h
#define _coprthr_device_h

#include <stddef.h>

#include "cmdcall.h"
#include "cpuset_type.h"


#define COPRTHR_DEVSUP_F_RUNTIME			0x00000001
#define COPRTHR_DEVSUP_F_COMPILER		0x00000002
#define COPRTHR_DEVSUP_F_STREAM			0x00000010
#define COPRTHR_DEVSUP_F_THREAD			0x00000020
#define COPRTHR_DEVSUP_F_SIGNAL			0x00000040

#define COPRTHR_DEVSUP_F_MEM_BUFFER		0x00001000
#define COPRTHR_DEVSUP_F_MEM_MUTEX		0x00002000
#define COPRTHR_DEVSUP_F_MEM_SIGNAL		0x00004000
#define COPRTHR_DEVSUP_F_MEM_REGISTER	0x00008000
#define COPRTHR_DEVSUP_F_MEM_FIFO		0x00010000
#define COPRTHR_DEVSUP_F_MEM_STACK		0x00020000

#define COPRTHR_DEVSUP_F_MEM_PROT		0x00100000
#define COPRTHR_DEVSUP_F_MEM_OFFSET		0x00200000


struct coprthr_device_info {

	unsigned int max_compute_units;
	unsigned int max_freq;
	char* name;
	char* vendor;
	unsigned int vendorid;
	char* drv_version;
	char* profile;
	char* version;
	char* extensions;

	int arch_id;
	int memsup;
	
	size_t global_mem_sz;
	size_t local_mem_sz;

	int devsup;
};

struct coprthr_command_queue;
struct coprthr_device_state {
	cpu_set_t cpumask;
	int avail;
	int compiler_avail;
	union {
		struct {
			unsigned int veid_base;
			unsigned int nve;
		} cpu;

      struct {
         size_t core_local_mem_size;
         void* core_base_addr;
         int array_ncol;
         int array_nrow;
         int ncore;
			unsigned int* p_mutex_alloc_map;
      } e32;
	};
	struct coprthr_command_queue* cmdq;
	pid_t locked_pid;
};


struct coprthr_device_commands {
	cmdcall_t not_used;
   cmdcall_t cmd_ndrange_kernel;
	cmdcall_t cmd_task;
	cmdcall_t cmd_native_kernel;
	cmdcall_t cmd_read_buffer;
	cmdcall_t cmd_write_buffer;
	cmdcall_t cmd_copy_buffer;
	cmdcall_t cmd_read_image;
	cmdcall_t cmd_write_image;
	cmdcall_t cmd_copy_image;
	cmdcall_t cmd_copy_image_to_buffer;
	cmdcall_t cmd_copy_buffer_to_image;
	cmdcall_t cmd_map_buffer;
	cmdcall_t cmd_map_image;
	cmdcall_t cmd_unmap_mem_object;
	cmdcall_t cmd_marker;
	cmdcall_t cmd_acquire_gl_objects;
	cmdcall_t cmd_release_gl_objects;
	cmdcall_t cmd_read_buffer_rect;
	cmdcall_t cmd_write_buffer_rect;
	cmdcall_t cmd_copy_buffer_rect;
	cmdcall_t cmd_user;
	cmdcall_t cmd_barrier;
};

#define __cmd_offset(cmdname) \
	(offsetof(struct coprthr_device_commands,cmd_##cmdname)/sizeof(cmdcall_t))


#define __CL_COMMAND_NDRANGE_KERNEL __cmd_offset(ndrange_kernel)
#define __CL_COMMAND_TASK __cmd_offset(task)
#define __CL_COMMAND_NATIVE_KERNEL __cmd_offset(native_kernel)
#define __CL_COMMAND_READ_BUFFER __cmd_offset(read_buffer)
#define __CL_COMMAND_WRITE_BUFFER __cmd_offset(write_buffer)
#define __CL_COMMAND_COPY_BUFFER __cmd_offset(copy_buffer) 
#define __CL_COMMAND_READ_IMAGE __cmd_offset(read_image)
#define __CL_COMMAND_WRITE_IMAGE __cmd_offset(write_image)
#define __CL_COMMAND_COPY_IMAGE __cmd_offset(copy_image)
#define __CL_COMMAND_COPY_IMAGE_TO_BUFFER __cmd_offset(copy_image_to_buffer)
#define __CL_COMMAND_COPY_BUFFER_TO_IMAGE __cmd_offset(copy_buffer_to_image)
#define __CL_COMMAND_MAP_BUFFER __cmd_offset(map_buffer)
#define __CL_COMMAND_MAP_IMAGE __cmd_offset(map_image)
#define __CL_COMMAND_UNMAP_MEM_OBJECT __cmd_offset(unmap_mem_object)
#define __CL_COMMAND_MARKER __cmd_offset(marker)
#define __CL_COMMAND_ACQUIRE_GL_OBJECTS __cmd_offset(acquire_gl_objects)
#define __CL_COMMAND_RELEASE_GL_OBJECTS __cmd_offset(release_gl_objects)
#define __CL_COMMAND_READ_BUFFER_RECT __cmd_offset(read_buffer_rect)
#define __CL_COMMAND_WRITE_BUFFER_RECT __cmd_offset(write_buffer_rect)
#define __CL_COMMAND_COPY_BUFFER_RECT __cmd_offset(copy_buffer_rect)
#define __CL_COMMAND_USER __cmd_offset(user)
#define __CL_COMMAND_BARRIER __cmd_offset(barrier)


struct coprthr_device_operations {
	void* _dummy;
	void* (*memalloc) ( size_t sz, int flags );
	void* (*memrealloc) ( void* ptr, size_t sz, int flags);
	void (*memfree)( void* memptr, int flags );
	size_t (*memread)( void* memptr, void* buf, size_t sz );
	size_t (*memwrite)( void* memptr, void* buf, size_t sz );
	size_t (*memcopy)( void* memptr_src, void* memptr_dst, size_t sz);
	int (*mtxlock)( void* mtxptr );
	int (*mtxunlock)( void* mtxptr );
};

struct coprthr_device_compiler {
	void* (*comp)(void*);
	void* (*ilcomp)(void*);
};

struct _coprthr_ksyms_struct;
struct coprthr_device_linker {
	void* (*link)(void*);
	int (*bind_ksyms)(struct _coprthr_ksyms_struct*,void*,char*);
};

struct coprthr_device {
	struct coprthr_device_info* devinfo;
	struct coprthr_device_state* devstate;
	struct coprthr_device_operations* devops;
	union {
		struct coprthr_device_commands* devcmds;
		cmdcall_t* v_cmdcall;
	};
	struct coprthr_device_compiler* devcomp;
	struct coprthr_device_linker* devlink;
};

#define __resolve_devid_devinfo(d,m) ((d)->codev->devinfo->m)
#define __resolve_devid_devstate(d,m) ((d)->codev->devstate->m)
#define __resolve_devid_devops(d,m) ((d)->codev->devops->m)
#define __resolve_devid_devcomp(d,m) ((d)->codev->devcomp->m)
#define __resolve_devid_devlink(d,m) ((d)->codev->devlink->m)

#endif

