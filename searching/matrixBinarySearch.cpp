#include <iostream>
#include <vector>
using namespace std;

vector<int> findElementInMatrix(vector<vector<int>> mat, int target)
{
    vector<int> ans;
    int cols = mat[0].size();
    int s = 0;
    int e = mat.size() * mat[0].size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowIdx = mid / cols;
        int colIdx = mid % cols;
        int element = mat[rowIdx][colIdx];

        if (element == target)
        {
            ans.push_back(rowIdx);
            ans.push_back(colIdx);
            return ans;
        }
        else if (target < element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{

    vector<vector<int>> mat{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};

    int target = 9;

    vector<int> ans = findElementInMatrix(mat, target);

    if (ans[0] != -1)
    {
        cout << "Target found at rowIndex: " << ans[0] << ", colIndex: " << ans[1] << endl;
    }
    else
    {
        cout << "Target not found." << endl;
    }

    return 0;
}