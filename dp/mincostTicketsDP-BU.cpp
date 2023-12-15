// TC = O(3^n) | SC = O(n + 1)
// Bottom up memoization approach
// only one variable is changing so 1D vector needed
#include <iostream>
#include <vector>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs, vector<int> &dp)
{
    dp[days.size()] = 0;

    for (int i = days.size() - 1; i >= 0; i--)
    {

        // solve 1 case
        // 1 day pass taken
        int cost1 = costs[0] + dp[i + 1]; // mincostTickets(days, costs, dp, i + 1);

        // 7 days pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + dp[j]; // mincostTickets(days, costs, dp, j);

        // 30 days pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + dp[j]; // mincostTickets(days, costs, dp, j);

        // return min(cost1, min(cost7, cost30));
        dp[i] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}

int main()
{
    vector<int> days{2, 5};
    vector<int> costs{1, 2, 25};

    vector<int> dp(days.size() + 1, -1);
    int ans = mincostTickets(days, costs, dp);

    cout << "Answer: " << ans << endl;

    return 0;
}