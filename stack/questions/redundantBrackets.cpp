#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &exp)
{
    stack<char> st;

    for (char ch : exp)
    {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int opCount = 0;

            while (!st.empty() && st.top() != '(')
            {
                opCount++;
                st.pop();
            }

            st.pop();

            if (opCount == 0)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    string exp = "((a+b)*(a-b+c))";

    if (checkRedundant(exp))
    {
        cout << "Redundant brackets are present." << endl;
    }
    else
    {
        cout << "Redundant brackets are not present." << endl;
    }

    return 0;
}