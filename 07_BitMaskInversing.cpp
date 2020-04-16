#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

// Print the number as hexadecimal and binary to see the bits moving
void printAsBinary(unsigned char a)
{
  cout << hex << "0x" << (int(a) & 0xFF) << "\t" << std::bitset<8>(a) << endl;
}

int main()
{
    // Some time we will want to know what the state of all bits /except/ 1
    // We can use a bit mask for this as well

    uint8_t var = 0xF0; // 11110000
    printAsBinary(var);

    // The obvious option is just to use a value with every bit set except
    //   the one that we want to remove
    var = var & 0xDF; // 11010000
    printAsBinary(var);

    // But & 0xDF doesn't really mean anything....
    //  This is where the bitwise not is handy.
    const uint8_t userFun1ActBitMask = 0x20;
    var = 0xF0 & ~userFun1ActBitMask;
    printAsBinary(var); // 11010000;
  
    // Another quick trick with bitwise not is setting and clearing a bit.
    // Some languages provide functions to do this directly,
    //   and C/C++ have some helpers lieing around, but it is simple enough:

    printAsBinary(var); // 11010000
    var = var | 0x04; // Set bit 3
    printAsBinary(var); // 11010100
    var = var & ~0x04; // Clear bit 3
    printAsBinary(var); // 11010000
    
    // The same can be applied to groups of bits
    const uint8_t systemErrorMask = 0x1C;
    printAsBinary(var); // 11010000
    var |= systemErrorMask; // Set the bits
    printAsBinary(var); // 11011100
    var &= ~systemErrorMask; // Clear the bits
    printAsBinary(var); // 11000000
    
    // Some times we want to make a bitmask from a number of bits to mask out
    // For example, we want to use bits 2,3,4, and 5.

    // First shift a 1 to bit 6-2, 
    uint8_t mask = 1 << (6 - 2);
    printAsBinary(mask); // 00010000

    // Then subtract 1 - mask for a crazy thug life
    mask = 1 - mask;  // 00001111
    printAsBinary(mask);

    // Then shift by 2 for the offset
    mask >>= 2;
    printAsBinary(mask);

    return 0;
}
