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
    // To make a bitmask from multiple values we just apply the left shift and bitwise or operations.

    uint8_t var = 1; // Start with System OK

    // Set the valueOoR and systemError to the previous part's example values
    uint8_t valueOoR = 3;    // 00000011
    uint8_t systemError = 5; // 00000101

    // First, lets do systemError
    var = var | (systemError << 2);
    printAsBinary(var); // --> 00010101


    // A cleaner syntax (which has no equivalent in many languages)
    var |= valueOoR << 6;
    printAsBinary(var); // 11010101;

    
    // And to break it down again...
    cout << "b0 - System OK?      : "; printAsBinary(var & 0x01); // Bit Set!
    cout << "b1 - System Cal'd?   : "; printAsBinary(var & 0x02);
    cout << "b2 - System Error 1? : "; printAsBinary(var & 0x04); // Bit Set!
    cout << "b3 - System Error 2? : "; printAsBinary(var & 0x08);
    cout << "b4 - System Error 3? : "; printAsBinary(var & 0x10); // Bit Set!
    cout << "b5 - User Fun 1 Act? : "; printAsBinary(var & 0x20);
    cout << "b6 - Value 1 OoR?    : "; printAsBinary(var & 0x40); // Bit Set!
    cout << "b7 - Value 2 OoR?    : "; printAsBinary(var & 0x80); // Bit Set!

    return 0;
}
