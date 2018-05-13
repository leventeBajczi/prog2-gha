#include "virtualmachine.hpp"

#include <sstream>



void mov(VirtualMachine& vm, std::string s1, std::string s2){}
void add(VirtualMachine& vm, std::string s1, std::string s2){}
void sub(VirtualMachine& vm, std::string s1, std::string s2){}
void cmp(VirtualMachine& vm, std::string s1, std::string s2){}
void swp(VirtualMachine& vm, std::string s1, std::string s2){}
void sl0(VirtualMachine& vm, std::string s1, std::string s2){}
void sr0(VirtualMachine& vm, std::string s1, std::string s2){}
void jmp(VirtualMachine& vm, std::string s1, std::string s2){}
void jsr(VirtualMachine& vm, std::string s1, std::string s2){}
void rts(VirtualMachine& vm, std::string s1, std::string s2){}

VirtualMachine::VirtualMachine(Sprache sprache, unsigned int memory, unsigned int general) : memory(memory), generalRegisterArray(general), specialRegisterArray(2), language(sprache)
{
    std::map<std::string, unsigned int>::iterator i = sprache.languageElements.begin();
    functions.insert(std::make_pair( (i++)->first, (void*)mov));
    functions.insert(std::make_pair( (i++)->first, (void*)add));
    functions.insert(std::make_pair( (i++)->first, (void*)sub));
    functions.insert(std::make_pair( (i++)->first, (void*)swp));
    functions.insert(std::make_pair( (i++)->first, (void*)sl0));
    functions.insert(std::make_pair( (i++)->first, (void*)sr0));
    functions.insert(std::make_pair( (i++)->first, (void*)jmp));
    functions.insert(std::make_pair( (i++)->first, (void*)jsr));
    functions.insert(std::make_pair( (i++)->first, (void*)rts));

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

void* VirtualMachine::getPtr(std::string s)
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
    return true;
}
void VirtualMachine::reRunAll()
{

}
bool VirtualMachine::addLabel(std::string s)
{

}
bool VirtualMachine::addSubroutine(std::string s)
{

}
