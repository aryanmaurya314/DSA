#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &ranks, int t, int p)
{
    int pratas = 0;
    for (int r : ranks)
    {
        int it = 1;
        int time = r;
        while (time <= t)
        {
            pratas++;
            it++;
            time += it * r;
        }
    }
    return pratas >= p;
}

int solve(vector<int> &v, int p)
{
    int start = 1, end, mid, ans = -1;
    int highestRank = *max_element(v.begin(), v.end());
    end = highestRank * (p * ((p + 1) / 2));

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (isPossible(v, mid, p))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> ranks{1, 2, 3, 4};
    int prata = 10;

    int time = solve(ranks, prata);

    cout << "Time to get order done: " << time << endl;

    return 0;
}