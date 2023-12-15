// TC = O(k^n) | SC = O(n + 1)
// LEETCODE: 1155
#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    // base case
    if ((target < 0) || (n == 0 && target != 0) || (n != 0 && target == 0))
    {
        return 0;
    }
    if (n == 0 && target == 0)
    {
        return 1;
    }

    // try all k faces to reach target
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += numRollsToTarget(n - 1, k, target - i);
    }

    return ans;
}

int main()
{
    int n = 2, k = 6, target = 7;
    // TLE: n = 30, k = 30, target = 500

    int ans = numRollsToTarget(n, k, target);

    cout << "Answer: " << ans << endl;

    return 0;
}