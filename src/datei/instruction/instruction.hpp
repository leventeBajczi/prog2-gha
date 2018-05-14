#ifndef _INSTRUCTION
#define _INSTRUCTION

#include "../datei.hpp"
#include <vector>

class VirtualMachine;

class Instruktion : public Datei
{
    public:
        Instruktion(std::string str) : Datei(str) {}
        virtual std::string print() = 0;
        virtual void run(VirtualMachine&) = 0;
    
};

class SimpleInstruktion : public Instruktion
{
    private:
        std::string representation;
        void *function;
        std::string param1;
        std::string param2;
    public:
        SimpleInstruktion(std::string, std::string, void*, std::string, std::string);
        std::string print();
        void run(VirtualMachine&);

};

class ComplexInstruktion : public Instruktion
{
    private:
        std::vector<SimpleInstruktion> instructions;
    public:
        ComplexInstruktion(std::string);
        ComplexInstruktion(std::string, SimpleInstruktion&);
        std::string print();
        void run(VirtualMachine&);
        void add(SimpleInstruktion&);
        

};


#endif