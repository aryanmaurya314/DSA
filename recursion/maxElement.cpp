#include <iostream>
#include <limits.h>
using namespace std;

void findMax(int arr[], int n, int &maxi)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // processing
    maxi = max(*arr, maxi);

    // recursive call
    findMax(arr + 1, n - 1, maxi);
}

int main()
{
    int arr[] = {20, 30, 100, 40, 60, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxi = INT_MIN;

    findMax(arr, n, maxi);

    cout << "Maximum: " << maxi << endl;

    return 0;
}