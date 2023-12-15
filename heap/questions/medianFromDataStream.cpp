#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int val)
{
    if (maxHeap.size() == minHeap.size())
    {
        if (val > median)
        {
            minHeap.push(val);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(val);
            median = maxHeap.top();
        }
    }
    else if (maxHeap.size() == minHeap.size() + 1)
    {
        if (val > median)
        {
            minHeap.push(val);
        }
        else
        {
            int shiftElem = maxHeap.top();
            maxHeap.pop();
            minHeap.push(shiftElem);
            maxHeap.push(val);
        }
        median = (minHeap.top() + maxHeap.top()) / 2.0;
    }
    else if (minHeap.size() == maxHeap.size() + 1)
    {
        if (val > median)
        {
            int shiftElem = minHeap.top();
            minHeap.pop();
            maxHeap.push(shiftElem);
            minHeap.push(val);
        }
        else
        {
            maxHeap.push(val);
        }
        median = (minHeap.top() + maxHeap.top()) / 2.0;
    }
}

int main()
{
    vector<int> arr{12, 10, 8, 4, 2, 3, 15};
    int n = arr.size();

    double median = 0;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int a : arr)
    {
        solveForMedian(median, maxHeap, minHeap, a);
        cout << "Median: " << median << endl;
    }

    return 0;
}