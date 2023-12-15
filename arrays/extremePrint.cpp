#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (start == end)
        {
            cout << arr[start] << " ";
        }
        else
        {
            cout << arr[start] << " " << arr[end] << " ";
        }
        start++;
        end--;
    }

    cout << endl;
    return 0;
}