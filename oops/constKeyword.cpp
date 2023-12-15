#include <iostream>
using namespace std;

int main()
{
    // 1. x is constant, can't be reassigned
    const int x = 9;
    // cout << x << endl;

    // 2. 'const' with pointers
    // const int *a = new int(2); // 'const' data, 'non-const' pointer
    int const *a = new int(2); // if I write 'const' before * then content is constant same as above line
    // *a = 20; // can't be modified
    cout << *a << endl;
    // avoid memory leakage
    delete a;
    // updating value of a after using const
    int b = 20;
    a = &b; // pointer itself can be reassigned
    cout << *a << endl;

    // making pointer constant
    int *const c = new int(3);
    // c = &b; // error: pointer is constant
    *c = b; // data can be modified here

    // 'const' pointer and 'const' data
    const int *const p = new int(3);
    // p = &b; // error: pointer is constant
    // *p = b; // error: data is constant

    return 0;
}