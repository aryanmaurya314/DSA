#include <iostream>
using namespace std;

int main()
{
    cout << "Enter size of butterfly in even number: ";
    int n;
    cin >> n;

    // upper part
    for (int row = 0; row < n / 2; row++)
    {
        // left wing
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        // spaces
        for (int col = 0; col < n - 2 * row - 2; col++)
        {
            cout << "  ";
        }
        // right wing
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // lower part
    for (int row = 0; row < n / 2; row++)
    {
        // left wing
        for (int col = 0; col < n / 2 - row; col++)
        {
            cout << "* ";
        }
        // spaces
        for (int col = 0; col < 2 * row; col++)
        {
            cout << "  ";
        }
        // right wing
        for (int col = 0; col < n / 2 - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}