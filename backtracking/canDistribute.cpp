#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canDistribute(vector<int> &quantity, unordered_map<int, int> &countMap, int currCustomer = 0)
{
    // base case
    if (currCustomer == quantity.size())
    {
        return true;
    }

    for (auto it : countMap)
    {
        if (it.second >= quantity[currCustomer])
        {
            countMap[it.first] = it.second - quantity[currCustomer];
            bool isPossible = canDistribute(quantity, countMap, currCustomer + 1);
            if (isPossible)
            {
                return true;
            }
            countMap[it.first] = it.second + quantity[currCustomer];
        }
    }

    return false;
}

int main()
{
    vector<int> nums{1, 1, 2, 2};
    vector<int> quantity{2, 2};

    unordered_map<int, int> countMap;

    for (int n : nums)
    {
        countMap[n]++;
    }

    bool ans = canDistribute(quantity, countMap);

    cout << "Answer: " << ans << endl;

    return 0;
}