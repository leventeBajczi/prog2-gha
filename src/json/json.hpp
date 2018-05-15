#ifndef _JSON
#define _JSON

#include <string>
#include <iostream>
#include "../../lib/simplejson/json.hpp"
class JSONObject;


/**
 * Klasse für den Arbeit mit JSON Dateien.
 */
class JSON{
    protected:
        std::string content; /*Enthalt die internale Darstellung des JSON-Objektes.*/
    public:

/**
 * Konstruktor für die Klasse JSON. Ladet den `content` ein. 
 */
        JSON(std::string content) : content(content)
        {}
/**
 * Gibt die internale Darstellung als eine String zurück.. 
 */
        operator std::string()
        {return content;}

        friend std::ostream& operator<<(std::ostream&, JSON&); 

};

/**
 * Klasse für den Arbeit mit JSONArrays, ein Child von JSON
 */
class JSONArray : public JSON{
    public:
        JSONArray(std::string = "[]");

        JSONObject operator[](int n);

        template<typename T> void set(int, T);

};
/**
 * Klasse für den Arbeit mit JSONObjects, ein Child von JSON
 */
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

/**
 * Operatorüberladung für den << operator, schreibt den Inhalt des JSON Klasses (also entweder eine JSONObject or eine JSONArray) zum ostream.
 */

inline std::ostream& operator<<(std::ostream& os, JSON& content)
{
    os<<content.content;
    return os;
}


//JSONObject implementation

/**
 * Gibt den Wert des Objektes als ein Integer zurück.
 */
inline JSONObject::operator int()
{return atoi(content.c_str());}

/**
 * Konstruktor des JSONObjectes, ladet den inhalt ein.
 */
inline JSONObject::JSONObject(std::string content) : JSON(content)
{}

/**
 * Gibt den Wert mit Schlüssel `key` zurück als eine neue JSONObject.
 */
inline JSONObject JSONObject::get(std::string key)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[key].dump());
    return json;
}

/**
 * Falls die JSONObject eine Array enthalten soll, muss man kastieren.
 */
inline JSONArray& JSONObject::toArr()
{
    return *static_cast<JSONArray*>(static_cast<JSON*>(this));
}


/**
 * Ein neues Wert zum JSON Dateien einfügen mit Schlüssel `key` und Wert `value`. Diese Methode funktioniert für fast alle Werte (deswegen eine Template wird benutzt).
 */
template<typename T> inline void JSONObject::put(std::string key, T value)
{
    json::JSON obj = json::JSON::Load(content);
    obj[key] = value;
    content = obj.dump();
}

/**
 * Ein neues Wert zum JSON Dateien einfügen mit Schlüssel `key` und Wert `value`. Diese Methode funktioniert nur für Werte mit JSON-Typ.
 */
template<> inline void JSONObject::put<JSON>(std::string key, JSON value)
{
    json::JSON obj = json::JSON::Load(content);
    json::JSON obj2 = json::JSON::Load((std::string)value);
    obj[key] = obj2;
    content = obj.dump();    
}


/**
 * Ein neues Wert zum JSON Dateien einfügen mit Schlüssel `key` und Wert `value`. Diese Methode funktioniert nur für JSONObjects.
 */
template<> inline void JSONObject::put<JSONObject>(std::string key, JSONObject value)
{
    (*this).put(key, dynamic_cast<JSON&>(value));
}

/**
 * Ein neues Wert zum JSON Dateien einfügen mit Schlüssel `key` und Wert `value`. Diese Methode funktioniert nur für JSONArrays.
 */
template<> inline void JSONObject::put<JSONArray>(std::string key, JSONArray value)
{
    (*this).put(key, dynamic_cast<JSON&>(value));
}

//JSONArray implementation
/**
 * Konstruktor für die Klasse JSONArray. Ladet den `content` ein. 
 */
inline JSONArray::JSONArray(std:: string content) : JSON(content)
{}

/**
 * Gibt den Wert beim Platz n zurück. 
 */
inline JSONObject JSONArray::operator[](int n)
{
    json::JSON obj = json::JSON::Load(content);
    JSONObject json(obj[n].dump());
    return json;
}

/**
 * Einstellen den Wert beim Platz n. Der neue Wert wird t sein (Template). 
 */
template<typename T> inline void JSONArray::set(int n, T t)
{
        json::JSON obj = json::JSON::Load(content);
        obj[n] = t;
        content = obj.dump();
}


/**
 * Einstellen den Wert beim Platz n. Der neue Wert wird t sein (JSON). 
 */
template<> inline void JSONArray::set<JSON>(int n, JSON t)
{
        json::JSON obj = json::JSON::Load(content);
        json::JSON obj2 = json::JSON::Load((std::string)t);
        obj[n] = obj2;
        content = obj.dump();
}


/**
 * Einstellen den Wert beim Platz n. Der neue Wert wird t sein (JSONObject). 
 */
template<> inline void JSONArray::set<JSONObject>(int key, JSONObject value)
{
    (*this).set(key, dynamic_cast<JSON&>(value));
}

/**
 * Einstellen den Wert beim Platz n. Der neue Wert wird t sein (JSONArray). 
 */
template<> inline void JSONArray::set<JSONArray>(int key, JSONArray value)
{
    (*this).set(key, dynamic_cast<JSON&>(value));
}


#endif