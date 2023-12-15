#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &output, int index = 0)
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
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        output.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], ans, output, i + 1);
        output.pop_back();
    }
}

int main()
{
    vector<int> candidates{2, 5, 2, 1, 2};
    sort(candidates.begin(), candidates.end());
    int target = 5;
    vector<vector<int>> ans;
    vector<int> output;

    combinationSum2(candidates, target, ans, output);

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