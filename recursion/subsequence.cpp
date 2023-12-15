#include <iostream>
using namespace std;

void printSubsequences(string &s, int i, string output)
{
    // base case
    if (i == s.size())
    {
        cout << output << endl;
        return;
    }

    // exclude
    printSubsequences(s, i + 1, output);

    // include
    output.push_back(s[i]);
    printSubsequences(s, i + 1, output);
}

int main()
{
    string s = "xy";

    printSubsequences(s, 0, "");

    return 0;
}