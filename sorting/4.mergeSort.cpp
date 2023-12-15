// based on divide and conquer technique
// TC = O(n*log(n)) | SC = O(n) + O(log(n)) = O(n)
// Important question => Inversion count, inplace merge sort(without using extra space)
/**
 * 1. find mid
 * 2. break into 2 half
 * 3. ask recursion to sort both half
 * 4. merge both sorted half
 */
#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create left and right array
    int *left = new int[len1];
    int *right = new int[len2];
    // copy values to left and right array
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // update main array
    int leftIndex = 0;
    int rightIndex = 0;
    int index = s;
    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[index++] = left[leftIndex++];
        }
        else
        {
            arr[index++] = right[rightIndex++];
        }
    }
    // copy remaining left
    while (leftIndex < len1)
    {
        arr[index++] = left[leftIndex++];
    }
    // copy remaining right
    while (rightIndex < len2)
    {
        arr[index++] = right[rightIndex++];
    }

    // delete left and right newly created array
    delete[] left;
    delete[] right;
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
    merge(arr, s, e);
}

int main()
{
    int arr[] = {7, 3, 2, 4, 9};
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