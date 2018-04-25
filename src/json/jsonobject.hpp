#ifndef _JSONOBJECT
#define _JSONOBJECT

#include <string>
#include "json.hpp"
#include <iostream>
#include "../../lib/simplejson/json.hpp"
class JSONObject : public JSON{
    public:
        JSONObject(std::string content = "{}") : JSON(content)
        {}

        JSONObject get(std::string key)
        {
            json::JSON obj = json::JSON::Load(content);
            JSONObject json(obj[key].dump());
            return json;
        }

        template<typename T> void put(std::string, T);

        operator int()
        {return atoi(content.c_str());}

        JSONObject operator[](int);

};

template<typename T> inline void JSONObject::put(std::string key, T value)
{
    json::JSON obj = json::JSON::Load(content);
    obj[key] = value;
    content = obj.dump();
}
template<> inline void JSONObject::put(std::string key, JSONObject value)
{
    json::JSON obj = json::JSON::Load(content);
    json::JSON obj2 = json::JSON::Load((std::string)value);
    obj[key] = obj2;
    content = obj.dump();    
}


#endif