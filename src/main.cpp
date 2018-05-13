#include <iostream>
#include "datei/sprache/sprache.hpp"
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

    std::cout<<(std::string)sprache.get("Add B to A")<<std::endl;
    return 0;
}