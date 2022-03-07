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
    // Exercise time! Given a group of 4 2 bit variables, pack them into a single byte.

    // This should now be trivial.

    // Example of 4 values
    uint8_t values[4] = { 1,2,1,3 };

    // Start with zero
    uint8_t result = 0;

    // Bitwise and with 3 to keep out bit clobering
    result = result | (values[0] & 0x03);
    printAsBinary(result); // 00 00 00 01
    // Each subsequent value must be shifted left!
    result |= (values[1] & 0x03) << 2;
    printAsBinary(result); // 00 00 10 01

    result |= (values[2] & 0x03) << 4;
    printAsBinary(result); // 00 01 10 01

    result |= (values[3] & 0x03) << 6;
    printAsBinary(result); // 11 01 10 01

    // now result is encoded as follows:
    // b0,b1 = value[0]
    // b2,b3 = value[1]
    // b4,b5 = value[2]
    // b6,b7 = value[3]

    // This can also be done as a loop, but it is not always better.
    result = 0;
    for(int i = 0; i < 4; i++)
      result |= (values[i] & 0x03) << i*2;
    printAsBinary(result); // 11 01 10 01

    // And just for fun, lets be clever
    result = 0;
    for(int i = 4; i >= 0; i--)
      result = (values[i] & 0x03) | (result << 2);
    printAsBinary(result); // 11 01 10 01

    // Or as two steps:
    result = 0;
    for(int i = 4; i >= 0; i--)
    {
      result <<= 2;
      result |= (values[i] & 0x03);
    }
    printAsBinary(result); // 11 01 10 01

    // Or as a monster
    result = ((values[0] & 0x03) << 0)
           | ((values[1] & 0x03) << 2)
           | ((values[2] & 0x03) << 4)
           | ((values[3] & 0x03) << 6);
    printAsBinary(result); // 11 01 10 01


    // And, just as a callback to how *2 /2 can be done with << and >>
    // we can also do << and >> with *2 and /2 (but it is less clear)
    // Note that we use + instead of |. They are often interchangable.
    result = (values[0] & 0x03)*1
           + (values[1] & 0x03)*2
           + (values[2] & 0x03)*4
           + (values[3] & 0x03)*8;
    printAsBinary(result); // 11 01 10 01


    return 0;
}
