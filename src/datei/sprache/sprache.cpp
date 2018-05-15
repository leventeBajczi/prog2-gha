#include "sprache.hpp"

std::vector<std::string> Sprache::languageElements = {
    "Move B to A",
    "Add B to A",
    "Substract B from A",
    "Swap the upper and lower 4 bits",
    "Shift left, insert 0",
    "Shift right, insert 0",
    "Jump to subroutine",
    "Push value to stack",
    "Pop value from stack"
};


/**
 * Konstruktor für Klasse Sprache. Ordnet die Befehle zu ihnen Bedeutungen.  
 */
Sprache::Sprache(std::string data, std::string lang) : Datei(lang), JSONObject(data), instructions({
    {this->get("Move B to A"), "Move B to A"},
    {this->get("Add B to A"), "Add B to A"},
    {this->get("Substract B from A"), "Substract B from A"},
    {this->get("Swap the upper and lower 4 bits"), "Swap the upper and lower 4 bits"},
    {this->get("Shift left, insert 0"), "Shift left, insert 0"},
    {this->get("Shift right, insert 0"), "Shift right, insert 0"},
    {this->get("Jump to subroutine"), "Jump to subroutine"},
    {this->get("Push value to stack"), "Push value to stack"},
    {this->get("Pop value from stack"), "Pop value from stack"},
    })
{ 
}


std::string Sprache::print()
{
    return (std::string)*this;
}
