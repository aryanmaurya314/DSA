// Link: https://www.spoj.com/problems/EKO/

#include <iostream>
#include <algorithm>
using namespace std;

int findDiffLength(int a[], int n, int mid)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            length += a[i] - mid;
        }
    }
    return length;
}

int maxHeight(int heights[], int n, int requiredWood)
{

    int start = 0;
    int end = *max_element(heights, heights + n);
    int mid;
    int ans = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int woodLength = findDiffLength(heights, n, mid);

        if (woodLength == requiredWood)
        {
            return mid;
        }
        else if (woodLength > requiredWood)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int heights[] = {4, 42, 40, 26, 46};
    int n = sizeof(heights) / sizeof(heights[0]);
    int requiredWood = 20;

    int ans = maxHeight(heights, n, requiredWood);

    cout << "Maximum possible height: " << ans << endl;

    return 0;
}