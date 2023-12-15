#include <iostream>
#include <vector>
using namespace std;
// TODO: Apply DP to reduce TC
int rob(vector<int> &houses, int i, int n)
{
    // base case
    if (i >= n)
    {
        return 0;
    }

    int option1 = houses[i] + rob(houses, i + 2, n);
    int option2 = 0 + rob(houses, i + 1, n);

    return max(option1, option2);
}

int main()
{
    vector<int> houses{1};
    int n = houses.size();
    int ans;
    if (n == 1)
    {
        ans = houses[0];
    }
    else
    {
        int option1 = rob(houses, 0, n - 1);
        int option2 = rob(houses, 1, n);
        ans = max(option1, option2);
    }

    cout << "Answer: " << ans << endl;

    return 0;
}