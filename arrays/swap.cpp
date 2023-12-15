#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 6;

    cout << "Before swap: "
         << "a = " << a << ", b = " << b << endl;

    /* 1. using temp variable
    int temp = a;
    a = b;
    b = temp;
    */

    /* 2. using +/-
    b = a + b;
    a = b - a; // (a + b) - a = b
    b = b - a; // (a + b) - b = a
    */

    /* 3. using xor operator */
    b = a ^ b;
    a = b ^ a; // a^b^a = b
    b = b ^ b; // a^b^b = a

    cout << "After swap: "
         << "a = " << a << ", b = " << b << endl;

    return 0;
}