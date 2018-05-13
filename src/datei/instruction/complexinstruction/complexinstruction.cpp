#include "complexinstruction.hpp"
#include <cstring>

ComplexInstruktion::ComplexInstruktion(std::string lang) : Instruktion(lang)
{
}
ComplexInstruktion::ComplexInstruktion(std::string lang, SimpleInstruktion& begin) : Instruktion(lang)
{
    instructions.push_back(begin);
}
std::string ComplexInstruktion::print()
{
    std::string ret = "";
    for(SimpleInstruktion si : instructions)
    {
        ret+=si.print()+='\n';
    }
    return ret;
}
void ComplexInstruktion::run()
{
    for(SimpleInstruktion si : instructions)
    {
        si.run();
    }
}