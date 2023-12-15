#include <iostream>
using namespace std;

bool isPallindrome(string &s, int low, int high)
{
    // base case
    if (low >= high)
    {
        return true;
    }
    // solve 1 case
    if (s[low] != s[high])
    {
        return false;
    }
    // recursive call
    return isPallindrome(s, low + 1, high - 1);
}

int main()
{
    string s = "abaa";
    int ans = isPallindrome(s, 0, s.size() - 1);

    cout << "Answer: " << ans << endl;

    return 0;
}