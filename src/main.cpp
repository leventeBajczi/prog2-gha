#include <iostream>
#include "datei/sprache/sprache.hpp"
#include "virtualmachine/virtualmachine.hpp"
int main()
{
    std::string sprachendatei = "{  \
   \"Move B to A\":\"mov\",\
   \"Add B to A\":\"add\",\
   \"Substract B from A\":\"sub\",\
   \"Swap the upper and lower 4 bits\":\"swp\",\
   \"Shift left, insert 0\":\"sl0\",\
   \"Shift right, insert 0\":\"sr0\",\
   \"Jump inconditionally\":\"jmp\",\
   \"Jump to subroutine\":\"jsr\",\
   \"Return from subroutine\":\"rts\"\
}";

    Sprache sprache(sprachendatei, "mylang");
    VirtualMachine vm(sprache);
    vm.runInstruction("sub r12 0x05");
    std::cout<<(unsigned int)vm.getValue("r12")<<std::endl;
    vm.reRunAll();
        std::cout<<(unsigned int)vm.getValue("r12")<<std::endl;
    vm.reRunAll();
        std::cout<<(unsigned int)vm.getValue("r12")<<std::endl;
    vm.reRunAll();
    return 0;
}