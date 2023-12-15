/**
 * Ex: "abc": "abc", "acb", "bac", "bca", "cab", "cba"
 *      here every character wants to come every place once
 *
 */

// TC = O(n!) | SC = O(n)

#include <iostream>
using namespace std;

void printPermutations(string &s, int i)
{
    // base case
    if (i == s.size())
    {
        cout << s << " ";
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        // swap
        swap(s[i], s[j]);
        // recursive call
        printPermutations(s, i + 1);
        // backtracking
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "abc";
    int i = 0;
    printPermutations(s, i);
    cout << endl;

    return 0;
}