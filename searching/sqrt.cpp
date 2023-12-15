#include <iostream>
using namespace std;

int findSqrt(int num)
{
    int ans = 0;

    int s = 0;
    int e = num;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid < num)
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

    return ans;
}
int main()
{
    cout << "Enter number: ";
    int n;
    cin >> n;

    int sqrtOfn = findSqrt(n);
    cout << "Square root of n : " << sqrtOfn << endl;

    cout << "Enter precision: ";
    int prec;
    cin >> prec;

    double finalAns = sqrtOfn;
    double step = 0.1;
    for (int i = 0; i < prec; i++)
    {
        for (double j = finalAns; j * j <= n; j += step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "Square root of n : " << finalAns << endl;

    return 0;
}