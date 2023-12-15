#include <iostream>
#include <vector>
using namespace std;

// TC = O(n^2) | SC = O(n + 2) = O(n)

void printArr(vector<int> &v, int i, int j)
{
    while (i <= j)
    {
        cout << v[i++];
    }
    cout << " ";
}
void printSubArray(vector<int> &v, int i, int j)
{
    // base case
    if (i == v.size() - 1)
    {
        return;
    }
    if (j == v.size())
    {
        i += 1;
        j = i;
    }
    printArr(v, i, j);
    printSubArray(v, i, j + 1);
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    int i = 0, j = 0;

    printSubArray(v, i, j);
    cout << endl;

    return 0;
}