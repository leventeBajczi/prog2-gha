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
        template <class T> SimpleInstruktion(std::string, std::string, T, std::string, std::string);
        std::string print();
        void run();

};

template<class T> SimpleInstruktion::SimpleInstruktion(std::string lang, std::string repr, T ptr, std::string p1, std::string p2) : Instruktion(lang), representation(repr), function(ptr), param1(p1), param2(p2) 
{
}

#endif