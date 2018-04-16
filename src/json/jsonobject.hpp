#ifndef _JSONOBJECT
#define _JSONOBJECT

#include <string>
#include "json.hpp"

class JSONObject : public JSON{
    private:
        std::string path;
    public:
        JSONObject();
        JSONObject(std::string);
        JSONObject(std::string, std::string);
        JSONObject& get(std::string);
        template <class T> bool put(std::string, T&);
};

#endif