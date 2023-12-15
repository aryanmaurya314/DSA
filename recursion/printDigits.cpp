#include <iostream>
using namespace std;

void printDigits(int num)
{
    // base case
    if (num == 0)
    {
        return;
    }
    // recursive call
    printDigits(num / 10);
    // processing
    cout << num % 10 << " ";
}

int main()
{
    int num = 647;
    // num = 0647 prints 423 as in c++ number with leading zero treated as octal number
    printDigits(num);

    cout << endl;

    return 0;
}