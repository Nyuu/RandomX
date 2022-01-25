#include <stdexcept>
#include <climits>
#include "jit_compiler_ppc64le.hpp"
#include "jit_compiler_ppc64le_static.hpp"
#include "superscalar.hpp"
#include "program.hpp"
#include "reciprocal.h"
#include "virtual_memory.hpp"


//EXPERIMENTAL
namespace POWER{

constexpr uint32_t opcode = 0xABCDEF98;

}
//EXPERIMENTAL OVER

namespace randomx{

/*
    REGISTER ALLOC

    ; 8R 32bit
    ; 12R 64bit
*/

#include "instruction_weights.hpp"
#define INST_HANDLE(x) REPN(&JitCompilerPPC64LE::h_##x, WT(x))

    InstructionGeneratorPPC64LE JitCompilerPPC64LE::engine[256] = {
        INST_HANDLE(IADD_RS)
        INST_HANDLE(IADD_M)
        INST_HANDLE(ISUB_R)
        INST_HANDLE(ISUB_M)
        INST_HANDLE(IMUL_R)
        INST_HANDLE(IMUL_M)
        INST_HANDLE(IMULH_R)
        INST_HANDLE(IMULH_M)
        INST_HANDLE(ISMULH_R)
        INST_HANDLE(ISMULH_M)
        INST_HANDLE(IMUL_RCP)
        INST_HANDLE(INEG_R)
        INST_HANDLE(IXOR_R)
        INST_HANDLE(IXOR_M)
        INST_HANDLE(IROR_R)
        INST_HANDLE(IROL_R)
        INST_HANDLE(ISWAP_R)
        INST_HANDLE(FSWAP_R)
        INST_HANDLE(FADD_R)
        INST_HANDLE(FADD_M)
        INST_HANDLE(FSUB_R)
        INST_HANDLE(FSUB_M)
        INST_HANDLE(FSCAL_R)
        INST_HANDLE(FMUL_R)
        INST_HANDLE(FDIV_M)
        INST_HANDLE(FSQRT_R)
        INST_HANDLE(CBRANCH)
        INST_HANDLE(CFROUND)
        INST_HANDLE(ISTORE)
        INST_HANDLE(NOP)
    };
}