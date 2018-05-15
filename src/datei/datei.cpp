#include "datei.hpp"


/**
 * Konstruktor für Dateien, stellt die Sprache ein.
 */
Datei::Datei(std::string lang) : language(lang) {}


/**
 * Auschreiben. 
 */
std::ostream& operator<<(std::ostream& os, Datei& d)
{
    os<<d.print();
    return os;
}

/**
 * Getterfunktion für die Sprache. 
 */
std::string Datei::getLang() { return language;}