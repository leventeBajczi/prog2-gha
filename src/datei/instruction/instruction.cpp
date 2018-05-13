
#include "instruction.hpp"
SimpleInstruktion::SimpleInstruktion(std::string lang, std::string repr, void* ptr, std::string p1, std::string p2) : Instruktion(lang), representation(repr), function(ptr), param1(p1), param2(p2) 
{
    this->function = ptr;
}

std::string SimpleInstruktion::print()
{
    return representation+" "+param1+" "+param2;
}
void SimpleInstruktion::run(VirtualMachine& vm)
{
    void (*ptr)(VirtualMachine&, std::string, std::string) = (void (*)(VirtualMachine&, std::string, std::string))function;
    (*ptr)(vm, param1, param2);
}


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
void ComplexInstruktion::run(VirtualMachine& vm)
{
    for(SimpleInstruktion si : instructions)
    {
        si.run(vm);
    }
}

void ComplexInstruktion::add(SimpleInstruktion& si)
{
    instructions.push_back(si);
}