#include <iostream>
#include <cstring>
using namespace std;

int getLength(char a[])
{
    int len = 0;
    int i = 0;
    while (a[i++] != '\0')
    {
        len++;
    }

    return len;
}

int main()
{
    char name[50]; // stores null character ('\0') after the end of all characters
    // cin >> name; // can't read after space, tab, enter
    cin.getline(name, 20); // use this to read after space, tab but you can use delimeter also

    cout << "Your name: " << name << endl;

    cout << "Length: " << getLength(name) << endl;
    cout << "Length using stl: " << strlen(name) << endl;
    // strlen -- to compare
    // strcp -- to copy
    return 0;
}