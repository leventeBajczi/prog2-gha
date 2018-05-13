#include "memory.hpp"
#include <cstring>

Memory::Memory(unsigned int n) : size(n)
{
    speicherBereich = new uint8_t[n];
}
Memory::Memory(const Memory& obj) : size(obj.size)
{
    speicherBereich = new uint8_t[size];
    memcpy(speicherBereich, obj.speicherBereich, size);
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
bool Memory::shiftRight(unsigned int address, uint8_t data, uint8_t dataMask, uint8_t& flag, uint8_t mask)
{
    if(address >= size) return false;
    uint8_t newdata = ((data & dataMask)&&1)<<7 | ((speicherBereich[address] & 0xFE) >> 1); 
    flag&= ~mask;
    flag |= (speicherBereich[address] & 0x01) ? mask : 0;
    return this->write(address, newdata);

}
bool Memory::shiftLeft(unsigned int address, uint8_t data, uint8_t dataMask, uint8_t& flag, uint8_t mask)
{
    if(address >= size) return false;
    uint8_t newdata = ((data & dataMask) && 1) | ((speicherBereich[address] & 0x7F) << 1); 
    flag &= ~mask;
    flag |= ((speicherBereich[address] & 0x80)) ? mask : 0;
    return this->write(address, newdata);
    

}