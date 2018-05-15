
#include "instruction.hpp"


/**
 * Konstruktor der SimpleInstruktion Klasse und initialisiert die Membervariablen Sprache, representation, function und die 2 Parametern. 
 */
SimpleInstruktion::SimpleInstruktion(std::string lang, std::string repr, void* ptr, std::string p1, std::string p2) : Instruktion(lang), representation(repr), function(ptr), param1(p1), param2(p2) 
{
    this->function = ptr;
}

/**
 * Gibt eine String-Representation zurück.
 */
std::string SimpleInstruktion::print()
{
    return representation;
}


/**
 * ausführt den Inhaltinstruktion durch eine Funktionenpointer zum entsprechenden Funktion.  
 */
void SimpleInstruktion::run(VirtualMachine& vm)
{
    void (*ptr)(VirtualMachine&, std::string, std::string) = (void (*)(VirtualMachine&, std::string, std::string))function;
    (*ptr)(vm, param1, param2);
}


/**
 * Initialisiert ComplexInstruktion nur mit der Sprache. 
 */
ComplexInstruktion::ComplexInstruktion(std::string lang) : Instruktion(lang)
{
}


/**
 * Initialisiert ComplexInstruktion sowohl mit der Sprache als auch mit einem SimpleInstruktion. 
 */
ComplexInstruktion::ComplexInstruktion(std::string lang, SimpleInstruktion& begin) : Instruktion(lang)
{
    instructions.push_back(begin);
}


/**
 * Gibt die String-Representation des ganzen Instruktionenliste zurück. 
 */
std::string ComplexInstruktion::print()
{
    std::string ret = "";
    for(SimpleInstruktion si : instructions)
    {
        ret+=si.print()+='\n';
    }
    return ret;
}

/**
 * Ausführt jede Instruktion, denen sie enthielt. 
 */
void ComplexInstruktion::run(VirtualMachine& vm)
{
    for(SimpleInstruktion si : instructions)
    {
        si.run(vm);
    }
}


/**
 * Eine neue SimpleInstruktion einfügen. 
 */
void ComplexInstruktion::add(SimpleInstruktion& si)
{
    instructions.push_back(si);
}
