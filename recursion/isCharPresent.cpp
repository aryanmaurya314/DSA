#include <iostream>
using namespace std;

bool isCharPresent(string &s, char &target, int i)
{
    if (i == s.size())
    {
        return false;
    }

    if (s[i] == target)
    {
        return true;
    }

    return isCharPresent(s, target, i + 1);
}

int main()
{
    string s = "aryanMaurya";
    char target = 'M';

    bool isPresent = isCharPresent(s, target, 0);

    cout << "Answer: " << isPresent << endl;

    return 0;
}