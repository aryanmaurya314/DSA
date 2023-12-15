#include <iostream>
using namespace std;

void heapify(int *arr, int n, int index)
{
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest = index;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void convertToMaxHeap(int *arr, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int *arr, int n)
{
    while (n > 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

void printArray(int *arr, int n)
{
    cout << "Printing array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-1, 5, 20, 11, 10, 6};
    int n = 5;

    convertToMaxHeap(arr, n);
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}