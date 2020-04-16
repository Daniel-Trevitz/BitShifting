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
    const uint8_t systemErrorBitMask = 0x1C; // uint8_t == unsigned char
    const uint8_t valueOoRBitMask = 0xC0;

    // Next we want to extract out information in a bit mask.
    // Specifically, we want to see the System Error group as a single value
    // This is easily done with shift right.

    // b0: System OK
    // b1: System Calibrated
    // b2: System Error 1
    // b3: System Error 2
    // b4: System Error 3
    // b5: User Function 1 Active
    // b6: Value 1 out of range
    // b7: Value 2 out of range
    unsigned char var = 0xD4;
    printAsBinary(var); // --> 11010100

    // We are only interested in the system error bits
    uint8_t systemError = var & systemErrorBitMask;
    printAsBinary(systemError); // --> 00010100

    // But systemError is still in the packed structure, which is not as interesting.
    // So we just shift right 2 since System Error 1 starts at 2.
    systemError >>= 2;
    printAsBinary(systemError); // 00000101;


    // Lets do this again for value OoR

    // We are only interested in the system error bits
    uint8_t valueOoR = var & valueOoRBitMask;
    printAsBinary(valueOoR); // --> 11000000

    // But systemError is still in the packed structure, which is not as interesting.
    // So we just shift right 2 since System Error 1 starts at 2.
    valueOoR >>= 6;
    printAsBinary(valueOoR); // 00000011;

    return 0;
}
