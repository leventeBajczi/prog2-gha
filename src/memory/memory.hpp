#ifndef _MEMORY
#define _MEMORY

#include <cstdint>



/**
 * Klasse für die Darstellung des Speicherplatzes. 
 */
class Memory{
    private:
        uint8_t * speicherBereich;
        const unsigned int size;
    public:
        const unsigned int getSize();
        Memory(unsigned int);
        ~Memory();
        Memory(const Memory&);
        bool write(unsigned int, uint8_t);
        uint8_t& read(unsigned int);
        bool shiftRight(unsigned int, uint8_t, uint8_t, uint8_t&, uint8_t);
        bool shiftLeft(unsigned int, uint8_t, uint8_t, uint8_t&, uint8_t);
};


#endif