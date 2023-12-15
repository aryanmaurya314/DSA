/**
 * 3^5 = 3*3*3*3*3 | TC = O(n)
 */

#include <iostream>
using namespace std;

int slowExponentiation(int num, int pow) // TC = O(pow)
{
    int ans = 1;
    for (int i = 0; i < pow; i++)
    {
        ans *= num;
    }
    return ans;
}

int fastExponentiation(int num, int pow) // TC = O(log(pow))
{
    int ans = 1;
    while (pow > 0)
    {
        if (pow & 1)
        { // pow == odd
            ans = ans * num;
        }
        num = num * num;
        pow = pow >> 1; // divide by 2 using right shift operator
    }
    return ans;
}

int main()
{
    int num = 2;
    int pow = 4;

    // cout << "Slow exponentiation ans: " << slowExponentiation(num, pow) << endl;
    cout << "Slow exponentiation ans: " << fastExponentiation(num, pow) << endl;

    return 0;
}