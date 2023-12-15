#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while ((e - s) > 1)
    {
        if ((arr[s] - s) != (arr[mid] - mid))
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }

    return arr[s] + 1;
}

int main()
{
    int arr[] = {1, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNum = findMissingNumber(arr, n);

    cout << "Missing number : " << missingNum << endl;

    return 0;
}