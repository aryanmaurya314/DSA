#include <iostream>
#include <limits.h>
using namespace std;

// Given an integer N denoting the Length of a line segment. 
// You need to cut the line segment in such a way that the cut length 
// of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.
// Note: if no segment can be cut then return 0.

int maximizeTheCuts(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    // x cut karlo baki recursion dekh lega
    int option1 = 1 + maximizeTheCuts(n - x, x, y, z);
    // y cut karlo baki recursion dekh lega
    int option2 = 1 + maximizeTheCuts(n - y, x, y, z);
    // z cut karlo baki recursion dekh lega
    int option3 = 1 + maximizeTheCuts(n - z, x, y, z);

    // cout << option1 << " " << option2 << " " << option3 << endl;

    return max(option1, max(option2, option3));
}

int main()
{
    int n = 5, x = 5, y = 3, z = 2;

    int ans = maximizeTheCuts(n, x, y, z);

    cout << "Answer: " << ans << endl;

    return 0;
}