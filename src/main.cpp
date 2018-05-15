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



std::string sprachendatei = "{  \
                                                \"Move B to A\":\"mov\",\
                                                \"Add B to A\":\"add\",\
                                                \"Substract B from A\":\"sub\",\
                                                \"Swap the upper and lower 4 bits\":\"swp\",\
                                                \"Shift left, insert 0\":\"sl0\",\
                                                \"Shift right, insert 0\":\"sr0\",\
                                                \"Jump to subroutine\":\"jsr\"\
                                                }";
Sprache sprache(sprachendatei, "mylang");
VirtualMachine* vm = new VirtualMachine(sprache);
    for(int i = 1; i<argc;i++){
        if      (strcmp(argv[i], PRINT_LANGUAGE) == 0){
            std::cout<<Sprache::printEmpty();
        }
        else if (strcmp(argv[i], LANGUAGE_FILE) == 0){
            std::ifstream t(argv[++i]);
            std::string file((std::istreambuf_iterator<char>(t)),
            std::istreambuf_iterator<char>());
            sprachendatei = file;

            Sprache sprache(sprachendatei, "mylang");
            delete vm;
            vm = new VirtualMachine(sprache);

        }
        else if (strcmp(argv[i], USE_FILES) == 0){
            for(i=i+1;i<argc;i++)
            {
                std::ifstream t(argv[i]);
                std::string file((std::istreambuf_iterator<char>(t)),
                std::istreambuf_iterator<char>());
                std::cout<<file<<std::endl;
                vm->addSubroutine(file);
            }
        }
        else{
            std::cout<<"Unrecognized CLI switch "<<argv[i]<<" , quitting."<<std::endl;
            return -1;
        }
    }

vm ->reRunAll();
std::cout<<(unsigned int)vm->getValue("(r1)")<<std::endl;

delete vm;

    return 0;
}