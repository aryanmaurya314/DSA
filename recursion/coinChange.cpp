// LEETCODE : 322
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    else if (amount < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int coin : coins)
    {
        if (coin <= amount)
        {
            int recAns = coinChange(coins, amount - coin);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }

    return mini;
}

int main()
{
    vector<int> coins{1, 2, 5};
    int amount = 11;
    int ans = coinChange(coins, amount);

    if (ans == INT_MAX)
    {
        ans = -1;
    }

    cout << "Answer: " << ans << endl;

    return 0;
}