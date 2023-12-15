#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for (int j = 0; j < mCols; j++)
    {
        for (int i = 0; i < nRows; i++)
        {
            if ((j & 1) == 0)
            {
                ans.push_back(arr[i][j]);
            }
            else
            {
                ans.push_back(arr[nRows - i - 1][j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    vector<int> wave = wavePrint(mat, 3, 4);

    for (int w : wave)
    {
        cout << w << " ";
    }

    cout << endl;

    return 0;
}