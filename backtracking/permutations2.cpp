#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void permutations2(vector<int> &nums, vector<vector<int>> &ans, int i = 0)
{
    // base case
    if (i == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_map<int, bool> visited;
    for (int j = i; j < nums.size(); j++)
    {
        if (!visited[nums[j]])
        {
            visited[nums[j]] = true;
            // make permutation
            swap(nums[i], nums[j]);
            // recursive call to create next permutations
            permutations2(nums, ans, i + 1);
            // backtracking
            swap(nums[i], nums[j]);
        }
    }
}

int main()
{
    vector<int> nums{1, 1, 1, 2, 1};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    permutations2(nums, ans);

    for (auto a : ans)
    {
        for (auto p : a)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}