#pragma once

#include <cstdint>
#include <cstring>
#include <altivec.h>
#include "common.hpp"

#undef vector
#undef bool
#undef pixel

namespace randomy{
    
    class Program;
    struct ProgramConfiguration;
    class SuperscalarProgram;
    class JitCompilerPPC64LE;
    class Instruction;
    
    typedef
    void(JitCompilerPPC64LE::*InstructionGeneratorPPC64LE)(Instruction&, uint32_t&);
    
    class JitCompilerPPC64LE{
        
    public:
        
        JitCompiler();
        ~JitCompiler();
        
        void generateProgram(Program&, ProgramConfiguration&);
        
        void generateProgramLight(Program&, ProgramConfiguration&, uint32_t);
        
        
