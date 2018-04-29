#ifndef _SPRACHE
#define _SPRACHE

#include <map>

#include "../datei.hpp"
#include "../../json/json.hpp"

class Sprache : public Datei, public JSONObject
{
    private:
        static std::map<const std::string, unsigned int> languageElements;
        std::map<std::string, const std::string> instructions;
    public:
        Sprache(std::string, std::string);
        std::string print();
        bool parseAndRun(std::string);
        bool parseAndBuild(std::string);

};

#endif