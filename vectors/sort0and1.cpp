#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0};
    int n = 22;
    int start = 0;
    int end = n - 1;
    int i = 0;
    while (i != end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i++], arr[start++]);
        }
        else
        {
            swap(arr[i], arr[end--]);
        }
    }

    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}