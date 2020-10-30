#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "arch.h"

void dump_state_ppc64(
		const struct proc_info_t *const info)
{
	const struct user_regs_ppc64   *regs   = &info->regs_struct;

	write_data(STDOUT_FILENO, (uint8_t *)regs, sizeof(struct user_regs_ppc64));
}
