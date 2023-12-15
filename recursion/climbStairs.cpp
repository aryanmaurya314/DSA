#include <iostream>
using namespace std;

// if total number of stairs is n, find number of ways to reach nth stair

int climbStairs(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n = 44;

    int noOfWays = climbStairs(n);

    cout << "No. of ways: " << noOfWays << endl;

    return 0;
}