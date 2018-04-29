#ifndef _SPRACHE
#define _SPRACHE

#include <map>

#include "../datei.hpp"
#include "../../json/json.hpp"
#include "../instruction/instruction.hpp"

class Sprache : public Datei, public JSONObject
{
    private:
        static std::map<const std::string, unsigned int> languageElements;
        
    public:
        Sprache(std::string, std::string);
        std::string print();
        //Instruktion& parse(std::string);

};

#endif