#include <iostream>
#include <queue>
#include <stack>
#include "Queue.h"
using namespace std;

void interleaveTwoHalves(queue<int> &q)
{
    int n = q.size();
    int mid = n / 2;
    queue<int> q1;

    while (mid)
    {
        q1.push(q.front());
        q.pop();
        mid--;
    }

    while (!q1.empty())
    {
        q.push(q1.front());
        q.push(q.front());
        q1.pop();
        q.pop();
    }
    if (n & 1) // is size is odd
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    printQueue(q);
    interleaveTwoHalves(q);
    printQueue(q);

    return 0;
}