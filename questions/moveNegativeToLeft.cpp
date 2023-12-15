#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{1, 2, -3, 4, -5, 6};

    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        if (nums[high] < 0)
        {
            swap(nums[low++], nums[high--]);
        }
        else
        {
            high--;
        }
    }

    for (int n : nums)
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}