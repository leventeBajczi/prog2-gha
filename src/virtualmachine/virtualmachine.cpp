#include "virtualmachine.hpp"

VirtualMachine::VirtualMachine(Sprache sprache, unsigned int memory, unsigned int general) : memory(memory), generalRegisterArray(general), specialRegisterArray(2), language(sprache)
{
    labels.insert(std::make_pair("CODE",*(new ComplexInstruktion(language.getLang()))));
}
VirtualMachine::~VirtualMachine()
{
    for(auto pair : labels)
    {
        delete [] i.
    }
}
bool runInstruction(std::string)
{

}
void reRunAll();
bool addLabel(std::string);
bool addSubroutine(std::string);