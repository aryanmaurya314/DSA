#include <iostream>
using namespace std;

int main()
{
    // IMPLICIT CASTING: compiler converts one data type to another data type during operation
    //                   it promotes one type to a larger type to maintain precision
    // 1. int to float
    /*
    int num1 = 5;
    float num2 = 2.4;
    float result = num1 + num2; // implicit type conversion of num1 from int to float
    cout << result << endl;
    */
    // 2. char to int
    /*
    char ch = 'A';
    char a = ch + 1; // Implicit conversion of ch from char to int
                     // A --> 65 + 1 = 66
                     // 66 --> B
    cout << a << endl;
    */
    // 3. int to char
    /*
    int a = 97;
    char ch = a; // Implicit type conversion from int to char
    cout << ch << endl;
    */

    // EXPLICIT CASTING:  allow you to explicitly specify the desired data type during an operation
    // 1. double to int
    /*
    double pi = 3.14159265;
    int intPi = (int)pi; // Explicit conversion from double to int
    cout << intPi << endl;
    */
    // 2. float to char
    /*
    float floatNum = 65.35;
    char charVal = (char)floatNum;
    cout << charVal << endl;
    */
    // 3. int to float
    // * int/int = int
    // * int/float = float
    // * float/int = float
    /*
    int a = 10;
    int b = 3.0;
    float c = a / (float)b; // Explicit conversion from int to float
    cout << c << endl;
    */

    return 0;
}