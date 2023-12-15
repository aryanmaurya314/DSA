#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(char a, char b)
{
    return a > b; // asc --= '<' | desc --= '>'
}

bool cmp1(string a, string b)
{
    return a > b;
}

int main()
{
    // string name = "aryan";
    // sort(name.begin(), name.end(), cmp);
    // cout << name << endl;

    vector<string> arr = {"cha", "r", "act", "ers"};
    sort(arr.begin(), arr.end(), cmp1);
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}