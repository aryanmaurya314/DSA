#include <iostream>
#include <vector>
using namespace std;

/**
 * all elements occurr even number of times except one
 * all repeating occurrence of elements appear in pairs & pairs ae not adjacent
 * find the element that appears odd number of times
 */

int findOddOccurringElement(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return mid;
        }

        if ((mid & 1) == 0)
        { // mid --> even
            if (v[mid] == v[mid + 1])
            { // ans --> in right
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        else
        {
            // mid --> odd
            if (v[mid] == v[mid - 1])
            { // ans --> in right
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> v{1, 1, 3, 2, 2, 3, 3, 4, 4, 3, 3, 600, 600, 4, 4};

    int ans = findOddOccurringElement(v);

    if (ans != -1)
    {

        cout << "Index of odd occurring element: " << ans << endl;
    }
    else
    {
        cout << "No odd occurring element found." << endl;
    }

    return 0;
}