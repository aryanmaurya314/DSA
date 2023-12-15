// LEETCODE : 198
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &houses, int i)
{
    // base case
    if (i >= houses.size())
    {
        return 0;
    }
    // chori karo --> ith index par
    int option1 = houses[i] + rob(houses, i + 2);
    // chori mat karo --> ith index par
    int option2 = 0 + rob(houses, i + 1);

    return max(option1, option2);
}

int main()
{
    vector<int> houses{4, 5, 7, 1, 2};
    int ans = rob(houses, 0);
    cout << "Answer: " << ans << endl;

    return 0;
}