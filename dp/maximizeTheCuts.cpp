#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Given an integer N denoting the Length of a line segment.
// You need to cut the line segment in such a way that the cut length
// of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.
// Note: if no segment can be cut then return 0.

int maximizeTheCuts(int n, int x, int y, int z)
{

    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int op1 = 1 + maximizeTheCuts(n - x, x, y, z);
    int op2 = 1 + maximizeTheCuts(n - y, x, y, z);
    int op3 = 1 + maximizeTheCuts(n - z, x, y, z);

    cout << "RE" << endl;
    return max(op1, max(op2, op3));
}

int maximizeTheCutsDpMem(int n, int x, int y, int z, vector<int> &dp)
{

    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != INT_MIN)
    {
        return dp[n];
    }

    int op1 = 1 + maximizeTheCutsDpMem(n - x, x, y, z, dp);
    int op2 = 1 + maximizeTheCutsDpMem(n - y, x, y, z, dp);
    int op3 = 1 + maximizeTheCutsDpMem(n - z, x, y, z, dp);

    return dp[n] = max(op1, max(op2, op3));
}

int main()
{
    int n = 9999, x = 94, y = 20, z = 244;
    // int n = 5, x = 4, y = 2, z = 6;

    vector<int> dp(n + 1, INT_MIN);

    // int ans = maximizeTheCuts(n, x, y, z);
    int ans = maximizeTheCutsDpMem(n, x, y, z, dp);
    ans = ans < 0 ? 0 : ans;
    cout << "Answer: " << ans << endl;

    return 0;
}