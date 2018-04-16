#include "jsonobject.hpp"

#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/value.h"

JSONObject::JSONObject() : JSON(), path("")
{
}
JSONObject::JSONObject(std::string con) : JSON(con), path("")
{
}
JSONObject::JSONObject(std::string con, std::string p) : JSON(con), path(p)
{
}
JSONObject& JSONObject::get(std::string child)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    content[child.c_str()].Accept(writer);
    return *(new JSONObject(buffer.GetString(), ""));
}

template <class T>
bool JSONObject::put(std::string key, T& value)
{
    Value v(value);
    content.PushBack()
}