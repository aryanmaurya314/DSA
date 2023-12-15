#include <iostream>
using namespace std;

void solve(int **p)
{
    // p = p + 1; // it will change value newly created box(pass by value)
    // *p = *p + 1; // it will update value of p1
    **p = **p + 1; // it will update value of a
}

int main()
{
    int a = 5;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;

    cout << a << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << *p2 << endl;
    cout << **p2 << endl;

    solve(p2);
    cout << "after" << endl;
    cout << a << endl;
    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}