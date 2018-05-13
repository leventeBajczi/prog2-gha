#ifndef _VIRTUALMACHINE
#define _VIRTUALMACHINE

#include <stack>
#include <cstdint>
#include <map>

#include "../memory/memory.hpp"
#include "../datei/sprache/sprache.hpp"
#include "../datei/instruction/instruction.hpp"


class ComplexInstruktion;

class VirtualMachine
{
    private:
        std::stack<uint8_t> stack;
        Memory memory;
        Memory generalRegisterArray;
        Memory specialRegisterArray;
        std::map<std::string, ComplexInstruktion> labels;
        std::map<std::string, ComplexInstruktion> subroutines;
        Sprache language;
        std::map<std::string, void*> functions;
        void* getPtr(std::string);


        
    public:
        VirtualMachine(Sprache, unsigned int = 1024, unsigned int = 16);
        ~VirtualMachine();
        bool runInstruction(std::string);
        void reRunAll();
        bool addLabel(std::string);
        bool addSubroutine(std::string);

};

#endif