#include "datei.hpp"


Datei::Datei(std::string lang) : language(lang) {}
std::ostream& operator<<(std::ostream& os, Datei& d)
{
    os<<d.print();
    return os;
}

std::string Datei::getLang() { return language;}