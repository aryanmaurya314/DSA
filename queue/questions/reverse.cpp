#include <iostream>
#include <queue>
#include "Queue.h"
using namespace std;

int main()
{
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    cout<<"Before reverse: ";
    printQueue(q);
    reverse(q);
    cout<<"After reverse: ";
    printQueue(q);

    return 0;
}