#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// TC = O(n * log(k))
int kthSmallest(vector<int> &v, int k)
{
    priority_queue<int> pq;

    int i = 0;
    for (; i < k; i++)
    {
        pq.push(v[i]);
    }

    for (; i < v.size(); i++)
    {
        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    return pq.top();
}

int kthGreatest(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;
    for (; i < k; i++)
    {
        pq.push(v[i]);
    }

    for (; i < v.size(); i++)
    {
        if (v[i] > pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    return pq.top();
}

int main()
{
    vector<int> v{3, 7, 4, 5, 8, 6, 9};
    int k = 1;

    cout << k << "th smallest element: " << kthSmallest(v, k) << endl;
    cout << k << "th greatest element: " << kthGreatest(v, k) << endl;

    return 0;
}