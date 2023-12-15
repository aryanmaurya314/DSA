#include <iostream>
#include <queue>
#include <vector>
#include "Queue.h"
using namespace std;

vector<int> solve(vector<int> &v, int k) // k is the size of window
{
    vector<int> ans;
    queue<int> q;
    int low = 0, high = 0;
    while (high < k)
    {
        if (v[high] < 0)
        {
            q.push(high);
        }
        high++;
    }
    // high = k here
    high = k - 1;
    while (high < v.size())
    {
        if (!q.empty())
        {
            ans.push_back(v[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        while (!q.empty() && q.front() <= low)
        {
            q.pop();
        }
        high++;
        low++;
        if (v[high] < 0)
        {
            q.push(high);
        }
    }

    return ans;
}

int main()
{
    vector<int> v{12, -1, -7, 8, -15, 30, 16, 28};

    vector<int> ans = solve(v, 8);

    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}