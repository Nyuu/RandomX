#pragma once

#include <cstdint>
#include <cstring>
#include <altivec.h>
#include "common.hpp"

#undef vector
#undef bool
#undef pixel

namespace randomx {
    
    class Program;
    struct ProgramConfiguration;
    class SuperscalarProgram;
    class JitCompilerPPC64LE;
    class Instruction;
    
    typedef
    void(JitCompilerPPC64LE::*InstructionGeneratorPPC64LE)(Instruction&, uint32_t&);
    
    class JitCompilerPPC64LE{
        
    public:
        
        JitCompilerPPC64LE();
        ~JitCompilerPPC64LE();
        
        void generateProgram(Program&, ProgramConfiguration&);
        
        void generateProgramLight(Program&, ProgramConfiguration&, uint32_t);
        
        template<size_t N>
        void generateSuperscalarHash(SuperscalarProgram (&programs)[N], std::vector<uint64_t> &);
        
        void generateDatasetInitCode();
        
        ProgramFunc* getProgramFunc(){
            return reinterpret_cast<ProgramFunc*>(code);
        }
        
        DatasetInitFunc* getDatasetInitFunc(){
            return (DatasetInitFunc*)code;
        }
        
        uint8_t* getCode(){
            return code;
            
        }
        
        size_t getCodeSize();
        
        void enableWriting();
        void enableExecution();
        void enableAll();
        
    private:
        
        static InstructionGeneratorPPC64LE engine[256];
        
        //insert stuffs ?
        
        uint8_t* code;
        
        //insert MOAR stuffs ?
    }
}
