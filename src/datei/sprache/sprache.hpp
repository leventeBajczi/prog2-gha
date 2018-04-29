#ifndef _SPRACHE
#define _SPRACHE

#include <map>

#include "../datei.hpp"
#include "../../json/json.hpp"
#include "../instrucion/instruction.hpp"

class Sprache : public Datei, public JSONObject
{
    private:
        static std::map<const std::string, unsigned int> languageElements;
        
    public:
        Sprache(std::string, std::string);
        std::string print();
        bool parseAndRun(std::string);
        Instruktion parseAndBuild(std::string);

};

#endif