/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

#include <stdio.h>
#include <k_api.h>
#include <u_task.h>
#include <u_res.h>

static int process_try_exit = 0;

kstat_t krhino_utask_dyn_create(ktask_t **task, const name_t *name, void *arg,
                                uint8_t pri, tick_t ticks, size_t ustack,
                                size_t kstack, task_entry_t entry, uint8_t autorun)
{
    cpu_stack_t *ustack_buf;

    ustack_buf = malloc(ustack * sizeof(cpu_stack_t));
    if (NULL == ustack_buf) {
        return RHINO_NO_MEM;
    }

    return krhino_utask_create(task, name, arg, pri, ticks, ustack_buf,
                               ustack, kstack, entry, autorun);
}

int krhino_uprocess_is_try_exit(void)
{
    return (process_try_exit >0)? 1: 0;
}

void krhino_uprocess_try_exit(void)
{
    process_try_exit++;
}
