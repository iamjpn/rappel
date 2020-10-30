#include <stdio.h>

#include "common.h"
#include "arch.h"

#include "display.h"
#include "printfmt.h"

extern struct options_t options;

void display_ppc64(
		const struct proc_info_t *const info)
{
	const struct user_regs_ppc64    *uregs    = &info->regs_struct;

	const struct user_regs_ppc64   *old_uregs     = &info->old_regs_struct;

	if (options.allregs) printf("GP Regs:\n");

	PRINTREG64(" r0=", gpr[0], uregs, old_uregs, "\t");
	PRINTREG64(" r1=", gpr[1], uregs, old_uregs, "\t");
	PRINTREG64(" r2=", gpr[2], uregs, old_uregs, "\t");
	PRINTREG64(" r3=", gpr[3], uregs, old_uregs, "\n");

	PRINTREG64(" r4=", gpr[4], uregs, old_uregs, "\t");
	PRINTREG64(" r5=", gpr[5], uregs, old_uregs, "\t");
	PRINTREG64(" r6=", gpr[6], uregs, old_uregs, "\t");
	PRINTREG64(" r7=", gpr[7], uregs, old_uregs, "\n");

	PRINTREG64(" r8=", gpr[8], uregs, old_uregs, "\t");
	PRINTREG64(" r9=", gpr[9], uregs, old_uregs, "\t");
	PRINTREG64("r10=", gpr[10], uregs, old_uregs, "\t");
	PRINTREG64("r11=", gpr[11], uregs, old_uregs, "\n");

	PRINTREG64("r12=", gpr[12], uregs, old_uregs, "\t");
	PRINTREG64("r13=", gpr[13], uregs, old_uregs, "\t");
	PRINTREG64("r14=", gpr[14], uregs, old_uregs, "\t");
	PRINTREG64("r15=", gpr[15], uregs, old_uregs, "\n");

	PRINTREG64("r16=", gpr[16], uregs, old_uregs, "\t");
	PRINTREG64("r17=", gpr[17], uregs, old_uregs, "\t");
	PRINTREG64("r18=", gpr[18], uregs, old_uregs, "\t");
	PRINTREG64("r19=", gpr[19], uregs, old_uregs, "\n");

	PRINTREG64("r20=", gpr[20], uregs, old_uregs, "\t");
	PRINTREG64("r21=", gpr[21], uregs, old_uregs, "\t");
	PRINTREG64("r22=", gpr[22], uregs, old_uregs, "\t");
	PRINTREG64("r23=", gpr[23], uregs, old_uregs, "\n");

	PRINTREG64("r24=", gpr[24], uregs, old_uregs, "\t");
	PRINTREG64("r25=", gpr[25], uregs, old_uregs, "\t");
	PRINTREG64("r26=", gpr[26], uregs, old_uregs, "\t");
	PRINTREG64("r27=", gpr[27], uregs, old_uregs, "\n");

	PRINTREG64("r28=", gpr[28], uregs, old_uregs, "\t");
	PRINTREG64("r29=", gpr[29], uregs, old_uregs, "\t");
	PRINTREG64("r30=", gpr[30], uregs, old_uregs, "\t");
	PRINTREG64("r31=", gpr[31], uregs, old_uregs, "\n");

	PRINTREG64("nip=", nip, uregs, old_uregs, "\t");
	PRINTREG64("msr=", msr, uregs, old_uregs, "\t");
	PRINTREG64("ctr=", ctr, uregs, old_uregs, "\t");
	PRINTREG64("link=", link, uregs, old_uregs, "\n");

	PRINTREG64("xer=", xer, uregs, old_uregs, "\t");
	PRINTREG64("ccr=", ccr, uregs, old_uregs, "\t");
	PRINTREG64("softe=", softe, uregs, old_uregs, "\t");
	PRINTREG64("trap=", trap, uregs, old_uregs, "\n");

	PRINTREG64("dar=", dar, uregs, old_uregs, "\t");
	PRINTREG64("dsisr=", dsisr, uregs, old_uregs, "\t");
	PRINTREG64("result=", result, uregs, old_uregs, "\n");

	// 5 is sigtrap, which is expected, -1 is initial value
	if (info->sig != 5 && info->sig != -1) {
		printf("Process died with signal: %d\n", info->sig);
		printf("Exited: %ld\n", info->exit_code);
	}
}
