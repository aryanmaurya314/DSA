// LEETCODE: 198
#include <iostream>
#include <vector>
using namespace std;

// TC = O(2^n) | SC = O(n)

int rob(vector<int> &nums, int i)
{
    // base case
    if (i >= nums.size())
    {
        return 0;
    }

    // rob kiya
    int option1 = nums[i] + rob(nums, i + 2);
    // rob nahi kiya
    int option2 = 0 + rob(nums, i + 1);

    return max(option1, option2);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    // nums = {2, 7, 9, 3, 1};

    int ans = rob(nums, 0);

    cout << "Answer: " << ans << endl;

    return 0;
}