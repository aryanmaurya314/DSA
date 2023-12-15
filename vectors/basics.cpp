#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr)
{
    for (int a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    //** vectors in cpp doubles its size initially it's 2
    //** ways to initialise vertor
    //** 1. initialise a empty vector
    vector<int> arr;
    int size = sizeof(arr) / sizeof(int); // finding size this way depends on compiler

    // cout << size << endl;
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    //** Size: refers to number of elements present in vector
    //** Capacity: refers to number of elements that this vector can hold at a time
    // cout << "Size: " << arr.size() << endl
    //      << "Capacity: " << arr.capacity() << endl;
    arr.pop_back();
    arr.pop_back();
    //** size will not decrease once increased
    // cout << "Size: " << arr.size() << endl
    //      << "Capacity: " << arr.capacity() << endl;

    //** 2. initialise a vector of size given in brackets with zero
    vector<int> brr(2); // it means initially it is 2 but adds up when elements added
    brr.push_back(2);   // this will add after last zero
    brr.push_back(3);
    // printVector(brr);

    //** 3. initialise a vector of n size with desired elements
    vector<int> crr(3, 30);
    crr.push_back(20); //** capacity doubles (6 in this case) if a element added
    // cout << "Size: " << crr.size() << endl
    //      << "Capacity: " << crr.capacity() << endl;
    // printVector(crr);

    //** 4. initialise vector with desired elements
    vector<int> drr{10, 20, 34};
    drr.push_back(20); //** capacity doubles (6 in this case) if a element added
    // cout << "Size: " << drr.size() << endl
    //      << "Capacity: " << drr.capacity() << endl;
    // printVector(drr);

    //** check if vector is empty
    // cout << drr.empty() << endl;

    //** 5. create vector based on user input
    cout << "Enter size of vector: ";
    int n;
    cin >> n;

    vector<int> err(n); // this is good practice for create array of dynamic size
    cout << "Enter vector elements: ";
    for (int i = 0; i < err.size(); i++)
    {
        cin >> err[i];
    }

    // printVector(err);

    return 0;
}