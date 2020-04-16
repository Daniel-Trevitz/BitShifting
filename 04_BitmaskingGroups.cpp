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
    // Bitmasks are not restricted to single values.
    // In the example from part 03, we can see that there are 2 obvious groups
    // b2, b3, and b4 - System Error x
    // b6 and b7 - Value x OoR.

    // b0: System OK
    // b1: System Calibrated
    // b2: System Error 1
    // b3: System Error 2
    // b4: System Error 3
    // b5: User Function 1 Active
    // b6: Value 1 out of range
    // b7: Value 2 out of range
    unsigned char var = 0xCC;
    printAsBinary(var); // --> 11001100

    // To determine if any of the System Error are set is simple:
    const uint8_t systemErrorBitMask = 0x1C; // uint8_t == unsigned char 
    printAsBinary(systemErrorBitMask); // --> 00011100

    printAsBinary(var & systemErrorBitMask); // --> 00001100

    // This then has two syntax for checking if any of the system errors are active
    if(var & systemErrorBitMask) cout << "Sure are!" << endl; 
    if((var & systemErrorBitMask) != 0) cout << "Same thing... This is boring" << endl; 

    // Now, to check if all the bits are set we use another syntax
    if((var & systemErrorBitMask) == systemErrorBitMask) cout << "All Set" << endl; 
    else cout << "All are not set! This is run!" << endl;

    // Lets do this again with the value out of range - where both are set
    const uint8_t valueOOR = 0xC0;
    if((var & valueOOR) == valueOOR) cout << "All Set! This is run!" << endl; 
    else cout << "All are not set!" << endl;

    return 0;
}
