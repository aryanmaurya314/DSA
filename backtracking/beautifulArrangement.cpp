#include <iostream>
#include <vector>
using namespace std;

void beautifulArrangement(int n, vector<int> &v, int &ans, int currNum = 1)
{
    // base case
    if (currNum == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << v[i];
        }
        cout << endl;
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum;
            beautifulArrangement(n, v, ans, currNum + 1);
            // backtracking
            v[i] = 0;
        }
    }
}

int main()
{
    int n = 3;

    vector<int> v(n + 1);
    int ans = 0;
    beautifulArrangement(n, v, ans);

    cout << "Answer: " << ans << endl;

    return 0;
}