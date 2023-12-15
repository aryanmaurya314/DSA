#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char name[] = "Aryan";

    int i = 0;
    int j = strlen(name) - 1;

    while (i < j)
    {
        swap(name[i++], name[j--]);
    }

    cout << name << endl;

    return 0;
}