// (partion logic) put 1 number to its correct place rest will handle recursion
// worst case TC = O(n^2) | best/average TC = O(n*log(n))
/**
 * 1. choose pivot element
 * 2. put pivot element to its right position
 * 3. put all elements less than pivot to its left and rest to its right
 */
#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    // STEP 1: find pivot index and element
    int pivotIndex = s;
    int pivotElement = arr[pivotIndex];

    // STEP 2: find right index of pivotElement
    int correctIndex = s;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            correctIndex++;
        }
    }
    // STEP 3: put pivot element to right position and update pivot index
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;

    // STEP 4: make sure element to the left of pivot is smaller and right to pivot is greater
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // A. found contradict elements swap
        // B. no contradict elements found
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    // STEP 5: return pivotIndex for partitioning
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partitioning of array
    int p = partition(arr, s, e);

    // sort left part recursively
    quickSort(arr, s, p - 1);
    // sort right part recursively
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {7, 3, 1, 4, 2, 9, 8, 7, 7, 7, 7, 8, 9, 3, 3, 1, 1, 4, 11, 12, 34, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int s = 0, e = n - 1;
    quickSort(arr, s, e);

    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}