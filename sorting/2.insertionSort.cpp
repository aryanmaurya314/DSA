// take i^th element and insert it to its right position
// A. get element
// B. compare (1 --> 7 <-- 10)
// C. shifting elements to make space
// D. copy the element
// TC = O(n^2) | rounds = n - 1
// TC = O(n) | rounds = 1, in best case if array is already sorted
// can be used if array is partially sorted

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 1, 7, 6, 14, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        // step A: fetch value
        int val = arr[i];
        // step B: compare previous values
        int j = i - 1;
        for (; j >= 0; j--)
        {

            if (arr[j] > val) // change > to < if sort in descending order

            {
                // step C: shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // stop here
                break;
            }
        }
        // step D: copy val
        arr[j + 1] = val;
    }

    // print sorted array
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}