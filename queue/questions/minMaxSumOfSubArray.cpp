#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> minMaxSumOfSubArray(vector<int> &v, int k)
{
    deque<int> mini;
    deque<int> maxi;
    vector<int> ans;

    // process 1st subarray
    for (int i = 0; i < k; i++)
    {
        // PROCESS TO FIND MAXIMUMS
        // remove smaller nums
        while (!maxi.empty() && v[i] >= v[maxi.back()])
        {
            maxi.pop_back();
        }
        // insert current num to maxi
        maxi.push_back(i);

        // PROCESS TO FIND MINIMUMS
        // remove smaller nums
        while (!mini.empty() && v[i] <= v[mini.back()])
        {
            mini.pop_back();
        }
        // insert current num to mini
        mini.push_back(i);
    }
    // insert sum of max and min of 1st subarray
    ans.push_back(v[maxi.front()] + v[mini.front()]);

    // process remaining subarrays
    for (int i = k; i < v.size(); i++)
    {
        // PROCESS MAXIMUMS
        // remove outside subarray index
        if (i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        // remove smaller nums
        while (!maxi.empty() && v[i] >= v[maxi.back()])
        {
            maxi.pop_back();
        }
        // insert current num to maxi
        maxi.push_back(i);

        // PROCESS MINIMUMS
        // remove outside subarray index
        if (i - mini.front() >= k)
        {
            mini.pop_front();
        }
        // remove smaller nums
        while (!mini.empty() && v[i] <= v[mini.back()])
        {
            mini.pop_back();
        }
        // insert current num to mini
        mini.push_back(i);

        // insert sum of max and min of current subarray
        ans.push_back(v[maxi.front()] + v[mini.front()]);
    }

    return ans;
}

int main()
{
    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    vector<int> ans = minMaxSumOfSubArray(v, k);

    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}