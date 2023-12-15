#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int n, int index)
{
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int largetIndex = index;

    if (leftIndex < n && v[leftIndex] > v[largetIndex])
    {
        largetIndex = leftIndex;
    }

    if (rightIndex < n && v[rightIndex] > v[largetIndex])
    {
        largetIndex = rightIndex;
    }

    if (largetIndex != index)
    {
        swap(v[largetIndex], v[index]);
        heapify(v, n, largetIndex);
    }
}

void convertToMaxHeap(vector<int> &v)
{
    int n = v.size();
    int startIndex = (n / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
    {
        heapify(v, n, i);
    }
}

void heapSort(vector<int> &v)
{
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void printVector(vector<int> &v)
{
    cout << "Printing vector: ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {5, 20, 11, 10, 6};
    convertToMaxHeap(v);
    heapSort(v);
    printVector(v);

    return 0;
}