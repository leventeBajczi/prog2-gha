#ifndef _SPRACHE
#define _SPRACHE

#include <map>
#include <vector>

#include "../datei.hpp"
#include "../../json/json.hpp"
#include "../instruction/instruction.hpp"

/**
 * Child von 2 Basisklassen. Enthielt die Definitionen des Befehle. 
 */
class Sprache : public Datei, public JSONObject
{
    public:
        std::map<std::string, std::string> instructions;
        static std::vector<std::string> languageElements;
        Sprache(std::string, std::string);
        std::string print();
        
};

#endif