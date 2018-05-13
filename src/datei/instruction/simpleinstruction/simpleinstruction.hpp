#ifndef _SIMPLEINSTRUCTION
#define _SIMPLEINSTRUCTION

#include "../instruction.hpp"

class SimpleInstruktion : public Instruktion
{
    private:
        std::string representation;
        void* function;
        std::string param1;
        std::string param2;
    public:
        SimpleInstruktion(std::string, std::string, void*, std::string, std::string);
        std::string print();
        void run();

};

#endif