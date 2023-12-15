#include <iostream>
using namespace std;

int lastOccurance(string &s1, char s2, int i)
{
    //  base case
    if (s1[i] == s2)
    {
        return i;
    }
    else if (i < 0)
    {
        return -1;
    }

    return lastOccurance(s1, s2, i - 1);
}

int main()
{
    string s1 = "xabcddedfx";
    char s2 = 'x';

    int ans = lastOccurance(s1, s2, s1.size() - 1);

    cout << "Answer: " << ans << endl;

    return 0;
}