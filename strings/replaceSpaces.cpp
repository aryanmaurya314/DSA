#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "My name is hero.";

    int i = 0;
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '@';
        }
    }

    cout << "Answer: " << str << endl;

    return 0;
}