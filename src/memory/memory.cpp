#include "memory.hpp"

Memory::Memory(unsigned int n) : size(n)
{
    speicherBereich = new uint8_t[n];
}
Memory::~Memory()
{
    delete [] speicherBereich;
}
bool Memory::write(unsigned int address, uint8_t data)
{
    if(address >= size) return false;
    speicherBereich[address] = data;
    return true;

}
bool Memory::read(unsigned int address, uint8_t& data)
{
    if(address >= size) return false;
    data = speicherBereich[address];
    return true;
}