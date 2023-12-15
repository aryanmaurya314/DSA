#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &v, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // solve 1 case
    swap(v[s], v[e]);
    // rest will handle recursion
    reverseArray(v, s + 1, e - 1);
}

int main()
{
    vector<int> v{2, 4, 6, 8, 9, 1};

    reverseArray(v, 0, v.size() - 1);

    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}