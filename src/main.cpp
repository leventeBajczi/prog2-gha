#include <iostream>
#include <fstream>
#include "datei/sprache/sprache.hpp"
#include "virtualmachine/virtualmachine.hpp"

#include <cstring>

#define PRINT_LANGUAGE "-p"
#define LANGUAGE_FILE "-l"
#define USE_FILES "-f"


int main(int argc, char** argv)
{
    std::string sprachendatei;
    for(int i = 1; i<argc;i++){
        if      (strcmp(argv[i], PRINT_LANGUAGE) == 0){
            std::cout<<Sprache::printEmpty();
        }
        else if (strcmp(argv[i], LANGUAGE_FILE) == 0){
            std::ifstream t(argv[++i]);
            std::string file((std::istreambuf_iterator<char>(t)),
            std::istreambuf_iterator<char>());
            sprachendatei = file;
        }
        else if (strcmp(argv[i], USE_FILES) == 0){
            for(i=i+1;i<argc;i++)
            {
                std::ifstream t(argv[i]);
                std::string file((std::istreambuf_iterator<char>(t)),
                std::istreambuf_iterator<char>());
                
            }
        }
        else{
            std::cout<<"Unrecognized CLI switch "<<argv[i]<<" , quitting."<<std::endl;
            return -1;
        }
    }




    std::string sprachendatei = "{  \
   \"Move B to A\":\"mov\",\
   \"Add B to A\":\"add\",\
   \"Substract B from A\":\"sub\",\
   \"Swap the upper and lower 4 bits\":\"swp\",\
   \"Shift left, insert 0\":\"sl0\",\
   \"Shift right, insert 0\":\"sr0\",\
   \"Jump to subroutine\":\"jsr\"\
}";

std::string subroutine = "main\nmov r12 0x34\nadd r12 0x02\nmov r10 0x00\nmov (r10) r12";

    Sprache sprache(sprachendatei, "mylang");
    VirtualMachine vm(sprache);
    vm.addSubroutine(subroutine);
    vm.runInstruction("sub r12 0x05");
    vm.runInstruction("jsr main");
    std::cout<<(unsigned int)vm.getValue("(r10)")<<std::endl;
    


    return 0;
}