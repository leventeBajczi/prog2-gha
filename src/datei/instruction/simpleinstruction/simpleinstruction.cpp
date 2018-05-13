#include "simpleinstruction.hpp"

SimpleInstruktion::SimpleInstruktion(std::string lang, std::string repr, void* ptr, std::string p1, std::string p2) : Instruktion(lang), representation(repr), function(ptr), param1(p1), param2(p2) 
{
}
std::string SimpleInstruktion::print()
{
    return representation+" "+param1+" "+param2;
}
void SimpleInstruktion::run()
{
    void (*ptr)(std::string, std::string) = (void (*)(std::string, std::string))function;
    (*ptr)(param1, param2);
}