#include <iostream>
using namespace std;

// int fun(int n)
// {
//     int count = 0;
//     while (n)
//     {
//         n &= (n - 1);
//         count++;
//     }
//     return count;
// }

// bool fun(int x, int y)
// {
//     return ((x ^ y) < 0);
// }

bool fun(int n, int k)
{
    bool bit = n & (1 << k);
    return bit;
}

int main()
{
    // cout << fun(5, 2) << endl;
    // cout << (5 & 4) << endl;

    // if (~0 == 1)
    //     cout << "Y" << endl;
    // else
    //     cout << "N" << endl;

    int x = -11;
    x = x >> 1;
    cout << x << endl;

    return 0;
}