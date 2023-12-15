#if !defined(QUEUE_H)
#define QUEUE_H

#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q)
{
    if (q.empty())
    {
        cout << endl;
        return;
    }
    int temp = q.front();
    q.pop();
    cout << temp << " ";
    printQueue(q);
}

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        cout << endl;
        return;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

#endif // QUEUE_H
