// TC = | SC =
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSubArraySum(vector<int> v, int start, int end)
{
    // base case
    if (start == end)
    {
        return v[start];
    }

    int mid = start + ((end - start) >> 1);

    int leftMaxSum = maxSubArraySum(v, start, mid);
    int rightMaxSum = maxSubArraySum(v, mid + 1, end);

    int leftBorderMaxSum = INT_MIN, rightBorderMaxSum = INT_MIN;
    // max cross border sum
    int leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += v[i];
        leftBorderMaxSum = max(leftBorderMaxSum, leftBorderSum);
    }
    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += v[i];
        rightBorderMaxSum = max(rightBorderMaxSum, rightBorderSum);
    }
    int crossBorderMaxSum = leftBorderMaxSum + rightBorderMaxSum;
    return max(crossBorderMaxSum, max(leftMaxSum, rightMaxSum));
}

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int start = 0, end = v.size() - 1;

    int ans = maxSubArraySum(v, start, end);

    cout << "Answer: " << ans << endl;

    return 0;
}