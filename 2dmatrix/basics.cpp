#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int row = 3;
    int col = 5;

    vector<vector<int>> mat(row, vector<int>(col, -1));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}