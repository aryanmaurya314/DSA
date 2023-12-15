#include <iostream>
using namespace std;

/**
 * GCD: Greatest Common Divisor
 * GCD/HCF
 * 1. Euclid's algorithm to find GCD
 *    gcd(a,b) = gcd(a-b,b) or gcd(a%b,b)
 * 2. LCM(a,b) * gcd(a,b) = a*b
 *
 * Note: modulo operation is heavy so prefer minus over modulo here
 */

int findGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    if (a > b)
    {
        return findGCD(a - b, b);
    }
    else
    {
        return findGCD(b - a, a);
    }
}

int main()
{
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    int gcd = findGCD(a, b);

    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;

    int lcm = (a * b) / gcd;
    cout << "LCM of " << a << " and " << b << " is " << lcm << endl;

    return 0;
}