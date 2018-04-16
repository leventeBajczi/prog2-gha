#ifndef _JSON
#define _JSON

#include <string>
#include "../../lib/rapidjson/document.h"
class JSON{
    protected:
        rapidjson::Document content;
    public:
        JSON();
        JSON(std::string);
        operator std::string();
        static bool checkJSON(rapidjson::Document&, std::string&);
};

#endif