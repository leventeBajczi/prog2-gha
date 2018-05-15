#ifndef _VIRTUALMACHINE
#define _VIRTUALMACHINE

#include <stack>
#include <cstdint>
#include <map>

#include "../memory/memory.hpp"
#include "../datei/sprache/sprache.hpp"
#include "../datei/instruction/instruction.hpp"


class ComplexInstruktion;

/**
 * Klasse für den virtuellen Gerät, wodurch die Instruktionen ausgeführt werden können. 
 */
class VirtualMachine
{
    private:
        std::stack<uint8_t> stack;
        Memory memory;
        Memory generalRegisterArray;
        Memory specialRegisterArray;
        std::map<std::string, ComplexInstruktion*> labels;
        std::map<std::string, ComplexInstruktion*> subroutines;
        Sprache language;
        std::map<std::string, void*> functions;
        void* getPtr(std::string);


        
    public:
        VirtualMachine(Sprache, unsigned int = 1024, unsigned int = 16);
        bool runInstruction(std::string);
        void reRunAll();
        bool addSubroutine(std::string);
        uint8_t& getReference(std::string);
        uint8_t getValue(std::string);
        void runSubroutine(std::string);
        void pushValue(uint8_t);
        uint8_t popValue();

};

#endif