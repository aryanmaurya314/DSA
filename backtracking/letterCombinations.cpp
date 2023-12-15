// TC = O(4^n) | SC = (4^n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void letterCombinations(string &digits, int i, unordered_map<char, string> &digitsMap, vector<string> &ans, string output)
{
    // base case
    if (i == digits.size())
    {
        ans.push_back(output);
        return;
    }
    //
    string letters = digitsMap[digits[i]];
    for (int j = 0; j < letters.size(); j++)
    {
        // include current letter
        output.push_back(letters[j]);
        // include remaining letters using recurrsion
        letterCombinations(digits, i + 1, digitsMap, ans, output);
        // backtracking
        output.pop_back();
    }
}

int main()
{
    vector<string> ans;
    string digits = "234";
    unordered_map<char, string> digitsMap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string output = "";
    letterCombinations(digits, 0, digitsMap, ans, output);

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}