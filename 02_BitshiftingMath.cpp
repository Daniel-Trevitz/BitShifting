#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

// Print the number as decimal and binary to see the bits moving
void printAsBinary(unsigned char a)
{
  cout << (int(a) & 0xFF) << "\t" << std::bitset<8>(a) << endl;
}

int main()
{
    // Second, a more mundane and historic use of bit shifting:
    //  Multiplication and Division by 2.

    unsigned char var = 4;
    printAsBinary(var); // --> 00000100

    // 
    var <<= 2; // Shift Left 2 to * 4
    printAsBinary(var); // --> 00000100

    //
    var >>= 1; // Shift Right 1 to divide by 2
    printAsBinary(var); // --> 00000100

    return 0;
}
