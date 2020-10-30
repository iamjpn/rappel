#include <sys/uio.h>
#include <stdint.h>

#define TRAP 0x7fe00008
#define TRAP_SZ 4

#define PPC64_INIT_PROC_INFO(i) \
	do {\
		(i).regs   = (struct iovec) { .iov_base = &(i).regs_struct,   .iov_len = sizeof((i).regs_struct) }; \
	} while (0)

struct user_regs_ppc64
{
        unsigned long gpr[32];
        unsigned long nip;
        unsigned long msr;
        unsigned long orig_gpr3;        /* Used for restarting system calls */
        unsigned long ctr;
        unsigned long link;
        unsigned long xer;
        unsigned long ccr;
        unsigned long softe;            /* Soft enabled/disabled */
        unsigned long trap;             /* Reason for being here */
        unsigned long dar;              /* Fault registers */
        unsigned long dsisr;            /* on 4xx/Book-E used for ESR */
        unsigned long result;           /* Result of a system call */
};

struct proc_info_t {
	pid_t pid;

	struct user_regs_ppc64 regs_struct;
	struct user_regs_ppc64 old_regs_struct;
	struct iovec regs;

	int sig;
	long exit_code;
};

#define PAGE_SHIFT      16
#define PAGE_SIZE       (1UL << PAGE_SHIFT)
