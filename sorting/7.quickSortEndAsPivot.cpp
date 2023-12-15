#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int start, int end)
{
    int pivotIndex = end;
    int pivotElement = v[pivotIndex];

    // find correct index for pivotElement
    int correctIndex = pivotIndex;
    for (int i = end - 1; i >= start; i--)
    {
        if (v[i] > v[pivotIndex])
        {
            correctIndex--;
        }
    }
    // update pivotIndex and position of pivotElement
    swap(v[pivotIndex], v[correctIndex]);
    pivotIndex = correctIndex;

    // make sure left of pivotIndex is left than and right is more than pivotElement
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (v[i] <= pivotElement)
        {
            i++;
        }
        while (v[j] > pivotElement)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(v[i], v[j]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &v, int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }

    // find partition
    int p = partition(v, start, end);

    // sort left part
    quickSort(v, start, p - 1);
    // sort right part
    quickSort(v, p + 1, end);
}

int main()
{
    vector<int> v = {7, 2, 8, 6, 3, 2, 7, 5, 1, 1, 4, 1, 1, 4};
    int start = 0, end = v.size() - 1;
    quickSort(v, start, end);

    for (int elm : v)
    {
        cout << elm << " ";
    }
    cout << endl;

    return 0;
}