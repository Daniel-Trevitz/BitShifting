#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

// Print the number as a binary to see the bits moving
void printAsBinary(unsigned char a)
{
  cout << std::bitset<8>(a) << endl;
}

int main()
{

    // First, lets cover what we already know.
    // When "bit shifting" we are literally moving the bit from the current position.

    unsigned char var = 0xFF;
    printAsBinary(var); // --> 11111111

    // When we shift left the most significant bits are lost, and the least significant bits are made 0.
    var = var << 2; // Shift Left 2
    printAsBinary(var); // --> 11111100

    // When  we shift right the least significant bits are lost, and the most signficiant bits are made 0
    var = var >> 3; // Shift Right 3
    printAsBinary(var); // --> 00011111

    // As demonstration we dir SHL 2, and SHR 3; this means we have lost from the original value of 0xFF the state of the 2 most significant bits, and the 1 least signficiant bit.
    var <<= 1; // Shift var Left 1
    printAsBinary(var); // --> 00111110

    return 0;
}
