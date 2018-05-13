#ifndef _SPRACHE
#define _SPRACHE

#include <map>

#include "../datei.hpp"
#include "../../json/json.hpp"
#include "../instruction/instruction.hpp"

class Sprache : public Datei, public JSONObject
{
    private:
        std::map<std::string, std::string> instructions;
    public:
        static std::map<const std::string, unsigned int> languageElements;
        Sprache(std::string, std::string);
        std::string print();
        
};

#endif