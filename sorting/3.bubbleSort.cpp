// in i^th round, put i^th largest element to its right position
// round 1: 1st largest element will reached to its right position ...next rounds
// TC = O(n^2) | rounds = n - 1 // in worst case if reverse sorted array
// TC = O(n) | rounds = 1 in best case if array is already sorted
// can be used to put i^th largest element to its right place
// no need to sort first element

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 1, 7, 6, 14, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1]) // change > to < if sort in descending order
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (!swapped)
        {
            // if no swapped it means array is sorted now no further operation needed
            break;
        }
    }

    // print sorted array
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}