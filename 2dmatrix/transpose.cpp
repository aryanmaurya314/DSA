#include <iostream>
using namespace std;

void printMatrix(int mat[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // to find index in memory = c * i + j
    int mat[3][3] = {{2, 4, 6}, {1, 3, 5}, {9, 11, 13}};
    cout << "Matrix: " << endl;
    printMatrix(mat);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    cout << "Transpose of matrix: " << endl;
    printMatrix(mat);
    return 0;
}