#ifndef _VIRTUALMACHINE
#define _VIRTUALMACHINE

#include <stack>
#include <cstdint>
#include <map>

#include "../memory/memory.hpp"
#include "../datei/instruction/complexinstruction/complexinstruction.hpp"

class VirtualMachine
{
    private:
        std::stack<uint8_t> stack;
        Memory memory;
        Memory generalRegisterArray;
        Memory specialRegisterArray;
        std::map<std::string, ComplexInstruktion> labels;
        std::map<std::string, ComplexInstruktion> subroutines;
        
    public:
        VirtualMachine(unsigned int = 1024, unsigned int = 16);
        bool runInstruction(std::string);
        void reRun();
        bool addLabel(std::string);
        bool addSubroutine(std::string);

};

#endif