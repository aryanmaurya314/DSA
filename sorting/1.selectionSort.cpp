// put each element to its right position | TC = O(n^2) | rounds = n - 1
// no need to sort last element
// unstable sorting algo, can be used on small datasets
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 4, 2, 1, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    /* sort in ascending order */
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        int mini = arr[i]; // this helps to sort if duplicates present
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < mini)
            {
                minIndex = j;
                mini = arr[j];
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    /* sort in descending order
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        int maxi = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > maxi)
            {
                maxIndex = j;
                maxi = arr[j];
            }
        }
        swap(arr[maxIndex], arr[i]);
    }
    */

    // print sorted array
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}