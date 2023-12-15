#include <iostream>
#include <queue>
#include <string>
using namespace std;

string solve(string &str)
{
    int freq[26] = {0};
    queue<char> q;
    string ans;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}

int main()
{
    string str = "aabc";
    str = "zarcaazrd";

    string ans = solve(str);

    for (char ch : ans)
    {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}