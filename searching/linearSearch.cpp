#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 3, 5, 7, 8};
    int size = 6;
    int target = 8;
    int targetIndex = linearSearch(arr, size, target);

    if (targetIndex != -1)
    {
        cout << "Target found at " << targetIndex << " index." << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }

    return 0;
}