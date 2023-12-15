#include <iostream>
using namespace std;

int findPeakIndex(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        { // peak element can't be here as it is always greater
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start; // or end
}

int main()
{
    int arr[] = {0, 10, 9, 6, 5};
    int size = 5;

    int peakIndex = findPeakIndex(arr, size);

    cout << "Peak Element is at index " << peakIndex << endl;

    return 0;
}