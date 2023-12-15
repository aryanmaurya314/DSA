#include <iostream>
#include <cstring>
using namespace std;

bool isPallindrome(char str[])
{
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        if (str[i++] != str[j--])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char str[] = "racecar";

    if (isPallindrome(str))
    {
        cout << str << " is a valid pallindrome." << endl;
    }
    else
    {
        cout << str << " is not a pallindrome." << endl;
    }

    return 0;
}