#include "json.hpp"

#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"

JSON::JSON(std::string con)
{
    JSON::checkJSON(content, con);
}
JSON::JSON() : JSON("{}")
{

}
JSON::operator std::string()
{
    rapidjson::StringBuffer buffer;

    buffer.Clear();

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    content.Accept(writer);
    return std::string(buffer.GetString());
}
bool JSON::checkJSON(rapidjson::Document& d, std::string& con)
{
    return d.Parse<0>(con.c_str()).HasParseError();
}