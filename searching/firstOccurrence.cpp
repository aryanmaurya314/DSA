#include <iostream>
#include <algorithm>
using namespace std;

int firstOccurrenceIndex(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4, 6, 7};
    int size = 9;
    int target = 4;

    int firstIndex = firstOccurrenceIndex(arr, size, target);

    cout << "Target first appear at " << firstIndex << " index." << endl;

    // using stl
    auto ans = lower_bound(arr, arr + size, target);

    cout << "Lower bound is " << ans - arr << endl;

    return 0;
}