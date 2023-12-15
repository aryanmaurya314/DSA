// Exponential Search or doubling search or galloping search or strazik search
// used when array is very very large
/**
 * TC = O(log(2^log(m)-1))
 * Applications:
 *  1. search in infinite array (unbounded arrays)
 *  2. better than BS when x is near to 1
 * 
 * unbounded arrays:
 * find element in an infinite sorted array when end is not known
 * brute force: while(1) if(a[i] < x);
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &v, int s, int e, int x)
{
    int mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] == x)
        {
            return mid;
        }
        else if (x > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return -1;
}

int exponentialSearch(vector<int> &v, int x)
{
    if (v[0] == x)
    {
        return 0;
    }

    int i = 1;
    int n = v.size();

    while (i < n && v[i] <= x)
    {
        i = i << 1; // i * 2
    }

    return binarySearch(v, i / 2, min(i, n - 1), x);
}

int main()
{
    vector<int> v = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int x = 70;

    int ans = exponentialSearch(v, x);

    if (ans != -1)
    {
        cout << "x is found at index " << ans << endl;
    }
    else
    {
        cout << "x is not found!" << endl;
    }

    return 0;
}