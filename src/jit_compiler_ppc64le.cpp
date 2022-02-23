#include "jit_compiler_ppc64le.hpp"
#include "superscalar.hpp"
#include "program.hpp"
#include "reciprocal.h"
#include "virtual_memory.hpp"

namespace POWER_ISA{
    //PBG-C To be filled with opcodes ?
    constexpr uint32_t li = 0x003300FF;
    
}

namespace randomx{
    
    static const size_t CodeSize = ((uint8_t*)randomx_init_dataset_ppc64le_end) - ((uint8_t*)randomx_program_ppc64le);
    static const size_t MainLoopBegin = ((uint8_t*)randomx_program_ppc64le_main_loop) - ((uint8_t*)randomx_program_ppc64le);
    static const size_t PrologueSize = ((uint8_t*)randomx_program_ppc64le_vm_instructions) - ((uint8_t*)randomx_program_ppc64le);
    static const size_t ImulRcpLiteralEnd = ((uint8_t*)randomx_program_ppc64le_imul_rcp_literals_end) - ((uint8_t*)randomx_program_ppc64le);
    
    static const size_t CalcDatasetItemSize = ((uint8_t*)randomx_calc_dataset_item_ppc64le_prefetch - (uint8_t*)randomx_calc_dataset_item_ppc64le) + RANDOMX_CACHE_ACCESSES * (((uint8_t*)randomx_calc_dataset_item_ppc64le_mix - ((uint8_t*)randomx_calc_dataset_item_ppc64le_prefetch)) + 4 + ((RANDOMX_SUPERSCALAR_LATENCY * 3) + 2) * 16 + ((uint8_t*)randomx_calc_dataset_item_ppc64le_end - (uint8_t*)randomx_calc_dataset_item_ppc64le_mix) + 4) + ((uint8_t*)randomx_calc_dataset_item_ppc64le_end - (uint8_t*)randomx_calc_dataset_item_ppc64le_store_result);
    
    constexpr uint32_t IntRegMap[8] = {4,5,6,7,12,13,14,15};
    
    template<typename T> static constexpr size_t Log2(T value) { return (value > 1) ? (Log2(value / 2) + 1) : 0; }
    
    JitCompilerPPC64LE::JitCompilerPPC64LE()
        :code((uint8_t*)allocMemoryPages(CodeSize+CalcDatasetItemSize))
        ,literalPos(ImulRcpLiteralEnd)
        ,num32bitLiterals(0)
        {
            memset(reg_changed_offset, 0 , sizeof(reg_changed_offset));
            memcpy(code, (void*)randomx_program_ppc64le, CodeSize);
#ifdef __GNUC__
            __builtin___clear_cache(reinterpret_cast<char*>(code), reinterpret_cast<char*>(code + CodeSize));
#endif
        }
        
        JitCompilerPPC64LE::~JitCompilerPPC64LE(){
            freePagedMemory(code, CodeSize + CalcDatasetItemSize);
        }
        
        void JitCompilerPPC64LE::enableWriting(){
            setPagesRW(code, CodeSize + CalcDatasetItemSize);
        }
        
        void JitCompilerPPC64LE::enableExecution(){
            setPagesRX(code, CodeSize + CalcDatasetItemSize);
        }
        
        void JitCompilerPPC64LE::enableAll(){
            setPagesRWX(code, CodeSize + CalcDatasetItemSize);
        }
        
        void JitCompilerPPC64LE::generateProgram(Program& program, ProgramConfiguration& config){
            
            uint32_t codePos = MainLoopBegin + 4;
            
            //CONTINUE
            
        }
}
