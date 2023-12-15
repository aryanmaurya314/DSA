#include <iostream>
using namespace std;

void solve(int &b)
{
    b++;
}

int main()
{
    int a = 5;
    solve(a);

    cout << a << endl;

    return 0;
}