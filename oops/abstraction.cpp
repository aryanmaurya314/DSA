#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {3, 2, 4, 1};
    // sort is abstraction here
    sort(v.begin(), v.end());

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}