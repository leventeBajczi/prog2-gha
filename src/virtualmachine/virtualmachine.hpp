#ifndef _VIRTUALMACHINE
#define _VIRTUALMACHINE

#include <stack>
#include <cstdint>
#include <map>

#include "../memory/memory.hpp"
#include "../datei/sprache/sprache.hpp"
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
        Sprache language;
        std::map<std::string, void (VirtualMachine::*)(std::string, std::string)> functions;


        void mov(std::string, std::string);
        void add(std::string, std::string);
        void adc(std::string, std::string);
        void sub(std::string, std::string);
        void sbc(std::string, std::string);
        void cmp(std::string, std::string);
        void AND(std::string, std::string);
        void OR(std::string, std::string);
        void XOR(std::string, std::string);
        void swp(std::string, std::string);
        void sl0(std::string, std::string);
        void sl1(std::string, std::string);
        void sr0(std::string, std::string);
        void jmp(std::string, std::string);
        void jsr(std::string, std::string);
        void rts(std::string, std::string);


        
    public:
        VirtualMachine(Sprache, unsigned int = 1024, unsigned int = 16);
        ~VirtualMachine();
        bool runInstruction(std::string);
        void reRunAll();
        bool addLabel(std::string);
        bool addSubroutine(std::string);

};

#endif