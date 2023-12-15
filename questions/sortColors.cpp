#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{1, 0, 1, 0, 2, 2, 1, 2, 0, 2, 1, 0};

    /*
    int zeros = 0, ones = 0, twos = 0;

    for (int n : nums)
    {
        if (n == 0)
            zeros++;
        if (n == 1)
            ones++;
        if (n == 2)
            twos++;
    }

    int index = 0;
    while (zeros > 0)
    {
        nums[index++] = 0;
        zeros--;
    }
    while (ones > 0)
    {
        nums[index++] = 1;
        ones--;
    }
    while (twos > 0)
    {
        nums[index++] = 2;
        twos--;
    }
    */
    // Using 3 pointer approach sort in place
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low++], nums[mid++]);
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high--], nums[mid]);
        }
    }

    for (int n : nums)
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}