// LEETCODE: 22
// include opening bracket and closing bracket simultaneously
// include close bracket only when open is less than close
// it means open is already present for close
// TC = O(2^(2*n)) = O(2^n) | SC = O(2*n) = O(n)
#include <iostream>
#include <vector>
using namespace std;

void generateParenthesis(int open, int close, vector<string> &ans, string output)
{
    // base case
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    // include open
    if (open > 0)
    {
        /*
        // add open bracket to output
        output.push_back('(');
        // add remaining brackets using recursion
        generateParenthesis(open - 1, close, ans, output);
        // backtracking
        output.pop_back();
        */
        generateParenthesis(open - 1, close, ans, output + '(');
    }

    // include close
    if (close > open)
    {
        /*
        // add open bracket to output
        output.push_back(')');
        // add remaining brackets using recursion
        generateParenthesis(open, close - 1, ans, output);
        // backtracking
        output.pop_back();
        */
        generateParenthesis(open, close - 1, ans, output + ')');
    }
}

int main()
{
    int n = 3;
    int open = n, close = n;
    vector<string> ans;
    string output = "";

    generateParenthesis(open, close, ans, output);

    for (auto a : ans)
    {
        cout << a << " ";
    }

    cout << endl;

    return 0;
}