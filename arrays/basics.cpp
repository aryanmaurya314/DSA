#include <cstring>
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void printCharArray(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    /** 1.
    cout << "Enter size of array less than or equal to 100: ";
    int n;
    cin >> n;

    // BAD PRACTICE
    // int arr[n];

    // for static array use constant always
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Your array: ";
    printArray(arr, n);
    */
    /** 2.
     int arr[10] = {1, 2, 3};
     // if empty array then all values initialize with garbage
     // if any element present then then rest element will be initialised with 0
     // if you want to initialize all values other than 0 use a for loop
     cout << "Your array: ";
     printArray(arr, 10);
    */
    // to initialize all the values in char array use memset
    char arr[10] = {};
    memset(arr, 't', 10);
    printCharArray(arr, 10);

    cout << endl;
    return 0;
}