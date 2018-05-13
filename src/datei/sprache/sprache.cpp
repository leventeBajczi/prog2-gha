#include "sprache.hpp"

std::map<const std::string, unsigned int> Sprache::languageElements = {
    {"Move B to A", 2},
    {"Add B to A", 2},
    {"Substract B from A", 2},
    {"Swap the upper and lower 4 bits", 1},
    {"Shift left, insert 0", 1},
    {"Shift right, insert 0", 1},
    {"Jump inconditionally", 1},
    {"Jump to subroutine", 1},
    {"Return from subroutine", 0}
};

Sprache::Sprache(std::string data, std::string lang) : Datei(lang), JSONObject(data) 
{
    std::map<std::string, const std::string> instructions = {
    {this->get("Move B to A"), "Move B to A"},
    {this->get("Add B to A"), "Add B to A"},
    {this->get("Substract B from A"), "Substract B from A"},
    {this->get("Swap the upper and lower 4 bits"), "Swap the upper and lower 4 bits"},
    {this->get("Shift left, insert 0"), "Shift left, insert 0"},
    {this->get("Shift right, insert 0"), "Shift right, insert 0"},
    {this->get("Jump inconditionally"), "Jump inconditionally"},
    {this->get("Jump to subroutine"), "Jump to subroutine"},
    {this->get("Return from subroutine"), "Return from subroutine"}
    };
}

std::string Sprache::print()
{
    return (std::string)*this;
}
