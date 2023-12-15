#include <iostream>
using namespace std;

void printReverseCounting(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // processing
    cout << n << " ";

    // recursive call
    printReverseCounting(n - 1);
}

void printCounting(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // recursive call
    printCounting(n - 1);

    // processing
    cout << n << " ";
}

int main()
{
    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    cout << "Print counting from 1 to " << n << " : ";
    printCounting(n);
    cout << endl;

    cout << "Print counting from " << n << " to 1 : ";
    printReverseCounting(n);
    cout << endl;

    return 0;
}