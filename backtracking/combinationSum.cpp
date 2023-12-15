#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &output, int index = 0)
{
    // base case
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        output.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], ans, output, i);
        output.pop_back();
    }
}

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> output;

    combinationSum(candidates, target, ans, output);

    for (auto v : ans)
    {
        for (auto c : v)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}