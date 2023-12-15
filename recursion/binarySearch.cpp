#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int s, int e, int key)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (v[mid] == key)
    {
        return mid;
    }
    else if (key < v[mid])
    {
        return binarySearch(v, s, mid - 1, key);
    }
    else
    {
        return binarySearch(v, mid + 1, e, key);
    }
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};
    int key = 170;

    int keyIndex = binarySearch(v, 0, v.size() - 1, key);

    cout << "Key is present at index: " << keyIndex << endl;

    return 0;
}