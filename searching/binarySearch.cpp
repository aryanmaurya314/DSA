#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2; // (start + end) / 2; // integer overflow

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 3, 5, 7, 8, 9};
    int size = 7;
    int target = 9;
    int targetIndex = binarySearch(arr, size, target);

    if (targetIndex != -1)
    {
        cout << "Target found at " << targetIndex << " index." << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }

    // using stl returns true(1) / false(0)
    // in case of vector --> binary_search(v.begin(), v.end(), 9)
    cout << binary_search(arr, arr + size, 9) << endl;

    return 0;
}