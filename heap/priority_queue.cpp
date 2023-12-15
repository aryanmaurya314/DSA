#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // create max-heap
    priority_queue<int> pq;
    // Max heap operations
    cout << "Max heap operation: " << endl;
    cout << "Size: " << pq.size() << endl;
    cout << "Is empty: " << pq.empty() << endl;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    pq.push(60);
    pq.push(70);

    cout << "Size: " << pq.size() << endl;
    cout << "Is empty: " << pq.empty() << endl;
    cout << "Top element of Heap: " << pq.top() << endl;
    pq.pop();
    cout << "Top element of Heap: " << pq.top() << endl;

    cout << endl;

    // create min-heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    // Min heap operations
    cout << "Min heap operation: " << endl;
    cout << "Size: " << pq1.size() << endl;
    cout << "Is empty: " << pq1.empty() << endl;

    pq1.push(10);
    pq1.push(20);
    pq1.push(30);
    pq1.push(40);
    pq1.push(50);
    pq1.push(60);
    pq1.push(70);

    cout << "Size: " << pq1.size() << endl;
    cout << "Is empty: " << pq1.empty() << endl;
    cout << "Top element of Heap: " << pq1.top() << endl;
    pq1.pop();
    cout << "Top element of Heap: " << pq1.top() << endl;

    return 0;
}