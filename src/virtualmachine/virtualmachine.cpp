#include "virtualmachine.hpp"

#include <sstream>



void mov(VirtualMachine& vm, std::string s1, std::string s2){
    vm.getReference(s1) = vm.getValue(s2);
}
void add(VirtualMachine& vm, std::string s1, std::string s2){
    vm.getReference(s1) = vm.getValue(s2) + vm.getValue(s1);
}
void sub(VirtualMachine& vm, std::string s1, std::string s2){
    vm.getReference(s1) = vm.getValue(s1) - vm.getValue(s2);
}
void swp(VirtualMachine& vm, std::string s1, std::string s2){
    vm.getReference(s1) = (vm.getValue(s1))  >> 4 | (vm.getValue(s1) << 4);
}
void sl0(VirtualMachine& vm, std::string s1, std::string s2){
    vm.getReference(s1) = vm.getValue(s1) << 1;
}
void sr0(VirtualMachine& vm, std::string s1, std::string s2){ 
    vm.getReference(s1) = vm.getValue(s1) >> 1;
}
void jsr(VirtualMachine& vm, std::string s1, std::string s2){ 
    vm.runSubroutine(s1);
}


uint8_t& VirtualMachine::getReference(std::string s)
{
    unsigned int reg;
    std::stringstream ss;
    switch(s[0])
    {
        case '(':
            ss << s.substr(2, s.size()-1);
            ss >> reg;
            return memory.read(generalRegisterArray.read(reg));
            break;
        case 'r':
            ss << s.substr(1, s.size());
            ss >> reg;
            return generalRegisterArray.read(reg);
            break;
        default:
            //ERROR
            break;
    }
}

uint8_t VirtualMachine::getValue(std::string s)
{
    unsigned int reg;
    unsigned int ret;
    std::stringstream ss;
    std::istringstream iss(s);
    switch(s[0])
    {
        case '(':
            ss << s.substr(2, s.size()-1);
            ss >> reg;
            return memory.read(generalRegisterArray.read(reg));
            break;
        case 'r':
            ss << s.substr(1, s.size());
            ss >> reg;
            return generalRegisterArray.read(reg);
            break;
        case '0':
            iss >> std::hex >> ret;
            return ret;
        default:
            //ERROR
            break;
    }

}


VirtualMachine::VirtualMachine(Sprache sprache, unsigned int memory, unsigned int general) : memory(memory), generalRegisterArray(general), specialRegisterArray(2), language(sprache)
{
    std::vector<std::string>::iterator i = sprache.languageElements.begin();
    functions.insert(std::make_pair( *(i++), (void*)mov));
    functions.insert(std::make_pair( *(i++), (void*)add));
    functions.insert(std::make_pair( *(i++), (void*)sub));
    functions.insert(std::make_pair( *(i++), (void*)swp));
    functions.insert(std::make_pair( *(i++), (void*)sl0));
    functions.insert(std::make_pair( *(i++), (void*)sr0));
    functions.insert(std::make_pair( *(i++), (void*)jsr));

    labels.insert(std::make_pair("_start",*(new ComplexInstruktion(language.getLang()))));
}
VirtualMachine::~VirtualMachine()
{
  /*  for(auto pair : labels)
    {
        delete &pair.second;
    }
    for(auto pair : subroutines)
    {
        delete &pair.second;
    }*/
    
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
    sNew.run(*this);
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
