#include <iostream>
using namespace std;

int divideUsingBinarySearch(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (abs(divisor) * mid == abs(dividend))
        {
            return mid;
        }
        else if (abs(divisor) * mid < abs(dividend))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    if (dividend * divisor < 0)
    {
        ans = -ans;
    }

    return ans;
}

int main()
{
    int a = 3;
    int b = 3;

    if (b == 0)
    {
        cout << "Divisor can't be zero!" << endl;
    }

    int quotient = divideUsingBinarySearch(a, b);

    cout << "Quotient: " << quotient << endl;

    return 0;
}