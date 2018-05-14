#include "virtualmachine.hpp"

#include <sstream>



void mov(VirtualMachine& vm, std::string s1, std::string s2){
    uint8_t value;
    std::stringstream ss;
    switch(s2[0])
    {
        case '0':
            ss << std::hex << s2;
            ss >> value;
            break;
        case '(':
            value = vm.getMemoryAt(vm.getRegisterValue(s2.substr(1, s2.size() - 1)));
            break;
        case 'r':
            value = vm.getRegisterValue(s2.substr(1, s2.size()));
            break;
        default:
            //ERROR
    }
    switch(s1[0])
    {
        case '(':
            vm.writeMemoryAt(vm.getRegisterValue(s1.substr(1, s1.size() - 1)), value);
        case 'r':
            vm.writeRegister(s1.substr(1, s1.size()), value);
        default:
            //ERROR
    }

}
void add(VirtualMachine& vm, std::string s1, std::string s2){
    std::cout<<"Hello2"<<std::endl;
}
void sub(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello3"<<std::endl; }
void cmp(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello4"<<std::endl; }
void swp(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello5"<<std::endl; }
void sl0(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello6"<<std::endl; }
void sr0(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello7"<<std::endl; }
void jmp(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello8"<<std::endl; }
void jsr(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello9"<<std::endl; }
void rts(VirtualMachine& vm, std::string s1, std::string s2){     std::cout<<"Hello10"<<std::endl; }

VirtualMachine::VirtualMachine(Sprache sprache, unsigned int memory, unsigned int general) : memory(memory), generalRegisterArray(general), specialRegisterArray(2), language(sprache)
{
    std::vector<std::string>::iterator i = sprache.languageElements.begin();
    functions.insert(std::make_pair( *(i++), (void*)mov));
    functions.insert(std::make_pair( *(i++), (void*)add));
    functions.insert(std::make_pair( *(i++), (void*)sub));
    functions.insert(std::make_pair( *(i++), (void*)swp));
    functions.insert(std::make_pair( *(i++), (void*)sl0));
    functions.insert(std::make_pair( *(i++), (void*)sr0));
    functions.insert(std::make_pair( *(i++), (void*)jmp));
    functions.insert(std::make_pair( *(i++), (void*)jsr));
    functions.insert(std::make_pair( *(i++), (void*)rts));

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
