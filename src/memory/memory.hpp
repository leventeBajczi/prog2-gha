#ifndef _MEMORY
#define _MEMORY

#include <cstdint>

class Memory{
    private:
        uint8_t * speicherBereich;
        const unsigned int size;
    public:
        Memory(unsigned int);
        ~Memory();
        bool write(unsigned int, uint8_t);
        bool read(unsigned int, uint8_t&);

};


#endif