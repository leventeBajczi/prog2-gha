#include "simpleinstruction.hpp"


std::string SimpleInstruktion::print()
{
    return representation+" "+param1+" "+param2;
}
void SimpleInstruktion::run()
{
    void (*ptr)(std::string, std::string) = (void (*)(std::string, std::string))function;
    (*ptr)(param1, param2);
}