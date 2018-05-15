#include "memory.hpp"
#include <cstring>

/**
 * Konstruktor des Speicherplatzes.
 */
Memory::Memory(unsigned int n) : size(n)
{
    speicherBereich = new uint8_t[n];
}

/**
 * Kopierkonstruktor des Speicherplatzes. 
 */
Memory::Memory(const Memory& obj) : size(obj.size)
{
    speicherBereich = new uint8_t[size];
    memcpy(speicherBereich, obj.speicherBereich, size);
}


/**
 * Destruktor des Speicherplatzes.. 
 */
Memory::~Memory()
{
    delete [] speicherBereich;
}


/**
 * Schreibt data in dem Speicher beim `address` ein. 
 */
bool Memory::write(unsigned int address, uint8_t data)
{
    if(address >= size) return false;
    speicherBereich[address] = data;
    return true;

}


/**
 * Gibt den Wert beim `address` zurück.
 */
uint8_t& Memory::read(unsigned int address)
{
    return speicherBereich[address];
}

/**
 * Verschiebt den Wert beim `address` nach rechts.
 */
bool Memory::shiftRight(unsigned int address, uint8_t data, uint8_t dataMask, uint8_t& flag, uint8_t mask)
{
    if(address >= size) return false;
    uint8_t newdata = ((data & dataMask)&&1)<<7 | ((speicherBereich[address] & 0xFE) >> 1); 
    flag&= ~mask;
    flag |= (speicherBereich[address] & 0x01) ? mask : 0;
    return this->write(address, newdata);

}


/**
 * Verschiebt den Wert beim `address` nach links. 
 */
bool Memory::shiftLeft(unsigned int address, uint8_t data, uint8_t dataMask, uint8_t& flag, uint8_t mask)
{
    if(address >= size) return false;
    uint8_t newdata = ((data & dataMask) && 1) | ((speicherBereich[address] & 0x7F) << 1); 
    flag &= ~mask;
    flag |= ((speicherBereich[address] & 0x80)) ? mask : 0;
    return this->write(address, newdata);
    

}