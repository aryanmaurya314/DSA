#include <iostream>
using namespace std;

void solve(int arr[]) // copy of pointer of arr
{
    cout << "Size of arr in solve: " << sizeof(arr) << endl;
    cout << "arr(in solve): " << arr << endl;
    cout << "&arr(in solve): " << &arr << endl;
    arr[0] = 50;
}

void update(int *p) // copy of pointer of a
{
    cout << "value of p: " << p << endl;
    cout << "address of p: " << &p << endl;
    *p = *p + 7;
}

int main()
{
    // int a = 5;
    // int *ptr = &a; // store address of a
    // int *p = ptr;  // copy ptr to p
    // cout << a << endl;
    // cout << &a << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << p << endl;
    // cout << *p << endl;

    // array pointers
    // int arr[3] = {12, 14, 15};
    /*
    cout << arr << endl; // base address of arr
    cout << arr[0] << endl;
    cout << &arr << endl;    // base address of arr
    cout << &arr[0] << endl; // base address of arr

    int *p1 = arr;
    cout << p1 << endl;
    cout << &p1 << endl;
    // --------------------- //
    cout << " ------------ " << endl;
    cout << *arr << endl;       // arr[0]
    cout << *arr + 1 << endl;   // arr[0] + 1
    cout << *(arr + 1) << endl; // arr[1]
    cout << " ==>> ------------ " << endl;
    int i = 0;
    cout << arr[i] << endl;
    cout << *(arr + i) << endl;
    cout << i[arr] << endl;
    cout << *(i + arr) << endl;
    */
    /*
    cout << "=> ----- char array pointer ------- " << endl;
    // this wierd happens because implementation of cout is different for int array and char array
    char ch[6] = "Hello";
    cout << ch << endl;  // "Hello"
    cout << &ch << endl; // base address of ch
    char *c = ch;
    cout << &c << endl;        // address of c
    cout << c << endl;         // "Hello"
    cout << c + 2 << endl;     // "lle" (base address of char at 2nd index)
    cout << c + 8 << endl;     // after null(\0) character
    cout << *ch << endl;       // ch[0]
    cout << *(ch + 1) << endl; // ch[1]
    */
    /*
    cout << "=> ------ char pointer --------- " << endl;
    char ch = 'k';
    char *c = &ch;

    cout << ch << endl;  // k
    cout << &ch << endl; // k with some garbage value
    cout << c << endl;   // k with some garbage value
    cout << &c << endl;  // address of c
    cout << *c << endl;  // k

    char *name = "Aryan";
    cout << name << endl;
    */
    cout << "=> ------ function pointers --------- " << endl;
    int arr[10] = {2, 1, 3, 5};
    cout << "Size of arr in main: " << sizeof(arr) << endl;
    cout << "arr(in main): " << arr << endl;   // same
    cout << "&arr(in main): " << &arr << endl; // same
    cout << "--> arr values before solve " << endl;
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    solve(arr);
    cout << "--> arr values after solve " << endl;
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    cout << "--> Pass int by reference ------ " << endl;
    int a = 8;
    int *ptr = &a;
    cout << "value of a: " << a << endl;
    cout << "address of a: " << &a << endl;
    cout << "value of ptr: " << ptr << endl;
    cout << "address of ptr: " << &ptr << endl;

    update(ptr);

    cout << "value of a after update: " << a << endl;

    return 0;
}