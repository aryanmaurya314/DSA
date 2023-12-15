// LEETCODE: 1910
#include <iostream>
using namespace std;

void removeOccurances(string &s, string &part)
{
    int pos = s.find(part);
    while (pos != string::npos)
    {
        s.erase(pos, part.size());
        pos = s.find(part);
    }
}

// TC = O((N/M) * (N*M)) = O(N^2) | SC = O(N/M)
void removeOccurancesRE(string &s, string &part, int pos)
{
    // base case
    if (pos == string::npos)
    {
        return;
    }
    // solve 1 case
    s.erase(pos, part.size()); // TC = O(N)
    pos = s.find(part);        // TC = O(N*M)
    // rest will solve recursion
    removeOccurancesRE(s, part, pos); // total calls = N/M
}

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    // removeOccurances(s, part);
    int pos = s.find(part);
    removeOccurancesRE(s, part, pos);

    cout << "Final String: " << s << endl;
    return 0;
}