#include "sprache.hpp"

std::map<const std::string, unsigned int> Sprache::languageElements = {
    {"Move B to A", 2},
    {"Add B to A", 2},
    {"Add B to A with carry", 2},
    {"Substract B from A", 2},
    {"Substract B from A with carry", 2},
    {"Compare B and A", 2},
    {"Bitwise AND of B into A", 2},
    {"Bitwise OR of B into A", 2},
    {"Bitwise XOR of B into A", 2},
    {"Bitwise testing of A with B", 2},
    {"Swap the upper and lower 4 bits", 1},
    {"Shift left, insert 0", 1},
    {"Shift left, insert 1", 1},
    {"Shift right, insert 0", 1},
    {"Shift right, insert 1", 1},
    {"Shift left, duplicate MSB", 1},
    {"Rotate left", 1},
    {"Rotate right", 1},
    {"Rotate left with carry", 1},
    {"Rotate right with carry", 1},
    {"Jump inconditionally", 1},
    {"Jump if Z", 1},
    {"Jump if not Z", 1},
    {"Jump if C", 1},
    {"Jump if not C", 1},
    {"Jump if N", 1},
    {"Jump if not N", 1},
    {"Jump if V", 1},
    {"Jump if not V", 1},
    {"Jump to subroutine", 1},
    {"Enable interrupts", 0},
    {"Disable interrupts", 0},
    {"Return from interrupt", 0}
};

Sprache::Sprache(std::string data, std::string lang) : Datei(lang), JSONObject(data) 
{
    std::map<const std::string, unsigned int>::iterator i = Sprache::languageElements.begin();    
    for(;i!=Sprache::languageElements.end();i++)
    {
        instructions.insert((std::string)(this->get(i->first).get("sign")), i->first);
    }
}
std::string Sprache::print()
{
    return (std::string)*this;
}
bool parseAndRun(std::string instr)
{

}
bool parseAndBuild(std::string);