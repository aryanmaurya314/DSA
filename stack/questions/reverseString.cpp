#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> st;

    string str = "aryan";

    for (char ch : str)
    {
        st.push(ch);
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    
    cout << endl;

    return 0;
}