 .globl DECL(randomx_program_ppc64le)
 .globl DECL(randomx_program_ppc64le_main_loop)
 .globl DECL(randomx_program_ppc64le_vm_instructions)
 .globl DECL(randomx_program_ppc64le_imul_rcp_literals_end)
 .globl DECL(randomx_program_ppc64le_vm_instructions_end)
 .globl DECL(randomx_program_ppc64le_cacheline_align_mask1)
 .globl DECL(randomx_program_ppc64le_cacheline_align_mask2)
 .globl DECL(randomx_program_ppc64le_update_spMix1)
 .globl DECL(randomx_program_ppc64le_vm_instructions_end_light)
 .globl DECL(randomx_program_ppc64le_light_cacheline_align_mask)
 .globl DECL(randomx_program_ppc64le_light_dataset_offset)
 .globl DECL(randomx_init_dataset_ppc64le)
 .globl DECL(randomx_init_dataset_ppc64le_end)
 .globl DECL(randomx_calc_dataset_item_ppc64le)
 .globl DECL(randomx_calc_dataset_item_ppc64le_prefetch)
 .globl DECL(randomx_calc_dataset_item_ppc64le_mix)
 .globl DECL(randomx_calc_dataset_item_ppc64le_store_result)
 .globl DECL(randomx_calc_dataset_item_ppc64le_end)

#include "configuration.h"

# special
#gpr0 prologue
#gpr1 sp
#gpr2 TOC
#gpr3 first param .. gpr7
#gpr13 reserved in 64bit implementation as specified in leabi; was not able to found out for what lol

# storage PBG-C probably GPR31 and FPR31 <

# VM registers alloc
#gpr31 => r0 GROUP R
#gpr30 => r1
#gpr29 => r2
#gpr28 => r3
#gpr27 => r4
#gpr26 => r5
#gpr25 => r6
#gpr24 => r7
#fpr31 => f0 GROUP F
#fpr30 => f1
#fpr29 => f2
#fpr28 => f3
#fpr27 => e0 GROUP E
#fpr26 => e1
#fpr25 => e2
#fpr24 => e3
#fpr23 => a0 GROUP A
#fpr22 => a1
#fpr21 => a2
#fpr20 => a3

# other allocs
#gpr23 => IMUL_RCP literal
#gpr22 => IMUL_RCP literal
#gpr21 => IMUL_RCP literal
#gpr20 => IMUL_RCP literal
#gpr19 => IMUL_RCP literal
#gpr18 => IMUL_RCP literal
#gpr17 => IMUL_RCP literal
#gpr16 => IMUL_RCP literal
#gpr15 => IMUL_RCP literal
#gpr14 => IMUL_RCP literal
#gpr10 => IMUL_RCP literal
#gpr9 => IMUL_RCP literal
#gpr8 => mx, ma
#gpr7 => spAddr0
#gpr6 => spAddr1
#gpr5 => ic (loop counter)
#

#convert GROUP F and E  32 int to float via MASKS _> a64.s

# .align 2
DECL(randomx_program_ppc64le):
#PBG-C might need correction!!
 mflr 0
 std 14,-144(1)
 std 15,-136(1)
 std 16,-128(1)
 std 17,-120(1)
 std 18,-112(1)
 std 19,-104(1)
 std 20,-96(1)
 std 21,-88(1)
 std 22,-80(1)
 std 23,-72(1)
 std 24,-64(1)
 std 25,-56(1)
 std 26,-48(1)
 std 27,-40(1)
 std 28,-32(1)
 std 29,-24(1)
 std 30,-16(1)
 std 31,-8(1)
 std 0,16(1)

#PBG-C INSERT PROLOGUE BY LEABI
 
 li 31, 0
 li 30, 0
 li 29, 0
 li 28, 0
 li 27, 0
 li 26, 0
 li 25, 0
 li 24, 0
 
 
 
DECL(randomx_program_ppc64le_main_loop):
 
 
 
DECL(randomx_program_ppc64le_vm_instructions):
 
 
 
DECL(randomx_program_ppc64le_imul_rcp_literals_end):
 
 
 
DECL(randomx_program_ppc64le_vm_instructions_end):
 
 
 
DECL(randomx_program_ppc64le_cacheline_align_mask1):
 
 
 
DECL(randomx_program_ppc64le_cacheline_align_mask2):
 
 
 
DECL(randomx_program_ppc64le_xor_with_dataset_line):
 
 
 
DECL(randomx_program_ppc64le_update_spMix1):
 
 
 
DECL(randomx_program_ppc64le_vm_instructions_end_light):
 
 
 
DECL(randomx_program_ppc64le_light_cacheline_align_mask):
 
 
 
DECL(randomx_program_ppc64le_light_dataset_offset):
 
 
 
DECL(randomx_init_dataset_ppc64le):
 
 
 
DECL(randomx_init_dataset_ppc64le_main_loop):
 
 
 
DECL(randomx_init_dataset_ppc64le_end):
 
 
 
DECL(randomx_calc_dataset_item_ppc64le):
 
 
 
DECL(randomx_calc_dataset_item_ppc64le_prefetch):
 
 
 
DECL(randomx_calc_dataset_item_ppc64le_mix):
 
 
 
DECL(randomx_calc_dataset_item_ppc64le_store_result):
 
 
 
DECL(randomx_calc_dataset_item_ppc64le_end):
 
 
 
#EOF
