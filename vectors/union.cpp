#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findUnion(vector<int> arr, vector<int> brr)
{
    vector<int> unionArray;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr.size(); j++)
        {
            if (brr[j] == arr[i])
            {
                brr[j] = -1;
            }
        }
    }

    for (auto a : arr)
    {
        unionArray.push_back(a);
    }

    for (auto b : brr)
    {
        if (b != -1)
        {
            unionArray.push_back(b);
        }
    }

    return unionArray;
}

vector<int> findUnionUsingSet(vector<int> arr, vector<int> brr)
{
    set<int> unionSet;
    vector<int> unionArray;

    for (int a : arr)
    {
        unionSet.insert(a);
    }

    for (int b : brr)
    {
        unionSet.insert(b);
    }

    for (int s : unionSet)
    {
        unionArray.push_back(s);
    }

    return unionArray;
}

void printVector(vector<int> arr)
{
    for (auto a : arr)
    {
        cout << a << " ";
    }
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{2, 3, 1, 6, 7, 8, 9};

    vector<int> unionArray = findUnionUsingSet(a, b); // findUnion(a, b);

    cout << "Union of a & b : ";
    printVector(unionArray);
    cout << endl;

    return 0;
}