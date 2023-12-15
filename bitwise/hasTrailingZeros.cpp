#include <iostream>
using namespace std;

bool hasTrailingZeros(int value)
{
    return ((value & -value) != 1);
}

int main()
{
    int num = 2; // 010 True
    num = 3;     // 011 False

    cout << (hasTrailingZeros(num) ? "True" : "False") << endl;

    return 0;
}