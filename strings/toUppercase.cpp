#include <iostream>
using namespace std;

void toUpperCase(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = str[i] - 'a' + 'A';
        i++;
    }
}

void toLowerCase(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = str[i] - 'A' + 'a';
        i++;
    }
}

int main()
{
    char str[] = "aryan";

    toUpperCase(str);

    cout << "To uppercase: " << str << endl;

    toLowerCase(str);

    cout << "To lowercase: " << str << endl;

    return 0;
}