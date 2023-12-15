#include <iostream>
#include <queue>
#include <stack>
#include "Queue.h"
using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    if (k <= 0 || k > q.size())
    {
        return;
    }
    stack<int> st;
    int i = 1, n = q.size();

    while (i <= k)
    {

        st.push(q.front());
        q.pop();
        i++;
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    i = k + 1;
    while (i <= n)
    {
        q.push(q.front());
        q.pop();
        i++;
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    printQueue(q);

    // reverse first 3 elements
    reverseFirstK(q, 2);
    printQueue(q);

    return 0;
}