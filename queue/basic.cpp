#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // create
    queue<int> q;
    // cout << q.empty() << endl;
    // insert
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    // front
    cout << q.front() << endl;
    // delete
    q.pop();
    cout << q.front() << " " << q.size() << endl;
    // check empty
    cout << q.empty() << endl;

    return 0;
}