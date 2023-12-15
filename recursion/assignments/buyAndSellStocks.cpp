// LEETCODE: 121
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int buy = 0, sell = 1;

    while (sell < prices.size())
    {
        if (prices[sell] > prices[buy])
        {
            profit = max(profit, (prices[sell] - prices[buy]));
        }
        else
        {
            buy = sell;
        }
        sell++;
    }
    return profit;
}

int maxProfitRE(vector<int> &prices, int buy, int sell, int profit = 0)
{
    // base case
    if (sell == prices.size())
    {
        return profit;
    }
    // solve 1 case
    if (prices[sell] > prices[buy])
    {
        profit = max(profit, prices[sell] - prices[buy]);
    }
    else
    {
        buy = sell;
    }

    // recursive call
    return maxProfitRE(prices, buy, sell + 1, profit);
}

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};

    // int profit = maxProfit(prices);
    int profit = maxProfitRE(prices, 0, 1);

    cout << "Maximum Profit: " << profit << endl;

    return 0;
}