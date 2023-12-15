#include <iostream>
using namespace std;

int fibonacci(int n)
{
    // base case
    if ((n == 1) || (n == 2))
    {
        return n - 1;
    }

    // recursive call
    int fib = fibonacci(n - 1) + fibonacci(n - 2);

    return fib;
}

int main()
{
    int n = 6;

    int ans = fibonacci(n);

    cout << n << "th term is : " << ans << endl;

    return 0;
}