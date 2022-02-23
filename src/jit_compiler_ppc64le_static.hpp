#pragma once

extern "C" {
    void randomx_program_ppc64le(void* reg, void* mem, void* scratchpad, uint64_t iterations);
    void randomx_program_ppc64le_main_loop();
    void randomx_program_ppc64le_vm_instructions();
    void randomx_program_ppc64le_imul_rcp_literals_end();
    void randomx_program_ppc64le_vm_instructions_end();
    void randomx_program_ppc64le_cacheline_align_mask1();
    void randomx_program_ppc64le_cacheline_align_mask2();
    void randomx_program_ppc64le_update_spMix1();
    void randomx_program_ppc64le_vm_instructions_end_light();
    void randomx_program_ppc64le_light_cacheline_align_mask();
    void randomx_program_ppc64le_light_dataset_offset();
    void randomx_init_dataset_ppc64le();
    void randomx_init_dataset_ppc64le_end();
    void randomx_calc_dataset_item_ppc64le();
    void randomx_calc_dataset_item_ppc64le_prefetch();
    void randomx_calc_dataset_item_ppc64le_mix();
    void randomx_calc_dataset_item_ppc64le_store_result();
    void randomx_calc_dataset_item_ppc64le_end();
}
