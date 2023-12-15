#include <iostream>
#include <vector>
using namespace std;

int binarySearchInNearlySortedArray(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (target == arr[mid])
        {
            return mid;
        }
        else if (mid - 1 >= s && target == arr[mid - 1])
        {
            return mid - 1;
        }
        else if (mid + 1 <= e && target == arr[mid + 1])
        {
            return mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 2;
        }
        else if (target > arr[mid])
        {
            s = mid + 2;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> arr{10, 2, 40, 20, 50, 80, 70};
    int target = 1;

    int ans = binarySearchInNearlySortedArray(arr, target);

    if (ans != -1)
    {
        cout << "Element present at " << ans << " index " << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}