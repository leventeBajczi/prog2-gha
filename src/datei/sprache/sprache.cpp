#include "sprache.hpp"

std::vector<std::string> Sprache::languageElements = {
    "Move B to A",
    "Add B to A",
    "Substract B from A",
    "Swap the upper and lower 4 bits",
    "Shift left, insert 0",
    "Shift right, insert 0",
    "Jump inconditionally",
    "Jump to subroutine",
    "Return from subroutine"
};
Sprache::Sprache(std::string data, std::string lang) : Datei(lang), JSONObject(data), instructions({
    {this->get("Move B to A"), "Move B to A"},
    {this->get("Add B to A"), "Add B to A"},
    {this->get("Substract B from A"), "Substract B from A"},
    {this->get("Swap the upper and lower 4 bits"), "Swap the upper and lower 4 bits"},
    {this->get("Shift left, insert 0"), "Shift left, insert 0"},
    {this->get("Shift right, insert 0"), "Shift right, insert 0"},
    {this->get("Jump inconditionally"), "Jump inconditionally"},
    {this->get("Jump to subroutine"), "Jump to subroutine"},
    {this->get("Return from subroutine"), "Return from subroutine"}
    })
{ 
}

std::string Sprache::print()
{
    return (std::string)*this;
}
