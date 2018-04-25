#include <string>
#include <iostream>
#include "../../lib/simplejson/json.hpp"
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

inline std::ostream& operator<<(std::ostream& os, JSON& content)
{
    os<<content.content;
    return os;
}