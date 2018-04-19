#include "jsonobject.hpp"


JSONObject::JSONObject(std::string content) : content(content)
{
}
JSONObject JSONObject::get(std::string key)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[key].dump());
    return json;
}
JSONObject::operator int()
{
    return atoi(content.c_str());
}
JSONObject::operator std::string()
{
    return content;
}
JSONObject JSONObject::operator[](int n)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[n].ToString());
    return json;
}


std::ostream& operator<<(std::ostream& os, JSONObject content)
{
    os<<content.content;
    return os;
}