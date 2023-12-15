#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersection(vector<int> arr, vector<int> brr)
{
    vector<int> intersectionArray;

    for (int a : arr)
    {
        for (int i = 0; i < brr.size(); i++)
        {
            if (a == brr[i])
            {
                brr[i] = -1;
                intersectionArray.push_back(a);
                break;
            }
        }
    }

    return intersectionArray;
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
    vector<int> a{2, 3, 1, 1, 1, 4, 4};
    vector<int> b{2, 1, 6, 7, 1, 1, 1, 3, 4};

    vector<int> intersectionArray = findIntersection(a, b);

    cout << "Intersection of a & b : ";
    printVector(intersectionArray);
    cout << endl;

    return 0;
}