// remove extra space used to create left and right array in merge
// based on divide and conquer technique
// TC = O(n*log(n)) | SC = O(log(n)) = O(n)
// Important question => Inversion count, inplace merge sort(without using extra space)
/**
 * 1. find mid
 * 2. break into 2 half
 * 3. ask recursion to sort both half
 * 4. merge both sorted half
 */
#include <iostream>
using namespace std;

// method 1
void merge(int *arr, int s, int mid, int e)
{
    int s2 = mid + 1;
    if (arr[mid] <= arr[s2])
    {
        return;
    }

    while (s <= mid && s2 <= e)
    {
        if (arr[s] <= arr[s2])
        {
            s++;
        }
        else
        {
            // shift all the elments between s and s2 and update s with s2
            int val = arr[s2];
            int i = s2;
            while (i != s)
            {
                arr[i] = arr[i - 1];
                i--;
            }
            arr[s] = val;

            s++;
            mid++;
            s2++;
        }
    }
}

// method 2
void mergeInPlace(int *arr, int s, int e)
{
    int total_len = e - s + 1;
    int gap = (total_len / 2) + (total_len % 2); // ceil
    while (gap)
    {
        int i = s, j = s + gap;
        while (j <= e)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++, j++;
        }
        gap = gap == 1 ? 0 : (gap / 2) + (gap % 2);
    }
}
void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    // sort left part by recursion
    mergeSort(arr, s, mid);
    // sort right part by recursion
    mergeSort(arr, mid + 1, e);

    // merge both sorted part
    mergeInPlace(arr, s, e);
}

int main()
{
    int arr[] = {7, 3, 2, 4, 9, 2, 3, 4, 1, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}