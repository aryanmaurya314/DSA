#include <iostream>
#include <math.h>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int s, int e, int mid)
{
    int len1 = mid - s + 1, len2 = e - mid;
    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i <= len1; i++)
    {
        left[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i <= len2; i++)
    {
        right[i] = arr[k++];
    }
    int leftIndex = 0, rightIndex = 0, index = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[index++] = left[leftIndex++];
        }
        else
        {
            arr[index++] = right[rightIndex++];
        }
    }

    while (leftIndex < len1)
    {
        arr[index++] = left[leftIndex++];
    }

    while (rightIndex < len2)
    {
        arr[index++] = right[rightIndex++];
    }

    delete[] left;
    delete[] right;
}

void mergeInPlace(int *arr, int s, int e, int n)
{
    int totalLen = e - s + 1;
    // int gap = ceil(totalLen / 2.0); // ceil is heavy op
    int gap = (totalLen / 2) + (totalLen % 2);

    while (gap)
    {
        // printArray(arr, n);
        int i = s, j = s + gap;
        while (j <= e)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }

        // gap = gap == 1 ? 0 : ceil(gap / 2.0); // ceil is heavy op
        gap = gap == 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSort(int *arr, int s, int e, int n)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // sort left part
    mergeSort(arr, s, mid, n);
    // sort right part
    mergeSort(arr, mid + 1, e, n);

    // merge(arr, s, e, mid);
    mergeInPlace(arr, s, e, n);
}

int main()
{
    int arr[] = {2, 4, 5, 1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // selection sort
    /*
    for (int i = 0; i < n - 1; i++)
    {
        printArray(arr, n);
        int minIndex = i, mini = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < mini)
            {
                minIndex = j;
                mini = arr[j];
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    */
    // insertion sort
    /*
    for (int i = 1; i < n; i++)
    {
        printArray(arr, n);
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
    */
    // bubble sort
    /*
    for (int i = n - 1; i > 0; i--)
    {
        printArray(arr, n);
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    */
    // merge sort
    int s = 0, e = n - 1;
    mergeSort(arr, s, e, n);

    // print sorted array
    printArray(arr, n);

    return 0;
}