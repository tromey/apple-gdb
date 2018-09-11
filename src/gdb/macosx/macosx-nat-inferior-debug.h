#ifndef __GDB_MACOSX_NAT_INFERIOR_DEBUG_H__
#define __GDB_MACOSX_NAT_INFERIOR_DEBUG_H__

#include <stdio.h>
#include <mach/mach.h>

#include "defs.h"

extern FILE *inferior_stderr;
extern int inferior_debug_flag;

struct macosx_inferior_status;

void inferior_debug PARAMS ((int level, const char *fmt, ...));
void macosx_debug_port_info PARAMS ((task_t task, port_t port));
void macosx_debug_task_port_info PARAMS ((mach_port_t task));
void macosx_debug_inferior_status PARAMS ((struct macosx_inferior_status *s));
void macosx_debug_message PARAMS ((mach_msg_header_t *msg));
void macosx_debug_notification_message PARAMS ((struct macosx_inferior_status *inferior, mach_msg_header_t *msg));
void macosx_debug_region (task_t task, vm_address_t address);
void macosx_debug_regions (task_t task);

const char *unparse_exception_type PARAMS ((unsigned int i));
const char *unparse_protection PARAMS ((vm_prot_t p));
const char *unparse_inheritance PARAMS ((vm_inherit_t i));

#endif /* __GDB_MACOSX_NAT_INFERIOR_DEBUG_H__ */
