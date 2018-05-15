#ifndef _DATEI
#define _DATEI

#include <iostream>


/**
 * Klasse für Dateien. 
 */
class Datei{
    protected:
        std::string language;
    public:
        Datei(std::string);
        virtual std::string print() = 0;
        friend std::ostream& operator<<(std::ostream&, Datei&);
        std::string getLang();
};
#endif