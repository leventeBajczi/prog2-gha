#include "virtualmachine.hpp"

#include <sstream>

VirtualMachine::VirtualMachine(Sprache sprache, unsigned int memory, unsigned int general) : memory(memory), generalRegisterArray(general), specialRegisterArray(2), language(sprache)
{
    std::map<std::string, unsigned int>::iterator i = sprache.languageElements.begin();
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::mov));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::add));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::sub));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::swp));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::sl0));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::sr0));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::jmp));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::jsr));
    functions.insert(std::make_pair( (i++)->first, &VirtualMachine::rts));

    labels.insert(std::make_pair("_start",*(new ComplexInstruktion(language.getLang()))));
}
VirtualMachine::~VirtualMachine()
{
    for(auto pair : labels)
    {
        delete [] &pair.second;
    }
    for(auto pair : subroutines)
    {
        delete [] &pair.second;
    }
    
}

auto VirtualMachine::getPtr(std::string s)
{
    std::string str;
    for(auto pair : language.instructions)
    {
        if(pair.first == s)
        {   
            str = pair.second;
            break;
        }
    }
    for(auto pair : functions)
    {
        if(pair.first == str)
        {
            return (pair.second);
        }
    }
}

bool VirtualMachine::runInstruction(std::string r)
{
    std::istringstream is(r);
    std::string instruction, param1, param2;
    is>>instruction;
    is>>param1;
    is>>param2;

    SimpleInstruktion sNew(language.getLang(), r, getPtr(instruction), param1, param2);
    sNew.run();
    for(auto pair : labels)
    {
        if(pair.first == "_start")
        {
            pair.second.add(sNew);
            break;
        }
    }
}
void reRunAll();
bool addLabel(std::string);
bool addSubroutine(std::string);