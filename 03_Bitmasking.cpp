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
    // A closly related topic is bit masking.

    // Just as a refresher - lets see the decimal, hex, and binary outputs of each bit set along
    printAsBinary(1);   //   1 == 0x01 == 0b00000001
    printAsBinary(2);   //   2 == 0x02 == 0b00000010
    printAsBinary(4);   //   4 == 0x04 == 0b00000100
    printAsBinary(8);   //   8 == 0x08 == 0b00001000
    printAsBinary(16);  //  16 == 0x10 == 0b00010000
    printAsBinary(32);  //  32 == 0x20 == 0b00100000
    printAsBinary(64);  //  64 == 0x40 == 0b01000000
    printAsBinary(128); // 128 == 0x80 == 0b10000000

    // Bit masking is the action of using the bitwise AND operator to allow
    //   breaking a single 2's compliment number into multiple logical components

    // Given an 8 bit number we will assign each bit a totally contrived meaning
    // b0: System OK
    // b1: System Calibrated
    // b2: System Error 1
    // b3: System Error 2
    // b4: System Error 3
    // b5: User Function 1 Active
    // b6: Value 1 out of range
    // b7: Value 2 out of range
    unsigned char var = 0x53;
    printAsBinary(var); // --> 01010011

    // Now that we have given meaning to each of these bits, lets view the example.
    cout << "b0 - System OK?      : "; printAsBinary(var & 0x01); // Bit Set!
    cout << "b1 - System Cal'd?   : "; printAsBinary(var & 0x02); // Bit Set!
    cout << "b2 - System Error 1? : "; printAsBinary(var & 0x04);
    cout << "b3 - System Error 2? : "; printAsBinary(var & 0x08);
    cout << "b4 - System Error 3? : "; printAsBinary(var & 0x10); // Bit Set!
    cout << "b5 - User Fun 1 Act? : "; printAsBinary(var & 0x20);
    cout << "b6 - Value 1 OoR?    : "; printAsBinary(var & 0x40); // Bit Set!
    cout << "b7 - Value 2 OoR?    : "; printAsBinary(var & 0x80);

    // There are two equivalent syntax for determining if a bit is set:
    // As we can see above, the bitwise and, &, returns the value of the bit that you are checking
    // remember that if operates on boolean expressions 
    //  - but due to C legacy, which has no boolean data type,
    //    considers any non-zero value as true.

    if(var & 0x10) cout << "System is in Error 3!" << endl;
    if((var & 0x40) == 0x40) cout << "Value 1 Out of Range!" << endl;

    // And we can do the reverse
    if(!(var & 0x80)) cout << "Value 2 is okay!" << endl;

    return 0;
}
