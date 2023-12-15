#include <iostream>
using namespace std;

int *solve()
{
    int a = 8;
    int *ans = &a;

    return ans;
}

int main()
{

    // cout << solve() << endl;

    int arr[10] = {-1};
    int *ptr = arr;
    int(*p)[10] = &arr;

    for (int i = 0; i < 10; i++)
    {
        cout << (*p)[i] << " ";
    }
    cout << endl;

    return 0;
}