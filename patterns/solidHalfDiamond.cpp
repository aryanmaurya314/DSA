#include <iostream>
using namespace std;

int main()
{
    int n = 11;

    for (int row = 0; row < n / 2 + 1; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 0; row < n / 2; row++)
    {
        for (int col = 0; col < n / 2 - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}