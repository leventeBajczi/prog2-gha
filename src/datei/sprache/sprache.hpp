#ifndef _SPRACHE
#define _SPRACHE

#include <map>
#include <vector>

#include "../datei.hpp"
#include "../../json/json.hpp"
#include "../instruction/instruction.hpp"

class Sprache : public Datei, public JSONObject
{
    public:
        std::map<std::string, std::string> instructions;
        static std::vector<std::string> languageElements;
        Sprache(std::string, std::string);
        std::string print();
        static std::string printEmpty();
        
};

#endif