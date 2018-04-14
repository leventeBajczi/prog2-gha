#ifndef _JSON
#define _JSON

#include <string>
#include "../../lib/rapidjson/document.h"
class JSON{
    private:
        rapidjson::Document content;
    public:
        JSON();
        JSON(std::string);
        operator std::string();
        static bool checkJSON(rapidjson::Document&, std::string&);
};

#endif