#include <iostream>
using namespace std;

int factorial(int n)
{
    if ((n == 1) || (n == 0))
    {
        return 1;
    }

    int ans = n * factorial(n - 1);
    return ans;
}

int main()
{
    cout << "Enter a positive number: ";
    int n;
    cin >> n;

    int ans = factorial(n);

    cout << "Factorial of " << n << " is " << ans << endl;

    return 0;
}