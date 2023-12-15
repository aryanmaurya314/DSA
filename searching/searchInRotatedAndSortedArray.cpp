#include <iostream>
#include <vector>
using namespace std;

int findElementUsingBinarySearch(vector<int> v, int target, int s, int e)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (v[mid] == target)
        {
            return mid;
        }
        else if (target < v[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int findPivotIndex(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }
        if (mid + 1 <= e && v[mid] > v[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= s && v[mid] < v[mid - 1])
        {
            return mid - 1;
        }

        if (v[s] > v[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> v{9, 10, 4, 6, 7, 8};
    int target = 8;

    int pivotIndex = findPivotIndex(v);

    if (pivotIndex == -1)
    {
        cout << "Invalid test case!" << endl;
        return 0;
    }

    int ans = -1;

    if (target <= v[pivotIndex] && target >= v[0])
    {
        ans = findElementUsingBinarySearch(v, target, 0, pivotIndex);
    }
    else
    {
        ans = findElementUsingBinarySearch(v, target, pivotIndex, v.size() - 1);
    }

    if (ans != -1)
    {
        cout << "Element found at index " << ans << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}