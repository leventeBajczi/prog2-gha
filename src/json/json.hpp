#ifndef _JSON
#define _JSON

#include <string>
#include <iostream>
#include "../../lib/simplejson/json.hpp"
class JSONObject;
class JSON{
    protected:
        std::string content;
    public:
        JSON(std::string content) : content(content)
        {}

        operator std::string()
        {return content;}

        friend std::ostream& operator<<(std::ostream&, JSON&); 

};

class JSONArray : public JSON{
    public:
        JSONArray(std::string = "[]");

        JSONObject operator[](int n);

        template<typename T> void set(int, T);

};

class JSONObject : public JSON {
    public:
        JSONObject(std::string= "{}");

        JSONObject get(std::string);

        template<typename T> void put(std::string, T);

        operator int();

        JSONArray& toArr();

        JSONObject operator[](int);

};

//JSON implementation

inline std::ostream& operator<<(std::ostream& os, JSON& content)
{
    os<<content.content;
    return os;
}


//JSONObject implementation

inline JSONObject::operator int()
{return atoi(content.c_str());}


inline JSONObject::JSONObject(std::string content) : JSON(content)
{}

inline JSONObject JSONObject::get(std::string key)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[key].dump());
    return json;
}

inline JSONArray& JSONObject::toArr()
{
    return *static_cast<JSONArray*>(static_cast<JSON*>(this));
}

template<typename T> inline void JSONObject::put(std::string key, T value)
{
    json::JSON obj = json::JSON::Load(content);
    obj[key] = value;
    content = obj.dump();
}
template<> inline void JSONObject::put<JSON>(std::string key, JSON value)
{
    json::JSON obj = json::JSON::Load(content);
    json::JSON obj2 = json::JSON::Load((std::string)value);
    obj[key] = obj2;
    content = obj.dump();    
}
template<> inline void JSONObject::put<JSONObject>(std::string key, JSONObject value)
{
    (*this).put(key, dynamic_cast<JSON&>(value));
}
template<> inline void JSONObject::put<JSONArray>(std::string key, JSONArray value)
{
    (*this).put(key, dynamic_cast<JSON&>(value));
}

//JSONArray implementation

inline JSONArray::JSONArray(std:: string content) : JSON(content)
{}

inline JSONObject JSONArray::operator[](int n)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[n].dump());
    return json;
}

template<typename T> inline void JSONArray::set(int n, T t)
{
        json::JSON obj = json::JSON::Load(content);
        obj[n] = t;
        content = obj.dump();
}
template<> inline void JSONArray::set<JSON>(int n, JSON t)
{
        json::JSON obj = json::JSON::Load(content);
        json::JSON obj2 = json::JSON::Load((std::string)t);
        obj[n] = obj2;
        content = obj.dump();
}

template<> inline void JSONArray::set<JSONObject>(int key, JSONObject value)
{
    (*this).set(key, dynamic_cast<JSON&>(value));
}
template<> inline void JSONArray::set<JSONArray>(int key, JSONArray value)
{
    (*this).set(key, dynamic_cast<JSON&>(value));
}


#endif