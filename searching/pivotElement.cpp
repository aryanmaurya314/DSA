#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return v[s];
        }
        if (mid + 1 <= e && v[mid] > v[mid + 1])
        {
            return v[mid];
        }
        if (mid - 1 >= s && v[mid] < v[mid - 1])
        {
            return v[mid - 1];
        }

        if (v[s] > v[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    vector<int> v{9, 10, 2, 4, 6, 8};

    int ans = findPivot(v);

    if (ans != -1)
    {
        cout << "Pivot element is : " << ans << endl;
    }
    else
    {
        cout << "Kuch gadbad hai daya!";
    }

    return 0;
}