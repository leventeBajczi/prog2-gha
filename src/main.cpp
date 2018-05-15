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
                                                \n\"Move B to A\":\"mov\",\
                                                \n\"Add B to A\":\"add\",\
                                                \n\"Substract B from A\":\"sub\",\
                                                \n\"Swap the upper and lower 4 bits\":\"swp\",\
                                                \n\"Shift left, insert 0\":\"sl0\",\
                                                \n\"Shift right, insert 0\":\"sr0\",\
                                                \n\"Jump to subroutine\":\"jsr\",\
                                                \n\"Push value to stack\":\"push\",\
                                                \n\"Pop value from stack\":\"pop\"\
                                                \n}";
Sprache sprache(sprachendatei, "mylang");
VirtualMachine* vm = new VirtualMachine(sprache);
    for(int i = 1; i<argc;i++){
        if      (strcmp(argv[i], PRINT_LANGUAGE) == 0){
            std::ofstream myfile;
            myfile.open ("language.lang");
            myfile << sprachendatei;
            myfile.close();
            return 0;
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
                vm->addSubroutine(file);
            }
        }
        else{
            std::cout<<"Unrecognized CLI switch "<<argv[i]<<" , quitting."<<std::endl;
            return -1;
        }
    }
    std::string line;
    while(true)
    {
        std::getline(std::cin, line);
        if(line == "quit")
        {
            delete vm;
             return 0;
        }
        else if (line == "runAll") vm->reRunAll();
        else if (line[0] == '(' || line[0] == 'r') std::cout<<"Wert von "<<line<<": 0x"<<std::hex<<(unsigned int)vm->getValue(line)<<std::endl;
        else vm->runInstruction(line);   
    }
}