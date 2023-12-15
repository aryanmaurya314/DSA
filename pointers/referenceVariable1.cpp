#include <iostream>
using namespace std;

void solve(int *&b) // passing pointer by reference
{
    b = b + 1;
}

int main()
{
    int a = 5;
    int *p = &a;

    cout << "before : " << p << endl;
    solve(p);
    cout << "after : " << p << endl;

    return 0;
}