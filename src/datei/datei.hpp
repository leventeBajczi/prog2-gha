#ifndef _DATEI
#define _DATEI

#include <iostream>

class Datei{
    protected:
        std::string language;
    public:
        Datei(std::string);
        virtual std::string print() = 0;
        friend std::ostream& operator<<(std::ostream&, Datei&);
};
#endif