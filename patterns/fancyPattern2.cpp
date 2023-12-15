#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            char ch = col + 1 + 'A' - 1;
            cout << ch;
        }

        for (int col = 0; col < row; col++)
        {
            char ch = row + 'A' - col - 1;
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}