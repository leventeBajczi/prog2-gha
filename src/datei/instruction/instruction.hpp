#ifndef _INSTRUCTION
#define _INSTRUCTION

#include "../datei.hpp"

class Instruktion : public Datei
{
    public:
        Instruktion(std::string str) : Datei(str) {}
        virtual std::string print() = 0;
        virtual void run() = 0;

};

#endif