#ifndef _JSONOBJECT
#define _JSONOBJECT

#include <string>
#include <iostream>
#include "../../lib/simplejson/json.hpp"
class JSONObject{
    private:
        std::string content;
    public:
        JSONObject(std::string = "{}");
        JSONObject get(std::string);
        template<typename T> void put(std::string, T);
        operator int();
        operator std::string();
        JSONObject operator[](int);
        friend std::ostream& operator<<(std::ostream&, JSONObject); 

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