#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &v, int i)
{
    // base case
    if (i == v.size() - 1)
    {
        return true;
    }
    // processing
    if (v[i] > v[i + 1])
    {
        return false;
    }
    // recursive call
    return isSorted(v, i + 1);
}

int main()
{
    vector<int> v = {10, 40, 30, 40, 50};

    bool ans = isSorted(v, 0);

    cout << "Answer: " << ans << endl;

    return 0;
}